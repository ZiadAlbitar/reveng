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

# Default endpoints for the instrument (see docs/usb-protocol.md).
BULK_OUT_EP = 0x04
BULK_OUT_PARA = 0x06
BULK_IN_PRIMARY = 0x83
BULK_IN_SECONDARY = 0x85



class CaryFTIR:
    def __init__(self, dev: usb.core.Device, interface: int = 0):
        self.dev = dev
        self.sequence = -1
        self.log = logging.getLogger("CaryFTIR")
        self.interface =  interface
        self.hej = False

    # ------------------------------------------------------------------ #
    # USB helpers
    # ------------------------------------------------------------------ #

    def _next_sequence(self) -> int:
        # Works like a counter, looks after 255
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
    
    def _build_measurement_header():
        # The measurements have a different header
        pass
        
    
    def _write(self, endpoint: int, data: bytes) -> None:
        # Just logging debug info
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
        if (self.hej):
            print("före read hej")
        raw = self._read(endpoint, timeout)
        print("efter read hej")
        # Frames can't be shorter than header, but sometimes frames are empty, mabybe this breaks that?
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
        # Frames can't be shorter than header, but sometimes frames are empty, mabybe this breaks that?
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

    # Simply writes the frame to send it
    def send_frame(
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
    ) -> None:
        p_len = len(payload)
        if (self.hej):
            p_len = 0
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
        print(f"Sending frame")
        print(f"{(header)}") 
        zeros_trail = b"\x00" * (48 - len(payload))

        self._write(endpoint, header + payload + zeros_trail)

    # Intial step of the hand shake, just an empty payload starting with 0x0d
    def reset_link(self) -> None:
        """
        Issue the link reset (type 0x0D). The capture shows 64 zero bytes,
        so we replicate that padding.
        """
        seq = self._next_sequence()
        dword0 = (0x00 << 16) | (seq << 8) | 0x0D
        reset_packet = struct.pack("<I", dword0) + b"\x00" * 60
        self._write(BULK_OUT_EP, reset_packet)
        frame = self._recv_frame()
        # Check if received frame looks right
        if frame.type != 0x0D or frame.command != 0x07:
            raise IOError(f"unexpected reset reply: {frame}")
        self.log.info("Link reset acknowledged: %s", frame)

    def query_version(self) -> Tuple[int, int]:
        """Send cmd=0x01 and return (family, status_flags)."""
        self.send_frame(BULK_OUT_EP, 0x08, 0x01, param0=0x00002A01)
        frame = self._recv_frame()
        if frame.command != 0x01:
            raise IOError(f"version query failed: {frame}")
        family = frame.param0
        self.log.info("Instrument family 0x%08x", family)
        return family, frame.flags
    
    def cmd_19(self) -> None:
        self.send_frame(BULK_OUT_EP, 0x08, 0x19)
        frame = self._recv_frame()
        if frame.command != 0x19:
            raise IOError(f"Command 19 failed: {frame}")
        self.log.info("Command 19 works")
    
    def query_runtime_counters(self) -> Tuple[int, int]:
        """Send cmd=0x68 and return the 24-bit counters from the payload."""
        self.send_frame(BULK_OUT_EP, 0x08, 0x68)
        frame = self._recv_frame()
        if frame.command != 0x68:
            raise IOError(f"counter query failed: {frame}")
        # Counters arrive as 0x10 payload bytes; pack them from the payload.
        left = struct.unpack_from("<I", frame.payload, 0)[0] & 0x00FFFFFF
        right = struct.unpack_from("<I", frame.payload, 4)[0] & 0x00FFFFFF
        return left, right
    
    def read_register(self, address: int) -> None:
        """
        Read register data using command 0x18. The firmware requires `param0 = addr << 8`.
        Collects the follow-up type 0x18 fragments from the secondary pipe.
        """
        self.send_frame(BULK_OUT_EP, 0x08, 0x18, param0=(address << 16))
        ack = self._recv_frame()
        if ack.command != 0x00:
            raise IOError(f"register read failed: {ack}")
        # data = bytearray(ack.payload)
        # Additional pages arrive on pipe 0x1C / endpoint 0x85 as type 0x18.
        # while len(data) < length:
        #     frame = self._recv_frame(endpoint=BULK_IN_SECONDARY)
        #     if frame.type != 0x18:
        #         self.log.warning("Unexpected frame while reading register: %s", frame)
        #         continue
        #     data.extend(frame.payload)
        # return bytes(data[:length])
        frame = self._recv_frame(endpoint=BULK_IN_SECONDARY)


    def cmd_b2(self) -> None:
        self.send_frame(BULK_OUT_EP, 0x08, 0xb2, pipe_id=0x30)
        frame = self._recv_frame()
        if frame.command != 0xb2:
            raise IOError(f"Command b2 failed: {frame}")
        self.log.info("Command b2 works")

    def cmd_copy(self, endpoint: int, frame_type: int, pipe_id: int, command: int, flags: int, param0: int, param1: int, payload: str) -> None:
        self.send_frame(
            endpoint=endpoint,
            frame_type=frame_type,
            pipe_id=pipe_id,
            command=command,
            flags=flags,
            param0=param0,
            param1=param1,
            # fromhex() städar bort mellanslag och gör om till riktiga bytes
            payload=bytes.fromhex(payload) 
        )
        if (self.hej):
            print(f"frame type: {frame_type}, pipe id: {pipe_id}, flags: {flags}")
        frame = self._recv_frame()
        if frame.command != command:
            raise IOError(f"Command {command} copy failed: {frame}")
        self.log.info(f"Command {command} copy works with payload: {payload}")
        
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
        self.log.info("Command b4 works")
    
    def cmd_60(self) -> None:
        self.send_frame(0x08, 0x60)
        frame = self._recv_frame()
        if frame.command != 0x60:
            raise IOError(f"Command 60 failed: {frame}")
        self.log.info("Command 60 works")

    def cmd_61(self) -> None:
        self.send_frame(0x08, 0x61)
        frame = self._recv_frame()
        if frame.command != 0x61:
            raise IOError(f"Command 61 failed: {frame}")
        self.log.info("Command 61 works")

    def cmd_62(self) -> None:
        self.send_frame(0x08, 0x62, param0=0x10000000)
        frame = self._recv_frame()
        if frame.command != 0x62:
            raise IOError(f"Command 62 failed: {frame}")
        self.log.info("Command 62 works")

    def cmd_63(self) -> None:
        self.send_frame(0x08, 0x63)
        frame = self._recv_frame()
        if frame.command != 0x63:
            raise IOError(f"Command 63 failed: {frame}")
        self.log.info("Command 63 works")

    def cmd_64(self) -> None:
        self.send_frame(0x08, 0x64)
        frame = self._recv_frame()
        # if frame.command != 0x00 or frame.pipe_id != 0x04:
        #     raise IOError(f"Command 64 failed: {frame}")
        self.log.info("Command 64 works")
        self._recv_measure_frame()
        print("get measurement work")

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
        
def find_device(vendor_id: int, product_id: int) -> usb.core.Device:
    dev = usb.core.find(idVendor=vendor_id, idProduct=product_id)
    if not isinstance(dev, usb.core.Device):
        raise IOError(f"Device VID=0x{vendor_id:04x} PID=0x{product_id:04x} not found")
    if os.name == "posix":
        if dev.is_kernel_driver_active(0):
            dev.detach_kernel_driver(0)
        dev.set_configuration()
        usb.util.claim_interface(dev, 0)
    return dev

def run_measurement(
    vendor_id: int,
    product_id: int,
    start_cm: float,
    stop_cm: float,
    resolution: int,
    output: Optional[str],
) -> None:
    dev = find_device(vendor_id, product_id)
    driver = CaryFTIR(dev)
    driver.reset_link()
    driver.query_version()
    driver.cmd_19()
    counters = driver.query_runtime_counters()
    driver.read_register(0x40)
    driver.read_register(0x20)
    logging.info("Runtime counters: %s", counters)
    hej = False

    # driver.cmd_63()
    # driver.cmd_62()
    # driver.cmd_64()
    
    # breakpoint()
    # for i in range (1, 10):
    #     driver.cmd_60()

    # New_sniff
    
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x1c, 0xb4, 0x00, 0x000c0000, 0x00010000, '000000000031000000010041000000010000000000000000000000000000000000000000000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x00007019, 0x00000000, '000000002482587798de0d1500000d15247a811518000000d007ee0f64000000889b0d15000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x00007039, 0x00000000, '000000000000016000303935353333000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x00007049, 0x00000000, '000000000000010100303935353333000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x00008019, 0x00000000, '000000000000010b00303935353333000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x00001039, 0x00000000, '000000000000001400303935353333000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x00001049, 0x00000000, '000000000b0b030000303935353333000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x0000102e, 0x00000000, '0000000009ffffff00303935353333000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x0000130e, 0x00000000, '000000004d59323434364355313400000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x0000131e, 0x00000000, '000000003030323300364355313400000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x0000132e, 0x00000000, '000000003030343700364355313400000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x0000133e, 0x00000000, '000000003031313300364355313400000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x0000134e, 0x00000000, '000000003000313300364355313400000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x0000135e, 0x00000000, '000000004155323433393638363200000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x0000136e, 0x00000000, '000000003144313130303935353333000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x00001109, 0x00000000, '0000000038c20d15a416d914ab16d91404e4af004828e10fb828e10f0000000005000000000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x00001101, 0x00000000, '000000000000000600303935353333000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x00001111, 0x00000000, '000000000000000100303935353333000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x00001121, 0x00000000, '000000000000000000303935353333000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x00001131, 0x00000000, '000000000000000000303935353333000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x00001144, 0x00000000, '000000000000000000303935353333000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x00003154, 0x00000000, '000000007fffffff00303935353333000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x00003194, 0x00000000, '0000000045ee700000303935353333000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x00003184, 0x00000000, '00000000bef0a3d700303935353333000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb3, 0x00, 0x00001041, 0x00040000, '000000010000000435333300000000000000000000000000000000000000000030323134000000000000000000000000')
    # driver.hej = True
    # driver.cmd_copy(BULK_OUT_EP, 0x0a, 0x04, 0x00, 0x4c, 0x00000000, 0x00000000, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    # driver.hej = False
    # driver.send_param()
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb3, 0x00, 0x00000231, 0x00040000, '00000000000000000000000004e4af00894ed914440e0000d8e3d814ffffffff4828e10f000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb3, 0x00, 0x00000241, 0x00040000, '000000000000000000303935353333000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb3, 0x00, 0x00000221, 0x00040000, '000000010000000000303935353333000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x00000211, 0x00000000, '000000003000000004000000010000004828e10f1b36520e000000000000000000000000000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb3, 0x00, 0x00000211, 0x00040000, '000000000000001900303935353333000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x10, 0x69, 0x00, 0x00000001, 0x00000000, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x1c, 0xb4, 0x00, 0x000c0000, 0x00030000, '000000000031000000020041000000010000000000000000000000000000000000000000000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x24, 0x15, 0x08, 0x10010000, 0x00040004, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb3, 0x00, 0x000031a1, 0x00040000, '00000001000000000000000004e4af00894ed914440e00005683d914ffffffff4828e10f000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb3, 0x00, 0x000031c1, 0x00040000, '000000010000000200303935353333000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x00001109, 0x00000000, '00000000c402000098e2af00e63e547778e40d154828e10fd89bbc0200000000b0e2af00000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x00001101, 0x00000000, '000000000000000600303935353333000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x00001111, 0x00000000, '000000000000000100303935353333000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x00001121, 0x00000000, '000000000000000000303935353333000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x00001131, 0x00000000, '000000000000000000303935353333000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x00001144, 0x00000000, '000000000000000000303935353333000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x00003154, 0x00000000, '000000007fffffff00303935353333000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x00003194, 0x00000000, '0000000045ee700000303935353333000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x00003184, 0x00000000, '00000000bef0a3d700303935353333000000000000050000022401000991100000060151000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x10, 0xb6, 0x00, 0x00000000, 0x00040000, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x10, 0xb5, 0x00, 0x00000000, 0x00040000, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x10, 0x60, 0x00, 0x00000000, 0x00000000, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x10, 0xb5, 0x00, 0x00000000, 0x00040000, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x10, 0x60, 0x00, 0x00000000, 0x00000000, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x10, 0xb5, 0x00, 0x00000000, 0x00040000, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x10, 0x60, 0x00, 0x00000000, 0x00000000, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    # driver.cmd_copy(BULK_OUT_EP, 0x08, 0x10, 0xb5, 0x00, 0x00000000, 0x00040000, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')

    #105_to_111

    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x1c, 0xb4, 0x00, 0x00000c00, 0x00000100, '000000000031000000010041000000010000000000000000000000000000000000000000000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x19700000, 0x00000000, '000000000000551b000000008898551b100000000000211bc401211b9008211b8898551b000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x39700000, 0x00000000, '0000000000000160000030402000000b0000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x49700000, 0x00000000, '0000000000000101000030402000000b0000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x19800000, 0x00000000, '000000000000010b000030402000000b0000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x39100000, 0x00000000, '0000000000000014000030402000000b0000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x49100000, 0x00000000, '000000000b0b0300000030402000000b0000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x2e100000, 0x00000000, '0000000009ffffff000030402000000b0000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x0e130000, 0x00000000, '000000004d593234343643553134000b0000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x1e130000, 0x00000000, '0000000030303233003643553134000b0000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x2e130000, 0x00000000, '0000000030303437003643553134000b0000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x3e130000, 0x00000000, '0000000030313133003643553134000b0000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x4e130000, 0x00000000, '0000000030003133003643553134000b0000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x5e130000, 0x00000000, '0000000041553234333936383632000b0000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x6e130000, 0x00000000, '000000003144313130303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x09110000, 0x00000000, '0000000008c8551ba416021bab16021b20e85601003c381b703c381b0000000005000000000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x01110000, 0x00000000, '000000000000000600303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x11110000, 0x00000000, '000000000000000100303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x21110000, 0x00000000, '000000000000000000303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x31110000, 0x00000000, '000000000000000000303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x44110000, 0x00000000, '000000000000000000303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x54310000, 0x00000000, '000000007fffffff00303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x94310000, 0x00000000, '0000000045ee700000303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x84310000, 0x00000000, '00000000bef0a3d700303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb3, 0x00, 0x41100000, 0x00000400, '000000010000000435333300000000000000000000000000000000000000000030323134000000000000000000000000')
    driver.hej = True
    driver.cmd_copy(BULK_OUT_EP, 0x0a, 0x04, 0x00, 0x4c, 0x00000000, 0x00000000, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    driver.hej = False
    driver.send_param()
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb3, 0x00, 0x31020000, 0x00000400, '00000000000000000000000020e85601894e021bf00e0000d8e3011bffffffff003c381b000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb3, 0x00, 0x41020000, 0x00000400, '000000000000000000303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb3, 0x00, 0x21020000, 0x00000400, '000000010000000000303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x11020000, 0x00000000, '00000000300000000400000001000000003c381b1b36111a000000000000000000000000000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb3, 0x00, 0x11020000, 0x00000400, '000000000000001900303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x10, 0x69, 0x00, 0x01000000, 0x00000000, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x1c, 0xb4, 0x00, 0x00000c00, 0x00000300, '000000000031000000020041000000010000000000000000000000000000000000000000000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x24, 0x15, 0x08, 0x00000110, 0x04000400, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb3, 0x00, 0xa1310000, 0x00000400, '00000001000000000000000020e85601894e021bf00e00005683021bffffffff003c381b000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb3, 0x00, 0xc1310000, 0x00000400, '000000010000000200303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x09110000, 0x00000000, '00000000a4e65601cce65601faee4c7700000000003c381bd8f1920300000000606cc51b000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x01110000, 0x00000000, '000000000000000600303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x11110000, 0x00000000, '000000000000000100303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x21110000, 0x00000000, '000000000000000000303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x31110000, 0x00000000, '000000000000000000303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x10, 0x60, 0x00, 0x00000000, 0x00000000, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x44110000, 0x00000000, '000000000000000000303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x54310000, 0x00000000, '000000007fffffff00303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x94310000, 0x00000000, '0000000045ee700000303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x84310000, 0x00000000, '00000000bef0a3d700303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x10, 0xb6, 0x00, 0x00000000, 0x00000400, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x10, 0xb5, 0x00, 0x00000000, 0x00000400, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x10, 0xb5, 0x00, 0x00000000, 0x00000400, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x10, 0x60, 0x00, 0x00000000, 0x00000000, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x10, 0xb5, 0x00, 0x00000000, 0x00000400, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x10, 0x60, 0x00, 0x00000000, 0x00000000, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x10, 0xb5, 0x00, 0x00000000, 0x00000400, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x10, 0x60, 0x00, 0x00000000, 0x00000000, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x10, 0xb5, 0x00, 0x00000000, 0x00000400, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x10, 0x60, 0x00, 0x00000000, 0x00000000, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x10, 0x60, 0x00, 0x00000000, 0x00000000, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x10, 0xb5, 0x00, 0x00000000, 0x00000400, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x10, 0x60, 0x00, 0x00000000, 0x00000000, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x10, 0xb5, 0x00, 0x00000000, 0x00000400, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x09110000, 0x00000000, '00000000ef2c0976640000000000000013c9011b27c9011b9440061b00000000c8c6551b000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x19110000, 0x00000000, '000000000000000600303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x01110000, 0x00000000, '00000000a500010100303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x61110000, 0x00000000, '000000000000000100303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x71110000, 0x00000000, '000000000000010200303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x81110000, 0x00000000, '000000000000000100303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x91110000, 0x00000000, '000000000000000200303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x54310000, 0x00000000, '000000000000000100303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x94310000, 0x00000000, '0000000045ee700000303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x84310000, 0x00000000, '00000000bef0a3d700303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x01130000, 0x00000000, '0000000045ef5e5200303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x51130000, 0x00000000, '000000000000000200303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x61130000, 0x00000000, '000000000000000100303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x11130000, 0x00000000, '00000000017621e100303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x24140000, 0x00000000, '000000000003040100303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x64140000, 0x00000000, '000000000000000000303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x34140000, 0x00000000, '000000000000000000303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x74140000, 0x00000000, '000000000000000000303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x44140000, 0x00000000, '000000000000000000303935353333000000080000001000000409000010318000040151000000000000000000000000')
    driver.cmd_copy(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, 0x84140000, 0x00000000, '000000000000000000303935353333000000080000001000000409000010318000040151000000000000000000000000')


    # profile = driver.request_profile_block(0x0C00, 0x0100)
    # logging.info("Profile digest: %s", profile[:16].hex())

    # driver.push_compute_params()
    # driver.start_collect(start_cm, stop_cm, resolution)

    # raw_frames = driver.read_spectrum(duration=10.0)
    # if output:
    #     with open(output, "wb") as fh:
    #         for frame in raw_frames:
    #             fh.write(frame.payload)
    #     logging.info("Wrote %d frames to %s", len(raw_frames), output)
    # else:
    #     logging.info("Captured %d frames (no output file specified)", len(raw_frames))

def main(argv: List[str]) -> None:
    args = parse_args(argv)
    configure_logging(args.verbose)
    hej = False
    try:
        run_measurement(
            vendor_id=args.vid,
            product_id=args.pid,
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