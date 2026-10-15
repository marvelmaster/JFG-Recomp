#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
Object **objGetObjList(s32 *start, s32 *end);
void objFreeObject(void *obj);
s16 objTvTimes(s32 timer);
void hitInitObjectHit(void *obj, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, f32 f0, f32 f1, f32 f2, f32 f3, s32 a11);
s32 GetAutoAimTarget(s32 arg0, u8 *arg1);
void objRegisterDependancy(void *obj, void *target);
void *GetBaddyData(void *obj);
void SquaddieLightAndAnimate(s32 arg0, void *arg1, s32 arg2);
void mathMtxCatF(f32 (*a)[4], f32 (*b)[4], f32 (*out)[4]);
void matrix_SCL_RPY_XYZ(void *obj, f32 (*mtx)[4]);
void matrixYaw(s16 angle, f32 (*mtx)[4]);
void camPushFloatModelMtx(void **arg0, void **arg1, f32 (*arg2)[4]);
void runlinkSetDestructTimer(s32 module, s32 a1, s32 a2);
void hitBridgeMoveWith(Object *obj, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6);
void trackMakePolylist(s32 a0, void *a1, void *a2, void *a3, s32 a4, s32 a5, s32 a6);
s32 trackGetIntersect(void *a0, void *a1, void *a2, s32 a3, s32 a4, void **out);
void objMoveXYZ(void *obj, f32 x, f32 y, f32 z);
void objRemoveDependancy(void *obj, s32 target);
void partUpdateTriggers(void *obj, s32 a1, f32 *a2);
void amSndPlayXYZ(s32 sfx, f32 x, f32 y, f32 z, s32 a4, s32 a5);
f32 GetRange(f32 x0, f32 y0, f32 z0, f32 x1, f32 y1, f32 z1);
s16 mathDiffAngle(s16 a, s16 b);
f32 Sinf(s16 angle);
void ShirukenBounce(Object *arg0, void *arg1);
extern s32 __MODULE00122;
extern f32 D_overlay_122_07A010D4;
extern f32 D_overlay_122_07A010D8;
extern f32 D_overlay_122_07A010DC;
extern f32 D_overlay_122_07A010E0;
extern f32 D_overlay_122_07A010E4;
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void ShirukenInit(Object *arg0, void *arg1) {
    u8 *state;
    Object **objList;
    Object *cand;
    Object *best;
    s32 start;
    s32 end;
    s32 i;
    s32 count;
    u32 bestVal;
    u32 val;
    u8 aimFlag;
    s32 target;
    u8 *flags;

    state = *(u8 **)((u8 *)arg0 + 0x68);
    objList = objGetObjList(&start, &end);
    count = 0;
    bestVal = 0;
    best = NULL; /* asm: best is an uninitialised stack slot when no candidate qualifies */
    for (i = start; i < end; i++) {
        cand = objList[i];
        if (cand->behaviorId == 0x99 && *((u8 *)cand + 0xA0) == 0) {
            count++;
            val = *(u32 *)(*(u8 **)((u8 *)cand + 0x68) + 0x84);
            if (bestVal < val) {
                best = cand;
                bestVal = val;
            }
        }
    }
    if (count >= 0xB) {
        objFreeObject(best);
    }
    state[0x82] = 2;
    *(f32 *)(state + 0x8) = arg0->segment.trans.x_position;
    *(f32 *)(state + 0xC) = arg0->segment.trans.y_position;
    *(f32 *)(state + 0x10) = arg0->segment.trans.z_position;
    *(s16 *)(state + 0x74) = 0;
    *(f32 *)(state + 0x14) = 0.0f;
    *(f32 *)(state + 0x18) = 0.0f;
    *(f32 *)(state + 0x1C) = 0.0f;
    *(f32 *)(state + 0x24) = 0.0f;
    *(f32 *)(state + 0x28) = 0.0f;
    *(s32 *)(state + 0x0) = *(s32 *)((u8 *)arg1 + 0xC);
    *(s16 *)(state + 0x80) = objTvTimes(0x258);
    *(s32 *)(state + 0x84) = 0;
    hitInitObjectHit(arg0, 0xA00, 1, 2, 0, 0, 0, 16.0f, 16.0f, 1.0f, 0.75f, 0x11);
    flags = *(u8 **)((u8 *)arg0 + 0x7C);
    *flags |= 2;
    target = GetAutoAimTarget(*(s32 *)state, &aimFlag);
    *(s32 *)(state + 0x4) = target;
    if (target != 0) {
        objRegisterDependancy(arg0, (void *) target);
        return;
    }
    state[0x82] |= 8;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o122/overlay_122/ShirukenInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_122_07A00374_1FC825C(Object *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    u8 *baddy;
    u8 *entry;
    u8 *mtx;
    u8 *ext;

    if (arg0 == NULL || *((u8 *)arg0 + 0xA0) != 0) {
        return 0;
    }
    if (arg0->behaviorId == 0x18) {
        baddy = GetBaddyData(arg0);
        if (baddy != NULL) {
            /* sig mismatch: asm calls with only arg0 set up */
            ((void (*)(void *))SquaddieLightAndAnimate)(arg0);
            entry = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x6C) + ((s8) *((u8 *)arg0 + 0x3A)) * 4);
            mtx = *(u8 **)(entry + 0x10 + ((s8) entry[0xB]) * 4);
            mathMtxXFMF((f32 (*)[4])(mtx + (baddy[0x36] << 6)), 0.0f, 0.0f, 0.0f, arg1, arg2, arg3);
        } else {
            *arg1 = arg0->segment.trans.x_position;
            *arg2 = arg0->segment.trans.y_position + 40.0f;
            *arg3 = arg0->segment.trans.z_position;
        }
    } else if (arg0->behaviorId == 1 || arg0->behaviorId == 0x5A) {
        ext = *(u8 **)((u8 *)arg0 + 0x4C);
        *arg1 = arg0->segment.trans.x_position;
        *arg2 = arg0->segment.trans.y_position + (*(f32 *)(ext + 0x28) * 0.75f);
        *arg3 = arg0->segment.trans.z_position;
    } else {
        *arg1 = arg0->segment.trans.x_position;
        *arg2 = arg0->segment.trans.y_position;
        *arg3 = arg0->segment.trans.z_position;
    }
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o122/overlay_122/func_overlay_122_07A00374_1FC825C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Hit struct (trackGetIntersect out, asm sp+0xAC..): +0 obj, +4/+8/+C surface normal,
// +0x20 flags word, +0x24 surface type byte.
void ShirukenControl(Object *arg0, s32 arg1) {
    u8 *state;
    u8 *ext;
    u8 *flags;
    u8 *d50;
    u8 hit[0x28];
    Object *hitObj;
    Object *parent;
    Object *target;
    u8 *hitModel;
    f32 mtx[4][4];
    f32 dt;
    f32 tgtX;
    f32 tgtY;
    f32 tgtZ;
    f32 range;
    f32 speed;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 desVx;
    f32 desVz;
    f32 sumX;
    f32 sumZ;
    f32 st28;
    f32 st18;
    u32 hitFlags;
    u16 timer;
    s16 curYaw;
    s16 tgtYaw;
    s16 newYaw;
    s16 turn;
    s16 clampedTurn;
    s16 turnRate;

    state = *(u8 **)((u8 *)arg0 + 0x68);
    dt = (f32) arg1;
    runlinkSetDestructTimer(__MODULE00122, 2, 2);
    *(s32 *)(state + 0x84) += 1;

    ext = *(u8 **)((u8 *)arg0 + 0x4C);
    if (*(s16 *)(ext + 0x6) != 0xA00) {
        *(s16 *)(ext + 0x6) = 0xA00;
        state[0x82] &= 0xFE;
        state[0x82] |= 0x20;
    }

    /* state flag bit 0: attached to a parent object */
    if (state[0x82] & 1) {
        parent = *(Object **)(state + 0x30);
        if (parent == NULL) {
            return;
        }
        hitModel = *(u8 **)((u8 *)parent + 0x5C);
        if (parent->behaviorId == 0x37) {
            hitBridgeMoveWith(parent, state + 0x64, state + 0x68, state + 0x6C,
                              &arg0->segment.trans.x_position, &arg0->segment.trans.y_position,
                              &arg0->segment.trans.z_position);
        } else if (*(s16 *)(hitModel + 0x12C) != 0) {
            mathMtxXFMF((f32 (*)[4])(hitModel + (hitModel[0x12B] << 6) + 0x80),
                        *(f32 *)(state + 0x64), *(f32 *)(state + 0x68), *(f32 *)(state + 0x6C),
                        &tgtX, &tgtY, &tgtZ);
            objMoveXYZ(arg0, tgtX - arg0->segment.trans.x_position,
                       tgtY - arg0->segment.trans.y_position,
                       tgtZ - arg0->segment.trans.z_position);
        }
        return;
    }

    /* state flag bit 5: spinning (free-falling after a hit) */
    if (state[0x82] & 0x20) {
        flags = *(u8 **)((u8 *)arg0 + 0x7C);
        if (!(*flags & 2)) {
            arg0->segment.trans.y_rotation += *(s16 *)(state + 0x7A);
            arg0->segment.trans.x_rotation += *(s16 *)(state + 0x7C);
            arg0->segment.trans.z_rotation += *(s16 *)(state + 0x7E);
        }
        return;
    }

    /* normal flight */
    *(s16 *)(state + 0x78) += 0x1D6B;
    *(f32 *)(state + 0x8) = arg0->segment.trans.x_position;
    *(f32 *)(state + 0xC) = arg0->segment.trans.y_position;
    *(f32 *)(state + 0x10) = arg0->segment.trans.z_position;
    objMoveXYZ(arg0, *(f32 *)((u8 *)arg0 + 0x1C) * dt, *(f32 *)((u8 *)arg0 + 0x20) * dt,
               *(f32 *)((u8 *)arg0 + 0x24) * dt);

    d50 = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x40) + 0x50);
    trackMakePolylist(1, state + 0x8, &arg0->segment.trans.x_position, d50 + 0xC,
                      0xCE000000, 0, 0);

    if (trackGetIntersect(arg0, state + 0x8, &arg0->segment.trans.x_position,
                          *(s32 *)(d50 + 0xC), *(u8 *)(d50 + 0x10), (void **)hit) != 0) {
        hitObj = *(Object **)hit;
        hitFlags = *(u32 *)(hit + 0x20);
        if (hitObj != NULL && (*(u16 *)(*(u8 **)((u8 *)hitObj + 0x40) + 0x14) & 0x8000)) {
            ShirukenBounce(arg0, state);
        } else if (hitObj != NULL && hitObj->behaviorId == 0x4E) {
            *(s32 *)((u8 *)hitObj + 0x88) = 1;
            hitModel = *(u8 **)((u8 *)hitObj + 0x5C);
            *(s16 *)(hitModel + 0x130) = 0xA;
            hitModel = *(u8 **)((u8 *)hitObj + 0x5C);
            hitModel[0x12A] = 1;
        } else {
            if (hitObj != NULL && hitObj->behaviorId == 0x57) {
                *(s16 *)(*(u8 **)((u8 *)hitObj + 0x4C) + 0x6) = 0;
                objRemoveDependancy(arg0, 0); /* asm: a1 not set on this path */
                state[0x82] |= 4;
                *(void **)(state + 0x4) = *(void **)(state + 0x0);
            } else if (hitFlags & 0x400) {
                ShirukenBounce(arg0, state);
                *(f32 *)((u8 *)arg0 + 0x1C) = 0.0f;
                *(f32 *)((u8 *)arg0 + 0x20) = 0.0f;
                *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
            } else if (hitFlags & 0x2000) {
                *(void **)(state + 0x4) = NULL;
                state[0x82] |= 0x20;
                flags = *(u8 **)((u8 *)arg0 + 0x7C);
                *flags &= 0xFD;
                *(s16 *)(state + 0x7A) = mathRnd(-0x3E8, 0x3E8);
                *(s16 *)(state + 0x7C) = mathRnd(-0x3E8, 0x3E8);
                *(s16 *)(state + 0x7E) = mathRnd(-0x3E8, 0x3E8);
            } else if (hit[0x24] == 3) {
                *(void **)(state + 0x4) = NULL;
                state[0x82] |= 0x20;
                flags = *(u8 **)((u8 *)arg0 + 0x7C);
                *flags &= 0xFD;
                *(s16 *)(state + 0x7A) = mathRnd(-0x1388, 0x1388);
                *(s16 *)(state + 0x7C) = mathRnd(-0x1388, 0x1388);
                *(s16 *)(state + 0x7E) = mathRnd(-0x1388, 0x1388);
                *(f32 *)((u8 *)arg0 + 0x1C) = *(f32 *)(hit + 0x4) * 3.0f;
                *(f32 *)((u8 *)arg0 + 0x20) = *(f32 *)(hit + 0x8) * 3.0f;
                *(f32 *)((u8 *)arg0 + 0x24) = *(f32 *)(hit + 0xC) * 3.0f;
            } else {
                *(f32 *)((u8 *)arg0 + 0x1C) = 0.0f;
                *(f32 *)((u8 *)arg0 + 0x20) = 0.0f;
                *(f32 *)((u8 *)arg0 + 0x24) = 0.0f;
                *(Object **)(state + 0x30) = hitObj;
                if (hitObj != NULL) {
                    hitModel = *(u8 **)((u8 *)hitObj + 0x5C);
                    matrix_SCL_RPY_XYZ(arg0, mtx);
                    matrixYaw(*(s16 *)(state + 0x78), mtx);
                    mathMtxCatF(mtx, (f32 (*)[4])(hitModel + (hitModel[0x12B] << 6)),
                                (f32 (*)[4])(state + 0x34));
                }
                if (!(state[0x82] & 1)) {
                    amSndPlayXYZ(0x9A, arg0->segment.trans.x_position,
                                 arg0->segment.trans.y_position, arg0->segment.trans.z_position,
                                 4, 0);
                }
                state[0x82] |= 1;
                state[0x82] &= 0xF7;
            }
        }
    }

    /* end of intersect block: state->0x4 is the current target */
    target = *(Object **)(state + 0x4);
    if (target == NULL) {
        *(s32 *)((u8 *)arg0 + 0x84) = 1;
        partUpdateTriggers(arg0, arg1, &tgtY);
        if (!(state[0x82] & 1)) {
            arg0->segment.trans.y_rotation = (s16) Arctanf(*(f32 *)((u8 *)arg0 + 0x1C),
                                                           *(f32 *)((u8 *)arg0 + 0x24));
            arg0->segment.trans.x_rotation = (s16) -Arctanf(*(f32 *)((u8 *)arg0 + 0x20),
                                                            sqrtf((*(f32 *)((u8 *)arg0 + 0x1C) * *(f32 *)((u8 *)arg0 + 0x1C))
                                                                  + (*(f32 *)((u8 *)arg0 + 0x24) * *(f32 *)((u8 *)arg0 + 0x24))));
        }
        return;
    }

    if (func_overlay_122_07A00374_1FC825C(target, &tgtX, &tgtY, &tgtZ) == 0) {
        objRemoveDependancy(arg0, 0); /* asm: a1 not set on this path */
        state[0x82] |= 4;
        *(void **)(state + 0x4) = *(void **)(state + 0x0);
        target = *(Object **)(state + 0x4);
        tgtX = target->segment.trans.x_position;
        tgtY = target->segment.trans.y_position
             + (*(f32 *)(*(u8 **)((u8 *)target + 0x4C) + 0x28) * 0.75f);
        tgtZ = target->segment.trans.z_position;
    }

    range = GetRange(arg0->segment.trans.x_position, arg0->segment.trans.y_position,
                     arg0->segment.trans.z_position, tgtX, tgtY, tgtZ);

    if (!(state[0x82] & 8)) {
        dx = tgtX - arg0->segment.trans.x_position;
        dy = tgtY - arg0->segment.trans.y_position;
        dz = tgtZ - arg0->segment.trans.z_position;
        if (range != 0.0f) {
            dx /= range;
            dy /= range;
            dz /= range;
        }
        dy *= 5.5f;
        desVx = ((dx * 5.5f) - *(f32 *)((u8 *)arg0 + 0x1C)) * D_overlay_122_07A010D4;
        desVz = ((dz * 5.5f) - *(f32 *)((u8 *)arg0 + 0x24)) * D_overlay_122_07A010D8;
        *(f32 *)(state + 0x14) = *(f32 *)(state + 0x14)
            + ((desVx - *(f32 *)(state + 0x14)) * D_overlay_122_07A010DC);
        *(f32 *)(state + 0x1C) = *(f32 *)(state + 0x1C)
            + ((desVz - *(f32 *)(state + 0x1C)) * D_overlay_122_07A010E0);

        curYaw = (s16) Arctanf(*(f32 *)((u8 *)arg0 + 0x1C), *(f32 *)((u8 *)arg0 + 0x24));
        sumX = *(f32 *)((u8 *)arg0 + 0x1C) + *(f32 *)(state + 0x14);
        sumZ = *(f32 *)((u8 *)arg0 + 0x24) + *(f32 *)(state + 0x1C);
        tgtYaw = (s16) Arctanf(sumX, sumZ);
        speed = sqrtf((sumX * sumX) + (sumZ * sumZ));
        turn = mathDiffAngle(curYaw, tgtYaw);
        clampedTurn = turn;
        if (turn >= 0x5DD) {
            clampedTurn = 0x5DC;
        } else if (turn < -0x5DC) {
            clampedTurn = -0x5DC;
        }
        newYaw = (s16)(curYaw + clampedTurn);
        if (speed < 4.0f) {
            speed = 4.0f;
        }
        *(f32 *)((u8 *)arg0 + 0x1C) = Sinf(newYaw) * speed;
        *(f32 *)((u8 *)arg0 + 0x24) = Cosf((s32) newYaw) * speed;

        if (state[0x82] & 2) {
            turnRate = 0;
        } else {
            turnRate = mathDiffAngle(newYaw, *(s16 *)(state + 0x76));
        }

        arg0->segment.trans.y_rotation = (s16) Arctanf(*(f32 *)((u8 *)arg0 + 0x1C),
                                                       *(f32 *)((u8 *)arg0 + 0x24));
        arg0->segment.trans.z_rotation = (s16)(turnRate * 0xA);
        arg0->segment.trans.x_rotation = (s16) -Arctanf(*(f32 *)((u8 *)arg0 + 0x20),
                                                        sqrtf((*(f32 *)((u8 *)arg0 + 0x1C) * *(f32 *)((u8 *)arg0 + 0x1C))
                                                              + (*(f32 *)((u8 *)arg0 + 0x24) * *(f32 *)((u8 *)arg0 + 0x24))));

        if (turnRate < 0) {
            *(f32 *)(state + 0x24) = (f32) -turnRate;
        } else {
            *(f32 *)(state + 0x24) = (f32) turnRate;
        }

        if (state[0x82] & 2) {
            *(f32 *)(state + 0x18) = 0.0f;
        } else {
            st28 = *(f32 *)(state + 0x28);
            *(f32 *)(state + 0x24) = st28 + ((*(f32 *)(state + 0x24) - st28) * 0.5f);
            *(f32 *)(state + 0x18) = (dy - *(f32 *)((u8 *)arg0 + 0x20))
                + ((f32) mathDiffAngle((s16)(s32) st28, (s16)(s32) *(f32 *)(state + 0x24))
                   * D_overlay_122_07A010E4);
        }

        st18 = *(f32 *)(state + 0x18);
        if (st18 >= 0.0f) {
            *(f32 *)(state + 0x18) = sqrtf(st18);
        } else {
            *(f32 *)(state + 0x18) = -sqrtf(-st18);
        }
        *(f32 *)((u8 *)arg0 + 0x20) = *(f32 *)((u8 *)arg0 + 0x20) + *(f32 *)(state + 0x18);

        timer = *(u16 *)(state + 0x80);
        state[0x82] &= 0xFD;
        *(s16 *)(state + 0x76) = newYaw;
        *(f32 *)(state + 0x28) = *(f32 *)(state + 0x24);
        if (arg1 < (s32) timer) {
            *(u16 *)(state + 0x80) = (u16)(timer - arg1);
        } else {
            objRemoveDependancy(arg0, arg1);
            state[0x82] |= 4;
            *(void **)(state + 0x4) = *(void **)(state + 0x0);
        }
    }

    *(s32 *)((u8 *)arg0 + 0x84) = 1;
    partUpdateTriggers(arg0, arg1, NULL); /* asm: a2 not set on this path */
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o122/overlay_122/ShirukenControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void ShirukenPushMtx(void **arg0, void **arg1, Object *arg2) {
    u8 *state;
    u8 *parent;
    u8 *tmp;
    f32 mtx[4][4];

    state = *(u8 **)((u8 *)arg2 + 0x68);
    parent = *(u8 **)(state + 0x30);
    if (parent != NULL && *(s16 *)(parent + 0x48) != 0x37) {
        tmp = *(u8 **)(parent + 0x5C);
        /* sig mismatch: asm also passes parent in $a3 */
        ((void (*)(void *, void *, void *, void *))mathMtxCatF)(state + 0x34, tmp + (tmp[0x12B] << 6) + 0x80, mtx, parent);
        camPushFloatModelMtx(arg0, arg1, mtx);
        return;
    }
    matrix_SCL_RPY_XYZ(arg2, mtx);
    matrixYaw(*(s16 *)(state + 0x78), mtx);
    camPushFloatModelMtx(arg0, arg1, mtx);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o122/overlay_122/ShirukenPushMtx.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void ShirukenBounce(Object *arg0, void *arg1) {
    u8 *state = (u8 *)arg1;
    u8 *flags;

    state[0x82] |= 0x20;
    *(s32 *)(state + 0x4) = *(s32 *)state;
    flags = *(u8 **)((u8 *)arg0 + 0x7C);
    *flags &= 0xFD;
    *(f32 *)((u8 *)arg0 + 0x1C) *= -0.5f;
    *(f32 *)((u8 *)arg0 + 0x20) = (f32) mathRnd(0, 5);
    *(f32 *)((u8 *)arg0 + 0x24) *= -0.5f;
    *(s16 *)(state + 0x7A) = mathRnd(-0x1388, 0x1388);
    *(s16 *)(state + 0x7C) = mathRnd(-0x1388, 0x1388);
    *(s16 *)(state + 0x7E) = mathRnd(-0x1388, 0x1388);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o122/overlay_122/ShirukenBounce.s")
#endif
