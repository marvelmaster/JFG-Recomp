#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
#define RD_U8(p, off)  (*(u8 *)((u8 *)(p) + (off)))
#define RD_S16(p, off) (*(s16 *)((u8 *)(p) + (off)))
#define RD_S32(p, off) (*(s32 *)((u8 *)(p) + (off)))
#define RD_F32(p, off) (*(f32 *)((u8 *)(p) + (off)))
#define RD_PTR(p, off) (*(u8 **)((u8 *)(p) + (off)))

extern f32 D_overlay_118_0760092C;
extern f32 D_overlay_118_07600910;
extern u8 D_overlay_118_07600900[];
extern u8 robotMission;

typedef struct RobotSparkParams {  /* asm: stack block passed to sparkAdd */
    s16 u40;
    s16 u42;
    f32 f44;
    f32 f48;
    f32 f4C;
    f32 f50;
    f32 f54;
    s16 s58;
    s8 b5A;
    s8 b5B;
    s32 w5C;
    s32 w60;
} RobotSparkParams;

void **objGetObjList(s32 *, s32 *);
void *objGetPlayerNo(s32);
void objAnimDframe();
void hitInitObjectHit(void *arg0, s16 arg1, s8 arg2, s8 arg3, s16 arg4, s16 arg5, s16 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, u16 arg11);
s32 fxFadeOn();
void setupClearScreen(void *arg0);
void amSndPlay(u16 soundID, void *handlePtr);
void robotUpdateObjectives();
void robotFinished(void *arg0);
void sparkAdd(void *arg0);
void animseqPlay(void);
void animseqPause(void);
void animseqStartPath(s32 arg0);
void animseqStopPath(s32 arg0);
void animseqHoldPath(s32 arg0);
void animseqSetupGroup(s32 arg0);
f32 Sinf(s16 angle);
void *func_overlay_118_07600000_1FC5538(void);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_overlay_118_07600000_1FC5538(void) {
    s32 idx;
    s32 count;
    void **list;
    void *found;
    void *obj;

    found = NULL;
    list = objGetObjList(&idx, &count);
    for (; idx < count; idx++) {
        obj = list[idx];
        if (RD_S16(obj, 0x48) == 2) {
            found = obj;
        }
    }
    return found;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o118/overlay_118/func_overlay_118_07600000_1FC5538.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void robottargetInit(u8 *arg0, u8 *arg1) {
    RD_U8(arg0, 0x88) = RD_U8(arg1, 0xA);
    RD_U8(arg0, 0x89) = RD_U8(arg1, 0xB);
    RD_U8(arg0, 0x8A) = RD_U8(arg1, 0xC);
    RD_U8(arg0, 0x8B) = RD_U8(arg1, 0xD);
    RD_U8(arg0, 0x8C) = RD_U8(arg1, 0x10);
    RD_U8(arg0, 0x8D) = RD_U8(arg1, 0x11);
    RD_S16(arg0, 0x8E) = 0xFF;
    RD_S16(arg0, 0x0) = (s16) (RD_U8(arg1, 0xE) << 8);
    RD_U8(arg0, 0x3A) = 0;
    RD_S16(arg0, 0x2) = (s16) (RD_U8(arg1, 0xF) << 8);
    hitInitObjectHit(arg0, (s16) (RD_U8(arg1, 0xB) << 8), 0, 8, 0, 0, 0, 20.0f, 20.0f, -1.0f, 1.0f, 0x11);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o118/overlay_118/robottargetInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void robottargetControl(u8 *arg0, s32 arg1) {
    RobotSparkParams spark;
    u8 *objPtr;
    u8 *player;
    u8 *playerState;
    u8 *anim;
    s32 i;
    s32 count;
    u8 cmd;

    objPtr = RD_PTR(arg0, 0x4C);
    if (objPtr != NULL && RD_PTR(arg0, 0x5C) != NULL && RD_S16(objPtr, 0x6) > 0) {
        player = objGetPlayerNo(0);
        if (player != NULL) {
            playerState = RD_PTR(player, 0x68);
            if (playerState != NULL && RD_U8(playerState, 0x10D) == 1) {
                RD_S16(objPtr, 0x6) = (s16) (RD_S16(objPtr, 0x6) - RD_S16(RD_PTR(arg0, 0x5C), 0x130));
            }
        }
        if (RD_S16(objPtr, 0x6) <= 0) {
            anim = arg0 + 0x88;
            if (RD_U8(anim, 0x3) != 0) {
                RD_U8(arg0, 0x3A) = 1;
            }
            count = RD_U8(anim, 0x2);
            if (count != 0) {
                spark.f48 = RD_F32(arg0, 0xC);
                spark.f4C = RD_F32(arg0, 0x10);
                spark.f50 = RD_F32(arg0, 0x14);
                spark.s58 = 0x14;
                spark.b5A = 0xA;
                spark.b5B = 0xFF;
                spark.w5C = -0x7F01;
                spark.w60 = 0xFF0000FF;
                for (i = 0; i < count; i++) {
                    spark.u40 = (s16) mathRnd(-0x8000, 0x7FFF);
                    spark.u42 = (s16) mathRnd(-0x3000, 0x3C00);
                    spark.f44 = (f32) mathRnd(0x46, 0x5A) * D_overlay_118_07600910;
                    spark.f54 = (f32) mathRnd(0x19, 0x32) * D_overlay_118_07600910;
                    sparkAdd(&spark);
                }
            }
            cmd = RD_U8(anim, 0x4);
            switch (cmd) {
            case 0:
                animseqPlay();
                break;
            case 1:
                animseqPause();
                break;
            case 2:
                animseqStartPath(RD_U8(anim, 0x5));
                break;
            case 3:
                animseqStopPath(RD_U8(anim, 0x5));
                break;
            case 4:
                animseqHoldPath(RD_U8(anim, 0x5));
                break;
            case 5:
                animseqSetupGroup(RD_U8(anim, 0x5));
                break;
            }
            RD_S16(objPtr, 0x6) = 0;
            amSndPlay(0x22, 0);
            robotUpdateObjectives(RD_U8(anim, 0x0), 1);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o118/overlay_118/robottargetControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void robotcollectableInit(u8 *arg0, u8 *arg1) {
    RD_F32(arg0, 0x88) = (f32) RD_U8(arg1, 0xB);
    RD_S16(arg0, 0x8E) = 0xFF;
    RD_S16(arg0, 0x8C) = RD_U8(arg1, 0xA);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o118/overlay_118/robotcollectableInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void robotcollectableControl(u8 *arg0, s32 arg1) {
    u8 *player;
    u8 *playerState;
    u8 *target;

    if (RD_S16(arg0, 0x8E) == 0xFF) {
        if (RD_S16(arg0, 0x4A) == 0x2C5) {
            objAnimDframe(arg0, 0.01f, (f32) arg1);
        } else {
            RD_S16(arg0, 0x0) = (s16) (RD_S16(arg0, 0x0) + (arg1 << 8));
        }
        player = objGetPlayerNo(0);
        target = NULL;
        if (player != NULL) {
            playerState = RD_PTR(player, 0x68);
            if (playerState != NULL && RD_U8(playerState, 0x10D) == 1) {
                target = func_overlay_118_07600000_1FC5538();
            }
        }
        if (target != NULL) {
            u8 *tstate = RD_PTR(target, 0x68);
            f32 dx = RD_F32(arg0, 0xC) - RD_F32(tstate, 0x0);
            f32 dy = RD_F32(arg0, 0x10) - RD_F32(tstate, 0x4);
            f32 dz = RD_F32(arg0, 0x14) - RD_F32(tstate, 0x8);
            f32 radius = RD_F32(arg0, 0x88);

            if ((dx * dx) + (dy * dy) + (dz * dz) < radius * radius) {
                if (fxFadeOn() == 0) {
                    setupClearScreen(D_overlay_118_07600900);
                }
                amSndPlay(0x8A, 0);
                robotUpdateObjectives(RD_S16(arg0, 0x8C), 0);
                RD_S16(arg0, 0x8E) = (s16) (RD_S16(arg0, 0x8E) - (arg1 * 0x10));
            }
        }
    } else {
        if (RD_S16(arg0, 0x8E) > 0) {
            if (RD_S16(arg0, 0x4A) == 0x2C5) {
                objAnimDframe(arg0, 0.01f, (f32) arg1);
            } else {
                RD_S16(arg0, 0x0) = (s16) (RD_S16(arg0, 0x0) + (arg1 << 8));
            }
            RD_S16(arg0, 0x8E) = (s16) (RD_S16(arg0, 0x8E) - (arg1 * 0x10));
            if (RD_S16(arg0, 0x8E) < 0) {
                RD_S16(arg0, 0x8E) = 0;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o118/overlay_118/robotcollectableControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void robotcheckInit(u8 *arg0, u8 *arg1) {
    f32 sp28;
    f32 temp_f2;
    u8 *temp_s1;

    temp_s1 = RD_PTR(arg0, 0x68);
    RD_F32(arg0, 0x8) = (f32) ((f32) RD_U8(arg1, 0xC) * D_overlay_118_0760092C);
    RD_S16(arg0, 0x0) = (s16) (RD_U8(arg1, 0xD) << 0xA);
    RD_S16(arg0, 0x2) = (s16) (RD_U8(arg1, 0xE) << 0xA);
    RD_S16(arg0, 0x4) = 0;
    sp28 = Sinf(RD_S16(arg0, 0x0));
    RD_F32(temp_s1, 0x0) = (f32) (Cosf((s32) RD_S16(arg0, 0x2)) * sp28);
    RD_F32(temp_s1, 0x4) = (f32) -Sinf(RD_S16(arg0, 0x2));
    sp28 = Cosf((s32) RD_S16(arg0, 0x0));
    temp_f2 = Cosf((s32) RD_S16(arg0, 0x2)) * sp28;
    RD_F32(temp_s1, 0x8) = temp_f2;
    RD_F32(temp_s1, 0xC) = (f32) -((RD_F32(temp_s1, 0x0) * RD_F32(arg0, 0xC)) +
                                   (RD_F32(temp_s1, 0x4) * RD_F32(arg0, 0x10)) +
                                   (temp_f2 * RD_F32(arg0, 0x14)));
    RD_F32(temp_s1, 0x10) = (f32) (RD_U8(arg1, 0xC) * 4);
    RD_S16(temp_s1, 0x14) = (s16) RD_U8(arg1, 0xA);
    RD_S16(temp_s1, 0x16) = (s16) RD_U8(arg1, 0xB);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o118/overlay_118/robotcheckInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void robotcheckControl(u8 *arg0, s32 arg1) {
    u8 *plane;
    u8 *player;
    u8 *playerState;
    u8 *target;
    f32 tx;
    f32 ty;
    f32 tz;
    f32 dx;
    f32 dy;
    f32 dz;

    plane = RD_PTR(arg0, 0x68);
    if (robotMission != 0 && RD_S16(plane, 0x16) != 0) {
        player = objGetPlayerNo(0);
        if (player != NULL) {
            playerState = RD_PTR(player, 0x68);
            target = RD_PTR(playerState, 0x50C);
            if (target != NULL) {
                tx = RD_F32(target, 0xC);
                ty = RD_F32(target, 0x10);
                tz = RD_F32(target, 0x14);
                dx = tx - RD_F32(arg0, 0xC);
                dy = ty - RD_F32(arg0, 0x10);
                dz = tz - RD_F32(arg0, 0x14);
                if (((dx * dx) + (dy * dy) + (dz * dz)) < (RD_F32(plane, 0x10) * RD_F32(plane, 0x10)) &&
                    (((RD_F32(plane, 0x0) * tx) + (RD_F32(plane, 0x4) * ty) + (RD_F32(plane, 0x8) * tz) +
                      RD_F32(plane, 0xC)) < 0.0f)) {
                    robotUpdateObjectives(dz, RD_F32(plane, 0x10), RD_S16(plane, 0x14), 2, playerState);
                    if (RD_S16(plane, 0x16) == 0xFF && RD_U8(playerState, 0x10D) == 1) {
                        robotFinished(playerState);
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o118/overlay_118/robotcheckControl.s")
#endif
