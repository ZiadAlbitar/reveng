# Instrument Control Code Map

This repository contains three layers of reverse–engineered binaries that form the Cary/Agilent FTIR software stack. Each layer plays a distinct role between the UI and the spectrometer firmware. The table below maps the components and highlights the portions that own USB I/O so you can focus on the driver–relevant parts.

- **FTIRInst.dll.c** – Managed/COM bridge that exposes a flat C API to the .NET GUI (`MLInstrumentControl.cs.txt`). Key exports such as `FTIRInst_Init`, `FTIRInst_dptrStartSpectrum`, `FTIRInst_GetStatusEx`, etc. wrap methods on the `ftirInstrument` C++ class. This layer handles configuration, data marshaling, and Win32 window registration for status callbacks, but it never touches USB directly.
- **mInst.dll.c** – Core instrument logic (`mFtirInst` and related helpers). This layer translates high‑level operations (scan sequencing, servo control, notification routing) into low-level command frames. Functions in the `0x10002xxx–0x100054xx` range build and queue frames using a common helper (`FUN_10014dc0`) before dispatching them through the transport vtable stored at `this + 0x78`.
  - Important routines for the protocol surface:
    - `FUN_10002e30` / `FUN_10002f40` / `FUN_10002fe0` → connection handshake steps (command IDs `0x01`, `0x02`, `0x19`).
    - `FUN_10003390` → sets status/event masks (command `0x69`) while caching masks at offsets `0x58/0x5c`.
    - `FUN_10003c40` (`cmd 0x63`) and `FUN_10003cc0` (`cmd 0x61`) → kick watchdog & request live status.
    - `FUN_100042d0` (`cmd 0x18`) → request calibration blob, response copied via `FUN_10035ce0`.
    - `FUN_100047c0`/`FUN_10004a50`/`FUN_10004b30` (`cmd 0xB7/0xB6/0xB5`) → start, poll, and finalize bulk transfers (payload in `local_20[7]`).
    - `FUN_10005170` (`cmd 0xB1`) → write 0x30-byte setup blocks; response length must also match 0x30.
    - `FUN_10005430` (`cmd 0x68`) → read two 24-bit counters returned in the response body.
    - A dedicated helper emits command `0xB4` (seen in the latest sniff) to stage the 0x0C00-byte instrument profile that immediately follows as `type 0x18` fragments on pipe `0x1c`.
    - The request header layout matches the cleaned struct in [`docs/usb_frames.h`](usb_frames.h); the sequence byte (`this+0xe0`) is copied directly into the prefix.
  - `*(this + 0x78)` is the transport vtable. Methods at offsets `0x18/0x24/0x30/0x38/0x3c` correspond to connect, read, write, lock, unlock operations implemented by `mInstUsb.dll`.
- **mInstUsb.dll.c** – Transport abstraction. Even though the raw decompile is noisy, the `WinUsb_*` imports show that the default transport is USB WinUSB. Three strands matter for driver work:
  - `connectWinUSB` (called from `FUN_10017700`) locates the device path (via registry/INF data parsed by `FUN_10017340`), opens a handle, initialises WinUSB, enumerates interface 0, and caches bulk in/out pipe IDs at offsets `0x118` (bulk out) and `0x124` (bulk in).
  - `sendMessage` is implemented by `FUN_10016e30`: it assembles a frame header, writes up to 0x7FFF bytes per chunk (observed limit), updates sequence counter at `this + 0x535`, and waits for an ACK block. It also maintains `lastTxTick` at `this + 0x57c` and persists the last generated checksum for retry logic.
  - `StatusThread` / `HeartbeatThread` (created in `FUN_10018bf0` / `FUN_10018b70`) continuously call `FUN_100188c0` and `FUN_10018a40`, which in turn drive `sendMessage(0x10)` (heartbeat) and `reconnect` on failures.

### Runtime object layout

| Offset | Owner            | Meaning (deduced)                                |
|--------|------------------|--------------------------------------------------|
| +0x40  | `ftirInstrument` | Capture compute parameters (apodization, zero fill, etc.) |
| +0x58  | `mFtirInst`      | Latched enable mask used by `FUN_10004200`       |
| +0x68  | `mFtirInst`      | Transport state flag (`1` while connected)       |
| +0x74  | `mFtirInst`      | Firmware build ID returned by command `0x01`     |
| +0x78  | `mFtirInst`      | Pointer to transport vtable (USB by default)     |
| +0x8c  | `mFtirInst`      | Device address used by command `0x18`            |
| +0xe0  | `mFtirInst`      | Rolling message counter (mirrored into `prefix.sequence`) |
| +0xe1  | `mFtirInst`      | Logical device ID used by certain register reads |
| +0x10c | `mInstUsb`       | Raw device handle (`INVALID_HANDLE_VALUE` when closed) |
| +0x110 | `mInstUsb`       | `WINUSB_INTERFACE_HANDLE`                        |
| +0x118 | `mInstUsb`       | Bulk‐OUT pipe ID                                 |
| +0x124 | `mInstUsb`       | Bulk‐IN pipe ID                                  |
| +0x57c | `mInstUsb`       | Last TX tick for heartbeat supervision           |
| +0x535 | `mInstUsb`       | Frame sequence counter (increments modulo 256)   |
| +0x57a | `mInstUsb`       | Connection health flag set when WinUSB initialised |

### Recommended reading order

1. `mInstUsb.dll.c` ➜ functions `FUN_10017700`, `FUN_10016e30`, `FUN_100188c0`, `FUN_10018bf0` – show how USB pipes are opened, how frames are written, and how heartbeat/status threads drive retries.
2. `mInst.dll.c` ➜ functions listed above – expose the command vocabulary; match each command ID with the data layout that the driver needs to reproduce.
3. `FTIRInst.dll.c` ➜ exported wrappers for application use; useful to see which command sequences occur for specific operations (scan start, data download, etc.).
