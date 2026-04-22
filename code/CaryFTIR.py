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

DEFAULT_TIMEOUT_MS = 2_000
MAX_PACKET = 512

# Default endpoints for the instrument (see docs/usb-protocol.md).
BULK_OUT_EP = 0x04
BULK_IN_PRIMARY = 0x83
BULK_IN_SECONDARY = 0x85

backend = usb.backend.libusb1.get_backend()
print(backend)
breakpoint()

class CaryFTIR:
    def __init__(self, dev: usb.core.Device, interface: int = 0):
        self.dev = dev
        self.sequence = 0
        self.log = logging.getLogger("CaryFTIR")
        self.interface =  interface

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
        dword1 = (flags << 24) | ((payload_len & 0xFF) << 16) | (status << 8) | command
        header = struct.pack("<IIII", dword0, dword1, param0, param1)
        return header
    
    def _build_measurement_header():
        # The measurements have a different header
        pass
        
    
    def _write(self, endpoint: int, data: bytes) -> None:
        # Just logging debug info
        self.log.debug("USB OUT %s", data.hex())
        # Sending write to machine
        written = self.dev.write(endpoint, data, timeout=DEFAULT_TIMEOUT_MS)
        if written != len(data):
            raise IOError(f"short write: expected {len(data)} wrote {written}")
        
    def _read(self, endpoint: int = BULK_IN_PRIMARY, timeout: int = DEFAULT_TIMEOUT_MS) -> bytes:
        # Logging debug info
        # reading from machine
        data = bytes(self.dev.read(endpoint, MAX_PACKET, timeout=timeout))
        self.log.debug("USB IN  %s", data.hex())
        return data
    # receives a frame 
    def _recv_frame(self, endpoint: int = BULK_IN_PRIMARY, timeout: int = DEFAULT_TIMEOUT_MS) -> Frame:
        raw = self._read(endpoint, timeout)
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
        frame_type: int,
        command: int,
        *,
        pipe_id: int = 0x10,
        payload: bytes = b"",
        flags: int = 0,
        param0: int = 0,
        param1: int = 0,
    ) -> None:
        header = self._build_header(
            frame_type,
            command,
            pipe_id=pipe_id,
            flags=flags,
            payload_len=len(payload),
            param0=param0,
            param1=param1,
        )
        self._write(BULK_OUT_EP, header + payload)

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
        self.send_frame(0x08, 0x01, param0=0x00002A01)
        frame = self._recv_frame()
        if frame.status != 0x40 or frame.command != 0x01:
            raise IOError(f"version query failed: {frame}")
        family = frame.param0
        self.log.info("Instrument family 0x%08x", family)
        return family, frame.flags
    
    def query_runtime_counters(self) -> Tuple[int, int]:
        """Send cmd=0x68 and return the 24-bit counters from the payload."""
        self.send_frame(0x08, 0x68)
        frame = self._recv_frame()
        if frame.command != 0x68 or frame.status != 0x40:
            raise IOError(f"counter query failed: {frame}")
        # Counters arrive as 0x10 payload bytes; pack them from the payload.
        left = struct.unpack_from("<I", frame.payload, 0)[0] & 0x00FFFFFF
        right = struct.unpack_from("<I", frame.payload, 4)[0] & 0x00FFFFFF
        return left, right

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
    dev = usb.core.find(idVendor=vendor_id, idProduct=product_id, backend=backend)
    if not isinstance(dev, usb.core.Device):
        raise IOError(f"Device VID=0x{vendor_id:04x} PID=0x{product_id:04x} not found")
    if os.name == "posix":
        if dev.is_kernel_driver_active(0):
            dev.detach_kernel_driver(0)
        dev.set_configuration()
        usb.util.claim_interface(dev, 0)
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
    counters = driver.query_runtime_counters()
    logging.info("Runtime counters: %s", counters)

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