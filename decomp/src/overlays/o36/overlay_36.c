#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
void amInit(void *arg0);
void amInitAudioMap(void);
void animseqInit(void);
void arithmeticFunction(OSMesgQueue *queue1, OSMesgQueue *queue2);
void camlightInit(void);
void diPrintfInit(void);
void diRcpTraceInit(void);
void explosionFlushBlasts(void);
void fmvInit(void);
void fontInit(void);
void fxInit(void);
void fxInitLevelEffects(void);
void fxInitLines(void);
void initFront(void);
void mathSeed(u32 seed);
void modInitModels(void);
void objInitObjects(void);
void partInitLib(void);
void squadsInit(void);
void texInitTextures(void);
void levelGetCounts(void);
void mainSetDefaultGame(Game *game);
void mainInitMultiPlayer(void);
void func_overlay_36_02400250_1F55768(void);
void func_overlay_36_02400564_1F55A7C(void);
extern u8 D_overlay_36_02400750[];
extern u8 arithmeticSums[];
extern s32 D_overlay_36_024006D0[4];
extern s32 D_overlay_36_024006F0[4];
extern s32 D_overlay_36_02400710[4];
extern s32 D_overlay_36_02400730[4];
extern s32 D_overlay_36_024006DC;
extern s32 D_overlay_36_024006FC;
extern s32 D_overlay_36_0240071C;
extern s32 D_overlay_36_0240073C;
extern OSScClient resetClient;
extern void *resetMsgBuffer;
extern OSMesgQueue resetMsgQueue;
extern s32 resetPressed;
extern u8 *tribaltable;
extern s32 frame;
extern s32 joyfail;
extern Gfx *gfx;
extern Gfx *gfxBase[2];
extern void *mtxBase[2];
extern void *polBase[2];
extern void *vtxBase[2];
extern void *mtx;
extern void *pol;
extern void *vtx;
extern void *D_800FB414;
extern void *D_800FB424;
extern void *D_800FB434;
extern s32 currentalloc;
extern s32 MAX_gfx;
extern s32 MAX_mtx;
extern s32 MAX_pol;
extern s32 MAX_vtx;
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainInitRlo(void) {
    Gfx *temp;

    mainPreNMI();
    amInit(&sc);
    runlinkFreeCode(0x19);
    mainPreNMI();
    amInitAudioMap();
    joyfail = joyInit();
    texInitTextures();
    mainPreNMI();
    modInitModels();
    mainPreNMI();
    objInitObjects();
    runlinkFreeCode(0x22);
    mainPreNMI();
    explosionFlushBlasts();
    arithmeticFunction((OSMesgQueue *) D_overlay_36_02400750, (OSMesgQueue *) arithmeticSums);
    runlinkFreeCode(0x2D);
    mainPreNMI();
    diPrintfInit();
    mainPreNMI();
    partInitLib();
    runlinkFreeCode(0x1A);
    mainPreNMI();
    initWeather();
    mainPreNMI();
    func_overlay_36_02400250_1F55768();
    mainPreNMI();
    fxInitLines();
    fxInitLevelEffects();
    mainPreNMI();
    camlightInit();
    mainPreNMI();
    fontInit();
    runlinkFreeCode(0x23);
    mainPreNMI();
    packInit();
    mainPreNMI();
    initFront();
    mainPreNMI();
    animseqInit();
    fxInit();
    mainPreNMI();
    squadsInit();
    diRcpTraceInit();
    fmvInit();
    func_overlay_36_02400564_1F55A7C();
    osCreateMesgQueue(&resetMsgQueue, &resetMsgBuffer, 1);
    osScAddClient(&sc, &resetClient, &resetMsgQueue, 3U);
    resetPressed = 0;
    mainPreNMI();
    tribaltable = (u8 *) objGetTable(0x34);
    frame = 0;
    temp = gfxBase[0];
    gfx = temp + 1;
    temp->words.w0 = 0xE9000000;
    temp->words.w1 = 0;
    temp = gfx;
    gfx = temp + 1;
    temp->words.w1 = 0;
    temp->words.w0 = 0xB8000000;
    osSetTime(0);
    mathSeed(0xD43E);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o36/overlay_36/mainInitRlo.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_36_02400250_1F55768(void) {
    Game *game;

    levelGetCounts();
    Time[0] = 0;
    game = (Game *) mmAlloc(0x538, -1U);
    gameplay = game;
    mainSetDefaultGame(game);
    mainInitMultiPlayer();
    load_save_flags = 0x04000000;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o36/overlay_36/func_overlay_36_02400250_1F55768.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void listReallocate(s32 arg0) {
    s32 savedDelay;
    s32 total;
    s32 gfxCount;
    s32 mtxCount;
    s32 polCount;
    s32 vtxCount;
    u8 *base;

    if (arg0 != currentalloc) {
        currentalloc = arg0;
        savedDelay = mmGetDelay();
        mmSetDelay(0);
        total = (D_overlay_36_02400730[arg0] * 0x10) + (D_overlay_36_024006D0[arg0] * 8) + (D_overlay_36_02400710[arg0] << 6) + (D_overlay_36_024006F0[arg0] * 0xA);
        mmFree(gfxBase[0]);
        mmFree(gfxBase[1]);
        gfxBase[0] = mmAllocAtAddr(total, (u8 *) gfxBase[0], 0xFF0000FFU);
        gfxBase[1] = mmAllocAtAddr(total, (u8 *) gfxBase[1], 0xFFFF00FFU);
        if (gfxBase[0] == NULL || gfxBase[1] == NULL) {
            if (gfxBase[0] != NULL) {
                mmFree(gfxBase[0]);
                gfxBase[0] = NULL;
            }
            if (gfxBase[1] != NULL) {
                mmFree(gfxBase[1]);
                gfxBase[1] = NULL;
            }
            func_overlay_36_02400564_1F55A7C();
        }
        base = (u8 *) gfxBase[0];
        gfxCount = D_overlay_36_024006D0[arg0];
        mtxCount = D_overlay_36_02400710[arg0];
        polCount = D_overlay_36_02400730[arg0];
        vtxCount = D_overlay_36_024006F0[arg0];
        mtxBase[0] = base + (gfxCount * 8);
        polBase[0] = (u8 *) mtxBase[0] + (mtxCount << 6);
        vtxBase[0] = (u8 *) polBase[0] + (polCount * 0x10);
        D_800FB414 = (u8 *) gfxBase[1] + (gfxCount * 8);
        D_800FB434 = (u8 *) mtxBase[1] + (mtxCount << 6);
        D_800FB424 = (u8 *) polBase[1] + (polCount * 0x10);
        MAX_gfx = gfxCount;
        MAX_mtx = mtxCount;
        MAX_pol = polCount;
        MAX_vtx = vtxCount;
        mmSetDelay(savedDelay);
    }
    gfx = gfxBase[frame];
    mtx = mtxBase[frame];
    pol = polBase[frame];
    vtx = vtxBase[frame];
    gfx->words.w0 = 0xE9000000;
    gfx->words.w1 = 0;
    gfx++;
    gfx->words.w0 = 0xB8000000;
    gfx->words.w1 = 0;
    gfx++;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o36/overlay_36/listReallocate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_36_02400564_1F55A7C(void) {
    u8 *base;
    s32 total;

    currentalloc = 3;
    total = (D_overlay_36_0240073C * 0x10) + (D_overlay_36_024006DC * 8) + (D_overlay_36_0240071C << 6) + (D_overlay_36_024006FC * 0xA);
    base = (u8 *) mmAlloc(total, 0xFF0000FF);
    gfxBase[0] = (Gfx *) base;
    mtxBase[0] = base + (D_overlay_36_024006DC * 8);
    vtxBase[0] = (u8 *) mtxBase[0] + (D_overlay_36_0240071C << 6);
    polBase[0] = (u8 *) vtxBase[0] + (D_overlay_36_024006FC * 0xA);
    base = (u8 *) mmAlloc(total, 0xFFFF00FF);
    gfxBase[1] = (Gfx *) base;
    D_800FB414 = base + (D_overlay_36_024006DC * 8);
    D_800FB424 = (u8 *) D_800FB414 + (D_overlay_36_0240071C << 6);
    D_800FB434 = (u8 *) D_800FB424 + (D_overlay_36_024006FC * 0xA);
    MAX_gfx = D_overlay_36_024006DC;
    MAX_mtx = D_overlay_36_0240071C;
    MAX_pol = D_overlay_36_0240073C;
    MAX_vtx = D_overlay_36_024006FC;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o36/overlay_36/func_overlay_36_02400564_1F55A7C.s")
#endif
