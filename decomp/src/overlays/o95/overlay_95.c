#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
/* Raw-offset accessor for fields without a known struct layout. */
#define OFF(p, o, T) (*(T *)((u8 *)(p) + (o)))

/* Flamethrower state word (0x620): bits 26..31 = particle head index,
   bits 20..25 = active count (CNT_B), bits 14..19 = loop count (CNT_A),
   bit 13 = refresh flag, bits 4..9 = countdown copy. */
#define FLAME_HEAD(s)  (((u32)(s)) >> 26)
#define FLAME_CNT_A(s) ((((u32)(s)) << 12) >> 26)
#define FLAME_CNT_B(s) ((((u32)(s)) << 6) >> 26)
#define FLAME_FLAG(s)  ((((u32)(s)) << 18) >> 31)

typedef struct FlameParticle {
    f32 pos[3];         /* 0x00 */
    f32 vel[3];         /* 0x0C */
    f32 scale;          /* 0x18 */
    f32 unk1C;          /* 0x1C: passed to texAnimateSprite */
    f32 srcVel[3];      /* 0x20: copied from owner object */
    s16 life;           /* 0x2C */
    s16 fadeTime;       /* 0x2E */
    s8 fadeStep;        /* 0x30 */
    u8 alpha;           /* 0x31 */
    u8 pad32[2];
} FlameParticle;        /* 0x34 */

typedef struct Flamethrower {
    Object *owner;                  /* 0x00 */
    void *light;                    /* 0x04 */
    FlameParticle particles[30];    /* 0x08 */
    u32 state;                      /* 0x620 */
} Flamethrower;                     /* 0x624 */

extern s32 D_overlay_95_05F01880;
extern f32 D_overlay_95_05F01858;
extern f32 D_overlay_95_05F0185C;
extern f32 D_overlay_95_05F01860;
extern f32 D_overlay_95_05F01868;
extern f32 D_overlay_95_05F0186C;
extern ObjectHeader48 D_overlay_95_05F01830;
extern Flamethrower *D_overlay_95_05F01870[];
extern s32 __MODULE00095;
extern u8 multiPlayerGame;

extern void _bzero(void *ptr, s32 size);
extern void mmFree(void *data);
extern void amSndPlay(s32 soundId, void *handlePtr);
extern void amSndStop(s32 handle);
extern void mathOneFloatPY(s16 *in, void *out);
extern void texAnimateSprite(void *data, s32 *frame, s32 n, void *anim, s32 rate);
extern s32 trackNearestIntersection(f32 a, f32 b, s32 c, f32 *from, void *obj, void **hitObj, s32 d, s32 e);
extern void killLight(void *light, s32 arg);
extern void *objSetupObject(void *params, s32 arg1);
extern void runlinkSetDestructTimer(s32 module, s32 a, s32 b);
extern void camDoSprite(Gfx **dl, s32 *arg1, s32 *arg2, s16 *arg3, s32 arg4, s32 arg5, s32 arg6);
extern void SetSquaddieOnFire(void *obj);
extern void **objGetObjList(f32 a, f32 b, s32 *lo, s32 *hi, u32 c, s32 d);
extern void squadsPlayerShootsSquaddie(f32 a, f32 b, void *obj, void *owner, u32 c, s32 d);
extern void texDPInit(Gfx **dl);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void flamethrowerInit(s32 owner, Flamethrower *flame) {
    _bzero(flame, 0x624);
    flame->owner = (Object *) owner;
    D_overlay_95_05F01870[D_overlay_95_05F01880] = flame;
    D_overlay_95_05F01880 += 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o95/overlay_95/flamethrowerInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void flamethrowerFire(Flamethrower *flame, f32 arg1, f32 arg2, f32 arg3, s16 arg4, s16 arg5, s32 arg6) {
    Object *owner = flame->owner;
    Object_Racer *racer;
    u8 *spriteData;
    f32 from[3];
    f32 hitPos[3];
    void *hitObj;
    s16 dir[3];
    s32 animFrame;
    u32 st;
    u32 v1;
    s32 v0;
    s32 t0;
    s32 t8;
    s32 k;
    FlameParticle *p;
    f32 rate;

    animFrame = 9;
    from[0] = arg1;
    from[1] = arg2;
    from[2] = arg3;

    if (owner->behaviorId == 1) {
        racer = owner->racer;
        if (OFF(racer, 0x53A, u8) != 1) {
            if (OFF(racer, 0xC0, s32) != 0) {
                amSndStop(OFF(racer, 0xC0, s32));
            }
            amSndPlay(1, (u8 *) racer + 0xC0);
            OFF(racer, 0x53A, u8) = 1;
        }
        spriteData = OFF(OFF(owner, 0x40, void *), 0xAC, void *);
        spriteData = OFF(spriteData, 0xC, u8 *);
    } else {
        spriteData = *(u8 **) OFF(OFF(owner, 0x40, void *), 0xAC, void *);
    }

    /* advance the state word's LCG-like bit mix */
    st = flame->state;
    st = ((((u32) (((((st << 12) >> 26) + arg6) ^ (st >> 14)) << 26)) >> 12)) ^ st;
    flame->state = st;
    v1 = st;
    v0 = FLAME_CNT_A(v1);

    if (v0 >= 2) {
        do {
            p = &flame->particles[FLAME_HEAD(v1)];
            t8 = v0 - 2;
            if (p->life <= 0) {
                p->life = 0x3C;
                p->fadeTime = 0x2D;
                p->alpha = 0xFF;
                p->fadeStep = 0x11;
                p->pos[0] = arg1;
                p->pos[1] = arg2;
                p->pos[2] = arg3;
                p->scale = (f32) ((mathRnd(0, 0xBB8) * D_overlay_95_05F01858) + 1.0f);
                p->unk1C = (f32) mathRnd(0, (s32) *spriteData);
                p->srcVel[0] = (f32) OFF(owner, 0x1C, s32);
                p->srcVel[1] = (f32) OFF(owner, 0x20, s32);
                p->srcVel[2] = (f32) OFF(owner, 0x24, s32);
                dir[0] = arg4;
                dir[1] = arg5;
                dir[2] = 0;
                p->vel[0] = 0.0f;
                p->vel[1] = 0.0f;
                p->vel[2] = -2.0f;
                mathOneFloatPY(dir, p->vel);

                t0 = t8;
                if (t0 != 0) {
                    p->life -= t0;
                    p->fadeTime -= t0;
                    if (t0 > 0) {
                        for (k = 0; k < t0; k++) {
                            p->scale *= D_overlay_95_05F0185C;
                        }
                    }
                    rate = (f32) t0;
                    {
                        f32 newX = p->pos[0] + ((p->vel[0] + p->srcVel[0]) * rate);
                        f32 oldZ = p->pos[2];
                        p->pos[0] = newX;
                        p->pos[1] = p->pos[1] + ((p->vel[1] + p->srcVel[1]) * rate);
                        p->pos[2] = oldZ + ((p->vel[2] + p->srcVel[2]) * rate);
                        if (trackNearestIntersection(oldZ, newX, 0, from, p, &hitObj, 0, 0) != 0) {
                            /* asm: hit point read from stack slots written by the trace call */
                            p->pos[0] = hitPos[0];
                            p->pos[1] = hitPos[1];
                            p->pos[2] = hitPos[2];
                        }
                    }
                    texAnimateSprite(spriteData, &animFrame, 0x14, &p->unk1C, arg6);
                }

                /* advance the head index and the packed count fields */
                if (FLAME_HEAD(flame->state) == 0x1D) {
                    flame->state = (flame->state & ~0xFCu) | 0;
                } else {
                    flame->state = (flame->state & ~0xFFu) | (((FLAME_HEAD(flame->state) + 1) * 4) & 0xFF) | (flame->state & 0x3);
                }
                {
                    u32 cntB = FLAME_CNT_B(flame->state);
                    u32 lo16 = flame->state & 0xFFFF;
                    flame->state = (flame->state & 0xFFFF0000) | ((((cntB + 1) * 0x10) & 0x3F0) | (lo16 & 0xFC0F));
                }
                v1 = flame->state;
                t8 = FLAME_CNT_A(v1) - 2;
            }
            st = ((u32) ((t8 ^ (v1 >> 14)) << 26) >> 12) ^ v1;
            v0 = FLAME_CNT_A(st);
            flame->state = st;
            v1 = st;
        } while (v0 >= 2);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o95/overlay_95/flamethrowerFire.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void flamethrowerUpdate(Flamethrower *flame, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    Object *owner = flame->owner;
    u8 *spriteData;
    s32 animFrame;
    s32 count;
    s32 i;
    s32 t0;
    f32 mult;
    FlameParticle *p;
    void *light;
    f32 from[3];
    f32 hitPos[3];
    void *hitObj;
    u8 setupBuf[0x14];
    s32 k;
    s32 tmp;

    animFrame = 9;
    count = FLAME_CNT_B(flame->state);
    if (count != 0) {
        runlinkSetDestructTimer(__MODULE00095, 2, 2);
        count = FLAME_CNT_B(flame->state);
    }

    if (count != 0) {
        light = flame->light;
        if (light == NULL) {
            light = (void *) addObjectLight(NULL, &D_overlay_95_05F01830);
            flame->light = light;
            count = FLAME_CNT_B(flame->state);
        }
        if (light != NULL) {
            s8 intensity = (s8) (count * 0x10);
            if ((count * 0x10) >= 0x100) {
                intensity = -1;
            }
            OFF(light, 0x43, s8) = intensity;
            OFF(light, 0x44, f32) = (f32) intensity;
            OFF(light, 0x18, f32) = arg1;
            OFF(light, 0x1C, f32) = arg2;
            OFF(light, 0x20, f32) = arg3;
            count = FLAME_CNT_B(flame->state);
        }
    } else {
        light = flame->light;
        if (light != NULL) {
            killLight(light, count);
            flame->light = NULL;
            count = FLAME_CNT_B(flame->state);
        }
    }

    if (count != 0) {
        if (FLAME_FLAG(flame->state) != 0) {
            for (i = 0; i < 30; i++) {
                p = &flame->particles[i];
                if (p->life > 0) {
                    p->fadeTime = 0;
                    p->fadeStep = (s8) ((s32) p->alpha / p->life);
                }
            }
        }

        if (owner->behaviorId == 1) {
            spriteData = OFF(OFF(OFF(owner, 0x40, void *), 0xAC, void *), 0xC, u8 *);
        } else {
            spriteData = *(u8 **) OFF(OFF(owner, 0x40, void *), 0xAC, void *);
        }

        mult = D_overlay_95_05F01860;
        for (i = 0; i < 30; i++) {
            p = &flame->particles[i];
            if (p->life > 0) {
                p->life -= arg4;
                if (p->life <= 0) {
                    s32 cnt = FLAME_CNT_B(flame->state) - 1;
                    flame->state = (flame->state & 0xFFFF0000) | (((cnt * 0x10) & 0x3F0) | (flame->state & 0xFC0F));
                } else {
                    f32 f2 = (f32) arg4;

                    if (p->fadeTime <= 0) {
                        tmp = p->alpha - (p->fadeStep * arg4);
                        p->alpha = (tmp < 0) ? 0 : (u8) tmp;
                    } else {
                        p->fadeTime -= arg4;
                    }

                    for (k = 0; k < arg4; k++) {
                        p->scale *= mult;
                    }

                    from[0] = p->pos[0];
                    from[1] = p->pos[1];
                    from[2] = p->pos[2];
                    {
                        f32 oldZ = p->pos[2];
                        f32 newZ;
                        p->pos[0] = p->pos[0] + ((p->vel[0] + p->srcVel[0]) * f2);
                        newZ = oldZ + ((p->vel[2] + p->srcVel[2]) * f2);
                        p->pos[1] = p->pos[1] + ((p->vel[1] + p->srcVel[1]) * f2);
                        p->pos[2] = newZ;
                        if ((trackNearestIntersection(newZ, oldZ, 0, from, p, &hitObj, 0, 0) != 0) && (hitObj != NULL)) {
                            /* asm: hit point read from stack slots written by the trace call */
                            p->pos[0] = hitPos[0];
                            p->pos[1] = hitPos[1];
                            p->pos[2] = hitPos[2];
                            if (((Object *) hitObj)->behaviorId == 0x5B) {
                                OFF(hitObj, 0x88, s32) = OFF(hitObj, 0x88, s32) + (arg4 * 0x10);
                            } else if ((((Object *) hitObj)->behaviorId == 0x4E) && (OFF(hitObj, 0x5C, void *) != NULL)) {
                                OFF(OFF(hitObj, 0x5C, void *), 0x12A, s8) = 1;
                                OFF(OFF(hitObj, 0x5C, void *), 0x130, s16) = OFF(OFF(hitObj, 0x5C, void *), 0x130, s16) + (arg4 * 0x10);
                            }
                        }
                    }
                    texAnimateSprite(spriteData, &animFrame, 0x14, &p->unk1C, arg4);
                    mult = D_overlay_95_05F01868;
                }
            }
        }

        if (multiPlayerGame == 0) {
            if (mathRnd(0, 3) == 0) {
                t0 = (s32) (FLAME_HEAD(flame->state)) - mathRnd(1, 4);
                if (t0 < 0) {
                    t0 += 0x1E;
                }
                p = &flame->particles[t0];
                if (p->life >= 0x29) {
                    OFF(setupBuf, 0x00, s16) = 0x142;
                    OFF(setupBuf, 0x02, u8) = 0x14;
                    OFF(setupBuf, 0x03, u8) = 0;
                    OFF(setupBuf, 0x04, s16) = (s16) (s32) p->pos[0];
                    OFF(setupBuf, 0x06, s16) = (s16) (s32) p->pos[1];
                    OFF(setupBuf, 0x08, s16) = (s16) (s32) p->pos[2];
                    OFF(setupBuf, 0x0E, u8) = 0;
                    OFF(setupBuf, 0x10, f32) = 0.0f;
                    OFF(objSetupObject(setupBuf, 1), 0x3C, s32) = 0;
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o95/overlay_95/flamethrowerUpdate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void flamethrowerConstrain(Flamethrower *flame) {
    u32 state = flame->state;
    s32 count = FLAME_CNT_B(state);
    s32 head;
    s32 cur;
    s32 prev;
    s32 s4;
    FlameParticle *curP;
    FlameParticle *prevP;
    FlameParticle *headP;
    f32 maxDist;
    f32 diff;
    f32 nx;
    f32 ny;
    f32 nz;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 len;
    f32 scale;

    if (count != 0) {
        head = (s32) FLAME_HEAD(state) - 1;
        if (head < 0) {
            head += 30;
        }
        headP = &flame->particles[head];
        cur = head;
        prev = (cur + 29) % 30;
        maxDist = 2.0f;
        if (count >= 2) {
            s4 = 1;
            do {
                curP = &flame->particles[cur];
                prevP = &flame->particles[prev];
                diff = (f32) (curP->life - prevP->life);
                if ((curP->life - prevP->life) < 4) {
                    nx = curP->pos[0] + (headP->vel[0] * diff);
                    ny = curP->pos[1] + (headP->vel[1] * diff);
                    nz = curP->pos[2] + (headP->vel[2] * diff);
                    dx = prevP->pos[0] - nx;
                    dy = prevP->pos[1] - ny;
                    dz = prevP->pos[2] - nz;
                    len = sqrtf((dx * dx) + (dy * dy) + (dz * dz));
                    if (maxDist < len) {
                        f32 ratio = maxDist / len;
                        f32 ax = ((ratio * dx) + nx) - curP->pos[0];
                        f32 ay = ((ratio * dy) + ny) - curP->pos[1];
                        f32 az = ((ratio * dz) + nz) - curP->pos[2];
                        f32 bx = prevP->pos[0] - curP->pos[0];
                        f32 by = prevP->pos[1] - curP->pos[1];
                        f32 bz = prevP->pos[2] - curP->pos[2];
                        f32 lenA = sqrtf((ax * ax) + (ay * ay) + (az * az));
                        f32 lenB = sqrtf((bx * bx) + (by * by) + (bz * bz));
                        f32 t;
                        if (lenA == 0.0f) {
                            t = 0.0f;
                        } else {
                            t = lenB / lenA;
                        }
                        prevP->pos[0] = curP->pos[0] + (t * ax);
                        prevP->pos[1] = curP->pos[1] + (t * ay);
                        prevP->pos[2] = curP->pos[2] + (t * az);
                    }
                    dx = prevP->pos[0] - curP->pos[0];
                    dy = prevP->pos[1] - curP->pos[1];
                    dz = prevP->pos[2] - curP->pos[2];
                    scale = sqrtf((dx * dx) + (dy * dy) + (dz * dz));
                    if (scale != 10.0f) {
                        f32 t2;
                        if (scale == 0.0f) {
                            t2 = 0.0f;
                        } else {
                            t2 = 10.0f / scale;
                        }
                        prevP->pos[0] = curP->pos[0] + (t2 * dx);
                        prevP->pos[1] = curP->pos[1] + (t2 * dy);
                        prevP->pos[2] = curP->pos[2] + (t2 * dz);
                    }
                }
                if (s4 >= 4) {
                    maxDist += D_overlay_95_05F0186C;
                }
                s4 += 1;
                cur = prev;
                prev = (prev + 29) % 30;
            } while ((u32) s4 < (u32) FLAME_CNT_B(flame->state));
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o95/overlay_95/flamethrowerConstrain.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void flamethrowerHits(Flamethrower *flame) {
    Object *owner = flame->owner;
    f32 ox = OFF(owner, 0x0C, f32);
    f32 oy = OFF(owner, 0x10, f32);
    f32 oz = OFF(owner, 0x14, f32);
    s32 lo = 0;
    s32 hi = 0;
    s32 k;
    s32 k2;
    s32 count;
    s32 headRaw;
    s32 idx;
    s32 idx2;
    f32 bestD2 = 0.0f;
    FlameParticle *bestP = NULL;
    f32 dy = 0.0f;   /* asm: last-iteration deltas are passed on to objGetObjList */
    f32 dz = 0.0f;
    f32 dx;
    f32 d2;
    f32 radius;
    void **list;
    void *obj;
    void *playerRacer = NULL;   /* asm: uninitialised stack slot in original */
    void *squadRacer = NULL;
    Object *hitOwner;
    FlameParticle *p;

    if (owner->behaviorId == 1) {
        count = (s32) FLAME_CNT_B(flame->state);
        headRaw = (s32) FLAME_HEAD(flame->state) - 1;
        if (count != 0) {
            if (count >= 2) {
                idx = headRaw;
                for (k = 2; k <= count; k++) {
                    if (idx < 0) {
                        idx += 30;
                    }
                    p = &flame->particles[idx];
                    dx = ox - p->pos[0];
                    dy = oy - p->pos[1];
                    dz = oz - p->pos[2];
                    d2 = (dx * dx) + (dy * dy) + (dz * dz);
                    if (bestD2 < d2) {
                        bestD2 = d2;
                        bestP = p;
                    }
                    idx -= 1;
                }
            }
            if (bestP != NULL) {
                radius = bestP->scale * 4.0f;
                bestD2 = bestD2 + (radius * radius);
                list = objGetObjList(dy, dz, &lo, &hi, (u32) count, headRaw);
                for (k = lo; k < hi; k++) {
                    obj = list[k];
                    if (((Object *) obj)->behaviorId != 0x18) {
                        if ((((Object *) obj)->behaviorId == 1) && (obj != owner)) {
                            playerRacer = ((Object *) obj)->racer;
                        } else if ((((Object *) obj)->behaviorId == 0xA6) || (((Object *) obj)->behaviorId == 0xA7)) {
                            squadRacer = ((Object *) obj)->racer;
                        } else {
                            obj = NULL;
                        }
                    }
                    if (obj != NULL) {
                        f32 ox2 = OFF(obj, 0x0C, f32);
                        f32 oy2 = OFF(obj, 0x10, f32);
                        f32 oz2 = OFF(obj, 0x14, f32);
                        f32 ex = ox - ox2;
                        f32 ey = oy - oy2;
                        f32 ez = oz - oz2;
                        if (((ex * ex) + (ey * ey) + (ez * ez)) <= bestD2) {
                            void *objExtra = OFF(obj, 0x4C, void *);
                            idx2 = headRaw;
                            for (k2 = 0; k2 < count - 1; k2++) {
                                f32 r;
                                if (idx2 < 0) {
                                    idx2 += 30;
                                }
                                p = &flame->particles[idx2];
                                r = p->scale * 4.0f;
                                if (objExtra != NULL) {
                                    r += OFF(objExtra, 0x24, f32);
                                }
                                dx = ox2 - p->pos[0];
                                dy = oy2 - p->pos[1];
                                dz = oz2 - p->pos[2];
                                if (((dx * dx) + (dy * dy) + (dz * dz)) <= (r * r)) {
                                    if (((Object *) obj)->behaviorId == 0x18) {
                                        squadsPlayerShootsSquaddie(dy, dz, obj, owner, (u32) count, headRaw);
                                        SetSquaddieOnFire(obj);
                                    } else if (((Object *) obj)->behaviorId == 1) {
                                        OFF(playerRacer, 0x56F, u8) = 6;
                                        hitOwner = flame->owner;
                                        if ((hitOwner != NULL) && (hitOwner->behaviorId == 1)) {
                                            OFF(playerRacer, 0x570, Object *) = hitOwner;
                                        }
                                    } else {
                                        OFF(squadRacer, 0x9A, u8) = 1;
                                    }
                                    break;
                                }
                                idx2 -= 1;
                            }
                        }
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o95/overlay_95/flamethrowerHits.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void flamethrowerDraw(Object *owner, Flamethrower *flame, Gfx **dlPtr, s32 *arg3, s32 *arg4) {
    Gfx *dl;
    Gfx *g;
    s32 sp94;
    s32 sp90;
    s32 spriteAnim;
    s16 pos[3];
    f32 spriteParams[5];
    s32 count;
    s32 idx;
    s32 n;
    s32 limit;
    f32 accum;
    FlameParticle *p;

    dl = *dlPtr;
    sp94 = *arg3;
    sp90 = *arg4;
    pos[0] = 0;
    pos[1] = 0;
    pos[2] = 0;

    texDPInit(&dl);
    g = dl;
    dl = g + 1;
    g->words.w1 = 0;
    g->words.w0 = 0xE7000000;
    g = dl;
    dl = g + 1;
    g->words.w1 = -1U;
    g->words.w0 = 0xFB000000;

    if (owner->behaviorId == 1) {
        spriteAnim = (s32) OFF(OFF(OFF(owner, 0x40, void *), 0xAC, void *), 0xC, void *);
    } else {
        spriteAnim = (s32) *(void **) OFF(OFF(owner, 0x40, void *), 0xAC, void *);
    }

    count = (s32) FLAME_CNT_B(flame->state);
    limit = count;
    idx = (s32) FLAME_HEAD(flame->state) - 1;
    accum = 0.0f;
    n = 0;
    if (count != 0) {
        do {
            if (idx < 0) {
                idx += 0x1E;
            }
            if (accum <= 0.0f) {
                p = &flame->particles[idx];
                if (p->life > 0) {
                    spriteParams[0] = p->unk1C;
                    spriteParams[1] = p->pos[0];
                    spriteParams[2] = p->pos[1];
                    spriteParams[3] = p->pos[2];
                    spriteParams[4] = p->scale;
                    g = dl;
                    dl = g + 1;
                    g->words.w1 = 0;
                    g->words.w0 = 0xE7000000;
                    g = dl;
                    dl = g + 1;
                    g->words.w0 = 0xFA000000;
                    g->words.w1 = p->alpha | ~0xFF;
                    camDoSprite(&dl, &sp94, &sp90, pos, spriteAnim, 2, (s32) p->alpha);
                    limit = (s32) FLAME_CNT_B(flame->state);
                }
                accum += p->scale;
            }
            n += 1;
            accum -= 1.5f;
            idx -= 1;
        } while (n < limit);
    }

    g = dl;
    dl = g + 1;
    g->words.w1 = -1U;
    g->words.w0 = 0xFA000000;
    texDPInit(&dl);
    *dlPtr = dl;
    *arg3 = sp94;
    *arg4 = sp90;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o95/overlay_95/flamethrowerDraw.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 _AutoExit00095(void) {
    s32 ret = D_overlay_95_05F01880;
    s32 i;

    if (D_overlay_95_05F01880 != 0) {
        for (i = D_overlay_95_05F01880 - 1; i >= 0; i--) {
            Flamethrower *flame = D_overlay_95_05F01870[i];
            Object *owner = flame->owner;

            ret = i;
            if (owner->behaviorId == 1) {
                Object_Racer *racer = owner->racer;
                void *fx = OFF(racer, 0x564, void *);
                void *light = OFF(fx, 0x4, void *);

                if (light != NULL) {
                    killLight(light, (s32) light);
                }
                mmFree(OFF(racer, 0x564, void *));
                OFF(racer, 0x564, void *) = NULL;
                ret = i;
            }
        }
    }
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o95/overlay_95/_AutoExit00095.s")
#endif
