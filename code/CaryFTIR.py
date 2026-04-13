import usb.util
import usb.core
import struct
import logging

from dataframe import Frame

DEFAULT_TIMEOUT_MS = 2_000
MAX_PACKET = 512

# Default endpoints for the instrument (see docs/usb-protocol.md).
BULK_OUT_EP = 0x04
BULK_IN_PRIMARY = 0x83
BULK_IN_SECONDARY = 0x85

class CaryFTIR:
    def __init__(self, dev: usb.core.Device):
        self.dev = dev
        self.sequence = 0
        self.log = logging.getLogger("CaryFTIR")

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
        self.log.debug("USB IN  %s", data.hex())
        # reading from machine
        data = bytes(self.dev.read(endpoint, MAX_PACKET, timeout=timeout))
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
    