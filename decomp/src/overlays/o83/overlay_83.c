#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
void mathOneFloatPY(void *obj);
void hitInitObjectHit(void *obj, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, f32 f0, f32 f1, f32 f2, f32 f3, s32 a11);
s32 trackGetIntersect(void *a0, void *a1, void *a2, s32 a3, s32 a4, void *a5);
void trackMakePolylist(s32 a0, void *a1, void *a2, void *a3, s32 a4, s32 a5, s32 a6);
void runlinkSetDestructTimer(s32 a0, s32 a1, s32 a2);
s32 trackPolyHeight(f32 x, f32 z, f32 *height, s32 flags);
f32 Powerf(f32 base, s32 n);
s32 mathSin(s32 angle);
void *objSetupObject(void *params, s32 arg1);
void objFreeObject(void *obj);
s32 objMoveXYZ(void *obj, f32 dx, f32 dy, f32 dz);
s32 objAnimDframe(void *obj, f32 rate, f32 dframe);
void partUpdateTriggers(void *obj, s32 arg1);
void amSndPlayXYZ(u16 soundId, f32 x, f32 y, f32 z, u8 arg4, void *soundMask);
void explosionStart(s16 a0, s16 a1, s16 a2, s16 a3, s32 a4, void *owner);
extern s32 __MODULE00083;
extern u8 multiPlayerGame;
extern f32 D_overlay_83_0530122C;
extern f32 D_overlay_83_05301230;
extern f32 D_overlay_83_05301234;
extern f32 D_overlay_83_05301238;
extern f32 D_overlay_83_0530123C;
extern f32 D_overlay_83_05301240;
extern f32 D_overlay_83_05301244;
extern f32 D_overlay_83_05301248;
extern f32 D_overlay_83_0530124C;
extern f32 D_overlay_83_05301210;
extern f32 D_overlay_83_05301214;
extern f32 D_overlay_83_05301218;
extern f32 D_overlay_83_0530121C;
extern f32 D_overlay_83_05301220;
extern f32 D_overlay_83_05301224;
extern f32 D_overlay_83_05301228;
f32 sqrtf(f32 x);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainclusterInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *def = (u8 *)arg1;
    f32 lo[3];
    f32 hi[3];
    s32 radius;
    f32 hitOut[3];

    *(f32 *)(obj + 0x24) = -1.0f;
    *(s16 *)(obj + 0x0) = *(s16 *)(def + 0xC);
    *(s16 *)(obj + 0x4) = 0;
    *(s16 *)(obj + 0x2) = *(s16 *)(def + 0xE);
    mathOneFloatPY(obj + 0x1C);
    lo[0] = *(f32 *)(obj + 0xC) - (*(f32 *)(obj + 0x1C) * 16.0f);
    lo[1] = *(f32 *)(obj + 0x10) - (*(f32 *)(obj + 0x20) * 16.0f);
    lo[2] = *(f32 *)(obj + 0x14) - (*(f32 *)(obj + 0x24) * 16.0f);
    hi[0] = *(f32 *)(obj + 0xC) + (*(f32 *)(obj + 0x1C) * 16.0f);
    hi[1] = *(f32 *)(obj + 0x10) + (*(f32 *)(obj + 0x20) * 16.0f);
    radius = 0x41000000; /* 8.0f bits */
    hi[2] = *(f32 *)(obj + 0x14) + (*(f32 *)(obj + 0x24) * 16.0f);
    trackMakePolylist(1, lo, hi, &radius, 0, 0, 0);
    if (trackGetIntersect(0, lo, hi, radius, 1, hitOut) != 0) {
        *(f32 *)(obj + 0xC) = hi[0];
        *(f32 *)(obj + 0x10) = hi[1];
        *(f32 *)(obj + 0x14) = hi[2];
    }
    *(f32 *)(obj + 0x1C) = *(f32 *)(obj + 0x1C) * *(f32 *)(def + 0x10);
    *(f32 *)(obj + 0x20) = *(f32 *)(obj + 0x20) * *(f32 *)(def + 0x10);
    *(f32 *)(obj + 0x24) = *(f32 *)(obj + 0x24) * *(f32 *)(def + 0x10);
    *(s16 *)(obj + 0x88) = 0;
    *(s16 *)(obj + 0x8A) = *(s16 *)(def + 0xA);
    *(s32 *)(obj + 0x8C) = *(s32 *)(def + 0x14);
    hitInitObjectHit(arg0, 0x1800, 1, 4, 0, 0, 0, 8.0f, 8.0f, -1.0f, 1.0f, 0x11);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o83/overlay_83/mainclusterInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void mainclusterControl(void *arg0, s32 arg1) {
    typedef void (*AmSndBitsFn)(s32, s32, s32, s32, s32, void *);
    u8 *obj = (u8 *)arg0;
    f32 posLo[3];            /* sp+0xBC: copy of obj position taken at entry */
    f32 hitOut[4];           /* sp+0x88: trackGetIntersect output, [1..3] used */
    f32 hiY;                 /* sp+0xCC: ground height from trackPolyHeight */
    f32 *posSel;             /* sp+0xB8 */
    f32 factor;              /* sp+0xB0: Powerf(0.875f, steps) */
    f32 dt;                  /* sp+0xB4: (f32)steps */
    f32 vy;                  /* obj+0x20 before update */
    f32 dy;                  /* objMoveXYZ dy */
    f32 oldY;               /* obj+0x10 before ground snap */
    f32 scale;               /* D_overlay_83_05301220 */
    s32 radius;              /* sp+0xC8: 8.0f bits */
    s32 hitMode;             /* sp+0xDC: 0 none, 1 posSel fallback, 2 trackGetIntersect hit */
    s32 steps;
    s32 i;
    s16 savedField2;
    s16 angle;
    s16 pitch;
    void *owner;
    void *spawned;
    u32 setupBuf[6];         /* object setup record at sp+0x54 (raw offsets) */
    u8 *setup = (u8 *)setupBuf;

    runlinkSetDestructTimer(__MODULE00083, 2, 2);
    hitMode = 0;
    *(s32 *)(obj + 0x84) = 0;
    radius = 0x41000000; /* 8.0f bits */
    posLo[0] = *(f32 *)(obj + 0xC);
    posLo[1] = *(f32 *)(obj + 0x10);
    posLo[2] = *(f32 *)(obj + 0x14);
    steps = arg1;
    if (*(s16 *)(obj + 0x8A) < steps) {
        steps = *(s16 *)(obj + 0x8A);
    }
    dt = (f32)steps;
    if (*(s16 *)(obj + 0x88) & 1) {
        factor = Powerf(0.875f, steps);
        *(f32 *)(obj + 0x1C) = *(f32 *)(obj + 0x1C) * factor;
        vy = *(f32 *)(obj + 0x20);
        *(f32 *)(obj + 0x20) = (Powerf(D_overlay_83_05301210, steps) * (D_overlay_83_05301214 - vy)) + vy;
        dy = *(f32 *)(obj + 0x20) * dt;
        *(f32 *)(obj + 0x24) = *(f32 *)(obj + 0x24) * factor;
    } else {
        vy = *(f32 *)(obj + 0x20);
        dy = (vy * dt) + (D_overlay_83_05301218 * dt * dt);
        *(f32 *)(obj + 0x20) = vy + (D_overlay_83_0530121C * dt);
    }
    objMoveXYZ(obj, *(f32 *)(obj + 0x1C) * dt, dy, *(f32 *)(obj + 0x24) * dt);
    if (trackPolyHeight(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x14), &hiY, 0x2000) & 0x2000) {
        oldY = *(f32 *)(obj + 0x10);
        if (oldY < hiY) {
            if (!(*(s16 *)(obj + 0x88) & 1)) {
                savedField2 = *(s16 *)(obj + 0x2);
                *(s16 *)(obj + 0x2) = 0;
                *(s32 *)(obj + 0x84) = *(s32 *)(obj + 0x84) | 1;
                *(f32 *)(obj + 0x10) = hiY;
                partUpdateTriggers(obj, 2);
                *(s16 *)(obj + 0x2) = savedField2;
                *(f32 *)(obj + 0x10) = oldY;
                /* sig mismatch: asm passes the f32 position values as raw words in a1..a3 */
                ((AmSndBitsFn)amSndPlayXYZ)(0xD, *(s32 *)(obj + 0xC), *(s32 *)&oldY, *(s32 *)(obj + 0x14), 4, NULL);
                *(s16 *)(obj + 0x88) = (s16)(*(s16 *)(obj + 0x88) | 1);
            } else if ((hiY - oldY) > 16.0f) {
                *(s32 *)(obj + 0x84) = *(s32 *)(obj + 0x84) | 2;
                partUpdateTriggers(obj, 2);
            }
        }
    }
    trackMakePolylist(1, posLo, obj + 0xC, &radius, 0xCE002000, 0, 0);
    if (trackGetIntersect(arg0, posLo, obj + 0xC, radius, 1, hitOut) != 0) {
        hitMode = 2;
        posSel = (f32 *)(obj + 0xC);
    } else if (*(s16 *)(*(u8 **)(obj + 0x4C) + 0x6) != 0x1800) {
        posSel = posLo;
        hitMode = 1;
    } else {
        *(s16 *)(obj + 0x8A) = (s16)(*(s16 *)(obj + 0x8A) - arg1);
        if (*(s16 *)(obj + 0x8A) <= 0) {
            posSel = (f32 *)(obj + 0xC);
            hitMode = 1;
        }
    }
    if (hitMode != 0) {
        owner = *(void **)(obj + 0x8C);
        if ((owner != NULL) && (*(s16 *)((u8 *)owner + 0x48) != 1)) {
            owner = NULL;
        }
        if (*(s16 *)(obj + 0x88) & 1) {
            explosionStart(6, (s16)(s32)posSel[0], (s16)(s32)posSel[1], (s16)(s32)posSel[2], 0xE, owner);
        } else {
            explosionStart(7, (s16)(s32)posSel[0], (s16)(s32)posSel[1], (s16)(s32)posSel[2], 0xE, owner);
            *(s16 *)(setup + 0x00) = 0x136;
            *(s16 *)(setup + 0x04) = (s16)(s32)posSel[0];
            *(s16 *)(setup + 0x06) = (s16)(s32)posSel[1];
            *(s16 *)(setup + 0x08) = (s16)(s32)posSel[2];
            *(s16 *)(setup + 0x0A) = 0x12C;
            *(void **)(setup + 0x14) = *(void **)(obj + 0x8C);
            scale = D_overlay_83_05301220;
            i = 0;
            do {
                if (hitMode == 2) {
                    if (D_overlay_83_05301224 <= hitOut[2]) {
                        *(s16 *)(setup + 0x0C) = (s16)(i * 0x5555);
                        *(s16 *)(setup + 0x0E) = (s16)mathRnd(0x3400, 0x3800);
                        *(f32 *)(setup + 0x10) = (f32)mathRnd(0x41, 0x4B) * scale;
                    } else if (hitOut[2] <= D_overlay_83_05301228) {
                        *(s16 *)(setup + 0x0C) = (s16)(i * 0x5555);
                        *(s16 *)(setup + 0x0E) = (s16)mathRnd(-0x3800, -0x3400);
                        *(f32 *)(setup + 0x10) = (f32)mathRnd(0x14, 0x1E) * scale;
                    } else {
                        angle = (s16)(Arctanf(hitOut[1], hitOut[3]) + 0x8000);
                        *(s16 *)(setup + 0x0C) = (s16)(mathRnd(-0x2000, 0x2000) + angle);
                        pitch = (s16)Arctanf(hitOut[2], sqrtf((hitOut[3] * hitOut[3]) + (hitOut[1] * hitOut[1])));
                        *(s16 *)(setup + 0x0E) = (s16)(mathRnd(-0x2000, 0x2000) + pitch);
                        *(f32 *)(setup + 0x10) = (f32)mathRnd(0x1E, 0x32) * scale;
                    }
                } else {
                    *(s16 *)(setup + 0x0C) = (s16)(i * 0x5555);
                    *(s16 *)(setup + 0x0E) = (s16)mathRnd(0x3400, 0x3800);
                    *(f32 *)(setup + 0x10) = (f32)mathRnd(0x41, 0x4B) * scale;
                }
                spawned = objSetupObject(setup, 1);
                i++;
                if (spawned != NULL) {
                    *(s32 *)((u8 *)spawned + 0x3C) = 0;
                }
            } while (i != 3);
        }
        /* sig mismatch: asm passes the f32 position values as raw words in a1..a3 */
        ((AmSndBitsFn)amSndPlayXYZ)(0x96, *(s32 *)&posSel[0], *(s32 *)&posSel[1], *(s32 *)&posSel[2], 4, NULL);
        objFreeObject(obj);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o83/overlay_83/mainclusterControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void smallclusterInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *def = (u8 *)arg1;

    *(f32 *)(obj + 0x24) = -*(f32 *)(def + 0x10);
    *(s16 *)(obj + 0x0) = *(s16 *)(def + 0xC);
    *(s16 *)(obj + 0x4) = 0;
    *(s16 *)(obj + 0x2) = *(s16 *)(def + 0xE);
    mathOneFloatPY(obj + 0x1C);
    *(s16 *)(obj + 0x2) = 0;
    *(u8 *)(obj + 0x88) = 0;
    *(u8 *)(obj + 0x89) = 0;
    *(s16 *)(obj + 0x8A) = *(s16 *)(def + 0xA);
    *(s32 *)(obj + 0x8C) = *(s32 *)(def + 0x14);
    hitInitObjectHit(arg0, 0x800, 1, 4, 0, 0, 0, 8.0f, 8.0f, -1.0f, 1.0f, 0x11);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o83/overlay_83/smallclusterInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void smallclusterControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *flags = obj + 0x88;   /* flags[0] = +0x88, flags[1] = +0x89 */
    u32 setupBuf[9];          /* object setup record at sp+0x44 (raw offsets) */
    u8 *setup = (u8 *)setupBuf;
    f32 posLo[3];             /* sp+0xA4: copy of obj position */
    f32 hitOut[3];            /* sp+0x70 */
    f32 *posSel;              /* sp+0xA0 */
    f32 hiY;                  /* sp+0xB4: ground height from trackPolyHeight */
    f32 oldY;                 /* sp+0xBC */
    f32 dt;                   /* sp+0x34: clamped step as float */
    f32 factor;               /* sp+0x98 */
    f32 tmp;
    f32 var_f12;
    s32 radius;               /* sp+0xB0: 8.0f bits */
    s32 hitFound;             /* sp+0xC4 */
    s32 steps;
    s32 i;
    s16 savedField2;
    u8 rot;
    void *owner;
    void *spawned;
    u32 animBitsA;
    u32 animBitsB;

    runlinkSetDestructTimer(__MODULE00083, 0xC8, 0xA);
    *(s32 *)(obj + 0x84) = 0;
    radius = 0x41000000; /* 8.0f bits */
    *(s16 *)(obj + 0x0) = (s16)(*(s16 *)(obj + 0x0) + (arg1 << 8));
    posLo[0] = *(f32 *)(obj + 0xC);
    posLo[1] = *(f32 *)(obj + 0x10);
    posLo[2] = *(f32 *)(obj + 0x14);
    steps = arg1;
    if (*(s16 *)(obj + 0x8A) < steps) {
        steps = *(s16 *)(obj + 0x8A);
    }
    dt = (f32)steps;
    if (flags[0] & 1) {
        factor = Powerf(0.875f, steps);
        *(f32 *)(obj + 0x1C) = *(f32 *)(obj + 0x1C) * factor;
        tmp = *(f32 *)(obj + 0x20);
        *(f32 *)(obj + 0x20) = (Powerf(D_overlay_83_0530122C, steps) * (D_overlay_83_05301230 - tmp)) + tmp;
        var_f12 = *(f32 *)(obj + 0x20) * dt;
        *(f32 *)(obj + 0x24) = *(f32 *)(obj + 0x24) * factor;
    } else if (flags[0] & 2) {
        factor = Powerf(D_overlay_83_05301234, steps);
        *(f32 *)(obj + 0x1C) = *(f32 *)(obj + 0x1C) * factor;
        tmp = *(f32 *)(obj + 0x20);
        *(f32 *)(obj + 0x20) = (Powerf(D_overlay_83_05301238, steps) * (-0.75f - tmp)) + tmp;
        var_f12 = *(f32 *)(obj + 0x20) * dt;
        *(f32 *)(obj + 0x24) = *(f32 *)(obj + 0x24) * factor;
    } else {
        tmp = *(f32 *)(obj + 0x20);
        var_f12 = (tmp * dt) + (D_overlay_83_0530123C * dt * dt);
        *(f32 *)(obj + 0x20) = tmp + (D_overlay_83_05301240 * dt);
    }
    objMoveXYZ(obj, *(f32 *)(obj + 0x1C) * dt, var_f12, *(f32 *)(obj + 0x24) * dt);
    if (*(f32 *)(obj + 0x20) < -3.0f) {
        flags[0] = (u8)(flags[0] | 2);
    }
    if (trackPolyHeight(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x14), &hiY, 0x2000) & 0x2000) {
        oldY = *(f32 *)(obj + 0x10);
        if (oldY < hiY) {
            if (!(flags[0] & 1)) {
                savedField2 = *(s16 *)(obj + 0x2);
                *(f32 *)(obj + 0x10) = hiY;
                *(s16 *)(obj + 0x2) = 0;
                *(s32 *)(obj + 0x84) = *(s32 *)(obj + 0x84) | 5;
                partUpdateTriggers(obj, 2);
                *(s16 *)(obj + 0x2) = savedField2;
                *(f32 *)(obj + 0x10) = oldY;
                amSndPlayXYZ(0x9E, *(f32 *)(obj + 0xC), oldY, *(f32 *)(obj + 0x14), 4, NULL);
                flags[0] = (u8)(flags[0] | 1);
            } else if ((hiY - oldY) > 16.0f) {
                *(s32 *)(obj + 0x84) = *(s32 *)(obj + 0x84) | 2;
                partUpdateTriggers(obj, 2);
            }
        }
    }
    if (flags[0] & 1) {
        animBitsA = 0xBC88CE70; /* float constant passed as bits in asm */
        objAnimDframe(obj, *(f32 *)&animBitsA, dt);
    } else if (flags[0] & 2) {
        animBitsB = 0x3D08CE70; /* float constant passed as bits in asm */
        objAnimDframe(obj, *(f32 *)&animBitsB, dt);
        rot = (u8)(flags[1] + (arg1 * 2));
        flags[1] = rot;
        *(s16 *)(obj + 0x4) = (s16)(mathSin((s16)(rot << 8)) >> 4);
    }
    trackMakePolylist(1, posLo, obj + 0xC, &radius, 0xCE002000, 0, 0);
    hitFound = 0;
    if (trackGetIntersect(arg0, posLo, obj + 0xC, radius, 1, hitOut) != 0) {
        hitFound = 1;
        posSel = (f32 *)(obj + 0xC);
    } else if (*(s16 *)(*(u8 **)(obj + 0x4C) + 0x6) != 0x800) {
        posSel = posLo;
        hitFound = 1;
    } else {
        *(s16 *)(obj + 0x8A) = (s16)(*(s16 *)(obj + 0x8A) - arg1);
        if (*(s16 *)(obj + 0x8A) <= 0) {
            posSel = (f32 *)(obj + 0xC);
            hitFound = 1;
        }
    }
    if (hitFound != 0) {
        owner = *(void **)(obj + 0x8C);
        if ((owner != NULL) && (*(s16 *)((u8 *)owner + 0x48) != 1)) {
            owner = NULL;
        }
        if (flags[0] & 1) {
            explosionStart(6, (s16)(s32)posSel[0], (s16)(s32)posSel[1], (s16)(s32)posSel[2], 0xE, owner);
        } else {
            explosionStart(8, (s16)(s32)posSel[0], (s16)(s32)posSel[1], (s16)(s32)posSel[2], 0xE, owner);
            if (multiPlayerGame == 0) {
                *(s16 *)(setup + 0x00) = 0x139;
                *(s16 *)(setup + 0x04) = (s16)(s32)posSel[0];
                *(s16 *)(setup + 0x06) = (s16)(s32)posSel[1];
                *(s16 *)(setup + 0x08) = (s16)(s32)posSel[2];
                *(s16 *)(setup + 0x0E) = 0x78;
                *(f32 *)(setup + 0x18) = D_overlay_83_05301244;
                setup[0x1C] = 0xE;
                *(void **)(setup + 0x20) = owner;
                i = 0;
                do {
                    *(s16 *)(setup + 0x0A) = (s16)(*(s16 *)obj + (i << 14));
                    *(s16 *)(setup + 0x0C) = (s16)mathRnd(0x1000, 0x2000);
                    *(f32 *)(setup + 0x14) = (f32)mathRnd(0x32, 0x50) * D_overlay_83_05301248;
                    *(f32 *)(setup + 0x10) = (f32)mathRnd(0xF, 0x19) * D_overlay_83_0530124C;
                    spawned = objSetupObject(setup, 1);
                    i++;
                    if (spawned != NULL) {
                        *(s32 *)((u8 *)spawned + 0x3C) = 0;
                    }
                } while (i != 4);
            }
        }
        amSndPlayXYZ(0x96, posSel[0], posSel[1], posSel[2], 4, NULL);
        objFreeObject(obj);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o83/overlay_83/smallclusterControl.s")
#endif
