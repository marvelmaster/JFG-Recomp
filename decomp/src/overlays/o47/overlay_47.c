#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
extern u8 animscroll[];
extern u8 animlight[];
void trackAddTextureScroll(u8, s32, s32);
extern f32 D_overlay_47_02F02610;
extern f32 D_overlay_47_02F02614;
extern f32 D_overlay_47_02F02618;
extern f32 D_overlay_47_02F0261C;
extern f32 D_overlay_47_02F02620;
extern f32 D_overlay_47_02F02624;
extern f32 D_overlay_47_02F02628;
extern f32 D_overlay_47_02F0262C;
extern f32 D_overlay_47_02F02630;
extern f32 D_overlay_47_02F0264C;
extern u8 D_overlay_47_02F026E0[];
extern void *animcamera[];
void objAnimDframe(void *, f32, f32, void *);
extern u8 *front_text;
extern void **animpath;
extern f32 D_overlay_47_02F026B8;
extern f32 D_overlay_47_02F026D0;
extern s16 D_overlay_47_02F025A0[];
extern s16 D_overlay_47_02F025A8[];
extern s16 D_overlay_47_02F025B0[];
extern s16 D_overlay_47_02F025B8[];
extern s16 D_overlay_47_02F025C0[];
extern s16 D_overlay_47_02F025C8[];
s32 texAnimateSprite(s32, s32 *, s32, void *, s32);
void lightObject(void *, void *, s32, s32);
void modGenAnimMatrices(void *, void *, void *, f32, f32);
void objAnimTextures(void *, void *, void *, s8);
s32 objMakeGunMtx(void *, void *, void *, s32, s32, s32, s32, s32);
void *objSetupObject(void *, s32);
s32 mainGetGameFlag(s32);
s32 mathRnd(s32, s32);
void mathOneFloatPY(s16 *, s32 *);
void hoovergemCreate(f32, f32, s32, s16, s32, f32, f32);
void bloodSpurtAdd(f32, f32, s32, s32, f32, f32, s32, s32, f32);
void camPushFloatModelMtx(s32, s32, s32, s32);
void camPushMuzzleMtx(s32, s32, s32, void *);
void mathRpyXyzMtx(f32 *, s16 *);
void fontUseFont(s32);
void fontBackground(s32, s32, s32, s32);
void fontColour(s32, s32, s32, s32, s32);

void fontPrintXY(s32, s32, s32, s32, s32);
void fxDrawWindow(s32, s32, s32, s32, s32, s32, s32);
extern s32 playing;
extern f32 D_overlay_47_02F02634;
extern f32 D_overlay_47_02F02638;
extern f32 D_overlay_47_02F0263C;
extern f32 D_overlay_47_02F02640;
extern f32 D_overlay_47_02F02644;
extern f32 D_overlay_47_02F02648;
void func_overlay_47_02F013D0_1F66B38(u8 *, u8 *, s32);
void func_overlay_47_02F01560_1F66CC8(void *, void *, s32);
f32 Powerf(f32, s32);
s16 trackGetBlock(f32, f32, f32);
void partUpdateTriggers(void *, s32);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 animseqUpdateTextureScrollers(s16 arg0) {
    u8 *var_s0;
    s16 temp_v1;
    s16 var_v0;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_v0 = 0;
    s32 var_s4;
    u8 temp_t4;
    u8 temp_v0_2;

    var_s0 = animscroll;
    var_s4 = 7;
    do {
        temp_v0 = var_s4;
        if (var_s0[0] != 0xFF) {
            temp_v1 = *(s16 *)(var_s0 + 0x2);
            var_v0 = temp_v1;
            if (temp_v1 != 0) {
                if (arg0 < temp_v1) {
                    var_v0 = arg0;
                }
                *(s16 *)(var_s0 + 0x2) = (s16)(temp_v1 - var_v0);
                *(s32 *)(var_s0 + 0x4) = *(s32 *)(var_s0 + 0x4) + (*(s32 *)(var_s0 + 0x8) * var_v0);
                *(s32 *)(var_s0 + 0xC) = *(s32 *)(var_s0 + 0xC) + (*(s32 *)(var_s0 + 0x10) * var_v0);
            }
            temp_v0_2 = var_s0[0x1];
            temp_s1 = ((*(s32 *)(var_s0 + 0x4) * arg0) >> 8) + (temp_v0_2 & 0xF);
            temp_s2 = ((*(s32 *)(var_s0 + 0xC) * arg0) >> 8) + ((s32)temp_v0_2 >> 4);
            trackAddTextureScroll(var_s0[0], temp_s1 >> 3, temp_s2 >> 3);
            temp_t4 = temp_s1 & 7;
            var_s0[0x1] = (u8)(temp_t4 | ((temp_s2 & 7) * 0x10));
        }
        var_s0 += 0x14;
        var_s4 -= 1;
    } while (var_s4 != 0);
    return temp_v0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o47/overlay_47/animseqUpdateTextureScrollers.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 animseqUpdateLightChangers(s32 arg0) {
    u8 *var_s0;
    s16 temp_t2;
    s32 temp_lo;
    s32 temp_s1;
    s32 temp_v0 = 0;
    s32 var_s3;
    u8 temp_a0;
    u8 temp_a1;
    u8 temp_a2;
    u8 temp_a3;
    u8 var_s2;
    u8 var_t0;
    u8 var_t1;
    u8 var_v1;

    var_s0 = animlight;
    var_s3 = 0xB;
    do {
        temp_s1 = *(s32 *)(var_s0 + 0x0);
        if (temp_s1 != 0) {
            temp_t2 = *(s16 *)(var_s0 + 0xC);
            temp_a0 = var_s0[0x5];
            temp_a1 = var_s0[0x7];
            temp_a2 = var_s0[0x9];
            temp_a3 = var_s0[0xB];
            var_v1 = temp_a0;
            var_t0 = temp_a1;
            var_t1 = temp_a2;
            var_s2 = temp_a3;
            if (arg0 >= temp_t2) {
                *(s32 *)(var_s0 + 0x0) = 0;
            } else {
                *(s16 *)(var_s0 + 0xC) = (s16)(temp_t2 - arg0);
                temp_lo = ((s32)*(s16 *)(var_s0 + 0xC) << 0x10) / (s16)*(s16 *)(var_s0 + 0xE);
                var_v1 += (s32)((var_s0[0x4] - temp_a0) * temp_lo) >> 0x10;
                var_t0 += (s32)((var_s0[0x6] - temp_a1) * temp_lo) >> 0x10;
                var_t1 += (s32)((var_s0[0x8] - temp_a2) * temp_lo) >> 0x10;
                var_s2 += (s32)((var_s0[0xA] - temp_a3) * temp_lo) >> 0x10;
            }
            if (temp_s1 < 0) {
                changeLightColour((UnkLight *)temp_s1, var_v1, var_t0, var_t1);
                changeLightIntensity((UnkLight *)temp_s1, var_s2);
            } else {
                u8 *dst = (u8 *)((u32)temp_s1 | 0x80000000u);
                dst[0x38] = var_v1;
                dst[0x39] = var_t0;
                dst[0x3A] = var_t1;
                dst[0x3B] = var_s2;
            }
        }
        temp_v0 = var_s3;
        var_s0 += 0x10;
        var_s3 -= 1;
    } while (var_s3 != 0);
    return temp_v0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o47/overlay_47/animseqUpdateLightChangers.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqSampleCurve(void *arg0, f32 arg1, f32 *arg2, f32 *arg3, u32 arg4) {
    u8 *c = (u8 *)arg0;
    u8 *p1 = *(u8 **)(c + 0x28);
    u8 *p0 = *(u8 **)(c + 0x24);
    u8 *p2 = *(u8 **)(p1 + 0x28);
    f32 v[4];
    s32 isInt = 0;
    s32 off;
    s32 i;
    s32 j;
    f32 diff;
    f32 temp_f0_2;
    f32 temp_f16;
    f32 temp_f14;
    f32 temp_f18;

    switch (arg4) {
    case 0:
        off = 0xC;
        break;
    case 1:
        off = 0x10;
        break;
    case 2:
        off = 0x14;
        break;
    case 3:
        isInt = 1;
        off = 0;
        break;
    case 4:
        isInt = 1;
        off = 2;
        break;
    case 5:
        isInt = 1;
        off = 4;
        break;
    default:
        off = 8;
        break;
    }
    if (isInt) {
        v[0] = (f32)*(s16 *)(p0 + off);
        v[1] = (f32)*(s16 *)(c + off);
        v[2] = (f32)*(s16 *)(p1 + off);
        v[3] = (f32)*(s16 *)(p2 + off);
        for (i = 0; i < 3; i++) {
            diff = v[i + 1] - v[i];
            if (diff > 32768.0f) {
                for (j = i + 1; j < 4; j++) {
                    v[j] -= 65536.0f;
                }
            } else if (diff < -32768.0f) {
                for (j = i + 1; j < 4; j++) {
                    v[j] += 65536.0f;
                }
            }
        }
    } else {
        v[0] = *(f32 *)(p0 + off);
        v[1] = *(f32 *)(c + off);
        v[2] = *(f32 *)(p1 + off);
        v[3] = *(f32 *)(p2 + off);
    }
    if (c[0x7] != 0) {
        if (arg2 != NULL) {
            *arg2 = ((v[2] - v[1]) * arg1) + v[1];
        }
        if (arg3 != NULL) {
            *arg3 = v[2] - v[1];
        }
    } else {
        temp_f0_2 = D_overlay_47_02F02610 * v[0];
        temp_f16 = (v[2] * D_overlay_47_02F02614) + temp_f0_2;
        temp_f14 = (v[3] * D_overlay_47_02F02618) +
                   ((D_overlay_47_02F0261C * v[0]) + (D_overlay_47_02F02620 * v[1]) + (D_overlay_47_02F02624 * v[2]));
        temp_f18 = (v[3] * D_overlay_47_02F02628) +
                   (temp_f0_2 + (D_overlay_47_02F0262C * v[1]) + (D_overlay_47_02F02630 * v[2]));
        if (arg2 != NULL) {
            *arg2 = (((((temp_f18 * arg1) + temp_f14) * arg1) + temp_f16) * arg1) + v[1];
        }
        if (arg3 != NULL) {
            *arg3 = (((temp_f18 * 3.0f * arg1) + (2.0f * temp_f14)) * arg1) + temp_f16;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o47/overlay_47/animseqSampleCurve.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s16 func_overlay_47_02F007DC_1F65F44(f32 arg0, s16 arg1, s32 arg2) {
    s32 temp_t1;
    s32 var_v1;

    var_v1 = (arg2 - arg1) & 0xFFFF;
    temp_t1 = (arg1 - arg2) & 0xFFFF;
    if (temp_t1 < var_v1) {
        var_v1 = -temp_t1;
    }
    return (s16)(arg1 + (s32)((f32)var_v1 * arg0));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o47/overlay_47/func_overlay_47_02F007DC_1F65F44.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Path layout (cf. src/anim.c animseqInitPath / func_80077BE8): +0x01 anim path index,
// +0x08 obj, +0x10 blend, +0x15 mode, +0x16 flags (&4 = direct update), +0x18 current node,
// +0x1C t, +0x2A steps left, +0x2C accumulated distance, +0x30 speed.
// Node layout: +0x0C/+0x10/+0x14 pos, +0x18/+0x1A/+0x1C s16 values, +0x20 f32 length,
// +0x28 next node.
void animseqUpdatePath(u8 *arg0, f32 arg1, s32 arg2, s32 arg3) {
    u8 *obj;
    u8 *node;
    u8 *next;
    u8 *cur;
    u8 *objtype;
    u8 *p;
    f32 *pv;
    f32 frames;
    f32 t;
    f32 tTemp;
    f32 tNew;
    f32 stepT;
    f32 stepHalf;
    f32 remain;
    f32 lenPrev;
    f32 lenNext;
    f32 lenNode;
    f32 accum;
    f32 cx;
    f32 cy;
    f32 cz;
    f32 bx;
    f32 by;
    f32 bz;
    f32 len;
    f32 avg;
    f32 dtUsed;
    f32 blend;
    f32 k;
    s32 loopState;
    s32 steps;
    s32 mode;
    s16 rx;
    s16 ry;
    s16 rz;

    if (arg0 != NULL) {
        obj = *(u8 **)(arg0 + 0x08);
        if (obj != NULL && !(arg1 < 0.0f)) {
            frames = arg1 * 60.0f;
            cur = *(u8 **)(obj + 0x5C);
            if (cur != NULL && *(s16 *)(cur + 0x12E) == 0) {
                *(f32 *)(cur + 0x118) = *(f32 *)(obj + 0x0C);
                *(f32 *)(cur + 0x11C) = *(f32 *)(obj + 0x10);
                *(f32 *)(cur + 0x120) = *(f32 *)(obj + 0x14);
                *(s16 *)(cur + 0x128) = *(s16 *)(obj + 0x00);
                *(s16 *)(cur + 0x126) = *(s16 *)(obj + 0x02);
                *(s16 *)(cur + 0x124) = *(s16 *)(obj + 0x04);
                *(s16 *)(cur + 0x12E) = 1;
            }
            func_overlay_47_02F013D0_1F66B38(arg0, obj, arg3);
            if ((arg0[0x16] & 4) || playing < 0) {
                func_overlay_47_02F01560_1F66CC8(arg0, obj, arg3);
                partUpdateTriggers(obj, arg2);
            } else {
                node = *(u8 **)(arg0 + 0x18);
                t = *(f32 *)(arg0 + 0x1C);
                if (arg1 == 0.0f) {
                    animseqSampleCurve(node, t, (f32 *)(obj + 0x0C), NULL, 0);
                    animseqSampleCurve(node, t, (f32 *)(obj + 0x10), NULL, 1);
                    animseqSampleCurve(node, t, (f32 *)(obj + 0x14), NULL, 2);
                    *(s16 *)(obj + 0x2E) = trackGetBlock(*(f32 *)(obj + 0x0C), *(f32 *)(obj + 0x10),
                                                         *(f32 *)(obj + 0x14));
                } else {
                    next = *(u8 **)(node + 0x28);
                    if (*(f32 *)(node + 0x20) != 0.0f || *(f32 *)(next + 0x20) != 0.0f) {
                        lenNode = *(f32 *)(node + 0x20);
                        lenPrev = lenNode + (t * (*(f32 *)(next + 0x20) - lenNode));
                        stepT = D_overlay_47_02F02634;
                        stepHalf = D_overlay_47_02F02638;
                        *(f32 *)(obj + 0x1C) = *(f32 *)(obj + 0x0C);
                        *(f32 *)(obj + 0x20) = *(f32 *)(obj + 0x10);
                        *(f32 *)(obj + 0x24) = *(f32 *)(obj + 0x14);
                        accum = 0.0f;
                        loopState = 0;
                        remain = arg1;

                        if (!(t == 1.0f && *(u8 **)(next + 0x28) == next)) {
                            for (;;) {
                                /* loop head (asm label .Loverlay_47_02F00AD8) */
                                next = *(u8 **)(node + 0x28);
                                if (t == 1.0f) {
                                    node = next;
                                    next = *(u8 **)(node + 0x28);
                                    stepHalf = D_overlay_47_02F02640;
                                    stepT = D_overlay_47_02F0263C;
                                    t = 0.0f;
                                    loopState = 0;
                                }
                                tTemp = t + stepT;
                                tNew = tTemp;
                                if (tTemp > 1.0f) {
                                    cx = *(f32 *)(next + 0x0C);
                                    cy = *(f32 *)(next + 0x10);
                                    cz = *(f32 *)(next + 0x14);
                                    lenNext = *(f32 *)(next + 0x20);
                                    tNew = 1.0f;
                                } else {
                                    lenNode = *(f32 *)(node + 0x20);
                                    lenNext = lenNode + (tNew * (*(f32 *)(next + 0x20) - lenNode));
                                    animseqSampleCurve(node, tNew, &cx, NULL, 0);
                                    animseqSampleCurve(node, tTemp, &cy, NULL, 1);
                                    animseqSampleCurve(node, tTemp, &cz, NULL, 2);
                                }

                                bx = cx - *(f32 *)(obj + 0x0C);
                                by = cy - *(f32 *)(obj + 0x10);
                                bz = cz - *(f32 *)(obj + 0x14);
                                len = sqrtf((bx * bx) + (by * by) + (bz * bz));

                                avg = (lenPrev + lenNext) * 0.5f;
                                if (0.0f < avg) {
                                    dtUsed = len / avg;
                                    remain -= dtUsed;
                                    if ((D_overlay_47_02F02644 < remain && remain < D_overlay_47_02F02648)
                                        || loopState == 8) {
                                        loopState = 9;
                                        *(f32 *)(obj + 0x0C) = cx;
                                        *(f32 *)(obj + 0x10) = cy;
                                        *(f32 *)(obj + 0x14) = cz;
                                        *(s16 *)(obj + 0x2E) = trackGetBlock(cx, cy, cz);
                                        t = tNew;
                                        accum = accum + len;
                                    } else if (loopState == 0 && 0.0f < remain) {
                                        *(f32 *)(obj + 0x0C) = cx;
                                        *(f32 *)(obj + 0x10) = cy;
                                        *(f32 *)(obj + 0x14) = cz;
                                        *(s16 *)(obj + 0x2E) = trackGetBlock(cx, cy, cz);
                                        t = tNew;
                                        accum = accum + len;
                                        lenPrev = lenNext;
                                    } else {
                                        /* asm .Loverlay_47_02F00D48: step bisection */
                                        if (0.0f < remain) {
                                            stepT = stepT + stepHalf;
                                        } else {
                                            stepT = stepT - stepHalf;
                                        }
                                        remain += dtUsed;
                                        stepHalf = stepHalf * 0.5f;
                                        loopState += 1;
                                    }
                                } else {
                                    loopState = 9;
                                }

                                if (loopState >= 9) {
                                    break;
                                }
                                if (t == 1.0f && *(u8 **)(*(u8 **)(node + 0x28) + 0x28) == *(u8 **)(node + 0x28)) {
                                    break;
                                }
                            }
                        }

                        /* asm .Loverlay_47_02F00DBC: velocity from position delta */
                        *(f32 *)(obj + 0x1C) = (*(f32 *)(obj + 0x0C) - *(f32 *)(obj + 0x1C)) / frames;
                        *(f32 *)(obj + 0x20) = (*(f32 *)(obj + 0x10) - *(f32 *)(obj + 0x20)) / frames;
                        *(f32 *)(obj + 0x24) = (*(f32 *)(obj + 0x14) - *(f32 *)(obj + 0x24)) / frames;
                    }
                }

                /* asm .Loverlay_47_02F00E08 */
                *(f32 *)(arg0 + 0x1C) = t;
                *(u8 **)(arg0 + 0x18) = node;
                steps = *(s16 *)(arg0 + 0x2A);
                if (steps != 0) {
                    if (arg2 < steps) {
                        *(s16 *)(arg0 + 0x2A) = (s16)(steps - arg2);
                        *(f32 *)(arg0 + 0x2C) = *(f32 *)(arg0 + 0x2C) + (*(f32 *)(arg0 + 0x30) * frames);
                    } else {
                        *(s16 *)(arg0 + 0x2A) = 0;
                        *(f32 *)(arg0 + 0x2C) = *(f32 *)(arg0 + 0x2C) + (*(f32 *)(arg0 + 0x30) * (f32)steps);
                    }
                }

                /* scale from sampled curve (mode 6) */
                animseqSampleCurve(node, t, &bx, NULL, 6);
                objtype = *(u8 **)(obj + 0x40);
                *(f32 *)(obj + 0x08) = (*(f32 *)objtype * *(f32 *)(arg0 + 0x2C)) * bx;
                pv = *(f32 **)(obj + 0x50);
                if (pv != NULL) {
                    *pv = *(f32 *)(objtype + 0x54) * bx;
                }

                rx = *(s16 *)(obj + 0x00);
                ry = *(s16 *)(obj + 0x02);
                rz = *(s16 *)(obj + 0x04);
                mode = arg0[0x15];
                switch (mode) {
                case 1:
                    next = *(u8 **)(node + 0x28);
                    bx = (f32)*(s16 *)(node + 0x18)
                        + ((f32)(*(s16 *)(next + 0x18) - *(s16 *)(node + 0x18)) * t);
                    by = (f32)*(s16 *)(node + 0x1A)
                        + ((f32)(*(s16 *)(next + 0x1A) - *(s16 *)(node + 0x1A)) * t);
                    bz = (f32)*(s16 *)(node + 0x1C)
                        + ((f32)(*(s16 *)(next + 0x1C) - *(s16 *)(node + 0x1C)) * t);
                    rx = (s16)(rx + (s32)(bx * frames));
                    ry = (s16)(ry + (s32)(by * frames));
                    rz = (s16)(rz + (s32)(bz * frames));
                    break;
                case 2:
                    animseqSampleCurve(node, t, NULL, &bx, 0);
                    animseqSampleCurve(node, t, NULL, &by, 1);
                    animseqSampleCurve(node, t, NULL, &bz, 2);
                    rx = (s16)(Arctanf(bx, bz) - 0x8000);
                    ry = (s16)Arctanf(by, sqrtf((bx * bx) + (by * by) + (bz * bz)));
                    animseqSampleCurve(node, t, &bz, NULL, 5);
                    rz = (s16)(s32)bz;
                    break;
                case 3:
                    p = (u8 *)animpath[arg0[0x01]];
                    if (p != NULL) {
                        cur = *(u8 **)(p + 0x08);
                        if (cur != NULL) {
                            bx = *(f32 *)(cur + 0x0C) - *(f32 *)(obj + 0x0C);
                            by = *(f32 *)(cur + 0x10) - *(f32 *)(obj + 0x10);
                            bz = *(f32 *)(cur + 0x14) - *(f32 *)(obj + 0x14);
                            rx = (s16)(Arctanf(bx, bz) - 0x8000);
                            ry = (s16)Arctanf(by, sqrtf((bx * bx) + (by * by) + (bz * bz)));
                            rz = 0;
                        }
                    }
                    break;
                default:
                    animseqSampleCurve(node, t, &bx, NULL, 3);
                    animseqSampleCurve(node, t, &by, NULL, 4);
                    animseqSampleCurve(node, t, &bz, NULL, 5);
                    rx = (s16)(s32)bx;
                    ry = (s16)(s32)by;
                    rz = (s16)(s32)bz;
                    break;
                }

                blend = *(f32 *)(arg0 + 0x10);
                if (blend != 1.0f) {
                    k = 1.0f - Powerf(1.0f - blend, arg2);
                    *(s16 *)(obj + 0x00) = func_overlay_47_02F007DC_1F65F44(k, *(s16 *)(obj + 0x00), rx);
                    *(s16 *)(obj + 0x02) = func_overlay_47_02F007DC_1F65F44(k, *(s16 *)(obj + 0x02), ry);
                    *(s16 *)(obj + 0x04) = func_overlay_47_02F007DC_1F65F44(k, *(s16 *)(obj + 0x04), rz);
                } else {
                    *(s16 *)(obj + 0x00) = rx;
                    *(s16 *)(obj + 0x02) = ry;
                    *(s16 *)(obj + 0x04) = rz;
                }
                func_overlay_47_02F01560_1F66CC8(arg0, obj, arg2);
                partUpdateTriggers(obj, arg2);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o47/overlay_47/animseqUpdatePath.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_47_02F013D0_1F66B38(u8 *arg0, u8 *arg1, s32 arg2) {
    s8 temp_t7;
    u8 temp_v0;
    u8 temp_v1;
    u8 temp_v1_2;
    u8 temp_t2;
    s32 var_v0;

    if (*(s8 *) (*(u8 **) (arg1 + 0x40) + 0x1E) == 0) {
        if (arg0[0x14] != 0) {
            objAnimDframe(arg1, -*(f32 *) (arg0 + 0xC), (f32) arg2, arg0);
        } else {
            objAnimDframe(arg1, *(f32 *) (arg0 + 0xC), (f32) arg2, arg0);
        }
    }
    temp_v0 = arg0[0x27];
    temp_v1 = arg0[0x26];
    if ((s32) temp_v0 < (s32) temp_v1) {
        temp_t2 = temp_v0 + arg2;
        var_v0 = temp_t2 & 0xFF;
        arg0[0x27] = temp_t2;
        if (var_v0 >= (s32) temp_v1) {
            arg0[0x27] = temp_v1;
            var_v0 = temp_v1 & 0xFF;
        }
        temp_v1_2 = arg0[0x24];
        temp_t7 = temp_v1_2 + ((s32) ((arg0[0x25] - temp_v1_2) * var_v0) / (s32) temp_v1);
        *(s8 *) (arg1 + 0x39) = temp_t7;
        if ((temp_t7 & 0xFF) < 0xFF) {
            *(s16 *) (arg1 + 0x6) = (s16) (*(s16 *) (arg1 + 0x6) | 4);
        } else if (!(*(u16 *) (*(u8 **) (arg1 + 0x40) + 0x14) & 4)) {
            *(s16 *) (arg1 + 0x6) = (s16) (*(s16 *) (arg1 + 0x6) & 0xFFFB);
        }
    }
    if (arg0[0x16] & 2) {
        animcamera[0] = arg1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o47/overlay_47/func_overlay_47_02F013D0_1F66B38.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_47_02F01560_1F66CC8(void *arg0, void *arg1, s32 arg2) {
    u8 *obj = (u8 *)arg1;
    u8 *spr = (u8 *)arg0;
    u8 *temp_s1;
    u8 *sp44;
    u8 *temp_v0_3;
    u8 *temp_v1;
    s32 temp_a0;
    s32 temp_v0_2;
    s8 temp_v0;
    s32 sp50;

    temp_v0 = *(s8 *)(*(u8 **)(obj + 0x40) + 0x1E);
    if (temp_v0 == 1) {
        temp_a0 = *(s32 *)(*(u8 **)(obj + 0x6C) + (*(s8 *)(obj + 0x3A) * 4));
        if (temp_a0 != 0) {
            sp50 = 9;
            if (spr[0x14] != 0) {
                sp50 = 0xB;
            }
            texAnimateSprite(temp_a0, &sp50, (s32)(*(f32 *)(spr + 0xC) * 60.0f), obj + 0x28, arg2);
        }
    } else if (temp_v0 == 0) {
        temp_s1 = *(u8 **)(*(u8 **)(obj + 0x6C) + (*(s8 *)(obj + 0x3A) * 4));
        if (temp_s1[0xA] != 0) {
            sp44 = *(u8 **)temp_s1;
            if (*(s8 *)(sp44 + 0x4E) != 0) {
                modGenAnimMatrices(temp_s1, sp44, obj, 1.0f, 0.0f);
                lightObject(obj, temp_s1, *(s32 *)(obj + 0x54), *(s32 *)(temp_s1 + (*(s8 *)(temp_s1 + 0xB) * 4) + 0x10));
            } else {
                if (sp44[0x11] != 0) {
                    temp_s1[0xB] = (s8)(1 - *(s8 *)(temp_s1 + 0xB));
                }
                lightObject(obj, temp_s1, *(s32 *)(obj + 0x54), *(s32 *)(temp_s1 + (*(s8 *)(temp_s1 + 0xB) * 4) + 0x10));
            }
            if (*(s16 *)(obj + 0x48) == 0x33) {
                if (*(u8 **)(obj + 0x60) != NULL) {
                    temp_v0_2 = *(s32 *)(obj + 0x68);
                    objMakeGunMtx(obj, temp_s1, sp44, *(s32 *)(obj + 0x8C), temp_v0_2, temp_v0_2 + 0x40, temp_v0_2 + 0x44, temp_v0_2 + 0x48);
                    temp_v0_3 = *(u8 **)(*(u8 **)(obj + 0x60) + 0x4);
                    if (temp_v0_3 != NULL) {
                        temp_v1 = *(u8 **)(*(u8 **)(temp_v0_3 + 0x6C) + (*(s32 *)(obj + 0x8C) * 4));
                        if (temp_v1 != NULL) {
                            temp_v1[0xA] = (s8)arg2;
                        }
                    }
                }
            }
            if (sp44[0x11] != 0) {
                objAnimTextures(obj, sp44, temp_s1, *(s8 *)(temp_s1 + 0xA));
            }
            temp_s1[0xA] = 0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o47/overlay_47/func_overlay_47_02F01560_1F66CC8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqAddChangeLight(void *arg0, s32 arg1, s8 arg2, s8 arg3, s32 arg4, f32 arg5, s32 arg6) {
    u8 *obj;
    u8 *p;
    s32 n;

    if (arg0 != NULL) {
        obj = (u8 *) arg0;
        p = animlight;
        n = 0xB;
        do {
            if (*(void **) p == NULL) {
                if (arg6 != 0) {
                    *(void **) p = arg0;
                    p[0x4] = obj[0x40];
                    p[0x6] = obj[0x41];
                    p[0x8] = obj[0x42];
                    p[0xA] = obj[0x43];
                } else {
                    *(void **) p = (void *) ((s32) arg0 & 0x7FFFFFFF);
                    p[0x4] = obj[0x38];
                    p[0x6] = obj[0x39];
                    p[0x8] = obj[0x3A];
                    p[0xA] = obj[0x3B];
                }
                p[0x7] = arg2;
                p[0x9] = arg3;
                p[0x5] = (s8) arg1;
                p[0xB] = (s8) arg4;
                *(s16 *) (p + 0xC) = (s16) (s32) (arg5 * D_overlay_47_02F0264C);
                *(s16 *) (p + 0xE) = *(s16 *) (p + 0xC);
                return;
            }
            p += 0x10;
            n -= 1;
        } while (n != 0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o47/overlay_47/animseqAddChangeLight.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqFireBullet(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    u8 *obj = (u8 *)arg0;
    u8 *temp_v1;
    u8 *temp_v0;
    u8 *src;
    u8 sp44[0x24];
    u8 sp38[0xC];

    temp_v1 = *(u8 **)(*(u8 **)(obj + 0x6C) + (*(s8 *)(obj + 0x3A) * 4));
    if (temp_v1 != NULL) {
        *(s16 *)(sp44 + 0x0) = 0x50;
        sp44[0x2] = 0x24;
        sp44[0x3] = 0;
        if (*(s16 *)(obj + 0x48) == 0x33) {
            src = *(u8 **)(obj + 0x68);
            *(s16 *)(sp44 + 0x4) = (s16)(s32)*(f32 *)(src + 0x40);
            *(s16 *)(sp44 + 0x6) = (s16)(s32)*(f32 *)(src + 0x44);
            *(s16 *)(sp44 + 0x8) = (s16)(s32)*(f32 *)(src + 0x48);
        } else if (arg1 < *(u8 *)(*(u8 **)temp_v1 + 0x2D)) {
            src = *(u8 **)(temp_v1 + 0x68) + (arg1 * 0xC);
            *(s16 *)(sp44 + 0x4) = (s16)(s32)*(f32 *)(src + 0x0);
            *(s16 *)(sp44 + 0x6) = (s16)(s32)*(f32 *)(src + 0x4);
            *(s16 *)(sp44 + 0x8) = (s16)(s32)*(f32 *)(src + 0x8);
        } else {
            *(s16 *)(sp44 + 0x4) = (s16)(s32)*(f32 *)(obj + 0xC);
            *(s16 *)(sp44 + 0x6) = (s16)(s32)*(f32 *)(obj + 0x10);
            *(s16 *)(sp44 + 0x8) = (s16)(s32)*(f32 *)(obj + 0x14);
        }
        sp44[0xA] = (u8)arg2;
        sp44[0xB] = (u8)arg6;
        *(s16 *)(sp44 + 0xC) = (s16)arg4;
        *(s16 *)(sp44 + 0xE) = (s16)arg5;
        sp44[0x10] = 0;
        sp44[0x11] = 0;
        sp44[0x12] = 0;
        sp44[0x13] = 0xFF;
        *(f32 *)(sp44 + 0x14) = (f32)arg3;
        *(void **)(sp44 + 0x18) = arg0;
        *(s32 *)(sp44 + 0x1C) = 0;
        *(s32 *)(sp44 + 0x20) = 0;
        temp_v0 = objSetupObject(sp44, 1);
        if (temp_v0 != NULL) {
            *(s32 *)(temp_v0 + 0x3C) = 0;
        }
        *(s16 *)(sp38 + 0x0) = 0xAC;
        sp38[0x2] = 0xC;
        *(s16 *)(sp38 + 0x4) = *(s16 *)(sp44 + 0x4);
        *(s16 *)(sp38 + 0x6) = *(s16 *)(sp44 + 0x6);
        *(s16 *)(sp38 + 0x8) = *(s16 *)(sp44 + 0x8);
        sp38[0xA] = (u8)arg1;
        if ((*(s16 *)(obj + 0x48) != 0x33) || (arg2 == 1)) {
            sp38[0xB] = 0;
        } else {
            sp38[0xB] = 2;
        }
        temp_v0 = objSetupObject(sp38, 1);
        if (temp_v0 != NULL) {
            *(s32 *)(temp_v0 + 0x3C) = 0;
            *(void **)(temp_v0 + 0x88) = arg0;
            *(s32 *)(temp_v0 + 0x8C) = 1;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o47/overlay_47/animseqFireBullet.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqMuzzleFlash(s32 arg0, s32 arg1, void *arg2) {
    s16 *var_v0;
    s16 temp_v0;
    s32 temp_a3;
    u8 rpy[0x18];
    f32 mtx[16];

    temp_v0 = *(s16 *)((u8 *)arg2 + 0x4A);
    temp_a3 = *(s32 *)((u8 *)arg2 + 0x68);
    switch (temp_v0) {
    case 0x2A3:
        var_v0 = D_overlay_47_02F025C8;
        break;
    case 0x2A2:
        var_v0 = D_overlay_47_02F025C0;
        break;
    case 0x2A1:
        var_v0 = D_overlay_47_02F025B8;
        break;
    case 0xC4:
    case 0x11A:
    case 0x1B6:
    case 0x1F6:
    case 0x2BA:
        var_v0 = D_overlay_47_02F025B0;
        break;
    case 0xC6:
    case 0x119:
    case 0x1B5:
    case 0x1F4:
    case 0x204:
    case 0x2B9:
        var_v0 = D_overlay_47_02F025A8;
        break;
    default:
        var_v0 = D_overlay_47_02F025A0;
        break;
    }
    camPushFloatModelMtx(arg0, arg1, temp_a3, temp_a3);
    *(s16 *)(rpy + 0x0) = var_v0[0];
    *(s16 *)(rpy + 0x2) = var_v0[1];
    *(s16 *)(rpy + 0x4) = var_v0[2];
    *(f32 *)(rpy + 0x8) = 1.0f;
    *(f32 *)(rpy + 0xC) = 0.0f;
    *(f32 *)(rpy + 0x10) = 0.0f;
    *(f32 *)(rpy + 0x14) = 0.0f;
    mathRpyXyzMtx(mtx, (s16 *)rpy);
    camPushMuzzleMtx(arg0, arg1, temp_a3 + 0x40, mtx);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o47/overlay_47/animseqMuzzleFlash.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *animseqReleaseBits(s32 arg0, s32 arg1, u32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    void *var_v0;
    u8 *temp_s3;
    f32 var_f22;
    f32 f20;
    s32 spA4;
    s32 spB0;
    s16 sp9C[2];
    s32 sp8C[2];
    f32 sp94;
    f32 *temp_v0;
    s32 i;
    s32 temp_s0;
    s32 temp_s1;
    s32 temp_v0_2;

    var_v0 = animpath[arg0];
    var_f22 = 1.0f;
    if (var_v0 == NULL) {
        return NULL;
    }
    temp_s3 = *(u8 **)((u8 *)var_v0 + 0x8);
    if (temp_s3 == NULL) {
        return var_v0;
    }
    if (arg2 == 0xFF) {
        if (mainGetGameFlag(0x59) != 0) {
            var_f22 = 5.0f;
        } else {
            var_f22 = 40.0f;
        }
        if (arg1 != 0) {
            f20 = D_overlay_47_02F026B8;
            for (i = 0; i < arg1; i++) {
                temp_s0 = mathRnd(-arg5, arg5);
                temp_s1 = mathRnd(-arg6, arg6);
                temp_v0_2 = mathRnd(-arg8, arg8);
                hoovergemCreate(*(f32 *)(temp_s3 + 0xC), *(f32 *)(temp_s3 + 0x10), *(s32 *)(temp_s3 + 0x14),
                                (s16)(temp_s0 + arg3), temp_s1 + arg4, (f32)(temp_v0_2 + arg7) * f20, var_f22);
            }
        }
    } else {
        switch (arg2) {
        case 0:
            spB0 = 0;
            break;
        case 1:
            spB0 = 1;
            break;
        case 2:
            var_f22 = 0.5f;
            spB0 = 1;
            break;
        case 3:
            var_f22 = 0.75f;
            spB0 = 5;
            break;
        case 4:
            spB0 = 4;
            break;
        default:
            spB0 = 2;
            break;
        }
        temp_v0 = *(f32 **)(temp_s3 + 0x54);
        if (temp_v0 != NULL) {
            spA4 = (s32)(*temp_v0 * 255.0f);
        } else {
            spA4 = 0xFF;
        }
        if (arg1 != 0) {
            f20 = D_overlay_47_02F026D0;
            for (i = 0; i < arg1; i++) {
                sp9C[0] = (s16)(mathRnd(-arg5, arg5) + arg3);
                sp9C[1] = (s16)(mathRnd(-arg6, arg6) + arg4);
                sp94 = (f32)(mathRnd(-arg8, arg8) + arg7) * f20;
                mathOneFloatPY(sp9C, sp8C);
                bloodSpurtAdd(*(f32 *)(temp_s3 + 0xC), *(f32 *)(temp_s3 + 0x10), *(s32 *)(temp_s3 + 0x14), sp8C[0],
                              *(f32 *)&sp8C[1], sp94, spA4, spB0, var_f22);
            }
        }
    }
    return NULL;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o47/overlay_47/animseqReleaseBits.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqInitCaptions(void) {
    u8 *slot;
    s32 i;

    for (i = 0; i < 5; i++) {
        slot = D_overlay_47_02F026E0 + i * 0xC;
        *(s16 *) slot = 0;
        slot[0xB] = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o47/overlay_47/animseqInitCaptions.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqStartCaption(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5, s32 arg6) {
    u8 *slot;
    s32 i;

    for (i = 0; i < 5; i++) {
        slot = D_overlay_47_02F026E0 + i * 0xC;
        if (slot[0xB] == 0 && *(s16 *) slot <= 0) {
            *(s16 *) (slot + 0x2) = arg0;
            *(s16 *) (slot + 0x0) = arg1;
            *(s16 *) (slot + 0x4) = arg2;
            *(s16 *) (slot + 0x6) = arg3;
            slot[0x8] = (s8) arg4;
            slot[0x9] = (s8) arg5;
            slot[0xB] = 0;
            slot[0xA] = (s8) arg6;
            return;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o47/overlay_47/animseqStartCaption.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqUpdateCaptions(s32 arg0) {
    u8 *slot;
    s16 timer;
    u8 alpha;
    s32 a;
    s32 i;

    for (i = 0; i < 5; i++) {
        slot = D_overlay_47_02F026E0 + i * 0xC;
        timer = *(s16 *) slot;
        if (timer > 0 || (s32) slot[0xB] > 0) {
            alpha = slot[0xB];
            if (timer > 0) {
                a = alpha + (arg0 * 8);
                *(s16 *) slot = (s16) (timer - arg0);
                if (a >= 0x100) {
                    slot[0xB] = 0xFF;
                } else {
                    slot[0xB] = (u8) a;
                }
            } else if ((s32) alpha > 0) {
                a = alpha - (arg0 * 8);
                if (a < 0) {
                    slot[0xB] = 0;
                } else {
                    slot[0xB] = (u8) a;
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o47/overlay_47/animseqUpdateCaptions.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animseqPrintCaptions(s32 arg0) {
    u8 *slot;
    s32 i;
    s32 temp_s1;
    s32 temp_s2;
    s32 temp_s3;

    fontUseFont(2);
    fontBackground(0, 0, 0, 0);
    for (i = 0; i < 5; i++) {
        slot = D_overlay_47_02F026E0 + i * 0xC;
        if ((s32)slot[0xB] > 0) {
            temp_s1 = fontStringWidth((char *)*(s32 *)(front_text + (*(u16 *)(slot + 0x2) * 4)), 2, 1) + 0x28;
            temp_s2 = *(u16 *)(slot + 0x4) - (temp_s1 >> 1);
            temp_s3 = *(u16 *)(slot + 0x6) - 0xC;
            fontColour(0, 0, 0, 0xFF, slot[0xB]);
            fxDrawWindow(arg0, 0, temp_s2, temp_s3, temp_s1, 0x18, (s32)slot[0xB] >> 1);
            fontPrintXY(arg0, *(u16 *)(slot + 0x4) + 1, *(u16 *)(slot + 0x6) + 1,
                        *(s32 *)(front_text + (*(u16 *)(slot + 0x2) * 4)), 0xC);
            fontColour(slot[0x8], slot[0x9], slot[0xA], 0xFF, slot[0xB]);
            fontPrintXY(arg0, *(u16 *)(slot + 0x4), *(u16 *)(slot + 0x6),
                        *(s32 *)(front_text + (*(u16 *)(slot + 0x2) * 4)), 0xC);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o47/overlay_47/animseqPrintCaptions.s")
#endif
