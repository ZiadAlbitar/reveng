# Cary FTIR USB protocol (reverse engineered)

The legacy Cary/MicroLab software communicates with the spectrometer through WinUSB. The transport logic lives in `mInstUsb.dll` and is driven by the instrument controller in `mInst.dll`. This document distils the noisy GHIDRA output into a workable description so a custom USB driver can be implemented.

## Physical transport

- **Interface** – single WinUSB interface (interface 0). `FUN_10017700` opens the device, enumerates pipe descriptors with `WinUsb_QueryInterfaceSettings`, and memorises:
  - Bulk OUT pipe ID at `+0x118`
  - Bulk IN pipe ID at `+0x124`
  - Interrupt pipe is not used; status is polled instead.
- **Chunking** – `FUN_10016e30` (aliased as `mInstUsb::sendMessage`) breaks payloads into chunks of at most `0x7FFF` bytes. Each chunk is wrapped in the common 16‑byte header described below. Responses are read with the same helper and must match the expected byte count otherwise the call fails.
- **Concurrency** – two background threads are spawned (`FUN_10018b70` & `FUN_10018df0`):
  - *HeartbeatThread* repeatedly calls `sendMessage(0x10)` once per second; failure triggers a reconnect.
  - *StatusThread* polls status when the API has registered a window for notifications.

## Frame structure

Every exchange begins with four little-endian DWORDs followed by an optional payload. The cleaned helper in [`docs/usb_frames.h`](usb_frames.h) matches the capture exactly.

```
DWORD0 = (pipe_id << 24) | (??? << 16) | (sequence << 8) | type
DWORD1 = (flags << 24)   | (payload_len << 16) | (status << 8) | command
DWORD2 = param0 (little endian)
DWORD3 = param1 (little endian)
```

- **type**: `0x08` host request, `0x09` acknowledgement, `0x0B` register response on bulk-IN 0x83, `0x0D` link reset, `0x18` large data fragments streamed over bulk IN 0x85. The device mirrors the request `sequence`.
- **status**: ASCII status code (`0x40` `'@'` success, `0x41` `'A'` error, ``0x60`` ``` ` ``` retry). Requests clear this byte.
- **payload_len**: number of bytes that trail the 16 byte header.
- **param0/param1**: immediate arguments. For command `0x01` the first word carries the instrument family (`0x00002a01`). Register reads (`command 0x18`) store the firmware address left-shifted by eight bits (`param0 >> 8 = register`).
- **flags**: remain zero on most host requests. Device replies set this byte to mark context: `0x10` accompanies the `0x68` counter block, while register replies (type `0x0B`) reuse the byte as a page/chunk indicator (0x64, 0x21 observed).

The `pipe_id` byte reflects the USB endpoint that transported the frame: `0x10` for the command mailbox (OUT 0x04 / IN 0x83) and `0x04` for register replies streamed over the same IN pipe. `0x1C` and `0x28` appear on configuration reads that spill over to the secondary IN endpoint (0x85).

### Example handshake (from `new_sniff.pcapng`)

| Frame | Direction | DWORD0    | DWORD1    | DWORD2    | Notes                                  |
|-------|-----------|-----------|-----------|-----------|----------------------------------------|
| 7     | host → dev | `0x0000000D` | `0x00000000` | `0x00000000` | Link reset (`type = 0x0D`).              |
| 10    | dev → host | `0x0400000D` | `0x0100FF07` | `0x00000000` | Device replies with firmware caps.      |
| 11    | host → dev | `0x10000108` | `0x00000001` | `0x00002A01` | Command `0x01`, payload `0`, sequence 1.|
| 14    | dev → host | `0x10000109` | `0x00400001` | `0x00002A01` | Ack (`status='@'`, payload 0).          |
| 15    | host → dev | `0x10000208` | `0x00000019` | `0x00000000` | Command `0x19`, sequence 2.             |
| 18    | dev → host | `0x10000209` | `0x00400019` | `0x00000000` | Ack.                                    |
| 19    | host → dev | `0x10000308` | `0x00000068` | `0x00000000` | Command `0x68`.                         |
| 22    | dev → host | `0x10000309` | `0x10400068` | `0x00114100` | Ack with 0x10-byte payload.             |
| 23    | host → dev | `0x10000408` | `0x00000018` | `0x00400000` | Command `0x18`, read register 0x4000.   |
| 26    | dev → host | `0x0400040B` | `0x01000000` | `0x00114100` | Register block response (`payload_len=1`). |
| 28    | dev → host | `0x10004418` | `0x01000000` | `0x02001100` | First 0x18 fragment (340 bytes) carrying instrument info (`param1 = 0x21003da8`). |

The capture continues with additional `0x18` reads that pull the serial number (`"MY2446CU14"`), model ID, and accessory tables; the payload bytes in frames 28, 34, 39‒75 match the structures returned by `mFtirInst::GetInstrumentInfoEx`.

## Connection sequence

`mInstUsb::connectWinUSB` issues the commands shown above in order:

1. **Reset (type 0x0D)** – clears the transport state.
2. **Command `0x01`** – returns the instrument family (`param0 = 0x00002a01` in the capture).
3. **Command `0x19`** – completes the handshake.
4. **Command `0x68`** – retrieves two 24-bit counters (copied into `mFtirInst+0x50/+0x54`).
5. **Command `0x18` @0x4000** – reads the calibration/register block; the firmware streams the data over bulk-IN 0x83/0x85 using types `0x0B` and `0x18`.

The firmware expects each request to increment the sequence byte; missing or repeated values trigger retries handled by `FUN_10004b30`.

## Command reference

The table below gathers the commands that are directly visible in `mInst.dll`. Multi-byte values are little-endian inside `param0/param1`.

| Command | Function(s)                                | Request fields                                                     | Notes |
|---------|-------------------------------------------|--------------------------------------------------------------------|-------|
| `0x01`  | `FUN_10002e30`                            | `param0 = 0x00002a01`.                                             | Returns firmware build ID in the ack payload. |
| `0x02`  | `FUN_10002f40`                            | No payload; `param0 = 0`.                                          | Second handshake stage (rarely used). |
| `0x19`  | `FUN_10002fe0`                            | No payload.                                                        | Completes connect. |
| `0x18`  | `FUN_100042d0`                            | `param0 = register offset`, `payload_len` set to number of bytes requested (0x10 in the capture). | Responses arrive as a `0x0B` header followed by optional `0x18` fragments on EP 0x85. |
| `0x61`  | `FUN_10003cc0`                            | No payload.                                                        | Periodic status poll. |
| `0x63`  | `FUN_10003c40`                            | No payload.                                                        | Watchdog kick. |
| `0x68`  | `FUN_10005430`                            | No payload.                                                        | Ack payload_len=0x10 containing two 24-bit counters. |
| `0x69`  | `FUN_10003390`                            | `param0=enable mask`, `param1=latch mask`.                         | Updates masks cached at offsets `+0x58/+0x5c`. |
| `0xB1`  | `FUN_10005170`                            | `payload_len = 0x30`, payload filled via `FUN_1002ee20`.           | Acquisition setup block. |
| `0xB5`  | `FUN_10004b30`                            | `param0 = transfer ID`.                                            | Ack status `'@'` success, `'A'` failure, ``'`'`` busy. |
| `0xB6`  | `FUN_10004a50`                            | No payload.                                                        | Allocates a transfer ID written back through `param_1`. |
| `0xB7`  | `FUN_100047c0`                            | `payload_len` matches the data copied from the caller.             | Bulk data (spectra, firmware). |
| `0xB4`  | (observed in capture)                     | `pipe_id = 0x1C`, `param0 = size (0x00000c00)`, `param1 = offset (0x00000100)`. | Triggers a large read that is returned as type `0x18` fragments on bulk IN 0x85. |
| `0x10`  | `FUN_100188c0` / heartbeat thread         | No payload.                                                        | Sent repeatedly; the device drops the link after 12 missed beats. |

Higher-level exports in `FTIRInst.dll` combine these primitives to implement scans, live data streaming, and configuration updates.

## Status and data flow

1. **Continuous status** – The UI registers a Win32 window. `mInstUsb` stores the handle and the desired message IDs. `StatusThread` polls the device using command `0x61` and posts translated notifications to the window.
2. **Scan start** – `FTIRInst_dptrStartSingleBeam` and related exports call into `mFtirInst::StartNewCollect`, which sends a `0xB7` block containing scan parameters, waits for the `0xB6` acknowledgement, and then enables notifications for data delivery.
3. **Spectral data** – Delivered as `0xB7` frames. Large spectra are chunked to ≤0x7FFF bytes per the transport limit enforced in `FUN_10016e30`.

## Implementing a custom driver

To replace the WinUSB layer:

1. Reproduce the sequence in the handshake table (including the initial `0x0D` reset) and maintain the heartbeat loop (`command 0x10`).
2. Keep a monotonic sequence counter modulo 256; mirror the device's behaviour of echoing the byte in every response.
3. Encode register addresses as `addr << 8` in `param0` when issuing `0x18` requests, and expect the reply blocks (`type 0x0B`) to re-use the upper address byte in the `flags`.
4. Set the `pipe_id` byte to `0x10` for control transfers. Use the IDs returned by the firmware when replying (`0x04`, `0x1C`, `0x28`) so your decoder can route the data correctly.
5. Honour the chunking enforced by `sendMessage`: split payloads to at most `0x7FFF` bytes and handle status values `'@'`, `'A'`, and ``'`'`` exactly like `FUN_10004b30`.

Armed with the capture and the cleaned header in [`usb_frames.h`](usb_frames.h) you can synthesise frames without revisiting the decompiler output.
