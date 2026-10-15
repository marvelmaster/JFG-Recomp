#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern s32 __MODULE00029;
extern f32 D_overlay_29_01D00FC4;
extern f32 D_overlay_29_01D00FC8;
extern s32 D_overlay_29_01D00FD0;
extern s32 D_overlay_29_01D00FD4;
extern Object *D_overlay_29_01D00FD8;
extern Object *D_overlay_29_01D00FDC;
extern f32 D_overlay_29_01D00FE0;
extern f32 D_overlay_29_01D00FE4;
extern f32 D_overlay_29_01D00FE8;
extern s32 D_overlay_29_01D00F94;
extern f32 D_overlay_29_01D00F98;
extern f32 D_overlay_29_01D00F9C;
extern f32 D_overlay_29_01D00FA0;
extern s32 D_overlay_29_01D00FA4;
extern s32 D_overlay_29_01D00FA8;
extern f32 D_overlay_29_01D00FEC;
extern f32 D_overlay_29_01D00FF0;
extern f32 D_overlay_29_01D00FF4;
extern f32 D_overlay_29_01D00FF8;
extern f32 D_overlay_29_01D00FFC;
extern s16 D_overlay_29_01D01000;
extern s16 D_overlay_29_01D01002;
extern s16 D_overlay_29_01D01004;
extern s16 D_overlay_29_01D01006;
extern f32 D_overlay_29_01D01008;
extern f32 D_overlay_29_01D0100C;
extern f32 D_overlay_29_01D01010;
extern s16 D_overlay_29_01D01014;
extern s16 D_overlay_29_01D01016;
extern s16 D_overlay_29_01D01018;
extern s16 D_overlay_29_01D0101A;
extern s32 D_overlay_29_01D0101C;
extern ObjectTransform *controlcam;

ObjectTransform *camGetListPtr(void);
Object **objGetObjList(s32 *arg0, s32 *arg1, void *arg2);
Object *objSetupObject(s16 *arg0, s32 arg1);
void objMoveXYZ(void *arg0, f32 arg1, f32 arg2, f32 arg3);
void objFreeObject(void *arg0);
void partUpdateTriggers(void *arg0, s32 arg1);
void explosionStart(s32 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, void *arg5);
void amSndPlay(s32 arg0, s32 arg1);
void amSndPlayXYZ(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4, s32 arg5);
void runlinkSetDestructTimer(s32 arg0, s32 arg1, s32 arg2);
s32 squadsIsTribal(s16 arg0);
s32 trackGetHeights(f32 arg0, f32 arg1, s32 arg2, f32 ***arg3);
s32 hitGetHeights(f32 arg0, f32 arg1, s32 arg2, f32 ***arg3);
f32 Powerf(f32 arg0, s32 arg1);
f32 Sinf(s16 arg0);
s16 dAngle(s16 arg0, s16 arg1, f32 arg2);
void girlMagicCameraInit(Object *arg0);
void girlMagicCutCamera(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s16 arg5, f32 arg6);
void girlMagicFadeFog(f32 arg0, f32 arg1);
void girlMagicUpdateFog(s32 arg0);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void girlUpdateMagic(Object *arg0, void *arg1, s32 arg2) {
    u8 *state;
    struct {
        s16 id;
        s16 pad2;
        s16 unk4;
        s16 unk6;
        s16 unk8;
        s8 unkA;
        s8 unkB;
        s8 unkC;
        s8 unkD;
    } setup;
    s32 start;
    s32 end;
    Object **objList;
    Object *obj;
    ObjectTransform *tgt;
    f32 **trackHeights;
    f32 **hitHeights;
    s32 ok;
    s32 blocked;
    s32 timer;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 frac;
    f32 hitY;

    state = arg1;
    runlinkSetDestructTimer(__MODULE00029, 2, 2);
    switch (state[0x19D]) {
    case 1:
        if (*(s32 *)(state + 0x568) != 0) {
            state[0x19D] = 0;
        } else if (*(f32 *)(state + 4) == 0.0f) {
            /* asm passes two extra unused args to girlMagicFadeFog */
            girlMagicFadeFog(1.0f, 2.75f);
            girlMagicCameraInit(arg0);
            state[0x19D] = 2;
            D_overlay_29_01D0101C = 0xB4;
            setup.id = 0x56;
            setup.unk4 = 0;
            setup.unk6 = 0;
            setup.unk8 = 0;
            setup.unkA = 0;
            setup.unkB = 0x40;
            setup.unkC = 0;
            setup.unkD = 0;
            D_overlay_29_01D00FDC = objSetupObject((s16 *)&setup, 1);
            if (D_overlay_29_01D00FDC != NULL) {
                *(s32 *)((u8 *)D_overlay_29_01D00FDC + 0x3C) = 0;
                D_overlay_29_01D00FDC->segment.trans.unk6 = (s16) (D_overlay_29_01D00FDC->segment.trans.unk6 | 0x400);
            }
        }
        break;
    case 2:
        timer = D_overlay_29_01D0101C - arg2;
        D_overlay_29_01D0101C = timer;
        if (timer <= 0) {
            state[0x19D] = 3;
        }
        break;
    case 3:
        objList = objGetObjList(&start, &end, arg1);
        D_overlay_29_01D00FD8 = NULL;
        while (start < end) {
            obj = objList[start];
            start++;
            D_overlay_29_01D00FD8 = obj;
            ok = 0;
            tgt = *(ObjectTransform **)((u8 *)obj + 0x4C);
            if ((*(s16 *)((u8 *)obj + 0x48) == 0x18) && (tgt != NULL) && (tgt->unk6 > 0)
                && (squadsIsTribal(*(s16 *)((u8 *)obj + 0x4A)) == 0)) {
                dx = arg0->segment.trans.x_position - obj->segment.trans.x_position;
                dy = arg0->segment.trans.y_position - obj->segment.trans.y_position;
                dz = arg0->segment.trans.z_position - obj->segment.trans.z_position;
                if (((dx * dx) + (dy * dy) + (dz * dz)) < D_overlay_29_01D00FC4) {
                    blocked = 0;
                    if ((trackGetHeights(obj->segment.trans.x_position, obj->segment.trans.z_position, 0x800, &trackHeights) != 0)
                        && (obj->segment.trans.y_position < **trackHeights)) {
                        blocked = 1;
                    }
                    if (!blocked) {
                        if ((hitGetHeights(obj->segment.trans.x_position, obj->segment.trans.z_position, 0x800, &hitHeights) != 0)
                            && (obj->segment.trans.y_position < **hitHeights)) {
                            blocked = 1;
                        }
                    }
                    if (!blocked) {
                        ok = 1;
                    }
                }
            }
            if (ok) {
                break;
            }
            D_overlay_29_01D00FD8 = NULL;
        }
        if (D_overlay_29_01D00FD8 == NULL) {
            state[0x19D] = 5;
            D_overlay_29_01D00FD4 = 0xB4;
            girlMagicFadeFog(0.0f, 2.75f);
        } else {
            D_overlay_29_01D00FE0 = D_overlay_29_01D00FD8->segment.trans.x_position;
            D_overlay_29_01D00FE4 = D_overlay_29_01D00FD8->segment.trans.y_position + 2000.0f;
            D_overlay_29_01D00FE8 = D_overlay_29_01D00FD8->segment.trans.z_position;
            if (D_overlay_29_01D00FDC != NULL) {
                objMoveXYZ(D_overlay_29_01D00FDC,
                           D_overlay_29_01D00FE0 - D_overlay_29_01D00FDC->segment.trans.x_position,
                           D_overlay_29_01D00FE4 - D_overlay_29_01D00FDC->segment.trans.y_position,
                           D_overlay_29_01D00FE8 - D_overlay_29_01D00FDC->segment.trans.z_position);
                D_overlay_29_01D00FDC->segment.trans.unk6 = (s16) (D_overlay_29_01D00FDC->segment.trans.unk6 & 0xFBFF);
            }
            state[0x19D] = 4;
            D_overlay_29_01D00FD0 = 0x3C;
            girlMagicCutCamera(D_overlay_29_01D00FD8->segment.trans.x_position,
                               D_overlay_29_01D00FD8->segment.trans.y_position,
                               D_overlay_29_01D00FD8->segment.trans.z_position,
                               75.0f, 400.0f, (s16) mathRnd(0, 0x10000), 4.0f);
            amSndPlay(0xF1, 0);
        }
        break;
    case 4:
        if (D_overlay_29_01D00FD0 != 0) {
            timer = D_overlay_29_01D00FD0 - arg2;
            D_overlay_29_01D00FD0 = timer;
            if (timer < 0) {
                D_overlay_29_01D00FD0 = 0;
                timer = 0;
            }
            if (D_overlay_29_01D00FDC != NULL) {
                frac = (f32) timer / 60.0f;
                dx = D_overlay_29_01D00FD8->segment.trans.x_position;
                hitY = D_overlay_29_01D00FD8->segment.trans.y_position;
                dz = D_overlay_29_01D00FD8->segment.trans.z_position;
                objMoveXYZ(D_overlay_29_01D00FDC,
                           (dx + ((D_overlay_29_01D00FE0 - dx) * frac)) - D_overlay_29_01D00FDC->segment.trans.x_position,
                           (hitY + ((D_overlay_29_01D00FE4 - hitY) * frac)) - D_overlay_29_01D00FDC->segment.trans.y_position,
                           (dz + ((D_overlay_29_01D00FE8 - dz) * frac)) - D_overlay_29_01D00FDC->segment.trans.z_position);
                *(s32 *)((u8 *)D_overlay_29_01D00FDC + 0x84) = 1;
                partUpdateTriggers(D_overlay_29_01D00FDC, arg2);
                timer = D_overlay_29_01D00FD0;
            }
            if (timer == 0) {
                tgt = *(ObjectTransform **)((u8 *)D_overlay_29_01D00FD8 + 0x4C);
                tgt->unk6 = (s16) (tgt->unk6 - 0x5000);
                *(s32 *)((u8 *)tgt + 0x3C) = 0;
                explosionStart(0xC, (s16) (s32) D_overlay_29_01D00FD8->segment.trans.x_position,
                               (s16) (s32) (D_overlay_29_01D00FD8->segment.trans.y_position + 8.0f),
                               (s16) (s32) D_overlay_29_01D00FD8->segment.trans.z_position, 0xF, arg0);
                amSndPlayXYZ(0x22, D_overlay_29_01D00FD8->segment.trans.x_position,
                             D_overlay_29_01D00FD8->segment.trans.y_position,
                             D_overlay_29_01D00FD8->segment.trans.z_position, 4, 0);
                D_overlay_29_01D00FD4 = 0x78;
                if (D_overlay_29_01D00FDC != NULL) {
                    D_overlay_29_01D00FDC->segment.trans.unk6 = (s16) (D_overlay_29_01D00FDC->segment.trans.unk6 | 0x400);
                }
            }
        } else {
            timer = D_overlay_29_01D00FD4 - arg2;
            D_overlay_29_01D00FD4 = timer;
            if (timer <= 0) {
                state[0x19D] = 3;
            }
        }
        break;
    case 5:
        timer = D_overlay_29_01D00FD4 - arg2;
        D_overlay_29_01D00FD4 = timer;
        if (timer <= 0) {
            state[0x19D] = 0;
            if (D_overlay_29_01D00FDC != NULL) {
                objFreeObject(D_overlay_29_01D00FDC);
            }
        }
        break;
    }
    girlMagicUpdateFog(arg2);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o29/overlay_29/girlUpdateMagic.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void girlMagicCameraInit(Object *arg0) {
    ObjectTransform *cam;
    f32 dx;
    f32 dz;

    cam = camGetListPtr();
    D_overlay_29_01D00FEC = arg0->segment.trans.x_position;
    D_overlay_29_01D00FF0 = arg0->segment.trans.y_position + 45.0f;
    D_overlay_29_01D00FF4 = arg0->segment.trans.z_position;
    dx = cam->x_position - D_overlay_29_01D00FEC;
    dz = cam->z_position - D_overlay_29_01D00FF4;
    D_overlay_29_01D00FF8 = sqrtf((dx * dx) + (dz * dz));
    D_overlay_29_01D00FFC = 0.0f;
    D_overlay_29_01D01000 = (s16) (0x8000 - Arctanf(dx, dz));
    D_overlay_29_01D01002 = 0;
    D_overlay_29_01D00F94 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o29/overlay_29/girlMagicCameraInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void girlMagicCamera(ObjectTransform *arg0, s32 arg1, s32 arg2) {
    s32 timer;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 fadeLeft;
    f32 curX;
    f32 curY;
    f32 sweep;
    f32 cosA;
    f32 offZ;
    f32 easeA;
    s16 angY;
    u16 angX;

    timer = D_overlay_29_01D00F94;
    if (timer > 0) {
        timer -= arg2;
        D_overlay_29_01D00F94 = timer;
        if (timer <= 0) {
            arg0->y_rotation = D_overlay_29_01D01004;
            timer = 0;
            arg0->x_rotation = D_overlay_29_01D01006;
            D_overlay_29_01D00F94 = 0;
        } else {
            arg0->x_position = D_overlay_29_01D01008;
            arg0->y_position = D_overlay_29_01D0100C;
            arg0->z_position = D_overlay_29_01D01010;
            if (D_overlay_29_01D00FDC != NULL) {
                dy = controlcam->y_position - D_overlay_29_01D00FDC->segment.trans.y_position;
                dx = controlcam->x_position - D_overlay_29_01D00FDC->segment.trans.x_position;
                dz = controlcam->z_position - D_overlay_29_01D00FDC->segment.trans.z_position;
                arg0->y_rotation = (s16) (0x8000 - Arctanf(dx, dz));
                arg0->x_rotation = (s16) Arctanf(dy, sqrtf((dx * dx) + (dz * dz)));
            } else {
                arg0->y_rotation = D_overlay_29_01D01014;
                arg0->x_rotation = D_overlay_29_01D01016;
            }
        }
    }
    if (timer <= 0) {
        curX = D_overlay_29_01D00FF8;
        curY = D_overlay_29_01D00FFC;
        fadeLeft = 1.0f - Powerf(D_overlay_29_01D00FC8, arg2);
        D_overlay_29_01D00FF8 = curX + ((100.0f - curX) * fadeLeft);
        D_overlay_29_01D00FFC = curY + ((180.0f - curY) * fadeLeft);
        D_overlay_29_01D01002 += arg2 * 0x1F;
        if (D_overlay_29_01D01002 >= 0x110) {
            D_overlay_29_01D01002 = 0x10F;
        }
        D_overlay_29_01D01000 += D_overlay_29_01D01002 * arg2;
        /* m2c resolved this callee as Sinf with a 6-arg signature; sig mismatch */
        sweep = ((f32 (*)(f32, f32, s16, f32 *, f32 *, s32))Sinf)(curX, curY, D_overlay_29_01D01000,
                                                                  &D_overlay_29_01D00FF8, &D_overlay_29_01D00FFC, arg2)
                * D_overlay_29_01D00FF8;
        cosA = Cosf((s32) D_overlay_29_01D01000);
        arg0->x_position = (f32) (D_overlay_29_01D00FEC + sweep);
        offZ = -cosA * D_overlay_29_01D00FF8;
        arg0->y_position = (f32) (D_overlay_29_01D00FF0 + D_overlay_29_01D00FFC);
        arg0->z_position = (f32) (D_overlay_29_01D00FF4 + offZ);
        angY = (s16) (0x8000 - Arctanf(sweep, offZ));
        angX = Arctanf(D_overlay_29_01D00FFC, D_overlay_29_01D00FF8);
        easeA = 1.0f - Powerf(0.875f, arg2);
        arg0->y_rotation = dAngle(arg0->y_rotation, angY, easeA);
        arg0->x_rotation = dAngle(arg0->x_rotation, (s16) angX, easeA);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o29/overlay_29/girlMagicCamera.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void girlMagicCutCamera(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, s16 arg5, f32 arg6) {
    ObjectTransform *cam;
    f32 offX;
    f32 offZ;

    cam = camGetListPtr();
    offX = Sinf(arg5) * arg3;
    offZ = -Cosf((s32) arg5) * arg3;
    D_overlay_29_01D01008 = arg0 + offX;
    D_overlay_29_01D0100C = arg1 + arg4;
    D_overlay_29_01D01010 = arg2 + offZ;
    D_overlay_29_01D01014 = (s16) (0x8000 - Arctanf(offX, offZ));
    D_overlay_29_01D01016 = (s16) Arctanf(arg4, arg3);
    D_overlay_29_01D01018 = cam->y_rotation;
    D_overlay_29_01D0101A = cam->x_rotation;
    D_overlay_29_01D00F94 = (s32) (arg6 * 60.0f);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o29/overlay_29/girlMagicCutCamera.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void girlMagicFadeFog(f32 arg0, f32 arg1) {
    s32 frames;

    D_overlay_29_01D00F9C = D_overlay_29_01D00F98;
    D_overlay_29_01D00FA0 = arg0;
    frames = (s32) (arg1 * 60.0f);
    D_overlay_29_01D00FA4 = frames;
    D_overlay_29_01D00FA8 = frames;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o29/overlay_29/girlMagicFadeFog.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void girlMagicUpdateFog(s32 arg0) {
    s32 remaining;

    D_overlay_29_01D00F98 = D_overlay_29_01D00FA0;
    if (arg0 < D_overlay_29_01D00FA8) {
        remaining = D_overlay_29_01D00FA8 - arg0;
        D_overlay_29_01D00FA8 = remaining;
        D_overlay_29_01D00F98 += (D_overlay_29_01D00F9C - D_overlay_29_01D00FA0)
                                 * ((f32) remaining / (f32) D_overlay_29_01D00FA4);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o29/overlay_29/girlMagicUpdateFog.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void girlMagicFog(u8 *arg0, s8 *arg1, s8 *arg2, s16 *arg3, s16 *arg4, s8 *arg5) {
    f32 keep;
    f32 v;

    if (D_overlay_29_01D00F98 != 0.0f) {
        keep = 1.0f - D_overlay_29_01D00F98;
        *arg0 = (u8) (s32) ((f32) *arg0 * keep);
        v = (f32) *arg1;
        if ((s32) *arg1 < 0) {
            v += 4294967296.0f;
        }
        *arg1 = (s8) (s32) (v * keep);
        v = (f32) *arg2;
        if ((s32) *arg2 < 0) {
            v += 4294967296.0f;
        }
        *arg2 = (s8) (s32) (v * keep);
        *arg3 = *arg3 + (s32) ((f32) (0x3D9 - *arg3) * D_overlay_29_01D00F98);
        *arg4 = *arg4 + (s32) ((f32) (0x3FC - *arg4) * D_overlay_29_01D00F98);
        *arg5 = (s8) (s32) ((f32) *arg5 * keep);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o29/overlay_29/girlMagicFog.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void girlMagicTrackFade(s32 *arg0, s32 *arg1, s32 *arg2) {
    if (D_overlay_29_01D00F98 != 0.0f) {
        *arg0 = *arg0 + (s32) ((f32) (0x40 - *arg0) * D_overlay_29_01D00F98);
        *arg1 = *arg1 + (s32) ((f32) (0x40 - *arg1) * D_overlay_29_01D00F98);
        *arg2 = *arg2 + (s32) ((f32) (0x40 - *arg2) * D_overlay_29_01D00F98);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o29/overlay_29/girlMagicTrackFade.s")
#endif
