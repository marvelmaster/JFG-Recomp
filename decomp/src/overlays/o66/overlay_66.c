#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern void **animpath;                         /* pointer to animation path table */

f32 Sinf(s16 angle);
void *lightGetStrongestEffect(f32 x, f32 y, f32 z);
void texDPTextureX(Gfx **dl, s32 texture, s32 arg2, s32 arg3);
void windowMakeBeams(u8 *window, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
f32 sqrtf(f32 x);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void windowfxInit(u8 *arg0, u8 *arg1, s32 arg2) {
    u8 *state;
    void **table;
    void **entry;
    u8 *wd;
    s16 *src;
    s16 *dst;
    s32 n;
    s32 i;
    s32 size;
    void *buf;

    state = *(u8 **)(arg0 + 0x68);
    *(s16 *)(arg0 + 0) = *(s16 *)(arg1 + 0xA);
    *(s16 *)(arg0 + 2) = *(s16 *)(arg1 + 0xC);
    *(s16 *)(arg0 + 4) = *(s16 *)(arg1 + 0xE);

    if (arg2 == 0) {
        table = *(void ***)(arg0 + 0x6C);
        entry = (void **)table[(s8)arg0[0x3A]];
        if (entry != NULL) {
            wd = (u8 *)entry[0];
            size = (*(s16 *)(wd + 0x12)) * 0xA;
            /* asm: two buffers, filled from index 1 down to 0 */
            for (i = 1; i >= 0; i--) {
                buf = mmAlloc(size, -1);
                ((void **)state)[i] = buf;
                if (buf != NULL) {
                    dst = (s16 *)buf;
                    src = *(s16 **)(wd + 0x1C);
                    n = (size + 1) >> 1;
                    while (n-- != 0) {
                        *dst++ = *src++;
                    }
                }
            }
        }
        state[8] = 1;
    }
    state[9] = arg1[0x10];
    state[0xA] = arg1[0x11];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o66/overlay_66/windowfxInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void windowfxControl(u8 *arg0, s32 arg1) {
    u8 *state;
    u8 *anim;
    u8 *path;
    u8 *light;
    f32 f0;
    f32 f12;
    f32 f14;
    f32 f16;
    f32 f18;
    f32 f8;

    state = *(u8 **)(arg0 + 0x68);
    if (state[9] != 0xFF) {
        *(u16 *)(arg0 + 6) |= 0x400;
        path = (u8 *)animpath[state[9]];
        if (path != NULL && (path[0x16] & 1)) {
            anim = *(u8 **)(path + 8);
            if (anim != NULL) {
                *(s16 *)(arg0 + 0) = *(s16 *)(anim + 0);
                *(s16 *)(arg0 + 2) = *(s16 *)(anim + 2);
                *(s16 *)(arg0 + 4) = *(s16 *)(anim + 4);
                *(f32 *)(arg0 + 8) = (*(f32 *)*(u8 **)(arg0 + 0x40) * *(f32 *)(anim + 8))
                                     / *(f32 *)*(u8 **)(anim + 0x40);
                *(f32 *)(arg0 + 0xC) = *(f32 *)(anim + 0xC);
                *(f32 *)(arg0 + 0x10) = *(f32 *)(anim + 0x10);
                *(s32 *)(arg0 + 0x14) = *(s32 *)(anim + 0x14);
                *(u16 *)(arg0 + 6) &= 0xFBFF;
                *(s16 *)(arg0 + 0x2E) = *(s16 *)(anim + 0x2E);
            }
        }
    }

    if (!(*(u16 *)(arg0 + 6) & 0x400)) {
        light = (u8 *)lightGetStrongestEffect(*(f32 *)(arg0 + 0xC), *(f32 *)(arg0 + 0x10),
                                              *(f32 *)(arg0 + 0x14));
        if (light != NULL) {
            f0 = *(f32 *)(light + 0x24);
            f12 = *(f32 *)(light + 0x18);
            f14 = *(f32 *)(light + 0x1C);
            f16 = *(f32 *)(light + 0x20);
            f18 = f0 * 0.25f;
            f8 = *(f32 *)(light + 0x44);
        } else {
            f18 = 0.0f;
            f12 = *(f32 *)(arg0 + 0xC);
            f14 = *(f32 *)(arg0 + 0x10);
            f16 = *(f32 *)(arg0 + 0x14);
            f0 = 0.0f;
            f8 = 0.0f;
        }
        windowMakeBeams(arg0, f12, f14, f16, f0, f18, f8);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o66/overlay_66/windowfxControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void windowMakeBeams(u8 *arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    u8 *state;
    void **table;
    void **entry;
    u8 *wd;
    u8 *src;
    u8 *out;
    s16 count;
    s32 i;
    s32 type;
    s32 toggle;
    s32 v;
    s16 x;
    s16 y;
    f32 scale;
    f32 cosx;
    f32 sinx;
    f32 cosy;
    f32 siny;
    f32 cosz;
    f32 sinz;
    f32 t14;
    f32 t22;
    f32 t2;
    f32 t12;
    f32 t30;
    f32 sp5C;
    f32 ratioA;
    f32 ratioB;
    f32 ratioC;
    f32 dx;
    f32 dy;
    f32 d2;
    f32 dist;
    f32 f2;

    state = *(u8 **)(arg0 + 0x68);
    table = *(void ***)(arg0 + 0x6C);
    entry = (void **)table[(s8)arg0[0x3A]];
    if (entry == NULL) {
        return;
    }
    wd = (u8 *)entry[0];
    if (wd == NULL) {
        return;
    }

    arg1 -= *(f32 *)(arg0 + 0xC);
    arg2 -= *(f32 *)(arg0 + 0x10);
    arg3 -= *(f32 *)(arg0 + 0x14);

    cosx = Cosf(-*(s16 *)(arg0 + 0));
    sinx = Sinf(-*(s16 *)(arg0 + 0));
    t14 = (arg1 * cosx) + (arg3 * sinx);
    t22 = (arg3 * cosx) - (arg1 * sinx);

    cosy = Cosf(-*(s16 *)(arg0 + 2));
    siny = Sinf(-*(s16 *)(arg0 + 2));
    t2 = (arg2 * cosy) - (t22 * siny);
    t12 = (t22 * cosy) + (arg2 * siny);

    cosz = Cosf(-*(s16 *)(arg0 + 4));
    sinz = Sinf(-*(s16 *)(arg0 + 4));
    arg1 = (t14 * cosz) - (t2 * sinz);
    arg2 = (t2 * cosz) + (t14 * sinz);

    type = state[0xA];
    scale = *(f32 *)(arg0 + 8);
    ratioA = (f32)type / scale;

    if (arg5 < arg4) {
        dist = arg4 - arg5;
        ratioB = ratioA / dist;
        ratioC = arg6 / dist;
    } else {
        ratioC = 0.0f;
        ratioB = 0.0f;
    }

    toggle = state[8] ^ 1;
    state[8] = (u8)toggle;
    count = *(s16 *)(wd + 0x12);
    out = (u8 *)((void **)state)[toggle & 0xFF];
    src = *(u8 **)(wd + 0x1C);
    entry[1] = out;
    *(void **)(arg0 + 0x44) = out;

    if (count != 0) {
        t30 = 0.0f - t12;
        sp5C = t30 * t30;
        i = count - 1;
        do {
            x = *(s16 *)(src + 0);
            y = *(s16 *)(src + 2);
            dx = ((f32)x * scale) - arg1;
            dy = ((f32)y * scale) - arg2;
            d2 = (dx * dx) + (dy * dy) + sp5C;

            if (*(s16 *)(src + 4) == 0) {
                if (d2 < (arg5 * arg5)) {
                    /* asm: float to int with clamp of negatives to -1 */
                    v = (s32)arg6;
                    if (v < 0) {
                        v = -1;
                    }
                    out[9] = (s8)v;
                } else if (d2 < (arg4 * arg4)) {
                    out[9] = (s8)(s32)((arg4 - sqrtf(d2)) * ratioC);
                } else {
                    out[9] = 0;
                }
            } else if (d2 < (arg4 * arg4)) {
                dist = sqrtf(d2);
                f2 = dist;
                if (dist > 0.0f) {
                    if (dist < arg5) {
                        f2 = ratioA / dist;
                    } else {
                        f2 = ((arg4 - dist) * ratioB) / dist;
                    }
                }
                *(s16 *)(out + 0) = (s16)(x + (s32)(dx * f2));
                *(s16 *)(out + 2) = (s16)(y + (s32)(dy * f2));
                *(s16 *)(out + 4) = (s16)(s32)(t30 * f2);
            } else {
                *(s16 *)(out + 0) = x;
                *(s16 *)(out + 2) = y;
                *(s16 *)(out + 4) = 0;
            }
            src += 0xA;
            out += 0xA;
        } while (i-- != 0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o66/overlay_66/windowMakeBeams.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
/* Appends one 64-bit display list command and advances the list pointer. */
static void windowGfxWord(Gfx **dl, u32 hi, u32 lo) {
    Gfx *g = *dl;

    *dl = g + 1;
    g->words.w0 = hi;
    g->words.w1 = lo;
}

void windowDrawBeams(Gfx **arg0, MatrixS **arg1, ObjectTransform *arg2) {
    u8 *win = (u8 *)arg2;
    u8 *state;
    void **table;
    void **entry;
    u8 *wd;
    u8 *recs;
    u8 *rec;
    s32 count;
    s32 i;
    s32 tex;
    s32 hasTex;
    u32 s4;
    s32 a;
    s32 b;
    s32 da;
    s32 db;
    u32 addr;
    u32 ta;

    state = *(u8 **)(win + 0x68);
    table = *(void ***)(win + 0x6C);
    entry = (void **)table[(s8)win[0x3A]];
    wd = (u8 *)entry[0];

    camPushModelMtx(arg0, arg1, arg2, 1.0f, 0.0f);
    windowGfxWord(arg0, 0xBF000000, 0);

    count = *(s16 *)(wd + 0x16);
    s4 = *(u32 *)(state + (state[8] * 4));
    if (s4 == 0) {
        s4 = (u32)*(void **)(wd + 0x1C);
    }
    recs = *(u8 **)(wd + 0x24);
    if (recs[0] == 0xFF) {
        tex = 0;
        hasTex = 0;
    } else {
        tex = *(s32 *)((u8 *)*(void **)(wd + 0x18) + (recs[0] * 8));
        hasTex = 1;
    }
    texDPTextureX(arg0, tex, 0x16, 0);
    windowGfxWord(arg0, 0xFA000000, 0xFFFFFFFF);
    windowGfxWord(arg0, 0xFB000000, 0xFFFFFF00);

    i = count - 1;
    if (count != 0) {
        rec = recs;
        do {
            if (!(*(u32 *)(rec + 0xC) & 0x400)) {
                a = *(s16 *)(rec + 6);
                b = *(s16 *)(rec + 8);
                da = *(s16 *)(rec + 0x16) - a;
                ta = ((u32)(a * 0xA) + s4 + 0x80000000);
                db = *(s16 *)(rec + 0x18) - b;

                windowGfxWord(arg0,
                              ((((da * 8) | (ta & 6)) & 0xFF) << 16) | 0x04000000 | (((da * 0xA) + 8) & 0xFFFF),
                              ta);
                addr = (u32)*(u8 **)(wd + 0x20) + (b * 0x10) + 0x80000000;
                windowGfxWord(arg0,
                              ((((((db - 1) * 0x10) | hasTex) & 0xFF) << 16) | 0x05000000) | ((db * 0x10) & 0xFFFF),
                              addr);
            }
            rec += 0x10;
        } while (i-- != 0);
    }

    camRestoreModelMtx(arg0);
    windowGfxWord(arg0, 0xE7000000, 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o66/overlay_66/windowDrawBeams.s")
#endif
