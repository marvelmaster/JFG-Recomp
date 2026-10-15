#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
void hitInitObjectHit(void *arg0, s16 arg1, s8 arg2, s8 arg3, s16 arg4, s16 arg5, s16 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, u16 arg11);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void buoyInit(void *arg0, s32 arg1, s32 arg2) {
    /* arg1 / arg2 are spilled to the stack by the asm but never read */
    hitInitObjectHit(arg0, -1, 1, 1, 0, 0, 0, 30.0f, 30.0f, -1.0f, 1.0f, 0x11);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o79/overlay_79/buoyInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void buoyControl(void *arg0, s32 arg1) {
    f32 *y = (f32 *)((u8 *)arg0 + 0x28);

    *y = *y + ((f32)arg1 * 8.0f);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o79/overlay_79/buoyControl.s")
#endif
