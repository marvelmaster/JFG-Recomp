#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#define RD_U8(p, off)  (*(u8 *)((u8 *)(p) + (off)))
#define RD_S8(p, off)  (*(s8 *)((u8 *)(p) + (off)))
#define RD_S16(p, off) (*(s16 *)((u8 *)(p) + (off)))
#define RD_S32(p, off) (*(s32 *)((u8 *)(p) + (off)))
#define RD_F32(p, off) (*(f32 *)((u8 *)(p) + (off)))
#define RD_PTR(p, off) (*(u8 **)((u8 *)(p) + (off)))
#define WR_PTR(p, off, v) (*(void **)((u8 *)(p) + (off)) = (v))

extern f32 D_overlay_91_05B00F30;
extern f32 D_overlay_91_05B00F34;
extern f32 D_overlay_91_05B00F38;
extern f32 D_overlay_91_05B00F3C;
extern f32 D_overlay_91_05B00F40;
extern f32 D_overlay_91_05B00F44;
extern f32 D_overlay_91_05B00F48;
extern f32 D_overlay_91_05B00F4C;
extern f32 D_overlay_91_05B00F50;
extern f32 D_overlay_91_05B00F54;
extern f32 D_overlay_91_05B00F58;
extern f32 D_overlay_91_05B00F5C;
extern f32 D_overlay_91_05B00F60;
extern s32 __MODULE00091;

void **objGetObjList(s32 *arg0, s32 *arg1);
s32 trackPolyHeight(f32, f32, f32 *, s32);
f32 Powerf(f32 base, s32 n);
f32 Sinf(s16 angle);
s16 dAngle(s16 a, s16 b, f32 c);
s32 mainGetNumberOfPlayers(void);
void objFreeObject(void *obj);
void objMoveXYZ(void *obj, f32 x, f32 y, f32 z);
s32 objAnimDframe(void *obj, f32 a, f32 b);
void mathOneFloatPY(void *obj, f32 *out);
void runlinkSetDestructTimer(s32, s32, s32);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_91_05B00000_1FB3558(void *arg0, void *arg1) {
    s32 start;
    s32 total;
    void **list;
    f32 var_f22;
    f32 var_f20;
    f32 var_f18;

    if (RD_U8(arg1, 0x3E) != 0) {
        return;
    }

    var_f22 = D_overlay_91_05B00F30;
    var_f20 = var_f22;
    var_f18 = var_f22;
    /* asm: objGetObjList is passed the arg1/arg0 pointers in a2/a3 */
    list = ((void **(*)(s32 *, s32 *, void *, void *))objGetObjList)(&start, &total, arg1, arg0);
    var_f18 = D_overlay_91_05B00F30;
    while (start < total) {
        u8 *obj = (u8 *)list[start];
        s16 bn;

        start += 1;
        bn = RD_S16(obj, 0x48);
        if ((bn == 1 && RD_PTR(arg1, 0x08) == NULL) ||
            (bn == 0x4D && RD_PTR(arg1, 0x0C) == NULL) ||
            ((bn == 0x9B || bn == 0xA6) && RD_PTR(arg1, 0x10) == NULL)) {
            f32 dx = RD_F32(obj, 0x0C) - RD_F32(arg0, 0x0C);
            f32 dy = RD_F32(obj, 0x10) - RD_F32(arg0, 0x10);
            f32 dz = RD_F32(obj, 0x14) - RD_F32(arg0, 0x14);
            f32 d2;

            if (bn == 1) {
                d2 = dx * dx + dy * dy + dz * dz;
                if (d2 < 14400.0f && d2 < var_f22) {
                    *(void **)((u8 *)arg1 + 0x08) = obj;
                    var_f22 = d2;
                }
            }
            if (bn == 0x4D && RD_S32(obj, 0x88) > 0 && RD_U8(RD_PTR(obj, 0x68), 0x0E) != 0) {
                d2 = dx * dx + dy * dy + dz * dz;
                if (d2 < D_overlay_91_05B00F34 && d2 < var_f20) {
                    *(void **)((u8 *)arg1 + 0x0C) = obj;
                    var_f20 = d2;
                }
            }
            if (bn == 0x9B || bn == 0xA6) {
                d2 = dx * dx + dy * dy + dz * dz;
                if (d2 < D_overlay_91_05B00F34) {
                    if (d2 < var_f18) {
                        *(void **)((u8 *)arg1 + 0x10) = obj;
                        RD_S16(arg1, 0x4A) = 0x258;
                        var_f18 = d2;
                    }
                }
            }
        }
    }

    if (RD_PTR(arg1, 0x08) != NULL) {
        *(void **)((u8 *)arg1 + 0x0C) = NULL;
        *(void **)((u8 *)arg1 + 0x10) = NULL;
        RD_S16(arg1, 0x00) = 0;
        {
            u8 *near = RD_PTR(arg1, 0x08);

            if (RD_F32(near, 0x0C) < RD_F32(arg1, 0x14)) {
                RD_S16(arg1, 0x00) = (s16)(RD_S16(arg1, 0x00) | 1);
            }
            if (RD_F32(near, 0x10) < RD_F32(arg1, 0x18)) {
                RD_S16(arg1, 0x00) = (s16)(RD_S16(arg1, 0x00) | 2);
            }
            if (RD_F32(near, 0x14) < RD_F32(arg1, 0x1C)) {
                RD_S16(arg1, 0x00) = (s16)(RD_S16(arg1, 0x00) | 4);
            }
        }
    }
    if (RD_PTR(arg1, 0x0C) != NULL) {
        *(void **)((u8 *)arg1 + 0x10) = NULL;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o91/overlay_91/func_overlay_91_05B00000_1FB3558.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fishInit(void *arg0, void *arg1) {
    u8 *state = RD_PTR(arg0, 0x68);
    u8 *base = *(u8 **)RD_PTR(arg0, 0x6C);
    s32 maxAbs = 0;
    s32 n;

    RD_F32(arg0, 0x08) = (f32)RD_U8(arg1, 0x0E) * D_overlay_91_05B00F38;
    RD_S16(state, 0x00) = mathRnd(0, 7);
    RD_S16(state, 0x02) = (s16)(RD_U8(arg1, 0x13) << 8);

    /* asm: six s16 entries at base+0x8C (the loop runs 6 times, m2c shows 5) */
    for (n = 0; n < 6; n++) {
        s16 v = RD_S16(base, 0x8C + n * 2);

        if (v < 0) {
            v = (s16)(-v);
        }
        if (maxAbs < v) {
            maxAbs = v;
        }
    }

    RD_S32(state, 0x08) = 0;
    RD_S32(state, 0x0C) = 0;
    RD_S32(state, 0x10) = 0;
    RD_F32(state, 0x04) = RD_F32(arg0, 0x08) * (f32)maxAbs;
    RD_F32(state, 0x14) = (f32)RD_S16(arg1, 0x04);
    RD_F32(state, 0x18) = (f32)RD_S16(arg1, 0x06);
    RD_F32(state, 0x1C) = (f32)RD_S16(arg1, 0x08);
    RD_F32(state, 0x20) = (f32)RD_U8(arg1, 0x0B);
    RD_F32(state, 0x24) = (f32)RD_U8(arg1, 0x0C);
    RD_F32(state, 0x28) = (f32)RD_U8(arg1, 0x0D);
    RD_F32(state, 0x2C) = 0.0f;
    RD_S16(state, 0x30) = 0;
    RD_S16(state, 0x32) = mathRnd(0, 0x10000);
    RD_S16(state, 0x38) = (s16)(RD_U8(arg1, 0x10) << 4);
    RD_S16(state, 0x34) = mathRnd(0, 0x10000);
    RD_S16(state, 0x3A) = (s16)(RD_U8(arg1, 0x11) << 4);
    RD_S16(state, 0x36) = mathRnd(0, 0x10000);
    RD_S16(state, 0x3C) = (s16)(RD_U8(arg1, 0x12) << 4);
    RD_S8(state, 0x3E) = (s8)(RD_U8(arg1, 0x03) & 1);

    if ((trackPolyHeight(RD_F32(arg0, 0x0C), RD_F32(arg0, 0x14), (f32 *)(state + 0x40), 0x2000) & 0x2000) &&
        (RD_F32(arg0, 0x10) < RD_F32(state, 0x40))) {
        RD_S8(state, 0x3F) = 1;
    } else {
        RD_S8(state, 0x3F) = 1;
        RD_F32(state, 0x40) = RD_F32(arg0, 0x10);
    }

    RD_S16(state, 0x44) = (s16)(RD_U8(arg1, 0x14) << 8);
    RD_S16(state, 0x48) = 0;
    RD_S16(state, 0x46) = (s16)(RD_U8(arg1, 0x15) * 0x3C);
    RD_S16(state, 0x4A) = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o91/overlay_91/fishInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Field layouts follow fishInit and func_overlay_91_05B00000_1FB3558 above.
// Object (arg0): +0x00/+0x02/+0x04 s16 angles, +0x08 f32 scale, +0x0C/+0x10/+0x14 f32 pos,
// +0x1C/+0x20/+0x24 f32 velocity, +0x68 state ptr. State (st): see fishInit.
void fishControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *st;
    u8 *near;
    u8 *fish;
    u8 *tgt;
    f32 scale;
    f32 tgtX;
    f32 tgtY;
    f32 tgtZ;
    f32 blend;
    f32 dy;
    f32 ref;
    f32 dirX;
    f32 dirZ;
    f32 dist;
    f32 cur;
    f32 powBase;
    u16 yawTgt;
    u16 pitchTgt;
    s16 yawErr;
    s16 pitchErr;
    s16 maxStep;
    s32 shift;
    s32 absYaw;
    s32 absPitch;
    s32 q;
    s16 mv;
    s32 i;

    runlinkSetDestructTimer(__MODULE00091, 2, 2);
    if (mainGetNumberOfPlayers() >= 2) {
        objFreeObject(arg0);
        return;
    }

    st = RD_PTR(obj, 0x68);
    scale = (f32)arg1;

    if (RD_S8(st, 0x3F) != 0) {
        if (RD_S16(st, 0x02) == 0 && RD_S8(st, 0x3E) == 0) {
            /* idle / settled: ease the body back towards rest */
            f32 pw = Powerf(D_overlay_91_05B00F3C, arg1);

            RD_F32(obj, 0x1C) = RD_F32(obj, 0x1C) * pw;
            RD_F32(obj, 0x24) = RD_F32(obj, 0x24) * pw;
            blend = 1.0f - pw;
            RD_S16(st, 0x48) = (s16)(RD_S16(st, 0x48) + (arg1 << 8));
            RD_S16(obj, 0x04) = dAngle((s16)((s32)(Sinf(RD_S16(st, 0x48)) * 2048.0f) + 0x4000),
                                       RD_S16(obj, 0x04), blend);
            RD_S16(obj, 0x02) = dAngle(0, RD_S16(obj, 0x02), blend);
            RD_F32(st, 0x2C) = RD_F32(st, 0x2C) * Powerf(D_overlay_91_05B00F40, arg1);
            if (RD_S8(st, 0x3F) != 0) {
                f32 target = (RD_F32(st, 0x40) - RD_F32(obj, 0x10)) * D_overlay_91_05B00F44;

                if (target > 1.0f) {
                    target = 1.0f;
                }
                blend = target;
                cur = RD_F32(obj, 0x20);
                RD_F32(obj, 0x20) = cur + ((blend - cur) * (1.0f - Powerf(D_overlay_91_05B00F48, arg1)));
            }
        } else {
            near = RD_PTR(st, 0x08);
            if (near != NULL) {
                f32 nx = RD_F32(near, 0x0C) - RD_F32(obj, 0x0C);
                f32 ny = RD_F32(near, 0x10) - RD_F32(obj, 0x10);
                f32 nz = RD_F32(near, 0x14) - RD_F32(obj, 0x14);
                f32 sx20;
                f32 sx24;
                f32 sx28;
                f32 sweepZ;

                ref = RD_F32(obj, 0x10);
                if (D_overlay_91_05B00F4C < ((nx * nx) + (ny * ny) + (nz * nz))) {
                    WR_PTR(st, 0x08, NULL);
                    near = NULL;
                }

                sx20 = RD_F32(st, 0x20);
                sx24 = RD_F32(st, 0x24);
                sx28 = RD_F32(st, 0x28);
                tgtX = RD_F32(st, 0x14) - sx20;
                sweepZ = RD_F32(st, 0x18) - sx24;
                tgtZ = RD_F32(st, 0x1C) - sx28;
                if (RD_S16(st, 0x00) & 1) {
                    tgtX += 2.0f * sx20;
                }
                if (RD_S16(st, 0x00) & 2) {
                    sweepZ += 2.0f * sx24;
                }
                if (RD_S16(st, 0x00) & 4) {
                    tgtZ += 2.0f * sx28;
                }
                if (near != NULL) {
                    f32 ex = tgtX - RD_F32(obj, 0x0C);
                    f32 ey = sweepZ - ref;
                    f32 ez = tgtZ - RD_F32(obj, 0x14);

                    if (((ex * ex) + (ey * ey) + (ez * ez)) < 400.0f) {
                        RD_S16(st, 0x00) = (s16)mathRnd(0, 7);
                        ref = RD_F32(obj, 0x10);
                    }
                }
                blend = 3.5f - (RD_F32(obj, 0x08) * D_overlay_91_05B00F50);
                dy = sweepZ - ref;
            } else {
                fish = RD_PTR(st, 0x0C);
                if (fish != NULL) {
                    func_overlay_91_05B00000_1FB3558(arg0, st);
                    if (RD_S16(st, 0x48) > 0) {
                        RD_S16(st, 0x48) = (s16)(RD_S16(st, 0x48) - arg1);
                    } else {
                        f32 fx = RD_F32(fish, 0x0C) - RD_F32(obj, 0x0C);
                        f32 fy = RD_F32(fish, 0x10) - RD_F32(obj, 0x10);
                        f32 fz = RD_F32(fish, 0x14) - RD_F32(obj, 0x14);

                        if (((fx * fx) + (fy * fy) + (fz * fz)) < 400.0f) {
                            RD_S32(fish, 0x88) = RD_S32(fish, 0x88) - RD_S16(st, 0x44);
                            RD_S16(st, 0x48) = RD_S16(st, 0x46);
                            if (RD_S32(fish, 0x88) <= 0) {
                                WR_PTR(st, 0x0C, NULL);
                            } else if (RD_S32(fish, 0x8C) == 0) {
                                RD_F32(fish, 0x24) = -1.5f;
                                mathOneFloatPY(obj, (f32 *)(fish + 0x1C));
                            }
                        }
                    }
                    tgtX = RD_F32(fish, 0x0C);
                    tgtZ = RD_F32(fish, 0x14);
                    blend = 1.75f - (RD_F32(obj, 0x08) * D_overlay_91_05B00F54);
                    dy = RD_F32(fish, 0x10) - RD_F32(obj, 0x10);
                } else {
                    tgt = RD_PTR(st, 0x10);
                    if (tgt != NULL) {
                        func_overlay_91_05B00000_1FB3558(arg0, st);
                        RD_S16(st, 0x4A) = (s16)(RD_S16(st, 0x4A) - arg1);
                        if (RD_S16(st, 0x4A) < 0) {
                            WR_PTR(st, 0x10, NULL);
                        }
                        tgtX = RD_F32(tgt, 0x0C);
                        tgtZ = RD_F32(tgt, 0x14);
                        blend = 1.0f - (RD_F32(obj, 0x08) * D_overlay_91_05B00F58);
                        dy = RD_F32(tgt, 0x10) - RD_F32(obj, 0x10);
                    } else {
                        /* no target: idle bobbing around the home point */
                        func_overlay_91_05B00000_1FB3558(arg0, st);
                        tgtX = (Sinf(RD_S16(st, 0x32)) * RD_F32(st, 0x20)) + RD_F32(st, 0x14);
                        tgtY = (Sinf(RD_S16(st, 0x34)) * RD_F32(st, 0x24)) + RD_F32(st, 0x18);
                        tgtZ = (Sinf(RD_S16(st, 0x36)) * RD_F32(st, 0x28)) + RD_F32(st, 0x1C);
                        blend = 1.25f - (RD_F32(obj, 0x08) * D_overlay_91_05B00F5C);
                        dy = tgtY - RD_F32(obj, 0x10);
                    }
                }
            }

            /* steer towards the chosen point */
            dirX = RD_F32(obj, 0x0C) - tgtX;
            dirZ = RD_F32(obj, 0x14) - tgtZ;
            dist = sqrtf((dirX * dirX) + (dirZ * dirZ));
            yawTgt = Arctanf(dirX, dirZ);
            yawErr = (s16)(yawTgt - RD_S16(obj, 0x00));
            pitchTgt = Arctanf(dy, dist);
            pitchErr = (s16)(pitchTgt - RD_S16(obj, 0x02));

            if (RD_PTR(st, 0x08) != NULL) {
                powBase = 0.875f;
                maxStep = (s16)(arg1 * 0x5B0);
                shift = 2;
            } else {
                powBase = D_overlay_91_05B00F60;
                maxStep = (s16)(arg1 * 0x16C);
                shift = 4;
            }

            /* yaw: step towards target, clamped to maxStep */
            q = (s32)(yawErr * arg1) >> shift;
            mv = (s16)q;
            if ((s16)q == 0) {
                mv = yawErr;
            }
            if (mv < -maxStep) {
                RD_S16(obj, 0x00) = (s16)(RD_S16(obj, 0x00) - maxStep);
            } else if (maxStep < mv) {
                RD_S16(obj, 0x00) = (s16)(RD_S16(obj, 0x00) + maxStep);
            } else {
                RD_S16(obj, 0x00) = (s16)(RD_S16(obj, 0x00) + mv);
            }

            /* pitch: same step, applied to +0x02 */
            q = (s32)(pitchErr * arg1) >> shift;
            mv = (s16)q;
            if ((s16)q == 0) {
                mv = pitchErr;
            }
            if (mv < -maxStep) {
                RD_S16(obj, 0x02) = (s16)(RD_S16(obj, 0x02) - maxStep);
            } else if (maxStep < mv) {
                RD_S16(obj, 0x02) = (s16)(RD_S16(obj, 0x02) + maxStep);
            } else {
                RD_S16(obj, 0x02) = (s16)(RD_S16(obj, 0x02) + mv);
            }

            absYaw = (s16)yawTgt - RD_S16(obj, 0x00);
            if (absYaw < 0) {
                absYaw = -absYaw;
            }
            absPitch = (s16)pitchTgt - RD_S16(obj, 0x02);
            if (absPitch < 0) {
                absPitch = -absPitch;
            }
            if ((absYaw >= 0x401) || (absPitch >= 0x401)) {
                blend = 0.75f;
            }

            cur = RD_F32(st, 0x2C);
            /* asm passes extra regs (a1..a3) to Powerf; only base and n are used */
            RD_F32(st, 0x2C) = cur + ((blend - cur) * (1.0f - Powerf(powBase, absYaw)));

            /* phase advance for the three idle sine channels */
            for (i = 0; i < 3; i++) {
                RD_S16(st, 0x32 + (i * 2)) =
                    (s16)(RD_S16(st, 0x32 + (i * 2)) + (RD_S16(st, 0x38 + (i * 2)) * arg1));
            }

            RD_F32(obj, 0x24) = -RD_F32(st, 0x2C);
            mathOneFloatPY(obj, (f32 *)(obj + 0x1C));
        }
        objMoveXYZ(obj, RD_F32(obj, 0x1C) * scale, RD_F32(obj, 0x20) * scale, RD_F32(obj, 0x24) * scale);
        objAnimDframe(obj, RD_F32(st, 0x2C) * 0.03125f, scale);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o91/overlay_91/fishControl.s")
#endif
