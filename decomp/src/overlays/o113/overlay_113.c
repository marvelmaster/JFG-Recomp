#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
typedef struct MissileRacer {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ s32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ f32 unk18;
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ s32 unk20;
    /* 0x24 */ s32 unk24;
    /* 0x28 */ s16 unk28;
    /* 0x2A */ s16 unk2A;
    /* 0x2C */ s16 unk2C;
    /* 0x2E */ s16 unk2E;
    /* 0x30 */ s16 unk30;
    /* 0x32 */ s16 unk32;
    /* 0x34 */ s16 unk34;
    /* 0x36 */ u8 unk36;
    /* 0x37 */ u8 unk37;
    /* 0x38 */ u8 unk38;
    /* 0x39 */ s8 unk39;
} MissileRacer;

typedef struct MissileSetup {
    /* 0x00 */ u8 pad00[0xA];
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 unkB;
    /* 0x0C */ f32 unkC;
    /* 0x10 */ s32 unk10;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s16 unk18;
    /* 0x1A */ s16 unk1A;
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ s16 unk1E;
    /* 0x20 */ s16 unk20;
    /* 0x22 */ s16 unk22;
    /* 0x24 */ u8 unk24;
    /* 0x25 */ u8 unk25;
    /* 0x26 */ s8 unk26;
} MissileSetup;

/* hit result block passed to trackNearestIntersection (asm sp+0xCC..0xF3) */
typedef struct MissileHit {
    /* 0x00 */ s32 flag;
    /* 0x04 */ f32 hitX;
    /* 0x08 */ f32 hitY;
    /* 0x0C */ f32 hitZ;
    /* 0x10 */ f32 nx;
    /* 0x14 */ f32 ny;
    /* 0x18 */ f32 nz;
    /* 0x1C */ u8 pad1C[8];
    /* 0x24 */ s32 surface;
} MissileHit;

/* stack setup block for an object spawned on hit (asm sp+0x88) */
typedef struct MissileSpawnA {
    /* 0x00 */ s16 id;
    /* 0x02 */ u8 unk2;
    /* 0x03 */ u8 pad3;
    /* 0x04 */ s16 x;
    /* 0x06 */ s16 y;
    /* 0x08 */ s16 z;
    /* 0x0A */ s16 unkA;
    /* 0x0C */ f32 unkC;
} MissileSpawnA;

/* stack setup block for the explosion object (asm sp+0x6C) */
typedef struct MissileSpawnB {
    /* 0x00 */ s16 id;
    /* 0x02 */ s16 pad2;
    /* 0x04 */ s16 x;
    /* 0x06 */ s16 y;
    /* 0x08 */ s16 z;
    /* 0x0A */ s16 rotX;
    /* 0x0C */ s16 rotY;
    /* 0x0E */ u8 pad0E[2];
    /* 0x10 */ u8 flagA;
    /* 0x11 */ u8 flagB;
    /* 0x12 */ u8 level;
    /* 0x13 */ u8 flagC;
    /* 0x14 */ void *owner;
} MissileSpawnB;

f32 Sinf(s16 angle);
s32 mathDiffAngle(s16 a, s16 b);
void explosionAddBlast(f32 x, f32 y, f32 z, f32 a3, f32 a4, f32 a5, s32 a6, void *a7);
void explosionStart(s32 type, s16 x, s16 y, s16 z, s32 a4, void *owner);
void amSndPlayXYZ(u16 soundId, f32 x, f32 y, f32 z, u8 arg4, void *soundMask);
void *objSetupObject(void *params, s32 arg1);
void objFreeObject(void *obj);
void objMoveXYZ(void *obj, f32 x, f32 y, f32 z);
void mathOneFloatRPY(void *rot, f32 *vec);
void partUpdateTriggers(void *obj, s32 arg);
void runlinkSetDestructTimer(s32 a, s32 b, s32 c);
void squadsAddInterestingEvent(void *arg0, s16 x, s16 y, s16 z, s32 a, s32 b, s32 c);
void trackLightDelete(s32 id);
void trackLightMove(s32 id, f32 x, f32 y, f32 z);
s32 trackNearestIntersection(s32 a, void *from, void *to, void *out, s32 mask, s32 c);
extern u8 D_overlay_113_07100CC4[];
extern f32 D_overlay_113_07100CD0;
extern s32 __MODULE00113;
void hitInitObjectHit(Object *obj, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6,
                      f32 f1, f32 f2, f32 f3, f32 f4, s32 a7);
void mathOneFloatPY(void *a, void *b);
void objRegisterDependancy(void *obj, s32 id);
s16 objTvTimes(s32 n);
s32 trackLightAdd(f32 x, f32 y, f32 z, f32 r, f32 g, s32 b, s32 a, s32 c);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void missileInit(Object *arg0, MissileSetup *arg1) {
    f32 vec[3];
    f32 temp_f4;
    MissileRacer *racer;

    *(f32 *)((u8 *)arg0 + 0x1C) = 0.0f;
    *(f32 *)((u8 *)arg0 + 0x20) = 0.0f;
    *(f32 *)((u8 *)arg0 + 0x24) = -arg1->unkC;
    arg0->segment.trans.y_rotation = arg1->unk1E;
    arg0->segment.trans.x_rotation = arg1->unk20;
    arg0->segment.trans.z_rotation = 0;
    racer = (MissileRacer *)arg0->racer;
    mathOneFloatPY(arg0, (u8 *)arg0 + 0x1C);
    racer->unk36 = 0;
    racer->unkC = 0;
    racer->unk1C = -arg1->unkC;
    racer->unk37 = arg1->unk24;
    racer->unk24 = arg1->unk14;
    racer->unk38 = arg1->unk25;
    racer->unk10 = arg0->segment.trans.x_position;
    racer->unk14 = arg0->segment.trans.y_position;
    racer->unk18 = arg0->segment.trans.z_position;
    racer->unk39 = arg1->unk26;
    if (arg1->unk24 != 1) {
        racer->unk32 = arg1->unk1C;
        racer->unk34 = arg1->unk22;
        racer->unk2E = arg1->unk18;
        racer->unk30 = arg1->unk1A;
        vec[0] = Sinf(racer->unk2E) * (f32)racer->unk32;
        temp_f4 = Cosf((s32)racer->unk2E) * (f32)racer->unk32;
        vec[2] = 0.0f;
        vec[1] = temp_f4;
        pointListRPY(1, (s16 *)arg0, (s32 *)vec, vec);
        arg0->segment.trans.x_position += vec[0];
        arg0->segment.trans.y_position += vec[1];
        arg0->segment.trans.z_position += vec[2];
    } else {
        racer->unk32 = 0;
        racer->unk34 = 0;
        racer->unk2E = 0;
        racer->unk30 = 0;
        objRegisterDependancy(arg0, racer->unk24);
    }
    racer->unk0 = arg0->segment.trans.x_position;
    racer->unk4 = arg0->segment.trans.y_position;
    racer->unk8 = arg0->segment.trans.z_position;
    racer->unk28 = objTvTimes(arg1->unkB * 6);
    racer->unk20 = arg1->unk10;
    hitInitObjectHit(arg0, (arg1->unkA + 1) << 8, 1, 4, 0, 0, 0, 2.0f, 2.0f, -1.0f, 1.0f, 0x11);
    *(s32 *)((u8 *)arg0 + 0x88) = *(s16 *)(*(u8 **)((u8 *)arg0 + 0x4C) + 6);
    if ((f32)racer->unk32 == 0.0f) {
        *(s32 *)((u8 *)arg0 + 0x8C) = trackLightAdd(arg0->segment.trans.x_position,
                                                   arg0->segment.trans.y_position,
                                                   arg0->segment.trans.z_position,
                                                   500.0f, 300.0f, 0xFF, 0xE0, 0);
        return;
    }
    *(s32 *)((u8 *)arg0 + 0x8C) = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o113/overlay_113/missileInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void missileControl(Object *obj, s32 arg1) {
    MissileRacer *racer;
    MissileHit hit;
    MissileSpawnA spawnA;
    MissileSpawnB spawnB;
    f32 vec[3];
    f32 *vel;
    f32 dt;
    f32 dx, dy, dz, dist;
    f32 *node;
    u8 *target;
    u8 *tgt4C;
    u8 *obj4C;
    u8 *owner;
    u8 *setupRet;
    u8 hitRes;
    s16 yawT;
    s16 pitchT;
    s32 d;
    s32 dA;
    s32 dB;
    s32 i;
    s32 idx;

    runlinkSetDestructTimer(__MODULE00113, 2, 2);
    racer = (MissileRacer *)obj->racer;
    dt = (f32)arg1;
    racer->unk28 = (s16)(racer->unk28 - arg1);
    obj4C = *(u8 **)((u8 *)obj + 0x4C);
    vel = (f32 *)((u8 *)obj + 0x1C);

    if (racer->unk28 > 0 && *(s16 *)(obj4C + 0x6) > 0 && racer->unk36 == 0 &&
        *(s32 *)((u8 *)obj + 0x88) == *(s16 *)(obj4C + 0x6)) {
        if (racer->unk37 == 1) {
            /* homing: steer toward the target object */
            target = (u8 *)racer->unk24;
            if (target != NULL && *(u8 **)(target + 0x4C) == NULL) {
                racer->unk24 = 0;
                target = NULL;
            }
            if (target != NULL) {
                tgt4C = *(u8 **)(target + 0x4C);
                if (racer->unk38 != 0xFF && (s32)racer->unk38 >= *(s16 *)(tgt4C + 0x32)) {
                    racer->unk38 = 0xFF;
                }
                if (arg1 > 0) {
                    i = 0;
                    do {
                        idx = racer->unk38;
                        if (idx == 0xFF) {
                            node = (f32 *)(tgt4C + 0x18);
                        } else {
                            node = (f32 *)(*(u8 **)(tgt4C + 0x40) + idx * 0x34 + 0x18);
                        }
                        dx = obj->segment.trans.x_position - node[0];
                        dy = obj->segment.trans.y_position - node[1];
                        dz = obj->segment.trans.z_position - node[2];
                        dist = sqrtf(dx * dx + dz * dz);
                        if (dz == 0.0f) {
                            yawT = 0;
                        } else {
                            yawT = (s16)Arctanf(dx, dz);
                        }
                        if (dist == 0.0f) {
                            pitchT = 0;
                        } else {
                            pitchT = (s16)-Arctanf(dy, dist);
                        }

                        /* yaw: rotate toward target, step clamped to +/-0x258 */
                        d = mathDiffAngle(obj->segment.trans.y_rotation, yawT) >> 3;
                        dA = (s16)d;
                        if ((s16)d >= 0x259) {
                            dA = 0x258;
                        }
                        if (dA < -0x258) {
                            dA = -0x258;
                        }
                        obj->segment.trans.y_rotation = (s16)(obj->segment.trans.y_rotation + dA);

                        /* pitch: same step, clamped identically */
                        d = mathDiffAngle(obj->segment.trans.x_rotation, pitchT) >> 3;
                        dB = (s16)d;
                        if ((s16)d >= 0x259) {
                            dB = 0x258;
                        }
                        if (dB < -0x258) {
                            dB = -0x258;
                        }
                        obj->segment.trans.x_rotation = (s16)(obj->segment.trans.x_rotation + dB);
                    } while (++i != arg1);
                }
            }
            vel[0] = 0.0f;
            vel[1] = 0.0f;
            vel[2] = racer->unk1C;
            mathOneFloatPY(obj, (u8 *)obj + 0x1C);
            objMoveXYZ(obj, vel[0] * dt, vel[1] * dt, vel[2] * dt);
        } else {
            racer->unk10 = racer->unk10 + vel[0] * dt;
            racer->unk14 = racer->unk14 + vel[1] * dt;
            racer->unk18 = racer->unk18 + vel[2] * dt;
            racer->unk32 = (s16)(racer->unk32 + racer->unk34 * arg1);
            if (racer->unk32 == 0) {
                obj->segment.trans.z_rotation = (s16)(obj->segment.trans.z_rotation + (arg1 << 10));
                vec[0] = 0.0f;
                vec[1] = 0.0f;
                vec[2] = 0.0f;
            } else {
                racer->unk2E = (s16)(racer->unk2E + racer->unk30 * arg1);
                if (racer->unk32 >= 0x33) {
                    racer->unk32 = 0x32;
                }
                vec[0] = Sinf(racer->unk2E) * (f32)racer->unk32;
                vec[1] = Cosf((s32)racer->unk2E) * (f32)racer->unk32;
                vec[2] = 0.0f;
                mathOneFloatRPY(obj, vec);
            }
            vec[0] = vec[0] + racer->unk10;
            vec[1] = vec[1] + racer->unk14;
            vec[2] = vec[2] + racer->unk18;
            objMoveXYZ(obj, vec[0] - obj->segment.trans.x_position,
                       vec[1] - obj->segment.trans.y_position,
                       vec[2] - obj->segment.trans.z_position);
        }

        /* sweep for a surface between obj and its position; snap on hit */
        hitRes = (u8)trackNearestIntersection((s32)obj, (u8 *)obj4C + 0x18, (u8 *)obj + 0xC,
                                              &hit, 0, 0);
        racer->unk36 = hitRes;
        if (hitRes != 0) {
            if (hit.flag == 0) {
                racer->unk36 = hitRes | 2;
            }
            racer->unk0 = hit.hitX;
            racer->unk4 = hit.hitY;
            racer->unk8 = hit.hitZ;
            racer->unkC = hit.surface;
            objMoveXYZ(obj, racer->unk0 - obj->segment.trans.x_position,
                       racer->unk4 - obj->segment.trans.y_position,
                       racer->unk8 - obj->segment.trans.z_position);
            racer->unk2A = (s16)(Arctanf(hit.nx, hit.nz) + 0x8000);
            racer->unk2C = (s16)Arctanf(hit.ny, sqrtf(hit.nx * hit.nx + hit.nz * hit.nz));
        }
        if (*(s32 *)((u8 *)obj + 0x8C) != 0) {
            trackLightMove(*(s32 *)((u8 *)obj + 0x8C), obj->segment.trans.x_position,
                           obj->segment.trans.y_position, obj->segment.trans.z_position);
        }
    } else {
        /* detonation: destroyed, or no longer valid */
        if ((racer->unkC & 0x2000) && !(racer->unkC & 0x8000)) {
            amSndPlayXYZ(0xD, obj->segment.trans.x_position, obj->segment.trans.y_position,
                         obj->segment.trans.z_position, 4, NULL);
            spawnA.id = 0xC0;
            spawnA.unk2 = 0x10;
            spawnA.x = (s16)(s32)racer->unk0;
            spawnA.y = (s16)(s32)racer->unk4;
            spawnA.z = (s16)(s32)racer->unk8;
            spawnA.unkA = 0x100;
            spawnA.unkC = 20.0f;
            setupRet = (u8 *)objSetupObject(&spawnA, 1);
            if (setupRet != NULL) {
                *(s32 *)(setupRet + 0x3C) = 0;
            }
        } else {
            amSndPlayXYZ(0x96, obj->segment.trans.x_position, obj->segment.trans.y_position,
                         obj->segment.trans.z_position, 4, NULL);
            owner = (u8 *)racer->unk20;
            if (owner != NULL && *(s16 *)(owner + 0x48) != 1) {
                owner = NULL;
            }
            if (racer->unk37 == 1) {
                spawnB.id = 0x13C;
                spawnB.x = (s16)(s32)obj->segment.trans.x_position;
                spawnB.y = (s16)(s32)obj->segment.trans.y_position;
                spawnB.z = (s16)(s32)obj->segment.trans.z_position;
                spawnB.rotX = racer->unk2A;
                spawnB.rotY = racer->unk2C;
                spawnB.flagA = racer->unk36 & 1;
                spawnB.flagB = 1;
                spawnB.level = *(u8 *)((u8 *)levelGetLevel() + 0xE2);
                spawnB.flagC = racer->unk36 & 2;
                spawnB.owner = owner;
                setupRet = (u8 *)objSetupObject(&spawnB, 1);
                if (setupRet != NULL) {
                    *(s32 *)(setupRet + 0x3C) = 0;
                }
                explosionAddBlast(obj->segment.trans.x_position, obj->segment.trans.y_position,
                                  obj->segment.trans.z_position, 120.0f, 120.0f,
                                  D_overlay_113_07100CD0, D_overlay_113_07100CC4[racer->unk37],
                                  owner);
            } else {
                explosionStart(2, (s16)(s32)obj->segment.trans.x_position,
                               (s16)(s32)obj->segment.trans.y_position,
                               (s16)(s32)obj->segment.trans.z_position,
                               D_overlay_113_07100CC4[racer->unk37], owner);
            }
            squadsAddInterestingEvent(NULL, (s16)(s32)obj->segment.trans.x_position,
                                      (s16)(s32)obj->segment.trans.y_position,
                                      (s16)(s32)obj->segment.trans.z_position, 5, 1, 0x96);
        }
        if (*(s32 *)((u8 *)obj + 0x8C) != 0) {
            trackLightDelete(*(s32 *)((u8 *)obj + 0x8C));
        }
        objFreeObject(obj);
        racer = NULL;
    }

    if (racer != NULL) {
        if (racer->unk32 == 0) {
            *(s32 *)((u8 *)obj + 0x84) = 1;
        } else {
            *(s32 *)((u8 *)obj + 0x84) = 3;
        }
        partUpdateTriggers(obj, arg1);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o113/overlay_113/missileControl.s")
#endif
