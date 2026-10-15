#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern Gfx *frontgfx;
extern void *D_overlay_57_039009A0;
extern void *D_overlay_57_039009A4;
extern TextureHeader *D_overlay_57_039009A8;
extern TextureHeader *D_overlay_57_039009AC;
extern TextureHeader *D_overlay_57_039009B0;
extern void *D_overlay_57_039009B4;
extern s32 D_overlay_57_039009B8;
extern s32 D_overlay_57_039009BC;
extern s32 D_overlay_57_039009C0;
extern s32 D_overlay_57_039009C4;
extern s32 D_overlay_57_039009C8;
extern s32 D_overlay_57_039009CC;
extern s32 D_overlay_57_039009D0;
extern s32 D_overlay_57_039009D4;
extern u8 D_overlay_57_039009D8[];
extern char D_overlay_57_03900A00[];
extern char D_overlay_57_03900A10[];
void mmFree(void *data);
void *screenLoad(s32 id);
void *fmvStart(s32 a, s32 b, s32 c, s32 d, s32 e);
void fmvStop(void *fmv);
void fmvUpdate(void *fmv, s32 arg);
void fmvDraw(void *fmv, Gfx **dl, s32 scale);
void screenDraw(Gfx **dl, void *screen, s32 arg);
void mainTitlePageInit(s32 *arg0, s32 arg1);
void amTunePlay(s32 id, s32 arg1);
void amTuneSetVolume(s32 vol);
void fontUseFont(s32 font);
void fontBackground(s32 r, s32 g, s32 b, s32 a);
void fontColour(s32 r, s32 g, s32 b, s32 a, s32 arg4);
void fontPrintXY(Gfx **dl, s32 x, s32 y, char *str, s32 arg4);
void texFreeTexture(TextureHeader *tex);
s32 frontRecallScreenMode(void);
void frontSetScreenMode(s32 mode);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontInitRarepage(void) {
    D_overlay_57_039009A0 = screenLoad(0);
    D_overlay_57_039009A4 = screenLoad(1);
    D_overlay_57_039009A8 = texLoadTexture(0x28E);
    D_overlay_57_039009AC = texLoadTexture(0x28F);
    D_overlay_57_039009B0 = texLoadTexture(0x290);
    D_overlay_57_039009B4 = fmvStart(0, 0x7C, 0x41, 0, 0);
    D_overlay_57_039009B8 = 1;
    D_overlay_57_039009BC = 0;
    D_overlay_57_039009C0 = 0;
    D_overlay_57_039009C4 = 0;
    D_overlay_57_039009C8 = 0;
    D_overlay_57_039009CC = 0;
    D_overlay_57_039009D0 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o57/overlay_57/frontInitRarepage.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
/* Each helper appends one or more RDP commands to frontgfx, as the asm does inline. */
static void rarepageWord(u32 w0, u32 w1) {
    Gfx *g = frontgfx;

    frontgfx = g + 1;
    g->words.w0 = w0;
    g->words.w1 = w1;
}

static void rarepageFadeCmd(s32 level) {
    s32 t = level & 0xFF;

    rarepageWord(0xFA000000, (t << 0x18) | (t << 0x10) | (t << 8) | 0xFF);
}

static void rarepageTexCmd(TextureHeader *tex) {
    s32 n = tex->numberOfCommands;

    rarepageWord(((n & 0xFF) << 0x10) | 0x07000000 | ((n * 8) & 0xFFFF), (u32) tex->cmd + 0x80000000);
}

void frontRarepage(s32 arg0) {
    s32 t;
    s32 v;

    switch (D_overlay_57_039009B8) {
    case 1:
        t = D_overlay_57_039009BC + (arg0 * 4);
        D_overlay_57_039009BC = t;
        if (t >= 0xFF) {
            amTunePlay(0x55, arg0);
            amTuneSetVolume(0x7F);
            D_overlay_57_039009BC = 0xFF;
            D_overlay_57_039009B8 = 2;
        }
        break;
    case 2:
        t = D_overlay_57_039009C0 + (arg0 * 4);
        D_overlay_57_039009C0 = t;
        if (t >= 0xFF) {
            D_overlay_57_039009C0 = 0xFF;
            D_overlay_57_039009D4 = 0x3C;
            D_overlay_57_039009B8 = 3;
        }
        break;
    case 3:
        if (D_overlay_57_039009D4 <= 0) {
            t = D_overlay_57_039009C4 - (arg0 * 8);
            D_overlay_57_039009C4 = t;
            if (t <= 0) {
                D_overlay_57_039009C4 = 0;
                D_overlay_57_039009D4 = 0x3C;
                D_overlay_57_039009B8 = 4;
            }
        } else if (D_overlay_57_039009C4 < 0xFF) {
            t = D_overlay_57_039009C4 + (arg0 * 8);
            D_overlay_57_039009C4 = t;
            if (t >= 0x100) {
                D_overlay_57_039009C4 = 0xFF;
            }
        } else {
            D_overlay_57_039009D4 -= arg0;
        }
        break;
    case 4:
        if (D_overlay_57_039009D4 <= 0) {
            v = arg0 * 8;
            D_overlay_57_039009BC -= v;
            D_overlay_57_039009C0 -= v;
            t = D_overlay_57_039009C8 - v;
            D_overlay_57_039009C8 = t;
            if (t <= 0) {
                D_overlay_57_039009BC = 0;
                D_overlay_57_039009C0 = 0;
                D_overlay_57_039009C8 = 0;
                D_overlay_57_039009D4 = 0x78;
                D_overlay_57_039009B8 = 5;
            }
        } else if (D_overlay_57_039009C8 < 0xFF) {
            t = D_overlay_57_039009C8 + (arg0 * 8);
            D_overlay_57_039009C8 = t;
            if (t >= 0x100) {
                D_overlay_57_039009C8 = 0xFF;
            }
        } else {
            D_overlay_57_039009D4 -= arg0;
        }
        break;
    case 5:
        if (D_overlay_57_039009D4 <= 0) {
            t = D_overlay_57_039009CC - (arg0 * 8);
            D_overlay_57_039009CC = t;
            if (t <= 0) {
                D_overlay_57_039009CC = 0;
                D_overlay_57_039009B8 = 6;
            }
        } else if (D_overlay_57_039009CC < 0xFF) {
            D_overlay_57_039009CC += arg0 * 8;
            if (D_overlay_57_039009CC >= 0x100) {
                D_overlay_57_039009CC = 0xFF;
            }
        } else {
            D_overlay_57_039009D4 -= arg0;
        }
        break;
    case 6:
        fmvUpdate(D_overlay_57_039009B4, arg0);
        t = *(s32 *) ((u8 *) D_overlay_57_039009B4 + 0x4);
        if (t < 0x200) {
            D_overlay_57_039009D0 = t >> 1;
        } else if (t >= 0x2301) {
            D_overlay_57_039009D0 = (0x2500 - t) >> 1;
        } else {
            D_overlay_57_039009D0 = 0xFF;
        }
        if (t >= 0x2500) {
            D_overlay_57_039009D0 = 0;
            D_overlay_57_039009B8 = 7;
            D_overlay_57_039009D4 = 0xB4;
        }
        break;
    case 7:
        t = D_overlay_57_039009D4 - arg0;
        D_overlay_57_039009D4 = t;
        if (t <= 0) {
            D_overlay_57_039009B8 = 0;
            mainTitlePageInit(&D_overlay_57_039009D4, arg0);
        }
        break;
    }

    if (D_overlay_57_039009BC != 0) {
        rarepageFadeCmd(D_overlay_57_039009BC);
        screenDraw(&frontgfx, D_overlay_57_039009A0, 0);
    }
    if (D_overlay_57_039009C4 != 0) {
        rarepageFadeCmd(D_overlay_57_039009C4);
        rarepageWord(0x06000000, (u32) D_overlay_57_039009D8);
        rarepageTexCmd(D_overlay_57_039009A8);
        rarepageWord(0xE43A0370, 0x160290);
        rarepageWord(0xB3000000, 0x700);
        rarepageWord(0xB2000000, 0x0400FC00);
        texDPInit(&frontgfx);
    }
    if (D_overlay_57_039009C8 != 0) {
        rarepageFadeCmd(D_overlay_57_039009C8);
        rarepageWord(0x06000000, (u32) D_overlay_57_039009D8);
        rarepageTexCmd(D_overlay_57_039009AC);
        rarepageWord(0xE4280380, 0x100280);
        rarepageWord(0xB3000000, 0x800);
        rarepageWord(0xB2000000, 0x0400FC00);
        rarepageTexCmd(D_overlay_57_039009B0);
        rarepageWord(0xE4400380, 0x280280);
        rarepageWord(0xB3000000, 0x800);
        rarepageWord(0xB2000000, 0x0400FC00);
        texDPInit(&frontgfx);
    }
    if (D_overlay_57_039009C0 != 0) {
        fontUseFont(2);
        fontBackground(0, 0, 0, 0);
        fontColour(0xFF, 0xFF, 0xFF, 0xFF, D_overlay_57_039009C0);
        fontPrintXY(&frontgfx, 0xA0, 0x88, D_overlay_57_03900A00, 0xC);
    }
    if (D_overlay_57_039009CC != 0) {
        rarepageFadeCmd(D_overlay_57_039009CC);
        screenDraw(&frontgfx, D_overlay_57_039009A4, 0);
    }
    if (D_overlay_57_039009D0 != 0) {
        *(s8 *) ((u8 *) D_overlay_57_039009B4 + 0x3) = (s8) D_overlay_57_039009D0;
        fmvDraw(D_overlay_57_039009B4, &frontgfx, 0x3F800000);
        fontUseFont(2);
        fontBackground(0, 0, 0, 0);
        fontColour(0xFF, 0xFF, 0xFF, 0xFF, D_overlay_57_039009D0);
        fontPrintXY(&frontgfx, 0xA0, 0xC0, D_overlay_57_03900A10, 0xC);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o57/overlay_57/frontRarepage.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontCleanupRarepage(void) {
    fmvStop(D_overlay_57_039009B4);
    texFreeTexture(D_overlay_57_039009B0);
    texFreeTexture(D_overlay_57_039009AC);
    texFreeTexture(D_overlay_57_039009A8);
    mmFree(D_overlay_57_039009A4);
    mmFree(D_overlay_57_039009A0);
    frontSetScreenMode(frontRecallScreenMode());
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o57/overlay_57/frontCleanupRarepage.s")
#endif
