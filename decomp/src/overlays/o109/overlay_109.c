#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern u8 D_overlay_109_06D00B94[];
extern u8 D_overlay_109_06D00BA4[];
extern u8 D_overlay_109_06D00BB4[];
extern void *D_overlay_109_06D00C04;
extern void *D_overlay_109_06D00C08;
extern void *D_overlay_109_06D00C0C;
void mathOneFloatPY(void *obj);
void hitInitObjectHit(void *arg0, s16 arg1, s8 arg2, s8 arg3, s16 arg4, s16 arg5, s16 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, u16 arg11);
void amSndStopXYZ(void *soundMask);
/* asm passes some float args as raw GPR words; prototypes follow codebase convention */
void amSndPlayXYZ(u16 soundId, f32 x, f32 y, f32 z, s32 arg4, void **soundMask);
void objMoveXYZ(void *obj, f32 dx, f32 dy, f32 dz);
void objFreeObject(void *obj);
void **objGetPlayerlist(s32 *count);
void *objSetupObject(void *params, s32 arg1, s32 owner);
void squadsAddInterestingEvent(void *arg0, s16 x, s16 y, s16 z, s32 a, s32 b, s32 c);
s32 trackLightAdd(f32 x, f32 y, f32 z, f32 a, f32 b, s32 r, s32 g, s32 bl);
void trackLightDelete(s32 light);
s32 trackNearestIntersection(void *obj, void *from, void *to, void *out, s32 mask, s32 c);
void partUpdateTriggers(void *obj, s32 arg1);
void runlinkSetDestructTimer(s32 module, s32 time, s32 kind);
extern s32 __MODULE00109;
extern s16 D_overlay_109_06D00BC4[];
extern s16 D_overlay_109_06D00BE4[];
extern f32 D_overlay_109_06D00C10;
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void laserboltInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *spawn = (u8 *)arg1;
    u8 *st = *(u8 **)(obj + 0x68);
    u8 **table;
    u8 *ent;
    s16 base;
    s16 base2;
    s32 hitBits;
    s8 idx;

    *(f32 *)(obj + 0x1C) = 0.0f;
    *(f32 *)(obj + 0x20) = 0.0f;
    *(f32 *)(obj + 0x24) = -*(f32 *)(spawn + 0x14);
    *(s16 *)(obj + 0x0) = *(s16 *)(spawn + 0xC);
    *(s16 *)(obj + 0x4) = 0;
    *(s16 *)(obj + 0x2) = *(s16 *)(spawn + 0xE);
    mathOneFloatPY(obj + 0x1C);

    *(s8 *)(obj + 0x3A) = (s8)(spawn[0xA] >> 2);
    if (*(s8 *)(obj + 0x3A) >= *(s8 *)(*(u8 **)(obj + 0x40) + 0x1F)) {
        *(s8 *)(obj + 0x3A) = (s8)(*(s8 *)(*(u8 **)(obj + 0x40) + 0x1F) - 1);
    }
    table = *(u8 ***)(obj + 0x6C);
    ent = table[*(s8 *)(obj + 0x3A)];
    base = (s16)((ent[0] - 1) << 5);
    base2 = (s16)((ent[1] - 1) << 5);

    st[0x00] = 0x40;
    st[0x01] = 0;
    *(s16 *)(st + 0x04) = base;
    *(s16 *)(st + 0x06) = 0;
    st[0x02] = 1;
    *(s16 *)(st + 0x08) = base;
    *(s16 *)(st + 0x0A) = base2;
    st[0x03] = 2;
    *(s16 *)(st + 0x0C) = 0;
    *(s16 *)(st + 0x0E) = 0;
    st[0x10] = 0x40;
    st[0x11] = 1;
    *(s16 *)(st + 0x14) = base;
    *(s16 *)(st + 0x16) = base2;
    st[0x12] = 2;
    *(s16 *)(st + 0x18) = 0;
    *(s16 *)(st + 0x1A) = 0;
    st[0x13] = 3;
    *(s16 *)(st + 0x1C) = 0;
    *(s16 *)(st + 0x1E) = base2;
    st[0x60] = 0;
    st[0x61] = spawn[0xA];
    st[0x62] = spawn[0x10];
    st[0x63] = spawn[0x11];
    *(f32 *)(st + 0x64) = *(f32 *)(spawn + 0x14);
    *(s16 *)(st + 0x6A) = (s16)(spawn[0xB] * 6);
    *(s32 *)(st + 0x70) = *(s32 *)(spawn + 0x18);
    *(s32 *)(st + 0x74) = *(s32 *)(spawn + 0x1C);
    *(s32 *)(st + 0x78) = *(s32 *)(spawn + 0x20);
    *(s8 *)(st + 0x7C) = *(s8 *)(spawn + 0x12);
    st[0x7D] = 0;
    if (st[0x62] >= 5) {
        st[0x62] = 4;
    }

    if (spawn[0xA] == 0) {
        *(f32 *)(st + 0x6C) = 2.5f;
        hitBits = 0x40;
        *(s32 *)(obj + 0x8C) = (s32)0xFFC01000;
    } else {
        *(f32 *)(st + 0x6C) = *(f32 *)(D_overlay_109_06D00BB4 + (((spawn[0xA] - 1) & 3) * 4));
        hitBits = spawn[0xA] << 8;
        *(s32 *)(obj + 0x8C) = *(s32 *)(D_overlay_109_06D00BA4 + (((spawn[0xA] - 1) & 3) * 4));
    }
    hitInitObjectHit(obj, (s16)hitBits, 1, 4, 0, 0, 0, 4.0f, 4.0f, 100.0f, 1.0f, 0x11);
    *(s32 *)(obj + 0x88) = 0;
    idx = *(s8 *)(spawn + 0x13);
    if (idx >= 0 && idx < 4) {
        *(s32 *)(obj + 0x8C) = *(s32 *)(D_overlay_109_06D00B94 + idx * 4);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o109/overlay_109/laserboltInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void laserboltControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *st;
    u8 isect[0x28];  /* hit record written by trackNearestIntersection (asm sp+0xD4) */
    u8 spawn[0x24];  /* spawn record passed to objSetupObject (asm sp+0x7C) */
    f32 dt;
    s32 keepAlive = 1; /* asm sp+0xC4: object is freed at the end while still 1 */
    s32 hit;
    s32 i;
    s32 count;
    s32 yaw;
    s32 pitch;
    s32 life;
    s32 lvl;
    s32 col;
    u16 sfx;
    void **players;
    s16 *tblA;
    s16 *tblB;
    void *spawned;
    u8 *player;
    f32 vx, vy, vz, nx, ny, nz, dot, k;
    f32 rx, ry, rz;
    f32 dx, dy, dz;

    runlinkSetDestructTimer(__MODULE00109, 0x1F4, 2);
    st = *(u8 **)(obj + 0x68);
    dt = (f32)arg1;
    if (*(s32 *)(obj + 0x88) != 0) {
        trackLightDelete(*(s32 *)(obj + 0x88));
        *(s32 *)(obj + 0x88) = 0;
    }
    *(s16 *)(st + 0x6A) = (s16)(*(s16 *)(st + 0x6A) - arg1);
    if (*(s16 *)(st + 0x6A) > 0 && *(s16 *)(*(u8 **)(obj + 0x4C) + 0x6) > 0) {
        if (st[0x60] == 0) {
            objMoveXYZ(obj, *(f32 *)(obj + 0x1C) * dt, *(f32 *)(obj + 0x20) * dt, *(f32 *)(obj + 0x24) * dt);
            *(f32 *)(st + 0x80) = *(f32 *)(st + 0x80) + *(f32 *)(st + 0x64) * dt;
            if (*(s16 *)(*(u8 **)(st + 0x70) + 0x48) == 1) {
                squadsAddInterestingEvent(obj, (s16)*(f32 *)(obj + 0x0C), (s16)*(f32 *)(obj + 0x10),
                                          (s16)*(f32 *)(obj + 0x14), 4, 1, 0);
            } else if (*(s16 *)(*(u8 **)(st + 0x70) + 0x48) == 0x18 && st[0x7D] == 0
                       && D_overlay_109_06D00C08 == NULL && *(f32 *)(st + 0x80) > 900.0f) {
                /* homing: the first player inside the radius locks the sound and the flag */
                players = objGetPlayerlist(&count);
                if (count > 0) {
                    for (i = 0; i < count; i++) {
                        player = (u8 *)players[i];
                        dx = *(f32 *)(obj + 0x0C) - *(f32 *)(player + 0x0C);
                        dy = *(f32 *)(obj + 0x10) - *(f32 *)(player + 0x10);
                        dz = *(f32 *)(obj + 0x14) - *(f32 *)(player + 0x14);
                        if ((dx * dx + dy * dy + dz * dz) < D_overlay_109_06D00C10) {
                            amSndPlayXYZ((u16)(mathRnd(0x219, 0x21B) & 0xFFFF), *(f32 *)(obj + 0x0C),
                                         *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14), 4, &D_overlay_109_06D00C08);
                            st[0x7D] = 1;
                            D_overlay_109_06D00C0C = obj;
                        }
                    }
                }
            }
            hit = trackNearestIntersection(obj, *(u8 **)(obj + 0x4C) + 0xC, obj + 0xC, isect, 0, 0);
            st[0x60] = (u8)hit;
            if (hit & 0xFF) {
                *(s32 *)(st + 0x5C) = *(s32 *)(isect + 0x24);
                objMoveXYZ(obj, *(f32 *)(isect + 0x04) - *(f32 *)(obj + 0x0C),
                           *(f32 *)(isect + 0x08) - *(f32 *)(obj + 0x10),
                           *(f32 *)(isect + 0x0C) - *(f32 *)(obj + 0x14));
                if (st[0x63] != 0) {
                    if (!(*(s32 *)(st + 0x5C) & 0xA000)) {
                        /* bounce: reflect the velocity about the hit normal (-2 * dot) */
                        vx = *(f32 *)(obj + 0x1C);
                        vy = *(f32 *)(obj + 0x20);
                        vz = *(f32 *)(obj + 0x24);
                        nx = *(f32 *)(isect + 0x10);
                        ny = *(f32 *)(isect + 0x14);
                        nz = *(f32 *)(isect + 0x18);
                        dot = nx * vx + ny * vy + nz * vz;
                        k = dot * -2.0f;
                        rx = nx * k + vx;
                        ry = ny * k + vy;
                        rz = nz * k + vz;
                        *(s16 *)(obj + 0x0) = Arctanf(-rx, -rz);
                        *(s16 *)(obj + 0x2) = Arctanf(ry, sqrtf(rx * rx + rz * rz));
                        *(f32 *)(obj + 0x24) = -*(f32 *)(st + 0x64);
                        /* sig mismatch: asm passes (obj, obj + 0x1C) */
                        ((void (*)(void *, void *))mathOneFloatPY)(obj, obj + 0x1C);
                        st[0x60] = 0;
                    }
                } else if (st[0x62] != 0) {
                    /* spawn a fan of projectiles around the hit normal */
                    *(s16 *)(spawn + 0x00) = 0x50;
                    spawn[0x02] = 0x24;
                    spawn[0x03] = 0;
                    *(s16 *)(spawn + 0x04) = (s16)*(f32 *)(obj + 0x0C);
                    *(s16 *)(spawn + 0x06) = (s16)*(f32 *)(obj + 0x10);
                    *(s16 *)(spawn + 0x08) = (s16)*(f32 *)(obj + 0x14);
                    spawn[0x0A] = st[0x61];
                    life = (s16)*(s16 *)(st + 0x6A) / 6;
                    spawn[0x0B] = (s8)life;
                    if ((u8)life == 0) {
                        spawn[0x0B] = 1;
                    }
                    *(f32 *)(spawn + 0x14) = *(f32 *)(st + 0x64);
                    *(s32 *)(spawn + 0x18) = *(s32 *)(st + 0x70);
                    *(s32 *)(spawn + 0x1C) = *(s32 *)(st + 0x74);
                    *(s32 *)(spawn + 0x20) = *(s32 *)(st + 0x78);
                    spawn[0x11] = st[0x63];
                    nx = *(f32 *)(isect + 0x10);
                    ny = *(f32 *)(isect + 0x14);
                    nz = *(f32 *)(isect + 0x18);
                    yaw = Arctanf(-nx, -nz);
                    pitch = Arctanf(ny, sqrtf(nz * nz + nx * nx));
                    if (spawn[0x0A] >= 2) {
                        spawn[0x0A] = (u8)(spawn[0x0A] >> 1);
                    }
                    spawn[0x10] = (u8)(st[0x62] - 1);
                    count = st[0x62];
                    if (count != 0) {
                        /* tables are read from byte offset count * 8 (asm: sll 2, sll 1) */
                        tblA = (s16 *)((u8 *)D_overlay_109_06D00BC4 + count * 8);
                        tblB = (s16 *)((u8 *)D_overlay_109_06D00BE4 + count * 8);
                        for (i = count; i != 0; i--) {
                            *(s16 *)(spawn + 0x0C) = (s16)(*tblA + yaw);
                            *(s16 *)(spawn + 0x0E) = (s16)(*tblB + pitch);
                            tblA += 1;
                            tblB += 1;
                            spawned = objSetupObject(spawn, 1, pitch);
                            if (spawned != NULL) {
                                *(s32 *)((u8 *)spawned + 0x3C) = 0;
                            }
                        }
                    }
                }
                col = *(s32 *)(obj + 0x8C);
                *(s32 *)(obj + 0x88) = trackLightAdd(*(f32 *)(obj + 0x0C), *(f32 *)(obj + 0x10),
                                                     *(f32 *)(obj + 0x14), 200.0f, 100.0f,
                                                     (col >> 24) & 0xFF, (col >> 16) & 0xFF, (col >> 8) & 0xFF);
            }
            dx = *(f32 *)(obj + 0x0C) - *(f32 *)(*(u8 **)(obj + 0x4C) + 0x0C);
            dy = *(f32 *)(obj + 0x10) - *(f32 *)(*(u8 **)(obj + 0x4C) + 0x10);
            dz = *(f32 *)(obj + 0x14) - *(f32 *)(*(u8 **)(obj + 0x4C) + 0x14);
            *(f32 *)(obj + 0x34) = sqrtf(dx * dx + dy * dy + dz * dz);
            keepAlive = 0;
        } else {
            /* already hit last frame: impact sound, then parts/trigger */
            lvl = 2;
            if (*(s32 *)(st + 0x5C) & 0x2000) {
                *(s16 *)(obj + 0x2) = 0;
            } else {
                lvl = *(u8 *)((u8 *)levelGetLevel() + 0xE2);
            }
            if (lvl != 0xFF) {
                if (*(s32 *)(st + 0x78) != 0) {
                    if (D_overlay_109_06D00C04 != NULL) {
                        amSndStopXYZ(D_overlay_109_06D00C04);
                    }
                    sfx = ((u16 *)*(u8 **)(st + 0x78))[lvl];
                    amSndPlayXYZ(sfx, *(f32 *)(obj + 0x0C), *(f32 *)(obj + 0x10),
                                 *(f32 *)(obj + 0x14), 4, &D_overlay_109_06D00C04);
                    squadsAddInterestingEvent(NULL, (s16)*(f32 *)(obj + 0x0C), (s16)*(f32 *)(obj + 0x10),
                                              (s16)*(f32 *)(obj + 0x14), 1, 1, sfx);
                }
                if (*(s32 *)(st + 0x74) != 0 && arg1 < 5) {
                    *(s16 *)(obj + 0x2) = 0;
                    *(s32 *)(obj + 0x84) = ((s32 *)*(u8 **)(st + 0x74))[lvl];
                    partUpdateTriggers(obj, 2);
                }
            }
        }
    }
    if (keepAlive != 0) {
        objFreeObject(obj);
    } else if (D_overlay_109_06D00C08 != NULL && obj == (u8 *)D_overlay_109_06D00C0C) {
        /* sig mismatch: header declares f32 position args, asm passes raw float words */
        ((void (*)(void *, s32, s32, s32))amSndSetXYZ)(D_overlay_109_06D00C08, *(s32 *)(obj + 0x0C),
                                                      *(s32 *)(obj + 0x10), *(s32 *)(obj + 0x14));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o109/overlay_109/laserboltControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void _AutoExit00109(void) {
    if (D_overlay_109_06D00C04 != NULL) {
        amSndStopXYZ(D_overlay_109_06D00C04);
    }
    if (D_overlay_109_06D00C08 != NULL) {
        amSndStopXYZ(D_overlay_109_06D00C08);
    }
    D_overlay_109_06D00C0C = NULL;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o109/overlay_109/_AutoExit00109.s")
#endif
