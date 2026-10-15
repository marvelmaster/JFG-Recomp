#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern s16 D_800FF8E6;
extern f32 D_800FF8F0;
extern void *frontendptrs[];
extern s8 playStatus[];
extern s8 playChoice[];
extern s8 frontJoyDx[];
extern s32 frontJoyPressed[];
extern u8 okayed;
extern u8 disable;
extern u8 numberOfPlayers;
extern u8 multiCharacter[];
extern u8 multiCharacterType[];
extern s8 charselquitmode;
extern u8 D_overlay_58_03A01050[];
extern u8 D_overlay_58_03A010F8[];
extern s16 D_overlay_58_03A01100;
extern s16 D_overlay_58_03A0111C;
extern u8 D_overlay_58_03A01120[];
extern u8 D_overlay_58_03A01138[];
extern u8 D_overlay_58_03A0113C[];
extern void *D_overlay_58_03A011B8;
extern void *D_overlay_58_03A01220;
extern void *D_overlay_58_03A01224;
extern void *D_overlay_58_03A01228;
extern s16 D_overlay_58_03A0122C;
extern s16 D_overlay_58_03A0122E;
extern u8 D_overlay_58_03A01230;
extern u8 D_overlay_58_03A01231;
extern s32 D_overlay_58_03A01234;
extern void *D_overlay_58_03A01238;
extern void *D_overlay_58_03A01240[2];
extern s32 D_overlay_58_03A01248;
extern s32 D_overlay_58_03A0124C;
extern f32 D_overlay_58_03A01218;
extern void *D_overlay_58_03A01250[4];

void amTunePlay(u8 seqID);
void modelSetModelFlags(s32 arg0);
void loadFrontEndList(s16 *arg0);
void setupFrontEndList(s16 *arg0);
void *objSetupObject(void *params, s32 arg1, void *owner);
void *screenLoad(s32 arg0);
void mainInitMultiPlayerPoints(void *arg0, void *arg1, s32 arg2, s32 arg3);
void amSndPlay(u16 soundID, void *handlePtr);
void amTuneSetFade(f32 fade, s32 volume);
void animseqStopPath(s32 arg0);
void frontCharBadge(s32 arg0, s32 arg1, s32 arg2);
s32 levelGetRegionNo(s32 arg0);
s32 mainGetGameFlag(s32 flag);
void mainSetMode(s32 modeToSet);
void mainTitlePageInit(void);
void mainValidateRestart(s32 *arg0, s32 *arg1, s32 *arg2);
void *menuCamGetObjPtr(void);
void setupClearScreen(void *arg0);
void *trackGetTrack(void);
void mainSetDefaultCharacter(void *arg0, s32 arg1);
void multiCharArmSetStatus(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
Object **objGetObjList(s32 *arg0, s32 *arg1);
void freeFrontEndList(s16 *arg0);
void objFreeObject(void *obj);
s16 *camGetPtr(void);
void camSetNo(s32 arg0);
void mmFree(void *data);
void func_overlay_58_03A00F5C_1F7920C(s32 arg0, s32 arg1, s8 *arg2, s32 arg3);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontInitCharSelect(void) {
    modelSetModelFlags(0);
    loadFrontEndList(&D_overlay_58_03A01100);
    modelSetModelFlags(8);
    setupFrontEndList(&D_overlay_58_03A0111C);
    D_overlay_58_03A01228 = NULL;
    D_overlay_58_03A01230 = 1;
    D_overlay_58_03A01220 = NULL;
    D_overlay_58_03A01224 = NULL;
    D_overlay_58_03A01248 = 0x28;
    D_overlay_58_03A0122E = 0x1E0;
    D_overlay_58_03A01231 = 0;
    D_overlay_58_03A01234 = 0;
    /* sig mismatch: asm passes only 2 args here */
    D_overlay_58_03A01240[0] = ((void *(*)(void *, s32))objSetupObject)(D_overlay_58_03A01120, 1);
    D_overlay_58_03A01240[1] = objSetupObject(D_overlay_58_03A01120, 1, D_overlay_58_03A01240);
    *(s16 *)((u8 *)D_overlay_58_03A01240[0] + 0x6) = (s16)(*(s16 *)((u8 *)D_overlay_58_03A01240[0] + 0x6) | 0x400);
    *(s16 *)((u8 *)D_overlay_58_03A01240[1] + 0x6) = (s16)(*(s16 *)((u8 *)D_overlay_58_03A01240[1] + 0x6) | 0x400);
    *(f32 *)((u8 *)frontendptrs[D_800FF8E6] + 0x28) = 1.0f;
    if (viGetVideoMode() & 1) {
        D_800FF8F0 += 20.0f;
    }
    D_overlay_58_03A0124C = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o58/overlay_58/frontInitCharSelect.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontCharSelect(s32 arg0) {
    u8 *temp_v1;
    u8 *temp_t6;
    u8 *temp_v0_2;
    u8 *temp_v1_2;
    u8 *var_a1;
    u8 *var_v0;
    u8 *sp38;
    s32 sp40;
    s32 sp34;
    s32 sp30;
    s32 sp2C;
    s8 temp_a1;
    u16 temp_v0;
    s32 var_t0;
    s32 var_v1;
    s32 var_at;

    temp_v1 = D_overlay_58_03A01220;
    if (temp_v1 == NULL) {
        D_overlay_58_03A01220 = menuCamGetObjPtr();
    }
    if (temp_v1 != NULL) {
        temp_t6 = *(u8 **)(temp_v1 + 0x68);
        D_overlay_58_03A01224 = temp_t6;
        if (temp_t6 != NULL) {
            if (D_overlay_58_03A0124C < 0x1E) {
                D_overlay_58_03A0124C += arg0;
            }
            if ((mainGetGameFlag(1) == 0) || (mainGetGameFlag(0x5B) != 0)) {
                animseqStopPath(0);
            }
            if ((mainGetGameFlag(0) == 0) || (mainGetGameFlag(0x5A) != 0)) {
                animseqStopPath(1);
            }
            if ((mainGetGameFlag(2) == 0) || (mainGetGameFlag(0x5C) != 0)) {
                animseqStopPath(2);
            }
            frontCharBadge(0, 0, arg0);
            if (!(D_overlay_58_03A01234 & 2) && (joyGetPressed(0) & 0x4000) && (charselquitmode != 0) && (D_overlay_58_03A0124C >= 0x1E)) {
                amTuneSetFade(0.75f, 0);
                mainTitlePageInit();
            }
            if (*(u32 *)temp_t6 & 4) {
                if ((joyGetPressed(0) & 0x8000) && (D_overlay_58_03A0122E != 0x1E0)) {
                    D_overlay_58_03A0122E = 0;
                } else {
                    D_overlay_58_03A0122E -= arg0;
                }
                if (D_overlay_58_03A0122E <= 0) {
                    if (D_overlay_58_03A01231 == 0) {
                        setupClearScreen(D_overlay_58_03A010F8);
                        D_overlay_58_03A01231 = 1;
                        D_overlay_58_03A0122C = 0x50;
                        amTuneSetFade(D_overlay_58_03A01218, 0);
                    } else {
                        D_overlay_58_03A0122C -= arg0;
                        if (D_overlay_58_03A0122C <= 0) {
                            temp_a1 = (s8)D_overlay_58_03A01138[temp_t6[0x51]];
                            temp_v1_2 = (u8 *)mainGetGame() + (temp_a1 * 0x76) + 0x15C;
                            sp38 = temp_v1_2;
                            sp40 = temp_a1;
                            /* sig mismatch: asm passes 2 args here */
                            ((void (*)(s32, s32))mainSetMode)(0, temp_a1);
                            if (levelGetRegionNo((u16)*(u16 *)(temp_v1_2 + 0x74) >> 5) != 0) {
                                temp_v1_2[5] = (u8)(temp_v1_2[5] & 0xE0);
                            }
                            sp34 = (u16)*(u16 *)(temp_v1_2 + 0x74) >> 5;
                            sp30 = *(u16 *)(temp_v1_2 + 0x74) & 0x1F;
                            sp38 = temp_v1_2;
                            sp2C = *(u16 *)(temp_v1_2 + 0x4) & 0x1F;
                            mainValidateRestart(&sp34, &sp30, &sp2C);
                            *(u16 *)(sp38 + 0x74) = (u16)((sp34 << 5) | (*(u16 *)(sp38 + 0x74) & 0x1F));
                            sp38[0x75] = (u8)((sp30 & 0x1F) | (sp38[0x75] & 0xE0));
                            temp_v0 = *(u16 *)(sp38 + 0x74);
                            sp38[5] = (u8)((sp2C & 0x1F) | (sp38[5] & 0xE0));
                            mainChangeLevel((s32)(temp_v0 >> 5), sp40, temp_v0 & 0x1F, 0x10, 1, 0);
                        }
                    }
                }
            }
            if (D_overlay_58_03A01228 == NULL) {
                temp_v0_2 = trackGetTrack();
                var_t0 = 0;
                if (*(s16 *)(temp_v0_2 + 0x1A) > 0) {
                    var_a1 = *(u8 **)(temp_v0_2 + 0x4);
                    do {
                        var_v1 = 0;
                        if (*(s32 *)(var_a1 + 0x28) > 0) {
                            var_v0 = *(u8 **)(var_a1 + 0xC);
                            do {
                                var_v1 += 1;
                                var_at = var_v1 < *(s32 *)(var_a1 + 0x28);
                                if (*(s32 *)var_v0 == 0x31) {
                                    D_overlay_58_03A01228 = (*(s32 *)(var_v0 + 0x8) * 0x10) + *(u8 **)(var_a1 + 0x4);
                                    var_at = var_v1 < *(s32 *)(var_a1 + 0x28);
                                }
                                var_v0 += 0x10;
                            } while (var_at != 0);
                        }
                        var_t0 += 1;
                        var_a1 += 0x48;
                    } while (var_t0 < *(s16 *)(temp_v0_2 + 0x1A));
                }
            } else if ((((*(s16 *)((u8 *)D_overlay_58_03A01228 + 0x4)) >> 5) % 32) >= 2) {
                D_overlay_58_03A01230 = 1;
            } else if (D_overlay_58_03A01230 != 0) {
                if ((temp_t6 != NULL) && (!(*(u32 *)temp_t6 & 2) || (temp_t6[0x51] == 0))) {
                    amSndPlay(0xD0, 0);
                }
                D_overlay_58_03A01230 = 0;
            }
            D_overlay_58_03A01234 = *(u32 *)D_overlay_58_03A01224;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o58/overlay_58/frontCharSelect.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontTeleporterTick(s32 arg0) {
    u8 *temp_a2;
    s8 temp_a0;
    s16 *temp_v0;
    u8 *obj0;
    u8 *obj1;

    if (*(u32 *)D_overlay_58_03A01224 & 2) {
        temp_a0 = *((u8 *)D_overlay_58_03A01224 + 0x51);
        temp_a2 = *(u8 **)(*(u8 **)((u8 *)D_overlay_58_03A01224 + (temp_a0 * 4) + 0x4) + 0x68);
        obj0 = D_overlay_58_03A01240[0];
        obj1 = D_overlay_58_03A01240[1];
        if (D_overlay_58_03A01238 == NULL) {
            if (temp_a0 == 2) {
                *(s16 *)(D_overlay_58_03A0113C + 0x24) = 0xA5;
                *(s16 *)(D_overlay_58_03A0113C + 0x26) = 0x50;
            } else {
                *(s16 *)(D_overlay_58_03A0113C + 0x24) = 0x64;
                *(s16 *)(D_overlay_58_03A0113C + 0x26) = 0x64;
            }
            *(s16 *)(D_overlay_58_03A0113C + 0x4) = (s16)*(f32 *)(temp_a2 + 0xC);
            *(s16 *)(D_overlay_58_03A0113C + 0x6) = (s16)*(f32 *)(temp_a2 + 0x10);
            *(s16 *)(D_overlay_58_03A0113C + 0x8) = (s16)*(f32 *)(temp_a2 + 0x14);
            D_overlay_58_03A01238 = objSetupObject(D_overlay_58_03A0113C, 1, temp_a2);
        } else if ((*(s16 *)(*(u8 **)((u8 *)D_overlay_58_03A01238 + 0x68) + 0xFCA) >= 0x137) && (D_overlay_58_03A01248 > 0)) {
            *(s16 *)(obj0 + 0x6) = (s16)(*(s16 *)(obj0 + 0x6) & 0xFBFF);
            *(s16 *)(obj1 + 0x6) = (s16)(*(s16 *)(obj1 + 0x6) & 0xFBFF);
            /* sig mismatch: asm passes 3 args to camSetNo */
            ((void (*)(s32, void *, void *))camSetNo)(0, obj1, temp_a2);
            temp_v0 = camGetPtr();
            *(f32 *)(obj0 + 0xC) = *(f32 *)(temp_a2 + 0xC);
            *(f32 *)(obj0 + 0x10) = *(f32 *)(temp_a2 + 0x10) + 35.0f;
            *(f32 *)(obj0 + 0x14) = *(f32 *)(temp_a2 + 0x14);
            *(s16 *)(obj0 + 0x0) = (s16)(0xC000 - *temp_v0);
            *(f32 *)(obj1 + 0xC) = *(f32 *)(temp_a2 + 0xC);
            *(f32 *)(obj1 + 0x10) = *(f32 *)(temp_a2 + 0x10) + 35.0f;
            *(f32 *)(obj1 + 0x14) = *(f32 *)(temp_a2 + 0x14);
            *(s16 *)(obj1 + 0x0) = (s16)(0x4000 - *temp_v0);
            D_overlay_58_03A01248 -= arg0;
        } else {
            *(s16 *)(obj0 + 0x6) = (s16)(*(s16 *)(obj0 + 0x6) | 0x400);
            *(s16 *)(obj1 + 0x6) = (s16)(*(s16 *)(obj1 + 0x6) | 0x400);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o58/overlay_58/frontTeleporterTick.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontCleanupCharSelect(void) {
    freeFrontEndList(&D_overlay_58_03A01100);
    if (D_overlay_58_03A01238 != NULL) {
        objFreeObject(D_overlay_58_03A01238);
        D_overlay_58_03A01238 = NULL;
    }
    D_overlay_58_03A01220 = NULL;
    objFreeObject(D_overlay_58_03A01240[0]);
    objFreeObject(D_overlay_58_03A01240[1]);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o58/overlay_58/frontCleanupCharSelect.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontInitMultiSelect(void) {
    s32 i;

    joyResetMap();
    numberOfCameras = 1;
    D_overlay_58_03A011B8 = screenLoad(0);
    amTunePlay(0xE);
    for (i = 0; i < 4; i++) {
        if (playStatus[i] != 0) {
            if (playChoice[i] == 0) {
                playStatus[i] = 2;
            } else {
                playStatus[i] = 1;
            }
        }
        D_overlay_58_03A01250[i] = NULL;
    }
    mainInitMultiPlayerPoints(&D_overlay_58_03A01250[4], playChoice, 2, 4);
    D_overlay_58_03A0124C = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o58/overlay_58/frontInitMultiSelect.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontMultiSelect(s32 arg0) {
    s32 sp88;
    s32 sp84;
    s32 sp78;
    s32 var_s4;
    s32 var_s5;
    s32 var_s6;
    s32 var_s5_2;
    s32 var_s1_2_idx;
    s32 var_a1;
    s32 var_a3;
    s32 var_s1;
    s32 temp_a2;
    s32 temp_v0_2;
    s32 temp_v1_3;
    s32 temp_v0_7;
    s32 idx;
    s32 found;
    s8 temp_a0_7;
    s8 temp_v1;
    s8 temp_a1;
    s8 temp_a2_2;
    u8 temp_t3;
    s8 *var_fp;
    s8 *var_s1_2;
    s8 *temp_s2;
    u8 *temp_s0;
    u8 *temp_v0_4;
    u8 *temp_v0_5;
    Object **temp_v0;
    Object *temp_v1_2;
    Object *var_a0_2;
    Object *temp_v0_6;
    s32 var_a0;
    s32 temp_a0_6;

    if (D_overlay_58_03A0124C < 0x1E) {
        D_overlay_58_03A0124C += arg0;
    }
    var_s5 = 0;
    if (D_overlay_58_03A01250[0] == NULL) {
        temp_v0 = objGetObjList(&sp88, &sp84);
        if (sp88 < sp84) {
            for (var_s4 = sp88; var_s4 < sp84; var_s4++) {
                temp_v1_2 = temp_v0[var_s4];
                if (*(s16 *)((u8 *)temp_v1_2 + 0x48) == 0x5C) {
                    D_overlay_58_03A01250[var_s5] = temp_v1_2;
                    var_s5 += 1;
                }
            }
        }
    }
    if (okayed == 0) {
        var_s6 = 0;
        if (disable == 0) {
            var_fp = playStatus;
            var_s1_2 = frontJoyDx;
            do {
                temp_v0_2 = frontJoyPressed[var_s6 * 4];
                temp_v1 = frontJoyDx[var_s6];
                sp78 = 0;
                var_a0 = temp_v1 < 0;
                var_s5_2 = 0;
                var_a1 = temp_v0_2 & 0x9000;
                temp_a2 = temp_v0_2 & 0x4000;
                if (var_a0 == 0) {
                    var_a0 = (temp_v0_2 & 0x20) != 0;
                }
                temp_a0_6 = temp_v1 > 0;
                var_s1 = temp_a0_6;
                if (temp_a0_6 == 0) {
                    var_s1 = (temp_v0_2 & 0x10) != 0;
                }
                temp_a0_7 = playStatus[var_s6];
                switch (temp_a0_7) {
                case 0:
                    if (var_a1 != 0) {
                        playStatus[var_s6] = 1;
                        numberOfPlayers += 1;
                    }
                    break;
                case 1:
                    if (var_a1 != 0) {
                        playStatus[var_s6] = 2;
                    } else if ((temp_a2 != 0) && (D_overlay_58_03A0124C >= 0x1E)) {
                        playStatus[var_s6] = 0;
                        temp_t3 = numberOfPlayers - 1;
                        numberOfPlayers = temp_t3;
                        if ((temp_t3 & 0xFF) <= 0) {
                            okayed = 1;
                            amTuneSetFade(0.5f, 0);
                            mainTitlePageInit();
                        }
                    } else {
                        func_overlay_58_03A00F5C_1F7920C(var_a0, var_s1, &playChoice[var_s6], 0);
                    }
                    break;
                case 2:
                    if ((var_a1 != 0) && ((s32)numberOfPlayers >= 2)) {
                        var_s1_2 = playStatus;
                        do {
                            temp_a1 = *var_s1_2;
                            var_s1_2 += 1;
                            if (temp_a1 == 1) {
                                var_a1 = 0;
                            }
                        } while ((u32)var_s1_2 < (u32)playChoice);
                        if (var_a1 != 0) {
                            okayed = 1;
                            amTuneSetFade(0.5f, 0);
                            var_s4 = 0;
                            for (idx = 0; idx < 4; idx++) {
                                if (playStatus[idx] != 0) {
                                    temp_s2 = &playChoice[idx];
                                    temp_a2_2 = *temp_s2;
                                    if ((temp_a2_2 != 1) && (temp_a2_2 != 0)) {
                                        temp_s0 = multiCharacter + (var_s5_2 * 0x76);
                                        mainSetDefaultCharacter(temp_s0, 0);
                                        temp_v0_4 = D_overlay_58_03A01050 + (playChoice[idx] * 8);
                                        temp_s0[5] = (u8)((temp_v0_4[1] & 0x1F) | (temp_s0[5] & 0xE0));
                                        multiCharacterType[var_s5_2] = temp_v0_4[0];
                                    }
                                    var_s5_2 += 1;
                                }
                            }
                            var_s5_2 = 0;
                            joyCreateMap(playStatus);
                            mainChangeLevel(0, 0, 0, 8, 1, 0);
                        }
                    } else if (temp_a2 != 0) {
                        temp_v0_5 = (u8 *)&playChoice[var_s6];
                        if (*temp_v0_5 == 0) {
                            *temp_v0_5 = 1;
                            sp78 = 1;
                        }
                        playStatus[var_s6] = 1;
                    }
                    break;
                }
                found = 0;
                for (idx = 0; idx < 4; idx++) {
                    temp_v1_2 = D_overlay_58_03A01250[idx];
                    temp_v0_6 = *(Object **)((u8 *)temp_v1_2 + 0x68);
                    var_a0_2 = NULL;
                    if ((temp_v0_6 != NULL) && (var_s6 == *(s16 *)((u8 *)temp_v0_6 + 0x12))) {
                        var_a0_2 = temp_v1_2;
                        found = 1;
                    }
                    if (var_a0_2 != NULL) {
                        temp_v1_3 = frontJoyDx[var_s6];
                        temp_a1 = playStatus[var_s6];
                        temp_a2_2 = playChoice[var_s6];
                        temp_v0_7 = frontJoyPressed[var_s6 * 4];
                        var_a3 = 0;
                        if ((temp_v1_3 < 0) || ((temp_v0_7 & 0x20) != 0)) {
                            var_a3 = 1;
                        } else if ((temp_v1_3 > 0) || ((temp_v0_7 & 0x10) != 0) || (sp78 != 0)) {
                            var_a3 = 2;
                        }
                        if (temp_a1 == 2) {
                            var_a3 = 0;
                        }
                        if (temp_a2_2 == 0) {
                            multiCharArmSetStatus(var_a0_2, temp_a1, multiCharacterType[var_s6], var_a3, 1);
                        } else {
                            multiCharArmSetStatus(var_a0_2, temp_a1, (u8)temp_a2_2, var_a3, 0);
                        }
                    }
                    if (found) {
                        break;
                    }
                }
                var_s6 += 1;
            } while (var_s6 != 4);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o58/overlay_58/frontMultiSelect.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_58_03A00F5C_1F7920C(s32 arg0, s32 arg1, s8 *arg2, s32 arg3) {
    s32 var_v1;
    s8 var_v0;

    var_v0 = *arg2;
    var_v1 = 0;
    if (arg1 != 0) {
        do {
            var_v0 += 1;
            if (var_v0 >= 0x13) {
                var_v0 = 1;
            } else if (*(u32 *)(D_overlay_58_03A01050 + (var_v0 * 8) + 4) & *(u32 *)((u8 *)&globalflags + 0x64)) {
                var_v1 = 1;
            }
        } while (var_v1 == 0);
    } else if (arg0 != 0) {
        do {
            var_v0 -= 1;
            if (var_v0 < 2) {
                var_v0 = 0x13;
            } else if (*(u32 *)(D_overlay_58_03A01050 + (var_v0 * 8) + 4) & *(u32 *)((u8 *)&globalflags + 0x64)) {
                var_v1 = 1;
            }
        } while (var_v1 == 0);
    }
    *arg2 = var_v0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o58/overlay_58/func_overlay_58_03A00F5C_1F7920C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontCleanupMultiSelect(void) {
    mmFree(D_overlay_58_03A011B8);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o58/overlay_58/frontCleanupMultiSelect.s")
#endif
