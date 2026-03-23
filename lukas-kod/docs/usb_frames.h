#ifndef USB_FRAMES_H
#define USB_FRAMES_H

#include <stdint.h>

/*
 * Live captures of the original WinUSB driver show that every message begins
 * with four little-endian 32-bit words. The layout is:
 *
 *   DWORD0 : [pipe_id | reserved | sequence | type]
 *   DWORD1 : [flags   | payload_len | status | command]
 *   DWORD2 : immediate parameter 0 (little endian)
 *   DWORD3 : immediate parameter 1 (little endian)
 *
 * Where each tag represents a single byte (little endian order). Observed
 * values for the type byte:
 *   0x08  host request
 *   0x09  device acknowledgement
 *   0x0B  register-block reply (bulk IN 0x83, payload_len always 0x01)
 *   0x0D  link reset sequence before the first request
 *   0x18  large data payload on the auxiliary IN pipe (0x85)
 *
 * The device mirrors the sequence counter supplied by the host. The status
 * byte matches the ASCII codes used in the firmware (`'@'` success, `'A'`
 * failure, ``'`'`` busy). `payload_len` is the number of bytes that follow
 * the 16-byte header. For register reads (`command 0x18`) the firmware expects
 * `param0` to contain the address shifted left by eight bits (`addr << 8`).
 */

typedef struct __attribute__((packed)) {
    uint8_t  type;
    uint16_t sequence;
    uint8_t  pipe_id;
} UsbFramePrefix;

typedef struct __attribute__((packed)) {
    uint8_t  command;
    uint8_t  status;
    uint8_t  payload_len;
    uint8_t  flags;
} UsbFrameControl;

typedef struct __attribute__((packed)) {
    UsbFramePrefix  prefix;
    UsbFrameControl control;
    uint32_t        param0;
    uint32_t        param1;
} UsbFrameHeader;

static inline void usb_frame_init_request(UsbFrameHeader *hdr,
                                          uint8_t  pipe_id,
                                          uint16_t sequence,
                                          uint8_t  command,
                                          uint8_t  payload_len,
                                          uint32_t param0,
                                          uint32_t param1)
{
    hdr->prefix.type      = 0x08;
    hdr->prefix.sequence  = sequence;
    hdr->prefix.pipe_id   = pipe_id;
    hdr->control.command  = command;
    hdr->control.status   = 0x00;
    hdr->control.payload_len = payload_len;
    hdr->control.flags    = 0x00;
    hdr->param0           = param0;
    hdr->param1           = param1;
}

#endif /* USB_FRAMES_H */
