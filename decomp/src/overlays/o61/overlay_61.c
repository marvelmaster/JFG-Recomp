#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
f32 Sinf(s32 arg0);
void *camGetListPtr(void);
s32 camGetNo(void);
void camSetMode(s32 arg0);
void camSetNo(s32 arg0);
void camStandardOrtho();
void camCopyOrthoMatrix();
void camDo2DSprite();
void freeFrontEndList(void *arg0);
void loadFrontEndList(void *arg0);
void setupFrontEndList(void *arg0);
void instInitHealthMeter(void);
void instFreeHealthMeter(void);
void instInitMsgQueues(void);
void texFreeTexture(s32 arg0);
void amSndPlay(u16 soundID, void *handlePtr);
void amSndStop(s32 arg0);
void amTuneSetFade();
void fontBackground();
void fontColour();
void fontPrintXY();
void fontUseFont();
void fontWindowAddStringXY();
void fontWindowColour();
void fontWindowDraw();
void fontWindowFlushStrings();
void fontWindowFontBackground();
void fontWindowFontColour();
void fontWindowSize();
void fontWindowUseFont();
void frontDrawObj();
void frontDrawRectangle();
void frontFlashScreen();
s32 frontGet2PlayerSplit(void);
void frontPlayerScreenLimits();
void frontPlayerTarget();
void frontPrintNum(u16 num, s32 x, s32 y, s32 a, s32 b, s32 c, s32 d);
void instDrawHealth();
void instGetPos();
void instMsgQueueTick();
void *instGetBarWidth(void);
void *instGetBarY(void);
void instSpriteToScreenCoord();
void mainChangeCameras();
void mainFrontInit();
void *mainGetGameCharacter();
void mainPauseDisable();
void mainSetPauseMode();
s32 mainGetPauseMode(void);
void rcpTileWriteX(Gfx **dl, s32 tex, f32 x, f32 y, f32 sx, f32 sy, s32 a, s32 b);
void matrixRoll(s16 arg0, void *mtx);
void matrixTranslate(f32 x, f32 y, f32 z, void *mtx);
void mathMtxF2L(void *src, s32 dst);
void updateColourCycle();
void texDPTextureX();
void sortByKills(void);
void sortPlayers(s32 arg0);
void func_overlay_61_03D01218_1F7CA68(void *arg0, s32 arg1);
void func_overlay_61_03D019E0_1F7D230(void **arg0, s32 arg1);
void func_overlay_61_03D01F14_1F7D764(void *arg0, void **arg1, s32 arg2);
s32 func_overlay_61_03D023B8_1F7DC08(s32 arg0, s32 arg1, s32 arg2);
void frontEndDeathMatch(s32 arg0, void **arg1, s32 arg3);
extern u8 D_overlay_61_03D03450[];
extern u8 D_overlay_61_03D034A0[];
extern TextureHeader *D_overlay_61_03D03528;
extern TextureHeader *D_overlay_61_03D03540;
extern TextureHeader *D_overlay_61_03D03558;
extern TextureHeader *D_overlay_61_03D03570;
extern u8 D_overlay_61_03D031F0[];
extern u8 D_overlay_61_03D0360A[];
extern u8 D_overlay_61_03D036BA[];
extern u8 D_overlay_61_03D03600[];
extern u8 D_overlay_61_03D036B0[];
extern unkResetColourCycle D_overlay_61_03D03760;
extern unkResetColourCycle D_overlay_61_03D03770;
extern f32 D_overlay_61_03D03780;
extern u8 D_overlay_61_03D03788[];
extern s32 D_overlay_61_03D037C8;
extern u32 D_overlay_61_03D03584[];
extern u32 D_overlay_61_03D03594[];
extern u32 D_overlay_61_03D035A4[];
extern u32 D_overlay_61_03D035B8[];
extern u8 D_overlay_61_03D035E0[];
extern u8 D_overlay_61_03D035E8[];
extern s16 D_overlay_61_03D03418;
extern s32 D_overlay_61_03D0341C;
extern f32 D_overlay_61_03D035EC;
extern f32 D_overlay_61_03D035F0;
extern u8 currentobjects[];
extern s32 currentGameTime;
extern u8 numberOfPlayers;
extern u8 radarMode;
extern u8 multiFinished;
extern u16 multiGameTarget;
extern s32 multiGameTime;
extern u8 multiGameType;
extern u8 multiPlayer[];
extern u32 orderedPlayers[];
extern u8 msgQueues[];
extern u32 frontJoyPressed[];
extern u16 gameoverFade[];
extern s32 D_800FF4BC;
extern void *D_800FF4B4;
extern void *D_800FF4B8;
extern s16 D_800FF786;
extern f32 D_800FF78C;
extern f32 D_800FF790;
extern void *front_text;
extern Gfx *frontgfx;
extern s32 frontmtx;
extern void *frontvtx;
extern void *frontpol;
extern u8 numberOfCameras;
extern s32 D_800FF408;
extern void *D_800FF4C0;
extern void *D_800FF4C4;
extern u8 D_800FED60[];
extern u8 D_83D03188[];
extern u8 D_83D03420[];
extern u8 D_83D031A8[];
extern u8 D_83D031D0[];
extern u8 D_83D032F0[];
extern u8 D_83D03370[];
extern u8 D_83D033D0[];
extern u8 D_83D033F0[];
extern u8 D_83D03430[];
extern u8 D_83D03440[];
extern u8 D_83D036B0[];

/* helper: append one display-list command */
static void gfxPut(u32 w0, u32 w1) {
    frontgfx->words.w0 = w0;
    frontgfx->words.w1 = w1;
    frontgfx++;
}
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontInitMultiInstruments(void) {
    s32 i;
    u8 *p;
    f32 sinA, cosA, sinN, cosN;
    s32 angle;

    loadFrontEndList(D_overlay_61_03D03450);
    setupFrontEndList(D_overlay_61_03D034A0);
    *(f32 *)(currentobjects + 8) = *(f32 *)(currentobjects + 8) * 0.75f;

    for (i = 0; i < 16; i++) {
        angle = i * 0x1000;
        sinA = Sinf(angle);
        cosA = Cosf(angle);
        sinN = Sinf(angle + 0x1000);
        cosN = Cosf(angle + 0x1000);

        /* D_overlay_61_03D0360A: 10-byte entries */
        p = D_overlay_61_03D0360A + i * 0xA;
        *(s16 *)(p + 4) = 0;
        *(s16 *)(p + 0) = (s16)(s32)(17.0f * sinA);
        *(s16 *)(p + 2) = (s16)(s32)(17.0f * cosA);

        /* D_overlay_61_03D036BA: 10-byte entries */
        p = D_overlay_61_03D036BA + i * 0xA;
        *(s16 *)(p + 4) = 0;
        p[6] = 0xFF;
        p[7] = 0xFF;
        p[8] = 0xFF;
        p[9] = 0xFF;
        *(s16 *)(p + 0) = (s16)(s32)(15.0f * sinA);
        *(s16 *)(p + 2) = (s16)(s32)(15.0f * cosA);

        /* D_overlay_61_03D031F0: 16-byte entries */
        p = D_overlay_61_03D031F0 + i * 0x10;
        *(s16 *)(p + 4) = 0x220;
        *(s16 *)(p + 6) = 0x220;
        *(s16 *)(p + 8) = (s16)(s32)((512.0f * sinA) + 544.0f);
        *(s16 *)(p + 0xA) = (s16)(s32)((512.0f * cosA) + 544.0f);
        *(s16 *)(p + 0xC) = (s16)(s32)((sinN * 512.0f) + 544.0f);
        *(s16 *)(p + 0xE) = (s16)(s32)((cosN * 512.0f) + 544.0f);
    }

    /* D_overlay_61_03D03600 and D_overlay_61_03D036B0 header fields */
    *(s16 *)(D_overlay_61_03D03600 + 0) = 0;
    *(s16 *)(D_overlay_61_03D03600 + 2) = 0;
    *(s16 *)(D_overlay_61_03D03600 + 4) = 0;
    *(s16 *)(D_overlay_61_03D036B0 + 0) = 0;
    *(s16 *)(D_overlay_61_03D036B0 + 2) = 0;
    *(s16 *)(D_overlay_61_03D036B0 + 4) = 0;
    D_overlay_61_03D036B0[6] = 0xFF;
    D_overlay_61_03D036B0[7] = 0xFF;
    D_overlay_61_03D036B0[8] = 0xFF;
    D_overlay_61_03D036B0[9] = 0xFF;

    /* 4 entries of 0x10 bytes, clear the flag bytes */
    for (i = 0; i < 4; i++) {
        p = D_overlay_61_03D03788 + i * 0x10;
        *(s16 *)(p + 0) = 0;
        *(s16 *)(p + 4) = 0;
        *(s16 *)(p + 8) = 0;
        *(s16 *)(p + 0xC) = 0;
    }

    instInitHealthMeter();
    initColourCycle(&D_overlay_61_03D03760, 0x29);
    initColourCycle(&D_overlay_61_03D03770, 0x2A);
    D_overlay_61_03D03780 = 0.0f;
    instInitMsgQueues();
    D_overlay_61_03D03528 = texLoadTexture(0x26A);
    D_overlay_61_03D03540 = texLoadTexture(0x26B);
    D_overlay_61_03D03558 = texLoadTexture(0x26C);
    D_overlay_61_03D03570 = texLoadTexture(0x26D);
    D_overlay_61_03D037C8 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o61/overlay_61/frontInitMultiInstruments.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontCleanupMultiInstruments(void) {
    freeFrontEndList(D_overlay_61_03D03450);
    instFreeHealthMeter();
    texFreeTexture((s32)D_overlay_61_03D03528);
    texFreeTexture((s32)D_overlay_61_03D03540);
    texFreeTexture((s32)D_overlay_61_03D03558);
    texFreeTexture((s32)D_overlay_61_03D03570);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o61/overlay_61/frontCleanupMultiInstruments.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
#define MP_PLAYER(i) (multiPlayer + (i) * 0xA0)

void frontDeathMatchScores(s32 arg0, void **arg1, s32 arg2) {
    s32 sp84 = 0;
    s32 sp90, sp94, sp8C;
    s32 sp7C, sp78;
    s32 var_a2 = multiFinished;
    s32 var_a1 = 0;
    s32 var_a1_2 = 0;
    s32 i, k;
    s32 spA0, sp9C, spC0;
    s32 spB0, spAC, spA8, spA4;
    s32 spB8, spB4;
    s32 sp48;
    s32 temp_t6, temp_t4;
    void *temp_s0, *temp_s2, *temp_s1, *sp6C;
    u16 *temp_s0_2;
    u16 temp_t5;
    s32 var_v0_2;
    s32 temp_a2;
    u8 *pl;

    func_overlay_61_03D019E0_1F7D230(arg1, arg2);
    sp90 = viGetVideoMode();
    viGetCurrentSize(&sp7C, &sp78);
    sp94 = camGetMode();
    sp8C = camGetNo();
    camSetMode(0);
    camSetNo(0);
    camSetScissor(&frontgfx);
    camStandardOrtho(&frontgfx, &frontmtx);
    fontBackground(0, 0, 0, 0);

    if (var_a2 == 0) {
        temp_t6 = multiGameType & 0x30;
        if (temp_t6 != 0x10) {
            var_a1 = 0;
            if (temp_t6 != 0x30) {
                /* count players at or over the target */
                for (i = 0; i < arg0; i++) {
                    if (*(s16 *)(MP_PLAYER(i) + 0x10) >= (s32)multiGameTarget) {
                        var_a1_2 += 1;
                    }
                }
                if (var_a1_2 != 0) {
                    for (i = 0; i < arg0; i++) {
                        *(u8 *)(MP_PLAYER(i) + 0x15) = 1;
                    }
                    sortByKills();
                    frontEndDeathMatch(arg0, arg1, 0); /* a3 not set by caller */
                }
            } else {
                for (i = 0; i < arg0; i++) {
                    if (*(u8 *)(MP_PLAYER(i) + 0x13) != 0) {
                        var_a1 += 1;
                    }
                }
                if (arg0 != 0) {
                    var_a2 = 0x57E40;
                    for (i = 0; i < arg0; i++) {
                        pl = MP_PLAYER(i);
                        if (pl[0x13] == 0) {
                            if (pl[0x15] == 0) {
                                *(s8 *)(pl + 0x14) = (s8)(var_a1 + 1);
                                pl[0x15] = 1;
                            }
                        } else {
                            temp_a2 = *(u32 *)(pl + 0x90) + arg2;
                            *(u32 *)(pl + 0x90) = temp_a2;
                            if (temp_a2 >= 0x57E40) {
                                *(u32 *)(pl + 0x90) = 0x57E3F;
                            }
                            *(s8 *)(pl + 0x14) = 1;
                        }
                    }
                }
                if (var_a1 < 2) {
                    sortPlayers(4);
                    frontEndDeathMatch(arg0, arg1, 0);
                }
            }
        } else if (func_overlay_61_03D023B8_1F7DC08(arg0, multiGameTime, arg2) != 0) {
            sortByKills();
            frontEndDeathMatch(arg0, arg1, 0);
        }
    }

    if (var_a2 != 0) {
        mainPauseDisable(0xA);
    }
    if (arg0 > 0) {
        for (i = 0; i < arg0; i++) {
            temp_s2 = arg1[i];
            if (temp_s2 != NULL) {
                temp_s0 = *(void **)((u8 *)temp_s2 + 0x68);
                sp48 = sp90 & 1;
                temp_s1 = MP_PLAYER(i);
                instMsgQueueTick(temp_s0, arg2);
                func_overlay_61_03D01218_1F7CA68(temp_s0, arg2);
                sp6C = mainGetGameCharacter(*(s8 *)temp_s0, *((s8 *)temp_s0 + 1));
                if ((sp48 == 0) && (numberOfPlayers == 2)) {
                    frontGet2PlayerSplit();
                }
                fontUseFont(2);
                fontColour(0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
                camStandardOrtho(&frontgfx, &frontmtx);
                texDPInit(&frontgfx);
                D_800FF786 = *(s16 *)((u8 *)sp6C + 0x70) + 0xA;
                temp_t4 = (u32)(*(u32 *)((u8 *)temp_s0 + 0x540) * 4) >> 0x1E;
                if (temp_t4 & 3) {
                    sp84 = 1;
                }
                instGetPos(1, *(s8 *)temp_s0, &spB8, &spB4);
                D_800FF78C = (f32)spB8;
                D_800FF790 = (f32)spB4;
                frontDrawObj(0);
                frontPrintNum(*(u16 *)((u8 *)sp6C + *(s16 *)((u8 *)sp6C + 0x70) * 2 + 0x14), spB8 + 0xC, spB4 - 9, 9, 3,
                              0xFFFF00FF, 0xFFFF0080);
                instDrawHealth(temp_s2, (*(s16 *)(*(u8 **)((u8 *)temp_s2 + 0x4C) + 6)) >> 8, 0xC, arg2);
                if ((multiGameType & 0x30) == 0x30) {
                    instGetPos(0, *(s8 *)temp_s0, &spB8, &spB4);
                    frontPrintNum(*(u8 *)((u8 *)temp_s1 + 0x13), spB8 + 5, spB4 + 3, 9, 1, 0xFFFF00FF, 0xFFFF0080);
                }
                func_overlay_61_03D01F14_1F7D764(temp_s2, arg1, arg2);
                if ((((s32)multiFinished > 0) && ((s32)multiFinished < 0xA)) || (*(u8 *)((u8 *)temp_s1 + 0x15) != 0)) {
                    temp_s0_2 = (u16 *)((u8 *)gameoverFade + i * 2);
                    temp_t5 = *temp_s0_2 + (arg2 * 2);
                    var_v0_2 = temp_t5 & 0xFFFF;
                    *temp_s0_2 = temp_t5;
                    if (var_v0_2 >= 0x100) {
                        *temp_s0_2 = 0xFF;
                        var_v0_2 = 0xFF;
                    }
                    temp_a2 = 0xFF - var_v0_2;
                    frontFlashScreen(&frontgfx, i,
                                     (temp_a2 << 0x18) | (temp_a2 << 0x10) | (temp_a2 << 8) |
                                         D_overlay_61_03D035A4[*(u8 *)((u8 *)temp_s1 + 0x14)]);
                    frontPlayerScreenLimits(i, &spB0, &spAC, &spA8, &spA4);
                    spA0 = ((spB0 + spA8) >> 1) + 0xA;
                    sp9C = ((spAC + spA4) >> 1) - 0xD;
                    fontUseFont(2);
                    fontColour(0, 0, 0, 0xFF, (s32)*temp_s0_2);
                    fontPrintXY(&frontgfx, spA0, sp9C, D_overlay_61_03D03594[*(u8 *)((u8 *)temp_s1 + 0x14)], 0xC);
                    fontColour(0, 0xFF, 0x80, 0xFF, (s32)*temp_s0_2);
                    fontPrintXY(&frontgfx, spA0 - 1, sp9C - 1, D_overlay_61_03D03594[*(u8 *)((u8 *)temp_s1 + 0x14)], 0xC);
                    var_v0_2 = *temp_s0_2;
                    if (var_v0_2 == 0xFF) {
                        var_v0_2 = 0xFE;
                    }
                    spC0 = var_v0_2;
                    rcpTileWriteX(&frontgfx, D_overlay_61_03D03584[*(u8 *)((u8 *)temp_s1 + 0x14)], (f32)(spA0 - 0x14),
                                  (f32)(sp9C + 7), 1.5f, 1.5f, var_v0_2, 1);
                    rcpTileWriteX(&frontgfx, D_overlay_61_03D03584[*(u8 *)((u8 *)temp_s1 + 0x14)], (f32)(spA0 - 0x13),
                                  (f32)(sp9C + 6), 1.5f, 1.5f, var_v0_2 | 0xFF8000, 1);
                }
            }
        }
    }

    if (sp84 != 0) {
        if (D_overlay_61_03D037C8 != 0) {
            amSndStop(D_overlay_61_03D037C8);
        }
        amSndPlay(0x8B, &D_overlay_61_03D037C8);
    }

    switch (multiFinished) {
    case 1:
        var_a1_2 = 0;
        for (i = 0; i < arg0; i++) {
            if ((s32)((u16 *)gameoverFade)[i] >= 0xFF) {
                var_a1_2 += 1;
            }
        }
        if (var_a1_2 == arg0) {
            multiFinished = 2;
            mainSetPauseMode(2, var_a1_2);
        }
        break;
    case 2:
        if ((arg0 > 0) && (multiFinished == 2)) {
            for (k = 0; (k < arg0) && (multiFinished == 2); k++) {
                if (frontJoyPressed[k] & 0x9000) {
                    mainChangeCameras(1);
                    temp_t6 = multiGameType & 0x30;
                    if (temp_t6 != 0x10) {
                        temp_a2 = 0x12;
                        if (temp_t6 != 0x20) {
                            temp_a2 = 0x14;
                        }
                    } else {
                        temp_a2 = 0x13;
                    }
                    mainFrontInit(temp_a2, 0, 0);
                    multiFinished = 3;
                }
            }
        }
        break;
    }

    camSetMode(sp94);
    camSetNo(sp8C);
    for (i = 0; i < arg0; i++) {
        temp_s2 = arg1[i];
        if (temp_s2 != NULL) {
            temp_s0 = *(void **)((u8 *)temp_s2 + 0x68);
            temp_t4 = *(u8 *)((u8 *)temp_s0 + 0x568);
            if ((temp_t4 == 5) || (temp_t4 == 0xB)) {
                frontPlayerTarget(temp_s2, temp_s0, arg2);
            }
        }
    }
    if (multiFinished == 3) {
        camSetMode(0);
        camSetNo(0);
        camSetScissor(&frontgfx);
        camSetMode(sp94);
        camSetNo(sp8C);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o61/overlay_61/frontDeathMatchScores.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void sortByKills(void) {
    s32 n = numberOfPlayers;
    s32 i, idx, swapped, rank;
    u8 *a, *b, *cur, *last;

    for (i = 0; i < n; i++) {
        orderedPlayers[i] = (u32)(multiPlayer + i * 0xA0);
    }
    do {
        swapped = 1;
        /* asm: idx runs n-2 down to 1 */
        for (idx = n - 2; idx > 0; idx--) {
            a = (u8 *)orderedPlayers[idx];
            b = (u8 *)orderedPlayers[idx + 1];
            if ((*(s16 *)(a + 0x10) < *(s16 *)(b + 0x10)) ||
                ((*(s16 *)(a + 0x10) == *(s16 *)(b + 0x10)) &&
                 ((s32)*(s16 *)(b + *(s16 *)(b + 0x8C) * 2) < (s32)*(s16 *)(a + *(s16 *)(a + 0x8C) * 2)))) {
                orderedPlayers[idx] = (u32)b;
                orderedPlayers[idx + 1] = (u32)a;
                swapped = 0;
            }
        }
    } while (!swapped);

    rank = 0;
    last = NULL;
    for (i = 0; i < n; i++) {
        cur = (u8 *)orderedPlayers[i];
        if (last == NULL ||
            *(s16 *)(cur + 0x10) != *(s16 *)(last + 0x10) ||
            (s32)*(s16 *)(last + *(s16 *)(last + 0x8C) * 2) != (s32)*(s16 *)(cur + *(s16 *)(cur + 0x8C) * 2)) {
            rank = i + 1;
        }
        *(s8 *)(cur + 0x14) = (s8)rank;
        last = cur;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o61/overlay_61/sortByKills.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void sortPlayers(s32 arg0) {
    s32 n = numberOfPlayers;
    s32 i, idx, swapped;
    u8 *a, *b;

    for (i = 0; i < n; i++) {
        orderedPlayers[i] = (u32)(multiPlayer + i * 0xA0);
    }
    do {
        swapped = 1;
        for (idx = 0; idx < n - 1; idx++) {
            a = (u8 *)orderedPlayers[idx];
            b = (u8 *)orderedPlayers[idx + 1];
            if ((arg0 == 0 && *(s16 *)(a + 0x10) < *(s16 *)(b + 0x10)) ||
                (arg0 == 1 && *(u32 *)(a + 0x90) < *(u32 *)(b + 0x90)) ||
                (arg0 == 2 && *(u32 *)(b + 0x90) < *(u32 *)(a + 0x90)) ||
                (arg0 == 3 && *(s32 *)(a + 0x9C) < *(s32 *)(b + 0x9C)) ||
                (arg0 == 4 && *(s8 *)(b + 0x14) < *(s8 *)(a + 0x14))) {
                orderedPlayers[idx] = (u32)b;
                orderedPlayers[idx + 1] = (u32)a;
                swapped = 0;
            }
        }
    } while (!swapped);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o61/overlay_61/sortPlayers.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_61_03D01218_1F7CA68(void *arg0, s32 arg1) {
    u8 sp148[0x40];
    u8 *barY = (u8 *)instGetBarY();
    s16 *barW = (s16 *)instGetBarWidth();
    s32 player = *(s8 *)arg0;
    u8 *msg = msgQueues + player * 0x50;
    s32 sp144 = 0, sp140 = 0, sp138, sp134, sp130, sp120, sp13C;
    s32 var_t0, var_v1_2, temp_t6, temp_s0, temp_t9, temp_a2;
    s32 var_t6 = 0;
    s32 sp34 = 0;
    s32 sp38 = 0, sp30 = 0;
    s32 sp28 = 0, sp2C = 0;
    s16 sp68 = 0, sp6A = 0, sp6C = 0;
    f32 sp70 = 0.5f, sp74 = 0.0f, sp78 = 0.0f, sp7C = 0.0f, sp90 = 0.0f;
    u8 *str;
    s32 temp_v1_4;
    s32 temp_v1_3;
    s32 temp_v1_2;
    s32 temp_v0_2;

    if (msg[0] != 0 || barY[player] != 0x4B) {
        camCopyOrthoMatrix(sp148, msg);
        switch (numberOfCameras) {
        case 2:
            if (!(viGetVideoMode() & 1)) {
                if (frontGet2PlayerSplit() != 0) {
                    goto block_9;
                }
                sp144 = 0;
                temp_v1_2 = *(s8 *)arg0;
                if (temp_v1_2 == 0) {
                    var_t6 = barY[temp_v1_2] + 0x3C;
                    goto block_24;
                }
                sp140 = barY[temp_v1_2] - 0x3C;
            } else {
block_9:
                if (*(s8 *)arg0 == 0) {
case_3: ;
                }
                /* fall through into case 4 code */
                temp_v1_3 = *(s8 *)arg0;
                if ((temp_v1_3 == 0) || (temp_v1_3 == 2)) {
                    sp144 = -0x5E;
                } else {
                    sp144 = 0x42;
                }
                if ((temp_v1_3 == 0) || (temp_v1_3 == 1)) {
                    sp140 = barY[temp_v1_3] + 0x3C;
                } else {
                    var_t6 = barY[temp_v1_3] - 0x3C;
block_24:
                    sp140 = var_t6;
                }
            }
            break;
        case 3:
            goto case_3;
        case 4:
            temp_v1_3 = *(s8 *)arg0;
            if ((temp_v1_3 == 0) || (temp_v1_3 == 2)) {
                sp144 = -0x5E;
            } else {
                sp144 = 0x42;
            }
            if ((temp_v1_3 == 0) || (temp_v1_3 == 1)) {
                sp140 = barY[temp_v1_3] + 0x3C;
            } else {
                var_t6 = barY[temp_v1_3] - 0x3C;
                sp140 = var_t6;
            }
            break;
        }
        str = msg + 0x12;
        temp_v1_4 = *(s16 *)(msg + 2);
        if (temp_v1_4 != -1) {
            if (temp_v1_4 == 0x9F) {
                str = msg + 0x12;
                sprintf((char *)str, (char *)D_overlay_61_03D035E0, *(s32 *)((u8 *)front_text + 0x27C),
                        *(s32 *)(D_800FED60 + player * 0xA0));
            } else {
                str = msg + 0x12;
                sprintf((char *)str, (char *)D_overlay_61_03D035E8, *(s32 *)((u8 *)front_text + temp_v1_4 * 4));
            }
        } else {
            str = msg + 0x12;
        }
        sp34 = (s32)str;
        camSetMode(numberOfCameras - 1);
        camSetNo(player);
        camSetScissor(&frontgfx);
        camStandardOrtho(&frontgfx, &frontmtx);
        var_t0 = barW[player];
        if (var_t0 >= 2) {
            gfxPut((((((u32)frontvtx + 0x80000000) & 6) | 0x20) & 0xFF) << 0x10 | 0x04000000 | 0x30,
                   (u32)frontvtx + 0x80000000);
            temp_v0_2 = sp140 + 6;
            *(s16 *)((u8 *)frontvtx + 2) = temp_v0_2;
            *(s16 *)((u8 *)frontvtx + 0) = (s16)(sp144 - (barW[player] >> 1));
            temp_a2 = sp140 - 7;
            *(s16 *)((u8 *)frontvtx + 0xC) = temp_v0_2;
            *(s16 *)((u8 *)frontvtx + 0xA) = (s16)((barW[player] >> 1) + sp144);
            *(s16 *)((u8 *)frontvtx + 0x16) = temp_a2;
            *(s16 *)((u8 *)frontvtx + 0x14) = (s16)(sp144 - (barW[player] >> 1));
            *(s16 *)((u8 *)frontvtx + 0x20) = temp_a2;
            *(s16 *)((u8 *)frontvtx + 0x1E) = (s16)((barW[player] >> 1) + sp144);
            {
                s32 k;
                for (k = 0; k < 4; k++) {
                    *(s16 *)((u8 *)frontvtx + 4) = 0;
                    *((u8 *)frontvtx + 6) = 0xFF;
                    *((u8 *)frontvtx + 7) = 0xFF;
                    *((u8 *)frontvtx + 8) = 0xFF;
                    *((u8 *)frontvtx + 9) = 0xFF;
                    frontvtx = (u8 *)frontvtx + 0xA;
                }
            }
            texDPTextureX(&frontgfx, 0, 0, 0);
            gfxPut(0xE7000000, 0);
            gfxPut(0xFB000000, 0x283260);
            gfxPut(0xFA000000, 0x1E5A00);
            gfxPut(0x07020010, (u32)D_83D03420);
            gfxPut(0x05110020, (u32)D_83D03188);
            var_t0 = barW[player];
        }
        sp74 = (f32)((var_t0 >> 1) + sp144 + 2);
        sp78 = (f32)sp140;
        sp6C = 0;
        sp6A = 0;
        sp68 = 0;
        sp7C = 0.0f;
        sp90 = 0.0f;
        sp70 = 0.5f;
        texDPInit(&frontgfx);
        gfxPut(0xFA000000, 0xFFFFFFFF);
        camDo2DSprite(&frontgfx, &frontmtx, &frontvtx, &sp68, D_800FF408, 0, 0xFF);
        sp68 = -0x8000;
        sp74 = (f32)((sp144 - (barW[player] >> 1)) - 2);
        camDo2DSprite(&frontgfx, &frontmtx, &frontvtx, &sp68, D_800FF408, 0, 0xFF);
        temp_t9 = sp144 - (barW[player] >> 1);
        sp13C = temp_t9;
        sp138 = barW[player] + temp_t9;
        sp134 = sp140 + 5;
        sp130 = sp140 - 6;
        instSpriteToScreenCoord(&sp13C, &sp134);
        instSpriteToScreenCoord(&sp138, &sp130);
        fontWindowUseFont(1, 2);
        fontWindowFlushStrings(1);
        fontWindowSize(1, sp13C, sp134, sp138, sp130);
        fontWindowColour(1, 0, 0, 0, 0);
        fontWindowFontBackground(1, 0, 0, 0, 0);
        var_v1_2 = *(s16 *)(msg + 0x4E);
        if (var_v1_2 < fontStringWidth((char *)str, 2, 1)) {
            temp_t6 = var_v1_2 + arg1;
            *(s16 *)(msg + 0x4E) = temp_t6;
            var_v1_2 = temp_t6;
        }
        sp120 = ((sp138 - sp13C) - var_v1_2) - 5;
        fontWindowFlushStrings(1);
        fontWindowFontColour(1, 0, 0xFF, 0xFF, 0xFF, 0xFF);
        fontWindowAddStringXY(1, sp120, 1, (s8 *)str, 1, 0);
        fontWindowFontColour(1, 0, 0, 0x80, 0xFF, 0xFF);
        fontWindowAddStringXY(1, sp120 + 1, 2, (s8 *)str, 1, 0);
        fontWindowDraw(&frontgfx, &frontmtx, &frontvtx, 1);
        fontWindowFlushStrings(1);
        camSetMode(0);
        camSetNo(0);
        camSetScissor(&frontgfx);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o61/overlay_61/func_overlay_61_03D01218_1F7CA68.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_61_03D019E0_1F7D230(void **arg0, s32 arg1) {
    void *list = camGetListPtr();
    s16 temp_v1 = D_overlay_61_03D03418;
    s32 spC0, spBC;
    s32 spC8 = 0; /* asm: uninitialised stack slot, carried across the outer loop */
    s32 n = numberOfPlayers;
    s32 i, j;
    void *p, *q;
    u8 *pe, *qe;
    u8 *entry;
    f32 dx, dy, dz, dist, f2, ang_f, c, s, rx, ry;
    s32 angle, var_s6, var_s7, var_s4;
    s32 ang2;
    s32 temp_s4;

    D_overlay_61_03D03418 = temp_v1 - (arg1 << 0xA);
    D_overlay_61_03D0341C = (s32)temp_v1;
    if ((D_overlay_61_03D03418 >= 0x4E21) && (D_overlay_61_03D0341C < 0x4E20)) {
        D_overlay_61_03D0341C += 0x10000;
    }
    spC0 = (s32)D_overlay_61_03D03418;
    if (D_overlay_61_03D03418 < 0) {
        spC0 = -(s32)D_overlay_61_03D03418;
    } else {
        spC0 = 0x10000 - spC0;
    }
    spBC = D_overlay_61_03D0341C;
    if (D_overlay_61_03D0341C < 0) {
        spBC = -D_overlay_61_03D0341C;
    } else {
        spBC = 0x10000 - spBC;
    }
    if (spC0 < spBC) {
        spBC += 0xFFFF0000;
    }
    D_overlay_61_03D03418 += arg1 << 9;

    var_s4 = spC8;
    for (i = 0; i < n; i++) {
        p = arg0[i];
        pe = (u8 *)p;
        for (j = 0; j < n; j++) {
            q = arg0[j];
            qe = (u8 *)q;
            /* entry = D_overlay_61_03D03788[player(p)][j] */
            entry = D_overlay_61_03D03788 + (*(u8 *)(*(u8 **)(pe + 0x68))) * 0x10 + j * 4;

            dx = (*(f32 *)(qe + 0xC) - *(f32 *)(pe + 0xC)) / 100.0f;
            dy = *(f32 *)(qe + 0x10) - *(f32 *)(pe + 0x10);
            dz = (*(f32 *)(qe + 0x14) - *(f32 *)(pe + 0x14)) / 100.0f;
            dist = sqrtf((dx * dx) + (dz * dz));
            f2 = dist;
            if (dist > 15.0f) {
                f2 = 15.0f / dist;
                dx *= f2;
                dz *= f2;
            }
            if (f2 == 0.0f) {
                entry[0] = 0;
                entry[1] = 0;
            } else {
                var_s7 = 0;
                if (dy < -30.0f) {
                    var_s6 = 0;
                } else {
                    var_s6 = 1;
                    if (dy > 30.0f) {
                        var_s6 = 2;
                    }
                }
                rx = -dz;
                angle = 0x8000 - *(s32 *)((u8 *)list + *(u8 *)(*(u8 **)(pe + 0x68)) * 0x4C);
                c = Cosf(angle);
                ry = (Sinf(angle) * rx) + (dx * c);
                c = Cosf(angle);
                ang_f = (rx * c) - (Sinf(angle) * dx);
                if (radarMode != 0) {
                    if (radarMode == 1) {
                        temp_s4 = entry[2];
                        ang2 = Arctanf(ry, ang_f);
                        if (spC0 >= ang2) {
                            if (ang2 >= spBC) {
                                var_s4 = 0xFF;
                                var_s7 = 1;
                            } else {
                                goto block_29;
                            }
                        } else {
block_29:
                            if ((arg1 * 8) < temp_s4) {
                                var_s4 = temp_s4 - (arg1 * 8);
                            } else {
                                var_s4 = 0;
                            }
                        }
                    }
                } else {
                    var_s7 = 1;
                    var_s4 = 0xFF;
                }
                if (var_s7 != 0) {
                    entry[0] = (s8)(s32)ry;
                    entry[1] = (s8)(s32)ang_f;
                    entry[3] = var_s6;
                }
                if ((*(u8 *)(*(u8 **)(qe + 0x68) + 0x10E) != 0) || (*(s16 *)(*(u8 **)(qe + 0x4C) + 6) < 0x100)) {
                    entry[2] = 0;
                } else {
                    entry[2] = (s8)var_s4;
                }
            }
        }
    }
    spC8 = var_s4;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o61/overlay_61/func_overlay_61_03D019E0_1F7D230.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_61_03D01F14_1F7D764(void *arg0, void **arg1, s32 arg2) {
    u8 sp9C[0x40];
    s32 spE8, spE4, spE0, spDC;
    u8 *temp_s5 = *(u8 **)((u8 *)arg0 + 0x68);
    u8 *var_s0;
    s32 var_s1;
    s32 temp_s2;

    instGetPos(3, *temp_s5, &spE8, &spE4);
    camCopyOrthoMatrix(sp9C);
    matrixTranslate((f32)spE8, (f32)spE4, 0.0f, sp9C);
    mathMtxF2L(sp9C, frontmtx);
    gfxPut(0x07070038, ((u32 *)D_800FF4C4)[3] + 0x80000000);
    gfxPut(0x01000040, (u32)frontmtx + 0x80000000);
    frontmtx += 0x40;
    gfxPut(0xE7000000, 0);
    gfxPut(0xFB000000, 0x283260);
    gfxPut(0xFA000000, 0x1E5A00);
    gfxPut(0x07020010, (u32)D_83D03430);
    gfxPut((((((u32)D_83D03370 & 6) | 0x48) & 0xFF) << 0x10) | 0x04000000 | 0x62, (u32)D_83D03370);
    gfxPut(0x05710080, (u32)D_83D032F0);
    camStandardOrtho(&frontgfx, &frontmtx);
    texDPInit(&frontgfx);

    var_s0 = D_overlay_61_03D03788 + (*temp_s5 * 0x10);
    for (var_s1 = 0; var_s1 < numberOfPlayers; var_s1++) {
        if ((var_s1 != *temp_s5) || (var_s0[2] != 0)) {
            temp_s2 = ((u32 *)D_overlay_61_03D035B8)[var_s0[3]] | var_s0[2];
            spE0 = (s8)var_s0[0] + spE8;
            spDC = (s8)var_s0[1] + spE4;
            instSpriteToScreenCoord(&spE0, &spDC);
            frontDrawRectangle(&frontgfx, spE0 - 1, spDC - 1, spE0 + 1, spDC + 1, temp_s2);
        }
        var_s0 += 4;
    }

    if (radarMode == 1) {
        matrixRoll(D_overlay_61_03D03418, sp9C);
        mathMtxF2L(sp9C, frontmtx);
        gfxPut(0x01000040, (u32)frontmtx + 0x80000000);
        frontmtx += 0x40;
        gfxPut(0x07020010, (u32)D_83D03440);
        gfxPut(0xFA000000, 0xFFFFFF);
        gfxPut(0x07070038, ((u32 *)D_800FF4C0)[3] + 0x80000000);
        gfxPut((((((u32)D_83D033F0 & 6) | 0x20) & 0xFF) << 0x10) | 0x04000000 | 0x30, (u32)D_83D033F0);
        gfxPut(0x05110020, (u32)D_83D033D0);
        camStandardOrtho(&frontgfx, &frontmtx);
        texDPInit(&frontgfx);
    }

    spE0 = spE8;
    spDC = spE4;
    instSpriteToScreenCoord(&spE0, &spDC);
    frontDrawRectangle(&frontgfx, spE0 - 1, spDC - 1, spE0 + 1, spDC + 1, 0xFFFF00FF);
    gfxPut(0xFA000000, 0xFFFFFFFF);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o61/overlay_61/func_overlay_61_03D01F14_1F7D764.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_61_03D023B8_1F7DC08(s32 arg0, s32 arg1, s32 arg2) {
    u8 sp8C[0x40];
    s32 spF4, spF0, spE0, spDC;
    f32 sp88, sp84, sp7C, sp78;
    s32 sp34, sp28, sp2C;
    s32 sp38, sp30;
    s32 cnt, rem;
    s32 temp_t0, temp_v0_3, temp_a1;
    s32 var_t8, var_t8_2;
    f32 temp_f2, temp_f4, temp_f0;
    f32 var_f4, var_f4_2, var_f8;
    s32 temp_s1;
    u8 *vtx;
    u8 *pol;

    if (mainGetPauseMode() == 0) {
        currentGameTime += arg2;
    }
    if (currentGameTime >= arg1) {
        currentGameTime = arg1;
        spF4 = 1;
    } else {
        spF4 = 0;
    }
    camCopyOrthoMatrix(sp8C);
    sp7C = 0.0f;
    sp78 = 0.0f;
    if (arg0 == 2) {
        if (!(viGetVideoMode() & 1)) {
            if (frontGet2PlayerSplit() == 0) {
                sp7C = 100.0f;
            } else {
                sp78 = -85.0f;
            }
        } else {
            sp78 = -85.0f;
        }
    }
    matrixTranslate(sp7C, sp78, 0, sp8C);
    mathMtxF2L(sp8C, frontmtx);
    gfxPut(0x01000040, (u32)frontmtx + 0x80000000);
    frontmtx += 0x40;

    spF0 = (s32)(((f32)(arg1 - currentGameTime) * 65536.0f) / (f32)arg1);
    resetColourCycle(&D_overlay_61_03D03760);
    temp_a1 = (spF0 * -0x3C) + 0x3C0000;
    var_t8 = temp_a1 >> 0x10;
    if (temp_a1 < 0) {
        var_t8 = (temp_a1 + 0xFFFF) >> 0x10;
    }
    updateColourCycle(&D_overlay_61_03D03760, var_t8);

    if ((arg1 - currentGameTime) < 0x4B1) {
        updateColourCycle(&D_overlay_61_03D03770, arg2);
        if (arg2 > 0) {
            rem = arg2 & 3;
            cnt = 0;
            if (rem != 0) {
                for (cnt = 0; cnt != rem; cnt++) {
                    D_overlay_61_03D03780 += (1.0f - D_overlay_61_03D03780) * D_overlay_61_03D035EC;
                }
            }
            if ((rem == 0) || (rem != arg2)) {
                for (cnt = rem; cnt != arg2; cnt += 4) {
                    D_overlay_61_03D03780 += (1.0f - D_overlay_61_03D03780) * D_overlay_61_03D035F0;
                    D_overlay_61_03D03780 += (1.0f - D_overlay_61_03D03780) * D_overlay_61_03D035F0;
                    D_overlay_61_03D03780 += (1.0f - D_overlay_61_03D03780) * D_overlay_61_03D035F0;
                    D_overlay_61_03D03780 += (1.0f - D_overlay_61_03D03780) * D_overlay_61_03D035F0;
                }
            }
        }
    }

    temp_f2 = 1.0f - D_overlay_61_03D03780;
    temp_s1 = (s32)(((f32)D_overlay_61_03D03760.unk8 * temp_f2) + (D_overlay_61_03D03780 * (f32)D_overlay_61_03D03770.unk8));
    var_f4 = (f32)D_overlay_61_03D03770.unk9;
    spE0 = (s32)(((f32)D_overlay_61_03D03760.unk9 * temp_f2) + (D_overlay_61_03D03780 * var_f4));
    var_f4_2 = (f32)D_overlay_61_03D03760.unkA;
    var_f8 = (f32)D_overlay_61_03D03770.unkA;
    spDC = (s32)((var_f4_2 * temp_f2) + (D_overlay_61_03D03780 * var_f8));

    texDPTextureX((void **)0x3F800000, &frontgfx, D_800FF4BC, 0x205, 0);
    temp_f4 = 45.0f + (100.0f * D_overlay_61_03D03780);
    var_t8_2 = (s32)temp_f4;
    if (var_t8_2 < 0) {
        var_t8_2 = -1;
    }
    gfxPut(0xFA000000, (s32)((temp_s1 << 0x18) | ((spE0 & 0xFF) << 0x10) | ((spDC & 0xFF) << 8) | (var_t8_2 & 0xFF)));

    temp_t0 = (((((s32)D_83D031A8 & 6) | 0x20) & 0xFF) << 0x10) | 0x04000000 | 0x30;
    sp34 = temp_t0;
    sp38 = (s32)D_83D031A8;
    gfxPut(temp_t0, (u32)D_83D031A8);
    sp30 = (s32)D_83D031D0;
    gfxPut(0x05110020, (u32)D_83D031D0);

    if (spF4 == 0) {
        camCopyOrthoMatrix(sp8C);
        matrixTranslate(sp7C + 1.0f, sp78 + 1.0f, 0, sp8C);
        mathMtxF2L(sp8C, frontmtx);
        gfxPut(0x01000040, (u32)frontmtx + 0x80000000);
        frontmtx += 0x40;
        texDPTextureX(&frontgfx, D_800FF4B4, 5, 0);
        gfxPut(0xFA000000, -0x40);
        gfxPut((((((u32)D_83D036B0 & 6) | 0x88) & 0xFF) << 0x10) | 0x04000000 | 0xB2, (u32)D_83D036B0);

        temp_t0 = spF0 / 4096;
        temp_v0_3 = temp_t0 << 0xC;
        if (temp_t0 != 0) {
            gfxPut((((((temp_t0 - 1) * 0x10) | 1) & 0xFF) << 0x10) | 0x05000000 | ((temp_t0 * 0x10) & 0xFFFF),
                   (u32)D_overlay_61_03D031F0);
        }
        if (spF0 != temp_v0_3) {
            sp28 = temp_v0_3;
            sp2C = temp_t0;
            sp88 = Sinf(spF0);
            temp_f0 = Cosf(spF0);
            sp84 = temp_f0;
            gfxPut(((((((u32)frontvtx + 0x80000000) & 6) | 8) & 0xFF) << 0x10) | 0x04000000 | 0x2212,
                   (u32)frontvtx + 0x80000000);
            vtx = (u8 *)frontvtx;
            *(s16 *)(vtx + 0) = (s16)(s32)(15.0f * sp88);
            *(s16 *)(vtx + 2) = (s16)(s32)(15.0f * temp_f0);
            *(s16 *)(vtx + 4) = 0;
            vtx[6] = 0xFF;
            vtx[7] = 0xFF;
            vtx[8] = 0xFF;
            vtx[9] = 0xFF;
            frontvtx = vtx + 0xA;

            pol = (u8 *)frontpol;
            pol[0] = 0x40;
            pol[1] = 0;
            pol[2] = (s8)(temp_t0 + 1);
            pol[3] = 0x11;
            *(s16 *)(pol + 4) = 0x220;
            *(s16 *)(pol + 6) = 0x220;
            *(s16 *)(pol + 8) = (s16)(s32)((Sinf(sp28) * 512.0f) + 544.0f);
            *(s16 *)(pol + 0xA) = (s16)(s32)((Cosf(sp28) * 512.0f) + 544.0f);
            *(s16 *)(pol + 0xC) = (s16)(s32)((512.0f * sp88) + 544.0f);
            *(s16 *)(pol + 0xE) = (s16)(s32)((512.0f * sp84) + 544.0f);
            gfxPut(0x05010010, (u32)pol + 0x80000000);
            frontpol = pol + 0x10;
        }
    }

    camCopyOrthoMatrix(sp8C);
    matrixTranslate(sp7C, sp78, 0, sp8C);
    mathMtxF2L(sp8C, frontmtx);
    gfxPut(0x01000040, (u32)frontmtx + 0x80000000);
    frontmtx += 0x40;
    gfxPut(0xFA000000, -1);
    texDPTextureX(&frontgfx, D_800FF4B8, 0, 0);
    gfxPut((u32)sp34, (u32)sp38);
    gfxPut(0x05110020, (u32)sp30);
    return spF4;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o61/overlay_61/func_overlay_61_03D023B8_1F7DC08.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
static void frontSetDeathFlag(void *p) {
    if (p != NULL) {
        *(u8 *)(*(u8 **)((u8 *)p + 0x68) + 0x5C8) = 0xF0;
    }
}

void frontEndDeathMatch(s32 arg0, void **arg1, s32 arg3) {
    s32 a0 = arg0;
    s32 a2 = 0;
    s32 a3 = arg3;
    s32 rem;
    s32 i;

    multiFinished = 1;
    if (arg0 > 0) {
        rem = arg0 & 3;
        a3 = rem;
        if (rem != 0) {
            for (a2 = 0; a2 != rem; a2++) {
                frontSetDeathFlag(arg1[a2]);
            }
        }
        if (rem == 0 || rem != arg0) {
            for (i = a2; i < arg0; i += 4) {
                frontSetDeathFlag(arg1[i]);
                frontSetDeathFlag(arg1[i + 1]);
                frontSetDeathFlag(arg1[i + 2]);
                frontSetDeathFlag(arg1[i + 3]);
            }
            a3 = (s32)(arg1 + arg0);
            a0 = (s32)(arg1 + arg0);
        } else {
            a0 = (s32)(arg1 + rem);
        }
    }
    amTuneSetFade(0x40000000, (void **)a0, 0, a2, a3);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o61/overlay_61/frontEndDeathMatch.s")
#endif
