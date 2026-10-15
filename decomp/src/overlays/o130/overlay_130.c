#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
typedef struct TwinkleRacer {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ u8 unk16;
} TwinkleRacer;

typedef struct TwinkleSetup {
    /* 0x00 */ u8 pad00[0xA];
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 unkB;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
    /* 0x10 */ s16 unk10;
    /* 0x12 */ u8 pad12[2];
    /* 0x14 */ s32 unk14;
} TwinkleSetup;

void hitInitObjectHit(Object *obj, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6,
                      f32 f1, f32 f2, f32 f3, f32 f4, s32 a7);
s16 objTvTimes(s32 n);
s32 trackLightAdd(f32 x, f32 y, f32 z, f32 a, f32 b, s32 c, s32 d, s32 e);
void amSndPlayXYZ(u16 soundId, f32 x, f32 y, f32 z, u8 arg4, void *soundMask);
void explosionStart(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, s32 arg5);
void objFreeObject(void *obj);
void objMoveXYZ(void *obj, f32 x, f32 y, f32 z);
void *objSetupObject(void *params, s32 arg1);
void partUpdateTriggers(void *obj, s32 arg1);
void runlinkSetDestructTimer(s32 overlayIndex, s32 selfDestructTimer, s32 refCount);
void squadsAddInterestingEvent(void *obj, s16 x, s16 y, s16 z, s32 a, s32 b, s32 c);
void trackLightDelete(s32 id);
void trackLightMove(s32 id, f32 x, f32 y, f32 z);
s32 trackNearestIntersection(void *obj, void *from, void *to, void *hit, s32 a4, s32 a5);
extern s32 __MODULE00130;

typedef struct TwinkleHit {
    /* 0x00 */ s32 unk00;
    /* 0x04 */ f32 x;
    /* 0x08 */ f32 y;
    /* 0x0C */ f32 z;
    /* 0x10 */ f32 nx;
    /* 0x14 */ f32 ny;
    /* 0x18 */ f32 nz;
    /* 0x1C */ s32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 surface;
} TwinkleHit;

typedef struct TwinkleSpawn {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3;
    /* 0x04 */ s16 x;
    /* 0x06 */ s16 y;
    /* 0x08 */ s16 z;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ f32 scale;
} TwinkleSpawn;
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void TwinkleInit(Object *arg0, TwinkleSetup *arg1) {
    TwinkleRacer *racer;
    f32 temp_f0;
    f32 temp_f2;

    *(f32 *)((u8 *)arg0 + 0x1C) = (f32)arg1->unkC;
    *(f32 *)((u8 *)arg0 + 0x20) = (f32)arg1->unkE;
    *(f32 *)((u8 *)arg0 + 0x24) = (f32)arg1->unk10;
    temp_f0 = *(f32 *)((u8 *)arg0 + 0x1C);
    temp_f2 = *(f32 *)((u8 *)arg0 + 0x24);
    arg0->segment.trans.y_rotation = (s16)(Arctanf(temp_f0, temp_f2) - 0x8000);
    arg0->segment.trans.x_rotation =
        (s16)Arctanf(*(f32 *)((u8 *)arg0 + 0x20), sqrtf((temp_f0 * temp_f0) + (temp_f2 * temp_f2)));
    arg0->segment.trans.z_rotation = 0;
    racer = (TwinkleRacer *)arg0->racer;
    racer->unk16 = 0;
    racer->unkC = 0;
    racer->unk0 = arg0->segment.trans.x_position;
    racer->unk4 = arg0->segment.trans.y_position;
    racer->unk8 = arg0->segment.trans.z_position;
    racer->unk14 = objTvTimes(arg1->unkB * 6);
    racer->unk10 = arg1->unk14;
    hitInitObjectHit(arg0, (arg1->unkA + 1) << 8, 1, 4, 0, 0, 0, 2.0f, 2.0f, -1.0f, 1.0f, 0x11);
    *(s32 *)((u8 *)arg0 + 0x88) = *(s16 *)(*(u8 **)((u8 *)arg0 + 0x4C) + 6);
    *(s32 *)((u8 *)arg0 + 0x8C) = trackLightAdd(arg0->segment.trans.x_position,
                                               arg0->segment.trans.y_position,
                                               arg0->segment.trans.z_position,
                                               500.0f, 300.0f, 0, 0xE0, 0xFF);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o130/overlay_130/TwinkleInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void TwinkleControl(Object *obj, s32 arg1) {
    TwinkleRacer *racer;
    TwinkleHit hit;
    TwinkleSpawn spawn;
    void *spawned;
    s16 target;

    racer = (TwinkleRacer *)obj->racer;
    runlinkSetDestructTimer(__MODULE00130, 2, 2);
    racer->unk14 = (s16)(racer->unk14 - arg1);

    if (racer->unk14 > 0 && (target = *(s16 *)(*(u8 **)((u8 *)obj + 0x4C) + 6)) > 0 &&
        racer->unk16 == 0 && *(s32 *)((u8 *)obj + 0x88) == target) {
        objMoveXYZ(obj, *(f32 *)((u8 *)obj + 0x1C), *(f32 *)((u8 *)obj + 0x20), *(f32 *)((u8 *)obj + 0x24));
        racer->unk16 = (u8)trackNearestIntersection(obj, *(u8 **)((u8 *)obj + 0x4C) + 0x18,
                                                    (u8 *)obj + 0xC, &hit, 0, 0);
        if (racer->unk16 != 0) {
            racer->unk0 = hit.x;
            racer->unk4 = hit.y;
            racer->unk8 = hit.z;
            racer->unkC = hit.surface;
            objMoveXYZ(obj, racer->unk0 - *(f32 *)((u8 *)obj + 0xC), racer->unk4 - *(f32 *)((u8 *)obj + 0x10), racer->unk8 - *(f32 *)((u8 *)obj + 0x14));
            if (racer->unk16 == 1 &&
                (s16)Arctanf(hit.ny, sqrtf(hit.nz * hit.nz + hit.nx * hit.nx)) < 0x2000) {
                racer->unk16 = 2;
            }
        }
        if (*(s32 *)((u8 *)obj + 0x8C) != 0) {
            trackLightMove(*(s32 *)((u8 *)obj + 0x8C), *(f32 *)((u8 *)obj + 0xC), *(f32 *)((u8 *)obj + 0x10), *(f32 *)((u8 *)obj + 0x14));
        }
    } else {
        if ((racer->unkC & 0x2000) && !(racer->unkC & 0x8000)) {
            amSndPlayXYZ(0xD, *(f32 *)((u8 *)obj + 0xC), *(f32 *)((u8 *)obj + 0x10), *(f32 *)((u8 *)obj + 0x14), 4, 0);
            spawn.unk0 = 0xC0;
            spawn.unk2 = 0x10;
            spawn.x = (s16)(s32)racer->unk0;
            spawn.y = (s16)(s32)racer->unk4;
            spawn.z = (s16)(s32)racer->unk8;
            spawn.unkA = 0x100;
            spawn.scale = 20.0f;
            spawned = objSetupObject(&spawn, 1);
            if (spawned != NULL) {
                *(s32 *)((u8 *)spawned + 0x3C) = 0;
            }
        } else {
            amSndPlayXYZ(0x96, *(f32 *)((u8 *)obj + 0xC), *(f32 *)((u8 *)obj + 0x10), *(f32 *)((u8 *)obj + 0x14), 4, 0);
            explosionStart(2, (s16)(s32)*(f32 *)((u8 *)obj + 0xC), (s16)(s32)*(f32 *)((u8 *)obj + 0x10), (s16)(s32)*(f32 *)((u8 *)obj + 0x14), 0x64, 0);
            squadsAddInterestingEvent(0, (s16)(s32)*(f32 *)((u8 *)obj + 0xC), (s16)(s32)*(f32 *)((u8 *)obj + 0x10), (s16)(s32)*(f32 *)((u8 *)obj + 0x14), 5, 1, 0x96);
        }
        if (*(s32 *)((u8 *)obj + 0x8C) != 0) {
            trackLightDelete(*(s32 *)((u8 *)obj + 0x8C));
        }
        objFreeObject(obj);
        racer = NULL;
    }
    if (racer != NULL) {
        *(s32 *)((u8 *)obj + 0x84) = 3;
        partUpdateTriggers(obj, arg1);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o130/overlay_130/TwinkleControl.s")
#endif
