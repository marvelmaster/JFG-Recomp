#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
void hitInitObjectHit(void *arg0, s16 arg1, s8 arg2, s8 arg3, s16 arg4, s16 arg5, s16 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, u16 arg11);
void mathOneFloatPY(void *arg0, void *arg1, void *arg2);
extern s32 __MODULE00097;
void runlinkSetDestructTimer(s32 module, s32 a, s32 b);
void objMoveXYZ(void *obj, f32 x, f32 y, f32 z);
void partUpdateTriggers(void *obj, s32 arg1);
s32 trackNearestIntersection(void *obj, f32 *from, void *to, void *out, s32 mask, s32 c);
void objFreeObject(void *obj);
void amSndPlayXYZ(u16 soundId, f32 x, f32 y, f32 z, u8 arg4, void *soundMask);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hitfragmentInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *params = (u8 *)arg1;
    u8 *state = *(u8 **)(obj + 0x68);

    *(f32 *)(obj + 0x24) = -*(f32 *)(params + 0x14);
    mathOneFloatPY(params + 0xA, obj + 0x1C, params);
    *(f32 *)(obj + 0x8) = **(f32 **)(obj + 0x40) * *(f32 *)(params + 0x10);
    *(f32 *)(state + 0x0) = *(f32 *)(params + 0x18);
    *(s16 *)(state + 0x4) = *(s16 *)(params + 0xE);
    state[0x6] = (u8)mathRnd(8, 0x10);
    state[0x7] = 0xFF;
    *(s8 *)(state + 0x8) = *(s8 *)(params + 0x1C);
    *(s32 *)(state + 0xC) = *(s32 *)(params + 0x20);
    if (*(s32 *)(obj + 0x4C) != 0) {
        hitInitObjectHit(obj, 0x100, 1, 4, 0, 0, 0, 200.0f, 200.0f, -1.0f, 1.0f, 0x11);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o97/overlay_97/hitfragmentInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hitfragmentControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *state;
    void *target;
    f32 start[3];
    u8 hit[0x30];   /* trackNearestIntersection result: vec at +4, flags at +0x24 */
    f32 speed;
    s32 lo;
    s32 var;
    s32 sndId;
    s32 flags;

    runlinkSetDestructTimer(__MODULE00097, 2, 2);
    state = *(u8 **) (obj + 0x68);
    *(s16 *) (state + 4) = *(s16 *) (state + 4) - arg1;
    lo = state[6] * arg1;
    *(s16 *) (obj + 0) = *(s16 *) (obj + 0) + (lo << 6);
    *(s16 *) (obj + 2) = *(s16 *) (obj + 2) + (lo << 7);
    *(s16 *) (obj + 4) = *(s16 *) (obj + 4) + (lo << 5);
    target = *(void **) (obj + 0x4C);
    if (target != NULL && *(s16 *) ((u8 *) target + 6) <= 0) {
        var = 3;
    } else {
        var = 0;
        if (*(s16 *) (state + 4) <= 0) {
            var = 4;
        }
    }
    if (var == 0) {
        speed = (f32) arg1;
        if (*(s16 *) (state + 4) < 0x10) {
            state[7] = (s8) (*(s16 *) (state + 4) * 0x10);
        }
        start[0] = *(f32 *) (obj + 0xC);
        start[1] = *(f32 *) (obj + 0x10);
        start[2] = *(f32 *) (obj + 0x14);
        objMoveXYZ(arg0, *(f32 *) (obj + 0x1C) * speed, *(f32 *) (obj + 0x20) * speed,
                   *(f32 *) (obj + 0x24) * speed);
        *(s32 *) (obj + 0x84) = 1;
        *(f32 *) (obj + 0x20) = *(f32 *) (obj + 0x20) - speed * *(f32 *) state;
        partUpdateTriggers(arg0, arg1);
        if (trackNearestIntersection(arg0, start, obj + 0xC, hit, 0, 0) != 0) {
            objMoveXYZ(arg0, *(f32 *) (hit + 4) - *(f32 *) (obj + 0xC),
                       *(f32 *) (hit + 8) - *(f32 *) (obj + 0x10),
                       *(f32 *) (hit + 0xC) - *(f32 *) (obj + 0x14));
            *(s16 *) (obj + 0) = 0;
            *(s16 *) (obj + 2) = *(s16 *) (obj + 0);
            *(s16 *) (obj + 4) = *(s16 *) (obj + 0);
            var = 1;
            flags = *(s32 *) (hit + 0x24);
            if ((flags & 0x2000) && !(flags & 0x8000)) {
                var = 2;
            }
        }
    }
    if (var == 0) {
        return;
    }
    sndId = -1;
    switch (var) {
    case 1:
        *(s32 *) (obj + 0x84) = 2;
        if (*(u8 *) ((u8 *) levelGetLevel() + 0xE2) == 0) {
            sndId = 0x16;
        } else {
            sndId = 0xF;
        }
        break;
    case 2:
        *(s32 *) (obj + 0x84) = 0xC;
        sndId = 0x9E;
        break;
    case 3:
        *(s32 *) (obj + 0x84) = 2;
        sndId = 0xF;
        break;
    default:
        *(s32 *) (obj + 0x84) = 2;
        break;
    }
    if (sndId >= 0) {
        amSndPlayXYZ(sndId & 0xFFFF, *(f32 *) (obj + 0xC), *(f32 *) (obj + 0x10),
                     *(f32 *) (obj + 0x14), 4, NULL);
    }
    partUpdateTriggers(arg0, arg1);
    objFreeObject(arg0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o97/overlay_97/hitfragmentControl.s")
#endif
