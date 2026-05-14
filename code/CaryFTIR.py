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



import time

import usb.util
import usb.core
import struct
import logging
from typing import Optional, Tuple, List
from dataframe import Frame, Settings
import os
import sys
import argparse
from dataclasses import dataclass


DEFAULT_TIMEOUT_MS = 5_000
MAX_PACKET = 512
MAX_PRIMARY_PACKET = 64


# Default endpoints for the instrument (see docs/usb-protocol.md).
BULK_OUT_EP = 0x04
BULK_OUT_PARAM = 0x06
BULK_IN_PRIMARY = 0x83
BULK_IN_SECONDARY = 0x85

# States
SETUP = 0
CLEAN_PLATE = 1
BACKGROUND_SCAN = 2
MEASUREMENT = 3

# Extra macros
ZERO_PAYLOAD_HEX = bytes.fromhex("00" * 48) # Borde vara öndigt. Testa att ta bort



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


class CaryFTIR:
    def __init__(self, interface: int = 0):
        self.sequence = -1
        self.log = logging.getLogger("CaryFTIR")
        self.interface =  interface
        self.state = SETUP
        self.settings = Settings(None, None)
        self.dev = find_device(self.settings.vendor_id, self.settings.product_id)
        self.measure_count = 0


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
        data = bytes(self.dev.read(endpoint, MAX_PACKET, timeout=timeout))
        self.log.debug("USB IN  %s", data.hex())
        return data
    
    @staticmethod 
    def _is_timeout(exc: usb.core.USBError) -> bool:
        errno = getattr(exc, "errno", None)
        return errno in (60, 110, 116) or "timed out" in str(exc).lower()
        
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
        frame_len : int = 64,
        p_len : int = 0
    ) -> None:
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


    # # fråga efter parametrar
    # def cmd_b2(self) -> None:
    #     self.send_frame(BULK_OUT_EP, 0x08, 0xb2, pipe_id=0x30)
    #     frame = self._recv_frame()
    #     if frame.command != 0xb2:
    #         raise IOError(f"Command b2 failed: {frame}")
    #     self.log.info("Command b2 succeded")
        
    #------------ MAPPA TILL RIKTIGA VARIABLER ------------------
    # 103 paketen skickar våra variabler
    def send_param(self) -> None:
        hex_data = "01 01 00 00 00 04 01 11 00 00 02 00 01 21 00 00 00 80 01 31 00 00 00 c8 01 41 00 00 00 04 31 01 00 00 00 01 31 11 00 00 00 00 31 21 00 00 00 00 31 31 00 00 00 01 31 41 00 00 00 01"
        self.send_frame(
            BULK_OUT_PARAM,
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
    

    def exchange_frame(
        self,
        endpoint: int,
        frame_type: int,
        pipe_id: int,
        command: int,
        flags: int = 0,
        param0: int = 0,
        param1: int = 0,
        payload: object = b'',
        status: int = 0,
        expected_command: Optional[object] = None,
        ) -> Frame:
        if isinstance(payload, bytes):
            payload_bytes = payload
        else:
            # fromhex() städar bort mellanslag och gör om till riktiga bytes
            payload_bytes = bytes.fromhex(str(payload))
        self.send_frame(
            endpoint=endpoint,
            frame_type=frame_type,
            pipe_id=pipe_id,
            command=command,
            status=status,
            flags=flags,
            param0=param0,
            param1=param1,
            payload=payload_bytes
        )
        frame = self._recv_frame()
        if expected_command is None:
            expected_command = 0xb3 if frame_type == 0x0a and command == 0x00 else command
        if isinstance(expected_command, int):
            expected_commands = (expected_command,)
        else:
            expected_commands = tuple(expected_command)
        if frame.command not in expected_commands:
            expected_hex = ", ".join(f"0x{cmd:02x}" for cmd in expected_commands)
            raise IOError(f"Command 0x{command:02x} expected {expected_hex} but got: {frame}")
        self.log.info(f"Command {command:02x} copy works with payload: {payload_bytes.hex()}")
        return frame 
    
    # ------------------------------------------------------------------ #
    # High-level functions
    # ------------------------------------------------------------------ #
    def establish_connection(self):
        """ Connects to device and performs the intial handshake """
        vendor_id = self.settings.vendor_id
        product_id = self.settings.product_id

        
            # Intial step of the hand shake, just an empty payload starting with 0x0d
        def reset_link(driver: CaryFTIR) -> None:
            """
            Issue the link reset (type 0x0D).
            """
            driver.send_frame(BULK_OUT_EP, 0x0d, 0x00)
            frame = driver._recv_frame()
            # Check if received frame looks right
            if frame.type != 0x0D or frame.command != 0x07:
                raise IOError(f"unexpected reset reply: {frame}")
            driver.log.info("Link reset acknowledged: %s", frame)

        
        def query_version(driver: CaryFTIR) -> Tuple[int, int]:
            """Send cmd=0x01 and return (family, status_flags)."""
            driver.send_frame(BULK_OUT_EP, 0x08, 0x01, param0=0x00002A01)
            frame = driver._recv_frame()
            if frame.command != 0x01:
                raise IOError(f"version query failed: {frame}")
            family = frame.param0
            driver.log.info("Instrument family 0x%08x", family)
            return family, frame.flags

        def cmd_19(driver: CaryFTIR) -> None:
            driver.send_frame(BULK_OUT_EP, 0x08, 0x19)
            frame = driver._recv_frame()
            if frame.command != 0x19:
                raise IOError(f"Command 19 failed: {frame}")
            driver.log.info("Command 19 succeded")

        def query_runtime_counters(driver: CaryFTIR) -> Tuple[int, int]:
            """Send cmd=0x68 and return the 24-bit counters from the payload."""
            driver.send_frame(BULK_OUT_EP, 0x08, 0x68)
            frame = driver._recv_frame()
            if frame.command != 0x68:
                raise IOError(f"counter query failed: {frame}")
            # Counters arrive as 0x10 payload bytes; pack them from the payload.
            left = struct.unpack_from("<I", frame.payload, 0)[0] & 0x00FFFFFF
            right = struct.unpack_from("<I", frame.payload, 4)[0] & 0x00FFFFFF
            return left, right
    
        reset_link(self)
        query_version(self)
        cmd_19(self)
        counters = query_runtime_counters(self)
        logging.info("Runtime counters: %s", counters)
    
    
    def param_config(self):
        self.read_register(0x40)
        self.read_register(0x20)

        def chain_b2(param0: int, payload: bytes) -> bytes:
            frame = self.exchange_frame(BULK_OUT_EP, 0x08, 0x30, 0xb2, 0x00, param0, 0x00000000, payload)
            return frame.payload
        def chain_b3(param0: int, param1: int, payload: bytes) -> bytes:
            frame = self.exchange_frame(BULK_OUT_EP, 0x08, 0x30, 0xb3, 0x00, param0, param1, payload)
            return frame.payload
        
        self.exchange_frame(BULK_OUT_EP, 0x08, 0x1c, 0xb4, 0x00, 0x00000c00, 0x00000100, '000000000031000000010041000000010000000000000000000000000000000000000000000000000000000000000000')
        
        payload = bytes.fromhex('0000000044823a7718e0ec150000ec15247a641618000000d007f00f64000000e09cec15000000000000000000000000')
        payload = chain_b2(0x19700000, payload)

        for param0 in (
        0x39700000, 0x49700000, 0x19800000, 0x39100000, 0x49100000,
        0x2e100000, 0x0e130000, 0x1e130000, 0x2e130000, 0x3e130000,
        0x4e130000, 0x5e130000, 0x6e130000):
            payload = chain_b2(param0, payload)

        payload = bytes.fromhex('00000000d8c2ec15a4166c10ab166c1084e64f0178298e10e8298e100000000005000000000000000000000000000000')
        payload = chain_b2(0x09110000, payload)
        for param0 in (
            0x01110000, 0x11110000, 0x21110000, 0x31110000, 0x44110000,
            0x54310000, 0x94310000, 0x84310000,):
            payload = chain_b2(param0, payload)
        payload = bytes.fromhex('000000010000000435333300000000000000000000000000000000000000000030323134000000000000000000000000')
        self.exchange_frame(BULK_OUT_EP, 0x08, 0x30, 0xb3, 0x00, 0x4110,  0x00000400, payload)
        self.exchange_frame(BULK_OUT_EP, 0x0a, 0x04, 0x00, 0x4c, 0x0000,  0x00000400)
        self.send_param()
        self.exchange_frame(BULK_OUT_EP, 0x08, 0x30, 0xb3, 0x00, 0x31020000, 0x00000400, '00000000000000000000000084e64f01894e6c10cc0c0000d8e36b10ffffffff78298e10000000000000000000000000')
        self.exchange_frame(BULK_OUT_EP, 0x08, 0x30, 0xb3, 0x00, 0x41020000, 0x00000400, '000000000000000000303935353333000000000004051000022401000991108000060141000000000000000000000000')
        self.exchange_frame(BULK_OUT_EP, 0x08, 0x30, 0xb3, 0x00, 0x21020000, 0x00000400, '000000010000000000303935353333000000000004051000022401000991108000060141000000000000000000000000')
        payload = chain_b2(0x11020000, bytes.fromhex('0000000030000000040000000100000078298e101b36e90f000000000000000000000000000000000000000000000000'))
        payload = chain_b3(0x11020000, 0x00000400, payload)
        self.exchange_frame(BULK_OUT_EP, 0x08, 0x10, 0x69, 0x00, 0x01000000, 0x00000000, '00' * 48)
        self.exchange_frame(BULK_OUT_EP, 0x08, 0x1c, 0xb4, 0x00, 0x00000c00, 0x00000300, '000000000031000000020041000000010000000000000000000000000000000000000000000000000000000000000000')
        self.exchange_frame(BULK_OUT_EP, 0x08, 0x24, 0x15, 0x08, 0x00000110, 0x04000400, '00' * 48)
        self.exchange_frame(BULK_OUT_EP, 0x08, 0x30, 0xb3, 0x00, 0xa1310000, 0x00000400, '00000001000000000000000084e64f01894e6c10cc0c000056836c10ffffffff78298e10000000000000000000000000')
        self.exchange_frame(BULK_OUT_EP, 0x08, 0x30, 0xb3, 0x00, 0xc1310000, 0x00000400, '000000010000000200303935353333000000000004051000022401000991108000060141000000000000000000000000')

        payload = chain_b2(0x09110000, bytes.fromhex('00000000c402000018e54f01f63e367718e5ec1578298e10389b64030000000030e54f01000000000000000000000000'))
        for param0 in (
            0x01110000, 0x11110000, 0x21110000, 0x31110000, 0x44110000,
            0x54310000, 0x94310000, 0x84310000,
        ):
            payload = chain_b2(param0, payload)
        self.exchange_frame(BULK_OUT_EP, 0x08, 0x10, 0xb6, 0x00, 0x00000000, 0x00000400, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')

        for _ in range(7):
            self.exchange_frame(BULK_OUT_EP, 0x08, 0x10, 0xb5, 0x00, 0x00000000, 0x00000400, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
            self.exchange_frame(BULK_OUT_EP, 0x08, 0x10, 0x60, 0x00, 0x00000000, 0x00000000, '000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000')
        payload = chain_b2(0x09110000, bytes.fromhex('00000000df557576640000000000000013c96b1027c96b10944070100000000098c1ec15000000000000000000000000'))

        for param0 in (
            0x19110000, 0x01110000, 0x61110000, 0x71110000, 0x81110000,
            0x91110000, 0x54310000, 0x94310000, 0x84310000, 0x01130000,
            0x51130000, 0x61130000, 0x11130000, 0x24140000, 0x64140000,
            0x34140000, 0x74140000, 0x44140000, 0x84140000,
        ):
            payload = chain_b2(param0, payload)

    def cmd_60_status_poll(self) -> Frame:
        return self.exchange_frame(
            BULK_OUT_EP,
            0x08,
            0x10,
            0x60,
            0x00,
            0x00000000,
            0x00000000,
            ZERO_PAYLOAD_HEX,
        ) # Funktioner inför measurement stream

    def cmd_64_ack_and_data(self, secondary_reads: int = 0, secondary_timeout: int = 1_000) -> Tuple[Frame, List[bytes]]:
        ack = self.exchange_frame(
            BULK_OUT_EP,
            0x08,
            0x10,
            0x64,
            0x00,
            0x00000000,
            0x00000000,
            ZERO_PAYLOAD_HEX,
            status=self.measure_count,
            expected_command=(0x00),
        )
        secondary = []
        for _ in range(secondary_reads):
            try:
                secondary.append(self._read_secondary(timeout=secondary_timeout))
            except usb.core.USBError as exc:
                if self._is_timeout(exc):
                    break
                raise
        return ack, secondary
        # Funktioner inför measurement stream

    def start_measurement_stream(self, pre_measure_polls: int , poll_delay: float) -> List[bytes]:
        for _ in range(pre_measure_polls):
            time.sleep(poll_delay)
            self.cmd_60_status_poll()

        self.exchange_frame(
            BULK_OUT_EP,
            0x08,
            0x10,
            0x62,
            0x00,
            0x00400000,
            0x00000000,
            ZERO_PAYLOAD_HEX,
        )
        _, profile_dump = self.cmd_64_ack_and_data(secondary_reads=2, secondary_timeout=1_000)

        self.exchange_frame(
            BULK_OUT_EP,
            0x08,
            0x10,
            0x63,
            0x00,
            0x00000000,
            0x00000000,
            ZERO_PAYLOAD_HEX,
        )
        self.exchange_frame(
            BULK_OUT_EP,
            0x08,
            0x10,
            0x62,
            0x00,
            0x01000000,
            0x00000000,
            ZERO_PAYLOAD_HEX,
        )
        self.cmd_64_ack_and_data(secondary_reads=0)
        self.measure_count = (self.measure_count + 1) & 0xFF
        return profile_dump # Nytt
    
    def read_measurement_stream(
        self,
        duration: float,
        max_frames: int,
        output: Optional[str],
        timeout_ms: int = 1_000,
    ) -> Tuple[int, int]:
        deadline = time.monotonic() + duration
        frame_count = 0
        byte_count = 0
        out_file = open(output, "wb") if output else None
        try:
            while frame_count < max_frames and time.monotonic() < deadline:
                try:
                    raw = self._read_secondary(timeout=timeout_ms)
                except usb.core.USBError as exc:
                    print("except")
                    if self._is_timeout(exc):
                        break
                    if getattr(exc, "errno", None) == 32:
                        if frame_count:
                            self.log.info("Endpoint 0x%02x stalled after data stream ended", BULK_IN_SECONDARY)
                        else:
                            self.log.warning("Endpoint 0x%02x stalled before data arrived", BULK_IN_SECONDARY)
                        break
                    raise
                frame_count += 1
                byte_count += len(raw)
                if out_file:
                    out_file.write(raw)
        finally:
            if out_file:
                out_file.close()

        return frame_count, byte_count # Nytt

    def plot_measurement_file(self, raw_path: str, plot_path: str, show_plot: bool) -> dict:
        plot_dir = os.path.abspath(os.path.join(os.path.dirname(__file__), "..", "plotting_spectra"))
        if not os.path.isdir(plot_dir):
            raise FileNotFoundError(f"plotting_spectra directory not found at {plot_dir}")

        inserted = False
        if plot_dir not in sys.path:
            sys.path.insert(0, plot_dir)
            inserted = True
        try:
            #TODO: VIKTOR IMPORTERA DIN DEL
            from run import plot_raw_measurement

            return plot_raw_measurement(raw_path, output_png=plot_path, show=show_plot)
        finally:
            if inserted:
                try:
                    sys.path.remove(plot_dir)
                except ValueError:
                    pass
        # Nytt, lär göra egen


    def get_measurement(
            self, 
            pre_measure_polls: int, 
            poll_delay: float,
            data_seconds: float,
            max_data_frames: int,
            output: Optional[str],
            plot_enabled: bool,
            show_plot: bool,
            plot_output: Optional[str]):
        logging.info("Starting measurement sequence")
        profile_dump = self.start_measurement_stream(pre_measure_polls, poll_delay)
        logging.info("Read %d profile/config packets before acquisition", len(profile_dump))
        frame_count, byte_count = self.read_measurement_stream(
            duration=data_seconds,
            max_frames=max_data_frames,
            output=output,
        )
        if output:
            logging.info("Captured %d data packets (%d bytes) to %s", frame_count, byte_count, output)
        else:
            logging.info("Captured %d data packets (%d bytes); use --out to save them", frame_count, byte_count)

        if False:#plot_enabled and output and frame_count:
            if plot_output:
                plot_path = plot_output
            else:
                stem, _ = os.path.splitext(output)
                plot_path = f"{stem}_plot.png"
            try:
                logging.info("Plotting measurement from %s to %s (show_plot=%s)", output, plot_path, show_plot)
                plot_stats = self.plot_measurement_file(output, plot_path, show_plot)
                logging.info("Plotted measurement to %s (%s)", plot_path, plot_stats)
            except ModuleNotFoundError as exc:
                missing = exc.name or str(exc)
                logging.error(
                    "Plotting failed because Python package '%s' is not installed. "
                    "Install plotting dependencies with: python -m pip install numpy matplotlib",
                    missing,
                    exc_info=True,
                )
            except Exception as exc:  # pylint: disable=broad-except
                logging.error("Plotting failed: %s", exc, exc_info=True)
        elif plot_enabled and not output:
            logging.warning("Skipping plot because no --out file was provided")


    def shut_down(self):
        self.send_frame(BULK_OUT_EP, 0x08, 0x15,
                        pipe_id=0x24,
                        flags=0x08,
                        param0=0x00000111,
                        param1=0x04000400)
        self._recv_frame()

        self.send_frame(BULK_OUT_EP, 0x08, 0xd5,
                        pipe_id=0x10,
                        flags=0x02)
        self._recv_frame() 

  
# def run_measurement(driver: CaryFTIR) -> None:
#     driver.establish_connection()

#     driver.param_config()
#     driver.get_measurement(
#         driver.settings.pre_measure_polls,
#         driver.settings.poll_delay,
#         driver.settings.data_seconds,
#         driver.settings.max_data_frames,
#         driver.settings.output,
#         driver.settings.plot_enabled,
#         driver.settings.show_plot,
#         driver.settings.plot_output
#     )

            


def parse_args(argv: List[str]) -> argparse.Namespace:
    parser = argparse.ArgumentParser(description="Run a Cary FTIR measurement using pyusb.")
    parser.add_argument("--vid", type=lambda x: int(x, 0), default=4020, help="USB vendor ID (e.g. 0x0957)")
    parser.add_argument("--pid", type=lambda x: int(x, 0), default=513, help="USB product ID")
    parser.add_argument("--start", type=float, default=4000.0, help="Start wavenumber (cm^-1)")
    parser.add_argument("--stop", type=float, default=650.0, help="Stop wavenumber (cm^-1)")
    parser.add_argument("--resolution", type=int, default=4, help="Resolution setting (points)")
    parser.add_argument("--out", type=str, help="Dump raw spectral payloads to file")
    parser.add_argument("--verbose", action="store_true", help="Enable debug logging")
    # TODO: Funktion som ändrar driver.settings beroende på args
    return parser.parse_args(argv)

def configure_logging(verbose: bool) -> None:
    if verbose:
        level = logging.DEBUG
    else:
        level = logging.INFO
    logging.basicConfig(level=level, format="%(asctime)s %(levelname)s %(name)s: %(message)s")
    

def main(argv: List[str]) -> None:
    args = parse_args(argv)
    configure_logging(args.verbose)
    driver = CaryFTIR()

    try: 
        driver.establish_connection()
    except Exception as exc:
        logging.error("Connection or handshake failed: %s", exc, exc_info=args.verbose)
        sys.exit(1)
    
    try: 
        driver.param_config()
    except Exception as exc:
        logging.error("Parameter config failed: %s", exc, exc_info=args.verbose)
        sys.exit(1)
        
    for i in range(1):
        try:
            driver.get_measurement(
                driver.settings.pre_measure_polls,
                driver.settings.poll_delay,
                driver.settings.data_seconds,
                driver.settings.max_data_frames,
                driver.settings.output,
                driver.settings.plot_enabled,
                driver.settings.show_plot,
                driver.settings.plot_output
            )
        except Exception as exc:  # pylint: disable=broad-except
            logging.error("Measurement failed: %s", exc, exc_info=args.verbose)
            sys.exit(1)

    driver.shut_down()

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