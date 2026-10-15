#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
void *objGetPlayerNo(s32 playerNo);
void changeWeather(s32 x, s32 y, s32 z, s32 a, s32 b, s32 c);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void weatherInit(void *arg0, void *arg1) {
    f32 temp_f0;

    temp_f0 = (f32) *(s16 *)((u8 *)arg1 + 0xA);
    temp_f0 = temp_f0 * temp_f0;
    *(f32 *)((u8 *)arg0 + 0x88) = temp_f0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o134/overlay_134/weatherInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void weatherControl(void *arg0, s32 arg1) {
    void *player;
    void *cfg;
    f32 dx;
    f32 dz;
    f32 radius;

    player = objGetPlayerNo(0);
    if (player != NULL) {
        dx = *(f32 *)((u8 *)arg0 + 0xC) - *(f32 *)((u8 *)player + 0xC);
        dz = *(f32 *)((u8 *)arg0 + 0x14) - *(f32 *)((u8 *)player + 0x14);
        radius = *(f32 *)((u8 *)arg0 + 0x88);
        cfg = *(void **)((u8 *)arg0 + 0x3C);
        if (((dx * dx) + (dz * dz)) <= radius) {
            changeWeather(*(s16 *)((u8 *)cfg + 0xC) << 8,
                          *(s16 *)((u8 *)cfg + 0xE) << 8,
                          *(s16 *)((u8 *)cfg + 0x10) << 8,
                          *(u8 *)((u8 *)cfg + 0x12) * 0x101,
                          *(u8 *)((u8 *)cfg + 0x13) * 0x101,
                          *(s16 *)((u8 *)cfg + 0x14));
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o134/overlay_134/weatherControl.s")
#endif
