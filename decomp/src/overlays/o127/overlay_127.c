#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern f32 D_overlay_127_07F01174;
extern f32 D_overlay_127_07F011BC;
extern f32 D_overlay_127_07F011C0;
extern f32 D_overlay_127_07F011D0;
extern f32 D_overlay_127_07F011D4;
extern f32 D_overlay_127_07F011D8;
extern f32 D_overlay_127_07F011DC;
extern f32 D_overlay_127_07F011E0;
extern f32 D_overlay_127_07F011E4;
extern f32 D_overlay_127_07F011E8;
extern f32 D_overlay_127_07F011EC;
extern s16 D_overlay_127_07F011F0;
extern s16 D_overlay_127_07F011F2;
extern s16 D_overlay_127_07F011F4;
extern s16 D_overlay_127_07F011F6;
extern f32 D_overlay_127_07F011F8;
extern f32 D_overlay_127_07F011FC;
extern s16 D_overlay_127_07F01200;
extern f32 D_overlay_127_07F01204;
extern f32 D_overlay_127_07F01208;
extern s16 D_overlay_127_07F0120C;
extern f32 D_overlay_127_07F01210;
extern f32 D_overlay_127_07F01214;
extern s32 D_overlay_127_07F01218;
void *camGetPtr(void);
f32 Sinf(s16 angle);
f32 Powerf(f32 base, s32 n);
s16 dAngle(s16 a, s16 b, f32 c);
void *objGetPlayerNo(s32 n);
void objFreeObject(void *obj);
void objAnimDframe(void *obj, f32 a, f32 b);
void objAnimSetMove(void *obj, s32 anim, f32 speed);
void partUpdateTriggers(void *obj, s32 arg1, void *arg2);
void mainPauseDisable(s32 n);
void hinttextStart(u8 id, s32 arg, void *obj);
void hinttextStop(void);
s32 hinttextActive(void);
void amSndPlay(s32 id, void *handle);
void amSndStop(s32 handle);
void mathOneFloatPY(f32 a, void *obj, f32 *out, s32 n);
void objMoveXYZ(void *obj, f32 x, f32 y, f32 z);
void objMoveXYZnocheck(void);
void *objGetObjList(s32 *start, s32 *count);
void terminalCameraInit(void *arg0);
void func_overlay_127_07F00FA0_1FCCBF0(void *arg0, s32 arg1);
extern f32 D_overlay_127_07F01190;
extern f32 D_overlay_127_07F01194;
extern f32 D_overlay_127_07F01198;
extern f32 D_overlay_127_07F0119C;
extern f32 D_overlay_127_07F011A0;
extern f32 D_overlay_127_07F011A4;
extern f32 D_overlay_127_07F011A8;
extern f32 D_overlay_127_07F011AC;
extern f32 D_overlay_127_07F011B0;
extern f32 D_overlay_127_07F011B4;
extern f32 D_overlay_127_07F011B8;
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_127_07F00000_1FCBC50(void *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 *arg5) {
    *arg2 = *(f32 *)((u8 *)arg0 + 0xC);
    *arg3 = *(f32 *)((u8 *)arg0 + 0x10);
    *arg4 = *(f32 *)((u8 *)arg0 + 0x14);
    *arg5 = D_overlay_127_07F01174;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o127/overlay_127/func_overlay_127_07F00000_1FCBC50.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void terminalInit(void *arg0, void *arg1) {
    u8 *state;
    u8 *setup;

    state = *(u8 **)((u8 *)arg0 + 0x68);
    setup = (u8 *)arg1;
    *(s16 *)arg0 = (s16)(setup[0xB] << 8);
    state[0x0] = 0;
    *(s16 *)(state + 0x2) = 0;
    *(s32 *)(state + 0x8) = 0;
    *(s32 *)(state + 0xC) = 0;
    *(s32 *)(state + 0x10) = 0;
    *(s32 *)(state + 0x1C) = 0;
    state[0x1] = setup[0xA];
    *(f32 *)(state + 0x18) = 0.0f;
    *(f32 *)(state + 0x14) = 0.0f;
    objAnimSetMove(arg0, 0, 0.0f);
    objAnimSetMove(arg0, 0, 0.0f);
    hitInitObjectHit(arg0, -1, 0, 8, 0, 0, 0, 4.0f, 4.0f, -1.0f, 1.0f, 1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o127/overlay_127/terminalInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Object state (obj+0x68): +0x0 mode u8, +0x1 hint id u8, +0x2 timer s16, +0x4 f32 anim,
// +0x8 child obj ptr, +0xC/+0x10 s32 accumulators, +0x14/+0x18 f32 velocities, +0x1C snd handle.
// Player obj: +0x1F9 u8 flag, +0x68 player state.
// Child obj (type 0x7E): +0x0/+0x2/+0x4 s16 angles, +0x6 s16 flags, +0x48 s16 type,
// +0x84 s32 flag, +0x88 s32 phase, +0x8C s32 timer.
void terminalControl(void *arg0, s32 arg1) {
    u8 *obj;
    u8 *player;
    u8 *playerState;
    u8 *state;
    u8 *child;
    u8 **objList;
    s32 start;
    s32 count;
    s32 snd;
    s32 n;
    s32 t3;
    s32 v0;
    s32 v1;
    s32 t7;
    s32 mode;
    s32 doMove;
    s16 yawDiff;
    f32 px;
    f32 py;
    f32 pz;
    f32 range;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 off[3];
    f32 rate;
    f32 frame;

    obj = (u8 *)arg0;
    player = (u8 *)objGetPlayerNo(0);
    if (player == NULL) {
        objFreeObject(arg0);
        return;
    }
    state = *(u8 **)(obj + 0x68);
    playerState = *(u8 **)(player + 0x68);
    *(s32 *)(obj + 0x84) = 0;
    switch (state[0x0]) {
    case 0:
        if (joyGetPressed(0) & 0x8000) {
            func_overlay_127_07F00000_1FCBC50(arg0, (s32)playerState, &px, &py, &pz, &range);
            dx = px - *(f32 *)(player + 0xC);
            dy = py - *(f32 *)(player + 0x10);
            dz = pz - *(f32 *)(player + 0x14);
            yawDiff = (s16)((*(s16 *)(player + 0x0) - *(s16 *)(obj + 0x0)) - 0x8000);
            if (((dx * dx) + (dz * dz)) < range) {
                if ((dy >= -8.0f) && (dy <= 8.0f)) {
                    if ((yawDiff >= -0x1555) && (yawDiff < 0x1556)) {
                        state[0x0] = 1;
                        terminalCameraInit(arg0);
                        mainPauseDisable(0xA);
                        playerState[0x1F9] = 2;
                        objAnimSetMove(arg0, 0, 0.0f);
                    }
                }
            }
        }
        break;
    case 1:
        mainPauseDisable(0xA);
        objAnimDframe(arg0, 0.0084f, (f32)arg1);
        if (*(f32 *)(obj + 0x28) == 1.0f) {
            state[0x0] = 2;
            *(s16 *)(state + 0x2) = 0x78;
            *(f32 *)(state + 0x4) = D_overlay_127_07F01190;
            objAnimSetMove(arg0, 1, 0.0f);
        }
        break;
    case 2:
        mainPauseDisable(0xA);
        frame = (f32)arg1;
        objAnimDframe(arg0, *(f32 *)(state + 0x4), frame);
        *(f32 *)(state + 0x4) = *(f32 *)(state + 0x4) + (D_overlay_127_07F01198 * frame);
        if (D_overlay_127_07F01194 < *(f32 *)(state + 0x4)) {
            *(f32 *)(state + 0x4) = D_overlay_127_07F01194;
        }
        if (D_overlay_127_07F0119C < *(f32 *)(state + 0x4)) {
            *(s32 *)(obj + 0x84) = 1;
            if (*(s32 *)(state + 0x1C) == 0) {
                amSndPlay(0x1BE, state + 0x1C);
            }
        }
        *(s16 *)(state + 0x2) = (s16)(*(s16 *)(state + 0x2) - arg1);
        if (*(s16 *)(state + 0x2) <= 0) {
            snd = *(s32 *)(state + 0x1C);
            state[0x0] = 3;
            *(s16 *)(state + 0x2) = 0x80;
            *(s32 *)(state + 0xC) = 0;
            *(s32 *)(state + 0x10) = 0xFF;
            if (snd != 0) {
                amSndStop(snd);
            }
            amSndPlay(0x1BF, NULL);
        }
        break;
    case 3:
        mainPauseDisable(0xA);
        frame = (f32)arg1;
        objAnimDframe(arg0, *(f32 *)(state + 0x4), frame);
        *(f32 *)(state + 0x4) = *(f32 *)(state + 0x4) - (D_overlay_127_07F011A4 * frame);
        if (*(f32 *)(state + 0x4) < D_overlay_127_07F011A0) {
            *(f32 *)(state + 0x4) = D_overlay_127_07F011A0;
        }
        if (D_overlay_127_07F011A8 < *(f32 *)(state + 0x4)) {
            *(s32 *)(obj + 0x84) = 1;
        }
        *(s16 *)(state + 0x2) = (s16)(*(s16 *)(state + 0x2) - arg1);
        if (*(s16 *)(state + 0x2) <= 0) {
            state[0x0] = 4;
            hinttextStart(state[0x1], 0, arg0);
        }
        break;
    case 4:
        mainPauseDisable(0xA);
        objAnimDframe(arg0, *(f32 *)(state + 0x4), (f32)arg1);
        if (joyGetPressed(0) & 0x1000) {
            hinttextStop();
        }
        if (hinttextActive() == 0) {
            state[0x0] = 5;
            objAnimSetMove(arg0, 2, 1.0f);
            D_overlay_127_07F01204 = D_overlay_127_07F011E8;
            D_overlay_127_07F01208 = D_overlay_127_07F011EC;
            D_overlay_127_07F0120C = D_overlay_127_07F011F0;
            D_overlay_127_07F01210 = D_overlay_127_07F011AC;
            D_overlay_127_07F01214 = D_overlay_127_07F011B0;
            D_overlay_127_07F01218 = 0;
            *(f32 *)(state + 0x18) = 0.0f;
            *(f32 *)(state + 0x14) = 0.0f;
            amSndPlay(0x1BF, NULL);
        }
        break;
    case 5:
        mainPauseDisable(0xA);
        objAnimDframe(arg0, -0.0084f, (f32)arg1);
        if (*(f32 *)(obj + 0x28) == 0.0f) {
            state[0x0] = 0;
            playerState[0x1F9] = 0;
        }
        break;
    }
    partUpdateTriggers(arg0, arg1, arg0);
    child = *(u8 **)(state + 0x8);
    if (child != NULL) {
        mode = state[0x0];
        if ((mode == 3) || (mode == 4)) {
            *(s16 *)(child + 0x2) = -0x800;
            *(s16 *)(child + 0x4) = 0;
            *(s32 *)(child + 0x84) = 0;
            *(s16 *)(child + 0x0) = *(s16 *)(obj + 0x0);
            if (*(s32 *)(state + 0x10) > 0) {
                t3 = arg1 * 2;
                if (t3 != 0) {
                    n = t3;
                    do {
                        v1 = *(s32 *)(state + 0xC);
                        if (v1 < 0xC000) {
                            *(s32 *)(state + 0xC) = v1 + 0x100;
                            *(s32 *)(child + 0x84) = 1;
                        } else {
                            v0 = *(s32 *)(state + 0x10);
                            if (v0 > 0) {
                                *(s32 *)(state + 0xC) = v1 + v0;
                                *(s32 *)(state + 0x10) = v0 - 2;
                            }
                        }
                    } while (--n != 0);
                }
                off[0] = Sinf(*(s32 *)(state + 0xC)) * -85.0f;
                off[1] = (Cosf((*(s32 *)(state + 0xC) * 3) >> 2) * 55.0f) + 100.0f;
                off[2] = (Cosf(*(s32 *)(state + 0xC)) * 85.0f) + -35.0f;
                rate = 0.0f;
                *(s16 *)(child + 0x0) = (s16)((*(s16 *)(child + 0x0) - *(s32 *)(state + 0xC))
                                              + (*(s32 *)(state + 0x10) << 6));
                *(s16 *)(child + 0x4) = (s16)(*(s16 *)(child + 0x4) - (*(s32 *)(state + 0x10) * 0x10));
            } else {
                objAnimDframe(child, -0.0167f, (f32)arg1);
                off[0] = 0.0f;
                off[1] = (Sinf(*(s32 *)(child + 0x88)) * 8.0f) + 100.0f;
                off[2] = 50.0f;
                rate = D_overlay_127_07F011B4;
            }
            t7 = *(s32 *)(child + 0x8C) + (arg1 * 4);
            *(s16 *)(child + 0x6) = (s16)(*(s16 *)(child + 0x6) & 0xFBFF);
            *(s32 *)(child + 0x88) = *(s32 *)(child + 0x88) + (arg1 << 8);
            *(s32 *)(child + 0x8C) = t7;
            if (t7 >= 0x100) {
                *(s32 *)(child + 0x8C) = 0xFF;
            }
            ((void (*)(void *, s32))partUpdateTriggers)(child, arg1); /* sig mismatch: 2-arg call site */
            doMove = 1;
        } else if (*(s32 *)(child + 0x8C) != 0) {
            frame = (f32)arg1;
            if (arg1 != 0) {
                n = arg1;
                do {
                    *(f32 *)(state + 0x14) = *(f32 *)(state + 0x14) + D_overlay_127_07F011B8;
                    *(f32 *)(state + 0x18) = *(f32 *)(state + 0x18) + *(f32 *)(state + 0x14);
                    *(s16 *)(child + 0x2) = (s16)(*(s16 *)(child + 0x2) + 0x40);
                    if (*(s16 *)(child + 0x2) >= 0x4001) {
                        *(s16 *)(child + 0x2) = 0x4000;
                    }
                    if (*(f32 *)(state + 0x18) > 5.0f) {
                        *(f32 *)(state + 0x18) = 5.0f;
                    }
                } while (--n != 0);
            }
            off[2] = -*(f32 *)(state + 0x18) * frame;
            mathOneFloatPY(frame, child, off, arg1);
            objMoveXYZnocheck();
            objMoveXYZ(child, off[0], off[1], off[2]);
            t7 = *(s32 *)(child + 0x8C) - (arg1 * 2);
            *(s32 *)(child + 0x8C) = t7;
            if (t7 <= 0) {
                *(s32 *)(child + 0x8C) = 0;
                *(s16 *)(child + 0x6) = (s16)(*(s16 *)(child + 0x6) | 0x400);
            }
            *(s32 *)(child + 0x84) = 1;
            ((void (*)(void *, s32))partUpdateTriggers)(child, arg1); /* sig mismatch: 2-arg call site */
            doMove = 0;
            objAnimDframe(child, 0.0167f, frame);
        } else {
            *(s32 *)(child + 0x88) = 0;
            *(s32 *)(child + 0x8C) = 0;
            doMove = 0;
            *(f32 *)(child + 0x28) = 1.0f;
        }
        if (doMove != 0) {
            pointListRPY(1, (s16 *)arg0, (s32 *)off, off);
            px = off[0] + *(f32 *)(obj + 0xC);
            py = off[1] + *(f32 *)(obj + 0x10);
            pz = off[2] + *(f32 *)(obj + 0x14);
            rate = 1.0f - Powerf(rate, arg1);
            objMoveXYZnocheck();
            objMoveXYZ(child, (px - *(f32 *)(child + 0xC)) * rate,
                       (py - *(f32 *)(child + 0x10)) * rate,
                       (pz - *(f32 *)(child + 0x14)) * rate);
        }
    } else {
        objList = (u8 **)objGetObjList(&start, &count);
        if (start < count) {
loop_73:
            child = objList[start];
            start += 1;
            if (*(s16 *)(child + 0x48) == 0x7E) {
                *(u8 **)(state + 0x8) = child;
                *(s32 *)(child + 0x8C) = 0;
            } else if (start < count) {
                goto loop_73;
            }
        }
    }
    func_overlay_127_07F00FA0_1FCCBF0(arg0, arg1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o127/overlay_127/terminalControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void terminalCameraInit(void *arg0) {
    u8 *obj;
    u8 *cam;
    f32 vec[3];
    f32 dx;
    f32 dy;
    f32 dz;

    obj = (u8 *)arg0;
    cam = camGetPtr();
    vec[0] = 0.0f;
    vec[1] = 70.0f;
    vec[2] = -40.0f;
    pointListRPY(1, (s16 *)arg0, (s32 *)vec, vec);
    D_overlay_127_07F011DC = vec[0] + *(f32 *)(obj + 0xC);
    D_overlay_127_07F011E0 = vec[1] + *(f32 *)(obj + 0x10);
    D_overlay_127_07F011E4 = vec[2] + *(f32 *)(obj + 0x14);
    vec[0] = 0.0f;
    vec[1] = 0.0f;
    vec[2] = 0.0f;
    pointListRPY(1, (s16 *)arg0, (s32 *)vec, vec);
    D_overlay_127_07F011D0 = vec[0] + *(f32 *)(obj + 0xC);
    D_overlay_127_07F011D4 = vec[1] + *(f32 *)(obj + 0x10);
    D_overlay_127_07F011D8 = vec[2] + *(f32 *)(obj + 0x14);
    dx = *(f32 *)(cam + 0xC) - D_overlay_127_07F011D0;
    dy = *(f32 *)(cam + 0x10) - D_overlay_127_07F011D4;
    dz = *(f32 *)(cam + 0x14) - D_overlay_127_07F011D8;
    D_overlay_127_07F011E8 = sqrtf((dx * dx) + (dz * dz));
    D_overlay_127_07F011EC = dy;
    D_overlay_127_07F011F0 = (s16)(0x8000 - Arctanf(dx, dz));
    D_overlay_127_07F011F2 = *(s16 *)(cam + 0x0);
    D_overlay_127_07F011F4 = *(s16 *)(cam + 0x2);
    D_overlay_127_07F011F6 = *(s16 *)(cam + 0x4);
    D_overlay_127_07F011F8 = D_overlay_127_07F011E8;
    D_overlay_127_07F011FC = D_overlay_127_07F011EC;
    D_overlay_127_07F01200 = D_overlay_127_07F011F0;
    D_overlay_127_07F01204 = 200.0f;
    D_overlay_127_07F01208 = 100.0f;
    D_overlay_127_07F0120C = (s16)(0x2800 - *(s16 *)obj);
    D_overlay_127_07F01210 = D_overlay_127_07F011BC;
    D_overlay_127_07F01214 = D_overlay_127_07F011C0;
    D_overlay_127_07F01218 = 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o127/overlay_127/terminalCameraInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void terminalCameraUpdate(void *arg0, s32 arg1) {
    u8 *obj;
    s16 sp36;
    s16 sp32;
    s16 var_s0;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 rate;
    f32 dx;
    f32 dz;

    obj = (u8 *)arg0;
    rate = 1.0f - Powerf(D_overlay_127_07F01210, arg1);
    dx = D_overlay_127_07F011F8;
    dz = D_overlay_127_07F011FC;
    D_overlay_127_07F011F8 = dx + ((D_overlay_127_07F01204 - dx) * rate);
    D_overlay_127_07F011FC = dz + ((D_overlay_127_07F01208 - dz) * rate);
    D_overlay_127_07F01200 = dAngle(D_overlay_127_07F01200, D_overlay_127_07F0120C, rate);
    Sinf(D_overlay_127_07F01200); /* asm: result unused */
    Cosf((s32)D_overlay_127_07F01200); /* asm: result unused */
    *(f32 *)(obj + 0xC) = (Sinf(D_overlay_127_07F01200) * D_overlay_127_07F011F8) + D_overlay_127_07F011D0;
    *(f32 *)(obj + 0x10) = D_overlay_127_07F011D4 + D_overlay_127_07F011FC;
    *(f32 *)(obj + 0x14) = D_overlay_127_07F011D8 - (Cosf((s32)D_overlay_127_07F01200) * D_overlay_127_07F011F8);
    if (D_overlay_127_07F01218 != 0) {
        dx = *(f32 *)(obj + 0xC) - D_overlay_127_07F011DC;
        sp28 = *(f32 *)(obj + 0x10) - D_overlay_127_07F011E0;
        sp2C = dx;
        dz = *(f32 *)(obj + 0x14) - D_overlay_127_07F011E4;
        sp24 = dz;
        sp32 = (s16)(0x8000 - Arctanf(dx, dz));
        var_s0 = (s16)Arctanf(sp28, sqrtf((sp2C * sp2C) + (dz * dz)));
        sp36 = 0;
    } else {
        var_s0 = D_overlay_127_07F011F4;
        sp32 = D_overlay_127_07F011F2;
        sp36 = D_overlay_127_07F011F6;
    }
    rate = 1.0f - Powerf(D_overlay_127_07F01214, arg1);
    sp20 = rate;
    *(s16 *)(obj + 0x0) = dAngle(*(s16 *)(obj + 0x0), sp32, rate);
    *(s16 *)(obj + 0x2) = dAngle(*(s16 *)(obj + 0x2), var_s0, sp20);
    *(s16 *)(obj + 0x4) = dAngle(*(s16 *)(obj + 0x4), sp36, sp20);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o127/overlay_127/terminalCameraUpdate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_127_07F00FA0_1FCCBF0(void *arg0, s32 arg1) {
    s32 sp14; /* asm: uninitialised stack slot 0x14, read as the initial var_s0 */
    u8 *state;
    u8 *ctx;
    u8 *hdr;
    u8 *tbl;
    u8 *entry;
    u8 *rec;
    u8 *rec8;
    s32 mask;
    s32 count;
    s32 n;
    s32 n1;
    s32 n2;
    s32 t4;
    s32 var_s0;
    s16 start;
    s16 t5;
    s16 t5_2;
    s16 t5_3;
    s16 t3;
    s16 minv;
    s16 s1;
    u8 cnt2;

    state = *(u8 **)((u8 *)arg0 + 0x68);
    ctx = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x6C));
    hdr = *(u8 **)ctx;
    tbl = *(u8 **)(*(u8 **)(hdr + 0x18) + 0x38);
    mask = (tbl[1] << 5) - 1;
    count = *(s16 *)(hdr + 0x16);
    entry = *(u8 **)(hdr + 0x24);
    var_s0 = sp14;
    if (count != 0) {
        n = count - 1;
        do {
            if (entry[0] == 7) {
                start = *(s16 *)(entry + 0x8);
                t4 = *(s16 *)(entry + 0x18) - start;
                rec = *(u8 **)(hdr + 0x20) + (start * 0x10);
                if (t4 != 0) {
                    n1 = t4 - 1;
                    do {
                        if (*state == 0) {
                            t5 = *(s16 *)(rec + 0x6);
                            *(s16 *)(rec + 0x6) = (s16)((t5 + (arg1 * 0x10)) & mask);
                            var_s0 = *(s16 *)(rec + 0xE) - t5;
                            t5_2 = *(s16 *)(rec + 0x6);
                            *(s16 *)(rec + 0xA) = (s16)(t5_2 + (*(s16 *)(rec + 0xA) - t5));
                            *(s16 *)(rec + 0xE) = (s16)(t5_2 + var_s0);
                        } else {
                            t5_3 = *(s16 *)(rec + 0x6);
                            t3 = *(s16 *)(rec + 0xA);
                            minv = t5_3;
                            if (t3 < t5_3) {
                                minv = t3;
                            }
                            s1 = *(s16 *)(rec + 0xE);
                            if (s1 < var_s0) {
                                var_s0 = s1;
                            }
                            *(s16 *)(rec + 0x6) = (s16)(t5_3 - minv);
                            *(s16 *)(rec + 0xA) = (s16)(t3 - minv);
                            *(s16 *)(rec + 0xE) = (s16)(s1 - minv);
                        }
                        rec += 0x10;
                    } while (n1-- != 0); /* asm: counter decremented in bnez delay slot */
                }
            }
            entry += 0x10;
        } while (n-- != 0); /* asm: counter decremented in bnez delay slot */
        sp14 = var_s0;
    }
    cnt2 = hdr[0x2C];
    if (cnt2 != 0) {
        rec8 = *(u8 **)(ctx + 0x74);
        n2 = cnt2 - 1;
        do {
            if ((*(u32 *)(rec8 + 0x4) & 0xFF) == 7) {
                if (*state == 0) {
                    *(s16 *)rec8 = 0;
                } else {
                    *(s16 *)rec8 = 0x100;
                }
            }
            rec8 += 0x8;
        } while (n2-- != 0); /* asm: counter decremented in bnez delay slot */
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o127/overlay_127/func_overlay_127_07F00FA0_1FCCBF0.s")
#endif
