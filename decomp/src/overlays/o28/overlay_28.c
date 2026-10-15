#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern f32 D_overlay_28_01C01BE0;
extern f32 D_overlay_28_01C01BE4;
extern s16 D_overlay_28_01C01BD8[];
void hitInitObjectHit(void *arg0, u8 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, s32 arg11);
void *objSetupObject(s16 *arg0, s32 arg1, void *arg2, void *arg3);
void shrinkbeamControl(void *arg0, s32 arg1);
void amSndPlayXYZ(u16 soundId, f32 x, f32 y, f32 z, u8 arg4, void *soundMask);
void amSndStopXYZ(void *soundMask);
void *camGetListPtr(void);
s32 levelGetNumber(void);
void **objGetObjList(s32 *arg0, s32 *arg1);
extern SoundMask *D_overlay_28_01C01BD4;
extern f32 D_overlay_28_01C01C14;
extern f32 D_overlay_28_01C01BE8;
extern f32 D_overlay_28_01C01BEC;
extern f32 D_overlay_28_01C01BF0;
extern f32 D_overlay_28_01C01BF4;
extern f32 D_overlay_28_01C01BF8;
extern f32 D_overlay_28_01C01BFC;
extern f32 D_overlay_28_01C01C00;
extern f32 D_overlay_28_01C01C04;
extern f32 D_overlay_28_01C01C08;
extern f32 D_overlay_28_01C01C0C;
extern f32 D_overlay_28_01C01C10;
extern f32 widthcoeffs[];
f32 Sinf(s16 angle);
void partUpdateTriggers(void *obj, s32 arg1);
void matrix_SCL_RPY_XYZ(void *obj, f32 (*mtx)[4]);
s32 trackNearestIntersection(void *a, void *from, void *to, void *out, s32 mask, s32 c);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void shrinkbeamInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *src = (u8 *) arg1;
    u8 *d;
    u8 *rec;
    u8 *p;
    void *srcCfg;
    s32 i;
    s32 s0;
    s32 t5;
    s32 a1v;
    s32 a2v;
    s32 a3v;
    s32 t8;
    void *temp_v0;
    s32 temp_a0_2;

    d = *(u8 **) (obj + 0x68);
    srcCfg = *(void **) (src + 0x10);
    if (srcCfg != NULL) {
        *(f32 *) (obj + 0xC) = *(f32 *) ((u8 *) srcCfg + 0xC);
        *(f32 *) (obj + 0x10) = *(f32 *) ((u8 *) srcCfg + 0x10);
        *(f32 *) (obj + 0x14) = *(f32 *) ((u8 *) srcCfg + 0x14);
        *(s16 *) (obj + 0x0) = *(s16 *) ((u8 *) srcCfg + 0x0);
        *(s16 *) (obj + 0x2) = *(s16 *) ((u8 *) srcCfg + 0x2);
        *(s16 *) (obj + 0x4) = *(s16 *) ((u8 *) srcCfg + 0x4);
    }
    *(f32 *) (obj + 0x1C) = 0.0f;
    *(f32 *) (obj + 0x20) = 0.0f;
    *(f32 *) (obj + 0x24) = 0.0f;

    for (i = 0; i < 3; i++) {
        *(s16 *) (d + 0xA64 + i * 2) = *(s16 *) (src + 0x14 + i * 2);
        *(s16 *) (d + 0xA6A + i * 2) = *(s16 *) (src + 0x1A + i * 2);
        *(s16 *) (d + 0xA70 + i * 2) = *(s16 *) (src + 0x20 + i * 2);
        *(s32 *) (d + 0xA38 + (i + 1) * 4) = 0;
    }
    *(s16 *) (d + 0xA78) = 0;
    *(void **) (d + 0xA38) = srcCfg;
    *(u8 *) (d + 0xA7C) = *(u8 *) (src + 0x28);
    *(u8 *) (d + 0xA7E) = 0;
    *(u8 *) (d + 0xA7F) = 0;
    *(f32 *) (d + 0xA58) = D_overlay_28_01C01BE0;
    *(s16 *) (d + 0xA7A) = *(s16 *) (src + 0x26);
    *(u8 *) (d + 0xA81) = 0xFF;
    *(u8 *) (d + 0xA7D) = 0;
    *(f32 *) (d + 0xA60) = D_overlay_28_01C01BE0;
    *(f32 *) (d + 0xA5C) = D_overlay_28_01C01BE4;
    *(u8 *) (d + 0xA82) = *(u8 *) (src + 0x29);
    *(u8 *) (d + 0xA83) = *(u8 *) (src + 0x2A);

    /* 27 iterations, 0x28-byte stride from d + 0x600 */
    p = d + 0x600;
    for (i = 0; i != 0x6C; i += 4) {
        p[0x10] = 0xFF;
        p[0x11] = 0xFF;
        p[0x12] = 0xFF;
        p[0x13] = 0xFF;
        p[0x1A] = 0xFF;
        p[0x1B] = 0xFF;
        p[0x1C] = 0xFF;
        p[0x1D] = 0xFF;
        p[0x24] = 0xFF;
        p[0x25] = 0xFF;
        p[0x26] = 0xFF;
        p[0x27] = 0xFF;
        p += 0x28;
        p[-0x22] = 0xFF;
        p[-0x21] = 0xFF;
        p[-0x20] = 0xFF;
        p[-0x1F] = 0xFF;
    }

    /* 48 records of 0x20 bytes: 3 outer x 2 middle x 8 inner */
    rec = d;
    for (s0 = 0; s0 < 3; s0++) {
        for (t5 = 0; t5 < 2; t5++) {
            a2v = 0;
            a1v = 0;
            a3v = 0x40;
            do {
                t8 = ((a3v / 8) - 1) << 5;
                rec[0x00] = 0x40;
                rec[0x01] = a1v;
                rec[0x02] = a1v + 1;
                rec[0x03] = a1v + 2;
                *(s16 *) (rec + 0x04) = 0x1E0;
                *(s16 *) (rec + 0x06) = a2v;
                *(s16 *) (rec + 0x08) = 0;
                *(s16 *) (rec + 0x0A) = a2v;
                *(s16 *) (rec + 0x0C) = 0x1E0;
                *(s16 *) (rec + 0x0E) = t8;
                rec[0x10] = 0x40;
                rec[0x11] = a1v + 1;
                rec[0x12] = a1v + 3;
                rec[0x13] = a1v + 2;
                *(s16 *) (rec + 0x14) = 0;
                *(s16 *) (rec + 0x16) = a2v;
                *(s16 *) (rec + 0x18) = 0;
                *(s16 *) (rec + 0x1A) = t8;
                *(s16 *) (rec + 0x1C) = 0x1E0;
                *(s16 *) (rec + 0x1E) = t8;
                rec += 0x20;
                a2v = t8;
                a1v += 2;
                a3v += 0x40;
            } while (a3v != 0x240);
        }
    }

    hitInitObjectHit(arg0, *(u8 *) (d + 0xA7C), 1, 4, 0, 0, 0, 20.0f, 20.0f, -1.0f, 1.0f, 0x11);
    temp_v0 = *(void **) (*(u8 **) (obj + 0x78));
    if (temp_v0 != NULL) {
        *(u8 *) ((u8 *) temp_v0 + 0x3B) = 0;
    }
    temp_a0_2 = *(s32 *) (*(u8 **) (obj + 0x74));
    if (temp_a0_2 != 0) {
        changeLightColourCycle(temp_a0_2, D_overlay_28_01C01BD8[*(u8 *) (d + 0xA83)]);
        turnLightOff((UnkLight *) *(s32 *) (*(u8 **) (obj + 0x74)));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o28/overlay_28/shrinkbeamInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void shrinkbeamControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *d;
    u8 *part;
    UnkLight *light;
    u8 *endPt;
    f32 mtx[4][4];
    f32 spC0[18];
    f32 hitOut[4];
    f32 f20;
    f32 f22;
    f32 f2;
    f32 f0;
    f32 f10;
    f32 f14;
    f32 tmpf2;
    f32 sp164;
    f32 sp168;
    f32 sp16C;
    f32 pf0;
    f32 pf1;
    f32 savX;
    f32 savY;
    f32 savZ;
    f32 tmpf12;
    f32 tmpf14;
    f32 tmpf20;
    f32 tmpf22;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 *widthPtr;
    f32 *pairPtr;
    s16 spBC;
    s16 s4;
    s16 s3;
    s32 s7;
    s32 sp7C;
    s32 sp94;
    s32 s6;
    s32 s6tmp;
    s32 hit;
    s32 a2;
    s32 a2_2;
    s32 a2_3;
    s32 a2_4;
    s32 a2_5;
    s32 lo;
    s32 lo2;
    s32 lo3;
    s32 tlo;
    s32 t6;
    s32 t9;
    s32 v1;
    s32 temp_a1;
    s32 temp_a1_2;
    s32 temp_a1_3;
    s32 temp_v1_3;
    s32 temp_t9;
    s32 cnt;
    s16 temp_a0;
    s16 v1s;
    s16 v0s;
    s16 temp_v0_2;
    s16 temp_v0_3;
    s16 temp_v0_4;
    s16 temp_v0_5;
    s16 temp_v0_6;
    s16 temp_v0_7;
    s16 temp_v0_8;
    s16 temp_v0_9;
    s16 temp_v0_10;
    s16 temp_v0_11;
    s16 temp_v1;
    s16 temp_v1_2;
    u8 temp_v0_12;
    u8 temp_v0_13;
    u8 temp_v0_15;
    u8 *temp_v0_14;
    u8 *sub;
    u8 *sp98;
    u8 *sp88;
    u8 *sp8C;
    u8 *s0p;
    u8 *s1p;
    u8 *var_v0_2;
    u8 *partPtr;
    u8 *lightPtr;
    u8 *camP;
    f32 *sFloat;

    d = *(u8 **) (obj + 0x68);
    if (*(u8 *) (d + 0xA7D) != 0) {
        if (*(u8 *) (d + 0xA7E) == 0) {
            part = *(u8 **) (*(u8 **) (obj + 0x78));
            if (part != NULL) {
                *(u8 *) (part + 0x3B) = 0x80;
            }
            *(u8 *) (d + 0xA81) = 0xFF;
        }
        a2 = 0;
        if (arg1 > 0) {
            temp_a1 = arg1 & 3;
            if (temp_a1 != 0) {
                temp_v1 = *(s16 *) (d + 0xA7A);
                a2 = 1;
                if (temp_a1 != 1) {
                    do {
                        temp_v0_2 = *(s16 *) (d + 0xA78);
                        a2 += 1;
                        *(f32 *) (d + 0xA58) = *(f32 *) (d + 0xA58) * D_overlay_28_01C01BE8;
                        *(s16 *) (d + 0xA78) = (s16) (temp_v0_2 + ((s32) (temp_v1 - temp_v0_2) / 4));
                    } while (temp_a1 != a2);
                }
                temp_v0_3 = *(s16 *) (d + 0xA78);
                *(f32 *) (d + 0xA58) = *(f32 *) (d + 0xA58) * D_overlay_28_01C01BE8;
                *(s16 *) (d + 0xA78) = (s16) (temp_v0_3 + ((s32) (temp_v1 - temp_v0_3) / 4));
                if (a2 != arg1) {
                    goto block_11;
                }
            } else {
block_11:
                temp_v1_2 = *(s16 *) (d + 0xA7A);
                a2_2 = a2 + 4;
                f10 = *(f32 *) (d + 0xA58) * D_overlay_28_01C01BEC;
                if (a2_2 != arg1) {
                    do {
                        temp_v0_4 = *(s16 *) (d + 0xA78);
                        *(f32 *) (d + 0xA58) = f10;
                        *(s16 *) (d + 0xA78) = (s16) (temp_v0_4 + ((s32) (temp_v1_2 - temp_v0_4) / 4));
                        temp_v0_5 = *(s16 *) (d + 0xA78);
                        *(f32 *) (d + 0xA58) = *(f32 *) (d + 0xA58) * D_overlay_28_01C01BEC;
                        *(s16 *) (d + 0xA78) = (s16) (temp_v0_5 + ((s32) (temp_v1_2 - temp_v0_5) / 4));
                        temp_v0_6 = *(s16 *) (d + 0xA78);
                        *(f32 *) (d + 0xA58) = *(f32 *) (d + 0xA58) * D_overlay_28_01C01BEC;
                        *(s16 *) (d + 0xA78) = (s16) (temp_v0_6 + ((s32) (temp_v1_2 - temp_v0_6) / 4));
                        temp_v0_7 = *(s16 *) (d + 0xA78);
                        *(f32 *) (d + 0xA58) = *(f32 *) (d + 0xA58) * D_overlay_28_01C01BEC;
                        f10 = *(f32 *) (d + 0xA58) * D_overlay_28_01C01BEC;
                        a2_2 += 4;
                        *(s16 *) (d + 0xA78) = (s16) (temp_v0_7 + ((s32) (temp_v1_2 - temp_v0_7) / 4));
                    } while (a2_2 != arg1);
                }
                temp_v0_8 = *(s16 *) (d + 0xA78);
                *(f32 *) (d + 0xA58) = f10;
                *(s16 *) (d + 0xA78) = (s16) (temp_v0_8 + ((s32) (temp_v1_2 - temp_v0_8) / 4));
                temp_v0_9 = *(s16 *) (d + 0xA78);
                *(f32 *) (d + 0xA58) = *(f32 *) (d + 0xA58) * D_overlay_28_01C01BEC;
                *(s16 *) (d + 0xA78) = (s16) (temp_v0_9 + ((s32) (temp_v1_2 - temp_v0_9) / 4));
                temp_v0_10 = *(s16 *) (d + 0xA78);
                *(f32 *) (d + 0xA58) = *(f32 *) (d + 0xA58) * D_overlay_28_01C01BEC;
                *(s16 *) (d + 0xA78) = (s16) (temp_v0_10 + ((s32) (temp_v1_2 - temp_v0_10) / 4));
                temp_v0_11 = *(s16 *) (d + 0xA78);
                *(f32 *) (d + 0xA58) = *(f32 *) (d + 0xA58) * D_overlay_28_01C01BEC;
                *(s16 *) (d + 0xA78) = (s16) (temp_v0_11 + ((s32) (temp_v1_2 - temp_v0_11) / 4));
            }
        }
        f20 = 3.0f;
        if (*(f32 *) (d + 0xA58) > 3.0f) {
            *(f32 *) (d + 0xA58) = 3.0f;
        }
        *(u8 *) (d + 0xA7E) = 1;
        f22 = D_overlay_28_01C01BF0;
        goto block_41;
    }
    if ((*(u8 *) (d + 0xA82) != 1) && ((*(s16 *) (d + 0xA78) > 0) || (D_overlay_28_01C01BF4 < *(f32 *) (d + 0xA58)))) {
        f22 = D_overlay_28_01C01BF8;
        a2_3 = 0;
        if (arg1 > 0) {
            temp_a1_2 = arg1 & 3;
            if (temp_a1_2 != 0) {
                a2_3 = 1;
                lo = *(s16 *) (d + 0xA78) * 9;
                if (temp_a1_2 != 1) {
                    do {
                        a2_3 += 1;
                        *(f32 *) (d + 0xA58) = *(f32 *) (d + 0xA58) * D_overlay_28_01C01BFC;
                        *(s16 *) (d + 0xA78) = (s16) (lo / 10);
                        lo = *(s16 *) (d + 0xA78) * 9;
                    } while (temp_a1_2 != a2_3);
                }
                *(f32 *) (d + 0xA58) = *(f32 *) (d + 0xA58) * D_overlay_28_01C01BFC;
                *(s16 *) (d + 0xA78) = (s16) (lo / 10);
                if (a2_3 != arg1) {
                    goto block_25;
                }
            } else {
block_25:
                a2_4 = a2_3 + 4;
                lo2 = (s32) (*(s16 *) (d + 0xA78) * 9) / 10;
                t6 = lo2;
                if (a2_4 != arg1) {
                    do {
                        *(s16 *) (d + 0xA78) = (s16) t6;
                        a2_4 += 4;
                        *(f32 *) (d + 0xA58) = *(f32 *) (d + 0xA58) * D_overlay_28_01C01C00;
                        *(f32 *) (d + 0xA58) = *(f32 *) (d + 0xA58) * D_overlay_28_01C01C00;
                        *(f32 *) (d + 0xA58) = *(f32 *) (d + 0xA58) * D_overlay_28_01C01C00;
                        *(f32 *) (d + 0xA58) = *(f32 *) (d + 0xA58) * D_overlay_28_01C01C00;
                        *(s16 *) (d + 0xA78) = (s16) ((s32) (*(s16 *) (d + 0xA78) * 9) / 10);
                        *(s16 *) (d + 0xA78) = (s16) ((s32) (*(s16 *) (d + 0xA78) * 9) / 10);
                        *(s16 *) (d + 0xA78) = (s16) ((s32) (*(s16 *) (d + 0xA78) * 9) / 10);
                        lo2 = (s32) (*(s16 *) (d + 0xA78) * 9) / 10;
                        t6 = lo2;
                    } while (a2_4 != arg1);
                }
                *(s16 *) (d + 0xA78) = (s16) lo2;
                *(f32 *) (d + 0xA58) = *(f32 *) (d + 0xA58) * D_overlay_28_01C01C00;
                *(f32 *) (d + 0xA58) = *(f32 *) (d + 0xA58) * D_overlay_28_01C01C00;
                *(f32 *) (d + 0xA58) = *(f32 *) (d + 0xA58) * D_overlay_28_01C01C00;
                *(f32 *) (d + 0xA58) = *(f32 *) (d + 0xA58) * D_overlay_28_01C01C00;
                *(s16 *) (d + 0xA78) = (s16) ((s32) (*(s16 *) (d + 0xA78) * 9) / 10);
                *(s16 *) (d + 0xA78) = (s16) ((s32) (*(s16 *) (d + 0xA78) * 9) / 10);
                *(s16 *) (d + 0xA78) = (s16) ((s32) (*(s16 *) (d + 0xA78) * 9) / 10);
            }
        }
        if (*(f32 *) (d + 0xA58) < f22) {
            *(f32 *) (d + 0xA58) = f22;
        }
        if ((*(s16 *) (d + 0xA78) < 0xA) && (*(s16 *) (d + 0xA78) = 0, (f22 == *(f32 *) (d + 0xA58)))) {
            *(f32 *) (d + 0xA48) = *(f32 *) (obj + 0xC);
            *(f32 *) (d + 0xA4C) = *(f32 *) (obj + 0x10);
            *(f32 *) (d + 0xA50) = *(f32 *) (obj + 0x14);
        } else {
            f20 = 3.0f;
            *(u8 *) (d + 0xA7E) = 0;
block_41:
            if ((*(u8 *) (d + 0xA7F) == 0) && ((*(s16 *) (d + 0xA7A) - 0xA) < *(s16 *) (d + 0xA78))) {
                if (mathRnd(0, 2) == 0) {
                    *(f32 *) (d + 0xA54) = (f32) (((f32) mathRnd(0, 0x3E8) / 1000.0f) + D_overlay_28_01C01C04);
                    *(s16 *) (d + 0xA76) = mathRnd(0, 0xFFFF);
                    *(u8 *) (d + 0xA7F) = mathRnd(4, 6);
                } else {
                    goto block_46;
                }
            } else {
block_46:
                temp_v0_12 = *(u8 *) (d + 0xA7F);
                *(s16 *) (d + 0xA76) = (s16) (*(s16 *) (d + 0xA76) + (arg1 << 8));
                if ((s32) temp_v0_12 < arg1) {
                    *(u8 *) (d + 0xA7F) = 0;
                } else {
                    *(u8 *) (d + 0xA7F) = (u8) (temp_v0_12 - arg1);
                }
            }
            if (f20 == *(f32 *) (d + 0xA58)) {
                f2 = *(f32 *) (d + 0xA60);
                *(f32 *) (d + 0xA5C) = (f32) (*(f32 *) (d + 0xA5C) + (f2 * (f32) arg1));
                f0 = *(f32 *) (d + 0xA5C);
                if (f0 > 1.5f) {
                    *(f32 *) (d + 0xA5C) = (f32) (f20 - f0);
                    *(f32 *) (d + 0xA60) = (f32) -f2;
                } else if (f0 < D_overlay_28_01C01C08) {
                    *(f32 *) (d + 0xA5C) = (f32) (f22 - f0);
                    *(f32 *) (d + 0xA60) = (f32) -f2;
                }
            } else {
                *(f32 *) (d + 0xA5C) = (f32) (*(f32 *) (d + 0xA5C) * D_overlay_28_01C01C10);
                if (*(f32 *) (d + 0xA5C) < D_overlay_28_01C01C0C) {
                    *(f32 *) (d + 0xA5C) = (f32) D_overlay_28_01C01C0C;
                }
            }
            temp_v0_13 = *(u8 *) (d + 0xA81);
            if ((s32) temp_v0_13 >= 0x65) {
                *(u8 *) (d + 0xA81) = (u8) (temp_v0_13 - (arg1 * 2));
            }
            temp_v0_14 = *(u8 **) (*(u8 **) (obj + 0x78));
            if (temp_v0_14 != NULL) {
                temp_v0_15 = *(u8 *) (temp_v0_14 + 0x3B);
                if (temp_v0_15 != 0) {
                    if ((s32) temp_v0_15 >= 0x65) {
                        *(s32 *) (obj + 0x84) = 2;
                        partUpdateTriggers(obj, 8);
                    }
                    v1 = 0;
                    if (arg1 > 0) {
                        temp_a1_3 = arg1 & 3;
                        if (temp_a1_3 != 0) {
                            do {
                                v1 += 1;
                                *(u8 *) (temp_v0_14 + 0x3B) = (u8) ((s32) (*(u8 *) (temp_v0_14 + 0x3B) * 9) / 10);
                            } while (temp_a1_3 != v1);
                            if (v1 != arg1) {
                                goto loop_68;
                            }
                        } else {
                            do {
loop_68:
                                v1 += 4;
                                lo = (s32) (*(u8 *) (temp_v0_14 + 0x3B) * 9) / 10;
                                *(u8 *) (temp_v0_14 + 0x3B) = (u8) lo;
                                lo2 = (s32) ((lo & 0xFF) * 9) / 10;
                                *(u8 *) (temp_v0_14 + 0x3B) = (u8) lo2;
                                lo3 = (s32) ((lo2 & 0xFF) * 9) / 10;
                                *(u8 *) (temp_v0_14 + 0x3B) = (u8) lo3;
                                *(u8 *) (temp_v0_14 + 0x3B) = (u8) ((s32) ((lo3 & 0xFF) * 9) / 10);
                            } while (v1 != arg1);
                        }
                    }
                    if ((s32) *(u8 *) (temp_v0_14 + 0x3B) < 0xA) {
                        *(u8 *) (temp_v0_14 + 0x3B) = 0;
                    }
                }
            }
            v0s = *(s16 *) (d + 0xA78);
            if (v0s != 0) {
                light = *(UnkLight **) (*(u8 **) (obj + 0x74));
                if (light != NULL) {
                    turnLightOn(light);
                    v0s = *(s16 *) (d + 0xA78);
                    light = *(UnkLight **) (*(u8 **) (obj + 0x74));
                }
                if (light != NULL) {
                    changeLightIntensity(light, (u8) ((s32) (v0s * 0xFF) / (s16) *(s16 *) (d + 0xA7A)) & 0xFF);
                    *(f32 *) ((u8 *) light + 0x10) = (f32) ((s32) -(*(s16 *) (d + 0xA78) * 3) / 4);
                }
                a2_5 = 0;
                temp_v1_3 = arg1 << 5;
                var_v0_2 = d;
                do {
                    temp_a0 = *(s16 *) (var_v0_2 + 0x16);
                    *(s16 *) (var_v0_2 + 0x6) = (s16) (*(s16 *) (var_v0_2 + 0x6) - temp_v1_3);
                    *(s16 *) (var_v0_2 + 0xA) = (s16) (*(s16 *) (var_v0_2 + 0xA) - temp_v1_3);
                    *(s16 *) (var_v0_2 + 0xE) = (s16) (*(s16 *) (var_v0_2 + 0xE) - temp_v1_3);
                    var_v0_2 += 0x10;
                    if (temp_a0 < -0x800) {
                        *(s16 *) (var_v0_2 + 0x6) = (s16) (temp_a0 + 0x1000);
                        *(s16 *) (var_v0_2 + 0xA) = (s16) (*(s16 *) (var_v0_2 + 0xA) + 0x1000);
                        *(s16 *) (var_v0_2 + 0xE) = (s16) (*(s16 *) (var_v0_2 + 0xE) + 0x1000);
                    }
                    a2_5 += 1;
                } while (a2_5 != 0x60);
                matrix_SCL_RPY_XYZ(obj, mtx);
                endPt = d + 0xA48;
                mathMtxXFMF(mtx, 0.0f, 0.0f, (f32) -*(s16 *) (d + 0xA78), (f32 *) endPt, (f32 *) (d + 0xA4C), (f32 *) (d + 0xA50));
                hit = trackNearestIntersection(obj, obj + 0xC, endPt, hitOut, 0, 0);
                if (hit != 0) {
                    *(f32 *) (d + 0xA48) = hitOut[1];
                    *(f32 *) (d + 0xA4C) = hitOut[2];
                    *(f32 *) (d + 0xA50) = hitOut[3];
                    dx = *(f32 *) (d + 0xA48) - *(f32 *) (obj + 0xC);
                    dy = *(f32 *) (d + 0xA4C) - *(f32 *) (obj + 0x10);
                    dz = *(f32 *) (d + 0xA50) - *(f32 *) (obj + 0x14);
                    f2 = sqrtf((dx * dx) + (dy * dy) + (dz * dz));
                } else {
                    f2 = (f32) *(s16 *) (d + 0xA78);
                }
                if (*(u8 *) (d + 0xA82) == 0) {
                    spBC = 0xE00;
                } else {
                    spBC = 0x1000;
                }
                s6 = 0;
                sp88 = d + 0x6B4;
                sp8C = d + 0x600;
                sp94 = 0;
                sp98 = d;
                sp7C = (s16) (s32) (-f2 / 8.0f);
                do {
                    s4 = *(s16 *) (sp98 + 0xA64);
                    s0p = sp8C;
                    s1p = sp88;
                    s7 = 0;
                    s3 = 0;
                    widthPtr = widthcoeffs;
                    pairPtr = spC0;
                    *(s16 *) (sp98 + 0xA64) = (s16) (s4 + (arg1 * *(s16 *) (sp98 + 0xA6A)));
                    tmpf22 = (f32) *(s16 *) (d + 0xA78) / (f32) *(s16 *) (d + 0xA7A);
loop_88:
                    tmpf20 = Sinf((s16) s7) * 20.0f * tmpf22;
                    s7 = (s16) (s7 + spBC);
                    sp164 = Sinf((s16) s4) * tmpf20;
                    tmpf2 = Cosf((s32) s4) * tmpf20;
                    sp16C = 0.0f;
                    sp168 = tmpf2;
                    if (sp94 == 0) {
                        s6tmp = s6 + 1;
                        spC0[s6] = sp164;
                        spC0[s6tmp] = tmpf2;
                        s6 = s6tmp + 1;
                        sp164 = 0.0f;
                        sp168 = 0.0f;
                    }
                    tmpf14 = *widthPtr * tmpf22;
                    pf0 = pairPtr[0];
                    pf1 = pairPtr[1];
                    widthPtr += 1;
                    tmpf12 = 18.0f * tmpf14;
                    pairPtr += 2;
                    s0p += 0x14;
                    s1p += 0x14;
                    *(s16 *) (s0p - 0x14) = (s16) (s32) ((sp164 - tmpf12) + pf0);
                    *(s16 *) (s0p - 0x10) = s3;
                    *(s16 *) (s0p - 0x12) = (s16) (s32) (sp168 + pf1);
                    *(s16 *) (s0p - 0xA) = (s16) (s32) (sp164 + tmpf12 + pf0);
                    *(s16 *) (s0p - 0x6) = s3;
                    *(s16 *) (s0p - 0x8) = (s16) (s32) (sp168 + pf1);
                    *(s16 *) (s1p - 0x14) = (s16) (s32) (sp164 + pf0);
                    *(s16 *) (s1p - 0x10) = s3;
                    *(s16 *) (s1p - 0x12) = (s16) (s32) ((sp168 - tmpf12) + pf1);
                    *(s16 *) (s1p - 0xA) = (s16) (s32) (sp164 + pf0);
                    *(s16 *) (s1p - 0x6) = s3;
                    *(s16 *) (s1p - 0x8) = (s16) (s32) (sp168 + tmpf12 + pf1);
                    s3 += sp7C;
                    s4 += *(s16 *) (sp98 + 0xA70);
                    if (widthPtr != widthcoeffs + 9) {
                        goto loop_88;
                    }
                    temp_t9 = sp94 + 0x168;
                    sp88 += 0x168;
                    sp8C += 0x168;
                    sp94 = temp_t9;
                    sp98 += 2;
                } while (temp_t9 != 0x438);
                if (hit != 0) {
                    savX = *(f32 *) (obj + 0xC);
                    savY = *(f32 *) (obj + 0x10);
                    savZ = *(f32 *) (obj + 0x14);
                    *(f32 *) (obj + 0xC) = *(f32 *) (d + 0xA48);
                    *(f32 *) (obj + 0x10) = *(f32 *) (d + 0xA4C);
                    *(s32 *) (obj + 0x84) = 3;
                    *(f32 *) (obj + 0x14) = *(f32 *) (d + 0xA50);
                    partUpdateTriggers(obj, arg1);
                    *(f32 *) (obj + 0xC) = savX;
                    *(f32 *) (obj + 0x10) = savY;
                    *(f32 *) (obj + 0x14) = savZ;
                }
                partPtr = *(u8 **) (obj + 0x4C);
                if (partPtr != NULL) {
                    *(s16 *) (partPtr + 0x6) = (s16) (*(u8 *) (d + 0xA7C) * arg1);
                }
            }
        }
    } else {
        *(u8 *) (d + 0xA7E) = 0;
        lightPtr = *(u8 **) (obj + 0x74);
        light = *(UnkLight **) (lightPtr);
        if (light != NULL) {
            turnLightOff(light);
        }
        part = *(u8 **) (*(u8 **) (obj + 0x78));
        if (part != NULL) {
            *(u8 *) (part + 0x3B) = 0;
        }
        *(f32 *) (d + 0xA48) = *(f32 *) (obj + 0xC);
        *(f32 *) (d + 0xA4C) = *(f32 *) (obj + 0x10);
        *(f32 *) (d + 0xA50) = *(f32 *) (obj + 0x14);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o28/overlay_28/shrinkbeamControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
typedef struct TrackBeamSetup {
    /* 0x00 */ s16 type;
    /* 0x02 */ u8 unk02;
    /* 0x03 */ u8 pad03;
    /* 0x04 */ s16 unk04;
    /* 0x06 */ s16 unk06;
    /* 0x08 */ s16 unk08;
    /* 0x0A */ u8 pad0A[6];
    /* 0x10 */ void *unk10;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ s16 unk18;
    /* 0x1A */ s16 unk1A;
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ s16 unk20;
    /* 0x22 */ s16 unk22;
    /* 0x24 */ s16 unk24;
    /* 0x26 */ s16 unk26;
    /* 0x28 */ u8 unk28;
    /* 0x29 */ s8 unk29;
    /* 0x2A */ s8 unk2A;
} TrackBeamSetup;

void trackbeamInit(void *arg0, void *arg1) {
    TrackBeamSetup setup;
    u8 *src = (u8 *) arg1;
    void **slot;
    void *obj;

    setup.type = 0xB6;
    setup.unk02 = 0x2C;
    setup.unk04 = *(s16 *) (src + 0x4);
    setup.unk06 = *(s16 *) (src + 0x6);
    setup.unk08 = *(s16 *) (src + 0x8);
    setup.unk2A = (*(s16 *) (src + 0x0) == 0x1BD) ? 1 : 0;
    if (*(u8 *) (src + 0x2) == 0xA) {
        setup.unk28 = 1;
        setup.unk26 = 0xFA;
        setup.unk10 = arg0;
    } else {
        setup.unk28 = *(u8 *) (src + 0x10);
        setup.unk26 = *(s16 *) (src + 0xE);
        setup.unk10 = *(void **) (src + 0x14);
    }
    setup.unk14 = 0;
    setup.unk16 = 0x4000;
    setup.unk18 = 0;
    setup.unk1A = 0x800;
    setup.unk1C = -0x1200;
    setup.unk1E = 0x800;
    setup.unk20 = 0x2000;
    setup.unk22 = 0x2000;
    setup.unk24 = -0x2000;
    setup.unk29 = 1;

    slot = (void **) *(void **) ((u8 *) arg0 + 0x68);
    obj = objSetupObject((s16 *) &setup, 1, arg1, arg0);
    *slot = obj;
    *(s32 *) ((u8 *) obj + 0x3C) = 0;
    *(s16 *) ((u8 *) arg0 + 0x0) = *(s16 *) (src + 0xA);
    *(s16 *) ((u8 *) arg0 + 0x2) = *(s16 *) (src + 0xC);
    *(s16 *) ((u8 *) *slot + 0x0) = *(s16 *) (src + 0xA);
    *(s16 *) ((u8 *) *slot + 0x2) = *(s16 *) (src + 0xC);
    *(s32 *) ((u8 *) arg0 + 0x8C) = setup.unk26;
    shrinkbeamControl(*slot, 2);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o28/overlay_28/trackbeamInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void trackbeamControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *) arg0;
    void **slot;
    u8 *child;
    u8 *sub;

    slot = *(void ***) (obj + 0x68);
    child = (u8 *) *slot;
    sub = *(u8 **) (child + 0x68);
    if (*(s16 *) (obj + 0x6) & 0x400) {
        *(s16 *) (sub + 0xA78) = 0;
        *(u8 *) (sub + 0xA7D) = 0;
    } else {
        *(s16 *) (sub + 0xA78) = (s16) *(s32 *) (obj + 0x8C);
        *(s16 *) (sub + 0xA7A) = (s16) *(s32 *) (obj + 0x8C);
        *(u8 *) (sub + 0xA7D) = 1;
    }
    *(f32 *) (child + 0xC) = *(f32 *) (obj + 0xC);
    *(f32 *) (child + 0x10) = *(f32 *) (obj + 0x10);
    *(f32 *) (child + 0x14) = *(f32 *) (obj + 0x14);
    *(s16 *) (child + 0x0) = *(s16 *) (obj + 0x0);
    *(s16 *) (child + 0x2) = *(s16 *) (obj + 0x2);
    *(s16 *) (child + 0x4) = *(s16 *) (obj + 0x4);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o28/overlay_28/trackbeamControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void shrinkbeamSoundUpdate(void) {
    s32 start;
    s32 end;
    s32 camCount;
    s32 camIdx;
    s32 i;
    void *camList;
    void **list;
    u8 *best;
    u8 *cam;
    u8 *obj;
    f32 bestDist;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 d2;

    best = NULL;
    bestDist = D_overlay_28_01C01C14;
    if (levelGetNumber() != 0xD4) {
        camCount = mainGetNumberOfCameras();
        camList = camGetListPtr();
        list = objGetObjList(&start, &end);
        for (camIdx = 0; camIdx < camCount; camIdx++) {
            cam = (u8 *) camList + camIdx * 0x4C;
            for (i = start; i < end; i++) {
                obj = (u8 *) list[i];
                if (*(s16 *) (obj + 0x48) == 0x98 && *(s16 *) (*(u8 **) (obj + 0x68) + 0xA78) > 0) {
                    dx = *(f32 *) (cam + 0xC) - *(f32 *) (obj + 0xC);
                    dy = *(f32 *) (cam + 0x10) - *(f32 *) (obj + 0x10);
                    dz = *(f32 *) (cam + 0x14) - *(f32 *) (obj + 0x14);
                    d2 = (dx * dx) + (dy * dy) + (dz * dz);
                    if (d2 < bestDist) {
                        best = obj;
                        bestDist = d2;
                    }
                }
            }
        }
        if (best != NULL) {
            if (D_overlay_28_01C01BD4 == NULL) {
                amSndPlayXYZ(0x9B, *(f32 *) (best + 0xC), *(f32 *) (best + 0x10), *(f32 *) (best + 0x14), 1, &D_overlay_28_01C01BD4);
            } else {
                amSndSetXYZ(D_overlay_28_01C01BD4, *(f32 *) (best + 0xC), *(f32 *) (best + 0x10), *(f32 *) (best + 0x14));
            }
        } else if (D_overlay_28_01C01BD4 != NULL) {
            amSndStopXYZ(D_overlay_28_01C01BD4);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o28/overlay_28/shrinkbeamSoundUpdate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void _AutoExit00028(void) {
    if (D_overlay_28_01C01BD4 != NULL) {
        amSndStopXYZ(D_overlay_28_01C01BD4);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o28/overlay_28/_AutoExit00028.s")
#endif
