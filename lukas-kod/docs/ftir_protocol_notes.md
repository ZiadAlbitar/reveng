# FTIR USB Protocol Notes

These notes are based on:

- `sniff.pcapng` and the exported spectrum `2026-04-08T15-25-32.csv`
- `mtest_sniff.pcapng` from the diagnostic application

## Confirmed framing

- The interesting measurement stream is endpoint `1.39.5 -> host`.
- A `539`-byte USB frame is a `27`-byte USBPcap wrapper plus a `512`-byte application chunk.
- A short `105`/`111`-byte USB frame is the same application stream with a short final chunk.
- The application stream on `1.39.5` is message-framed.

Application message header:

- bytes `0..1`: little-endian sequence counter
- bytes `2..3`: constant `0x1044`
- bytes `4..7`: big-endian body length

Examples:

- `64 ce 44 10 00 00 02 46` -> seq `0xce64`, type `0x1044`, body length `0x246 = 582`
- `64 d9 44 10 00 03 92 4c` -> seq `0xd964`, type `0x1044`, body length `0x3924c = 234060`

234060 = 457*512 - 8 + (111-27) 
457 packages of 512 with regards to the 8 byte header of the first one and then a package of 84 bytes (111-27)

## Repeating message pattern

After startup, the device repeatedly emits:

1. one large message with body length `234060`
2. one small state message with body length `582` at first, then `588`

There is also one initial small state message at frame `20` before the stable repeating pattern starts.

The small messages are TLV-like with 6-byte records:

- `2` bytes tag, big-endian
- `4` bytes value, big-endian

Examples from the small state messages:

- tag `0x0011`
- tag `0x0021`
- tag `0x0031`
- tag `0x0141`
- tag `0x0211`

## State machine

The short TLV messages clearly encode device state transitions.

Observed major transitions:

- state `0x0031 = 2` through the live/background phase
- state `0x0031 = 3` starts at frame `11720`, time `5.041192 s`
- state `0x0031 = 4` starts at frame `27348`, time `11.646258 s`
- state `0x0031 = 5` starts at frame `42092`, time `17.847313 s`

The strongest candidate for "user clicked acquire/sample" is the transition into state `3`.

Why:

- just before it, host sends two unusual `host -> 1.39.4` control packets with the `...0030b2...` payload pattern:
  - frame `11699` at `5.017687 s`
  - frame `11703` at `5.020678 s`
- later transitions into states `4` and `5` do not have the same preceding custom control commands
- at frame `11720`, the small `1.39.5` state message changes:
  - body length `582 -> 588`
  - tag `0x0031` changes `2 -> 3`
  - tag `0x0021` pulses to `0x0100`
- the next large `234060`-byte measurement message starts at frame `11736`, time `5.049675 s`

## What is likely happening

The capture appears to contain:

- a live/background phase in state `2`
- a user-triggered acquisition entering state `3`
- one or more automatic follow-up phases entering states `4` and `5`

That means the exported sample is most likely derived from the large messages that begin after frame `11736`, not from the earlier live/background stream.

## Link To The Diagnostic Model

The original `1.39.5` large messages also fit the same record layout found in the diagnostic capture:

- `1` byte class
- `3` bytes signed big-endian value

If those records are split by the low bit of the class byte:

- the even-class stream again behaves like the IR interferogram candidate
- the odd-class stream again behaves like the laser-reference candidate

For the first large message in `sniff.pcapng`:

- even-class raw peak scaled by `1/256`: about `19777.5`
- odd-class raw peak scaled by `1/256`: about `7425.5`

Across the original capture, the even-class raw peak stays close to `19766 .. 19794`.

The short TLV state messages expose a related peak field only after acquisition starts:

- state `2`: tag `0x0231 = 0`
- state `3`: tag `0x0231 = 5036625` -> `19674.3` after scaling by `1/256`
- state `4`: tag `0x0231 = 5038542` -> `19681.8`
- state `5`: tag `0x0231 = 5040025` -> `19687.6`

So the diagnostic capture does carry over to the original one: both applications are looking at the same raw interferogram-scale data.

## What is not solved yet

The exact numeric transform from the large `234060`-byte bodies to the exported CSV values is not fully resolved yet.

What is ruled out:

- the exported spectrum is not stored as a plain contiguous `int16`, `int32`, or `float32` vector
- it is also not a simple fixed-column extraction from an obvious `3901 x 15 x 4` table

What still looks plausible:

- the large body is an interleaved fixed-point stream
- the exported spectrum is derived from that same raw interferogram stream plus host-side FTIR processing
- states `3 -> 4 -> 5` likely correspond to acquisition and post-processing stages of that same measurement

## Repro

Run:

```bash
python3 parse_ftir_capture.py sniff.pcapng
```

That script reproduces the framing summary, the TLV state transitions, and the most likely sample-start boundary.

## Diagnostic application capture

The diagnostic app uses the same application framing, but on endpoint `1.6.5 -> host`.

Observed message pattern:

- one startup message with body length `354`
- one startup message with body length `281`
- then a repeating pair:
  - one small state message with body length `588`
  - one large data message with body length `234060`

The `588`-byte state message is the same `6`-byte TLV format:

- `2` bytes tag, big-endian
- `4` bytes value, big-endian

Confirmed UI field mappings from the first repeated `588`-byte state message:

- tag `0x1201 = 217` -> `IR gain value = 217`
- tag `0x1211 = 204` -> `laser gain value = 204`

## Large diagnostic body structure

The large `234060`-byte body is best explained as:

- `58515` fixed `4`-byte records
- each record is:
  - `1` byte class
  - `3` bytes signed big-endian integer

The class byte is not just a simple channel id. It is interleaved and highly structured, but one bit is already very useful:

- records with class byte `LSB = 0` form one continuous value stream
- records with class byte `LSB = 1` form a second continuous value stream

### Even-class stream: live IR interferogram

If you take the `24`-bit signed value from every record whose class byte is even, in message order, you get a stream that matches the diagnostic app's live interferogram very closely.

For the first large message in `mtest_sniff.pcapng`:

- point count: `29258`
- raw min/max: `-5030476 / 2334602`
- raw peak: `-5030476`
- raw peak scaled by `1/256`: `19650.3`

This matches the UI well:

- visible graph range of about `-5,000,000` to `+2,000,000`
- `Scaled IR peak = 19648`

If that even-class stream is linearly resampled to `1024` display points:

- resampled peak is about `19554.8`
- peak index is `640`

That is close to the app's displayed:

- `Resampled Igram [Peak = 19529 (at 639)]`

The remaining small difference is consistent with the app using a slightly different resampler or extra smoothing before drawing.

Across all `107` large diagnostic messages:

- even-class raw peak scaled stays in a very tight range: `19590.6 .. 19676.2`

So the even-class stream is the strongest confirmed candidate for the live IR interferogram.

### Odd-class stream: likely laser reference

If you take the `24`-bit signed value from every record whose class byte is odd, in message order, you get a second stream:

- first-message raw min/max: `-1897282 / 1907936`
- first-message raw peak scaled by `1/256`: `7452.9`
- across all large messages, raw peak scaled stays in `7449.7 .. 7481.5`

That is close to the diagnostic app's:

- `Scaled laser peak = 7570`

So the odd-class stream is the strongest current candidate for the laser-reference channel, although its exact display scaling is not fully pinned down yet.

## What this means

The diagnostic app does not appear to read one plain contiguous interferogram array from the packet.

Instead, the large message contains many interleaved `4`-byte records, and the software reconstructs at least two live streams from them:

- even-class records -> IR interferogram
- odd-class records -> likely laser reference

The gain values are carried separately in the short TLV state messages.

## Repro for the diagnostic capture

Run:

```bash
python3 parse_ftir_capture.py mtest_sniff.pcapng
```

That prints:

- the endpoint and framing summary
- the confirmed gain TLVs
- the even/odd stream peak summaries
- the first-message resampled interferogram peak approximation
