#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern s8 clayPigeonAmmo;
extern s8 clayPigeonGrenades;
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void genericplayerInit(void *arg0, void *arg1) {
    s32 sp24;
    s32 sp20;
    u8 *params = (u8 *) arg1;
    u8 *dst;

    viGetCurrentSize(&sp24, &sp20);
    dst = *(u8 **) ((u8 *) arg0 + 0x68);
    dst[0x00] = params[0x10];
    *(s16 *) (dst + 0x02) = 0;
    *(s16 *) (dst + 0x04) = 0;
    *(s16 *) (dst + 0x06) = 0;
    *(s32 *) (dst + 0x08) = 0;
    dst[0x01] = params[0x11];
    *(s16 *) (dst + 0x0C) = clayPigeonAmmo;
    *(s16 *) (dst + 0x0E) = clayPigeonGrenades;
    *(f32 *) (dst + 0x10) = (f32) ((u32) sp24 >> 1);
    *(f32 *) (dst + 0x14) = (f32) ((u32) sp20 >> 1);
    *(f32 *) (dst + 0x18) = 0.0f;
    *(f32 *) (dst + 0x1C) = 0.0f;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o70/overlay_70/genericplayerInit.s")
#endif
