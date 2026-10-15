#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern s8 D_800FF1B1;
extern s8 D_800FF1B2;
extern s8 D_800FF1B3;
extern u8 D_overlay_63_03F00CA4[];
extern s32 D_overlay_63_03F00CB4;
extern s32 D_overlay_63_03F00CCC;
extern s32 D_overlay_63_03F00CE4;
extern s32 D_overlay_63_03F00CFC;
extern void *D_overlay_63_03F00D14;
extern u8 D_overlay_63_03F00E70[];
extern s32 D_overlay_63_03F00EC0;
extern s32 D_overlay_63_03F00EC4;
extern s32 D_overlay_63_03F00ECC;
extern s32 D_overlay_63_03F00ED0;
extern s32 D_overlay_63_03F00ED4;
extern s32 D_overlay_63_03F00EDC;
extern s32 D_overlay_63_03F00EE0;
extern s32 D_overlay_63_03F00EE8;
extern s32 D_overlay_63_03F00EEC;
extern s8 cooperativeGame;
extern void *frontendptrs[];
extern s8 multiPlayerGame;
extern u8 numberOfPlayers;
extern s8 playStatus;
extern s8 startscreenOption;
extern s32 D_overlay_63_03F00CA0;
extern s32 D_overlay_63_03F00ED8;
extern char D_overlay_63_03F00C60[];
extern void *D_800FF644;
extern void *D_800FF648;
extern u8 D_83F00D18[];
extern u8 D_83F00D78[];
extern s32 frontJoyPressed[4];
extern s8 frontJoyDx[4];
extern u8 disable;
extern s32 numberOfJoypads;
extern Gfx *frontgfx;
extern MatrixS *frontmtx;
extern Vtx *frontvtx;
void freeFrontEndList(s16 *arg0);
void objFreeObject(void *obj);
void loadFrontEndList(s16 *arg0);
void mainSetDefaultGame(Game *game);
void rcpSetBorderColour(s32 r, s32 g, s32 b);
void amTunePlay(s32 id);
void amTuneSetVolume(s32 vol);
f32 Sinf(s32 angle);
void amSndPlay(u16 soundID, void *handlePtr);
void amTuneSetFade(f32 fade, s32 volume);
void camStandardOrtho(Gfx **dlist, void *mtx);
void *camGetListPtr(void);
void camDo2DSprite(Gfx **dlist, MatrixS **mtx, Vtx **vtx, void *spr, void *tex, s32 arg5, s32 arg6);
void texDPTextureX(Gfx **dlist, void *tex, s32 rtile, s32 tmem);
void fontBackground(s32 red, s32 green, s32 blue, s32 alpha);
void fontUseFont(s32 font);
void fontColour(s32 red, s32 green, s32 blue, s32 alpha, s32 opacity);
void fontPrintXY(Gfx **displayList, s32 xpos, s32 ypos, char *text, s32 alignmentFlags);
void rcpTileWrite(Gfx **dlist, void *tex, s32 x, s32 y, s32 r, s32 g, s32 b, s32 a);
void rcpTileWriteX(Gfx **dlist, void *tex, f32 x, f32 y, f32 sx, f32 sy, s32 colour, s32 flags);
void mainFrontInit(s32 arg0, s32 arg1, s32 arg2);
void mainToggleDebug(s32 *arg0, s32 arg1); /* sig mismatch: main.c defines (void); asm passes ptr + flags */
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontInitStartScreen(void) {
    rcpSetBorderColour(0, 0, 0);
    joyResetMap();
    playStatus = 0;
    D_800FF1B1 = 0;
    D_800FF1B2 = 0;
    D_800FF1B3 = 0;
    D_overlay_63_03F00EC0 = 2;
    D_overlay_63_03F00D14 = D_overlay_63_03F00E70;
    D_overlay_63_03F00ECC = 0;
    D_overlay_63_03F00ED0 = 3;
    D_overlay_63_03F00EC4 = 0;
    startscreenOption = 0;
    D_overlay_63_03F00ED4 = 0xC000;
    D_overlay_63_03F00EDC = 0;
    D_overlay_63_03F00EE8 = 0;
    D_overlay_63_03F00EEC = 4;
    D_overlay_63_03F00EE0 = 0x168;
    loadFrontEndList((s16 *) D_overlay_63_03F00CA4);
    D_overlay_63_03F00CB4 = *(s32 *) ((u8 *) frontendptrs + 0x198);
    D_overlay_63_03F00CCC = *(s32 *) ((u8 *) frontendptrs + 0x1A0);
    D_overlay_63_03F00CE4 = *(s32 *) ((u8 *) frontendptrs + 0x1A4);
    D_overlay_63_03F00CFC = *(s32 *) ((u8 *) frontendptrs + 0x19C);
    amTunePlay(0xB);
    amTuneSetVolume(0x7F);
    multiPlayerGame = 0;
    cooperativeGame = 0;
    numberOfPlayers = 1;
    mainSetDefaultGame(mainGetGame());
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o63/overlay_63/frontInitStartScreen.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// cf. DKR (title/start screen menu logic) - names only, asm is authoritative
void frontStartScreen(s32 arg0) {
    u8 spr[0x30];   /* 2D sprite block at sp80: s16 @0x0,0x2,0x4; f32 @0x8,0xC,0x10,0x14,0x28 */
    s32 spBC;       /* viGetVideoMode() & 1 */
    s32 spB8;       /* sprite y base: 0xB0 or 0xAC */
    s32 var_s0;
    s32 var_a1;
    s32 *var_a0;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s1_4;
    s32 var_s1_5;
    s32 var_s2_2;
    s32 var_s0_3;
    s32 var_v1;
    s32 var_v1_2;
    s32 temp_v1_2;
    s32 temp_t7;
    s32 temp_v0;
    s32 temp_lo;
    s32 temp_lo_2;
    s32 temp_s1;
    s32 col;
    s32 opt;
    s32 v3;
    s8 *var_s2;
    s8 *var_v1_4;
    s8 dx;
    u8 *ent;

    mainGetGame();
    spBC = viGetVideoMode() & 1;
    if (spBC != 0) {
        spB8 = 0xB0;
    } else {
        spB8 = 0xAC;
    }

    var_s0 = 0;
    var_a1 = 0;
    if (disable == 0) {
        /* asm: loop runs once (counter 0, tested before decrement) */
        var_a0 = &frontJoyPressed[0];
        var_s1 = 0;
        do {
            temp_v1_2 = *var_a0;
            var_s0 |= temp_v1_2 & 0x9000;
            var_a1 |= temp_v1_2 & 0x4000;
            var_a0 -= 1;
        } while (var_s1-- != 0);
        mainToggleDebug(var_a0, var_a1);
    }

    switch (D_overlay_63_03F00ECC) {
    case 4:
        break;
    case 0:
        if (var_s0 != 0) {
            D_overlay_63_03F00EC4 = 1;
        }
        if (D_overlay_63_03F00EC4 != 0) {
            var_v1 = D_overlay_63_03F00ED8 + (arg0 * 8);
            D_overlay_63_03F00ED8 = var_v1;
            if (var_v1 >= 0x100) {
                var_v1 = 0xFF;
                D_overlay_63_03F00ED8 = 0xFF;
            }
            if (var_v1 >= 0xC0) {
                D_overlay_63_03F00EDC += arg0 * 0x10;
                D_overlay_63_03F00ED0 = 1;
                if (D_overlay_63_03F00EDC >= 0xFF) {
                    D_overlay_63_03F00EDC = 0xFF;
                    D_overlay_63_03F00ECC = 2;
                }
            }
        } else {
            var_v1_2 = D_overlay_63_03F00ED8 + arg0;
            D_overlay_63_03F00ED8 = var_v1_2;
            if (var_v1_2 >= 0x100) {
                var_v1_2 = 0xFF;
                D_overlay_63_03F00ED8 = 0xFF;
            }
            if (var_v1_2 >= 0xC0) {
                D_overlay_63_03F00EDC += arg0 * 2;
                D_overlay_63_03F00ED0 = 0;
                if (D_overlay_63_03F00EDC >= 0xFF) {
                    D_overlay_63_03F00EDC = 0xFF;
                    D_overlay_63_03F00ECC = 1;
                }
            }
        }
        break;
    case 1:
        D_overlay_63_03F00ED4 += arg0 << 0xA;
        temp_t7 = D_overlay_63_03F00EE0 - arg0;
        if (D_overlay_63_03F00EE0 != 0) {
            D_overlay_63_03F00EE0 = temp_t7;
            if (temp_t7 <= 0) {
                D_overlay_63_03F00EE0 = 0;
            }
        } else {
            temp_v0 = D_overlay_63_03F00EE8 + (D_overlay_63_03F00EEC * arg0);
            D_overlay_63_03F00EE8 = temp_v0;
            if (temp_v0 >= 0xFF) {
                D_overlay_63_03F00EE0 = 0x168;
                D_overlay_63_03F00EE8 = 0xFF;
                D_overlay_63_03F00EEC = -4;
            } else if (temp_v0 <= 0) {
                D_overlay_63_03F00EE0 = 0x168;
                D_overlay_63_03F00EE8 = 0;
                D_overlay_63_03F00EEC = 4;
            }
        }
        if (var_s0 != 0) {
            D_overlay_63_03F00ECC = 2;
            D_overlay_63_03F00ED0 = 1;
        }
        break;
    case 2:
        if (var_s0 != 0) {
            if (startscreenOption == 1) {
                /* asm: loop runs once (counter 0, tested before decrement) */
                var_s1_2 = 0;
                do {
                    if (frontJoyPressed[var_s1_2] & 0x9000) {
                        *(&playStatus + var_s1_2) = 1;
                    }
                } while (var_s1_2-- != 0);
                D_overlay_63_03F00ECC = 3;
            } else if (D_overlay_63_03F00EC0 == startscreenOption) {
                mainChangeLevel(0, 0, 0, 4, 1, 0);
                amTuneSetFade(1.0f, 0);
                D_overlay_63_03F00ECC = 4;
            } else {
                multiPlayerGame = 0;
                numberOfPlayers = 1;
                numberOfCameras = 1;
                mainFrontInit(0x18, 0, 0);
                D_overlay_63_03F00ECC = 4;
            }
            amSndPlay(0x16D, 0);
        } else if (disable == 0) {
            /* joystick up/down: loop runs once (counter 0, tested before decrement) */
            opt = startscreenOption;
            var_s2 = &frontJoyDx[0];
            var_s1_4 = 0;
            v3 = opt;
            do {
                dx = *var_s2;
                if (dx > 0) {
                    if (v3 < D_overlay_63_03F00EC0) {
                        startscreenOption = opt + 1;
                        amSndPlay(0x16B, 0);
                    } else {
                        amSndPlay(0x16E, 0);
                    }
                    opt = startscreenOption;
                    v3 = opt;
                    if (opt == 1 && numberOfJoypads < 2) {
                        opt = 2;
                        v3 = 2;
                        startscreenOption = 2;
                    }
                } else if (dx < 0) {
                    if (v3 > 0) {
                        startscreenOption = opt - 1;
                        amSndPlay(0x16B, 0);
                    } else {
                        amSndPlay(0x16E, 0);
                    }
                    opt = startscreenOption;
                    v3 = opt;
                }
                var_s2 -= 1;
            } while (var_s1_4-- != 0);
            if (v3 == 1 && numberOfJoypads < 2) {
                startscreenOption = 0;
            }
        }
        break;
    case 3:
        D_overlay_63_03F00ED8 = 0;
        numberOfPlayers = 0;
        /* asm: 4 iterations (counter 3..0), byte read before pointer step */
        var_v1_4 = (s8 *)&D_800FF1B3;
        var_s1_4 = 3;
        do {
            if (*var_v1_4 == 1) {
                numberOfPlayers += 1;
            }
            var_v1_4 -= 1;
        } while (var_s1_4-- != 0);
        multiPlayerGame = 1;
        cooperativeGame = 0;
        numberOfCameras = 1;
        mainChangeLevel(0xA1, 0, 0, 6, 1, 0);
        D_overlay_63_03F00ECC = 4;
        break;
    }

    camStandardOrtho(&frontgfx, &frontmtx);
    texDPTextureX(&frontgfx, D_800FF644, 4, 0);
    frontgfx->words.w0 = 0xEF082C0F;
    frontgfx->words.w1 = 0x504340;
    frontgfx++;
    frontgfx->words.w1 = -1U;
    frontgfx->words.w0 = 0xFA000000;
    frontgfx++;
    frontgfx->words.w0 = (((((s32) D_83F00D18 & 6) | 0x48) & 0xFF) << 0x10) | 0x04000000 | 0x62;
    frontgfx->words.w1 = (u32) D_83F00D18;
    frontgfx++;
    frontgfx->words.w1 = (u32) D_83F00D78;
    frontgfx->words.w0 = 0x05710080;
    frontgfx++;
    texDPInit(&frontgfx);
    fontBackground(0, 0, 0, 0);
    fontUseFont(2);

    switch (D_overlay_63_03F00ED0) {
    case 3:
        break;
    case 0:
        if (D_overlay_63_03F00EE8 != 0xFF) {
            if (spBC == 0) {
                sprSetTextureFilter(0);
            }
            *(s16 *)&spr[0x0] = 0;
            *(s16 *)&spr[0x2] = 0;
            temp_lo = ((0xFF - D_overlay_63_03F00EE8) * D_overlay_63_03F00EDC) / 255;
            *(s16 *)&spr[0x4] = -*(s16 *)((u8 *)camGetListPtr() + 0x4);
            *(f32 *)&spr[0x10] = (f32) (0x64 - spB8);
            *(f32 *)&spr[0xC] = -4.0f;
            *(f32 *)&spr[0x14] = 1.0f;
            *(f32 *)&spr[0x8] = 1.0f;
            *(f32 *)&spr[0x28] = 0.0f;
            frontgfx->words.w0 = 0xE7000000;
            frontgfx->words.w1 = 0;
            frontgfx++;
            frontgfx->words.w0 = 0xFA000000;
            frontgfx->words.w1 = (temp_lo & 0xFF) | ~0xFF;
            frontgfx++;
            camDo2DSprite(&frontgfx, &frontmtx, &frontvtx, spr, D_800FF648, 0, temp_lo);
            frontgfx->words.w1 = 0;
            frontgfx->words.w0 = 0xE7000000;
            frontgfx++;
            frontgfx->words.w1 = -1U;
            frontgfx->words.w0 = 0xFA000000;
            frontgfx++;
            sprSetTextureFilter(1);
        }
        if (D_overlay_63_03F00EE8 != 0) {
            temp_lo_2 = (D_overlay_63_03F00EE8 * D_overlay_63_03F00EDC) / 255;
            if (spBC == 0) {
                rcpTileWrite(&frontgfx, &D_overlay_63_03F00CB4, 0xA0, spB8, 0xFF, 0xFF, 0xFF, temp_lo_2);
            } else {
                rcpTileWriteX(&frontgfx, &D_overlay_63_03F00CB4, 160.0f, (f32) spB8, 0.75f, 1.0f, temp_lo_2 | ~0xFF, 0);
            }
            fontColour(0xFF, 0x80, 0x80, 0xFF, (((s32) (Sinf(D_overlay_63_03F00ED4) * 127.0f) + 0x80) * temp_lo_2) / 255);
            fontPrintXY(&frontgfx, 0xA0, spB8 + 0x34, D_overlay_63_03F00C60, 0xC);
        }
        break;
    case 1:
        temp_s1 = D_overlay_63_03F00EC0 + 1;
        var_s1_5 = temp_s1 - 1;
        if (temp_s1 != 0) {
            var_s2_2 = var_s1_5 * 0xC;
            do {
                if (var_s1_5 == startscreenOption) {
                    var_s0_3 = 0xFF;
                } else if (var_s1_5 == 1) {
                    var_s0_3 = 0x80;
                    if (numberOfJoypads < 2) {
                        var_s0_3 = 0x40;
                    }
                } else {
                    var_s0_3 = 0x80;
                }
                ent = (u8 *) D_overlay_63_03F00D14 + var_s2_2;
                if (spBC == 0) {
                    col = var_s0_3 & 0xFF;
                    rcpTileWrite(&frontgfx, *(void **) (ent + 4), *(s16 *) (ent + 0), *(s16 *) (ent + 2), col, col, col, D_overlay_63_03F00EDC);
                } else {
                    rcpTileWriteX(&frontgfx, *(void **) (ent + 4), (f32) *(s16 *) (ent + 0), (f32) *(s16 *) (ent + 2), 0.75f, 1.0f, (var_s0_3 << 0x18) | (var_s0_3 << 0x10) | (var_s0_3 << 8) | D_overlay_63_03F00EDC, 0);
                }
                fontColour(var_s0_3, var_s0_3, 0xFF, 0xFF, D_overlay_63_03F00EDC);
                fontPrintXY(&frontgfx, *(s16 *) (ent + 0), *(s16 *) (ent + 2) + 0x34, *(char **) (ent + 8), 0xC);
                var_s2_2 -= 0xC;
            } while (var_s1_5-- != 0);
        }
        break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o63/overlay_63/frontStartScreen.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontCleanupStartScreen(void) {
    freeFrontEndList((s16 *) D_overlay_63_03F00CA4);
    if (D_overlay_63_03F00CA0 != 0) {
        objFreeObject((void *) D_overlay_63_03F00CA0);
        D_overlay_63_03F00CA0 = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o63/overlay_63/frontCleanupStartScreen.s")
#endif
