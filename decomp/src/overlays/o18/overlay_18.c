#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
extern Gfx *frontgfx;
extern MatrixS *frontmtx;
extern Vtx *frontvtx;
extern u8 *front_text;
extern s8 frontJoyDx[];
extern void *frontendptrs[];
extern u8 currentobjects[];
extern s32 objtrans;
extern s32 pausePlayer;
extern s32 D_800FF65C;
extern s16 D_800FFA86;
extern s16 D_800FFAC0;
extern s16 D_800FFAC6;
extern f32 D_800FFAC8;
extern s16 D_800FFB66;

extern s16 D_overlay_18_01206684;
extern s16 D_overlay_18_0120668C;
extern s32 D_overlay_18_01206BDC;
extern s32 D_overlay_18_01206BE4;
extern s16 D_overlay_18_01206694;
extern s16 D_overlay_18_012066A0;
extern s16 D_overlay_18_01206718;
extern s16 D_overlay_18_01206724;
extern f32 D_overlay_18_0120675C[];
extern u8 D_overlay_18_01206774[];
extern void *D_overlay_18_01206CB0[];
extern f32 D_overlay_18_01206CD0[];
extern u8 D_overlay_18_01206CF8;
extern s32 D_overlay_18_01206CFC;
extern s32 D_overlay_18_01206D00;
extern s8 D_overlay_18_01206D04;
extern s8 D_overlay_18_01206D05;
extern s8 D_overlay_18_01206D07;
extern s8 D_overlay_18_01206D08;
extern s8 D_overlay_18_01206D09;
extern s16 D_overlay_18_01206D0A;
extern s16 D_overlay_18_01206D0C;
extern s16 D_overlay_18_01206D0E;
extern MemoryPoolSlot *D_overlay_18_01206D10;
extern s16 D_overlay_18_01206D14;
extern s16 D_overlay_18_01206D16;
extern s32 D_overlay_18_01206680;
extern f32 D_overlay_18_01206CF0;
extern f32 D_overlay_18_01206CF4;
extern f32 D_overlay_18_01206B70;
extern f32 D_overlay_18_01206B84;
extern u8 D_overlay_18_01206779[];
extern void *D_800FF56C;
extern u8 NullTextureOffsets[];
void matrixScale(f32 x, f32 y, f32 z, void *mtx);
void camPushFloatModelMtx(Gfx **dList, MatrixS **mtx, void *arg2);
void objAnimTextures(void *arg0, void *arg1, void *arg2, s8 arg3);

extern u8 D_overlay_18_012066AC;
extern u8 D_overlay_18_012066B0;
extern s16 D_overlay_18_012066F8[];
extern f32 D_overlay_18_012066B4[];
extern char D_overlay_18_01206AF8[];
extern char D_overlay_18_01206B00[];
extern char D_overlay_18_01206B08[];
extern char D_overlay_18_01206B14[];
extern f32 D_overlay_18_01206B68;
extern f32 D_overlay_18_01206B6C;
extern s32 D_overlay_18_01206BCC;
extern s32 D_overlay_18_01206C88;
extern s32 D_overlay_18_01206C8C;
extern s32 D_overlay_18_01206C90;
extern s32 D_overlay_18_01206C94;
extern s16 D_overlay_18_01206C98[4];
extern f32 D_overlay_18_01206CA0;
extern f32 D_overlay_18_01206CA4;
extern s16 D_overlay_18_01206CA8;

s32 func_overlay_18_0120207C_1F31A54(s8 *arg0);
void func_overlay_18_01200000_1F2F9D8(void);
void func_overlay_18_01201194_1F30B6C(s32 arg0);
void func_overlay_18_012011E4_1F30BBC(void);
void func_overlay_18_01201218_1F30BF0(void *arg0);
void func_overlay_18_01201294_1F30C6C(void *arg0);
void func_overlay_18_012040A8_1F33A80(f32 arg0, s32 arg1);
void weaponScreenSetupDpad(void);
void weaponScreenFreeDpad(void);

void rcpClearScreen(Gfx **dlist, MatrixS **mtxp, s32 arg2);
void camSetFOV(f32 fov, s32 force);
void camSetNo(s32 arg0);
void camSetView(Gfx **dlist, MatrixS **mtxp);
void camStandardPersp(Gfx **dlist, MatrixS **mtxp);
void camStandardOrtho(Gfx **dlist, MatrixS **mtxp);
void camOverrideProjScales(f32 arg0, f32 arg1);
void camDo2DSprite(Gfx **dlist, MatrixS **mtxp, Vtx **vtxp, s16 *spr, void *tex, s32 arg5, s32 arg6);
s32 frontGetScreenMode(void);
void viFrameRateReset(void);
void frontMapInitWorldIcons(void);
void frontMapCleanupWorldIcons(void);
void loadFrontEndList(s16 *arg0);
void setupFrontEndList(s16 *arg0);
void freeFrontEndList(s16 *arg0);
void loadFrontEndItem(s32 arg0);
void freeFrontEndItem(s32 arg0);
void *objGetPlayerNo(s32 player);
void *mainGetGameCharacter(s8 a, s8 b);
void *objSetupObject(void *params, s32 arg1);
void objAnimDframe(void *obj, f32 arg1, f32 arg2);
void partUpdateTriggers(void *obj, s32 arg1);
void frontDrawObj(s32 arg0);
void fontUseFont(s32 font);
void fontColour(s32 red, s32 green, s32 blue, s32 alpha, s32 opacity);
void fontPrintXY(Gfx **dlist, s32 xpos, s32 ypos, char *text, s32 alignmentFlags);
void amSndPlay(u16 soundID, void *handlePtr);
void pauseSetScreen(s32 arg0);
void lightSetObjectLight(s32 arg0, s32 arg1, s32 arg2, s16 arg3, s32 arg4, s32 arg5);
MemoryPoolSlot *mmAlloc(s32 size, u32 colourTag);
void objFreeObject(void *obj);
void objDoFrees(void);
s32 mainGetGameFlag(s32 flag);
void frontCharBadge(s32 arg0, s32 arg1, s32 arg2);
void frontMapDrawWorldIcon(s32 world, s32 x, s32 y, s32 arg3);
char *frontGetWorldName(s32 world);
void frontGetHourTime(s32 time, s32 *hours, s32 *mins, s32 *secs, s32 *arg4);
s32 levelGetWorldRegions(s32 arg0, u8 *arg1);
void objAnimSetMove(void *obj, s32 move, s32 arg2);
void modSetTextureFrame(void *obj, s32 idx, s32 frame);
void camDisableUserView(s32 arg0, s32 arg1);
void camEnableUserView(s32 arg0, s32 arg1);
void *camGetPtr(void);
void camSetUserView(s32 a, s32 b, s32 c, s32 d, s32 e);
void camSetUserViewSpecial(s32 a, s32 b, s32 c, s32 d, s32 e);
void camUserViewTick(void);
s16 dAngle(s16 cur, s16 target, s32 rate, f32 *spd);
void lightObject(void *obj, void *model, s32 arg2, s32 arg3);
void modGenAnimMatrices(void *obj, void *anim, void *arg2, f32 arg3, f32 arg4);
void texDPTextureX(Gfx **dlist, s32 a, s32 b, s32 c);
void func_overlay_18_01205800_1F351D8(s32 arg0);
s32 func_overlay_18_01205850_1F35228(s32 arg0);
void func_overlay_18_01205880_1F35258(s32 arg0);
void func_overlay_18_01205A24_1F353FC(s16 arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg4);
s32 camProjectPoint(f32 x, f32 y, f32 z, f32 *sx, f32 *sy, s32 flag);
void frontDrawRectangles(Gfx **gfxp, s32 count, void *rects, s32 flag);
extern void *D_overlay_18_01206BFC;
extern s8 D_overlay_18_01206BF9;
extern s8 D_overlay_18_01206BFA;
extern s8 D_overlay_18_01206BFB;
extern s16 D_overlay_18_0120692C[];
extern s16 D_overlay_18_01206930[];
extern s32 D_overlay_18_01206C60;
extern s32 D_overlay_18_01206C64;
extern s32 D_overlay_18_01206C68;
extern s32 D_overlay_18_01206C6C;
extern s32 D_overlay_18_01206C70;
extern s32 D_overlay_18_01206C74;
extern s32 D_overlay_18_01206C78;
extern s32 D_overlay_18_01206C7C;
extern s32 D_overlay_18_01206C80;
extern s32 D_overlay_18_01206C84;
void func_overlay_18_012057D8_1F351B0(void);
extern void *D_800FF614;
extern void *D_800FF618;
extern void *D_800FF5E4;
extern s32 D_800FF5B4[];
extern u8 D_800FF800[];
extern f32 D_800FF928;
extern f32 D_800FF92C;
extern f32 D_800FF930;
extern f32 D_800FF938;
extern f32 D_800FFE28;
extern f32 D_800FFE2C;
extern f32 D_800FFE30;
extern u8 tribaltable[];
extern u8 D_81206670[];
extern s16 D_overlay_18_01206BB0[4];
extern s16 D_overlay_18_012067E0;
extern s16 D_overlay_18_012067E8;
extern s16 D_overlay_18_012067F4[];
extern s16 D_overlay_18_01206D18;
extern s8 D_overlay_18_01206D1A;
extern s8 D_overlay_18_01206D1B;
extern s8 D_overlay_18_01206808[4];
extern char D_overlay_18_01206B1C[];
extern char D_overlay_18_01206A40[];
extern char D_overlay_18_01206A44[];
extern char D_overlay_18_01206A48[];
extern char D_overlay_18_01206A4C[];
extern char D_overlay_18_01206A58[];
extern char D_overlay_18_01206A5C[];
extern char D_overlay_18_01206A60[];
extern char D_overlay_18_01206A64[];
extern char D_overlay_18_01206A70[];
extern char D_overlay_18_01206A74[];
extern char D_overlay_18_01206A78[];
extern char D_overlay_18_01206A7C[];
extern u8 D_overlay_18_01206BF8[];
extern s16 D_overlay_18_01206810;
extern s16 D_overlay_18_0120681C;
extern s16 D_overlay_18_0120682C[];
extern u8 D_overlay_18_01206874[];
extern s16 D_overlay_18_01206880[];
extern s16 D_overlay_18_01206898[];
extern s16 D_overlay_18_012068B0[];
extern s16 D_overlay_18_012068B2[];
extern f32 D_overlay_18_012068E0[];
extern u8 D_overlay_18_01206914[];
extern u8 D_overlay_18_01206920[];
extern f32 D_overlay_18_01206B88;
extern f32 D_overlay_18_01206B8C;
extern s8 D_overlay_18_01206BD0;
extern s8 D_overlay_18_01206BD1;
extern s8 D_overlay_18_01206BD2;
extern s8 D_overlay_18_01206BD3;
extern s8 D_overlay_18_01206BD4;
extern s8 D_overlay_18_01206BD5;
extern s8 D_overlay_18_01206BD6;
extern s16 D_overlay_18_01206BD8;
extern s16 D_overlay_18_01206BE0;
extern s16 D_overlay_18_01206BE8;
extern f32 D_overlay_18_01206BEC;
extern f32 D_overlay_18_01206BF0;
extern u8 D_overlay_18_01206BF4;
extern u8 D_overlay_18_01206BF5;
extern u8 D_overlay_18_01206BF6;
extern s16 D_overlay_18_01206938[];
extern s32 D_overlay_18_012069D0[];
extern s16 D_overlay_18_012069EC[];
extern u8 D_overlay_18_012069F0[];
extern u8 D_81206A30[];
extern s16 D_overlay_18_01206C10[];
extern f32 D_overlay_18_012067B8;
extern f32 D_overlay_18_01206B90;
extern f32 D_overlay_18_01206B94;
extern f32 D_overlay_18_01206B98;
extern f32 D_overlay_18_01206B9C;
extern f32 D_overlay_18_01206BA0;
extern char D_overlay_18_01206B2C[];
extern char D_overlay_18_01206B30[];
extern char D_overlay_18_01206B34[];
extern void *D_800FF63C;
extern void *D_800FF678;
extern u8 D_overlay_18_0120672C[];
extern u8 D_overlay_18_01206778[];
extern s8 D_overlay_18_012067B4;
extern s8 D_overlay_18_012067BC[];
extern s8 D_overlay_18_012067C0[];
extern s16 D_overlay_18_012067C4;
extern s32 D_overlay_18_012067C8[];
extern f32 D_overlay_18_01206B74;
extern f32 D_overlay_18_01206B78;
extern f32 D_overlay_18_01206B7C;
extern f32 D_overlay_18_01206B80;
extern s16 D_overlay_18_01206BB8;
extern s16 D_overlay_18_01206BBA;
extern s8 D_overlay_18_01206D06;
extern u8 D_overlay_18_0120676C[];
extern void *D_800FF66C;
extern s32 D_800FF674;
extern s8 frontJoyDy[];
s32 frontGetSelectableCharacter(s32 arg0, s32 arg1);
void func_overlay_18_01203BB4_1F3358C(s32 arg0, s8 arg1);
void amTuneStop(void);
void camDoSprite(Gfx **dlist, MatrixS **mtxp, Vtx **vtxp, s16 *spr, void *tex, s32 arg5, s32 arg6);
s32 levelGetRegionNo(u32 arg0);
void mainSaveGame(s8 arg0);
void mainValidateRestart(u32 *arg0, s32 *arg1, s32 *arg2);
void objMakeGunMtx(void *a, void *b, void *c, s32 d, void *e, void *f, void *g, void *h);
s8 pauseGetPauseCharacter(void);
void pauseSetNewLevel(u32 arg0, s8 arg1, s32 arg2, s32 arg3);
void rcpTileWrite(Gfx **dlist, s32 *tile, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
s32 mainPlayerHas(s8 player, s8 charIdx, s16 item);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_18_01200000_1F2F9D8(void) {
    rcpClearScreen(&frontgfx, &frontmtx, 0);
    texDPInit(&frontgfx);
    frontgfx->words.w1 = -1U;
    frontgfx->words.w0 = 0xF8000000;
    frontgfx++;
    frontgfx->words.w0 = 0xBC000008;
    frontgfx->words.w1 = 0x64009867;
    frontgfx++;
    frontgfx->words.w1 = 0;
    frontgfx->words.w0 = 0xE7000000;
    frontgfx++;
    camSetNo(0);
    camSetFOV(52.0f, 1);
    camSetView(&frontgfx, 0);
    camStandardPersp(&frontgfx, &frontmtx);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/func_overlay_18_01200000_1F2F9D8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void tribalScreenInit(void) {
    s32 sp18;

    sp18 = func_overlay_18_0120207C_1F31A54(*(s8 **)((u8 *)objGetPlayerNo(0) + 0x68));
    loadFrontEndList(&D_overlay_18_01206684);
    setupFrontEndList(&D_overlay_18_0120668C);
    frontMapInitWorldIcons();
    D_overlay_18_01206BDC = *(u8 *)((u8 *)mainGetGame() + sp18 * 0x76 + 0x1CD);
    D_800FFB66 = 0x90;
    D_overlay_18_01206BE4 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/tribalScreenInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void tribalScreenCleanup(void) {
    freeFrontEndList(&D_overlay_18_01206684);
    frontMapCleanupWorldIcons();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/tribalScreenCleanup.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void tribalScreen(s32 arg0) {
    u8 regionIds[16];
    char text[32];
    LevelHeader *level;
    u8 *game;
    u8 *entry;
    s32 sumUnk334;
    s32 sumUnk335;
    s32 sumLeft;
    s32 sumUnk338;
    s32 extraRegion;
    s32 left;
    s32 right;
    s32 prevWorld;
    s32 found;
    s32 t;
    s32 count;
    s32 k;
    s32 region;
    s32 rowY;
    s32 v334;
    s32 v335;
    s32 leftover;
    s32 hours;
    s32 mins;
    s32 secs;
    s32 unusedTime;
    s32 joy;
    f32 savedD928;
    f32 savedE28;

    sumUnk334 = 0;
    sumUnk335 = 0;
    sumLeft = 0;
    sumUnk338 = 0;
    left = 0;
    right = 0;
    level = levelGetLevel();
    func_overlay_18_01200000_1F2F9D8();
    camOverrideProjScales(1.0f, 1.0f);
    camSetFOV(52.0f, 1);
    camStandardPersp(&frontgfx, &frontmtx);
    frontDrawObj(0x1F);
    switch (D_overlay_18_01206BDC) {
    case 1:
    case 2:
    case 3:
    case 6:
    case 8:
    case 9:
    case 12:
        frontMapDrawWorldIcon(D_overlay_18_01206BDC, -0x55, 0x3C, arg0);
        break;
    default:
        frontMapDrawWorldIcon(D_overlay_18_01206BDC, -0x46, 0x3C, arg0);
        break;
    }
    fontUseFont(2);
    fontColour(0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    fontPrintXY(&frontgfx, 0x5A, 0x5A, frontGetWorldName(D_overlay_18_01206BDC), 4);

    game = (u8 *) mainGetGame();
    if (D_overlay_18_01206BE4 == 0) {
        joy = frontJoyDx[pausePlayer];
        right = joy >= 0x21;
        left = joy < -0x20;
    }

    prevWorld = D_overlay_18_01206BDC;
    if (left) {
        found = 0;
        t = D_overlay_18_01206BDC - 1;
        do {
            D_overlay_18_01206BDC = t;
            if (t < 0) {
                D_overlay_18_01206BDC = 0xE;
            }
            if ((*(u16 *)(game + 0x236) & (1 << D_overlay_18_01206BDC))
                || (mainGetGameFlag(0) != 0 && (*(u16 *)(game + 0x1C0) & (1 << D_overlay_18_01206BDC)))
                || (mainGetGameFlag(2) != 0 && (*(u16 *)(game + 0x2AC) & (1 << D_overlay_18_01206BDC)))) {
                found = 1;
            }
            t = D_overlay_18_01206BDC - 1;
        } while (found == 0);
        if (prevWorld != D_overlay_18_01206BDC) {
            amSndPlay(0x16B, NULL);
        } else {
            amSndPlay(0x16E, NULL);
        }
    }
    if (right) {
        found = 0;
        t = D_overlay_18_01206BDC + 1;
        do {
            D_overlay_18_01206BDC = t;
            if (t >= 0xF) {
                D_overlay_18_01206BDC = 0;
            }
            if ((*(u16 *)(game + 0x236) & (1 << D_overlay_18_01206BDC))
                || (mainGetGameFlag(0) != 0 && (*(u16 *)(game + 0x1C0) & (1 << D_overlay_18_01206BDC)))
                || (mainGetGameFlag(2) != 0 && (*(u16 *)(game + 0x2AC) & (1 << D_overlay_18_01206BDC)))) {
                found = 1;
            }
            t = D_overlay_18_01206BDC + 1;
        } while (found == 0);
        if (prevWorld != D_overlay_18_01206BDC) {
            amSndPlay(0x16B, NULL);
        } else {
            amSndPlay(0x16E, NULL);
        }
    }

    camStandardOrtho(&frontgfx, &frontmtx);
    *(f32 *)(currentobjects + 0x1AC) = 13.0f;
    *(f32 *)(currentobjects + 0x1B0) = 68.0f;
    *(f32 *)(currentobjects + 0x1B8) = 0.0f;
    frontDrawObj(0xD);
    D_800FF938 = 1.0f;
    D_800FF92C += 41.0f;
    frontDrawObj(0xD);
    D_800FF938 = 2.0f;
    D_800FF92C += 41.0f;
    frontDrawObj(0xD);
    D_800FF92C = -13.0f;
    D_800FF930 = -5.0f;
    D_800FF938 = 0.0f;
    savedD928 = D_800FF928;
    D_800FF928 *= 0.75f;
    frontDrawObj(0xD);
    D_800FF938 = 1.0f;
    D_800FF92C += 30.0f;
    frontDrawObj(0xD);
    D_800FF938 = 2.0f;
    D_800FF92C += 30.0f;
    frontDrawObj(0xD);
    D_800FF928 = savedD928;
    *(f32 *)(currentobjects + 0x6AC) = 18.0f;
    *(f32 *)(currentobjects + 0x6B0) = 28.0f;
    frontDrawObj(0x35);
    D_800FFE2C = 90.0f;
    savedE28 = D_800FFE28;
    D_800FFE30 = -5.0f;
    D_800FFE28 *= 0.75f;
    frontDrawObj(0x35);
    D_800FFE28 = savedE28;

    count = levelGetWorldRegions(D_overlay_18_01206BDC, regionIds);
    rowY = 0x88;
    for (k = 0; k < count; k++) {
        region = regionIds[k];
        entry = game + (region * 8);
        v334 = entry[0x334];
        v335 = entry[0x335];
        sumUnk334 += v334;
        sumUnk335 += v335;
        leftover = (tribaltable[region] - v334) - v335;
        sumLeft += leftover;
        sumUnk338 += *(s32 *)(entry + 0x338);

        fontPrintXY(&frontgfx, 0x82, rowY, *(char **)(front_text + (region * 4) + 0x65C), 1);
        sprintf(text, D_overlay_18_01206A40, leftover);
        fontPrintXY(&frontgfx, 0x96, rowY, text, 1);
        sprintf(text, D_overlay_18_01206A44, v334);
        fontPrintXY(&frontgfx, 0xB4, rowY, text, 1);
        sprintf(text, D_overlay_18_01206A48, v335);
        fontPrintXY(&frontgfx, 0xD2, rowY, text, 1);
        frontGetHourTime(*(s32 *)(entry + 0x338), &hours, &mins, &secs, &unusedTime);
        sprintf(text, D_overlay_18_01206A4C, hours, mins, secs);
        fontPrintXY(&frontgfx, 0x10E, rowY, text, 1);
        rowY += 0xE;
    }

    if (D_overlay_18_01206BDC == *(s8 *)((u8 *)level + 0x20)) {
        extraRegion = *(u8 *)((u8 *)level + 0x102);
        if (extraRegion != 0xFF && extraRegion != 0) {
            fontColour(0, 0xFF, 0, 0xFF, 0xFF);
            fontPrintXY(&frontgfx, 0x82, rowY, *(char **)(front_text + (extraRegion * 4) + 0x65C), 1);
            sprintf(text, D_overlay_18_01206A58, game[6]);
            fontPrintXY(&frontgfx, 0x96, rowY, text, 1);
            sprintf(text, D_overlay_18_01206A5C, game[4]);
            fontPrintXY(&frontgfx, 0xB4, rowY, text, 1);
            sprintf(text, D_overlay_18_01206A60, game[5]);
            fontPrintXY(&frontgfx, 0xD2, rowY, text, 1);
            frontGetHourTime(*(s32 *)(game + 0x514), &hours, &mins, &secs, &unusedTime);
            sprintf(text, D_overlay_18_01206A64, hours, mins, secs);
            fontPrintXY(&frontgfx, 0x10E, rowY, text, 1);
            fontColour(0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        }
    }

    sprintf(text, D_overlay_18_01206A70, sumLeft);
    fontPrintXY(&frontgfx, 0xAF, 0x48, text, 4);
    sprintf(text, D_overlay_18_01206A74, sumUnk334);
    fontPrintXY(&frontgfx, 0xD8, 0x48, text, 4);
    sprintf(text, D_overlay_18_01206A78, sumUnk335);
    fontPrintXY(&frontgfx, 0x101, 0x48, text, 4);
    frontGetHourTime(sumUnk338, &hours, &mins, &secs, &unusedTime);
    sprintf(text, D_overlay_18_01206A7C, hours, mins, secs);
    fontPrintXY(&frontgfx, 0xF0, 0x5A, text, 1);
    if (joyGetPressed(pausePlayer) & 0x4000) {
        pauseSetScreen(1);
        D_overlay_18_01206BE4 = 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/tribalScreen.s")
#endif


#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void weaponScreenSetupDpad(void) {
    u8 *game = (u8 *)mainGetGame();
    s16 listA[4];
    s16 listB[4];
    s32 countA = 0;
    s32 countB = 0;
    s32 found;
    s32 i;
    s32 j;
    s16 v;

    for (i = 0; i < 4; i++) {
        v = D_overlay_18_01206C98[i];
        if (v != -1) {
            found = 0;
            for (j = 0; j < countA; j++) {
                if (v == listA[j]) {
                    found = 1;
                }
            }
            if (found == 0) {
                listA[countA] = v;
                countA++;
            }
        }
    }

    for (i = 0; i < 4; i++) {
        v = (s16) (game[i + 0x534] + 0xA);
        D_overlay_18_01206C98[i] = v;
        found = 0;
        for (j = 0; j < countB; j++) {
            if (v == listB[j]) {
                found = 1;
            }
        }
        if (found == 0) {
            listB[countB] = v;
            countB++;
        }
    }

    for (i = 0; i < countA; i++) {
        v = listA[i];
        found = 0;
        for (j = 0; j < countB; j++) {
            if (v == listB[j]) {
                found = 1;
            }
        }
        if (found == 0) {
            freeFrontEndItem(v);
        }
    }

    for (i = 0; i < countB; i++) {
        v = listB[i];
        found = 0;
        for (j = 0; j < countA; j++) {
            if (v == listA[j]) {
                found = 1;
            }
        }
        if (found == 0) {
            loadFrontEndItem(v);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/weaponScreenSetupDpad.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void weaponScreenFreeDpad(void) {
    s32 idx;
    s32 k;
    s16 v;

    for (idx = 0; idx < 4; idx++) {
        v = D_overlay_18_01206C98[idx];
        if (v != -1) {
            freeFrontEndItem(v);
            for (k = idx + 1; k < 4; k++) {
                if (v == D_overlay_18_01206C98[k]) {
                    D_overlay_18_01206C98[k] = -1;
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/weaponScreenFreeDpad.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void weaponScreenInit(void) {
    s8 *playerData;
    void *chr;
    s32 k;

    playerData = *(s8 **)((u8 *)objGetPlayerNo(0) + 0x68);
    loadFrontEndList(&D_overlay_18_01206694);
    setupFrontEndList(&D_overlay_18_012066A0);
    chr = mainGetGameCharacter(playerData[0], func_overlay_18_0120207C_1F31A54(playerData));
    func_overlay_18_01201194_1F30B6C(*(s8 *)((u8 *)chr + 0x70));
    D_overlay_18_01206CA0 = 0.0f;
    D_overlay_18_01206CA4 = D_overlay_18_012066B4[*(s8 *)((u8 *)chr + 0x70)];
    D_overlay_18_01206CA8 = 0x1E;
    D_overlay_18_01206BCC = 0;
    if (frontGetScreenMode() & 1) {
        *(f32 *)(currentobjects + 0x30C) = *(f32 *)(currentobjects + 0x30C) * D_overlay_18_01206B68;
    }
    D_overlay_18_01206C88 = 0xFF;
    D_overlay_18_01206C8C = 0;
    D_overlay_18_01206C90 = 0;
    for (k = 0; k < 4; k++) {
        D_overlay_18_01206C98[k] = -1;
    }
    D_overlay_18_01206C94 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/weaponScreenInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void weaponScreenCleanup(void) {
    void *temp_v0;
    u8 *temp_v1;

    weaponScreenFreeDpad();
    temp_v0 = objGetPlayerNo(0);
    if (temp_v0 != NULL) {
        temp_v1 = *(u8 **)((u8 *)temp_v0 + 0x68);
        temp_v1[0x585] = D_overlay_18_012066B0;
    }
    freeFrontEndList(&D_overlay_18_01206694);
    func_overlay_18_012011E4_1F30BBC();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/weaponScreenCleanup.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_18_01201194_1F30B6C(s32 arg0) {
    D_overlay_18_012066AC = arg0 + 0x4A;
    D_overlay_18_012066B0 = arg0;
    loadFrontEndItem(D_overlay_18_012066AC);
    D_800FFA86 = (s16) D_overlay_18_012066AC;
    viFrameRateReset();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/func_overlay_18_01201194_1F30B6C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_18_012011E4_1F30BBC(void) {
    s32 idx;

    if (D_overlay_18_012066AC != 0) {
        idx = D_overlay_18_012066AC;
        freeFrontEndItem(idx);
        D_overlay_18_012066AC = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/func_overlay_18_012011E4_1F30BBC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_18_01201218_1F30BF0(void *arg0) {
    s32 idx = D_overlay_18_012066B0;
    u16 mask = *(u16 *)((u8 *)arg0 + 0xA);

    do {
        idx += 1;
        if (idx >= 0xF) {
            idx = 0;
        }
    } while (!(D_overlay_18_012066F8[idx] & mask));
    if (idx != D_overlay_18_012066B0) {
        func_overlay_18_012011E4_1F30BBC();
        func_overlay_18_01201194_1F30B6C((s8) idx);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/func_overlay_18_01201218_1F30BF0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_18_01201294_1F30C6C(void *arg0) {
    s32 idx = D_overlay_18_012066B0;
    u16 mask = *(u16 *)((u8 *)arg0 + 0xA);

    do {
        idx -= 1;
        if (idx < 0) {
            idx = 0xE;
        }
    } while (!(D_overlay_18_012066F8[idx] & mask));
    if (idx != D_overlay_18_012066B0) {
        func_overlay_18_012011E4_1F30BBC();
        func_overlay_18_01201194_1F30B6C((s8) idx);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/func_overlay_18_01201294_1F30C6C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void weaponScreen(s32 arg0) {
    u8 *game;
    u8 *chr2;
    u8 *obj;
    u8 *sp70;
    void *chr;
    s8 *playerData;
    u16 pressed;
    s32 prevDpad;
    s32 joyDx;
    s32 sel;
    s32 idx2;
    s32 temp_t9;
    s32 temp_t2;
    s32 temp_t2_2;
    s32 temp_t3;
    s32 temp_t6;
    s32 temp_v1;
    u32 temp_v1_3;
    f32 argF;
    f32 pct;
    f32 var_f8;
    f32 f28;
    char buf[12];
    s16 *cur300;
    s16 *cur304;
    struct {
        s16 unk0;
        s16 unk2;
        s16 unk4;
        f32 unk8;
        f32 unkC;
        f32 unk10;
        f32 unk14;
    } spr;

    game = (u8 *)mainGetGame();
    pressed = joyGetPressed(pausePlayer);
    func_overlay_18_01200000_1F2F9D8();
    argF = (f32) arg0;
    func_overlay_18_012040A8_1F33A80(argF, 0x21);
    cur300 = (s16 *) (currentobjects + 0x300);
    cur304 = (s16 *) (currentobjects + 0x304);

    if ((D_overlay_18_012066AC != 0) && (D_overlay_18_01206BCC != 0)) {
        playerData = *(s8 **)((u8 *)objGetPlayerNo(0) + 0x68);
        chr = mainGetGameCharacter(playerData[0], func_overlay_18_0120207C_1F31A54(playerData));
        joyDx = frontJoyDx[pausePlayer];
        prevDpad = D_overlay_18_012066B0;
        if (joyDx < -0x20 && D_overlay_18_01206C94 == 0) {
            func_overlay_18_01201294_1F30C6C(chr);
            joyDx = frontJoyDx[pausePlayer];
        }
        if (joyDx >= 0x21 && D_overlay_18_01206C94 == 0) {
            func_overlay_18_01201218_1F30BF0(chr);
        }
        if (prevDpad != D_overlay_18_012066B0) {
            amSndPlay(0x16B, 0);
            D_overlay_18_01206C88 = 0xFF;
            D_overlay_18_01206C8C = 0;
            D_overlay_18_01206C90 = 0;
        }
        *cur300 = (s16) (*cur300 + (arg0 << 8));
        obj = (u8 *) frontendptrs[D_overlay_18_012066AC];
        sp70 = *(u8 **)(obj + 0x6C);
        if (D_overlay_18_012066B0 == 0xA) {
            if (D_overlay_18_01206B6C < *(f32 *)(obj + 0x28)) {
                *cur304 = (s16) (*cur304 + ((0x3000 - *cur304) >> 2));
            } else {
                *cur304 = (s16) (*cur304 + ((s16) -*cur304 >> 2));
            }
        } else {
            *(s32 *)(obj + 0x84) = 0;
            partUpdateTriggers(obj, arg0);
            *cur304 = (s16) (*cur304 + ((s16) -*cur304 >> 2));
        }
        if (D_overlay_18_01206CA8 > 0) {
            if (arg0 < D_overlay_18_01206CA8) {
                D_overlay_18_01206CA8 -= arg0;
            } else {
                D_overlay_18_01206CA8 = 0;
                D_overlay_18_01206CA0 = D_overlay_18_01206CA4;
            }
        } else {
            f28 = *(f32 *)(obj + 0x28);
            if ((f28 == 0.0f) && (D_overlay_18_01206CA0 < 0.0f)) {
                D_overlay_18_01206CA8 = mathRnd(0x78, 0x12C);
                D_overlay_18_01206CA4 = D_overlay_18_012066B4[D_overlay_18_012066B0];
            }
            if ((f28 == 1.0f) && (D_overlay_18_01206CA0 > 0.0f)) {
                D_overlay_18_01206CA8 = mathRnd(0x78, 0x12C);
                D_overlay_18_01206CA4 = -D_overlay_18_012066B4[D_overlay_18_012066B0];
            }
        }
        if (D_overlay_18_01206C90 > 0) {
            temp_t9 = arg0 << 5;
            temp_t2 = D_overlay_18_01206C88 - temp_t9;
            D_overlay_18_01206C88 = temp_t2;
            D_overlay_18_01206C8C += temp_t9;
            if (temp_t2 < 0) {
                D_overlay_18_01206C88 = 0;
            }
            if (D_overlay_18_01206C8C >= 0x100) {
                D_overlay_18_01206C8C = 0xFF;
            }
            D_overlay_18_01206C90 -= arg0;
        } else {
            temp_v1 = D_overlay_18_01206C88;
            if (temp_v1 != 0xFF) {
                temp_t2_2 = arg0 << 5;
                temp_t3 = temp_v1 + temp_t2_2;
                D_overlay_18_01206C88 = temp_t3;
                D_overlay_18_01206C8C -= temp_t2_2;
                if (temp_t3 >= 0x100) {
                    D_overlay_18_01206C88 = 0xFF;
                }
                if (D_overlay_18_01206C8C < 0) {
                    D_overlay_18_01206C8C = 0;
                }
            }
        }
        objAnimDframe(obj, D_overlay_18_01206CA0, argF);
        *(s8 *) (sp70 + 0xA) = (s8) arg0;
        if (D_overlay_18_01206C88 > 0) {
            objtrans = D_overlay_18_01206C88;
            frontDrawObj(0x18);
            objtrans = 0xFF;
        }

        fontUseFont(2);
        fontColour(0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        fontPrintXY(&frontgfx, 0x52, 0x2D, *(char **)(front_text + 0x2BC), 4);
        fontPrintXY(&frontgfx, 0x52, 0x4B, *(char **)(front_text + 0x2C0), 4);
        fontColour(0xFF, 0xFF, 0, 0xFF, 0xFF);
        idx2 = D_overlay_18_012066B0 * 2;
        chr2 = (u8 *) chr + idx2;
        sprintf(buf, D_overlay_18_01206AF8, *(s32 *)(chr2 + 0x14), idx2);
        fontPrintXY(&frontgfx, 0x52, 0x3A, buf, 4);
        sprintf(buf, D_overlay_18_01206B00, *(s32 *)(chr2 + 0x34));
        fontPrintXY(&frontgfx, 0x52, 0x58, buf, 4);
        fontColour(0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        if ((D_overlay_18_012066B0 == 0) || (D_overlay_18_012066B0 == 1) || (D_overlay_18_012066B0 == 5) ||
            (D_overlay_18_012066B0 == 2) || (D_overlay_18_012066B0 == 3) || (D_overlay_18_012066B0 == 7)) {
            fontColour(0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
            fontPrintXY(&frontgfx, 0x52, 0x69, *(char **)(front_text + 0x2C8), 4);
            fontColour(0xFF, 0xFF, 0, 0xFF, 0xFF);
            temp_v1_3 = *(u32 *)(game + D_overlay_18_012066B0 * 4 + 0x4B4);
            if (temp_v1_3 == 0) {
                pct = 0.0f;
            } else {
                temp_t6 = *(s32 *)(game + D_overlay_18_012066B0 * 4 + 0x474);
                var_f8 = (f32) temp_t6;
                if (temp_t6 < 0) {
                    var_f8 += 4294967296.0f;
                }
                pct = (100.0f * (f32) temp_v1_3) / var_f8;
            }
            sprintf(buf, D_overlay_18_01206B08, pct);
            fontPrintXY(&frontgfx, 0x52, 0x76, buf, 4);
        } else {
            fontColour(0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
            fontPrintXY(&frontgfx, 0x52, 0x69, *(char **)(front_text + 0x2C4), 4);
            fontColour(0xFF, 0xFF, 0, 0xFF, 0xFF);
            sprintf(buf, D_overlay_18_01206B14, *(u16 *)(game + idx2 + 0x4F4));
            fontPrintXY(&frontgfx, 0x52, 0x76, buf, 4);
        }
        fontPrintXY(&frontgfx, 0x37, 0x96, *(char **)(front_text + D_overlay_18_012066B0 * 0x14 + 0x2CC), 0);
        fontPrintXY(&frontgfx, 0x37, 0xA0, *(char **)(front_text + D_overlay_18_012066B0 * 0x14 + 0x2D0), 0);
        fontPrintXY(&frontgfx, 0x37, 0xAA, *(char **)(front_text + D_overlay_18_012066B0 * 0x14 + 0x2D4), 0);
        fontPrintXY(&frontgfx, 0x37, 0xB4, *(char **)(front_text + D_overlay_18_012066B0 * 0x14 + 0x2D8), 0);
        fontPrintXY(&frontgfx, 0x37, 0xBE, *(char **)(front_text + D_overlay_18_012066B0 * 0x14 + 0x2DC), 0);
        fontColour(0xFF, 0xFF, 0xFF, 0xFF, D_overlay_18_01206C88);
        fontPrintXY(&frontgfx, 0xD2, 0x26, *(char **)(front_text + D_overlay_18_012066B0 * 4 + 0xE4), 4);
    }

    sel = -1;
    if (D_overlay_18_01206C94 == 0) {
        if (pressed & 0x4000) {
            pauseSetScreen(1);
            sel = -1;
            D_overlay_18_01206C94 = 1;
        } else if (pressed & 0x800) {
            sel = 0;
        } else if (pressed & 0x100) {
            sel = 1;
        } else if (pressed & 0x400) {
            sel = 2;
        } else if (pressed & 0x200) {
            sel = 3;
        }
    }
    if ((sel >= 0) && (sel < 4)) {
        *(u8 *)(game + sel + 0x534) = D_overlay_18_012066B0;
        amSndPlay(0x16D, 0);
        D_overlay_18_01206C90 = 0x12C;
        weaponScreenSetupDpad();
    }
    if (joyGetButtons(pausePlayer) & 0x2000) {
        if (D_overlay_18_01206C94 == 0) {
            if (D_overlay_18_01206C90 == 0) {
                weaponScreenSetupDpad();
            }
            D_overlay_18_01206C90 = 0x3C;
        }
    }

    camOverrideProjScales(1.0f, 1.0f);
    camSetFOV(52.0f, 1);
    camStandardPersp(&frontgfx, &frontmtx);
    frontDrawObj(0x21);
    frontDrawObj(0x22);
    frontDrawObj(0x23);
    frontDrawObj(0x24);
    camSetFOV(52.0f, 1);
    if (D_overlay_18_01206BCC != 0) {
        if (D_overlay_18_01206C8C > 0) {
            camStandardOrtho(&frontgfx, &frontmtx);
            sprSetTextureFilter(0);
            frontgfx->words.w0 = 0xFA000000;
            frontgfx->words.w1 = (s32) ((D_overlay_18_01206C8C & 0xFF) | ~0xFF);
            frontgfx++;
            spr.unk0 = 0;
            spr.unk2 = 0;
            spr.unk4 = 0;
            spr.unk8 = 1.0f;
            spr.unk14 = 1.0f;
            spr.unkC = 46.0f;
            spr.unk10 = 40.0f;
            camDo2DSprite(&frontgfx, &frontmtx, &frontvtx, (s16 *) &spr, (void *) D_800FF65C, 0, 0xFF);
            spr.unkC = 46.0f;
            spr.unk10 = 70.0f;
            camDo2DSprite(&frontgfx, &frontmtx, &frontvtx, (s16 *) &spr, frontendptrs[D_overlay_18_01206C98[0]], 0, 0xFF);
            spr.unkC = 80.0f;
            spr.unk10 = 40.0f;
            camDo2DSprite(&frontgfx, &frontmtx, &frontvtx, (s16 *) &spr, frontendptrs[D_overlay_18_01206C98[1]], 0, 0xFF);
            spr.unkC = 46.0f;
            spr.unk10 = 10.0f;
            camDo2DSprite(&frontgfx, &frontmtx, &frontvtx, (s16 *) &spr, frontendptrs[D_overlay_18_01206C98[2]], 0, 0xFF);
            spr.unkC = 12.0f;
            spr.unk10 = 40.0f;
            camDo2DSprite(&frontgfx, &frontmtx, &frontvtx, (s16 *) &spr, frontendptrs[D_overlay_18_01206C98[3]], 0, 0xFF);
            sprSetTextureFilter(0);
            frontgfx->words.w1 = -1;
            frontgfx->words.w0 = 0xFA000000;
            frontgfx++;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/weaponScreen.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_18_0120207C_1F31A54(s8 *arg0) {
    u16 temp_t7;
    s32 temp_t6;

    temp_t6 = arg0[1] & 3;
    if (temp_t6 == 3) {
        temp_t7 = *(u16 *)((u8 *)mainGetGame() + 0x2C2);
        return temp_t7 & 3;
    }
    return temp_t6;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/func_overlay_18_0120207C_1F31A54.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void menuScreenInit(void) {
    s32 sp64;
    struct {
        s16 unk0;
        s8 unk2;
        s8 pad3;
        s16 unk4;
        s16 unk6;
        s16 unk8;
    } romdef;
    s8 *playerData;
    s32 charIdx;
    u8 *temp_s4;
    u8 *temp_v0_2;
    s32 temp_v1;
    void *obj;
    s32 i;
    s32 v1;

    sp64 = runlinkIsModuleLoaded(0x14);
    playerData = *(s8 **)((u8 *)objGetPlayerNo(0) + 0x68);
    charIdx = func_overlay_18_0120207C_1F31A54(playerData);
    if (playerData[1] & 4) {
        D_overlay_18_01206CF8 = charIdx + 0x9A;
    } else {
        D_overlay_18_01206CF8 = charIdx + 0x5E;
    }
    D_overlay_18_01206CFC = 0;
    D_overlay_18_01206D00 = 0;
    loadFrontEndItem(D_overlay_18_01206CF8);
    loadFrontEndList(&D_overlay_18_01206718);
    setupFrontEndList(&D_overlay_18_01206724);
    *(u8 *)(*(u8 **)((u8 *)frontendptrs + 0x194) + 0x3A) = 0;
    D_800FFAC6 = (s16) D_overlay_18_01206CF8;
    D_800FFAC8 = D_overlay_18_0120675C[charIdx];
    temp_s4 = (u8 *) frontendptrs[D_overlay_18_01206CF8];
    temp_v1 = *(s32 *)(temp_s4 + 0x54);
    if (temp_v1 != 0) {
        temp_v0_2 = *(u8 **)(temp_s4 + 0x40);
        lightSetObjectLight(temp_v1 + 0x10, (s32) (*(f32 *)(temp_v0_2 + 0x94) * 255.0f),
                            (s32) (*(f32 *)(temp_v0_2 + 0x90) * 255.0f), *(s16 *)(temp_v0_2 + 0x9C),
                            (s32) *(s16 *)(temp_v0_2 + 0x9E), (s32) *(s16 *)(temp_v0_2 + 0xA0));
        *(s8 *)(temp_s4 + 0xA1) = 1;
    }
    *(s32 *)(temp_s4 + 0x8C) = 0;

    romdef.unk0 = 0x1B0;
    romdef.unk2 = 0xA;
    romdef.unk4 = 0;
    romdef.unk6 = 0;
    romdef.unk8 = 0;
    for (i = 0; i < 8; i++) {
        obj = objSetupObject(&romdef, 0);
        D_overlay_18_01206CB0[i] = obj;
        *(u8 *)((u8 *)obj + 0x3A) = (u8) (i & 1);
        D_overlay_18_01206CD0[i] = 0.0f;
        *(s16 *)(D_overlay_18_01206774 + i * 8 + 6) = 0;
    }
    if (sp64 == 0) {
        runlinkFreeCode(0x14);
    }

    D_overlay_18_01206D04 = 0;
    D_overlay_18_01206D05 = -1;
    D_overlay_18_01206CF0 = D_overlay_18_01206B70;
    D_overlay_18_01206CF4 = 0.0f;
    D_overlay_18_01206D07 = -1;
    D_overlay_18_01206D0A = 0;
    D_overlay_18_01206D0C = 0xFF;
    D_overlay_18_01206D08 = 0;
    D_overlay_18_01206D09 = 0;
    D_overlay_18_01206D0E = D_800FFAC0;
    D_overlay_18_01206D10 = mmAlloc(0x460, -1U);
    for (v1 = 0; v1 != 0x460; v1 += 0x70) {
        u8 *slot = (u8 *) D_overlay_18_01206D10 + v1;

        *(s32 *)(slot + 0x10) = -1;
        *(s32 *)(slot + 0x2C) = -1;
        *(s32 *)(slot + 0x48) = -1;
        *(s32 *)(slot + 0x64) = -1;
    }
    D_overlay_18_01206D14 = 0;
    D_overlay_18_01206D16 = 0;
    D_overlay_18_01206680 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/menuScreenInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void menuScreenCleanup(void) {
    s32 i;

    freeFrontEndItem(D_overlay_18_01206CF8);
    freeFrontEndList(&D_overlay_18_01206718);
    for (i = 0; i < 8; i++) {
        objFreeObject(D_overlay_18_01206CB0[i]);
    }
    objDoFrees();
    mmFree(D_overlay_18_01206D10);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/menuScreenCleanup.s")
#endif


#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void menuScreen(s8 arg0) {
    s8 *plr;
    s8 cur;
    s8 pc;
    s32 charFlag;
    s32 charSlot;
    s32 selLeft;
    s32 selRight;
    s32 scrollStep;
    s32 fadeStep;
    s32 texVals[3];
    s32 spriteCount;
    s32 i;
    s32 k;
    s32 jx;
    s32 jy;
    s32 moved;
    s32 a2;
    s32 alpha;
    s32 colour;
    s32 v1;
    s32 t2;
    s32 barX;
    s32 barY;
    s32 t9v;
    s32 t3v;
    s32 restartA;
    s32 restartB;
    s32 restartC;
    u16 w74;
    f32 argF;
    s32 sprRec[6];
    s32 tileRec[4];
    u8 *obj;
    u8 *mtx;
    u8 *anim;
    u8 *objE;
    u8 *mtxE;
    u8 *animE;
    u8 *chrp;
    u8 *part;
    u8 *rec;
    u8 *cp;
    u8 *cv;
    u8 *o40;
    u8 *gunObj;
    u8 *gunAux;
    u8 *gunMtx;
    u8 *gunPtr;
    u8 *m68;
    s16 *spr;

    plr = *(s8 **)((u8 *)objGetPlayerNo(0) + 0x68);
    charFlag = plr[1] & 4;
    if (charFlag != 0) {
        charSlot = D_overlay_18_01206CF8 - 0x9A;
    } else {
        charSlot = D_overlay_18_01206CF8 - 0x5E;
    }
    selLeft = frontGetSelectableCharacter(charSlot, -1);
    selRight = frontGetSelectableCharacter(charSlot, 1);

    scrollStep = arg0 * 8;
    if (D_overlay_18_01206D07 != -1) {
        D_overlay_18_01206D0C = (s16)(D_overlay_18_01206D0C - scrollStep);
        if (D_overlay_18_01206D0C <= 0) {
            D_overlay_18_01206D0C = 0;
            if (D_overlay_18_01206D08 == 0) {
                freeFrontEndItem(D_overlay_18_01206CF8);
                D_overlay_18_01206D08 = 1;
            } else {
                plr[1] = (s8)(D_overlay_18_01206D07 | charFlag);
                mainGetGame()->pad[0] = plr[1];
                if (charFlag != 0) {
                    D_overlay_18_01206CF8 = D_overlay_18_01206D07 + 0x9A;
                } else {
                    D_overlay_18_01206CF8 = D_overlay_18_01206D07 + 0x5E;
                }
                loadFrontEndItem(D_overlay_18_01206CF8);
                D_overlay_18_01206D08 = 0;
                *(s16 *)(currentobjects + 0x346) = D_overlay_18_01206CF8;
                *(f32 *)(currentobjects + 0x348) = D_overlay_18_0120675C[D_overlay_18_01206D07 & 3];
                obj = (u8 *)frontendptrs[D_overlay_18_01206CF8];
                if (*(s32 *)(obj + 0x54) != 0) {
                    o40 = *(u8 **)(obj + 0x40);
                    lightSetObjectLight(*(s32 *)(obj + 0x54) + 0x10,
                                        (s32)(*(f32 *)(o40 + 0x94) * 255.0f),
                                        (s32)(*(f32 *)(o40 + 0x90) * 255.0f),
                                        *(s16 *)(o40 + 0x9C), *(s16 *)(o40 + 0x9E), *(s16 *)(o40 + 0xA0));
                    obj[0xA1] = 1;
                }
                *(s32 *)(obj + 0x8C) = 0;
                D_overlay_18_01206D07 = -1;
            }
        }
    } else {
        D_overlay_18_01206D0C = (s16)(D_overlay_18_01206D0C + scrollStep);
        if (D_overlay_18_01206D0C >= 0x100) {
            D_overlay_18_01206D0C = 0xFF;
        }
        if (D_overlay_18_012067B4 != 0) {
            if (charFlag != 0) {
                charSlot = D_overlay_18_01206CF8 - 0x9A;
            } else {
                charSlot = D_overlay_18_01206CF8 - 0x5E;
            }
            jx = frontJoyDx[pausePlayer];
            if (jx < -0x20) {
                charSlot = selLeft;
                D_overlay_18_01206D07 = (s8)selLeft;
                amSndPlay(0x221, NULL);
            } else if (jx >= 0x21) {
                charSlot = selRight;
                D_overlay_18_01206D07 = (s8)selRight;
                amSndPlay(0x221, NULL);
            }
        }
    }

    if (D_overlay_18_012067B4 != 0) {
        if (D_overlay_18_01206B74 <= *(f32 *)((u8 *)D_800FF56C + 0x28)) {
            D_overlay_18_01206D0A = (s16)(D_overlay_18_01206D0A + arg0 * 4);
            if (D_overlay_18_01206D0A >= 0x100) {
                D_overlay_18_01206D0A = 0xFF;
            }
        }
        fadeStep = arg0 * 4;
    } else {
        fadeStep = arg0 * 4;
        D_overlay_18_01206D0A = (s16)(D_overlay_18_01206D0A - fadeStep);
        if (D_overlay_18_01206D0A < 0) {
            D_overlay_18_01206D0A = 0;
        }
        if (D_overlay_18_01206D05 == -1 && D_overlay_18_01206D14 == 0) {
            cur = D_overlay_18_01206D04;
            jy = frontJoyDy[pausePlayer];
            if (jy < -0x20 && D_overlay_18_01206680 == 0) {
                if (D_overlay_18_01206D04 == 6) {
                    if (mainGetGameFlag(0x64) != 0) {
                        D_overlay_18_01206D04 = 3;
                    } else {
                        D_overlay_18_01206D04 = 1;
                    }
                } else if (D_overlay_18_01206D04 == 5 && mainGetGameFlag(0x5F) == 0) {
                    D_overlay_18_01206D04 = 0;
                } else {
                    D_overlay_18_01206D04 += 2;
                }
            }
            jy = frontJoyDy[pausePlayer];
            if (jy >= 0x21 && D_overlay_18_01206680 == 0) {
                if (D_overlay_18_01206D04 == 1) {
                    D_overlay_18_01206D04 = 6;
                } else if (D_overlay_18_01206D04 == 3 && mainGetGameFlag(0x64) != 0) {
                    D_overlay_18_01206D04 = 6;
                } else if (D_overlay_18_01206D04 == 0 && mainGetGameFlag(0x5F) == 0) {
                    D_overlay_18_01206D04 = 5;
                } else {
                    D_overlay_18_01206D04 -= 2;
                }
            }
            jx = frontJoyDx[pausePlayer];
            moved = (jx < 0x21);
            if (jx < -0x20) {
                moved = (jx < 0x21);
                if (D_overlay_18_01206680 == 0) {
                    if (D_overlay_18_01206D04 == 0 && mainGetGameFlag(0x5F) == 0) {
                        D_overlay_18_01206D04 = 6;
                    } else if (D_overlay_18_01206D04 == 2 && mainGetGameFlag(0x64) != 0) {
                        D_overlay_18_01206D04 = 0;
                    } else {
                        D_overlay_18_01206D04 -= 1;
                    }
                    moved = (frontJoyDx[pausePlayer] < 0x21);
                }
            }
            if (!moved && D_overlay_18_01206680 == 0) {
                if (D_overlay_18_01206D04 == 6 && mainGetGameFlag(0x5F) == 0) {
                    D_overlay_18_01206D04 = 0;
                } else if (D_overlay_18_01206D04 == 0 && mainGetGameFlag(0x64) != 0) {
                    D_overlay_18_01206D04 = 2;
                } else {
                    D_overlay_18_01206D04 += 1;
                }
            }
            if (D_overlay_18_01206D04 < 0) {
                D_overlay_18_01206D04 = 7;
            }
            if (D_overlay_18_01206D04 >= 8) {
                D_overlay_18_01206D04 = 0;
            }
            if (cur != D_overlay_18_01206D04) {
                amSndPlay(0x16B, NULL);
                D_overlay_18_01206D00 = 0xFF;
                D_overlay_18_01206CFC = 0;
            }
        }
    }

    func_overlay_18_01200000_1F2F9D8();
    camOverrideProjScales(1.0f, 1.0f);
    camSetFOV(52.0f, 1);
    camStandardPersp(&frontgfx, &frontmtx);
    frontDrawObj(0x1F);
    camSetFOV(52.0f, 1);
    camStandardPersp(&frontgfx, &frontmtx);

    if (D_overlay_18_01206CF8 == 0x60 || D_overlay_18_01206CF8 == 0x9C) {
        *(s16 *)(currentobjects + 0x340) = -0x8000;
    } else {
        *(s16 *)(currentobjects + 0x340) = (s16)(*(s16 *)(currentobjects + 0x340) + (arg0 << 7));
        D_overlay_18_01206D0E = *(s16 *)(currentobjects + 0x340);
    }

    argF = (f32)arg0;
    obj = (u8 *)D_800FF56C;
    mtx = *(u8 **)(*(u8 **)(obj + 0x6C));
    mtx[0xA] = arg0;
    objAnimDframe(obj, D_overlay_18_01206CF0, argF);

    if (D_overlay_18_01206D05 != -1) {
        if ((joyGetPressed(pausePlayer) & 0x8000) && D_overlay_18_01206680 == 0) {
            D_overlay_18_01206D06 = 0;
        }
        if (arg0 < D_overlay_18_01206D06) {
            D_overlay_18_01206D06 = (s8)(D_overlay_18_01206D06 - arg0);
        } else if (D_overlay_18_01206D06 != -0x64) {
            pauseSetScreen((s32)D_overlay_18_01206778[D_overlay_18_01206D05 * 8]);
            D_overlay_18_01206D06 = -0x64;
        }
    }
    if ((joyGetPressed(pausePlayer) & 0x8000) && D_overlay_18_01206D05 == -1 && D_overlay_18_01206D14 == 0 && D_overlay_18_01206680 == 0) {
        if (D_overlay_18_012067B4 == 0) {
            amSndPlay(0x16D, NULL);
        }
        if (D_overlay_18_01206D04 == 0) {
            D_overlay_18_012067B4 = 1;
        } else {
            D_overlay_18_01206CF0 = -D_overlay_18_01206CF0;
            D_overlay_18_01206D05 = D_overlay_18_01206D04;
            D_overlay_18_01206D06 = 0x3C;
        }
    }

    if (D_overlay_18_01206D05 != -1) {
        k = 0;
        if (arg0 > 0) {
            if ((arg0 & 3) != 0) {
                do {
                    k += 1;
                    D_overlay_18_01206CF4 += (22.0f - D_overlay_18_01206CF4) * 0.125f;
                } while ((arg0 & 3) != k);
                if (k != arg0) {
                    goto block_108;
                }
            } else {
block_108:
                do {
                    k += 4;
                    D_overlay_18_01206CF4 += (22.0f - D_overlay_18_01206CF4) * 0.125f;
                    D_overlay_18_01206CF4 += (22.0f - D_overlay_18_01206CF4) * 0.125f;
                    D_overlay_18_01206CF4 += (22.0f - D_overlay_18_01206CF4) * 0.125f;
                    D_overlay_18_01206CF4 += (22.0f - D_overlay_18_01206CF4) * 0.125f;
                } while (k != arg0);
            }
        }
    }

    /* 8 texture channels: alpha ramps in for the selected slot, out for the others */
    cp = (u8 *)D_overlay_18_01206774;
    cv = D_overlay_18_0120676C;
    i = 0;
    do {
        if (i == D_overlay_18_01206D04) {
            a2 = 0x100;
            if (D_overlay_18_01206B78 < *(f32 *)((u8 *)D_800FF56C + 0x28)) {
                *(s16 *)(cp + 6) = (s16)(*(s16 *)(cp + 6) + scrollStep);
                if (*(s16 *)(cp + 6) >= 0x100) {
                    *(s16 *)(cp + 6) = 0xFF;
                }
            }
        } else {
            a2 = 0;
            *(s16 *)(cp + 6) = (s16)(*(s16 *)(cp + 6) - scrollStep);
            if (*(s16 *)(cp + 6) < 0) {
                *(s16 *)(cp + 6) = 0;
            }
        }
        modSetTextureFrame(mtx, *cv, a2);
        i += 1;
        cp += 8;
        cv += 1;
    } while (i < 8);

    t9v = D_overlay_18_012067BC[selLeft] << 8;
    t3v = D_overlay_18_012067BC[selRight] << 8;
    if (D_overlay_18_012067B4 != 0) {
        texVals[2] = 0x100;
        texVals[1] = t3v + 0x100;
        texVals[0] = t9v + 0x100;
    } else {
        texVals[1] = t3v;
        texVals[0] = t9v;
        texVals[2] = 0;
    }
    for (k = 0; k < 3; k++) {
        modSetTextureFrame(mtx, D_overlay_18_012067C0[k], texVals[k]);
    }

    D_overlay_18_01206BB0[0] = 0x2008;
    D_overlay_18_01206BB0[2] = 0x200E;
    D_overlay_18_01206BB0[1] = D_overlay_18_01206D0E;
    D_overlay_18_01206BB0[3] = D_overlay_18_01206D0E;
    spr = &D_overlay_18_01206BB8;
    if (mainGetGameFlag(0x5F) == 0) {
        D_overlay_18_01206BB8 = 0x203E;
        D_overlay_18_01206BBA = 0x4000;
        spr = &D_overlay_18_01206BBA + 1;
    }
    if (mainGetGameFlag(0x64) != 0) {
        spr[1] = 0x4000;
        spr[0] = 0x201A;
        spr += 2;
    }
    if (D_overlay_18_01206D05 != -1) {
        spr[0] = (s16)((((D_overlay_18_01206D05 * 6) + 0x14) | 0x2000));
        spr[1] = 0;
        spr += 2;
    }
    spr[0] = 0x1000;
    frontDrawObj(0x19);

    if (D_overlay_18_01206D08 == 0) {
        objE = (u8 *)frontendptrs[D_overlay_18_01206CF8];
        mtxE = *(u8 **)(*(u8 **)(objE + 0x6C));
        mtxE[0xA] = arg0;
        animE = *(u8 **)mtxE;
        objAnimDframe(objE, *(f32 *)(D_overlay_18_0120672C + (charSlot * 0xC) + (*(s8 *)(objE + 0x3B) * 4)), argF);
        if (*(f32 *)(objE + 0x28) == 1.0f) {
            objAnimSetMove(objE, mathRnd(0, 2), 0);
        }
        mtxE[0xA] = arg0;
        modGenAnimMatrices(mtxE, animE, objE, 1.0f, 0.0f);
        lightObject(objE, mtxE, *(s32 *)(objE + 0x54), *(s32 *)(mtxE + (mtxE[0xB] * 4) + 0x10));
        if (D_overlay_18_01206CF8 != 0x60) {
            if (D_overlay_18_01206CF8 != 0x9C) {
                gunObj = *(u8 **)(objE + 0x60);
                gunAux = *(u8 **)(gunObj + 4);
                gunMtx = *(u8 **)(*(u8 **)(gunAux + 0x6C));
                gunMtx[0xA] = arg0;
                gunPtr = *(u8 **)(objE + 0x68);
                objMakeGunMtx(objE, mtxE, animE, 0, gunPtr, gunPtr + 0x40, gunPtr + 0x44, gunPtr + 0x48);
                if ((D_overlay_18_01206CF8 == 0x5F || D_overlay_18_01206CF8 == 0x9B) && *(u8 *)(animE + 0x2D) != 0) {
                    m68 = *(u8 **)(mtxE + 0x68);
                    *(f32 *)(gunPtr + 0x30) = *(f32 *)(m68 + 0);
                    *(f32 *)(gunPtr + 0x34) = *(f32 *)(m68 + 4);
                    *(f32 *)(gunPtr + 0x38) = *(f32 *)(m68 + 8);
                }
            }
        }
        mtxE[0xA] = 0;
        objtrans = (s32)D_overlay_18_01206D0C;
        frontDrawObj(0x1A);
        objtrans = 0xFF;
    }

    /* 40 particle records of 0x1C bytes */
    part = (u8 *)D_overlay_18_01206D10;
    spriteCount = 0;
    *(s16 *)((u8 *)sprRec + 0) = 0;
    *(s16 *)((u8 *)sprRec + 2) = 0;
    i = 0;
    do {
        if (spriteCount <= 0 && *(s16 *)(part + 0x10) < 0 && D_overlay_18_01206D0C != 0xFF) {
            *(s16 *)(part + 0x10) = 0;
            *(u32 *)(part + 0x8) = (u32)D_overlay_18_012067C8[mathRnd(0, 5)];
            *(s16 *)(part + 0x0) = (s16)mathRnd(-0x1E, 0x1E);
            *(s16 *)(part + 0x2) = 0x4A;
            *(s16 *)(part + 0x4) = (s16)mathRnd(-0x28, 0x14);
            *(s16 *)(part + 0x6) = (s16)mathRnd(-2, -1);
            *(f32 *)(part + 0xC) = (f32)(((f32)mathRnd(0, 0x64) * D_overlay_18_01206B7C) + D_overlay_18_01206B80);
            *(s16 *)(part + 0x14) = (s16)mathRnd(-0x8000, 0x8000);
            *(s16 *)(part + 0x16) = (s16)mathRnd(-0x200, 0x200);
            *(s16 *)(part + 0x12) = (s16)(mathRnd(0, 2) + 0x14);
            *(s8 *)(part + 0x18) = (s8)mathRnd(5, 0xA);
            spriteCount += 1;
        }
        if (*(s16 *)(part + 0x10) >= 0) {
            *(s16 *)(part + 0x10) = (s16)(*(s16 *)(part + 0x10) + arg0);
            *(s16 *)(part + 0x2) = (s16)(*(s16 *)(part + 0x2) + (*(s16 *)(part + 0x6) * arg0));
            *(s16 *)(part + 0x14) = (s16)(*(s16 *)(part + 0x14) + (*(s16 *)(part + 0x16) * arg0));
            if (*(s16 *)(part + 0x12) < *(s16 *)(part + 0x10)) {
                colour = *(u32 *)(part + 0x8);
                v1 = (colour & 0xFF) - (*(s8 *)(part + 0x18) * arg0);
                t2 = colour & ~0xFF;
                if (v1 < 0) {
                    *(s16 *)(part + 0x10) = -1;
                    v1 = 0;
                    t2 = *(u32 *)(part + 0x8) & ~0xFF;
                }
                *(u32 *)(part + 0x8) = t2;
                *(u32 *)(part + 0x8) = (u32)(t2 | v1);
            }
            *(f32 *)((u8 *)sprRec + 0xC) = (f32)*(s16 *)(part + 0x0);
            *(f32 *)((u8 *)sprRec + 0x10) = (f32)*(s16 *)(part + 0x2);
            *(f32 *)((u8 *)sprRec + 0x14) = (f32)*(s16 *)(part + 0x4);
            *(s16 *)((u8 *)sprRec + 4) = *(s16 *)(part + 0x14);
            *(f32 *)((u8 *)sprRec + 8) = *(f32 *)(part + 0xC);
            colour = *(u32 *)(part + 0x8);
            sprSetIA2ColOverride(0xFF, 0xFF, 0xFF, (colour >> 0x18) & 0xFF, (colour >> 0x10) & 0xFF, (colour >> 8) & 0xFF);
            camDoSprite(&frontgfx, &frontmtx, &frontvtx, (s16 *)sprRec, D_800FF66C, 6, *(u32 *)(part + 0x8) & 0xFF);
            sprClearIA2ColOverride();
        }
        i += 1;
        part += 0x1C;
    } while (i < 0x28);

    if (mainGetGameFlag(0x5F) != 0) {
        func_overlay_18_01203BB4_1F3358C(7, arg0);
    }
    if (mainGetGameFlag(0x64) == 0) {
        func_overlay_18_01203BB4_1F3358C(1, arg0);
    }
    func_overlay_18_01203BB4_1F3358C(0, arg0);
    for (i = 2; i < 7; i++) {
        func_overlay_18_01203BB4_1F3358C(i, arg0);
    }

    fontUseFont(2);
    if (D_overlay_18_01206D05 == -1) {
        rec = (u8 *)D_overlay_18_01206774;
        i = 0;
        do {
            alpha = *(s16 *)(rec + 6);
            if (alpha > 0) {
                fontColour(0, 0, 0x80, 0xFF, alpha);
                fontPrintXY(&frontgfx, 0xA0, 0xB0, *(char **)(front_text + (*(s32 *)(rec + 0) * 4)), 4);
            }
            i += 1;
            rec += 8;
        } while (i != 8);
    }

    if (D_overlay_18_01206D0A > 0) {
        fontColour(0, 0, 0x80, 0xFF, D_overlay_18_01206D0A);
        if (viGetVideoMode() & 1) {
            barX = 0x6D;
            barY = 0xD3;
        } else {
            barX = 0x56;
            barY = 0xEA;
        }
        fontPrintXY(&frontgfx, barX, 0xBA, *(char **)(front_text + (selLeft * 4) + 0x628), 1);
        fontPrintXY(&frontgfx, barY, 0xBA, *(char **)(front_text + (selRight * 4) + 0x628), 0);
    }

    if (D_overlay_18_01206D14 == -1) {
        D_overlay_18_01206D14 = 0;
    }
    if ((joyGetPressed(pausePlayer) & 0x2000) && D_overlay_18_01206D14 == 0 && D_overlay_18_01206D16 == 0 && D_overlay_18_012067B4 == 0) {
        D_overlay_18_01206D14 = 0x14;
        D_overlay_18_01206D16 = 0x3C;
    }
    if (D_overlay_18_01206D14 > 0) {
        D_overlay_18_01206D14 = (s16)(D_overlay_18_01206D14 - arg0);
        if (D_overlay_18_01206D14 <= 0) {
            mainSaveGame(mainGetGame()->pad[3]);
            D_overlay_18_01206D14 = -1;
        }
    }

    if (D_overlay_18_012067B4 != 0) {
        D_overlay_18_012067C4 = (s16)(D_overlay_18_012067C4 - fadeStep);
        if (D_overlay_18_012067C4 < 0) {
            D_overlay_18_012067C4 = 0;
        }
    } else {
        D_overlay_18_012067C4 = (s16)(D_overlay_18_012067C4 + fadeStep);
        if (D_overlay_18_012067C4 >= 0x100) {
            D_overlay_18_012067C4 = 0xFF;
        }
    }

    if (D_overlay_18_01206D16 == 0) {
        fontColour(0xFF, 0xFF, 0xFF, 0xFF, D_overlay_18_012067C4);
        fontPrintXY(&frontgfx, 0xAA, 0xC2, *(char **)(front_text + 0x848), 4);
        *(s32 *)((u8 *)tileRec + 0x0) = D_800FF674;
        *(s32 *)((u8 *)tileRec + 0x4) = 0;
        *(s16 *)((u8 *)tileRec + 0x8) = -8;
        *(s16 *)((u8 *)tileRec + 0xA) = -8;
        *(s32 *)((u8 *)tileRec + 0xC) = 0;
        rcpTileWrite(&frontgfx, tileRec, 0x82, 0xC6, 0xFF, 0xFF, 0xFF, D_overlay_18_012067C4);
    } else {
        D_overlay_18_01206D16 = (s16)(D_overlay_18_01206D16 - arg0);
        if (D_overlay_18_01206D16 <= 0) {
            D_overlay_18_01206D16 = 1;
        }
        fontColour(0xFF, 0xFF, 0xFF, 0xFF, D_overlay_18_012067C4);
        fontPrintXY(&frontgfx, 0xA0, 0xC2, *(char **)(front_text + 0x84C), 4);
    }

    if (joyGetPressed(pausePlayer) & 0x5000) {
        if (D_overlay_18_01206680 == 0) {
            if (D_overlay_18_012067B4 != 0) {
                D_overlay_18_012067B4 = 0;
            } else if (D_overlay_18_01206D07 == -1) {
                D_overlay_18_01206680 = 1;
                pc = plr[1];
                if (pauseGetPauseCharacter() != pc) {
                    chrp = (u8 *)mainGetGameCharacter(plr[0], plr[1]);
                    amTuneStop();
                    if (levelGetRegionNo(*(u16 *)(chrp + 0x74) >> 5) != 0) {
                        chrp[5] = (u8)(chrp[5] & 0xFFE0);
                    }
                    restartA = *(u16 *)(chrp + 0x74) >> 5;
                    restartB = *(u16 *)(chrp + 0x74) & 0x1F;
                    restartC = *(u16 *)(chrp + 0x4) & 0x1F;
                    mainValidateRestart((u32 *)&restartA, &restartB, &restartC);
                    *(u16 *)(chrp + 0x74) = (u16)((restartA << 5) | (*(u16 *)(chrp + 0x74) & 0x1F));
                    chrp[0x75] = (u8)((restartB & 0x1F) | (chrp[0x75] & 0xFFE0));
                    chrp[5] = (u8)((restartC & 0x1F) | (chrp[5] & 0xFFE0));
                    w74 = *(u16 *)(chrp + 0x74);
                    pauseSetNewLevel(w74 >> 5, plr[1], w74 & 0x1F, 0x10);
                    D_overlay_18_01206D09 = 1;
                    plr[1] = pauseGetPauseCharacter();
                } else if (D_overlay_18_01206D09 == 0) {
                    pauseSetScreen(0xA);
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/menuScreen.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 frontGetSelectableCharacter(s32 arg0, s32 arg1) {
    s32 idx;

    idx = arg0;
    do {
        do {
            idx += arg1;
            if (idx < 0) {
                idx = 2;
            } else if (idx >= 3) {
                idx = 0;
            }
        } while (mainGetGameFlag(idx) == 0);
    } while (mainGetGameFlag(idx + 0x5A) != 0);
    return idx;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/frontGetSelectableCharacter.s")
#endif


#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// cf. DKR: none used (menu-item highlight/lerp, no twin identified)
void func_overlay_18_01203BB4_1F3358C(s32 arg0, s8 arg1) {
    f32 mtx[16];        /* asm sp4C; mtx[12..14] are the sp7C/sp80/sp84 translation slots */
    f32 *lerp;          /* &D_overlay_18_01206CD0[arg0] */
    f32 target;
    f32 *pos;
    u8 *root;           /* *(D_800FF56C->unk6C)[0] */
    u8 *rootHdr;        /* root->unk0 */
    u8 *obj;            /* D_overlay_18_01206CB0[arg0] */
    u8 *model;          /* obj->unk6C[obj->unk3A] */
    u8 *hdr;            /* model->unk0 */
    u8 *vtx;            /* model->unk4: 10 B vertex records */
    u8 *texOfs;
    u8 col;
    Gfx *g;
    s32 fbase;
    s32 rem;
    s32 i;
    s32 off;
    s32 cnt;
    s32 frame;

    root = *(u8 **)(*(u8 **)((u8 *)D_800FF56C + 0x6C));
    rootHdr = *(u8 **)root;

    target = 0.0f;
    if (arg0 == D_overlay_18_01206D05) {
        target = 15.0f;
    } else if (arg0 == D_overlay_18_01206D04) {
        target = 30.0f;
    }

    /* ease the stored value towards target: v += (target - v) * 0.125f, arg1 steps */
    lerp = &D_overlay_18_01206CD0[arg0];
    i = 0;
    if (arg1 > 0) {
        rem = arg1 & 3;
        if (rem != 0) {
            do {
                *lerp = *lerp + ((target - *lerp) * 0.125f);
                i += 1;
            } while (i != rem);
        }
        if (i != arg1) {
            /* unrolled by 4 in asm */
            do {
                *lerp = *lerp + ((target - *lerp) * 0.125f);
                *lerp = *lerp + ((target - *lerp) * 0.125f);
                *lerp = *lerp + ((target - *lerp) * 0.125f);
                *lerp = *lerp + ((target - *lerp) * 0.125f);
                i += 4;
            } while (i != arg1);
        }
        i = 0;
    }

    /* build the 4x4 matrix: row-major, element 15 = 1, every 4th element = 0 */
    fbase = (*(u16 *)(*(u8 **)(rootHdr + 0x30) + arg0 * 4 + 2) << 6)
          + *(s32 *)(root + (*(s8 *)(root + 0xB) * 4) + 0x10);
    for (i = 0; i < 16; i++) {
        if (i == 15) {
            mtx[i] = 1.0f;
        } else if ((i & 3) == 3) {
            mtx[i] = 0.0f;
        } else {
            mtx[i] = *(f32 *)((u8 *)fbase + i * 4);
        }
    }

    obj = (u8 *)D_overlay_18_01206CB0[arg0];
    model = *(u8 **)(*(u8 **)(obj + 0x6C) + (*(s8 *)(obj + 0x3A) * 4));

    if (model != NULL) {
        hdr = *(u8 **)model;
        frame = (s32) (D_overlay_18_01206779[arg0 * 8] << 8);
        /* sig mismatch: prototype has 3 args, asm passes 4 (a3 = model->unk0) */
        ((void (*)(void *, s32, s32, void *))modSetTextureFrame)(model, 0, frame, hdr);

        col = 0x62;
        if (arg0 == D_overlay_18_01206D04) {
            col = 0xFF;
        }
        cnt = *(s16 *)(hdr + 0x12);
        vtx = *(u8 **)(model + 4);
        for (i = 0, off = 0; i < cnt; i++, off += 0xA) {
            vtx[off + 6] = col;
            vtx[off + 7] = col;
            vtx[off + 8] = col;
        }

        *(s8 *)(model + 0xA) = arg1;
        if (*(s8 *)(model + 0xA) != 0) {
            lightObject(obj, model, *(s32 *)((u8 *)D_800FF56C + 0x54), (s32) mtx);
            if (*(u8 *)(hdr + 0x11) != 0) {
                objAnimTextures(D_800FF56C, hdr, model, *(s8 *)(model + 0xA));
            }
            *(s8 *)(model + 0xA) = 0;
        }

        if (*(u8 *)(hdr + 0x11) != 0) {
            texOfs = *(u8 **)(model + (*(s8 *)(model + 0xB) * 4) + 0x78);
        } else {
            texOfs = NullTextureOffsets;
        }

        pos = (f32 *)(*(u8 **)(root + 0x68) + arg0 * 12);
        mtx[12] = pos[0];
        mtx[13] = pos[1];
        mtx[14] = *lerp + pos[2];
        if (arg0 == D_overlay_18_01206D05) {
            if (arg0 & 1) {
                mtx[12] -= D_overlay_18_01206CF4;
            } else {
                mtx[12] += D_overlay_18_01206CF4;
            }
        }

        matrixScale(D_overlay_18_01206B84, D_overlay_18_01206B84, D_overlay_18_01206B84, mtx);
        camPushFloatModelMtx(&frontgfx, &frontmtx, mtx);

        /* display list: model texture/geometry, then reset */
        g = frontgfx;
        frontgfx = g + 1;
        g->words.w0 = (((u32) *(u32 *)(model + (*(s8 *)(model + 0xB) * 4) + 0x10) + 0x80000000U) & 0xFFFFFFU) | 0xBF000000U;
        g->words.w1 = (u32) *(u8 **)(model + 4) + 0x80000000U;

        g = frontgfx;
        frontgfx = g + 1;
        g->words.w1 = (u32) texOfs + 0x80000000U;
        g->words.w0 = 0x02000050;

        g = frontgfx;
        frontgfx = g + 1;
        g->words.w0 = 0x06000000;
        g->words.w1 = *(u32 *)(hdr + 0x74) + 0x80000000U;

        g = frontgfx;
        frontgfx = g + 1;
        g->words.w1 = 0;
        g->words.w0 = 0xBF000000;

        camRestoreModelMtx(&frontgfx);
        texDPInit(&frontgfx);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/func_overlay_18_01203BB4_1F3358C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *frontMenuPodiumGetTiltList(void) {
    return D_overlay_18_01206BB0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/frontMenuPodiumGetTiltList.s")
#endif


#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_18_012040A8_1F33A80(f32 arg0, s32 arg1) {
    u8 *base;
    u8 *rec;
    u8 *v1rec;
    u8 *a1;
    u8 *hdr;
    u8 *sub;
    u8 *tp;
    u8 *ent;
    f32 delta;
    s32 n;
    s32 t1;
    s16 val;
    s16 val2;

    base = currentobjects + (arg1 << 5);
    if (D_overlay_18_01206BCC == 0) {
        delta = arg0 * 10.0f;
        *(f32 *)(base + 0x0C) += delta;
        if (*(f32 *)(base + 0x0C) > 0.0f) {
            *(f32 *)(base + 0x0C) = 0.0f;
        }
        *(f32 *)(base + 0x2C) -= delta;
        if (*(f32 *)(base + 0x2C) < 0.0f) {
            *(f32 *)(base + 0x2C) = 0.0f;
            *(f32 *)(base + 0x50) += delta;
            if (*(f32 *)(base + 0x50) > 0.0f) {
                *(f32 *)(base + 0x50) = 0.0f;
            }
            *(f32 *)(base + 0x70) -= delta;
            if (*(f32 *)(base + 0x70) < 0.0f) {
                *(f32 *)(base + 0x70) = 0.0f;
                D_overlay_18_01206BCC = 1;
            }
        }
    }

    if (D_overlay_18_01206BCC != 0) {
        rec = base;
        v1rec = currentobjects;
        do {
            v1rec += 0x20;
            a1 = *(u8 **)((u8 *)frontendptrs[*(s16 *)(rec + 6)] + 0x6C);
            hdr = *(u8 **)a1;
            tp = *(u8 **)(a1 + (a1[0xB] * 4) + 0x78);
            sub = *(u8 **)(a1 + 0x74);
            n = *(s32 *)(hdr + 0x2C);
            for (t1 = 0; t1 < n; t1++) {
                ent = *(u8 **)(*(u8 **)(hdr + 0x18) + (sub[4] * 8));
                if (*(u32 *)(ent + 6) & 0x10000) {
                    *(s16 *)sub = 0x100;
                    if (*(s16 *)(sub + 2) >= 0) {
                        val = 0x200;
                        if (*(s16 *)(ent + 0x12) <= 0x200) {
                            val = 0x100;
                        }
                        *(s16 *)(sub + 2) = val;
                    }
                }
                *(s16 *)tp = (s16) ((*(s16 *)sub >> 8) * *(s16 *)(ent + 0x16));
                tp += 2;
                val2 = *(s16 *)(sub + 2);
                if (val2 >= 0) {
                    *(s16 *)tp = (s16) ((val2 >> 8) * *(s16 *)(ent + 0x16));
                    tp += 2;
                }
                sub += 8;
            }
            rec += 0x20;
        } while (v1rec != D_800FF800);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/func_overlay_18_012040A8_1F33A80.s")
#endif


#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void healthScreenInit(void) {
    s32 charIdx;

    loadFrontEndList(&D_overlay_18_012067E0);
    setupFrontEndList(&D_overlay_18_012067E8);
    D_overlay_18_01206BCC = 0;
    objAnimSetMove(D_800FF614, 0, 0);
    objAnimSetMove(D_800FF618, 0, 0);
    charIdx = func_overlay_18_0120207C_1F31A54(*(s8 **)((u8 *)objGetPlayerNo(0) + 0x68));
    loadFrontEndList(&D_overlay_18_012067F4[charIdx * 3]);
    *(s16 *)(currentobjects + 0x3E6) = 0x8F;
    *(s16 *)(currentobjects + 0x626) = D_overlay_18_012067F4[charIdx * 3 + 1];
    D_overlay_18_01206D18 = 0;
    D_overlay_18_01206D1A = 0;
    D_overlay_18_01206D1B = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/healthScreenInit.s")
#endif


#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void healthScreenCleanup(void) {
    s32 charIdx;

    charIdx = func_overlay_18_0120207C_1F31A54(*(s8 **)((u8 *)objGetPlayerNo(0) + 0x68));
    freeFrontEndList(&D_overlay_18_012067E0);
    freeFrontEndList(&D_overlay_18_012067F4[charIdx * 3]);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/healthScreenCleanup.s")
#endif


#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void healthScreen(s32 arg0) {
    s8 *playerData;
    s32 charIdx;
    u8 *chr;
    u8 *model;
    u8 *hdrObj;
    s32 health;
    s32 segCount;
    s32 segDiv;
    s32 hi;
    s32 lo;
    s32 lo2;
    s32 lo3;
    s32 shown;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s1_3;
    s32 hour;
    s32 minute;
    s32 second;
    s32 unusedTime;
    s8 *var_s0;
    char text[32];
    s32 sndFlag;
    s32 digits;
    u8 *obj614;
    u8 *m;

    func_overlay_18_01200000_1F2F9D8();
    playerData = *(s8 **)((u8 *)objGetPlayerNo(0) + 0x68);
    charIdx = func_overlay_18_0120207C_1F31A54(playerData);
    chr = (u8 *) mainGetGameCharacter(playerData[0], charIdx);
    health = *(s16 *)chr >> 8;
    segCount = chr[2];
    *(s16 *)(currentobjects + 0x5E0) = (s16) (*(s16 *)(currentobjects + 0x5E0) + (arg0 << 8));
    *(s16 *)(currentobjects + 0x600) = (s16) (*(s16 *)(currentobjects + 0x600) - (arg0 << 8));

    model = *(u8 **)((u8 *)D_800FF618 + 0x6C);
    model[0xA] = (u8) arg0;
    segDiv = segCount + 1;
    hi = health % segDiv;
    lo = health / segDiv;
    shown = hi;
    digits = lo;

    if (D_overlay_18_01206D18 < 0x168) {
        if (hi == 0 && D_overlay_18_01206D18 < 0xF0) {
            D_overlay_18_01206D18 = 0xF0;
        } else {
            D_overlay_18_01206D18 += arg0;
        }
    }
    sndFlag = D_overlay_18_01206D1A < shown;
    if (hi != D_overlay_18_01206D1A) {
        lo2 = (s16) D_overlay_18_01206D18 / 12;
        if (lo2 < hi) {
            shown = lo2;
        } else {
            D_overlay_18_01206D18 = 0xF0;
        }
        sndFlag = D_overlay_18_01206D1A < shown;
    }
    if (sndFlag != 0) {
        amSndPlay(0x16B, NULL);
    }
    D_overlay_18_01206D1A = (s8) shown;
    if (D_overlay_18_01206D18 >= 0xF1) {
        if (lo != D_overlay_18_01206D1B) {
            lo3 = (D_overlay_18_01206D18 - 0xF0) / 12;
            if (lo3 < lo) {
                digits = lo3;
            }
        }
        if (digits == lo) {
            D_overlay_18_01206D18 = 0x1E0;
        }
    } else {
        digits = 0;
    }
    if (D_overlay_18_01206D1B < digits) {
        amSndPlay(0x16C, NULL);
    }
    D_overlay_18_01206D1B = (s8) digits;

    modSetTextureFrame(model, 0, (4 - digits) << 8);
    for (var_s1 = 0; var_s1 < 4; var_s1++) {
        if (digits != 0) {
            modSetTextureFrame(model, D_overlay_18_01206808[var_s1], 0);
            digits -= 1;
        } else {
            modSetTextureFrame(model, D_overlay_18_01206808[var_s1], 0x100);
        }
    }
    camOverrideProjScales(1.0f, 1.0f);
    camSetFOV(52.0f, 1);
    camStandardPersp(&frontgfx, &frontmtx);
    frontDrawObj(0x2F);

    obj614 = (u8 *) D_800FF614;
    m = *(u8 **)(obj614 + 0x6C);
    m[0xA] = (u8) arg0;
    var_s1 = 0;
    do {
        if (shown != 0) {
            shown -= 1;
            modSetTextureFrame(m, var_s1, 0);
        } else {
            modSetTextureFrame(m, var_s1, 0x100);
        }
        var_s1 += 1;
    } while (var_s1 < 6);

    var_s1_2 = 6;
    if (segCount >= 7) {
        do {
            obj614[0x3A] = (s8) (obj614[0x3A] + 1);
            hdrObj = *(u8 **)(obj614 + 0x6C + (obj614[0x3A] * 4));
            if (shown != 0) {
                shown -= 1;
                modSetTextureFrame(hdrObj, 0, 0);
            } else {
                modSetTextureFrame(hdrObj, 0, 0x100);
            }
            frontDrawObj(0x2F);
            var_s1_2 += 1;
        } while (var_s1_2 != segCount);
    }
    obj614[0x3A] = 0;
    frontDrawObj(0x30);
    frontDrawObj(0x1F);
    frontCharBadge(1, D_overlay_18_01206D18 >= 0x169, arg0);

    fontUseFont(2);
    fontColour(0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
    fontPrintXY(&frontgfx, 0x2C, 0xA0, *(char **)(front_text + (charIdx * 4) + 0x634), 0);
    fontColour(0xFF, 0xFF, 0, 0xFF, 0xFF);
    var_s1_3 = health / 8;
    if (var_s1_3 >= 8) {
        var_s1_3 = 7;
    }
    sprintf(text, D_overlay_18_01206B1C, *(char **)(front_text + (var_s1_3 * 4) + 0x640), health, (segCount * 5) + 4);
    fontPrintXY(&frontgfx, 0x3E, 0xAF, text, 0);
    if (joyGetPressed(pausePlayer) & 0x4000) {
        pauseSetScreen(1);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/healthScreen.s")
#endif


#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void shipScreenInit(void) {
    s32 wasLoaded;
    u8 *model;

    wasLoaded = runlinkIsModuleLoaded(0x14);
    D_overlay_18_01206BF5 = (u8) runlinkIsModuleLoaded(0x2B);
    loadFrontEndList(&D_overlay_18_01206810);
    setupFrontEndList(&D_overlay_18_0120681C);
    D_overlay_18_01206BCC = 0;
    if (wasLoaded == 0) {
        runlinkFreeCode(0x14);
    }
    func_overlay_18_012057D8_1F351B0();
    D_overlay_18_01206BD3 = 0;
    D_overlay_18_01206BD1 = (s8) D_overlay_18_01206874[D_overlay_18_01206BD3];
    model = *(u8 **)((u8 *)D_800FF5E4 + 0x6C);
    D_overlay_18_01206BD0 = D_overlay_18_01206BD1;
    loadFrontEndItem(0x6F);
    *(s16 *)(currentobjects + 0x4A6) = 0x6F;
    func_overlay_18_01205800_1F351D8((s32) (*(u8 **)(model + 0x68) + D_overlay_18_01206920[D_overlay_18_01206BD0] * 12));
    *(f32 *)(currentobjects + 0x4AC) = 0.0f;
    *(f32 *)(currentobjects + 0x4B0) = 0.0f;
    D_overlay_18_01206BD8 = D_overlay_18_0120682C[D_overlay_18_01206BD1 * 3];
    *(s16 *)(currentobjects + 0x4C0) = D_overlay_18_01206BD8;
    D_overlay_18_01206BD2 = 0;
    D_overlay_18_01206BEC = D_overlay_18_01206B88;
    D_overlay_18_01206BE0 = D_overlay_18_01206898[D_overlay_18_01206BD0];
    if (D_overlay_18_01206BE0 == -1) {
        D_overlay_18_01206BE0 = 0;
        D_overlay_18_01206BF0 = 0.0f;
    } else {
        D_overlay_18_01206BF0 = D_overlay_18_012068E0[D_overlay_18_01206BE0];
    }
    objAnimSetMove(D_800FF5E4, D_overlay_18_01206BE0, 0);
    D_overlay_18_01206BD4 = 0x78;
    D_overlay_18_01206BE8 = 0x100;
    D_overlay_18_01206BD5 = 0x1E;
    D_overlay_18_01206BD6 = 0;
    D_overlay_18_01206BF4 = 0;
    D_overlay_18_01206BF6 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/shipScreenInit.s")
#endif


#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void shipScreen(s32 arg0) {
    u8 *model;
    u8 *hdr;
    u8 *obj;
    u8 *cam;
    u8 *sub;
    u8 *wr;
    u8 *ent;
    u8 *model2;
    f32 argF;
    f32 svC;
    f32 svC10;
    f32 svC14;
    f32 svX;
    f32 svY;
    f32 svZ;
    f32 varF2;
    s32 flag56;
    s32 flag57;
    s32 joy;
    s32 i;
    s32 t9;
    s32 v1x8;
    s32 n;
    s32 k;
    s32 t6;
    s32 t7;
    s32 newOld;
    s32 fontCount;
    s32 tbl0;
    s32 fromIdx;
    s32 ypos;
    s32 val2;
    s16 val;

    argF = (f32) arg0;
    func_overlay_18_012040A8_1F33A80(argF, 0x21);
    func_overlay_18_01200000_1F2F9D8();
    obj = (u8 *) D_800FF5E4;
    model = *(u8 **)(obj + 0x6C);
    hdr = *(u8 **)model;
    model[0xA] = (u8) arg0;
    objAnimDframe(obj, D_overlay_18_01206BF0, argF);
    flag56 = mainGetGameFlag(D_overlay_18_01206BD0 + 0x20);
    joy = frontJoyDx[pausePlayer];
    flag57 = mainGetGameFlag(D_overlay_18_01206BD1 + 0x20);

    if (joy < -0x20 && D_overlay_18_01206BF6 == 0) {
        func_overlay_18_01205850_1F35228((s32) (*(u8 **)(model + 0x68) + D_overlay_18_01206920[D_overlay_18_01206BD0] * 12));
        D_overlay_18_01206BD3 -= 1;
        if (D_overlay_18_01206BD3 < 0) {
            D_overlay_18_01206BD3 = 0xB;
        }
        D_overlay_18_01206BD0 = (s8) D_overlay_18_01206874[D_overlay_18_01206BD3];
        func_overlay_18_01205800_1F351D8((s32) (*(u8 **)(model + 0x68) + D_overlay_18_01206920[D_overlay_18_01206BD0] * 12));
        D_overlay_18_01206BD2 = 1;
        D_overlay_18_01206BD4 = 0x78;
        amSndPlay(0x16B, NULL);
    } else if (joy >= 0x21 && D_overlay_18_01206BF6 == 0) {
        func_overlay_18_01205850_1F35228((s32) (*(u8 **)(model + 0x68) + D_overlay_18_01206920[D_overlay_18_01206BD0] * 12));
        D_overlay_18_01206BD3 += 1;
        if (D_overlay_18_01206BD3 >= 0xC) {
            D_overlay_18_01206BD3 = 0;
        }
        D_overlay_18_01206BD0 = (s8) D_overlay_18_01206874[D_overlay_18_01206BD3];
        func_overlay_18_01205800_1F351D8((s32) (*(u8 **)(model + 0x68) + D_overlay_18_01206920[D_overlay_18_01206BD0] * 12));
        D_overlay_18_01206BD2 = 2;
        D_overlay_18_01206BD4 = 0x78;
        amSndPlay(0x16B, NULL);
    }

    if (D_overlay_18_01206BCC != 0) {
        D_overlay_18_01206BD6 += arg0;
        if (D_overlay_18_01206BD6 >= 0x61) {
            D_overlay_18_01206BD6 = 0x60;
        }
        texDPTextureX(&frontgfx, 0, 0, 0);
        frontgfx->words.w0 = 0xFB000000;
        frontgfx->words.w1 = (D_overlay_18_01206BD6 & 0xFF) | 0x283200;
        frontgfx++;
        frontgfx->words.w0 = 0xFA000000;
        frontgfx->words.w1 = 0x1E5A00;
        frontgfx++;
        frontgfx->words.w1 = (u32) D_81206670;
        frontgfx->words.w0 = 0x07020010;
        frontgfx++;
        frontgfx->words.w1 = 0x9C07C;
        frontgfx->words.w0 = 0xF61EC214;
        frontgfx++;

        camSetNo(0);
        camSetUserView(0, 0x88, 0x20, 0x116, 0x84);
        camEnableUserView(0, 1);
        camUserViewTick();
        cam = (u8 *) camGetPtr();
        svC = *(f32 *)(cam + 0xC);
        svC10 = *(f32 *)(cam + 0x10);
        svC14 = *(f32 *)(cam + 0x14);
        svZ = (f32) *(s16 *)(cam + 0x4);
        svY = (f32) *(s16 *)(cam + 0x2);
        svX = (f32) *(s16 *)(cam + 0x0);
        *(s16 *)(cam + 0x4) = 0;
        *(s16 *)(cam + 0x2) = 0;
        *(s16 *)(cam + 0x0) = 0;
        *(f32 *)(cam + 0xC) = 0.0f;
        *(f32 *)(cam + 0x10) = 30.0f;
        *(f32 *)(cam + 0x14) = D_overlay_18_01206BEC;
        camSetView(&frontgfx, &frontmtx);
        modGenAnimMatrices(model, hdr, obj, 1.0f, 0.0f);
        lightObject(obj, model, *(s32 *)(obj + 0x54), *(s32 *)(model + (model[0xB] * 4) + 0x10));
        model[0xA] = 0;
        wr = *(u8 **)(model + (model[0xB] * 4) + 0x78);
        sub = *(u8 **)(model + 0x74);
        if (mainGetGameFlag(0x25) != 0) {
            if (arg0 < D_overlay_18_01206BD5) {
                D_overlay_18_01206BD5 -= arg0;
            } else {
                D_overlay_18_01206BD5 += 0x1E;
                D_overlay_18_01206BE8 ^= 0x100;
            }
        } else {
            D_overlay_18_01206BE8 = 0x100;
        }

        n = *(s32 *)(hdr + 0x2C);
        for (i = 0; i < n; i++) {
            t9 = sub[4] & 0xFF;
            v1x8 = t9 * 8;
            ent = *(u8 **)(*(u8 **)(hdr + 0x18) + v1x8);
            if (t9 == 2 || v1x8 == 0x60 || v1x8 == 0x68) {
                *(s16 *)sub = (s16) D_overlay_18_01206BE8;
            }
            *(s16 *)wr = (s16) ((*(s16 *)sub >> 8) * *(s16 *)(ent + 0x16));
            wr += 2;
            val2 = *(s16 *)(sub + 2);
            if (val2 >= 0) {
                *(s16 *)wr = (s16) ((val2 >> 8) * *(s16 *)(ent + 0x16));
                wr += 2;
            }
            sub += 8;
        }

        frontDrawObj(0x26);
        func_overlay_18_01205880_1F35258(arg0);
        if (D_800FF5B4[D_overlay_18_01206BD1] == 0) {
            *(s16 *)(currentobjects + 0x4A6) = (s16) (D_overlay_18_01206BD1 + 0x6F);
            *(f32 *)(currentobjects + 0x4B0) = 0.0f;
            loadFrontEndItem(*(s16 *)(currentobjects + 0x4A6));
        }
        *(f32 *)(cam + 0xC) = svC;
        *(f32 *)(cam + 0x10) = svC10;
        *(f32 *)(cam + 0x14) = svC14;
        *(s16 *)(cam + 0x0) = (s16) svX;
        *(s16 *)(cam + 0x2) = (s16) svY;
        *(s16 *)(cam + 0x4) = (s16) svZ;

        camSetNo(1);
        cam = (u8 *) camGetPtr();
        camSetUserViewSpecial(1, 0x51, D_overlay_18_01206914[D_overlay_18_01206BD1], 0x8000, 0x8000);
        camEnableUserView(1, 1);
        camUserViewTick();
        *(f32 *)(cam + 0xC) = 0.0f;
        *(f32 *)(cam + 0x10) = 0.0f;
        *(s16 *)(cam + 0x4) = 0;
        *(s16 *)(cam + 0x2) = 0;
        *(s16 *)(cam + 0x0) = 0;
        *(f32 *)(cam + 0x14) = D_overlay_18_01206B8C;
        camSetView(&frontgfx, &frontmtx);
        frontgfx->words.w0 = 0xED0A0050;
        frontgfx->words.w1 = 0x1E8210;
        frontgfx++;

        ent = (u8 *) frontendptrs[*(s16 *)(currentobjects + 0x4A6)];
        model2 = *(u8 **)(ent + 0x6C);
        model2[0xA] = (u8) arg0;
        lightObject(ent, model2, *(s32 *)(ent + 0x54), 0);
        model2[0xA] = 0;

        if (flag57 == 0) {
            frontgfx->words.w1 = 0x6000FF;
            frontgfx->words.w0 = 0xF8000000;
            frontgfx++;
            frontgfx->words.w1 = 0x05000500;
            frontgfx->words.w0 = 0xBC000008;
            frontgfx++;
        }
        objtrans = (s32) D_overlay_18_01206BF4;
        frontDrawObj(0x25);
        objtrans = 0xFF;
        frontgfx->words.w0 = 0xBC000008;
        frontgfx->words.w1 = 0x40004;
        frontgfx++;
        camDisableUserView(0, 1);
        camDisableUserView(1, 1);
        camStandardPersp(&frontgfx, &frontmtx);
        camSetView(&frontgfx, NULL);

        newOld = D_overlay_18_01206BD1;
        if (D_overlay_18_01206BD0 != newOld) {
            t7 = arg0 * 8;
            if (t7 < (s32) D_overlay_18_01206BF4) {
                D_overlay_18_01206BF4 -= t7;
            } else {
                D_overlay_18_01206BF4 = 0;
                freeFrontEndItem(newOld + 0x6F);
                D_overlay_18_01206BD1 = D_overlay_18_01206BD0;
            }
            D_overlay_18_01206BD8 = D_overlay_18_0120682C[newOld * 3];
            D_overlay_18_01206BE0 = D_overlay_18_01206898[D_overlay_18_01206BD0];
            if (D_overlay_18_01206BE0 == -1 || flag56 == 0) {
                D_overlay_18_01206BE0 = 0;
                D_overlay_18_01206BF0 = 0.0f;
            } else {
                D_overlay_18_01206BF0 = D_overlay_18_012068E0[D_overlay_18_01206BE0];
            }
            objAnimSetMove(obj, D_overlay_18_01206BE0, 0);
        } else {
            t6 = arg0 * 4;
            if ((s32) D_overlay_18_01206BF4 < (0xFF - t6)) {
                D_overlay_18_01206BF4 += t6;
            } else {
                D_overlay_18_01206BF4 = 0xFF;
            }
        }

        varF2 = (f32) D_overlay_18_01206880[D_overlay_18_01206BD0];
        if (D_overlay_18_01206BD4 > 0) {
            D_overlay_18_01206BD4 -= arg0;
        }
        k = arg0 - 1;
        if (arg0 != 0) {
            do {
                *(f32 *)(currentobjects + 0x4AC) += (0.0f - *(f32 *)(currentobjects + 0x4AC)) * 0.25f;
                if (D_overlay_18_01206BD4 > 0) {
                    *(s16 *)(currentobjects + 0x4C0) = dAngle(*(s16 *)(currentobjects + 0x4C0), D_overlay_18_01206BD8, 0x3D051EB8, &D_overlay_18_01206BEC);
                }
                D_overlay_18_01206BEC += (varF2 - D_overlay_18_01206BEC) * 0.125f;
                k -= 1;
            } while (k != 0);
        }
        if (D_overlay_18_01206BD4 <= 0) {
            *(s16 *)(currentobjects + 0x4C0) = (s16) (*(s16 *)(currentobjects + 0x4C0) + (arg0 * 0x70));
        }
        *(s16 *)(currentobjects + 0x4A0) = (s16) (*(s16 *)(currentobjects + 0x4A0) + (arg0 * 0xC0));
        camSetScissor(&frontgfx);

        fontUseFont(2);
        ypos = 0xA0;
        fontCount = D_overlay_18_012068B2[D_overlay_18_01206BD0 * 2];
        fontColour(0xFF, 0xFF, 0, 0xFF, 0xFF);
        tbl0 = D_overlay_18_012068B0[D_overlay_18_01206BD0 * 2];
        fontPrintXY(&frontgfx, 0x3C, 0x96, *(char **)(front_text + (tbl0 * 4)), 0);
        fontColour(0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
        fromIdx = (tbl0 + 1) * 4;
        if (fontCount >= 2) {
            for (k = 1; k != fontCount; k++) {
                fontPrintXY(&frontgfx, 0x3C, ypos, *(char **)(front_text + fromIdx), 0);
                fromIdx += 4;
                ypos += 0xA;
            }
        }
    }

    camOverrideProjScales(1.0f, 1.0f);
    camSetFOV(52.0f, 1);
    camStandardPersp(&frontgfx, &frontmtx);
    frontDrawObj(0x21);
    frontDrawObj(0x22);
    frontDrawObj(0x23);
    frontDrawObj(0x24);
    camSetFOV(52.0f, 1);
    if (joyGetPressed(pausePlayer) & 0x4000) {
        pauseSetScreen(1);
        D_overlay_18_01206BF6 = 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/shipScreen.s")
#endif


#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void shipScreenCleanup(void) {
    freeFrontEndList(&D_overlay_18_01206810);
    freeFrontEndItem(D_overlay_18_01206BD1 + 0x6F);
    if (D_overlay_18_01206BF5 == 0) {
        runlinkFreeCode(0x2B);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/shipScreenCleanup.s")
#endif


#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_18_012057D8_1F351B0(void) {
    u8 *p;
    s32 i;

    p = D_overlay_18_01206BF8;
    i = 2;
    do {
        *p = 0;
        p += 8;
    } while (i--);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/func_overlay_18_012057D8_1F351B0.s")
#endif


#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_18_01205800_1F351D8(s32 arg0) {
    s8 *rec;
    s32 i;

    rec = D_overlay_18_01206BF8;
    i = 2;
    do {
        if (rec[0] == 0) {
            rec[0] = 1;
            rec[1] = 0x1E;
            rec[2] = 0x1E;
            rec[3] = 0x1E;
            *(s32 *)(rec + 4) = arg0;
            return;
        }
        rec += 8;
    } while (i--);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/func_overlay_18_01205800_1F351D8.s")
#endif


#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_18_01205850_1F35228(s32 arg0) {
    s32 i;
    s32 target;

    target = (s32) D_overlay_18_01206BFC;
    i = 2;
    do {
        if (arg0 == target) {
            D_overlay_18_01206BF8[0] = 0;
            return i;
        }
    } while (i--);
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/func_overlay_18_01205850_1F35228.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_18_01205880_1F35258(s32 arg0) {
    f32 sx;
    f32 sy;
    f32 *pos;
    s8 old9;
    s8 oldA;
    s8 *s1;
    s32 pass;
    s32 i;
    s32 s2;
    s32 last;
    s32 r;

    for (pass = 0; pass < 2; pass++) {
        if (D_overlay_18_01206BF8[0] != 0) {
            /* asm: rotate the three bytes BF9..BFB, BF9 moves by -arg0 */
            old9 = D_overlay_18_01206BF9;
            oldA = D_overlay_18_01206BFA;
            D_overlay_18_01206BF9 = (s8) (old9 - arg0);
            D_overlay_18_01206BFA = old9;
            D_overlay_18_01206BFB = oldA;
        }
        if (D_overlay_18_01206BF9 < 0) {
            D_overlay_18_01206BF9 = 0;
        }
        pos = (f32 *) D_overlay_18_01206BFC;
        if (camProjectPoint(pos[0], pos[1], pos[2], &sx, &sy, 1) != 0) {
            s1 = &D_overlay_18_01206BF9;
            s2 = 0xA0;
            last = -1;
            for (i = 0; i < 2; i++) {
                if (D_overlay_18_01206BF8[0] != 0) {
                    r = (*s1 * 2) + 8;
                    if (r != last) {
                        func_overlay_18_01205A24_1F353FC((s16) ((s32) sx - r), (s16) ((s32) sy - r), r * 2, r * 2, 0xFF0000 | s2);
                        last = r;
                    }
                }
                s2 -= 0x34;
                s1 += 1;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/func_overlay_18_01205880_1F35258.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_18_01205A24_1F353FC(s16 arg0, s16 arg1, s32 arg2, s32 arg3, s32 arg4) {
    struct {
        s16 x0;
        s16 y0;
        s16 x1;
        s16 y1;
        s32 c;
    } rects[8];
    s16 w;
    s16 h;

    w = arg0 + arg2;
    h = arg1 + arg3;
    rects[0].x0 = arg0 - 2;  rects[0].y0 = arg1 - 2;  rects[0].x1 = w + 2;      rects[0].y1 = arg1 + 3;  rects[0].c = 0;
    rects[1].x0 = arg0;      rects[1].y0 = arg1;      rects[1].x1 = w + 1;      rects[1].y1 = arg1 + 1;  rects[1].c = arg4;
    rects[2].x0 = arg0 - 2;  rects[2].y0 = arg1 - 2;  rects[2].x1 = arg0 + 3;   rects[2].y1 = h + 2;      rects[2].c = 0;
    rects[3].x0 = arg0;      rects[3].y0 = arg1 + 1;  rects[3].x1 = arg0 + 1;   rects[3].y1 = h;          rects[3].c = arg4;
    rects[4].x0 = w - 2;     rects[4].y0 = arg1 - 2;  rects[4].x1 = w + 3;      rects[4].y1 = h + 2;      rects[4].c = 0;
    rects[5].x0 = w;         rects[5].y0 = arg1 + 1;  rects[5].x1 = w + 1;      rects[5].y1 = h;          rects[5].c = arg4;
    rects[6].x0 = arg0 - 2;  rects[6].y0 = h - 2;     rects[6].x1 = w + 2;      rects[6].y1 = h + 3;      rects[6].c = 0;
    rects[7].x0 = arg0;      rects[7].y0 = h;         rects[7].x1 = w + 1;      rects[7].y1 = h + 1;      rects[7].c = arg4;
    frontDrawRectangles(&frontgfx, 8, rects, 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/func_overlay_18_01205A24_1F353FC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void inventoryScreenInit(void) {
    loadFrontEndList(D_overlay_18_0120692C);
    loadFrontEndItem(0x91);
    D_overlay_18_01206C74 = 0x91;
    setupFrontEndList(D_overlay_18_01206930);
    D_800FFB66 = 0x92;
    D_overlay_18_01206C60 = 0;
    D_overlay_18_01206C70 = 0;
    D_overlay_18_01206C68 = 0xFF;
    D_overlay_18_01206C64 = 0;
    D_overlay_18_01206C6C = 0;
    D_overlay_18_01206C78 = 0;
    D_overlay_18_01206C80 = 0;
    D_overlay_18_01206C7C = 0;
    D_overlay_18_01206C84 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/inventoryScreenInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void inventoryScreenCleanup(void) {
    freeFrontEndList(D_overlay_18_0120692C);
    freeFrontEndItem(D_overlay_18_01206C74);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/inventoryScreenCleanup.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void inventoryScreen(s32 arg0) {
    s8 *plr;
    s32 charIdx;
    void *chr;
    Game *game;
    Gfx *gfxp;
    u32 texAddr;
    char text[16];
    u8 *objA;
    u8 *objB;
    s16 *p;
    s16 *outp;
    s16 v;
    s16 sv;
    s16 a2;
    s16 s3;
    s32 n17;
    s32 n18;
    s32 total;
    s32 flagAny;
    s32 g2C;
    s32 g2E;
    s32 g2D;
    s16 savedCur640;
    u8 gb;
    s32 j;

    plr = *(s8 **)((u8 *)objGetPlayerNo(0) + 0x68);
    charIdx = func_overlay_18_0120207C_1F31A54(plr);
    chr = mainGetGameCharacter(*plr, charIdx);
    game = mainGetGame();
    func_overlay_18_01200000_1F2F9D8();
    camOverrideProjScales(1.0f, 1.0f);
    camSetFOV(52.0f, 1);
    camStandardPersp(&frontgfx, &frontmtx);
    frontDrawObj(0x1F);
    fontUseFont(2);
    fontColour(0, 0, 0xFF, 0xFF, D_overlay_18_01206C68);
    objtrans = D_overlay_18_01206C68;
    *(s16 *)(currentobjects + 0x640) = (s16)(*(s16 *)(currentobjects + 0x640) + (arg0 << 8));

    if (D_overlay_18_01206C78 != 0) {
        mmSetDelay(0);
        freeFrontEndItem(D_overlay_18_01206C74);
        mmSetDelay(2);
        D_overlay_18_01206C74 = D_overlay_18_012069EC[D_overlay_18_01206C60];
        loadFrontEndItem(D_overlay_18_01206C74);
        D_overlay_18_01206C78 = 0;
    }

    if (D_overlay_18_01206C68 > 0) {
        D_overlay_18_01206C7C = 0;
        switch (D_overlay_18_01206C60) {
        case 0:
            fontPrintXY(&frontgfx, 0xA0, 0x21, *(char **)(front_text + 0x6D8), 4);
            fontPrintXY(&frontgfx, 0xA0, 0x5D, *(char **)(front_text + 0x6DC), 4);
            fontPrintXY(&frontgfx, 0xA0, 0x98, *(char **)(front_text + 0x6E0), 4);
            objA = (u8 *)D_800FF63C;
            *(s16 *)(currentobjects + 0x646) = 0x91;
            p = D_overlay_18_01206938;
            outp = D_overlay_18_01206C10;
            v = p[0];
            if (v != -1) {
                do {
                    if (v == 0) {
                        /* asm: zero entry sets the draw origin, then skips 4 halfwords */
                        *(f32 *)(currentobjects + 0x64C) = (f32)p[2];
                        p += 4;
                        *(f32 *)(currentobjects + 0x650) = (f32)p[-1];
                        v = p[0];
                    }
                    sv = v;
                    D_overlay_18_012067B8 = (f32)p[1] * 0.0078125f;
                    p += 5;
                    a2 = p[-2];
                    s3 = p[-3];
                    outp[0] = (s16)(s32)*(f32 *)(currentobjects + 0x64C);
                    outp[1] = (s16)(s32)*(f32 *)(currentobjects + 0x650);
                    outp += 2;
                    if (a2 == 0x17) {
                        n18 = mainPlayerHas(*plr, charIdx, 0x18);
                        n17 = mainPlayerHas(*plr, charIdx, 0x17);
                        total = mainPlayerHas(*plr, charIdx, 0x19) + n17 + n18;
                        if (total != 0) {
                            objA[0x3A] = (s8)(sv + total - 1);
                            *(f32 *)(currentobjects + 0x648) = D_overlay_18_012067B8;
                            frontDrawObj(0x32);
                        }
                        *(f32 *)(currentobjects + 0x64C) += (f32)s3;
                    } else if (mainPlayerHas(*plr, charIdx, a2) != 0) {
                        objA[0x3A] = (s8)sv;
                        *(f32 *)(currentobjects + 0x648) = D_overlay_18_012067B8;
                        frontDrawObj(0x32);
                        *(f32 *)(currentobjects + 0x64C) += (f32)s3;
                    }
                    v = p[0];
                } while (v != -1);
            }
            savedCur640 = *(s16 *)(currentobjects + 0x640);
            *(s16 *)(currentobjects + 0x640) = -0x8000;
            objA[0x3A] = 0xF;
            *(f32 *)(currentobjects + 0x648) = D_overlay_18_01206B90;
            *(f32 *)(currentobjects + 0x64C) = -30.0f;
            *(f32 *)(currentobjects + 0x650) = -75.0f;
            frontDrawObj(0x32);
            *(f32 *)(currentobjects + 0x64C) = 90.0f;
            frontDrawObj(0x32);
            *(s16 *)(currentobjects + 0x640) = savedCur640;
            objA[0x3A] = 0xD;
            *(f32 *)(currentobjects + 0x648) = D_overlay_18_01206B94;
            *(f32 *)(currentobjects + 0x64C) = -101.0f;
            *(f32 *)(currentobjects + 0x650) = -82.0f;
            frontDrawObj(0x32);
            sprintf(text, D_overlay_18_01206B2C, *(u16 *)((u8 *)chr + 0x8));
            fontPrintXY(&frontgfx, 0x86, 0xB7, text, 4);
            objA[0x3A] = 0xC;
            *(f32 *)(currentobjects + 0x64C) = 35.0f;
            *(f32 *)(currentobjects + 0x650) = -82.0f;
            frontDrawObj(0x32);
            sprintf(text, D_overlay_18_01206B30, *(u16 *)((u8 *)chr + 0x6));
            fontPrintXY(&frontgfx, 0xF2, 0xB7, text, 4);
            break;
        case 1:
            fontPrintXY(&frontgfx, 0xA0, 0x21, *(char **)(front_text + 0x6E4), 4);
            fontPrintXY(&frontgfx, 0xA0, 0x5D, *(char **)(front_text + 0x6E8), 4);
            fontPrintXY(&frontgfx, 0xA0, 0x98, *(char **)(front_text + 0x6EC), 4);
            objB = (u8 *)D_800FF678;
            *(s16 *)(currentobjects + 0x646) = 0xA0;
            objB[0x3A] = 0xA;
            savedCur640 = *(s16 *)(currentobjects + 0x640);
            *(s16 *)(currentobjects + 0x640) = -0x8000;
            *(f32 *)(currentobjects + 0x648) = D_overlay_18_01206B98;
            *(f32 *)(currentobjects + 0x64C) = 0.0f;
            *(f32 *)(currentobjects + 0x650) = 61.0f;
            frontDrawObj(0x32);
            *(s16 *)(currentobjects + 0x640) = savedCur640;
            sprintf(text, D_overlay_18_01206B34, *(s16 *)((u8 *)chr + 0x12));
            fontPrintXY(&frontgfx, 0xA0, 0x3C, text, 4);
            objB[0x3A] = 0;
            *(f32 *)(currentobjects + 0x648) = 0.25f;
            *(f32 *)(currentobjects + 0x64C) = -70.0f;
            *(f32 *)(currentobjects + 0x650) = 58.0f;
            frontDrawObj(0x32);
            *(f32 *)(currentobjects + 0x648) = D_overlay_18_01206B9C;
            *(f32 *)(currentobjects + 0x64C) = -100.0f;
            *(f32 *)(currentobjects + 0x650) = -6.0f;
            /* five Game bytes at +0x28.. each select an icon from the s32 table */
            for (j = 0; j < 5; j++) {
                gb = game->pad[0x28 + j];
                if (gb != 0) {
                    objB[0x3A] = (s8)D_overlay_18_012069D0[gb];
                    frontDrawObj(0x32);
                }
                *(f32 *)(currentobjects + 0x64C) += 48.0f;
            }
            *(f32 *)(currentobjects + 0x648) = D_overlay_18_01206BA0;
            *(f32 *)(currentobjects + 0x64C) = 0.0f;
            *(f32 *)(currentobjects + 0x650) = -83.0f;
            flagAny = game->pad[9] & 0x10;
            g2C = mainGetGameFlag(0x2C);
            g2E = mainGetGameFlag(0x2E);
            g2D = mainGetGameFlag(0x2D);
            flagAny = flagAny | g2D | g2E | g2C;
            if (mainGetGameFlag(0x2D) != 0) {
                objB[0x3A] = 2;
                frontDrawObj(0x32);
            }
            if (mainGetGameFlag(0x2E) != 0) {
                objB[0x3A] = 3;
                frontDrawObj(0x32);
            }
            if (flagAny != 0) {
                objB[0x3A] = 1;
                frontDrawObj(0x32);
            }
            if (mainGetGameFlag(0x2C) != 0) {
                objB[0x3A] = 4;
                frontDrawObj(0x32);
            }
            break;
        }
    } else if (D_overlay_18_01206C7C < 3) {
        D_overlay_18_01206C7C += 1;
    }

    switch (D_overlay_18_01206C64) {
    case 1:
        D_overlay_18_01206C68 += arg0 * 0x10;
        D_overlay_18_01206C7C = 0;
        if (D_overlay_18_01206C68 >= 0xFF) {
            D_overlay_18_01206C68 = 0xFF;
            D_overlay_18_01206C64 = 0;
        }
        break;
    case 2:
        D_overlay_18_01206C68 -= arg0 * 0x10;
        if (D_overlay_18_01206C7C == 2) {
            D_overlay_18_01206C68 = 0;
            D_overlay_18_01206C60 ^= 1;
            D_overlay_18_01206C78 = 1;
            D_overlay_18_01206C64 = 1;
        }
        D_overlay_18_01206C6C = 0;
        break;
    default:
        D_overlay_18_01206C6C += arg0;
        if (D_overlay_18_01206C6C & 0x20) {
            camStandardOrtho(&frontgfx, &frontmtx);
            texDPTextureX(&frontgfx, 0, 0, 0);
            texAddr = (u32)((u8 *)D_overlay_18_012069F0 + (D_overlay_18_01206C60 * 0x1E)) + 0x80000000U;
            gfxp = frontgfx;
            frontgfx = gfxp + 1;
            gfxp->words.w0 = (((texAddr & 6) | 0x18) & 0xFF) << 16 | 0x04000026;
            gfxp->words.w1 = texAddr;
            gfxp = frontgfx;
            frontgfx = gfxp + 1;
            gfxp->words.w1 = (u32)D_81206A30;
            gfxp->words.w0 = 0x05000010;
            gfxp = frontgfx;
            frontgfx = gfxp + 1;
            gfxp->words.w1 = 0;
            gfxp->words.w0 = 0xE7000000;
        }
        if (joyGetPressed(pausePlayer) & 0x4000) {
            pauseSetScreen(1);
            D_overlay_18_01206C84 = 1;
        } else if (D_overlay_18_01206C60 == 0) {
            if (frontJoyDx[pausePlayer] >= 0x21 && D_overlay_18_01206C84 == 0) {
                amSndPlay(0x16B, NULL);
                D_overlay_18_01206C64 = 2;
            }
        } else if (D_overlay_18_01206C60 == 1) {
            if (frontJoyDx[pausePlayer] < -0x20 && D_overlay_18_01206C84 == 0) {
                amSndPlay(0x16B, NULL);
                D_overlay_18_01206C64 = 2;
            }
        }
        break;
    }
    objtrans = 0xFF;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o18/overlay_18/inventoryScreen.s")
#endif
