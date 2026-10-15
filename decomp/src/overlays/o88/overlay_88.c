#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
extern f32 D_overlay_88_058002F0;
extern f32 D_overlay_88_058002F4;
extern f32 D_overlay_88_058002F8;
extern f32 D_overlay_88_058002FC;
extern f32 D_overlay_88_05800300;
void *camGetPtr(void);
f32 alCents2Ratio(s32 cents);
void amSndPlayXYZ(u16 soundId, f32 x, f32 y, f32 z, u8 arg4, void *soundMask);
void amSndStopXYZ(void *soundMask);
void amSndSetPitchXYZ(void *soundMask, s32 pitch);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void dopplerPointInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *state = *(u8 **)(obj + 0x68);

    *(s16 *)(state + 0x0) = *(s16 *)((u8 *)arg1 + 0xA);
    *(f32 *)(state + 0x8) = 1.0f;
    *(f32 *)(state + 0x4) = 0.0f;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o88/overlay_88/dopplerPointInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void dopplerPointControl(void *arg0, s32 arg1) {
    u8 *state = *(u8 **)((u8 *)arg0 + 0x68);
    u8 *cam = (u8 *)camGetPtr();
    f32 dx = *(f32 *)((u8 *)arg0 + 0xC) - *(f32 *)(cam + 0xC);
    f32 dy = *(f32 *)((u8 *)arg0 + 0x10) - *(f32 *)(cam + 0x10);
    f32 dz = *(f32 *)((u8 *)arg0 + 0x14) - *(f32 *)(cam + 0x14);
    f32 distSq = dx * dx + dy * dy + dz * dz;
    f32 dist;
    f32 v;
    f32 cur;
    s32 pitch;

    if (D_overlay_88_058002F0 < distSq) {
        if (*(void **)(state + 0xC) != NULL) {
            amSndStopXYZ(*(void **)(state + 0xC));
        }
    } else {
        if (*(s32 *)(state + 0xC) == 0) {
            amSndPlayXYZ(*(u16 *)(state + 0x0), *(f32 *)((u8 *)arg0 + 0xC), *(f32 *)((u8 *)arg0 + 0x10),
                         *(f32 *)((u8 *)arg0 + 0x14), 1, state + 0xC);
        }

        dist = sqrtf(distSq);
        v = ((*(f32 *)(state + 0x4) - dist) / (f32)arg1) * 3.0f;
        if (v > 15.0f) {
            v = 15.0f;
        } else if (v < -15.0f) {
            v = -15.0f;
        }

        *(f32 *)(state + 0x8) = *(f32 *)(state + 0x8)
            + ((alCents2Ratio((s32)(((70.0f + v) / (70.0f - v)) * D_overlay_88_058002F4))
                - D_overlay_88_058002FC) - *(f32 *)(state + 0x8)) * 0.5f;

        cur = *(f32 *)(state + 0x8);
        if (D_overlay_88_058002F8 < cur) {
            *(f32 *)(state + 0x8) = D_overlay_88_058002F8;
        } else if (cur < D_overlay_88_05800300) {
            *(f32 *)(state + 0x8) = D_overlay_88_05800300;
        }

        *(f32 *)(state + 0x4) = dist;

        /* float -> int truncation; negative results become -1 (0xFF after the u8 mask) */
        pitch = (s32)((*(f32 *)(state + 0x8) + 1.0f) * 100.0f);
        if (pitch < 0) {
            pitch = -1;
        }
        amSndSetPitchXYZ(*(void **)(state + 0xC), pitch & 0xFF);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o88/overlay_88/dopplerPointControl.s")
#endif
