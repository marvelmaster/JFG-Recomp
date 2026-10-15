#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
extern f32 D_overlay_135_08702A90;
extern f32 D_overlay_135_08702A94;
extern f32 D_overlay_135_08702A98;
extern f32 D_overlay_135_08702A9C;
extern f32 D_overlay_135_08702AA4;
extern f32 D_overlay_135_08702AA8;
extern f32 D_overlay_135_08702AAC;
extern f32 D_overlay_135_08702AB4;
extern f32 D_overlay_135_08702AB8;
extern f32 D_overlay_135_08702ABC;
extern f32 D_overlay_135_08702AC0;
extern f32 D_overlay_135_08702AC4;
extern f32 D_overlay_135_08702AC8;
extern u8 D_overlay_135_08702A78[];
extern u8 D_overlay_135_08702A84[];
extern u8 D_overlay_135_08702A68[];
extern u8 D_overlay_135_087029D0[];
extern u8 D_overlay_135_08702AD0[];

s32 mainGetGameFlag(s32 flag);
void *animseqWhichPathHasObject(void *obj);
void *camGetPtr(void);
f32 camGetFOV(f32 x, f32 y);
void camSetFOV(f32 fov, s32 arg1);
void camSetNo();
void trackGetFog(s32 arg0, s16 *arg1, s16 *arg2, void *arg3, u8 *arg4, u8 *arg5, u8 *arg6, void *arg7);
f32 Sinf(s32 angle);
f32 Powerf(f32 base, s32 exp);
s16 dAngle(s16 a, s16 b, f32 t);
void *menuCamGetObjPtr(void);
s32 menuCamSetFocus(void *obj, s32 dir);
void func_overlay_135_08702834_1FD2CBC(void *obj, s32 arg1, s32 arg2);
/* arg lists vary per caller, so these are unprototyped */
void **objGetObjList();
void objAnimSetMove();
void amSndPlay();
void amSndStop();
void amSndSetPitchDirect();
void amSndSetVol();

/* Steps s16 towards target by step, clamped at the target. */
static s16 menuCamApproach(s16 cur, s16 target, s32 step) {
    if (cur < target) {
        cur = (s16)(cur + step);
        if (target < cur) {
            cur = target;
        }
    } else if (target < cur) {
        cur = (s16)(cur - step);
        if (cur < target) {
            cur = target;
        }
    }
    return cur;
}
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void menuCamFocusInit(void *arg0, s32 arg1) {
    void **cam = *(void ***)((u8 *)arg0 + 0x68);

    *(s32 *)cam = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o135/overlay_135/menuCamFocusInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void menuCamFocusControl(void *arg0, s32 arg1) {
    void **cam = *(void ***)((u8 *)arg0 + 0x68);
    u8 *selfData = *(u8 **)((u8 *)arg0 + 0x3C);
    void **list;
    s32 start;
    s32 end;
    s32 i;
    f32 bestDist;
    f32 dist;
    f32 dx;
    f32 dy;
    f32 dz;
    void *obj;
    u8 *path;

    if (cam[0] != NULL) {
        return;
    }

    bestDist = D_overlay_135_08702A90;
    list = objGetObjList(&start, &end, arg0);
    if (start < end) {
        i = start;
        /* odd element count: the first entry is checked against the range limit */
        if ((end - start) & 1) {
            obj = list[start];
            if (*(u8 *)(*(u8 **)((u8 *)obj + 0x40) + 0x1B) == 8) {
                dx = *(f32 *)((u8 *)arg0 + 0x0C) - *(f32 *)((u8 *)obj + 0x0C);
                dy = *(f32 *)((u8 *)arg0 + 0x10) - *(f32 *)((u8 *)obj + 0x10);
                dz = *(f32 *)((u8 *)arg0 + 0x14) - *(f32 *)((u8 *)obj + 0x14);
                dist = (dx * dx) + (dy * dy) + (dz * dz);
                if (dist < D_overlay_135_08702A94) {
                    cam[0] = obj;
                    bestDist = dist;
                }
            }
            i++;
        }
        for (; i < end; i++) {
            obj = list[i];
            if (*(u8 *)(*(u8 **)((u8 *)obj + 0x40) + 0x1B) == 8) {
                dx = *(f32 *)((u8 *)arg0 + 0x0C) - *(f32 *)((u8 *)obj + 0x0C);
                dy = *(f32 *)((u8 *)arg0 + 0x10) - *(f32 *)((u8 *)obj + 0x10);
                dz = *(f32 *)((u8 *)arg0 + 0x14) - *(f32 *)((u8 *)obj + 0x14);
                dist = (dx * dx) + (dy * dy) + (dz * dz);
                if (dist < bestDist) {
                    cam[0] = obj;
                    bestDist = dist;
                }
            }
        }
    }

    obj = cam[0];
    if (obj != NULL) {
        path = animseqWhichPathHasObject(obj);
        cam[1] = path;
        objAnimSetMove(cam[0], *(u8 *)((u8 *)selfData + 0x0C), 0);
        *(f32 *)(path + 0x0C) = (f32)*(u8 *)((u8 *)selfData + 0x0D) / 255.0f;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o135/overlay_135/menuCamFocusControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void menuCamInit(void *arg0, s32 arg1) {
    u8 *cam = *(u8 **)((u8 *)arg0 + 0x68);

    *(s16 *)(cam + 0x4A) = 0;
    *(u8 *)(cam + 0x50) = 0;
    *(s8 *)(cam + 0x54) = 0x28;
    *(f32 *)(cam + 0x28) = 0.0f;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o135/overlay_135/menuCamInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void menuCamControl(void *arg0, s32 arg1) {
    u8 *cam;
    u8 *selfData;
    u8 *lvl;
    void **list;
    s32 start;
    s32 end;
    s32 i;
    u8 *obj;
    u8 *data;
    u8 *fObj;
    u8 *fCam;
    u8 *fData;
    void *anim;
    u8 *camera;
    u8 *tgt;
    s32 flags;
    s32 snd;
    s32 diff;
    s32 absDiff;
    s32 v1;
    s32 a0;
    s32 k;
    s16 fogNear;
    s16 fogFar;
    u8 fogR;
    u8 fogG;
    u8 fogB;
    s16 yaw;
    s16 pitch;
    s16 tYaw;
    s16 tPitch;
    s16 spEA;
    s16 spE6;
    s16 spE2;
    s16 spE6b;
    f32 fov;
    f32 f14;
    f32 f2;
    f32 spF8;
    f32 spF4;
    f32 spF0;
    f32 spEC;
    f32 dx;
    f32 dy;
    f32 dz;
    s32 a3v;
    s32 t3v;
    s32 t4v;
    s32 t5v;
    s32 rav;
    s32 fogIdx;

    cam = *(u8 **)((u8 *)arg0 + 0x68);
    selfData = *(u8 **)((u8 *)arg0 + 0x3C);
    lvl = (u8 *)levelGetLevel();

    /* first-time setup: collect the 0x47 objects and set the initial focus */
    if (*(u8 *)(cam + 0x50) == 0) {
        list = objGetObjList(&start, &end);
        for (i = start; i < end; i++) {
            obj = list[i];
            if (*(s16 *)(obj + 0x48) == 0x47) {
                data = *(u8 **)(obj + 0x3C);
                *(void **)(cam + 4 + data[0x0E] * 4) = obj;
                if (*(s8 *)(cam + 0x52) < (s8)data[0x0E]) {
                    *(s8 *)(cam + 0x52) = (s8)data[0x0E];
                }
            }
        }
        *(u8 *)(cam + 0x50) = 1;
        menuCamSetFocus(arg0, 0);
        trackGetFog(0, &fogNear, &fogFar, cam + 0x48, &fogR, &fogG, &fogB, cam + 0x55);
        *(s32 *)(cam + 0x30) = (s32)fogNear << 0x14;
        *(s32 *)(cam + 0x34) = (s32)fogFar << 0x14;
        *(s32 *)(cam + 0x38) = (s32)fogR << 0x14;
        *(s32 *)(cam + 0x3C) = (s32)fogG << 0x14;
        *(s32 *)(cam + 0x40) = (s32)fogB << 0x14;
    }

    /* stick input: step the focus left/right with a short cooldown */
    if (*(s8 *)(cam + 0x53) > 0) {
        *(s8 *)(cam + 0x53) = (s8)(*(s8 *)(cam + 0x53) - arg1);
    } else if (!(*(s32 *)cam & 2)) {
        if ((joyGetStickX(0) < -0x20) || (joyGetPressed(0) & 0x20)) {
            if (menuCamSetFocus(arg0, 1) != 0) {
                *(s8 *)(cam + 0x53) = 0x14;
                *(s8 *)(cam + 0x54) = 0x28;
            }
        } else if ((joyGetStickX(0) >= 0x21) || (joyGetPressed(0) & 0x10)) {
            if (menuCamSetFocus(arg0, 0) != 0) {
                *(s8 *)(cam + 0x53) = 0x14;
                *(s8 *)(cam + 0x54) = 0x28;
            }
        } else if ((joyGetStickX(0) >= -7) && (joyGetStickX(0) < 8)) {
            *(s8 *)(cam + 0x53) = 0;
        }
    }

    /* focused object and its cam/data blocks */
    fObj = *(u8 **)(cam + 4 + *(s8 *)(cam + 0x51) * 4);
    fCam = NULL;
    fData = NULL;
    anim = NULL;
    if (fObj != NULL) {
        fCam = *(u8 **)(fObj + 0x68);
        fData = *(u8 **)(fObj + 0x3C);
        anim = *(void **)fCam;
    }

    if (fCam != NULL && *(void **)(fCam + 4) != NULL) {
        if (joyGetPressed(0) & 0x8000) {
            flags = *(s32 *)cam;
            if (flags & 2) {
                if (!(flags & 4)) {
                    *(s32 *)cam = flags | 4;
                    objAnimSetMove(0, anim, fData[0x1C], 0, anim);
                    *(f32 *)(*(u8 **)(fCam + 4) + 0x0C) = (f32)fData[0x1D] / 255.0f;
                    list = objGetObjList(&start, &end);
                    for (i = start; i < end; i++) {
                        obj = list[i];
                        if (*(s16 *)(obj + 0x48) == 0x23) {
                            tgt = *(u8 **)(obj + 0x68);
                            if (*(s32 *)(selfData + 0x20) == *(s32 *)tgt) {
                                *(s16 *)(tgt + 4) = 0;
                                *(s16 *)(tgt + 6) = 0;
                            }
                        }
                    }
                }
            } else {
                *(s32 *)cam = flags | 2;
                if (anim != NULL) {
                    if (fData[0x0A] != *(u8 *)((u8 *)anim + 0x3B)) {
                        objAnimSetMove(0, anim, fData[0x0A], 0, anim);
                    }
                }
                *(f32 *)(*(u8 **)(fCam + 4) + 0x0C) = (f32)fData[0x0B] / 255.0f;
            }
        } else if (joyGetPressed(0) & 0x4000) {
            flags = *(s32 *)cam;
            if (!(flags & 4)) {
                *(s32 *)cam = flags & ~2;
                if (anim != NULL) {
                    if (fData[0x0C] != *(u8 *)((u8 *)anim + 0x3B)) {
                        objAnimSetMove(0, anim, fData[0x0C], 0, anim);
                    }
                }
                *(f32 *)(*(u8 **)(fCam + 4) + 0x0C) = (f32)fData[0x0D] / 255.0f;
            }
        }
    }

    /* 0x24 blend: towards 1 when active, towards 0 otherwise */
    if (*(s32 *)cam & 2) {
        for (k = 0; k < arg1; k++) {
            *(f32 *)(cam + 0x24) = *(f32 *)(cam + 0x24) + ((1.0f - *(f32 *)(cam + 0x24)) * D_overlay_135_08702A9C);
        }
    } else {
        for (k = 0; k < arg1; k++) {
            *(f32 *)(cam + 0x24) = *(f32 *)(cam + 0x24) + ((0.0f - *(f32 *)(cam + 0x24)) * D_overlay_135_08702AA8);
        }
    }

    /* 0x2C blend towards 1 when bit 4 is set */
    if (*(s32 *)cam & 4) {
        for (k = 0; k < arg1; k++) {
            *(f32 *)(cam + 0x2C) = *(f32 *)(cam + 0x2C) + ((1.0f - *(f32 *)(cam + 0x2C)) * D_overlay_135_08702AAC);
        }
    }

    camSetNo();
    camera = (u8 *)camGetPtr();

    /* 0x28 blend: towards 0 while 0x54 is counting down, towards 1 otherwise */
    if (*(s8 *)(cam + 0x54) > 0) {
        *(s8 *)(cam + 0x54) = (s8)(*(s8 *)(cam + 0x54) - arg1);
        for (k = 0; k < arg1; k++) {
            *(f32 *)(cam + 0x28) = *(f32 *)(cam + 0x28) + ((0.0f - *(f32 *)(cam + 0x28)) * D_overlay_135_08702AB4);
        }
    } else {
        for (k = 0; k < arg1; k++) {
            *(f32 *)(cam + 0x28) = *(f32 *)(cam + 0x28) + ((1.0f - *(f32 *)(cam + 0x28)) * D_overlay_135_08702ABC);
        }
    }

    /* camera position: lerp between the two focus points, then orbit the target */
    spEC = (f32)*(s16 *)(selfData + 0x0C)
         + ((f32)(*(s16 *)(selfData + 0x12) - *(s16 *)(selfData + 0x0C)) * *(f32 *)(cam + 0x28));
    yaw = *(s16 *)(cam + 0x4A);
    spF8 = Sinf(yaw) * spEC;
    spF4 = (f32)*(s16 *)(selfData + 0x10)
         + ((f32)(*(s16 *)(selfData + 0x14) - *(s16 *)(selfData + 0x10)) * *(f32 *)(cam + 0x28));
    spF0 = Cosf(yaw) * spEC;

    fObj = *(u8 **)(cam + 4 + *(s8 *)(cam + 0x51) * 4);
    data = *(u8 **)(fObj + 0x3C);
    f14 = Sinf((s32)((f32)yaw + ((1.0f - *(f32 *)(cam + 0x2C)) * (f32)*(s16 *)(data + 0x14))));
    f2 =Cosf((s32)((f32)yaw + ((1.0f - *(f32 *)(cam + 0x2C)) * (f32)*(s16 *)(data + 0x14))));
    *(f32 *)(camera + 0x0C) = (*(f32 *)(cam + 0x24) * ((f14 * (f32)*(s16 *)(selfData + 0x0A)) - spF8)) + spF8 + *(f32 *)((u8 *)arg0 + 0x0C);
    *(f32 *)(camera + 0x10) = (*(f32 *)(cam + 0x24) * ((f32)*(u8 *)(selfData + 0x0E) - spF4)) + spF4 + *(f32 *)((u8 *)arg0 + 0x10);
    *(f32 *)(camera + 0x14) = (*(f32 *)(cam + 0x24) * ((f2 * (f32)*(s16 *)(selfData + 0x0A)) - spF0)) + spF0 + *(f32 *)((u8 *)arg0 + 0x14);

    fov = camGetFOV(spF8, spF4);
    if (!(*(s32 *)cam & 2)) {
        t3v = (s32)lvl[0x61] << 0x14;
        a3v = (s32)lvl[0x60] << 0x14;
        t4v = (s32)lvl[0x62] << 0x14;
        t5v = (s32)lvl[0x5A] << 0x14;
        rav = (s32)lvl[0x5C] << 0x14;
        f14 = (f32)*(s32 *)(lvl + 0xAC);
    } else {
        a3v = (s32)*(s16 *)(selfData + 0x18) << 0x14;
        f14 = 45.0f;
        t3v = (s32)*(s16 *)(selfData + 0x19) << 0x14;
        t4v = (s32)*(s16 *)(selfData + 0x1A) << 0x14;
        t5v = (s32)*(s16 *)(selfData + 0x1C) << 0x14;
        rav = (s32)*(s16 *)(selfData + 0x1E) << 0x14;
    }
    for (k = 0; k < arg1; k++) {
        *(s32 *)(cam + 0x30) += (t5v - *(s32 *)(cam + 0x30)) >> 5;
        *(s32 *)(cam + 0x34) += (rav - *(s32 *)(cam + 0x34)) >> 5;
        *(s32 *)(cam + 0x38) += (a3v - *(s32 *)(cam + 0x38)) >> 5;
        *(s32 *)(cam + 0x3C) += (t3v - *(s32 *)(cam + 0x3C)) >> 5;
        *(s32 *)(cam + 0x40) += (t4v - *(s32 *)(cam + 0x40)) >> 5;
        fov = fov + ((f14 - fov) * 0.125f);
    }

    camSetFOV(fov, 1);
    trackSetFog(0, (s16)(*(s32 *)(cam + 0x30) >> 0x14), (s16)(*(s32 *)(cam + 0x34) >> 0x14),
                *(s16 *)(cam + 0x48), (u8)(*(s32 *)(cam + 0x38) >> 0x14),
                (u8)(*(s32 *)(cam + 0x3C) >> 0x14), (u8)(*(s32 *)(cam + 0x40) >> 0x14),
                (s8)*(s8 *)(cam + 0x55));

    tgt = *(u8 **)(fObj + 0x68);
    tgt = *(u8 **)tgt;
    if (tgt == NULL) {
        tgt = fObj;
    }
    dy = *(f32 *)(tgt + 0x10) - *(f32 *)(camera + 0x10);
    dx = *(f32 *)(tgt + 0x0C) - *(f32 *)(camera + 0x0C);
    dz = *(f32 *)(tgt + 0x14) - *(f32 *)(camera + 0x14);
    spEA = *(s16 *)(data + 0x10);
    spE6 = *(s16 *)(data + 0x12);
    spEA -= (s16)((f32 (*)(f32, f32))Arctanf)(dx, dz);
    spE6 -= (s16)((f32 (*)(f32, f32))Arctanf)(dy, sqrtf((dx * dx) + (dy * dy) + (dz * dz)));

    dx = *(f32 *)((u8 *)arg0 + 0x0C) - *(f32 *)(camera + 0x0C);
    dy = (*(f32 *)((u8 *)arg0 + 0x10) + (f32)*(s16 *)(selfData + 0x16)) - *(f32 *)(camera + 0x10);
    dz = *(f32 *)((u8 *)arg0 + 0x14) - *(f32 *)(camera + 0x14);
    tYaw = (s16)(-((f32 (*)(f32, f32))Arctanf)(dx, dz));
    tPitch = (s16)(-((f32 (*)(f32, f32))Arctanf)(dy, sqrtf((dx * dx) + (dy * dy) + (dz * dz))));
    spE2 = dAngle(tYaw, spEA, *(f32 *)(cam + 0x24));
    spE6b = dAngle(tPitch, spE6, *(f32 *)(cam + 0x24));
    *(s16 *)(camera + 0x00) = dAngle(spE2, tYaw, *(f32 *)(cam + 0x2C));
    *(s16 *)(camera + 0x02) = spE6b;

    /* yaw/pitch smoothing, with angle wrap-around */
    v1 = *(s16 *)(cam + 0x4A);
    a0 = *(s16 *)(cam + 0x4C);
    if (*(s32 *)cam & 1) {
        if (1 == (*(s32 *)cam & 1)) {
            if (v1 < a0) {
                a0 += -0x10000;
            }
        }
    } else if (a0 < v1) {
        a0 += 0x10000;
    }
    for (k = 0; k < arg1; k++) {
        v1 += (a0 - v1) >> 5;
    }
    *(s16 *)(cam + 0x4A) = (s16)v1;

    diff = a0 - v1;
    absDiff = (diff < 0) ? -diff : diff;
    if (absDiff < 0x64) {
        if (*(u8 *)(cam + 0x56) != 0) {
            snd = *(s32 *)(cam + 0x44);
            if (snd != 0) {
                amSndStop(snd);
            }
            amSndPlay(0x21, NULL);
            *(u8 *)(cam + 0x56) = 0;
        }
    } else {
        *(u8 *)(cam + 0x56) = 1;
        if (*(s32 *)(cam + 0x44) == 0) {
            amSndPlay(0x23, cam + 0x44);
        }
        snd = *(s32 *)(cam + 0x44);
        if (snd != 0) {
            f2 = (f32)absDiff / D_overlay_135_08702AC0;
            if (f2 > 1.0f) {
                f2 = 1.0f;
            }
            amSndSetPitchDirect(snd, f2 + 0.25f);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o135/overlay_135/menuCamControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 menuCamSetFocus(void *arg0, s32 arg1) {
    u8 *s = *(u8 **)((u8 *)arg0 + 0x68);
    s32 startIdx;
    s32 idx;
    void *target;
    f32 dx;
    f32 dy;
    f32 dz;

    mainGetGame();
    startIdx = *(s8 *)(s + 0x51);
    if (*(s8 *)(s + 0x52) >= 0) {
        /* step the focus index until it lands on a valid, unlocked entry */
        for (;;) {
            if (arg1 == 0) {
                *(s8 *)(s + 0x51) = (s8)(*(s8 *)(s + 0x51) + 1);
                idx = *(s8 *)(s + 0x51);
                if (*(s8 *)(s + 0x52) < idx) {
                    *(s8 *)(s + 0x51) = 0;
                    idx = 0;
                }
            } else {
                *(s8 *)(s + 0x51) = (s8)(*(s8 *)(s + 0x51) - 1);
                idx = *(s8 *)(s + 0x51);
                if (idx < 0) {
                    *(s8 *)(s + 0x51) = *(s8 *)(s + 0x52);
                    idx = *(s8 *)(s + 0x51);
                }
            }
            if (*(void **)(s + 4 + idx * 4) == NULL) {
                continue;
            }
            if (mainGetGameFlag(*(s32 *)(D_overlay_135_08702A78 + idx * 4)) == 0) {
                continue;
            }
            if (mainGetGameFlag(*(s32 *)(D_overlay_135_08702A84 + idx * 4)) == 0) {
                break;
            }
        }
    } else {
        *(s8 *)(s + 0x51) = 0;
    }

    target = *(void **)(s + 4 + *(s8 *)(s + 0x51) * 4);
    if (target != NULL) {
        dy = *(f32 *)((u8 *)target + 0x10) - *(f32 *)((u8 *)arg0 + 0x10);
        dx = *(f32 *)((u8 *)target + 0x0C) - *(f32 *)((u8 *)arg0 + 0x0C);
        dz = *(f32 *)((u8 *)target + 0x14) - *(f32 *)((u8 *)arg0 + 0x14);
        *(s16 *)(s + 0x4C) = (s16)((f32 (*)(f32, f32))Arctanf)(dx, dz);
        *(s16 *)(s + 0x4E) = (s16)-((f32 (*)(f32, f32))Arctanf)(dy, sqrtf((dx * dx) + (dy * dy) + (dz * dz)));
        if (startIdx != *(s8 *)(s + 0x51)) {
            *(s32 *)s = (*(s32 *)s & ~1) | arg1;
        }
    }
    return startIdx != *(s8 *)(s + 0x51);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o135/overlay_135/menuCamSetFocus.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void menuCamCleanup(void *arg0) {
    u8 *cam = *(u8 **)((u8 *)arg0 + 0x68);
    s32 snd = *(s32 *)(cam + 0x44);

    if (snd != 0) {
        amSndStop(snd);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o135/overlay_135/menuCamCleanup.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void menuCamFacingTVControl(void *arg0, s32 arg1) {
    u8 *s = *(u8 **)((u8 *)arg0 + 0x68);
    u8 *cam = NULL;
    u8 *target = NULL;
    u8 **ctrlArr;
    u8 *anim;
    u8 *tex;
    u16 *screen;
    u16 *dst;
    s32 row;
    s32 col;
    s32 rowStep;
    s32 parity = 0;
    s32 snd;
    s32 count;
    s32 vol;
    s32 t3;
    f32 frac;
    f32 acc;

    if (*(void **)s == NULL) {
        *(void **)s = menuCamGetObjPtr();
        *(s16 *)(s + 0x0A) = (s16)mathRnd(0x3C, 0x5A);
    }

    if (*(void **)s != NULL) {
        cam = *(u8 **)(*(u8 **)s + 0x68);
        if (*(s16 *)(cam + 0x54) <= 0) {
            *(s16 *)arg0 = dAngle(*(s16 *)arg0, (s16)(*(s16 *)(cam + 0x4C) + 0x8000),
                                  1.0f - Powerf(D_overlay_135_08702AC4, arg1));
        }
        target = *(u8 **)(*(u8 **)(cam + 4 + *(s8 *)(cam + 0x51) * 4) + 0x3C);
    }

    if (target != NULL) {
        if (*(s16 *)(s + 0x08) == 0) {
            *(s16 *)(s + 0x04) = *(s16 *)(target + 0x16);
            *(s16 *)(s + 0x06) = *(s16 *)(target + 0x18);
            *(s16 *)(s + 0x08) = *(s16 *)(target + 0x1A);
        } else {
            *(s16 *)(s + 0x04) = menuCamApproach(*(s16 *)(s + 0x04), *(s16 *)(target + 0x16), arg1);
            *(s16 *)(s + 0x06) = menuCamApproach(*(s16 *)(s + 0x06), *(s16 *)(target + 0x18), arg1);
            *(s16 *)(s + 0x08) = menuCamApproach(*(s16 *)(s + 0x08), *(s16 *)(target + 0x1A), arg1);
        }

        /* texture of the first control entry: scroll it into the screen buffer */
        ctrlArr = *(u8 ***)((u8 *)arg0 + 0x6C);
        anim = *(u8 **)ctrlArr[0];
        tex = *(u8 **)(anim + 0x18);
        screen = (u16 *)otherScreen;
        count = (s32)(*(s16 *)(s + 0x08) * 3) / 4;
        frac = (f32)count / (f32)tex[1];
        row = tex[1] - 1;
        if (row >= 0) {
            do {
                col = 0;
                rowStep = (s32)(((f32)row * frac) + (f32)*(s16 *)(s + 0x06)) * 0x140;
                t3 = (tex[1] - row) - 1;
                row -= 1;
                acc = 0.0f;
                if (*(s16 *)tex > 0) {
                    do {
                        dst = (u16 *)(tex + 0x20) + (*(s16 *)tex * t3) + (col ^ parity);
                        col += 1;
                        *dst = screen[rowStep + *(s16 *)(s + 0x04) + (s32)acc];
                        acc += (f32)*(s16 *)(s + 0x08) / (f32)*(s16 *)tex;
                    } while (col < (s32)*(s16 *)tex);
                }
                parity ^= 2;
            } while (row >= 0);
        }

        /* sparkle pixels */
        if (*(s16 *)(s + 0x0C) > 0) {
            count = (*(s16 *)tex * tex[1] * *(s16 *)(s + 0x0C)) / 100;
            while (count != 0) {
                row = mathRnd(0, tex[1] - 1);
                dst = (u16 *)(tex + 0x20) + (*(s16 *)tex * ((tex[1] - row) - 1)) + mathRnd(0, *(s16 *)tex - 1);
                vol = mathRnd(0, 0x80) * 2;
                count -= 1;
                *dst = (u16)(vol | (vol << 5) | (vol << 0xA) | 1);
            }
            if (*(s16 *)(s + 0x0C) < arg1) {
                *(s16 *)(s + 0x0A) = (s16)mathRnd(0x1E, 0x5A);
                *(s16 *)(s + 0x0C) = 0;
            } else {
                *(s16 *)(s + 0x0C) = (s16)(*(s16 *)(s + 0x0C) - arg1);
            }
            if (*(s32 *)cam & 2) {
                snd = *(s32 *)(s + 0x10);
                if (snd != 0) {
                    amSndStop(snd);
                }
            } else {
                if (*(s32 *)(s + 0x10) == 0) {
                    amSndPlay(0xCF, s + 0x10);
                }
                if (*(s32 *)(s + 0x10) != 0) {
                    t3 = *(s16 *)(s + 0x0C) * 2;
                    vol = (t3 >= 0x80) ? 0x7F : t3;
                    amSndSetVol(0xCF, *(s32 *)(s + 0x10), vol & 0xFF);
                }
            }
        } else {
            snd = *(s32 *)(s + 0x10);
            if (snd != 0) {
                amSndStop(snd);
            }
            if (*(s16 *)(s + 0x0A) < arg1) {
                *(s16 *)(s + 0x0C) = (s16)mathRnd(0x14, 0x4B);
            } else {
                *(s16 *)(s + 0x0A) = (s16)(*(s16 *)(s + 0x0A) - arg1);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o135/overlay_135/menuCamFacingTVControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void menuCamFacingTVCleanup(void *arg0) {
    u8 *cam = *(u8 **)((u8 *)arg0 + 0x68);
    s32 snd = *(s32 *)(cam + 0x10);

    if (snd != 0) {
        amSndStop(snd);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o135/overlay_135/menuCamFacingTVCleanup.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *menuCamGetObjPtr(void) {
    s32 pad[2];
    s32 start;
    s32 end;
    s32 i;
    void **list;

    list = objGetObjList(&start, &end);
    for (i = start; i < end; i++) {
        if (*(s16 *)((u8 *)list[i] + 0x48) == 0x46) {
            return list[i];
        }
    }
    return NULL;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o135/overlay_135/menuCamGetObjPtr.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void multiCharArmInit(void *arg0, void *arg1) {
    u8 *d = *(u8 **)((u8 *)arg0 + 0x68);
    u8 *src = (u8 *)arg1;

    *(s16 *)(d + 0x04) = *(s16 *)(src + 0x0A);
    *(s16 *)(d + 0x06) = *(s16 *)(src + 0x0C);
    *(s16 *)(d + 0x0C) = *(s16 *)(src + 0x10);
    *(s16 *)(d + 0x0A) = *(s16 *)(src + 0x12);
    *(s16 *)(d + 0x08) = *(s16 *)(d + 0x0A);
    *(u8 *)(d + 0x12) = src[0x0F];
    *(u8 *)(d + 0x10) = src[0x0E];
    *(u8 *)((u8 *)arg0 + 0x3A) = src[0x0E];
    *(s16 *)arg0 = *(s16 *)(d + 0x04);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o135/overlay_135/multiCharArmInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void multiCharArmControl(void *arg0, s32 arg1) {
    u8 *d = *(u8 **)((u8 *)arg0 + 0x68);
    s16 start0 = *(s16 *)arg0;
    s16 cur = start0;
    s32 v1;
    s32 delta = 0;
    s32 absDelta;
    s32 dir;
    s32 flip;
    s32 k;
    s32 handle;
    s32 t0;
    s32 yaw;
    u8 *ent;
    s32 pitchStep;
    f32 f2;
    s32 need = 0;

    if (d[0x13] != 0) {
        if (d[0x13] == 1 || d[0x13] == 2) {
            dir = *(s8 *)(d + 0x16);
            v1 = *(s16 *)(d + 0x08);
            if (dir == -1 && v1 < *(s16 *)(d + 0x0A)) {
                v1 += 0x10000;
            } else if (dir == 1 && *(s16 *)(d + 0x0A) < v1) {
                v1 -= 0x10000;
            }
            for (k = 0; k < arg1; k++) {
                *(s16 *)arg0 = (s16)(*(s16 *)arg0 + (((s32)(*(s16 *)(d + 0x06) - *(s16 *)arg0)) >> 3));
                v1 += (((s32)(*(s16 *)(d + 0x0A) - v1)) >> 4);
            }
            *(s16 *)(d + 0x08) = v1;
            cur = *(s16 *)arg0;
            delta = cur - start0;
        }
    } else {
        for (k = 0; k < arg1; k++) {
            *(s16 *)arg0 = (s16)(*(s16 *)arg0 + (((s32)(*(s16 *)(d + 0x04) - *(s16 *)arg0)) >> 4));
            *(s16 *)(d + 0x08) = (s16)(*(s16 *)(d + 0x08) - (*(s16 *)(d + 0x08) >> 1));
        }
        cur = *(s16 *)arg0;
        delta = cur - start0;
    }

    if (arg1 != 0) {
        delta = delta / arg1;
    }
    absDelta = (delta < 0) ? -delta : delta;
    if (absDelta < 0x64) {
        if (*(s32 *)(d + 0x18) != 0) {
            handle = *(s32 *)d;
            if (handle != 0) {
                amSndStop(handle);
            }
            amSndPlay(0x21, NULL);
            *(s32 *)(d + 0x18) = 0;
        }
    } else {
        *(u8 *)(d + 0x18) = 1;
        if (*(s32 *)d == 0) {
            amSndPlay(0x23, d);
        }
        handle = *(s32 *)d;
        if (handle != 0) {
            f2 = (f32)delta / D_overlay_135_08702AC8;
            if (f2 > 1.0f) {
                f2 = 1.0f;
            }
            amSndSetPitchDirect(handle, f2 + 0.25f);
        }
    }

    v1 = *(s16 *)(d + 0x08);
    if (v1 < 0) {
        v1 += 0x8000;
    }
    t0 = *(s16 *)(d + 0x0E);
    if (t0 < 0) {
        t0 += 0x8000;
    }
    dir = *(s8 *)(d + 0x16);
    yaw = *(s16 *)(d + 0x0C);
    if ((dir == 1 && !(yaw < t0) && yaw < v1) ||
        (dir == -1 && yaw < t0 && yaw >= v1) ||
        (*(u8 *)(d + 0x17) != 0)) {
        need = 1;
    }
    if (*(u8 *)(d + 0x1A) == 1) {
        need = 1;
        *(u8 *)(d + 0x1A) = 2;
    }
    if (need != 0) {
        if (*(u8 *)(d + 0x19) != 0) {
            pitchStep = *(s16 *)(D_overlay_135_08702A68 + ((*(s8 *)(d + 0x14) & 7) * 2));
            flip = 0;
        } else {
            ent = D_overlay_135_087029D0 + *(s8 *)(d + 0x14) * 8;
            flip = ent[2];
            pitchStep = (s8)ent[3];
            if (d[0x13] == 2) {
                pitchStep += 1;
            }
        }
        *(u8 *)((u8 *)arg0 + 0x3A) = (u8)(((*(u8 *)((u8 *)arg0 + 0x3A)) & 3) + flip);
        func_overlay_135_08702834_1FD2CBC(arg0, (s16)(pitchStep << 8), 0xE);
    }
    *(u8 *)(d + 0x17) = 0;
    *(s16 *)(d + 0x0E) = *(s16 *)(d + 0x08);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o135/overlay_135/multiCharArmControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void multiCharArmSetStatus(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *d = *(u8 **)((u8 *)arg0 + 0x68);

    if (arg3 == 1) {
        *(s8 *)(d + 0x16) = -1;
        *(s16 *)(d + 0x0A) = (s16)(*(s16 *)(d + 0x0A) - 0x8000);
    } else if (arg3 == 2) {
        *(s8 *)(d + 0x16) = 1;
        *(s16 *)(d + 0x0A) = (s16)(*(s16 *)(d + 0x0A) + 0x8000);
    }
    if (d[0x13] == 1 && arg1 == 0) {
        if (*(s16 *)(d + 0x08) < 0) {
            *(s16 *)(d + 0x08) = (s16)(*(s16 *)(d + 0x08) + 0x8000);
        }
    }
    if (arg1 == 2 && d[0x13] == 1) {
        *(u8 *)(d + 0x17) = 1;
        amSndPlay(0xFD, NULL);
    } else if (arg1 == 1) {
        if (d[0x13] == 2) {
            *(u8 *)(d + 0x17) = 1;
            amSndPlay(0xFE, NULL);
        }
    }
    *(s8 *)(d + 0x14) = (s8)arg2;
    *(u8 *)(d + 0x13) = (u8)arg1;
    *(s8 *)(d + 0x19) = (s8)arg4;
    if (*(u8 *)(d + 0x1A) == 0) {
        *(u8 *)(d + 0x1A) = 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o135/overlay_135/multiCharArmSetStatus.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_135_08702834_1FD2CBC(void *arg0, s32 arg1, s32 arg2) {
    u8 *ctrl = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x6C) + (*(s8 *)((u8 *)arg0 + 0x3A) * 4));
    u8 *entry = *(u8 **)(ctrl + 0x74);
    u8 *anim = *(u8 **)ctrl;
    u8 *out = *(u8 **)(ctrl + (*(s8 *)(ctrl + 0x0B) * 4) + 0x78);
    s32 s0 = arg1;
    s32 key;
    s32 n;
    s32 i;
    u8 *ent2;
    s32 flags;

    if (entry != NULL) {
        key = arg2 << 8;
        n = *(u8 *)(anim + 0x2C);
        for (i = 0; i < n; i++) {
            flags = *(s32 *)(entry + 4);
            ent2 = *(u8 **)(*(u8 **)(anim + 0x18) + ((flags & 0xFF) * 8));
            if ((flags & 0x10000) && (key == *(u16 *)(ent2 + 0x12))) {
                *(s16 *)entry = s0;
                if (*(s16 *)(entry + 2) >= 0) {
                    s0 += 0x100;
                    if (s0 >= *(u16 *)(ent2 + 0x12)) {
                        s0 -= 0x100;
                    }
                    *(s16 *)(entry + 2) = s0;
                }
            }
            if (*(s16 *)(entry + 2) >= 0) {
                *(s16 *)out = (s16)((*(s16 *)(entry + 2) >> 8) * *(s16 *)(ent2 + 0x16));
                out += 2;
            }
            *(s16 *)out = (s16)((*(s16 *)entry >> 8) * *(s16 *)(ent2 + 0x16));
            out += 2;
            entry += 8;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o135/overlay_135/func_overlay_135_08702834_1FD2CBC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void multiCharArmGetTiltList(void *arg0) {
    u8 *cam = *(u8 **)((u8 *)arg0 + 0x68);
    u8 *base = D_overlay_135_08702AD0;
    s16 *list = (s16 *)base;
    s16 tilt = *(s16 *)(cam + 0x08);

    list[0] = 0x2008;
    list[2] = 0x2006;
    list[3] = 0;
    list[4] = 0x200A;
    list[5] = 0;
    list[6] = 0x1000;
    list[1] = tilt;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o135/overlay_135/multiCharArmGetTiltList.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void multiCharArmCleanup(void *arg0) {
    u8 *cam = *(u8 **)((u8 *)arg0 + 0x68);
    s32 snd = *(s32 *)cam;

    if (snd != 0) {
        amSndStop(snd);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o135/overlay_135/multiCharArmCleanup.s")
#endif
