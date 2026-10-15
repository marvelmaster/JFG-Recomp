#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
s32 cloneTasksQueueAndWait(void);
s32 frontGet2PlayerSplit(void);
extern u8 D_800A3540_A4140[];
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void prnBorder(Gfx **arg0) {
    Gfx *dl;
    Gfx *p;
    s32 cams;
    s32 mode;
    s32 w;
    s32 h;
    s32 halfW;
    s32 halfH;
    s32 doTop;
    s32 doBottom;

    if (cloneTasksQueueAndWait() == 0) {
        return;
    }

    cams = mainGetNumberOfCameras();
    mode = viGetVideoMode();
    if (cams < 2) {
        return;
    }

    dl = *arg0;
    viGetCurrentSize(&w, &h);
    halfW = (u32) w >> 1;
    halfH = (u32) h >> 1;

    dl->words.w0 = 0x06000000;
    dl->words.w1 = (u32) D_800A3540_A4140;
    p = dl + 1;

    /* top border: only for 3+ cameras, or 2 cameras in the unsplit (even) mode */
    if (cams >= 3) {
        doTop = 1;
    } else if (mode & 1) {
        doTop = 0;
    } else {
        doTop = (frontGet2PlayerSplit() == 0);
    }

    if (doTop) {
        p[0].words.w0 = 0xFA000000;
        p[0].words.w1 = 0;
        p[1].words.w0 = (((w & 0x3FF) << 0xE) | 0xF6000000 | (((halfH + 2) & 0x3FF) * 4));
        p[1].words.w1 = ((halfH - 2) & 0x3FF) * 4;
        p[2].words.w0 = 0xE7000000;
        p[2].words.w1 = 0;
        p[3].words.w0 = 0xFA000000;
        p[3].words.w1 = 0xFF;
        p[4].words.w0 = (((w & 0x3FF) << 0xE) | 0xF6000000 | (((halfH + 1) & 0x3FF) * 4));
        p[4].words.w1 = ((halfH - 1) & 0x3FF) * 4;
        p[5].words.w0 = 0xE7000000;
        p[5].words.w1 = 0;
        p += 6;
    }

    /* bottom border: 3+ cameras, 2 cameras in odd mode, or 2 cameras split */
    if (cams >= 3) {
        doBottom = 1;
    } else if (mode & 1) {
        doBottom = 1;
    } else {
        doBottom = (frontGet2PlayerSplit() != 0);
    }

    if (doBottom) {
        p[0].words.w0 = 0xFA000000;
        p[0].words.w1 = 0;
        p[1].words.w0 = ((((halfW + 2) & 0x3FF) << 0xE) | 0xF6000000 | ((h & 0x3FF) * 4));
        p[1].words.w1 = ((halfW - 2) & 0x3FF) << 0xE;
        p[2].words.w0 = 0xE7000000;
        p[2].words.w1 = 0;
        p[3].words.w0 = 0xFA000000;
        p[3].words.w1 = 0xFF;
        p[4].words.w0 = ((((halfW + 1) & 0x3FF) << 0xE) | 0xF6000000 | ((h & 0x3FF) * 4));
        p[4].words.w1 = ((halfW - 1) & 0x3FF) << 0xE;
        p[5].words.w0 = 0xE7000000;
        p[5].words.w1 = 0;
        p += 6;
    }

    *arg0 = p;
    texDPInit(arg0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/prnBorder/prnBorder.s")
#endif
