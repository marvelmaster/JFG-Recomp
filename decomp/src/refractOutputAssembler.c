#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern void *refractBuffers[2];
extern s32 refractDelay;
extern s32 refractWhichBuffer;
extern s32 gUnresolvedSymbolAddr[];
/* decomp: externs end */

// Expands one 32-bit packed record (two 16-bit halves) into a buffer halfword.
// Field layout: dx = bits 11..15 (-16), dy = bits 1..5 (-16), bias = bits 6..10.
// Row stride of the source screen is 640 bytes (320 x 16-bit pixels).
static void refractPixel(u16 *dst, u8 *src, u32 v) {
    s32 dx = ((v >> 11) & 0x1F) - 16;
    s32 dy = ((v >> 1) & 0x1F) - 16;
    u32 m = v & 0x7C0;
    u32 bias = m + (m >> 5);
    u16 *s = (u16 *) (src + dx * 2 + dy * 640);

    *dst = (u16) (*s + bias);
}
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void refractOutputAssembler(void) {
    u8 *buf;
    u8 *bufEnd;
    u8 *scan;
    u8 *zeroStart;
    u8 *screenPos;
    u8 *runScreen;
    u8 *src;
    u8 *dst;
    s32 *tbl;
    s32 *p;
    s32 n;
    s32 i;
    u32 word;

    if (refractDelay != 0) {
        refractDelay -= 1;
        return;
    }
    buf = (u8 *) refractBuffers[refractWhichBuffer];
    if (buf == NULL) {
        return;
    }
    bufEnd = buf + 0x25800;
    screenPos = (u8 *) currentScreen;
    tbl = gUnresolvedSymbolAddr;
    zeroStart = buf;
    scan = buf;

    // Pass 1: walk the buffer; each run of nonzero words is expanded in place
    // from the screen, and (zero-skip, run-length) pairs are recorded in the table.
    for (;;) {
        while (scan < bufEnd && *(u32 *) scan == 0) {
            scan += 4;
        }
        if (scan >= bufEnd) {
            if (zeroStart < bufEnd) {
                *tbl = (s32) (scan - zeroStart);
            }
            break;
        }

        *tbl++ = (s32) (scan - zeroStart);
        screenPos += scan - zeroStart;
        runScreen = screenPos;
        do {
            word = *(u32 *) scan;
            if (word >> 16) {
                refractPixel((u16 *) scan, screenPos, word >> 16);
            }
            if (word & 0xFFFF) {
                refractPixel((u16 *) (scan + 2), screenPos + 2, word & 0xFFFF);
            }
            scan += 4;
            if (scan >= bufEnd) {
                /* asm: run reaches end of buffer, slot records span from zero start */
                *tbl++ = (s32) (scan - zeroStart);
                break;
            }
            screenPos += 4;
        } while (*(u32 *) scan != 0);

        // end of run
        zeroStart = scan;
        scan += 4;
        *tbl++ = (s32) (screenPos - runScreen);
        if (scan >= bufEnd) {
            if (zeroStart < bufEnd) {
                *tbl = (s32) (scan - zeroStart);
            }
            break;
        }
    }

    // Pass 2: copy each nonzero run from the buffer back onto the screen,
    // stepping over the recorded zero-skips.
    src = buf + gUnresolvedSymbolAddr[0];
    dst = (u8 *) currentScreen + gUnresolvedSymbolAddr[0];
    if (src < bufEnd) {
        p = &gUnresolvedSymbolAddr[1];
        do {
            n = p[0] / 4;
            for (i = 0; i < n; i++) {
                *(u32 *) dst = *(u32 *) src;
                dst += 4;
                src += 4;
            }
            src += p[1];
            dst += p[1];
            p += 2;
        } while (src < bufEnd);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/refractOutputAssembler/refractOutputAssembler.s")
#endif
