#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
extern u8 *CpuTexSpaceA[4];        /* cf. src/fx.c, overlay_143 */
extern u8 *CpuTexSpaceB[4];
extern u8 D_overlay_65_041006A0;   /* ping-pong buffer selector */
extern s32 D_overlay_65_041006A4;  /* one-shot: seed row initialised */
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
/* Same ping-pong structure as overlay_143 GenerateFireTexture, but the
 * torch variant: a seeded row at height-6, 4-tap blend for rows 0..height-7,
 * 3-tap blend for rows height-5..height-1, a copy of row height-7 into
 * height-6, and an IA16 conversion with hi = min(v + 0x34, 255). */
void GenerateTorchFireTex(s32 idx, u8 *tex, s32 unused) {
    u8 *oldBuf;
    u8 *newBuf;
    u8 *seed;
    u8 *s0;
    u8 *s1;
    u8 *d;
    u8 *src;
    u16 *out;
    s32 width;
    s32 height;
    s32 k;
    s32 x;
    s32 y;
    s32 row;
    s32 swizzled;
    s32 v;
    s32 a;
    s32 hi;
    s32 cap;

    width = tex[0];
    height = tex[1];

    if (D_overlay_65_041006A0 != 0) {
        oldBuf = CpuTexSpaceA[idx];
    } else {
        oldBuf = CpuTexSpaceB[idx];
    }

    /* reseed row (height-6), columns 3 .. width-4.
     * asm: counter starts at width-7 and is tested before decrement, so the
     * loop runs width-6 times (none when width == 6). */
    seed = oldBuf + (height - 6) * width + 3;
    if (D_overlay_65_041006A4 == 0) {
        for (k = width - 7; k >= 0; k--) {
            v = (width >> 1) - k - 3;
            if (v <= 0) {
                v = -v;
            }
            *seed = (u8) mathRnd(0, 0xFF - (v * 0x10));
            seed++;
        }
        D_overlay_65_041006A4 = 1;
    } else {
        for (k = width - 7; k >= 0; k--) {
            v = (width >> 1) - k - 3;
            if (v <= 0) {
                v = -v;
            }
            cap = 0xFF - (v * 0x10);
            v = mathRnd(-0x60, 0x60) + *seed;
            if (cap < v) {
                v = cap;
            }
            if (v < 0) {
                v = 0;
            }
            *seed = (u8) v;
            seed++;
        }
    }

    /* flip the selector; the new buffer is the one it now points at */
    D_overlay_65_041006A0 = (u8) (D_overlay_65_041006A0 ^ 1);
    if (D_overlay_65_041006A0 != 0) {
        newBuf = CpuTexSpaceA[idx];
    } else {
        newBuf = CpuTexSpaceB[idx];
    }

    /* rows 0 .. height-7 (asm: height-6 rows): 4-tap blend of old rows y and y+1 */
    for (y = 0; y <= height - 7; y++) {
        s0 = oldBuf + y * width;
        s1 = s0 + width;
        d = newBuf + y * width;
        d[0] = 0;
        for (x = 1; x <= width - 2; x++) {
            v = (4 * s1[x] + 2 * s0[x] + s1[x - 1] + s1[x + 1]) >> 3;
            if (v < 0xAA) {
                v = v - 1;
            }
            if (v < 0) {
                v = 0;
            }
            d[x] = (u8) v;
        }
        d[width - 1] = 0;
    }

    /* row height-6 = copy of row height-7 of newBuf.
     * asm: copies width bytes (counter tested before decrement).
     * For height == 6 this reads the row before newBuf (asm does the same). */
    d = newBuf + (height - 6) * width;
    src = d - width;
    for (x = 0; x < width; x++) {
        d[x] = src[x];
    }

    /* rows height-5 .. height-1 (asm: 5 rows): 3-tap blend of the row above
     * (old buffer, row y-1) */
    for (y = height - 5; y <= height - 1; y++) {
        s0 = oldBuf + (y - 1) * width;
        d = newBuf + y * width;
        d[0] = 0;
        for (x = 1; x <= width - 2; x++) {
            v = (s0[x] + s0[x - 1] + s0[x + 1]) >> 2;
            if (v < 0xAA) {
                v = v - 1;
            }
            if (v < 0) {
                v = 0;
            }
            d[x] = (u8) v;
        }
        d[width - 1] = 0;
    }

    /* convert to IA16. Rows alternate between linear and x^2 swizzled
     * (same parity rule as GenerateFireTexture). */
    out = (u16 *) (tex + 0x20);
    src = newBuf;
    for (row = 0; row < height; row++) {
        swizzled = ((height - 1 - row) & 1) == 0;
        for (x = 0; x < width; x++) {
            v = src[x];
            a = v;
            if ((v >> 4) != 0) {
                a = v * (v >> 4);
            }
            if (a >= 0x100) {
                a = 0xFF;
            }
            hi = v + 0x34;
            if (hi >= 0x100) {
                hi = 0xFF;
            }
            out[swizzled ? (x ^ 2) : x] = (u16) ((hi << 8) | a);
        }
        src += width;
        out += width;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o65/overlay_65/GenerateTorchFireTex.s")
#endif
