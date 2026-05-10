"""
Prototype USB driver for Cary FTIR instruments using pyusb.

The script mirrors the reverse-engineered protocol documented in:
  - docs/usb-protocol.md
  - docs/driver-guide.md

It performs the following high-level steps:
  1. Locate the WinUSB interface (interface 0) for the target VID/PID.
  2. Execute the five-stage handshake (reset, version query, counters, register dump).
  3. Subscribe to status notifications.
  4. Push default collection parameters (igram/single-beam settings).
  5. Start a single-beam collect and stream the raw spectral data.

Spectral payload decoding is left as a TODO (blocks arriving on pipe 0x85
with `type 0x18` are written to disk for later analysis).

Requires:
    pip install pyusb
    pip install libusb1

    ensure libusb-1.0.dll is in your path    
"""



import usb.util
import usb.core
import struct
import logging
from typing import Optional, Tuple, List
from dataframe import Frame
import os
import sys
import argparse
import usb.backend.libusb1

DEFAULT_TIMEOUT_MS = 5_000
MAX_PACKET = 512
MAX_PRIMARY_PACKET = 64

# Default endpoints for the instrument (see docs/usb-protocol.md).
BULK_OUT_EP = 0x04
BULK_OUT_PARA = 0x06
BULK_IN_PRIMARY = 0x83
BULK_IN_SECONDARY = 0x85



class CaryFTIR:
    def __init__(self, interface: int = 0):
        self.dev = None
        self.sequence = -1
        self.log = logging.getLogger("CaryFTIR")
        self.interface =  interface

    # ------------------------------------------------------------------ #
    # USB helpers
    # ------------------------------------------------------------------ #

    def _next_sequence(self) -> int:
        # works like a counter, looks after 255
        self.sequence = (self.sequence + 1) & 0xFF
        return self.sequence
    
    def _build_header(
        self,
        frame_type: int,
        command: int,
        pipe_id: int = 0x10,
        flags: int = 0,
        payload_len: int = 0,
        status: int = 0x00,
        param0: int = 0,
        param1: int = 0,
    ) -> bytes:
        seq = self._next_sequence()
        dword0 = (pipe_id << 24) | (0x00 << 16) | (seq << 8) | frame_type
        dword1 = (flags << 24) | ((payload_len & 0xFF) << 16) |(status << 8)  | command
        header = struct.pack("<IIII", dword0, dword1, param0, param1)
        return header        
    
    def _write(self, endpoint: int, data: bytes) -> None:
        self.log.debug("USB OUT %s", data.hex())
        # Sending write to machine
        print("Writing frame")
        written = self.dev.write(endpoint, data, timeout=DEFAULT_TIMEOUT_MS)
        if written != len(data):
            raise IOError(f"short write: expected {len(data)} wrote {written}")
        
    def _read(self, endpoint: int = BULK_IN_PRIMARY, timeout: int = DEFAULT_TIMEOUT_MS) -> bytes:
        # Logging debug info
        # reading from machine
        data = bytes(self.dev.read(endpoint, MAX_PACKET, timeout=timeout))
        self.log.debug("USB IN  %s", data.hex())
        return data
    
    def _read_secondary(self, endpoint: int = BULK_IN_SECONDARY, timeout: int = DEFAULT_TIMEOUT_MS) -> bytes:
        # Logging debug info
        # reading from machine
        print(BULK_IN_SECONDARY)
        data = bytes(self.dev.read(endpoint, MAX_PACKET, timeout=timeout))
        self.log.debug("USB IN  %s", data.hex())
        return data
        
    # receives a frame 
    def _recv_frame(self, endpoint: int = BULK_IN_PRIMARY, timeout: int = DEFAULT_TIMEOUT_MS) -> Frame:
        raw = self._read(endpoint, timeout)
        if len(raw) < 16:
            raise IOError("response shorter than header")
        # Unpack the header
        d0, d1, param0, param1 = struct.unpack("<IIII", raw[:16])
        frame = Frame(
            type=d0 & 0xFF,
            sequence=(d0 >> 8) & 0xFFFF,
            pipe_id=(d0 >> 24) & 0xFF,
            command=d1 & 0xFF,
            status=(d1 >> 8) & 0xFF,
            payload_len=(d1 >> 16) & 0xFF,
            flags=(d1 >> 24) & 0xFF,
            param0=param0,
            param1=param1,
            payload=raw[16:],
        )
        return frame
    
    def _recv_measure_frame(self, endpoint: int = BULK_IN_SECONDARY, timeout: int = DEFAULT_TIMEOUT_MS) -> Frame:
        raw = self._read_secondary()
        if len(raw) < 16:
            raise IOError("response shorter than header")
        # Unpack the header
        d0, d1, param0, param1 = struct.unpack("<IIII", raw[:16])
        frame = Frame(
            type=d0 & 0xFF,
            sequence=(d0 >> 8) & 0xFFFF,
            pipe_id=(d0 >> 24) & 0xFF,
            command=d1 & 0xFF,
            status=(d1 >> 8) & 0xFF,
            payload_len=(d1 >> 16) & 0xFF,
            flags=(d1 >> 24) & 0xFF,
            param0=param0,
            param1=param1,
            payload=raw[16:],
        )
        return frame

    def _send_frame(
        self,
        endpoint: int,
        frame_type: int,
        command: int,
        status: int=0x00,
        *,
        pipe_id: int = 0x10,
        payload: bytes = b"",
        flags: int = 0,
        param0: int = 0,
        param1: int = 0,
        frame_len : int = 64
    ) -> None:
        p_len = len(payload)
        header = self._build_header(
            frame_type,
            command,
            status=status,
            pipe_id=pipe_id,
            flags=flags,
            payload_len=p_len,
            param0=param0,
            param1=param1,
        )
        # TODO: This is hardcoded
        zeros_trail = b"\x00" * (frame_len - 16 - len(payload))

        self._write(endpoint, header + payload + zeros_trail)
        
    # Packet before ~300 packets. Machine returns a 91 byte packet that has counters and after a ~300 byte packet
    # consisting of parameters. address is first 40 then 20 at offset 10 in header
    def read_register(self, address: int) -> Frame:
        """
        Read register data using command 0x18. The firmware requires `param0 = addr << 8`.
        Collects the follow-up type 0x18 fragments from the secondary pipe.
        """
        self.send_frame(BULK_OUT_EP, 0x08, 0x18, param0=(address << 16))
        ack = self._recv_frame()
        if ack.command != 0x00:
            raise IOError(f"register read failed: {ack}")

        frame = self._recv_frame(endpoint=BULK_IN_SECONDARY)
        return frame


    # fråga efter parametrar
    def cmd_b2(self) -> None:
        self.send_frame(BULK_OUT_EP, 0x08, 0xb2, pipe_id=0x30)
        frame = self._recv_frame()
        if frame.command != 0xb2:
            raise IOError(f"Command b2 failed: {frame}")
        self.log.info("Command b2 succeded")
        
    #------------ MAPPA TILL RIKTIGA VARIABLER ------------------
    # 103 paketen skickar våra variabler
    def send_param(self) -> None:
        hex_data = "01 01 00 00 00 04 01 11 00 00 02 00 01 21 00 00 00 80 01 31 00 00 00 c8 01 41 00 00 00 04 31 01 00 00 00 01 31 11 00 00 00 00 31 21 00 00 00 00 31 31 00 00 00 01 31 41 00 00 00 01"
        self.send_frame(
            BULK_OUT_PARA,
            0xb4, 
            0x00, 
            pipe_id=0x00, 
            status=0x3c,
            param0=0x00000200, 
            param1=0x00000000, 
            # fromhex() städar bort mellanslag och gör om till riktiga bytes
            payload=bytes.fromhex(hex_data) 
        )

        frame = self._recv_frame()
        if frame.command != 0xb4:
            raise IOError(f"Command param send failed: {frame}")
        self.log.info("Command Parameters sent")


    def cmd_b4(self) -> None:
        hex_data = "00 00 00 00 00 31 00 00 00 01 00 41 00 00 00 01 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00 00"

        self.send_frame(
            BULK_OUT_EP,
            0x08, 
            0xb4, 
            pipe_id=0x1c, 
            param0=0x00000c00, 
            param1=0x00000100, 
            # fromhex() städar bort mellanslag och gör om till riktiga bytes
            payload=bytes.fromhex(hex_data) 
        )
        frame = self._recv_frame()
        if frame.command != 0xb4:
            raise IOError(f"Command b4 failed: {frame}")
        self.log.info("Command b4 succeeded")
    
    def cmd_60(self) -> None:
        self.send_frame(0x08, 0x60)
        frame = self._recv_frame()
        if frame.command != 0x60:
            raise IOError(f"Command 60 failed: {frame}")
        self.log.info("Command 60 succeeded")

    def cmd_61(self) -> None:
        self.send_frame(0x08, 0x61)
        frame = self._recv_frame()
        if frame.command != 0x61:
            raise IOError(f"Command 61 failed: {frame}")
        self.log.info("Command 61 succeeded")

    def cmd_62(self) -> None:
        self.send_frame(0x08, 0x62, param0=0x10000000)
        frame = self._recv_frame()
        if frame.command != 0x62:
            raise IOError(f"Command 62 failed: {frame}")
        self.log.info("Command 62 succeeded")

    def cmd_63(self) -> None:
        self.send_frame(0x08, 0x63)
        frame = self._recv_frame()
        if frame.command != 0x63:
            raise IOError(f"Command 63 failed: {frame}")
        self.log.info("Command 63 succeeded")

    def cmd_64(self) -> None:
        self.send_frame(0x08, 0x64)
        frame = self._recv_frame()
        self.log.info("Command 64 succeeded")
        self._recv_measure_frame()
    
    # ------------------------------------------------------------------ #
    # High-level functions
    # ------------------------------------------------------------------ #
    def establish_connection(self, vendor_id: int, product_id: int):
        """ Connects to device and performs the intial handshake """
        def _find_device(vendor_id: int, product_id: int) -> None:
            dev = usb.core.find(idVendor=vendor_id, idProduct=product_id)
            if not isinstance(dev, usb.core.Device):
                raise IOError(f"Device VID=0x{vendor_id:04x} PID=0x{product_id:04x} not found")
            if os.name == "posix":
                if dev.is_kernel_driver_active(0):
                    dev.detach_kernel_driver(0)
                dev.set_configuration()
                usb.util.claim_interface(dev, 0)
        
            # Intial step of the hand shake, just an empty payload starting with 0x0d
        def _reset_link(driver: CaryFTIR) -> None:
            """
            Issue the link reset (type 0x0D).
            """
            seq = driver._next_sequence()
            dword0 = (0x00 << 16) | (seq << 8) | 0x0D
            driver.send_frame(BULK_OUT_EP, 0x0d, 0x00)
            frame = driver._recv_frame()
            # Check if received frame looks right
            if frame.type != 0x0D or frame.command != 0x07:
                raise IOError(f"unexpected reset reply: {frame}")
            driver.log.info("Link reset acknowledged: %s", frame)

        
        def _query_version(driver: CaryFTIR) -> Tuple[int, int]:
            """Send cmd=0x01 and return (family, status_flags)."""
            driver.send_frame(BULK_OUT_EP, 0x08, 0x01, param0=0x00002A01)
            frame = driver._recv_frame()
            if frame.command != 0x01:
                raise IOError(f"version query failed: {frame}")
            family = frame.param0
            driver.log.info("Instrument family 0x%08x", family)
            return family, frame.flags

        def _cmd_19(driver: CaryFTIR) -> None:
            driver.send_frame(BULK_OUT_EP, 0x08, 0x19)
            frame = driver._recv_frame()
            if frame.command != 0x19:
                raise IOError(f"Command 19 failed: {frame}")
            driver.log.info("Command 19 succeded")

        def _query_runtime_counters(driver: CaryFTIR) -> Tuple[int, int]:
            """Send cmd=0x68 and return the 24-bit counters from the payload."""
            driver.send_frame(BULK_OUT_EP, 0x08, 0x68)
            frame = driver._recv_frame()
            if frame.command != 0x68:
                raise IOError(f"counter query failed: {frame}")
            # Counters arrive as 0x10 payload bytes; pack them from the payload.
            left = struct.unpack_from("<I", frame.payload, 0)[0] & 0x00FFFFFF
            right = struct.unpack_from("<I", frame.payload, 4)[0] & 0x00FFFFFF
            return left, right
    
        _find_device(self, vendor_id, product_id)
        _reset_link()
        _query_version(self)
        _cmd_19(self)
        counters = _query_runtime_counters(self)
        logging.info("Runtime counters: %s", counters)
    
    
    def param_config(self):
        self.read_register(0x40)
        self.read_register(0x20)

        def chain_b2(param0: int, payload: bytes) -> bytes:
            self.send_frame(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, param0, 0x00000000, payload)
            frame = self._recv_frame()
            return frame

def parse_args(argv: List[str]) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run a Cary FTIR measurement using pyusb.")
    parser.add_argument("--vid", type=lambda x: int(x, 0), default=4020, help="USB vendor ID (e.g. 0x0957)")
    parser.add_argument("--pid", type=lambda x: int(x, 0), default=513, help="USB product ID")
    parser.add_argument("--start", type=float, default=4000.0, help="Start wavenumber (cm^-1)")
    parser.add_argument("--stop", type=float, default=650.0, help="Stop wavenumber (cm^-1)")
    parser.add_argument("--resolution", type=int, default=4, help="Resolution setting (points)")
    parser.add_argument("--out", type=str, help="Dump raw spectral payloads to file")
    parser.add_argument("--verbose", action="store_true", help="Enable debug logging")
    return parser.parse_args(argv)

def configure_logging(verbose: bool) -> None:
    if verbose:
        level = logging.DEBUG
    else:
        level = logging.INFO
    logging.basicConfig(level=level, format="%(asctime)s %(levelname)s %(name)s: %(message)s")
    


def run_measurement(
    start_cm: float,
    stop_cm: float,
    resolution: int,
    output: Optional[str],
) -> None:
    pass

def main(argv: List[str]) -> None:
    args = parse_args(argv)
    configure_logging(args.verbose)
    driver = CaryFTIR()

    try: 
        driver.establish_connection(args.vid, args.pid)
    except Exception as exc:
        logging.error("Connection or handshake failed: %s", exc, exc_info=args.verbose)
    
    try: 
        driver.param_config(args.vid, args.pid)
    except Exception as exc:
        logging.error("Connection or handshake failed: %s", exc, exc_info=args.verbose)

    try:
        run_measurement(
            start_cm=args.start,
            stop_cm=args.stop,
            resolution=args.resolution,
            output=args.out,
        )
    except Exception as exc:  # pylint: disable=broad-except
        logging.error("Measurement failed: %s", exc, exc_info=args.verbose)
        sys.exit(1)


if __name__ == "__main__":
    main(sys.argv[1:])



"""



def main(argv: List[str]) -> None:
    args = parse_args(argv)
    configure_logging(args.verbose)
    logging.info("CaryFTIR.py revision: %s", SCRIPT_REVISION)
    logging.info("CaryFTIR.py path: %s", os.path.abspath(__file__))
    hej = False
    try:
        run_measurement(
            vendor_id=args.vid,
            product_id=args.pid,
            start_cm=args.start,
            stop_cm=args.stop,
            resolution=args.resolution,
            output=args.out,
            data_seconds=args.data_seconds,
            max_data_frames=args.max_data_frames,
            pre_measure_polls=args.pre_measure_polls,
            poll_delay=args.poll_delay,
            plot_enabled=not args.no_plot,
            plot_output=args.plot_out,
            show_plot=args.show_plot,
        )
    except Exception as exc:  # pylint: disable=broad-except
        logging.error("Measurement failed: %s", exc, exc_info=args.verbose)
        sys.exit(1)


if __name__ == "__main__":
    main(sys.argv[1:])


"""