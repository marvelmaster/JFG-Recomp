#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
s32 mainGetPauseMode(void);
void *objGetPlayerNo(s32);
s32 mainGetNextCharacter(void);
s32 levelGetNumber(void);
s32 levelGetWorld(s32);
void mainSetPauseMode(s32, s32, s32, s32 *);
s32 amTuneGetVolume(void);
void amTuneSetFade(f32, s32);
void frontSetMenuFrame(s32, s32);
void amSndPlay(u16, void *);
void pauseSetScreen(s32);
extern u8 D_overlay_19_013010E0[];
extern s32 D_overlay_19_01301188;
extern s32 D_overlay_19_013013B0;
extern s32 D_overlay_19_013013B4;
extern s32 D_overlay_19_013013B8;
extern s32 D_overlay_19_013013BC;
extern s32 D_overlay_19_013013C0;
extern s32 D_overlay_19_013013C4;
extern s32 D_overlay_19_013013DC;
extern s32 D_overlay_19_013013E0;
extern s32 D_overlay_19_013013E4;
extern s32 D_overlay_19_013013E8;
extern s32 D_overlay_19_013013EC;
extern s32 D_overlay_19_013013F0;
extern s32 D_overlay_19_013013F4;
extern s32 D_overlay_19_013013F8;
extern s8 D_overlay_19_013013FC;
extern u8 cooperativeGame;
extern s32 pausePlayer;
extern s32 pausetunevol;
extern s32 D_overlay_19_01301184;
extern s32 D_overlay_19_013013C8;
extern s32 D_overlay_19_013013CC;
extern s32 D_overlay_19_013013D0;
extern s32 D_overlay_19_013013D4;
extern s32 D_overlay_19_01301248;
extern s32 D_overlay_19_0130124C;
extern s32 D_overlay_19_01301400;
extern s32 D_overlay_19_01301404;
extern s32 D_overlay_19_01301408;
extern s32 D_overlay_19_0130140C;
extern s32 D_overlay_19_01301410;
void frontCleanupMap(void);
void frontCleanupOptionsPage(void);
void frontMenuFrameSetEnable(s32);
void menuScreenCleanup(void);
void healthScreenCleanup(void);
void inventoryScreenCleanup(void);
void shipScreenCleanup(void);
void tribalScreenCleanup(void);
void weaponScreenCleanup(void);
void fontWindowDisable(s32);
void frontClearMenuFrame(s32);
void frontInitMap(s32);
void frontInitOptionsPage(s32);
void frontMap(s32);
s32 frontMenuFrameTrackDrawingOn(void);
void frontOptionsPage(s32);
void frontSetMenuFrameFade(s32);
s32 frontGetMenuFrameAlpha(void);
s32 frontGetMenuFullyOpen(void);
void healthScreen(s32);
void healthScreenInit(void);
void inventoryScreen(s32);
void inventoryScreenInit(void);
void menuFrameChangeLevel(s32, s32, s32, s32);
void menuScreen(s32);
void menuScreenInit(void);
void mmFlushFreeStack(void);
void pauseClearScreen(void);
void rainSetDraw(s32);
void shipScreen(s32);
void shipScreenInit(void);
void tribalScreen(s32);
void tribalScreenInit(void);
void weaponScreen(s32);
void weaponScreenInit(void);
void func_overlay_19_01300944_1F3A874(void);
void func_overlay_19_013008EC_1F3A81C(void);
void func_overlay_19_01300968_1F3A898(s32);
extern Gfx *frontgfx;
extern MatrixS *frontmtx;
extern Vtx *frontvtx;
extern u8 numberOfPlayers;
extern s32 frontJoyPressed[4];
extern s8 frontJoyDx[4];
extern s8 frontJoyDy[4];
extern u8 *front_text;
extern u8 racingInGame;
extern u8 multiFinished;
extern s8 raceGameSingleScreen;
extern s16 racingReturnLevel;
extern u8 racingCharacter;
extern u8 racingReturnSetup;
void loadFrontEndList(void *);
void setupFrontEndList(void *);
void freeFrontEndList(void *);
f32 camGetFOV(void);
s32 camGetNo(void);
void camOverrideProjScales(f32, f32);
void camResetView(Gfx **);
void camSetFOV(f32, s32);
void camSetMode(s32);
void camSetNo(s32);
void camStandardPersp(Gfx **, MatrixS **);
void fontBackground(s32, s32, s32, s32);
void fontColour(s32, s32, s32, s32, s32);
void fontPrintXY(Gfx **, s32, s32, u8 *, s32);
void fontUseFont(s32);
void frontDrawObj(s32);
void rcpClearScreen(Gfx **, MatrixS **, s32);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void pauseInit(s32 arg0) {
    void *player;
    s32 level;
    s32 world;
    s32 idx;
    s32 next;
    u8 *entry;

    if (mainGetPauseMode() == 0) {
        player = objGetPlayerNo(0);
        if (player != NULL) {
            D_overlay_19_013013B8 = *(s8 *)(*(u8 **)((u8 *)player + 0x68) + 0x1);
        } else {
            D_overlay_19_013013B8 = mainGetNextCharacter();
        }
        D_overlay_19_013013BC = D_overlay_19_013013B8;
        level = levelGetNumber();
        D_overlay_19_013013B0 = level;
        D_overlay_19_013013B4 = level;
        world = levelGetWorld(level);
        D_overlay_19_01301188 = 0;
        entry = D_overlay_19_013010E0;
        next = *(s32 *)entry;
        idx = 0;
        if (next != 0 && world != *(s16 *)(entry + 0x4)) {
            do {
                next = *(s32 *)(entry + 0x8);
                idx++;
                entry += 0x8;
            } while (next != 0 && world != *(s16 *)(entry + 0x4));
        }
        if (next != 0) {
            D_overlay_19_01301188 = idx;
        }
        D_overlay_19_013013C0 = cooperativeGame;
        D_overlay_19_013013DC = 0;
        D_overlay_19_013013E0 = 0;
        D_overlay_19_013013E4 = 0;
        D_overlay_19_013013E8 = 0;
        mainSetPauseMode(1, next, world, &D_overlay_19_01301188);
        pausetunevol = amTuneGetVolume();
        amTuneSetFade(0.5f, 0);
        frontSetMenuFrame(0x140, 0xF0);
        amSndPlay(0x21, NULL);
        D_overlay_19_013013F0 = 0;
        D_overlay_19_013013EC = 1;
        pausePlayer = arg0;
        D_overlay_19_013013F4 = 0xA;
        D_overlay_19_013013F8 = 0;
        D_overlay_19_013013C4 = 2;
        pauseSetScreen(1);
        D_overlay_19_013013FC = 0;
    }
}

#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o19/overlay_19/pauseInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void pauseSetScreen(s32 arg0) {
    D_overlay_19_013013F8 = arg0;
    D_overlay_19_013013C4 = 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o19/overlay_19/pauseSetScreen.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 pauseGetScreen(void) {
    return D_overlay_19_013013F4;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o19/overlay_19/pauseGetScreen.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_19_013001D8_1F3A108(void) {
    runlinkFreeCode(0x26);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o19/overlay_19/func_overlay_19_013001D8_1F3A108.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 pauseGetPauseCharacter(void) {
    return D_overlay_19_013013B8;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o19/overlay_19/pauseGetPauseCharacter.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_19_01300208_1F3A138(s32 arg0) {
    switch (D_overlay_19_013013F4) {
    case 2:
        frontCleanupMap();
        runlinkFreeCode(9);
        frontMenuFrameSetEnable(1);
        return;
    case 1:
        menuScreenCleanup();
        return;
    case 12:
        func_overlay_19_01300944_1F3A874();
        return;
    case 3:
        tribalScreenCleanup();
        runlinkFreeCode(9);
        frontMenuFrameSetEnable(1);
        return;
    case 4:
        weaponScreenCleanup();
        frontMenuFrameSetEnable(1);
        return;
    case 6:
        frontCleanupOptionsPage();
        runlinkFreeCode(0x25);
        return;
    case 5:
        healthScreenCleanup();
        runlinkFreeCode(0x29);
        frontMenuFrameSetEnable(1);
        return;
    case 9:
        shipScreenCleanup();
        return;
    case 7:
        inventoryScreenCleanup();
        frontMenuFrameSetEnable(1);
        return;
    default:
        return;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o19/overlay_19/func_overlay_19_01300208_1F3A138.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void pauseSetNewLevel(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    D_overlay_19_013013C8 = arg0;
    D_overlay_19_013013CC = arg1;
    D_overlay_19_013013D0 = arg2;
    D_overlay_19_013013D4 = arg3;
    D_overlay_19_013013F8 = 0xB;
    D_overlay_19_013013C4 = 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o19/overlay_19/pauseSetNewLevel.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void pauseUpdate(Gfx **arg0, MatrixS **arg1, Vtx **arg2, s32 arg3) {
    s32 ready;
    s32 pending;
    s32 savedState;

    frontgfx = *arg0;
    frontmtx = *arg1;
    frontvtx = *arg2;
    fontWindowDisable(1);
    if (runlinkIsModuleLoaded(5) != 0) {
        rainSetDraw(0);
    }
    pending = D_overlay_19_013013F8;
    savedState = pending != 0;
    if (pending != 0) {
        if (D_overlay_19_013013FC != 0) {
            switch (pending) {
            case 3:
                tribalScreenInit();
                break;
            case 2:
                frontInitMap(1);
                break;
            case 4:
                weaponScreenInit();
                break;
            case 1:
                menuScreenInit();
                break;
            case 12:
                func_overlay_19_013008EC_1F3A81C();
                break;
            case 6:
                frontInitOptionsPage(1);
                break;
            case 5:
                healthScreenInit();
                break;
            case 9:
                shipScreenInit();
                break;
            case 7:
                inventoryScreenInit();
                break;
            case 10:
                mmFlushFreeStack();
                mmSetDelay(0);
                func_overlay_19_013001D8_1F3A108();
                mmSetDelay(2);
                frontClearMenuFrame(2);
                if (runlinkIsModuleLoaded(0x12) != 0) {
                    runlinkFreeCode(0x12);
                }
                break;
            case 11:
                mmFlushFreeStack();
                mmSetDelay(0);
                func_overlay_19_013001D8_1F3A108();
                mmSetDelay(2);
                frontClearMenuFrame(2);
                if (runlinkIsModuleLoaded(0x12) != 0) {
                    runlinkFreeCode(0x12);
                }
                menuFrameChangeLevel(D_overlay_19_013013C8, D_overlay_19_013013CC, D_overlay_19_013013D0, D_overlay_19_013013D4);
                break;
            }
            D_overlay_19_013013F4 = pending;
            D_overlay_19_013013F8 = 0;
            D_overlay_19_013013C4 = 2;
            D_overlay_19_013013FC = 0;
            pending = 0;
        }
        savedState = pending != 0;
    }
    ready = savedState;
    if (ready != 0) {
        ready = frontGetMenuFrameAlpha() == 0xFF;
        if (ready != 0) {
            ready = frontGetMenuFullyOpen() != 0;
            if (ready != 0) {
                ready = D_overlay_19_013013C4 == 1;
                if (ready != 0) {
                    ready = frontMenuFrameTrackDrawingOn() == 0;
                }
            }
        }
    }
    if (ready == 0) {
        switch (D_overlay_19_013013F4) {
        case 1:
            pauseClearScreen();
            menuScreen(arg3);
            break;
        case 12:
            pauseClearScreen();
            func_overlay_19_01300968_1F3A898(arg3);
            break;
        case 2:
            frontMap(arg3);
            break;
        case 3:
            pauseClearScreen();
            tribalScreen(arg3);
            break;
        case 4:
            pauseClearScreen();
            weaponScreen(arg3);
            break;
        case 6:
            frontOptionsPage(arg3);
            break;
        case 5:
            pauseClearScreen();
            healthScreen(arg3);
            break;
        case 9:
            pauseClearScreen();
            shipScreen(arg3);
            break;
        case 7:
            pauseClearScreen();
            inventoryScreen(arg3);
            break;
        case 8:
            pauseClearScreen();
            menuScreen(arg3);
            break;
        }
    }
    if (D_overlay_19_013013F8 != 0) {
        if (D_overlay_19_013013C4 == 1) {
            if (ready != 0) {
                mmFlushFreeStack();
                mmSetDelay(0);
                func_overlay_19_01300208_1F3A138(D_overlay_19_013013F4);
                mmSetDelay(2);
                D_overlay_19_013013FC = 1;
            } else {
                frontSetMenuFrameFade(4);
            }
        }
    } else {
        frontSetMenuFrameFade(-4);
    }
    *arg0 = frontgfx;
    *arg1 = frontmtx;
    *arg2 = frontvtx;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o19/overlay_19/pauseUpdate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 targetMode(void) {
    return D_overlay_19_01301184;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o19/overlay_19/targetMode.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void multiPlayerPauseInit(void) {
    if (mainGetPauseMode() == 0) {
        /* asm: a1-a3 are not set in this function (unset registers) */
        mainSetPauseMode(1, 0, 0, NULL);
        pausetunevol = amTuneGetVolume();
        amTuneSetFade(0.5f, 0);
        frontSetMenuFrame(0x140, 0xF0);
        amSndPlay(0x21, NULL);
        D_overlay_19_013013F0 = 0;
        D_overlay_19_013013EC = 1;
        D_overlay_19_013013F4 = 0xA;
        D_overlay_19_013013F8 = 0;
        D_overlay_19_013013C4 = 2;
        pauseSetScreen(0xC);
        D_overlay_19_013013FC = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o19/overlay_19/multiPlayerPauseInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_19_013008EC_1F3A81C(void) {
    loadFrontEndList(&D_overlay_19_01301248);
    setupFrontEndList(&D_overlay_19_0130124C);
    D_overlay_19_01301400 = 0;
    D_overlay_19_0130140C = 0;
    D_overlay_19_01301404 = 0xA;
    D_overlay_19_01301408 = 0;
    D_overlay_19_01301410 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o19/overlay_19/func_overlay_19_013008EC_1F3A81C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_19_01300944_1F3A874(void) {
    freeFrontEndList(&D_overlay_19_01301248);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o19/overlay_19/func_overlay_19_01300944_1F3A874.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_19_01300968_1F3A898(s32 arg0) {
    u8 **text_tab;
    s32 dyPos;
    s32 dyNeg;
    s32 btn4000;
    s32 btn9000;
    s32 dxPos;
    s32 dxNeg;
    s32 i;
    s32 cam_mode;
    s32 cam_no;
    f32 cam_fov;
    s32 vpW;
    s32 vpH;
    s32 tmp;

    dyPos = 0;
    dyNeg = 0;
    btn4000 = 0;
    btn9000 = 0;
    dxPos = 0;
    dxNeg = 0;
    /* asm: loop runs for players numberOfPlayers-1 down to 1 */
    i = numberOfPlayers - 1;
    if (numberOfPlayers != 0) {
        do {
            btn9000 |= frontJoyPressed[i] & 0x9000;
            btn4000 |= frontJoyPressed[i] & 0x4000;
            dyPos += frontJoyDy[i] > 0;
            dyNeg += frontJoyDy[i] < 0;
            dxNeg += frontJoyDx[i] < 0;
            dxPos += frontJoyDx[i] > 0;
            i -= 1;
        } while (i != 0);
    }
    tmp = D_overlay_19_01301400 + (arg0 * D_overlay_19_01301404);
    D_overlay_19_01301400 = tmp;
    if (tmp >= 0x100) {
        D_overlay_19_01301400 = 0x1FE - tmp;
        D_overlay_19_01301404 = -D_overlay_19_01301404;
    } else if (tmp < 0) {
        D_overlay_19_01301400 = -tmp;
        D_overlay_19_01301404 = -D_overlay_19_01301404;
    }
    cam_mode = camGetMode();
    cam_no = camGetNo();
    cam_fov = camGetFOV();
    camSetMode(0);
    camSetNo(0);
    camSetScissor(&frontgfx);
    viGetCurrentSize(&vpW, &vpH);
    vpW = (s32)((u32)vpW >> 1);
    vpH = (s32)((u32)vpH >> 1);
    rcpClearScreen(&frontgfx, &frontmtx, 0);
    texDPInit(&frontgfx);
    frontgfx->words.w1 = -1U;
    frontgfx->words.w0 = 0xF8000000;
    frontgfx++;
    frontgfx->words.w1 = 0x64009867;
    frontgfx->words.w0 = 0xBC000008;
    frontgfx++;
    frontgfx->words.w1 = 0;
    frontgfx->words.w0 = 0xE7000000;
    frontgfx++;
    pauseClearScreen();
    camOverrideProjScales(1.0f, 1.0f);
    camSetFOV(52.0f, 1);
    camResetView(&frontgfx);
    camStandardPersp(&frontgfx, &frontmtx);
    frontDrawObj(0x1F);
    fontUseFont(2);
    fontColour(0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    fontBackground(0, 0, 0, 0);
    text_tab = (u8 **)front_text;
    if (D_overlay_19_01301410 == 0) {
        fontPrintXY(&frontgfx, vpW, 0x32, text_tab[0x1FF], 4);
        if (D_overlay_19_01301408 == 0) {
            fontColour(0, D_overlay_19_01301400, 0xFF, 0xFF, 0xFF);
        } else {
            fontColour(0, 0xFF, 0xFF, 0xFF, 0xFF);
        }
        fontPrintXY(&frontgfx, vpW, 0x64, text_tab[0x200], 4);
        if (D_overlay_19_01301408 == 1) {
            fontColour(0, D_overlay_19_01301400, 0xFF, 0xFF, 0xFF);
        } else {
            fontColour(0, 0xFF, 0xFF, 0xFF, 0xFF);
        }
        fontPrintXY(&frontgfx, vpW, 0x8C, text_tab[0x28], 4);
    } else {
        fontPrintXY(&frontgfx, vpW, 0x32, text_tab[0x28], 4);
        fontColour(0, 0xFF, 0xFF, 0xFF, 0xFF);
        fontPrintXY(&frontgfx, vpW, 0x64, text_tab[0x13C], 4);
        if (D_overlay_19_01301408 == 0) {
            fontColour(0, D_overlay_19_01301400, 0xFF, 0xFF, 0xFF);
        } else {
            fontColour(0, 0xFF, 0xFF, 0xFF, 0xFF);
        }
        fontPrintXY(&frontgfx, vpW - 0x19, 0x8C, text_tab[0x13D], 4);
        if (D_overlay_19_01301408 == 1) {
            fontColour(0, D_overlay_19_01301400, 0xFF, 0xFF, 0xFF);
        } else {
            fontColour(0, 0xFF, 0xFF, 0xFF, 0xFF);
        }
        fontPrintXY(&frontgfx, vpW + 0x19, 0x8C, text_tab[0x13E], 4);
    }
    if (D_overlay_19_0130140C == 0) {
        if (D_overlay_19_01301410 != 0) {
            if ((btn4000 != 0) || ((btn9000 != 0) && (D_overlay_19_01301408 == 1))) {
                amSndPlay(0x16D, NULL);
                D_overlay_19_01301408 = 1;
                D_overlay_19_01301410 = 0;
            } else if (btn9000 != 0) {
                amSndPlay(0x16D, NULL);
                D_overlay_19_0130140C = 1;
                if (racingInGame != 0) {
                    multiFinished = 0xA;
                    if (raceGameSingleScreen != 0) {
                        pauseSetNewLevel(racingReturnLevel, racingCharacter, racingReturnSetup, 0x10);
                    } else {
                        pauseSetNewLevel(0x11D, 3, 0, 0x10);
                    }
                } else {
                    multiFinished = 0xA;
                    pauseSetNewLevel(0, 0, 0, 8);
                }
            } else if ((dxPos != 0) || (dxNeg != 0)) {
                amSndPlay(0x16B, NULL);
                D_overlay_19_01301408 = (D_overlay_19_01301408 + 1) & 1;
            }
        } else if ((btn4000 != 0) || ((btn9000 != 0) && (D_overlay_19_01301408 == 0))) {
            amSndPlay(0x16D, NULL);
            D_overlay_19_0130140C = 1;
            pauseSetScreen(0xA);
        } else if (btn9000 != 0) {
            amSndPlay(0x16D, NULL);
            D_overlay_19_01301410 = 1;
            D_overlay_19_01301408 = 1;
        } else if ((dyPos != 0) || (dyNeg != 0)) {
            amSndPlay(0x16B, NULL);
            D_overlay_19_01301408 = (D_overlay_19_01301408 + 1) & 1;
        }
    }
    camSetMode(cam_mode);
    camSetNo(cam_no);
    camSetScissor(&frontgfx);
    camSetFOV(cam_fov, 1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o19/overlay_19/func_overlay_19_01300968_1F3A898.s")
#endif
