#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern u8 D_overlay_87_05701224[];
extern u8 D_overlay_87_05701264[];
extern u8 D_overlay_87_057012A4[];
extern u8 D_overlay_87_05701324[];
extern u8 D_overlay_87_05701364[];
extern u8 D_overlay_87_05701384[];
extern u8 D_overlay_87_05701390[];
extern u8 D_overlay_87_057013F0[];
extern u8 D_overlay_87_05701450[];
extern u8 D_overlay_87_05701470[];
extern f32 D_overlay_87_057014B0;
extern f32 D_overlay_87_057014B4;
extern f32 D_overlay_87_057014B8;
extern f32 D_overlay_87_057014BC;
extern s32 __MODULE00087;
void *func_overlay_87_05700000_1FB0DC0(s32 arg0);
f32 Sinf(s32 angle);
void mathOneFloatPY(void *obj, ...);
void hitInitObjectHit(void *arg0, s16 arg1, s8 arg2, s8 arg3, s16 arg4, s16 arg5, s16 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, u16 arg11);
void amSndPlayXYZ(u16 soundId, f32 x, f32 y, f32 z, u8 arg4, void *soundMask);
void bloodSpurtAdd(f32, f32, f32, f32, f32, f32, s32, s32, f32);
void explosionStart(s32, s16, s16, s16, s32, s32);
void explosionAddBlast(f32, f32, f32, f32, f32, f32, s32, s32);
void squadsAddInterestingEvent(void *, s16, s16, s16, s32, s32, s32);
void *objSetupObject(void *params, s32 arg1);
void objFreeObject(void *obj);
void partUpdateTriggers(void *obj, s32 arg1);
void runlinkSetDestructTimer(s32, s32, s32);
s32 levelGetObjectID(s32);
s32 levelObjectFlagSet(s32, s32);
void levelSetObjectFlag(s32, s32);
s32 trackGetHeights(f32, f32, s32, f32 ***);
s32 trackGetIntersect(void *, f32 *, f32 *, f32, s32, void **);
void trackMakePolylist(s32, f32 *, f32 *, f32 *, s32, s32, s32);
s16 trackGetBlock(f32, f32, f32);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_overlay_87_05700000_1FB0DC0(s32 arg0) {
    switch (arg0) {
    case 0x135:
        return D_overlay_87_05701224;
    case 0x168:
        return D_overlay_87_05701264;
    case 0x171:
        return D_overlay_87_057012A4;
    case 0x1A8:
        return D_overlay_87_05701324;
    case 0x1C3:
        return D_overlay_87_05701390;
    case 0x2DE:
    case 0x2DF:
        return D_overlay_87_057013F0;
    case 0x2CC:
        return D_overlay_87_05701450;
    case 0x58:
        return D_overlay_87_05701470;
    default:
        return D_overlay_87_05701364;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o87/overlay_87/func_overlay_87_05700000_1FB0DC0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_87_057000D4_1FB0E94(Object *arg0, s32 arg1, f32 *arg2, f32 *arg3) {
    f32 r = arg0->segment.trans.scale;
    f32 ox = arg0->segment.trans.x_position;
    f32 oy = arg0->segment.trans.y_position;
    f32 oz = arg0->segment.trans.z_position;
    f32 sr = Sinf(arg0->segment.trans.y_rotation) * r;
    f32 cr = Cosf((s32)arg0->segment.trans.y_rotation) * r;
    f32 *var_a2 = arg2;
    f32 *var_a3 = arg3;
    s32 var_a1 = arg1 - 1;
    s32 var_v0 = arg1;

    if (arg1 != 0) {
        do {
            f32 x = var_a2[0];
            f32 y = var_a2[1];
            f32 z = var_a2[2];

            var_v0 = var_a1;
            var_a3[0] = x * cr + z * sr + ox;
            var_a3[1] = y * r + oy;
            var_a3[2] = z * cr - x * sr + oz;
            var_a2 += 3;
            var_a3 += 3;
        } while (var_a1--);
    }
    return var_v0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o87/overlay_87/func_overlay_87_057000D4_1FB0E94.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void damagecrateInit(Object *arg0, void *arg1, s32 arg2) {
    u8 *st = (u8 *)arg0->racer;
    u8 *setup = (u8 *)arg1;
    u8 *hdr = *(u8 **)((u8 *)arg0 + 0x40);
    f32 var_f0;
    f32 **sp4C;
    s32 temp_v0_2;
    s32 var_a0 = -1;
    s32 var_v1;
    f32 temp_f0;
    f32 temp_f14;
    f32 *temp_v1;
    s16 id;

    var_f0 = (f32)setup[0x0B] * 0.015625f;
    if (var_f0 < D_overlay_87_057014B0) {
        var_f0 = D_overlay_87_057014B0;
    }
    arg0->segment.trans.scale = *(f32 *)hdr * var_f0;
    *(f32 *)(st + 0x10) = *(f32 *)(hdr + 0x54) * var_f0;
    temp_v1 = *(f32 **)((u8 *)arg0 + 0x50);
    if (temp_v1 != NULL) {
        *temp_v1 = 0.0f;
    }
    arg0->segment.trans.y_rotation = (s16)(*(s16 *)(setup + 0x0C) << 8);
    if (arg2 == 0) {
        *(s32 *)(st + 0x18) = levelGetObjectID(1);
    }
    *(s8 *)((u8 *)arg0 + 0x3A) = 0;
    hitInitObjectHit(arg0, -1, 0, 8, 0, 0, 0, 32.0f, 32.0f, -1.0f, 1.0f, 1);
    *(s16 *)st = *(s16 *)((u8 *)func_overlay_87_05700000_1FB0DC0(*(s16 *)setup) + 0x1C);
    st[2] = 0x20;
    st[3] = 0;
    *(f32 *)(st + 0x0C) = arg0->segment.trans.y_position;
    temp_v0_2 = trackGetHeights(arg0->segment.trans.x_position, arg0->segment.trans.z_position, 0x800, &sp4C);

    temp_f14 = *(f32 *)(st + 0x0C);
    if (temp_v0_2 == 0 || (var_a0 = -1, temp_f14 < sp4C[temp_v0_2][-1])) {
        /* asm: heights bail-out path, goto block_18 */
        st[9] = 1;
        st[0x0A] = 0;
    } else {
        for (var_v1 = 0; var_v1 < temp_v0_2; var_v1++) {
            temp_f0 = *sp4C[var_v1];
            if (((temp_f14 - 5.0f) <= temp_f0) && (temp_f0 <= (temp_f14 + 5.0f))) {
                var_a0 = var_v1;
                break;
            }
        }
        if (var_a0 == -1) {
            st[9] = 0;
            st[0x0A] = 2;
        } else {
            st[9] = -0xF;
            *(f32 *)(st + 0x0C) = (*sp4C[var_a0] + 1.0f);
            st[0x0A] = 0;
        }
    }
    *(f32 *)((u8 *)arg0 + 0x20) = 0.0f;
    *(s32 *)(st + 0x14) = 0;
    st[0x0B] = 0;
    *(s32 *)((u8 *)arg0 + 0x88) = 0;
    if (levelObjectFlagSet(*(s32 *)(st + 0x18), temp_v0_2) != 0) {
        id = *(s16 *)setup;
        if (id != 0x2DF) {
            if (id != 0x2CC && id != 0x2DE) {
                u8 *tA = *(u8 **)((u8 *)arg0 + 0x4C);
                *(s8 *)((u8 *)arg0 + 0x3A) = (s8)(hdr[0x1F] - 1);
                *(u16 *)(tA + 0x0A) = (u16)(*(u16 *)(tA + 0x0A) & 0xFFFE);
            }
            if (st[9] & 0xF0) {
                temp_v1 = *(f32 **)((u8 *)arg0 + 0x50);
                if (temp_v1 != NULL) {
                    *temp_v1 = *(f32 *)(st + 0x10);
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o87/overlay_87/damagecrateInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void damagecrateControl(Object *arg0, s32 arg1) {
    u8 *st = (u8 *)arg0->racer;
    u8 *hdr = *(u8 **)((u8 *)arg0 + 0x40);
    u8 *tbl;
    u8 *temp_s0;
    u8 *temp_v1;
    u8 *var_s0;
    u8 rec[0x18];
    f32 pos[3];
    f32 sp78[3];
    f32 cur[3];
    f32 nxt[3];
    f32 sp108;
    f32 sp5C;
    f32 sp60;
    f32 sp64;
    s16 sp54;
    s16 sp56;
    void *spC4 = NULL;
    f32 sp110 = 0.0f;
    f32 sp114 = 0.0f;
    f32 sp10C = 0.0f;
    f32 velStep;
    s32 sp128 = 0;
    s32 sp120 = 0;
    s32 var_s0_2;
    s32 var_s1 = 0;
    s32 var_s2 = 0;
    s32 var_s4 = 0;
    s32 var_s4_2;
    s32 var_t0 = 0;
    s32 var_t1 = -1;
    s32 var_t2 = -1;
    s32 var_t8;
    s32 var_v0;
    s32 n;
    s32 idx;
    s32 next;
    s32 cntBits;
    u8 spE9 = 0; /* asm: hit-result flag byte, not resolved by m2c */
    s16 temp_t6;
    s16 temp_v0_4;
    s8 temp_v0_3;
    u8 temp_v1_2;
    void *temp_v0_9;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    s8 v;
    s8 v2;

    runlinkSetDestructTimer(__MODULE00087, 2, 2);
    if ((*(u16 *)(*(u8 **)((u8 *)arg0 + 0x4C) + 0x0A) & 1) || (*(s32 *)(st + 0x1C) != 0)) {
        tbl = func_overlay_87_05700000_1FB0DC0(*(s16 *)((u8 *)arg0 + 0x4A));
        if (tbl == D_overlay_87_05701364) {
            func_overlay_87_057000D4_1FB0E94(arg0, 1, (f32 *)D_overlay_87_05701384, sp78);
        }
        temp_v1 = *(u8 **)((u8 *)arg0 + 0x5C);
        temp_s0 = tbl + (*(s8 *)((u8 *)arg0 + 0x3A) << 5);
        var_v0 = *(s16 *)(temp_v1 + 0x130);
        var_s1 = 0;
        var_s4 = 0;
        if (var_v0 < *(s16 *)(temp_s0 + 0x1E)) {
            *(s16 *)(temp_v1 + 0x130) = 0;
            var_v0 = *(s16 *)(*(u8 **)((u8 *)arg0 + 0x5C) + 0x130);
        }
        *(s16 *)st = (s16)((*(s16 *)st - var_v0) - *(s32 *)((u8 *)arg0 + 0x88));
        *(s32 *)((u8 *)arg0 + 0x88) = 0;
        *(s32 *)(st + 0x1C) = 0;
        var_s0 = temp_s0 - 0x20;
        var_s2 = 0;
        var_t1 = -1;
        if (*(s16 *)(*(u8 **)((u8 *)arg0 + 0x4C) + 0x06) <= 0) {
            pos[0] = arg0->segment.trans.x_position;
            pos[1] = arg0->segment.trans.y_position;
            pos[2] = arg0->segment.trans.z_position;
            sp114 = 0.0f;
            sp110 = 0.0f;
            sp10C = 0.0f;
            var_t0 = 0;
            var_t2 = -1;
            n = hdr[0x1F];
            idx = *(s8 *)((u8 *)arg0 + 0x3A);
            if (*(s16 *)st <= 0 && idx < n - 1) {
                next = idx + 1;
                do {
                    *(s8 *)((u8 *)arg0 + 0x3A) = (s8)next;
                    temp_t6 = *(s16 *)(var_s0 + 0x3C);
                    var_s0 += 0x20;
                    *(s16 *)st = (s16)(*(s16 *)st + temp_t6);
                    temp_v1_2 = var_s0[1];
                    var_s1 |= var_s0[0];
                    if (var_s4 < (s32)temp_v1_2) {
                        var_s4 = (s32)temp_v1_2;
                        sp128 = (s32)(s8)var_s0[3];
                        *(s16 *)(rec + 0x00) = *(s16 *)(var_s0 + 0x04);
                    }
                    temp_v0_3 = (s8)var_s0[6];
                    var_s2 |= var_s0[2];
                    if (temp_v0_3 != -1) {
                        var_t1 = temp_v0_3;
                        sp120 = (s32)(s8)var_s0[7];
                    }
                    temp_v0_4 = *(s16 *)(var_s0 + 0x0C);
                    var_t0 |= var_s0[8];
                    if ((s8)st[3] < temp_v0_4) {
                        st[3] = (s8)temp_v0_4;
                    }
                    *(s32 *)(st + 4) = (s32)(*(s32 *)(st + 4) | var_s0[0x0E]);
                    temp_f0 = *(f32 *)(var_s0 + 0x10);
                    if (sp114 < temp_f0) {
                        sp114 = temp_f0;
                    }
                    temp_f0_2 = *(f32 *)(var_s0 + 0x14);
                    if (sp110 < temp_f0_2) {
                        sp110 = temp_f0_2;
                    }
                    temp_f0_3 = *(f32 *)(var_s0 + 0x18);
                    if (sp10C < temp_f0_3) {
                        sp10C = temp_f0_3;
                    }
                    if (*(s16 *)st > 0) {
                        break;
                    }
                    if (next >= n - 1) {
                        break;
                    }
                    next += 1;
                } while (1);
            }
            var_t8 = var_s1 & 0x10;
            if (var_t8 != 0) {
                u8 *anim = *(u8 **)((u8 *)arg0 + 0x4C);
                *(u16 *)(anim + 0x0A) = (u16)(*(u16 *)(anim + 0x0A) & 0xFFFE);
                levelSetObjectFlag(*(s32 *)(st + 0x18), -1);
                var_t2 = -1;
            }
            if ((var_s1 & 0x20) && (st[2] == 0x20)) {
                st[2] = 0;
            }
            if (var_s1 & 1) {
                var_t2 = 0x22;
            }
            if (var_s1 & 2) {
                var_t2 = 0x195;
            }
            if (var_t2 != -1) {
                amSndPlayXYZ((u16)(var_t2 & 0xFFFF), arg0->segment.trans.x_position, arg0->segment.trans.y_position,
                             arg0->segment.trans.z_position, 4, 0);
                squadsAddInterestingEvent(0, (s16)arg0->segment.trans.x_position, (s16)arg0->segment.trans.y_position,
                                          (s16)arg0->segment.trans.z_position, 5, 1, 0x22);
            }
            if (var_t1 >= 0) {
                f32 *vp = (f32 *)((u8 *)pos + sp120 * 0xC);
                explosionStart(var_t1, (s16)vp[0], (s16)vp[1], (s16)vp[2], 0x64, 0);
            }
            if (var_t0 != 0) {
                if (st[9] & 0xF0) {
                    f32 *p50 = *(f32 **)((u8 *)arg0 + 0x50);
                    if (p50 != NULL) {
                        *p50 = *(f32 *)(st + 0x10);
                    }
                }
                *(s32 *)((u8 *)arg0 + 0x84) = var_t0;
                partUpdateTriggers(arg0, 2);
            }
            if (var_s4 > 0) {
                var_s0_2 = 0;
                if (sp128 == 0) {
                    rec[0x0E] = 0x3C;
                    rec[0x0F] = 1;
                    *(f32 *)(rec + 0x14) = D_overlay_87_057014B4;
                    *(s16 *)(rec + 0x0A) = (s16)mathRnd(0, 0x10000);
                }
                cntBits = var_s2 & 7;
                if (cntBits != 0) {
                    if (!(var_s2 & 1)) {
                        do {
                            var_s0_2 = (var_s0_2 + 1) & 7;
                        } while (!((1 << var_s0_2) & var_s2));
                    }
                }
                var_s4_2 = var_s4 - 1;
                if (var_s4 != 0) {
                    do {
                        f32 *pv = (f32 *)((u8 *)pos + var_s0_2 * 0xC);
                        if (sp128 == 1) {
                            sp54 = (s16)mathRnd(0, 0x10000);
                            sp56 = (s16)mathRnd(0x1000, 0x3000);
                            sp64 = (f32)mathRnd(0x1C2, 0x258) * D_overlay_87_057014B8;
                            mathOneFloatPY(&sp54, &sp5C, &sp60);
                            bloodSpurtAdd(pv[0], pv[1], pv[2], sp5C, sp60, sp64,
                                          (s32)(**(f32 **)((u8 *)arg0 + 0x54) * 255.0f), 1, 1.0f);
                        } else {
                            *(s16 *)(rec + 0x04) = (s16)pv[0];
                            *(s16 *)(rec + 0x06) = (s16)pv[1];
                            *(s16 *)(rec + 0x08) = (s16)pv[2];
                            *(s16 *)(rec + 0x0C) = (s16)mathRnd(0x2800, 0x3800);
                            *(f32 *)(rec + 0x10) = (f32)mathRnd(0x2EE, 0x384) * D_overlay_87_057014BC;
                            temp_v0_9 = objSetupObject(rec, 1);
                            if (temp_v0_9 != NULL) {
                                *(s32 *)((u8 *)temp_v0_9 + 0x3C) = 0;
                            }
                        }
                        *(s16 *)(rec + 0x0A) = (s16)(*(s16 *)(rec + 0x0A) + mathRnd(0x2000, 0x6000));
                        if (cntBits != 0) {
                            do {
                                var_s0_2 = (var_s0_2 + 1) & 7;
                            } while (!((1 << var_s0_2) & var_s2));
                        }
                        var_s4_2 -= 1;
                    } while (var_s4_2 != 0);
                }
            }
            if (sp114 > 0.0f) {
                explosionAddBlast(arg0->segment.trans.x_position, arg0->segment.trans.y_position,
                                  arg0->segment.trans.z_position, sp110, sp114, sp10C, 0x64, 0);
            }
        }
    }
    v = (s8)st[3];
    if (v != 0) {
        st[3] = (s8)(v - arg1);
        *(s32 *)((u8 *)arg0 + 0x84) = *(s32 *)(st + 4);
        partUpdateTriggers(arg0, arg1);
        if ((s8)st[3] < 0) {
            st[3] = 0;
            *(s32 *)(st + 4) = 0;
        }
    }
    v2 = (s8)st[2];
    if (v2 < 0x20) {
        st[2] = (s8)(v2 + arg1);
        if ((s8)st[2] >= 0x21) {
            st[2] = 0x20;
        }
        arg0->segment.trans.z_rotation = (s16)((s32)(Sinf((s8)st[2] << 0xB) * 2048.0f) & 0xFFF0);
        arg0->segment.trans.y_position = (f32)((Sinf((s8)st[2] << 0xA) * 16.0f) + *(f32 *)(st + 0x0C));
        st[0x0B] = 1;
    } else {
        arg0->segment.trans.y_position = *(f32 *)(st + 0x0C);
        st[0x0B] = 0;
    }
    if (*(Object **)(st + 0x14) != NULL) {
        u8 *ost = *(u8 **)((u8 *)*(Object **)(st + 0x14) + 0x68);
        if ((ost[0x0A] & 3) || (ost[0x0B] != 0)) {
            st[8] = 1;
        } else if (st[0x0A] & 3) {
            st[8] = 1;
        } else {
            st[8] = 0;
        }
    } else {
        st[8] = 1;
    }
    if (((s8)st[9] == 0) && ((s8)st[8] != 0)) {
        velStep = (f32)arg1;
        sp108 = arg0->segment.trans.scale * 20.0f;
        *(f32 *)((u8 *)arg0 + 0x20) = *(f32 *)((u8 *)arg0 + 0x20) - (0.5f * velStep);
        cur[0] = arg0->segment.trans.x_position;
        cur[1] = *(f32 *)(st + 0x0C) + sp108;
        cur[2] = arg0->segment.trans.z_position;
        nxt[0] = arg0->segment.trans.x_position;
        nxt[1] = *(f32 *)(st + 0x0C) + sp108 + (*(f32 *)((u8 *)arg0 + 0x20) * velStep);
        nxt[2] = arg0->segment.trans.z_position;
        trackMakePolylist(1, cur, nxt, &sp108, 0xCE000000, 0, 0);
        if (trackGetIntersect(arg0, cur, nxt, sp108, 0x20, &spC4) != 0) {
            if (spE9 & 2) {
                st[9] = 1;
                st[0x0A] = 0;
                *(f32 *)((u8 *)arg0 + 0x20) = 0.0f;
            } else if (spE9 & 0x10) {
                *(void **)(st + 0x14) = spC4;
                *(f32 *)((u8 *)arg0 + 0x20) = (nxt[1] - cur[1]) / velStep;
            }
        } else {
            *(void **)(st + 0x14) = NULL;
            *(f32 *)((u8 *)arg0 + 0x20) = (nxt[1] - cur[1]) / velStep;
        }
        temp_f0 = *(f32 *)((u8 *)arg0 + 0x20);
        if (temp_f0 > 0.0f) {
            st[0x0A] = 1;
        } else if (temp_f0 < 0.0f) {
            st[0x0A] = 2;
        } else if (temp_f0 == 0.0f) {
            s8 v3 = (s8)st[0x0A];
            if (v3 & 1) {
                st[0x0A] = 2;
            } else if (v3 & 2) {
                st[0x0A] = 0;
            }
        }
        arg0->segment.trans.x_position = nxt[0];
        *(f32 *)(st + 0x0C) = nxt[1] - sp108;
        arg0->segment.trans.z_position = nxt[2];
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o87/overlay_87/damagecrateControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void flyingdebrisInit(Object *arg0, void *arg1) {
    u8 *p = (u8 *)arg1;

    arg0->segment.trans.y_rotation = *(s16 *)(p + 0x0A);
    arg0->segment.trans.x_rotation = *(s16 *)(p + 0x0C);
    *(f32 *)((u8 *)arg0 + 0x24) = -*(f32 *)(p + 0x10);
    mathOneFloatPY(arg0, (u8 *)arg0 + 0x1C);
    *(s32 *)((u8 *)arg0 + 0x84) = p[0x0F];
    *(f32 *)((u8 *)arg0 + 0x88) = *(f32 *)(p + 0x14);
    *(s32 *)((u8 *)arg0 + 0x8C) = (s32)(p[0x0E] * 8);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o87/overlay_87/flyingdebrisInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void flyingdebrisControl(Object *arg0, s32 arg1) {
    s32 temp_t8;
    s32 temp_v1;
    s32 var_v1;
    f32 temp_f0;

    temp_t8 = *(s32 *)((u8 *)arg0 + 0x8C) - (arg1 * 8);
    *(s32 *)((u8 *)arg0 + 0x8C) = temp_t8;
    if (temp_t8 <= 0) {
        objFreeObject(arg0);
        return;
    }
    if (arg1 != 0) {
        f32 vx = *(f32 *)((u8 *)arg0 + 0x1C);
        f32 vz = *(f32 *)((u8 *)arg0 + 0x24);
        f32 vy2 = *(f32 *)((u8 *)arg0 + 0x88);

        var_v1 = arg1 - 1;
        do {
            arg0->segment.trans.x_position = arg0->segment.trans.x_position + vx;
            temp_f0 = *(f32 *)((u8 *)arg0 + 0x20);
            *(f32 *)((u8 *)arg0 + 0x20) = temp_f0 + vy2;
            arg0->segment.trans.y_position = arg0->segment.trans.y_position + temp_f0;
            arg0->segment.trans.z_position = arg0->segment.trans.z_position + vz;
        } while (var_v1--);
    }
    *(s16 *)((u8 *)arg0 + 0x2E) = trackGetBlock(arg0->segment.trans.x_position, arg0->segment.trans.y_position,
                                               arg0->segment.trans.z_position);
    temp_v1 = arg1 << 0x0B;
    arg0->segment.trans.x_rotation = (s16)(arg0->segment.trans.x_rotation + temp_v1);
    arg0->segment.trans.z_rotation = (s16)(arg0->segment.trans.z_rotation + temp_v1);
    partUpdateTriggers(arg0, arg1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o87/overlay_87/flyingdebrisControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void damagecrateChangeHitsmin(s32 arg0, s16 arg1) {
    *(s16 *)((u8 *)func_overlay_87_05700000_1FB0DC0(arg0) + 0x1E) = arg1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o87/overlay_87/damagecrateChangeHitsmin.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void damagecrateRepair(Object *arg0) {
    u8 *st = (u8 *)arg0->racer;

    *(s16 *)st = *(s16 *)((u8 *)func_overlay_87_05700000_1FB0DC0(*(s16 *)((u8 *)arg0 + 0x2C)) + 0x1C);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o87/overlay_87/damagecrateRepair.s")
#endif
