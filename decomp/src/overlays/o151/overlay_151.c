#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
typedef struct Cfg151 {
    /* 0x00 */ u8 pad00[0x24];
    /* 0x24 */ f32 unk24;
} Cfg151;

typedef struct Obj151 {
    /* 0x00 */ s16 unk0;        /* heading */
    /* 0x02 */ u8 pad02[0xA];
    /* 0x0C */ f32 unkC;        /* x */
    /* 0x10 */ f32 unk10;       /* y */
    /* 0x14 */ f32 unk14;       /* z */
    /* 0x18 */ u8 pad18[0x4];
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ u8 pad28[0x20];
    /* 0x48 */ s16 unk48;       /* object type */
    /* 0x4A */ u8 pad4A[0x2];
    /* 0x4C */ Cfg151 *unk4C;
    /* 0x50 */ u8 pad50[0x4];
    /* 0x54 */ f32 *unk54;      /* optional scale pointer */
    /* 0x58 */ u8 pad58[0x10];
    /* 0x68 */ void *unk68;     /* per-type state */
    /* 0x6C */ u8 pad6C[0x10];
    /* 0x7C */ u8 *unk7C;       /* flag byte, bit 1 = done */
} Obj151;

typedef struct SpiderState151 {
    /* 0x00 */ u16 unk0;        /* bit 0x2000 = no re-target */
    /* 0x02 */ u8 unk2;         /* bit 0x20 = has target */
    /* 0x03 */ u8 pad03[0x17];
    /* 0x1A */ u8 unk1A;        /* mission id */
    /* 0x1B */ u8 unk1B;        /* eat state */
    /* 0x1C */ u8 pad1C[0x8];
    /* 0x24 */ Obj151 *unk24;   /* owning squad object */
    /* 0x28 */ u8 pad28[0x10];
    /* 0x38 */ f32 unk38;
    /* 0x3C */ u8 pad3C[0x4];
    /* 0x40 */ f32 unk40;
    /* 0x44 */ u8 pad44[0x7];
    /* 0x4B */ u8 unk4B;
    /* 0x4C */ u8 pad4C[0x5];
    /* 0x51 */ u8 unk51;        /* eat timer */
    /* 0x52 */ u8 pad52[0x12];
    /* 0x64 */ Obj151 *unk64;   /* target object */
} SpiderState151;

typedef struct SquadState151 {
    /* 0x00 */ u8 pad00[0x7A];
    /* 0x7A */ s8 unk7A;        /* region index */
} SquadState151;

typedef struct SpitState151 {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s16 unk4;        /* lifetime timer */
    /* 0x06 */ u8 unk6;
} SpitState151;

typedef struct SpitSetup151 {
    /* 0x00 */ u8 pad00[0xA];
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 unkB;
    /* 0x0C */ f32 unkC;        /* angle pair for mathOneFloatPY */
    /* 0x10 */ f32 unk10;
    /* 0x14 */ s32 unk14;
} SpitSetup151;

typedef struct SpitParticle151 {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ s16 unk2;
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ u8 pad08[0x2];
    /* 0x0A */ s16 unkA;
} SpitParticle151; /* Size: 0x0C bytes */

extern s32 __MODULE00151;
extern SpitParticle151 D_overlay_151_09700FF0[0x10];
extern u8 D_overlay_151_097010B0;
extern u8 D_overlay_151_097010B1;
extern u8 D_overlay_151_097010B2;
extern u8 *CpuTexSpaceA[4];
extern u8 *CpuTexSpaceB[4];

Obj151 *squadsGetClosestFood(s16 x, s16 z, s32 range, s8 kind);
Obj151 *squadsGetClosestPlayer(void);
s32 squadsIsObjectEdible(void *obj);
void objRegisterDependancy(void *arg0, void *arg1);
void objRemoveDependancy(void *obj);
void runlinkSetDestructTimer(s32 overlayIndex, s32 selfDestructTimer, s32 refCount);
s32 TryToSetMission(s32 arg0, s32 arg1, u8 arg2, u8 arg3, u8 arg4);
void UpdateOrSetAnim(s32 arg0, f32 arg1, s32 arg2);
s32 DoesSquaddieWantToFire(f32 arg0, f32 arg1, s16 arg2);
s32 IsPointInRegionIdx(f32 x, f32 z, s32 a, s32 b);
s32 IsPointInSibling(f32 x, f32 z);
s32 DoesLineCrossRegionIdx(f32 x0, f32 z0, f32 x1, f32 z1, s32 region, s32 a, s32 b, s32 c);
f32 GetRangeSquared2D(f32 x0, f32 z0, f32 x1, f32 z1);
s32 objTvTimes(s32 arg0);
void mathOneFloatPY(void *arg0, f32 *arg1);
void hitInitObjectHit(void *arg0, s16 arg1, s8 arg2, s8 arg3, s16 arg4, s16 arg5, s16 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, u16 arg11);
void objFreeObject(void *obj);
void amSndPlayXYZ(s32 sfx, f32 x, f32 y, f32 z, s32 arg4, s32 arg5);
void bloodSpurtAdd(f32 x, f32 y, f32 z, f32 vx, f32 vy, f32 vz, s32 colour, s32 arg7, f32 scale);
void TryToSetAnim(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
s32 TryToUpdateAnim(s32 arg0, f32 arg1);
void ClearMissionFields(s32 arg0, s32 arg1);
f32 Sinf(s16 angle);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void BTSBSpider(Obj151 *arg0) {
    SpiderState151 *state;
    Obj151 *food;

    state = arg0->unk68;
    food = squadsGetClosestFood((s16) arg0->unkC, (s16) arg0->unk14, 0x320,
                                ((SquadState151 *) state->unk24->unk68)->unk7A);
    runlinkSetDestructTimer(__MODULE00151, 2, 2);
    if ((food != NULL) && (TryToSetMission(4, 0x14, 0, 0, 0) != 0)) {
        state->unk38 = food->unkC;
        state->unk64 = food;
        state->unk40 = food->unk14;
        objRegisterDependancy(arg0, food);
    }
    if (state->unk1A != 0x14) {
        /* asm: only a0-a2 are set for this call */
        if (DoesSquaddieWantToFire(0.0f, 400.0f, 0x17F0) != 0) {
            if ((state->unk1A != 5) && (TryToSetMission(4, 5, 0, 0, 0) != 0)) {
                UpdateOrSetAnim(6, 1.0f, 5);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o151/overlay_151/BTSBSpider.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void SpiderMover(Obj151 *arg0) {
    SpiderState151 *state;
    SquadState151 *ownerState;
    Obj151 *player;
    s32 blocked;
    s32 k;
    s32 k2;
    s32 temp;
    s32 absT;
    s32 angleR;
    s16 angleS;
    s16 aimAngle;
    f32 dist;
    f32 tx;
    f32 tz;
    f32 dist2;
    f32 tx2;
    f32 tz2;

    state = arg0->unk68;
    ownerState = (SquadState151 *) state->unk24->unk68;
    player = squadsGetClosestPlayer();
    blocked = 0;

    /* probe six headings around the current one, stop on the first blocked probe */
    for (k = 6; k != 0; k--) {
        temp = k - 3;
        angleS = (s16) (arg0->unk0 + (temp << 12));
        absT = (temp > 0) ? temp : -temp;
        dist = (5.0f - (f32) absT) * arg0->unk4C->unk24;
        tx = arg0->unkC - (Sinf(angleS) * dist);
        tz = arg0->unk14 - (Cosf((s32) angleS) * dist);
        /* asm: a3 is not set for this call */
        if ((IsPointInRegionIdx(tx, tz, ownerState->unk7A, 0) == 0) || (IsPointInSibling(tx, tz) == 0)) {
            blocked = 1;
            break;
        }
    }

    if (GetRangeSquared2D(arg0->unkC, arg0->unk14, state->unk38, state->unk40) < 600.0f) {
        blocked = 1;
        state->unk2 = (u8) (state->unk2 & 0xDF);
    }

    if (blocked == 0) {
        state->unk2 = (u8) (state->unk2 & 0xDF);
        return;
    }
    if (state->unk0 & 0x2000) {
        return;
    }

    /* pick a new wander target, up to four tries */
    for (k2 = 4; k2 != 0; k2--) {
        if ((k2 == 4) && (IsPointInRegionIdx(player->unkC, player->unk14, -0x8000, ownerState->unk7A) != 0)) {
            aimAngle = (s16) Arctanf(arg0->unkC - player->unkC, arg0->unk14 - player->unk14);
            angleR = mathRnd(-0x1770, 0x1770) + aimAngle;
        } else {
            angleR = mathRnd(-0x8000, 0x7FFF);
        }
        dist2 = (f32) mathRnd(0xC8, 0x190);
        tx2 = arg0->unkC - (Sinf((s16) angleR) * dist2);
        tz2 = arg0->unk14 - (Cosf(angleR) * dist2);
        if (DoesLineCrossRegionIdx(arg0->unkC, arg0->unk14, tx2, tz2, ownerState->unk7A, 0, -1, 0xFF) == 0) {
            state->unk38 = tx2;
            state->unk40 = tz2;
            state->unk2 = (u8) (state->unk2 | 0x20);
            return;
        }
    }
    state->unk38 = arg0->unkC;
    state->unk40 = arg0->unk14;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o151/overlay_151/SpiderMover.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void SpiderEatStuffMover(Obj151 *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    SpiderState151 *state;
    Obj151 *player;
    s32 colour;
    s32 spurtX;
    s32 spurtY;

    state = arg0->unk68;
    player = squadsGetClosestPlayer();
    *arg1 = state->unk38;
    *arg2 = arg0->unk10;
    *arg3 = state->unk40;
    if (squadsIsObjectEdible(state->unk64) == 0) {
        state->unk1B = 5;
    }
    switch (state->unk1B) {
    case 1:
        if (GetRangeSquared2D(arg0->unkC, arg0->unk14, state->unk38, state->unk40) < 600.0f) {
            TryToSetAnim(3, 0x36, 0, 0);
            state->unk1B = 4;
            amSndPlayXYZ(0x105, arg0->unkC, arg0->unk10, arg0->unk14, 4, 0);
        }
        state->unk51 = 1;
        break;
    case 4:
        if ((state->unk64->unk48 != 0x4D) && (mathRnd(1, 7) == 1)) {
            if (arg0->unk54 != NULL) {
                colour = (s32) (*arg0->unk54 * 255.0f);
            } else {
                colour = 0xFF;
            }
            spurtX = mathRnd(-3, 3);
            spurtY = mathRnd(1, 4);
            bloodSpurtAdd(arg0->unkC, arg0->unk10, arg0->unk14, (f32) spurtX, (f32) spurtY,
                          (f32) mathRnd(-3, 3), colour, 1, 1.0f);
        }
        if (TryToUpdateAnim(3, 1.0f) != 0) {
            state->unk51 = (u8) (state->unk51 - 1);
            if (state->unk51 == 0) {
                objFreeObject(state->unk64);
                state->unk1B = 5;
            }
        }
        break;
    case 5:
        state->unk1B = 9;
        state->unk64 = player;
        /* fallthrough */
    case 9:
        if ((TryToUpdateAnim(3, 1.0f) != 0) || (state->unk4B != 3)) {
            state->unk4B = 0;
            objRemoveDependancy(arg0);
            ClearMissionFields(1, 0);
        }
        break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o151/overlay_151/SpiderEatStuffMover.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void SpiderSpitInit(Obj151 *arg0, SpitSetup151 *arg1) {
    SpitState151 *state;
    u8 *flags;

    state = arg0->unk68;
    arg0->unk1C = 0.0f;
    arg0->unk20 = 0.0f;
    arg0->unk24 = -arg1->unk10;
    mathOneFloatPY(&arg1->unkC, &arg0->unk1C);
    hitInitObjectHit(arg0, (s16) ((arg1->unkA + 1) << 8), 1, 1, 0, 0, 0, 16.0f, 16.0f, 1.0f, 0.75f, 0x11);
    state->unk4 = (s16) objTvTimes(arg1->unkB * 6);
    state->unk6 = arg1->unkA;
    state->unk0 = arg1->unk14;
    flags = arg0->unk7C;
    *flags = (u8) (*flags & 0xFFFD);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o151/overlay_151/SpiderSpitInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void SpiderSpitControl(Obj151 *arg0, s32 arg1) {
    SpitState151 *state;

    state = arg0->unk68;
    state->unk4 = (s16) (state->unk4 - arg1);
    if ((state->unk4 < 0) || (*arg0->unk7C & 2)) {
        objFreeObject(arg0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o151/overlay_151/SpiderSpitControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_151_0970084C_1FE24B4(s32 arg0, s32 arg1) {
    SpitParticle151 *p;
    s16 angle;
    s16 speed;
    s16 x;
    s32 idx;

    idx = D_overlay_151_097010B1;
    p = &D_overlay_151_09700FF0[idx];
    D_overlay_151_097010B1 += 1;
    angle = (s16) mathRnd(0, 0x10000);
    speed = (s16) mathRnd(0x96, 0xFF);
    p->unk0 = (s16) (arg0 << 7);
    x = (s16) (arg1 << 7);
    p->unk2 = x;
    p->unk4 = (s16) (Sinf(angle) * (f32) speed);
    p->unk6 = (s16) (Cosf((s32) angle) * (f32) speed);
    p->unkA = (s16) ((s32) x / speed);
    if ((s32) D_overlay_151_097010B1 >= 0x10) {
        D_overlay_151_097010B1 = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o151/overlay_151/func_overlay_151_0970084C_1FE24B4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Spit texture generator. Per call: optional reset of the 8 spit slots, one
// particle splat into the "cur" buffer, a 5-point blur cur -> next, then the
// rows of next are packed into IA16 texels at cfg+0x20 (intensity = value,
// alpha = clamped value * (value >> 4)). Even rows swap the two halves of each
// group of 4 texels (index ^ 2); odd rows are linear.
// Loop counts follow the asm: bnez/addiu delay-slot counters run n+1 times.
void GenerateSpitTexture(s32 texIdx, u8 *cfg, s32 reset) {
    SpitParticle151 *p;
    u8 *cur;
    u8 *next;
    u8 *src;
    u8 *dst;
    u16 *out;
    u16 *rowOut;
    s32 w;
    s32 h;
    s32 cnt;
    s32 n;
    s32 r;
    s32 c;
    s32 v;
    s32 f;
    s32 a;

    w = cfg[0];
    h = cfg[1];

    if (D_overlay_151_097010B2 != 0) {
        cur = CpuTexSpaceA[texIdx];
    } else {
        cur = CpuTexSpaceB[texIdx];
    }

    cnt = reset;
    if (reset != 0) {
        D_overlay_151_097010B1 = 0;
        for (n = 7; n >= 0; n--) {
            /* sig mismatch: asm passes (w, h, count); callee takes 2 args */
            ((void (*)(s32, s32, s32))func_overlay_151_0970084C_1FE24B4)(w, h, cnt);
            cnt = n;
        }
        D_overlay_151_097010B0 = 0;
        D_overlay_151_097010B2 = 0;
    }

    D_overlay_151_097010B0 = (u8) (D_overlay_151_097010B0 + 1);
    if (D_overlay_151_097010B0 >= 3) {
        /* sig mismatch: asm passes (w, h, 0) */
        ((void (*)(s32, s32, s32))func_overlay_151_0970084C_1FE24B4)(w, h, cnt);
        D_overlay_151_097010B0 = 0;
    }

    /* splat the 16 spit particles into cur (8.8 fixed point x, y) */
    p = D_overlay_151_09700FF0;
    for (n = 0; n < 0x10; n++, p++) {
        if (p->unkA != 0) {
            cur[((s16) p->unk2 >> 8) * w + ((s16) p->unk0 >> 8)] = (u8) (p->unkA * 8);
            p->unk0 = (s16) (p->unk0 + p->unk4);
            p->unk2 = (s16) (p->unk2 + p->unk6);
            p->unkA = (s16) (p->unkA - 1);
        }
    }

    D_overlay_151_097010B2 ^= 1;
    if (D_overlay_151_097010B2 != 0) {
        next = CpuTexSpaceA[texIdx];
    } else {
        next = CpuTexSpaceB[texIdx];
    }

    /* 5-point blur over rows 1..h-2: (below + 4 * centre + left + right + above) >> 3 */
    src = cur + w + 1;
    dst = next + w + 1;
    if (h != 2) {
        r = h - 3;
        do {
            if (w != 2) {
                c = w - 3;
                do {
                    v = src[w] + 4 * src[0] + src[-1] + src[1] + src[-w];
                    *dst = (u8) (v >> 3);
                    dst++;
                    src++;
                } while (c-- != 0);
            }
            dst += 2;
            src += 2;
        } while (r-- != 0);
    }

    /* pack next into IA16 rows, h rows of w texels, starting at cfg+0x20 */
    src = next;
    out = (u16 *) (cfg + 0x20);
    for (r = h - 1; r >= 0; r--) {
        rowOut = out;
        for (c = 0; c < w; c++) {
            v = *src;
            src++;
            f = v >> 4;
            a = v;
            if (f != 0) {
                a = v * f;
            }
            if (a >= 0x100) {
                a = 0xFF;
            }
            rowOut[(r & 1) ? c : (c ^ 2)] = (u16) ((v << 8) | a);
        }
        out += w;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o151/overlay_151/GenerateSpitTexture.s")
#endif
