#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
extern u32 *D_800A51AC_A5DAC;
extern u8 *front_text;
extern u8 D_800A51B0_A5DB0;
extern u8 D_800A5194_A5D94;
extern u8 disable;
extern u8 okayed;
extern u8 multiPlayerGame;
extern u8 numberOfPlayers;
extern s32 currentGameTime;
void frontFreeMode(void);
void frontInitMode(void);
void func_8005A4B4(void);
void viConvertXY();
void fontUseFont(s32 arg0);
void fontBackground(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void fontColour(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
void fontPrintXY(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 mainGetPauseMode();
void fxScreenEffect();
void fxQueueScreenEffect();
void frontPlayerScreenLimits();
extern s8 frontJoyDx[4];
extern s8 frontJoyDy[4];
extern s8 frontJoyDxRepeat[4];
extern s8 D_800FF3E4_B1DE4[4];
extern s32 D_800FF3E8_B1DE8[4];
extern s32 frontJoyHeld[4];
extern s32 frontJoyPressed[4];
extern void *frontendptrs[];
extern u8 currentobjects[];
extern u8 D_800A51DC_A5DDC[];
extern s16 *D_800A51D0_A5DD0;
extern s16 D_800A51D8_A5DD8;
extern u8 D_800FF6C8_B20C8[];
extern u16 D_800A5918_A6518[];
extern u8 D_800FF386_B1D86;
extern u8 selectedControlModes[];
extern s8 charselquitmode;
void freeFrontEndItem(s32 arg0);
void loadFrontEndItem(s32 arg0);
void setupFrontEndObject(s32 arg0);
void texFreeTexture(void *tex);
void texFreeSprite(void *sprite);
void *texLoadSprite(s32 spriteId, s32 arg1, s32 owner);
void *modLoadModel(s32 arg0, s32 arg1, s32 arg2);
void modFreeModel(void *model);
void *objSetupObject(void *params, s32 arg1, s32 arg2);
void objFreeObject(void *obj);
void objDoFrees(void);
extern u8 D_800A51A0_A5DA0;
extern s16 D_800A51D4_A5DD4;
extern u8 D_800FF1B7_B1BB7;
extern u8 multiGameType;
extern u8 racingInGame;
extern s8 widescreenVOffset;
extern s32 someResVar;
extern u8 speakerSetting;
extern u16 SFXVolume;
extern u16 musicVolume;
extern u8 D_800A5938_A6538[];
extern u8 D_800A51A4_A5DA4;
void viSetWideAdjust(s32 arg0);
s8 viGetWideAdjust(void);
void alSurround_OutputType(u8 arg0, s8 arg1);
void gsSndpSetGlobalVolume(u32 arg0);
void amTuneSetGlobalVolume(u32 volume);
extern u8 D_800A51A8_A5DA8;
extern u8 D_800A58F8_A64F8[];
extern s16 D_800A508C_A5C8C[];
extern u32 D_800FF3A8_B1DA8;
extern u32 D_800FF3B4_B1DB4;
extern Gfx *frontgfx;
extern u8 D_800A58A0_A64A0[];
extern u8 D_A58E8[];
u32 texFrame(void *arg0, s32 arg1);
extern MatrixS *frontmtx;
extern Vtx *frontvtx;
extern void *frontpol;
void fontWindowFlushStrings(s32 arg0);
void frontCleanupCharSelect(void);
void frontCleanupInstruments(void);
void frontCleanupMap(void);
void frontCleanupMultiInstruments(void);
void frontCleanupMultiModeSelect(void);
void frontCleanupMultiSelect(void);
void frontCleanupMultiStats(void);
void frontCleanupOptionsPage(void);
void frontCleanupRarepage(void);
void frontCleanupStartScreen(void);
void frontInitMenuFrame(void);
void frontKeyboardCleanup(void);
void sprintFreeInstruments(void);
void frontCreditsInit(void);
void frontInitCharSelect(s32 arg0);
void frontInitInstruments(void);
void frontInitMap(s32 arg0);
void frontInitMultiInstruments(void);
void frontInitMultiModeSelect(void);
void frontInitMultiSelect(void);
void frontInitMultiStats(void);
void frontInitOptionsPage(void);
void frontInitRarepage(void);
void frontInitStartScreen(void);
void frontKeyboardInit(void);
void frontMenuFrameTrackDrawingOn(void);
void sprintInitInstruments(void);
void diRcpTrace(void *arg0, const char *arg1, s32 arg2);
void frontCharSelect(s32 arg0);
void frontCredits(s32 arg0);
void frontDeathMatchScores(s32 arg0);
void frontInstruments(s32 arg0);
void frontKeyboard(s32 arg0);
void frontMap(s32 arg0);
void frontMenuFrameDraw(s32 arg0);
void frontMenuFrameTick(void);
void frontMultiModeSelect(s32 arg0);
void frontMultiSelect(s32 arg0);
void frontMultiStats(s32 arg0);
void frontOptionsPage(s32 arg0);
s32 frontRarepage(void);
void frontStartScreen(s32 arg0);
void func_8005A548(s32 arg0);
s32 frontGet2PlayerSplit(void);
s32 levelGetScreenMode(void);
s32 *objGetPlayerlist(s32 *arg0);
void duckshootDrawTargets(s32 arg0, s32 *arg1, s32 arg2, s32 *arg3);
void getDeathMatchObjectTable(s32 arg0, s32 arg1, s32 arg2, s32 *arg3);
void frontSingleInstruments(Gfx **arg0, MatrixS **arg1, Vtx **arg2, u8 arg3);
void sprintDrawInstruments(Gfx **arg0, MatrixS **arg1, Vtx **arg2, u8 arg3);
extern u8 multiObjectList;
extern s32 objtrans;
extern u8 frR;
extern u8 frB;
extern u8 D_800A51B8_A5DB8;
extern s32 D_800A51C4_A5DC4;
s32 mainGetCurrentLevel(void);
s32 *rainInit(s32 arg0); /* overlay 5, runtime-linked via TrapDanglingJump */
void objPrintObject(Gfx **arg0, MatrixS **arg1, Vtx **arg2, void *arg3);
void camDo2DSprite(Gfx **arg0, MatrixS **arg1, Vtx **arg2, void *arg3, void *arg4, s32 arg5, s32 arg6);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void setLanguage(s32 arg0) {
    u32 *table;
    u32 *entry;
    s32 index;
    s32 i;
    s32 *slot;

    table = D_800A51AC_A5DAC;
    if (table == NULL) {
        table = piRomLoad(7);
        D_800A51AC_A5DAC = table;
    }
    switch (arg0) {
    case 4:
        index = 5;
        break;
    case 3:
        index = 4;
        break;
    case 2:
        index = 3;
        break;
    case 1:
        index = 2;
        break;
    default:
        index = 1;
        break;
    }
    entry = &table[index];
    if (front_text != NULL) {
        piRomLoadSection(6, (u32) front_text, (s32) entry[0], entry[1] - entry[0]);
        for (i = 0; i < (s32) *D_800A51AC_A5DAC; i++) {
            slot = (s32 *) (front_text + i * 4);
            if (*slot == -1) {
                *slot = 0;
            } else {
                *slot += (s32) front_text;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/setLanguage.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void initFront(void) {
    u32 *slot;
    u32 value;
    u32 *entry;
    u32 *table;
    s32 i;

    D_800FF3A8_B1DA8 = (u32) mmAlloc(0xFA8, -1);
    slot = &D_800FF3A8_B1DA8;
    value = slot[-1];
    do {
        slot++;
        value += 0x538;
        slot[-1] = value;
    } while ((u32) slot < (u32) &D_800FF3B4_B1DB4);
    front_text = (u8 *) mmAlloc(0x3000, -1);
    setLanguage(0);
    entry = (u32 *) frontendptrs;
    do {
        entry += 4;
        entry[-4] = 0;
        entry[-3] = 0;
        entry[-2] = 0;
        entry[-1] = 0;
    } while ((u8 *) entry != D_800FF6C8_B20C8);
    D_800A51A0_A5DA0 = 0;
    table = piRomLoad(0x1A);
    D_800A51D4_A5DD4 = 0;
    D_800A51D0_A5DD0 = (s16 *) table;
    while (table[D_800A51D4_A5DD4 * 2] != -1) {
        D_800A51D4_A5DD4++;
    }
    D_800A51D8_A5DD8 = 0;
    for (i = 0; i < D_800A51D4_A5DD4; i++) {
        D_800FF6C8_B20C8[i] = 0;
    }
    D_800FF1B7_B1BB7 = 2;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/initFront.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontFreeMode(void) {
    if (runlinkIsModuleLoaded(0xC) != 0) {
        frontCleanupRarepage();
    }
    if (D_800A51A0_A5DA0 != 0) {
        switch (D_800A51B0_A5DB0) {
        case 0:
            fontWindowFlushStrings(1);
            break;
        case 2:
            frontCleanupStartScreen();
            break;
        case 3:
            frontCleanupOptionsPage();
            break;
        case 4:
            frontCleanupCharSelect();
            break;
        case 5:
            frontCleanupMultiSelect();
            break;
        case 6:
            frontCleanupMultiModeSelect();
            break;
        case 8:
            frontCleanupMultiStats();
            break;
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
            frontKeyboardCleanup();
            break;
        case 24:
            sprintFreeInstruments();
            break;
        case 16:
            if (((multiPlayerGame != 0) && (multiGameType == 4)) || (racingInGame != 0)) {
                frontCleanupInstruments();
            } else if (numberOfPlayers == 1) {
                frontCleanupMultiInstruments();
            } else {
                frontCleanupMap();
            }
            break;
        case 17:
            frontInitMenuFrame();
            runlinkFreeCode(9);
            break;
        }
        D_800A51A0_A5DA0 = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontFreeMode.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontInitMode(void) {
    frontInitRarepage();
    if (D_800A51A0_A5DA0 == 0) {
        switch (D_800A51B0_A5DB0) {
        case 2:
            frontInitStartScreen();
            break;
        case 3:
            frontInitOptionsPage();
            break;
        case 4:
            frontInitMap(0);
            break;
        case 17:
            frontInitCharSelect(0);
            break;
        case 5:
            frontInitMultiSelect();
            break;
        case 6:
            frontInitMultiModeSelect();
            break;
        case 8:
            frontInitMultiStats();
            break;
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
            frontCreditsInit();
            break;
        case 23:
            frontKeyboardInit();
            break;
        case 24:
            sprintInitInstruments();
            break;
        case 16:
            if (((multiPlayerGame != 0) && (multiGameType == 4)) || (racingInGame != 0)) {
                frontInitInstruments();
            } else {
                runlinkDownloadCode(6);
                if (numberOfPlayers == 1) {
                    frontInitMultiInstruments();
                } else {
                    frontMenuFrameTrackDrawingOn();
                }
            }
            break;
        }
        D_800A51A0_A5DA0 = 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontInitMode.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontSetMode(s32 arg0) {
    frontFreeMode();
    D_800A51B0_A5DB0 = (u8) arg0;
    frontInitMode();
    func_8005A4B4();
    okayed = 0;
    disable = 1;
    if (arg0 == 0) {
        multiPlayerGame = 0;
        numberOfPlayers = 1;
        numberOfCameras = 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontSetMode.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 frontGetMode(void) {
    return D_800A51B0_A5DB0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontGetMode.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 frontUpdate(Gfx **arg0, MatrixS **arg1, Vtx **arg2, void **arg3, s32 arg4) {
    func_8005A548(arg4);
    frontgfx = *arg0;
    frontmtx = *arg1;
    frontvtx = *arg2;
    frontpol = *arg3;
    diRcpTrace(frontgfx, "front/front.c", 0x256);
    if (frontRarepage() != 0) {
        switch (D_800A51B0_A5DB0) {
        case 2:
            frontStartScreen(arg4);
            break;
        case 3:
            frontOptionsPage(arg4);
            break;
        case 4:
            frontMap(arg4);
            break;
        case 17:
            frontCharSelect(arg4);
            break;
        case 5:
            frontMultiSelect(arg4);
            break;
        case 6:
            frontMultiModeSelect(arg4);
            break;
        case 8:
            frontMultiStats(arg4);
            break;
        case 18:
        case 19:
        case 20:
        case 21:
        case 22:
            frontCredits(arg4);
            break;
        case 23:
            frontKeyboard(arg4);
            break;
        case 24:
            frontMenuFrameDraw(arg4);
            break;
        case 16:
            frontInstruments(arg4);
            break;
        }
    }
    frontMenuFrameTick();
    frontDeathMatchScores(arg4);
    diRcpTrace(frontgfx, "front/front.c", 0x27A);
    *arg0 = frontgfx;
    *arg1 = frontmtx;
    *arg2 = frontvtx;
    *arg3 = frontpol;
    disable = 0;
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontUpdate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontDemoMessage(s32 arg0, s32 arg1) {
    s32 x;
    s32 y;
    u8 counter;

    counter = D_800A5194_A5D94 + arg1;
    D_800A5194_A5D94 = counter;
    if (counter & 0x10) {
        x = 0xA0;
        y = 0xD0;
        viConvertXY(&x, &y);
        setLanguage(frontGetLanguage());
        fontUseFont(2);
        fontBackground(0, 0, 0, 0);
        fontColour(0, 0, 0, 0xFF, 0xFF);
        fontPrintXY(arg0, x + 1, y + 1, *(s32 *) (front_text + 0xC4), 0xC);
        fontColour(0xFF, 0xFF, 0xFF, 0, 0xFF);
        fontPrintXY(arg0, x, y, *(s32 *) (front_text + 0xC4), 0xC);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontDemoMessage.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontInstruments(s32 arg0) {
    s32 playerCount;
    s32 *playerList;
    s32 gameType;

    playerList = objGetPlayerlist(&playerCount);
    if (multiPlayerGame != 0) {
        gameType = multiGameType & 0xF;
        switch (gameType) {
        case 0:
            duckshootDrawTargets(playerCount, playerList, arg0, playerList);
            break;
        case 4:
        case 6:
            sprintDrawInstruments(&frontgfx, &frontmtx, &frontvtx, numberOfPlayers);
            break;
        }
    } else if (racingInGame != 0) {
        frontSingleInstruments(&frontgfx, &frontmtx, &frontvtx, numberOfPlayers);
    } else if (playerCount > 0) {
        getDeathMatchObjectTable(*playerList, arg0, arg0, playerList);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontInstruments.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 frontUpdateTimer(s32 arg0, s32 arg1, s32 arg2) {
    s32 finished;

    finished = 0;
    if (mainGetPauseMode() == 0) {
        currentGameTime += arg2;
    }
    if (currentGameTime >= arg1) {
        currentGameTime = arg1;
        finished = 1;
    }
    return finished;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontUpdateTimer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Prints arg0 as arg4 digits (leading '0' padding) with the digit sprite frontendptrs[arg3].
// Glyph sheet order is 1..9,0: digit slot for number n is (n - 1) % 10 (asm: num-1, then /10).
// Gfx layout: 0xE4 texrect (xh/yh word0, xl/yl word1), 0xB3 glyph word1 = slot*width<<16 | row,
// 0xB2/0x0400FC00 closes each glyph. Fields of TextureHeader (height, numberOfCommands, cmd) from structs.h.
// cf. DKR menu.c timer digits (n % 10 / n / 10 split), which uses a different sprite mechanism.
void frontPrintNum(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, u32 arg5, u32 arg6) {
    s32 screenW;
    s32 screenH;
    TextureHeader *tex;
    Gfx *gfx;
    s32 num;
    s32 count;
    s32 pad;
    s32 padRem;
    s32 padStop;
    s32 digW;    /* sp9C: glyph slot width (texels), only set for sprite 8 / 9 in asm */
    s32 digAdv;  /* spA0: pixel advance per digit, only set for sprite 8 / 9 in asm */
    s32 texV;    /* spA4: (height - 1) << 5 */
    s32 height;
    s32 cmdCount;
    s32 xFix;    /* (x + screenW / 2) * 4, 10.2 fixed */
    s32 yFix;    /* ((screenH / 2) - y) * 4, 10.2 fixed */
    s32 yBot;    /* spAC: yFix + height * 4 */
    s32 xh;      /* t0: texrect right edge, stepped per glyph */
    s32 xl;      /* a3: texrect left edge, stepped per glyph */
    s32 step;    /* t1: digAdv * 4 */
    u32 blankW1; /* t2: glyph word1 for a '0' padding slot */

    viGetCurrentSize(&screenW, &screenH);
    num = arg0;
    xFix = (arg1 + ((u32) screenW >> 1)) * 4;
    yFix = (((u32) screenH >> 1) - arg2) * 4;

    tex = (TextureHeader *) frontendptrs[arg3];
    if (tex == NULL) {
        return;
    }
    if (arg3 == 8) {
        digW = 0xB;
        digAdv = 0xC;
    } else if (arg3 == 9) {
        digW = 8;
        digAdv = 8;
    }
    /* asm: for other sprite ids digW/digAdv are read uninitialised from the stack */

    /* 0x06000000: display list call, 0x07020010 + &D_A58E8 */
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w0 = 0x06000000;
    gfx->words.w1 = (u32) &D_800A58A0_A64A0;
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w0 = 0x07020010;
    gfx->words.w1 = (u32) &D_A58E8;

    height = tex->height;
    yBot = height * 4 + yFix;
    texV = (height - 1) << 5;
    cmdCount = tex->numberOfCommands - 1;

    /* texture command 0 (word0 copied from the header cmd list, word1 = texture address) */
    gfx = frontgfx;
    gfx->words.w0 = tex->cmd->words.w0;
    gfx->words.w1 = texFrame(tex, 0) + 0x80000000;
    /* texture command 1 */
    gfx = gfx + 1;
    gfx->words.w0 = ((cmdCount & 0xFF) << 16) | 0x07000000 | ((cmdCount * 8) & 0xFFFF);
    gfx->words.w1 = (u32) (tex->cmd + 1) + 0x80000000;
    /* 0xFA000000: set primitive colour arg5 */
    gfx = gfx + 1;
    frontgfx = gfx + 1;
    gfx->words.w0 = 0xFA000000;
    gfx->words.w1 = arg5;

    xh = digW * 4 + xFix;
    xl = xFix;
    step = digAdv * 4;
    count = 0;
    if (num != 0) {
        do {
            xh -= step;
            xl -= step;
            gfx = frontgfx;
            frontgfx = gfx + 1;
            gfx->words.w0 = 0xE4000000 | ((xh & 0xFFF) << 12) | (yBot & 0xFFF);
            gfx->words.w1 = ((xl & 0xFFF) << 12) | (yFix & 0xFFF);
            gfx = frontgfx;
            frontgfx = gfx + 1;
            gfx->words.w0 = 0xB3000000;
            gfx->words.w1 = ((((num - 1) % 10) * (digW << 5)) & 0xFFFF) << 16 | (texV & 0xFFFF);
            gfx = frontgfx;
            frontgfx = gfx + 1;
            gfx->words.w0 = 0xB2000000;
            gfx->words.w1 = 0x0400FC00;
            count += 1;
            num = num / 10;
        } while (num != 0);
    }

    /* 0xFA000000: set primitive colour arg6 */
    gfx = frontgfx;
    frontgfx = gfx + 1;
    gfx->words.w0 = 0xFA000000;
    gfx->words.w1 = arg6;

    pad = arg4 - count;
    if (pad != 0) {
        blankW1 = ((digW * 0x120) << 16) | (texV & 0xFFFF); /* asm: slot 9 = '0' */
        padRem = -(pad & 3);
        if (padRem != 0) {
            /* asm: 1-glyph-per-pass loop until pad reaches padStop */
            padStop = padRem + pad;
            do {
                xh -= step;
                xl -= step;
                gfx = frontgfx;
                frontgfx = gfx + 1;
                gfx->words.w0 = 0xE4000000 | ((xh & 0xFFF) << 12) | (yBot & 0xFFF);
                gfx->words.w1 = ((xl & 0xFFF) << 12) | (yFix & 0xFFF);
                gfx = frontgfx;
                frontgfx = gfx + 1;
                gfx->words.w0 = 0xB3000000;
                gfx->words.w1 = blankW1;
                gfx = frontgfx;
                frontgfx = gfx + 1;
                gfx->words.w0 = 0xB2000000;
                gfx->words.w1 = 0x0400FC00;
                pad -= 1;
            } while (padStop != pad);
        }
        if (pad != 0) {
            /* asm: 4 glyphs per pass, written out as the asm does (pad is a multiple of 4 here
             * unless arg4 < count, in which case the asm also runs this loop without a guard) */
            do {
                xh -= step;
                xl -= step;
                gfx = frontgfx;
                frontgfx = gfx + 1;
                gfx->words.w0 = 0xE4000000 | ((xh & 0xFFF) << 12) | (yBot & 0xFFF);
                gfx->words.w1 = ((xl & 0xFFF) << 12) | (yFix & 0xFFF);
                gfx = frontgfx;
                frontgfx = gfx + 1;
                gfx->words.w0 = 0xB3000000;
                gfx->words.w1 = blankW1;
                gfx = frontgfx;
                frontgfx = gfx + 1;
                gfx->words.w0 = 0xB2000000;
                gfx->words.w1 = 0x0400FC00;

                xh -= step;
                xl -= step;
                gfx = frontgfx;
                frontgfx = gfx + 1;
                gfx->words.w0 = 0xE4000000 | ((xh & 0xFFF) << 12) | (yBot & 0xFFF);
                gfx->words.w1 = ((xl & 0xFFF) << 12) | (yFix & 0xFFF);
                gfx = frontgfx;
                frontgfx = gfx + 1;
                gfx->words.w0 = 0xB3000000;
                gfx->words.w1 = blankW1;
                gfx = frontgfx;
                frontgfx = gfx + 1;
                gfx->words.w0 = 0xB2000000;
                gfx->words.w1 = 0x0400FC00;

                xh -= step;
                xl -= step;
                gfx = frontgfx;
                frontgfx = gfx + 1;
                gfx->words.w0 = 0xE4000000 | ((xh & 0xFFF) << 12) | (yBot & 0xFFF);
                gfx->words.w1 = ((xl & 0xFFF) << 12) | (yFix & 0xFFF);
                gfx = frontgfx;
                frontgfx = gfx + 1;
                gfx->words.w0 = 0xB3000000;
                gfx->words.w1 = blankW1;
                gfx = frontgfx;
                frontgfx = gfx + 1;
                gfx->words.w0 = 0xB2000000;
                gfx->words.w1 = 0x0400FC00;

                xh -= step;
                xl -= step;
                gfx = frontgfx;
                frontgfx = gfx + 1;
                gfx->words.w0 = 0xE4000000 | ((xh & 0xFFF) << 12) | (yBot & 0xFFF);
                gfx->words.w1 = ((xl & 0xFFF) << 12) | (yFix & 0xFFF);
                gfx = frontgfx;
                frontgfx = gfx + 1;
                gfx->words.w0 = 0xB3000000;
                gfx->words.w1 = blankW1;
                gfx = frontgfx;
                frontgfx = gfx + 1;
                gfx->words.w0 = 0xB2000000;
                gfx->words.w1 = 0x0400FC00;
                pad -= 4;
            } while (pad != 0);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontPrintNum.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontDrawRectangles(Gfx **gfxp, s32 count, void *rects, s32 flag) {
    s32 screenW;
    s32 screenH;
    u8 *rect;
    u32 curTex;
    u32 tex;
    s32 i;
    s32 x;
    s32 y;
    s32 w;
    s32 h;
    Gfx *gfx;

    viGetCurrentSize(&screenW, &screenH);

    gfx = *gfxp;
    *gfxp = gfx + 1;
    gfx->words.w0 = 0x06000000;
    gfx->words.w1 = (u32) &D_800A58F8_A64F8;

    gfx = *gfxp;
    *gfxp = gfx + 1;
    gfx->words.w0 = 0xEF082C0F;
    gfx->words.w1 = (flag != 0) ? 0x504340 : 0x504240;

    rect = (u8 *) rects;
    curTex = *(u32 *) (rect + 8);
    gfx = *gfxp;
    *gfxp = gfx + 1;
    gfx->words.w0 = 0xFA000000;
    gfx->words.w1 = curTex;

    for (i = 0; i < count; i++) {
        w = *(s16 *) (rect + 4);
        h = *(s16 *) (rect + 6);
        if (w >= 0 && h >= 0) {
            x = *(s16 *) (rect + 0);
            y = *(s16 *) (rect + 2);
            if (x < screenW && y < screenH) {
                if (x < 0) {
                    x = 0;
                }
                if (y < 0) {
                    y = 0;
                }
                if (screenW < w) {
                    w = screenW;
                }
                if (screenH < h) {
                    h = screenH;
                }
                tex = *(u32 *) (rect + 8);
                if (tex != curTex) {
                    gfx = *gfxp;
                    *gfxp = gfx + 1;
                    gfx->words.w0 = 0xE7000000;
                    gfx->words.w1 = 0;

                    gfx = *gfxp;
                    *gfxp = gfx + 1;
                    gfx->words.w0 = 0xFA000000;
                    gfx->words.w1 = tex;
                    curTex = tex;
                }
                gfx = *gfxp;
                *gfxp = gfx + 1;
                gfx->words.w0 = ((w & 0x3FF) << 14) | 0xF6000000 | ((h & 0x3FF) * 4);
                gfx->words.w1 = ((x & 0x3FF) << 14) | ((y & 0x3FF) * 4);
            }
        }
        rect += 12;
    }

    texDPInit(gfxp);
    gfx = *gfxp;
    *gfxp = gfx + 1;
    gfx->words.w0 = 0xFA000000;
    gfx->words.w1 = -1U;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontDrawRectangles.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontDrawRectangle(Gfx **gfxp, s16 x, s16 y, s16 w, s16 h, void *tex) {
    u8 rect[12];

    *(s16 *) (rect + 0) = x;
    *(s16 *) (rect + 2) = y;
    *(s16 *) (rect + 4) = w;
    *(s16 *) (rect + 6) = h;
    *(void **) (rect + 8) = tex;
    frontDrawRectangles(gfxp, 1, rect, 1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontDrawRectangle.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontFlashScreen(s32 arg0, s32 arg1, s32 arg2) {
    s32 left;
    s32 top;
    s32 right;
    s32 bottom;
    s32 width;
    s32 height;

    frontPlayerScreenLimits(arg1, &left, &top, &right, &bottom);
    viGetCurrentSize(&width, &height);
    if (arg0 != 0) {
        fxScreenEffect(arg0, otherScreen, width, height, left, top, right, bottom, arg2);
        return;
    }
    fxQueueScreenEffect(otherScreen, width, height, left, top, right, bottom, arg2);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontFlashScreen.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontPlayerScreenLimits(s32 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4) {
    s32 idx;
    s16 *limits;

    idx = (((numberOfCameras - 1) * 4) + arg0) * 4;
    if ((viGetVideoMode() & 1) || ((numberOfCameras == 2) && (frontGet2PlayerSplit() != 0))) {
        idx += 0x40;
    }
    limits = &D_800A508C_A5C8C[idx];
    *arg1 = limits[0];
    *arg2 = limits[1];
    viConvertXY(arg1, arg2);
    *arg3 = limits[2];
    *arg4 = limits[3];
    viConvertXY(arg3, arg4);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontPlayerScreenLimits.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8005A4B4(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        D_800FF3E8_B1DE8[i] = -1;
        frontJoyDxRepeat[i] = 0x14;
        D_800FF3E4_B1DE4[i] = 0xF;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8005A4B4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
static void frontJoyAxisRepeat(s8 *axis, s8 *repeat, s32 step) {
    if (*axis < -0x23) {
        if (*repeat < 0) {
            *repeat = *repeat + step;
            if (*repeat >= 0) {
                *repeat = -0xF;
            } else {
                *axis = 0;
            }
        } else {
            *repeat = -0x14;
        }
    } else if (*axis >= 0x24) {
        if (*repeat > 0) {
            *repeat = *repeat - step;
            if (*repeat <= 0) {
                *repeat = 0xF;
            } else {
                *axis = 0;
            }
        } else {
            *repeat = 0x14;
        }
    } else {
        *axis = 0;
        *repeat = 0;
    }
}

void func_8005A548(s32 arg0) {
    s32 i;
    s32 buttons;

    for (i = 0; i < 4; i++) {
        buttons = joyGetButtons(i);
        frontJoyHeld[i] = buttons;
        frontJoyPressed[i] = ~D_800FF3E8_B1DE8[i] & buttons;
        D_800FF3E8_B1DE8[i] = buttons;
        frontJoyDx[i] = joyGetStickX(i);
        frontJoyAxisRepeat(&frontJoyDx[i], &frontJoyDxRepeat[i], arg0);
        frontJoyDy[i] = joyGetStickY(i);
        frontJoyAxisRepeat(&frontJoyDy[i], &D_800FF3E4_B1DE4[i], arg0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/func_8005A548.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void freeFrontEndList(s16 *arg0) {
    s16 *p;
    s16 id;

    if (*arg0 != -1) {
        p = arg0;
        id = *arg0;
        do {
            p++;
            freeFrontEndItem(id);
            id = *p;
        } while (id != -1);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/freeFrontEndList.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void freeFrontEndItem(s32 arg0) {
    s16 flags;
    void *ptr;

    if (D_800FF6C8_B20C8[arg0] != 0) {
        ptr = frontendptrs[arg0];
        if (ptr != NULL) {
            flags = D_800A51D0_A5DD0[arg0];
            if ((flags & 0xC000) == 0xC000) {
                texFreeTexture(ptr);
            } else if (flags & 0x8000) {
                texFreeSprite(ptr);
            } else if (flags & 0x4000) {
                objFreeObject(ptr);
            } else {
                modFreeModel(ptr);
            }
        }
        frontendptrs[arg0] = NULL;
        D_800FF6C8_B20C8[arg0] = 0;
        D_800A51D8_A5DD8 -= 1;
        objDoFrees();
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/freeFrontEndItem.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void loadFrontEndList(s16 *arg0) {
    s16 *p;
    s16 id;

    if (*arg0 != -1) {
        p = arg0;
        id = *arg0;
        do {
            p++;
            loadFrontEndItem(id);
            id = *p;
        } while (id != -1);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/loadFrontEndList.s")
#endif

const char D_800ADF40[] = "loadFrontEndItem() - Item no %d out of range 0-%d\n";

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void loadFrontEndItem(s32 arg0) {
    struct {
        s16 id;
        s8 unk2;
        s16 unk4;
        s16 unk6;
        s16 unk8;
        s8 unkA;
        s8 unkB;
        s8 unkC;
    } spawn;
    s16 flags;
    void *tex;

    if (D_800FF6C8_B20C8[arg0] == 0) {
        flags = D_800A51D0_A5DD0[arg0];
        if ((flags & 0xC000) == 0xC000) {
            tex = texLoadTexture(flags & 0x3FFF);
        } else if (flags & 0x8000) {
            tex = texLoadSprite(flags & 0x3FFF, 0, arg0);
        } else if (flags & 0x4000) {
            spawn.id = flags & 0x3FFF;
            spawn.unk2 = 0xA;
            spawn.unk4 = 0;
            spawn.unk6 = 0;
            spawn.unk8 = 0;
            spawn.unkA = 0;
            spawn.unkB = 0x40;
            spawn.unkC = 0;
            tex = objSetupObject(&spawn, 0, arg0);
            if (((s8 *) *(u8 **) ((u8 *) tex + 0x40))[0x1F] > 0) {
                *(s8 *) (**(u8 ***) ((u8 *) tex + 0x6C) + 0xA) = 2;
            }
        } else {
            tex = modLoadModel(flags & 0x3FFF, 0, arg0);
        }
        frontendptrs[arg0] = tex;
        D_800FF6C8_B20C8[arg0] = 1;
        D_800A51D8_A5DD8 += 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/loadFrontEndItem.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void setupFrontEndList(s16 *arg0) {
    s16 *p;
    s16 id;

    if (*arg0 != -1) {
        p = arg0;
        id = *arg0;
        do {
            p++;
            setupFrontEndObject(id);
            id = *p;
        } while (id != -1);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/setupFrontEndList.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void setupFrontEndObject(s32 arg0) {
    u8 *src;
    u8 *dst;

    src = &D_800A51DC_A5DDC[arg0 << 5];
    dst = &currentobjects[arg0 << 5];
    *(s16 *) (dst + 0x0) = *(s16 *) (src + 0x0);
    *(s16 *) (dst + 0x2) = *(s16 *) (src + 0x2);
    *(s16 *) (dst + 0x4) = *(s16 *) (src + 0x4);
    *(s16 *) (dst + 0x6) = *(s16 *) (src + 0x6);
    *(f32 *) (dst + 0x8) = *(f32 *) (src + 0x8);
    *(f32 *) (dst + 0xC) = *(f32 *) (src + 0xC);
    *(f32 *) (dst + 0x10) = *(f32 *) (src + 0x10);
    *(f32 *) (dst + 0x14) = *(f32 *) (src + 0x14);
    *(f32 *) (dst + 0x18) = *(f32 *) (src + 0x18);
    *(s8 *) (dst + 0x1C) = *(s8 *) (src + 0x1C);
    *(s8 *) (dst + 0x1D) = *(s8 *) (src + 0x1D);
    *(s8 *) (dst + 0x1E) = *(s8 *) (src + 0x1E);
    *(s8 *) (dst + 0x1F) = *(s8 *) (src + 0x1F);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/setupFrontEndObject.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontDrawObj(s32 arg0) {
    ObjectTransform trans; /* sp7C: copy of the record transform (unk6 not copied) */
    ObjectTransform *rec;  /* currentobjects + arg0 * 0x20; f32 at +0x18 */
    void *obj;             /* frontendptrs[id] */
    void *spAC;
    f32 spA4;
    Gfx *dl;
    s32 flags;
    s16 id;

    rec = (ObjectTransform *) (currentobjects + (arg0 << 5));
    id = rec->unk6;
    obj = frontendptrs[id];
    if (obj == NULL) {
        return;
    }
    if ((D_800A51D0_A5DD0[id] & 0xC000) == 0xC000) {
        return;
    }
    trans.y_rotation = rec->y_rotation;
    trans.x_rotation = rec->x_rotation;
    trans.z_rotation = rec->z_rotation;
    trans.scale = rec->scale;
    trans.x_position = rec->x_position;
    trans.y_position = rec->y_position;
    trans.z_position = rec->z_position;
    flags = D_800A51D0_A5DD0[id];

    if (flags & 0x4000) {
        /* plain object: copy transform straight into the object and print it */
        ObjectTransform *dst = (ObjectTransform *) obj;
        dst->y_rotation = rec->y_rotation;
        dst->x_rotation = rec->x_rotation;
        dst->z_rotation = rec->z_rotation;
        dst->scale = rec->scale;
        dst->x_position = rec->x_position;
        dst->y_position = rec->y_position;
        dst->z_position = rec->z_position;
        ((s8 *) obj)[0x39] = (s8) objtrans;
        objPrintObject(&frontgfx, &frontmtx, &frontvtx, obj);
    } else if (flags & 0x8000) {
        /* 2D sprite: prim/env colour setup around camDo2DSprite */
        spA4 = *(f32 *) ((u8 *) rec + 0x18); /* asm stores this to a dead stack slot */
        dl = frontgfx;
        frontgfx = dl + 1;
        dl->words.w0 = 0xE7000000;
        dl->words.w1 = 0;
        dl = frontgfx;
        frontgfx = dl + 1;
        dl->words.w0 = 0xFA000000;
        dl->words.w1 = ((u32) frR << 24) | ((u32) D_800A51B8_A5DB8 << 16) | ((u32) frB << 8) | ((u32) objtrans & 0xFF);
        dl = frontgfx;
        frontgfx = dl + 1;
        dl->words.w0 = 0xFB000000;
        dl->words.w1 = 0xFFFFFF00;
        camDo2DSprite(&frontgfx, &frontmtx, &frontvtx, &trans, obj, D_800A51C4_A5DC4, objtrans);
        dl = frontgfx;
        frontgfx = dl + 1;
        dl->words.w0 = 0xE7000000;
        dl->words.w1 = 0;
        dl = frontgfx;
        frontgfx = dl + 1;
        dl->words.w0 = 0xFA000000;
        dl->words.w1 = 0xFFFFFFFF;
    } else {
        /* 3D model: optional alpha setup, then a model matrix push and display list call */
        dl = frontgfx;
        frontgfx = dl + 1;
        dl->words.w1 = 0;
        dl->words.w0 = 0xE7000000;
        if (objtrans < 0xFF) {
            dl = frontgfx;
            frontgfx = dl + 1;
            dl->words.w0 = 0xFA000000;
            dl->words.w1 = ((u32) objtrans & 0xFF) | 0xFFFFFF00;
        } else {
            dl = frontgfx;
            frontgfx = dl + 1;
            dl->words.w1 = 0xFFFFFFFF;
            dl->words.w0 = 0xFA000000;
        }
        dl = frontgfx;
        frontgfx = dl + 1;
        dl->words.w0 = 0xFB000000;
        dl->words.w1 = 0xFFFFFF00;
        spA4 = *(f32 *) ((u8 *) rec + 0x18) * 0.0625f; /* asm stores this to a dead stack slot */

        /* model flag byte at +0x4E of the model header pointed to by *obj */
        if (((s8 *) (*(void **) obj))[0x4E] == 0) {
            spAC = obj;
            camPushModelMtx(&frontgfx, &frontmtx, &trans, 1.0f, 0.0f);
            dl = frontgfx;
            frontgfx = dl + 1;
            dl->words.w0 = (((*(u32 *) ((u8 *) spAC + (((s8 *) spAC)[0xB] * 4) + 0x10)) + 0x80000000) & 0xFFFFFF) | 0xBF000000;
            dl->words.w1 = *(u32 *) ((u8 *) spAC + 4) + 0x80000000;
            dl = frontgfx;
            frontgfx = dl + 1;
            dl->words.w0 = 0x06000000;
            dl->words.w1 = *(u32 *) ((u8 *) (*(void **) spAC) + 0x74) + 0x80000000;
            dl = frontgfx;
            frontgfx = dl + 1;
            dl->words.w1 = 0;
            dl->words.w0 = 0xBF000000;
            camPopModelMtx(&frontgfx);
        }

        if (objtrans < 0xFF) {
            dl = frontgfx;
            frontgfx = dl + 1;
            dl->words.w1 = 0;
            dl->words.w0 = 0xE7000000;
            dl = frontgfx;
            frontgfx = dl + 1;
            dl->words.w1 = 0xFFFFFFFF;
            dl->words.w0 = 0xFA000000;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontDrawObj.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontSetupMultiPickup(u8 *arg0) {
    u8 params[12]; /* sp50..sp5B: objSetupObject params record */
    s32 *table;
    s32 level;
    s32 idx;
    s32 key;
    s16 *rec;
    u8 *list;
    s32 flag;
    s8 sp5A;
    s8 sp5B;
    s32 spawn;
    void *obj;
    s32 i;

    table = NULL;
    if (!(multiGameType & 0xF)) {
        table = rainInit(0);
    }
    if (table == NULL) {
        return;
    }
    idx = 0;
    level = mainGetCurrentLevel();
    /* find the level entry: 4-word entries, key at word 0 (negative = terminator) */
    if (table[0] >= 0 && level != table[0]) {
        do {
            key = table[idx * 4 + 4];
            idx++;
        } while (key >= 0 && level != key);
    }
    if (level != table[idx * 4]) {
        return;
    }
    /* per-level object list, selected by multiObjectList (word 1 + mode) */
    list = (u8 *) table[idx * 4 + multiObjectList + 1];
    /* 8-byte records, indexed by arg0->unkA (signed byte) */
    rec = (s16 *) (list + ((s8 *) arg0)[0xA] * 8);

    spawn = 1;
    switch (rec[0]) {
        case 0xCF:
        case 0xE7:
        case 0xE8:
            flag = 0x10;
            sp5B = (s8) rec[1];
            sp5A = (s8) rec[2];
            break;
        case 0xA9:
        case 0xE9:
        case 0x12A:
        case 0x33C:
            flag = 0xC;
            sp5A = (s8) rec[1];
            sp5B = (s8) rec[2];
            break;
        case 0xFA:
        case 0xFB:
        case 0xFC:
        case 0xFD:
        case 0xFE:
        case 0xFF:
        case 0x100:
        case 0x101:
        case 0x102:
        case 0x103:
        case 0x104:
        case 0x105:
        case 0x123:
        case 0x124:
        case 0x125:
            flag = 0xC;
            sp5A = 0;
            sp5B = (s8) rec[1];
            break;
        default:
            spawn = 0;
            break;
    }

    if (spawn) {
        /* first 10 bytes of arg0 form the record, then id/flag/extra bytes overwrite it */
        for (i = 0; i < 10; i++) {
            params[i] = arg0[i];
        }
        *(s16 *) params = rec[0];
        params[2] = (u8) flag;
        params[10] = (u8) sp5A;
        params[11] = (u8) sp5B;
        obj = objSetupObject(params, 1, 0);
        if (obj != NULL) {
            *(s32 *) ((u8 *) obj + 0x3C) = 0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontSetupMultiPickup.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 frontGameSelected(void) {
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontGameSelected.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 frontGetWorldLevel(void) {
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontGetWorldLevel.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 frontGetWorldName(s32 arg0) {
    return *(s32 *) (front_text + (D_800A5918_A6518[arg0] << 2));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontGetWorldName.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 frontGetLanguage(void) {
    return D_800FF386_B1D86;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontGetLanguage.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontSetLanguage(s32 arg0) {
    D_800FF386_B1D86 = arg0;
    setLanguage(arg0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontSetLanguage.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 frontGetScreenMode(void) {
    s32 mode;
    u32 v;

    v = someResVar;
    mode = 0;
    if (v & 0x40000000) {
        mode = 1;
    }
    if (v & 0x20000000) {
        mode = mode | 2;
    }
    return mode;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontGetScreenMode.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontSetScreenMode(s32 arg0) {
    u8 mode;
    u8 *flags;

    mode = arg0 & 3;
    flags = (u8 *) &globalflags + 0x6C;
    if (D_800A51A8_A5DA8 != mode) {
        D_800A51A8_A5DA8 = mode;
        if (mode & 1) {
            *flags |= 0x40;
        } else {
            *flags &= 0xBF;
        }
        if (mode & 2) {
            *flags |= 0x20;
            return;
        }
        *flags &= 0xDF;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontSetScreenMode.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontStoreScreenMode(void) {
    D_800A51A4_A5DA4 = D_800A51A8_A5DA8;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontStoreScreenMode.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 frontRecallScreenMode(void) {
    return D_800A51A4_A5DA4;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontRecallScreenMode.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 frontGetLevelScreenMode(void) {
    if (D_800A51A8_A5DA8 == 1) {
        return 1;
    }
    if (D_800A51A8_A5DA8 == 2) {
        return levelGetScreenMode() | 2;
    }
    if (D_800A51A8_A5DA8 == 3) {
        return 3;
    }
    return levelGetScreenMode();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontGetLevelScreenMode.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s8 frontGetWideAdjust(void) {
    return widescreenVOffset;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontGetWideAdjust.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontSetWideAdjust(s32 arg0) {
    viSetWideAdjust(arg0);
    widescreenVOffset = viGetWideAdjust();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontSetWideAdjust.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 frontGetStereoMode(void) {
    return speakerSetting;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontGetStereoMode.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontSetStereoMode(s32 arg0) {
    s32 mode = arg0;

    if (mode < 0) {
        mode = 0;
    }
    if (mode >= 4) {
        mode = 3;
    }
    speakerSetting = mode;
    alSurround_OutputType(D_800A5938_A6538[mode], mode);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontSetStereoMode.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 frontGetSfxVolume(void) {
    return SFXVolume;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontGetSfxVolume.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontSetSfxVolume(s32 arg0) {
    s32 vol = arg0;

    if (vol < 0) {
        vol = 0;
    }
    if (vol >= 0x101) {
        vol = 0x100;
    }
    SFXVolume = vol;
    gsSndpSetGlobalVolume(vol);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontSetSfxVolume.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 frontGetBgmVolume(void) {
    return musicVolume;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontGetBgmVolume.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontSetBgmVolume(s32 arg0) {
    s32 vol = arg0;

    if (vol < 0) {
        vol = 0;
    }
    if (vol >= 0x101) {
        vol = 0x100;
    }
    musicVolume = vol;
    amTuneSetGlobalVolume(vol);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontSetBgmVolume.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 frontGet2PlayerSplit(void) {
    u32 t;

    t = (u32) someResVar << 3;
    return t >> 31;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontGet2PlayerSplit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontSet2PlayerSplit(s32 arg0) {
    s32 bit;

    bit = (arg0 << 4) & 0x10;
    *((u8 *) &globalflags + 0x6C) = (u8) (bit | (*((u8 *) &globalflags + 0x6C) & 0xFFEF));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontSet2PlayerSplit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 frontGetTargetControl(s32 arg0) {
    return selectedControlModes[arg0 & 3];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontGetTargetControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontSetTargetControl(s32 arg0, s32 arg1) {
    selectedControlModes[arg0 & 3] = arg1 & 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontSetTargetControl.s")
#endif

#ifdef VERSION_us
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontCharSelectSetQuitMode(s32 arg0) {
    charselquitmode = arg0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/menu/frontCharSelectSetQuitMode.s")
#endif
#endif
