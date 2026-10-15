#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern u8 D_overlay_39_02700570[];
extern UnkLight *D_overlay_39_027007AC;
extern f32 D_overlay_39_027007B0;
extern s32 D_overlay_39_027007B4;
extern s32 D_overlay_39_027007B8;
extern s32 D_overlay_39_027007BC;
extern s32 D_overlay_39_027007C0;
extern s32 D_overlay_39_027007C4;
extern s32 D_overlay_39_027007C8;
extern s32 D_overlay_39_027007CC;
extern s32 D_overlay_39_027007D0;
extern s32 D_overlay_39_027007D4;

void killLight(s32 light);
void mantisLightingUpdate(s32 arg0);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mantisLightingInit(void) {
    u8 def[0x18];

    *(s8 *)(def + 0x00) = 0;
    *(s8 *)(def + 0x01) = 3;
    *(s8 *)(def + 0x02) = 0x41;
    *(s8 *)(def + 0x03) = -1;
    *(s16 *)(def + 0x04) = 0;
    *(s16 *)(def + 0x06) = 0;
    *(s16 *)(def + 0x08) = 0;
    *(s16 *)(def + 0x0A) = 0;
    *(s16 *)(def + 0x0C) = 0x64;
    *(s16 *)(def + 0x0E) = 0x64;
    *(s8 *)(def + 0x13) = 0;
    *(s16 *)(def + 0x14) = -1;
    *(s8 *)(def + 0x16) = 0;
    *(s8 *)(def + 0x17) = 0xC6;

    D_overlay_39_027007AC = (UnkLight *) addObjectLight(NULL, (ObjectHeader48 *) def);
    D_overlay_39_027007B4 = 0;
    D_overlay_39_027007B0 = 0.0f;
    mantisLightingUpdate(0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o39/overlay_39/mantisLightingInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mantisLightingFree(void) {
    if (D_overlay_39_027007AC != NULL) {
        killLight((s32) D_overlay_39_027007AC);
        D_overlay_39_027007AC = NULL;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o39/overlay_39/mantisLightingFree.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mantisLightingUpdate(s32 arg0) {
    u8 *base;
    u8 *v0;
    u8 *v1;
    f32 f0;
    f32 t;
    s32 r;
    s32 g;
    s32 b;
    s32 intensity;

    base = D_overlay_39_02700570;
    D_overlay_39_027007B0 = D_overlay_39_027007B0 + ((f32) arg0 / 60.0f);
    v1 = base + (D_overlay_39_027007B4 * 0x34);
    f0 = *(f32 *)(v1 + 0x30);
    if (f0 <= D_overlay_39_027007B0) {
        do {
            D_overlay_39_027007B0 = D_overlay_39_027007B0 - f0;
            D_overlay_39_027007B4 = D_overlay_39_027007B4 + 1;
            f0 = *(f32 *)(v1 + 0x64);
            v1 = v1 + 0x34;
            if (f0 == 0.0f) {
                D_overlay_39_027007B4 = 0;
                f0 = *(f32 *)(base + 0x30);
                v1 = base;
            }
        } while (f0 <= D_overlay_39_027007B0);
    }

    t = D_overlay_39_027007B0 / f0;
    v0 = v1 + 0x34;
    if (*(f32 *)(v1 + 0x64) == 0.0f) {
        v0 = base;
    }

    D_overlay_39_027007B8 = (s32) (*(f32 *)(v1 + 0x00) + ((*(f32 *)(v0 + 0x00) - *(f32 *)(v1 + 0x00)) * t));
    D_overlay_39_027007BC = (s32) (*(f32 *)(v1 + 0x04) + ((*(f32 *)(v0 + 0x04) - *(f32 *)(v1 + 0x04)) * t));
    D_overlay_39_027007C0 = (s32) (*(f32 *)(v1 + 0x08) + ((*(f32 *)(v0 + 0x08) - *(f32 *)(v1 + 0x08)) * t));
    D_overlay_39_027007C4 = (s32) (*(f32 *)(v1 + 0x0C) + ((*(f32 *)(v0 + 0x0C) - *(f32 *)(v1 + 0x0C)) * t));
    D_overlay_39_027007C8 = (s32) (*(f32 *)(v1 + 0x10) + ((*(f32 *)(v0 + 0x10) - *(f32 *)(v1 + 0x10)) * t));
    D_overlay_39_027007CC = (s32) (*(f32 *)(v1 + 0x14) + ((*(f32 *)(v0 + 0x14) - *(f32 *)(v1 + 0x14)) * t));
    D_overlay_39_027007D0 = (s32) (*(f32 *)(v1 + 0x18) + ((*(f32 *)(v0 + 0x18) - *(f32 *)(v1 + 0x18)) * t));
    D_overlay_39_027007D4 = (s32) (*(f32 *)(v1 + 0x1C) + ((*(f32 *)(v0 + 0x1C) - *(f32 *)(v1 + 0x1C)) * t));

    if (D_overlay_39_027007AC != NULL) {
        r = (s32) (*(f32 *)(v1 + 0x20) + ((*(f32 *)(v0 + 0x20) - *(f32 *)(v1 + 0x20)) * t));
        g = (s32) (*(f32 *)(v1 + 0x24) + ((*(f32 *)(v0 + 0x24) - *(f32 *)(v1 + 0x24)) * t));
        b = (s32) (*(f32 *)(v1 + 0x28) + ((*(f32 *)(v0 + 0x28) - *(f32 *)(v1 + 0x28)) * t));
        intensity = (s32) (*(f32 *)(v1 + 0x2C) + ((*(f32 *)(v0 + 0x2C) - *(f32 *)(v1 + 0x2C)) * t));
        changeLightColour(D_overlay_39_027007AC, (u8) r, (u8) g, (u8) b);
        changeLightIntensity(D_overlay_39_027007AC, (u8) intensity);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o39/overlay_39/mantisLightingUpdate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mantisLightingGetFog(s16 *arg0, s16 *arg1, s8 *arg2, s8 *arg3, s8 *arg4) {
    *arg0 = (s16) D_overlay_39_027007D0;
    *arg1 = (s16) D_overlay_39_027007D4;
    *arg2 = (s8) D_overlay_39_027007C4;
    *arg3 = (s8) D_overlay_39_027007C8;
    *arg4 = (s8) D_overlay_39_027007CC;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o39/overlay_39/mantisLightingGetFog.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mantisLightingGetTrackFade(s32 *arg0, s32 *arg1, s32 *arg2) {
    *arg0 = D_overlay_39_027007B8;
    *arg1 = D_overlay_39_027007BC;
    *arg2 = D_overlay_39_027007C0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o39/overlay_39/mantisLightingGetTrackFade.s")
#endif
