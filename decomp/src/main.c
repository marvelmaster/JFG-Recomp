#include "common.h"
#include "sched.h"

/* decomp: externs */
#ifdef NON_MATCHING
typedef struct ZBCheckEntry {
    s16 x;          /* 0x00 */
    s16 y;          /* 0x02 */
    u8 pad4;        /* 0x04 */
    s8 w;           /* 0x05 */
    s8 h;           /* 0x06 */
    s8 visible;     /* 0x07 */
} ZBCheckEntry;

extern void *D_800A3370_A3F70;
extern s32 D_800A3290_A3E90;
extern s32 D_800A3530_A4130;
extern s8 D_800FD7BC_B3B0C;
extern s32 areaTitlePrintTimer;
extern s16 D_800FD7A4_B3AF4;
extern s16 continues;
extern Gfx *gfx;
extern Gfx *gfxBase[2];
extern void *mtx;
extern void *vtx;
extern void *pol;
extern void *mtxBase[2];
extern void *vtxBase[2];
extern void *polBase[2];
extern s32 frame;
extern s8 D_800FD7BD_B3B0D;
extern u8 robotMission;
extern u8 cooperativeGame;
extern u8 multiPlayerGame;
extern u8 numberOfPlayers;
extern u8 racingInGame;
extern s32 arcadeScreen;
extern s32 MAX_gfx;
extern s32 MAX_mtx;
extern s32 MAX_pol;
extern s32 MAX_vtx;
extern s32 blurOn;
extern s32 dayfactor;
extern s32 delayDat;
extern s16 fadeCount;
extern s8 gameInWindow;
extern s16 levelId;
extern s16 D_800FD794_B3AE4;
extern s16 D_800FD796_B3AE6;
extern s16 D_800FD798_B3AE8;
extern s16 D_800FD79A_B3AEA;
extern s16 D_800FD79C_B3AEC;
extern s16 D_800FD79E_B3AEE;
extern s16 D_800FD7A0_B3AF0;
extern s16 D_800FD7A2_B3AF2;
extern s16 D_800A3234_A3E34;
extern s8 D_800A4FB0_A5BB0;
extern s32 D_800F6F54_B1794;
extern s32 AllowSelfDestructing;
extern s8 D_800A3294_A3E94;
extern s32 D_800A3328_A3F28;
extern s32 D_800A3378_A3F78;
extern ZBCheckEntry D_800FD750_B3AA0[8];
extern s32 D_800A332C_A3F2C;
extern s32 D_800A3330_A3F30;
extern u8 D_800A3377_A3F77;
extern s32 D_800A32AC_A3EAC;
extern s8 D_800A32C4_A3EC4;
extern s32 D_80101594;
extern s16 D_800A3240_A3E40;
extern s16 D_800A3244_A3E44;
extern s16 D_800A3248_A3E48;
extern s16 D_800A324C_A3E4C;
extern s16 D_800A3258_A3E58;
extern s16 D_800A3264_A3E64;
extern s16 D_800A3268_A3E68;
extern s16 D_800A3270_A3E70;
extern s16 D_800A3274_A3E74;
extern s16 D_800A3278_A3E78;
extern s16 D_800A327C_A3E7C;
extern s8 D_800A3284_A3E84;
extern s8 D_800A3288_A3E88;
extern s8 D_800A32A0_A3EA0;
extern s32 D_800A3304_A3F04;

void viReset(void);
void diRcpTraceReset(void);
void diRcpTrace(Gfx *dl, char *file, s32 line);
void rcpFast3d(Gfx *dl0, Gfx *dl, s32 arg2, s32 arg3);
void rcpInitSp(Gfx **dlist);
void camSetUserView(s32 view, s32 x1, s32 y1, s32 x2, s32 y2);
void camEnableUserView(s32 view, s32 flag);
void camDisableUserView(s32 view, s32 flag);
void camTick(s32 arg0);
void camUserViewTick(void);
s32 camIsUserView(s32 view);
void camGetUserView(s32 view, s32 *x1, s32 *y1, s32 *x2, s32 *y2);
s32 camGetPtr(void);
void rcpSetBorderColour(s32 r, s32 g, s32 b);
void rcpClearScreen(Gfx **dlist, void **mtxp, s32 arg2);
void diCpuTraceGetFault(void);
void diCpuTraceTick(s32 arg0);
void fxUnQueueScreenEffect(Gfx **dlist);
s32 fxFadeOn();
void fxGenerateTextures(void);
void fxInitLines(void);
void fxOutputLines(void);
f32 rainDensity(void);
void amAudioTick(u8 arg0);
void debug_print_memory(void);
void fontWindowsDraw(Gfx **dlist, void **mtxp, void **vtxp);
void fontWindowDisable(s32 arg0);
void fontWindowFlushStrings(s32 arg0);
s32 updateClearScreen(s32 arg0);
void drawClearScreen(Gfx **dlist, void **mtxp, void **vtxp);
void frontDemoMessage(Gfx **dlist, s32 arg1);
void frontUpdate(Gfx **dlist, void **mtxp, void **vtxp, void **polp, s32 arg4);
s32 mainDemoOnly(void);
s32 mainGetPauseMode(void);
s32 levelGetWorld(s16 arg0, s32 *arg1);
s32 viFrameSync(s32 arg0, s32 *arg1, s32 *arg2, Gfx *arg3);
void viFrameRateReset(void);
void trackDraw(Gfx **dlist, void **mtxp, void **vtxp, void **polp, s32 arg4);
void trackUpdateFX(s32 arg0);
void trackUpdateTextureScroll(void);
void trackUpdateLighting(s32 arg0, s32 arg1);
void runlinkTick(void);
void subtitlesTick(s32 arg0);
void prnBorder(Gfx **dlist);
void objDoFrees(void);
s32 objCutCameraActive(void);
void objObjectsCutCameraTick(s32 arg0);
void objObjectsPauseTick(void);
void objObjectsTick(s32 arg0);
void objResetAnimModels(s32 arg0);
void partUpdateParticles(s32 arg0);
void animseqCamera(s32 arg0, s32 arg1);
void animseqUpdate(s32 arg0);
void setupClearScreen(void *arg0);
void frontSetLanguage(s32 arg0);
s32 frontGetScreenMode(void);
void frontSetScreenMode(s32 arg0);
s32 frontGetWideAdjust(void);
void frontSetWideAdjust(s32 arg0);
s32 frontGetStereoMode(void);
void frontSetStereoMode(s32 arg0);
s32 frontGetSfxVolume(void);
void frontSetSfxVolume(s32 arg0);
s32 frontGetBgmVolume(void);
void frontSetBgmVolume(s32 arg0);
void frontStoreScreenMode(void);
void mainFrontInit(s32 arg0, s32 arg1, s32 arg2);
void mainCPUeffects(s32 arg0, s32 arg1);
void mainUpdateZBCheck(void);
void func_8004552C(s32 arg0);
void func_800456F8(s32 arg0);
void func_800457F4(s32 arg0);
s32 func_80045D44(s16 arg0, s16 *arg1, s16 *arg2, s16 *arg3, s16 *arg4);
extern s8 D_800A329C_A3E9C;
extern s32 D_800A32FC_A3EFC;
extern s32 D_800A3304_A3F04;
extern s16 D_800A337C_A3F7C;
extern u8 D_800FF391_B1D91;
extern s32 D_800FD7C8_B3B18;
extern s32 D_800A32C8_A3EC8;
extern s16 D_800FEDE4_B17E4;
extern s16 D_800FEDE6_B17E6;
extern s16 D_800FEDE8_B17E8;
extern s16 D_800FEDEA_B17EA;
extern s16 D_800FEDEC_B17EC;
extern s16 D_800FEE84_B1884;
extern s16 D_800FEE86_B1886;
extern s16 D_800FEE88_B1888;
extern s16 D_800FEE8A_B188A;
extern s16 D_800FEE8C_B188C;
extern s16 D_800FEF24_B1924;
extern s16 D_800FEF26_B1926;
extern s16 D_800FEF28_B1928;
extern s16 D_800FEF2A_B192A;
extern s16 D_800FEF2C_B192C;
extern s16 D_800FEFC4_B19C4;
extern s16 D_800FEFC6_B19C6;
extern s16 D_800FEFC8_B19C8;
extern s16 D_800FEFCA_B19CA;
extern s16 D_800FEFCC_B19CC;
extern u8 multiPlayer;
extern u8 multiCharacter;
extern u8 multiCharacterType;
extern u8 multiGameLife;
extern u8 D_800FED66_B1766;
s32 mainGetGameFlag(s32 flag);
void mainSetPauseMode(s32 arg0);
u8 amTuneGetSeqNo(void);
void amTuneSetFade(f32 arg0, s32 arg1);
void controlClearPlayerSetup(s32 arg0);
s16 levelGetRegionNo(s16 arg0);
s32 levelGetTune(s16 arg0);
void rumbleRumbles(s32 arg0);
void mainSetDefaultCharacter(void *arg0, s32 arg1);
void *controlGetWeaponDef(s32 arg0);
extern s16 D_800A3314_A3F14;
void *mainGetGameCharacter(s32 arg0, s32 arg1);
extern s32 D_800FF37C_B1D7C;
void amSetMuteMode(s32 arg0);
void mainSaveGlobalFlags(); /* asm takes no args; callers pass leftovers */
void frontDisplayRegion(void);
void blurUpdate(Gfx **dlist, s16 arg1, s32 arg2, s16 arg3, s32 arg4);
void blurTask(s32 arg0);
void frontMenuFrameTrackDrawingOn(void);
s32 robotPauseUpdate(void);
void pauseUpdate(void);
void robotDisplay(Gfx **dlist, void **mtxp, void **vtxp, s32 arg3);
void refractTick(Gfx **dlist, void **mtxp, s32 arg2);
void animseqUpdateNoisyFade(void);
void dayUpdate(s32 arg0);
void mantisLightingUpdate(s32 arg0);
void rainActive(s32 arg0);
s32 rainDraw(void);
void refractOutput(s32 arg0, s32 arg1, s32 arg2, s32 arg3, f32 arg4);
s32 starfieldActive(void);
s32 starfieldMove(void);
void squadsModuleTick(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void robotPauseInit(s32 arg0);
void pauseInit(s32 arg0);
void multiPlayerPauseInit(s32 arg0);
void hinttextUpdate(void);
void arcadeDrawScreen(Gfx **dlist, s32 arg1);
void frontShowRegionStats(Gfx **dlist, void **mtxp, void **vtxp, s32 arg3);
void sparkFreeAll(s16 *arg0, s32 arg1);
extern s32 joyfail;
extern s8 D_800A3298_A3E98;
extern s8 *tribaltable;
extern s32 debugInputCode[];
extern s32 debugInputCount;
extern u8 D_800FED62_B1762;
u8 levelNGetType(s32 arg0);
void *levelGetRegionFlags(void);
void levelInitRegionFlags(s32 arg0, s32 arg1);
void fontWindowSize(s32 windowId, s32 x1, s32 y1, s32 x2, s32 y2);
void fontWindowColour(s32 windowId, s32 red, s32 green, s32 blue, s32 alpha);
void fontSetWindowNoise(u8 arg0, u8 arg1, u8 arg2);
void fontWindowDraw(Gfx **dlist, void **mtxp, void **vtxp, s32 windowId);
void fontUseFont(s32 font);
void fontColour(s32 red, s32 green, s32 blue, s32 alpha, s32 opacity);
void fontBackground(s32 red, s32 green, s32 blue, s32 alpha);
void fontPrintXY(Gfx **displayList, s32 xpos, s32 ypos, char *text, s32 alignmentFlags);
s32 objGetPlayerNo(s32 arg0);
extern s32 D_800A32EC_A3EEC;
extern s32 D_800A32F4_A3EF4;
extern u8 D_800A507C_A5C7C;
extern s32 D_800A3928_A4528;
extern u8 racingCharacter;
extern u8 raceGameIDNumber;
extern s16 racingReturnLevel;
void amTuneStop(void);
void amWaitForMidiSync(void);
void bloodSpurtFreeLib(void);
void camInit(s32 arg0);
void explosionFlushBlasts(void);
void frontFreeMode(void);
s32 frontGetLevelScreenMode(s16 arg0);
void frontSetMode(s16 arg0);
void hinttextFree(void);
void levelFreeAll(void);
u32 levelGetBlurEffect(s32 arg0);
u32 levelGetGfxIndex(s32 arg0);
void levelInit(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
void listReallocate(s32 arg0);
void mainResetRegion(void);
void mainSetLevelWorld(s32 arg0, s32 arg1, u8 arg2);
void mmFlushFreeStack(void);
void partFreeLib(void);
void partSetupLib(void);
void racingInGameEnd(void);
void racingInGameStart(s32 arg0);
void robotMissionFree(void);
void splinecamFree(void);
void splinecamSetup(s32 arg0);
void squadsLowMemoryPanic(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
void subtitlesFree(void);
void subtitlesInit(void);
s32 viChangeBuffers(s32 arg0);
void viChangeMode(s32 arg0);
s32 viDisplayingScreen0(void);
void viSetTrippleBuffer(s32 arg0);
/* end decomp: externs */
#endif

#ifdef VERSION_kiosk
const char D_800ACDB0[] = "1.1723";
const char D_800ACDB8[] = "19/08/99 15:26";
const char D_800ACDC8[] = "jpegg";
const char D_800ACDD0[] = "null";
const char D_800ACDD8[] = "setting up";
const char D_800ACDE4[] = "freeing";
const char D_800ACDEC[] = "processing";
const char D_800ACDF8[] = "exploding";
const char D_800ACE04[] = "WARNING: couldn't find 'ra=0x666' in function %d\n";
const char D_800ACE38[] = "main/main.c";
const char D_800ACE44[] = "main/main.c";
const char D_800ACE50[] = "main/main.c";
const char D_800ACE5C[] = "main/main.c";
const char D_800ACE68[] = "main/main.c";
const char D_800ACE74[] = "main/main.c";
const char D_800ACE80[] = "Change: L %d, R %d >> L %d, R %d  (%d)\n";
const char D_800ACEA8[] = "SYNC\n";
const char D_800ACEB0[] = "Char Flag %d\n";
const char D_800ACEC0[] = "Char Flag %d\n";
const char D_800ACED0[] = "Saving Game %d\n";
const char D_800ACEE0[] = "Canyon";
const char D_800ACEE8[] = "Asteroid";
const char D_800ACEF4[] = "Mizar";
const char D_800ACEFC[] = "Ichor";
const char D_800ACF04[] = "Alien Cave";
const char D_800ACF10[] = "Swamp";
const char D_800ACF18[] = "Sekhmet Battleship";
const char D_800ACF2C[] = "Dune";
const char D_800ACF34[] = "SS Anubis";
const char D_800ACF40[] = "Spawn Ship";
const char D_800ACF4C[] = "Goldwood Forest";
const char D_800ACF5C[] = "Goldwood Quarry";
const char D_800ACF6C[] = "Spacestation";
const char D_800ACF7C[] = "Water ruin";
const char D_800ACF88[] = "Walkway";
const char D_800ACF90[] = "Multi";
const char D_800ACF98[] = "Old";
const char D_800ACF9C[] = "Baddy Test";
const char D_800ACFA8[] = "Canyon Mine";
const char D_800ACFB4[] = "Sub-Worlds";
const char D_800ACFC0[] = "GIRL";
const char D_800ACFC8[] = "BOY";
const char D_800ACFCC[] = "DOG";
const char D_800ACFD0[] = "GIRL HOVERSHIP";
const char D_800ACFE0[] = "POWERGIRL";
const char D_800ACFEC[] = "POWERBOY";
const char D_800ACFF8[] = "POWERDOG";
const char D_800AD004[] = "ANT HOVERSHIP";
const char D_800AD014[] = "CHEATS OFF";
const char D_800AD020[] = "CHEATS ON";
const char D_800AD02C[] = "GOLDWOOD Area 1";
const char D_800AD03C[] = "SS ANUBIS Maze";
const char D_800AD04C[] = "SS ANUBIS Floyd";
const char D_800AD05C[] = "CERULEAN Colony";
const char D_800AD06C[] = "ICHOR Military Base";
const char D_800AD080[] = "MIZARS PALACE";
const char D_800AD090[] = "WALKWAY Sequence";
const char D_800AD0A4[] = "ALIEN CAVES";
const char D_800AD0B0[] = "WATER RUIN";
const char D_800AD0BC[] = "PISTOL";
const char D_800AD0C4[] = "HOMING MISSILE";
const char D_800AD0D4[] = "MACHINE GUN";
const char D_800AD0E0[] = "SHOT GUN";
const char D_800AD0EC[] = "SHRINK BEAM";
const char D_800AD0F8[] = "ROCKET";
const char D_800AD100[] = "FLAMETHROWER";
const char D_800AD110[] = "GRENADE";
const char D_800AD118[] = "SHIRUKEN";
const char D_800AD124[] = "FISH FOOD";
const char D_800AD130[] = "PROXIMITY MINE";
const char D_800AD140[] = "TIMED MINE";
const char D_800AD14C[] = "REMOTE MINE";
const char D_800AD158[] = "FLARE";
const char D_800AD160[] = "CLUSTER BOMB";
// const char D_800AD170[] = "%5d  %5d  %5d\n";
// const char D_800AD180[] = "FREE %d";
// const char D_800AD188[] = "%d K";
#else
const char D_800AC4D0_AD0D0[] = "1.1848";
const char D_800AC4D8_AD0D8[] = "04/09/99 20:40";
const char D_800AC4E8_AD0E8[] = "jpegg";
const char D_800AC4F0_AD0F0[] = "null";
const char D_800AC4F8_AD0F8[] = "setting up";
const char D_800AC504_AD104[] = "freeing";
const char D_800AC50C_AD10C[] = "processing";
const char D_800AC518_AD118[] = "exploding";
const char D_800AC524_AD124[] = "%d\n";
const char D_800AC528_AD128[] = "WARNING: couldn't find 'ra=0x666' in function %d\n";
#endif

void mainPreNMI(void);

void mainThread(UNUSED void *unused) {
    // Anti Piracy - This will zero out all RAM if this is a PAL console.
    if (osTvType == OS_TV_TYPE_PAL) {
        s32 i = 0;
        while (1) {
            ((vu32 *) (RAM_END))[--i] = (u32) 0;
        }
    }
    D_800A3B70 = osBootRamTest1_6105();
    D_800A3B74 = osBootRamTest2_6105();
    mainInitGame();
    load_save_flags = joyRead(load_save_flags, 0);
    D_800FE280 = 0;
    mainGameMode = 6;
    mainChangeLevel(0, D_800A3AB0, 0, 0, 1, 0);
#ifdef VERSION_kiosk
    func_80046070(0x1E);
    while (1) {
        if (mainResetPressed()) {
            rumbleKill();
            amStop();
            osViBlack(TRUE);
            __osSpSetStatus(SP_SET_HALT | SP_CLR_INTR_BREAK | SP_CLR_YIELD | SP_CLR_YIELDED | SP_CLR_TASKDONE |
                            SP_CLR_RSPSIGNAL | SP_CLR_CPUSIGNAL | SP_CLR_SIG5 | SP_CLR_SIG6 | SP_CLR_SIG7);
            osDpSetStatus(DPC_SET_XBUS_DMEM_DMA | DPC_CLR_FREEZE | DPC_CLR_FLUSH | DPC_CLR_TMEM_CTR | DPC_CLR_PIPE_CTR |
                          DPC_CLR_CMD_CTR | DPC_CLR_CMD_CTR);
            while (1) {} // Infinite loop
        }
        func_80044938();
        if (joyGetPressed(1) & L_TRIG) {
            mainSetGameFlag(0x58, 1);
        }
        if (joyGetPressed(1) & R_TRIG) {
            mainSetGameFlag(0x58, 0);
        }
        bootCheckStack();
    }
#else
    while (1) {
        mainPreNMI();
        func_80044938();
        bootCheckStack();
    }
#endif
}

#ifdef VERSION_us
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainPreNMI(void) {
    OSTime t;

    if (mainResetPressed() != 0) {
        amStop();
        if (D_800A3290_A3E90 != 0) {
            osSetTime(0);
            t = osGetTime();
            if (t == 0 && (u32) t < 0x22ADD7U) {
                do {
                    t = osGetTime();
                } while (t == 0 && (u32) t < 0x22ADD7U);
            }
        }
        __osSpSetStatus(0xAAAA82U);
        osDpSetStatus(0x1D6U);
        viReset();
        rumbleKill(1);
        rumbleTick(2);
        rumbleTick(2);
        rumbleTick(2);
        while (1) {}
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainPreNMI.s")
#endif
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void RevealReturnAddresses(void) {
    void **entry;
    u32 *insn;
    s32 outer;
    s32 inner;

    /* Scans 5 code blocks of 64 words (table entries walk backwards) and
     * rewrites any "addiu rt, rs, 0x666" marker into "or rt, $ra, $zero"
     * so the return address becomes visible. */
    entry = &D_800A3370_A3F70;
    outer = 4;
    do {
        insn = (u32 *) *entry;
        inner = 0x3F;
        do {
            if ((*insn >> 26) == 9 && (*insn & 0xFFFF) == 0x666) {
                *insn = 0x03E00025U | (((*insn >> 16) & 0x1F) << 11);
                osWritebackDCache(insn, 4);
                osInvalICache(insn, 4);
                break;
            }
            insn++;
        } while (inner-- != 0);
        entry--;
    } while (outer-- != 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/RevealReturnAddresses.s")
#endif

#ifdef VERSION_kiosk
void mainInitGame(void) {
    s32 viMode;

    RevealReturnAddresses();
    mmInit();
    securitybuffer = mmAlloc(16, COLOUR_TAG_GREY);
    rzipInit();
    D_800FE26C = 0;

    if (osTvType == OS_TV_TYPE_PAL) {
        viMode = OS_VI_PAL_LPN1;
    } else if (osTvType == OS_TV_TYPE_NTSC) {
        viMode = OS_VI_NTSC_LPN1;
    } else if (osTvType == OS_TV_TYPE_MPAL) {
        viMode = OS_VI_MPAL_LPN1;
    }
    osCreateScheduler(&sc, &Time, 13, viMode, 1);
    viInit(&sc);
    piInit();
    rcpInit(&sc);
    runlinkInitialise();
    TrapDanglingJump();
    runlinkFreeCode(0x24);
}
#else
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainInitGame(void) {
    u8 viMode;

    if (osTvType == OS_TV_TYPE_PAL) {
        viMode = OS_VI_PAL_LPN1;
    } else if (osTvType == OS_TV_TYPE_NTSC) {
        viMode = OS_VI_NTSC_LPN1;
    } else if (osTvType == OS_TV_TYPE_MPAL) {
        viMode = OS_VI_MPAL_LPN1;
    }
    osCreateScheduler(&sc, Time, 0xD, viMode, 1);
    RevealReturnAddresses();
    mmInit();
    rzipInit();
    securitybuffer = mmAlloc(0x40, 0x7F7F7FFFU);
    D_800FD7BC_B3B0C = 0;
    D_800A3530_A4130 = 1;
    viInit(&sc);
    mainPreNMI();
    piInit();
    mainPreNMI();
    rcpInit(&sc);
    mainPreNMI();
    runlinkInitialise();
    mainPreNMI();
    D_800A3290_A3E90 = 1;
    frontDisplayRegion();
    mainPreNMI();
    runlinkFreeCode(0x24);
    D_800A3530_A4130 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainInitGame.s")
#endif
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_800448B0(s32 arg0) {
    s32 alpha;

    if (arg0 < areaTitlePrintTimer) {
        areaTitlePrintTimer = areaTitlePrintTimer - arg0;
        alpha = areaTitlePrintTimer * 4;
        if (alpha >= 0x100) {
            alpha = 0xFF;
        }
        blurUpdate(&gfx, D_800FD7A4_B3AF4, levelGetWorld(D_800A323C_A3E3C, &areaTitlePrintTimer), continues, alpha);
        return;
    }
    areaTitlePrintTimer = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/func_800448B0.s")
#endif

// main_game_loop in DKR
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80044938(void) {
    s32 width;
    s32 height;
    Gfx *dlStart;
    s32 *src;
    s32 *dst;
    s32 i;
    s32 count;

    if (blurOn != 0) {
        blurTask(0);
    }
    osSetTime(0);
    if (D_800A32AC_A3EAC == 8) {
        gfx = gfxBase[frame];
        segSetBase(&gfx, 0, 0);
        segSetBase(&gfx, 1, currentScreen);
        segSetBase(&gfx, 2, otherZbuf);
        segSetBase(&gfx, 4, currentScreen - 0x500);
    }
    rcpFast3d(gfxBase[frame], gfx, 0, currentScreen);
    if (blurOn != 0) {
        frontMenuFrameTrackDrawingOn();
    }
    frame ^= 1;
    diRcpTraceReset();
    gfx = gfxBase[frame];
    mtx = mtxBase[frame];
    vtx = vtxBase[frame];
    pol = polBase[frame];
    diRcpTrace(gfx, "main/main.c", 0x386);
    segSetBase(&gfx, 0, 0);
    segSetBase(&gfx, 1, (s32) otherScreen);
    segSetBase(&gfx, 2, otherZbuf);
    segSetBase(&gfx, 4, (s32) otherScreen - 0x500);
    rcpInitSp(&gfx);
    rcpInitDp(&gfx);
    if (robotPauseUpdate() != 0) {
        if (gameInWindow != 0) {
            camSetUserView(0, mainGameWindowSizeX1, mainGameWindowSizeY1, mainGameWindowSizeX2, mainGameWindowSizeY2);
            camEnableUserView(0, 1);
            rcpSetBorderColour(0, 0, 0);
        }
        rcpClearScreen(&gfx, &mtx, 1);
        camDisableUserView(0, 1);
    }
    load_save_flags = joyRead(load_save_flags, delayDat);
    diCpuTraceGetFault();
    if (mainGameMode == 5) {
        diCpuTraceTick(delayDat);
    } else {
        func_800457F4(delayDat);
        if (mainGameMode == 6) {
            func_800456F8(delayDat);
        }
    }
    fxUnQueueScreenEffect(&gfx);
    if (D_800FD7BD_B3B0D == 1) {
        if (robotMission != 0) {
            pauseUpdate();
        } else if (runlinkIsModuleLoaded(0x13) != 0) {
            robotDisplay(&gfx, &mtx, &vtx, delayDat);
        }
    } else {
        func_800448B0(delayDat);
    }
    frontUpdate(&gfx, &mtx, &vtx, &pol, delayDat);
    if (runlinkIsModuleLoaded(0x16) != 0) {
        refractTick(&gfx, &mtx, delayDat);
    }
    amAudioTick(D_800A3377_A3F77);
    diPrintfAll(&gfx);
    if (debugMenuEnable != 0) {
        debug_print_memory();
    }
    fontWindowsDraw(&gfx, &mtx, &vtx);
    fontWindowDisable(4);
    fontWindowFlushStrings(4);
    if (updateClearScreen(delayDat) != 0) {
        drawClearScreen(&gfx, &mtx, &vtx);
    }
    if (D_800FE280 >= 8 && mainDemoOnly() != 0) {
        frontDemoMessage(&gfx, delayDat);
    }
    diRcpTrace(gfx, "main/main.c", 0x44B);
    gfx->words.w0 = 0xE9000000;
    gfx->words.w1 = 0;
    gfx++;
    gfx->words.w1 = 0;
    gfx->words.w0 = 0xB8000000;
    gfx++;
    if (runlinkIsModuleLoaded(2) != 0 && fxFadeOn() == 0) {
        animseqUpdateNoisyFade();
    }
    camTick(delayDat);
    camUserViewTick();
    func_8004552C(delayDat);
    if (fadeCount != 0) {
        dayUpdate(delayDat);
    }
    if (runlinkIsModuleLoaded(0x17) != 0 && mainGetPauseMode() == 0) {
        mantisLightingUpdate((s32) (delayDat * dayfactor) >> 8);
    }
    if (runlinkIsModuleLoaded(0x27) != 0) {
        rainActive(delayDat);
    }
    D_800A32AC_A3EAC = rcpWaitDP();
    mainUpdateZBCheck();
    mainCPUeffects(currentScreen, delayDat);
    trackUpdateTextureScroll();
    trackUpdateLighting(1, delayDat);
    runlinkTick();
    mmFreeTick();
    if (D_800A332C_A3F2C != 0) {
        viGetCurrentSize(&width, &height);
        count = (s32) ((u32) (width * height) >> 1);
        src = (s32 *) currentScreen;
        dst = otherScreen;
        for (i = 0; i < count; i++) {
            dst[i] = src[i];
        }
    }
    D_800A3330_A3F30 = D_800A3330_A3F30 - delayDat;
    if (D_800A3330_A3F30 < 0) {
        D_800A3330_A3F30 = 0;
    }
    D_800A332C_A3F2C = 0;
    dlStart = gfxBase[frame];
    if (MAX_gfx < ((s32) ((u32) gfx - (u32) dlStart) >> 3)) {
        D_800A332C_A3F2C = 1;
    }
    if (MAX_mtx < ((s32) ((u32) mtx - (u32) mtxBase[frame]) >> 6)) {
        D_800A332C_A3F2C = 1;
    }
    if (MAX_vtx < (s32) ((u32) vtx - (u32) vtxBase[frame]) / 10) {
        D_800A332C_A3F2C = 1;
    }
    if (MAX_pol < ((s32) ((u32) pol - (u32) polBase[frame]) >> 4)) {
        D_800A332C_A3F2C = 1;
    }
    if (D_800A332C_A3F2C != 0) {
        gfx = dlStart;
        gfx->words.w1 = 0;
        gfx->words.w0 = 0xE9000000;
        gfx++;
        gfx->words.w1 = 0;
        gfx->words.w0 = 0xB8000000;
        gfx++;
        D_800A3330_A3F30 = 0x3C;
    }
    delayDat = viFrameSync(D_800A32AC_A3EAC, &D_800A3330_A3F30, &D_800A332C_A3F2C, dlStart);
    if (D_800A32C4_A3EC4 != 0) {
        viFrameRateReset();
        delayDat = 2;
    } else if (delayDat >= 7) {
        delayDat = 6;
    }
    func_80046070(delayDat);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/func_80044938.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 mainAddZBCheck(s32 arg0, s32 arg1, s32 arg2) {
    s32 width;
    s32 height;
    s32 x1;
    s32 y1;
    s32 x2;
    s32 y2;
    s32 result;
    ZBCheckEntry *entry;

    viGetCurrentSize(&width, &height);
    result = -1;
    if (D_800A3378_A3F78 < 8) {
        x2 = arg0 + arg2;
        y2 = arg1 + arg2;
        if (x2 >= 0 && y2 >= 0) {
            x1 = arg0 - arg2;
            y1 = arg1 - arg2;
            if (x1 < width && y1 < height) {
                if (x1 < 0) {
                    x1 = 0;
                }
                if (y1 < 0) {
                    y1 = 0;
                }
                if (x2 >= width) {
                    x2 = width - 1;
                }
                if (y2 >= height) {
                    y2 = height - 1;
                }
                result = D_800A3378_A3F78;
                entry = &D_800FD750_B3AA0[D_800A3378_A3F78];
                D_800A3378_A3F78 += 1;
                entry->x = x1;
                entry->y = y1;
                entry->w = (s8) ((x2 - x1) + 1);
                entry->h = (s8) ((y2 - y1) + 1);
            }
        }
    }
    return result;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainAddZBCheck.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainUpdateZBCheck(void) {
    s32 width;
    s32 height;
    ZBCheckEntry *entry;
    s32 i;
    s32 visible;
    s32 rows;
    s32 cols;
    s32 row;
    s32 x;
    u16 *pixel;

    viGetCurrentSize(&width, &height);
    entry = D_800FD750_B3AA0;
    for (i = 0; i < 8; i++, entry++) {
        visible = 1;
        if (D_800A3378_A3F78 > 0) {
            D_800A3378_A3F78 -= 1;
            rows = entry->h;
            cols = entry->w;
            pixel = (u16 *) (otherZbuf + ((entry->y * width) + entry->x) * 2);
            if (rows != 0) {
                for (row = 0; row < rows && visible; row++) {
                    for (x = cols - 1; x >= 0 && visible; x--) {
                        if ((pixel[x] & 0xFFFC) == 0xFFFC) {
                            visible = 0;
                        }
                    }
                    pixel += width;
                }
            }
        }
        entry->visible = (s8) visible;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainUpdateZBCheck.s")
#endif

s8 mainGetZBCheck(s32 arg0) {
    if ((arg0 < 0) || (arg0 >= 8)) {
        return 1;
    }
    return D_800FE217[arg0].ZBCheck;
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainCPUeffects(s32 arg0, s32 arg1) {
    s32 width;
    s32 height;
    s32 x1;
    s32 y1;
    s32 x2;
    s32 y2;

    viGetCurrentSize(&width, &height);
    if (camIsUserView(0) != 0) {
        camGetUserView(0, &x1, &y1, &x2, &y2);
        height = (y2 - y1) + 1;
        arg0 += y1 * width * 2;
    }
    if (fxFadeOn() == 0 && runlinkIsModuleLoaded(5) != 0 && rainDraw() != 0) {
        if (D_80101594 > 0) {
            if ((u32) height >= (u32) D_80101594) {
                refractOutput(arg0, width, D_80101594, 0x43800000, rainDensity());
            }
        }
        D_80101594 = height;
    }
    fxGenerateTextures();
    if (runlinkIsModuleLoaded(2) != 0 && fxFadeOn() == 0) {
        starfieldActive();
    }
    if (fxFadeOn() == 0) {
        fxOutputLines();
        return;
    }
    fxInitLines();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainCPUeffects.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainSetGameWindow(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5, s32 arg6, s32 arg7, s32 arg8) {
    D_800FD794_B3AE4 = arg0;
    D_800FD796_B3AE6 = arg1;
    D_800FD798_B3AE8 = arg2;
    D_800FD79A_B3AEA = arg3;
    D_800FD79C_B3AEC = (s16) arg4;
    D_800FD79E_B3AEE = (s16) arg5;
    D_800FD7A0_B3AF0 = (s16) arg6;
    D_800FD7A2_B3AF2 = (s16) arg7;
    if (arg8 < 0) {
        D_800A3234_A3E34 = (s16) -arg8;
        levelId = 1;
    } else {
        D_800A3234_A3E34 = (s16) arg8;
        levelId = 0;
    }
    D_800A3A80 = D_800A3234_A3E34;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainSetGameWindow.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8004552C(s32 arg0) {
    s32 scale;
    s8 inWindow;

    if (D_800A3A80 != 0) {
        mainGameWindowSizeX1 = D_800FD79C_B3AEC;
        mainGameWindowSizeY1 = D_800FD79E_B3AEE;
        mainGameWindowSizeX2 = D_800FD7A0_B3AF0;
        D_800A3A80 -= arg0;
        mainGameWindowSizeY2 = D_800FD7A2_B3AF2;
        if (D_800A3A80 > 0) {
            scale = (s32) (D_800A3A80 << 0x10) / (s16) D_800A3234_A3E34;
            mainGameWindowSizeX1 += (s32) ((D_800FD794_B3AE4 - D_800FD79C_B3AEC) * scale) >> 0x10;
            mainGameWindowSizeY1 += (s32) ((D_800FD796_B3AE6 - D_800FD79E_B3AEE) * scale) >> 0x10;
            mainGameWindowSizeX2 += (s32) ((D_800FD798_B3AE8 - D_800FD7A0_B3AF0) * scale) >> 0x10;
            mainGameWindowSizeY2 += (s32) ((D_800FD79A_B3AEA - D_800FD7A2_B3AF2) * scale) >> 0x10;
        } else {
            D_800A3A80 = 0;
        }
    }
    inWindow = D_800A3A80 != 0;
    if (inWindow == 0) {
        inWindow = levelId == 0;
    }
    gameInWindow = inWindow;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/func_8004552C.s")
#endif

s16 mainGameWindowChanging(void) {
    return D_800A3A80;
}

void mainGameWindowSize(s32 *x1, s32 *y1, s32 *x2, s32 *y2) {
    *x1 = mainGameWindowSizeX1;
    *y1 = mainGameWindowSizeY1;
    *x2 = mainGameWindowSizeX2;
    *y2 = mainGameWindowSizeY2;
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_800456F8(s32 arg0) {
    s32 anyStart;
    s32 i;
    s32 frames;

    anyStart = 0;
    for (i = 0; i < 4; i++) {
        anyStart |= joyGetButtons(i) & 0x1000;
    }
    if (anyStart != 0) {
        D_800A4FB0_A5BB0 = 1;
    }
    frames = D_800FE280 + 1;
    D_800FE280 = frames;
    if (frames >= 0xA) {
        frontSetLanguage(frontGetLanguage());
        frontSetScreenMode(frontGetScreenMode());
        frontSetWideAdjust(frontGetWideAdjust());
        frontSetStereoMode(frontGetStereoMode());
        frontSetSfxVolume(frontGetSfxVolume());
        frontSetBgmVolume(frontGetBgmVolume());
        frontStoreScreenMode();
        mainFrontInit(2, 0, 0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/func_800456F8.s")
#endif

// PauseGame happens here, right when the rumblekill is called
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_800457F4(s32 arg0) {
    LevelHeader *level;
    s32 heldButtons;
    s32 pressedButtons;
    s32 pausePlayer;
    s32 playerCount;
    s32 p;
    s32 cutCamera;

    level = levelGetLevel();
    D_800F6F54_B1794 = 1;
    if (runlinkIsModuleLoaded(5) != 0 && starfieldMove() != 0 && D_800FD7BD_B3B0D == 0) {
        squadsModuleTick(0, 0, 0xC0000000, arg0);
    }
    heldButtons = 0;
    pressedButtons = 0;
    pausePlayer = -1;
    if (cooperativeGame != 0 && robotMission != 0) {
        playerCount = 2;
    } else if (multiPlayerGame != 0) {
        playerCount = numberOfPlayers;
    } else {
        playerCount = 1;
    }
    for (p = 0; p < playerCount; p++) {
        heldButtons |= joyGetButtons(p);
        pressedButtons |= joyGetPressed(p);
        if (pressedButtons & 0x1000) {
            pausePlayer = p;
        }
    }
    diRcpTrace(gfx, "main/main.c", 0x62E);
    objResetAnimModels(arg0);
    cutCamera = objCutCameraActive();
    AllowSelfDestructing = 1;
    if (D_800FD7BD_B3B0D == 0 && D_800A3328_A3F28 == 0 && cutCamera == 0) {
        *(s32 *) Time += arg0;
        animseqUpdate(arg0);
        if (runlinkIsModuleLoaded(3) != 0) {
            robotPauseInit(arg0);
        }
        objObjectsTick(arg0);
        partUpdateParticles(arg0);
        animseqCamera(0, camGetPtr());
        trackUpdateFX(arg0);
        if ((((s8 *) level)[0x6C] != 1) && (((s8 *) level)[0x6C] != 2) && (pressedButtons & 0x1000)
            && D_800A32BC_A3EBC == 0 && D_800A3294_A3E94 == 0 && mainGameMode == 0) {
            rumbleKill(1);
            if (multiPlayerGame == 0 && racingInGame == 0) {
                if (robotMission != 0) {
                    pauseInit(pausePlayer);
                } else {
                    multiPlayerPauseInit(pausePlayer);
                }
            } else {
                hinttextUpdate();
            }
            AllowSelfDestructing = 0;
        }
    } else {
        if (D_800FD7BD_B3B0D == 0 && D_800A3328_A3F28 == 0 && cutCamera != 0) {
            objObjectsCutCameraTick(arg0);
        } else {
            objObjectsPauseTick();
        }
        AllowSelfDestructing = 0;
    }
    if (D_800A32BC_A3EBC > 0) {
        D_800A32BC_A3EBC -= arg0;
        if (D_800A32BC_A3EBC < 0) {
            D_800A32BC_A3EBC = 0;
        }
    }
    objDoFrees();
    diRcpTrace(gfx, "main/main.c", 0x683);
    trackDraw(&gfx, &mtx, &vtx, &pol, arg0);
    diRcpTrace(gfx, "main/main.c", 0x6C0);
    subtitlesTick(arg0);
    if (runlinkIsModuleLoaded(7) != 0) {
        arcadeDrawScreen(&gfx, arg0);
    }
    if (arcadeScreen != 0) {
        frontShowRegionStats(&gfx, &mtx, &vtx, arcadeScreen);
    }
    prnBorder(&gfx);
    diRcpTrace(gfx, "main/main.c", 0x6DC);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/func_800457F4.s")
#endif

#ifdef VERSION_us
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainValidateRestart(s32 *arg0, s32 *arg1, s32 *arg2) {
    s32 code;

    code = *arg0;
    if (code == 0xF5 || code == 0xFA || code == 0x11D || code == 0x16B || code == 0x196) {
        *arg0 = 0xF5;
        *arg1 = 0;
        *arg2 = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainValidateRestart.s")
#endif
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainRestartAfterDeath(void) {
    u8 *player;

    if (D_800A3294_A3E94 == 0) {
        if (func_80045D44(D_800A323C_A3E3C, &D_800A3250_A3E50, &D_800A3254_A3E54, &D_800A3258_A3E58, &D_800A3268_A3E68) == 0) {
            if (D_800FD7A4_B3AF4 == 0 || D_800FD7A4_B3AF4 == 0xFF || continues > 0) {
                if (D_800FD7A4_B3AF4 != 0 && D_800FD7A4_B3AF4 != 0xFF) {
                    continues -= 1;
                    D_800A3284_A3E84 = 1;
                }
                D_800A3250_A3E50 = D_800A323C_A3E3C;
                D_800A3254_A3E54 = D_800A3248_A3E48;
                D_800A3268_A3E68 = D_800FD7A4_B3AF4;
                D_800A3258_A3E58 = D_800A3244_A3E44;
            } else {
                D_800A3250_A3E50 = D_800A3270_A3E70;
                D_800A3254_A3E54 = D_800A3274_A3E74;
                D_800A3258_A3E58 = D_800A3278_A3E78;
                D_800A3268_A3E68 = D_800A327C_A3E7C;
                D_800A3288_A3E88 = 1;
            }
        }
        D_800A3AB0 = D_800A3240_A3E40;
        D_800A3264_A3E64 = D_800A324C_A3E4C;
        if (D_800A3288_A3E88 != 0) {
            player = (u8 *) gameplay + ((D_800A3AB0 & 3) * 0x76);
            if ((*(u16 *)(player + 0x160) & 0x1F) == 1) {
                player[0x161] = (u8) (player[0x161] & 0xE0);
            }
        }
        if (fxFadeOn(&D_800A3250_A3E50, &D_800A3254_A3E54, &D_800A3258_A3E58, &D_800A3268_A3E68) == 0) {
            D_800A32A0_A3EA0 = 0;
            setupClearScreen(&D_800A3304_A3F04);
        }
        D_800A3294_A3E94 = 0x1E;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainRestartAfterDeath.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_80045D44(s16 arg0, s16 *arg1, s16 *arg2, s16 *arg3, s16 *arg4) {
    switch (arg0) {
        case 0xD2:
            *arg1 = 0xF9;
            *arg2 = 0;
            *arg3 = 0;
            *arg4 = D_800FD7A4_B3AF4;
            return 1;
        case 0xB5:
            *arg1 = 0x13;
            *arg2 = 0;
            *arg3 = 0;
            *arg4 = D_800FD7A4_B3AF4;
            return 1;
        case 0xC3:
            *arg1 = 0xC2;
            *arg2 = 0;
            *arg3 = 0;
            *arg4 = D_800FD7A4_B3AF4;
            return 1;
        case 0x182:
            *arg1 = 0x18B;
            *arg2 = 0;
            *arg3 = 0;
            *arg4 = D_800FD7A4_B3AF4;
            return 1;
        case 0xE9:
            *arg1 = 0x18C;
            *arg2 = 0;
            *arg3 = 0;
            *arg4 = D_800FD7A4_B3AF4;
            return 1;
        default:
            return 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/func_80045D44.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainChangeLevel(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    u8 seqNo;

#ifdef NM_DIRECT_START
    /* test build: "new game" (0x142 = ship intro) jumps straight to the chosen level/character */
    if (arg0 == 0x142) {
        arg0 = NM_START_LEVEL;
        arg1 = NM_START_CHAR;
    }
#endif
    if ((D_800A3294_A3E94 == 0) || (arg0 != D_800A3250_A3E50) || (arg1 != D_800A3AB0) || (arg3 != D_800A3264_A3E64)) {
        if (mainGameMode == 0) {
            if (arg0 == 0x11E) {
                if (mainGetGameFlag(0x5E) != 0) {
                    arg0 = 0x130;
                }
            } else if (arg0 == 0xC2) {
                if (mainGetGameFlag(0x4D) != 0) {
                    arg0 = 0x179;
                }
            } else if (arg0 == 0x14C) {
                controlClearPlayerSetup(arg0);
            }
        }
        D_800A3250_A3E50 = (s16) arg0;
        D_800A3254_A3E54 = 0;
        D_800A3258_A3E58 = (s16) arg2;
        D_800A3AB0 = (s16) arg1;
        D_800A3264_A3E64 = (s16) arg3;
        D_800A3268_A3E68 = levelGetRegionNo((s16) arg0);
        if ((arg5 & 1) && (D_800FD7A4_B3AF4 != 0) && (D_800FD7A4_B3AF4 != 0xFF) &&
            (((D_800FD7A4_B3AF4 != D_800A3268_A3E68) && (D_800A3268_A3E68 != 0xFF)) || (arg3 == 0x11))) {
            D_800A329C_A3E9C = 1;
            sparkFreeAll(&D_800A3268_A3E68, 0xFF);
            mainSetPauseMode(1);
        }
        if (D_800A3294_A3E94 <= 0) {
            D_800A3294_A3E94 = 0xA;
            if (fxFadeOn() == 0) {
                if (D_800A329C_A3E9C == 0) {
                    if (arg4 != 0) {
                        D_800A32A0_A3EA0 = 1;
                        setupClearScreen(&D_800A32FC_A3EFC);
                    } else {
                        D_800A32A0_A3EA0 = 0;
                        setupClearScreen(&D_800A3304_A3F04);
                    }
                }
                D_800A3294_A3E94 = 0x1E;
            }
            seqNo = amTuneGetSeqNo();
            if ((levelGetTune(D_800A3250_A3E50) != seqNo) && (mainGetPauseMode() == 0)) {
                amTuneSetFade(0.45f, 0);
            }
            rumbleKill(1);
            rumbleRumbles(0);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainChangeLevel.s")
#endif

void mainSetAnimGroup(s32 arg0) {
    D_800A3254_A3E54 = arg0;
}

s32 mainGetAnimGroup(void) {
    return D_800A3248_A3E48;
}

void mainChangeCameras(s32 arg0) {
    D_800A325C_A3E5C = arg0;
}

s32 mainGetNextCharacter(void) {
    return D_800A3AB0;
}

s32 mainGetNextLevel(void) {
    return D_800A3250_A3E50;
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80046070(s32 arg0) {
    s32 screenMode;
    s32 levelType;
    s32 world;
    s16 regionA;
    s16 regionB;
    s16 regionC;
    s16 regionD;
    u8 *player;
    u8 seqNo;
    s32 curW;
    s32 curH;
    u32 pixels;
    s32 *screen;
    Gfx *dl;
    Gfx *dl2;

    mainPreNMI();
    if (D_800A329C_A3E9C != 0) {
        if (!((joyGetPressed(0) & 0x8000) || (joyGetPressed(0) & 0x1000))) {
            return;
        }
        D_800A329C_A3E9C = 0;
        if (fxFadeOn() == 0) {
            D_800A32A0_A3EA0 = 1;
            setupClearScreen(&D_800A32FC_A3EFC);
        }
        amTuneSetFade(0.45f, 0);
        D_800A3294_A3E94 = 0x1E;
    }

    D_800A32C4_A3EC4 = 0;
    /* player record: 0x76 bytes each, base +0x15C inside Game */
    player = (u8 *)gameplay + ((D_800A3AB0 & 3) * 0x76) + 0x15C;
    if (D_800A3294_A3E94 == 0) {
        return;
    }
    D_800A3294_A3E94 -= arg0;
    if (D_800A3294_A3E94 > 0) {
        return;
    }

    if (D_800A507C_A5C7C != 0) {
        if (mainGetGameFlag(3) == 0) {
            mainSetGameFlag(3, 1);
        }
    }
    levelType = levelNGetType(D_800A3250_A3E50);
    if (levelType == 1 || levelType == 2) {
        /* asm: levelGetWorld is called with only a0 (a1 is stale) */
        world = ((s32 (*)(s16))levelGetWorld)(D_800A3250_A3E50); /* sig mismatch */
        mainSetLevelWorld(D_800A3AB0, -1, world);
    } else {
        world = ((s32 (*)(s16))levelGetWorld)(D_800A3250_A3E50); /* sig mismatch */
        mainSetLevelWorld(D_800A3AB0, D_800A3250_A3E50, world);
    }

    if (func_80045D44(D_800A3250_A3E50, &regionA, &regionB, &regionC, &regionD) != 0) {
        *(u16 *)(player + 0x74) = (u16)((regionA << 5) | (*(u16 *)(player + 0x74) & 0x1F));
        player[0x75] = (u8)((regionC & 0x1F) | (player[0x75] & 0xFFE0));
    } else {
        switch (D_800A3268_A3E68) {
        case 0xFF:
            break;
        case 0x0:
            if (levelType != 2 && levelType != 1) {
                *(u16 *)(player + 0x74) = (u16)((D_800A3250_A3E50 << 5) | (*(u16 *)(player + 0x74) & 0x1F));
                player[0x75] = (u8)((D_800A3258_A3E58 & 0x1F) | (player[0x75] & 0xFFE0));
            }
            break;
        default:
            if (racingInGame == 0) {
                if (D_800A3268_A3E68 != D_800FD7A4_B3AF4) {
                    *(u16 *)(player + 0x74) = (u16)((D_800A3250_A3E50 << 5) | (*(u16 *)(player + 0x74) & 0x1F));
                    player[0x75] = (u8)((D_800A3258_A3E58 & 0x1F) | (player[0x75] & 0xFFE0));
                } else if ((D_800A3240_A3E40 & 3) != (D_800A3AB0 & 3)) {
                    *(u16 *)(player + 0x74) = (u16)((D_800A3250_A3E50 << 5) | (*(u16 *)(player + 0x74) & 0x1F));
                    player[0x75] = (u8)((D_800A3258_A3E58 & 0x1F) | (player[0x75] & 0xFFE0));
                    D_800A3288_A3E88 = 1;
                }
            }
            break;
        }
    }

    /* gameplay flag 0x62: rewrite the three player-slot attribute halfwords */
    if (mainGetGameFlag(0x62) != 0) {
        *(u16 *)((u8 *)gameplay + 0x1D0) = (u16)((*(u16 *)((u8 *)gameplay + 0x1D0) & 0x1F) | 0x2600);
        gameplay->pad[0x1CD] = 2;
        gameplay->pad[0x1D1] = (u8)((gameplay->pad[0x1D1] & 0xFFE0) | 6);
        *(u16 *)((u8 *)gameplay + 0x246) = (u16)((*(u16 *)((u8 *)gameplay + 0x246) & 0x1F) | 0x2600);
        gameplay->pad[0x243] = 2;
        gameplay->pad[0x247] = (u8)((gameplay->pad[0x247] & 0xFFE0) | 8);
        *(u16 *)((u8 *)gameplay + 0x2BC) = (u16)((*(u16 *)((u8 *)gameplay + 0x2BC) & 0x1F) | 0x2600);
        gameplay->pad[0x2BD] = (u8)((gameplay->pad[0x2BD] & 0xFFE0) | 7);
        gameplay->pad[0x2B9] = 2;
        mainSetGameFlag(0x62, 0);
    }
    if (mainGetGameFlag(0x60) != 0) {
        *(u16 *)((u8 *)gameplay + 0x246) = (u16)((*(u16 *)((u8 *)gameplay + 0x246) & 0x1F) | 0x10E0);
        gameplay->pad[0x243] = 5;
        mainSetGameFlag(0x60, 0);
    }
    if (mainGetGameFlag(0x61) != 0) {
        *(u16 *)((u8 *)gameplay + 0x1D0) = (u16)((*(u16 *)((u8 *)gameplay + 0x1D0) & 0x1F) | 0x2660);
        gameplay->pad[0x1CD] = 2;
        mainSetGameFlag(0x61, 0);
    }
    if (mainGetGameFlag(0x5F) != 0) {
        *(u16 *)((u8 *)gameplay + 0x1C0) = (u16)(*(u16 *)((u8 *)gameplay + 0x1C0)
            | *(u16 *)((u8 *)gameplay + 0x236) | *(u16 *)((u8 *)gameplay + 0x2AC));
        *(u16 *)((u8 *)gameplay + 0x236) = (u16)(*(u16 *)((u8 *)gameplay + 0x236)
            | *(u16 *)((u8 *)gameplay + 0x1C0) | *(u16 *)((u8 *)gameplay + 0x2AC));
        *(u16 *)((u8 *)gameplay + 0x2AC) = (u16)(*(u16 *)((u8 *)gameplay + 0x2AC)
            | *(u16 *)((u8 *)gameplay + 0x1C0) | *(u16 *)((u8 *)gameplay + 0x236));
        *(u16 *)((u8 *)gameplay + 0x1C0) = (u16)(*(u16 *)((u8 *)gameplay + 0x1C0) & 0xFFFD);
        *(u16 *)((u8 *)gameplay + 0x2AC) = (u16)(*(u16 *)((u8 *)gameplay + 0x2AC) & 0xFFFD);
    }

    if (viDisplayingScreen0() == 0) {
        D_800A3294_A3E94 = 1;
        return;
    }

    D_800A3530_A4130 = 1;
    mmFlushFreeStack();
    mmSetDelay(0);
    mainPreNMI();
    frontFreeMode();
    mainPreNMI();
    if (runlinkIsModuleLoaded(0xA) != 0) {
        bloodSpurtFreeLib();
    }
    if (runlinkIsModuleLoaded(8) != 0) {
        hinttextFree();
    }
    if (runlinkIsModuleLoaded(7) != 0) {
        robotMissionFree();
    }
    if (robotMission != 0) {
        racingInGameEnd();
    }
    if (D_800A3298_A3E98 != 0) {
        mainPreNMI();
        if (racingInGame != 0) {
            splinecamFree();
        }
        levelFreeAll();
        if (runlinkIsModuleLoaded(0xB) != 0) {
            /* asm: a0 still holds the 0xB argument of runlinkIsModuleLoaded */
            racingInGameStart(0xB);
        }
        mainPreNMI();
        partFreeLib();
        mainPreNMI();
        subtitlesFree();
        /* 0xE9 / 0xB8 display list commands written at the start of the frame */
        dl = gfxBase[frame];
        gfx = dl;
        gfx = (Gfx *)((u8 *)dl + 8);
        dl->words.w0 = 0xE9000000;
        dl->words.w1 = 0;
        dl2 = gfx;
        gfx = (Gfx *)((u8 *)dl2 + 8);
        dl2->words.w1 = 0;
        dl2->words.w0 = 0xB8000000;
        D_800A3298_A3E98 = 0;
    }

    seqNo = amTuneGetSeqNo();
    if (levelGetTune(D_800A3250_A3E50) != seqNo) {
        amTuneStop();
    }
    if (((D_800A3240_A3E40 & 3) != 3) && ((D_800A3AB0 & 3) == 3)) {
        racingCharacter = (u8)D_800A3240_A3E40;
        gameplay->pad[0x2C3] = (u8)((D_800A3240_A3E40 & 0x1F) | (gameplay->pad[0x2C3] & 0xFFE0));
    }
    if (multiPlayerGame == 0) {
        if (D_800A3250_A3E50 == 0x10C) {
            raceGameIDNumber = 0;
            racingInGameStart(0);
        } else if (D_800A3250_A3E50 == 0x102) {
            racingReturnLevel = D_800A323C_A3E3C;
            raceGameIDNumber = 1;
            racingInGameStart(1);
        } else if (D_800A3250_A3E50 == 0x18D) {
            racingReturnLevel = D_800A323C_A3E3C;
            raceGameIDNumber = 2;
            listReallocate(1);
        } else if (D_800A3250_A3E50 == 0x14F) {
            *(u16 *)((u8 *)gameplay + 0x236) = (u16)(*(u16 *)((u8 *)gameplay + 0x236) | 2);
        }
    }

    D_800A323C_A3E3C = D_800A3250_A3E50;
    D_800A3248_A3E48 = D_800A3254_A3E54;
    D_800A3244_A3E44 = D_800A3258_A3E58;
    D_800A3240_A3E40 = D_800A3AB0;
    D_800A324C_A3E4C = D_800A3264_A3E64;
    if (D_800A3250_A3E50 == 0x7F && mainGetGameFlag(0x5F) != 0) {
        D_800A3254_A3E54 = 1;
        D_800A3248_A3E48 = D_800A3254_A3E54;
    }

    if ((D_800A3268_A3E68 != D_800FD7A4_B3AF4 && racingInGame == 0) || D_800A3288_A3E88 != 0) {
        D_800FD7A4_B3AF4 = D_800A3268_A3E68;
        *(s32 *)((u8 *)gameplay + 0x514) = 0;
        if (D_800A3268_A3E68 != 0 && D_800A3268_A3E68 != 0xFF) {
            /* sig mismatch: mainResetRegion takes &D_800A3268 in a0 */
            ((void (*)(s16 *))mainResetRegion)(&D_800A3268_A3E68);
            D_800A3270_A3E70 = D_800A323C_A3E3C;
            D_800A3274_A3E74 = D_800A3248_A3E48;
            D_800A3278_A3E78 = D_800A3244_A3E44;
            D_800A327C_A3E7C = D_800FD7A4_B3AF4;
            continues = 2;
            D_800A3284_A3E84 = 1;
        }
    }

    if (D_800A3284_A3E84 != 0) {
        areaTitlePrintTimer = 0xF0;
    } else {
        areaTitlePrintTimer = 0;
    }
    D_800A3284_A3E84 = 0;
    D_800A3288_A3E88 = 0;
    if (D_800A325C_A3E5C != 0) {
        numberOfCameras = (u8)D_800A325C_A3E5C;
    }
    D_800A325C_A3E5C = 0;
    mainPreNMI();

    screenMode = frontGetLevelScreenMode(D_800A323C_A3E3C);
    viSetTrippleBuffer(levelGetBlurEffect(D_800A323C_A3E3C));
    if (viGetVideoMode() != screenMode || viChangeBuffers(screenMode) != 0) {
        viChangeMode(screenMode);
    } else {
        viGetCurrentSize(&curW, &curH);
        /* N = (w*h)/2 iterations; the asm bnez tests the counter before its delay-slot decrement */
        pixels = ((u32)curW * (u32)curH) >> 1;
        screen = (s32 *)currentScreen;
        if (pixels != 0) {
            do {
                *screen = (s32)((u8)D_800A32A0_A3EA0 - 1);
                screen++;
                pixels--;
            } while (pixels != 0);
        }
    }

    D_800A3928_A4528 = 0;
    mainPreNMI();
    mmFlushFreeStack();
    mmSetDelay(0);
    mainPreNMI();
    splinecamSetup(levelGetGfxIndex(D_800A323C_A3E3C));
    runlinkFreeCode(0x24);
    mainPreNMI();
    mmFlushFreeStack();
    mmSetDelay(0);
    camInit(1);
    if (runlinkIsModuleLoaded(0xB) != 0) {
        partSetupLib();
    }
    mainPreNMI();
    subtitlesInit();
    mainPreNMI();
    squadsLowMemoryPanic(0x64, 0x64, 0x64, 0xA, 0xA, 0xF, 0xA);
    mainPreNMI();
    runlinkFreeCode(0x1A);
    mainPreNMI();
    levelInit(D_800A323C_A3E3C, D_800A3244_A3E44, D_800A3240_A3E40, D_800A3248_A3E48);
    mainPreNMI();
    if ((u8)D_800A32A0_A3EA0 != 0) {
        setupClearScreen(&D_800A32EC_A3EEC);
    } else {
        setupClearScreen(&D_800A32F4_A3EF4);
    }
    osSetTime(0);
    explosionFlushBlasts();
    mainPreNMI();
    frontSetMode(D_800A324C_A3E4C);
    mmSetDelay(2);
    rumbleUpdate();
    load_save_flags = joyRead(load_save_flags, 2);
    D_800A3294_A3E94 = 0;
    D_800A3298_A3E98 = 1;
    D_800FD7BD_B3B0D = 0;
    D_800A32C4_A3EC4 = 1;
    if (mainGetGameFlag(0x59) != 0) {
        dayfactor = 0;
    } else {
        dayfactor = 0x100;
    }
    if (D_800A326C_A3E6C != 0) {
        amWaitForMidiSync();
        D_800A326C_A3E6C = 0;
    }
    arcadeScreen = 0;
    rumbleRumbles(1);
    D_800A3530_A4130 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/func_80046070.s")
#endif

#ifdef VERSION_kiosk
void mainSetAutoSave(s32 autoSave) {
    mainGameAutoSave = autoSave;
}
#endif

void mainSyncNextLevel(void) {
    D_800A326C_A3E6C = 1;
}

void mainSetMode(s32 modeToSet) {
    mainGameMode = modeToSet;
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainTitlePageInit(void) {
    s16 *entry;
    u16 mask;

    mainGameMode = 1;
    entry = &D_800A337C_A3F7C;
    D_800FD7C8_B3B18 = 1;
    if ((u16) entry[1] != (D_800FF391_B1D91 & (u16) entry[1])) {
        do {
            mask = (u16) entry[3];
            entry += 4;
        } while (mask != (D_800FF391_B1D91 & mask));
    }
    mainChangeLevel((s32) entry[0], 0, 0, 3, 1, 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainTitlePageInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainFrontInit(s32 arg0, s32 arg1, s32 arg2) {
    mainGameMode = 1;
    D_800FD7C8_B3B18 = 1;
    if (D_800FD7BC_B3B0C == 0) {
        D_800FD7BC_B3B0C = 1;
    }
    mainChangeLevel(arg1, (s32) D_800A3AB0, 0, arg0, 1, 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainFrontInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainStartGame(s32 *arg1) {
    u8 *game = (u8 *) gameplay;
    u8 *chr = game + (game[0] & 3) * 0x76;

    game[1] = (u8) (*(u16 *) (chr + 0x160) >> 5);
    game[2] = (u8) levelGetWorld((s16) game[1], arg1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainStartGame.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainSetDefaultGame(void *arg0) {
    u8 *game = (u8 *) arg0;
    s16 *tbl;
    u8 *chr;
    u8 *ent;
    s32 i;

    game[0] = 0;
    for (i = 0; i < 0x40; i++) {
        *(u16 *)(game + 0x5C + i * 2) = 0;
        *(u16 *)(game + 0xDC + i * 2) = 0;
    }
    for (i = 0; i < 0x28; i++) {
        ent = game + 0x334 + i * 8;
        ent[0] = 0;
        ent[1] = 0;
        *(u16 *)(ent + 2) = 0;
        *(u32 *)(ent + 4) = 0;
    }
    game[4] = 0;
    game[5] = 0;
    game[6] = 0x32;
    *(u16 *)(game + 0x530) = 0;
    *(u32 *)(game + 0x514) = 0;
    *(u32 *)(game + 0x518) = 0;
    for (i = 0; i < 0x10; i++) {
        *(u32 *)(game + 0x474 + i * 4) = 0;
        *(u32 *)(game + 0x4B4 + i * 4) = 0;
        *(u16 *)(game + 0x4F4 + i * 2) = 0;
    }
    for (i = 0; i < 0x20; i++) {
        game[0x08 + i] = 0;
    }
    for (i = 0; i < 0x08; i++) {
        game[0x28 + i] = 0;
    }
    for (i = 0; i < 0x8C; i++) {
        game[0x30 + i] = 0;
    }

    mainSetGameFlag(1, 1);

    /* asm loop: one character per table entry, stride 0x76, ends at &D_800A3B70 */
    tbl = &D_800A3314_A3F14;
    chr = game + 0x15C;
    do {
        mainSetDefaultCharacter(chr, (s32) *tbl);
        tbl++;
        chr += 0x76;
    } while (tbl != (s16 *) &D_800A3B70);

    *(u16 *)(game + 0x1C0) = 0;
    *(u16 *)(game + 0x236) = 0x400;
    *(u16 *)(game + 0x2AC) = 0;
    game[0x534] = 0;
    game[0x535] = 0;
    game[0x536] = 0;
    game[0x537] = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainSetDefaultGame.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainIncreaseWeaponKills(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 0x10)) {
        if (*(u16 *) ((u8 *) gameplay + arg0 * 2 + 0x4F4) < 0xFFFF) {
            *(u16 *) ((u8 *) gameplay + arg0 * 2 + 0x4F4) = (u16) (*(u16 *) ((u8 *) gameplay + arg0 * 2 + 0x4F4) + 1);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainIncreaseWeaponKills.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainIncreaseWeaponShots(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 0x10)) {
        if (*(u32 *) ((u8 *) gameplay + arg0 * 4 + 0x474) < 0xFFFFFFFFU) {
            *(u32 *) ((u8 *) gameplay + arg0 * 4 + 0x474) = *(u32 *) ((u8 *) gameplay + arg0 * 4 + 0x474) + 1;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainIncreaseWeaponShots.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainIncreaseWeaponHits(s32 arg0) {
    if ((arg0 >= 0) && (arg0 < 0x10)) {
        if (*(u32 *) ((u8 *) gameplay + arg0 * 4 + 0x4B4) < 0xFFFFFFFFU) {
            *(u32 *) ((u8 *) gameplay + arg0 * 4 + 0x4B4) = *(u32 *) ((u8 *) gameplay + arg0 * 4 + 0x4B4) + 1;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainIncreaseWeaponHits.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainInitMultiPlayer(void) {
    s32 i;

    for (i = 0; i < 4; i++) {
        mainSetDefaultCharacter((u8 *) &multiCharacter + i * 0x76, 0);
        (&multiCharacterType)[i] = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainInitMultiPlayer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainInitMultiPlayerPoints(void) {
    D_800FEDEC_B17EC = 0;
    D_800FEDE4_B17E4 = 0;
    D_800FEDE6_B17E6 = 0;
    D_800FEDE8_B17E8 = 0;
    D_800FEDEA_B17EA = 0;
    D_800FEE8C_B188C = 0;
    D_800FEE84_B1884 = 0;
    D_800FEE86_B1886 = 0;
    D_800FEE88_B1888 = 0;
    D_800FEE8A_B188A = 0;
    D_800FEF2C_B192C = 0;
    D_800FEF24_B1924 = 0;
    D_800FEF26_B1926 = 0;
    D_800FEF28_B1928 = 0;
    D_800FEF2A_B192A = 0;
    D_800FEFCC_B19CC = 0;
    D_800FEFC4_B19C4 = 0;
    D_800FEFC6_B19C6 = 0;
    D_800FEFC8_B19C8 = 0;
    D_800FEFCA_B19CA = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainInitMultiPlayerPoints.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Per-player refresh for 4 slots: clears the player block (stride 0xA0),
// stores the slot index and life/character type, then copies 0x76 bytes of
// multiCharacter for each slot into D_800FED66_B1766 (stride 0xA0).
// The asm copy loop runs 0x76 times (bnez tests the counter before the
// delay-slot decrement, so the m2c off-by-one is resolved here).
void mainRefreshMultiPlayer(void) {
    s32 i;
    s32 j;
    u8 *player;
    u8 *src;
    u8 *dst;

    for (i = 0; i < 4; i++) {
        player = (u8 *) &multiPlayer + i * 0xA0;
        *(s16 *) (player + 0x00) = 0;
        *(s16 *) (player + 0x02) = 0;
        *(s16 *) (player + 0x04) = 0;
        *(s16 *) (player + 0x06) = 0;
        *(s16 *) (player + 0x08) = 0;
        *(s16 *) (player + 0x0A) = 0;
        *(s16 *) (player + 0x0C) = 0;
        *(s16 *) (player + 0x0E) = 0;
        *(s16 *) (player + 0x10) = 0;
        player[0x8C] = (u8) i;
        *(s32 *) (player + 0x90) = 0;
        player[0x15] = 0;
        player[0x13] = multiGameLife;
        player[0x12] = (&multiCharacterType)[i];

        src = (u8 *) &multiCharacter + i * 0x76;
        dst = (u8 *) &D_800FED66_B1766 + i * 0xA0;
        for (j = 0; j < 0x76; j++) {
            dst[j] = src[j];
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainRefreshMultiPlayer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainSetDefaultCharacter(void *arg0, s32 arg1) {
    u8 *chr = (u8 *) arg0;
    u8 *def;
    s32 i;

    *(u16 *)(chr + 0x00) = 0x2200;
    *(u16 *)(chr + 0x04) = (u16) ((arg1 << 5) | (*(u16 *)(chr + 0x04) & 0x1F));
    *(u16 *)(chr + 0x02) = 6;
    *(u16 *)(chr + 0x74) = (u16) ((arg1 << 5) | (*(u16 *)(chr + 0x74) & 0x1F));
    chr[0x05] &= 0xE0;

    /* 16 weapon slots: copy weapon def fields into the character */
    for (i = 0; i < 0x10; i++) {
        def = (u8 *) controlGetWeaponDef(i);
        *(u16 *)(chr + 0x14 + i * 2) = 0;
        *(s16 *)(chr + 0x34 + i * 2) = *(s16 *)(def + 0x24);
        chr[0x54 + i] = def[0x03];
    }

    def = (u8 *) controlGetWeaponDef(0);
    chr[0x6F] = 1;
    chr[0x70] = 0;
    *(u16 *)(chr + 0x0A) = 1; /* asm: 1 << (0 & 0xFF) */
    *(u16 *)(chr + 0x0C) = 0;
    *(u16 *)(chr + 0x0E) = 0;
    *(u16 *)(chr + 0x10) = 0;
    *(u16 *)(chr + 0x12) = 0;
    *(s16 *)(chr + 0x14) = *(s16 *)(def + 0x28);
    for (i = 0; i < 8; i++) {
        chr[0x66 + i] = 0;
    }
    *(u16 *)(chr + 0x06) = 0;
    *(u16 *)(chr + 0x08) = 0;
    chr[0x75] &= 0xE0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainSetDefaultCharacter.s")
#endif

Game *mainGetGame(void) {
    return gameplay;
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *mainGetGameCharacter(s32 arg0, s32 arg1) {
    s32 idx;

    if ((multiPlayerGame != 0) && ((s32) numberOfPlayers >= 2)) {
        idx = arg0;
        if ((idx < 0) || (idx >= (s32) numberOfPlayers)) {
            idx = 0;
        }
        return (u8 *) &multiPlayer + idx * 0xA0 + 0x16;
    }
    return (u8 *) gameplay + (arg1 & 3) * 0x76 + 0x15C;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainGetGameCharacter.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainPlayerCollected(s32 arg0, s32 arg1, s32 arg2) {
    u8 *chr = (u8 *) mainGetGameCharacter(arg0, arg1);

    if (chr != NULL) {
        chr[0x66 + (arg2 >> 3)] |= (u8) (0x80 >> (arg2 & 7));
        D_800A32C8_A3EC8 |= 1 << (arg1 & 3);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainPlayerCollected.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainPlayerDropped(s32 arg0, s32 arg1, s32 arg2) {
    u8 *chr = (u8 *) mainGetGameCharacter(arg0, arg1);

    if (chr != NULL) {
        chr[0x66 + (arg2 >> 3)] &= (u8) ~(0x80 >> (arg2 & 7));
        D_800A32C8_A3EC8 |= 1 << (arg1 & 3);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainPlayerDropped.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 mainPlayerHas(s32 arg0, s32 arg1, s32 arg2) {
    u8 *chr = (u8 *) mainGetGameCharacter(arg0, arg1);

    if (chr != NULL && (chr[0x66 + (arg2 >> 3)] & (0x80 >> (arg2 & 7)))) {
        return 1;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainPlayerHas.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 mainAnyoneHas(s32 arg0) {
    s32 player;

    for (player = 0; player < 3; player++) {
        if (mainPlayerHas(0, player, arg0) != 0) {
            return 1;
        }
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainAnyoneHas.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 mainPlayerHasWeapon(s32 arg0, s32 arg1, s32 arg2) {
    u8 *chr = (u8 *) mainGetGameCharacter(arg0, arg1);

    if (chr != NULL && (*(u16 *) (chr + 0x0A) & (1 << arg2))) {
        return 1;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainPlayerHasWeapon.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 mainGetGameFlagGamePtr(Game *game, s32 flag) {
    if (flag >= 0 && flag < 0x480) {
        if (game->pad[0x30 + (flag >> 3)] & (1 << (flag & 7))) {
            return 1;
        }
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainGetGameFlagGamePtr.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 mainGetGameFlag(s32 flag) {
    return mainGetGameFlagGamePtr(gameplay, flag);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainGetGameFlag.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainSetGameFlag(s32 arg0, s32 arg1) {
    s32 saved[32];
    s32 *words;
    u8 *gf;
    s32 i;
    s32 lastIdx;

    if ((arg0 == 0x5B || arg0 == 0x5A) && D_800A3B70 == 0) {
        arg1 = 1;
    }
    if (arg0 < 0 || arg0 >= 0x480) {
        return;
    }
    if (arg1 == 0) {
        gameplay->pad[0x30 + (arg0 >> 3)] &= (u8) ~(1 << (arg0 & 7));
        return;
    }
    gameplay->pad[0x30 + (arg0 >> 3)] |= (u8) (1 << (arg0 & 7));

    /* snapshot of globalflags (32 words), compared again after the update */
    words = (s32 *) &globalflags;
    gf = (u8 *) &globalflags;
    for (i = 0; i < 32; i++) {
        saved[i] = words[i];
    }

    if (arg0 < 0x14) {
        if (arg0 < 4) {
            D_800FF391_B1D91 = (u8) (gf[0x79] | (1 << arg0));
        }
        D_800FF37C_B1D7C = *(s32 *) (gf + 0x64) | (1 << arg0);
    } else if (arg0 >= 0x42 && arg0 < 0x47) {
        gf[0x6A] |= (u8) (1 << ((arg0 + 0x1E) & 0x1F));
    } else if (arg0 >= 0x49 && arg0 < 0x4D) {
        gf[0x6B] |= (u8) (1 << ((arg0 + 0x17) & 0x1F));
    } else if (arg0 >= 0x52 && arg0 < 0x58) {
        *(u16 *) (gf + 0x68) |= (u16) (1 << ((arg0 + 0xE) & 0x1F));
    } else if (arg0 == 0x5F) {
        gf[0x79] |= 0x40;
        *(s32 *) (gf + 0x64) |= 0x70;
    } else if (arg0 == 0x5D) {
        gf[0x79] |= 0x80;
    }

    lastIdx = 0;
    for (i = 0; i < 32; i++) {
        if (words[i] != saved[i]) {
            mainSaveGlobalFlags(&saved[i + 1], lastIdx, arg0, &globalflags);
            return;
        }
        lastIdx = 31 - i;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainSetGameFlag.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainSetTribalStatus(s32 arg0, s32 arg1) {
    u8 *tribal;
    s32 bit;
    u16 flags5C;
    u16 flagsDC;

    tribal = (u8 *) gameplay + ((u8 *) levelGetLevel())[0x103] * 2;
    bit = 1 << (arg0 & 0xF);
    flags5C = *(u16 *) (tribal + 0x5C);
    if (!(flags5C & bit)) {
        flagsDC = *(u16 *) (tribal + 0xDC);
        if (!(flagsDC & bit)) {
            switch (arg1) {
            case 1:
                *(u16 *) (tribal + 0x5C) = (u16) (flags5C | bit);
                gameplay->pad[4] += 1;
                gameplay->pad[6] -= 1;
                break;
            case 2:
                *(u16 *) (tribal + 0xDC) = (u16) (flagsDC | bit);
                gameplay->pad[5] += 1;
                gameplay->pad[6] -= 1;
                break;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainSetTribalStatus.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 mainGetTribalStatus(s32 arg0) {
    u8 *tribal;
    s32 bit;

    tribal = (u8 *) gameplay + ((u8 *) levelGetLevel())[0x103] * 2;
    bit = 1 << (arg0 & 0xF);
    if (*(u16 *) (tribal + 0x5C) & bit) {
        return 1;
    }
    if (*(u16 *) (tribal + 0xDC) & bit) {
        return 2;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainGetTribalStatus.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainSetLevelWorld(s32 arg0, s32 arg1, u8 arg2) {
    u8 *base;

    if (arg1 >= 0) {
        base = (u8 *) gameplay + (arg0 & 3) * 0x76;
        gameplay->pad[1] = (u8) arg1;
        *(u16 *) (base + 0x160) = (u16) ((arg1 << 5) | (*(u16 *) (base + 0x160) & 0x1F));
        base[0x15C + 0x71] = arg2;
    }
    gameplay->pad[2] = arg2;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainSetLevelWorld.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 mainGetPauseMode(void) {
    return (s32) D_800FD7BD_B3B0D;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainGetPauseMode.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainSetPauseMode(s32 arg0) {
    D_800FD7BD_B3B0D = (s8) arg0;
    if (D_800FD7BD_B3B0D == 0) {
        if (runlinkIsModuleLoaded(0x13) != 0) {
            runlinkFreeCode(0x13);
        }
        amSetMuteMode(0);
    } else {
        amSetMuteMode(1);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainSetPauseMode.s")
#endif

extern OSMesgQueue resetMsgQueue;
extern s32 resetPressed;

s32 mainResetPressed(void) {
    if (resetPressed == 0) {
        resetPressed = (s32) ((osRecvMesg(&resetMsgQueue, NULL, OS_MESG_NOBLOCK) + 1) != 0);
    }
    return resetPressed;
}

s32 mainGetCurrentLevel(void) {
    return D_800A323C_A3E3C;
}

#ifdef VERSION_kiosk
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainGameChanged.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainLoadGame(s32 arg0) {
    load_save_flags = load_save_flags & ~7;
    load_save_flags = load_save_flags | 0x80000000 | (arg0 & 7);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainLoadGame.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainLoadAllGames(Game *arg0) {
    D_800FD7D8_B3B28 = arg0;
    load_save_flags |= 0x08000000;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainLoadAllGames.s")
#endif

Game *mainGetGameArrayPtr(void) {
    return D_800FD7D8_B3B28;
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainSaveGame(s32 arg0) {
    load_save_flags = load_save_flags & ~0x38;
    load_save_flags = load_save_flags | 0x40000000 | ((arg0 & 7) * 8);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainSaveGame.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainSaveGame2(s32 arg0) {
    if (mainGameMode == 0) {
        load_save_flags = (load_save_flags & ~0x38) | 0x40000000 | ((arg0 & 7) * 8);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainSaveGame2.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainDeleteGame(s32 arg0) {
    load_save_flags = ((arg0 & 7) << 6) | 0x20000000;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainDeleteGame.s")
#endif

void mainResetSaveGames(void) {
    load_save_flags = 0x10000000;
}

void mainEraseFlashRom(void) {
    load_save_flags = 0x01000000;
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainLoadGlobalFlags(void) {
    load_save_flags |= 0x04000000;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainLoadGlobalFlags.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainSaveGlobalFlags() {
    load_save_flags |= 0x02000000;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainSaveGlobalFlags.s")
#endif

void mainPauseDisable(s32 arg0) {
    D_800A32BC_A3EBC = arg0;
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 mainDemoOnly(void) {
    if (joyfail == -1) {
        return 1;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainDemoOnly.s")
#endif

s32 mainGetNumberOfCameras(void) {
    return numberOfCameras;
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 mainGetNumberOfPlayers(void) {
    s32 type = levelNGetType(D_800A323C_A3E3C);

    if (type == 1 || type == 2) {
        return 0;
    }
    if (multiPlayerGame == 0 && racingInGame == 0) {
        return 1;
    }
    return numberOfPlayers;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainGetNumberOfPlayers.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 mainGetPlayerCharacter(s32 arg0) {
    if (numberOfPlayers >= 2) {
        if (multiPlayerGame == 0 && racingInGame == 0) {
            return (u8)D_800A3240_A3E40;
        }
        return *((u8 *)&D_800FED62_B1762 + (arg0 & 3) * 0xA0);
    }
    return (u8)D_800A3240_A3E40;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainGetPlayerCharacter.s")
#endif

#ifdef VERSION_kiosk
#pragma GLOBAL_ASM("asm/nonmatchings/main/func_80047EE8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/main/func_80047FC0.s")

// Main debug menu
#pragma GLOBAL_ASM("asm/nonmatchings/main/func_8004809C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainResetRegion(void) {
    u8 *base = (u8 *)gameplay;
    s32 i;
    s32 j;

    for (i = 0; i < 0x80; i += 2) {
        *(s16 *)(base + i + 0x5C) = 0;
        *(s16 *)(base + i + 0xDC) = 0;
    }
    base[4] = 0;
    base[5] = 0;
    base[6] = tribaltable[D_800A3268_A3E68];
    *(s16 *)(base + 0x530) = 0;
    *(s32 *)(base + 0x514) = 0;
    i = 0;
    j = 0;
    do {
        *(s32 *)(base + i + 0x474) = 0;
        *(s32 *)(base + i + 0x4B4) = 0;
        *(s16 *)(base + j + 0x4F4) = 0;
        *(s32 *)(base + i + 0x478) = 0;
        *(s32 *)(base + i + 0x4B8) = 0;
        *(s16 *)(base + j + 0x4F6) = 0;
        *(s32 *)(base + i + 0x47C) = 0;
        *(s32 *)(base + i + 0x4BC) = 0;
        *(s16 *)(base + j + 0x4F8) = 0;
        *(s32 *)(base + i + 0x480) = 0;
        *(s32 *)(base + i + 0x4C0) = 0;
        *(s16 *)(base + j + 0x4FA) = 0;
        i += 0x10;
        j += 8;
    } while (i != 0x40);
    levelInitRegionFlags(0x40, 0x40);
    if (D_800A3298_A3E98 != 0) {
        levelGetRegionFlags();
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainResetRegion.s")
#endif

#ifdef VERSION_kiosk
void mainToggleDebug(void) {
    // debugMenuEnable ^= 1;
}
#else
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainToggleDebug(void) {
    u16 pressed = joyGetPressed(0);

    if (pressed != 0) {
        s32 next = debugInputCount + 1;

        if (pressed == debugInputCode[debugInputCount]) {
            debugInputCount = next;
            if (debugInputCode[next] == 0) {
                debugInputCount = 0;
                debugMenuEnable ^= 1;
            }
        } else {
            debugInputCount = 0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/mainToggleDebug.s")
#endif
#endif

// Draw debug menu Lower Right section
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void debug_print_memory(void) {
    char buf[32];
    u8 *level;
    s32 player;
    s32 i;
    s32 y;

    level = (u8 *)levelGetLevel();
    player = objGetPlayerNo(0);
    fontWindowSize(4, 0xC8, 0xC0, 0x128, 0xE4);
    fontWindowColour(4, 0, 0, 0, 0xA0);
    fontSetWindowNoise(0, 0, 0);
    fontWindowDraw(&gfx, &mtx, &vtx, 4);
    fontSetWindowNoise(0, 0x50, 0);
    fontUseFont(3);
    fontColour(0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    fontBackground(0, 0, 0, 0);
    if (level != NULL) {
        /* 32 bytes copied, upper-casing a-z; the asm writes no terminator */
        for (i = 0; i < 32; i++) {
            u8 c = level[i];

            if (c >= 0x61 && c < 0x7B) {
                c -= 0x20;
            }
            buf[i] = c;
        }
        fontPrintXY(&gfx, 0xD0, 0xC2, buf, 0);
    }
    if (player != 0) {
        sprintf(buf, "%5d  %5d  %5d\n", (s32) *(f32 *)((u8 *)player + 0xC), (s32) *(f32 *)((u8 *)player + 0x10),
                (s32) *(f32 *)((u8 *)player + 0x14));
        fontPrintXY(&gfx, 0xD0, 0xC8, buf, 0);
    }
    y = 0xD0;
    for (i = 0; i < 3; i++) {
        sprintf(buf, "FREE %d", i);
        fontPrintXY(&gfx, 0xD0, y, buf, 0);
        sprintf(buf, "%d K", gPoolRAMSize[i] / 1024);
        fontPrintXY(&gfx, 0xF0, y, buf, 0);
        y += 6;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/main/debug_print_memory.s")
#endif
