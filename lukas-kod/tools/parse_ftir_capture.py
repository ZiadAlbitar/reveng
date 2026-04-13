#!/usr/bin/env python3
from __future__ import annotations

import argparse
import math
import subprocess
from collections import Counter, OrderedDict
from dataclasses import dataclass
from pathlib import Path
from statistics import mean
from typing import Iterable


@dataclass
class Frame:
    number: int
    time_s: float
    src: str
    dst: str
    frame_len: int
    capdata: bytes


@dataclass
class Segment:
    seq: int
    msg_type: int
    body_len: int
    start_frame: int
    start_time_s: float
    end_frame: int
    end_time_s: float
    final_usb_len: int
    body: bytes

    @property
    def is_small(self) -> bool:
        return self.body_len < 1000

    @property
    def is_large(self) -> bool:
        return self.body_len == 234060


def run_tshark(pcap_path: Path) -> list[Frame]:
    cmd = [
        "tshark",
        "-r",
        str(pcap_path),
        "-Y",
        "usb.capdata",
        "-T",
        "fields",
        "-E",
        "separator=\t",
        "-e",
        "frame.number",
        "-e",
        "frame.time_relative",
        "-e",
        "_ws.col.Source",
        "-e",
        "_ws.col.Destination",
        "-e",
        "frame.len",
        "-e",
        "usb.capdata",
    ]
    res = subprocess.run(cmd, capture_output=True, text=True, check=True)
    frames: list[Frame] = []
    for line in res.stdout.splitlines():
        number_s, time_s, src, dst, frame_len_s, hexdata = line.split("\t")
        frames.append(
            Frame(
                number=int(number_s),
                time_s=float(time_s),
                src=src,
                dst=dst,
                frame_len=int(frame_len_s),
                capdata=bytes.fromhex(hexdata),
            )
        )
    return frames


def detect_measurement_endpoint(frames: Iterable[Frame]) -> str:
    candidates = Counter(
        frame.src
        for frame in frames
        if frame.dst == "host"
        and frame.src.endswith(".5")
        and frame.frame_len in {105, 111, 316, 389, 539}
    )
    if not candidates:
        raise ValueError("could not find a candidate measurement endpoint ending in .5")
    return candidates.most_common(1)[0][0]


def parse_segments(frames: Iterable[Frame], endpoint: str) -> list[Segment]:
    ep_frames = [f for f in frames if f.src == endpoint and f.dst == "host"]
    segments: list[Segment] = []
    acc = bytearray()
    start: Frame | None = None
    for frame in ep_frames:
        if start is None:
            start = frame
        acc.extend(frame.capdata)
        if frame.frame_len != 539:
            raw = bytes(acc)
            seq = int.from_bytes(raw[0:2], "little")
            msg_type = int.from_bytes(raw[2:4], "little")
            body_len = int.from_bytes(raw[4:8], "big")
            body = raw[8:]
            if len(body) != body_len:
                raise ValueError(
                    f"segment ending at frame {frame.number} has body_len={body_len}, "
                    f"actual={len(body)}"
                )
            segments.append(
                Segment(
                    seq=seq,
                    msg_type=msg_type,
                    body_len=body_len,
                    start_frame=start.number,
                    start_time_s=start.time_s,
                    end_frame=frame.number,
                    end_time_s=frame.time_s,
                    final_usb_len=frame.frame_len,
                    body=body,
                )
            )
            acc = bytearray()
            start = None
    return segments


def decode_tlv6(body: bytes) -> OrderedDict[int, int] | None:
    if len(body) % 6:
        return None
    out: OrderedDict[int, int] = OrderedDict()
    for off in range(0, len(body), 6):
        tag = int.from_bytes(body[off : off + 2], "big")
        value = int.from_bytes(body[off + 2 : off + 6], "big")
        out[tag] = value
    return out


def control_endpoint_for(data_endpoint: str) -> str:
    prefix, _, _ = data_endpoint.rpartition(".")
    return f"{prefix}.4"


def find_sample_boundary(
    frames: list[Frame], small_segments: list[Segment], data_endpoint: str
) -> tuple[Segment, list[Frame]] | None:
    parsed = [(seg, decode_tlv6(seg.body)) for seg in small_segments]
    control_endpoint = control_endpoint_for(data_endpoint)
    for idx in range(1, len(parsed)):
        prev_seg, prev_tlvs = parsed[idx - 1]
        seg, tlvs = parsed[idx]
        if not prev_tlvs or not tlvs:
            continue
        if prev_tlvs.get(0x0031) == 2 and tlvs.get(0x0031) == 3:
            controls = [
                f
                for f in frames
                if f.src == "host"
                and f.dst == control_endpoint
                and f.frame_len == 91
                and prev_seg.end_frame <= f.number <= seg.start_frame
                and len(f.capdata) >= 5
                and f.capdata[2:5] == b"\x00\x30\xb2"
            ]
            return seg, controls
    return None


def signed24_be(data: bytes) -> int:
    value = int.from_bytes(data, "big")
    if value & 0x800000:
        value -= 1 << 24
    return value


def decode_record_stream(body: bytes) -> list[tuple[int, int]]:
    out: list[tuple[int, int]] = []
    for off in range(0, len(body), 4):
        rec = body[off : off + 4]
        if len(rec) < 4:
            break
        out.append((rec[0], signed24_be(rec[1:4])))
    return out


def split_even_odd_records(body: bytes) -> tuple[list[int], list[int]]:
    even_vals: list[int] = []
    odd_vals: list[int] = []
    for tag, value in decode_record_stream(body):
        if tag & 1:
            odd_vals.append(value)
        else:
            even_vals.append(value)
    return even_vals, odd_vals


def peak_index(values: list[int | float]) -> int:
    return max(range(len(values)), key=lambda idx: abs(values[idx]))


def linear_resample(values: list[int], out_len: int = 1024) -> list[float]:
    out: list[float] = []
    for out_idx in range(out_len):
        x = out_idx * (len(values) - 1) / (out_len - 1)
        left = math.floor(x)
        right = min(left + 1, len(values) - 1)
        frac = x - left
        out.append(values[left] * (1.0 - frac) + values[right] * frac)
    return out


def peak_summary(values: list[int]) -> dict[str, float]:
    raw_idx = peak_index(values)
    raw_peak = values[raw_idx]
    resampled = linear_resample(values, 1024)
    resampled_idx = peak_index(resampled)
    resampled_peak = resampled[resampled_idx]
    return {
        "count": float(len(values)),
        "raw_peak": float(raw_peak),
        "raw_peak_scaled": abs(raw_peak) / 256.0,
        "raw_peak_idx": float(raw_idx),
        "raw_min": float(min(values)),
        "raw_max": float(max(values)),
        "resampled_peak": float(resampled_peak),
        "resampled_peak_scaled": abs(resampled_peak) / 256.0,
        "resampled_peak_idx": float(resampled_idx),
    }


def is_diagnostic_capture(segments: list[Segment]) -> bool:
    body_lens = Counter(seg.body_len for seg in segments)
    return body_lens[354] == 1 and body_lens[281] == 1 and body_lens[234060] > 0


def print_segment_header(endpoint: str, segments: list[Segment]) -> None:
    print(f"{endpoint} message framing")
    print(f"  total segments: {len(segments)}")
    print(f"  large data segments: {sum(seg.is_large for seg in segments)}")
    print(f"  small state segments: {sum(seg.is_small for seg in segments)}")
    print()
    print("Segment header")
    print("  bytes 0..1: little-endian sequence counter")
    print("  bytes 2..3: constant 0x1044")
    print("  bytes 4..7: big-endian body length")
    print()


def print_export_summary(frames: list[Frame], endpoint: str, segments: list[Segment]) -> None:
    small = [s for s in segments if s.is_small]
    large = [s for s in segments if s.is_large]

    print_segment_header(endpoint, segments)
    print("Repeated stream pattern")
    print("  large body length: 234060 bytes")
    print("  startup small body length: 582 bytes")
    print("  later small body length: 588 bytes")
    print()

    print("First 12 small-state messages")
    for idx, seg in enumerate(small[:12]):
        tlvs = decode_tlv6(seg.body)
        state = tlvs.get(0x0031) if tlvs else None
        flag_21 = tlvs.get(0x0021) if tlvs else None
        flag_141 = tlvs.get(0x0141) if tlvs else None
        flag_211 = tlvs.get(0x0211) if tlvs else None
        print(
            f"  idx={idx:02d} seq=0x{seg.seq:04x} "
            f"frame={seg.start_frame} time={seg.start_time_s:.6f}s "
            f"body={seg.body_len} state_0031={state} tag_0021={flag_21} "
            f"tag_0141={flag_141} tag_0211={flag_211}"
        )
    print()

    print("State transitions from small-state TLVs")
    prev_state: int | None = None
    for idx, seg in enumerate(small):
        tlvs = decode_tlv6(seg.body)
        if not tlvs:
            continue
        state = tlvs.get(0x0031)
        if state != prev_state:
            print(
                f"  idx={idx:02d} seq=0x{seg.seq:04x} "
                f"frame={seg.start_frame} time={seg.start_time_s:.6f}s "
                f"body={seg.body_len} state_0031={state}"
            )
            prev_state = state
    print()

    boundary = find_sample_boundary(frames, small, endpoint)
    if boundary is None:
        print("No sample boundary heuristic matched.")
        return

    boundary_seg, controls = boundary
    print("Most likely sample/acquisition start")
    print(
        f"  state change frame={boundary_seg.start_frame} "
        f"time={boundary_seg.start_time_s:.6f}s"
    )
    print(
        "  reason: first small-state message where tag 0x0031 changes 2 -> 3 "
        "and body length changes 582 -> 588"
    )
    if controls:
        print(f"  preceding host->{control_endpoint_for(endpoint)} control frames:")
        for frame in controls:
            print(
                f"    frame={frame.number} time={frame.time_s:.6f}s "
                f"len={frame.frame_len} payload_head={frame.capdata[:16].hex()}"
            )
    print()

    if not large:
        return

    first_even, first_odd = split_even_odd_records(large[0].body)
    first_even_summary = peak_summary(first_even)
    first_odd_summary = peak_summary(first_odd)

    print("Link To Diagnostic Model")
    print(
        "  the same 4-byte record model also fits the original capture:"
    )
    print("  1-byte class + 24-bit signed big-endian value")
    print(
        f"  first large message even-class raw peak: "
        f"{first_even_summary['raw_peak_scaled']:.1f}"
    )
    print(
        f"  first large message odd-class raw peak: "
        f"{first_odd_summary['raw_peak_scaled']:.1f}"
    )
    print(
        f"  first large message even-class resampled peak: "
        f"{first_even_summary['resampled_peak_scaled']:.1f} "
        f"at index {int(first_even_summary['resampled_peak_idx'])}"
    )

    state = None
    peak_tag = None
    rows: list[tuple[int | None, float | None, float]] = []
    for seg in segments:
        if seg.is_small:
            tlvs = decode_tlv6(seg.body)
            state = tlvs.get(0x0031) if tlvs else None
            peak_tag = tlvs.get(0x0231) / 256.0 if tlvs and 0x0231 in tlvs else None
        elif seg.is_large:
            even_vals, _ = split_even_odd_records(seg.body)
            even_peak = peak_summary(even_vals)
            rows.append((state, peak_tag, even_peak["raw_peak_scaled"]))

    for state_value in [2, 3, 4, 5]:
        state_rows = [row for row in rows if row[0] == state_value]
        if not state_rows:
            continue
        avg_even = mean(row[2] for row in state_rows)
        peak_rows = [row[1] for row in state_rows if row[1] is not None]
        if peak_rows:
            print(
                f"  state {state_value}: avg tag 0x0231={mean(peak_rows):.1f}, "
                f"avg even-class raw peak={avg_even:.1f}"
            )
        else:
            print(
                f"  state {state_value}: avg even-class raw peak={avg_even:.1f}"
            )


def print_diagnostic_summary(endpoint: str, segments: list[Segment]) -> None:
    small = [seg for seg in segments if seg.body_len == 588]
    large = [seg for seg in segments if seg.body_len == 234060]
    first_small = decode_tlv6(small[0].body) if small else None
    first_even, first_odd = split_even_odd_records(large[0].body)
    first_even_summary = peak_summary(first_even)
    first_odd_summary = peak_summary(first_odd)

    print_segment_header(endpoint, segments)
    print("Repeated diagnostic pattern")
    print("  startup body lengths: 354 bytes, 281 bytes")
    print("  repeating body lengths: 588 bytes, 234060 bytes")
    print()

    if first_small:
        print("Small-state TLVs")
        print(f"  tag 0x0031: {first_small.get(0x0031)}")
        print(f"  tag 0x1201 IR gain: {first_small.get(0x1201)}")
        print(f"  tag 0x1211 laser gain: {first_small.get(0x1211)}")
        print()

    even_scaled = []
    odd_scaled = []
    even_pos = []
    for seg in large:
        even_vals, odd_vals = split_even_odd_records(seg.body)
        even_peak = peak_summary(even_vals)
        odd_peak = peak_summary(odd_vals)
        even_scaled.append(even_peak["raw_peak_scaled"])
        odd_scaled.append(odd_peak["raw_peak_scaled"])
        even_pos.append(even_peak["resampled_peak_idx"])

    print("Large diagnostic body")
    print("  interpreted as 58515 x 4-byte records")
    print("  record layout: 1-byte class + 24-bit signed big-endian value")
    print()

    print("First large message, even-class subsequence")
    print(f"  point count: {int(first_even_summary['count'])}")
    print(
        f"  raw min/max: {int(first_even_summary['raw_min'])} / "
        f"{int(first_even_summary['raw_max'])}"
    )
    print(
        f"  raw peak: {int(first_even_summary['raw_peak'])} "
        f"(scaled {first_even_summary['raw_peak_scaled']:.1f})"
    )
    print(
        f"  1024-point linear-resample peak: {first_even_summary['resampled_peak_scaled']:.1f} "
        f"at index {int(first_even_summary['resampled_peak_idx'])}"
    )
    print()

    print("First large message, odd-class subsequence")
    print(f"  point count: {int(first_odd_summary['count'])}")
    print(
        f"  raw min/max: {int(first_odd_summary['raw_min'])} / "
        f"{int(first_odd_summary['raw_max'])}"
    )
    print(
        f"  raw peak: {int(first_odd_summary['raw_peak'])} "
        f"(scaled {first_odd_summary['raw_peak_scaled']:.1f})"
    )
    print()

    print("Across all large messages")
    print(
        f"  even-class raw peak scaled: min={min(even_scaled):.1f} "
        f"max={max(even_scaled):.1f} avg={mean(even_scaled):.1f}"
    )
    print(
        f"  odd-class raw peak scaled: min={min(odd_scaled):.1f} "
        f"max={max(odd_scaled):.1f} avg={mean(odd_scaled):.1f}"
    )
    print(
        f"  even-class resampled peak index range: "
        f"{min(even_pos):.1f} .. {max(even_pos):.1f}"
    )
    print()
    print("Interpretation")
    print(
        "  even-class values are the live IR interferogram candidate: they match "
        "the observed raw +/- counts and the scaled IR peak after dividing by 256"
    )
    print(
        "  odd-class values are the strongest laser-reference candidate: their raw "
        "peak sits in the same range as the displayed scaled laser peak"
    )


def main() -> None:
    parser = argparse.ArgumentParser(description="Parse FTIR USB capture structure")
    parser.add_argument(
        "pcap",
        nargs="?",
        default="sniff.pcapng",
        help="Path to the pcapng/pcap capture",
    )
    parser.add_argument(
        "--endpoint",
        help="Override the auto-detected measurement endpoint (for example 1.39.5)",
    )
    args = parser.parse_args()

    pcap_path = Path(args.pcap)
    frames = run_tshark(pcap_path)
    endpoint = args.endpoint or detect_measurement_endpoint(frames)
    segments = parse_segments(frames, endpoint)
    if is_diagnostic_capture(segments):
        print_diagnostic_summary(endpoint, segments)
    else:
        print_export_summary(frames, endpoint, segments)


if __name__ == "__main__":
    main()
