#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern s32 __MODULE00112;
extern u8 D_1000A0838;
void amSndStopXYZ(void *soundMask);
void *camGetPtr(void);
void runlinkSetDestructTimer(s32 overlayIndex, s32 selfDestructTimer, s32 refCount);
void camPushFloatModelMtx(void **arg0, void **arg1, f32 (*arg2)[4]);
void mathOneFloatPY(void *obj, f32 *out, void *def);
void hitInitObjectHit(void *obj, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, f32 f0, f32 f1, f32 f2, f32 f3, s32 a11);
s16 objTvTimes(s32 timer);
void objAddMine(void *obj);
void matrix_SCL_RPY_XYZ(void *obj, f32 (*mtx)[4]);
extern u8 D_overlay_112_070013E4[];
extern f32 D_overlay_112_0700140C;
extern f32 D_overlay_112_07001410;
extern f32 D_overlay_112_07001414;
extern f32 D_overlay_112_07001418;
extern f32 D_overlay_112_0700141C;
f32 Powerf(f32 base, s32 n);
s32 trackPolyHeight(f32 x, f32 z, f32 *height, s32 flags);
s32 trackNearestIntersection(void *obj, f32 *from, void *to, void *out, s32 mask, s32 c);
void **objGetObjList(s32 *start, s32 *end);
void *objSetupObject(void *params, s32 arg1);
void objFreeObject(void *obj);
void objMoveXYZ(void *obj, f32 x, f32 y, f32 z);
void amSndPlayXYZ(s32 sfx, f32 x, f32 y, f32 z, s32 arg4, void *soundMask);
void explosionStart(s32 kind, s16 x, s16 y, s16 z, s32 arg4, void *arg5);
void explosionAddBlast(f32 x, f32 y, f32 z, f32 arg3, f32 radius, f32 arg5, s32 arg6, void *owner);
void squadsAddInterestingEvent(void *arg0, s16 x, s16 y, s16 z, s32 a, s32 b, s32 c);
void partUpdateTriggers(void *obj, s32 arg1, void *pos);
void hitBridgeMoveWith(void *a0, void *a1, void *a2, void *a3, void *a4, void *a5, void *a6);
void lightObject(void *obj, void *anim, s32 arg2, void *arg3);
void mathMtxCatF(void *a, void *b, void *c);
void matrixTransposeVectorMultiply(void *mtx, f32 *in, f32 *out);
void modGenAnimMatrices(void *anim, void *model, void *obj, f32 scale, f32 time);
void objAnimDframe(void *obj, s32 speedBits, f32 dt, s32 flags);
void objAnimTextures(void *obj, void *model, void *anim, s32 arg3);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mineRemove(Object *arg0) {
    u8 *state = *(u8 **)((u8 *)arg0 + 0x68);
    void *sound;

    if (state[1] != 5) {
        sound = *(void **)(state + 0xA8);
        if (sound != NULL) {
            amSndStopXYZ(sound);
        }
        state[1] = 6;
        *(s32 *)(state + 0xAC) = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o112/overlay_112/mineRemove.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mineInit(Object *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *def = (u8 *)arg1;
    u8 *state;
    u8 kind;
    f32 radius;

    state = *(u8 **)(obj + 0x68);
    if (def[3] == 0) {
        state[0] = 0;
        state[1] = 2;
        state[4] = 1;
        state[5] = mathRnd(0, 0x7F);
        *(s32 *)(state + 0x9C) = 0;
        *(s32 *)(state + 0xA0) = 0;
    } else {
        *(f32 *)(obj + 0x24) = -*(f32 *)(def + 0x10);
        *(s16 *)(obj + 0x0) = *(s16 *)(def + 0xC);
        *(s16 *)(obj + 0x4) = 0;
        *(s16 *)(obj + 0x2) = *(s16 *)(def + 0xE);
        mathOneFloatPY(obj, (f32 *)(obj + 0x1C), def);
        state[1] = 0;
        state[2] = 0x3C;
        state[0] = def[0xA];
        state[3] = def[0xB];
        state[5] = 0;
        state[4] = def[0x18];
        *(s16 *)(state + 0x6) = objTvTimes(def[0x19] * 6);
        *(s32 *)(state + 0x9C) = *(s32 *)(def + 0x14);
        *(s32 *)(state + 0xA0) = *(s32 *)(def + 0x14);
        *(s32 *)(obj + 0x3C) = 0;
        kind = state[0];
        if (kind == 0 || kind == 1) {
            objAddMine(arg0);
        }
    }
    *(s16 *)(state + 0x9A) = 0;
    *(s32 *)(obj + 0x88) = 0;
    *(s32 *)(obj + 0x8C) = 0xFF;
    kind = state[0];
    if (kind == 0) {
        radius = 80.0f;
    } else if (kind == 1) {
        radius = 107.0f;
    } else {
        radius = 32.0f;
    }
    hitInitObjectHit(obj, 0x100, 1, 2, 0, 0, 0, radius, radius, -1.0f, 1.0f, 1);
    matrix_SCL_RPY_XYZ(obj, (f32 (*)[4])(state + 0x48));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o112/overlay_112/mineInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Hit record written by trackNearestIntersection (asm sp+0x124..0x14F). Layout as in
// overlay_113 MissileHit: obj, hit point, surface normal, extra float, surface type.
typedef struct MineHit {
    /* 0x00 */ void *obj;
    /* 0x04 */ f32 hitX;
    /* 0x08 */ f32 hitY;
    /* 0x0C */ f32 hitZ;
    /* 0x10 */ f32 nx;
    /* 0x14 */ f32 ny;
    /* 0x18 */ f32 nz;
    /* 0x1C */ f32 w;
    /* 0x20 */ u8 pad20[8];
    /* 0x28 */ s32 surface;
} MineHit;

// Spawn block for objSetupObject on detonation (asm sp+0x80..0x97).
typedef struct MineSpawn {
    /* 0x00 */ s16 id;
    /* 0x02 */ u8 pad02[2];
    /* 0x04 */ s16 x;
    /* 0x06 */ s16 y;
    /* 0x08 */ s16 z;
    /* 0x0A */ s16 yaw;
    /* 0x0C */ u16 pitch;
    /* 0x0E */ u8 pad0E[2];
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;   // D_overlay_112_070013E4[state->kind]
    /* 0x12 */ u8 unk12;
    /* 0x13 */ s8 unk13;   // state->unk98
    /* 0x14 */ void *owner;
} MineSpawn;

void mineControl(Object *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *st = *(u8 **)(obj + 0x68);
    void *hitObj;
    void *snd;
    void *created;
    void *var_t0;
    void **list;
    void **cur;
    u8 *hitModel;
    u8 *timerObj;
    u8 *anim;
    u8 *model;
    u8 *other;
    u8 *ptr;
    u8 *racer;
    s16 hitId;
    s16 otherId;
    s16 savedUnk2;
    s32 start;
    s32 end;
    s32 found;
    s32 mode;
    s32 kind;
    s32 step;
    s32 v1;
    s32 timer6;
    f32 fstep;
    f32 spE8;
    f32 hpow;
    f32 savedY;
    f32 floorY;
    f32 spFC;
    f32 mx;
    f32 my;
    f32 mz;
    f32 vx;
    f32 vy;
    f32 vz;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 from[3];
    f32 spD8[3];
    f32 mtx98[4][4];
    MineHit hit;
    MineSpawn spawn;

    runlinkSetDestructTimer(__MODULE00112, 2, 2);

    // Object being touched (asm: state->unkA4)
    hitObj = *(void **)(st + 0xA4);
    if (hitObj != NULL) {
        hitId = *(s16 *)((u8 *)hitObj + 0x48);
        hitModel = *(u8 **)((u8 *)hitObj + 0x5C);
        if (hitId == 0x37) {
            hitBridgeMoveWith(hitObj, st + 0x38, st + 0x3C, st + 0x40, obj + 0xC, obj + 0x10, obj + 0x14);
        } else if (hitId == 7) {
            racer = *(u8 **)((u8 *)hitObj + 0x68);
            if (*(u16 *)(racer + 0x3E) & 5) {
                st[1] = 5;
            }
        } else if (hitId == 0x4E) {
            if (*(s32 *)((u8 *)hitObj + 0x88) <= 0) {
                st[1] = 5;
            }
        } else if (*(s16 *)(hitModel + 0x12C) != 0) {
            mathMtxXFMF(hitModel + (hitModel[0x12B] << 6) + 0x80,
                        *(f32 *)(st + 0x38), *(f32 *)(st + 0x3C), *(f32 *)(st + 0x40),
                        &mx, &my, &mz);
            objMoveXYZ(arg0, mx - *(f32 *)(obj + 0xC), my - *(f32 *)(obj + 0x10),
                       mz - *(f32 *)(obj + 0x14));
        }
    }

    // Parent object countdown (asm: obj->unk4C, timer at +6)
    timerObj = *(u8 **)(obj + 0x4C);
    if (timerObj != NULL) {
        if (*(s16 *)(st + 0x9A) != 0) {
            *(s16 *)(timerObj + 6) = (s16)(*(s16 *)(timerObj + 6) - (arg1 * 0x10));
        }
        if (*(s16 *)(timerObj + 6) <= 0) {
            st[1] = 5;
        }
    }

    mode = st[1];
    *(s16 *)(st + 0x9A) = 0;
    switch (mode) {
    case 0:
        from[0] = *(f32 *)(obj + 0xC);
        from[1] = *(f32 *)(obj + 0x10);
        from[2] = *(f32 *)(obj + 0x14);
        timer6 = *(s16 *)(st + 6);
        if (arg1 >= timer6) {
            step = timer6;
            *(s16 *)(st + 6) = 0;
        } else {
            step = arg1;
            *(s16 *)(st + 6) = (s16)(timer6 - arg1);
        }
        if (*(s32 *)(obj + 0x88) == 0) {
            *(s16 *)(obj + 2) = (s16)(*(s16 *)(obj + 2) + (arg1 << 10));
            *(s16 *)(obj + 0) = (s16)(*(s16 *)(obj + 0) + (arg1 << 11));
        }
        fstep = (f32)step;
        if (*(s32 *)(obj + 0x88) != 0) {
            spE8 = Powerf(D_overlay_112_0700140C, step);
            *(f32 *)(obj + 0x1C) = *(f32 *)(obj + 0x1C) * spE8;
            hpow = *(f32 *)(obj + 0x20);
            *(f32 *)(obj + 0x20) = (Powerf(D_overlay_112_07001410, step) * (D_overlay_112_07001414 - hpow)) + hpow;
            *(f32 *)(obj + 0x24) = *(f32 *)(obj + 0x24) * spE8;
            vy = *(f32 *)(obj + 0x20) * fstep;
        } else {
            vy = (*(f32 *)(obj + 0x20) * fstep) + (D_overlay_112_07001418 * fstep * fstep);
            *(f32 *)(obj + 0x20) = *(f32 *)(obj + 0x20) + (D_overlay_112_0700141C * fstep);
        }
        vx = *(f32 *)(obj + 0x1C) * fstep;
        vz = *(f32 *)(obj + 0x24) * fstep;
        objMoveXYZ(arg0, vx, vy, vz);

        // Floor bounce (only while obj->unk88 == 0)
        if (*(s32 *)(obj + 0x88) == 0) {
            if (trackPolyHeight(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x14), &floorY, 0x2000) & 0x2000) {
                if (*(f32 *)(obj + 0x10) < floorY) {
                    *(s32 *)(obj + 0x88) = 8;
                    savedY = *(f32 *)(obj + 0x10);
                    savedUnk2 = *(s16 *)(obj + 2);
                    *(s16 *)(obj + 2) = 0;
                    *(s32 *)(obj + 0x84) = 6;
                    *(f32 *)(obj + 0x10) = floorY;
                    partUpdateTriggers(arg0, 2, obj + 0xC);
                    amSndPlayXYZ(0x9E, *(f32 *)(obj + 0xC), floorY, *(f32 *)(obj + 0x14), 4, NULL);
                    *(f32 *)(obj + 0x10) = savedY;
                    *(s16 *)(obj + 2) = savedUnk2;
                }
            }
        }

        if (trackNearestIntersection(arg0, from, obj + 0xC, &hit, 0x2000, 0) != 0) {
            objMoveXYZ(arg0, hit.hitX - *(f32 *)(obj + 0xC), hit.hitY - *(f32 *)(obj + 0x10),
                       hit.hitZ - *(f32 *)(obj + 0x14));
            if (hit.surface == 3) {
                *(f32 *)(obj + 0x1C) = hit.nx * 8.0f;
                *(f32 *)(obj + 0x20) = hit.ny;
                *(f32 *)(obj + 0x24) = hit.nz * 8.0f;
            } else {
                kind = st[0];
                if (kind == 0) {
                    st[1] = 1;
                } else if (kind == 1) {
                    if (*(s8 *)(st + 3) != 0) {
                        st[1] = 3;
                    } else {
                        st[1] = 5;
                    }
                } else {
                    st[1] = 4;
                }
                *(void **)(st + 0xA4) = hit.obj;
                if (hit.obj != NULL) {
                    hitModel = *(u8 **)((u8 *)hit.obj + 0x5C);
                    matrix_SCL_RPY_XYZ(arg0, mtx98);
                    mathMtxCatF(mtx98, hitModel + (hitModel[0x12B] << 6), st + 8);
                    matrixTransposeVectorMultiply(hitModel + (hitModel[0x12B] << 6) + 0x80, &hit.nx,
                                                  (f32 *)(st + 0x88));
                } else {
                    *(f32 *)(st + 0x88) = hit.nx;
                    *(f32 *)(st + 0x8C) = hit.ny;
                    *(f32 *)(st + 0x90) = hit.nz;
                    *(f32 *)(st + 0x94) = hit.w;
                }
                *(s16 *)(st + 0x98) = 1;
            }
        } else if (*(s16 *)(st + 6) == 0) {
            st[1] = 5;
        }
        *(s32 *)(obj + 0x84) = *(s32 *)(obj + 0x88) | 1;
        // asm: a2 is not set for this call site
        ((void (*)(void *, s32))partUpdateTriggers)(arg0, arg1);
        break;

    case 1:
    case 2:
        list = objGetObjList(&start, &end);
        st[5] = (u8)(st[5] + (arg1 * 4));
        found = 0;
        if (start < end) {
            cur = list + start;
            do {
                other = (u8 *)*cur;
                start += 1;
                otherId = *(s16 *)(other + 0x48);
                cur += 1;
                if (otherId == 1 || otherId == 0x18 || otherId == 0x4D) {
                    dx = *(f32 *)(other + 0xC) - *(f32 *)(obj + 0xC);
                    dy = *(f32 *)(other + 0x10) - *(f32 *)(obj + 0x10);
                    dz = *(f32 *)(other + 0x14) - *(f32 *)(obj + 0x14);
                    if (((dx * dx) + (dy * dy) + (dz * dz)) < 6400.0f) {
                        found = 1;
                    }
                }
            } while (start < end && found == 0);
        }
        if (st[1] == 1 && found == 0) {
            amSndPlayXYZ(0xCD, *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14), 4, NULL);
            st[1] = 2;
        } else if (st[1] == 2) {
            objAnimDframe(arg0, 0x3C88CE70, (f32)arg1, found);   // 0x3C88CE70: float bits passed as int
            if (found != 0) {
                st[1] = 5;
            } else {
                snd = *(void **)(st + 0xA8);
                if (snd == NULL) {
                    st[0xAC] = 1;
                } else {
                    amSndSetXYZ(snd, *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14));
                }
            }
        }
        break;

    case 3:
        *(s8 *)(st + 2) = (s8)(*(s8 *)(st + 2) - arg1);
        if (*(s8 *)(st + 2) <= 0) {
            *(s8 *)(st + 3) = (s8)(*(s8 *)(st + 3) - 1);
            if (*(s8 *)(st + 3) != 0) {
                amSndPlayXYZ(0xD0, *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14), 4, NULL);
                *(s8 *)(st + 2) = (s8)(*(s8 *)(st + 2) + 0x3C);
            } else {
                st[1] = 5;
            }
        }
        break;

    case 4:
        if (*(void **)(st + 0x9C) == NULL) {
            st[1] = 5;
        } else {
            *(s8 *)(st + 2) = (s8)(*(s8 *)(st + 2) - arg1);
            if (*(s8 *)(st + 2) <= 0) {
                amSndPlayXYZ(0xCF, *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14), 4, NULL);
                *(s8 *)(st + 2) = (s8)(*(s8 *)(st + 2) + 0x3C);
            }
        }
        break;

    case 5:
        if (st[0] == 2) {
            ptr = *(u8 **)(st + 0x9C);
            if (ptr != NULL && *(s16 *)(ptr + 0x48) == 1) {
                racer = *(u8 **)(ptr + 0x68);
                if (obj == *(u8 **)(racer + 0x1A0)) {
                    *(void **)(racer + 0x1A0) = NULL;
                }
            }
        }
        snd = *(void **)(st + 0xA8);
        if (snd != NULL) {
            amSndStopXYZ(snd);
        }
        st[0xAC] = 0;
        v1 = trackPolyHeight(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x14), &spFC, 0x2000);
        if ((v1 & 0x2000) && (*(f32 *)(obj + 0x10) < spFC)) {
            spFC = spFC - *(f32 *)(obj + 0x10);
            if (spFC < 10.0f) {
                v1 = 0;
            }
        } else {
            v1 = 0;
        }
        var_t0 = *(void **)(st + 0xA0);
        if (var_t0 != NULL && *(s16 *)((u8 *)var_t0 + 0x48) != 1) {
            var_t0 = NULL;
        }
        if (v1 & 0x2000) {
            explosionStart(6, (s16)(s32)*(f32 *)(obj + 0xC), (s16)(s32)*(f32 *)(obj + 0x10),
                           (s16)(s32)*(f32 *)(obj + 0x14), D_overlay_112_070013E4[st[0]], var_t0);
        } else {
            hitObj = *(void **)(st + 0xA4);
            if (hitObj != NULL) {
                hitModel = *(u8 **)((u8 *)hitObj + 0x5C);
                matrixTransposeVectorMultiply(hitModel + (hitModel[0x12B] << 6), st + 0x88, spD8);
                vx = spD8[0];
                vy = spD8[1];
                vz = spD8[2];
            } else {
                vx = *(f32 *)(st + 0x88);
                vy = *(f32 *)(st + 0x8C);
                vz = *(f32 *)(st + 0x90);
            }
            spawn.id = 0x13C;
            spawn.x = (s16)(s32)*(f32 *)(obj + 0xC);
            spawn.y = (s16)(s32)*(f32 *)(obj + 0x10);
            spawn.z = (s16)(s32)*(f32 *)(obj + 0x14);
            spawn.yaw = (s16)(Arctanf(vx, vz) + 0x8000);
            spawn.pitch = Arctanf(vy, sqrtf((vx * vx) + (vz * vz)));
            spawn.unk10 = 2;
            spawn.unk11 = D_overlay_112_070013E4[st[0]];
            spawn.unk12 = 0;
            spawn.unk13 = (s8)*(s16 *)(st + 0x98);
            spawn.owner = var_t0;
            created = objSetupObject(&spawn, 1);
            if (created != NULL) {
                *(s32 *)((u8 *)created + 0x3C) = 0;
            }
            // asm: 0x43200000 is the bit pattern of 160.0f in a3
            explosionAddBlast(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14),
                              160.0f, 80.0f, 0.5f, D_overlay_112_070013E4[st[0]], var_t0);
        }
        amSndPlayXYZ(0x22, *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14), 4, NULL);
        squadsAddInterestingEvent(NULL, (s16)(s32)*(f32 *)(obj + 0xC), (s16)(s32)*(f32 *)(obj + 0x10),
                                  (s16)(s32)*(f32 *)(obj + 0x14), 5, 1, 0x96);
        objFreeObject(arg0);
        break;

    case 6:
        st[5] = (u8)(st[5] + (arg1 * 4));
        timer6 = *(s32 *)(obj + 0x8C) - (arg1 * 0x10);
        *(s32 *)(obj + 0x8C) = timer6;
        if (timer6 <= 0) {
            *(s32 *)(obj + 0x8C) = 0;
            objFreeObject(arg0);
        }
        break;
    }

    // Matrix and light update for the attached model
    hitObj = *(void **)(st + 0xA4);
    if (hitObj != NULL && *(s16 *)((u8 *)hitObj + 0x48) != 0x37) {
        hitModel = *(u8 **)((u8 *)hitObj + 0x5C);
        mathMtxCatF(st + 8, hitModel + (hitModel[0x12B] << 6) + 0x80, st + 0x48);
    } else {
        matrix_SCL_RPY_XYZ(arg0, (f32 (*)[4])(st + 0x48));
    }

    anim = (u8 *)((void **)(*(void **)(obj + 0x6C)))[*(s8 *)(obj + 0x3A)];
    model = *(u8 **)anim;
    if (*(s8 *)(model + 0x4E) != 0) {
        modGenAnimMatrices(anim, model, arg0, 1.0f, 0.0f);
        lightObject(arg0, anim, *(s32 *)(obj + 0x54),
                    *(void **)(anim + 0x10 + (*(s8 *)(anim + 0xB) * 4)));
    } else {
        if (model[0x11] != 0) {
            anim[0xB] = (u8)(anim[0xB] ^ 1);
        }
        lightObject(arg0, anim, *(s32 *)(obj + 0x54), st + 0x48);
    }
    if (model[0x11] != 0) {
        objAnimTextures(arg0, model, anim, *(s8 *)(anim + 0xA));
    }
    anim[0xA] = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o112/overlay_112/mineControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mineDraw(Gfx **arg0, MatrixS **arg1, Object *arg2) {
    u8 *obj = (u8 *)arg2;
    u8 *state;
    u8 *entry;
    u8 *texData;
    s16 *cam;
    ObjectTransform trans;
    Gfx *g;
    f32 fade;
    f32 scale;
    s32 alpha;
    u8 mode;

    runlinkSetDestructTimer(__MODULE00112, 2, 2);
    state = *(u8 **)(obj + 0x68);
    if (state[0] == 0 && (s32) state[5] < 0x80) {
        cam = camGetPtr();
        entry = *(u8 **)(*(u8 **)(obj + 0x6C) + 4);
        if (entry != NULL) {
            texData = *(u8 **)entry;
            fade = 1.0f - ((f32) state[5] / 127.0f);
            fade = 1.0f - (fade * fade);
            scale = fade * (80.0f / (f32) *(s16 *)(entry + 0x8C));
            alpha = 0x80 - state[5];
            if (alpha >= 0x41) {
                alpha = 0x40;
            }
            mode = state[1];

            g = *arg0;
            *arg0 = g + 1;
            g->words.w1 = -1U;
            g->words.w0 = 0xFB000000;

            g = *arg0;
            *arg0 = g + 1;
            if ((mode != 2) && (mode != 5)) {
                g->words.w1 = ((s32) (*(s32 *)(obj + 0x8C) * alpha) >> 8 & 0xFF) | 0xFF0000;
                g->words.w0 = 0xFA000000;
            } else {
                g->words.w1 = ((s32) (*(s32 *)(obj + 0x8C) * alpha) >> 8 & 0xFF) | 0xFF000000;
                g->words.w0 = 0xFA000000;
            }

            trans.y_rotation = (s16) (-0x8000 - *cam);
            trans.x_rotation = 0;
            trans.z_rotation = 0;
            camPushModelMtx(arg0, arg1, &trans, 1.0f, 0.0f);

            g = *arg0;
            *arg0 = g + 1;
            g->words.w0 = 0xBF000000;
            g->words.w1 = (u32) *(s32 *)(entry + 4) + 0x80000000;

            g = *arg0;
            *arg0 = g + 1;
            g->words.w0 = 0x02000050;
            g->words.w1 = (u32) &D_1000A0838;

            g = *arg0;
            *arg0 = g + 1;
            g->words.w0 = 0x06000000;
            g->words.w1 = (u32) *(s32 *)(texData + 0x78) + 0x80000000;
            texDPInit(arg0);

            trans.y_rotation = (s16) (-0x8000 - *cam);
            trans.x_rotation = 0x4000;
            trans.z_rotation = 0;
            camPushModelMtx(arg0, arg1, &trans, 1.0f, 0.0f);

            g = *arg0;
            *arg0 = g + 1;
            g->words.w0 = 0xBF000000;
            g->words.w1 = (u32) *(s32 *)(entry + 4) + 0x80000000;

            g = *arg0;
            *arg0 = g + 1;
            g->words.w0 = 0x02000050;
            g->words.w1 = (u32) &D_1000A0838;

            g = *arg0;
            *arg0 = g + 1;
            g->words.w0 = 0x06000000;
            g->words.w1 = (u32) *(s32 *)(texData + 0x78) + 0x80000000;
            texDPInit(arg0);

            g = *arg0;
            *arg0 = g + 1;
            g->words.w1 = 0;
            g->words.w0 = 0xBF000000;
            camRestoreModelMtx(arg0);
            texDPInit(arg0);

            g = *arg0;
            *arg0 = g + 1;
            g->words.w1 = -1U;
            g->words.w0 = 0xFA000000;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o112/overlay_112/mineDraw.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void minePushMtx(void **arg0, void **arg1, Object *arg2) {
    u8 *state = *(u8 **)((u8 *)arg2 + 0x68);

    camPushFloatModelMtx(arg0, arg1, (f32 (*)[4])(state + 0x48));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o112/overlay_112/minePushMtx.s")
#endif
