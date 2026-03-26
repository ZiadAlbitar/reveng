"""
Prototype USB driver for Cary FTIR instruments using pyusb.

This script manually implements a reverse-engineered USB protocol used by
Cary FTIR spectrometers. Instead of using an official SDK, it builds and
parses raw USB frames.

Key idea:
    We are speaking a custom binary protocol over USB bulk endpoints.
"""

import argparse
import logging
import struct
import sys
import time
from dataclasses import dataclass
from typing import Optional, Tuple, List

import usb.core
import usb.util


# ----------------------------------------------------------------------
# USB endpoint configuration
# ----------------------------------------------------------------------
# These are fixed for the instrument (based on reverse engineering)
BULK_OUT_EP = 0x04        # Host → device (commands)
BULK_IN_PRIMARY = 0x83    # Device → host (control responses)
BULK_IN_SECONDARY = 0x85  # Device → host (streaming data)

DEFAULT_TIMEOUT_MS = 2_000
MAX_PACKET = 512          # Typical USB bulk packet size


# ----------------------------------------------------------------------
# Frame abstraction
# ----------------------------------------------------------------------
@dataclass
class Frame:
    """
    Represents a parsed USB frame from the instrument.

    The protocol structure:
        [16-byte header][payload...]

    Header layout (4 x uint32):
        dword0:
            bits 0-7   = frame type
            bits 8-15  = sequence counter
            bits 24-31 = pipe ID

        dword1:
            bits 0-7   = command ID
            bits 8-15  = status
            bits 16-23 = payload length (LOW BYTE ONLY!)
            bits 24-31 = flags
    """

    type: int          # Frame type (0x08 = command, 0x18 = data, etc.)
    sequence: int      # Sequence counter (mirrors request)
    pipe_id: int       # Logical pipe (NOT USB endpoint)
    command: int       # Command identifier
    status: int        # Status (0x40 = success)
    payload_len: int   # Payload length (truncated to 1 byte)
    flags: int         # Misc flags
    param0: int        # Command-specific parameter
    param1: int        # Command-specific parameter
    payload: bytes     # Remaining data

    def __str__(self) -> str:
        # Human-readable representation for debugging/logging
        return (
            f"Frame(type=0x{self.type:02x}, seq={self.sequence}, pipe=0x{self.pipe_id:02x}, "
            f"cmd=0x{self.command:02x}, status=0x{self.status:02x}, flags=0x{self.flags:02x}, "
            f"len={self.payload_len}, param0=0x{self.param0:08x}, param1=0x{self.param1:08x})"
        )


# ----------------------------------------------------------------------
# Main driver class
# ----------------------------------------------------------------------
class CaryFTIR:
    """
    Low-level USB driver.

    Responsibilities:
        - Build protocol frames
        - Send/receive USB packets
        - Provide helpers for known commands

    This is NOT a high-level API — it mirrors firmware behavior closely.
    """

    def __init__(self, dev: usb.core.Device, interface: int = 0):
        self.dev = dev
        self.interface = interface

        # Rolling sequence counter (1 byte, wraps at 255)
        self.sequence = 0

        self.log = logging.getLogger("CaryFTIR")

        # Tracks which notifications are enabled
        self.current_notification_mask = 0

    # ------------------------------------------------------------------ #
    # USB helpers
    # ------------------------------------------------------------------ #
    def _next_sequence(self) -> int:
        """
        Increment sequence counter (mod 256).

        Every outgoing command must have a unique sequence value.
        The firmware often mirrors this back in responses.
        """
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
        """
        Construct a 16-byte protocol header.

        IMPORTANT:
        - payload_len is truncated to 1 byte (protocol limitation)
        - fields are packed into bitfields inside 32-bit integers
        """

        seq = self._next_sequence()

        # First 32-bit word
        dword0 = (pipe_id << 24) | (0x00 << 16) | (seq << 8) | frame_type

        # Second 32-bit word
        dword1 = (flags << 24) | ((payload_len & 0xFF) << 16) | (status << 8) | command

        # Pack into little-endian binary
        header = struct.pack("<IIII", dword0, dword1, param0, param1)
        return header

    def _write(self, endpoint: int, data: bytes) -> None:
        """
        Send raw bytes to USB endpoint.

        Raises error if not all bytes are written (important for reliability).
        """
        self.log.debug("USB OUT %s", data.hex())

        written = self.dev.write(endpoint, data, timeout=DEFAULT_TIMEOUT_MS)

        if written != len(data):
            raise IOError(f"short write: expected {len(data)} wrote {written}")

    def _read(self, endpoint: int = BULK_IN_PRIMARY, timeout: int = DEFAULT_TIMEOUT_MS) -> bytes:
        """
        Read a raw USB packet.

        Returns:
            bytes object of up to MAX_PACKET size.
        """
        data = bytes(self.dev.read(endpoint, MAX_PACKET, timeout=timeout))
        self.log.debug("USB IN  %s", data.hex())
        return data

    def _recv_frame(self, endpoint: int = BULK_IN_PRIMARY, timeout: int = DEFAULT_TIMEOUT_MS) -> Frame:
        """
        Receive and parse a protocol frame.

        Steps:
            1. Read raw USB data
            2. Validate minimum length
            3. Unpack header
            4. Extract bitfields
            5. Attach payload
        """
        raw = self._read(endpoint, timeout)

        if len(raw) < 16:
            raise IOError("response shorter than header")

        # Unpack first 16 bytes
        d0, d1, param0, param1 = struct.unpack("<IIII", raw[:16])

        # Decode bitfields
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
            payload=raw[16:],  # everything after header
        )
        return frame

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
        """
        High-level send function.

        Combines:
            - header construction
            - payload append
            - USB write
        """
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

    # ------------------------------------------------------------------ #
    # Protocol primitives
    # ------------------------------------------------------------------ #
    def reset_link(self) -> None:
        """
        Special-case reset command.

        Unlike normal frames:
            - uses custom format
            - padded to 64 bytes

        This is required before any other communication.
        """
        seq = self._next_sequence()

        dword0 = (0x00 << 16) | (seq << 8) | 0x0D

        # 64-byte packet: 4-byte header + 60 bytes padding
        reset_packet = struct.pack("<I", dword0) + b"\x00" * 60

        self._write(BULK_OUT_EP, reset_packet)

        frame = self._recv_frame()

        # Validate expected response
        if frame.type != 0x0D or frame.command != 0x07:
            raise IOError(f"unexpected reset reply: {frame}")

        self.log.info("Link reset acknowledged: %s", frame)

    def query_version(self) -> Tuple[int, int]:
        """
        Ask device for version / family info.

        param0 magic value likely selects version query mode.
        """
        self.send_frame(0x08, 0x01, param0=0x00002A01)

        frame = self._recv_frame()

        if frame.status != 0x40 or frame.command != 0x01:
            raise IOError(f"version query failed: {frame}")

        family = frame.param0
        self.log.info("Instrument family 0x%08x", family)

        return family, frame.flags

    def query_runtime_counters(self) -> Tuple[int, int]:
        """
        Retrieve internal device counters.

        Payload contains packed integers.
        Only lower 24 bits are valid.
        """
        self.send_frame(0x08, 0x68)

        frame = self._recv_frame()

        if frame.command != 0x68 or frame.status != 0x40:
            raise IOError(f"counter query failed: {frame}")

        # Extract two 24-bit values from payload
        left = struct.unpack_from("<I", frame.payload, 0)[0] & 0x00FFFFFF
        right = struct.unpack_from("<I", frame.payload, 4)[0] & 0x00FFFFFF

        return left, right
    
    def read_register(self, address: int, length: int) -> bytes:
        """
        Read a block of register/memory data from the instrument.

        Protocol behavior:
        1. Send command 0x18 with param0 = address << 8
        2. Device replies with an ACK frame (may contain first chunk of data)
        3. Remaining data arrives asynchronously on the secondary endpoint (0x85)
            as multiple frames of type 0x18

        This is effectively a "streaming read" split across multiple USB packets.
        """

        # IMPORTANT PROTOCOL DETAIL:
        # The firmware expects the address shifted left by 8 bits.
        # Likely the lower 8 bits are reserved for flags or sub-addressing.
        self.send_frame(0x08, 0x18, param0=address << 8)

        # First response is an ACK (and may include initial data bytes)
        ack = self._recv_frame()

        # Validate that the device accepted the command
        if ack.command != 0x18 or ack.status != 0x40:
            raise IOError(f"register read failed: {ack}")

        # Start accumulating data (ACK may already contain first fragment)
        data = bytearray(ack.payload)

        # IMPORTANT:
        # Additional data does NOT come on the primary endpoint.
        # Instead, it is streamed via:
        #   pipe_id = 0x1C → endpoint 0x85 (secondary bulk IN)
        #
        # We keep reading until we've collected the requested length.
        while len(data) < length:

            # Blocking read from secondary endpoint
            frame = self._recv_frame(endpoint=BULK_IN_SECONDARY)

            # We only care about data frames (type 0x18)
            if frame.type != 0x18:
                # Other frame types may appear (status, notifications, etc.)
                self.log.warning("Unexpected frame while reading register: %s", frame)
                continue

            # Append this chunk of payload data
            data.extend(frame.payload)

        # Return exactly requested number of bytes (truncate if extra arrived)
        return bytes(data[:length])


    def request_profile_block(self, size: int, offset: int) -> bytes:
        """
        Fetch a "profile block" (instrument configuration / accessory table).

        Protocol:
        - Send command 0xB4 with:
                param0 = size (number of bytes requested)
                param1 = offset (starting offset)
        - Device ACKs on primary endpoint
        - Data is streamed back as type 0x18 frames on secondary endpoint

        This behaves almost identically to read_register(), but uses a different command.
        """

        # NOTE:
        # pipe_id=0x1C explicitly routes this request to the data streaming pipe.
        self.send_frame(0x08, 0xB4, pipe_id=0x1C, param0=size, param1=offset)

        # Receive ACK confirming request was accepted
        ack = self._recv_frame()

        if ack.command != 0xB4 or ack.status != 0x40:
            raise IOError(f"profile request rejected: {ack}")

        buffer = bytearray()

        # Stream in chunks until we reach requested size
        while len(buffer) < size:

            # Read from data endpoint (same as register streaming)
            frame = self._recv_frame(endpoint=BULK_IN_SECONDARY)

            if frame.type != 0x18:
                # Ignore non-data frames (can happen due to async notifications)
                self.log.debug("Skipping non-data frame during profile fetch: %s", frame)
                continue

            buffer.extend(frame.payload)

        self.log.info("Fetched %d bytes of profile data", len(buffer))

        return bytes(buffer[:size])


    def set_notifications(self, enable_mask: int, latch_mask: int = 0) -> None:
        """
        Enable/disable asynchronous notifications from the instrument.

        enable_mask:
            Bitmask specifying which events should be sent automatically.
            Example (from usage):
                0x0100 → data ready
                0x0010 → status updates

        latch_mask:
            Likely controls which events are latched vs edge-triggered (unclear).

        Once enabled, notifications may appear interleaved with normal responses.
        """

        # Pack two 32-bit integers into payload
        payload = struct.pack("<II", enable_mask, latch_mask)

        self.send_frame(0x08, 0x69, payload=payload)

        ack = self._recv_frame()

        if ack.command != 0x69 or ack.status != 0x40:
            raise IOError(f"set_notifications failed: {ack}")

        # Store current state locally (useful for debugging / tracking)
        self.current_notification_mask = enable_mask


    def send_heartbeat(self) -> None:
        """
        Send a keep-alive (heartbeat) command.

        Some firmware requires periodic heartbeats to:
        - maintain connection
        - prevent timeout
        - keep acquisition running

        If ignored, device may stop streaming or reset connection.
        """

        self.send_frame(0x08, 0x10)

        frame = self._recv_frame()

        if frame.command != 0x10 or frame.status != 0x40:
            # Not fatal, but worth logging
            self.log.warning("Heartbeat not acknowledged: %s", frame)


    # ------------------------------------------------------------------ #
    # Transfer-ID helpers (commands 0xB6 / 0xB7 / 0xB5)
    # ------------------------------------------------------------------ #

    def allocate_transfer_id(self) -> int:
        """
        Allocate a transfer ID from the firmware.

        This is part of a mini "transfer protocol" layered on top of USB.

        Flow:
        1. Send command 0xB6
        2. Device returns an ID (usually 1 byte)

        The ID is used to track multi-step transfers.
        """

        self.send_frame(0x08, 0xB6)

        frame = self._recv_frame()

        if frame.command != 0xB6 or frame.status != 0x40:
            raise IOError(f"transfer ID allocation failed: {frame}")

        # ID may be returned either:
        #   - in payload (preferred)
        #   - or encoded in param0 fallback
        if frame.payload:
            transfer_id = frame.payload[0]
        else:
            transfer_id = frame.param0 & 0xFF

        self.log.debug("Allocated transfer id 0x%02x", transfer_id)

        return transfer_id


    def upload_block(self, transfer_id: int, channel: int, payload: bytes, param: int = 0) -> None:
        """
        Upload a block of data to the instrument.

        Command 0xB7 is used for sending chunks in a transfer.

        Parameters:
        transfer_id → identifies the transfer session
        channel     → logical destination (firmware-specific)
        payload     → actual data being sent

        Protocol mapping:
        param0 = channel
        param1 = transfer_id
        """

        self.send_frame(
            0x08,
            0xB7,
            payload=payload,
            param0=channel,
            param1=transfer_id,
            pipe_id=0x10,
        )

        ack = self._recv_frame()

        if ack.command != 0xB7 or ack.status != 0x40:
            raise IOError(f"block upload rejected: {ack}")


    def wait_for_transfer(self, transfer_id: int, retries: int = 12, delay: float = 0.25) -> None:
        """
        Poll for transfer completion using command 0xB5.

        Behavior:
        - Device returns status repeatedly
        - 0x40 → success
        - 0x41 → failure
        - otherwise → still in progress

        This is essentially a polling loop (no interrupt/event system).
        """

        for attempt in range(retries):

            # Ask device for transfer status
            self.send_frame(0x08, 0xB5, param0=transfer_id)

            reply = self._recv_frame()

            if reply.command != 0xB5:
                # Ignore unrelated frames (can happen due to async messages)
                self.log.debug("Unexpected frame while waiting for transfer: %s", reply)
                continue

            if reply.status == 0x40:
                # Transfer completed successfully
                return

            if reply.status == 0x41:
                # Explicit failure reported by firmware
                raise IOError(f"Transfer {transfer_id:#02x} failed: {reply}")

            # Still pending → wait before retrying
            time.sleep(delay)

        # If we exit loop → timeout
        raise TimeoutError(f"Transfer {transfer_id:#02x} did not complete")

    # ------------------------------------------------------------------ #
# Collection parameter handling
# ------------------------------------------------------------------ #
    def push_compute_params(
        self,
        is_res: int = 0x0000015C,
        is_phase_pts: int = 0x00000200,
        is_lpad: int = 0x00000080,
        is_rpad: int = 0x000000C8,
        sbeam_apod: int = 0x00000001,
        sbeam_zerofill: int = 0x00000000,
        sbeam_offsetcorr: int = 0x00000000,
        sbeam_phase_type: int = 0x00000001,
    ) -> None:
        """
        Upload computation / signal-processing parameters to the instrument.

        These parameters control how the interferogram is transformed into a spectrum.

        Based on reverse engineering, these likely map to:

        is_res           → interferogram resolution / number of points
        is_phase_pts     → number of points used for phase correction
        is_lpad/rpad     → left/right zero-padding (affects FFT symmetry)
        sbeam_apod       → apodization function (windowing)
        sbeam_zerofill   → zero filling factor (increases spectral resolution)
        sbeam_offsetcorr → offset correction enable/disable
        sbeam_phase_type → phase correction method

        NOTE:
        These are currently "magic defaults" extracted from captured traffic.
        Changing them will affect spectral quality and processing.
        """

        # Pack parameters into a list of 32-bit integers
        payload_words = [
            is_res,
            is_phase_pts,
            is_lpad,
            is_rpad,
            sbeam_apod,
            sbeam_zerofill,
            sbeam_offsetcorr,
            sbeam_phase_type,
        ]

        # Convert to little-endian binary blob
        payload = struct.pack("<" + "I" * len(payload_words), *payload_words)

        # Send command 0xB1 (compute parameter upload)
        self.send_frame(0x08, 0xB1, payload=payload)

        # Wait for acknowledgment
        ack = self._recv_frame()

        if ack.status != 0x40 or ack.command != 0xB1:
            raise IOError(f"compute parameter push failed: {ack}")

        self.log.info("Uploaded compute parameters.")


    # ------------------------------------------------------------------ #
    # Collect orchestration
    # ------------------------------------------------------------------ #
    def start_collect(self, start_cm: float, stop_cm: float, resolution: int, auto_background: bool = True) -> None:
        """
        Initiate a new spectral measurement.

        This is a simplified / partial implementation of the instrument's
        internal "StartNewCollect" routine.

        Intended flow (based on reverse engineering):
        1. Configure processing parameters (done earlier)
        2. Enable notifications so device can push data asynchronously
        3. Clear/ack previous transfers
        4. Send a "start measurement" command (NOT fully decoded yet)

        Parameters:
        start_cm        → starting wavenumber (cm^-1)
        stop_cm         → ending wavenumber (cm^-1)
        resolution      → spectral resolution setting
        auto_background → whether background scan is automatically taken

        IMPORTANT:
        The actual start command payload is still unknown.
        This function currently prepares the system but does NOT fully trigger acquisition.
        """

        # Enable asynchronous notifications from the instrument
        #
        # Bitmask meaning (inferred):
        #   0x0100 → data ready / spectral data blocks
        #   0x0010 → status updates (progress, state changes)
        #
        # Without this, you may not receive streaming data at all.
        self.set_notifications(0x00000110, 0x00000000)

        # Clear or acknowledge any previous transfers / pending state
        #
        # Command 0x19 appears to act like a "flush" or "acknowledge previous session"
        self.send_frame(0x08, 0x19)
        self._recv_frame()

        # NOTE:
        # The real firmware likely sends a complex payload here (multiple commands)
        # to configure scan range, resolution, detector settings, etc.
        #
        # Reverse engineering suggests:
        #   - command family ~0x29xx / 0x2Bxx
        #   - possibly writing to internal "button register" or state machine
        #
        # Currently, we only log the request instead of actually issuing it.
        self.log.info(
            "Start collect requested (start=%s cm^-1, stop=%s cm^-1, res=%d, auto_background=%s)",
            start_cm,
            stop_cm,
            resolution,
            auto_background,
        )

        # TODO:
        #   Capture and replicate the full StartNewCollect command sequence.
        #   This likely involves:
        #     - multiple register writes
        #     - transfer uploads (via B6/B7)
        #     - final trigger command


    def read_spectrum(self, duration: float = 5.0) -> List[Frame]:
        """
        Collect incoming spectral data frames for a fixed time window.

        Behavior:
        - Listens on the secondary endpoint (0x85)
        - Captures frames of type 0x18 (data frames)
        - Ignores/logs other frame types (status, notifications)

        Parameters:
        duration → how long to listen (seconds)

        Returns:
        List of raw Frame objects containing spectral data chunks

        IMPORTANT:
        - There is currently NO proper "end-of-scan" detection
        - This is purely time-based
        - In a full implementation, you would:
                * watch for a completion flag
                * or track expected number of data blocks
        """

        end = time.time() + duration
        frames: List[Frame] = []

        while time.time() < end:
            try:
                # Read from data streaming endpoint
                frame = self._recv_frame(endpoint=BULK_IN_SECONDARY, timeout=500)

            except usb.core.USBError as exc:
                # Some USB timeouts return errno=None → treat as "no data yet"
                if exc.errno is None:
                    continue
                raise

            # Type 0x18 = spectral / interferogram data block
            if frame.type == 0x18:
                frames.append(frame)
                self.log.debug("Data block: %s", frame)
            else:
                # Other frames may include:
                #   - status updates
                #   - progress notifications
                #   - heartbeat responses
                self.log.debug("Status frame on data pipe: %s", frame)

        return frames


# ---------------------------------------------------------------------- #
# High-level orchestration
# ---------------------------------------------------------------------- #
def configure_logging(verbose: bool) -> None:
    """
    Configure global logging.

    verbose=True → DEBUG (shows raw USB traffic)
    verbose=False → INFO (high-level events only)
    """
    level = logging.DEBUG if verbose else logging.INFO
    logging.basicConfig(level=level, format="%(asctime)s %(levelname)s %(name)s: %(message)s")


def find_device(vendor_id: int, product_id: int) -> usb.core.Device:
    """
    Locate and initialize the USB device.

    Steps:
    1. Find device by VID/PID
    2. Detach kernel driver (if OS has claimed it)
    3. Set configuration
    4. Claim interface 0

    Returns:
    usb.core.Device ready for communication
    """

    dev = usb.core.find(idVendor=vendor_id, idProduct=product_id)

    if dev is None:
        raise IOError(f"Device VID=0x{vendor_id:04x} PID=0x{product_id:04x} not found")

    # On Linux/macOS, kernel may already own the interface → must detach
    if dev.is_kernel_driver_active(0):
        dev.detach_kernel_driver(0)

    # Set active configuration (required before I/O)
    dev.set_configuration()

    # Claim interface so we can use it
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
    """
    Full measurement pipeline.

    This orchestrates the entire workflow:
    1. Connect to device
    2. Perform handshake
    3. Query device state
    4. Fetch profile/configuration
    5. Configure processing parameters
    6. Start measurement
    7. Collect spectral data
    8. Save raw output (optional)
    """

    dev = find_device(vendor_id, product_id)
    driver = CaryFTIR(dev)

    # --- Handshake sequence ---
    driver.reset_link()
    driver.query_version()

    # Retrieve internal counters (useful for diagnostics)
    counters = driver.query_runtime_counters()
    logging.info("Runtime counters: %s", counters)

    # Fetch device profile / configuration table
    profile = driver.request_profile_block(0x0C00, 0x0100)
    logging.info("Profile digest: %s", profile[:16].hex())

    # Upload processing parameters (FFT, apodization, etc.)
    driver.push_compute_params()

    # Start measurement (partial implementation)
    driver.start_collect(start_cm, stop_cm, resolution)

    # Collect raw spectral data frames
    raw_frames = driver.read_spectrum(duration=10.0)

    if output:
        # Write raw payloads to file (concatenated)
        with open(output, "wb") as fh:
            for frame in raw_frames:
                fh.write(frame.payload)

        logging.info("Wrote %d frames to %s", len(raw_frames), output)
    else:
        logging.info("Captured %d frames (no output file specified)", len(raw_frames))

def parse_args(argv: List[str]) -> argparse.Namespace:
    """
    Parse command-line arguments.

    This function defines the CLI interface for the script and converts
    user input into a structured object (`argparse.Namespace`).

    Example usage from terminal:
        python script.py --vid 0x0957 --pid 0x1234 --out data.bin --verbose
    """

    # Create argument parser with a description shown in --help
    parser = argparse.ArgumentParser(
        description="Run a Cary FTIR measurement using pyusb."
    )

    # USB vendor ID
    #
    # type=lambda x: int(x, 0) allows flexible input:
    #   "0x0957" → hex
    #   "2391"   → decimal
    #
    # Without base=0, hex strings would fail.
    parser.add_argument(
        "--vid",
        type=lambda x: int(x, 0),
        required=True,
        help="USB vendor ID (e.g. 0x0957)",
    )

    # USB product ID (same parsing logic as VID)
    parser.add_argument(
        "--pid",
        type=lambda x: int(x, 0),
        required=True,
        help="USB product ID",
    )

    # Start wavenumber (higher end of IR spectrum)
    #
    # FTIR convention:
    #   higher → lower frequency region (e.g. 4000 cm^-1)
    parser.add_argument(
        "--start",
        type=float,
        default=4000.0,
        help="Start wavenumber (cm^-1)",
    )

    # Stop wavenumber (lower end of scan)
    parser.add_argument(
        "--stop",
        type=float,
        default=650.0,
        help="Stop wavenumber (cm^-1)",
    )

    # Spectral resolution setting
    #
    # NOTE:
    # This is passed into start_collect(), but currently not fully used
    # since the real command payload is not implemented yet.
    parser.add_argument(
        "--resolution",
        type=int,
        default=4,
        help="Resolution setting (points)",
    )

    # Optional output file path
    #
    # If provided:
    #   → raw spectral payloads will be written to this file
    #
    # If omitted:
    #   → data is only logged (not saved)
    parser.add_argument(
        "--out",
        type=str,
        help="Dump raw spectral payloads to file",
    )

    # Enable verbose logging
    #
    # action="store_true" means:
    #   flag present  → True
    #   flag absent   → False
    #
    # Used to enable DEBUG-level logs (including raw USB traffic)
    parser.add_argument(
        "--verbose",
        action="store_true",
        help="Enable debug logging",
    )

    # Parse provided argv list (NOT sys.argv directly)
    #
    # This design makes the function testable and reusable.
    return parser.parse_args(argv)


def main(argv: List[str]) -> None:
    """
    Entry point for the script.

    Responsibilities:
    1. Parse CLI arguments
    2. Configure logging
    3. Run measurement pipeline
    4. Handle errors gracefully
    """

    # Parse command-line arguments into structured object
    args = parse_args(argv)

    # Configure logging level and format based on --verbose flag
    configure_logging(args.verbose)

    try:
        # Run the full measurement pipeline
        run_measurement(
            vendor_id=args.vid,
            product_id=args.pid,
            start_cm=args.start,
            stop_cm=args.stop,
            resolution=args.resolution,
            output=args.out,
        )

    except Exception as exc:  # pylint: disable=broad-except
        """
        Catch ALL exceptions to prevent ugly crashes.

        This is intentional for CLI tools:
        - ensures clean error message
        - optionally prints stack trace if verbose enabled
        """

        # Log error message
        # exc_info=True → includes full traceback (only if verbose)
        logging.error(
            "Measurement failed: %s",
            exc,
            exc_info=args.verbose
        )

        # Exit with non-zero status (indicates failure to shell)
        sys.exit(1)


# Standard Python entry-point guard
#
# Ensures this file behaves differently when:
#   - run directly       → executes main()
#   - imported as module → does NOT execute
if __name__ == "__main__":
    # Pass sys.argv[1:] (skip script name)
    main(sys.argv[1:])