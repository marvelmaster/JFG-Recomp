#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
s32 func_overlay_32_02001D2C_1F526FC(void *);
void func_overlay_32_02001D84_1F52754(void *);
s32 func_overlay_32_02001DD8_1F527A8(void *);
extern s16 D_overlay_32_02002F24;
extern s32 D_overlay_32_020031CC;
extern f32 D_overlay_32_020031D0;
extern f32 D_overlay_32_020031D4;
s32 mainGetPlayerCharacter(s32);
void *mainGetGameCharacter(s32, s32);
s32 mainGetGameFlag(s32);
s32 mainAnyoneHas(s32);
s32 mainPlayerHas();
void hitInitObjectHit(void *, s16, s8, s8, s16, s16, s16, f32, f32, f32, f32, u16);
void objAnimSetMove(void *, s16, s32, void *);
void modGenAnimMatrices(void *, void *, void *, s32, f32);
f32 Sinf(s16);
void objAnimDframe(void *, f32, f32);
void objFreeObject(void *);
void objMoveXYZ(void *, f32, f32, f32);
void partUpdateTriggers(void *, s32);
void mathOneFloatPY(s16 *, void *, void *);
void amSndPlayXYZ(u16, f32, f32, f32, u8, void *);
void amSndStopXYZ(void *);
f32 Powerf(f32, s32);
void *objGetPlayerNo(s32);
void mainPauseDisable(s32);
void amSndPlay(u16, void *);
void amTunePlay(u8);
void setupClearScreen(void *);
void objAnimTextures(void *, void *, void *, s8);
void lightObject(void *, void *, s32, s32);
void hinttextStart(u8, s8);
void hinttextStop(void);
void hinttextStopMagic(void);
void hinttextStartLevel(void);
s32 hinttextActive(void);
s32 hinttextActiveMagic(void);
s32 hinttextTriedToEnd(void);
void hinttextLoadObject(f32, f32, f32, f32, f32);
s16 func_overlay_32_02002068_1F52A38(s16, s16, s16);
void func_overlay_32_020025F0_1F52FC0(void *, void *, void *);
extern f32 D_overlay_32_02003224;
extern f32 D_overlay_32_02003228;
extern f32 D_overlay_32_0200322C;
extern u8 D_overlay_32_020031C4;
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mrhintsInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *setup = (u8 *)arg1;
    u8 *st = *(u8 **)(obj + 0x68);
    u8 *var_v1;
    void **sp44;
    void *sp40;
    f32 temp_f0;
    f32 var_f4;
    f32 var_f8;
    s16 temp_a0;
    s16 temp_v0;
    u8 temp_v0_2;
    u8 *temp_v1;
    u8 *temp_v1_2;

    *(s16 *)(st + 0x2) = *(s16 *)obj;
    *(f32 *)(st + 0x4) = (f32)*(s16 *)(setup + 0x4);
    *(f32 *)(st + 0x8) = (f32)*(s16 *)(setup + 0x6);
    *(f32 *)(st + 0xC) = (f32)*(s16 *)(setup + 0x8);
    *(f32 *)(st + 0x10) = (f32)*(s16 *)(setup + 0xA);
    temp_f0 = *(f32 *)(st + 0x10);
    *(f32 *)(st + 0x14) = temp_f0 * temp_f0 * D_overlay_32_020031D0;
    var_f4 = (f32)setup[0xD];
    *(f32 *)(st + 0x18) = var_f4;
    *(f32 *)(st + 0x1C) = (f32)(*(s16 *)(setup + 0x12) * 2);
    *(u8 *)(st + 0x30) = 0;
    *(f32 *)(st + 0x24) = 0.0f;
    *(f32 *)(st + 0x20) = (f32)(setup[0x13] * 2);
    *(u8 *)(st + 0x31) = setup[0xE];
    *(s16 *)obj = *(s16 *)(setup + 0x10);
    var_f8 = (f32)setup[0xC];
    *(f32 *)(obj + 0x8) = (f32)*(s32 *)*(u8 **)(obj + 0x40) * var_f8 * D_overlay_32_020031D4;
    temp_a0 = *(s16 *)setup;
    var_v1 = (u8 *)&D_overlay_32_02002F24;
    if ((temp_a0 != D_overlay_32_02002F24) && (D_overlay_32_02002F24 >= 0)) {
        do {
            temp_v0 = *(s16 *)(var_v1 + 0x38);
            var_v1 += 0x38;
        } while ((temp_a0 != temp_v0) && (temp_v0 >= 0));
    }
    *(s16 *)obj = (s16)(*(s16 *)obj + *(s16 *)(var_v1 + 0x2));
    if (*(s16 *)(setup + 0xA) != 0) {
        *(u8 *)st = 0;
    } else {
        *(u8 *)st = 2;
    }
    temp_v0_2 = *(u8 *)st;
    temp_v1 = *(u8 **)(var_v1 + 0x4) + temp_v0_2 * 0xC;
    *(f32 *)(st + 0x28) = (f32)*(s32 *)(temp_v1 + 0x8);
    *(u8 *)(st + 0x34) = 0;
    *(u8 *)(st + 0x35) = 0;
    *(u8 *)(st + 0x36) = 0;
    *(u8 *)(st + 0x37) = 0;
    *(u8 *)(st + 0x33) = temp_v0_2;
    *(u8 *)(st + 0x32) = setup[0xF];
    objAnimSetMove(obj, *(s16 *)(temp_v1 + 0x2), 0, setup);
    temp_v1_2 = *(u8 **)(obj + 0x40);
    hitInitObjectHit(obj, 0x100, *(s8 *)(temp_v1_2 + 0xBA), 1, *(s16 *)(temp_v1_2 + 0xB4), *(s16 *)(temp_v1_2 + 0xB6), *(s16 *)(temp_v1_2 + 0xB8), *(f32 *)(temp_v1_2 + 0xBC), *(f32 *)(temp_v1_2 + 0xC0), -1.0f, 1.0f, 0x11);
    sp44 = *(void ***)(obj + 0x6C);
    sp40 = *sp44;
    *(u8 *)(st + 0x1) = (u8)func_overlay_32_02001D2C_1F526FC(st);
    *(s32 *)(obj + 0x8C) = func_overlay_32_02001DD8_1F527A8(st);
    if (*(s16 *)((u8 *)sp40 + 0x4E) > 0) {
        modGenAnimMatrices(sp44, sp40, obj, 0x3F800000, 0.0f);
        *(s16 *)((u8 *)sp44 + 0xA) = 0;
    }
    D_overlay_32_020031CC = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o32/overlay_32/mrhintsInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// asm: some float args are passed as raw GPR bits in the original and some $a3/$a2 values
// are stale on certain paths. Floats are written as f32 values; the stale $a3 of
// objAnimSetMove is modelled by a3val (0 before the state dispatch, the state after it).
void mrhintsControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *st;
    u8 *row;
    u8 *anims;
    u8 *player;
    u8 *pst;
    u8 *sp50;
    u8 *sp54;
    u8 *ent;
    f32 fArg1;
    f32 dx;
    f32 dz;
    f32 dy;
    f32 f2;
    f32 fTmp;
    f32 sp64;
    f32 sp68;
    f32 sp74;
    s16 ang;
    s16 sp5A;
    s16 sp5C;
    s16 sp5E;
    s32 sp38;
    s32 a3val;
    s32 rnd;
    s32 v;
    s32 st0;

    fArg1 = (f32)arg1;
    st = *(u8 **)(obj + 0x68);
    player = NULL;
    sp5A = 0;
    a3val = 0;

    if (*(s32 *)(obj + 0x8C) == 0) {
        objFreeObject(obj);
        return;
    }

    /* row of hint table D_overlay_32_02002F24 (stride 0x38), matched by id at obj+0x4A */
    row = (u8 *)&D_overlay_32_02002F24;
    if (*(s16 *)(obj + 0x4A) != *(s16 *)row && *(s16 *)row >= 0) {
        do {
            row += 0x38;
        } while (*(s16 *)(obj + 0x4A) != *(s16 *)row && *(s16 *)row >= 0);
    }
    anims = *(u8 **)(row + 0x4);
    *(s16 *)obj = (s16)(*(s16 *)obj - *(s16 *)(row + 0x2));
    *(s32 *)(obj + 0x84) = 0;

    if (*(s16 *)(*(u8 **)(obj + 0x4C) + 0x6) < 0x100) {
        /* first visit: choose the start state from the object def */
        if (st[0] == 0 || st[0] == 1 || st[0] == 2 || st[0] == 0xA || st[0] == 0xB || st[0] == 0xC || st[0] == 0xF) {
            u8 mode;
            st[0x34] = 1;
            mode = *(*(u8 **)(row + 0xC) + *(*(u8 **)(obj + 0x4C) + 0x31));
            switch ((s8)mode) {
            case 0:
                if (*(u32 *)(*(u8 **)(obj + 0x4C) + 0x8) & 0x20000000) {
                    st[0] = 0x11;
                } else {
                    st[0] = 0x10;
                }
                break;
            case 1:
                if (*(u32 *)(*(u8 **)(obj + 0x4C) + 0x8) & 0x20000000) {
                    st[0] = 0x10;
                } else {
                    st[0] = 0x11;
                }
                break;
            default:
                if (mathRnd(1, 0xA) >= 6) {
                    st[0] = 0x10;
                } else {
                    st[0] = 0x11;
                }
                break;
            }
            ent = anims + st[0] * 12;
            *(f32 *)(st + 0x28) = *(f32 *)(ent + 0x8);
            objAnimSetMove(obj, *(s16 *)(ent + 0x2), 0, (void *)(s32)a3val); /* asm: $a3 not set here */
        }
        *(s16 *)(*(u8 **)(obj + 0x4C) + 0x6) = 0x100;
    }

    /* notice the player while idle/wandering */
    if (st[0x35] < 2 && st[0x36] == 0 && (st[0] == 0 || st[0] == 1 || st[0] == 0xB || st[0] == 0xC)) {
        player = objGetPlayerNo(0);
        if (player != NULL && *(u8 **)(player + 0x4C) != NULL && *(s16 *)(*(u8 **)(player + 0x4C) + 0x6) >= 0x100) {
            pst = *(u8 **)(player + 0x68);
            dx = *(f32 *)(obj + 0xC) - *(f32 *)(player + 0xC);
            dy = *(f32 *)(player + 0x10) - *(f32 *)(obj + 0x10);
            dz = *(f32 *)(obj + 0x14) - *(f32 *)(player + 0x14);
            ang = (s16)(Arctanf(dx, dz) - *(s16 *)player - 0x8000);
            if ((dx * dx + dz * dz) < (*(f32 *)(st + 0x18) * *(f32 *)(st + 0x18)) &&
                *(f32 *)(st + 0x20) < dy && dy < *(f32 *)(st + 0x1C) &&
                ang >= -0x2AA9 && ang < 0x2AAA &&
                ((func_overlay_32_02001D2C_1F526FC(st) != 0 && st[0x34] == 0) ||
                 ((joyGetPressed(0) & 0x8000) && pst[0x568] != 0xB))) {
                st[0] = 3;
                *(f32 *)(st + 0x28) = *(f32 *)(anims + 0x2C);
                objAnimSetMove(obj, *(s16 *)(anims + 0x26), *(s32 *)(obj + 0x28), (void *)(s32)a3val);
                pst[0x1F9] = 1;
                if (*(s16 *)(pst + 0x5C8) < 0xA) {
                    *(s16 *)(pst + 0x5C8) = 0xA;
                }
                mainPauseDisable(0xA);
                func_overlay_32_02001D84_1F52754(st);
                if (*(f32 *)(st + 0x10) != 0.0f) {
                    st[0x35] = (u8)(st[0x35] + 1);
                }
            } else {
                player = NULL;
            }
        }
    }

    /* state dispatch (asm jump table, states 0..0x12) */
    a3val = st[0];
    if ((u32)a3val < 0x13) {
        switch (a3val) {
        case 0:
            /* idle: countdown, then chase, wander or stop */
            v = (s8)st[0x30];
            dx = *(f32 *)(st + 0x4) - *(f32 *)(obj + 0xC);
            dz = *(f32 *)(st + 0xC) - *(f32 *)(obj + 0x14);
            if (v < 0x1F) {
                if (v > 0) {
                    st[0x30] = (u8)(v - arg1);
                }
            } else {
                st[0x30] = 0x1E;
            }
            if (*(u8 *)(obj + 0x93) != 0) {
                st[0] = 0xF;
                st[0x33] = 0;
                *(f32 *)(st + 0x28) = *(f32 *)(anims + 0xBC);
                objAnimSetMove(obj, *(s16 *)(anims + 0xB6), 0, (void *)(s32)a3val);
            } else if (st[0x36] != 0) {
                if ((dx * dx + dz * dz) < 144.0f || !(arg1 < (s32)st[0x37])) {
                    st[0x36] = 0;
                    st[0x37] = 0;
                    st[0x30] = 0x3C;
                } else {
                    st[0x37] = (u8)(st[0x37] - arg1);
                }
            } else if (st[0x35] >= 2) {
                st[0x36] = 1;
                st[0x35] = 0;
                st[0x37] = 0xF0;
                func_overlay_32_020025F0_1F52FC0(obj, st, anims);
            } else if (*(f32 *)(st + 0x14) < (dx * dx + dz * dz) && (s8)st[0x30] <= 0) {
                st[0] = 1;
                st[0x33] = 0;
                sp38 = Arctanf(dx, dz);
                *(s16 *)(st + 0x2) = (s16)(mathRnd(-0x720, 0x720) + sp38);
                *(f32 *)(st + 0x28) = *(f32 *)(anims + 0x14);
                objAnimSetMove(obj, *(s16 *)(anims + 0xE), *(s32 *)(obj + 0x28), (void *)(s32)a3val);
            } else {
                player = objGetPlayerNo(0);
                if (player != NULL) {
                    dx = *(f32 *)(obj + 0xC) - *(f32 *)(player + 0xC);
                    dz = *(f32 *)(obj + 0x14) - *(f32 *)(player + 0x14);
                    if (st[0x34] == 0) {
                        fTmp = dx * dx + dz * dz;
                        if (D_overlay_32_02003224 < fTmp && fTmp < D_overlay_32_02003228) {
                            rnd = mathRnd(0, 0x3E8);
                            if ((s16)rnd >= 0x3E3) {
                                st[0] = 1;
                                sp5E = (s16)rnd;
                                *(s16 *)(st + 0x2) = (s16)Arctanf(-dx, -dz);
                                *(f32 *)(st + 0x28) = *(f32 *)(anims + 0x14);
                                objAnimSetMove(obj, *(s16 *)(anims + 0xE), *(s32 *)(obj + 0x28), (void *)(s32)a3val);
                                if (sp5E == 0x3E8 && *(s16 *)(anims + 0xD8) != 0) {
                                    st[0x33] = 0x12;
                                } else if (sp5E < 0x3E7) {
                                    if (func_overlay_32_02001D2C_1F526FC(st) != 0) {
                                        st[0x33] = 0xB;
                                    } else {
                                        st[0x33] = 0xC;
                                    }
                                } else {
                                    st[0x33] = 0xC;
                                }
                            }
                        }
                    }
                    player = NULL;
                }
            }
            objAnimDframe(obj, *(f32 *)(anims + 0x4) * *(f32 *)(st + 0x24), fArg1);
            break;

        case 1:
            /* turn towards the stored heading, then pick the next state */
            *(s16 *)obj = (s16)func_overlay_32_02002068_1F52A38(*(s16 *)obj, *(s16 *)(st + 0x2), (s16)arg1);
            v = (s16)(*(s16 *)(st + 0x2) - *(s16 *)obj);
            if (v >= -0x3FF && v < 0x400) {
                st[0] = st[0x33];
                a3val = st[0x33];
                if (a3val == 0xA || a3val == 0xB || a3val == 0xC || a3val == 0x12) {
                    f2 = 0.0f;
                } else {
                    st[0] = 0;
                    st[0x30] = 0x1E;
                    a3val = 0;
                    f2 = *(f32 *)(obj + 0x28);
                }
                ent = anims + a3val * 12;
                *(f32 *)(st + 0x28) = *(f32 *)(ent + 0x8);
                objAnimSetMove(obj, *(s16 *)(ent + 0x2), *(s32 *)&f2, (void *)(s32)a3val);
            }
            objAnimDframe(obj, *(f32 *)(anims + 0x10) * *(f32 *)(st + 0x24), fArg1);
            break;

        case 2:
            objAnimDframe(obj, *(f32 *)(anims + 0x1C), fArg1);
            player = objGetPlayerNo(0);
            if (player != NULL && *(u8 **)(player + 0x4C) != NULL && *(s16 *)(*(u8 **)(player + 0x4C) + 0x6) >= 0x100) {
                pst = *(u8 **)(player + 0x68);
                if (((joyGetPressed(0) & 0x8000) && pst[0x568] != 0xB) ||
                    (func_overlay_32_02001D2C_1F526FC(st) != 0 && st[0x34] == 0)) {
                    dx = *(f32 *)(obj + 0xC) - *(f32 *)(player + 0xC);
                    dy = *(f32 *)(player + 0x10) - *(f32 *)(obj + 0x10);
                    dz = *(f32 *)(obj + 0x14) - *(f32 *)(player + 0x14);
                    fTmp = *(f32 *)(st + 0x18);
                    if ((dx * dx + dz * dz) < (fTmp * fTmp) && *(f32 *)(st + 0x20) < dy && dy < *(f32 *)(st + 0x1C)) {
                        if (*(s16 *)(obj + 0x4A) == 0x264) {
                            ang = (s16)(Arctanf(-dx, -dz) - *(s16 *)player);
                            if (ang >= -0x1554 && ang < 0x1555) {
                                st[0] = 5;
                                pst[0x1F9] = 1;
                            }
                        } else {
                            v = (s16)(*(s16 *)player - *(s16 *)obj);
                            if (v >= -0x1554 && v < 0x1555) {
                                ang = (s16)(Arctanf(dx, dz) - *(s16 *)obj);
                                if (ang < -0x6AAA || ang >= 0x6AAB) {
                                    st[0] = (st[0x34] != 0) ? 7 : 6;
                                    pst[0x1F9] = 1;
                                }
                            }
                        }
                        if (pst[0x1F9] != 0) {
                            if (*(s16 *)(pst + 0x5C8) < 0xA) {
                                *(s16 *)(pst + 0x5C8) = 0xA;
                            }
                            ent = anims + st[0] * 12;
                            *(f32 *)(st + 0x28) = *(f32 *)(ent + 0x8);
                            objAnimSetMove(obj, *(s16 *)(ent + 0x2), 0, (void *)(s32)st[0]);
                            mainPauseDisable(0xA);
                            func_overlay_32_02001D84_1F52754(st);
                        }
                    }
                }
            }
            break;

        case 3:
            mainPauseDisable(0xA);
            player = objGetPlayerNo(0);
            if (player != NULL) {
                dx = (*(f32 *)(player + 0xC) - (Sinf(*(s16 *)player) * 80.0f)) - *(f32 *)(obj + 0xC);
                ang = Arctanf(dx, (*(f32 *)(player + 0x14) - (Cosf(*(s16 *)player) * 80.0f)) - *(f32 *)(obj + 0x14));
                sp5C = ang;
                *(s16 *)obj = (s16)func_overlay_32_02002068_1F52A38(*(s16 *)obj, ang, (s16)arg1);
                v = (s16)(sp5C - *(s16 *)obj);
                if (v >= -0xFF && v < 0x100) {
                    st[0] = 4;
                    st[0x30] = 0x78;
                    *(f32 *)(st + 0x28) = *(f32 *)(anims + 0x38);
                    objAnimSetMove(obj, *(s16 *)(anims + 0x32), *(s32 *)(obj + 0x28), (void *)(s32)st[0]);
                }
                objAnimDframe(obj, *(f32 *)(anims + 0x28) * *(f32 *)(st + 0x24), *(f32 *)(obj + 0x28));
            }
            break;

        case 4:
            mainPauseDisable(0xA);
            player = objGetPlayerNo(0);
            if (player != NULL) {
                dx = (*(f32 *)(player + 0xC) - (Sinf(*(s16 *)player) * 80.0f)) - *(f32 *)(obj + 0xC);
                dz = (*(f32 *)(player + 0x14) - (Cosf(*(s16 *)player) * 80.0f)) - *(f32 *)(obj + 0x14);
                if (((dx * dx) + (dz * dz)) < 64.0f) {
                    st[0] = 5;
                    *(f32 *)(st + 0x28) = *(f32 *)(anims + 0x44);
                    objAnimSetMove(obj, *(s16 *)(anims + 0x3E), *(s32 *)(obj + 0x28), (void *)(s32)st[0]);
                } else {
                    v = (s8)st[0x30];
                    if (arg1 < v) {
                        st[0x30] = (u8)(v - arg1);
                    } else {
                        st[0] = 3;
                        *(f32 *)(st + 0x28) = *(f32 *)(anims + 0x2C);
                        objAnimSetMove(obj, *(s16 *)(anims + 0x26), *(s32 *)(obj + 0x28), (void *)(s32)st[0]);
                    }
                }
                objAnimDframe(obj, *(f32 *)(anims + 0x34) * *(f32 *)(st + 0x24), fArg1);
            }
            break;

        case 5:
            mainPauseDisable(0xA);
            player = objGetPlayerNo(0);
            if (player != NULL) {
                ang = Arctanf(*(f32 *)(player + 0xC) - *(f32 *)(obj + 0xC), *(f32 *)(player + 0x14) - *(f32 *)(obj + 0x14));
                sp5C = ang;
                *(s16 *)obj = (s16)func_overlay_32_02002068_1F52A38(*(s16 *)obj, ang, (s16)arg1);
                v = (s16)(sp5C - *(s16 *)obj);
                if (v >= -0xFF && v < 0x100) {
                    st[0] = (st[0x34] != 0) ? 7 : 6;
                    ent = anims + st[0] * 12;
                    *(f32 *)(st + 0x28) = *(f32 *)(ent + 0x8);
                    objAnimSetMove(obj, *(s16 *)(ent + 0x2), 0, (void *)(s32)st[0]);
                }
                objAnimDframe(obj, *(f32 *)(anims + 0x40) * *(f32 *)(st + 0x24), fArg1);
            }
            break;

        case 6:
            mainPauseDisable(0xA);
            player = objGetPlayerNo(0);
            if (*(f32 *)(obj + 0x28) == 1.0f) {
                st[0] = 8;
                *(f32 *)(st + 0x28) = *(f32 *)(anims + 0x68);
                objAnimSetMove(obj, *(s16 *)(anims + 0x62), 0, (void *)(s32)st[0]);
                D_overlay_32_020031CC = (s32)obj;
                hinttextStart(st[0x31], (s8)st[1]);
            }
            objAnimDframe(obj, *(f32 *)(anims + 0x4C), fArg1);
            break;

        case 7:
            mainPauseDisable(0xA);
            player = objGetPlayerNo(0);
            if (*(f32 *)(obj + 0x28) == 1.0f) {
                st[0] = 9;
                *(f32 *)(st + 0x28) = *(f32 *)(anims + 0x74);
                objAnimSetMove(obj, *(s16 *)(anims + 0x6E), 0, (void *)(s32)st[0]);
                D_overlay_32_020031CC = (s32)obj;
                if (*(s16 *)(obj + 0x4A) != 0x304) {
                    hinttextStart(0x2B, (s8)st[1]);
                } else {
                    hinttextStart(0x2C, (s8)st[1]);
                }
            }
            objAnimDframe(obj, *(f32 *)(anims + 0x58), fArg1);
            break;

        case 8:
            mainPauseDisable(0xA);
            player = objGetPlayerNo(0);
            if (*(void **)(st + 0x2C) != NULL) {
                if ((s8)obj[0x3B] != *(s16 *)(anims + 0x62)) {
                    objAnimSetMove(obj, *(s16 *)(anims + 0x62), *(s32 *)(obj + 0x28), (void *)(s32)st[0]);
                }
                objAnimDframe(obj, *(f32 *)(anims + 0x64), fArg1);
            } else {
                if ((s8)obj[0x3B] != *(s16 *)(anims + 0x1A)) {
                    objAnimSetMove(obj, *(s16 *)(anims + 0x1A), *(s32 *)(obj + 0x28), (void *)(s32)st[0]);
                }
                objAnimDframe(obj, *(f32 *)(anims + 0x1C), fArg1);
            }
            if (hinttextActive() == 0) {
                sp5A = 1;
                D_overlay_32_020031CC = 0;
            } else if (hinttextActiveMagic() == 1) {
                st[0] = 0xD;
                *(f32 *)(st + 0x28) = *(f32 *)(anims + 0xA4);
                objAnimSetMove(obj, *(s16 *)(anims + 0x9E), 0, (void *)(s32)st[0]);
                D_overlay_32_020031CC = 0;
            } else if (hinttextActiveMagic() != 0) {
                st[0] = 0xE;
                *(f32 *)(st + 0x28) = *(f32 *)(anims + 0xB0);
                objAnimSetMove(obj, *(s16 *)(anims + 0xAA), 0, (void *)(s32)st[0]);
                amTunePlay(0x46);
                D_overlay_32_020031CC = 0;
            }
            break;

        case 9:
            mainPauseDisable(0xA);
            player = objGetPlayerNo(0);
            if (*(void **)(st + 0x2C) != NULL) {
                if ((s8)obj[0x3B] != *(s16 *)(anims + 0x6E)) {
                    objAnimSetMove(obj, *(s16 *)(anims + 0x6E), *(s32 *)(obj + 0x28), (void *)(s32)st[0]);
                }
                objAnimDframe(obj, *(f32 *)(anims + 0x70), fArg1);
            } else {
                if ((s8)obj[0x3B] != *(s16 *)(anims + 0xE6)) {
                    objAnimSetMove(obj, *(s16 *)(anims + 0xE6), *(s32 *)(obj + 0x28), (void *)(s32)st[0]);
                }
                objAnimDframe(obj, *(f32 *)(anims + 0xE8), fArg1);
            }
            if (hinttextActive() == 0) {
                sp5A = 1;
                D_overlay_32_020031CC = 0;
            }
            break;

        case 10:
            if (*(f32 *)(obj + 0x28) == 1.0f) {
                if (*(f32 *)(st + 0x10) == 0.0f) {
                    st[0] = 2;
                } else if (st[0x36] != 0) {
                    func_overlay_32_020025F0_1F52FC0(obj, st, anims);
                } else {
                    st[0] = 0;
                    st[0x30] = 0xF;
                }
                ent = anims + st[0] * 12;
                *(f32 *)(st + 0x28) = *(f32 *)(ent + 0x8);
                objAnimSetMove(obj, *(s16 *)(ent + 0x2), *(s32 *)(obj + 0x28), (void *)(s32)st[0]);
            }
            objAnimDframe(obj, *(f32 *)(anims + 0x7C), fArg1);
            break;

        case 11:
            if (*(f32 *)(obj + 0x28) == 1.0f) {
                st[0] = 0;
                st[0x30] = 0xF;
                *(f32 *)(st + 0x28) = *(f32 *)(anims + 0x8);
                objAnimSetMove(obj, *(s16 *)(anims + 0x2), *(s32 *)(obj + 0x28), (void *)(s32)st[0]);
            }
            objAnimDframe(obj, *(f32 *)(anims + 0x88), fArg1);
            break;

        case 12:
            if (*(f32 *)(obj + 0x28) == 1.0f) {
                st[0] = 0;
                st[0x30] = 0xF;
                *(f32 *)(st + 0x28) = *(f32 *)(anims + 0x8);
                objAnimSetMove(obj, *(s16 *)(anims + 0x2), *(s32 *)(obj + 0x28), (void *)(s32)st[0]);
            }
            objAnimDframe(obj, *(f32 *)(anims + 0x94), fArg1);
            break;

        case 13:
            mainPauseDisable(0xA);
            if (*(f32 *)(obj + 0x28) == 1.0f) {
                st[0] = 8;
                *(f32 *)(st + 0x28) = *(f32 *)(anims + 0x68);
                objAnimSetMove(obj, *(s16 *)(anims + 0x62), *(s32 *)(obj + 0x28), (void *)(s32)st[0]);
                hinttextStopMagic();
            }
            sp64 = *(f32 *)(obj + 0x28);
            objAnimDframe(obj, *(f32 *)(anims + 0xA0), fArg1);
            if (sp64 < *(f32 *)(row + 0x10) && *(f32 *)(row + 0x10) <= *(f32 *)(obj + 0x28)) {
                amSndPlay(0xFA, NULL);
            } else if (sp64 < *(f32 *)(row + 0x14) && *(f32 *)(row + 0x14) <= *(f32 *)(obj + 0x28)) {
                sp68 = (f32)*(s16 *)(row + 0x22);
                sp74 = (Sinf(*(s16 *)obj) * sp68) + *(f32 *)(obj + 0xC);
                hinttextLoadObject(sp74, *(f32 *)(obj + 0x10) + 30.0f,
                                   (Cosf(*(s16 *)obj) * sp68) + *(f32 *)(obj + 0x14), 8.0f, 1.0f);
                setupClearScreen(&D_overlay_32_020031C4);
                amSndPlay(6, NULL);
            }
            if (*(f32 *)(row + 0x18) < *(f32 *)(obj + 0x28) && *(f32 *)(obj + 0x28) < *(f32 *)(row + 0x1C)) {
                *(s32 *)(obj + 0x84) = (s32)*(u16 *)(row + 0x20);
            }
            break;

        case 14:
            mainPauseDisable(0xA);
            sp64 = *(f32 *)(obj + 0x28);
            objAnimDframe(obj, *(f32 *)(anims + 0xAC), fArg1);
            if (sp64 < *(f32 *)(row + 0x24) && *(f32 *)(row + 0x24) <= *(f32 *)(obj + 0x28)) {
                hinttextStartLevel();
            }
            if (*(f32 *)(row + 0x28) < *(f32 *)(obj + 0x28) && *(f32 *)(obj + 0x28) < *(f32 *)(row + 0x2C)) {
                *(s32 *)(obj + 0x84) = *(s32 *)(row + 0x30);
            }
            break;

        case 15:
            objAnimDframe(obj, *(f32 *)(anims + 0xB8), fArg1);
            if (*(u8 *)(obj + 0x93) == 0) {
                if (st[0x34] != 0 && (player = objGetPlayerNo(0)) != NULL) {
                    st[0] = 1;
                    st[0x33] = 0xA;
                    *(s16 *)(st + 0x2) = (s16)Arctanf(*(f32 *)(player + 0xC) - *(f32 *)(obj + 0xC),
                                                       *(f32 *)(player + 0x14) - *(f32 *)(obj + 0x14));
                    player = NULL;
                } else if (st[0x36] != 0) {
                    func_overlay_32_020025F0_1F52FC0(obj, st, anims);
                } else {
                    st[0] = 0;
                }
                ent = anims + st[0] * 12;
                *(f32 *)(st + 0x28) = *(f32 *)(ent + 0x8);
                objAnimSetMove(obj, *(s16 *)(ent + 0x2), 0, (void *)(s32)st[0]);
            }
            break;

        case 16:
        case 17:
            objAnimDframe(obj, *(f32 *)(anims + a3val * 12 + 0x4), fArg1);
            if (*(f32 *)(obj + 0x28) >= 1.0f) {
                if (*(u8 *)(obj + 0x93) == 0 || *(f32 *)(st + 0x10) == 0.0f) {
                    player = objGetPlayerNo(0);
                    if (player != NULL) {
                        if (*(f32 *)(st + 0x10) == 0.0f) {
                            st[0] = 0xA;
                        } else {
                            st[0] = 1;
                            st[0x33] = 0xA;
                            *(s16 *)(st + 0x2) = (s16)Arctanf(*(f32 *)(player + 0xC) - *(f32 *)(obj + 0xC),
                                                               *(f32 *)(player + 0x14) - *(f32 *)(obj + 0x14));
                            player = NULL;
                        }
                    } else if (st[0x36] != 0) {
                        func_overlay_32_020025F0_1F52FC0(obj, st, anims);
                    } else {
                        st[0] = 0;
                    }
                } else {
                    st[0] = 0xF;
                }
                ent = anims + st[0] * 12;
                *(f32 *)(st + 0x28) = *(f32 *)(ent + 0x8);
                objAnimSetMove(obj, *(s16 *)(ent + 0x2), 0, (void *)(s32)st[0]);
            }
            break;

        case 18:
            objAnimDframe(obj, *(f32 *)(anims + 0xDC), fArg1);
            if (*(f32 *)(obj + 0x28) >= 1.0f) {
                st[0] = 0;
                *(f32 *)(st + 0x28) = *(f32 *)(anims + 0x8);
                objAnimSetMove(obj, *(s16 *)(anims + 0x2), 0, (void *)(s32)st[0]);
            }
            break;

        default:
            break;
        }
    }

    /* player-bound follow-up (the sp48 block of the asm) */
    if (player != NULL) {
        st0 = st[0];
        if (st0 != 0xD && (st[1] == 0 || st0 == 8 || st0 == 9) &&
            ((joyGetPressed(0) & 0x1000) || hinttextTriedToEnd() != 0 || sp5A != 0)) {
            pst = *(u8 **)(player + 0x68);
            if (st0 == 9) {
                st[0] = 8;
                *(f32 *)(st + 0x28) = *(f32 *)(anims + 0x68);
                objAnimSetMove(obj, *(s16 *)(anims + 0x62), 0, (void *)(s32)st[0]);
                hinttextStart(st[0x31], (s8)st[1]);
            } else {
                D_overlay_32_020031CC = 0;
                fTmp = *(f32 *)(st + 0x14);
                if (fTmp > 0.0f) {
                    dx = *(f32 *)(st + 0x4) - *(f32 *)(obj + 0xC);
                    dz = *(f32 *)(st + 0xC) - *(f32 *)(obj + 0x14);
                    st[0] = 1;
                    st[0x33] = 0;
                    if (fTmp < (dx * dx + dz * dz)) {
                        *(s16 *)(st + 0x2) = (s16)Arctanf(dx, dz);
                    } else {
                        *(s16 *)(st + 0x2) = (s16)(*(s16 *)obj + 0x8000);
                    }
                } else {
                    st[0] = 2;
                }
                st[1] = 0;
                ent = anims + st[0] * 12;
                *(f32 *)(st + 0x28) = *(f32 *)(ent + 0x8);
                objAnimSetMove(obj, *(s16 *)(ent + 0x2), *(s32 *)(obj + 0x28), (void *)(s32)st[0]);
                pst[0x1F9] = 0;
                hinttextStop();
            }
        }
    }

    /* eased blend of the anim speed, then move */
    fTmp = *(f32 *)(st + 0x24);
    *(f32 *)(st + 0x24) = (f32)((1.0f - Powerf(D_overlay_32_0200322C, arg1)) * (*(f32 *)(st + 0x28) - fTmp) + fTmp);
    *(f32 *)(obj + 0x24) = *(f32 *)(st + 0x24);
    mathOneFloatPY((s16 *)obj, obj + 0x1C, NULL); /* asm: $a2 stale */
    *(s16 *)obj = (s16)(*(s16 *)obj + *(s16 *)(row + 0x2));
    objMoveXYZ(obj, *(f32 *)(obj + 0x1C) * fArg1, *(f32 *)(obj + 0x20) * fArg1, *(f32 *)(obj + 0x24) * fArg1);
    v = *(s32 *)(obj + 0x84);
    if (v == 0) {
        v = v | *(s32 *)(row + 0x34);
        *(s32 *)(obj + 0x84) = v;
    }
    if (v != 0) {
        sp50 = *(u8 **)(*(u8 **)(obj + 0x6C) + ((s8)obj[0x3A] * 4));
        if (sp50 != NULL && sp50[0xA] != 0) {
            sp54 = *(u8 **)sp50;
            modGenAnimMatrices(sp50, sp54, obj, 0x3F800000, 0.0f);
            lightObject(obj, sp50, *(s32 *)(obj + 0x54), *(s32 *)(sp50 + ((s8)sp50[0xB] * 4) + 0x10));
            if ((s32)sp54[0x11] > 0) {
                objAnimTextures(obj, sp54, sp50, (s8)sp50[0xA]);
            }
            sp50[0xA] = 0;
        }
        partUpdateTriggers(obj, arg1);
    }
    if (*(void **)(st + 0x2C) != NULL) {
        amSndSetXYZ(*(void **)(st + 0x2C), *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o32/overlay_32/mrhintsControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_32_02001D2C_1F526FC(void *arg0) {
    u8 *obj = (u8 *)arg0;
    s32 sp1C;
    s32 sp18;
    s32 var_v0;
    u8 temp_v0;

    temp_v0 = obj[0x32];
    sp1C = (s32)temp_v0 >> 3;
    sp18 = 0x80 >> (temp_v0 & 7);
    var_v0 = 1;
    if ((*((u8 *)mainGetGame() + sp1C + 0x8)) & sp18) {
        var_v0 = 0;
    }
    return var_v0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o32/overlay_32/func_overlay_32_02001D2C_1F526FC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_32_02001D84_1F52754(void *arg0) {
    u8 *obj = (u8 *)arg0;
    s32 sp1C;
    s32 sp18;
    u8 temp_v0;
    u8 *temp_v1;

    temp_v0 = obj[0x32];
    sp1C = (s32)temp_v0 >> 3;
    sp18 = 0x80 >> (temp_v0 & 7);
    temp_v1 = (u8 *)mainGetGame() + sp1C;
    temp_v1[0x8] = (u8)(temp_v1[0x8] | sp18);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o32/overlay_32/func_overlay_32_02001D84_1F52754.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_32_02001DD8_1F527A8(void *arg0) {
    u8 *obj = (u8 *)arg0;
    s32 sp1C;
    void *sp18;
    Game *temp_v0;
    s32 temp_a1;
    u8 temp_t6;

    temp_a1 = mainGetPlayerCharacter(0) & 3;
    sp1C = temp_a1;
    sp18 = mainGetGameCharacter(0, temp_a1);
    temp_v0 = mainGetGame();
    temp_t6 = obj[0x32];
    switch (temp_t6) {
    case 1:
        if ((sp1C != 1) || (obj[0x1] == 0)) {
            return 0;
        }
        return 1;
    case 2:
        if ((sp1C != 1) || (*(u16 *)((u8 *)temp_v0 + 0x236) != 0x400)) {
            return 0;
        }
        return 1;
    case 3:
        if ((mainGetGameFlag(0x17) != 0) || (obj[0x1] == 0)) {
            return 0;
        }
        return 1;
    case 4:
        if (mainPlayerHas(0, sp1C, 1, sp1C) != 0) {
            return 0;
        }
        return 1;
    case 5:
        if (obj[0x1] == 0) {
            return 0;
        }
        return 1;
    case 6:
        if (mainGetGameFlag(0) != 0) {
            return 0;
        }
        return 1;
    case 7:
        if (mainAnyoneHas(0x15) != 0) {
            return 0;
        }
        return 1;
    case 9:
        if (mainAnyoneHas(0x11) != 0) {
            return 0;
        }
        return 1;
    case 10:
        if (mainPlayerHas(0, sp1C, 1, sp1C) != 0) {
            return 0;
        }
        return 1;
    case 11:
        if ((sp1C != 1) || (mainGetGameFlag(0x5F) != 0)) {
            return 0;
        }
        return 1;
    case 12:
        if (mainGetGameFlag(3) != 0) {
            return 0;
        }
        return 1;
    case 14:
        if (mainGetGameFlag(0x20) != 0) {
            return 0;
        }
        return 1;
    case 16:
        if (mainGetGameFlag(0x22) != 0) {
            return 0;
        }
        return 1;
    case 17:
        if (mainGetGameFlag(0x23) != 0) {
            return 0;
        }
        return 1;
    case 18:
        if (mainGetGameFlag(0x63) != 0) {
            return 0;
        }
        return 1;
    case 19:
        if ((sp1C != 0) || (*((u8 *)sp18 + 0xA) & 0x20)) {
            return 0;
        }
        return 1;
    case 20:
        if (mainGetGameFlag(0x24) != 0) {
            return 0;
        }
        return 1;
    default:
        return 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o32/overlay_32/func_overlay_32_02001DD8_1F527A8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s16 func_overlay_32_02002068_1F52A38(s16 arg0, s16 arg1, s16 arg2) {
    s16 var_a0 = arg0;
    s16 var_a2 = arg2;
    s32 temp_t4;
    s32 temp_t5;
    s32 var_v1;

    while (var_a2 != 0) {
        temp_t4 = (arg1 - var_a0) & 0xFFFF;
        temp_t5 = (var_a0 - arg1) & 0xFFFF;
        if (temp_t5 < temp_t4) {
            var_v1 = (s32)(-temp_t5) >> 3;
            if (var_v1 < -0x16C) {
                var_v1 = -0x16C;
            }
        } else {
            var_v1 = temp_t4 >> 3;
            if (var_v1 >= 0x16D) {
                var_v1 = 0x16C;
            }
        }
        var_a0 += var_v1;
        var_a2 -= 1;
    }
    return var_a0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o32/overlay_32/func_overlay_32_02002068_1F52A38.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void floatingInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *setup = (u8 *)arg1;
    u8 *st = *(u8 **)(obj + 0x68);
    u8 *temp_v1;

    *(f32 *)st = *(f32 *)(obj + 0x10);
    *(f32 *)(st + 0x4) = (f32)setup[0xA];
    *(s16 *)(st + 0x8) = 0;
    *(s16 *)(st + 0xA) = (s16)setup[0xB];
    if (*(s16 *)(st + 0xA) != 0) {
        *(s16 *)(st + 0x8) = -0x3000;
    }
    temp_v1 = *(u8 **)(obj + 0x70);
    if (temp_v1 != NULL) {
        *(f32 *)st = *(f32 *)st - (f32)*(s16 *)(temp_v1 + 0x1C);
    }
    *(f32 *)(obj + 0x8) = **(f32 **)(obj + 0x40) * *(f32 *)(setup + 0xC);
    *(s32 *)(obj + 0x88) = 0;
    *(s32 *)(obj + 0x8C) = 0xFF;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o32/overlay_32/floatingInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void floatingControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *st = *(u8 **)(obj + 0x68);
    u8 *temp_v1;
    u8 *temp_a0;
    u8 *temp_v0_2;
    u8 *temp_v0_3;
    u8 *light;
    s16 vec[3];
    s16 temp_v1_2;
    f32 var_f2;

    *(s16 *)obj = (s16)(*(s16 *)obj + (arg1 << 8));
    *(s16 *)(st + 0x8) = (s16)(*(s16 *)(st + 0x8) + (arg1 << 7));
    temp_v1 = *(u8 **)(*(u8 **)(obj + 0x6C));
    if (temp_v1 != NULL) {
        temp_a0 = *(u8 **)temp_v1;
        if (temp_a0 != NULL && *(s8 *)(temp_a0 + 0x4E) != 0) {
            objAnimDframe(obj, 0.16666667f, (f32)arg1); /* asm: float 0x3E2AB368 */
        }
    }
    temp_v1_2 = *(s16 *)(st + 0xA);
    var_f2 = *(f32 *)(st + 0x4);
    if (temp_v1_2 != 0) {
        if (*(s16 *)(st + 0x8) >= 0) {
            *(s16 *)(st + 0xA) = 0;
        } else {
            var_f2 = (f32)temp_v1_2;
        }
    }
    objMoveXYZ(obj, 0.0f, ((Sinf(*(s16 *)(st + 0x8)) * var_f2) + *(f32 *)st) - *(f32 *)(obj + 0x10), 0.0f);
    *(s32 *)(obj + 0x84) = 1;
    partUpdateTriggers(obj, arg1);
    if (*(s32 *)(obj + 0x88) != 0) {
        *(s16 *)(obj + 0x6) = (s16)(*(s16 *)(obj + 0x6) | 4);
        *(s32 *)(obj + 0x8C) = *(s32 *)(obj + 0x8C) - (arg1 << 2);
    }
    if (*(s32 *)(obj + 0x8C) <= 0) {
        objFreeObject(obj);
    } else {
        temp_v0_2 = *(u8 **)(obj + 0x74);
        if (temp_v0_2 != NULL) {
            light = *(u8 **)temp_v0_2;
            if (light != NULL) {
                *(f32 *)(light + 0x8) = 0.0f;
                *(f32 *)(light + 0xC) = 0.0f;
                *(f32 *)(light + 0x10) = -16.0f;
                temp_v0_3 = *(u8 **)(obj + 0x70);
                if (temp_v0_3 != NULL) {
                    vec[0] = (s16)(*(s16 *)(temp_v0_3 + 0xE) - *(s16 *)obj);
                    vec[1] = *(s16 *)(temp_v0_3 + 0x10);
                    vec[2] = 0;
                    mathOneFloatPY(vec, light + 0x8, light);
                    *(f32 *)(light + 0x8) = *(f32 *)(light + 0x8) + (f32)*(s16 *)(temp_v0_3 + 0x1A);
                    *(f32 *)(light + 0xC) = *(f32 *)(light + 0xC) + (f32)*(s16 *)(temp_v0_3 + 0x1C);
                    *(f32 *)(light + 0x10) = *(f32 *)(light + 0x10) + (f32)*(s16 *)(temp_v0_3 + 0x1E);
                }
                changeLightIntensity((UnkLight *)light, obj[0x8F]);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o32/overlay_32/floatingControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mrHintsSpeak(void *arg0, s16 arg1, s8 arg2) {
    u8 *obj = (u8 *)arg0;
    u8 *st = *(u8 **)(obj + 0x68);
    void *snd = *(void **)(st + 0x2C);
    s8 var_a2 = arg2;

    if (snd != NULL) {
        amSndStopXYZ(snd);
    }
    if (var_a2 >= 2) {
        arg1 += mathRnd(0, var_a2 - 1);
    }
    amSndPlayXYZ((u16)arg1, *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14), 4, st + 0x2C);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o32/overlay_32/mrHintsSpeak.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mrHintsEventHandler(void *arg0, s32 arg1) {
    u8 *ent = (u8 *)&D_overlay_32_02002F24;
    s16 key = *(s16 *)((u8 *)arg0 + 0x4A);
    s16 k;
    u8 *v;

    if (key != D_overlay_32_02002F24 && D_overlay_32_02002F24 >= 0) {
        do {
            k = *(s16 *)(ent + 0x38);
            ent += 0x38;
        } while (key != k && k >= 0);
    }
    v = *(u8 **)(ent + 0x8) + (arg1 - 1) * 4;
    mrHintsSpeak(arg0, *(s16 *)v, *(s8 *)(v + 0x3));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o32/overlay_32/mrHintsEventHandler.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mrHintsTalk(void) {
    u8 *obj;
    u8 *ent;
    u8 *sub;
    s16 key;
    s16 k;

    obj = (u8 *)D_overlay_32_020031CC;
    if (obj != NULL) {
        ent = (u8 *)&D_overlay_32_02002F24;
        key = *(s16 *)(obj + 0x4A);
        if (key != D_overlay_32_02002F24 && D_overlay_32_02002F24 >= 0) {
            do {
                k = *(s16 *)(ent + 0x38);
                ent += 0x38;
            } while (key != k && k >= 0);
        }
        sub = *(u8 **)(ent + 0x8);
        if (**(u8 **)(obj + 0x68) == 8) {
            mrHintsSpeak(obj, *(s16 *)(sub + 0x14), *(s8 *)(sub + 0x17));
            return;
        }
        mrHintsSpeak(obj, *(s16 *)(sub + 0x18), *(s8 *)(sub + 0x1B));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o32/overlay_32/mrHintsTalk.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_32_020025F0_1F52FC0(void *arg0, void *arg1, void *arg2) {
    u8 *a0 = (u8 *)arg0;
    u8 *a1 = (u8 *)arg1;
    u8 *a2 = (u8 *)arg2;

    *(u8 *)(a1 + 0x0) = 1;
    *(u8 *)(a1 + 0x33) = 0;
    *(s16 *)(a1 + 0x2) = (s16)Arctanf(*(f32 *)(a1 + 0x4) - *(f32 *)(a0 + 0xC), *(f32 *)(a1 + 0xC) - *(f32 *)(a0 + 0x14));
    *(f32 *)(a1 + 0x28) = *(f32 *)(a2 + 0x14);
    objAnimSetMove(arg0, *(s16 *)(a2 + 0xE), *(s32 *)(a0 + 0x28), arg1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o32/overlay_32/func_overlay_32_020025F0_1F52FC0.s")
#endif
