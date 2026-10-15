#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern Gfx *frontgfx;
extern MatrixS *frontmtx;
extern u8 D_826000F0[];
extern u8 D_82600118[];
void camStandardOrtho(Gfx **arg0, MatrixS **arg1);
void texDPTextureX(Gfx **dlist, void *tex, s32 rtile, s32 tmem);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void pauseClearScreen(void) {
    camStandardOrtho(&frontgfx, &frontmtx);
    texDPInit(&frontgfx);
    texDPTextureX(&frontgfx, 0, 0, 0);

    frontgfx->words.w0 = 0xFA000000;
    frontgfx->words.w1 = -1;
    frontgfx++;
    frontgfx->words.w0 = 0xFB000000;
    frontgfx->words.w1 = 0xFF;
    frontgfx++;
    frontgfx->words.w0 = ((((u32) D_826000F0 & 6) | 0x20) & 0xFF) << 16 | 0x04000030;
    frontgfx->words.w1 = (u32) D_826000F0;
    frontgfx++;
    frontgfx->words.w0 = 0x05110020;
    frontgfx->words.w1 = (u32) D_82600118;
    frontgfx++;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o38/overlay_38/pauseClearScreen.s")
#endif
