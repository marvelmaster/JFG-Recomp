#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
f32 Sinf(s32);
void texAnimateSprite(s32, s32 *, s32, void *, s32);
void objFreeObject(void *);
void **objGetPlayerlist();
void **objGetObjList(s32 *, s32 *);
void **objGetAnimPlayerlist();
void *trackGetTrack();
s16 trackGetBlock(f32, f32, void *, f32, void *);
void trackAddTextureScroll(s16, s32, s32, s32);
void trackSkySet(s32, void *);
void partUpdateTriggers(void *, s32);
s32 hitPlayer(f32, f32, f32, f32, s32, void *);
void amSndPlayXYZ(u16, f32, f32, f32, u8, void *);
void amSndStopXYZ(void *);
void amDittyPlay(s32);
void *objGetClosestControlType(f32, f32, f32, s32);
s32 objTvTimes(s32);
void objAnimDframe(void *, f32, f32);
void animControl(void *, s32);
void hitInitObjectHit(void *, s32, s32, s32, s32, s32, s32, f32, f32, f32, f32, s32);
void amSndPlay(u16, void *);
s32 explosionBlastHit(f32, f32, f32, f32, s32);
void animseqStartPath(u8);
void animseqSetupGroup(u8);
void animseqHoldPath(u8);
void animseqSndPlay(u8, s16);
void animseqSndStop(u8);
void animseqPause(void);
void animseqPlay(void);
void mmFree(void *);
void modMakeLimbModel(void *, void *, void *, s32, s32, s32, s32);
s32 squadsIsTribal(s32);
void *controlGetWeaponDef(s32);
void dropletAdd(void *, s32, s32);
void *mainGetGameCharacter(s8, s8);
void mainSaveGlobalFlags(s32, u64 *, s32);
void objMoveXYZ(void *, f32, f32, f32);
s32 trackNearestIntersection(s32, void *, void *, void *, s32, s32);
void instQueueMsg(f32, f32, f32, f32, f32, f32, f32, f32);
void instQueueMsg_1arg(s32 arg0); /* NM link alias of instQueueMsg (asm sets only a0) */
void mathOneFloatPY(void *, void *, void *, void *);
f32 Powerf(f32, s32);
void *camGetListPtr(void);
void mizarExplosionCallBack(void *, s32);
s32 mainGetGameFlag(s32);
extern u8 D_800A1120_A1D20[];
void cutcameraActivate(void *, s32);
void instUnlockMsg(void *, s32);
s32 mainPlayerHas(s8, s8, s32, void **);
s32 objAnimSetMove(void *, u8, f32);
extern s16 D_800A1180_A1D80[];
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void spranimInit(void *arg0, void *arg1) {
    u8 *obj = arg0;
    u8 *spawn = arg1;
    f32 var_f0;

    var_f0 = (f32) spawn[0xB];
    if (var_f0 < 10.0f) {
        var_f0 = 10.0f;
    }
    *(f32 *)(obj + 0x08) = *(f32 *)*(u8 **)(obj + 0x40) * (var_f0 / 64.0f);
    *(s32 *)(obj + 0x88) = spawn[0xA];
    *(f32 *)(obj + 0x28) = (f32) spawn[0xC];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/spranimInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void spranimControl(void *arg0, s32 arg1) {
    u8 *obj = arg0;
    s32 sp24;

    sp24 = 9;
    texAnimateSprite(*(s32 *)*(u8 **)(obj + 0x6C), &sp24, *(s32 *)(obj + 0x88), obj + 0x28, arg1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/spranimControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void sprasjiInit(void *arg0, void *arg1) {
    u8 *obj = arg0;
    u8 *spawn = arg1;
    f32 var_f0;

    var_f0 = (f32) (s32) spawn[0xB];
    if (var_f0 < 10.0f) {
        var_f0 = 10.0f;
    }
    *(f32 *)(obj + 0x08) = *(f32 *)*(u8 **)(obj + 0x40) * (var_f0 / 64.0f);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/sprasjiInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void spranimOnceControl(void *arg0, s32 arg1) {
    u8 *obj = arg0;
    s32 sp34;
    f32 sp2C;

    sp34 = 9;
    sp2C = *(f32 *)(obj + 0x28);
    texAnimateSprite(*(s32 *)*(u8 **)(obj + 0x6C), &sp34, *(s32 *)(obj + 0x88), obj + 0x28, arg1);
    if (*(f32 *)(obj + 0x28) < sp2C) {
        objFreeObject(arg0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/spranimOnceControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void effectboxControl(void *arg0, s32 arg1) {
    u8 *obj = arg0;
    u8 *spec = *(u8 **)(obj + 0x3C);
    void **list;
    s32 count;
    s32 ang;
    f32 cosA, sinA, extX, extY, extZ;
    s32 i;

    list = objGetPlayerlist(&count, arg0);
    ang = -((s32) spec[0xD] << 8);
    cosA = Cosf(ang);
    sinA = Sinf(ang);
    extX = (f32) (spec[0xA] * 3);
    extY = (f32) (spec[0xB] * 3);
    extZ = (f32) (spec[0xC] * 3);

    for (i = 0; i < count; i++) {
        u8 *other = list[i];
        f32 dx = *(f32 *)(other + 0x0C) - *(f32 *)(obj + 0x0C);
        f32 dy = *(f32 *)(other + 0x10) - *(f32 *)(obj + 0x10);
        f32 dz = *(f32 *)(other + 0x14) - *(f32 *)(obj + 0x14);

        if (-extY < dy && dy < extY) {
            f32 rx = (dx * cosA) + (dz * sinA);
            if (-extX < rx && rx < extX) {
                f32 rz = (-dx * sinA) + (dz * cosA);
                if (-extZ < rz && rz < extZ) {
                    u8 *ostate = *(u8 **)(other + 0x68);
                    f32 half = extY / 2.0f;

                    ostate[0x194] = spec[0xE];
                    ostate[0x195] = spec[0xF];
                    if (half < dy && spec[0xE] == 1) {
                        f32 val = (f32) spec[0xF] * (1.0f - ((dy - half) / half));
                        s32 t0 = (s32) val;

                        if (t0 < 0) {
                            t0 = -1;
                        }
                        ostate[0x195] = (u8) t0;
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/effectboxControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animInit(void *arg0, void *arg1, s32 arg2) {
    u8 *obj = arg0;
    u8 *spawn = arg1;
    s16 *st = *(s16 **)(obj + 0x68);

    st[1] = (s16) *(s8 *)(spawn + 0xA);
    st[2] = (s16) *(s8 *)(spawn + 0xB);
    st[3] = (s16) *(s8 *)(spawn + 0xC);
    st[0] = trackGetBlock(*(f32 *)(obj + 0x0C), *(f32 *)(obj + 0x10), arg1, *(f32 *)(obj + 0x14), arg0);
    if (arg2 == 0) {
        st[4] = 0;
        st[5] = 0;
    }
    if (st[0] != -1) {
        u8 *track = trackGetTrack();
        u8 *blk;

        if (st[1] < 0) {
            st[1] = 0;
        }
        blk = *(u8 **)(track + 4) + (st[0] * 0x48);
        if (st[1] >= *(s16 *)(blk + 0x28)) {
            st[1] = (s16) (*(s16 *)(blk + 0x28) - 1);
        }
    }
    animControl(arg0, 0x20000);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/animInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animControl(void *arg0, s32 arg1) {
    u8 *obj = arg0;
    s16 *st = *(s16 **)(obj + 0x68);
    s32 t0;
    s32 t1;
    s16 a2;

    st[4] = (s16) (st[4] + (st[2] * arg1 * 0x10));
    a2 = st[4];
    st[4] = (s16) (a2 & 0xF);
    t0 = a2 >> 4;
    st[5] = (s16) (st[5] + (st[3] * arg1 * 0x10));
    a2 = st[5];
    st[5] = (s16) (a2 & 0xF);
    t1 = a2 >> 4;

    if (st[0] != -1) {
        u8 *track = trackGetTrack(a2);
        u8 *blk = *(u8 **)(track + 4) + (st[0] * 0x48);
        u8 *seq = *(u8 **)(blk + 0xC) + (st[1] * 0x10);
        u8 t5 = seq[0];
        s16 t4 = *(s16 *)(seq + 0x08);
        s16 t3 = *(s16 *)(seq + 0x18);

        if (t5 != 0xFF) {
            s32 a1;
            s16 idx = t4;

            a1 = *(*(s32 **)(*(u8 **)track + (t5 * 8))) << 7;
            if (t4 < t3) {
                do {
                    s16 *e = (s16 *) (*(u8 **)(blk + 4) + (idx * 0x10));
                    u8 flags = ((u8 *) e)[0];

                    idx += 1;
                    if (!(flags & 0x80)) {
                        if ((a1 * 2) < e[3]) {
                            e[3] = (s16) (e[3] - a1);
                            e[5] = (s16) (e[5] - a1);
                            e[7] = (s16) (e[7] - a1);
                        }
                        if (e[3] < 0) {
                            e[3] = (s16) (e[3] + a1);
                            e[5] = (s16) (e[5] + a1);
                            e[7] = (s16) (e[7] + a1);
                        }
                        if ((a1 * 2) < e[2]) {
                            e[2] = (s16) (e[2] - a1);
                            e[4] = (s16) (e[4] - a1);
                            e[6] = (s16) (e[6] - a1);
                        }
                        if (e[2] < 0) {
                            e[2] = (s16) (e[2] + a1);
                            e[4] = (s16) (e[4] + a1);
                            e[6] = (s16) (e[6] + a1);
                        }
                        e[3] = (s16) (e[3] + t1);
                        e[5] = (s16) (e[5] + t1);
                        e[7] = (s16) (e[7] + t1);
                        e[2] = (s16) (e[2] + t0);
                        e[4] = (s16) (e[4] + t0);
                        e[6] = (s16) (e[6] + t0);
                    }
                } while (idx != t3);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/animControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Hit test helper: st+0x16 gates a facing test (hit centre behind plane st.n·p + st.d < 0).
static s32 exitHitFacing(u8 *st, u8 *hit) {
    f32 dot;

    if (*(s16 *)(st + 0x16) == 0) {
        return 1;
    }
    dot = *(f32 *)(st + 0x0) * *(f32 *)(hit + 0xC)
        + *(f32 *)(st + 0x4) * *(f32 *)(hit + 0x10)
        + *(f32 *)(st + 0x8) * *(f32 *)(hit + 0x14)
        + *(f32 *)(st + 0xC);
    return dot < 0.0f;
}

// Per-hit action: hit->0x68 is the hit object's state. Selector st+0x14 (3/4/5)
// picks the condition; if it passes, state+0xF4 = exit obj and state+0x196 = -0x78.
static void exitHitApply(u8 *obj, u8 *st, u8 *hit) {
    u8 *hs = *(u8 **)(hit + 0x68);
    s32 skip = 0;

    switch (*(s16 *)(st + 0x14)) {
    case 3:
        if (*(s8 *)(hs + 1) & 4) {
            skip = 1;
        }
        break;
    case 4:
        if (!(*(s8 *)(hs + 1) & 4)) {
            skip = 1;
        }
        break;
    case 5:
        if (*(s8 *)(hs + 0x189) != 1) {
            skip = 1;
        }
        break;
    }
    if (!skip) {
        *(u8 **)(hs + 0xF4) = obj;
        *(s8 *)(hs + 0x196) = -0x78;
    }
}

void exitControl(void *arg0, s32 arg1) {
    u8 *obj = arg0;
    u8 *st = *(u8 **)(obj + 0x68);
    s16 idx = *(s16 *)(st + 0x14);
    u8 *entry;
    void *hits[8]; /* asm: sp+0x54 array; 8 is a guess from frame size */
    s32 count;
    s32 i;

    /* arg1 is spilled by the asm but never read back */
    if (idx >= 0 && idx < 0x19) {
        entry = &D_800A1120_A1D20[idx * 4];
        /* sig mismatch: mainGetGameFlag takes one arg; asm also passes entry in $a1 (ignored) */
        if (entry[0] != 0xFF
            && ((s32 (*)(u8, void *))mainGetGameFlag)(entry[0], entry) != entry[1]) {
            return;
        }
        if (entry[2] != 0xFF
            && ((s32 (*)(u8, void *))mainGetGameFlag)(entry[2], entry) != entry[3]) {
            return;
        }
    }

    /* 6 args: f12, f14, a2 (raw word obj+0x14), a3, stack 0 and &hits */
    count = hitPlayer(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14),
                      (f32) *(s32 *)(st + 0x10), 0, hits);
    if (count <= 0) {
        return;
    }
    /* asm handles hits[0] alone for odd counts and then pairs; the per-hit code
       is identical in every branch, so one ordered loop reproduces it */
    for (i = 0; i < count; i++) {
        if (exitHitFacing(st, hits[i])) {
            exitHitApply(obj, st, hits[i]);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/exitControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void doorControl(void *arg0, s32 arg1) {
    u8 *obj = arg0;
    u8 *st;
    u8 *best = NULL;
    void *bestState;            /* asm: not set when best->type == 0x33 (stack garbage) */
    void **lists[2];
    s32 counts[2];
    s32 k;
    s32 i;
    s32 n;
    f32 bestDist = -100.0f;
    f32 radius2;
    s32 idx;
    s32 sp84 = -1;
    u16 *flagsp;
    s16 type;
    s32 v0;
    u8 f4b;

    st = *(u8 **)(obj + 0x68);
    flagsp = (u16 *)(st + 0x3E);
    lists[0] = objGetPlayerlist(&counts[0]);
    lists[1] = objGetAnimPlayerlist(&counts[1]);

    radius2 = (f32) *(u16 *)(st + 0x40);
    radius2 = radius2 * radius2;

    /* nearest object in the player list and the anim-player list.
       dy uses st+0x0 (not obj+0x10), as in the asm */
    for (k = 0; k < 2; k++) {
        void **list = lists[k];

        n = counts[k];
        for (i = 0; i < n; i++) {
            u8 *e = list[i];
            f32 dx = *(f32 *)(e + 0xC) - *(f32 *)(obj + 0xC);
            f32 dy = *(f32 *)(e + 0x10) - *(f32 *)(st + 0x0);
            f32 dz = *(f32 *)(e + 0x14) - *(f32 *)(obj + 0x14);
            f32 d = dx * dx + dy * dy + dz * dz;

            if (d < bestDist || bestDist < 0.0f) {
                bestDist = d;
                best = e;
            }
        }
    }

    if (best != NULL) {
        type = *(s16 *)(best + 0x48);
        if (type == 0x33) {
            idx = 0;
        } else {
            bestState = *(void **)(best + 0x68);
            idx = *(s8 *)((u8 *)bestState + 1);
            if (idx >= 4) {
                idx -= 4;
            }
        }

        if (type == 1) {
            if (st[0x43] >= 2 && (*flagsp & 8)) {
                /* a3 = &bestState (asm leaves $a3 = sp+0x9C) */
                if (mainPlayerHas(*(s8 *)bestState, *(s8 *)((u8 *)bestState + 1), st[0x43] - 2, &bestState) != 0) {
                    *flagsp &= 0xFFF7;
                }
            }
        }

        f4b = st[0x4B];
        if (f4b & (1 << (idx & 0x1F))) {
            sp84 = idx + 0x129;
        } else if ((f4b & 0x80) && *(s32 *)((u8 *)bestState + 0x50C) == 0) {
            sp84 = idx + 0x129;
        } else if ((f4b & 0x40) && mainGetGameFlag(0) == 0) {
            sp84 = 0x206;
        } else if (*flagsp & 8) {
            if (st[0x43] >= 2) {
                sp84 = D_800A1180_A1D80[st[0x43]];
            } else if (*flagsp & 0x20) {
                sp84 = 0x96;
            } else if (*flagsp & 0x40) {
                sp84 = 0x128;
            }
        } else if (bestDist < radius2) {
            if (!(*flagsp & 1)) {
                if (!(*flagsp & 4)) {
                    if (*(s16 *)(st + 0x38) != 0) {
                        if (*(void **)(st + 8) != NULL) {
                            amSndStopXYZ(*(void **)(st + 8));
                        }
                        amSndPlayXYZ((u16) *(s16 *)(st + 0x38), *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10),
                                     *(f32 *)(obj + 0x14), 4, st + 8);
                    }
                    if (st[0x42] == 5) {
                        f32 f8 = *(f32 *)(st + 0x14);

                        objAnimSetMove(obj, st[0x46], (f8 < 0.0f) ? 1.0f : 0.0f);
                        *(f32 *)(st + 0x24) = *(f32 *)(st + 0x14);
                    }
                }
                *flagsp |= 6;
            }
        } else if (*flagsp & 1) {
            if (radius2 + 100.0f < bestDist && st[0x42] != 4) {
                if (!(*flagsp & 2)) {
                    if (*(s16 *)(st + 0x38) != 0) {
                        if (*(void **)(st + 8) != NULL) {
                            amSndStopXYZ(*(void **)(st + 8));
                        }
                        amSndPlayXYZ((u16) *(s16 *)(st + 0x38), *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10),
                                     *(f32 *)(obj + 0x14), 4, st + 8);
                    }
                    objAnimSetMove(obj, st[0x47], (*(f32 *)(st + 0x18) < 0.0f) ? 1.0f : 0.0f);
                    *(f32 *)(st + 0x24) = *(f32 *)(st + 0x18);
                }
                *flagsp = (*flagsp & 0xFFFE) | 2;
            }
        }

        /* unlock / cutscene message depending on distance */
        if (bestDist < 8000.0f) {
            if (!(*flagsp & 0x80) && sp84 != -1) {
                instUnlockMsg(bestState, sp84);
                *flagsp |= 0x80;
            }
        } else if (bestDist > 10000.0f && (*flagsp & 0x80)) {
            cutcameraActivate(bestState, sp84);
            *flagsp &= 0xFF7F;
        }

        if (*flagsp & 2) {
            if (*(void **)(st + 0xC) == NULL) {
                s16 snd = *(s16 *)(st + 0x3A);

                if (snd != 0) {
                    amSndPlayXYZ((u16) snd, *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14),
                                 1, st + 0xC);
                }
            }

            if (*flagsp & 4) {
                switch (st[0x42]) {
                case 2: {
                    s16 vel = *(s16 *)(st + 0x32);
                    s32 pos;

                    *(s32 *)(st + 0x10) += vel * arg1;
                    pos = *(s32 *)(st + 0x10);
                    if ((vel < 0 && pos < *(s16 *)(st + 0x2C)) || (vel > 0 && *(s16 *)(st + 0x2C) < pos)) {
                        *(s32 *)(st + 0x10) = *(s16 *)(st + 0x2C);
                        *flagsp = (*flagsp & 0xFFF9) | 1;
                        pos = *(s16 *)(st + 0x2C);
                    }
                    *(s16 *)obj = (s16) (*(s16 *)(st + 0x2E) + pos);
                    break;
                }
                case 1:
                case 3: {
                    s16 lim = *(s16 *)(st + 0x36);

                    *(s16 *)(st + 0x34) = (s16) (*(s16 *)(st + 0x34) + st[0x45] * arg1);
                    if (*(s16 *)(st + 0x34) >= lim) {
                        *(s16 *)(st + 0x34) = lim;
                        *flagsp = (*flagsp & 0xFFF9) | 1;
                    }
                    break;
                }
                case 4: {
                    s16 vel = *(s16 *)(st + 0x32);
                    s32 pos;

                    *(s32 *)(st + 0x10) += vel * arg1;
                    pos = *(s32 *)(st + 0x10);
                    if ((vel < 0 && pos < *(s16 *)(st + 0x2C)) || (vel > 0 && *(s16 *)(st + 0x2C) < pos)) {
                        *(s32 *)(st + 0x10) = *(s16 *)(st + 0x2C);
                        *flagsp = (*flagsp & 0xFFF9) | 1;
                        pos = *(s16 *)(st + 0x2C);
                    }
                    *(s16 *)(obj + 2) = (s16) (*(s16 *)(st + 0x30) + pos);
                    break;
                }
                case 5: {
                    f32 f0 = *(f32 *)(st + 0x14);

                    if ((f0 > 0.0f && *(f32 *)(obj + 0x28) == 1.0f) || (f0 < 0.0f && *(f32 *)(obj + 0x28) == 0.0f)) {
                        u8 a1 = st[0x48];

                        *flagsp = (*flagsp & 0xFFF9) | 1;
                        if (a1 != 0xFF) {
                            objAnimSetMove(obj, a1, 0.0f);
                            *(f32 *)(st + 0x24) = *(f32 *)(st + 0x1C);
                        }
                    }
                    break;
                }
                default:
                    break;
                }
            } else {
                switch (st[0x42]) {
                case 2: {
                    s16 vel = *(s16 *)(st + 0x32);
                    s32 pos;

                    pos = *(s32 *)(st + 0x10) - vel * arg1;
                    *(s32 *)(st + 0x10) = pos;
                    if ((vel < 0 && pos > 0) || (vel > 0 && *(s32 *)(st + 0x10) < 0)) {
                        *(s32 *)(st + 0x10) = 0;
                        *flagsp &= 0xFFFC;
                        pos = 0;
                    }
                    *(s16 *)obj = (s16) (*(s16 *)(st + 0x2E) + pos);
                    break;
                }
                case 1:
                case 3:
                    *(s16 *)(st + 0x34) = (s16) (*(s16 *)(st + 0x34) - st[0x45] * arg1);
                    if (*(s16 *)(st + 0x34) < 0) {
                        *(s16 *)(st + 0x34) = 0;
                        *flagsp &= 0xFFFC;
                    }
                    break;
                case 5: {
                    f32 f0 = *(f32 *)(st + 0x18);

                    if ((f0 > 0.0f && *(f32 *)(obj + 0x28) == 1.0f) || (f0 < 0.0f && *(f32 *)(obj + 0x28) == 0.0f)) {
                        u8 a1 = st[0x49];

                        *flagsp &= 0xFFFC;
                        if (a1 != 0xFF && (s32) a1 != (s8) obj[0x3B]) {
                            objAnimSetMove(obj, a1, 0.0f);
                            *(f32 *)(st + 0x24) = *(f32 *)(st + 0x20);
                        }
                    }
                    break;
                }
                default:
                    break;
                }
            }

            v0 = *flagsp & 2;
            if (v0 == 0) {
                if (*(s16 *)(st + 0x3C) != 0) {
                    s16 snd3c = *(s16 *)(st + 0x3C);

                    if (*(void **)(st + 8) != NULL) {
                        amSndStopXYZ(*(void **)(st + 8));
                    }
                    amSndPlayXYZ((u16) snd3c, *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14),
                                 4, st + 8);
                }
                if (*(void **)(st + 0xC) != NULL) {
                    amSndStopXYZ(*(void **)(st + 0xC));
                }
            }
            *(s16 *)obj = (s16) (*(s16 *)obj & 0xFFF0);
        } else {
            if (st[0x42] == 5 && st[0x49] != 0xFF && (*flagsp & 1)) {
                u8 a1 = st[0x48];

                if ((s32) a1 != (s8) obj[0x3B]) {
                    objAnimSetMove(obj, a1, 0.0f);
                    *(f32 *)(st + 0x24) = *(f32 *)(st + 0x1C);
                }
            }
        }

        if (st[0x42] == 5) {
            if ((*flagsp & 3) != 0 || st[0x48] != 0xFF) {
                obj[0x3A] = 1;
            } else {
                obj[0x3A] = 0;
            }
            objAnimDframe(obj, *(f32 *)(st + 0x24), (f32) arg1);
        }

        if (st[0x42] == 3 || st[0x42] == 5) {
            u8 *p4c = *(u8 **)(obj + 0x4C);

            if (*flagsp & 3) {
                *(u16 *)(p4c + 0xA) &= 0xFFFE;
            } else {
                *(u16 *)(p4c + 0xA) |= 1;
            }
        }

        if (st[0x42] == 1) {
            *(f32 *)(obj + 0x10) = *(f32 *)(st + 0x0) + (f32) *(s16 *)(st + 0x34);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/doorControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void doorUnlock(s32 arg0, s32 arg1) {
    s32 start;
    s32 end;
    s32 i;
    u16 bits = arg1 & 0xFFFF;
    void **list = objGetObjList(&start, &end);

    for (i = start; i < end; i++) {
        u8 *obj = list[i];

        if (*(s16 *)(obj + 0x48) == 7) {
            u8 *st = *(u8 **)(obj + 0x68);

            if (arg0 == st[0x44]) {
                if ((s32) st[0x4A] > 0) {
                    st[0x4A] = (u8) (st[0x4A] - 1);
                }
                if (st[0x4A] == 0) {
                    *(u16 *)(st + 0x3E) = (u16) ((*(u16 *)(st + 0x3E) & ~8) | bits);
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/doorUnlock.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 doorRegisterOpener(s32 arg0, s32 arg1) {
    s32 start;
    s32 end;
    s32 i;
    u16 bits = arg1 & 0xFFFF;
    void **list = objGetObjList(&start, &end);

    for (i = start; i < end; i++) {
        u8 *obj = list[i];

        if (*(s16 *)(obj + 0x48) == 7) {
            u8 *st = *(u8 **)(obj + 0x68);

            if (arg0 == st[0x44]) {
                st[0x4A] = (u8) (st[0x4A] + 1);
                *(u16 *)(st + 0x3E) = (u16) (*(u16 *)(st + 0x3E) | bits);
                return 1;
            }
        }
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/doorRegisterOpener.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void doorSwitchControl(void *arg0, s32 arg1) {
    u8 *obj = arg0;
    u8 *st = *(u8 **)(obj + 0x68);
    u8 *linked = *(u8 **)(st + 0x4);
    u8 t1 = st[0x8];

    if (linked == NULL) {
        *(void **)(st + 0x4) = objGetClosestControlType(*(f32 *)(obj + 0x0C), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14), 7);
    } else {
        u16 flags = *(u16 *)(*(u8 **)(linked + 0x68) + 0x3E);

        if (!(flags & 8)) {
            if (st[0xC] != 0) {
                *(f32 *)st = (flags & 5) ? 0.012f : -0.012f;
                t1 = 1;
            } else if (!(flags & 0x10)) {
                *(f32 *)(obj + 0x28) = 1.0f;
                t1 = 1;
                *(f32 *)st = 0.0f;
            } else {
                if (st[0xA] == 0xFF) {
                    if (st[0x9] != 0) {
                        st[0xA] = (u8) objTvTimes(0x1E);
                    } else {
                        st[0xA] = 0;
                    }
                }
                if (st[0x9] != 0) {
                    instQueueMsg_1arg(st[0x9]); /* sig mismatch: asm sets only a0, see alias */
                    st[0x9] = 0;
                    st[0xB] = 1;
                }
                if (st[0xA] != 0xFF) {
                    if (arg1 < (s32) st[0xA]) {
                        st[0xA] = (u8) (st[0xA] - arg1);
                    } else {
                        if (st[0xB] != 0) {
                            amDittyPlay(0xF);
                            st[0xB] = 0;
                        }
                        st[0xA] = 0;
                        t1 = 1;
                        *(f32 *)st = 0.012f;
                    }
                }
            }
        }
    }

    objAnimDframe(arg0, *(f32 *)st, (f32) arg1);
    if (t1 != st[0x8]) {
        u8 **tbl = *(u8 ***)(obj + 0x6C);
        u8 *model = tbl[*(s8 *)(obj + 0x3A)];
        u8 *entry = *(u8 **)(model + 0x74);
        u8 *hdr = *(u8 **)model;
        s32 count = *(s32 *)(hdr + 0x10);
        s32 i;

        if (entry != NULL) {
            for (i = 0; i < count; i++) {
                if (*(u32 *)(entry + 0x4) & 0x10000) {
                    *(s16 *)entry = (s16) (t1 << 8);
                }
                entry += 8;
            }
        }
        st[0x8] = t1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/doorSwitchControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void skyControl(void *arg0, s32 arg1) {
    u8 *obj = arg0;
    s32 pad[6];
    void *sp20;

    if (hitPlayer(*(f32 *)(obj + 0x0C), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14), (f32) *(s32 *)(obj + 0x8C), 0, &sp20) != 0) {
        trackSkySet(*(s32 *)(obj + 0x88), arg0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/skyControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void texscrollControl(void *arg0, s32 arg1) {
    u8 *obj = arg0;
    s16 *st = *(s16 **)(obj + 0x68);
    s32 a1;
    s32 a2;

    a1 = (st[2] * arg1) + st[4];
    st[4] = (s16) (a1 & 3);
    a2 = (st[3] * arg1) + st[5];
    st[5] = (s16) (a2 & 3);
    trackAddTextureScroll(st[0], a1 >> 2, a2 >> 2, arg1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/texscrollControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void rangetriggerControl(void *arg0, s32 arg1) {
    u8 *obj = arg0;
    u8 *st = *(u8 **)(obj + 0x3C);
    void *sp20;

    if (hitPlayer(*(f32 *)(obj + 0x0C), 0.0f, *(f32 *)(obj + 0x14), (f32) *(u16 *)(st + 0xA), 1, &sp20) > 0) {
        *(s32 *)(obj + 0x84) = *(s32 *)(st + 0xC);
    } else {
        *(s32 *)(obj + 0x84) = 0;
    }
    partUpdateTriggers(arg0, arg1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/rangetriggerControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objEnsureNotTargetted(void *arg0) {
    s32 count;
    s32 idx;
    s32 k;
    s32 a0;
    void **players;
    u8 *racer;

    players = objGetPlayerlist(&count);
    for (idx = count - 1; idx >= 0; idx--) {
        if (*((u8 *)arg0 + idx + 0x93) != 0) {
            racer = *(u8 **)((u8 *)players[idx] + 0x68);
            for (k = 5; k >= 0; k--) {
                if (*(void **)(racer + 0x1A8 + k * 4) == arg0) {
                    if (k == 0) {
                        *(s32 *)(racer + 0x1A8) = 0;
                        racer[0x1C0] = 0xFF;
                    } else {
                        a0 = k - 2;
                        if (k - 1 != 0) {
                            while (*(s32 *)(racer + 0x1A8 + a0 * 4) != 0 && a0 != 0) {
                                a0--;
                            }
                        }
                        *(s32 *)(racer + 0x1A8 + k * 4) = *(s32 *)(racer + 0x1AC + a0 * 4);
                        racer[0x1C0 + k] = racer[0x1C1 + a0];
                        *(s32 *)(racer + 0x1AC + a0 * 4) = 0;
                        racer[0x1C1 + a0] = 0xFF;
                    }
                }
            }
        }
        *((u8 *)arg0 + idx + 0x93) = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/objEnsureNotTargetted.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *GetAutoAimTarget(void *arg0, u8 *arg1) {
    u8 *racer;
    s32 k;
    s32 count;
    s32 bestCount;
    u8 bestFlag;
    void *cand;
    void *best;
    void *next;

    racer = *(u8 **)((u8 *)arg0 + 0x68);
    bestFlag = 0;
    bestCount = 0x7FFFFFFF;
    best = NULL;
    for (k = 5; k >= 0; k--) {
        cand = *(void **)(racer + 0x1A8 + k * 4);
        if (cand != NULL && *((u8 *)cand + 0xA0) == 0) {
            count = 0;
            next = *(void **)((u8 *)cand + 0xA8);
            if (next != NULL) {
                do {
                    next = *(void **)((u8 *)next + 0xA8);
                    count++;
                } while (next != NULL);
            }
            if (count < bestCount) {
                bestFlag = racer[0x1C0 + k];
                bestCount = count;
                best = cand;
            }
        }
    }
    *arg1 = bestFlag;
    return best;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/GetAutoAimTarget.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animobjControl(void *arg0, void *arg1) {
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/animobjControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animplayerInit(void *arg0, s16 *arg1) {
    u8 *racer;
    s16 *p;
    s16 id;

    racer = *(u8 **)((u8 *)arg0 + 0x68);
    id = *arg1;
    *(s16 *)(racer + 0x4C) = id;
    if (id == 0x204 || id == 0x1F5 || id == 0x1F6 || id == 0x1D2 || id == 0x2B9 || id == 0x2BA
        || id == 0x320 || id == 0x31E || id == 0x31F || id == 0x2A5 || id == 0x299 || id == 0x28A
        || id == 0x32C) {
        *(s32 *)((u8 *)arg0 + 0x8C) = 0;
    } else {
        *(s32 *)((u8 *)arg0 + 0x8C) = 8;
    }
    p = (s16 *)(racer + 0x4E);
    if (id == 0xC4 || id == 0x1B6 || id == 0x11A) {
        p[0] = 0x405A;
        p[1] = 0x20;
        p[2] = 0x405C;
        p[3] = 0x20;
        p[4] = 0x405E;
        p[5] = 0x20;
        p += 6;
    }
    *p = 0x1000;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/animplayerInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animplayerControl(void *arg0, void *arg1) {
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/animplayerControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animdroidInit(void *arg0, void *arg1) {
    u8 *racer;

    racer = *(u8 **)((u8 *)arg0 + 0x68);
    racer = racer + 0x4;
    *(s16 *)racer = 0x1000;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/animdroidInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animdroidControl(void *arg0, s32 arg1) {
    u8 *racer;

    racer = *(u8 **)((u8 *)arg0 + 0x68);
    *(s32 *)(racer + 0x0) = *(s32 *)(racer + 0x0) + arg1 * 0x4800;
    *(s16 *)(racer + 0x6) = (s16) *(s32 *)(racer + 0x0);
    *(s16 *)(racer + 0x4) = 0x2008;
    *(s16 *)(racer + 0x8) = 0x1000;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/animdroidControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animGirlEventHandler(void *arg0, s32 arg1) {
    u8 *obj = arg0;

    switch (arg1) {
    case 1:
        amSndPlayXYZ(0xDD, *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14), 4, NULL);
        break;
    case 2:
        amSndPlayXYZ(0xDE, *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14), 4, NULL);
        break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/animGirlEventHandler.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animBoyEventHandler(void *arg0, s32 arg1) {
    u8 *obj = arg0;

    switch (arg1) {
    case 1:
        amSndPlayXYZ(0xDD, *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14), 4, NULL);
        break;
    case 2:
        amSndPlayXYZ(0xDE, *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14), 4, NULL);
        break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/animBoyEventHandler.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animDogEventHandler(void *arg0, s32 arg1) {
    u8 *obj = arg0;

    switch (arg1) {
    case 1:
    case 3:
        amSndPlayXYZ(0xDD, *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14), 4, NULL);
        break;
    case 2:
    case 4:
        amSndPlayXYZ(0xDE, *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14), 4, NULL);
        break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/animDogEventHandler.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animtriggerControl(void *arg0, s32 arg1) {
    u8 *obj = arg0;
    u8 *data;
    s32 hitInfo;
    f32 x;
    f32 y;
    u8 flags;

    data = *(u8 **)(obj + 0x3C);
    x = *(f32 *)(obj + 0xC);
    y = *(f32 *)(obj + 0x10);

    if (data[0x10] & 0x40) {
        if (*(s32 *)(obj + 0x88) == 0 && explosionBlastHit(x, y, *(f32 *)(obj + 0x14), (f32) *(u16 *)(data + 0xA), 1) != 0) {
            *(s32 *)(obj + 0x88) = 1;
        }
    } else if (*(s32 *)(obj + 0x88) != 0) {
        if (hitPlayer(x, y, *(f32 *)(obj + 0x14), (f32) *(u16 *)(data + 0xC), (s32) data[0xE], &hitInfo) == 0) {
            if (data[0x11] != 0) {
                if (data[0x10] & 0x80) {
                    animseqHoldPath(data[0xF]);
                } else {
                    animseqPause();
                }
                if (*(s16 *)(data + 0x12) != 0) {
                    animseqSndStop(data[0xF]);
                }
            }
            *(s32 *)(obj + 0x88) = 0;
        }
    } else if (hitPlayer(x, y, *(f32 *)(obj + 0x14), (f32) *(u16 *)(data + 0xA), (s32) data[0xE], &hitInfo) != 0) {
        flags = data[0x10];
        if (flags & 0x80) {
            animseqStartPath(data[0xF]);
        } else if (!(flags & 0x20)) {
            animseqSetupGroup(data[0xF]);
        }
        if (*(s16 *)(data + 0x12) != 0) {
            animseqSndPlay(data[0xF], *(s16 *)(data + 0x12));
        }
        if (*(s16 *)(data + 0x14) != 0) {
            amSndPlay(*(s16 *)(data + 0x14) & 0xFFFF, NULL);
        }
        *(s32 *)(obj + 0x88) = 1;
    }
    if (*(s32 *)(obj + 0x88) != 0 && (data[0x10] & 1)) {
        animseqPlay();
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/animtriggerControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hitanimInit(void *arg0, void *arg1) {
    hitInitObjectHit(arg0, -1, 0, 8, 0, 0, 0, 20.0f, 20.0f, -1.0f, 1.0f, 0x11);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/hitanimInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hitanim2Init(void *arg0, void *arg1) {
    hitInitObjectHit(arg0, -1, 0, 8, 0, 0, 0, 20.0f, 20.0f, -1.0f, 1.0f, 0x11);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/hitanim2Init.s")
#endif

#ifdef VERSION_kiosk
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/hitanimsndInit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/spranim/hitanim2sndInit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/spranim/hitanimsndControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void muzzleFlashInit(void *arg0, void *arg1) {
    u8 *obj = arg0;
    u8 *spawn = arg1;
    u8 *state = *(u8 **)(obj + 0x68);

    state[0] = spawn[0xA];
    state[1] = spawn[0xB];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/muzzleFlashInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void severedLimbInit(void *arg0, void *arg1) {
    u8 *obj = arg0;
    u8 *spawn = arg1;
    u8 *src;
    u8 *array;
    u8 *model;
    u8 *ctl;
    u8 *state;
    u8 *list;
    u8 *entry;
    s32 cnt;
    s32 total;
    s32 i;
    void *p;

    src = *(u8 **)(spawn + 0xC);
    array = *(u8 **)(src + 0x6C);
    model = *(u8 **)(*(u8 **)(array + (s8) src[0x3A] * 4));
    ctl = *(u8 **)(obj + 0x7C);
    ctl[0] &= 0xFD;
    state = *(u8 **)(obj + 0x68);
    *(s32 *)(state + 0x4) = 0;
    *(s32 *)(state + 0x8) = 0;
    *(s32 *)(state + 0xC) = 0;
    *(s32 *)(state + 0x10) = 0;
    *(u8 **)(state + 0x0) = src;
    *(s16 *)(state + 0x14) = 0x3B6;
    state[0x17] = spawn[0x12];

    cnt = *(s16 *)(model + 0x16);
    list = *(u8 **)(model + 0x24);
    total = 0;
    for (i = 0; i < cnt; i++) {
        entry = list + i * 0x10;
        if ((s32) (s8) entry[0x1] >= (s32) spawn[0x10]) {
            if ((s32) spawn[0x11] >= (s32) (s8) entry[0x1] && !(*(u32 *)(entry + 0xC) & 0x400)) {
                total = (total + *(s16 *)(entry + 0x18)) - *(s16 *)(entry + 0x8);
            }
        }
    }

    if (total != 0) {
        p = ((void *(*)(s32, u32)) mmAlloc2)(total * 0x1E, 0xFF0000FF); /* sig mismatch */
        *(void **)(state + 0x4) = p;
        if (p != NULL) {
            p = ((void *(*)(s32, u32)) mmAlloc2)(total * 0x10, 0xFF0000FF); /* sig mismatch */
            *(void **)(state + 0x8) = p;
            if (p != NULL) {
                modMakeLimbModel(state + 0xC, obj, src, 2, 0, (s32) spawn[0x10], (s32) spawn[0x11]);
                modMakeLimbModel(state + 0x10, obj, src, 6, 0, (s32) spawn[0x10], (s32) spawn[0x11]);
                if (*(s32 *)(state + 0x10) != 0) {
                    *(s32 *)(obj + 0x3C) = 0;
                    *(f32 *)(obj + 0x1C) = (f32) mathRnd(-5, 5);
                    *(f32 *)(obj + 0x20) = (f32) mathRnd(-5, 5);
                    *(f32 *)(obj + 0x24) = (f32) mathRnd(-5, 5);
                    *(s16 *)(state + 0x18) = mathRnd(-0x1388, 0x1388);
                    *(s16 *)(state + 0x1A) = mathRnd(-0x1388, 0x1388);
                    *(s16 *)(state + 0x1C) = mathRnd(-0x1388, 0x1388);
                    if (squadsIsTribal(*(s16 *)(src + 0x4A)) != 0) {
                        state[0x1E] = 0;
                    } else {
                        state[0x1E] = 1;
                    }
                    return;
                }
            }
        }
    }
    objFreeObject(obj);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/severedLimbInit.s")
#endif

//CollectedDroneHead is in here, seemingly when the mainSaveGlobalFlags calls are made
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void severedLimbControl(void *arg0, s32 arg1) {
    u8 *obj = arg0;
    u8 *state;
    u8 *ctl;
    u8 *gf;
    void *hitObj;
    s32 hits;
    u8 *hitState;
    u8 *chr;
    u8 *slot;
    void *wd;
    s32 sel;
    s32 kind;
    s32 cA;
    s32 cB;
    s32 cC;
    s32 r;
    u16 mask;
    u16 v;
    u8 tp;

    state = *(u8 **)(obj + 0x68);
    hits = hitPlayer(*(f32 *)(obj + 0x0C), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14), 40.0f, 0, &hitObj);
    ctl = *(u8 **)(obj + 0x7C);
    if (ctl[0] & 2) {
        *(s16 *)(state + 0x18) = 0;
        *(s16 *)(state + 0x1A) = 0;
        *(s16 *)(state + 0x1C) = 0;
    } else if (*(u16 *)(ctl + 0x2) != 0) {
        r = (s32) (*(f32 *)(ctl + 0x14) * 2500.0f);
        *(s16 *)(state + 0x18) = mathRnd(-r, r);
        *(s16 *)(state + 0x1A) = mathRnd(-r, r);
        *(s16 *)(state + 0x1C) = mathRnd(-r, r);
    }
    *(s16 *)(obj + 0x0) += *(s16 *)(state + 0x18);
    *(s16 *)(obj + 0x2) += *(s16 *)(state + 0x1A);
    *(s16 *)(obj + 0x4) += *(s16 *)(state + 0x1C);

    if (arg1 < *(s16 *)(state + 0x14)) {
        *(s16 *)(state + 0x14) = *(s16 *)(state + 0x14) - arg1 * 2;
    } else {
        *(s16 *)(state + 0x14) = 0;
        if (arg1 * 2 < obj[0x39]) {
            obj[0x39] = (u8) (obj[0x39] - arg1 * 2);
        } else {
            objFreeObject(obj);
        }
    }

    kind = state[0x17];
    if (kind >= 2 && hits > 0) {
        hitState = *(u8 **)((u8 *)hitObj + 0x68);
        chr = mainGetGameCharacter((s8) hitState[0], (s8) hitState[1]);
        sel = -1;
        if (kind == 3) {
            tp = chr[0x70];
            if (tp == 0) {
                cA = 2;
                cB = 0;
                cC = 3;
            } else if (tp == 2) {
                cA = 0;
                cB = 2;
                cC = 3;
            } else if (tp == 3) {
                cA = 2;
                cB = 3;
                cC = 0;
            } else {
                cA = 3;
                cB = 2;
                cC = 0;
            }
            mask = *(u16 *)(chr + 0x0A);
            if ((mask & (1 << cB)) && *(u16 *)(chr + 0x14 + cB * 2) < *(u16 *)(chr + 0x34 + cB * 2)) {
                sel = cB;
            } else if ((mask & (1 << cA)) && *(u16 *)(chr + 0x14 + cA * 2) < *(u16 *)(chr + 0x34 + cA * 2)) {
                sel = cA;
            } else if ((mask & (1 << cC)) && *(u16 *)(chr + 0x14 + cC * 2) < *(u16 *)(chr + 0x34 + cC * 2)) {
                sel = cC;
            } else if (mask & (1 << cB)) {
                sel = cB;
            } else {
                sel = 0;
            }
        } else if (kind == 4) {
            if (*(u16 *)(chr + 0x0A) & 0x40) {
                sel = 6;
            }
        } else if (kind == 2) {
            gf = (u8 *) &globalflags;
            if (state[0x1E] == 0) {
                v = (u16) (*(u16 *)(chr + 0x6) + 1);
                *(u16 *)(chr + 0x6) = v;
                if (v >= 0x2711) {
                    *(u16 *)(chr + 0x6) = 0x2710;
                }
            } else {
                v = (u16) (*(u16 *)(chr + 0x8) + 1);
                *(u16 *)(chr + 0x8) = v;
                if (v >= 0x2711) {
                    *(u16 *)(chr + 0x8) = 0x2710;
                    v = 0x2710;
                }
                if (v == 0x64) {
                    if (!(gf[0x7A] & 1)) {
                        gf[0x7A] = (u8) (gf[0x7A] | 1);
                        mainSaveGlobalFlags(0x64, &globalflags, -1);
                    }
                } else if (v == 0xC8) {
                    if (!(gf[0x7A] & 2)) {
                        gf[0x7A] = (u8) (gf[0x7A] | 2);
                        mainSaveGlobalFlags(0xC8, &globalflags, -1);
                    }
                } else if (v == 0x12C) {
                    if (!(gf[0x7A] & 4)) {
                        gf[0x7A] = (u8) (gf[0x7A] | 4);
                        mainSaveGlobalFlags(0xD, &globalflags, -1);
                    }
                }
            }
            amDittyPlay(0xD);
        }

        if (sel != -1) {
            slot = chr + sel * 2;
            wd = controlGetWeaponDef(sel);
            *(u16 *)(slot + 0x14) = (u16) (*(u16 *)(slot + 0x14) + *(s16 *)((u8 *)wd + 0x2A));
            if (*(u16 *)(slot + 0x34) < *(u16 *)(slot + 0x14)) {
                *(u16 *)(slot + 0x14) = *(u16 *)(slot + 0x34);
            }
            dropletAdd(hitState, sel + 0x48, sel);
            amSndPlay(0x1E9, NULL);
        }
        objFreeObject(obj);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/severedLimbControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void severedLimbDestroy(void *arg0) {
    u8 *state = *(u8 **)((u8 *)arg0 + 0x68);

    if (*(void **)(state + 0x4) != NULL) {
        mmFree(*(void **)(state + 0x4));
    }
    if (*(void **)(state + 0x8) != NULL) {
        mmFree(*(void **)(state + 0x8));
    }
    if (*(void **)(state + 0xC) != NULL) {
        mmFree(*(void **)(state + 0xC));
    }
    if (*(void **)(state + 0x10) != NULL) {
        mmFree(*(void **)(state + 0x10));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/severedLimbDestroy.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void dropletInit(void *arg0, void *arg1) {
    u8 *obj = arg0;
    u8 *spawn = arg1;
    u8 *state = *(u8 **)(obj + 0x68);

    *(f32 *)(state + 0x0) = *(f32 *)(obj + 0xC);
    *(f32 *)(state + 0x4) = *(f32 *)(obj + 0x10);
    *(f32 *)(state + 0x8) = *(f32 *)(obj + 0x14);
    *(f32 *)(obj + 0x24) = -*(f32 *)(spawn + 0x10);
    mathOneFloatPY(spawn + 0xA, obj + 0x1C, obj, spawn);
    *(s16 *)(state + 0xC) = 0;
    *(s16 *)(state + 0xE) = (s16) spawn[0xE];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/dropletInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void dropletControl(void *arg0, s32 arg1) {
    u8 *obj = arg0;
    u8 *state;
    f32 dt;
    s32 flags;
    u8 hitBuf[0x28];

    dt = (f32) arg1;
    state = *(u8 **)(obj + 0x68);
    objMoveXYZ(obj, *(f32 *)(obj + 0x1C) * dt, *(f32 *)(obj + 0x20) * dt, *(f32 *)(obj + 0x24) * dt);
    *(f32 *)(obj + 0x20) = *(f32 *)(obj + 0x20) - (0.134f * dt);
    *(s16 *)(state + 0xC) = *(s16 *)(state + 0xC) + 1;
    if (*(s16 *)(state + 0xC) >= *(s16 *)(state + 0xE)) {
        if (trackNearestIntersection(0, state, obj + 0xC, hitBuf, 0, 0) != 0) {
            flags = *(s32 *)(hitBuf + 0x24);
            if (flags & 0x8000) {
                *(s32 *)(obj + 0x84) = 1;
            } else if (flags & 0x2000) {
                *(s32 *)(obj + 0x84) = 6;
            } else {
                *(s32 *)(obj + 0x84) = 4;
            }
            *(f32 *)(obj + 0xC) = *(f32 *)(hitBuf + 0x4);
            *(f32 *)(obj + 0x10) = *(f32 *)(hitBuf + 0x8);
            *(f32 *)(obj + 0x14) = *(f32 *)(hitBuf + 0xC);
            *(s16 *)(obj + 0x2E) = ((s16 (*)(f32, f32, f32)) trackGetBlock)(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14)); /* sig mismatch */
            partUpdateTriggers(obj, 2);
            objFreeObject(obj);
        }
        *(s16 *)(state + 0xC) = 0;
        *(f32 *)(state + 0x0) = *(f32 *)(obj + 0xC);
        *(f32 *)(state + 0x4) = *(f32 *)(obj + 0x10);
        *(f32 *)(state + 0x8) = *(f32 *)(obj + 0x14);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/dropletControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void splashInit(void *arg0, void *arg1) {
    u8 *obj = arg0;
    u8 *spawn = arg1;
    f32 v;

    v = *(f32 *)(spawn + 0xC);
    if (v < 0.0f) {
        v = -v;
    }
    *(s32 *)(obj + 0x8C) = 0x23;
    *(s32 *)(obj + 0x88) = (s32) (v * 0.2f) + 2;
    *(s32 *)(obj + 0x84) = 1;
    *(f32 *)(obj + 0x8) = *(f32 *)(obj + 0x8) * ((15.0f + v) * 0.03f);
    *(f32 *)(obj + 0x20) = (v * 0.25f) + 2.5f;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/splashInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void splashControl(void *arg0, s32 arg1) {
    u8 *obj = arg0;
    s16 ang[2];
    f32 vec[3];
    s32 i;

    if (*(s32 *)(obj + 0x88) != 0) {
        *(s32 *)(obj + 0x88) = *(s32 *)(obj + 0x88) - 1;
        for (i = 0; i != 3; i++) {
            f32 spd;

            spd = (f32) mathRnd(0x4B, 0x7D) * 0.01f;
            ang[0] = mathRnd(-0x8000, 0x7FFF);
            ang[1] = mathRnd(0x2400, 0x3C00);
            vec[2] = (f32) mathRnd(0x19, 0x32) * -0.1f;
            ((void (*)(void *, void *)) mathOneFloatPY)(ang, vec); /* sig mismatch */
            instQueueMsg(spd, *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14), *(f32 *)(obj + 0x10), vec[0], vec[1], vec[2]);
        }
        if (*(s32 *)(obj + 0x88) == 0) {
            partUpdateTriggers(obj, arg1);
        }
    }
    *(s32 *)(obj + 0x8C) = *(s32 *)(obj + 0x8C) - arg1;
    if (*(s32 *)(obj + 0x8C) <= 0) {
        objFreeObject(obj);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/splashControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void waterbubbleInit(void *arg0, void *arg1) {
    u8 *obj = arg0;
    u8 *spawn = arg1;
    u8 *state = *(u8 **)(obj + 0x68);
    f32 rnd;
    f32 scale;

    *(f32 *)(obj + 0x1C) = Sinf((s32) *(s16 *)(spawn + 0xA)) * *(f32 *)(spawn + 0xC);
    *(f32 *)(obj + 0x20) = 0.0f;
    *(f32 *)(obj + 0x24) = Cosf((s32) *(s16 *)(spawn + 0xA)) * *(f32 *)(spawn + 0xC);
    rnd = (f32) mathRnd(0x4B, 0x7D);
    *(f32 *)(state + 0x4) = 0.1f;
    scale = rnd * 0.01f;
    *(f32 *)(state + 0x8) = scale;
    *(f32 *)(state + 0x0) = *(f32 *)(obj + 0x8) * scale;
    *(f32 *)(state + 0xC) = *(f32 *)(spawn + 0x10);
    *(f32 *)(obj + 0x8) = *(f32 *)(state + 0x0) * 0.1f;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/waterbubbleInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void waterbubbleControl(void *arg0, s32 arg1) {
    u8 *obj = arg0;
    u8 *state;
    u8 *cam;
    f32 dt;
    f32 p;

    dt = (f32) arg1;
    state = *(u8 **)(obj + 0x68);
    cam = camGetListPtr();
    if ((*(f32 *)(cam + 0x10) - *(f32 *)(state + 0xC)) > 0.0f) {
        *(s16 *)(obj + 0x6) = (s16) (*(s16 *)(obj + 0x6) | 8);
    } else {
        *(s16 *)(obj + 0x6) = (s16) (*(s16 *)(obj + 0x6) & 0xFFF7);
    }

    if (*(f32 *)(state + 0x4) < 1.0f) {
        *(f32 *)(state + 0x4) = *(f32 *)(state + 0x4) + (dt * 0.1f);
        if (1.0f <= *(f32 *)(state + 0x4)) {
            *(f32 *)(state + 0x4) = 1.0f;
        }
        *(f32 *)(obj + 0x8) = *(f32 *)(state + 0x0) * *(f32 *)(state + 0x4);
    } else {
        objMoveXYZ(obj, *(f32 *)(obj + 0x1C) * dt, *(f32 *)(obj + 0x20) * dt, *(f32 *)(obj + 0x24) * dt);
        p = Powerf(0.95f, arg1);
        *(f32 *)(obj + 0x20) = *(f32 *)(obj + 0x20) + ((*(f32 *)(state + 0x8) - *(f32 *)(obj + 0x20)) * (1.0f - p));
        if (*(f32 *)(state + 0xC) < *(f32 *)(obj + 0x10)) {
            *(f32 *)(obj + 0x10) = *(f32 *)(state + 0xC);
            *(s32 *)(obj + 0x84) = 1;
            partUpdateTriggers(obj, 2);
            objFreeObject(obj);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/waterbubbleControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void invisibilityInit(void *arg0, void *arg1) {
    u8 *obj = arg0;
    u8 *spawn = arg1;
    s16 t;

    *(s16 *)(obj + 0x88) = (s16) ((s8) spawn[0xA] * 0x3C);
    *(s16 *)(obj + 0x8C) = 0;
    t = (s16) ((s8) spawn[0xB] * 0x3C);
    *(s16 *)(obj + 0x8E) = 0xFF;
    *(s16 *)(obj + 0x8A) = t;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/invisibilityInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void invisibilityControl(void *arg0, s32 arg1) {
    u8 *obj = arg0;
    u8 *inv = obj + 0x88;
    void *hitList[10];
    s32 hits;
    s32 i;
    u8 *hitState;

    hits = hitPlayer(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14), 40.0f, 0, hitList);
    if (*(s16 *)(inv + 0x6) == 0) {
        *(s16 *)(inv + 0x4) = (s16) (*(s16 *)(inv + 0x4) - arg1);
        if (*(s16 *)(inv + 0x4) <= 0) {
            *(s16 *)(inv + 0x4) = 0;
            if (hits == 0) {
                *(s16 *)(inv + 0x6) = (s16) arg1;
            }
        }
    } else {
        *(s16 *)(inv + 0x6) = (s16) (*(s16 *)(inv + 0x6) + arg1 * 4);
        if (*(s16 *)(inv + 0x6) >= 0x100) {
            *(s16 *)(inv + 0x6) = 0xFF;
        }
        if (hits > 0) {
            for (i = 0; i != hits; i++) {
                hitState = *(u8 **)((u8 *)hitList[i] + 0x68);
                if (*(s16 *)(hitState + 0x10E) == 0) {
                    *(s16 *)(hitState + 0x10E) = *(s16 *)(inv + 0x0);
                    *(s16 *)(inv + 0x4) = *(s16 *)(inv + 0x2);
                    if (*(s16 *)(inv + 0x4) == 0) {
                        objFreeObject(obj);
                    } else {
                        *(s16 *)(inv + 0x6) = 0;
                    }
                    amSndPlay(0x8A, NULL);
                    mizarExplosionCallBack(hitState, 0x88);
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/spranim/invisibilityControl.s")
#endif
