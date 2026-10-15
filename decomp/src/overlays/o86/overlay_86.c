#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
extern s32 __MODULE00086;
s16 objTvTimes(s32 timer);
void *trackLightAdd(f32 x, f32 y, f32 z, f32 r, f32 g, s32 b, s32 a, s32 c);
void hitInitObjectHit(void *arg0, s16 arg1, s8 arg2, s8 arg3, s16 arg4, s16 arg5, s16 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, u16 arg11);
void runlinkSetDestructTimer(s32 module, s32 a, s32 b);
void amSndPlayXYZ(u16 soundId, f32 x, f32 y, f32 z, u8 arg4, void *soundMask);
void explosionStart(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5);
void squadsAddInterestingEvent(void *arg0, s16 x, s16 y, s16 z, s32 a, s32 b, s32 c);
void *objSetupObject(void *params, s32 arg1);
void objMoveXYZ(void *obj, f32 x, f32 y, f32 z);
void objFreeObject(void *obj);
void partUpdateTriggers(void *obj, s32 arg1);
void trackLightMove(void *light, f32 x, f32 y, f32 z);
void trackLightDelete(void *light);
u8 trackNearestIntersection(void *from, void *to, void *a2, void *out, s32 mask, s32 c);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void CyborgMissileInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *params = (u8 *)arg1;
    u8 *state = *(u8 **)(obj + 0x68);

    *(f32 *)(obj + 0x1C) = (f32)*(s16 *)(params + 0xC);
    *(f32 *)(obj + 0x20) = (f32)*(s16 *)(params + 0xE);
    *(f32 *)(obj + 0x24) = (f32)*(s16 *)(params + 0x10);
    *(s16 *)(obj + 0x0) = (s16)mathRnd(-0x8000, 0x7FFF);
    *(s16 *)(obj + 0x2) = (s16)mathRnd(-0x8000, 0x7FFF);
    *(s16 *)(obj + 0x4) = 0;
    *(u8 *)(state + 0x16) = 0;
    *(s32 *)(state + 0xC) = 0;
    *(f32 *)(state + 0x0) = *(f32 *)(obj + 0xC);
    *(f32 *)(state + 0x4) = *(f32 *)(obj + 0x10);
    *(f32 *)(state + 0x8) = *(f32 *)(obj + 0x14);
    *(s16 *)(state + 0x14) = objTvTimes(params[0xB] * 6);
    *(s32 *)(state + 0x10) = *(s32 *)(params + 0x14);
    hitInitObjectHit(obj, (s16)((params[0xA] + 1) << 8), 1, 4, 0, 0, 0, 2.0f, 2.0f, -1.0f, 1.0f, 0x11);
    *(s32 *)(obj + 0x88) = *(s16 *)(*(u8 **)(obj + 0x4C) + 0x6);
    *(void **)(obj + 0x8C) = trackLightAdd(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14),
                                           500.0f, 300.0f, 0xFF, 0xE0, 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o86/overlay_86/CyborgMissileInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void CyborgMissileControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *state = *(u8 **)(obj + 0x68);
    u8 hit[0x28];
    u8 setup[0x10];
    u8 hitResult;
    void *spawned;
    s16 tgt;

    runlinkSetDestructTimer(__MODULE00086, 2, 2);
    *(s16 *)(state + 0x14) = (s16)(*(s16 *)(state + 0x14) - arg1);

    if (*(s16 *)(state + 0x14) > 0 &&
        (tgt = *(s16 *)(*(u8 **)(obj + 0x4C) + 0x6)) > 0 &&
        *(u8 *)(state + 0x16) == 0 &&
        *(s32 *)(obj + 0x88) == tgt) {
        objMoveXYZ(obj, *(f32 *)(obj + 0x1C), *(f32 *)(obj + 0x20), *(f32 *)(obj + 0x24));
        hitResult = trackNearestIntersection(obj, *(u8 **)(obj + 0x4C) + 0x18, obj + 0xC, hit, 0, 0);
        *(u8 *)(state + 0x16) = hitResult;

        if (hitResult & 0xFF) {
            *(f32 *)(state + 0x0) = *(f32 *)(hit + 0x4);
            *(f32 *)(state + 0x4) = *(f32 *)(hit + 0x8);
            *(f32 *)(state + 0x8) = *(f32 *)(hit + 0xC);
            *(s32 *)(state + 0xC) = *(s32 *)(hit + 0x24);
            objMoveXYZ(obj,
                       *(f32 *)(state + 0x0) - *(f32 *)(obj + 0xC),
                       *(f32 *)(state + 0x4) - *(f32 *)(obj + 0x10),
                       *(f32 *)(state + 0x8) - *(f32 *)(obj + 0x14));
            if (*(u8 *)(state + 0x16) == 1 &&
                (s16)Arctanf(*(f32 *)(hit + 0x14),
                             sqrtf(*(f32 *)(hit + 0x18) * *(f32 *)(hit + 0x18) +
                                   *(f32 *)(hit + 0x10) * *(f32 *)(hit + 0x10))) < 0x2000) {
                *(u8 *)(state + 0x16) = 2;
            }
        }
        if (*(void **)(obj + 0x8C) != NULL) {
            trackLightMove(*(void **)(obj + 0x8C), *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14));
        }
    } else {
        s32 flags = *(s32 *)(state + 0xC);

        if ((flags & 0x2000) && !(flags & 0x8000)) {
            amSndPlayXYZ(0xD, *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14), 4, NULL);
            *(s16 *)(setup + 0x0) = 0xC0;
            *(u8 *)(setup + 0x2) = 0x10;
            *(s16 *)(setup + 0x4) = (s16)(s32)*(f32 *)(state + 0x0);
            *(s16 *)(setup + 0x6) = (s16)(s32)*(f32 *)(state + 0x4);
            *(s16 *)(setup + 0x8) = (s16)(s32)*(f32 *)(state + 0x8);
            *(s16 *)(setup + 0xA) = 0x100;
            *(f32 *)(setup + 0xC) = 20.0f;
            spawned = objSetupObject(setup, 1);
            if (spawned != NULL) {
                *(s32 *)((u8 *)spawned + 0x3C) = 0;
            }
        } else {
            amSndPlayXYZ(0x96, *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14), 4, NULL);
            explosionStart(2, (s16)(s32)*(f32 *)(obj + 0xC), (s16)(s32)*(f32 *)(obj + 0x10),
                           (s16)(s32)*(f32 *)(obj + 0x14), 0x64, 0);
            squadsAddInterestingEvent(NULL, (s16)(s32)*(f32 *)(obj + 0xC), (s16)(s32)*(f32 *)(obj + 0x10),
                                      (s16)(s32)*(f32 *)(obj + 0x14), 5, 1, 0x96);
        }
        if (*(void **)(obj + 0x8C) != NULL) {
            trackLightDelete(*(void **)(obj + 0x8C));
        }
        objFreeObject(obj);
        state = NULL;
    }

    if (state != NULL) {
        *(s32 *)(obj + 0x84) = 3;
        partUpdateTriggers(obj, arg1);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o86/overlay_86/CyborgMissileControl.s")
#endif
