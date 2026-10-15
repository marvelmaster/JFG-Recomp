#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
void BTSBStandardFire(s32 arg0);
void squadsGetChildPolyPosition(s32 arg0, f32 *arg1, f32 *arg2, f32 *arg3);
void hitInitObjectHit(void *arg0, s16 arg1, s8 arg2, s8 arg3, s16 arg4, s16 arg5, s16 arg6, f32 arg7,
                      f32 arg8, f32 arg9, f32 arg10, u16 arg11);
void amSndPlayXYZ(u16 soundId, f32 x, f32 y, f32 z, u8 arg4, void *soundMask);
void partUpdateTriggers(void *obj, s32 arg1);
void trackMakePolylist(s32 a, f32 *b, f32 *c, s32 *d, s32 e, s32 f, s32 g);
s32 trackGetIntersect(s32 a, f32 *b, f32 *c, s32 d, s32 e, void *hit);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void BTSBSpannerHand(Object *arg0) {
    u8 *racer;
    Object *hand;
    u8 *handRacer;
    f32 px;
    f32 py;
    f32 pz;

    racer = (u8 *)arg0->racer;
    hand = *(Object **)(racer + 0xAC);
    if (hand != NULL) {
        handRacer = (u8 *)hand->racer;
        squadsGetChildPolyPosition(0, &px, &py, &pz);
        *(f32 *)(handRacer + 0x4) = px;
        *(f32 *)(handRacer + 0x8) = py;
        *(f32 *)(handRacer + 0xC) = pz;
        hand->segment.trans.x_position = *(f32 *)(handRacer + 0x10);
        hand->segment.trans.y_position = *(f32 *)(handRacer + 0x14);
        hand->segment.trans.z_position = *(f32 *)(handRacer + 0x18);
    }
    BTSBStandardFire((s32)arg0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o150/overlay_150/BTSBSpannerHand.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// arg1 is the spawn-data block (fields read at 0x04..0x24).
void LaserBeamInit(void *arg0, void *arg1) {
    Object *obj;
    u8 *racer;
    u8 *spawn;

    obj = (Object *)arg0;
    spawn = (u8 *)arg1;
    racer = (u8 *)obj->racer;

    racer[0x20] = 0x40;
    racer[0x21] = 0;
    *(s16 *)(racer + 0x24) = 0;
    *(s16 *)(racer + 0x26) = 0;
    racer[0x22] = 1;
    *(s16 *)(racer + 0x28) = 0;
    *(s16 *)(racer + 0x2A) = 0;
    racer[0x23] = 2;
    *(s16 *)(racer + 0x2C) = 0;
    *(s16 *)(racer + 0x2E) = 0;
    racer[0x30] = 0x40;
    racer[0x31] = 1;
    *(s16 *)(racer + 0x34) = 0;
    *(s16 *)(racer + 0x36) = 0;
    racer[0x32] = 2;
    *(s16 *)(racer + 0x38) = 0;
    *(s16 *)(racer + 0x3A) = 0;
    racer[0x33] = 3;
    *(s16 *)(racer + 0x3C) = 0;
    *(s16 *)(racer + 0x3E) = 0;

    *(s32 *)(racer + 0x0) = *(s32 *)(spawn + 0x1C);
    *(f32 *)(racer + 0x4) = (f32)*(s16 *)(spawn + 0x4);
    *(f32 *)(racer + 0x8) = (f32)*(s16 *)(spawn + 0x6);
    *(f32 *)(racer + 0xC) = (f32)*(s16 *)(spawn + 0x8);

    *(f32 *)(racer + 0x10) = *(f32 *)(spawn + 0xC);
    *(f32 *)((u8 *)obj + 0xC) = *(f32 *)(spawn + 0xC);
    *(f32 *)(racer + 0x14) = *(f32 *)(spawn + 0x10);
    *(f32 *)((u8 *)obj + 0x10) = *(f32 *)(spawn + 0x10);
    *(f32 *)(racer + 0x18) = *(f32 *)(spawn + 0x14);
    *(f32 *)((u8 *)obj + 0x14) = *(f32 *)(spawn + 0x14);
    racer[0x1C] = spawn[0x18];
    *(f32 *)((u8 *)obj + 0x1C) = 0.0f;
    *(f32 *)((u8 *)obj + 0x20) = 0.0f;
    *(f32 *)((u8 *)obj + 0x24) = 0.0f;
    racer[0x80] = 0;
    *(s32 *)(racer + 0x88) = *(s32 *)(spawn + 0x20);
    *(s32 *)(racer + 0x8C) = *(s32 *)(spawn + 0x24);

    hitInitObjectHit(obj, (s16)(spawn[0x18] << 8), 1, 4, 0, 0, 0, 4.0f, 4.0f, -1.0f, 1.0f, 0x11);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o150/overlay_150/LaserBeamInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void LaserBeamControl(Object *obj, s32 arg1) {
    u8 *racer;
    SoundMask *soundMask;
    u8 *header;
    u8 *spawn;
    s32 hitInfo;

    racer = (u8 *)obj->racer;
    soundMask = *(SoundMask **)(racer + 0x90);
    if (soundMask == NULL) {
        amSndPlayXYZ(0x125, obj->segment.trans.x_position, obj->segment.trans.y_position,
                     obj->segment.trans.z_position, 1, racer + 0x90);
    } else {
        amSndSetXYZ(soundMask, obj->segment.trans.x_position, obj->segment.trans.y_position,
                    obj->segment.trans.z_position);
    }

    header = *(u8 **)((u8 *)obj + 0x40);
    spawn = *(u8 **)(header + 0x50);
    trackMakePolylist(1, (f32 *)(racer + 0x4), &obj->segment.trans.x_position, (s32 *)(spawn + 0xC), 0xCE000000,
                      0, 0);
    trackGetIntersect((s32)obj, (f32 *)(racer + 0x4), (f32 *)(racer + 0x10), *(s32 *)(spawn + 0xC),
                      (s32)spawn[0x10], &hitInfo);
    *(s32 *)((u8 *)obj + 0x84) = 1;
    partUpdateTriggers(obj, arg1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o150/overlay_150/LaserBeamControl.s")
#endif
