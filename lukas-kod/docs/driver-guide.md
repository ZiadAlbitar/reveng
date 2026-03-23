# Cary FTIR Driver Implementation Notes

These notes consolidate what we can see in the decompiled binaries together with the USB captures (`new_sniff.pcapng`, `startsniff.txt`). The goal is to outline the minimum feature set you need in a custom driver to initialise the spectrometer, configure a collection, and pull a complete scan.

The information is complementary to `docs/usb-protocol.md` (transport level) and `docs/code-map.md` (component overview).

## 1. Transport recap

* Interface: WinUSB interface 0, vendor specific class.
* Endpoints:
  * `0x04` bulk OUT — host → instrument mailbox.
  * `0x83` bulk IN  — primary reply channel (acks, short register reads).
  * `0x85` bulk IN  — secondary data channel (long tables, spectra).
* Every URB payload starts with a 16‑byte header described in `docs/usb_frames.h`:

```
DWORD0 = (pipe_id << 24) | (reserved << 16) | (sequence << 8) | type
DWORD1 = (flags   << 24) | (payload_len << 16) | (status  << 8) | command
DWORD2 = param0 (little endian)
DWORD3 = param1 (little endian)
payload (payload_len bytes, optional)
```

* Observed `type` values:
  * `0x08` — host request.
  * `0x09` — device acknowledgement (mirrors the sequence byte).
  * `0x0B` — register block reply on `0x83`.
  * `0x0D` — link reset handshake.
  * `0x18` — large data fragments streamed on `0x85`.
* `status` byte follows the firmware convention: `0x40` (`'@'`) success, `0x41` (`'A'`) permanent failure, ``0x60`` (``'` ``) “busy, retry”.
* For register reads (`command 0x18`) the firmware expects the register address left-shifted by eight bits in `param0`: `param0 = (addr << 8)`.
* The device echoes the sequence number provided by the host. Maintain a rolling 8‑bit counter, incremented for every request (even pure polls).

## 2. Bring-up handshake

The capture (`startsniff.txt`) shows the minimum sequence required to initialise the instrument after opening the WinUSB pipes:

| Step | OUT frame (type/cmd) | Key fields                               | IN reply                                     |
|------|----------------------|-------------------------------------------|----------------------------------------------|
| 1    | `type 0x0D`, `cmd 0x00` | 64 zero bytes (keepalive-reset).        | `type 0x0D`, `cmd 0x07`, `status 0xFF` (firmware advertises capabilities). |
| 2    | `type 0x08`, `cmd 0x01` | `param0 = 0x00002a01` (instrument family). | `type 0x09`, `cmd 0x01`, `status 0x40`, `param0 = 0x00002a01`. |
| 3    | `type 0x08`, `cmd 0x19` | no payload.                             | `type 0x09`, `cmd 0x19`, `status 0x40`.       |
| 4    | `type 0x08`, `cmd 0x68` | no payload.                             | `type 0x09`, `cmd 0x68`, `status 0x40`, payload 0x10 bytes (two 24‑bit counters echoed in `param0/param1`). |
| 5    | `type 0x08`, `cmd 0x18` | `param0 = 0x00400000` (read register 0x4000). | `type 0x0B` (`pipe 0x04`) with `flags 0x64`, followed by `type 0x18` data bursts on pipe `0x1C`. |

After step 5 the instrument streams a 0xC00‑byte instrument profile. The driver must collect all `type 0x18` fragments (each 0x154 or 0x121 bytes payload in the capture) until the advertised byte count is reached. A preceding `cmd 0xB4` request initiates the transfer, see §3.2.

Keep sending a heartbeat every second:

* `type 0x08`, `cmd 0x10`, zero payload. The background thread in the original binary does exactly this (`FUN_100188c0` / `FUN_10018aa0`).
* Record the last tick (`param +0x57c` in the original class) so you can detect timeouts and attempt a reconnect.

## 3. Accessing configuration data

### 3.1 Register reads (`command 0x18`)

* `param0 = (addr << 8)`, `param1 = 0`.
* `payload_len = 0`.
* Device replies with:
  * `type 0x0B`, `payload_len = 1`, header flag `0x40 + (addr >> 8)` (0x64 when reading 0x4000). This is an acknowledgement plus the first 16 bytes.
  * If more data is pending the device follows up with `type 0x18` frames on pipe 0x1C with `flags` acting as a page counter (0x21, 0x10 …).
* Each 0x18 payload continues the data stream. Concatenate them in order of arrival.

### 3.2 Block fetch (`command 0xB4`)

Used to request the 0xC00‑byte instrument profile observed after the handshake.

* Request: `type 0x08`, `cmd 0xB4`, `pipe_id = 0x1C`, `param0 = size (0x00000c00)`, `param1 = offset (0x00000100)`.
* Ack: `type 0x0B` on pipe `0x04`, `flags` toggling between `0x64`/`0x21` (`page` hints).
* Data: streamed on pipe `0x1C` as `type 0x18` frames, `param0` increments with `(chunk_index << 8) | 0x11`, `payload_len` always `0x01` in the header (actual data comes in the body).

Collect until you read `param0` + `payload_length_total` bytes. The binary expects 0xC00 bytes and parses them into accessory tables (`instrumentDefinitions.xml` mirrors the content).

### 3.3 Event masks (`command 0x69`)

`FUN_10003390` pushes two 32‑bit masks into the device:

```
payload = struct {
    uint32_t enable_mask;
    uint32_t latch_mask;
};
```

The driver should enable at least:

* Bit `0x00000100` — scan completed notifications.
* Bit `0x00000010` — acquisition progress.

Send `cmd 0x69` after connect and before starting a collect so that status posts arrive on the registered window (or in your case, the USB driver can interpret the status frames).

## 4. Parameter blocks (command 0xB1)

`FUN_10005170` shows that `cmd 0xB1` transports 8 little-endian words (payload length 0x20). Those words are built from the cached “igram” and “single beam” settings read in at start-up:

| Word | Source offset | Default key            | Meaning (best effort)                           |
|------|---------------|------------------------|-------------------------------------------------|
| 0    | `+0x30`       | `IS_Res`               | Interferogram resolution (points).              |
| 1    | `+0x34`       | `IS_PhasePts`          | Phase points.                                   |
| 2    | `+0x38`       | `IS_LPad`              | Left zero padding.                              |
| 3    | `+0x3C`       | `IS_RPad`              | Right zero padding.                             |
| 4    | `+0x40`       | `SBeam_Apod`           | Apodization selection.                          |
| 5    | `+0x44`       | `SBeam_ZeroFill`       | Zero-fill exponent (`0` → none, `1` → 2x …).    |
| 6    | `+0x48`       | `SBeam_OffsetCorr`     | Offset correction flag.                         |
| 7    | `+0x4C`       | `SBeam_PhaseType`      | Phase correction mode.                          |

The firmware caches `SBeam_PhaseApod` at `+0x50` but it is not shipped in this block; a follow-up command (`SetCollectSettings`) adds it when building the measurement configuration (see below).

Whenever you change resolution, zero-fill, apodisation or phase settings, push an updated `0xB1` block.

## 5. Transfer ID management (`commands 0xB6/0xB5/0xB7`)

The firmware wraps long host→device transfers in a three-stage protocol:

1. `cmd 0xB6` (type 0x08) — allocate a transfer ID.
   * Device reply (type 0x09) includes the new ID in the returned 16-byte block. Save it; the original code mirrors it into `*(this + 0xe0)`.
2. `cmd 0xB7` — push the data. Header fields:
   * `param1` is the transfer ID.
   * `param0` defines the channel/sub-command.
   * `param3` in `FUN_100047c0` is the payload length, copied into the header byte `payload_len`.
   * `param4` is a secondary argument (ex: background slot).
3. `cmd 0xB5` — poll for completion.
   * Status `'@'`: success, `'A'`: failure, ``'`'``: firmware busy, resend the poll after a delay.

This triplet is used by the higher level code to upload background spectra, calibration blobs or control scripts.

## 6. Configuring a collect

The sequence executed by `FTIRInst_dptrStartSpectrum` and `StartSingleBeam` can be mirrored in a driver:

1. **Ensure compute settings are up to date.**
   * Write new igram/sbeam values at offsets `+0x30 .. +0x50`.
   * Send `cmd 0xB1` to push the first eight words.
   * Send `mFtirInst::SetIgramSettings` / `SetCollectSettings` (internally they use the same `0xB1` infrastructure and fill in the remaining parameters such as phase apodisation and collection type).
2. **Clear stale notifications.** `FUN_10002f30` issues `ClearDataNotifications(0x356)` then registers:
   * `0x8000` (heartbeat/data alive).
   * `0x0100` (single scan data ready) or `0x0300` (if hardware button is armed).
   * These subscriptions are pushed through command `0x69`.
3. **Prime the instrument profile if needed.**
   * Issue `cmd 0xB4` with `(size=0x0C00, offset=0x0100)` and download the `type 0x18` fragments into memory. Parse them against `instrumentDefinitions.xml` to select the accessory configuration.
4. **Set servo/bandwidth.**
   * `SetServoMode(4)` is emitted at connect time (`FUN_10002e20`).
   * `SetBandwidthMode(1)` toggles between the two hardware bandwidths (command `0x63` with mask bit 0x10).
5. **Start the collect.**
   * Calculate point spacing via `FUN_100036e0` (stores start/end wavenumbers and returns the number of spectral points).
   * Call `StartNewCollect` (`FUN_10002b10`/`FUN_100029b0`):
     - Resets local state (`*(this + 0x1a0) = 0`, `*(this + 0x1e4) = 0`).
     - Registers notifications (step 2).
     - Invokes `mFtirInst::StartNewCollect(..., 1)`. Inside `mInst.dll.c` this schedules the actual `cmd 0xB7` bursts that arm the interferometer.
     - Marks the acquisition active (`*(this + 0x130) = 1`).
6. **Read spectral data.**
   * The collect emits notifications on `0x83` (type `0x09`, `cmd 0x18` or `0x63`) to indicate progress.
   * Spectral blocks stream on pipe `0x85` (type `0x18`), one block per interferogram line. The first two DWORDs of the payload carry a block header: point index, byte count. The rest are 32‑bit or 64‑bit IEEE floats depending on the collection mode (single beam vs ratio). This is parsed in `mFtirInst::GetSpectrum`.
   * Poll using `cmd 0xB5` if you need to ensure previous uploads finished before you reuse a transfer ID.
7. **Completion.**
   * When the instrument finishes it posts a status record (windows message in the original app) and clears `*(this + 0x130)`.
   * Send a final `cmd 0x69` with zero masks if you want to stop receiving status.

## 7. Background / reference management

The public API exposes:

* `FTIRInst_dptrGetBackground` / `GetClean` / `GetSingleBeam` — each validates that the corresponding cached pointer (`*(this + 0x154)`, `+0x160`, `+0x168`) is not null, then calls helper functions that issue a `cmd 0xB7` transfer to fetch the data from the instrument.
* `FTIRInst_dptrSetBackground` — pushes host-provided double arrays back to the device using `cmd 0xB7`, followed by a `cmd 0xB5` loop until status `'@'` is received.

Reuse the transfer-ID pattern (§5) for these operations.

## 8. Status monitoring

* The original driver creates two threads:
  * **Heartbeat thread** – sleeps 500 ms, sends `cmd 0x10`. If 12 attempts fail it tears down the session (`FUN_100188c0`).
  * **Status thread** – waits for Windows event signals, polls `cmd 0x61` (`FUN_10003cc0`) to query the current scan state, and posts UI messages when buttons on the instrument are pressed.
* If you are implementing a non-UI driver, replace the Windows message mechanism with a queue fed by the status frames on pipe `0x83`. The status payload is 0x10 bytes with bit fields indicating the sub-state (collecting, averaging, user button).

## 9. Putting it together — example flow

```
open_device()
  -> WinUSB_Initialize(...)
  -> set timeouts, flush pipes

reset_link()
  send(type=0x0D, cmd=0x00, payload=64 zeros)
  expect(type=0x0D, cmd=0x07)

handshake()
  send(cmd=0x01, param0=0x00002a01)
  expect ack '@'
  send(cmd=0x19)
  expect ack '@'
  send(cmd=0x68)
  cache counters
  fetch_register(0x4000) via cmd 0x18 → parse instrument profile
  fetch_block(cmd 0xB4, size 0x0c00, offset 0x0100) if table missing

configure_notifications()
  send(cmd 0x69, enable_mask=0x00000110, latch_mask=0x00000000)

configure_parameters(res, zero_fill, apod, phase,...)
  update cached igram & sbeam values
  send(cmd 0xB1, payload=[res, phasePts, leftPad, rightPad,
                          apod, zeroFill, offsetCorr, phaseType])
  (optional) send second block with phase apodisation if required

start_collect()
  send(cmd 0x10 heartbeat simultaneously)
  call start_collect helper:
     - send cmd 0x69 to subscribe (0x0100 data channel)
     - send any upload blocks (background) via B6/B7/B5
     - mFtirInst::StartNewCollect issues the firmware start command (internally a 0xB7)

read_data()
  loop:
     - read from pipe 0x83; handle status 0x61/0x63
     - read from pipe 0x85; append spectral points
     - send heartbeat
     - break when completion status received

stop()
  send cmd 0x69 with masks=0
  continue heartbeat until you intentionally disconnect (or issue cmd 0x19 with zero payload to rearm)
```

## 10. Open items / cautions

* We have not yet captured a full spectrum acquisition, so precise decoding of the data frame that streams on pipe 0x85 will require an additional sniff with the instrument producing live data.
* Several command IDs remain opaque (`0x07` in the reset reply, additional fields in the `0x18` payload header). Treat any unknown bits conservatively.
* The firmware often responds with ``status = '`'`` when the previous request has not finished (see `FUN_10004b30`). Your driver must backoff (100–200 ms) and retry rather than flooding the link.
* For button/LED control (`SetAppLedState`, `RegisterButton1/2`) the device uses the same frame format with command IDs `0x33`, `0x29`, `0x30`. They follow the same acknowledgement rules as the transport documented here.

With these building blocks you can reproduce what the original Windows driver does: enumerate the device, run the USB handshake, push acquisition parameters, start a collect, and harvest the resulting spectra. Cross-reference the API flow in `FTIRInst.dll.c` for higher-level logic (`StartNewCollect`, `SetCollectSettings`, etc.) whenever you need to align with the legacy behaviour.
