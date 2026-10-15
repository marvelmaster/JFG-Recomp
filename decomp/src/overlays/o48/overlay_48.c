#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern void *D_overlay_48_03000750[2];   /* blur buffer slots (mmAlloc'd) */
extern s32 D_overlay_48_03000758;        /* buffer index, flipped each task */
extern Gfx *D_overlay_48_03000760;       /* current blur dl start (NULL = none) */
extern Gfx *D_overlay_48_03000764;       /* current blur dl end */
extern s32 D_overlay_48_03000768;        /* extraScreen arg for rcpFast3d */
extern u8 D_overlay_48_0300075C;         /* blur colour/alpha byte */
extern s32 blurOn;
extern s32 blurTaskActive;
extern s32 extraScreen;
extern s32 currentScreen;
extern s32 otherZbuf;
s32 viGetTrippleBuffer(void);
void viGetCurrentSize(s32 *arg0, s32 *arg1);
void segSetBase(Gfx **dlist, s32 segment, s32 base);
void rcpInitSp(Gfx **dl);
void rcpInitDpNoSize(Gfx **dl);
void camSetNo(s32 arg0);
void camSetView(Gfx **dl, s32 arg1);
void rcpFast3d(Gfx *dl0, Gfx *dl, s32 arg2, s32 arg3);
void blurFree(void);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void blurInit(void) {
    blurFree();
    D_overlay_48_03000750[0] = mmAlloc(0x2000, -1U);
    D_overlay_48_03000750[1] = mmAlloc(0x2000, -1U);
    D_overlay_48_03000758 = 0;
    blurOn = 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o48/overlay_48/blurInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void blurFree(void) {
    if (D_overlay_48_03000750[0] != NULL) {
        mmFree(D_overlay_48_03000750[0]);
    }
    if (D_overlay_48_03000750[1] != NULL) {
        mmFree(D_overlay_48_03000750[1]);
    }
    D_overlay_48_03000750[0] = NULL;
    D_overlay_48_03000750[1] = NULL;
    D_overlay_48_03000760 = NULL;
    D_overlay_48_03000764 = NULL;
    blurOn = 0;
    blurTaskActive = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o48/overlay_48/blurFree.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void _AutoExit00048(void) {
    blurFree();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o48/overlay_48/_AutoExit00048.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void blurUpdate(s32 arg0) {
    Gfx *dl;
    s32 width;
    s32 height;
    s32 y;
    s32 rows;
    s32 nextY;
    s32 src;
    u32 n;
    s32 lastLine;
    s32 dxt;
    s32 tex;

    D_overlay_48_03000760 = NULL;
    if (viGetTrippleBuffer() != 0) {
        dl = (Gfx *) D_overlay_48_03000750[D_overlay_48_03000758];
        viGetCurrentSize(&width, &height);
        D_overlay_48_03000760 = dl;
        D_overlay_48_03000768 = extraScreen;
        segSetBase(&dl, 0, 0);
        segSetBase(&dl, 1, extraScreen);
        segSetBase(&dl, 2, otherZbuf);
        rcpInitSp(&dl);
        rcpInitDpNoSize(&dl);

        dl->words.w0 = 0xB6000000;
        dl->words.w1 = 0x10001;
        dl++;
        dl->words.w0 = ((width - 1) & 0xFFF) | 0xFF100000;
        dl->words.w1 = extraScreen + 0x80000000;
        dl++;
        dl->words.w0 = 0xED000000;
        dl->words.w1 = ((((s32) ((f32) (u32) width * 4.0f)) & 0xFFF) << 0xC)
                     | ((s32) ((f32) (u32) height * 4.0f) & 0xFFF);
        dl++;
        dl->words.w0 = 0xBC000002;
        dl->words.w1 = 0;
        dl++;
        dl->words.w1 = 0;
        dl->words.w0 = 0xE7000000;
        dl++;
        dl->words.w1 = 0x1000;
        dl->words.w0 = 0xB6000000;
        dl++;
        dl->words.w0 = 0xF9000000;
        dl->words.w1 = 0x64;
        dl++;
        dl->words.w0 = 0xFA000000;
        dl->words.w1 = -1U;
        dl++;
        dl->words.w0 = 0xFB000000;
        dl->words.w1 = D_overlay_48_0300075C | ~0xFF;
        dl++;
        camSetNo(0);
        camSetView(&dl, 0);
        dl->words.w1 = 0;
        dl->words.w0 = 0xE7000000;
        dl++;
        dl->words.w1 = 0x10001;
        dl->words.w0 = 0xB6000000;
        dl++;
        dl->words.w1 = 0x204;
        dl->words.w0 = 0xB7000000;
        dl++;
        dl->words.w0 = 0xFCFFFFFF;
        dl->words.w1 = 0xFFFCF67D;
        dl++;
        dl->words.w1 = 0x504240;
        dl->words.w0 = 0xEF000CCF;
        dl++;

        /* strip the screen in 4-line chunks (rows clamped to 4) */
        src = currentScreen;
        y = 0;
        if (height != 0) {
            do {
                rows = height - y;
                if (rows >= 5) {
                    rows = 4;
                }
                dl->words.w1 = (u32) src;
                dl->words.w0 = 0xFD100000;
                dl++;
                dl->words.w1 = 0x07080200;
                dl->words.w0 = 0xF5100000;
                dl++;
                dl->words.w1 = 0;
                dl->words.w0 = 0xE6000000;
                dl++;

                n = (u32) (width * 2) >> 3;
                if (n == 0) {
                    n = 1;
                }
                tex = (rows * width) - 1;
                if ((u32) tex < 0x7FFU) {
                    dxt = tex;
                } else {
                    dxt = 0x7FF;
                }
                dl->words.w0 = 0xF3000000;
                dl->words.w1 = ((((u32) (n + 0x7FF)) / n) & 0xFFF) | 0x07000000 | ((dxt & 0xFFF) << 0xC);
                dl++;
                dl->words.w1 = 0;
                dl->words.w0 = 0xE7000000;
                dl++;
                dl->words.w0 = ((((u32) ((width * 2) + 7) >> 3) & 0x1FF) << 9) | 0xF5100000;
                dl->words.w1 = 0x80200;
                dl++;
                dl->words.w0 = 0xF2000000;
                dl->words.w1 = ((((width - 1) * 4) & 0xFFF) << 0xC) | (((rows - 1) * 4) & 0xFFF);
                dl++;

                nextY = y + rows;
                dl->words.w1 = (y * 4) & 0xFFF;
                dl->words.w0 = (((width * 4) & 0xFFF) << 0xC) | 0xE4000000 | ((nextY * 4) & 0xFFF);
                dl++;
                dl->words.w1 = 0;
                dl->words.w0 = 0xB3000000;
                dl++;
                dl->words.w1 = 0x04000400;
                dl->words.w0 = 0xB2000000;
                dl++;

                y = nextY;
                src += width * rows * 2;
            } while (nextY < height);
        }
        dl->words.w1 = 0;
        dl->words.w0 = 0xE9000000;
        dl++;
        dl->words.w1 = 0;
        dl->words.w0 = 0xB8000000;
        dl++;
        D_overlay_48_03000764 = dl;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o48/overlay_48/blurUpdate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void blurTask(void) {
    if (D_overlay_48_03000760 != NULL) {
        rcpFast3d(D_overlay_48_03000760, D_overlay_48_03000764, 5, D_overlay_48_03000768);
        blurTaskActive = 1;
        D_overlay_48_03000758 ^= 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o48/overlay_48/blurTask.s")
#endif
