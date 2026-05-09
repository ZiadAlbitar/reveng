I compared new_sniff.pcapng, program_boot_login.pcapng, measurement_sniff.pcapng, and CaryFTIR_py_failed_run.pcapng. The failed run matches the manufacturer startup sequence until the special 0x0a transition frame, but there are three concrete problems.

**Main Breakpoint**
Your driver stops after this exchange:

```text
failed frame 741 OUT: type=0a seq=001f pipe=04 cmd=00 flags=4c
failed frame 744 IN : type=0a seq=001f pipe=00 cmd=b3 len=40
```

That response is not an error. The manufacturer trace has the same pattern:

```text
new_sniff frame 135 OUT: type=0a seq=001f pipe=04 cmd=00 flags=4c
new_sniff frame 138 IN : type=0a seq=001f pipe=00 cmd=b3 len=40
new_sniff frame 139 OUT: endpoint 0x06, 76-byte b4 parameter block
```

But [CaryFTIR.py:277](/Users/lukasthoming/Desktop/prompt/reveng-coding_branch/code/CaryFTIR.py:277) requires frame.command == command. For this one frame you send cmd=00, but the expected reply command is b3, so the driver raises and never reaches [send_param()](/Users/lukasthoming/Desktop/prompt/reveng-coding_branch/code/CaryFTIR.py:500).

So the immediate failure is: cmd_copy() is too strict for the 0x0a transition frame.

**Header Length Misunderstanding**
For normal endpoint 0x04 command frames with 48 bytes of payload, the manufacturer sets the inner len byte to 00, not 0x30.

Manufacturer:

```text
type=08 pipe=30 cmd=b2 len=00 caplen=64
type=08 pipe=30 cmd=b3 len=00 caplen=64
type=08 pipe=1c cmd=b4 len=00 caplen=64
```

Failed Python run:

```text
type=08 pipe=30 cmd=b2 len=30 caplen=64
type=08 pipe=30 cmd=b3 len=30 caplen=64
type=08 pipe=1c cmd=b4 len=30 caplen=64
```

Across the manufacturer captures I checked, b2/b3/b4 on endpoint 0x04 had len=00 every time. The failed run had len=30 on 25 such frames.

This comes from [CaryFTIR.py:171](/Users/lukasthoming/Desktop/prompt/reveng-coding_branch/code/CaryFTIR.py:171), where p_len = len(payload). That field should not be treated as “payload length” for these outgoing command frames. The USB transfer is 64 bytes, but the protocol header byte remains zero.

**Read Size Causes 5s Delays**
The failed run takes about 158 seconds to reach the same point the manufacturer reaches in milliseconds. The pattern is almost exactly 5 seconds per command.

Likely cause: endpoint 0x83 command replies are 64 bytes, but [CaryFTIR.py:100](/Users/lukasthoming/Desktop/prompt/reveng-coding_branch/code/CaryFTIR.py:100) reads MAX_PACKET = 512. Since 64 bytes is a full USB packet, libusb may wait for more data until the timeout and then return the partial data.

Use 64-byte reads for endpoint 0x83; keep larger reads for endpoint 0x85.

**What To Change**
1. Change primary command reads to request 64 bytes, not 512.
2. For endpoint 0x04 command frames, keep the inner header len byte at 0x00 unless a capture explicitly shows otherwise.
3. Special-case the 0x0a transition reply: sent cmd=00, valid reply cmd=b3.
4. After that reply, immediately send the endpoint 0x06 parameter block. Your code already has send_param(), but it never gets there because of the bad command check.

One thing you did get right in the active code: the active param0 constants like 0x19700000 match the manufacturer on-wire bytes. The older commented block using values like 0x00007019` would be byte-swapped for the current header builder.