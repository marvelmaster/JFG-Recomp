#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
typedef struct FxRect {
    /* 0x0 */ s8 flagX0;   /* nonzero: add arg4 to x0 */
    /* 0x1 */ s8 x0;
    /* 0x2 */ s8 flagY0;   /* nonzero: add arg5 to y0 */
    /* 0x3 */ s8 y0;
    /* 0x4 */ s8 flagX1;   /* nonzero: add arg4 to x1 */
    /* 0x5 */ s8 x1;
    /* 0x6 */ s8 flagY1;   /* nonzero: add arg5 to y1 */
    /* 0x7 */ s8 y1;
    /* 0x8 */ u8 alpha;    /* scaled by arg6 */
} FxRect; /* Size: 0x9 bytes */

typedef struct FxVtx {
    /* 0x0 */ s16 unk0;
    /* 0x2 */ s16 unk2;
    /* 0x4 */ s16 unk4;
    /* 0x6 */ s16 unk6;
    /* 0x8 */ s32 unk8;    /* colour word */
} FxVtx; /* Size: 0xC bytes */

void frontDrawRectangles(s32, s32, FxVtx *, s32);
extern FxRect *D_overlay_157_09D00224[];
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fxDrawWindow(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    FxVtx verts[0x18];
    FxRect *rec;
    FxVtx *vtx;
    s32 count;
    s32 temp_lo;

    rec = D_overlay_157_09D00224[arg1 & 0xFF];
    vtx = verts;
    count = 0;
    if (rec->flagX0 >= 0) {
        do {
            vtx->unk0 = (s16) (rec->x0 + arg2);
            if (rec->flagX0 != 0) {
                vtx->unk0 = (s16) (vtx->unk0 + arg4);
            }
            vtx->unk2 = (s16) (rec->y0 + arg3);
            if (rec->flagY0 != 0) {
                vtx->unk2 = (s16) (vtx->unk2 + arg5);
            }
            vtx->unk4 = (s16) (rec->x1 + arg2);
            if (rec->flagX1 != 0) {
                vtx->unk4 = (s16) (vtx->unk4 + arg4);
            }
            vtx->unk6 = (s16) (rec->y1 + arg3);
            if (rec->flagY1 != 0) {
                vtx->unk6 = (s16) (vtx->unk6 + arg5);
            }
            count += 1;
            temp_lo = rec->alpha * (arg6 & 0xFF);
            rec += 1;
            vtx->unk8 = (s32) ((temp_lo >> 7) | (arg6 & ~0xFF));
            vtx += 1;
        } while ((rec->flagX0 >= 0) && (count != 0x18));
    }
    frontDrawRectangles(arg0, count, verts, 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o157/overlay_157/fxDrawWindow.s")
#endif
