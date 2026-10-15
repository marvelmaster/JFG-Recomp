#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern f32 D_overlay_106_06A01D30;
void fxFreeCone(s32 arg0);
void chargeEffectFree(s32 arg0);
void objFreeObject(s32 arg0);
void amSndStopXYZ(s32 arg0);
s32 fxAllocateCone(s16 a0, s16 a1, s16 a2, s32 a3, s32 a4, f32 f0, f32 f1, s32 a7, s32 a8, s32 a9);
void hitInitObjectHit(void *obj, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, f32 f0, f32 f1, f32 f2, f32 f3, s32 a11);
s32 mainGetGameFlag(s32 flag);
f32 camDistance(f32 x, f32 y, f32 z, s32 *arr);
void camPushFloatModelMtx(Gfx **dl, void *arg1, f32 (*mtx)[4]);
void chargeEffectDraw(Gfx **dl, void *arg1, s32 arg2, s16 *vec, void *arg4, f32 (*mtx)[4]);
void fxDrawCone(Gfx **dl, s32 coneId, s32 mode, u8 flag);
void matrix_SCL_RPY_XYZ(void *obj, void *mtx);
void texAnimateSprite(void *arg0, s32 *arg1, s32 arg2, void *arg3, s32 arg4);
void partUpdateTriggers(void *arg0, s32 arg1);
void *objSetupObject(s16 *setup, s32 arg1);
void mathOneFloatPY(s16 *angles, void *vec);
extern s32 dayfactor;
extern f32 D_overlay_106_06A01D48;
extern f32 D_overlay_106_06A01D4C;
extern f32 D_overlay_106_06A01D50;
extern f32 D_overlay_106_06A01D54;
extern f32 D_overlay_106_06A01D58;
extern f32 D_overlay_106_06A01D5C;
extern f32 D_overlay_106_06A01D60;
extern f32 D_overlay_106_06A01D64;
extern f32 D_overlay_106_06A01D68;
extern f32 D_overlay_106_06A01D6C;
extern f32 D_overlay_106_06A01D70;
extern f32 D_overlay_106_06A01D74;
extern f32 D_overlay_106_06A01D78;
extern f32 D_overlay_106_06A01D7C;
extern f32 D_overlay_106_06A01D80;
extern f32 D_overlay_106_06A01D84;
extern f32 D_overlay_106_06A01D88;
extern f32 D_overlay_106_06A01D8C;
extern f32 D_overlay_106_06A01D90;
extern f32 D_overlay_106_06A01D94;
extern f32 D_overlay_106_06A01D98;
extern f32 D_overlay_106_06A01D9C;
extern f32 D_overlay_106_06A01DA0;
f32 Powerf(f32 base, s32 n);
f32 Sinf(s16 angle);
s32 chargeEffectCreate(s32 a0, s32 a1, s32 a2, f32 a3, f32 a4);
void chargeEffectSetPower(s32 handle, f32 power);
void chargeEffectUpdate(s32 handle, s32 dt);
void amSndPlay(u16 soundId, void *handlePtr);
void amSndPlayXYZ(u16 soundId, f32 x, f32 y, f32 z, u8 arg4, void *soundMask);
void amSndSetPitchXYZ(s32 handle, s32 pitch);
void amTuneStop(void);
void amTunePlay(u8 seqID);
void amTuneSetFade(f32 fade, u8 volume);
/* asm: called with f32 first arg and 6 words (camera.c version differs) */
void camStartShake(f32 a0, s32 a1, s32 a2, s32 a3, f32 a4, s32 a5);
s32 trackGetHeights(f32 x, f32 z, s32 flags, f32 ***out);
s32 trackGetIntersect(s32 a, f32 *from, f32 *to, f32 radius, s32 mask, void *hit);
void trackMakePolylist(s32 a, f32 *from, f32 *to, f32 *radius, s32 b, s32 c, s32 d);
s32 hitPlayer(f32 x, f32 y, f32 z, f32 r, s32 a4, void **out);
s32 mathSin(s32 angle);
s32 mathDiffAngle(s16 cur, s32 target);
void **objGetObjList(s32 *start, s32 *end);
void objMoveXYZ(void *obj, f32 x, f32 y, f32 z);
void objAnimSetFrame(void *obj, f32 frame);
void fxMakeConeTextureCoords(void *cone, s16 a);
void fxMakeConeLength(void *cone, s16 len, s32 a);
void dayStopAtNoon(void);
s32 frontGetMode(void);
s32 mainGetNextCharacter(void);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hoovertankInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *d;

    *(f32 *) (obj + 0x1C) = 0.0f;
    *(f32 *) (obj + 0x20) = 0.0f;
    *(f32 *) (obj + 0x24) = 0.0f;
    d = *(u8 **) (obj + 0x68);
    *(f32 *) (obj + 0x8) = (f32) *(u8 *) ((u8 *) arg1 + 0xA) * D_overlay_106_06A01D30;
    if (mainGetGameFlag(0x59) != 0) {
        d[0x0] = 5;
    } else {
        d[0x0] = 0;
    }
    d[0x1] = 0;
    *(s16 *) (d + 0x2) = 0;
    *(s32 *) (d + 0x1C) = 0;
    *(f32 *) (d + 0x20) = 0.0f;
    *(s32 *) (d + 0x24) = 0;
    *(s16 *) (d + 0x28) = 0;
    *(s16 *) (d + 0x2A) = 0;
    d[0x35] = 0;
    *(f32 *) (d + 0x2C) = 0.0f;
    *(f32 *) (d + 0x30) = 0.0f;
    d[0x34] = 1;
    d[0x36] = 0;
    hitInitObjectHit(arg0, -1, 0, 8, 0, 0, 0, 32.0f, 32.0f, -1.0f, 1.0f, 1);
    *(s16 *) (d + 0x38) = 0;
    d[0x3A] = (u8) mathRnd(-0x80, 0x7F);
    *(s32 *) (d + 0x3C) = fxAllocateCone(0, 0, (s16) (s32) (*(f32 *) (obj + 0x8) * -68.0f), 0, -0x4000, 18.0f, 75.0f, 0, 0x11, 0x12);
    d[0x3B] = (u8) mathRnd(-0x80, 0x7F);
    *(s32 *) (d + 0x40) = fxAllocateCone(0, 0, (s16) (s32) (*(f32 *) (obj + 0x8) * 70.0f), 0, -0x4000, 24.0f, 100.0f, 0, 0x11, 0x12);
    *(s32 *) (d + 0x44) = 0;
    *(s32 *) (d + 0x48) = 0;
    *(s32 *) (d + 0x4C) = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o106/overlay_106/hoovertankInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Hover-tank per-frame control. d = obj->0x68 state block; obj->0x0 yaw, 0x2 pitch,
// 0x8 scale, 0xC..0x14 position, 0x1C..0x24 velocity. Layout of d as in hoovertankInit.
void hoovertankControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *d;
    f32 dt = (f32) arg1;
    f32 from[3];
    f32 radius;
    u8 playerHit[0x20];                 /* hitPlayer out record (sp+0x98) */
    u8 hitRec[0x2C];                    /* trackGetIntersect hit record (sp+0xC4) */
    struct {
        s16 id;
        s16 pad02;
        s16 x;
        s16 y;
        s16 z;
        s16 pad0A;
        s16 rot;
        s16 unk0E;
        f32 scale;
    } spawnB;                           /* sp+0x6C */
    struct {
        s16 id;
        u8 unk2;
        u8 unk3;
        s16 x;
        s16 y;
        s16 z;
    } spawnA;                           /* sp+0x80 */
    void **list;
    void *spawned;
    void *cone;
    u8 *flags;
    u8 *it;
    f32 **heights;
    f32 chargeTarget;
    f32 dist;
    f32 dist2;
    f32 ddx;
    f32 ddy;
    f32 ddz;
    f32 nx;
    f32 ny;
    f32 nz;
    f32 w;
    f32 p;
    f32 dot;
    f32 ox;
    f32 oy;
    f32 oz;
    f32 shake;
    s32 mode;
    s32 vel;
    s32 lim;
    s32 target;
    s32 idx;
    s32 end;
    s32 k;
    s32 step;
    s32 ampTarget;
    s32 sp54;
    s32 sp64;
    s32 fd;
    s32 diff;
    s16 v28;
    s16 v2;

    d = *(u8 **) (obj + 0x68);
    if (d[0x0] == 5) {
        objFreeObject((s32) arg0);
        dayfactor = 0;
        return;
    }

    if (*(s16 *) (d + 0x2) < 0x1770) {
        if (arg1 < *(s16 *) (d + 0x2)) {
            *(s16 *) (d + 0x2) = (s16) (*(s16 *) (d + 0x2) - arg1);
        } else {
            *(s16 *) (d + 0x2) = 0;
        }
    }

    if (*(s32 *) (d + 0x1C) == 0) {
        *(s32 *) (d + 0x1C) = chargeEffectCreate(0x80, 2, 4, 45.0f, 320.0f);
    }
    if (*(void **) (d + 0x24) == NULL) {
        spawnA.id = 0x1DB;
        spawnA.unk2 = 10;
        spawnA.unk3 = 0;
        spawnA.x = 0;
        spawnA.y = 0;
        spawnA.z = 0;
        spawned = objSetupObject((s16 *) &spawnA, 1);
        *(void **) (d + 0x24) = spawned;
        if (spawned != NULL) {
            *(s32 *) ((u8 *) spawned + 0x3C) = 0;
        }
    }

    from[0] = *(f32 *) (obj + 0xC);
    from[1] = *(f32 *) (obj + 0x10);
    from[2] = *(f32 *) (obj + 0x14);
    if (hitPlayer(from[0], from[1], from[2], 450.0f, 1, (void **) playerHit) != 0 && d[0x0] < 3) {
        d[0x1] = 2;
        if (d[0x0] != 2) {
            d[0x0] = 2;
            d[0x37] = 0;
        }
        mode = 2;
    } else {
        mode = d[0x0];
        d[0x1] = 0;
    }

    switch (mode) {
    case 0:
        d[0x0] = 1;
        break;
    case 1:
        if (*(s8 *) (d + 0x35) < 0x20) {
            *(s8 *) (d + 0x35) = (s8) (*(s8 *) (d + 0x35) + 1);
        }
        *(s16 *) (obj + 0x0) = (s16) (*(s16 *) (obj + 0x0) + *(s8 *) (d + 0x35) * arg1);
        break;
    case 2:
        if (*(s8 *) (d + 0x35) > 0) {
            *(s8 *) (d + 0x35) = (s8) (*(s8 *) (d + 0x35) - 1);
        }
        if (d[0x34] != 0) {
            d[0x0] = 1;
        } else if (trackGetHeights(*(f32 *) (obj + 0xC), *(f32 *) (obj + 0x14), 0x800, &heights) != 0) {
            if (d[0x37] != 0) {
                if (*(f32 *) (obj + 0x10) - **heights < 480.0f) {
                    d[0x37] = 0;
                }
            } else if (480.0f < *(f32 *) (obj + 0x10) - **heights) {
                d[0x37] = 1;
            }
        }
        if (d[0x37] != 0) {
            d[0x1] = 0;
        }
        *(s16 *) (obj + 0x0) = (s16) (*(s16 *) (obj + 0x0) + *(s8 *) (d + 0x35) * arg1);
        break;
    case 3:
    case 4:
        if (*(s8 *) (d + 0x35) > 0) {
            *(s8 *) (d + 0x35) = (s8) (*(s8 *) (d + 0x35) - 1);
        }
        *(s16 *) (obj + 0x0) = (s16) (*(s16 *) (obj + 0x0) + *(s8 *) (d + 0x35) * arg1);
        break;
    default:
        break;
    }

    /* d+0x2C: forward speed (ramps to 24 while flag bit 0, else decays) */
    if ((d[0x1] & 1) != 0) {
        if (*(f32 *) (d + 0x2C) < 24.0f) {
            *(f32 *) (d + 0x2C) = *(f32 *) (d + 0x2C) + D_overlay_106_06A01D48 * dt;
            if (24.0f < *(f32 *) (d + 0x2C)) {
                *(f32 *) (d + 0x2C) = 24.0f;
            }
        }
    } else {
        *(f32 *) (d + 0x2C) = *(f32 *) (d + 0x2C) * Powerf(D_overlay_106_06A01D4C, arg1);
        if (D_overlay_106_06A01D50 < *(f32 *) (d + 0x2C) && *(f32 *) (d + 0x2C) < D_overlay_106_06A01D54) {
            *(f32 *) (d + 0x2C) = 0.0f;
        }
    }
    *(f32 *) (obj + 0x1C) = -(Sinf(*(s16 *) (obj + 0x0)) * *(f32 *) (d + 0x2C));
    *(f32 *) (obj + 0x24) = -(Cosf(*(s16 *) (obj + 0x0)) * *(f32 *) (d + 0x2C));

    /* d+0x30: pitch/lift speed */
    if ((d[0x1] & 2) != 0) {
        if (*(f32 *) (d + 0x30) < 0.5f) {
            *(f32 *) (d + 0x30) = *(f32 *) (d + 0x30) + D_overlay_106_06A01D58 * dt;
            if (0.5f < *(f32 *) (d + 0x30)) {
                *(f32 *) (d + 0x30) = 0.5f;
            }
        }
        d[0x34] = 0;
    } else {
        *(f32 *) (d + 0x30) = *(f32 *) (d + 0x30) * Powerf(D_overlay_106_06A01D5C, arg1);
        if (D_overlay_106_06A01D60 < *(f32 *) (d + 0x30) && *(f32 *) (d + 0x30) < D_overlay_106_06A01D64) {
            *(f32 *) (d + 0x30) = 0.0f;
            if ((d[0x1] & 4) != 0) {
                *(f32 *) (obj + 0x20) = *(f32 *) (obj + 0x20) * Powerf(D_overlay_106_06A01D68, arg1);
                if (D_overlay_106_06A01D6C < *(f32 *) (obj + 0x20) && *(f32 *) (obj + 0x20) < D_overlay_106_06A01D70) {
                    *(f32 *) (obj + 0x20) = 0.0f;
                }
            } else if (d[0x34] == 0) {
                if (0.0f < *(f32 *) (obj + 0x20)) {
                    *(f32 *) (obj + 0x20) = *(f32 *) (obj + 0x20) * Powerf(D_overlay_106_06A01D74, arg1);
                }
                *(f32 *) (obj + 0x20) = *(f32 *) (obj + 0x20) - D_overlay_106_06A01D78;
                if (*(f32 *) (obj + 0x20) < -10.0f) {
                    *(f32 *) (obj + 0x20) = -10.0f;
                }
            }
        }
    }

    /* d+0x36: countdown, clears bits 0..1 of d+0x1 when it expires */
    if (d[0x36] != 0) {
        d[0x36] = (u8) (d[0x36] - arg1);
        if (d[0x36] == 0) {
            d[0x1] = (u8) (d[0x1] & 0xFFFC);
        }
    }

    if (*(f32 *) (d + 0x30) != 0.0f) {
        if (*(f32 *) (obj + 0x20) < 0.0f) {
            *(f32 *) (obj + 0x20) = *(f32 *) (obj + 0x20) * Powerf(D_overlay_106_06A01D7C, arg1);
        }
        *(f32 *) (obj + 0x20) = *(f32 *) (obj + 0x20) + *(f32 *) (d + 0x30);
        if (10.0f < *(f32 *) (obj + 0x20)) {
            *(f32 *) (obj + 0x20) = 10.0f;
        }
    }

    /* yaw turn toward the target speed (arg1 steps, >> 4 each) */
    vel = (s32) (*(f32 *) (d + 0x2C) * D_overlay_106_06A01D80);
    lim = (s32) (*(f32 *) (d + 0x30) * 6400.0f);
    if (vel < lim) {
        vel = -lim;
    }
    target = -vel;
    for (k = arg1; k != 0; k--) {
        *(s16 *) (obj + 0x2) = (s16) (*(s16 *) (obj + 0x2) + (mathDiffAngle(*(s16 *) (obj + 0x2), target) >> 4));
    }

    if (d[0x34] == 0) {
        objMoveXYZ(obj, *(f32 *) (obj + 0x1C) * dt, *(f32 *) (obj + 0x20) * dt, *(f32 *) (obj + 0x24) * dt);
        radius = 3.0f;
        trackMakePolylist(1, from, (f32 *) (obj + 0xC), &radius, 0, 0, 0);
        if (trackGetIntersect((s32) arg0, from, (f32 *) (obj + 0xC), radius, 0x20, hitRec) != 0
            && (hitRec[0x25] & 2) != 0) {
            dist = ((f32 (*)(f32, f32, f32)) camDistance)(*(f32 *) (obj + 0xC), *(f32 *) (obj + 0x10), *(f32 *) (obj + 0x14));
            if (dist < D_overlay_106_06A01D84) {
                shake = -(*(f32 *) (obj + 0x20) * D_overlay_106_06A01D88);
                if (500.0f < dist) {
                    shake = shake * ((D_overlay_106_06A01D84 - dist) / 2000.0f);
                }
                camStartShake(D_overlay_106_06A01D84, 0, 0, 0, 2.0f, (s32) shake);
            }
            amSndPlayXYZ(0x1D4, *(f32 *) (obj + 0xC), *(f32 *) (obj + 0x10), *(f32 *) (obj + 0x14), 4, NULL);
            spawnB.id = 0x13B;
            spawnB.x = (s16) (s32) *(f32 *) (obj + 0xC);
            spawnB.y = (s16) (s32) (*(f32 *) (obj + 0x10) + 4.0f);
            spawnB.z = (s16) (s32) *(f32 *) (obj + 0x14);
            spawnB.pad0A = 0;
            spawnB.rot = -0x4000;
            spawnB.unk0E = 0x2D;
            spawnB.scale = 1.0f;
            spawned = objSetupObject((s16 *) &spawnB, 1);
            if (spawned != NULL) {
                *(s32 *) ((u8 *) spawned + 0x3C) = 0;
            }
            d[0x34] = 1;
            *(f32 *) (obj + 0x20) = 0.0f;
        }
    }

    /* d+0x04..0x18: two attachment points, rotated by the object's rotation */
    *(f32 *) (d + 0x4) = 0.0f;
    *(f32 *) (d + 0x8) = *(f32 *) (obj + 0x8) * 20.0f;
    *(f32 *) (d + 0xC) = *(f32 *) (obj + 0x8) * -88.0f;
    pointListRPY(1, (s16 *) obj, (s32 *) (d + 0x4), (f32 *) (d + 0x4));
    *(f32 *) (d + 0x4) = *(f32 *) (d + 0x4) + *(f32 *) (obj + 0xC);
    *(f32 *) (d + 0x8) = *(f32 *) (d + 0x8) + *(f32 *) (obj + 0x10);
    *(f32 *) (d + 0xC) = *(f32 *) (d + 0xC) + *(f32 *) (obj + 0x14);
    *(f32 *) (d + 0x10) = 0.0f;
    *(f32 *) (d + 0x14) = 0.0f;
    *(f32 *) (d + 0x18) = -1.0f;
    pointListRPY(1, (s16 *) obj, (s32 *) (d + 0x10), (f32 *) (d + 0x10));

    list = objGetObjList(&idx, &end);
    chargeTarget = 0.0f;
    if (d[0x0] == 1 && idx < end) {
        do {
            it = (u8 *) list[idx];
            idx = idx + 1;
            if (*(s16 *) (it + 0x48) == 0x86) {
                ddx = *(f32 *) (it + 0xC) - *(f32 *) (d + 0x4);
                ddy = *(f32 *) (it + 0x10) - *(f32 *) (d + 0x8);
                ddz = *(f32 *) (it + 0x14) - *(f32 *) (d + 0xC);
                dist2 = ddx * ddx + ddy * ddy + ddz * ddz;
                if (dist2 < 64.0f) {
                    objFreeObject((s32) it);
                    amSndPlay(0x16E, NULL);
                    *(s16 *) (d + 0x2) = (s16) (*(s16 *) (d + 0x2) + 0x258);
                    if (*(s16 *) (d + 0x2) >= 0x1771) {
                        *(s16 *) (d + 0x2) = 0x1770;
                    }
                } else if (dist2 < 102400.0f) {
                    dist = sqrtf(dist2);
                    w = dist * D_overlay_106_06A01D8C + 10.0f;
                    nx = ddx;
                    ny = ddy;
                    nz = ddz;
                    if (0.0f < dist) {
                        nx = nx / dist;
                        ny = ny / dist;
                        nz = nz / dist;
                    }
                    flags = *(u8 **) (it + 0x7C);
                    dot = *(f32 *) (d + 0x10) * nx + *(f32 *) (d + 0x14) * ny + *(f32 *) (d + 0x18) * nz;
                    if (flags != NULL) {
                        if (dist < 48.0f) {
                            chargeTarget = 1.0f;
                            p = Powerf(D_overlay_106_06A01D90, arg1);
                            flags[0] = (u8) (flags[0] & 0xFD);
                            ox = *(f32 *) (it + 0x1C);
                            oy = *(f32 *) (it + 0x20);
                            oz = *(f32 *) (it + 0x24);
                            *(f32 *) (it + 0x1C) = ox + ((-nx * w) - ox) * (1.0f - p);
                            *(f32 *) (it + 0x20) = oy + ((-ny * w) - oy) * (1.0f - p);
                            *(f32 *) (it + 0x24) = oz + ((-nz * w) - oz) * (1.0f - p);
                            *(void **) (flags + 0x20) = arg0;
                        } else if (D_overlay_106_06A01D94 < dot) {
                            w = w * dot;
                            chargeTarget = 1.0f;
                            p = Powerf(0.875f, arg1);
                            flags[0] = (u8) (flags[0] & 0xFD);
                            ox = *(f32 *) (it + 0x1C);
                            oy = *(f32 *) (it + 0x20);
                            oz = *(f32 *) (it + 0x24);
                            *(f32 *) (it + 0x1C) = ox + ((-nx * w) - ox) * (1.0f - p);
                            *(f32 *) (it + 0x20) = oy + ((-ny * w) - oy) * (1.0f - p);
                            *(f32 *) (it + 0x24) = oz + ((-nz * w) - oz) * (1.0f - p);
                            *(void **) (flags + 0x20) = arg0;
                        }
                    }
                }
            }
        } while (idx < end);
    }
    if (*(s32 *) (d + 0x1C) != 0) {
        *(f32 *) (d + 0x20) = *(f32 *) (d + 0x20) + (chargeTarget - *(f32 *) (d + 0x20)) * (1.0f - Powerf(D_overlay_106_06A01D98, arg1));
        chargeEffectSetPower(*(s32 *) (d + 0x1C), *(f32 *) (d + 0x20));
        chargeEffectUpdate(*(s32 *) (d + 0x1C), arg1);
    }

    /* d+0x28: dayfactor ramp; d+0x2A: phase timer */
    if (*(s16 *) (d + 0x2A) == 0) {
        v28 = *(s16 *) (d + 0x28);
        v2 = *(s16 *) (d + 0x2);
        if (v28 < v2) {
            *(s16 *) (d + 0x28) = (s16) (v28 + arg1 * 4);
            if (v2 < *(s16 *) (d + 0x28)) {
                *(s16 *) (d + 0x28) = v2;
            }
        } else {
            *(s16 *) (d + 0x28) = (s16) (v28 - arg1 * 4);
            if (*(s16 *) (d + 0x28) < v2) {
                *(s16 *) (d + 0x28) = v2;
            }
        }
        dayfactor = ((s32) ((*(s16 *) (d + 0x28) * 4 - *(s16 *) (d + 0x28)) << 11) / 6000) + 0x100;
        if (*(s16 *) (d + 0x28) == 0x1770) {
            *(s16 *) (d + 0x2A) = 0x3C;
            amTuneStop();
            amTunePlay(0x2B);
        }
    } else if (d[0x0] != 4) {
        fd = *(s16 *) (d + 0x2A);
        if (arg1 < fd) {
            *(s16 *) (d + 0x2A) = (s16) (fd - arg1);
            dayStopAtNoon();
        } else {
            *(s16 *) (d + 0x28) = (s16) (*(s16 *) (d + 0x28) - arg1 * 12);
            *(s16 *) (d + 0x2A) = 1;
            if (*(s16 *) (d + 0x28) < 0) {
                d[0x0] = 4;
                *(s16 *) (d + 0x28) = 0;
                sp54 = mainGetNextCharacter();
                mainChangeLevel(0x165, sp54, 0, frontGetMode(), 0, 0);
                amTuneSetFade(0.5f, 0);
            }
            dayfactor = ((s32) (*(s16 *) (d + 0x28) * 0x1300) / 6000) + 0x600;
        }
    }

    /* object d+0x24 follows the tank (its own rotation and an offset point) */
    if (*(void **) (d + 0x24) != NULL) {
        spawned = *(void **) (d + 0x24);
        *(s16 *) ((u8 *) spawned + 0x0) = *(s16 *) (obj + 0x0);
        *(s16 *) ((u8 *) spawned + 0x2) = *(s16 *) (obj + 0x2);
        *(f32 *) ((u8 *) spawned + 0xC) = 0.0f;
        *(s16 *) ((u8 *) spawned + 0x4) = *(s16 *) (obj + 0x4);
        *(f32 *) ((u8 *) spawned + 0x14) = 0.0f;
        *(f32 *) ((u8 *) spawned + 0x10) = *(f32 *) (obj + 0x8) * 130.0f;
        pointListRPY(1, (s16 *) obj, (s32 *) ((u8 *) spawned + 0xC), (f32 *) ((u8 *) spawned + 0xC));
        *(f32 *) ((u8 *) spawned + 0xC) = *(f32 *) ((u8 *) spawned + 0xC) + *(f32 *) (obj + 0xC);
        *(f32 *) ((u8 *) spawned + 0x10) = *(f32 *) ((u8 *) spawned + 0x10) + *(f32 *) (obj + 0x10);
        *(f32 *) ((u8 *) spawned + 0x14) = *(f32 *) ((u8 *) spawned + 0x14) + *(f32 *) (obj + 0x14);
        *(f32 *) ((u8 *) spawned + 0x8) = ((f32) *(s16 *) (d + 0x28) / D_overlay_106_06A01D9C) * *(f32 *) (obj + 0x8) + D_overlay_106_06A01DA0;
        objAnimSetFrame(spawned, 1.0f);
    }

    /* d+0x37/0x34 select the ampTarget; d+0x38 ramps toward it (arg1 steps) */
    if (d[0x37] != 0) {
        ampTarget = 0x80;
    } else if (d[0x1] != 0) {
        ampTarget = 0xFF;
    } else {
        ampTarget = 0;
    }
    for (k = arg1; k != 0; k--) {
        diff = (ampTarget - *(s16 *) (d + 0x38)) >> 4;
        step = diff;
        if (diff == 0) {
            if (ampTarget < *(s16 *) (d + 0x38)) {
                step = -1;
            } else if (*(s16 *) (d + 0x38) < ampTarget) {
                step = 1;
            }
        }
        *(s16 *) (d + 0x38) = (s16) (*(s16 *) (d + 0x38) + step);
    }

    if (*(s16 *) (d + 0x38) != 0) {
        cone = *(void **) (d + 0x3C);
        if (cone != NULL) {
            d[0x3A] = (u8) (d[0x3A] + arg1 * 16);
            sp64 = ((mathSin((s16) (d[0x3A] << 8)) + 0x18000) * (((s32) (*(s16 *) ((u8 *) cone + 0x20) * *(s16 *) (d + 0x38))) >> 8)) >> 16;
            fxMakeConeTextureCoords(cone, (s16) (d[0x3A] << 8));
            fxMakeConeLength(cone, (s16) sp64, *(s16 *) (d + 0x38));
        }
        cone = *(void **) (d + 0x40);
        if (cone != NULL) {
            d[0x3B] = (u8) (d[0x3B] + arg1 * 16);
            sp64 = ((mathSin((s16) (d[0x3B] << 8)) + 0x18000) * (((s32) (*(s16 *) ((u8 *) cone + 0x20) * *(s16 *) (d + 0x38))) >> 8)) >> 16;
            fxMakeConeTextureCoords(cone, (s16) (d[0x3B] << 8));
            fxMakeConeLength(cone, (s16) sp64, *(s16 *) (d + 0x38));
        }
    }

    /* looping sounds: handle at d+0x44 (pitch from d+0x28), d+0x48 (d+0x35), d+0x4C (d+0x38) */
    if (*(s16 *) (d + 0x28) != 0) {
        if (*(s32 *) (d + 0x44) == 0) {
            amSndPlayXYZ(0x1D6, *(f32 *) (obj + 0xC), *(f32 *) (obj + 0x10), *(f32 *) (obj + 0x14), 1, (void *) (d + 0x44));
        }
        amSndSetPitchXYZ(*(s32 *) (d + 0x44), (((s32) (*(s16 *) (d + 0x28) * 0x4B) / 6000) + 0x4B) & 0xFF);
    } else if (*(s32 *) (d + 0x44) != 0) {
        amSndStopXYZ(*(s32 *) (d + 0x44));
    }

    if (d[0x34] != 0 && *(s8 *) (d + 0x35) != 0) {
        if (*(s32 *) (d + 0x48) == 0) {
            amSndPlayXYZ(0x1D3, *(f32 *) (obj + 0xC), *(f32 *) (obj + 0x10), *(f32 *) (obj + 0x14), 1, (void *) (d + 0x48));
        }
        amSndSetPitchXYZ(*(s32 *) (d + 0x48), (*(s8 *) (d + 0x35) + 0x46) & 0xFF);
    } else if (*(s32 *) (d + 0x48) != 0) {
        amSndStopXYZ(*(s32 *) (d + 0x48));
    }

    if (*(s16 *) (d + 0x38) != 0) {
        if (*(s32 *) (d + 0x4C) == 0) {
            amSndPlayXYZ(0x1D5, *(f32 *) (obj + 0xC), *(f32 *) (obj + 0x10), *(f32 *) (obj + 0x14), 1, (void *) (d + 0x4C));
        }
        amSndSetPitchXYZ(*(s32 *) (d + 0x4C), (((s32) (*(s16 *) (d + 0x38) * 0x32) / 255) + 0x4B) & 0xFF);
    } else if (*(s32 *) (d + 0x4C) != 0) {
        amSndStopXYZ(*(s32 *) (d + 0x4C));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o106/overlay_106/hoovertankControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
static void hoovertankSwapEntries(f32 *dist, s32 *kind, s32 a, s32 b) {
    f32 tf = dist[a];
    s32 ti = kind[a];

    dist[a] = dist[b];
    dist[b] = tf;
    kind[a] = kind[b];
    kind[b] = ti;
}

void hoovertankDrawEffects(Gfx **arg0, void *arg1, void *arg2) {
    u8 *obj = (u8 *) arg2;
    u8 *d = *(u8 **) (obj + 0x68);
    struct {
        s16 rot[3];
        s16 pad;
        f32 scale;
        f32 pos[3];
    } xf;
    f32 mtx[4][4];
    f32 dist[3];
    s32 kind[3];
    s16 vec[3];
    f32 ex;
    f32 ey;
    f32 ez;
    s32 n = 0;
    s32 pass;
    s32 k;
    s32 i;

    xf.rot[0] = *(s16 *) (obj + 0x0);
    xf.rot[1] = *(s16 *) (obj + 0x2);
    xf.rot[2] = *(s16 *) (obj + 0x4);
    xf.scale = 1.0f;
    xf.pos[0] = *(f32 *) (obj + 0xC);
    xf.pos[1] = *(f32 *) (obj + 0x10);
    xf.pos[2] = *(f32 *) (obj + 0x14);
    matrix_SCL_RPY_XYZ(&xf, mtx);

    if (*(s32 *) (d + 0x3C) != 0) {
        mathMtxXFMF(mtx, 0.0f, 0.0f, *(f32 *) (obj + 0x8) * -68.0f, &ex, &ey, &ez);
        /* asm: camDistance gets only three float args here (a3 not set) */
        dist[0] = ((f32 (*)(f32, f32, f32)) camDistance)(ex, ey, ez);
        kind[0] = 0;
        n = 1;
    }
    if (*(s32 *) (d + 0x40) != 0) {
        mathMtxXFMF(mtx, 0.0f, 0.0f, *(f32 *) (obj + 0x8) * 70.0f, &ex, &ey, &ez);
        dist[n] = ((f32 (*)(f32, f32, f32)) camDistance)(ex, ey, ez);
        kind[n] = 1;
        n += 1;
    }
    if (*(s32 *) (d + 0x1C) != 0) {
        dist[n] = camDistance(*(f32 *) (d + 0x4), *(f32 *) (d + 0x8), *(f32 *) (d + 0xC), kind);
        kind[n] = 2;
        n += 1;
    }

    /* odd-even exchange sort, descending by distance (kind moves with dist) */
    for (pass = n - 1; pass > 0; pass--) {
        k = 0;
        if (pass & 1) {
            k = 1;
            if (dist[0] < dist[1]) {
                hoovertankSwapEntries(dist, kind, 0, 1);
            }
            if (pass == 1) {
                continue;
            }
        }
        for (; k != pass; k += 2) {
            if (dist[k] < dist[k + 1]) {
                hoovertankSwapEntries(dist, kind, k, k + 1);
            }
            if (dist[k + 1] < dist[k + 2]) {
                hoovertankSwapEntries(dist, kind, k + 1, k + 2);
            }
        }
    }

    for (i = 0; i < n; i++) {
        switch (kind[i]) {
        case 0:
            camPushFloatModelMtx(arg0, arg1, mtx);
            fxDrawCone(arg0, *(s32 *) (d + 0x3C), 6, d[0x39]);
            camRestoreModelMtx(arg0);
            break;
        case 1:
            camPushFloatModelMtx(arg0, arg1, mtx);
            fxDrawCone(arg0, *(s32 *) (d + 0x40), 6, d[0x39]);
            camRestoreModelMtx(arg0);
            break;
        case 2:
            vec[0] = 0;
            vec[1] = 0x4000;
            vec[2] = 0;
            chargeEffectDraw(arg0, arg1, *(s32 *) (d + 0x1C), vec, d + 0x4, mtx);
            break;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o106/overlay_106/hoovertankDrawEffects.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hoovertankFree(void *arg0) {
    u8 *d = *(u8 **) ((u8 *) arg0 + 0x68);

    if (*(s32 *) (d + 0x3C) != 0) {
        fxFreeCone(*(s32 *) (d + 0x3C));
    }
    if (*(s32 *) (d + 0x40) != 0) {
        fxFreeCone(*(s32 *) (d + 0x40));
    }
    if (*(s32 *) (d + 0x1C) != 0) {
        chargeEffectFree(*(s32 *) (d + 0x1C));
    }
    if (*(s32 *) (d + 0x24) != 0) {
        objFreeObject(*(s32 *) (d + 0x24));
    }
    if (*(s32 *) (d + 0x44) != 0) {
        amSndStopXYZ(*(s32 *) (d + 0x44));
    }
    if (*(s32 *) (d + 0x48) != 0) {
        amSndStopXYZ(*(s32 *) (d + 0x48));
    }
    if (*(s32 *) (d + 0x4C) != 0) {
        amSndStopXYZ(*(s32 *) (d + 0x4C));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o106/overlay_106/hoovertankFree.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hoovergemInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *) arg0;

    *(s32 *) (obj + 0x88) = *(u16 *) ((u8 *) arg1 + 0xA) * 6;
    *(s32 *) (obj + 0x8C) = 0xFF;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o106/overlay_106/hoovergemInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hoovergemControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *) arg0;
    s32 sp2C;
    s32 remaining;

    *(s16 *) (*(u8 **) (obj + 0x4C) + 0x6) = 0x1000;
    if (arg1 >= *(s32 *) (obj + 0x88)) {
        objFreeObject((s32) arg0);
        return;
    }
    remaining = *(s32 *) (obj + 0x88) - arg1;
    *(s32 *) (obj + 0x88) = remaining;
    if (remaining < 0x40) {
        *(s32 *) (obj + 0x8C) = remaining << 2;
    }
    sp2C = 9;
    texAnimateSprite(*(void **) (*(u8 **) (obj + 0x6C) + (*(s8 *) (obj + 0x3A) * 4)), &sp2C, 0xC, obj + 0x28, arg1);
    if (mathRnd(0, 0x64) >= 0x5B) {
        *(s32 *) (obj + 0x84) = *(s32 *) (obj + 0x84) | 1;
    } else {
        *(s32 *) (obj + 0x84) = *(s32 *) (obj + 0x84) & ~1;
    }
    partUpdateTriggers(arg0, arg1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o106/overlay_106/hoovergemControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hoovergemCreate(f32 arg0, f32 arg1, f32 arg2, s16 arg3, s16 arg4, f32 arg5, f32 arg6) {
    s16 setup[6];
    s16 angles[3];
    void *obj;
    u8 *flags;

    setup[0] = 0x311;
    setup[2] = (s16) (s32) arg0;
    setup[3] = (s16) (s32) arg1;
    setup[4] = (s16) (s32) arg2;
    setup[5] = (s16) (s32) (arg6 * 10.0f);
    obj = objSetupObject(setup, 1);
    if (obj != NULL) {
        *(s32 *) ((u8 *) obj + 0x3C) = 0;
        angles[0] = arg3;
        angles[1] = arg4;
        angles[2] = 0;
        *(f32 *) ((u8 *) obj + 0x24) = -arg5;
        mathOneFloatPY(angles, (u8 *) obj + 0x1C);
        flags = *(u8 **) ((u8 *) obj + 0x7C);
        if (flags != NULL) {
            *flags = (u8) (*flags & 0xFFFD);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o106/overlay_106/hoovergemCreate.s")
#endif
