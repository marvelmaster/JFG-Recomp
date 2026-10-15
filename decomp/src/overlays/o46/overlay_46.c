#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern u8 animlockon[];
extern s32 numanimlockons;
extern void **animpath;
extern u8 fadeR[];
extern s16 fadeA;
extern s16 fadeCount;
extern s16 fadeG;
extern s16 fadeB;
extern s16 fadeFromA;
extern s16 fadeToA;
extern s16 fadeTime;
extern s16 trackFade;
extern s16 trackFadeCount;
extern s16 trackFadeEnd;
extern s16 trackFadeStart;
extern s16 trackFadeTime;
extern s32 numexceptions;
extern u8 D_overlay_46_02E00950[];
void trackFadeExceptions(void);
void dayGetTrackFade(s32 *r, s32 *g, s32 *b);
void girlMagicTrackFade(s32 *r, s32 *g, s32 *b);
void mantisLightingGetTrackFade(s32 *r, s32 *g, s32 *b);
s32 runlinkIsModuleLoaded(s32 module);
void viGetCurrentSize(s32 *w, s32 *h);
void texDPInit(Gfx **dl);
s32 camProjectPoint(f32 x, f32 y, s32 z, f32 *sx, f32 *sy, s32 arg5);
void frontDrawRectangles(s32 count, void *rects, s32 flags);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqLockOnInit(s32 arg0, s8 arg1, s8 arg2, s8 arg3) {
    s8 *entry;
    s32 i;

    if (numanimlockons < 8) {
        for (i = 0; i < 7; i++) {
            entry = &animlockon[i * 8];
            if (entry[0] == -1) {
                entry[0] = 0;
                entry[1] = 0x1E;
                entry[2] = 0x1E;
                entry[3] = 0x1E;
                entry[4] = arg1;
                entry[5] = arg2;
                entry[6] = arg3;
                entry[7] = (s8) arg0;
                numanimlockons += 1;
                return;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o46/overlay_46/animseqLockOnInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqLockOnDelete(s32 arg0) {
    s8 *entry;
    s32 i;

    if (numanimlockons > 0) {
        for (i = 0; i < 7; i++) {
            entry = &animlockon[i * 8];
            if ((entry[0] != -1) && (arg0 == entry[7])) {
                entry[0] = -1;
                numanimlockons -= 1;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o46/overlay_46/animseqLockOnDelete.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqLockOnUpdate(s32 arg0) {
    s8 *entry;
    s32 i;
    s8 prevA1;
    s8 prevA2;
    void *path;
    void *obj;

    for (i = 0; i < 7; i++) {
        entry = &animlockon[i * 8];
        if (entry[0] != -1) {
            if (entry[0] < 8) {
                entry[0] = (s8) (entry[0] + 1);
            }
            prevA1 = entry[1];
            prevA2 = entry[2];
            entry[1] = (s8) (prevA1 - arg0);
            entry[2] = prevA1;
            entry[3] = prevA2;
            if (entry[1] < 0) {
                entry[1] = 0;
            }
            path = animpath[entry[7]];
            if (path != NULL) {
                obj = *(void **) ((u8 *) path + 0x8);
                if (obj != NULL) {
                    if (entry[0] & 1) {
                        *(u8 *) ((u8 *) obj + 0x93) = 6;
                        *(void **) ((u8 *) obj + 0x68) = entry + 4;
                    } else {
                        *(u8 *) ((u8 *) obj + 0x93) = 0;
                        *(void **) ((u8 *) obj + 0x68) = NULL;
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o46/overlay_46/animseqLockOnUpdate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_46_02E001C4_1F64D3C(s32 arg0, s16 arg1, s16 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    /* arg0 is unused (a0 never read by the asm); arg1..arg8 = a1,a2,a3,stack */
    struct {
        s16 unk0;
        s16 unk2;
        s16 unk4;
        s16 unk6;
        s32 unk8;
    } rect[8];
    s32 color;
    s32 xr;
    s32 yb;

    xr = arg1 + arg3;
    yb = arg2 + arg4;
    color = (arg5 << 24) | (arg6 << 16) | (arg7 << 8) | (arg8 & 0xFF);

    rect[0].unk0 = arg1 - 2;
    rect[0].unk2 = arg2 - 2;
    rect[0].unk4 = xr + 2;
    rect[0].unk6 = arg2 + 3;
    rect[0].unk8 = 0;

    rect[1].unk0 = arg1;
    rect[1].unk2 = arg2;
    rect[1].unk4 = xr + 1;
    rect[1].unk6 = arg2 + 1;
    rect[1].unk8 = color;

    rect[2].unk0 = arg1 - 2;
    rect[2].unk2 = arg2 - 2;
    rect[2].unk4 = arg1 + 3;
    rect[2].unk6 = yb + 2;
    rect[2].unk8 = 0;

    rect[3].unk0 = arg1;
    rect[3].unk2 = arg2 + 1;
    rect[3].unk4 = arg1 + 1;
    rect[3].unk6 = yb;
    rect[3].unk8 = color;

    rect[4].unk0 = xr - 2;
    rect[4].unk2 = arg2 - 2;
    rect[4].unk4 = xr + 3;
    rect[4].unk6 = yb + 2;
    rect[4].unk8 = 0;

    rect[5].unk0 = xr;
    rect[5].unk2 = arg2 + 1;
    rect[5].unk4 = xr + 1;
    rect[5].unk6 = yb;
    rect[5].unk8 = color;

    rect[6].unk0 = arg1 - 2;
    rect[6].unk2 = yb - 2;
    rect[6].unk4 = xr + 2;
    rect[6].unk6 = yb + 3;
    rect[6].unk8 = 0;

    rect[7].unk0 = arg1;
    rect[7].unk2 = yb;
    rect[7].unk4 = xr + 1;
    rect[7].unk6 = yb + 1;
    rect[7].unk8 = color;

    frontDrawRectangles(8, rect, 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o46/overlay_46/func_overlay_46_02E001C4_1F64D3C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 animseqLockOnDraw(s32 arg0) {
    f32 sx;
    f32 sy;
    s8 *entry;
    s8 *p;
    void *path;
    void *obj;
    s32 k;
    s32 j;
    s32 ret;
    s32 size;
    s32 radius;
    s32 prevRadius;
    s32 dbl;

    ret = 0;
    for (k = 0; k < 7; k++) {
        ret = 7 - k;
        entry = &animlockon[k * 8];
        if (entry[0] != -1) {
            path = animpath[entry[7]];
            if (path != NULL) {
                obj = *(void **) ((u8 *) path + 0x8);
                if (obj != NULL) {
                    p = entry + 1;
                    if (camProjectPoint(*(f32 *) ((u8 *) obj + 0xC), *(f32 *) ((u8 *) obj + 0x10),
                                        *(s32 *) ((u8 *) obj + 0x14), &sx, &sy, 1) != 0) {
                        size = 0xA0;
                        prevRadius = -1;
                        for (j = 0; j < 2; j++) {
                            radius = (p[0] * 8) + 0x10;
                            p++;
                            if (radius != prevRadius) {
                                dbl = radius * 2;
                                func_overlay_46_02E001C4_1F64D3C(arg0, (s32) sx - radius, (s32) sy - radius, dbl, dbl,
                                                                 entry[4], entry[5], entry[6], size);
                                prevRadius = radius;
                            }
                            size -= 0x34;
                        }
                    }
                }
            }
        }
    }
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o46/overlay_46/animseqLockOnDraw.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqStartNoisyFade(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4) {
    *(s16 *) fadeR = arg0;
    fadeG = arg1;
    fadeB = arg2;
    fadeFromA = fadeA;
    fadeToA = arg3;
    fadeTime = (s16) arg4;
    fadeCount = (s16) arg4;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o46/overlay_46/animseqStartNoisyFade.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqUpdateNoisyFade(s32 arg0) {
    if (fadeCount != 0) {
        fadeCount -= arg0;
        fadeA = fadeToA;
        if (fadeCount > 0) {
            fadeA += (s32) ((fadeFromA - fadeToA) * fadeCount) / (s16) fadeTime;
            return;
        }
        fadeCount = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o46/overlay_46/animseqUpdateNoisyFade.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqDrawNoisyFade(Gfx **arg0) {
    s32 w;
    s32 h;
    s32 inv;
    Gfx *gfx;

    if (fadeA != 0) {
        viGetCurrentSize(&w, &h);
        inv = 0xFF - fadeA;
        gfx = *arg0;
        *arg0 = gfx + 1;
        gfx->words.w0 = 0x06000000;
        gfx->words.w1 = (u32) D_overlay_46_02E00950;
        gfx = *arg0;
        *arg0 = gfx + 1;
        gfx->words.w0 = 0xFA000000;
        gfx->words.w1 = (((s32) (*(s16 *) fadeR * inv) >> 8) << 0x18)
            | ((((s32) (fadeG * inv) >> 8) & 0xFF) << 0x10)
            | ((((s32) (fadeB * inv) >> 8) & 0xFF) << 8)
            | (fadeA & 0xFF);
        gfx = *arg0;
        *arg0 = gfx + 1;
        gfx->words.w0 = ((w & 0x3FF) << 0xE) | 0xF6000000 | ((h & 0x3FF) * 4);
        gfx->words.w1 = 0;
        texDPInit(arg0);
        gfx = *arg0;
        *arg0 = gfx + 1;
        gfx->words.w1 = -1U;
        gfx->words.w0 = 0xFA000000;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o46/overlay_46/animseqDrawNoisyFade.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqUpdateTrackFade(u8 *arg0, void *arg1, s32 arg2) {
    s32 sp4C;   /* r */
    s32 sp48;   /* g */
    s32 sp44;   /* b */
    s16 var_t0;
    s32 count;
    s32 i;
    s32 k;
    s32 n;
    s32 cnt;
    u8 *ent;
    u8 *side;
    u8 *src;
    u8 *dst;
    s16 *out16;

    var_t0 = trackFadeEnd;
    sp4C = (s32) trackFadeEnd;
    if (trackFadeCount != 0) {
        if (arg2 < trackFadeCount) {
            trackFadeCount -= arg2;
            var_t0 += (s32) ((trackFadeStart - trackFadeEnd) * trackFadeCount) / (s16) trackFadeTime;
        } else {
            trackFadeCount = 0;
        }
        trackFade = var_t0;
        sp4C = (s32) var_t0;
    }
    if (runlinkIsModuleLoaded(0x27) != 0) {
        mantisLightingGetTrackFade(&sp4C, &sp48, &sp44);
    } else if (runlinkIsModuleLoaded(0x17) != 0) {
        dayGetTrackFade(&sp4C, &sp48, &sp44);
    } else {
        sp48 = sp4C;
        sp44 = sp4C;
    }
    if (runlinkIsModuleLoaded(0x1D) != 0) {
        girlMagicTrackFade(&sp4C, &sp48, &sp44);
    }

    count = *(s16 *) ((u8 *) arg1 + 0x1A);
    ent = *(u8 **) ((u8 *) arg1 + 0x4);
    for (i = 0; i < count; i++) {
        if (arg0[i] != 0) {
            side = *(u8 **) (ent + 0x34);
            if (side != NULL) {
                cnt = *(s16 *) (ent + 0x24);
                out16 = *(s16 **) (side + 0x4);
                n = (cnt + 0xF) >> 4;
                for (k = 0; k < n; k++) {
                    *out16 = 0;
                    out16++;
                }
                src = *(u8 **) side;
                dst = *(u8 **) ent;
                for (k = 0; k < cnt; k++) {
                    dst[10 * k + 6] = (s8) ((src[3 * k] * sp4C) >> 8);
                    dst[10 * k + 7] = (s8) (((s32) (src[3 * k + 1] * sp48)) >> 8);
                    dst[10 * k + 8] = (s8) (((s32) (src[3 * k + 2] * sp44)) >> 8);
                }
                *(s8 *) (ent + 0x32) = 0;
            }
        }
        ent += 0x48;
    }
    if (numexceptions > 0) {
        trackFadeExceptions();
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o46/overlay_46/animseqUpdateTrackFade.s")
#endif
