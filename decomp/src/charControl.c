#include "common.h"

const char D_800AC5E0[] = "charAnimSoundTick: Illegal soundtype\n";
const char D_800AC608[] = "The maximum number of camera objects has been exceeded.\n";
const char D_800AC644[] = "Cannot delete camera object, it is not in list.\n";
#ifdef VERSION_kiosk
const char D_800AC678[] = "grenade\n";
#endif

/* decomp: externs */
extern u8 D_800A26C4_A32C4[];
extern u8 D_800A26C5_A32C5[];
extern u8 D_800A265C_A325C[];
extern u8 D_800A2664_A3264[];
extern u8 D_800A266C_A326C[];
extern u8 D_800A2674_A3274[];
extern u8 *D_800A2BC0_A37C0[];
extern u8 D_800F6E58_B1808[];
extern u8 D_800F6E70_B1820[];
extern u8 D_800F7888[];
extern u8 *controlcam;
void amSndPlayXYZ(u16 soundId, f32 x, f32 y, f32 z, u8 arg4, void *soundMask);
void amSndStopXYZ(void *soundMask);
void squadsAddInterestingEvent(void *arg0, s16 x, s16 y, s16 z, s32 a, s32 b, s32 c);
void *camGetPtr(void);
f32 Powerf(f32 base, s32 n);
f32 Sinf(s16 angle);
s16 dAngle(s16 a, s16 b, f32 c);
void *mainGetGameCharacter(s8 a, s8 b);
s32 mainPlayerHas(s32 arg0, s32 arg1, s32 arg2);
void lobbycamPosition(f32 t, void *dst, void *cam, s32 n, u8 flag);
s32 lobbycamInuse(f32 t, void *cam);
s32 staticcamInuse(f32 t, s32 n);
void staticcamPosition(f32 t, void *cam);
s32 animseqCamera(s32 n, void *cam);
void *trackGetTrack(void);
s16 trackGetBlock(f32 x, f32 y, f32 z);
void func_8002F0E8(s32 camNo, f32 x, f32 y, f32 z);
s32 camGetNo(void *cam);
void camSetWaterLine(s32 a, s32 b);
void charSpeak(Object *obj, u8 arg1);
s32 objAnimSetMove(void *arg0, s8 arg1, f32 arg2);
void charPlaySoundEffect(Object *obj, s32 arg1);
void func_8002B8C0(ObjectTransform *obj, u8 *state, f32 t);
void func_8002BC64(ObjectTransform *obj, u8 *state, f32 t);
void func_8002BFD0(ObjectTransform *obj, u8 *state, f32 t);
void func_8002C078(ObjectTransform *obj, u8 *state, f32 t);
void func_8002C868(ObjectTransform *obj, u8 *state, f32 t);
void func_8002C900(ObjectTransform *obj, u8 *state, f32 t);
void func_8002CF78(ObjectTransform *obj, u8 *state, f32 t);
void arcadecameraUpdate(f32 t, u8 *cam, s32 n);
void chestcameraUpdate(f32 t, u8 *cam, s32 n, s32 m);
void girlMagicCamera(f32 t, u8 *cam, s32 n);
void hovershipCamera(f32 t, u8 *cam, s32 n);
void mizarCutCamera(f32 t, u8 *cam, u8 *state, s32 n);
void sidekickpadCamera(f32 t, ObjectTransform *obj, u8 *cam, s32 n);
void splinecamMovementCheck(f32 t, u8 *cam, ObjectTransform *obj, f32 u);
void terminalCameraUpdate(f32 t, u8 *cam, s32 n);
void transformerCamera(f32 t, u8 *cam, s32 n);
void chargeEffectCreate(u8 *a, u8 *b, u8 *c, f32 *d, f32 *e, f32 *f, s16 *g, s16 *h, s16 *i);
void splinecamCameraPos(u8 *a, u8 *b, f32 x, f32 y, f32 z);
s32 boyCanFire(void);
s32 dogCanFire(void);
s32 flamethrowerInit(void);
s32 frontGetTargetControl(s8 n);
s32 mainGetNumberOfPlayers(void);
void mainPauseDisable(s32 n);
void controlRestartPlayer(void *arg0, s8 *arg1);
extern u8 D_800FED63_B1763[];
extern u8 multiFinished;
extern u8 multiPlayerGame;
extern s16 D_800A2DB0_A39B0;
extern void *controlModeKeys;
extern s32 D_800A2D38_A3938;
extern void *D_800F6DF8_B17A8[];
extern u8 D_800A2BE0_A37E0[];
extern u8 D_800A2BF0_A37F0[];
extern u8 D_800A2C00_A3800[];
extern u8 D_800A2C10_A3810[];
extern u8 D_800A2C20_A3820[];
extern u8 D_800A2C30_A3830[];
extern u8 D_800A2C50_A3850[];
extern u8 D_800A2C60_A3860[];
extern u8 D_800A2C84_A3884[];
extern f32 D_800A2CAC_A38AC;
extern u8 D_800A2C64_A3864[];
extern u8 D_800A2C88_A3888[];
extern u8 D_800A2CA8_A38A8[];
void func_8002F45C(s32 arg0, f32 arg1);
extern u8 D_800A2CCC_A38CC[];
extern u8 D_800A2CD0_A38D0[];
extern u8 D_800A2CF0_A38F0[];
extern u8 D_800A2CF4_A38F4[];
extern u8 D_800A2D14_A3914[];
extern u8 D_800A2D18_A3918[];
s32 levelGetCamera(void);
void func_8002F2BC(s32 arg0, f32 *arg1, f32 *arg2, s32 *arg3, f32 *arg4, s32 *arg5, s32 arg6, s32 arg7);
extern f32 sidekickHeight;
extern u8 cooperativeGame;
void func_80031CC4(ObjectTransform *obj, void *a1, void *a2, void *a3);
s32 func_80031A44(ObjectTransform *obj, f32 *a1, f32 *a2, f32 *outDist, s32 delta);
s32 camProjectPoint(f32 x, f32 y, f32 z, f32 *sx, f32 *sy, u8 flag);
void camReversePoint(f32 x, f32 y, f32 *a, f32 *b, f32 *c, u8 flag);
extern u8 D_800A1790_A2390[];
extern u8 D_800A1850_A2450[];
extern u8 D_800A2D44_A3944[];
extern u8 D_800A2D5C_A395C[];
extern u8 D_800A2DA4_A39A4[];
extern u8 D_800A2D74_A3974[];
void controlPlayerInit(void *obj, void *setup);
void camSetNo(s32 arg0);
s32 camlightAdd(void *arg0, void *arg1);
s32 fxAllocateCone(s16 a0, s16 a1, s16 a2, s16 a3, s32 a4, f32 f0, f32 f1, s32 a7, s32 a8, s32 a9);
s32 osRamTest4_6105(s32 a0, s32 a1, s32 a2, s32 a3, f32 f0);
extern u8 D_800A18FC_A24FC[];
extern u8 D_800A1BF8_A27F8[];
extern u8 D_800A20B4_A2CB4[];
extern u8 D_800A23A8_A2FA8[];
extern u8 D_800A23BC_A2FBC[];
extern u8 D_800A25A0_A31A0[];
void objFreeObject(void *obj);
Object **objGetObjList(s32 *arg0, s32 *arg1);
s32 hitPlayer(f32 x, f32 y, f32 z, f32 radius, s32 ignoreY, void **out);
void mainRestartAfterDeath(void *arg0);
void hitInitObjectHit(void *arg0, s16 arg1, s8 arg2, s8 arg3, s16 arg4, s16 arg5, s16 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, u16 arg11);
void objMoveXYZnocheck(void);
extern u8 D_800A2DD8_A39D8[];
extern u8 rumbletime_bytes[];
extern f32 rumbletime_floats[];
extern u8 DebugAmmoFlag;
extern u8 weaponTable[];
extern u8 arithmeticSums[];
extern u8 D_800A2E10_A3A10[];
extern s16 D_800A2E40_A3A40[];
extern u8 D_800A1553_A2153;
void amSndPlay(u16 soundID, void *handlePtr);
void amSndStop(s32 handle);
void *objSetupObject(void *params, s32 arg1, void *owner);
void mainIncreaseWeaponShots(s32 arg0);
s32 GetAutoAimTarget(s32 arg0, u8 *arg1);
void partUpdateTriggers(void *obj, s32 arg1);
void **objGetPlayerlist(s32 *count);
void controlAlterMood(void *obj, s32 arg1);
void controlEmptyPlayersHand(void *obj, u8 weapon);
void controlGetGunBarrelPos(void *obj, void *state, f32 *x, f32 *y, f32 *z);
void flamethrowerFire(void *obj, MemoryPoolSlot *slot);
void flareThrow(MemoryPoolSlot *slot, f32 x, f32 y, f32 z, s32 a, s32 b, s32 c);
s32 func_80038488(void *obj, u8 *state, u8 *entry, f32 arg3);
void func_80038D54(void *obj, u8 *state, f32 x, f32 y, f32 z, s16 a5, s16 a6, f32 a7, s32 a8, s32 a9);
void func_80038E70(void *obj, u8 *state, f32 x, f32 y, f32 z, s16 a5, s16 a6, f32 a7, s32 a8, s32 a9, s32 a10);
void func_800390E0(void *obj, u8 *state, f32 x, f32 y, f32 z, s16 a5, s16 a6, f32 a7, s32 a8, s32 a9);
void func_8003931C(void *obj, u8 *state, f32 x, f32 y, f32 z, s16 a5, s16 a6, f32 a7, s32 a8, s32 a9);
void func_800394A4(void *obj, u8 *state, s32 arg2);
void func_800395B8(void *obj, u8 *state, f32 x, f32 y, f32 z, s16 a5, s16 a6, f32 a7, s32 a8, s32 a9);
void func_800396F0(void *obj, u8 *state, f32 x, f32 y, f32 z, s16 a5, s16 a6, f32 a7, s32 a8, s32 a9);
s32 func_80039AE0(void *obj, u8 *state, f32 x, f32 y, f32 z, s16 a5, s16 a6, f32 a7, s32 a8, s32 a9);
void func_80039810(void *obj, u8 *state, f32 x, f32 y, f32 z, s16 a5, s16 a6, f32 a7, s32 a8, s32 a9);
void func_80039970(void *obj, u8 *state, f32 x, f32 y, f32 z, s16 a5, s16 a6, f32 a7, s32 a8, s32 a9, s32 a10, s32 a11);
void func_80039CA4(void *obj, u8 *state, f32 x, f32 y, f32 z, s16 a5, s16 a6, f32 a7, s32 a8);
void mathOneFloatRPY(s16 *rot, f32 *vec);
void mathOneFloatYPR(s16 *rot, f32 *vec);
void objMoveXYZ(ObjectTransform *obj, f32 x, f32 y, f32 z);
void trackMakePolylist(s32 a, f32 *b, f32 *c, s32 *d, s32 e, s32 f, s32 g);
s32 trackGetIntersect(s32 a, f32 *b, f32 *c, s32 d, s32 e, void *hit);
void func_80035B30(ObjectTransform *obj, u8 *state, f32 *outX, f32 *outY, f32 *outZ);
void hitCrateCheck(f32 *lo, f32 *hi, void *plat);
void *hitSquashCheck(void *pts, s32 id, void *plat, f32 *out);
s32 trackCylinderHeights(f32 x, f32 z, f32 y, f32 yTop, f32 radius, s32 a, s32 b, s32 c);
u32 trackGetPlayerIntersect(void *obj, void *objPos, f32 *polyPts, f32 *pts, f32 *ptParam, f32 *deltas, u16 *mask, void *hits, s32 n, s32 *outIdx, f32 *outVec);
void func_80035628(ObjectTransform *obj, u8 *state, f32 arg2);
s32 levelGetNumber(void);
extern u8 D_800A11C0_A1DC0[];
extern f32 D_800A2E60_A3A60[];
extern s16 D_800F6DEC_B179C;
extern s16 D_800F6DEE_B179E;
extern s16 D_800F6DF0_B17A0;
extern s16 D_800F6DF2_B17A2;
extern u8 D_800A3708[8];
void SquaddieGetTiltList(void *obj, s16 a5, s16 a6, f32 a7);
s32 hitVectorCheck(s32 arg0, void *arg1, s32 arg2, void *arg3, void *arg4, void *arg5);
s32 trackNearestIntersection(s32 a, void *from, void *to, void *out, s32 mask, s32 c);
s32 trackGetLedgeCrossed(f32 *a, f32 *b, f32 *out);
s32 hitGetLedgeCrossed(f32 *a, f32 *b, f32 *out, void **outBlk);
void hitMakePolylist(f32 *lo, f32 *hi, s32 a, s32 b, s32 c);
s32 hitGetAdjacentLedge(f32 *arg0, f32 *arg1);
s32 trackGetAdjacentLedge(f32 *arg0, f32 *arg1);
void matrixTransposeVectorMultiply(void *, void *, f32 *);
s32 mathSin(s32 angle);
void fxMakeConeTextureCoords(void *cone, s16 a);
void fxMakeConeLength(void *cone, s16 len, s32 a);
/* controlPlayer callees (signatures from its asm: floats passed as int bits where noted) */
extern u8 racingInGame;
extern u8 multiGameType;
extern s32 D_80000310;
void func_800370D8(u8 *anim, f32 arg1);
extern u8 ControlModeExpert[];
extern u8 ControlModeNormal[];
extern u8 *camGetListPtr(void);
void boyBossControl(void *obj, s32 arg1);
void dogBossControl(void *obj, s32 arg1);
s32 girlBossControl(void);
void girlControl(void *obj, s32 arg1);
void boyControl(void *obj, s32 arg1);
void dogControl(void *obj, s32 arg1);
void hovershipControl(void *obj, s32 arg1);
void flamethrowerConstrain(void *obj, s32 arg1);
void flamethrowerHits(void *flame);
s32 flamethrowerUpdate(s32 a, s32 b, s32 c, s32 d, void *e, void *f);
void chargeEffectSetPower(void *obj);
s32 chargeEffectUpdate(s32 a, s32 b, s32 c, void *d);
s32 girlCanFire(s32 a, s32 b);
s32 splinecamSplineHead(void);
s32 splinecamGetNearestNode(s32 a, s32 b);
s32 frontGetMode(void);
s32 mainGetNextCharacter(s32 level);
s32 levelGetWorld(u32 a, void *b, s32 c, void *d);
void mainSetAnimGroup(s32 arg0);
s32 sprintCountdown(void *obj, s32 a, s32 b, s32 c, s32 d);
s32 hitPlayerKilledPlayer(void *arg0, void *arg1);
void controlDisableJoypad(s32 arg0);
/* sidekickControl callees (signatures from their asm) */
void controlReadJoypad(s32 player);
void mathOneFloatPY(void *rot, f32 *vec);
void camUseShake(void);
void amSndSetVol(u16 soundID, s32 handle, u8 volume);
void amSndSetPitchDirect(s32 handle, f32 pitch);
void *trackBlockDim(s16 blk, s32 y);
void func_8003109C(ObjectTransform *obj, u8 *state, u8 turnFlag, s32 delta);
void func_80031984(void *arg0, void *arg1, void *arg2, s32 arg3);
extern s32 robotTime;
extern void *D_800F6DE8_B1798;

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void charSpeak(Object *obj, u8 arg1) {
    u8 *ext = (u8 *)obj->racer;
    u8 *ent;
    u8 *list;
    s32 count;
    u16 last;
    s16 snd;

    if (*(void **)(ext + 0xBC) != NULL) {
        if (D_800A26C5_A32C5[(arg1 & 0xFF) * 8] & 1) {
            amSndStopXYZ(*(void **)(ext + 0xBC));
        } else {
            return;
        }
    }
    ent = D_800A26C4_A32C4 + (arg1 & 0xFF) * 8;
    count = ent[0];
    list = *(u8 **)(ent + 4) + count * (*(s8 *)(ext + 1) & 3) * 2;
    if (count == 1) {
        *(u16 *)(ext + 0xB8) = 0x7FFF;
    }
    last = *(u16 *)(ext + 0xB8);
    snd = (s16) last;
    if ((s16) last == last) {
        do {
            snd = *(s16 *)(list + mathRnd(0, count - 1) * 2);
        } while (snd == *(u16 *)(ext + 0xB8));
    }
    amSndPlayXYZ(snd & 0xFFFF, obj->segment.trans.x_position, obj->segment.trans.y_position,
                 obj->segment.trans.z_position, 4, ext + 0xBC);
    squadsAddInterestingEvent((u8 *)obj + 1, (s16)(s32) obj->segment.trans.x_position,
                              (s16)(s32) obj->segment.trans.y_position,
                              (s16)(s32) obj->segment.trans.z_position, 1, 1, (s32) snd);
    *(u16 *)(ext + 0xB8) = (u16) snd;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/charSpeak.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void charPlaySoundEffect(Object *obj, s32 arg1) {
    u8 *ext = (u8 *)obj->racer;
    u8 *ent = D_800A26C4_A32C4 + (arg1 & 0xFF) * 8;
    s32 count = ent[0];
    u8 *list = *(u8 **)(ent + 4) + count * (*(s8 *)(ext + 1) & 3) * 2;
    s16 snd = *(s16 *)(list + mathRnd(0, count - 1) * 2);
    f32 vx = *(f32 *)((u8 *)obj + 0x1C);
    f32 vz = *(f32 *)((u8 *)obj + 0x24);

    if (sqrtf((vx * vx) + (vz * vz)) > 0.7f) {
        amSndPlayXYZ(snd & 0xFFFF, obj->segment.trans.x_position, obj->segment.trans.y_position,
                     obj->segment.trans.z_position, 4, NULL);
        squadsAddInterestingEvent((u8 *)obj + 1, (s16)(s32) obj->segment.trans.x_position,
                                  (s16)(s32) obj->segment.trans.y_position,
                                  (s16)(s32) obj->segment.trans.z_position, 1, 1, (s32) snd);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/charPlaySoundEffect.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void charAnimSoundTick(Object *obj, f32 arg1, f32 arg2) {
    u8 *ext = (u8 *)obj->racer;
    f32 tStart = arg1;
    f32 tEnd;
    f32 evTime;
    s32 wrap = 0;
    u8 *rec;
    s8 recType;
    u8 *ev;
    s32 count;
    s32 i;

    if (*(f32 *)(ext + 0x60) > 0.0f) {
        *(u8 **)(D_800A26C4_A32C4 + 0x24) = D_800A266C_A326C;
        *(u8 **)(D_800A26C4_A32C4 + 0x2C) = D_800A2674_A3274;
    } else {
        *(u8 **)(D_800A26C4_A32C4 + 0x24) = D_800A265C_A325C;
        *(u8 **)(D_800A26C4_A32C4 + 0x2C) = D_800A2664_A3264;
    }
    rec = D_800A2BC0_A37C0[*(s8 *)(ext + 1)];
    if (rec != NULL) {
        tEnd = *(f32 *)((u8 *)obj + 0x28);
        if (arg2 < 0.0f) {
            tEnd = 1.0f - tEnd;
            tStart = 1.0f - tStart;
        }
        if (tEnd < tStart) {
            tEnd += 1.0f;
            wrap = 1;
        }
        recType = *(s8 *)rec;
        if (recType != -1) {
            do {
                if (recType == *(s8 *)((u8 *)obj + 0x3B)) {
                    ev = *(u8 **)(rec + 4);
                    count = rec[8];
                    for (i = 0; i < count; i++, ev += 8) {
                        evTime = *(f32 *)ev;
                        if (wrap != 0 && evTime <= tStart) {
                            evTime += 1.0f;
                        }
                        if (tStart <= evTime && evTime <= tEnd) {
                            switch (ev[4]) {
                                case 0:
                                    charSpeak(obj, ev[5]);
                                    break;
                                case 1:
                                    charPlaySoundEffect(obj, ev[5]);
                                    break;
                            }
                        }
                    }
                }
                recType = *(s8 *)(rec + 0xC);
                rec += 0xC;
            } while (recType != -1);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/charAnimSoundTick.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
f32 cameraGetBlend(s32 arg0) {
    return *(f32 *)(D_800F6E70_B1820 + arg0 * 0x2C);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/cameraGetBlend.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8002B378(Object *obj, u8 *state, f32 t) {
    ObjectTransform *tr = (ObjectTransform *) obj;
    s8 camNo = *(s8 *)state;
    void *track;
    u8 *lvl;
    s16 newBlock;
    f32 floorY;
    f32 curY;
    void *extra;
    u8 mode;

    if (camNo < mainGetNumberOfCameras()) {
        func_8002F0E8(camNo, tr->x_position, tr->y_position, tr->z_position);
        if (animseqCamera(0, controlcam) == 0) {
            if (*(s32 *)(state + 0x5C0) != 0) {
                chestcameraUpdate(t, controlcam, *(s32 *)(state + 0x5C0), (s32) t);
            } else if (state[0x1FA] != 0) {
                arcadecameraUpdate(t, controlcam, (s32) t);
            } else if (state[0x198] != 0) {
                terminalCameraUpdate(t, controlcam, (s32) t);
            } else {
                mode = state[0x1F9];
                if (mode == 2) {
                    girlMagicCamera(t, controlcam, (s32) t);
                } else if (mode != 0) {
                    func_8002BC64(tr, state, t);
                } else if (state[0x19D] >= 2) {
                    mizarCutCamera(t, controlcam, state, (s32) t);
                } else if (staticcamInuse(t, *(s32 *)(state + 0x5C0)) != 0) {
                    staticcamPosition(t, controlcam);
                } else {
                    u8 flags = state[0x568];
                    if (flags & 0x20) {
                        if (state[0x18E] != 0) {
                            sidekickpadCamera(t, tr, controlcam, (s32) t);
                        } else {
                            func_8002B8C0(tr, state, t);
                        }
                    } else {
                        u8 f2 = state[0x10D];
                        if (f2 & 1) {
                            func_8002BFD0(tr, state, t);
                        } else if (f2 & 2) {
                            transformerCamera(t, controlcam, (s32) t);
                        } else if (state[0x19F] != 0) {
                            hovershipCamera(t, controlcam, (s32) t);
                        } else if (flags == 0xB) {
                            func_8002C078(tr, state, t);
                        } else if ((*(s8 *)(state + 1) & 3) == 3) {
                            splinecamMovementCheck(t, controlcam, tr, t);
                        } else if (flags == 5) {
                            func_8002C078(tr, state, t);
                        } else if (lobbycamInuse(t, controlcam) != 0) {
                            func_8002C868(tr, state, t);
                        } else if (*(s16 *)(state + 0x1FC) >= 0) {
                            func_8002C900(tr, state, t);
                        } else {
                            func_8002CF78(tr, state, t);
                        }
                    }
                }
            }
        }
        track = trackGetTrack();
        if (track != NULL) {
            floorY = (f32) *(s16 *)((u8 *)track + 0x24) - 100.0f;
            curY = *(f32 *)(controlcam + 0x10);
            if (curY < floorY) {
                *(f32 *)(controlcam + 0x10) = curY + ((floorY - curY) * 0.175f);
            }
        }
        lvl = (u8 *) levelGetLevel();
        newBlock = trackGetBlock(*(f32 *)(controlcam + 0xC), *(f32 *)(controlcam + 0x10),
                                 *(f32 *)(controlcam + 0x14));
        if (newBlock != -1 && newBlock != *(s16 *)(lvl + 0x10E) && newBlock != *(s16 *)(lvl + 0x110)) {
            *(s16 *)(controlcam + 0x3E) = newBlock;
        }
        extra = *(void **)((u8 *)obj + 0x54);
        if (extra != NULL) {
            if (*(u8 *)((u8 *)levelGetLevel() + 0xDF) == 0) {
                *(f32 *)((u8 *)extra + 0x10) = *(f32 *)(controlcam + 0xC) - tr->x_position;
                *(f32 *)((u8 *)extra + 0x14) = *(f32 *)(controlcam + 0x10) - tr->y_position;
                *(f32 *)((u8 *)extra + 0x18) = *(f32 *)(controlcam + 0x14) - tr->z_position;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_8002B378.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8002B8C0(ObjectTransform *obj, u8 *state, f32 t) {
    Object *player;
    s16 rot[3];
    f32 vA[3];
    f32 vB[3];
    s16 yaw = obj->y_rotation;
    s16 pitch = -obj->x_rotation;
    s16 roll = 0;
    s16 v;
    f32 frac = 0.0f;
    f32 zOff;
    f32 blend;
    f32 tx;
    f32 ty;
    f32 tz;
    f32 cur;

    player = mainGetGameCharacter((s8) state[0], (s8) state[1]);
    *(s16 *)(state + 0x10A) = 0;
    *(f32 *)((u8 *)camGetPtr() + 0x2C) = 60.0f;

    if (*((u8 *)player + 0x70) != 7) {
        v = *(s16 *)(state + 0x1E2);
        if (v > 0) {
            pitch -= (s32) (v * 0xDC) >> 8;
        } else {
            pitch -= (s32) (v * 0xA0) >> 8;
        }
    } else {
        pitch -= *(s16 *)(state + 0x1E2);
    }
    v = *(s16 *)(state + 0x1E2);
    if (v >= 0x38F) {
        frac = (f32) (v - 0x38E) / 4551.11f;
    }
    if (v < -0x38E) {
        frac = (f32) (-0x38E - v) / 4551.11f;
    }
    if (frac > 1.0f) {
        frac = 1.0f;
    }
    zOff = (-105.0f * frac) + 150.0f;
    pitch = -pitch;

    rot[0] = yaw;
    rot[1] = pitch;
    rot[2] = roll;
    vA[0] = 0.0f;
    vA[1] = 0.0f;
    vA[2] = zOff;
    pointListRPY(1, rot, (s32 *) vA, vA);

    vB[0] = 0.0f;
    vB[1] = 60.0f;
    vB[2] = 0.0f;
    pointListRPY(1, (s16 *) obj, (s32 *) vB, vB);

    tx = vB[0] + (obj->x_position + vA[0]);
    ty = vB[1] + (obj->y_position + vA[1]);
    tz = vB[2] + (obj->z_position + vA[2]);

    blend = 1.0f;
    if (state[0x574] != 0) {
        blend = 1.0f - Powerf(0.875f, (s32) t);
    }
    *(s16 *)(controlcam + 0x0) = dAngle(*(s16 *)(controlcam + 0x0), (s16) (0x8000 - yaw), blend);
    *(s16 *)(controlcam + 0x2) = dAngle(*(s16 *)(controlcam + 0x2), (s16) (pitch * -1), blend);
    *(s16 *)(controlcam + 0x4) = dAngle(*(s16 *)(controlcam + 0x4), roll, 1.0f);

    blend = 1.0f;
    if (state[0x574] != 0) {
        blend = 1.0f - Powerf(0.875f, (s32) t);
    }
    cur = *(f32 *)(controlcam + 0xC);
    *(f32 *)(controlcam + 0xC) = cur + ((tx - cur) * blend);
    cur = *(f32 *)(controlcam + 0x10);
    *(f32 *)(controlcam + 0x10) = cur + ((ty - cur) * blend);
    cur = *(f32 *)(controlcam + 0x14);
    *(f32 *)(controlcam + 0x14) = cur + ((tz - cur) * blend);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_8002B8C0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8002BC64(ObjectTransform *obj, u8 *state, f32 t) {
    f32 camX = *(f32 *)(controlcam + 0xC);
    f32 camY = *(f32 *)(controlcam + 0x10);
    f32 camZ = *(f32 *)(controlcam + 0x14);
    f32 dx = camX - obj->x_position;
    f32 dy = camY - obj->y_position;
    f32 dz = camZ - obj->z_position;
    f32 dist = sqrtf((dx * dx) + (dz * dz));
    s32 n = (s32) t;
    s16 yawTarget = 0x6000 - obj->y_rotation;
    f32 k;
    f32 dist2;
    f32 dy2;
    f32 tx;
    f32 ty;
    f32 tz;
    f32 f;
    f32 rx;
    f32 ry;
    f32 rz;
    f32 vA[3];
    s16 yawOut;
    s16 pitchOut;

    *(s16 *)(state + 0x104) = dAngle(*(s16 *)(state + 0x104), yawTarget, 1.0f - Powerf(0.9f, n));
    k = 1.0f - Powerf(0.925f, n);
    dist2 = (k * (120.0f - dist)) + dist;
    dy2 = (k * (50.0f - dy)) + dy;
    tx = (Sinf(*(s16 *)(state + 0x104)) * dist2) + obj->x_position;
    ty = obj->y_position + dy2;
    tz = obj->z_position - (Cosf((s32) *(s16 *)(state + 0x104)) * dist2);

    f = 1.0f - Powerf(0.9334f, n);
    *(f32 *)(controlcam + 0xC) = camX + ((tx - camX) * f);
    *(f32 *)(controlcam + 0x10) = camY + ((ty - camY) * f);
    *(f32 *)(controlcam + 0x14) = camZ + ((tz - camZ) * f);

    vA[0] = 0.0f;
    vA[1] = 45.0f;
    vA[2] = -80.0f;
    pointListRPY(1, (s16 *) obj, (s32 *) vA, vA);
    rx = *(f32 *)(controlcam + 0xC) - (vA[0] + obj->x_position);
    ry = *(f32 *)(controlcam + 0x10) - (vA[1] + obj->y_position);
    rz = *(f32 *)(controlcam + 0x14) - (vA[2] + obj->z_position);
    yawOut = (s16) (0x8000 - Arctanf(rx, rz));
    pitchOut = (s16) Arctanf(ry, sqrtf((rx * rx) + (rz * rz)));

    f = 1.0f - Powerf(0.9f, n);
    *(s16 *)(controlcam + 0x0) = dAngle(*(s16 *)(controlcam + 0x0), yawOut, f);
    *(s16 *)(controlcam + 0x2) = dAngle(*(s16 *)(controlcam + 0x2), pitchOut, f);
    *(s16 *)(controlcam + 0x4) = dAngle(*(s16 *)(controlcam + 0x4), 0, f);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_8002BC64.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8002BFD0(ObjectTransform *obj, u8 *state, f32 t) {
    Object *target = *(Object **)(state + 0x50C);
    u8 *tExt;

    if (target != NULL) {
        tExt = (u8 *)target->racer;
        *(f32 *)(controlcam + 0xC) = target->segment.trans.x_position;
        *(f32 *)(controlcam + 0x10) = target->segment.trans.y_position;
        *(f32 *)(controlcam + 0x14) = target->segment.trans.z_position;
        *(s16 *)(controlcam + 0x4) = *(s16 *)(tExt + 0x64);
        *(s16 *)(controlcam + 0x2) = *(s16 *)(tExt + 0x62);
        *(s16 *)(controlcam + 0x0) = (s16) -*(s16 *)(tExt + 0x60);
        camSetWaterLine(camGetNo(target), 0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_8002BFD0.s")
#endif

void func_8002C070(void) {
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Camera follow helper. state[0x568]==5 selects a different start table (D_800A2CAC vs
// D_800A2C88) and a different end value for sp94. Two 4-float entries are lerped into pts.
void func_8002C078(ObjectTransform *obj, u8 *state, f32 t) {
    s16 rot[3];                 /* sp78: yaw, pitch, roll */
    f32 offs[3];                /* spC4 */
    f32 pts[8];                 /* sp98: two lerped 4-float entries */
    f32 pos[3];                 /* spB8 */
    f32 target[3];              /* spD0 */
    struct {
        void *obj;
        f32 pos[3];
    } hit;                      /* sp4C */
    f32 sp94;
    f32 eb;                     /* eased blend stored at ent+0x18 */
    f32 blend;
    f32 *tabA;
    f32 *tabB;
    void *chr;
    u8 *ent;
    s32 steps;
    s32 i;
    s32 e2;

    chr = mainGetGameCharacter(*(s8 *)state, *(s8 *)(state + 1));
    ent = D_800F6E58_B1808 + ((*(s8 *)state & 3) * 0x2C);
    *(s16 *)(state + 0x10A) = 0;
    /* asm also passes ent in $a2; the callee's C definition takes only two args */
    ((void (*)(s32, f32, u8 *)) func_8002F45C)(*(s8 *)(state + 1), 1.0f, ent);

    steps = (s32) t;
    eb = *(f32 *)(ent + 0x18);
    eb = eb + ((1.0f - eb) * (1.0f - Powerf(0.98f, steps)));
    *(f32 *)(ent + 0x1C) = 0.0f;
    *(f32 *)(ent + 0x18) = eb;

    if (state[0x568] == 5) {
        tabA = (f32 *) &D_800A2CAC_A38AC;
        sp94 = ((*(f32 *) D_800A2CA8_A38A8 - *(f32 *) D_800A2C60_A3860) * eb) + *(f32 *) D_800A2C60_A3860;
    } else {
        tabA = (f32 *) D_800A2C88_A3888;
        sp94 = ((*(f32 *) D_800A2C84_A3884 - *(f32 *) D_800A2C60_A3860) * eb) + *(f32 *) D_800A2C60_A3860;
    }
    tabB = (f32 *) D_800A2C64_A3864;
    for (i = 0; i < 8; i++) {
        pts[i] = ((tabA[i] - tabB[i]) * eb) + tabB[i];
    }

    *(f32 *)((u8 *) camGetPtr() + 0x2C) = (eb * 8.0f) + 52.0f;

    if (((*(s8 *)(state + 1) & 3) == 2) && (*(u8 *)((u8 *) chr + 0x70) == 7)) {
        e2 = *(s16 *)(state + 0x1E2);
        rot[0] = obj->y_rotation;
        /* asm: sp7A = -(-x - E2) = x + E2 (stored via a temporary, then negated) */
        rot[1] = (s16) (obj->x_rotation + e2);
        rot[2] = 0;
        offs[0] = 0.0f;
        offs[1] = 6.0f;
        offs[2] = 16.0f;
        pointListRPY(1, rot, (s32 *) offs, offs);
        pos[0] = *(f32 *)(state + 0x544);
        pos[1] = *(f32 *)(state + 0x548);
        pos[2] = *(f32 *)(state + 0x54C);
    } else {
        e2 = *(s16 *)(state + 0x1E2);
        rot[0] = obj->y_rotation;
        rot[1] = -obj->x_rotation;
        rot[2] = 0;
        if (*(u8 *)((u8 *) chr + 0x70) != 7) {
            rot[1] = (s16) (rot[1] - ((e2 * 0x120) >> 8));
        } else {
            rot[1] = (s16) (rot[1] - e2);
        }
        rot[1] = (s16) -rot[1];
        /* asm: two empty "if (E2 < 0x38F)" / "if (E2 < -0x38E)" checks here, no effect */
        offs[0] = 0.0f;
        offs[1] = 0.0f;
        offs[2] = pts[2];       /* asm: spCC = spA0 = pts[2] */
        pointListRPY(1, rot, (s32 *) offs, offs);
        pointListRPY(1, (s16 *) obj, (s32 *) &sp94, pos);
        pos[0] += obj->x_position;
        pos[1] += obj->y_position;
        pos[2] += obj->z_position;
    }

    target[0] = pos[0] + offs[0];
    target[1] = pos[1] + offs[1];
    target[2] = pos[2] + offs[2];

    if (trackNearestIntersection((s32) obj, pos, target, &hit, 0x2000, 0) != 0) {
        f32 dx = pos[0] - hit.pos[0];
        f32 dy = pos[1] - hit.pos[1];
        f32 dz = pos[2] - hit.pos[2];

        if (1024.0f < ((dx * dx) + (dy * dy) + (dz * dz))) {
            target[0] = hit.pos[0];
            target[1] = hit.pos[1];
            target[2] = hit.pos[2];
        } else {
            target[0] = 0.0f;
            target[1] = 0.0f;
            target[2] = 32.0f;
            pointListRPY(1, rot, (s32 *) target, target);
            target[0] += pos[0];
            target[1] += pos[1];
            target[2] += pos[2];
        }
    }

    blend = 1.0f;
    if (state[0x574] != 0) {
        blend = 1.0f - Powerf(0.875f, steps);
    }
    *(s16 *)(controlcam + 0x0) = dAngle(*(s16 *)(controlcam + 0x0), (s16) (0x8000 - rot[0]), blend);
    *(s16 *)(controlcam + 0x2) = dAngle(*(s16 *)(controlcam + 0x2), (s16) (-rot[1]), blend);
    *(s16 *)(controlcam + 0x4) = dAngle(*(s16 *)(controlcam + 0x4), rot[2], blend);
    /* asm recomputes the same 1.0 - Powerf(0.875, t) here; value identical, so reused */
    *(f32 *)(controlcam + 0xC) = ((target[0] - *(f32 *)(controlcam + 0xC)) * blend) + *(f32 *)(controlcam + 0xC);
    *(f32 *)(controlcam + 0x10) = ((target[1] - *(f32 *)(controlcam + 0x10)) * blend) + *(f32 *)(controlcam + 0x10);
    *(f32 *)(controlcam + 0x14) = ((target[2] - *(f32 *)(controlcam + 0x14)) * blend) + *(f32 *)(controlcam + 0x14);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_8002C078.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8002C868(ObjectTransform *obj, u8 *state, f32 t) {
    *(f32 *)(D_800F7888 + 0x8) = obj->x_position;
    *(f32 *)(D_800F7888 + 0xC) = obj->y_position;
    *(f32 *)(D_800F7888 + 0x10) = obj->z_position;
    *(s16 *)(D_800F7888 + 0x0) = obj->y_rotation;
    *(s16 *)(D_800F7888 + 0x2) = obj->x_rotation;
    *(s16 *)(D_800F7888 + 0x6) = 0;
    *(s16 *)(D_800F7888 + 0x4) = obj->z_rotation;
    lobbycamPosition(t, D_800F7888, controlcam, (s32) t, state[0x574]);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_8002C868.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8002C900(ObjectTransform *obj, u8 *state, f32 t) {
    f32 sp6C;
    f32 sp68;
    f32 sp64;
    s16 sp5E;
    s16 sp5C;
    s16 sp5A;
    f32 blend;

    if (controlDkeys & 0xF00) {
        controlcam[0x3D] = (u8) ((controlcam[0x3D] + 1) & 1);
    }
    *(f32 *)(D_800F7888 + 0x8) = obj->x_position;
    *(f32 *)(D_800F7888 + 0xC) = obj->y_position;
    *(f32 *)(D_800F7888 + 0x14) = 0.0f;
    *(f32 *)(D_800F7888 + 0x18) = 0.0f;
    *(f32 *)(D_800F7888 + 0x10) = obj->z_position;
    *(f32 *)(D_800F7888 + 0x1C) = -48.0f;
    if (controlcam[0x3D] != 0) {
        *(s16 *)(D_800F7888 + 0x0) = obj->y_rotation;
        *(s16 *)(D_800F7888 + 0x2) = obj->x_rotation;
        *(s16 *)(D_800F7888 + 0x4) = obj->z_rotation;
        *(s16 *)(D_800F7888 + 0x6) = 0;
    } else {
        *(s16 *)(D_800F7888 + 0x6) = 2;
    }
    splinecamCameraPos(state + 0x1FC, state + 0x21C, obj->x_position, obj->y_position, obj->z_position);
    chargeEffectCreate(state + 0x1FC, state + 0x21C, D_800F7888, &sp6C, &sp68, &sp64, &sp5E, &sp5C, &sp5A);

    blend = 1.0f;
    if (state[0x574] != 0) {
        blend = 1.0f - Powerf(0.875f, (s32) t);
    }
    *(s16 *)(controlcam + 0x0) = dAngle(*(s16 *)(controlcam + 0x0), sp5E, blend);
    *(s16 *)(controlcam + 0x2) = dAngle(*(s16 *)(controlcam + 0x2), sp5C, blend);
    *(s16 *)(controlcam + 0x4) = dAngle(*(s16 *)(controlcam + 0x4), sp5A, blend);
    *(f32 *)(controlcam + 0xC) = *(f32 *)(controlcam + 0xC) + ((sp6C - *(f32 *)(controlcam + 0xC)) * blend);
    *(f32 *)(controlcam + 0x10) = *(f32 *)(controlcam + 0x10) + ((sp68 - *(f32 *)(controlcam + 0x10)) * blend);
    *(f32 *)(controlcam + 0x14) = *(f32 *)(controlcam + 0x14) + ((sp64 - *(f32 *)(controlcam + 0x14)) * blend);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_8002C900.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// asm: a0 = ray origin (3 floats), a1 = point being moved; a2 is spilled but never read.
// Hit record {obj ptr, hit point} lives in the frame at sp+0x74..0x80. Ground heights come
// back from trackCylinderHeights as an array of f32 pointers (sp+0x40).
s32 func_8002CBD0(f32 *a0, f32 *a1, s32 a2) {
    f32 from[3];
    struct {
        void *obj;
        f32 pos[3];
    } hit;
    f32 origY;
    f32 **heights;
    s32 state = 1;
    s32 done = 0;
    s32 count;
    s32 ret;
    s32 i;
    f32 **pp;

    (void)a2;
    from[0] = a0[0];
    from[1] = a0[1];
    from[2] = a0[2];
    origY = a1[1];
    do {
        if (trackNearestIntersection(0, from, a1, &hit.obj, 0, 0) == 0) {
            done = 1;
        } else {
            s32 takeFinal = 1;

            if (state != 2 && hit.obj != NULL) {
                s16 bid = *(s16 *)((u8 *)hit.obj + 0x48);

                state = 2;
                if (bid == 0x30 || bid == 0x31) {
                    from[0] = hit.pos[0];
                    from[1] = hit.pos[1];
                    from[2] = hit.pos[2];
                    a1[1] = hit.pos[1];
                    takeFinal = 0;
                }
            }
            if (takeFinal) {
                state = 3;
                a1[0] = hit.pos[0];
                a1[1] = hit.pos[1];
                a1[2] = hit.pos[2];
                done = 1;
            }
        }
    } while (!done);

    count = trackCylinderHeights(a1[0], a1[2], -32000.0f, 32000.0f, 16.0f, 0xC00, 1, (s32)&heights);
    for (i = count - 1; i >= 0; i--) {
        f32 h = *heights[i];

        if (((h - 16.0f) < a1[1]) && (a1[1] < (h + 1.0f))) {
            a1[1] = h - 16.0f;
        }
    }

    count = trackCylinderHeights(a1[0], a1[2], -32000.0f, 32000.0f, 16.0f, 0xC00, 0, (s32)&heights);
    for (i = count - 1; i >= 0; i--) {
        f32 h = *heights[i];

        if (((h - 1.0f) < a1[1]) && (a1[1] < (h + 16.0f))) {
            a1[1] = h + 16.0f;
        }
    }
    ret = 0;

    if (state == 1) {
        ret = trackCylinderHeights(a1[0], a1[2], -32000.0f, 32000.0f, 16.0f, 0xC00, 0, (s32)&heights);
        if (ret > 0) {
            /* asm: empty scan over heights[1..ret) (t0 is hard-wired to 0) */
            for (pp = heights + 1; pp < heights + ret; pp++) {
            }
        }
        if (a1[1] < origY) {
            a1[1] = origY;
        }
    }
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_8002CBD0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8002CF78(ObjectTransform *obj, u8 *state, f32 t) {
    s32 steps;
    s32 keyDown;        /* spDC: controlKeys & 0x10 */
    s32 keyBrake;       /* spD8: state540 & 0xF, cleared if frontGetTargetControl != 0 */
    s32 turnKey;        /* spCC */
    s32 flagD4;         /* spD4, set by func_8002F2BC */
    s32 flagE0;         /* spE0, set by func_8002F2BC / state186 */
    s32 cylHit;         /* a0 flag from the cylinder path (spE4) */
    s32 cnt;
    s32 last;
    s32 a1;
    s32 takeArctan;
    s32 i;
    f32 vec[9];         /* sp68..sp88 */
    f32 tgt[3];         /* sp8C, sp90, sp94: camera target */
    f32 pt[3];          /* sp98, sp9C, spA0 */
    f32 **heights;      /* sp50 */
    f32 **pp;
    f32 f2v;
    f32 d0;
    f32 d1;
    f32 dist;
    f32 dx;
    f32 dz;
    f32 f14;
    f32 f16;
    f32 stick;
    f32 dist2;
    f32 spA8;
    f32 spA4;
    f32 spAC;
    f32 spB0;
    f32 spB4;
    f32 spB8;
    f32 spBC;
    f32 spC0;
    f32 spC4;
    f32 spC8;
    u8 *rec;
    s16 sp5A;
    s16 sp58;

    /* stick deflection sets the 0x10C flag */
    stick = *(f32 *) (state + 0x4);
    if (state[0x568] == 2 && (stick < -0.5f || stick > 0.5f)) {
        state[0x10C] = 1;
    } else if (stick < -0.75f || stick > 0.75f) {
        state[0x10C] = 1;
    }

    turnKey = 0;
    keyDown = controlKeys & 0x10;
    keyBrake = *(u16 *) (state + 0x540) & 0xF;
    if (frontGetTargetControl((s8) state[0]) != 0) {
        keyBrake = 0;
    }
    if (keyBrake != 0 || keyDown != 0) {
        state[0x10C] = 1;
    } else if (controlKeys & 1) {
        *(s16 *) (state + 0x10A) = (s16) (*(s16 *) (state + 0x10A) - ((s32) t << 8));
        turnKey = 1;
        state[0x10C] = 0;
    } else if (controlKeys & 2) {
        *(s16 *) (state + 0x10A) = (s16) (*(s16 *) (state + 0x10A) + ((s32) t << 8));
        turnKey = 1;
        state[0x10C] = 0;
    }

    steps = (s32) t;
    if (*(s16 *) (state + 0x10A) >= 0x2001) {
        *(s16 *) (state + 0x10A) = 0x2000;
    }
    if (*(s16 *) (state + 0x10A) < -0x2000) {
        *(s16 *) (state + 0x10A) = -0x2000;
    }
    if (state[0x10C] != 0) {
        if (keyDown != 0) {
            *(s16 *) (state + 0x10A) = (s16) (s32) ((f32) *(s16 *) (state + 0x10A) * 0.8f);
        } else {
            *(s16 *) (state + 0x10A) = (s16) (s32) ((f32) *(s16 *) (state + 0x10A) * 0.95f);
        }
        if (*(s16 *) (state + 0x10A) >= -0x1FF && *(s16 *) (state + 0x10A) < 0x200) {
            *(s16 *) (state + 0x10A) = 0;
        }
    }

    rec = D_800F6E58_B1808 + (((s8) state[0] & 3) * 0x2C);
    if (((*(u8 **) (state + 0x360))[5] & state[0x532]) != 0) {
        *(f32 *) (rec + 0x24) = 1.0f;
    }

    spA8 = 1.0f;
    spA4 = 1.0f;
    if (state[0x568] == 2 || state[0x568] == 0xA) {
        *(f32 *) (rec + 0x14) = ((1.0f - Powerf(0.95f, steps)) * (0.35f - *(f32 *) (rec + 0x14)))
                                + *(f32 *) (rec + 0x14);
    } else if (state[0x568] == 1 || (state[0x568] == 2 && *(s8 *)(state + 1) != 2)) {
        *(f32 *) (rec + 0x14) = ((1.0f - Powerf(0.95f, steps)) * (0.6f - *(f32 *) (rec + 0x14)))
                                + *(f32 *) (rec + 0x14);
    } else {
        *(f32 *) (rec + 0x14) = ((1.0f - Powerf(0.875f, steps)) * (1.0f - *(f32 *) (rec + 0x14)))
                                + *(f32 *) (rec + 0x14);
    }

    if (state[0x574] != 0) {
        spA8 = 1.0f - Powerf(0.98f, steps);
    }

    if (keyBrake == 0 || state[0x568] == 6 || state[0x568] == 7 || state[0x568] == 8) {
        *(f32 *) (rec + 0x18) = *(f32 *) (rec + 0x18) + ((0.0f - *(f32 *) (rec + 0x18)) * spA8);
        if (*(f32 *) (rec + 0x18) < 0.05f) {
            *(f32 *) (rec + 0x18) = 0.0f;
        }
    } else {
        *(f32 *) (rec + 0x18) = *(f32 *) (rec + 0x18) + ((1.0f - *(f32 *) (rec + 0x18)) * spA8);
    }

    if (*(s8 *)(state + 0x14A) == 0) {
        *(f32 *) (rec + 0x1C) = ((1.0f - Powerf(0.875f, steps)) * (0.0f - *(f32 *) (rec + 0x1C)))
                                + *(f32 *) (rec + 0x1C);
        if (*(f32 *) (rec + 0x1C) < 0.01f) {
            *(f32 *) (rec + 0x1C) = 0.0f;
        }
    } else {
        *(f32 *) (rec + 0x1C) = ((1.0f - Powerf(0.95f, steps)) * (1.0f - *(f32 *) (rec + 0x1C)))
                                + *(f32 *) (rec + 0x1C);
    }

    if (state[0x19E] == 0) {
        *(f32 *) (rec + 0x20) = ((1.0f - Powerf(0.97f, steps)) * (0.0f - *(f32 *) (rec + 0x20)))
                                + *(f32 *) (rec + 0x20);
        if (*(f32 *) (rec + 0x20) < 0.01f) {
            *(f32 *) (rec + 0x20) = 0.0f;
        }
    } else {
        *(f32 *) (rec + 0x20) = ((1.0f - Powerf(0.98f, steps)) * (1.0f - *(f32 *) (rec + 0x20)))
                                + *(f32 *) (rec + 0x20);
    }

    if (state[0x1FB] == 0) {
        *(f32 *) (rec + 0x28) = ((1.0f - Powerf(0.97f, steps)) * (0.0f - *(f32 *) (rec + 0x28)))
                                + *(f32 *) (rec + 0x28);
        if (*(f32 *) (rec + 0x28) < 0.01f) {
            *(f32 *) (rec + 0x28) = 0.0f;
        }
    } else {
        *(f32 *) (rec + 0x28) = ((1.0f - Powerf(0.98f, steps)) * (1.0f - *(f32 *) (rec + 0x28)))
                                + *(f32 *) (rec + 0x28);
    }

    /* sig mismatch: asm passes the rec+0x14 float as raw bits in $a1 (integer arg) */
    ((void (*)(s32, s32)) func_8002F45C)((s32) (s8) state[1], *(s32 *) (rec + 0x14));
    *(f32 *) ((u8 *) camGetPtr() + 0x2C) =
        (*(f32 *) (rec + 0x18) * (1.0f - *(f32 *) (rec + 0x1C)) * 8.0f) + 52.0f;

    /* vec[0..8] = 9 words copied from D_800A2C60 */
    for (i = 0; i < 9; i++) {
        vec[i] = ((f32 *) D_800A2C60_A3860)[i];
    }

    /* block 1: rec+0x18 */
    if (*(f32 *) (rec + 0x18) != 0.0f) {
        vec[0] = vec[0] + ((*(f32 *) D_800A2C84_A3884 - vec[0]) * *(f32 *) (rec + 0x18));
        for (i = 0; i < 8; i++) {
            vec[i + 1] = vec[i + 1] + ((((f32 *) D_800A2C88_A3888)[i] - vec[i + 1]) * *(f32 *) (rec + 0x18));
        }
    }
    /* block 2: rec+0x1C */
    if (*(f32 *) (rec + 0x1C) != 0.0f) {
        vec[0] = vec[0] + ((*(f32 *) D_800A2CCC_A38CC - vec[0]) * *(f32 *) (rec + 0x1C));
        for (i = 0; i < 8; i++) {
            vec[i + 1] = vec[i + 1] + ((((f32 *) D_800A2CD0_A38D0)[i] - vec[i + 1]) * *(f32 *) (rec + 0x1C));
        }
    }
    /* block 3: rec+0x20 */
    if (*(f32 *) (rec + 0x20) != 0.0f) {
        vec[0] = vec[0] + ((*(f32 *) D_800A2CF0_A38F0 - vec[0]) * *(f32 *) (rec + 0x20));
        for (i = 0; i < 8; i++) {
            vec[i + 1] = vec[i + 1] + ((((f32 *) D_800A2CF4_A38F4)[i] - vec[i + 1]) * *(f32 *) (rec + 0x20));
        }
    }
    /* block 4: rec+0x28 */
    if (*(f32 *) (rec + 0x28) != 0.0f) {
        vec[0] = vec[0] + ((*(f32 *) D_800A2D14_A3914 - vec[0]) * *(f32 *) (rec + 0x28));
        for (i = 0; i < 8; i++) {
            vec[i + 1] = vec[i + 1] + ((((f32 *) D_800A2D18_A3918)[i] - vec[i + 1]) * *(f32 *) (rec + 0x28));
        }
    }

    /* distance from camera to object, XZ plane */
    dx = *(f32 *) (controlcam + 0xC) - obj->x_position;
    dz = *(f32 *) (controlcam + 0x14) - obj->z_position;
    spBC = dx;
    spB4 = dz;
    dist = sqrtf((dx * dx) + (dz * dz));
    spC0 = dist;
    if (dist > 240.0f) {
        f14 = 1.0f;
        f16 = 1.0f;
    } else if (dist > 220.0f) {
        f14 = 1.0f;
        f16 = (dist - 220.0f) / 20.0f;
    } else if (dist > 200.0f) {
        f16 = 0.0f;
        f14 = (dist - 200.0f) / 20.0f;
    } else if (dist > 115.0f) {
        f14 = 0.0f;
        f16 = 0.0f;
    } else if (dist > 85.0f) {
        f16 = 0.0f;
        f14 = (dist - 115.0f) / -30.0f;
    } else {
        f14 = 1.0f;
        f16 = 0.0f;
    }
    spC8 = f14;
    spC4 = f16;
    *(f32 *) (state + 0x110) = *(f32 *) (state + 0x110)
        + ((f14 - *(f32 *) (state + 0x110)) * (1.0f - Powerf(0.75f, steps)));
    *(f32 *) (state + 0x114) = *(f32 *) (state + 0x114)
        + ((f16 - *(f32 *) (state + 0x114)) * (1.0f - Powerf(0.75f, steps)));

    spAC = vec[4];
    spB0 = vec[3];
    func_8002F2BC((s32) (s8) state[0], &spB0, &spAC, &flagE0, tgt, &flagD4, (s32) state[0x574], steps);

    if (*(s8 *)(state + 0x186) != 0) {
        tgt[0] = *(f32 *) (controlcam + 0xC);
        tgt[1] = *(f32 *) (controlcam + 0x10);
        tgt[2] = *(f32 *) (controlcam + 0x14);
        flagE0 = 1;
    }

    /* yaw: arctan path, or the dAngle blend path (block_108 in m2c) */
    if (keyDown == 0 && keyBrake == 0 && state[0x574] != 0
        && !(*(f32 *) (state + 0x114) > 0.05f) && *(f32 *) (rec + 0x1C) == 0.0f) {
        /* the state568 'switch' is a beq chain on 6, 7, 8 and 0xC (no jump table) */
        if (state[0x568] == 6 || state[0x568] == 7 || state[0x568] == 8 || state[0x568] == 0xC) {
            takeArctan = 0;
        } else if (*(s16 *) (state + 0x10A) == 0 && turnKey == 0) {
            takeArctan = 1;
        } else if (flagD4 != 0 && state[0x10C] == 0) {
            takeArctan = 0;
        } else {
            takeArctan = 1;
        }
    } else {
        takeArctan = 0;
    }

    if (takeArctan != 0) {
        *(s16 *) (state + 0x104) = (s16) (0x8000 - Arctanf(spBC, spB4));
    } else {
        if (keyDown != 0 && keyBrake == 0) {
            f2v = 0.125f;
        } else {
            f2v = vec[5];
        }
        if (state[0x574] != 0) {
            spA8 = 1.0f - Powerf(1.0f - f2v, steps);
        }
        if ((*(s8 *)(state + 1) & 3) == 3) {
            a1 = (s16) (0x8000 - *(s16 *) (state + 0x128));
        } else {
            a1 = (s16) (0x8000 - obj->y_rotation);
        }
        if (flagD4 != 0) {
            a1 = (s16) (a1 + *(s16 *) (state + 0x10A));
        }
        *(s16 *) (state + 0x104) = dAngle(*(s16 *) (state + 0x104), (s16) a1, spA8);
    }

    if (flagE0 == 0) {
        if (*(f32 *) (rec + 0x18) != 0.0f || (turnKey != 0 && flagD4 != 0)) {
            spB0 = vec[3];
            spAC = spAC + ((vec[4] - spAC) * *(f32 *) (rec + 0x18));
        } else {
            spB0 = *(f32 *) (rec + 0x10)
                * (spC0 + ((vec[3] - spC0) * (1.0f - Powerf(1.0f - *(f32 *) (state + 0x110), steps))));
        }
        tgt[0] = (Sinf(*(s16 *) (state + 0x104)) * spB0) + obj->x_position;
        tgt[1] = obj->y_position + spAC;
        tgt[2] = obj->z_position - (Cosf((s32) *(s16 *) (state + 0x104)) * spB0);
    }

    if (state[0x568] == 8 || (state[0x568] == 3 && *(f32 *) (rec + 0x18) == 0.0f)) {
        if (*(f32 *) (state + 0x57C) < obj->y_position) {
            tgt[1] = tgt[1] + (*(f32 *) (state + 0x57C) - obj->y_position);
        }
    }

    *(u8 *) (controlcam + 0x49) = (u8) (levelGetCamera() + 1);

    if (*(u8 *) (controlcam + 0x49) == 1 && flagE0 == 0) {
        pt[0] = 0.0f;
        pt[1] = 40.0f;
        pt[2] = 0.0f;
        pointListRPY(1, (s16 *) obj, (s32 *) pt, pt);
        pt[0] = pt[0] + obj->x_position;
        pt[1] = pt[1] + obj->y_position;
        pt[2] = pt[2] + obj->z_position;
        if (state[0x568] == 8 || state[0x568] == 6 || state[0x568] == 7) {
            pt[1] = pt[1] + 60.0f;
        } else if (state[0x1FB] != 0) {
            pt[1] = obj->y_position;
        }
        /* sig mismatch: spAC is passed as raw bits in $a2 */
        func_8002CBD0(pt, tgt, *(s32 *) &spAC);
    } else if (*(u8 *) (controlcam + 0x49) == 2 && flagE0 == 0) {
        cylHit = 0;
        cnt = trackCylinderHeights(tgt[0], tgt[2], -32000.0f, 32000.0f, 16.0f, 0xC00, 0, (s32) &heights);
        if (cnt > 0) {
            d1 = 32767.0f;
            last = cnt - 1;
            a1 = 0;
            if (last > 0 && tgt[1] < *heights[0]) {
                do {
                    a1++;
                } while (a1 < last && tgt[1] < *heights[a1]);
            }
            pp = &heights[a1];
            f2v = **pp;
            if (a1 > 0) {
                d1 = tgt[1] - f2v;
                if (d1 < 0.0f) {
                    d1 = -d1;
                }
                pp = pp - 1;
                f2v = **pp;
            }
            d0 = tgt[1] - f2v;
            if (d0 < 0.0f) {
                d0 = -d0;
            }
            if (d0 < d1) {
                if (d0 > 128.0f) {
                    cylHit = 1;
                }
                tgt[1] = f2v + spAC;
            } else {
                if (d1 > 128.0f) {
                    cylHit = 1;
                }
                tgt[1] = *(pp[1]) + spAC;
            }
        }
        if (state[0x574] != 0) {
            spA8 = 1.0f - Powerf(0.95f, steps);
        }
        if (cylHit != 0) {
            *(f32 *) (rec + 0x10) = *(f32 *) (rec + 0x10)
                + ((0.15f - *(f32 *) (rec + 0x10)) * spA8);
        } else {
            *(f32 *) (rec + 0x10) = *(f32 *) (rec + 0x10)
                + ((1.0f - *(f32 *) (rec + 0x10)) * spA8);
        }
    }

    if (state[0x574] != 0) {
        spA8 = 1.0f - Powerf(1.0f - vec[8], steps);
    }
    *(f32 *) (controlcam + 0xC) = ((tgt[0] - *(f32 *) (controlcam + 0xC)) * spA8) + *(f32 *) (controlcam + 0xC);
    *(f32 *) (controlcam + 0x10) = ((tgt[1] - *(f32 *) (controlcam + 0x10)) * spA8) + *(f32 *) (controlcam + 0x10);
    *(f32 *) (controlcam + 0x14) = ((tgt[2] - *(f32 *) (controlcam + 0x14)) * spA8) + *(f32 *) (controlcam + 0x14);
    *(f32 *) (controlcam + 0x18) = *(f32 *) (controlcam + 0xC);
    *(f32 *) (controlcam + 0x1C) = *(f32 *) (controlcam + 0x10);
    *(f32 *) (controlcam + 0x20) = *(f32 *) (controlcam + 0x14);

    /* yaw-change tracking: 0x108 / 0x109 / 0x106 */
    a1 = (s16) (*(s16 *) (state + 0x11C) - *(s16 *) (state + 0x106));
    if (a1 < 0) {
        a1 = -a1;
    }
    if (state[0x108] != 0) {
        if (a1 < 0x500) {
            state[0x109] = (u8) (state[0x109] - 1);
        } else {
            state[0x109] = 5;
        }
        if (state[0x109] == 0) {
            state[0x108] = 0;
        }
    } else {
        if (a1 >= 0x681) {
            state[0x109] = (u8) (state[0x109] - 1);
        } else {
            state[0x109] = 5;
        }
        if (state[0x109] == 0) {
            state[0x108] = 1;
        }
    }
    *(s16 *) (state + 0x106) = *(s16 *) (state + 0x11C);

    if (state[0x108] != 0 || keyBrake != 0 || state[0x568] == 0xA) {
        if (state[0x574] != 0) {
            spA8 = 1.0f - Powerf(0.75f, steps);
        }
        *(f32 *) (state + 0x118) = *(f32 *) (state + 0x118) * spA8;
    } else {
        if (state[0x574] != 0) {
            spA8 = 1.0f - Powerf(0.995f, steps);
        }
        if (state[0x569] != 0) {
            *(f32 *) (state + 0x118) = *(f32 *) (state + 0x118)
                + ((50.0f - *(f32 *) (state + 0x118)) * spA8);
        } else {
            *(f32 *) (state + 0x118) = *(f32 *) (state + 0x118)
                + ((-50.0f - *(f32 *) (state + 0x118)) * spA8);
        }
    }

    dx = *(f32 *) (controlcam + 0xC) - obj->x_position;
    dz = *(f32 *) (controlcam + 0x14) - obj->z_position;
    dist = sqrtf((dx * dx) + (dz * dz));
    if (dist < 90.0f) {
        f14 = 0.0f;
    } else if (dist < 140.0f) {
        f14 = (dist - 90.0f) / 50.0f;
    } else {
        f14 = 1.0f;
    }
    pt[0] = vec[0];
    pt[1] = vec[1];
    pt[2] = vec[2] + (*(f32 *) (state + 0x118) * f14);
    pointListRPY(1, (s16 *) obj, (s32 *) pt, pt);
    spBC = *(f32 *) (controlcam + 0xC) - (pt[0] + obj->x_position);
    spB8 = *(f32 *) (controlcam + 0x10) - (pt[1] + obj->y_position);
    spB4 = *(f32 *) (controlcam + 0x14) - (pt[2] + obj->z_position);

    if (!((((*(u8 **) (state + 0x360))[5] & state[0x532]) != 0))
        && *(f32 *) (rec + 0x1C) == 0.0f
        && *(f32 *) (rec + 0x18) == 0.0f
        && state[0x568] != 4
        && *(f32 *) (state + 0x57C) < obj->y_position
        && (obj->y_position - *(f32 *) (state + 0x57C)) < 108.0f) {
        *(f32 *) (rec + 0x24) = *(f32 *) (rec + 0x24)
            + ((1.0f - *(f32 *) (rec + 0x24)) * (1.0f - Powerf(0.95f, steps)));
    } else {
        *(f32 *) (rec + 0x24) = *(f32 *) (rec + 0x24) * Powerf(0.95f, steps);
    }
    spB8 = spB8 + ((obj->y_position - *(f32 *) (state + 0x57C)) * *(f32 *) (rec + 0x24));
    sp5A = (s16) (0x8000 - Arctanf(spBC, spB4));
    sp58 = (s16) Arctanf(spB8, sqrtf((spBC * spBC) + (spB4 * spB4)));

    if (state[0x574] != 0) {
        spA8 = 1.0f - Powerf(1.0f - vec[6], steps);
        spA4 = 1.0f - Powerf(1.0f - vec[7], steps);
    }
    *(s16 *) controlcam = dAngle(*(s16 *) controlcam, sp5A, spA8);
    *(s16 *) (controlcam + 0x2) = dAngle(*(s16 *) (controlcam + 0x2), sp58, spA4);
    *(s16 *) (controlcam + 0x4) = dAngle(*(s16 *) (controlcam + 0x4), 0, spA8);

    dx = obj->x_position - *(f32 *) (controlcam + 0xC);
    dz = obj->z_position - *(f32 *) (controlcam + 0x14);
    spBC = dx;
    spB4 = dz;
    dist2 = (dx * dx) + (dz * dz);
    spB0 = dist2;
    (void) sqrtf(dist2);
    if (dist2 < 1024.0f) {
        if (dist2 != 0.0f) {
            spB0 = (32.0f / sqrtf(dist2)) - 1.0f;
            spBC = spBC * spB0;
            spB4 = spB4 * spB0;
        }
        objMoveXYZ(obj, spBC, 0.0f, spB4);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_8002CF78.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void cameraTopDown(ObjectTransform *obj, u8 *state, f32 t) {
    s32 steps = (s32) t;
    s32 i;
    s32 t9;
    f32 targetY;

    if (controlKeys & 8) {
        controlcam[0x3D] = (u8) (controlcam[0x3D] - steps);
        if ((s32) controlcam[0x3D] >= 0x51) {
            controlcam[0x3D] = 0;
        }
    }
    if (controlKeys & 4) {
        controlcam[0x3D] = (u8) (controlcam[0x3D] + steps);
        if ((s32) controlcam[0x3D] >= 0x51) {
            controlcam[0x3D] = 0x50;
        }
    }
    t9 = controlcam[0x3D] + 0x28;

    *(f32 *)(controlcam + 0xC) = obj->x_position;
    targetY = obj->y_position + (512.0f * (f32) t9 * 0.025f);
    for (i = 0; i < steps; i++) {
        *(f32 *)(controlcam + 0x10) += (targetY - *(f32 *)(controlcam + 0x10)) * 0.1f;
    }
    *(f32 *)(controlcam + 0x14) = obj->z_position;
    *(s16 *)(controlcam + 0x0) = 0;
    *(s16 *)(controlcam + 0x2) = 0x4000;
    *(s16 *)(controlcam + 0x4) = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/cameraTopDown.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8002EDA0(Object *obj, u8 *state) {
    s32 n;
    s8 idx;

    controlcam = camGetPtr();
    *(s16 *)(controlcam + 0x4) = 0;
    *(s16 *)(controlcam + 0x2) = 0;
    *(s16 *)(controlcam + 0x0) = 0;
    *(f32 *)(controlcam + 0x28) = 48.0f;
    controlcam[0x3D] = 0;
    controlcam[0x44] = 0xFF;
    controlcam[0x45] = 0xFF;
    controlcam[0x46] = 0xFF;
    controlcam[0x47] = 0xFF;
    *(f32 *)(controlcam + 0x40) = 0.0f;
    *(f32 *)(controlcam + 0x24) = 150.0f;
    *(f32 *)(controlcam + 0x28) = 40.0f;
    *(f32 *)(controlcam + 0x10) = obj->segment.trans.y_position + 80.0f;
    *(f32 *)(controlcam + 0x18) = *(f32 *)(controlcam + 0xC);
    *(f32 *)(controlcam + 0x1C) = *(f32 *)(controlcam + 0x10);
    *(f32 *)(controlcam + 0x20) = *(f32 *)(controlcam + 0x14);
    controlcam[0x49] = 1;

    idx = (s8) state[0];
    if (idx >= 0 && idx < 4) {
        u8 *blk = D_800F6E58_B1808 + (idx * 0x2C);
        *(s32 *)(blk + 0x0) = 0;
        *(f32 *)(blk + 0x8) = 0.0f;
        *(f32 *)(blk + 0xC) = 0.0f;
        *(f32 *)(blk + 0x10) = 1.0f;
        *(f32 *)(blk + 0x14) = 1.0f;
        *(f32 *)(blk + 0x18) = 0.0f;
        *(f32 *)(blk + 0x1C) = 0.0f;
        *(f32 *)(blk + 0x20) = 0.0f;
        *(f32 *)(blk + 0x24) = 1.0f;
        *(f32 *)(blk + 0x28) = 0.0f;
    }
    state[0x574] = 0;
    n = 0;
    do {
        func_8002B378(obj, state, 1.0f);
        n += 1;
    } while (n != 8);
    state[0x574] = 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_8002EDA0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void cameraAddOverrideObject(void *obj) {
    if (D_800A2D38_A3938 < 0x18) {
        D_800F6DF8_B17A8[D_800A2D38_A3938] = obj;
        D_800A2D38_A3938 += 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/cameraAddOverrideObject.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void cameraDeleteOverrideObject(void *obj) {
    s32 i;
    s32 found = -1;
    s32 last;

    for (i = 0; i < D_800A2D38_A3938; i++) {
        if (obj == D_800F6DF8_B17A8[i]) {
            found = i;
        }
    }
    last = D_800A2D38_A3938 - 1;
    if (found != -1) {
        for (i = found; i < last; i++) {
            D_800F6DF8_B17A8[i] = D_800F6DF8_B17A8[i + 1];
        }
        D_800A2D38_A3938 = last;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/cameraDeleteOverrideObject.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// asm: a0 = camNo (0..3), a1/a2/a3 = x/y/z floats. Each camNo owns a 0x2C-byte block:
// blk+0 = current target object, blk+4 = its racer. Radii/bounds live in the racer.
void func_8002F0E8(s32 camNo, f32 x, f32 y, f32 z) {
    u8 *blk;
    u8 *racer;
    ObjectTransform *cur;
    ObjectTransform *o;
    f32 dx;
    f32 dz;
    s32 i;

    if (camNo >= 0 && camNo < 4) {
        blk = D_800F6E58_B1808 + camNo * 0x2C;
        cur = *(ObjectTransform **)blk;
        if (cur != NULL) {
            racer = *(u8 **)(blk + 4);
            if (racer != NULL) {
                dx = cur->x_position - x;
                dz = cur->z_position - z;
                if (*(f32 *)(racer + 0xC) * *(f32 *)(racer + 0xC) < dx * dx + dz * dz) {
                    *(ObjectTransform **)blk = NULL;
                    cur = NULL;
                } else if ((*(u32 *)(racer + 0x18) & 0x8000) &&
                           (y < *(f32 *)(racer + 0x14) || *(f32 *)(racer + 0x10) < y)) {
                    *(ObjectTransform **)blk = NULL;
                    cur = NULL;
                }
            }
        }
        if (cur == NULL) {
            for (i = 0; i < D_800A2D38_A3938; i++) {
                o = (ObjectTransform *) D_800F6DF8_B17A8[i];
                racer = *(u8 **)((u8 *)o + 0x68);
                dx = o->x_position - x;
                dz = o->z_position - z;
                if (dx * dx + dz * dz < *(f32 *)racer * *(f32 *)racer) {
                    *(ObjectTransform **)blk = o;
                    *(u8 **)(blk + 4) = racer;
                    if ((*(u32 *)(racer + 0x18) & 0x4000) &&
                        (y < *(f32 *)(racer + 0x8) || *(f32 *)(racer + 0x4) < y)) {
                        *(ObjectTransform **)blk = NULL;
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_8002F0E8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8002F2BC(s32 arg0, f32 *arg1, f32 *arg2, s32 *arg3, f32 *arg4, s32 *arg5, s32 arg6, s32 arg7) {
    u8 *blk;
    u8 *src;
    f32 tx = 0.0f;
    f32 ty = 0.0f;
    s32 flags;
    s32 keep;
    f32 k = 1.0f;

    *arg3 = 0;
    *arg5 = 1;
    if (arg0 >= 0 && arg0 < 4) {
        blk = D_800F6E58_B1808 + arg0 * 0x2C;
        if (*(s32 *)blk != 0) {
            src = *(u8 **)(blk + 4);
            if (src != NULL) {
                flags = *(s32 *)(src + 0x18);
                if (flags & 1) {
                    tx = *(f32 *)(src + 0x1C);
                }
                if (flags & 2) {
                    ty = *(f32 *)(src + 0x20);
                }
                keep = flags & 8;
                if (flags & 4) {
                    *arg3 = 1;
                    arg4[0] = *(f32 *)(src + 0x24);
                    arg4[1] = *(f32 *)(src + 0x28);
                    arg4[2] = *(f32 *)(src + 0x2C);
                    keep = *(s32 *)(src + 0x18) & 8;
                }
                if (keep == 0) {
                    *arg5 = 0;
                }
            }
        }
        if (arg6 != 0) {
            k = 1.0f - Powerf(0.9f, arg7);
        }
        *(f32 *)(blk + 8) = *(f32 *)(blk + 8) + (tx - *(f32 *)(blk + 8)) * k;
        *(f32 *)(blk + 0xC) = *(f32 *)(blk + 0xC) + (ty - *(f32 *)(blk + 0xC)) * k;
        *arg2 += *(f32 *)(blk + 8);
        *arg1 += *(f32 *)(blk + 0xC);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_8002F2BC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8002F45C(s32 arg0, f32 arg1) {
    s32 off = (arg0 & 3) * 4;

    *(f32 *)(D_800A2C60_A3860 + 0x4) = *(f32 *)(D_800A2C20_A3820 + off) * arg1;
    *(f32 *)(D_800A2C84_A3884 + 0x4) = *(f32 *)(D_800A2C30_A3830 + off) * arg1;
    *(f32 *)(D_800A2CCC_A38CC + 0x4) = *(f32 *)(D_800A2C50_A3850 + off) * arg1;
    *(f32 *)(D_800A2C60_A3860 + 0x10) = *(f32 *)(D_800A2BE0_A37E0 + off) * arg1;
    *(f32 *)(D_800A2C84_A3884 + 0x10) = *(f32 *)(D_800A2BF0_A37F0 + off) * arg1;
    D_800A2CAC_A38AC = *(f32 *)(D_800A2C00_A3800 + off) * arg1;
    *(f32 *)(D_800A2CCC_A38CC + 0x10) = *(f32 *)(D_800A2C10_A3810 + off) * arg1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_8002F45C.s")
#endif

// func_setting_floyd_height
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8002F518(s32 arg0, void *arg1, s32 arg2) {
    f32 var_f14;
    f32 var_f12;
    u8 *other;
    u8 *racer;
    u8 kind;

    other = *(u8 **)((u8 *)arg1 + 0x24);
    if (other != NULL) {
        racer = *(u8 **)(other + 0x68);
        kind = racer[0x568];
        if (kind == 2 || kind == 0xA) {
            var_f14 = 0.5f;
            var_f12 = 0.95f;
        } else if (kind != 1) {
            var_f14 = 1.0f;
            var_f12 = 0.875f;
        } else {
            var_f14 = 0.75f;
            var_f12 = 0.95f;
        }
        sidekickHeight += (var_f14 - sidekickHeight) * (1.0f - Powerf(var_f12, arg2));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_8002F518.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void sidekickInit(ObjectTransform *arg0, void *arg1) {
    u8 *state;

    // state = arg0->racer (offset 0x68)
    state = *(u8 **)((u8 *)arg0 + 0x68);
    *(s32 *)(state + 0x24) = *(s32 *)((u8 *)arg1 + 0xC);
    sidekickHeight = 1.0f;
    // asm: caller also stores 0 into its outgoing slot 0x10($sp); callee never reads it
    func_80031CC4(arg0, state, state + 4, state + 8);
    objMoveXYZnocheck();
    objMoveXYZ(arg0, *(f32 *)(state + 0x0) - arg0->x_position,
               *(f32 *)(state + 0x4) - arg0->y_position,
               *(f32 *)(state + 0x8) - arg0->z_position);
    *(s16 *)(state + 0x18) = 0;
    *(s16 *)(state + 0x1A) = 0;
    hitInitObjectHit(arg0, -1, 1, 2, 0, 0, 0, 125.0f, 125.0f, 1.0f, 1.0f, 0x11);
    *(f32 *)(state + 0xC) = arg0->x_position;
    *(f32 *)(state + 0x10) = arg0->y_position;
    *(f32 *)(state + 0x48) = 0.0f;
    *(f32 *)(state + 0x4C) = 0.0f;
    *(f32 *)(state + 0x14) = arg0->z_position;
    state[0x94] = (u8)((cooperativeGame << 7) | (state[0x94] & 0xFF7F));
    *(s32 *)((u8 *)arg0 + 0x88) = 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/sidekickInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// asm: arg1 is the frame delta. state = obj->racer (obj+0x68). Racer state offsets as used by
// sidekickInit / func_8003109C. Target racer flag 0x10D: bit 0 = player-steered sidekick path,
// value 1 = robot counter path, value 3 = after robot path. 0x94 bit 0x80 = cooperativeGame.
// asm: func_80031CC4 also gets delta in its 5th (stack) slot; the C callee does not read it (as in sidekickInit).
// asm: func_8002F518 gets obj in $a0; its C prototype takes an integer, so obj is passed as s32.
// asm: hitBuf is the trackGetPlayerIntersect hit record; the hit normal is at [1..3].
// asm: state+0x96 is the write cursor kept in D_800F6DE8_B1798 (u16 0x2008, s16 phase, u16 0x1000).
void sidekickControl(ObjectTransform *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *state;
    u8 *target;
    u8 *racer;
    u8 *camp;
    u8 *cam;
    s32 delta = arg1;
    f32 dt = (f32) arg1;
    f32 vec[3];
    f32 v4[3];
    f32 hitBuf[4];
    f32 hitVec[3];
    f32 spB0;
    s32 hitIdx;
    u16 mask;
    f32 k;
    f32 k34;
    f32 zin;
    f32 len;
    f32 s28;
    f32 s2c;
    f32 s30;
    f32 a28;
    f32 a2c;
    f32 a30;
    f32 nx;
    f32 ny;
    f32 nz;
    f32 dotv;
    f32 two;
    f32 sinA;
    f32 b0;
    f32 pitchVal;
    f32 sp8C;
    f32 sp60;
    f32 sinV;
    f32 o0;
    f32 o4;
    f32 o8;
    f32 f14;
    s32 v;
    s32 t;
    s32 ty;
    s32 var;
    s32 i;
    s32 orig;
    s32 r1c;
    s32 absA;
    s32 absV;
    s16 *bd;
    s32 ix;
    s32 iy;
    s32 iz;
    s16 blk;
    s16 xr;
    s16 yr;
    u8 volu;

    state = *(u8 **)(obj + 0x68);
    target = *(u8 **)(state + 0x24);
    if (target == NULL) {
        return;
    }
    racer = *(u8 **)(target + 0x68);
    D_800F6DE8_B1798 = state + 0x96;

    if (racer[0x10D] == 0 && multiPlayerGame == 0) {
        if (cooperativeGame == 0) {
            if (joyGetPressed(1) & 0x1000) {
                cooperativeGame = 1;
                state[0x94] = (u8) (state[0x94] | 0x80);
            }
        } else if (joyGetPressed(1) & 0x1000) {
            cooperativeGame = 0;
            state[0x94] = (u8) (state[0x94] & 0xFF7F);
        }
    }
    if (state[0x94] & 0x80) {
        controlReadJoypad(1);
    } else if (racer[0x10D] & 1) {
        if (racer[0x10D] != 1) {
            controlDisableJoypad(1);
        }
        controlReadJoypad(*(s8 *) racer);
    }
    controlDisableJoypad(0);

    *(s16 *) (state + 0x18) = (s16) (*(s16 *) (state + 0x18) + (delta << 8));
    *(s16 *) (state + 0x1A) = (s16) (*(s16 *) (state + 0x1A) + (delta * 0x4800));
    *(f32 *) (state + 0xC) = *(f32 *) (state + 0x0);
    *(f32 *) (state + 0x10) = *(f32 *) (state + 0x4);
    *(f32 *) (state + 0x14) = *(f32 *) (state + 0x8);

    if (!(racer[0x10D] & 1)) {
        /* player not steering the sidekick: follow the racer position */
        func_8002F518((s32) arg0, state, delta);
        func_80031CC4(arg0, &v4[0], &v4[1], &v4[2]);
        if (*(s16 *) (state + 0x90) == 0) {
            f14 = 1.0f;
        } else {
            f14 = 1.0f - Powerf(0.925f, delta);
        }
        o0 = *(f32 *) (state + 0x0);
        o4 = *(f32 *) (state + 0x4);
        o8 = *(f32 *) (state + 0x8);
        *(f32 *) (state + 0x0) = o0 + ((v4[0] - o0) * f14);
        *(f32 *) (state + 0x4) = o4 + ((v4[1] - o4) * f14);
        *(f32 *) (state + 0x6C) = 1.5f;
        *(f32 *) (state + 0x70) = 3.0f;
        *(f32 *) (state + 0x8) = o8 + ((v4[2] - o8) * f14);
        if (*(s16 *) (state + 0x90) != 0) {
            *(s16 *) (obj + 0x6) &= 0xFBFF;
        }
    } else {
        /* player steering: stick input drives the sidekick */
        *(s16 *) (obj + 0x6) |= 0x400;
        k = 1.0f - Powerf(0.9f, delta);

        v = controlAbsXjoy;
        if (v >= 0xD) {
            if (v >= 0x42) {
                v = 0x41;
            }
            var = (0xC - v) * 8;
        } else if (v < -0xC) {
            t = v + 0xC;
            if (v < -0x41) {
                t = -0x35;
            }
            var = -(t * 8);
        } else {
            var = 0;
        }
        t = *(s16 *) (state + 0x66);
        *(s16 *) (state + 0x66) = (s16) (t + (s32) ((f32) (var - t) * k));
        if (var == 0) {
            if (*(s16 *) (state + 0x66) >= -0x11 && *(s16 *) (state + 0x66) < 0x12) {
                *(s16 *) (state + 0x66) = 0;
            }
        }
        *(s16 *) (state + 0x60) = (s16) (*(s16 *) (state + 0x60) + (*(s16 *) (state + 0x66) * delta));

        v = controlAbsYjoy;
        if (v >= 0xD) {
            ty = v * 4;
            if (v >= 0x42) {
                v = 0x41;
                ty = 0x41 * 4;
            }
            var = ((ty - v) * 2) - 0x48;
        } else if (v < -0xC) {
            ty = v * 4;
            if (v < -0x41) {
                v = -0x41;
                ty = -0x41 * 4;
            }
            var = ((ty - v) * 2) + 0x48;
        } else {
            var = 0;
        }
        t = *(s16 *) (state + 0x68);
        *(s16 *) (state + 0x68) = (s16) (t + (s32) ((f32) (var - t) * k));
        if (var == 0) {
            if (*(s16 *) (state + 0x68) >= -0x11 && *(s16 *) (state + 0x68) < 0x12) {
                *(s16 *) (state + 0x68) = 0;
            }
        }
        *(s16 *) (state + 0x62) = (s16) (*(s16 *) (state + 0x62) + (*(s16 *) (state + 0x68) * delta));
        if (*(s16 *) (state + 0x62) >= 0x4001) {
            *(s16 *) (state + 0x62) = 0x4000;
        }
        if (*(s16 *) (state + 0x62) < -0x4000) {
            *(s16 *) (state + 0x62) = -0x4000;
        }
        if (racer[0x10D] == 3) {
            t = *(s16 *) (state + 0x62);
            *(s16 *) (state + 0x62) = (s16) (t - ((t * delta) >> 3));
        }
        k = 1.0f - Powerf(0.95f, delta);
        *(s16 *) (state + 0x64) = dAngle(*(s16 *) (state + 0x64), (s16) (*(s16 *) (state + 0x66) * -0x14), k);
        arg0->z_rotation = *(s16 *) (state + 0x64);
        arg0->x_rotation = *(s16 *) (state + 0x62);
        arg0->y_rotation = *(s16 *) (state + 0x60);

        camp = *(u8 **) (racer + 0x554);
        cam = (u8 *) camGetPtr();
        camUseShake();

        if (controlKeys & 0x8000) {
            *(f32 *) (state + 0x38) = *(f32 *) (state + 0x38) + (dt * 0.02f);
            if (*(f32 *) (state + 0x38) > 1.0f) {
                *(f32 *) (state + 0x38) = 1.0f;
            }
        } else {
            *(f32 *) (state + 0x38) = 0.0f;
        }
        if (controlKeys & 0x4000) {
            *(f32 *) (state + 0x3C) = *(f32 *) (state + 0x3C) + (dt * 0.02f);
            if (*(f32 *) (state + 0x3C) > 1.0f) {
                *(f32 *) (state + 0x3C) = 1.0f;
            }
        } else {
            *(f32 *) (state + 0x3C) = 0.0f;
        }

        vec[0] = 0.0f;
        vec[1] = 0.0f;
        zin = (*(f32 *) (state + 0x38) - *(f32 *) (state + 0x3C)) * dt;
        vec[2] = zin;
        mathOneFloatPY(state + 0x60, vec);

        if (zin != 0.0f) {
            k34 = *(f32 *) (state + 0x34);
            *(f32 *) (state + 0x28) = *(f32 *) (state + 0x28) * k34;
            *(f32 *) (state + 0x2C) = *(f32 *) (state + 0x2C) * k34;
            *(f32 *) (state + 0x30) = *(f32 *) (state + 0x30) * k34;
            v4[0] = vec[0] + *(f32 *) (state + 0x28);
            v4[1] = vec[1] + *(f32 *) (state + 0x2C);
            v4[2] = vec[2] + *(f32 *) (state + 0x30);
            k = 1.0f - Powerf(0.8f, delta);
            a28 = *(f32 *) (state + 0x28);
            a2c = *(f32 *) (state + 0x2C);
            a30 = *(f32 *) (state + 0x30);
            *(f32 *) (state + 0x28) = a28 + ((v4[0] - a28) * k);
            *(f32 *) (state + 0x2C) = a2c + ((v4[1] - a2c) * k);
            *(f32 *) (state + 0x30) = a30 + ((v4[2] - a30) * k);
            s28 = *(f32 *) (state + 0x28);
            s2c = *(f32 *) (state + 0x2C);
            s30 = *(f32 *) (state + 0x30);
            len = sqrtf((s30 * s30) + ((s28 * s28) + (s2c * s2c)));
            *(f32 *) (state + 0x34) = len;
            if (len > 0.0f) {
                *(f32 *) (state + 0x28) = s28 / len;
                *(f32 *) (state + 0x2C) = s2c / len;
                *(f32 *) (state + 0x30) = s30 / len;
                if (len > 8.0f) {
                    *(f32 *) (state + 0x34) = 8.0f;
                }
            }
        } else {
            *(f32 *) (state + 0x34) = *(f32 *) (state + 0x34) * Powerf(0.98f, delta);
            if (*(f32 *) (state + 0x34) < 0.1f) {
                *(f32 *) (state + 0x34) = 0.0f;
            }
        }

        if (*(s16 *) (state + 0x20) != 0) {
            if (*(f32 *) (state + 0x34) > 2.0f) {
                *(f32 *) (state + 0x34) = *(f32 *) (state + 0x34) - (0.5f * dt);
                if (*(f32 *) (state + 0x34) < 2.0f) {
                    *(f32 *) (state + 0x34) = 2.0f;
                }
            }
        } else if (*(s16 *) (state + 0x22) != 0) {
            *(f32 *) (state + 0x34) = *(f32 *) (state + 0x34) * 0.5f;
        }

        k34 = *(f32 *) (state + 0x34);
        *(f32 *) (obj + 0x1C) = *(f32 *) (state + 0x28) * k34;
        *(f32 *) (obj + 0x20) = *(f32 *) (state + 0x2C) * k34;
        *(f32 *) (obj + 0x24) = *(f32 *) (state + 0x30) * k34;
        *(f32 *) (state + 0x0) = *(f32 *) (state + 0x0) + (*(f32 *) (obj + 0x1C) * dt);
        *(f32 *) (state + 0x4) = *(f32 *) (state + 0x4) + (*(f32 *) (obj + 0x20) * dt);
        *(f32 *) (state + 0x8) = *(f32 *) (state + 0x8) + (*(f32 *) (obj + 0x24) * dt);

        k = Powerf(0.95f, delta);
        *(f32 *) (state + 0x6C) = *(f32 *) (state + 0x6C) * k;
        if (*(f32 *) (state + 0x34) > 0.0f) {
            *(f32 *) (state + 0x70) = *(f32 *) (state + 0x70) * k;
        } else {
            *(f32 *) (state + 0x70) = *(f32 *) (state + 0x70) + ((3.0f - *(f32 *) (state + 0x70)) * (1.0f - k));
        }

        if (racer[0x10D] == 1) {
            orig = *(s16 *) (state + 0x1C);
            if (orig > 0 && delta != 0) {
                for (i = 0; i < delta; i++) {
                    robotTime += 1;
                    *(s16 *) (state + 0x1E) = (s16) (*(s16 *) (state + 0x1E) - 1);
                    if (*(s16 *) (state + 0x1E) <= 0) {
                        *(s16 *) (state + 0x1E) = 6;
                        *(s16 *) (state + 0x1C) = (s16) (*(s16 *) (state + 0x1C) - 1);
                    }
                    if (*(s16 *) (state + 0x1C) <= 0) {
                        break;
                    }
                }
            }
            r1c = *(s16 *) (state + 0x1C);
            if (r1c < 0) {
                *(s16 *) (state + 0x1C) = 0;
                r1c = 0;
            }
            if (r1c < 0x65) {
                for (i = 1; i != 11; i++) {
                    v = i * 10;
                    if (v >= r1c && v < orig) {
                        amSndPlay((u16) (i + 0x15F), NULL);
                        break;
                    }
                }
            }
            if (racer[0x10D] == 1 && *(s16 *) (state + 0x1C) == 0) {
                amSndPlay(0x15F, NULL);
                racer[0x10D] = 3;
            }
        }
    }

    if (*(s16 *) (state + 0x90) == 0) {
        *(s16 *) (state + 0x20) = 0;
        *(s16 *) (state + 0x22) = 0;
        *(s16 *) (state + 0x66) = 0;
        *(s16 *) (state + 0x68) = 0;
        *(f32 *) (state + 0x34) = 0.0f;
        *(f32 *) (state + 0x38) = 0.0f;
        *(f32 *) (state + 0x3C) = 0.0f;
        *(f32 *) (state + 0x28) = 0.0f;
        *(f32 *) (state + 0x2C) = 0.0f;
        *(f32 *) (state + 0x30) = 0.0f;
        *(f32 *) (state + 0xC) = *(f32 *) (state + 0x0);
        *(f32 *) (state + 0x10) = *(f32 *) (state + 0x4);
        *(f32 *) (state + 0x14) = *(f32 *) (state + 0x8);
        if (!(racer[0x10D] & 1)) {
            *(s16 *) (obj + 0x6) &= 0xFBFF;
        }
    } else if (racer[0x10D] & 1) {
        /* sidekick is carried by the track: polylist / intersect, then orient to the hit */
        spB0 = *(f32 *) (*(u8 **) (*(u8 **) (obj + 0x40) + 0x50) + 0xC);
        mask = *(u8 *) (*(u8 **) (*(u8 **) (obj + 0x40) + 0x50) + 0x10);
        *(s16 *) (state + 0x22) = 0;
        trackMakePolylist(1, (f32 *) (state + 0xC), (f32 *) state, (s32 *) &spB0, (s32) 0x8E002000, 0, 0);
        if (trackGetPlayerIntersect(obj, NULL, (f32 *) (state + 0xC), (f32 *) state, &spB0, NULL, &mask, hitBuf, 1, &hitIdx, hitVec) != 0) {
            nx = hitBuf[1];
            ny = hitBuf[2];
            nz = hitBuf[3];
            s28 = *(f32 *) (state + 0x28);
            s2c = *(f32 *) (state + 0x2C);
            s30 = *(f32 *) (state + 0x30);
            dotv = (((-s28) * nx) + ((-s2c) * ny)) + (nz * (-s30));
            if (hitIdx >= 0) {
                sinA = Sinf((s16) (Arctanf(ny, sqrtf((nz * nz) + (nx * nx))) - 0x4000));
                len = sqrtf(((nx * nx) + (sinA * sinA)) + (nz * nz));
                *(f32 *) (state + 0x34) = 8.0f;
                *(f32 *) (state + 0x28) = nx / len;
                *(f32 *) (state + 0x2C) = sinA / len;
                *(f32 *) (state + 0x30) = nz / len;
            } else if (*(s16 *) (state + 0x20) == 0 && *(f32 *) (state + 0x34) >= 2.0f && (dotv < -0.2f || dotv > 0.2f)) {
                two = dotv + dotv;
                *(f32 *) (state + 0x28) = (nx * two) - (-s28);
                *(f32 *) (state + 0x2C) = (ny * two) - (-s2c);
                *(f32 *) (state + 0x30) = (nz * two) - (-s30);
                *(f32 *) (state + 0x40) = *(f32 *) (state + 0x34) * 2.5f;
                k = *(f32 *) (state + 0x40);
                *(f32 *) (cam + 0x30) = nx * k;
                *(f32 *) (cam + 0x34) = ny * k;
                *(f32 *) (cam + 0x38) = nz * k;
                *(s16 *) (state + 0x22) = 1;
            } else {
                v4[0] = (ny * s30) - (s2c * nz);
                v4[1] = (nz * s28) - (s30 * nx);
                v4[2] = (nx * s2c) - (s28 * ny);
                *(f32 *) (state + 0x28) = (v4[1] * nz) - (ny * v4[2]);
                *(f32 *) (state + 0x2C) = (v4[2] * nx) - (nz * v4[0]);
                *(f32 *) (state + 0x30) = (v4[0] * ny) - (nx * v4[1]);
                b0 = spB0;
                *(f32 *) (obj + 0xC) = *(f32 *) (state + 0x0) - (nx * b0);
                *(f32 *) (obj + 0x10) = *(f32 *) (state + 0x4) - (ny * b0);
                *(f32 *) (obj + 0x14) = *(f32 *) (state + 0x8) - (nz * b0);
                xr = arg0->x_rotation;
                yr = arg0->y_rotation;
                arg0->y_rotation = (s16) Arctanf(nx, nz);
                arg0->x_rotation = (s16) Arctanf(sqrtf((nz * nz) + (nx * nx)), ny);
                *(s32 *) (obj + 0x84) = 1;
                partUpdateTriggers(arg0, delta);
                arg0->x_rotation = xr;
                arg0->y_rotation = yr;
                *(s16 *) (state + 0x20) = (s16) (*(s16 *) (state + 0x20) + delta);
            }
        } else {
            *(s16 *) (state + 0x20) = 0;
            *(s16 *) (state + 0x22) = 0;
        }
        vec[0] = 0.0f;
        vec[1] = 0.0f;
        vec[2] = 1.0f;
        mathOneFloatPY(state + 0x60, vec);
        camp = *(u8 **) (racer + 0x554);
        *(f32 *) (camp + 0xC) = vec[0] + *(f32 *) (state + 0x0);
        *(f32 *) (camp + 0x10) = vec[1] + *(f32 *) (state + 0x4);
        *(f32 *) (camp + 0x14) = vec[2] + *(f32 *) (state + 0x8);

        k = (f32) *(s16 *) (state + 0x20) * 4.0f;
        if (k > 200.0f) {
            k = 200.0f;
        }
        *(f32 *) (state + 0x44) = *(f32 *) (state + 0x44) + ((k - *(f32 *) (state + 0x44)) * (1.0f - Powerf(0.95f, delta)));
        t = (s32) *(f32 *) (state + 0x44);
        if (t < 0) {
            t = -1;
        }
        *(s8 *) (camp + 0x3B) = (s8) t;
    }

    /* common tail */
    *(s16 *) (state + 0x90) = (s16) (*(s16 *) (state + 0x90) + (delta << 2));
    if (*(s16 *) (state + 0x90) >= 0x100) {
        *(s16 *) (state + 0x90) = 0xFF;
    }
    *(f32 *) (obj + 0xC) = (Sinf((s16) (*(s16 *) (state + 0x18) * 2)) * *(f32 *) (state + 0x6C)) + *(f32 *) (state + 0x0);
    *(f32 *) (obj + 0x10) = (Sinf(*(s16 *) (state + 0x18)) * *(f32 *) (state + 0x70)) + *(f32 *) (state + 0x4);
    *(f32 *) (obj + 0x14) = *(f32 *) (state + 0x8);

    if ((state[0x94] & 0x80) || (racer[0x10D] & 1)) {
        func_8003109C(arg0, state, racer[0x10D], delta);
    } else {
        /* free sidekick: steer toward the target's rotation */
        if (target != NULL) {
            if ((((s8) racer[1]) & 3) == 2 || racer[0x568] == 2) {
                v = 0;
            } else {
                v = *(s16 *) (target + 4);
            }
            k = 1.0f - Powerf(0.9f, delta);
            arg0->y_rotation = dAngle(arg0->y_rotation, (s16) (*(s16 *) target + 0x8000), k);
            arg0->x_rotation = dAngle(arg0->x_rotation, (s16) (-*(s16 *) (target + 2)), k);
            arg0->z_rotation = dAngle(arg0->z_rotation, (s16) v, k);
        }
        *(s16 *) (state + 0x60) = arg0->y_rotation;
        *(s16 *) (state + 0x64) = 0;
        *(s16 *) (state + 0x62) = arg0->x_rotation;
    }

    /* track block lookup */
    ix = (s32) *(f32 *) (obj + 0xC);
    iy = (s32) *(f32 *) (obj + 0x10);
    iz = (s32) *(f32 *) (obj + 0x14);
    blk = *(s16 *) (obj + 0x2E);
    bd = (s16 *) trackBlockDim(blk, iy);
    if (bd == NULL || ix < bd[0] || bd[3] < ix || iy < bd[1] || bd[4] < iy || iz < bd[2] || bd[5] < iz) {
        blk = trackGetBlock((f32) ix, (f32) iy, (f32) iz);
    }
    if (blk != -1) {
        *(s16 *) (obj + 0x2E) = blk;
    }

    /* display list cursor: three entries, then func_80031984 */
    *(u16 *) D_800F6DE8_B1798 = 0x2008;
    D_800F6DE8_B1798 = (u8 *) D_800F6DE8_B1798 + 2;
    *(s16 *) D_800F6DE8_B1798 = *(s16 *) (state + 0x1A);
    D_800F6DE8_B1798 = (u8 *) D_800F6DE8_B1798 + 2;
    *(u16 *) D_800F6DE8_B1798 = 0x1000;
    D_800F6DE8_B1798 = (u8 *) D_800F6DE8_B1798 + 2;
    func_80031984(arg0, state, racer, delta);

    if ((state[0x94] & 0x80) || (racer[0x10D] & 1)) {
        if (*(s32 *) (state + 0x74) == 0) {
            amSndPlay(0xF6, state + 0x74);
        }
        if (*(s32 *) (state + 0x78) == 0) {
            amSndPlay(0xF5, state + 0x78);
        }
        absA = *(s16 *) (state + 0x66);
        if (absA < 0) {
            absA = (s16) (-absA);
        }
        absV = *(s16 *) (state + 0x68);
        if (absV < 0) {
            absV = (s16) (-absV);
        }
        sp8C = *(f32 *) (state + 0x34) * 0.125f * 0.2f;
        sp60 = Sinf((s16) (absA * 45));
        sinV = Sinf((s16) (absV * 45));
        pitchVal = ((sinV * 0.1f) + (0.6f + (sp60 * 0.1f))) + sp8C;
        *(f32 *) (state + 0x84) = *(f32 *) (state + 0x84) + (((0.6f + sp8C) - *(f32 *) (state + 0x84)) * (1.0f - Powerf(0.8f, delta)));
        amSndSetPitchDirect(*(s32 *) (state + 0x74), *(f32 *) (state + 0x84));
        *(f32 *) (state + 0x88) = *(f32 *) (state + 0x88) + ((pitchVal - *(f32 *) (state + 0x88)) * (1.0f - Powerf(0.8f, delta)));
        amSndSetPitchDirect(*(s32 *) (state + 0x78), *(f32 *) (state + 0x88));

        if (*(s16 *) (state + 0x22) != 0) {
            if (*(s32 *) (state + 0x7C) != 0) {
                amSndStop(*(s32 *) (state + 0x7C));
            }
            v = (s32) (*(f32 *) (state + 0x34) * 15.875f);
            if (v < 0) {
                v = -1;
            }
            volu = (u8) v;
            amSndPlay(0x137, state + 0x7C);
            amSndSetVol(0x137, *(s32 *) (state + 0x7C), volu);
        }

        k = (f32) *(s16 *) (state + 0x20) * 4.233333f;
        if (k > 127.0f) {
            k = 127.0f;
        }
        *(f32 *) (state + 0x8C) = *(f32 *) (state + 0x8C) + ((k - *(f32 *) (state + 0x8C)) * (1.0f - Powerf(0.9f, delta)));
        t = (s32) *(f32 *) (state + 0x8C);
        if (t < 0) {
            t = -1;
        }
        volu = (u8) (t & 0xFF);
        if (volu != 0) {
            if (*(s32 *) (state + 0x80) == 0) {
                amSndPlay(0x138, state + 0x80);
            }
            amSndSetPitchDirect(*(s32 *) (state + 0x80), (*(f32 *) (state + 0x34) * 0.125f) + 0.75f);
            amSndSetVol(0x138, *(s32 *) (state + 0x80), volu);
        } else if (*(s32 *) (state + 0x80) != 0) {
            amSndStop(*(s32 *) (state + 0x80));
        }
    } else {
        if (*(s32 *) (state + 0x74) != 0) {
            amSndStop(*(s32 *) (state + 0x74));
        }
        if (*(s32 *) (state + 0x78) != 0) {
            amSndStop(*(s32 *) (state + 0x78));
        }
        if (*(s32 *) (state + 0x7C) != 0) {
            amSndStop(*(s32 *) (state + 0x7C));
        }
        if (*(s32 *) (state + 0x80) != 0) {
            amSndStop(*(s32 *) (state + 0x80));
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/sidekickControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// asm: arg1 is the sidekick racer state. Offsets: 0x24 Object* target (its 0x68 is the
// racer, 0x568 low nibble 0xA = dkey-clear case), 0x48/0x4C aim offsets (f32),
// 0x50 s32 flag, 0x54/0x58 object ptrs, 0x94 flag byte (bit 0x80 = cooperativeGame,
// set in sidekickInit; bit 0x40 = set here when the aim path is blocked).
// asm: hitNear is the trackNearestIntersection output; the f32 at +0x20 is the hit distance.
// asm: camProjectPoint takes 6 args (z goes in a2 as raw bits); m2c's extra arg was wrong.
void func_8003109C(ObjectTransform *obj, u8 *state, u8 turnFlag, s32 delta) {
    u8 *cam;
    void *child;
    ObjectTransform *src;
    s32 vpW;
    s32 vpH;
    f32 halfW;
    f32 halfH;
    s32 joyX;
    s32 joyY;
    f32 blend;
    f32 aimX;
    f32 aimY;
    f32 pt1[3];
    f32 pt2[3];
    f32 scr1X;
    f32 scr1Y;
    f32 scr2X;
    f32 scr2Y;
    f32 far1[3];
    f32 far2[3];
    f32 ptA[3];
    f32 ptB[3];
    f32 tgt[3];
    f32 kx;
    f32 ky;
    f32 kx2;
    f32 ky2;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 len;
    f32 aimDx;
    f32 aimDy;
    f32 aimDz;
    f32 pts[6];
    f32 *p;
    s16 rot[3];
    u8 hitNear[0x24];
    f32 outDist;
    s32 nearRes;
    s32 hitRes;
    s16 yaw;
    s16 pitch;
    s16 limit;
    s32 n;
    struct {
        s16 type;     /* 0x00 */
        s16 pad02;
        s16 x;        /* 0x04 */
        s16 y;        /* 0x06 */
        s16 z;        /* 0x08 */
        u8 b0A;       /* 0x0A */
        u8 b0B;       /* 0x0B */
        s16 yaw;      /* 0x0C */
        s16 pitch;    /* 0x0E */
        u8 b10;       /* 0x10 */
        u8 b11;       /* 0x11 */
        u8 pad12;
        s8 b13;       /* 0x13 */
        f32 scale;    /* 0x14 */
        void *owner;  /* 0x18 */
        void *tab0;   /* 0x1C */
        void *tab1;   /* 0x20 */
    } spawn;

    cam = (u8 *) camGetPtr();
    viGetCurrentSize(&vpW, &vpH);
    halfW = (f32) ((u32) vpW >> 1);
    halfH = (f32) ((u32) vpH >> 1);

    joyX = controlAbsXjoy;
    if (joyX >= 0x42) {
        joyX = 0x41;
    }
    if (joyX < -0x41) {
        joyX = -0x41;
    }
    joyY = -controlAbsYjoy;
    if (joyY >= 0x42) {
        joyY = 0x41;
    }
    if (joyY < -0x41) {
        joyY = -0x41;
    }

    // smooth the aim offsets toward the stick deflection (rate 1 - 0.7^delta)
    blend = 1.0f - Powerf(0.7f, delta);
    aimX = *(f32 *) (state + 0x48);
    *(f32 *) (state + 0x48) = aimX + ((((f32) (joyX * 0x50)) / 65.0f) - aimX) * blend;
    aimY = *(f32 *) (state + 0x4C);
    *(f32 *) (state + 0x4C) = aimY + ((((f32) (joyY * 0x50)) / 65.0f) - aimY) * blend;
    state[0x94] &= 0xBF;

    pt1[0] = -16.0f;
    pt1[1] = 16.0f;
    pt1[2] = -16.0f;
    pt2[0] = 16.0f;
    pt2[1] = -16.0f;
    pt2[2] = -16.0f;
    far1[2] = -2048.0f;
    far2[2] = -2048.0f;

    if (camProjectPoint(pt1[0], pt1[1], pt1[2], &scr1X, &scr1Y, 0) != 0 &&
        camProjectPoint(pt2[0], pt2[1], pt2[2], &scr2X, &scr2Y, 0) != 0) {
        camReversePoint(scr1X, scr1Y, &far1[0], &far1[1], &far1[2], 0);
        camReversePoint(scr2X, scr2Y, &far2[0], &far2[1], &far2[2], 0);

        kx = (pt2[0] - pt1[0]) / (scr2X - scr1X);
        ky = (pt1[1] - pt2[1]) / (scr1Y - scr2Y);
        kx2 = (far2[0] - far1[0]) / (scr2X - scr1X);
        ky2 = (far1[1] - far2[1]) / (scr1Y - scr2Y);

        // two world points on the near/far edge of the screen, offset by the aim
        ptA[0] = pt1[0] + (((halfW + aimX) - scr1X) * kx);
        ptA[1] = pt1[1] + (((halfH - aimY) - scr1Y) * ky);
        ptA[2] = pt1[2];
        ptB[0] = far1[0] + (((halfW + aimX) - scr1X) * kx2);
        ptB[1] = far1[1] + (((halfH - aimY) - scr1Y) * ky2);
        ptB[2] = far1[2];

        // rotate both points into world space by the camera angles, then add its position
        rot[0] = (s16) (-0x8000 - *(s16 *) (cam + 0x0));
        rot[1] = (s16) (-*(s16 *) (cam + 0x2));
        rot[2] = (s16) (-*(s16 *) (cam + 0x4));
        pointListRPY(1, rot, (s32 *) ptA, ptA);
        ptA[0] += *(f32 *) (cam + 0xC);
        ptA[1] += *(f32 *) (cam + 0x10);
        ptA[2] += *(f32 *) (cam + 0x14);
        pointListRPY(1, rot, (s32 *) ptB, ptB);
        ptB[0] += *(f32 *) (cam + 0xC);
        ptB[1] += *(f32 *) (cam + 0x10);
        ptB[2] += *(f32 *) (cam + 0x14);

        nearRes = trackNearestIntersection(0, ptA, ptB, hitNear, 0, 0);
        hitRes = func_80031A44(obj, ptA, ptB, &outDist, delta);
        if (hitRes != 0 || *(s32 *) (state + 0x50) != 0) {
            state[0x94] |= 0x40;
        }

        if (hitRes != 0 || *(s32 *) (state + 0x50) == 0) {
            tgt[0] = ptB[0];
            tgt[1] = ptB[1];
            tgt[2] = ptB[2];
            if ((nearRes | hitRes) != 0) {
                dx = ptA[0] - ptB[0];
                dy = ptA[1] - ptB[1];
                dz = ptA[2] - ptB[2];
                len = sqrtf((dx * dx) + (dy * dy) + (dz * dz));
                outDist = 1.0f - (*(f32 *) (hitNear + 0x20) / len);
                tgt[0] += dx * outDist;
                tgt[1] += dy * outDist;
                tgt[2] += dz * outDist;
            }
        } else {
            if (*(void **) (state + 0x58) != NULL) {
                src = *(ObjectTransform **) (state + 0x58);
            } else {
                src = *(ObjectTransform **) (state + 0x54);
            }
            tgt[0] = src->x_position;
            tgt[1] = src->y_position;
            tgt[2] = src->z_position;
        }

        // aim angles from the object towards the target point
        aimDx = obj->x_position - tgt[0];
        aimDz = obj->z_position - tgt[2];
        aimDy = tgt[1] - obj->y_position;
        yaw = (s16) Arctanf(aimDx, aimDz);
        pitch = (s16) Arctanf(aimDy, sqrtf((aimDx * aimDx) + (aimDz * aimDz)));

        if (turnFlag == 0) {
            blend = 1.0f - Powerf(0.9f, delta);
            obj->y_rotation = dAngle(obj->y_rotation, (s16) (yaw + 0x8000), blend);
            if (pitch < -0x2000) {
                limit = 0x2000;
            } else if (pitch >= 0x2001) {
                limit = -0x2000;
            } else {
                limit = (s16) -pitch;
            }
            obj->x_rotation = dAngle(obj->x_rotation, limit, blend);
            obj->z_rotation = dAngle(obj->z_rotation, 0, blend);
        }

        // target object: clear the dkey bit when its racer is in state 0xA
        if (*(u8 **) (state + 0x24) != NULL) {
            u8 *racer = *(u8 **) (*(u8 **) (state + 0x24) + 0x68);

            if (racer != NULL && (racer[0x568] & 0xF) == 0xA) {
                controlDkeys &= ~0x2000;
            }
        }

        if (controlDkeys & 0x2000) {
            spawn.type = 0x50;
            spawn.b0A = 1;
            spawn.b0B = 0x1E;
            spawn.b10 = 0;
            spawn.b11 = 0;
            spawn.owner = obj;
            spawn.tab0 = D_800A1790_A2390;
            spawn.tab1 = D_800A1850_A2450;
            spawn.b13 = -1;
            spawn.scale = 35.0f;

            // asm: word read at 0x94 >> 31 is bit 0x80 of byte 0x94
            if (state[0x94] & 0x80) {
                pointListRPY(2, (s16 *) obj, (s32 *) D_800A2D5C_A395C, pts);
            } else {
                pointListRPY(2, (s16 *) obj, (s32 *) D_800A2D44_A3944, pts);
            }
            pts[0] += obj->x_position;
            pts[1] += obj->y_position;
            pts[2] += obj->z_position;
            pts[3] += obj->x_position;
            pts[4] += obj->y_position;
            pts[5] += obj->z_position;

            n = 0;
            p = pts;
            do {
                aimDx = p[0] - tgt[0];
                aimDy = tgt[1] - p[1];
                aimDz = p[2] - tgt[2];
                spawn.x = (s16) (s32) p[0];
                spawn.y = (s16) (s32) p[1];
                spawn.z = (s16) (s32) p[2];
                spawn.yaw = (s16) Arctanf(aimDx, aimDz);
                spawn.pitch = (s16) Arctanf(aimDy, sqrtf((aimDx * aimDx) + (aimDz * aimDz)));
                /* sig mismatch: asm passes 2 args (params, 1); header declares 3 */
                child = ((void *(*)(void *, s32)) objSetupObject)(&spawn, 1);
                n += 1;
                if (child != NULL) {
                    *(s32 *) ((u8 *) child + 0x3C) = 0;
                }
                p += 3;
            } while (n != 2);
            amSndPlay(0xDA, NULL);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_8003109C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80031984(void *arg0, void *arg1, void *arg2, s32 arg3) {
    s16 v = 0x300;
    s16 *t92 = (s16 *)((u8 *)arg1 + 0x92);
    u8 *temp_v1;
    u8 *temp_a1;
    u8 *entry;
    s32 count;
    s32 i;

    *t92 = (s16) (*t92 + arg3);
    if ((*(u16 *)((u8 *)arg2 + 0x540) & 0xF) && (*t92 & 0x20)) {
        v = 0;
    } else if (**(f32 **)((u8 *)arg0 + 0x54) < 0.6f) {
        v = 0x100;
    }
    temp_v1 = *(u8 **)(*(u8 **)((u8 *)arg0 + 0x6C));
    temp_a1 = *(u8 **)temp_v1;
    entry = *(u8 **)(temp_v1 + 0x74);
    count = temp_a1[0x2C];
    for (i = 0; i < count; i++) {
        if ((*(s32 *)(entry + 4) & 0xFF) == 3) {
            *(s16 *)entry = v;
        }
        entry += 8;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_80031984.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// asm: a1/a2 are copied into a 9-float segment (a2 at +0xC, a1 at +0x18) that
// hitVectorCheck reads; seg[0..2] are never written by the asm. Hit list lives in
// the frame at sp+0x34. Object/hit field offsets follow hit.c (hitVectorHitCheck).
s32 func_80031A44(ObjectTransform *obj, f32 *a1, f32 *a2, f32 *outDist, s32 delta) {
    f32 seg[9];
    Object *hitList[256];
    void *hitOut;
    Object **list;
    s32 start;
    s32 total;
    s32 n = 0;
    s32 k;
    u8 *st;
    u8 *hitRec;
    f32 dx;
    f32 dd;

    seg[3] = a2[0];
    seg[4] = a2[1];
    seg[5] = a2[2];
    seg[6] = a1[0];
    seg[7] = a1[1];
    seg[8] = a1[2];
    st = *(u8 **)((u8 *)obj + 0x68);

    list = objGetObjList(&start, &total);
    for (k = 0; k < total - start; k++) {
        Object *o = list[start + k];
        u8 *hitp = *(u8 **)((u8 *)o + 0x4C);

        if (hitp != NULL) {
            u8 *o40 = *(u8 **)((u8 *)o + 0x40);

            if (*(u16 *)(o40 + 0x14) & 0x40) {
                if (hitp[0x30] == 1 || hitp[0x30] == 2) {
                    s16 id = *(s16 *)((u8 *)o + 0x48);

                    if (id != 1 && id != 0x98) {
                        hitList[n] = o;
                        n++;
                    }
                }
            }
        }
    }
    if (n > 0) {
        n = hitVectorCheck(0, seg, n, hitList, &hitOut, obj);
    }

    st[0x5C] = (u8)(st[0x5C] + delta);
    if (st[0x5C] >= 0x21) {
        st[0x5C] = 0x20;
    }

    if (n > 0) {
        hitRec = (u8 *)hitOut;
        if (*(s32 *)(st + 0x50) == *(s32 *)hitRec) {
            *(s8 *)(st + 0x5D) = (s8)(*(s8 *)(st + 0x5D) - delta);
            if (*(s8 *)(st + 0x5D) <= 0) {
                *(s8 *)(st + 0x5D) = 0;
                *(s16 *)(st + 0x5E) = 0x5A;
            }
        } else {
            *(s8 *)(st + 0x5D) = 0x14;
            *(s16 *)(st + 0x5E) = 0;
            st[0x5C] = 0;
        }
        *(s32 *)(st + 0x50) = *(s32 *)(hitRec + 0x0);
        *(s32 *)(st + 0x54) = *(s32 *)(hitRec + 0x4);
        *(s32 *)(st + 0x58) = *(s32 *)(hitRec + 0x8);

        dx = a1[0] - *(f32 *)(hitRec + 0x10);
        dd = dx * dx;
        *outDist = sqrtf((2.0f * dd) + dd);
    } else {
        *(s16 *)(st + 0x5E) = (s16)(*(s16 *)(st + 0x5E) - delta);
        if (*(s16 *)(st + 0x5E) <= 0) {
            *(s32 *)(st + 0x50) = 0;
            *(s8 *)(st + 0x5D) = 0x14;
        }
    }
    return n;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_80031A44.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// asm: outputs a1/a2/a3 receive the chosen point's x/y/z. Point list lives in buf (0x5C..0x9B
// of the frame, 5 points x 3 floats); trackGetIntersect scratch and trackMakePolylist output
// alias into the same buffer exactly as the asm frame does.
void func_80031CC4(ObjectTransform *obj, void *a1, void *a2, void *a3) {
    u8 *state = *(u8 **)((u8 *)obj + 0x68);
    ObjectTransform *tgt = *(ObjectTransform **)(state + 0x24);
    u8 mask = *(u8 *)(*(u8 **)(*(u8 **)((u8 *)obj + 0x40) + 0x50) + 0x10);
    f32 buf[18];
    u8 hitInfo[0x34];
    u8 *p;
    s32 *slot = (s32 *) ((u8 *) obj + 0x88);
    s32 s0;
    s32 i;
    s32 k;

    p = D_800A2DA4_A39A4;
    for (i = 0; i < 5; i++) {
        *(f32 *)(p + 4) = 48.0f * sidekickHeight;
        p -= 12;
    }
    pointListRPY(5, (s16 *) tgt, (s32 *) D_800A2D74_A3974, buf);
    for (k = 4; k >= 0; k--) {
        buf[k * 3 + 0] = buf[k * 3 + 0] + tgt->x_position;
        buf[k * 3 + 1] = buf[k * 3 + 1] + tgt->y_position;
        buf[k * 3 + 2] = buf[k * 3 + 2] + tgt->z_position;
    }
    buf[15] = 10.0f;
    buf[16] = 10.0f;
    buf[17] = 10.0f;
    trackMakePolylist(3, buf, &buf[6], (s32 *) &buf[15], 0x2000, 0, 0);

    if (trackGetIntersect((s32) obj, buf, &buf[3], 0x41200000, (s32) mask, hitInfo) != 0) {
        s0 = *slot;
        do {
            if (s0 == 1) {
                s0 = 2;
            }
            if (trackGetIntersect((s32) obj, buf, &buf[s0 * 3], 0x41200000, (s32) mask, hitInfo) == 0) {
                *slot = s0;
            } else {
                s0 = (s0 & 3) + 1;
            }
        } while (s0 != *slot);
    } else {
        *slot = 1;
    }

    *(f32 *) a1 = buf[*slot * 3 + 0];
    *(f32 *) a2 = buf[*slot * 3 + 1];
    *(f32 *) a3 = buf[*slot * 3 + 2];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_80031CC4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void controlClearAimlocks(void *arg0) {
    u8 *base = (u8 *)arg0;
    u8 *p;
    s32 i;

    if (*(s32 *)(base + 0x1BC) != 0) {
        p = base + 0x14;
        for (i = 5; i != 0; i--) {
            s32 idx = *(s32 *)(p + 0x1A8);

            if (idx != 0) {
                *(u8 *)(idx + *(s8 *)base + 0x93) = 0;
                *(s32 *)(p + 0x1A8) = 0;
            }
            p -= 4;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlClearAimlocks.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_80031F60(void *arg0, void *arg1) {
    u8 *p = (u8 *)arg0;
    u8 *end = (u8 *)arg1;

    if (p < end) {
        s32 head = (s32) (end - p) & 3;

        if (head != 0) {
            do {
                *p = 0;
                p++;
            } while (p != (u8 *)arg0 + head);
            if (p == end) {
                return p + 4;
            }
        }
        do {
            *(u32 *)p = 0;
            p += 4;
        } while (p != end);
    }
    return p;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_80031F60.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void controlPlayerReInit(void *arg0, f32 arg1, f32 arg2, f32 arg3, s16 arg4, s16 arg5, s16 arg6) {
    ObjectTransform *tr = (ObjectTransform *) arg0;
    u8 *state = *(u8 **)((u8 *)arg0 + 0x68);
    struct {
        u8 pad[0xA];
        s16 a6;
        s16 a5;
        s16 a4;
        s8 b0;
        s8 b1;
    } setup;   /* asm: stack struct at sp+0x2C, passed to controlPlayerInit */
    u8 *other;
    void *fx;

    setup.a4 = arg4;
    setup.a5 = arg5;
    setup.a6 = arg6;
    setup.b0 = *(s8 *)state;
    setup.b1 = *(s8 *)(state + 1);
    tr->unk6 = (s16) (tr->unk6 & 0xFBFF);
    tr->x_position = arg1;
    tr->y_position = arg2;
    tr->z_position = arg3;
    *(s16 *)((u8 *)arg0 + 0x2E) = trackGetBlock(arg1, arg2, arg3);
    *(u8 *)((u8 *)arg0 + 0x39) = 0xFF;
    other = *(u8 **)(state + 0x1A0);
    if (other != NULL) {
        *(s32 *)(*(u8 **)(other + 0x68) + 0xA0) = 0;
    }
    fx = *(void **)(state + 0x5BC);
    if (fx != NULL) {
        objFreeObject(fx);
        *(void **)(state + 0x5BC) = NULL;
    }
    func_80031F60(state, state + 0xBC);
    func_80031F60(state + 0xF4, state + 0x100);
    func_80031F60(state + 0x104, state + 0x23C);
    func_80031F60(state + 0x340, state + 0x364);
    func_80031F60(state + 0x510, state + 0x550);
    func_80031F60(state + 0x568, state + 0x598);
    func_80031F60(state + 0x5BC, state + 0x5CA);
    *(s16 *)(state + 0x5CA) = 0;
    /* asm: weapon arg is never set; $a1 still holds state+0x5CA from the last func_80031F60 call */
    controlEmptyPlayersHand(arg0, (u8) ((u32) state + 0x5CA));
    controlClearAimlocks(state);
    controlPlayerInit(arg0, &setup);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlPlayerReInit.s")
#endif

void controlDecapitatePlayer(s32 arg0) {
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void controlPlayerInit(void *obj, void *setup) {
    u8 *o = (u8 *) obj;
    u8 *su = (u8 *) setup;     /* setup: +0x10/+0x11 char ids, +0xA/+0xC/+0xE angles */
    u8 *state = *(u8 **) (o + 0x68);
    u8 *ch;                    /* mainGetGameCharacter result (asm sp+0xBC) */
    u8 *spC8 = NULL;           /* per-character data block (state+0x360) */
    u8 *blk;
    u8 **tbl;
    u8 **tbl6c;
    u8 *s1;
    u8 *s6;
    u8 *tbl30;
    u8 *v;
    u8 *cone;
    u8 *child;
    u8 *gl;
    u8 *dd;
    u8 *p;
    u16 vi;
    s32 i, k, n, count, s5, s0;

    struct {
        u8 b70;
        u8 b71;
        s16 h72;
        s16 h74;
        s16 h76;
        f32 f78;
        f32 f7C;
        f32 f80;
        u8 b84;
        u8 b85;
        u8 b86;
        u8 b87;
        s16 h88;
        s16 h8A;
        s16 h8C;
        s8 b8E;
        s8 b8F;
    } lightDesc;               /* asm sp+0x70 */
    ObjectHeader48 hdr;        /* asm sp+0x94 */
    struct {
        s16 w0;
        u8 b2;
        u8 pad3;
        s16 h4;
        s16 h6;
        s16 h8;
    } spawn;                   /* asm sp+0xAC */

    /* header, character data and object angles */
    *(s16 *) (state + 0x240) = 0x1000;
    state[0x00] = su[0x10];
    state[0x01] = su[0x11];
    ch = (u8 *) mainGetGameCharacter((s8) state[0x00], (s8) state[0x01]);
    state[0x189] = (u8) (*(u16 *) (ch + 0x4) & 0x1F);
    switch (((s8) state[0x01]) & 3) {
    case 0:
    case 1:
    case 2:
        *(f32 *) (state + 0x14) = 0.075f;
        break;
    default:
        *(f32 *) (state + 0x14) = 0.0f;
        break;
    }
    *(s16 *) (o + 0x0) = *(s16 *) (su + 0xE);
    *(s16 *) (o + 0x2) = *(s16 *) (su + 0xC);
    *(s16 *) (o + 0x4) = *(s16 *) (su + 0xA);
    *(f32 *) (state + 0x48) = 1.0f;
    *(f32 *) (state + 0x4C) = 1.0f;
    *(s16 *) (state + 0x11C) = *(s16 *) (o + 0x0);
    *(s16 *) (state + 0x128) = *(s16 *) (o + 0x0);
    *(s16 *) (state + 0x120) = *(s16 *) (o + 0x4);
    *(s16 *) (state + 0x104) = (s16) (0x8000 - *(s16 *) (o + 0x0));
    *(f32 *) (state + 0x57C) = *(f32 *) (o + 0x10);
    /* asm loop runs 6 times: bnez tests the counter before the delay-slot decrement */
    for (i = 0; i < 6; i++) {
        *(s32 *) (state + 0x1A8 + i * 4) = 0;
    }
    if ((state[0x01] & 3) != 2) {
        state[0x1F8] = 8;
    }

    /* per-character data block and point count (jump table in asm; default leaves spC8 unset) */
    switch ((s8) state[0x01]) {
    case 0:
    case 4:
        state[0x530] = 5;
        *(u32 *) (state + 0x518) = 0xCE002000;
        *(u32 *) (state + 0x51C) = 0x02000000;
        spC8 = D_800A1BF8_A27F8;
        break;
    case 1:
    case 5:
        state[0x530] = 5;
        *(u32 *) (state + 0x518) = 0xCE00A000;
        *(u32 *) (state + 0x51C) = 0x04000000;
        spC8 = D_800A20B4_A2CB4;
        break;
    case 2:
        state[0x530] = 2;
        *(u32 *) (state + 0x518) = 0xCE002000;
        *(u32 *) (state + 0x51C) = 0x08000000;
        spC8 = D_800A23A8_A2FA8;
        break;
    case 6:
        state[0x530] = 2;
        *(u32 *) (state + 0x518) = 0xCE002000;
        *(u32 *) (state + 0x51C) = 0x08000000;
        spC8 = D_800A23BC_A2FBC;
        break;
    case 3:
    case 7:
        state[0x530] = 2;
        *(u32 *) (state + 0x518) = 0;
        *(u32 *) (state + 0x51C) = 0;
        spC8 = D_800A25A0_A31A0;
        break;
    }
    *(u8 **) (state + 0x360) = spC8;
    switch (state[0x01] & 3) {
    case 0:
    case 1:
        s0 = 0x10;
        break;
    case 2:
        s0 = 9;
        break;
    default:
        s0 = 0;
        break;
    }
    objAnimSetMove(obj, (s8) s0, 0.0f);
    objAnimSetMove(obj, (s8) s0, 0.0f);

    /* copy the block's point list (x,y,z per entry) into state+0x364 */
    blk = *(u8 **) (state + 0x360);
    n = (s8) state[0x530];
    if (n > 0) {
        tbl = *(u8 ***) blk;
        for (k = 0; k < n; k++) {
            p = tbl[k];
            *(f32 *) (state + 0x364 + k * 12 + 0) = *(f32 *) (p + 0x0);
            *(f32 *) (state + 0x364 + k * 12 + 4) = *(f32 *) (p + 0x4);
            *(f32 *) (state + 0x364 + k * 12 + 8) = *(f32 *) (p + 0x8);
        }
    }
    state[0x535] = 0;
    func_80035628((ObjectTransform *) obj, state, 0.0f);
    n = (s8) state[0x530];
    for (k = 0; k < n; k++) {
        *(f32 *) (state + 0x484 + k * 12 + 0) = *(f32 *) (state + 0x3C4 + k * 12 + 0);
        *(f32 *) (state + 0x484 + k * 12 + 4) = *(f32 *) (state + 0x3C4 + k * 12 + 4);
        *(f32 *) (state + 0x484 + k * 12 + 8) = *(f32 *) (state + 0x3C4 + k * 12 + 8);
    }

    /* fx cones from the model's emitter table (state+0x598 slots) */
    tbl6c = *(u8 ***) (o + 0x6C);
    s6 = *(u8 **) tbl6c[(s8) o[0x3A]];
    s1 = D_800A18FC_A24FC + (state[0x01] & 7) * 16;
    count = s1[0];
    if (count != 0) {
        s5 = s1[1];
        for (k = 0; k < count; k++) {
            tbl30 = *(u8 **) (s6 + 0x30);
            vi = *(u16 *) (tbl30 + s5 * 4);
            if (*(u32 *) (state + 0x598 + k * 4) == 0) {
                v = *(u8 **) (s6 + 0x1C) + vi * 10;
                *(u32 *) (state + 0x598 + k * 4) = (u32) fxAllocateCone(
                    *(s16 *) (v + 0), *(s16 *) (v + 2), *(s16 *) (v + 4), *(s16 *) (s1 + 2),
                    *(s16 *) (s1 + 4), (f32) *(s16 *) (s1 + 6), (f32) *(s16 *) (s1 + 8),
                    *(s16 *) (s1 + 0xA), *(s16 *) (s1 + 0xC), *(s16 *) (s1 + 0xE));
                cone = state + k;
                cone[0x5A8] = (u8) mathRnd(-0x80, 0x7F);
                cone[0x5AC] = 0;
                cone[0x5B0] = (u8) s5;
                cone[0x5B8] = 0;
                cone[0x5B4] = (u8) *(u16 *) (tbl30 + s5 * 4 + 2);
            }
            s5++;
        }
    } else {
        *(u32 *) (state + 0x59C) = 0;
        *(u32 *) (state + 0x5A0) = 0;
        *(u32 *) (state + 0x5A4) = 0;
        *(u32 *) (state + 0x598) = 0;
    }

    *(f32 *) (state + 0x3C) = *(f32 *) (o + 0xC);
    *(f32 *) (state + 0x40) = *(f32 *) (o + 0x10);
    *(f32 *) (state + 0x44) = *(f32 *) (o + 0x14);
    gl = *(u8 **) (o + 0x4C);
    *(f32 *) (gl + 0x34) = -1.0f;
    gl[0x9] = 2;
    *(u16 *) (gl + 0xA) = (u16) (*(u16 *) (gl + 0xA) | 0x11);
    state[0x192] = 0xFF;
    state[0x186] = 0;
    *(u32 *) (state + 0x514) = 0;
    *(s16 *) (state + 0x1FC) = -2;
    *(s16 *) (state + 0x1FE) = 0;
    *(u32 *) (state + 0x200) = 0;
    *(f32 *) (state + 0x1EC) = 1.0f;
    *(f32 *) (state + 0x204) = 0.0f;
    state[0x531] = blk[0x4];
    *(f32 *) (state + 0x208) = *(f32 *) (o + 0xC);
    *(f32 *) (state + 0x20C) = *(f32 *) (o + 0x10);
    *(f32 *) (state + 0x210) = *(f32 *) (o + 0x14);
    *(u16 *) (state + 0x21C) = 0;
    *(u16 *) (state + 0x21E) = 0xFF;
    *(u32 *) (state + 0x220) = 0;
    state[0x19A] = 0;
    *(f32 *) (state + 0x224) = 0.0f;
    if ((s8) state[0x00] != -1) {
        camSetNo((s8) state[0x00]);
        func_8002EDA0(obj, state);
    }

    /* camera/fade block and debug-cam pointer */
    state[0x344] = 0;
    state[0x345] = 0;
    *(u16 *) (state + 0x346) = 0;
    *(u16 *) (state + 0x348) = 0;
    *(u16 *) (state + 0x34A) = 0;
    *(f32 *) (state + 0x34C) = 0.0f;
    *(f32 *) (state + 0x350) = 1.0f;
    dd = D_800F7888;
    *(u16 *) (dd + 0x6) = 0;
    *(f32 *) (dd + 0x14) = 0.0f;
    *(f32 *) (dd + 0x18) = 0.0f;
    *(f32 *) (dd + 0x1C) = -48.0f;
    *(u8 **) (state + 0x23C) = dd;
    state[0x568] = 0;

    /* character record: scale word and object stats */
    if (*(s16 *) ch < 0x100) {
        *(s16 *) ch = (s16) (((*(s16 *) (ch + 0x2) * 5) + 4) << 8);
    }
    *(s16 *) (gl + 0x6) = *(s16 *) ch;
    *(s16 *) (state + 0x586) = *(s16 *) (ch + 0xC);
    *(s16 *) (state + 0x588) = *(s16 *) (ch + 0xE);
    state[0x540] = (u8) (state[0x540] & 0xFD);
    *(u32 *) (state + 0xC0) = 0;
    *(u16 *) (state + 0x53A) = 0;
    *(u32 *) (state + 0x564) = 0;
    *(s16 *) (state + 0x58A) = *(s16 *) (ch + 0x10);

    /* one-time lights, ram test and child object */
    if (*(u32 *) (state + 0x550) == 0 && multiPlayerGame == 0) {
        *(s32 *) (state + 0x550) = osRamTest4_6105(0x18, 3, 5, 0x42960000, 175.0f);
    }
    if (*(u32 *) (state + 0x554) == 0) {
        lightDesc.b70 = 1;
        lightDesc.h88 = -1;
        lightDesc.b71 = 0;
        lightDesc.h72 = 0;
        lightDesc.h74 = 0;
        lightDesc.h76 = 0;
        lightDesc.f78 = 0.0f;
        lightDesc.f7C = 0.0f;
        lightDesc.f80 = 0.0f;
        lightDesc.b84 = 0xC0;
        lightDesc.b85 = 0xC0;
        lightDesc.b86 = 0xFF;
        lightDesc.b87 = 0;
        lightDesc.h8A = 0xFA;
        lightDesc.h8C = 0xFA;
        lightDesc.b8E = -1;
        lightDesc.b8F = 1;
        *(s32 *) (state + 0x554) = camlightAdd(NULL, &lightDesc);
    }
    if (*(u32 *) (state + 0x558) == 0) {
        hdr.unk0 = 1;
        hdr.unk1 = 3;
        hdr.unk2 = 0x40;
        hdr.unk3 = 0xFF;
        hdr.unk4 = 0;
        hdr.unk5 = 0;
        hdr.unk6 = 0;
        hdr.unk8 = 0;
        hdr.unkC = 0x96;
        hdr.unkE = 0x96;
        hdr.unk12 = 0xFF00;    /* asm: byte 0xA6 never written, left as 0 here */
        hdr.unk14 = -1;
        hdr.unk16 = 0;
        *(s32 *) (state + 0x558) = addObjectLight(NULL, &hdr);
    }
    if (*(u32 *) (state + 0x55C) == 0) {
        spawn.w0 = 0xAC;
        spawn.b2 = 0xC;
        spawn.h4 = 0;
        spawn.h6 = 0;
        spawn.h8 = 0;
        /* asm does not set $a2 here; passed as NULL */
        child = (u8 *) objSetupObject(&spawn, 1, NULL);
        *(u8 **) (state + 0x55C) = child;
        *(u8 **) (child + 0x88) = o;
        *(u32 *) (child + 0x3C) = 0;
        *(f32 *) (child + 0xC) = *(f32 *) (o + 0xC);
        *(f32 *) (child + 0x10) = *(f32 *) (o + 0x10);
        *(f32 *) (child + 0x14) = *(f32 *) (o + 0x14);
        *(f32 *) (child + 0x14) = *(f32 *) (o + 0x14);  /* asm stores this twice */
        *(s16 *) (child + 0x2E) = *(s16 *) (o + 0x2E);
    }

    /* reset of per-player flags and timers */
    state[0x2] = 0;
    state[0x3] = 0;
    state[0x12E] = 0;
    state[0x12F] = 0;
    *(u32 *) (state + 0x5CC) = 0;
    *(s16 *) (state + 0x58C) = 0;
    *(s16 *) (state + 0x592) = 0;
    *(f32 *) (state + 0x130) = 0.0f;
    *(f32 *) (state + 0x134) = 0.0f;
    state[0x5EE] = 0;
    state[0x585] = ch[0x70];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlPlayerInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Main per-frame player control. obj = Object (+0x4C transform, +0x60 sub-object,
// +0x68 player state, +0x2E yaw). state = raw player-state block (offsets from asm).
// Game block (mainGetGame) player slot: game + (game[0] & 3) * 0x76 (stride 0x76).
// asm: several callees receive float values as integer bits (lw/lwc1 into a1..a3); those
// are passed here as s32 loads so the argument registers match the asm.
void controlPlayer(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *state;
    u8 *game;
    u8 *slot;
    u8 *rec;
    u8 *tr;
    u8 *chr;
    u8 *e;
    u8 *tmp;
    s32 lvl;
    s32 idx;
    s32 w;
    s32 nextChr;
    s32 mode;
    s32 n;
    s32 old;
    s32 cnt;
    f32 sp44;
    f32 tmpf;
    f32 f;

    game = (u8 *)mainGetGame();
    state = *(u8 **)(obj + 0x68);
    if (*(s8 *)state == 0) {
        if (*(u32 *)(game + 0x514) < 0xF0000000U) {
            *(u32 *)(game + 0x514) = *(u32 *)(game + 0x514) + arg1;
        }
        if (*(u32 *)(game + 0x518) < 0xF0000000U) {
            *(u32 *)(game + 0x518) = *(u32 *)(game + 0x518) + arg1;
        }
    }
    controlcam = camGetListPtr();
    idx = mainGetNumberOfCameras() - 1;
    if (*(s8 *)state < idx) {
        idx = *(s8 *)state;
    }
    controlcam += idx * 0x4C;
    if (frontGetTargetControl(*(s8 *)state) != 0) {
        controlModeKeys = ControlModeExpert;
    } else {
        controlModeKeys = ControlModeNormal;
    }
    state[0x540] &= 0xFB;
    state[3] = state[2];
    if (splinecamSplineHead() == 0 && mathRnd(0, 0x3E8) >= 0x3DF) {
        tr = *(u8 **)(obj + 0x4C);
        *(s16 *)(tr + 0x6) = (s16)(*(s16 *)(tr + 0x6) - 0x40);
    }

    /* pending level change / pickup record (state+0xF4) */
    if (*(u8 **)(state + 0xF4) != NULL) {
        if (*(s16 *)(*(u8 **)(obj + 0x4C) + 0x6) >= 0x100) {
            rec = *(u8 **)(*(u8 **)(state + 0xF4) + 0x3C);
            lvl = rec[0xA];
            if (rec[0xB] != 0xFF) {
                lvl |= rec[0xB] << 8;
            }
            if ((s8)rec[0x14] != -1) {
                slot = game + (game[0] & 3) * 0x76;
                if (*(u16 *)(slot + 0x1C0) & (1 << (s8)rec[0x14])) {
                    w = levelGetWorld((*(u16 *)(slot + 0x160)) >> 5, rec, lvl, game);
                    *(u16 *)(slot + 0x1C0) = (u16)(*(u16 *)(slot + 0x1C0) | (1 << w));
                    mainChangeLevel(0, 0, 0, 0x11, 1, 1);
                } else {
                    w = levelGetWorld((*(u16 *)(slot + 0x160)) >> 5, rec, lvl, game);
                    *(u16 *)(slot + 0x1C0) = (u16)(*(u16 *)(slot + 0x1C0) | (1 << w));
                    *(u16 *)(slot + 0x1C0) = (u16)(*(u16 *)(slot + 0x1C0) | (1 << (s8)rec[0x14]));
                    /* asm: no args set here; a0 is whatever levelGetWorld left (world value assumed) */
                    nextChr = mainGetNextCharacter((*(u16 *)(slot + 0x160)) >> 5);
                    mode = frontGetMode();
                    mainChangeLevel(lvl, nextChr, (s8)rec[0xC], mode, (s8)rec[0x1A], 1);
                    if ((s8)rec[0x16] != -1) {
                        mainSetAnimGroup((s8)rec[0x16]);
                    }
                }
            } else {
                /* asm: a0 == -1 here */
                nextChr = mainGetNextCharacter(-1);
                mode = frontGetMode();
                mainChangeLevel(lvl, nextChr, (s8)rec[0xC], mode, (s8)rec[0x1A], 1);
            }
            *(s16 *)(state + 0x5C8) = 0x3C;
            if ((s8)rec[0x16] != -1) {
                mainSetAnimGroup((s8)rec[0x16]);
            }
            state[0x196] = 0;
            objFreeObject(*(void **)(state + 0xF4));
        }
        *(void **)(state + 0xF4) = NULL;
    }

    if (state[0x1F9] != 0 && *(s16 *)(state + 0x5C8) < 0xA) {
        *(s16 *)(state + 0x5C8) = 0xA;
    }
    if (*(s16 *)(state + 0x1FC) == -2) {
        *(s16 *)(state + 0x1FC) = -1;
        if (runlinkIsModuleLoaded(0xB) != 0 && splinecamGetNearestNode(0, 0) != 0) {
            *(s16 *)(state + 0x1FE) = (s16)flamethrowerUpdate(0, *(s32 *)(obj + 0xC), *(s32 *)(obj + 0x10),
                                                              *(s32 *)(obj + 0x14), state + 0x200, state + 0x204);
            *(s16 *)(state + 0x1FC) = 0;
        }
    }
    tmp = *(u8 **)(state + 0x564);
    if (tmp != NULL) {
        tmp[0x622] = (u8)((((*(s32 *)controlModeKeys & controlKeys) == 0) << 5) & 0x20 | (tmp[0x622] & 0xFFDF));
        sprintCountdown(*(void **)(state + 0x564), *(s32 *)(state + 0x544), *(s32 *)(state + 0x548),
                        *(s32 *)(state + 0x54C), arg1);
    }

    if ((s8)state[0x56F] > 0) {
        if (*(s16 *)(state + 0x5C8) <= 0 && (s8)state[1] != 1 && (s8)state[1] != 5) {
            n = (s8)state[0x56F];
            if (arg1 < (s8)state[0x56F]) {
                n = (s8)arg1;
            }
            tr = *(u8 **)(obj + 0x4C);
            old = *(s16 *)(tr + 0x6);
            *(s16 *)(tr + 0x6) = (s16)(old - (n << 4));
            state[0x56F] = (u8)((s8)state[0x56F] - n);
            if (multiPlayerGame != 0 && *(s16 *)(*(u8 **)(obj + 0x4C) + 0x6) < 0x100 && old >= 0x100) {
                if (*(u8 **)(state + 0x570) != NULL) {
                    hitPlayerKilledPlayer(*(void **)(state + 0x570), arg0);
                } else {
                    hitPlayerKilledPlayer(arg0, arg0);
                }
            }
        } else {
            state[0x56F] = 0;
        }
    }
    if ((s8)state[0x56F] <= 0) {
        *(void **)(state + 0x570) = NULL;
    }
    if (((multiPlayerGame != 0 && multiGameType == 4) || racingInGame != 0) && girlBossControl() != 0) {
        controlDisableJoypad(1);
    }

    if (*(u8 **)(state + 0xFC) != NULL) {
        switch (state[1]) {
        case 0:
        case 4:
            boyBossControl(arg0, arg1);
            break;
        case 1:
        case 5:
            dogBossControl(arg0, arg1);
            break;
        case 2:
        case 6:
            girlControl(arg0, arg1);
            break;
        default:
            break;
        }
    } else {
        switch (state[1]) {
        case 0:
        case 4:
            boyControl(arg0, arg1);
            break;
        case 1:
        case 5:
            dogControl(arg0, arg1);
            break;
        case 2:
        case 6:
            hovershipControl(arg0, arg1);
            break;
        case 3:
        case 7:
            flamethrowerConstrain(arg0, arg1);
            break;
        default:
            break;
        }
    }

    tmp = *(u8 **)(state + 0x5CC);
    if (tmp != NULL) {
        controlGetGunBarrelPos(arg0, state, (f32 *)(tmp + 0xC), (f32 *)(tmp + 0x10), (f32 *)(tmp + 0x14));
        *(s16 *)(tmp + 0x2E) = *(s16 *)(obj + 0x2E);
    }
    if (*(s8 *)(state + 0x149) != 0) {
        f = Powerf(0.9f, arg1);
        *(f32 *)(state + 0x6C) = *(f32 *)(state + 0x6C) * f;
        *(f32 *)(state + 0x70) = *(f32 *)(state + 0x70) * f;
    }
    if (*(u8 **)(state + 0x564) != NULL) {
        flamethrowerHits(*(void **)(state + 0x564));
        chargeEffectSetPower(*(void **)(state + 0x564));
    }

    if (*(s16 *)(state + 0x10E) != 0) {
        *(s16 *)(state + 0x10E) = (s16)(*(s16 *)(state + 0x10E) - arg1);
        if (*(s16 *)(state + 0x10E) < 0) {
            *(s16 *)(state + 0x10E) = 0;
        }
    } else {
        squadsAddInterestingEvent(arg0, (s16)(s32)*(f32 *)(obj + 0xC), (s16)(s32)*(f32 *)(obj + 0x10),
                                  (s16)(s32)*(f32 *)(obj + 0x14), 4, 1, 0);
    }
    tmpf = (f32)arg1;
    if (*(f32 *)(state + 0x4C) != *(f32 *)(state + 0x48)) {
        /* sig mismatch: asm passes the float in $a1 as integer bits */
        ((void (*)(void *, s32))func_800370D8)(state, *(s32 *)&tmpf);
    }

    if (*(s16 *)(state + 0x5C8) != 0) {
        tr = *(u8 **)(obj + 0x4C);
        e = *(u8 **)(tr + 0x40);
        if (!(*(u32 *)(e + 0x30) & 0x40000000)) {
            cnt = *(s16 *)(tr + 0x32);
            do {
                cnt -= 1;
                e[0x30] = (u8)(e[0x30] | 0x40);
                e += 0x34;
            } while (cnt > 0);
        }
        *(s16 *)(state + 0x5C8) = (s16)(*(s16 *)(state + 0x5C8) - arg1);
        if (*(s16 *)(state + 0x5C8) <= 0) {
            *(s16 *)(state + 0x5C8) = 0;
            cnt = *(s16 *)(tr + 0x32);
            do {
                cnt -= 1;
                e[0x30] = (u8)(e[0x30] & 0xFFBF);
                e += 0x34;
            } while (cnt > 0);
        }
    }

    camSetNo(*(s8 *)state);
    func_8002B378((Object *)obj, state, tmpf);
    controlDisableJoypad(0);
    chr = mainGetGameCharacter(*(s8 *)state, state[1] & 3);

    if (*(s16 *)(state + 0x586) < 0) {
        *(s16 *)(state + 0x586) = (s16)(*(s16 *)(state + 0x586) + (arg1 * 8));
    }
    if (*(s16 *)(state + 0x586) > 0) {
        *(s16 *)(state + 0x586) = (s16)(*(s16 *)(state + 0x586) - (arg1 * 8));
    }
    if (*(s16 *)(state + 0x588) < 0) {
        *(s16 *)(state + 0x588) = (s16)(*(s16 *)(state + 0x588) + (arg1 * 4));
    }
    if (*(s16 *)(state + 0x588) > 0) {
        *(s16 *)(state + 0x588) = (s16)(*(s16 *)(state + 0x588) - (arg1 * 4));
    }
    if (*(s16 *)(state + 0x58A) < 0) {
        *(s16 *)(state + 0x58A) = (s16)(*(s16 *)(state + 0x58A) + (arg1 * 2));
    }
    if (*(s16 *)(state + 0x58A) > 0) {
        *(s16 *)(state + 0x58A) = (s16)(*(s16 *)(state + 0x58A) - (arg1 * 2));
    }
    if (D_80000310 != 0x17D9) {
        if (mathRnd(0, 0x2710) >= 0x270C) {
            *(s16 *)(chr + chr[0x70] * 2 + 0x14) = 0;
        }
    }
    *(s16 *)(chr + 0xC) = *(s16 *)(state + 0x586);
    *(s16 *)(chr + 0xE) = *(s16 *)(state + 0x588);
    *(s16 *)(chr + 0x10) = *(s16 *)(state + 0x58A);
    *(s16 *)(chr + 0x0) = *(s16 *)(*(u8 **)(obj + 0x4C) + 0x6);

    if (*(s32 *)(state + 0x550) != 0 && state[0x10D] == 0) {
        if ((*(u32 *)(state + 0x540) >> 31) != 0 && chr[0x70] == 3) {
            sp44 = (f32)*(s16 *)(state + 0x53E) / (f32)(chr[0x57] << 5);
        } else {
            sp44 = 0.0f;
            if (*(u8 **)(state + 0xF0) != NULL) {
                amSndStopXYZ(*(void **)(state + 0xF0));
            }
        }
        chargeEffectUpdate(*(s32 *)(state + 0x550), *(s32 *)&sp44, *(s32 *)(state + 0x550), chr);
        girlCanFire(*(s32 *)(state + 0x550), arg1);
        tmp = *(u8 **)(state + 0x554);
        if (tmp != NULL) {
            *(f32 *)(tmp + 0xC) = *(f32 *)(state + 0x544);
            *(f32 *)(tmp + 0x10) = *(f32 *)(state + 0x548);
            *(f32 *)(tmp + 0x14) = *(f32 *)(state + 0x54C);
            tmp[0x3B] = (u8)(s32)(64.0f * sp44);
        }
    }

    tmp = *(u8 **)(state + 0x558);
    if (tmp != NULL) {
        if (*(u32 *)(state + 0x540) & 0x02000000) {
            *(f32 *)(tmp + 0x18) = *(f32 *)(state + 0x544);
            *(f32 *)(tmp + 0x1C) = *(f32 *)(state + 0x548);
            *(f32 *)(tmp + 0x20) = *(f32 *)(state + 0x54C);
            changeLightIntensity((UnkLight *)tmp, 0xFF);
            turnLightOn((UnkLight *)tmp);
        } else {
            changeLightIntensity((UnkLight *)tmp, 0);
            turnLightOff((UnkLight *)tmp);
        }
    }

    tmp = *(u8 **)(state + 0x55C);
    if (tmp != NULL) {
        *(f32 *)(tmp + 0xC) = *(f32 *)(obj + 0xC);
        *(f32 *)(tmp + 0x10) = *(f32 *)(obj + 0x10);
        *(f32 *)(tmp + 0x14) = *(f32 *)(obj + 0x14);
        *(s16 *)(tmp + 0x2E) = *(s16 *)(obj + 0x2E);
    }

    tmp = *(u8 **)(state + 0x560);
    if (tmp != NULL) {
        *(f32 *)(tmp + 0xC) = *(f32 *)(state + 0x544);
        *(f32 *)(tmp + 0x10) = *(f32 *)(state + 0x548);
        *(f32 *)(tmp + 0x14) = *(f32 *)(state + 0x54C);
        *(s16 *)(tmp + 0x0) = *(s16 *)(state + 0x1CA);
        *(s16 *)(tmp + 0x2) = *(s16 *)(state + 0x1CC);
        *(s16 *)(tmp + 0x2E) = *(s16 *)(obj + 0x2E);
    }

    tmp = *(u8 **)(obj + 0x60);
    if (tmp != NULL) {
        e = *(u8 **)(tmp + 0x4);
        if (e != NULL) {
            idx = chr[0x70];
            if (idx >= 9 || (((state[0x1FA] != 0) || (state[0x568] == 4)) && (s8)state[1] != 2 && (s8)state[1] != 6)) {
                idx = 8;
            }
            if (idx < *(s8 *)(*(u8 **)(e + 0x40) + 0x1F)) {
                u8 *ent = *(u8 **)(*(u8 **)(e + 0x6C) + idx * 4);
                if (ent != NULL) {
                    ent[0xA] = (u8)arg1;
                }
                *(f32 *)(e + 0xC) = *(f32 *)(state + 0x544);
                *(f32 *)(e + 0x10) = *(f32 *)(state + 0x548);
                *(f32 *)(e + 0x14) = *(f32 *)(state + 0x54C);
                *(s16 *)(e + 0x0) = *(s16 *)(state + 0x1CA);
                *(s16 *)(e + 0x4) = 0;
                *(s16 *)(e + 0x2) = *(s16 *)(state + 0x1CC);
            }
        }
    }

    if ((s8)state[1] == 3 || (s8)state[1] == 7) {
        f = Powerf(0.9f, arg1);
        *(f32 *)(state + 0x354) = *(f32 *)(state + 0x354) * f;
        if (*(f32 *)(state + 0x354) > -0.1f && *(f32 *)(state + 0x354) < 0.1f) {
            *(f32 *)(state + 0x354) = 0.0f;
        }
        *(f32 *)(state + 0x35C) = *(f32 *)(state + 0x35C) * f;
        if (*(f32 *)(state + 0x35C) > -0.1f && *(f32 *)(state + 0x35C) < 0.1f) {
            *(f32 *)(state + 0x35C) = 0.0f;
        }
    } else {
        *(f32 *)(state + 0x354) = 0.0f;
        *(f32 *)(state + 0x35C) = 0.0f;
    }
    *(s16 *)(state + 0x536) = 0;
    *(f32 *)(state + 0x358) = 0.0f;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlPlayer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void controlFrozen(s32 arg0, s8 *arg1) {
    u16 pressed;

    if (mainGetNumberOfPlayers() == 1) {
        mainPauseDisable(0xA);
    }
    pressed = joyGetPressed((s32) *arg1);
    if (multiPlayerGame != 0 && (D_800FED63_B1763[*arg1 * 0xA0] == 0 || multiFinished != 0)) {
        pressed = 0;
    }
    if ((pressed & 0xF00F) != 0) {
        controlRestartPlayer((void *) arg0, arg1);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlFrozen.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void controlRestartPlayer(void *arg0, s8 *arg1) {
    u8 *chr;
    Object **list;
    Object *cands[8];
    Object *o;
    Object *sel;
    void *hitOut;
    s32 sp9C;
    s32 sp98;
    s32 cand;
    s32 v;

    chr = mainGetGameCharacter(arg1[0], arg1[1]);
    *(u16 *)(chr + 0x14) = *(u16 *)(chr + 0x34);
    *(s16 *)(*(u8 **)((u8 *)arg0 + 0x4C) + 6) = 0;
    *(s16 *)chr = 0;
    if (mainGetNumberOfPlayers() < 2) {
        mainRestartAfterDeath(&sp9C);
        return;
    }
    list = objGetObjList(&sp9C, &sp98);
    cand = 0;
    if (sp9C < sp98) {
        do {
            o = list[sp9C];
            sp9C++;
            if (o->behaviorId == 6) {
                v = hitPlayer(o->segment.trans.x_position, o->segment.trans.y_position,
                              o->segment.trans.z_position, 32.0f, 0, &hitOut);
                if (v == 0 || (v == 1 && arg0 == hitOut)) {
                    cands[cand] = o;
                    cand++;
                }
            }
        } while (sp9C < sp98);
    }
    if (cand == 0) {
        sel = (Object *) arg0;
    } else if (cand == 1) {
        sel = cands[0];
    } else {
        sel = cands[mathRnd(0, cand - 1)];
    }
    controlPlayerReInit(arg0, sel->segment.trans.x_position, sel->segment.trans.y_position,
                        sel->segment.trans.z_position, sel->segment.trans.y_rotation,
                        sel->segment.trans.x_rotation, sel->segment.trans.z_rotation);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlRestartPlayer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// asm: $f12 is never written in this function, so the float passed to the camera helpers
// is whatever the caller left in $f12.
void controlFadePlayer(void *arg0, void *arg1, s32 arg2) {
    u8 *state = (u8 *) arg0;
    u8 *cam = (u8 *) arg1;
    f32 t;
    s32 fadeOk;
    s32 maxFade = 0x28;
    s32 kind;
    s8 fade;

    fadeOk = *(u16 *)(state + 0x540) & 0xF;
    if (frontGetTargetControl((s8) state[0]) != 0) {
        fadeOk = 0;
    }
    if ((*(s8 *)(state + 1) & 3) == 3) {
        fadeOk = 0;
    }
    kind = state[0x568];
    if (kind == 0xB || kind == 5) {
        fadeOk = 1;
        if (cam != NULL && cam[0x70] == 7) {
            maxFade = 0x40;
        }
    } else if (kind == 8 || kind == 6 || kind == 7 || kind == 4) {
        fadeOk = 0;
    } else if (lobbycamInuse(t, cam) != 0) {
        fadeOk = 0;
    }
    if (state[0x19D] != 0 || state[0x1F9] != 0 || state[0x1FA] != 0 || state[0x198] != 0) {
        fadeOk = 0;
    }
    if (fadeOk != 0 && staticcamInuse(t, (s32) cam) == 0) {
        *(s8 *)(state + 0x19C) = (s8) (*(s8 *)(state + 0x19C) + arg2);
        if (maxFade < *(s8 *)(state + 0x19C)) {
            *(s8 *)(state + 0x19C) = (s8) maxFade;
        }
    } else {
        fade = *(s8 *)(state + 0x19C);
        if (fade != 0) {
            fade = (s8) (fade - (arg2 * 0x10));
            *(s8 *)(state + 0x19C) = fade;
            if (fade < 0) {
                *(s8 *)(state + 0x19C) = 0;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlFadePlayer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void controlWalkingBack(s32 arg0, u8 *state, f32 *arg2, s32 arg3, s16 arg4, s16 arg5, f32 arg6, f32 arg7) {
    s16 diff = (s16) (arg3 - *(s16 *)(state + 0x11C));
    f32 target;

    if (state[0x569] != 0) {
        if (-arg4 < diff && diff < arg4) {
            state[0x569] = 0;
        }
        if (!(*(u16 *)(state + 0x540) & 0xF)) {
            D_800A2DB0_A39B0 += 1;
            if (D_800A2DB0_A39B0 >= 0x1E) {
                state[0x569] = 0;
            }
        } else {
            D_800A2DB0_A39B0 = 0;
        }
    } else if (*(u16 *)(state + 0x540) & 0xF) {
        if (frontGetTargetControl((s8) state[0]) == 0 && (diff < -arg5 || arg5 < diff)) {
            state[0x569] = 1;
        }
    }
    target = (state[0x569] != 0) ? arg7 : arg6;
    if (target < *arg2) {
        *arg2 = target;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlWalkingBack.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_80033EE8(u8 *obj) {
    switch (obj[1]) {
    case 0:
    case 4:
        return boyCanFire();
    case 1:
    case 5:
        return dogCanFire();
    case 2:
    case 6:
        return flamethrowerInit();
    default:
        return 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_80033EE8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 controlThrowWeapon(s32 arg0) {
    if (arg0 == 8 || (arg0 >= 0xA && arg0 <= 0xE)) {
        return 1;
    }
    if (arg0 == 9) {
        return 2;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlThrowWeapon.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s16 dAngle(s16 a, s16 b, f32 c) {
    s32 diff = (u16) (b - a);
    s32 negDiff = (u16) (a - b);

    if (negDiff < diff) {
        diff = -negDiff;
    }
    return (s16) (a + (s32) ((f32) diff * c));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/dAngle.s")
#endif

void controlMakeGravity(u8 *player) {
    f32 *table1[2];
    f32 *table2;

    table1[0] = (f32 *) objGetTable(1);
    table2 = (f32 *) objGetTable(2);
    controlchr_gravity = table1[0][((s8 *) player)[1] & 3] * table2[((s8 *) player)[0x575]];
    if (player[0x194] == 1) {
        controlchr_gravity = 0.0f;
    }
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
f32 controlMakeV(f32 arg0, f32 arg1, f32 *table, f32 arg3) {
    f32 x1 = arg1 * 10.0f;
    s32 i1 = (s32) x1;
    f32 x0 = arg0 * 10.0f;
    s32 i0 = (s32) x0;
    f32 v1 = table[i1] + ((table[i1 + 1] - table[i1]) * (x1 - (f32) i1));
    f32 v0 = table[i0] + ((table[i0 + 1] - table[i0]) * (x0 - (f32) i0));

    return (v1 - v0) / arg3;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlMakeV.s")
#endif

void controlFSUvels(s16 *rotation, u8 *player) {
    s16 sp18[3];

    sp18[0] = rotation[0];
    sp18[1] = rotation[1];
    sp18[2] = 0;
    pointListRPY(3, sp18, D_800A2DB4_A39B4, (f32 *) (player + 0x18));
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// asm: four flame slots. Per-slot bytes on arg1: mode 0x5B8, timer 0x5AC, phase 0x5A8;
// cone object pointers at 0x598 (stride 4); flag bits at 0x14A. arg0+0x78 points to a
// pointer whose byte 0x3B is reduced by arg4*8 on entry.
void controlUpdateJetFlames(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4) {
    u8 *obj = (u8 *)arg0;
    u8 *pl = (u8 *)arg1;
    u8 *sp48 = NULL;
    void **pp78;
    s32 i;
    s32 bit = 1;

    pp78 = *(void ***)(obj + 0x78);
    if (pp78 != NULL) {
        sp48 = (u8 *)*pp78;
        if (sp48 != NULL) {
            u8 v = sp48[0x3B];
            s32 t8 = arg4 * 8;

            if (t8 < (s32)v) {
                sp48[0x3B] = (u8)(v - t8);
            } else {
                sp48[0x3B] = 0;
            }
        }
    }

    for (i = 0; i < 4; i++, bit <<= 1) {
        void *cone = *(void **)(pl + 0x598 + i * 4);

        if (cone != NULL) {
            s32 t = pl[0x5AC + i];
            s32 ph = *(s8 *)(pl + 0x5A8 + i);
            s32 len0 = *(s16 *)((u8 *)cone + 0x20);
            s32 len = len0;
            s32 mode = pl[0x5B8 + i];
            s32 sinv;
            s32 prod;

            switch (mode) {
            case 0:
                t = 0;
                if (*(s8 *)(pl + 0x14A) & bit) {
                    s32 saved = *(s32 *)(obj + 0x84);

                    *(s32 *)(obj + 0x84) = arg3;
                    partUpdateTriggers(obj, 2);
                    *(s32 *)(obj + 0x84) = saved;
                    pl[0x5B8 + i] = 1;
                }
                break;
            case 1:
                t += arg4 << 5;
                len = (len0 * t) >> 7;
                if (t >= 0x100) {
                    t = 0xFF;
                    if (sp48 != NULL) {
                        sp48[0x3B] = 0x80;
                    }
                    if (*(s8 *)(pl + 0x14A) & bit) {
                        pl[0x5B8 + i] = 2;
                    } else {
                        pl[0x5B8 + i] = 3;
                    }
                }
                break;
            case 2:
                t += arg4 * 0x10;
                if (t >= 0x100) {
                    t = 0xFF;
                }
                ph += arg4 * 0x10;
                sinv = mathSin((s16)(ph << 8));
                *(s32 *)(obj + 0x84) = arg2;
                prod = (len0 * t) >> 8;
                len = ((sinv + 0x18000) * prod) >> 16;
                if (!(*(s8 *)(pl + 0x14A) & bit)) {
                    pl[0x5B8 + i] = 3;
                }
                break;
            case 3:
                t -= arg4 * 8;
                if (t <= 0) {
                    t = 0;
                    pl[0x5B8 + i] = 0;
                } else {
                    ph += arg4 * 0x10;
                    sinv = mathSin((s16)(ph << 8));
                    prod = (len0 * t) >> 8;
                    len = ((sinv + 0x18000) * prod) >> 16;
                    if (*(s8 *)(pl + 0x14A) & bit) {
                        pl[0x5B8 + i] = 2;
                    }
                }
                break;
            default:
                break;
            }

            pl[0x5AC + i] = (u8)t;
            pl[0x5A8 + i] = (u8)ph;
            if (t != 0) {
                fxMakeConeTextureCoords(cone, (s16)((s8)pl[0x5A8 + i] << 8));
                fxMakeConeLength(cone, (s16)len, pl[0x5AC + i]);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlUpdateJetFlames.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_800344C8(ObjectTransform *obj, u8 *state, f32 *vec, s32 arg3) {
    u8 st568 = state[0x568];
    s32 active = 0;
    s16 yawAng = 0;
    s16 pitchAng = 0;
    f32 blend;

    switch (state[1]) {
    case 0:
    case 4:
    case 1:
    case 5:
        active = (st568 == 2 || st568 == 0xA);
        break;
    case 2:
    case 6:
    case 3:
    case 7:
        active = ((*(u8 **)(state + 0x360))[5] & state[0x532]) != 0;
        break;
    }
    if (active) {
        f32 sinA = Sinf(-obj->y_rotation);
        f32 cosA = Cosf((s32) -obj->y_rotation);
        f32 side = (vec[2] * cosA) - (vec[0] * sinA);

        yawAng = (s16) Arctanf(-((vec[2] * sinA) + (vec[0] * cosA)), vec[1]);
        pitchAng = (s16) Arctanf(side, vec[1]);
    }
    pitchAng = (s16) (pitchAng + *(s16 *)(state + 0x11E));
    yawAng = (s16) (yawAng + *(s16 *)(state + 0x120));
    blend = 1.0f - Powerf(0.96f, arg3);
    obj->z_rotation = dAngle(obj->z_rotation, yawAng, blend);
    obj->x_rotation = dAngle(obj->x_rotation, pitchAng, blend);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_800344C8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void controlHalfTurn(s16 *arg0, u8 *state, f32 *arg2, s16 *arg3, s16 arg4, s16 arg5, s32 *arg6, f32 arg7) {
    *arg6 = 0;
    if ((*(s32 *)((u8 *) controlModeKeys + 0xC) & controlDkeys) || state[0x569] != 0 ||
        (*(s8 *)(state + 0x1F4) != 0 && frontGetTargetControl((s8) state[0]) == 0) ||
        (state[0x568] != 0 && state[0x568] != 2)) {
        state[0x13E] = 0;
    } else if (state[0x13E] == 0) {
        s16 cur = *arg0;
        s16 delta = (s16) (cur - *arg3);

        if (delta < -arg4 || arg4 < delta) {
            *(s16 *)(state + 0x13C) = cur;
            state[0x13E] = 1;
            state[0x13F] = 0;
            if (*(f32 *)(state + 0x4) < -2.5f) {
                state[0x576] = 2;
                state[0x13F] = 1;
                *arg6 = 1;
            }
        }
    } else {
        if (state[0x13F] != 0) {
            state[0x576] = 2;
            *arg2 = 0.0f;
        } else {
            f32 ax = -Sinf(*(s16 *)(state + 0x13C));
            f32 az = -Cosf((s32) *(s16 *)(state + 0x13C));
            f32 sinH = Sinf(*arg0);
            f32 cosH = Cosf((s32) *arg0);
            f32 xj = (f32) controlXjoy;
            f32 yj = (f32) -controlYjoy;
            f32 px = ax * ((xj * cosH) + (yj * sinH));
            f32 pz = az * ((yj * cosH) - (xj * sinH));

            *arg2 = sqrtf((px * px) + (pz * pz)) * arg7;
        }
        {
            s16 var = *arg3;
            s16 turnFromStart = (s16) (*(s16 *)(state + 0x13C) - var);
            s16 turnFromCur;

            if (-arg4 < turnFromStart && turnFromStart < arg4) {
                state[0x13E] = 0;
            }
            turnFromCur = (s16) (var - *arg0);
            if (-arg5 < turnFromCur && turnFromCur < arg5) {
                state[0x13E] = 0;
            }
        }
        if (state[0x13E] == 0) {
            if (*arg2 > 0.0f) {
                *arg2 = -*arg2;
            }
            if (*(f32 *)(state + 0x4) > 0.0f) {
                *(f32 *)(state + 0x4) = -*(f32 *)(state + 0x4);
            }
            state[0x576] = 0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlHalfTurn.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void controlUpdateBreathing(u8 *state, f32 arg1) {
    f32 mag;
    f32 target;
    f32 rate;
    f32 cur;
    f32 period;
    s32 steps;

    if (state[0x568] == 0xA) {
        state[0x12E] = 0;
        state[0x12F] = 0;
    }
    mag = *(f32 *)(state + 0x4);
    if (mag < 0.0f) {
        mag = -mag;
    }
    cur = *(f32 *)(state + 0x10);
    if (cur < 0.0f) {
        cur = -cur;
    }
    if (mag < cur) {
        mag = cur;
    }
    if (mag >= 4.0f) {
        target = 1.0f;
    } else {
        target = mag * 0.25f;
    }
    if (*(f32 *)(state + 0x134) < target) {
        rate = 0.0013f;
    } else {
        rate = 0.0025f;
    }
    steps = (s32) arg1;
    cur = *(f32 *)(state + 0x134);
    *(f32 *)(state + 0x134) = cur + ((target - cur) * (1.0f - Powerf(1.0f - rate, steps)));
    period = 180.0f + (-130.0f * *(f32 *)(state + 0x134));
    *(f32 *)(state + 0x130) += arg1 / period;
    if (*(f32 *)(state + 0x130) >= 1.0f) {
        state[0x12F] = 1;
        state[0x12E] = (s8) (s32) (period * 0.2f);
        *(f32 *)(state + 0x130) -= 1.0f;
        return;
    }
    state[0x12E] = (u8) ((s8) state[0x12E] - steps);
    if ((s8) state[0x12E] < 0) {
        state[0x12E] = 0;
    }
    state[0x12F] = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlUpdateBreathing.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 controlGroundHits(ObjectTransform *obj, u8 *state, f32 arg2) {
    f32 pts[8][3];       /* sp158: state+0x3C4 points, written back to state+0x484 at the end */
    f32 deltas[8][3];    /* spF8: points relative to obj position */
    f32 ptParam[8];      /* spD8: list item +0xC per point */
    u16 mask[8];         /* sp70: list item +0x10 per point (|0x40 if state[0x531] bit i) */
    u32 hits[80];        /* sp1B8: 8 hit records of 0x28 bytes (trackGetPlayerIntersect output) */
    f32 dir[3];          /* spCC: normalised sum of hit-record vectors */
    f32 outVec[3];       /* spC0: out vector of trackGetPlayerIntersect */
    s32 outIdx;          /* sp2F8: out index of trackGetPlayerIntersect */
    void *sp30C = NULL;  /* hit-record pointer taken from flag 0x40 */
    s32 idxSet = -1;     /* sp94: index of the hit record that matched the 0x26/0x20 test */
    s32 posOverride = 0; /* sp9C */
    s32 ra = 0;          /* var_ra */
    s32 flags = 0;       /* var_s2, return value */
    s32 numPts;
    u8 flags531;
    u32 hitRes;
    s32 i;
    u8 *e;
    u8 fl;
    u8 bit;
    f32 sx = 0.0f, sy = 0.0f, sz = 0.0f;
    f32 x, y, z, len, len2, scale;
    void **items;
    f32 *src;
    f32 *dst;
    f32 *s;

    /* count and flags are read before the call, as in the asm */
    numPts = *(s8 *)(state + 0x530);
    flags531 = state[0x531];
    func_80035628(obj, state, arg2);

    /* per-point setup: copy points, list values and deltas from obj */
    if (*(s8 *)(state + 0x530) > 0) {
        src = (f32 *)(state + 0x3C4);
        i = 0;
        do {
            items = *(void ***)(*(void **)(state + 0x360));
            e = (u8 *)items[i];
            pts[i][0] = src[i * 3 + 0];
            pts[i][1] = src[i * 3 + 1];
            pts[i][2] = src[i * 3 + 2];
            ptParam[i] = *(f32 *)(e + 0xC);
            mask[i] = (u16) e[0x10];
            if ((flags531 >> i) & 1) {
                mask[i] = mask[i] | 0x40;
            }
            deltas[i][0] = pts[i][0] - obj->x_position;
            deltas[i][1] = pts[i][1] - obj->y_position;
            deltas[i][2] = pts[i][2] - obj->z_position;
            i++;
        } while (i < *(s8 *)(state + 0x530));
    }

    trackMakePolylist(numPts, (f32 *)(state + 0x484), &pts[0][0], (s32 *) ptParam,
                      *(s32 *)(state + 0x518), *(s32 *)(state + 0x51C), *(s32 *)(state + 0x514));
    hitRes = trackGetPlayerIntersect(obj, (f32 *)((u8 *)obj + 0xC), (f32 *)(state + 0x484),
                                     &pts[0][0], ptParam, &deltas[0][0], mask, hits,
                                     numPts, &outIdx, outVec);

    if ((hitRes & 0x11110000) == 0x11110000) {
        obj->x_position = *(f32 *)(state + 0x524);
        obj->y_position = *(f32 *)(state + 0x528);
        obj->z_position = *(f32 *)(state + 0x52C);
        flags = 2;
        posOverride = 1;
    } else if ((hitRes & 0xFFFF0000) == 0xFFFF0000) {
        flags = 2;
        ra = 1;
        obj->x_position = *(f32 *)(state + 0x524);
        obj->y_position = *(f32 *)(state + 0x528);
        obj->z_position = *(f32 *)(state + 0x52C);
    }
    idxSet = -1;

    state[0x532] = 0;
    state[0x533] = 0;
    state[0x534] = 0;
    state[0x184] = 1;
    sp30C = NULL;
    state[0x187] = 0;
    *(void **)(state + 0x510) = NULL;
    *(u32 *)(state + 0x520) = 0;

    /* hit-record loop: classify each record, accumulate the normal sum */
    for (i = 0; i < numPts; i++) {
        bit = (u8) (1 << i);
        e = (u8 *)hits + i * 0x28;
        fl = e[0x25];

        if ((hitRes >> i) & 1) {
            if (fl & 1) {
                if (fl & 0x12) {
                    if (e[0x26] != 0 && (*(u32 *)(e + 0x20) & 0xCE000000)) {
                        idxSet = i;
                    } else {
                        state[0x532] |= bit;
                        if ((fl & 0x10) && (mask[i] & 0x22) && *(void **)e != NULL) {
                            *(void **)(state + 0x510) = *(void **)e;
                        }
                        if (((fl & 2) && (fl & 0x10)) || *(s8 *)(e + 0x27) >= 2) {
                            if (mask[i] & 0x22) {
                                state[0x184] = 0;
                            }
                        }
                    }
                }
                if (fl & 0x48) {
                    state[0x534] |= bit;
                    if (fl & 0x40) {
                        sp30C = *(void **)e;
                    }
                }
                if (fl & 0x24) {
                    state[0x533] |= bit;
                    flags |= 1;
                    if (*(s32 *)(state + 0x16C) == 0 && (fl & 0x20)) {
                        state[0x184] = 0;
                    }
                }
                if (fl & 0x80) {
                    if (mask[i] & 0x22) {
                        state[0x532] |= bit;
                    }
                    ra |= 2;
                }
            }
        }

        if (((hitRes >> i) & 1) && (fl & 0x12)) {
            sx += *(f32 *)(e + 4);
            sy += *(f32 *)(e + 8);
            sz += *(f32 *)(e + 0xC);
        }

        state[0x4E4 + i] = e[0x24];
        *(s32 *)(state + 0x4EC + i * 4) = *(s32 *)(e + 0x20);
        *(u32 *)(state + 0x520) |= *(u32 *)(e + 0x20);
    }

    /* normalised sum direction */
    dir[0] = 0.0f;
    dir[1] = 0.0f;
    dir[2] = 0.0f;
    if (hitRes != 0) {
        len = sqrtf((sx * sx) + (sy * sy) + (sz * sz));
        if (len > 0.0f) {
            dir[0] = sx / len;
            dir[1] = sy / len;
            dir[2] = sz / len;
        }
    }

    func_800344C8(obj, state, dir, (s32) arg2);

    /* speed/velocity selection from the intersect results */
    if (posOverride != 0) {
        if (sp30C != NULL && *(s16 *)(*(u8 **)((u8 *)sp30C + 0x5C) + 0x12C) != 0) {
            state[0x187] = 1;
            flags |= 4;
        } else if (*(void **)(state + 0x510) != NULL &&
                   *(s16 *)(*(u8 **)(*(u8 **)(state + 0x510) + 0x5C) + 0x12C) != 0) {
            state[0x187] = 2;
        }
    } else if (ra != 0) {
        x = outVec[0];
        z = outVec[2];
        len2 = (x * x) + (z * z);
        if (len2 > 0.0f) {
            len = sqrtf(len2);
            state[0x149] = 10;
            *(f32 *)(state + 0x6C) = (x / len) * 5.0f;
            *(f32 *)(state + 0x70) = (z / len) * 5.0f;
        }
    } else if ((*(u32 *)(state + 0x520) & 0x8000) && state[0x568] != 0xA) {
        x = outVec[0];
        y = outVec[1];
        z = outVec[2];
        len2 = (x * x) + (z * z);
        if (len2 > 0.0f) {
            len = sqrtf(len2);
            if (y < len) {
                state[0x149] = 0x14;
                *(f32 *)(state + 0x6C) = (x / len) * 5.0f;
                *(f32 *)(state + 0x70) = (z / len) * 5.0f;
            }
        }
    } else if (outIdx >= 0) {
        e = (u8 *)hits + outIdx * 0x28;
        x = *(f32 *)(e + 4);
        z = *(f32 *)(e + 0xC);
        len2 = (x * x) + (z * z);
        if (len2 > 0.0f) {
            if (levelGetNumber() == 0x81) {
                scale = 8.0f;
            } else {
                scale = 20.0f;
            }
            len = sqrtf(len2);
            state[0x149] = 10;
            *(f32 *)(state + 0x6C) = (x / len) * scale;
            *(f32 *)(state + 0x70) = (z / len) * scale;
        }
    } else if (idxSet != -1) {
        if (*(f32 *)((u8 *)obj + 0x20) < 0.0f) {
            e = (u8 *)hits + idxSet * 0x28;
            x = *(f32 *)(e + 4);
            z = *(f32 *)(e + 0xC);
            len2 = (x * x) + (z * z);
            if (len2 > 0.0f) {
                len = sqrtf(len2);
                state[0x149] = 5;
                *(f32 *)(state + 0x6C) = (x / len) * 5.0f;
                *(f32 *)(state + 0x70) = (z / len) * 5.0f;
            }
        }
    }

    /* write the point list back to state+0x484: remainder loop, then 4-point unrolled loop */
    if (numPts > 0) {
        dst = (f32 *)(state + 0x484);
        s = &pts[0][0];
        i = 0;
        if ((numPts & 3) != 0) {
            do {
                dst[0] = s[0];
                dst[1] = s[1];
                dst[2] = s[2];
                dst += 3;
                s += 3;
                i++;
            } while (i != (numPts & 3));
        }
        if (i != numPts) {
            do {
                dst[0] = s[0];
                dst[1] = s[1];
                dst[2] = s[2];
                dst[3] = s[3];
                dst[4] = s[4];
                dst[5] = s[5];
                dst[6] = s[6];
                dst[7] = s[7];
                dst[8] = s[8];
                dst[9] = s[9];
                dst[10] = s[10];
                dst[11] = s[11];
                dst += 12;
                s += 12;
                i += 4;
            } while (i != numPts);
        }
    }

    return flags;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlGroundHits.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void controlSetTransition(s32 arg0, u8 *state, u8 *table, s32 arg3) {
    u8 *entry;
    u8 **keys;
    f32 dur;
    s32 count;
    s32 i;

    entry = table + ((arg3 & 0xFF) * 0x14);
    if (entry != *(u8 **)(state + 0x360)) {
        state[0x531] = entry[4];
        *(u8 **)(state + 0x360) = entry;
        state[0x535] = (s8) *(s32 *)(entry + 0x8);
        dur = (f32) (s8) state[0x535];
        keys = *(u8 ***)entry;
        count = (s8) state[0x530];
        for (i = 0; i < count; i++) {
            f32 *cur = (f32 *)(state + 0x364 + i * 12);
            f32 *out = (f32 *)(state + 0x424 + i * 12);
            u8 *key = keys[i];

            out[0] = (*(f32 *)(key + 0x0) - cur[0]) / dur;
            out[1] = (*(f32 *)(key + 0x4) - cur[1]) / dur;
            out[2] = (*(f32 *)(key + 0x8) - cur[2]) / dur;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlSetTransition.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80035628(ObjectTransform *obj, u8 *state, f32 arg2) {
    s16 rot[3];
    f32 step;
    s8 frames;
    s32 count;
    s32 i;
    u8 **keys;

    rot[0] = obj->y_rotation;
    if (state[0x568] == 4 && (*(s8 *)(state + 1) & 3) != 2) {
        rot[1] = *(s16 *)(state + 0x12A);
        rot[2] = *(s16 *)(state + 0x12C);
    } else {
        rot[1] = obj->x_rotation;
        rot[2] = obj->z_rotation;
    }

    frames = (s8) state[0x535];
    step = 0.0f;
    if (frames > 0) {
        s8 left = (s8) (frames - (s32) arg2);

        if (left >= 0) {
            state[0x535] = (u8) left;
            step = arg2;
        } else {
            state[0x535] = 0;
            step = (f32) frames;
        }
    }

    keys = *(u8 ***)(*(u8 **)(state + 0x360));
    count = (s8) state[0x530];
    for (i = 0; i < count; i++) {
        f32 *pos = (f32 *)(state + 0x364 + i * 12);
        f32 *delta = (f32 *)(state + 0x424 + i * 12);
        f32 *out = (f32 *)(state + 0x3C4 + i * 12);
        u8 *key = keys[i];
        s32 j;

        if (step > 0.0f) {
            for (j = 0; j < 3; j++) {
                pos[j] = pos[j] + (delta[j] * step);
            }
        }
        out[0] = pos[0];
        out[1] = pos[1];
        out[2] = pos[2];
        if (key[0x11] != 0) {
            mathOneFloatRPY(rot, out);
        }
        out[0] = out[0] + obj->x_position;
        out[1] = out[1] + obj->y_position;
        out[2] = out[2] + obj->z_position;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_80035628.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void controlPlatform(ObjectTransform *obj, u8 *state, s32 arg2) {
    u8 *plat;
    u8 *pd;
    s16 dang;
    f32 dx, dy, dz;
    f32 ox, oy, oz;
    u8 mode;
    u8 mtx;

    *(f32 *)(state + 0x524) = *(f32 *)(state + 0x3C);
    *(f32 *)(state + 0x528) = *(f32 *)(state + 0x40);
    *(f32 *)(state + 0x52C) = *(f32 *)(state + 0x44);

    plat = *(u8 **)(state + 0x510);
    pd = NULL;
    if (plat != NULL) {
        pd = *(u8 **)(plat + 0x5C);
    }
    if (pd != NULL && *(s16 *)(pd + 0x12C) != 0) {
        dang = (s16) (*(s16 *)plat - *(s16 *)(pd + 0x128));
        if (state[0x13E] != 0) {
            *(s16 *)(state + 0x13C) = (s16) (*(s16 *)(state + 0x13C) + dang);
        }

        mode = state[0x568];
        if (mode == 8 || mode == 6 || mode == 7 || mode == 0xC) {
            func_80035B30(obj, state, &ox, &oy, &oz);
            dx = ox - obj->x_position;
            dy = oy - obj->y_position;
            dz = oz - obj->z_position;
        } else {
            mtx = pd[0x12B];
            mathMtxXFMF((f32 (*)[4])(pd +((mtx ^ 1) << 6)), obj->x_position, obj->y_position, obj->z_position, &dx, &dy, &dz);
            mathMtxXFMF((f32 (*)[4])(pd +(mtx << 6) + 0x80), dx, dy, dz, &ox, &oy, &oz);
            dx = ox - obj->x_position;
            dy = oy - obj->y_position;
            dz = oz - obj->z_position;
        }

        mode = state[0x568];
        if (mode == 8 || mode == 7) {
            *(s16 *)(state + 0x11C) = *(s16 *)(state + 0x182);
        } else {
            *(s16 *)(state + 0x11C) = (s16) (*(s16 *)(state + 0x11C) + dang);
        }

        objMoveXYZ(obj, dx, dy, dz);
        *(f32 *)(state + 0x3C) = *(f32 *)(state + 0x3C) + dx;
        *(f32 *)(state + 0x40) = *(f32 *)(state + 0x40) + dy;
        *(f32 *)(state + 0x44) = *(f32 *)(state + 0x44) + dz;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlPlatform.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void controlAttitude(ObjectTransform *obj, u8 *state, s32 arg2) {
    u8 mode;
    s16 v;

    mode = state[0x568];
    if (mode == 8 || mode == 6 || mode == 7 || mode == 0xC) {
        v = *(s16 *)(state + 0x17E);
        *(s16 *)(state + 0x120) = v;
        obj->z_rotation = v;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlAttitude.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80035B30(ObjectTransform *obj, u8 *state, f32 *outX, f32 *outY, f32 *outZ) {
    u8 *pd;
    u8 idx;
    f32 t;
    f32 a[3];
    f32 b[3];
    f32 sv[3];
    f32 pv[3];
    f32 d[3];
    f32 ap[3];
    s16 rot[3];

    pd = *(u8 **)(*(u8 **)(state + 0x510) + 0x5C);
    idx = pd[0x12B];
    t = *(f32 *)(state + 0x164);

    pv[0] = *(f32 *)(state + 0x14C) + (t * (*(f32 *)(state + 0x158) - *(f32 *)(state + 0x14C)));
    pv[1] = *(f32 *)(state + 0x150) + (t * (*(f32 *)(state + 0x15C) - *(f32 *)(state + 0x150)));
    pv[2] = *(f32 *)(state + 0x154) + (t * (*(f32 *)(state + 0x160) - *(f32 *)(state + 0x154)));

    mathMtxXFMF((f32 (*)[4])(pd +((((idx ^ 1) & 0xFF)) << 6) + 0x80), pv[0], pv[1], pv[2], &sv[0], &sv[1], &sv[2]);
    sv[0] = sv[0] - obj->x_position;
    sv[1] = sv[1] - obj->y_position;
    sv[2] = sv[2] - obj->z_position;

    mathMtxXFMF((f32 (*)[4])(pd +(idx << 6) + 0x80), *(f32 *)(state + 0x14C), *(f32 *)(state + 0x150), *(f32 *)(state + 0x154), &a[0], &a[1], &a[2]);
    mathMtxXFMF((f32 (*)[4])(pd +(idx << 6) + 0x80), *(f32 *)(state + 0x158), *(f32 *)(state + 0x15C), *(f32 *)(state + 0x160), &b[0], &b[1], &b[2]);
    d[0] = b[0] - a[0];
    d[1] = b[1] - a[1];
    d[2] = b[2] - a[2];

    *(s16 *)(state + 0x182) = (s16) (((s32) Arctanf(d[0], d[2]) - 0x4000) & 0xFFF0);
    *(s16 *)(state + 0x17E) = (s16) (Arctanf(d[1], sqrtf((d[0] * d[0]) + (d[2] * d[2]))) & 0xFFF0);

    ap[0] = (t * d[0]) + a[0];
    ap[1] = (t * d[1]) + a[1];
    ap[2] = (t * d[2]) + a[2];
    *(f32 *)(state + 0x178) = ap[1];

    rot[0] = (s16) -*(s16 *)(state + 0x122);
    rot[1] = 0;
    rot[2] = (s16) -*(s16 *)(state + 0x126);
    mathOneFloatYPR(rot, sv);

    rot[0] = *(s16 *)(state + 0x182);
    rot[1] = 0;
    rot[2] = *(s16 *)(state + 0x17E);
    mathOneFloatRPY(rot, sv);

    *outX = ap[0] - sv[0];
    *outY = ap[1] - sv[1];
    *outZ = ap[2] - sv[2];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_80035B30.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// cf. controlGrabOK (sibling ledge test: same hit/track ledge lookup and seg layout).
// seg = pl+0x14C: start (x,y,z) +0x14C, end +0x158, t +0x164, direction vector ptr +0x168.
// asm: arg4 (stack 0x10) unused. Hit object is read from pl+0x510 before and after
// hitGetLedgeCrossed; its out pointer (sp+0xEC) is never read by the asm.
// asm: track-side trackGetAdjacentLedge call sets only a0 (a1 is stale), and the adjacent
// buffer is then read uninitialised, reproduced as-is.
void controlHangOK(ObjectTransform *obj, void *arg1, f32 arg2, f32 arg3, void *arg4, void *arg5) {
    u8 *pl = (u8 *)arg1;
    f32 *seg = (f32 *)(pl + 0x14C);
    f32 *a5f = (f32 *)arg5;
    f32 *dirp;
    f32 vt[3];
    f32 p0[3];
    f32 p1[3];
    f32 cpt[3];
    f32 adj[6];
    f32 dx;
    f32 dy;
    f32 dz;
    f32 horiz;
    f32 len;
    f32 t;
    f32 x;
    f32 pl4;
    f32 pl10;
    f32 sinN;
    f32 cosN;
    f32 sinYS;
    f32 cosYS;
    f32 sinA3;
    f32 cosA3;
    s32 a5i14;
    s32 a5i18;
    s16 yaw0;
    s16 pitch;
    s16 nYaw;
    s16 yawS;
    s16 rollAng;
    s16 adjAng;
    s16 tDiff;
    s32 a3i;
    s32 hit;
    s32 adjRes;
    s32 flag;
    s32 hvT = 0;
    void *hitObj;
    void *hitOut;
    u8 *hv = NULL;
    u8 *mtxBase;
    u8 *mtx;

    (void)arg4;

    if (*(s8 *)(pl + 0x184) != 0) {
        if (*(void **)(pl + 0x510) != NULL) {
            hit = hitGetLedgeCrossed((f32 *)(pl + 0x3C), (f32 *)((u8 *)obj + 0xC), seg, &hitOut);
        } else {
            hit = trackGetLedgeCrossed((f32 *)(pl + 0x3C), (f32 *)((u8 *)obj + 0xC), seg);
        }

        if (hit == -1) {
            hitObj = *(void **)(pl + 0x510);
            dirp = *(f32 **)(pl + 0x168);

            if (hitObj != NULL) {
                hv = *(u8 **)((u8 *)hitObj + 0x5C);
                hvT = hv[0x12B];
                mtxBase = hv + (hvT << 6);
                mtx = mtxBase + 0x80;
                mathMtxXFMF((f32 (*)[4])mtx, seg[0], seg[1], seg[2], &p0[0], &p0[1], &p0[2]);
                mathMtxXFMF((f32 (*)[4])mtx, seg[3], seg[4], seg[5], &p1[0], &p1[1], &p1[2]);
                matrixTransposeVectorMultiply(mtxBase, dirp, vt);
            } else {
                p0[0] = seg[0];
                p0[1] = seg[1];
                p0[2] = seg[2];
                p1[0] = seg[3];
                p1[1] = seg[4];
                p1[2] = seg[5];
                vt[0] = dirp[0];
                vt[1] = dirp[1];
                vt[2] = dirp[2];
            }

            dx = p1[0] - p0[0];
            dy = p1[1] - p0[1];
            dz = p1[2] - p0[2];
            t = seg[6];
            cpt[0] = (t * dx) + p0[0];
            cpt[1] = (t * dy) + p0[1];
            cpt[2] = (t * dz) + p0[2];

            horiz = sqrtf((dx * dx) + (dz * dz));
            yaw0 = (s16)Arctanf(dx, dz);
            pitch = (s16)Arctanf(dy, horiz);

            nYaw = -yaw0;
            sinN = Sinf(nYaw);
            cosN = Cosf((s32)nYaw);
            rollAng = (s16)Arctanf((vt[2] * sinN) + (vt[0] * cosN), vt[1]);

            a3i = (s32)arg3;
            cosA3 = Cosf(a3i);
            yawS = (s16)(yaw0 - 0x4000);
            cosYS = Cosf((s32)yawS);
            sinYS = Sinf(yawS);
            sinA3 = Sinf((s16)a3i);

            a5i14 = *(s32 *)((u8 *)arg5 + 0x14);
            a5i18 = *(s32 *)((u8 *)arg5 + 0x18);

            pl4 = *(f32 *)(pl + 0x4);
            pl10 = *(f32 *)(pl + 0x10);
            flag = 0;
            if ((-a5f[0] < pl4) && (pl4 < a5f[0]) && (-a5f[4] < pl10) && (pl10 < a5f[4])) {
                flag = 1;
            } else if ((arg2 == 0.0f) && ((pl4 != 0.0f) || (pl10 != 0.0f))) {
                flag = 1;
            } else if (((sinA3 * sinYS) + (cosYS * cosA3)) > 0.0f) {
                flag = 1;
            }

            if ((flag != 0) && ((obj->y_position - 10.0f) < cpt[1]) && (cpt[1] < (obj->y_position + 10.0f))) {
                obj->x_position = cpt[0];
                obj->y_position = cpt[1];
                obj->z_position = cpt[2];
                *(u8 *)(pl + 0x568) = 6;
                *(s8 *)(pl + 0x579) = (s8)a5i14;
                *(s16 *)(pl + 0x17C) = (s16)(*(s16 *)(pl + 0x11C) - yawS);
                *(s8 *)(pl + 0x578) = (s8)a5i18;
                *(s16 *)(pl + 0x17C) = (s16)(*(s16 *)(pl + 0x17C) / a5i14);
                *(u8 *)(pl + 0x576) = 0;
                *(u8 *)(pl + 0x13E) = 0;
                *(void **)(pl + 0x16C) = hitObj;
                *(f32 *)(pl + 0x170) = a5f[2] / (f32)a5i18;
                *(s16 *)(pl + 0x17E) = pitch;
                *(s16 *)(pl + 0x182) = yawS;
                *(s16 *)(pl + 0x180) = rollAng;
                *(u8 *)(pl + 0x1F4) = 0;
                *(f32 *)(pl + 0x178) = cpt[1];

                if (hitObj != NULL) {
                    adjRes = hitGetAdjacentLedge(seg, adj);
                } else {
                    adjRes = ((s32 (*)(f32 *))trackGetAdjacentLedge)(seg);
                }
                *(f32 *)(pl + 0x174) = 0.0f;

                if (adjRes != 0) {
                    if (*(void **)(pl + 0x510) != NULL) {
                        mtx = hv + (hvT << 6) + 0x80;
                        mathMtxXFMF((f32 (*)[4])mtx, adj[0], adj[1], adj[2], &p0[0], &p0[1], &p0[2]);
                        mathMtxXFMF((f32 (*)[4])mtx, adj[3], adj[4], adj[5], &p1[0], &p1[1], &p1[2]);
                        adjAng = (s16)Arctanf(p1[0] - p0[0], p1[2] - p0[2]);
                    } else {
                        adjAng = (s16)Arctanf(adj[3] - adj[0], adj[5] - adj[2]);
                    }

                    tDiff = (s16)(adjAng - yaw0);
                    if ((tDiff < -0xBB8) || (tDiff >= 0xBB9)) {
                        len = sqrtf((dx * dx) + (dy * dy) + (dz * dz));
                        if (t < 0.5f) {
                            x = len * t;
                            if (x < a5f[3]) {
                                *(f32 *)(pl + 0x174) = (a5f[3] - x) / (f32)a5i18;
                            }
                        } else {
                            x = len * (1.0f - t);
                            if (x < a5f[3]) {
                                *(f32 *)(pl + 0x174) = -(a5f[3] - x) / (f32)a5i18;
                            }
                        }
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlHangOK.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// asm: a2/a3 and the stack slot at sp+0x10 are spilled/unused. arg5 is the 6th argument.
// seg = arg1+0x14C is a ledge segment: start (x,y,z) at +0x14C, end at +0x158, t at +0x164.
// Hit object +0x5C holds the transform block used by mathMtxXFMF.
void controlGrabOK(ObjectTransform *obj, void *arg1, s32 arg2, s32 arg3, s32 arg4, void *arg5) {
    u8 *pl = (u8 *)arg1;
    f32 *seg = (f32 *)(pl + 0x14C);
    f32 vA[3];
    f32 vB[3];
    f32 boxHi[3];
    f32 boxLo[3];
    f32 cpt[3];
    f32 p0[3];
    f32 p1[3];
    f32 radius;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 horiz;
    f32 vel;
    f32 gNeg;
    f32 dxRel;
    f32 dyRel;
    f32 zRel;
    f32 disc;
    f32 sq;
    f32 tHit;
    s8 tb;
    s16 rot[3];
    s16 yaw;
    s16 pitch;
    void *hitObj;
    u8 *mtx;
    s32 hit;

    (void)arg2;
    (void)arg3;
    (void)arg4;

    if (*(f32 *)((u8 *)obj + 0x20) < 0.0f) {
        if (*(f32 *)(pl + 0x4) <= 0.0f) {
            radius = (*(f32 *)(pl + 0x4) / -5.0f) * 70.0f;
            if (radius < 20.0f) {
                radius = 20.0f;
            }
            vA[0] = obj->x_position;
            vA[1] = obj->y_position + *(f32 *)((u8 *)arg5 + 0x10);
            vA[2] = obj->z_position;
            vB[0] = obj->x_position - Sinf(*(s16 *)(pl + 0x11C)) * radius;
            vB[1] = vA[1];
            vB[2] = obj->z_position - Cosf(*(s16 *)(pl + 0x11C)) * radius;

            hitObj = NULL;
            hit = trackGetLedgeCrossed(vA, vB, seg);
            if (hit == 0) {
                boxLo[0] = obj->x_position - radius;
                boxLo[1] = obj->y_position;
                boxLo[2] = obj->z_position - radius;
                boxHi[0] = obj->x_position + radius;
                boxHi[1] = obj->y_position + 80.0f;
                boxHi[2] = obj->z_position + radius;
                hitMakePolylist(boxLo, boxHi, -1, 0, 0);
                hit = hitGetLedgeCrossed(vA, vB, seg, &hitObj);
            }

            if (hit == 1) {
                if (hitObj != NULL) {
                    u8 *hv = *(u8 **)((u8 *)hitObj + 0x5C);

                    mtx = hv + (hv[0x12B] << 6) + 0x80;
                    mathMtxXFMF((f32 (*)[4])mtx, seg[0], seg[1], seg[2], &p0[0], &p0[1], &p0[2]);
                    mathMtxXFMF((f32 (*)[4])mtx, seg[3], seg[4], seg[5], &p1[0], &p1[1], &p1[2]);
                } else {
                    p0[0] = seg[0];
                    p0[1] = seg[1];
                    p0[2] = seg[2];
                    p1[0] = seg[3];
                    p1[1] = seg[4];
                    p1[2] = seg[5];
                }

                dy = p1[1] - p0[1];
                dx = p1[0] - p0[0];
                dz = p1[2] - p0[2];
                cpt[0] = (seg[6] * dx) + p0[0];
                cpt[1] = (seg[6] * dy) + p0[1];
                cpt[2] = (seg[6] * dz) + p0[2];

                if ((obj->y_position <= cpt[1]) && (cpt[1] < vA[1])) {
                    horiz = sqrtf((dx * dx) + (dz * dz));
                    yaw = (s16)(Arctanf(dx, dz) - 0x4000);
                    pitch = (s16)Arctanf(dy, horiz);
                    cpt[0] += *(f32 *)((u8 *)arg5 + 0x8) * Sinf(yaw);
                    cpt[2] += *(f32 *)((u8 *)arg5 + 0x8) * Cosf(yaw);

                    vA[0] = 0.0f;
                    vA[1] = -*(f32 *)((u8 *)arg5 + 0x10);
                    vA[2] = 0.0f;
                    rot[0] = yaw;
                    rot[1] = 0;
                    rot[2] = pitch;
                    mathOneFloatRPY(rot, vA);
                    vA[0] += cpt[0];
                    vA[1] += cpt[1];
                    vA[2] += cpt[2];

                    dxRel = vA[0] - obj->x_position;
                    dyRel = vA[1] - obj->y_position;
                    zRel = vA[2] - obj->z_position;
                    vel = *(f32 *)((u8 *)obj + 0x20);
                    gNeg = -controlchr_gravity;
                    disc = (vel * vel) + ((2.0f * gNeg) * dyRel);

                    if (disc > 0.0f) {
                        sq = sqrtf(disc);
                        tHit = ((-sq) - vel) / gNeg;
                        if (tHit >= 1.0f) {
                            tb = (s8)(s32)tHit;
                            *(u8 *)(pl + 0x568) = 0xC;
                            *(s8 *)(pl + 0x578) = tb;
                            *(s16 *)(pl + 0x17C) = (s16)(*(s16 *)(pl + 0x11C) - yaw);
                            *(f32 *)(pl + 0x174) = zRel / (f32)tb;
                            *(f32 *)(pl + 0x170) = dxRel / (f32)tb;
                            *(s16 *)(pl + 0x17C) = (s16)(*(s16 *)(pl + 0x17C) / tb);
                            *(s16 *)(pl + 0x182) = yaw;
                            *(s16 *)(pl + 0x17E) = pitch;
                            *(f32 *)(pl + 0x178) = cpt[1];
                            *(void **)(pl + 0x16C) = hitObj;
                        }
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlGrabOK.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void controlSquashCheckPrior(ObjectTransform *obj, u8 *state, s32 arg2) {
    u8 *tr;
    u8 **keys;
    f32 rad;
    f32 lo[3];
    f32 hi[3];
    f32 pts[16][3];
    s16 rot[3];
    f32 best;
    f32 dist;
    void *hitPlat;
    void *cur;
    u8 mode;
    u8 mask;
    s32 count;
    s32 i;

    tr = *(u8 **)(state + 0x360);
    rad = *(f32 *)(tr + 0x10);
    lo[0] = obj->x_position - rad;
    lo[1] = obj->y_position;
    lo[2] = obj->z_position - rad;
    hi[0] = obj->x_position + rad;
    hi[1] = obj->y_position + *(f32 *)(tr + 0xC);
    hi[2] = obj->z_position + rad;
    hitCrateCheck(lo, hi, *(void **)(state + 0x510));

    mode = state[0x568];
    if (mode == 6 || mode == 8 || mode == 7 || mode == 0xC) {
        keys = *(u8 ***)tr;
        count = (s8) state[0x530];
        rot[0] = obj->y_rotation;
        rot[1] = obj->x_rotation;
        rot[2] = obj->z_rotation;

        for (i = 0; i < count; i++) {
            f32 *src = (f32 *)(state + 0x364 + i * 12);
            f32 *dst = pts[i];

            dst[0] = src[0];
            dst[1] = src[1];
            dst[2] = src[2];
            if (keys[i][0x11] != 0) {
                mathOneFloatRPY(rot, dst);
            }
            dst[0] = dst[0] + obj->x_position;
            dst[1] = dst[1] + obj->y_position;
            dst[2] = dst[2] + obj->z_position;
        }

        mask = state[0x531];
        best = hi[1];
        hitPlat = NULL;
        for (i = 0; i < count; i++) {
            if (!(mask & 1)) {
                void *hp = hitSquashCheck(pts[i], *(s32 *)(keys[i] + 0xC), *(void **)(state + 0x510), &dist);

                if (hp != NULL && dist <= best) {
                    best = dist;
                    hitPlat = hp;
                }
            }
            mask >>= 1;
        }

        if (hitPlat != NULL) {
            cur = *(void **)(state + 0x510);
            state[0x186] = 0x1E;
            if (cur != NULL) {
                *(void **)(state + 0x514) = cur;
                *(void **)(state + 0x510) = NULL;
                *(s32 *)(state + 0x16C) = 0;
            } else {
                *(void **)(state + 0x514) = hitPlat;
                state[0x149] = 0xA;
                *(f32 *)(state + 0x6C) = Sinf(*(s16 *)(state + 0x11C)) * 5.0f;
                *(f32 *)(state + 0x70) = Cosf((s32) *(s16 *)(state + 0x11C)) * 5.0f;
            }
        } else {
            cur = *(void **)(state + 0x510);
            if (cur != NULL && *(s16 *)(*(u8 **)((u8 *)cur + 0x5C) + 0x12C) != 0) {
                f32 y = obj->y_position;

                if (trackCylinderHeights(obj->x_position, obj->z_position, y,
                                         y + *(f32 *)(tr + 0xC) + 20.0f, *(f32 *)(tr + 0x10), 0, 0, 0) != 0) {
                    state[0x186] = 0x1E;
                    *(void **)(state + 0x510) = NULL;
                    *(s32 *)(state + 0x16C) = 0;
                    *(void **)(state + 0x514) = cur;
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlSquashCheckPrior.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void controlSquashCheckPost(ObjectTransform *obj, u8 *state, s32 arg2) {
    u8 *tr;
    u8 **keys;
    u8 *plat;
    void *best;
    f32 bestY;
    f32 dist;
    f32 pushX;
    f32 pushZ;
    s16 ang;
    s32 vt;
    u8 mask;
    u8 flag;
    s32 count;
    s32 i;
    s8 timer;

    timer = (s8) state[0x186];
    if (timer != 0) {
        state[0x186] = (u8) (timer - arg2);
        if ((s8) state[0x186] <= 0) {
            *(void **)(state + 0x514) = NULL;
            state[0x186] = 0;
        }
    }

    flag = state[0x187];
    if (flag == 1) {
        state[0x188] = 1;
    } else if (flag == 2) {
        plat = *(u8 **)(state + 0x510);
        state[0x186] = 0x1E;
        *(u8 **)(state + 0x510) = NULL;
        *(u8 **)(state + 0x514) = plat;
        ang = (s16) Arctanf(obj->x_position - *(f32 *)(plat + 0xC), obj->z_position - *(f32 *)(plat + 0x14));
        state[0x149] = 0xA;
        *(f32 *)(state + 0x6C) = Sinf(ang) * 10.0f;
        *(f32 *)(state + 0x70) = Cosf((s32) ang) * 10.0f;
    }

    best = NULL;
    if (state[0x188] != 0) {
        tr = *(u8 **)(state + 0x360);
        keys = *(u8 ***)tr;
        count = (s8) state[0x530];
        mask = state[0x531];
        bestY = obj->y_position + *(f32 *)(tr + 0xC);
        for (i = 0; i < count; i++) {
            if (!(mask & 1)) {
                void *hp = hitSquashCheck(state + 0x484 + i * 12, *(s32 *)(keys[i] + 0xC), *(void **)(state + 0x510), &dist);

                if (hp != NULL && dist <= bestY) {
                    bestY = dist;
                    best = hp;
                }
            }
            mask >>= 1;
        }

        if (best != NULL) {
            tr = *(u8 **)(state + 0x360);
            if (*(void **)(state + 0x510) != NULL) {
                *(void **)(state + 0x514) = best;
                state[0x186] = (u8) arg2;
                state[0x57A] = 0;
                *(f32 *)(state + 0x4C) = (bestY - obj->y_position) / *(f32 *)(tr + 0xC);
                if (*(f32 *)((u8 *)obj + 0x20) > 0.0f) {
                    *(f32 *)((u8 *)obj + 0x20) = 0.0f;
                }
            } else {
                state[0x186] = (u8) arg2;
                *(void **)(state + 0x514) = best;
                vt = *(s32 *)((u8 *)best + 0x8C);
                if (vt == 0) {
                    ang = (s16) Arctanf(obj->x_position - *(f32 *)((u8 *)best + 0xC),
                                        obj->z_position - *(f32 *)((u8 *)best + 0x14));
                } else {
                    ang = (s16) ((vt * 0xB6) + 0x8000);
                }
                pushX = Sinf(ang) * 5.0f;
                pushZ = Cosf((s32) ang) * 5.0f;
                state[0x149] = 0xA;
                *(f32 *)(state + 0x70) = pushZ;
                *(f32 *)(state + 0x6C) = pushX;
                state[0x57A] = 0;
                *(f32 *)(state + 0x4C) = (bestY - obj->y_position) / *(f32 *)(tr + 0xC);
                if (*(f32 *)((u8 *)obj + 0x20) > 0.0f) {
                    *(f32 *)((u8 *)obj + 0x20) = 0.0f;
                }
            }
        } else {
            state[0x188] = 0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlSquashCheckPost.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_800370D8(u8 *anim, f32 arg1) {
    f32 cur = *(f32 *)(anim + 0x48);
    f32 target = *(f32 *)(anim + 0x4C);

    if (cur < target) {
        cur = cur + ((((target - cur) * 0.125f) + 0.02f) * arg1);
        *(f32 *)(anim + 0x48) = cur;
        if (target <= cur) {
            *(f32 *)(anim + 0x48) = target;
            *(f32 *)(anim + 0x4C) = 1.0f;
        }
    } else {
        cur = cur + ((((target - cur) * 0.125f) - 0.02f) * arg1);
        *(f32 *)(anim + 0x48) = cur;
        if (cur <= target) {
            *(f32 *)(anim + 0x48) = target;
            *(f32 *)(anim + 0x4C) = 1.0f;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_800370D8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 controlCeiling(f32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    f32 p1[3];
    f32 p2[3];
    u8 hit[0x28];
    s32 result;

    result = 1;
    p1[0] = arg0;
    p1[1] = arg1;
    p1[2] = arg2;
    p2[0] = arg0;
    p2[1] = arg1 + arg3;
    p2[2] = arg2;
    trackMakePolylist(1, p1, p2, &arg4, 0, 0, 0);
    if (trackGetIntersect(0, p1, p2, arg4, 1, hit) != 0 && (hit[0x25] & 0x48)) {
        result = 0;
    }
    return result;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlCeiling.s")
#endif

void controlDisableJoypad(s32 arg0) {
    disablejoy = arg0;
}

void controlReadJoypad(s32 player) {
    if (player >= 0 && player < MAXCONTROLLERS && !disablejoy) {
        controlXjoy = joyGetStickX(player);
        controlAbsXjoy = joyGetAbsX(player);
        controlYjoy = joyGetStickY(player);
        controlAbsYjoy = joyGetAbsY(player);
        controlKeys = joyGetButtons(player);
        controlDkeys = joyGetPressed(player);
        controlReleasedKeys = joyGetReleased(player);
    } else {
        controlXjoy = 0;
        controlAbsXjoy = 0;
        controlYjoy = 0;
        controlAbsYjoy = 0;
        controlKeys = 0;
        controlDkeys = 0;
        controlReleasedKeys = 0;
    }
}

#ifdef VERSION_us
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void controlSetRumble(s32 arg0, s32 arg1, s32 arg3, s32 arg4) {
    s32 flags = arg1;
    s32 idx;

    if (arg3 >= 0 && arg3 < 8) {
        flags = arg1 | D_800A2DD8_A39D8[arg3];
    }
    if (arg4 >= 0x20) {
        if (arg4 >= 0x80) {
            flags |= 4;
        } else if (arg4 >= 0x40) {
            flags |= 2;
        } else {
            flags |= 1;
        }
    }
    idx = flags & 7;
    if (flags != 0) {
        rumbleMax(arg0, rumbletime_bytes[idx], rumbletime_floats[idx]);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlSetRumble.s")
#endif
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 controlGetMaxCharge(u8 *base, s32 idx) {
    if (idx == 4) {
        return 0x1E;
    }
    if (idx == 6) {
        return 0x6E;
    }
    return base[idx + 0x54] << 5;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlGetMaxCharge.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_80037380(u8 *obj, s32 arg1) {
    u16 mask;
    s32 start;
    s32 target;
    s32 bit;
    s32 countUp;
    s32 countDown;
    s32 next;

    target = 1 << arg1;
    start = 1 << obj[0x70];
    mask = *(u16 *)(obj + 0xA);
    countUp = 0;
    countDown = 0;

    if (start != target) {
        bit = start;
        do {
            next = bit * 2;
            if (mask & bit) {
                countUp += 1;
            }
            bit = next;
            if (next == 0x10000) {
                bit = 1;
            }
        } while (bit != target);
        bit = start;
        do {
            if (mask & bit) {
                countDown += 1;
            }
            next = bit >> 1;
            if (bit == 1) {
                next = 0x10000 >> 1;
            }
            bit = next;
        } while (next != target);
    }

    if (countDown >= countUp) {
        return 2;
    }
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_80037380.s")
#endif

// can_fire_weapon

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_80037428(u8 *state, u8 *chr) {
    u8 weapon;
    u8 *obj;

    if (DebugAmmoFlag != 0) {
        return 1;
    }
    weapon = chr[0x70];
    if (weapon == 0 || *(u16 *)(chr + 0x14 + weapon * 2) != 0) {
        return 1;
    }
    if (weapon == 0xD) {
        obj = *(u8 **)(state + 0x5CC);
        if (obj != NULL) {
            return *(s16 *)(obj + 0x48) == 0x59;
        }
        return 0;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_80037428.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 controlUpdateWeapon(void *arg0, u8 *state, f32 arg2) {
    s32 frames;
    s32 ret;
    s32 stop;
    s32 canFire;
    u8 *chr;
    s32 blocked;
    u8 weapon0;
    s32 maxCharge;
    u8 *owner;
    u8 *held;
    u8 *grab;
    UnkLight *light;
    s32 reset;
    s32 mode;
    s32 next;
    s32 found;
    u8 *entry;
    u8 wparam;
    u8 *col;
    f32 barrelX;
    f32 barrelY;
    f32 barrelZ;

    frames = (s32) arg2;
    stop = 0;
    ret = -1;
    canFire = func_80033EE8((u8 *) arg0);
    chr = mainGetGameCharacter(state[0], state[1]);
    blocked = func_80037428(state, chr);
    weapon0 = chr[0x70];
    maxCharge = controlGetMaxCharge(chr, weapon0);
    owner = NULL;
    if (*(u8 **)(state + 0x560) != NULL) {
        owner = *(u8 **)(*(u8 **)(state + 0x560) + 0x68);
    }
    reset = 0;
    light = *(UnkLight **)(state + 0x558);
    if (light != NULL) {
        col = D_800A2E10_A3A10 + chr[0x70] * 3;
        changeLightColour(light, col[0], col[1], col[2]);
    }
    if (chr[0x70] != 2 && chr[0x70] != 4) {
        state[0x540] &= 0xFD;
    }
    if ((u32) frames < state[0x542]) {
        state[0x542] = (u8) (state[0x542] - frames);
    } else {
        state[0x542] = 0;
    }

    held = *(u8 **)(state + 0x1A0);
    grab = held;
    if (grab != NULL) {
        if ((state[0x568] & 0xF) == 0xA) {
            *(u8 **)(state + 0x1A0) = NULL;
            grab = NULL;
        } else if (chr[0x70] == 0xC) {
            mode = *(s32 *) controlModeKeys;
            if (!(mode & controlDkeys)) {
                controlKeys &= ~mode;
                controlDkeys &= ~mode;
            } else {
                *(u8 **)(state + 0x1A0) = NULL;
                grab = NULL;
            }
        }
        if (grab == NULL) {
            *(s32 *)(*(u8 **)(held + 0x68) + 0x9C) = 0;
            state[0x538] = 0x3C;
            return -1;
        }
    }

    if ((*(s32 *) controlModeKeys & controlDkeys) && blocked == 0) {
        found = 0;
        next = D_800A2E40_A3A40[chr[0x70]];
        controlClearAimlocks(state);
        do {
            if (next == -1) {
                found = 1;
            } else if ((*(u16 *)(chr + 0xA) & (1 << next)) && *(u16 *)(chr + 0x14 + next * 2) != 0) {
                found = 1;
            } else {
                next = D_800A2E40_A3A40[next];
            }
        } while (!found);
        if (next != -1) {
            state[0x540] = (u8) (((func_80037380(chr, next) * 0x10) & 0x30) | (state[0x540] & 0xCF));
            state[0x543] |= 0x80;
            state[0x585] = (s8) next;
            chr[0x70] = (u8) next;
        }
    }

    if (*(u16 *)(arithmeticSums + 0xC) != 0xE773) {
        state[0x543] |= 0x80;
    }
    if (state[0x543] & 0x80) {
        mode = *(s32 *) controlModeKeys;
        if (mode & controlKeys) {
            controlKeys &= ~mode;
            controlDkeys &= ~mode;
        } else {
            state[0x543] &= 0x7F;
        }
    }
    if (blocked == 0) {
        controlKeys &= ~*(s32 *) controlModeKeys;
        controlDkeys &= ~*(s32 *) controlModeKeys;
    }

    if (state[0x568] != 4 && state[2] != 0) {
        if (controlThrowWeapon(chr[0x70]) == 0) {
            controlGetGunBarrelPos(arg0, state, &barrelX, &barrelY, &barrelZ);
            if (barrelY <= *(f32 *)(state + 0x5C)) {
                if (chr[0x70] == 3) {
                    *(s16 *)(state + 0x53E) = 0;
                    state[0x540] &= 0x3F;
                    reset = 1;
                }
                mode = *(s32 *) controlModeKeys;
                if ((mode & controlDkeys) && *(s32 *)(state + 0xC0) == 0) {
                    amSndPlay(0x1C8, state + 0xC0);
                    *(u16 *)(state + 0x53A) = 0x1C8;
                    mode = *(s32 *) controlModeKeys;
                }
                controlKeys &= ~mode;
                controlDkeys &= ~mode;
            }
        }
    }

    if (state[0x540] & 0x80) {
        if (*(s8 *)(state + 0x53D) != 0) {
            state[0x53D] = (u8) (*(s8 *)(state + 0x53D) - frames);
            if (*(s8 *)(state + 0x53D) <= 0) {
                state[0x53D] = 0;
                stop = 1;
            }
        } else if (canFire == 0 || (*(s32 *) controlModeKeys & controlKeys)) {
            reset = 1;
            if (*(s8 *)(state + 0x1F4) == 0) {
                state[0x1F4] = 0xF;
            }
            *(s16 *)(state + 0x53E) = (s16) (*(s16 *)(state + 0x53E) + frames);
            if (chr[0x70] == 3) {
                *(s16 *)(state + 0x53E) = (s16) (*(s16 *)(state + 0x53E) + frames);
            }
            if (maxCharge < *(s16 *)(state + 0x53E)) {
                *(s16 *)(state + 0x53E) = (s16) maxCharge;
            }
        } else {
            if (chr[0x70] == 0xB) {
                if ((state[0x568] & ~0x20) != 0xA) {
                    ret = 0xB;
                    state[0x53D] = 0x1A;
                } else {
                    state[0x53D] = 0;
                    state[0x540] &= 0x7F;
                }
            } else {
                stop = 1;
            }
        }

        if (stop != 0) {
            state[0x540] &= 0x7F;
            state[0x53D] = 0;
            state[0x538] = 0;
            if (*(s8 *)(state + 0x1F6) == 0) {
                state[0x1F6] = 7;
                wparam = weaponTable[weapon0 * 0x30 + 2];
                state[0x1F7] = (u8) (wparam + (((s32) (wparam * *(s16 *)(state + 0x53E))) >> 9));
            }
            if (chr[0x70] == 3) {
                ret = 3;
            }
            reset = func_80038488(arg0, state, weaponTable + weapon0 * 0x30, arg2);
            *(s16 *)(state + 0x53E) = 0x20;
        }
    } else if (canFire != 0) {
        if (*(s8 *)(state + 0x538) != 0) {
            state[0x538] = (u8) (*(s8 *)(state + 0x538) - frames);
            if (*(s8 *)(state + 0x538) < 0) {
                state[0x538] = 0;
            }
        }
        if (*(s8 *)(state + 0x53D) != 0) {
            state[0x53D] = (u8) (*(s8 *)(state + 0x53D) - frames);
            if (*(s8 *)(state + 0x53D) <= 0) {
                reset = func_80038488(arg0, state, weaponTable + weapon0 * 0x30, arg2);
                state[0x53D] = 0;
            }
        } else if (*(s32 *) controlModeKeys & controlKeys) {
            if (chr[0x70] == 0) {
                if (state[0x542] < 0xD3 && *(s8 *)(state + 0x538) == 0) {
                    state[0x542] = (u8) (state[0x542] + 0x2A);
                    state[0x540] &= 0x3F;
                    entry = weaponTable + weapon0 * 0x30;
                    state[0x53D] = *(s8 *)(entry + 6);
                    wparam = (u8) (*(s8 *)(state + 0x1F8) * frames);
                    reset = 0;
                    if (*(s8 *)(state + 0x53D) < (s8) wparam) {
                        state[0x53D] = wparam;
                    }
                    if (*(s8 *)(state + 0x1F6) == 0) {
                        state[0x1F6] = 7;
                        state[0x1F7] = entry[2];
                    }
                    ret = 0;
                    if (*(s8 *)(state + 0x53D) == 0) {
                        reset = func_80038488(arg0, state, entry, arg2);
                    }
                }
            } else {
                entry = weaponTable + weapon0 * 0x30;
                if (*(s8 *)(entry + 6) == -1) {
                    state[0x540] = (u8) ((state[0x540] | 0x80) & 0xBF);
                    reset = 1;
                    if (chr[0x70] == 3 && (*(s32 *) controlModeKeys & controlDkeys)) {
                        if (*(u8 **)(state + 0xF0) != NULL) {
                            amSndStopXYZ(*(u8 **)(state + 0xF0));
                        }
                        amSndPlayXYZ(0xFA, ((ObjectTransform *) arg0)->x_position,
                                     ((ObjectTransform *) arg0)->y_position,
                                     ((ObjectTransform *) arg0)->z_position, 4, state + 0xF0);
                        reset = 1;
                    }
                } else if (*(s8 *)(state + 0x538) == 0) {
                    reset = 0;
                    state[0x540] &= 0x7F;
                    if ((state[0x540] & 0x80) == 0) {
                        if (*(s8 *)(entry + 6) == -2) {
                            state[0x540] |= 0x40;
                            state[0x53D] = 0;
                        } else {
                            state[0x540] &= 0xBF;
                            state[0x53D] = *(s8 *)(entry + 6);
                        }
                    }
                    if ((state[0x540] & 0x80) != 0) {
                        *(s16 *)(state + 0x53E) = (s16) (*(s16 *)(state + 0x53E) - frames);
                        if (*(s16 *)(state + 0x53E) <= 0) {
                            *(s16 *)(state + 0x53E) = 0;
                            reset = 1;
                        }
                    }
                    wparam = (u8) (*(s8 *)(state + 0x1F8) * frames);
                    if (*(s8 *)(state + 0x53D) < (s8) wparam) {
                        state[0x53D] = wparam;
                    }
                    if (*(s8 *)(state + 0x1F6) == 0) {
                        state[0x1F6] = 7;
                        state[0x1F7] = entry[2];
                    }
                    ret = chr[0x70];
                    if (ret == 0xD && state[1] != 2 && state[1] != 6) {
                        u8 *tgt = *(u8 **)(state + 0x5CC);
                        if (tgt == NULL) {
                            state[0x53D] = 0;
                            ret = -1;
                        } else if (*(s16 *)(tgt + 0x48) == 0x59) {
                            u8 *racer = *(u8 **)(tgt + 0x68);
                            if (*(s16 *)(racer + 0x1E) < 0x3C) {
                                *(s16 *)(racer + 0x1E) = 0x3C;
                            }
                        }
                    }
                    if (*(s8 *)(state + 0x53D) == 0 && reset == 0) {
                        reset = func_80038488(arg0, state, entry, arg2);
                    }
                }
            }
            if (chr[0x70] == 2 && *(s8 *)(state + 0x53D) == 0) {
                if (state[0x540] & 0x80) {
                    state[0x540] &= 0xFD;
                } else {
                    state[0x540] |= 0x02;
                }
            }
        } else {
            state[0x53D] = 0;
            state[0x540] &= 0xBD;
            reset = 1;
            switch (chr[0x70]) {
            case 7:
                break;
            case 1:
            case 5:
                break;
            default:
                state[0x538] = 0;
                break;
            }
            if ((s8) weaponTable[weapon0 * 0x30 + 6] == -2) {
                *(s16 *)(state + 0x53E) = (s16) (*(s16 *)(state + 0x53E) + frames);
                if (maxCharge < *(s16 *)(state + 0x53E)) {
                    *(s16 *)(state + 0x53E) = (s16) maxCharge;
                }
            } else {
                *(s16 *)(state + 0x53E) = 0x20;
            }
        }
    } else {
        reset = 1;
    }

    if (reset != 0) {
        switch (chr[0x70]) {
        case 2:
            if (*(u16 *)(state + 0x53A) == 8) {
                if (*(s32 *)(state + 0xC0) != 0) {
                    amSndStop(*(s32 *)(state + 0xC0));
                }
                amSndPlay(0xE, state + 0xC0);
                if (*(s32 *)(state + 0x5D4) != 0) {
                    amSndStop(*(s32 *)(state + 0x5D4));
                }
                *(u16 *)(state + 0x53A) = 0xE;
                amSndPlay(0x1E1, state + 0x5D4);
            }
            break;
        case 6:
            if (*(s32 *)(state + 0xC0) != 0 && *(u16 *)(state + 0x53A) == 1) {
                amSndStop(*(s32 *)(state + 0xC0));
                *(u16 *)(state + 0x53A) = 0;
            }
            break;
        case 4:
            if (owner != NULL) {
                *(u8 *)(owner + 0xA7D) = 0;
                if (*(s32 *)(state + 0xC0) != 0 && *(u16 *)(state + 0x53A) == 0x97) {
                    *(u16 *)(state + 0x53A) = 0;
                }
            }
            break;
        }
        state[0x540] &= 0xFD;
    }

    if (owner != NULL && chr[0x70] != 4) {
        *(u8 *)(owner + 0xA7D) = 0;
    }
    if (owner != NULL && chr[0x70] == 4) {
        if (*(f32 *)(owner + 0xA58) > 0.1f) {
            state[0x540] |= 2;
        }
    }
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlUpdateWeapon.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void controlSelectNextWeapon(void *arg0, u8 *state) {
    u8 *chr;
    u8 cur;
    u8 next;
    u16 owned;
    u16 bit;

    chr = mainGetGameCharacter(state[0], state[1]);
    cur = chr[0x70];
    owned = *(u16 *)(chr + 0xA);
    next = cur;
    bit = (u16) (1 << cur);
    do {
        if (next == 0xF) {
            next = 0;
            bit = 1;
        } else {
            next += 1;
            bit = (u16) (bit * 2);
        }
    } while (!(owned & bit));

    if (next != cur) {
        if (cur == 2) {
            if (*(s32 *)(state + 0xC0) != 0) {
                amSndStop(*(s32 *)(state + 0xC0));
                *(u16 *)(state + 0x53A) = 0;
            }
        }
        chr[0x70] = next;
        state[0x543] &= 0x7F;
        state[0x540] = (u8) (((((u32) ((s32) (s8) state[0x540] * 4) >> 0x1E) | 2) * 0x10 & 0x30) | (state[0x540] & 0xCF));
        state[0x540] &= 0xBF;
        controlEmptyPlayersHand(arg0, next);
        controlClearAimlocks(state);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlSelectNextWeapon.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 controlSelectWeapon(void *arg0, u8 *state, s32 weapon) {
    u8 *chr;
    u8 cur;

    chr = mainGetGameCharacter(state[0], state[1]);
    cur = chr[0x70];
    if (weapon != cur && (*(u16 *)(chr + 0xA) & (1 << weapon))) {
        if (cur == 2) {
            if (*(s32 *)(state + 0xC0) != 0) {
                amSndStop(*(s32 *)(state + 0xC0));
                *(u16 *)(state + 0x53A) = 0;
            }
        }
        state[0x540] = (u8) (((func_80037380(chr, weapon) * 0x10) & 0x30) | (state[0x540] & 0xCF));
        state[0x540] &= 0xBF;
        state[0x543] &= 0x7F;
        chr[0x70] = (u8) weapon;
        controlEmptyPlayersHand(arg0, (u8) weapon);
        controlClearAimlocks(state);
        return 1;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlSelectWeapon.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void controlSelectPreviousWeapon(void *arg0, u8 *state) {
    u8 *chr;
    u8 cur;
    u8 prev;
    u16 owned;
    u32 bit;

    chr = mainGetGameCharacter(state[0], state[1]);
    cur = chr[0x70];
    owned = *(u16 *)(chr + 0xA);
    prev = cur;
    bit = (1 << cur) & 0xFFFF;
    do {
        if (prev == 0) {
            prev = 0xF;
            bit = 0x8000;
        } else {
            prev -= 1;
            bit = (bit >> 1) & 0xFFFF;
        }
    } while (!(owned & bit));

    if (prev != cur) {
        if (cur == 2) {
            if (*(s32 *)(state + 0xC0) != 0) {
                amSndStop(*(s32 *)(state + 0xC0));
                *(u16 *)(state + 0x53A) = 0;
            }
        }
        chr[0x70] = prev;
        state[0x543] &= 0x7F;
        state[0x540] = (u8) (((((u32) ((s32) (s8) state[0x540] * 4) >> 0x1E) | 1) * 0x10 & 0x30) | (state[0x540] & 0xCF));
        state[0x540] &= 0xBF;
        controlEmptyPlayersHand(arg0, prev);
        controlClearAimlocks(state);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlSelectPreviousWeapon.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void controlFireDummyShot(void *arg0, u8 *state) {
    UnkLight *light;

    light = *(UnkLight **)(state + 0x558);
    if (light != NULL) {
        changeLightColour(light, D_800A2E10_A3A10[0], D_800A2E10_A3A10[1], D_800A2E10_A3A10[2]);
    }
    if (*(s32 *)(state + 0xC0) != 0) {
        amSndStop(*(s32 *)(state + 0xC0));
    }
    amSndPlay(3, state + 0xC0);
    *(u16 *)(state + 0x53A) = 3;
    state[0x540] |= 2;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlFireDummyShot.s")
#endif

// shooting_func

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_80038488(void *obj, u8 *state, u8 *entry, f32 arg3) {
    u8 *chr;
    u8 *ammo;
    u8 *tgt;
    u8 *tr;
    f32 savedX;
    f32 savedZ;
    s32 savedUnk84;
    f32 savedY;
    f32 bx;
    f32 by;
    f32 bz;
    s32 t0;
    s32 v1;
    s32 flagFire;
    s32 result;
    s32 range;

    chr = mainGetGameCharacter(state[0], state[1]);
    if (DebugAmmoFlag != 0) {
        ammo = chr + chr[0x70] * 2;
        if (*(u16 *)(ammo + 0x14) == 0) {
            *(u16 *)(ammo + 0x14) = 100;
        }
    }
    if (func_80037428(state, chr) == 0) {
        return 1;
    }
    *(s16 *)(state + 0x1CA) = (s16) (*(s16 *)(state + 0x1CA) + mathRnd(-(s32) *(s16 *)(entry + 8), *(s16 *)(entry + 8)));
    *(s16 *)(state + 0x1CC) = (s16) (*(s16 *)(state + 0x1CC) + mathRnd(-(s32) *(s16 *)(entry + 0xA), *(s16 *)(entry + 0xA)));

    tgt = *(u8 **)((u8 *) obj + 0x6C);
    if (tgt != NULL && *(u8 **)(tgt + 0x68) != NULL) {
        tr = *(u8 **)(tgt + 0x68);
        if (chr[0x70] == 2 && (*(u16 *)(chr + 0x14 + chr[0x70] * 2) & 3) == 0) {
            savedX = *(f32 *)((u8 *) obj + 0xC);
            savedY = *(f32 *)((u8 *) obj + 0x10);
            savedZ = *(f32 *)((u8 *) obj + 0x14);
            savedUnk84 = *(s32 *)((u8 *) obj + 0x84);
            *(s32 *)((u8 *) obj + 0x84) = 1;
            *(f32 *)((u8 *) obj + 0xC) = *(f32 *)(tr + 0);
            *(f32 *)((u8 *) obj + 0x10) = *(f32 *)(tr + 4) + 3.0f;
            *(f32 *)((u8 *) obj + 0x14) = *(f32 *)(tr + 8);
            partUpdateTriggers(obj, 2);
            *(s32 *)((u8 *) obj + 0x84) = savedUnk84;
            *(f32 *)((u8 *) obj + 0xC) = savedX;
            *(f32 *)((u8 *) obj + 0x10) = savedY;
            *(f32 *)((u8 *) obj + 0x14) = savedZ;
        }
    }

    controlGetGunBarrelPos(obj, state, &bx, &by, &bz);
    flagFire = 0;
    result = 0;
    t0 = 0;
    v1 = 0;
    state[0x538] = entry[5];

    switch (chr[0x70]) {
    case 13:
        range = (state[0x568] == 5 || state[0x568] == 0xB || *(s32 *)(state + 0xFC) != 0)
                    ? *(s16 *)(state + 0x1CC) : 0x2000;
        if (func_80039AE0(obj, state, bx, by, bz, *(s16 *)(state + 0x1CA), range,
                          *(f32 *)(entry + 0x10), entry[3], entry[7]) != 0) {
            if (state[1] != 2 && state[1] != 6) {
                return 0;
            }
        } else {
            result = 1;
        }
        break;
    case 11:
        v1 = 1;
        t0 = (*(s16 *)(state + 0x53E) - 0x20) >> 4;
        if (t0 == 0) {
            v1 = 0;
        }
        flagFire = 1;
        break;
    case 12:
        v1 = 2;
        t0 = 0;
        flagFire = 1;
        break;
    case 10:
        range = (state[0x568] == 5 || state[0x568] == 0xB || *(s32 *)(state + 0xFC) != 0)
                    ? *(s16 *)(state + 0x1CC) : 0x1800;
        func_800395B8(obj, state, bx, by, bz, *(s16 *)(state + 0x1CA), (s16) range,
                      *(f32 *)(entry + 0x10), entry[3], entry[7]);
        break;
    case 9:
        func_80039810(obj, state, bx, by, bz, *(s16 *)(state + 0x1CA), *(s16 *)(state + 0x1CC),
                      *(f32 *)(entry + 0x10), entry[3], entry[7]);
        break;
    case 8:
        controlAlterMood(obj, 4);
        range = (state[0x568] == 5 || state[0x568] == 0xB || *(s32 *)(state + 0xFC) != 0)
                    ? *(s16 *)(state + 0x1CC) : 0x1800;
        func_800396F0(obj, state, bx, by, bz, *(s16 *)(state + 0x1CA), (s16) range,
                      *(f32 *)(entry + 0x10), entry[3], entry[7]);
        break;
    case 6:
        if (*(void **)(state + 0x564) == NULL) {
            MemoryPoolSlot *slot = mmAlloc(0x624, 0xFFFF);
            *(void **)(state + 0x564) = slot;
            flamethrowerFire(obj, slot);
        }
        flareThrow(*(MemoryPoolSlot **)(state + 0x564), bx, by, bz, *(s16 *)(state + 0x1CA),
                   *(s16 *)(state + 0x1CC), (s32) arg3);
        break;
    case 5:
        func_800390E0(obj, state, bx, by, bz, *(s16 *)(state + 0x1CA), *(s16 *)(state + 0x1CC),
                      *(f32 *)(entry + 0x10), entry[3], entry[7]);
        break;
    case 1:
        func_8003931C(obj, state, bx, by, bz, *(s16 *)(state + 0x1CA), *(s16 *)(state + 0x1CC),
                      *(f32 *)(entry + 0x10), entry[3], entry[7]);
        break;
    case 4:
        func_800394A4(obj, state, (s32) arg3);
        break;
    case 3:
        func_80038D54(obj, state, bx, by, bz, *(s16 *)(state + 0x1CA), *(s16 *)(state + 0x1CC),
                      *(f32 *)(entry + 0x10), *(s16 *)(state + 0x53E) >> 5, entry[7]);
        break;
    case 14:
        range = (state[0x568] == 5 || state[0x568] == 0xB || *(s32 *)(state + 0xFC) != 0)
                    ? *(s16 *)(state + 0x1CC) : 0x1800;
        func_80039CA4(obj, state, bx, by, bz, *(s16 *)(state + 0x1CA), (s16) range,
                      *(f32 *)(entry + 0x10), entry[7]);
        break;
    default:
        controlAlterMood(obj, 3);
        if ((s8) entry[6] < 0) {
            range = *(s16 *)(state + 0x53E) >> 5;
        } else if (chr[0x70] == 0 && *(u16 *)(chr + 0x14) == 0) {
            range = 0;
        } else {
            range = entry[3];
        }
        func_80038E70(obj, state, bx, by, bz, *(s16 *)(state + 0x1CA), *(s16 *)(state + 0x1CC),
                      *(f32 *)(entry + 0x10), range, entry[7], (s8) entry[1]);
        break;
    }

    if (flagFire != 0) {
        range = (state[0x568] == 5 || state[0x568] == 0xB || *(s32 *)(state + 0xFC) != 0) ? 0x1CC : 0x1000;
        func_80039970(obj, state, bx, by, bz, *(s16 *)(state + 0x1CA), (s16) range,
                      *(f32 *)(entry + 0x10), entry[3], entry[7], v1, t0);
    }
    ammo = chr + chr[0x70] * 2 + 0x14;
    if (*(u16 *)ammo != 0) {
        *(u16 *)ammo -= 1;
    }
    return result != 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_80038488.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void controlFreePlayersStuff(void) {
    s32 count;
    void **list;
    s32 i;

    list = objGetPlayerlist(&count);
    for (i = 0; i < count; i++) {
        u8 *state = (u8 *) ((Object *) list[i])->racer;
        void *slot = *(void **)(state + 0x564);

        if (slot != NULL) {
            mmFree(slot);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlFreePlayersStuff.s")
#endif

// shoot_plasmashot

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80038D54(void *obj, u8 *state, f32 x, f32 y, f32 z, s16 a5, s16 a6, f32 a7, s32 a8, s32 a9) {
    u8 params[0x18];
    void *spawned;

    *(s16 *)(params + 0x00) = 0x13E;
    *(s16 *)(params + 0x04) = (s16) x;
    *(s16 *)(params + 0x06) = (s16) y;
    *(s16 *)(params + 0x08) = (s16) z;
    *(s8 *)(params + 0x0A) = (s8) a8;
    *(s8 *)(params + 0x0B) = (s8) a9;
    *(s16 *)(params + 0x0C) = a5;
    *(s16 *)(params + 0x0E) = a6;
    *(f32 *)(params + 0x10) = a7;
    *(s32 *)(params + 0x14) = (s32) obj;
    spawned = objSetupObject(params, 1, NULL);
    if (spawned != NULL) {
        *(s32 *)((u8 *) spawned + 0x3C) = 0;
    }
    mainIncreaseWeaponShots(3);
    if (*(s32 *)(state + 0xC0) != 0) {
        amSndStop(*(s32 *)(state + 0xC0));
    }
    amSndPlay(0xE1, state + 0xC0);
    *(u16 *)(state + 0x53A) = 0xE1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_80038D54.s")
#endif

// shoot_default

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80038E70(void *obj, u8 *state, f32 x, f32 y, f32 z, s16 a5, s16 a6, f32 a7, s32 a8, s32 a9, s32 a10) {
    u8 params[0x1C];
    u8 *chr;
    void *spawned;
    s32 handle;

    chr = mainGetGameCharacter(state[0], state[1]);
    *(s16 *)(params + 0x00) = 0x50;
    params[0x02] = 0x24;
    params[0x03] = 0;
    *(s16 *)(params + 0x04) = (s16) x;
    *(s16 *)(params + 0x06) = (s16) y;
    *(s16 *)(params + 0x08) = (s16) z;
    *(s8 *)(params + 0x0A) = (s8) a8;
    *(s8 *)(params + 0x0B) = (s8) a9;
    *(s16 *)(params + 0x0C) = a5;
    *(s16 *)(params + 0x0E) = a6;
    *(s8 *)(params + 0x10) = (s8) a10;
    params[0x11] = 0;
    params[0x12] = chr[0x70];
    *(s8 *)(params + 0x13) = -1;
    *(f32 *)(params + 0x14) = a7;
    *(s32 *)(params + 0x18) = (s32) obj;
    mainIncreaseWeaponShots(chr[0x70]);

    if (chr[0x70] == 2) {
        handle = *(s32 *)(state + 0xC0);
        if (handle == 0 || *(u16 *)(state + 0x53A) != 8) {
            if (handle != 0) {
                amSndStop(handle);
            }
            amSndPlay(8, state + 0xC0);
            *(u16 *)(state + 0x53A) = 8;
        }
    } else {
        handle = *(s32 *)(state + 0xC0);
        if (handle != 0) {
            amSndStop(handle);
        }
        if (chr[0x70] == 7 && state[0x568] == 0xB) {
            *(u16 *)(state + 0x53A) = 3;
            amSndPlay(3, state + 0xC0);
        } else if (a8 != 0) {
            *(u16 *)(state + 0x53A) = 3;
            amSndPlay(3, state + 0xC0);
            state[0x540] |= 2;
        } else {
            *(u16 *)(state + 0x53A) = 0xE;
            amSndPlay(0xE, state + 0xC0);
        }
    }
    spawned = objSetupObject(params, 1, NULL);
    if (spawned != NULL) {
        *(s32 *)((u8 *) spawned + 0x3C) = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_80038E70.s")
#endif

// shoot_TriRocket

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_800390E0(void *obj, u8 *state, f32 x, f32 y, f32 z, s16 a5, s16 a6, f32 a7, s32 a8, s32 a9) {
    u8 params[0x28];
    void *spawned;
    s32 handle;

    mainIncreaseWeaponShots(5);
    *(s16 *)(params + 0x00) = 0xA4;
    params[0x02] = 0x28;
    params[0x03] = 0;
    *(s16 *)(params + 0x04) = (s16) x;
    *(s16 *)(params + 0x06) = (s16) y;
    *(s16 *)(params + 0x08) = (s16) z;
    *(s8 *)(params + 0x0A) = (s8) a8;
    params[0x0B] = (u8) a9;
    *(f32 *)(params + 0x0C) = a7;
    *(s32 *)(params + 0x10) = (s32) obj;
    *(s16 *)(params + 0x1E) = a5;
    *(s16 *)(params + 0x20) = a6;
    params[0x24] = 0;
    params[0x26] = 5;

    handle = *(s32 *)(state + 0xC0);
    if (handle != 0) {
        amSndStop(handle);
    }
    *(s16 *)(params + 0x18) = 0;
    *(s16 *)(params + 0x1A) = (s16) mathRnd(0x40, 0x300);
    if (mathRnd(0, 1) == 1) {
        *(s16 *)(params + 0x1A) = (s16) -*(s16 *)(params + 0x1A);
    }
    *(s16 *)(params + 0x1C) = (s16) mathRnd(0, 0xA);
    *(s16 *)(params + 0x22) = (s16) mathRnd(1, 5);
    spawned = objSetupObject(params, 1, NULL);
    if (spawned != NULL) {
        *(s32 *)((u8 *) spawned + 0x3C) = 0;
    }

    *(s16 *)(params + 0x18) = -0x8000;
    params[0x0B] -= 1;
    *(s16 *)(params + 0x1A) = (s16) mathRnd(0x40, 0x300);
    *(s16 *)(params + 0x1C) = (s16) mathRnd(0, 0xA);
    *(s16 *)(params + 0x22) = (s16) mathRnd(1, 5);
    spawned = objSetupObject(params, 1, NULL);
    if (spawned != NULL) {
        *(s32 *)((u8 *) spawned + 0x3C) = 0;
    }

    *(s16 *)(params + 0x18) = -0x8000;
    params[0x0B] -= 1;
    *(s16 *)(params + 0x1A) = 0;
    *(s16 *)(params + 0x1C) = 0;
    *(s16 *)(params + 0x22) = 0;
    spawned = objSetupObject(params, 1, NULL);
    if (spawned != NULL) {
        *(s32 *)((u8 *) spawned + 0x3C) = 0;
    }

    handle = *(s32 *)(state + 0xC0);
    if (handle != 0) {
        amSndStop(handle);
    }
    amSndPlay(0x95, state + 0xC0);
    *(u16 *)(state + 0x53A) = 0x95;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_800390E0.s")
#endif

// shoot_HomingMissle

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8003931C(void *obj, u8 *state, f32 x, f32 y, f32 z, s16 a5, s16 a6, f32 a7, s32 a8, s32 a9) {
    u8 params[0x28];
    u8 aimOut;
    s32 target;
    void *spawned;
    s32 handle;

    mainIncreaseWeaponShots(1);
    *(s16 *)(params + 0x00) = 0xA4;
    params[0x02] = 0x28;
    params[0x03] = 0;
    aimOut = 0;
    target = GetAutoAimTarget((s32) obj, &aimOut);
    *(s16 *)(params + 0x04) = (s16) x;
    *(s16 *)(params + 0x06) = (s16) y;
    *(s16 *)(params + 0x08) = (s16) z;
    *(s8 *)(params + 0x0A) = (s8) a8;
    params[0x0B] = (u8) a9;
    if (target == 0) {
        params[0x0B] = (u8) (((u32) (a9 & 0xFF)) >> 2);
    }
    *(f32 *)(params + 0x0C) = a7;
    *(s32 *)(params + 0x10) = (s32) obj;
    *(s32 *)(params + 0x14) = target;
    *(s16 *)(params + 0x1E) = a5;
    *(s16 *)(params + 0x20) = a6;
    params[0x24] = 1;
    params[0x25] = aimOut;
    params[0x26] = 1;

    handle = *(s32 *)(state + 0xC0);
    if (handle != 0) {
        amSndStop(handle);
    }
    spawned = objSetupObject(params, 1, NULL);
    if (spawned != NULL) {
        *(s32 *)((u8 *) spawned + 0x3C) = 0;
    }
    handle = *(s32 *)(state + 0xC0);
    if (handle != 0) {
        amSndStop(handle);
    }
    amSndPlay(0x95, state + 0xC0);
    *(u16 *)(state + 0x53A) = 0x95;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_8003931C.s")
#endif

// shoot_Shocker

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_800394A4(void *obj, u8 *state, s32 arg2) {
    u8 params[0x2C];
    u8 *owner;
    s32 handle;

    owner = *(u8 **)(state + 0x560);
    if (owner == NULL) {
        *(s16 *)(params + 0x00) = 0xB6;
        params[0x02] = 0x2C;
        *(s16 *)(params + 0x04) = 0;
        *(s16 *)(params + 0x06) = 0;
        *(s16 *)(params + 0x08) = 0;
        *(s32 *)(params + 0x10) = (s32) obj;
        *(s32 *)(params + 0x14) = 0;
        *(s16 *)(params + 0x16) = 0x4000;
        *(s16 *)(params + 0x18) = 0;
        *(s16 *)(params + 0x1A) = 0x800;
        *(s16 *)(params + 0x1C) = -0x1200;
        *(s16 *)(params + 0x1E) = 0x800;
        *(s16 *)(params + 0x20) = 0x2000;
        *(s16 *)(params + 0x22) = 0x2000;
        *(s16 *)(params + 0x24) = -0x2000;
        *(s16 *)(params + 0x26) = 0x190;
        params[0x28] = D_800A1553_A2153;
        params[0x29] = 0;
        params[0x2A] = 0;
        owner = objSetupObject(params, 1, state);
        *(u8 **)(state + 0x560) = owner;
        *(s32 *)(owner + 0x3C) = 0;
        owner = *(u8 **)(state + 0x560);
    }
    *(u8 *)(*(u8 **)(owner + 0x68) + 0xA7D) = 1;
    if (*(u16 *)(state + 0x53A) != 0x97) {
        handle = *(s32 *)(state + 0xC0);
        if (handle != 0) {
            amSndStop(handle);
        }
        *(u16 *)(state + 0x53A) = 0x97;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_800394A4.s")
#endif

// shoot_FishFood

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_800395B8(void *obj, u8 *state, f32 x, f32 y, f32 z, s16 a5, s16 a6, f32 a7, s32 a8, s32 a9) {
    u8 params[0x14];
    s32 i;
    void *spawned;

    *(s16 *)(params + 0x00) = 0xF0;
    params[0x02] = 0x14;
    params[0x03] = 0;
    *(s16 *)(params + 0x04) = (s16) x;
    *(s16 *)(params + 0x06) = (s16) y;
    *(s16 *)(params + 0x08) = (s16) z;
    *(f32 *)(params + 0x10) = a7;
    for (i = 0; i != 2; i++) {
        *(s16 *)(params + 0x0A) = (s16) (mathRnd(-0x800, 0x800) + a5);
        *(s16 *)(params + 0x0C) = (s16) (mathRnd(-0x800, 0x800) + a6);
        *(s16 *)(params + 0x0E) = (s16) mathRnd(2, 4);
        spawned = objSetupObject(params, 1, NULL);
        if (spawned != NULL) {
            *(s32 *)((u8 *) spawned + 0x3C) = 0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_800395B8.s")
#endif

// shoot_Grenades

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_800396F0(void *obj, u8 *state, f32 x, f32 y, f32 z, s16 a5, s16 a6, f32 a7, s32 a8, s32 a9) {
    u8 params[0x18];
    void *spawned;

    mainIncreaseWeaponShots(8);
    *(s16 *)(params + 0x00) = 0x72;
    params[0x02] = 0x1C;
    params[0x03] = 0;
    *(s16 *)(params + 0x04) = (s16) x;
    *(s16 *)(params + 0x06) = (s16) y;
    *(s16 *)(params + 0x08) = (s16) z;
    *(s8 *)(params + 0x0A) = (s8) a8;
    *(s8 *)(params + 0x0B) = (s8) a9;
    *(s16 *)(params + 0x0C) = a5;
    *(s16 *)(params + 0x0E) = a6;
    *(f32 *)(params + 0x10) = a7;
    *(s32 *)(params + 0x14) = (s32) obj;
    spawned = objSetupObject(params, 1, NULL);
    amSndPlay(0x2F, NULL);
    charSpeak((Object *) obj, 2);
    if (spawned != NULL) {
        *(s32 *)((u8 *) spawned + 0x3C) = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_800396F0.s")
#endif

// shoot_shuriken
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80039810(void *obj, u8 *state, f32 x, f32 y, f32 z, s16 a5, s16 a6, f32 a7, s32 a8, s32 a9) {
    u8 params[0x20];
    u8 *spawned;
    f32 sn;

    *(s16 *)(params + 0x00) = 0x39;
    params[0x02] = 0xA;
    params[0x03] = 0;
    *(s16 *)(params + 0x04) = (s16) x;
    *(s16 *)(params + 0x06) = (s16) y;
    *(s16 *)(params + 0x08) = (s16) z;
    spawned = objSetupObject(params, 1, NULL);
    if (spawned != NULL) {
        sn = Sinf(a5);
        *(f32 *)(spawned + 0x1C) = Cosf(a6) * -sn * a7;
        *(f32 *)(spawned + 0x20) = Sinf(a6) * a7;
        sn = Cosf(a5);
        *(f32 *)(spawned + 0x24) = Cosf(a6) * -sn * a7;
        amSndPlay(0x2F, NULL);
        charSpeak((Object *) obj, 2);
        *(s32 *)(spawned + 0x3C) = 0;
        mainIncreaseWeaponShots(9);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_80039810.s")
#endif

// shoot_Mines
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80039970(void *obj, u8 *state, f32 x, f32 y, f32 z, s16 a5, s16 a6, f32 a7, s32 a8, s32 a9, s32 a10, s32 a11) {
    u8 params[0x20];
    u8 *spawned;
    s16 typeId;
    s32 shots;

    if ((u8) a10 == 0) {
        typeId = 0x127;
        shots = 0xB;
    } else if ((u8) a10 == 1) {
        typeId = 0x147;
        shots = 0xB;
    } else {
        typeId = 0x148;
        shots = 0xC;
    }
    *(s16 *)(params + 0x00) = typeId;
    params[0x02] = 0x1C;
    params[0x03] = 1;
    *(s16 *)(params + 0x04) = (s16) x;
    *(s16 *)(params + 0x06) = (s16) y;
    *(s16 *)(params + 0x08) = (s16) z;
    params[0x0A] = (u8) a10;
    params[0x0B] = (u8) a11;
    *(s16 *)(params + 0x0C) = a5;
    *(s16 *)(params + 0x0E) = a6;
    *(f32 *)(params + 0x10) = a7;
    *(void **)(params + 0x14) = obj;
    params[0x18] = (s8) a8;
    params[0x19] = (s8) a9;
    spawned = objSetupObject(params, 1, NULL);
    if (spawned != NULL) {
        *(s32 *)(spawned + 0x3C) = 0;
        if ((u8) a10 == 2) {
            *(u8 **)(state + 0x1A0) = spawned;
        }
        mainIncreaseWeaponShots(shots);
    }
    amSndPlay(0x2F, NULL);
    charSpeak((Object *) obj, 2);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_80039970.s")
#endif

// shoot_Flares
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_80039AE0(void *obj, u8 *state, f32 x, f32 y, f32 z, s16 a5, s16 a6, f32 a7, s32 a8, s32 a9) {
    u8 params[0x20];
    u8 *tilt;
    u8 *owner;
    u8 *spawned;
    s32 fired;
    s32 handle;

    fired = 0;
    tilt = *(u8 **)(state + 0x5CC);
    if (tilt != NULL) {
        if (*(s16 *)(tilt + 0x48) == 0x59) {
            SquaddieGetTiltList(tilt, a5, a6, a7);
            *(u8 **)(state + 0x5CC) = NULL;
            fired = 1;
        } else {
            /* a1 (state) is not reassigned before this call in the asm, so m2c passes it as the weapon byte */
            controlEmptyPlayersHand(obj, (u8) (s32) state);
        }
    }
    if (fired == 0) {
        owner = obj;
        if (*(s8 *)(state + 1) == 2 || *(s8 *)(state + 1) == 6) {
            owner = NULL;
            fired = 1;
        }
        *(s16 *)(params + 0x00) = 0xF7;
        *(s16 *)(params + 0x04) = (s16) x;
        *(s16 *)(params + 0x06) = (s16) y;
        *(s16 *)(params + 0x08) = (s16) z;
        *(s16 *)(params + 0x0A) = a5;
        *(s16 *)(params + 0x0C) = a6;
        params[0x0E] = (s8) a8;
        params[0x0F] = (s8) a9;
        *(f32 *)(params + 0x10) = a7;
        *(void **)(params + 0x14) = owner;
        spawned = objSetupObject(params, 1, NULL);
        if (spawned != NULL) {
            *(s32 *)(spawned + 0x3C) = 0;
            if (owner != NULL) {
                *(u8 **)(state + 0x5CC) = spawned;
            }
        }
    }
    if (fired != 0) {
        handle = *(s32 *)(state + 0xC0);
        if (handle != 0) {
            amSndStop(handle);
        }
        amSndPlay(0xF1, state + 0xC0);
        *(s16 *)(state + 0x53A) = 0xF1;
        charSpeak((Object *) obj, 2);
        return 1;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_80039AE0.s")
#endif

// shoot_clusterBombs
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80039CA4(void *obj, u8 *state, f32 x, f32 y, f32 z, s16 a5, s16 a6, f32 a7, s32 a8) {
    u8 params[0x20];
    u8 *spawned;

    *(s16 *)(params + 0x00) = 0x13A;
    *(s16 *)(params + 0x04) = (s16) x;
    *(s16 *)(params + 0x06) = (s16) y;
    *(s16 *)(params + 0x08) = (s16) z;
    *(s16 *)(params + 0x0A) = (s16) (a8 * 6);
    *(s16 *)(params + 0x0C) = a5;
    *(s16 *)(params + 0x0E) = a6;
    *(f32 *)(params + 0x10) = a7;
    *(void **)(params + 0x14) = obj;
    spawned = objSetupObject(params, 1, NULL);
    if (spawned != NULL) {
        amSndPlay(0x2F, NULL);
        charSpeak((Object *) obj, 2);
        *(s32 *)(spawned + 0x3C) = 0;
        mainIncreaseWeaponShots(0xE);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_80039CA4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
/* Aim assist. Picks the aim target (or aim point on it) closest to the gun
 * barrel and stores the resulting yaw/pitch in the player state.
 * Layout notes:
 *   obj    : Object; obj->segment.trans = yaw(+0) / pitch(+2)
 *   state  : player control state (raw offsets, same convention as controlPlayerInit)
 *   target : Object*, state+0x1A4
 *   target->unk4C (+0x4C) is ObjectTransform-shaped: s16 +0x06, x/y/z at +0C/+10/+14,
 *     s16 entry count at +0x32, entries pointer at +0x40. Entries are 0x34 bytes:
 *     u8 weight at +0x2E, u32 flags at +0x30 (bit 0x40000000 = skip), x/y/z at +0C/+10/+14.
 *   args (from the 8-arg overlay call in overlay_53.c): range=1000, othersYaw=10,
 *     othersPitch=60, targetYaw=15, targetPitch=65. A 8th arg exists in the caller but
 *     the asm never reads it, so it is not declared here.
 */
void controlUpdatePlayerAim(Object *obj, u8 *state, f32 range, f32 othersYawDeg, f32 othersPitchDeg,
                            f32 targetYawDeg, f32 targetPitchDeg) {
    u8 *chr;
    Object *target;
    Object *cand;
    Object *best;
    ObjectTransform *tgt;
    ObjectTransform *ct;
    u8 *entries;
    u8 *ent;
    Object **list;
    s32 listStart;
    s32 listEnd;
    s32 i;
    s32 sum;
    s32 idx;
    s32 count;
    s32 special;
    s32 aimHold;
    f32 gunX;
    f32 gunY;
    f32 gunZ;
    f32 maxDistSq;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 distSq;
    f32 dist;
    f32 score;
    f32 bestScore;
    f32 firstScore = 0.0f;
    f32 ex;
    f32 ey;
    f32 ez;
    u16 flags;
    s16 limYaw;
    s16 limPitch;
    s16 othersYawLim;
    s16 othersPitchLim;
    s16 yaw;
    s16 pitch;
    s16 bestX;
    s16 bestY;
    s8 hold;

    chr = (u8 *) mainGetGameCharacter((s8) state[0x00], (s8) state[0x01]);

    /* hold timers: state+0x1F4 countdown, state+0x1F8 */
    hold = *(s8 *) (state + 0x1F4);
    if (hold != 0) {
        *(s8 *) (state + 0x1F8) = (s8) (*(s8 *) (state + 0x1F8) - 1);
        *(s8 *) (state + 0x1F4) = (s8) (hold - 1);
        if (*(s8 *) (state + 0x1F8) < 0) {
            *(s8 *) (state + 0x1F8) = 0;
        }
    } else if ((*(s8 *) (state + 0x01) & 3) != 2) {
        *(s8 *) (state + 0x1F8) = 4;
    }

    /* aim timer: low nibble of the halfword at state+0x540 (byte at +0x541) */
    aimHold = *(u16 *) (state + 0x540) & 0xF;
    if (aimHold != 0) {
        state[0x541] = (u8) (((aimHold - 1) & 0xF) | (state[0x541] & 0xF0));
        aimHold = *(u16 *) (state + 0x540) & 0xF;
    }

    controlGetGunBarrelPos(obj, state, &gunX, &gunY, &gunZ);

    /* special: player holds weapon 0x12 and chr+0x70 is clear */
    special = 0;
    if (chr[0x70] == 0 && mainPlayerHas((s8) state[0x00], (s8) state[0x01], 0x12) != 0) {
        special = 1;
    }

    maxDistSq = range * range;

    /* ---- previous target: re-validate it ---- */
    target = *(Object **) (state + 0x1A4);
    if (target != NULL) {
        tgt = (ObjectTransform *) *(u8 **) ((u8 *) target + 0x4C);
        *(Object **) (state + 0x1A4) = NULL;
        limYaw = (s16) (s32) (targetYawDeg * 182.0444f);
        limPitch = (s16) (s32) (targetPitchDeg * 182.0444f);
        if (target->behaviorId == 0x9B && special != 0) {
            limYaw = 0x2AAA;
            limPitch = 0x3800;
        }
        if (tgt->unk6 > 0 && (target->behaviorId != 0x18 || target->racer->pad00[0x1A] != 0xC)) {
            dx = gunX - tgt->x_position;
            dz = gunZ - tgt->z_position;
            distSq = (dx * dx) + (dz * dz);
            if (distSq < 129600.0f) {
                state[0x541] = (u8) ((state[0x541] & 0xF0) | 0xA);
            }
            if (distSq > 0.0f && distSq < maxDistSq) {
                yaw = (s16) (Arctanf(dx, dz) - obj->segment.trans.y_rotation);
                if (-limYaw < yaw && yaw < limYaw) {
                    dist = sqrtf(distSq);
                    pitch = (s16) (Arctanf(tgt->y_position - gunY, dist) - obj->segment.trans.x_rotation);
                    if (-limPitch < pitch && pitch < limPitch) {
                        count = *(s16 *) ((u8 *) tgt + 0x32);
                        *(Object **) (state + 0x1A4) = target;
                        *(s16 *) (state + 0x1C8) = (s16) (pitch + obj->segment.trans.x_rotation);
                        *(s16 *) (state + 0x1C6) = (s16) (yaw + obj->segment.trans.y_rotation);
                        firstScore = -dist;
                        if (target->behaviorId == 0x9B) {
                            firstScore = -dist + 32768.0f;
                        }
                        if (count == 0) {
                            *(s16 *) (state + 0x1CC) = *(s16 *) (state + 0x1C8);
                            *(s16 *) (state + 0x1CA) = *(s16 *) (state + 0x1C6);
                        } else {
                            entries = *(u8 **) ((u8 *) tgt + 0x40);
                            sum = 0;
                            for (i = 0; i < count; i++) {
                                ent = entries + (i * 0x34);
                                if (!(*(u32 *) (ent + 0x30) & 0x40000000)) {
                                    sum += ent[0x2E];
                                }
                            }
                            if (sum >= 2) {
                                sum = mathRnd(1, sum);
                            }
                            idx = 0;
                            if (sum > 0) {
                                ent = entries;
                                if (count > 0) {
                                    do {
                                        if (!(*(u32 *) (ent + 0x30) & 0x40000000)) {
                                            sum -= ent[0x2E];
                                        }
                                        idx++;
                                        ent += 0x34;
                                    } while (sum > 0 && idx < count);
                                }
                            }
                            ent = entries + (idx * 0x34);
                            if (idx != 0) {
                                idx--;
                                ent -= 0x34;
                            }
                            ex = gunX - *(f32 *) (ent + 0xC);
                            ez = gunZ - *(f32 *) (ent + 0x14);
                            ey = *(f32 *) (ent + 0x10) - gunY;
                            *(s16 *) (state + 0x1CC) = (s16) Arctanf(ey, sqrtf((ex * ex) + (ez * ez)));
                            *(s16 *) (state + 0x1CA) = (s16) Arctanf(ex, ez);
                        }
                    }
                }
            }
        }
    }

    /* ---- scan all objects in the list for a better target ---- */
    othersYawLim = (s16) (s32) (othersYawDeg * 182.0444f);
    othersPitchLim = (s16) (s32) (othersPitchDeg * 182.0444f);
    limYaw = othersYawLim;
    limPitch = othersPitchLim;
    list = objGetObjList(&listStart, &listEnd);
    best = NULL;
    bestX = obj->segment.trans.x_rotation;
    bestY = obj->segment.trans.y_rotation;
    bestScore = -32768.0f;

    for (i = listStart; i < listEnd; i++) {
        cand = list[i];
        ct = (ObjectTransform *) *(u8 **) ((u8 *) cand + 0x4C);
        if (cand->behaviorId == 0x9B) {
            if (obj == *(Object **) cand->racer) {
                cand = obj;
            } else if (special != 0) {
                /* asm: sidekick-style 9B objects get wider limits */
                limYaw = 0x2000;
                limPitch = 0x3000;
            }
        }
        if (cand != obj && ct != NULL && ct->unk6 > 0) {
            flags = *(u16 *) (*(u8 **) ((u8 *) cand + 0x40) + 0x14);
            if ((flags & 0x40) && !(flags & 0x1000)
                && (cand->behaviorId != 0x18 || cand->racer->pad00[0x1A] != 0xC)) {
                dx = gunX - ct->x_position;
                dz = gunZ - ct->z_position;
                distSq = (dx * dx) + (dz * dz);
                if (distSq > 0.0f && distSq < maxDistSq) {
                    state[0x541] = (u8) ((state[0x541] & 0xF0) | 0xA);
                    yaw = (s16) (Arctanf(dx, dz) - obj->segment.trans.y_rotation);
                    if (-limYaw < yaw && yaw < limYaw) {
                        dy = ct->y_position - gunY;
                        dist = sqrtf(distSq);
                        pitch = (s16) (Arctanf(dy, dist) - obj->segment.trans.x_rotation);
                        if (-limPitch < pitch && pitch < limPitch) {
                            score = -dist;
                            if (cand->behaviorId == 0x9B) {
                                score = -dist + 32768.0f;
                            }
                            if (bestScore < score) {
                                best = cand;
                                bestX = (s16) (pitch + obj->segment.trans.x_rotation);
                                bestY = (s16) (yaw + obj->segment.trans.y_rotation);
                                bestScore = score;
                            }
                        }
                    }
                }
            }
        }
        if (cand->behaviorId == 0x9B && special != 0) {
            limYaw = othersYawLim;
            limPitch = othersPitchLim;
        }
    }

    /* ---- adopt the scan result if no target yet, or it beats the old one ---- */
    if (best != NULL && (*(Object **) (state + 0x1A4) == NULL || firstScore < bestScore)) {
        tgt = (ObjectTransform *) *(u8 **) ((u8 *) best + 0x4C);
        *(Object **) (state + 0x1A4) = best;
        *(s16 *) (state + 0x1C8) = bestX;
        *(s16 *) (state + 0x1C6) = bestY;
        count = *(s16 *) ((u8 *) tgt + 0x32);
        if (count == 0) {
            *(s16 *) (state + 0x1CC) = *(s16 *) (state + 0x1C8);
            *(s16 *) (state + 0x1CA) = *(s16 *) (state + 0x1C6);
        } else {
            entries = *(u8 **) ((u8 *) tgt + 0x40);
            sum = 0;
            for (i = 0; i < count; i++) {
                ent = entries + (i * 0x34);
                if (!(*(u32 *) (ent + 0x30) & 0x40000000)) {
                    sum += ent[0x2E];
                }
            }
            if (sum >= 2) {
                sum = mathRnd(1, sum);
            }
            idx = 0;
            if (sum > 0) {
                ent = entries;
                if (count > 0) {
                    do {
                        if (!(*(u32 *) (ent + 0x30) & 0x40000000)) {
                            sum -= ent[0x2E];
                        }
                        idx++;
                        ent += 0x34;
                    } while (sum > 0 && idx < count);
                }
            }
            ent = entries + (idx * 0x34);
            if (idx != 0) {
                idx--;
                ent -= 0x34;
            }
            ex = gunX - *(f32 *) (ent + 0xC);
            ez = gunZ - *(f32 *) (ent + 0x14);
            ey = *(f32 *) (ent + 0x10) - gunY;
            *(s16 *) (state + 0x1CC) = (s16) Arctanf(ey, sqrtf((ex * ex) + (ez * ez)));
            *(s16 *) (state + 0x1CA) = (s16) Arctanf(ex, ez);
        }
    }

    /* ---- publish the aim result ---- */
    if (*(Object **) (state + 0x1A4) != NULL) {
        *(s8 *) (state + 0x1F4) = 0xF;
        if (state[0x568] != 5 && state[0x568] != 0xB) {
            *(s8 *) (state + 0x1F5) = 0x1E;
            *(s16 *) (state + 0x1DA) = (s16) (*(s16 *) (state + 0x1C8) - obj->segment.trans.x_rotation);
            *(s16 *) (state + 0x1D8) = (s16) (*(s16 *) (state + 0x1C6) - obj->segment.trans.y_rotation);
        }
    } else {
        *(s16 *) (state + 0x1C8) = obj->segment.trans.x_rotation;
        *(s16 *) (state + 0x1C6) = obj->segment.trans.y_rotation;
        *(s16 *) (state + 0x1CC) = obj->segment.trans.x_rotation;
        *(s16 *) (state + 0x1CA) = obj->segment.trans.y_rotation;
    }

    /* asm: func_80033EE8 is declared with one arg in this file; the asm passes (obj, state) */
    if (*(s32 *) (state + 0x50C) != 0
        && ((s32 (*)(Object *, u8 *)) func_80033EE8)(obj, state) != 0
        && (*(u16 *) (state + 0x540) & 0xF) != 0
        && aimHold == 0
        && *(s32 *) (state + 0x5D0) == 0) {
        amSndPlay((u16) ((mathRnd(0, 1) + 0x1E4) & 0xFFFF), state + 0x5D0);
    }
    controlClearAimlocks(state);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlUpdatePlayerAim.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 controlGetManualAim(s32 arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s16 *arg6, s16 *arg7, f32 arg8) {
    u8 *state = (u8 *) arg1;
    u8 *chr;
    s32 manual;
    s32 yawIn;
    s32 pitchIn;
    s32 steps;
    s32 idx;
    s16 scaledX;
    s16 scaledY;
    f32 accel;
    f32 smoothed;
    f32 scale;
    f32 invScale;
    f32 divisor;
    f32 yawVel;
    f32 pitchVel;
    f32 gain;
    f32 yawAccel;
    f32 pitchAccel;

    chr = mainGetGameCharacter(state[0], state[1]);
    manual = 0;
    yawVel = 0.0f;
    pitchVel = 0.0f;
    if (chr != NULL && chr[0x70] == 7 && state[0x18E] == 0) {
        manual = 1;
    }
    yawIn = -controlAbsXjoy;
    pitchIn = -controlAbsYjoy;
    steps = (s32) arg8;
    if (manual != 0) {
        if (*(s32 *)((u8 *) controlModeKeys + 0x1C) & controlKeys) {
            accel = 0.05f;
        } else if (*(s32 *)((u8 *) controlModeKeys + 0x20) & controlKeys) {
            accel = -0.05f;
        } else {
            accel = 0.0f;
        }
        smoothed = ((1.0f - Powerf(0.875f, steps)) * (accel - *(f32 *)(state + 0x1F0))) + *(f32 *)(state + 0x1F0);
        scale = *(f32 *)(state + 0x1EC) + (smoothed * arg8);
        if (scale < 1.0f) {
            scale = 1.0f;
            if (smoothed < 0.0f) {
                smoothed = 0.0f;
            }
        }
        if (scale > 5.0f) {
            scale = 5.0f;
            if (smoothed > 0.0f) {
                smoothed = 0.0f;
            }
        }
        *(f32 *)(state + 0x1EC) = scale;
        *(f32 *)(state + 0x1F0) = smoothed;
    } else {
        *(f32 *)(state + 0x1F0) = 0.0f;
        scale = 1.0f;
    }

    invScale = 1.0f / scale;
    divisor = 1.0f / (((scale - 1.0f) * (scale * 0.5f)) + 1.0f);
    scaledX = (s16) (s32) ((f32) arg2 * divisor);
    scaledY = (s16) (s32) ((f32) arg3 * divisor);

    if (yawIn < -0x28) {
        if (yawIn < -0x2D && *(s16 *)(state + 0x1CE) < (0x2D8 - scaledX)) {
            idx = -0x2D - yawIn;
            if (idx >= 0x14) {
                idx = 0x13;
            }
            yawVel = -D_800A2E60_A3A60[idx] * invScale;
        }
        yawIn = -0x28;
    }
    if (yawIn >= 0x29) {
        if (yawIn >= 0x2E) {
            idx = yawIn - 0x2D;
            if (((s16) scaledX - 0x2D8) < *(s16 *)(state + 0x1CE)) {
                if (idx >= 0x14) {
                    idx = 0x13;
                }
                yawVel = D_800A2E60_A3A60[idx] * invScale;
            }
        }
        yawIn = 0x28;
    }
    if (pitchIn < -0x28) {
        if (pitchIn < -0x2D && *(s16 *)(state + 0x1E0) < (0x2D8 - scaledY)) {
            idx = -0x2D - pitchIn;
            if (idx >= 0x14) {
                idx = 0x13;
            }
            pitchVel = -D_800A2E60_A3A60[idx] * invScale;
        }
        pitchIn = -0x28;
    }
    if (pitchIn >= 0x29) {
        if (pitchIn >= 0x2E) {
            idx = pitchIn - 0x2D;
            if (((s16) scaledY - 0x2D8) < *(s16 *)(state + 0x1E0)) {
                if (idx >= 0x14) {
                    idx = 0x13;
                }
                pitchVel = D_800A2E60_A3A60[idx] * invScale;
            }
        }
        pitchIn = 0x28;
    }

    steps = (s32) arg8;
    gain = 1.0f - Powerf(0.8334f, steps);
    yawAccel = *(f32 *)(state + 0x1E4);
    pitchAccel = *(f32 *)(state + 0x1E8);
    *(f32 *)(state + 0x1E4) = yawAccel + ((yawVel - yawAccel) * gain);
    *(f32 *)(state + 0x1E8) = pitchAccel + ((pitchVel - pitchAccel) * gain);
    if (yawVel == 0.0f) {
        if (*(f32 *)(state + 0x1E4) > -1.0f && *(f32 *)(state + 0x1E4) < 1.0f) {
            *(f32 *)(state + 0x1E4) = 0.0f;
        }
    }
    if (pitchVel == 0.0f) {
        if (*(f32 *)(state + 0x1E8) > -1.0f && *(f32 *)(state + 0x1E8) < 1.0f) {
            *(f32 *)(state + 0x1E8) = 0.0f;
        }
    }

    *arg6 = (s16) ((scaledX * yawIn) / 40);
    *arg7 = (s16) ((scaledY * pitchIn) / 40);
    *(s16 *)(state + 0x11C) = (s16) (*(s16 *)(state + 0x11C) + (s32) (*(f32 *)(state + 0x1E4) * arg8));
    *(s16 *)(state + 0x1E2) = (s16) (*(s16 *)(state + 0x1E2) + (s32) (*(f32 *)(state + 0x1E8) * arg8));
    if (*(s16 *)(state + 0x1E2) < arg4) {
        *(s16 *)(state + 0x1E2) = (s16) arg4;
    }
    if (arg5 < *(s16 *)(state + 0x1E2)) {
        *(s16 *)(state + 0x1E2) = (s16) arg5;
    }
    return manual;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlGetManualAim.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 controlPlayerGunWeight(void *arg0) {
    u8 *state = (u8 *) arg0;
    u8 *chr = mainGetGameCharacter(state[0], *(s8 *)(state + 1));

    return ((s32) weaponTable[chr[0x70] * 0x30] >> *(s8 *)(state + 1)) & 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlPlayerGunWeight.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void controlPlayerStopAim(void *arg0) {
    s32 count;
    void **players;
    u8 *state;
    s32 i;

    players = objGetPlayerlist(&count);
    for (i = 0; i < count; i++) {
        state = *(u8 **) ((u8 *) players[i] + 0x68);
        if (arg0 == *(void **)(state + 0x1A4)) {
            *(void **)(state + 0x1A4) = NULL;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlPlayerStopAim.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void controlPlayerStopAimAndLook(void *arg0) {
    s32 count;
    void **players;
    u8 *state;
    s32 i;

    players = objGetPlayerlist(&count);
    for (i = 0; i < count; i++) {
        state = *(u8 **) ((u8 *) players[i] + 0x68);
        if (arg0 == *(void **)(state + 0x1A4)) {
            *(void **)(state + 0x1A4) = NULL;
        }
        if (arg0 == *(void **)(state + 0x1D4)) {
            *(void **)(state + 0x1D4) = NULL;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlPlayerStopAimAndLook.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void controlGetGunBarrelPos(void *obj, void *state, f32 *x, f32 *y, f32 *z) {
    u8 *st = (u8 *) state;
    u8 *o = (u8 *) obj;
    u8 **list;
    u8 *holder;
    u8 *barrel;

    if (*(u32 *)(st + 0x540) & 0x04000000) {
        *x = *(f32 *)(st + 0x544);
        *y = *(f32 *)(st + 0x548);
        *z = *(f32 *)(st + 0x54C);
        return;
    }
    list = *(u8 ***) (o + 0x6C);
    holder = list[0];
    barrel = *(u8 **)(holder + 0x68);
    if (barrel != NULL) {
        *x = *(f32 *)(barrel + 0x0);
        *y = *(f32 *)(barrel + 0x4);
        *z = *(f32 *)(barrel + 0x8);
        return;
    }
    *x = *(f32 *)(o + 0xC);
    *y = *(f32 *)(o + 0x10);
    *z = *(f32 *)(o + 0x14);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlGetGunBarrelPos.s")
#endif

// TODO: This is clearly wrong, but it works.
s32 controlPlayerTiltList(Object *obj) {
    Object_Racer *player = &obj->racer[1];
    return &player->pad68[0x90];
}

// TODO: same as above
s32 controlSidekickTiltList(Object *obj) {
    Object_Racer *player = &obj->racer[0];
    return &player->pad68[0x2E];
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
f32 controlGravity(void) {
    return controlchr_gravity;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlGravity.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *controlGetWeaponDef(s32 arg0) {
    return weaponTable + arg0 * 0x30;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlGetWeaponDef.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_8003B2E4(s32 arg0, s32 arg1) {
    s32 v = arg0;

    if (arg1 == 0) {
        return v;
    }
    if ((arg1 & 0xC000) == 0x8000) {
        if (v < 0) {
            v += arg1 & 0x3FFF;
            if (v > 0) {
                return 0;
            }
            return v;
        }
        v -= arg1 & 0x3FFF;
        if (v < 0) {
            return 0;
        }
        return v;
    }
    v += arg1;
    if (v < -0x8000) {
        v = -0x8000;
    } else if (v >= 0x8000) {
        v = 0x7FFF;
    }
    return v;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/func_8003B2E4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void controlAlterMood(void *obj, s32 arg1) {
    u8 *state;
    u8 *entry;
    s32 idx = arg1;

    if (*(s16 *)((u8 *) obj + 0x48) == 1) {
        state = *(u8 **)((u8 *) obj + 0x68);
        if (arg1 >= 0xD) {
            idx = 0;
        }
        entry = D_800A11C0_A1DC0 + (idx << 5);
        *(s16 *)(state + 0x586) = (s16) func_8003B2E4(*(s16 *)(state + 0x586), *(s16 *)(entry + 0));
        *(s16 *)(state + 0x588) = (s16) func_8003B2E4(*(s16 *)(state + 0x588), *(s16 *)(entry + 2));
        *(s16 *)(state + 0x58A) = (s16) func_8003B2E4(*(s16 *)(state + 0x58A), *(s16 *)(entry + 4));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlAlterMood.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void controlSetPlayerSetup(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    D_800F6DEC_B179C = arg0;
    D_800F6DEE_B179E = arg1;
    D_800F6DF0_B17A0 = arg2;
    D_800F6DF2_B17A2 = arg3;
    D_800A3708[0] = 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlSetPlayerSetup.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 controlGetPlayerSetup(s16 *arg0, s16 *arg1, s16 *arg2, s16 *arg3) {
    if (D_800A3708[0] != 0) {
        *arg0 = D_800F6DEC_B179C;
        *arg1 = D_800F6DEE_B179E;
        *arg2 = D_800F6DF0_B17A0;
        *arg3 = D_800F6DF2_B17A2;
        D_800A3708[0] = 0;
        return 1;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlGetPlayerSetup.s")
#endif

extern u8 D_800A3708[8];

void controlClearPlayerSetup(void) {
    D_800A3708[0] = 0;
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void controlPlayerOpenChest(void *arg0, void *arg1) {
    u8 type = *((u8 *)arg1 + 1);

    switch (type) {
    case 0:
    case 4:
        /* sig mismatch: objAnimSetMove takes f32 arg2, asm passes int 0 */
        ((s32 (*)(void *, s32, s32))objAnimSetMove)(arg0, 0x30, 0);
        return;
    case 1:
    case 5:
        ((s32 (*)(void *, s32, s32))objAnimSetMove)(arg0, 0x2B, 0);
        return;
    case 2:
    case 6:
        ((s32 (*)(void *, s32, s32))objAnimSetMove)(arg0, 7, 0);
        /* fallthrough */
    default:
        return;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlPlayerOpenChest.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
/* objects.c declares this with one arg; the asm also reads arg1 (chest state). */
s32 controlPlayerOpeningChest(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 type = *((u8 *)arg1 + 1);
    f32 t;

    switch (type) {
    case 0:
    case 4:
        if (*(s8 *)(obj + 0x3B) == 0x30) {
            t = *(f32 *)(obj + 0x28);
            if (t < 0.15f) {
                return 2;
            }
            if (t < 0.53f) {
                return 1;
            }
            return 0;
        }
        return 0;
    case 1:
    case 5:
        if (*(s8 *)(obj + 0x3B) == 0x2B) {
            t = *(f32 *)(obj + 0x28);
            if (t < 0.15f) {
                return 2;
            }
            if (t < 0.53f) {
                return 1;
            }
            return 0;
        }
        return 0;
    default:
        return 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlPlayerOpeningChest.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void controlEmptyPlayersHand(void *obj, u8 weapon) {
    u8 *racer = *(u8 **)((u8 *)obj + 0x68);
    u8 *held = *(u8 **)(racer + 0x5CC);

    if (held != NULL) {
        if (*(s16 *)(held + 0x48) == 0x59) {
            *(f32 *)(held + 0x1C) = 0.0f;
            *(f32 *)(held + 0x20) = 0.0f;
            *(f32 *)(held + 0x24) = 0.0f;
            **(s32 **)(held + 0x68) = 0;
        }
        *(void **)(racer + 0x5CC) = NULL;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/charControl/controlEmptyPlayersHand.s")
#endif
