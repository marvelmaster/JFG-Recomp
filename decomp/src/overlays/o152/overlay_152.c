#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
typedef struct SpriteEntry152 {
    /* 0x00 */ f32 depth;       /* negated camera Z, sort key */
    /* 0x04 */ u8 group;        /* group index into D_overlay_152_09800ED0 */
    /* 0x05 */ u8 idx;          /* entry index within the group */
    /* 0x06 */ u8 pad06[2];
} SpriteEntry152; /* Size: 0x08 bytes */

extern u8 D_overlay_152_09800ED0[];              /* 5 groups of 0x90 bytes, 8 entries of 0x10 */
extern f32 D_overlay_152_09800EC0;
extern f32 D_overlay_152_098012F8;
extern void *D_overlay_152_09801300;             /* pointer to target object */
extern SpriteEntry152 D_overlay_152_098011A0[];  /* sprite sort list */
extern f32 D_overlay_152_09800EC4;               /* wave/push threshold scale */
extern f32 D_overlay_152_09800EC8;               /* sprite height offset */
extern f32 D_overlay_152_09800ECC;               /* sprite height divisor */
extern f32 D_overlay_152_098012FC;               /* XZ distance to target */
extern s32 iDeltaTime;
void *objGetPlayerNo(s32);

f32 Sinf(s32);
f32 Cosf(s32);
f32 sqrtf(f32);
f32 SmoothValue(s16 arg0, s16 arg1, u16 arg2);
s16 mathDiffAngle(s16, s16);
f32 camGetProjZ(f32, f32, f32);
void camDoSpriteDirect(s32, s32, s32, s32, s32, s32, s32, s32, f32, f32, s32, s32);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void GetWaveAboutPosition(void *arg0, void *arg1, s32 arg2, f32 *arg3, f32 *arg4, f32 *arg5) {
    u8 *obj = (u8 *)arg0;
    u8 *grp = (u8 *)arg1;
    s32 t;
    s16 sp2A;
    f32 scale;
    f32 sp20;

    t = *(s32 *)(D_overlay_152_09800ED0 + 0x410) - (arg2 * 0x708);
    if (t < 0) {
        t = 0;
    }
    if (t >= 0x10000) {
        t = 0xFFFF;
    }
    *(s16 *)(grp + 0x88) = (s16)SmoothValue(*(s16 *)(D_overlay_152_09800ED0 + 0x41A),
                                             *(s16 *)(D_overlay_152_09800ED0 + 0x41C), (u16)t);
    *(s16 *)(grp + 0x88) = (s16)(*(s16 *)(grp + 0x88) +
                                 (((s32)(grp - D_overlay_152_09800ED0) / 0x90) * 0x3333));

    sp2A = (s16)(s32)((Sinf(*(s16 *)(grp + 0x84) + (arg2 * -0x1147)) * 2000.0f) + D_overlay_152_09800EC0);
    scale = (f32)(arg2 * 0x5A) * D_overlay_152_098012F8;

    sp20 = Cosf((s32)sp2A);
    *arg3 = (Sinf((s32)*(s16 *)(grp + 0x88)) * sp20 * scale) + *(f32 *)(obj + 0xC);
    *arg4 = (Sinf((s32)sp2A) * scale) + *(f32 *)(obj + 0x10);
    sp20 = Cosf((s32)sp2A);
    *arg5 = (Cosf((s32)*(s16 *)(grp + 0x88)) * sp20 * scale) + *(f32 *)(obj + 0x14);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o152/overlay_152/GetWaveAboutPosition.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void GetPushPosition(void *arg0, void *arg1, s32 arg2, f32 *arg3, f32 *arg4, f32 *arg5) {
    u8 *obj = (u8 *)arg0;
    u8 *target = (u8 *)D_overlay_152_09801300;
    u8 *state = *(u8 **)(obj + 0x68);
    u8 *owner = *(u8 **)(state + 0x24);
    u8 *ownerState = *(u8 **)(owner + 0x68);
    s16 angle = (s16)((s32)(s8)ownerState[0x1B] << 8);
    s32 sinAng = angle + 0x4000;
    s16 yaw;
    s16 pitch;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 horiz2;
    f32 dist;
    f32 clampLen;
    f32 len;
    f32 cosPitch;
    f32 k;
    f32 f22;
    f32 f26;
    f32 f20;
    f32 scale;

    dx = (Sinf(sinAng) * 0.0f) + (*(f32 *)(target + 0xC) - *(f32 *)(obj + 0xC));
    dy = *(f32 *)(target + 0x10) - *(f32 *)(obj + 0x10);
    dz = (Cosf(sinAng) * 0.0f) + (*(f32 *)(target + 0x14) - *(f32 *)(obj + 0x14));
    yaw = (s16)Arctanf(dx, dz);
    horiz2 = (dx * dx) + (dz * dz);
    pitch = (s16)Arctanf(dy, sqrtf(horiz2));
    dist = sqrtf((dy * dy) + horiz2);

    clampLen = 720.0f * D_overlay_152_098012F8;
    len = dist;
    if (clampLen < dist) {
        len = clampLen;
    }

    cosPitch = Cosf((s32)pitch);
    f22 = Sinf((s32)yaw) * cosPitch * len;
    f26 = Sinf((s32)pitch) * len;
    f20 = Cosf((s32)yaw) * cosPitch * len;

    k = (f32)((((s32)((u8 *)arg1 - D_overlay_152_09800ED0)) / 0x90) - 2);
    f22 = f22 + (Sinf((s32)angle) * k * 56.0f);
    f20 = f20 + (Cosf((s32)angle) * k * 56.0f);

    scale = (f32)arg2 / 8.0f;
    *arg3 = *(f32 *)(obj + 0xC) + (f22 * scale);
    *arg4 = *(f32 *)(obj + 0x10) + (f26 * scale);
    *arg5 = *(f32 *)(obj + 0x14) + (f20 * scale);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o152/overlay_152/GetPushPosition.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void BTSBWaterBoss(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *state = *(u8 **)(obj + 0x68);
    u8 *ed = D_overlay_152_09800ED0;
    u8 *ownerObj = *(u8 **)(obj + 0x4C);
    u8 *s3 = *(u8 **)(ownerObj + 0x40);   /* output table cursor, 0x34 stride */
    u8 *target;
    u8 *owner;
    u8 *ownerState;
    u8 *grp;
    u8 *s0;
    f32 *ent;
    s16 angle;
    s32 g;
    s32 j;
    s32 s2;
    s32 a3;
    s32 lo;
    s32 newv;
    f32 dx;
    f32 dz;
    f32 t;
    f32 wx;
    f32 wy;
    f32 wz;
    f32 px;
    f32 py;
    f32 pz;

    if (*(s32 *)(state + 0xA8) == 0) {
        /* one-time init: state->A8 = wave/sprite block, scale from owner byte 2 */
        *(s32 *)(state + 0xA8) = (s32)ed;
        owner = *(u8 **)(state + 0x24);
        ownerState = *(u8 **)(owner + 0x68);
        /* u8 load in asm, so the signed fixup for negative values is dead */
        D_overlay_152_098012F8 = (f32)ownerState[0x2] / 142.0f;
        target = objGetPlayerNo(0);
        D_overlay_152_09801300 = target;
        /* 'a1' is stale in the asm; objGetPlayerNo only takes the player index */
        angle = (s16)Arctanf(*(f32 *)(target + 0xC) - *(f32 *)(obj + 0xC),
                             *(f32 *)(target + 0x14) - *(f32 *)(obj + 0x14));
        *(s16 *)(ed + 0x416) = 0;
        *(s32 *)(ed + 0x410) = 0;
        *(u16 *)(ed + 0x414) = 0x177;
        *(s16 *)(ed + 0x418) = angle;
        *(s16 *)(ed + 0x41A) = angle;
        *(s16 *)(ed + 0x41C) = angle;
        *(s16 *)(ed + 0x420) = 1;
        *(s16 *)(ed + 0x422) = 0;
        *(s16 *)(ed + 0x424) = 0;

        /* asm: 5 passes (bnez tests the pre-decrement counter), 5 groups of 0x90 */
        for (g = 0; g < 5; g++) {
            grp = ed + g * 0x90;
            *(s32 *)(grp + 0x80) = 0;
            *(s16 *)(grp + 0x84) = (s16)mathRnd(0, 0xFFFF);
            *(s16 *)(grp + 0x86) = (s16)mathRnd(0x113, 0x1F4);
            *(s16 *)(grp + 0x88) = angle;
            *(s16 *)(grp + 0x8A) = angle;
            *(s16 *)(grp + 0x8C) = angle;
        }
    }

    /* distance to target in XZ */
    target = (u8 *)D_overlay_152_09801300;
    dx = *(f32 *)(target + 0xC) - *(f32 *)(obj + 0xC);
    dz = *(f32 *)(target + 0x14) - *(f32 *)(obj + 0x14);
    D_overlay_152_098012FC = sqrtf((dx * dx) + (dz * dz));

    /* mode switch on distance: 1 (idle) -> 2 (approach), 3 (retreat) -> 2 */
    switch (*(s16 *)(ed + 0x420)) {
    case 1:
        if (D_overlay_152_098012FC < (D_overlay_152_09800EC4 * D_overlay_152_098012F8)) {
            *(s16 *)(ed + 0x420) = 2;
            *(s16 *)(ed + 0x422) = 0;
            *(s16 *)(ed + 0x424) = 2;
        }
        break;
    case 3:
        if ((2000.0f * D_overlay_152_098012F8) < D_overlay_152_098012FC) {
            *(s16 *)(ed + 0x420) = 2;
            *(s16 *)(ed + 0x422) = 0x80;
            *(s16 *)(ed + 0x424) = -1;
        }
        break;
    }

    /* 0x416 phase, decays by iDeltaTime * 0x20A (asm: shift/add chain) */
    *(s16 *)(ed + 0x416) = (s16)(*(s16 *)(ed + 0x416) - iDeltaTime * 0x20A);

    /* smoothed angle 0x418, clamped timer 0x410 */
    a3 = (*(s32 *)(ed + 0x410) < 0xFFFF) ? *(s32 *)(ed + 0x410) : 0xFFFF;
    *(s16 *)(ed + 0x418) = (s16)(s32)SmoothValue(*(s16 *)(ed + 0x41A), *(s16 *)(ed + 0x41C),
                                                  (u16)a3);

    /* 0x410 accumulates rate 0x414 * iDeltaTime; wraps at 100001 and picks a new target */
    lo = (s32)*(u16 *)(ed + 0x414) * iDeltaTime;
    newv = *(s32 *)(ed + 0x410) + lo;
    *(s32 *)(ed + 0x410) = newv;
    if ((lo + newv) >= 0x186A1) {
        *(s16 *)(ed + 0x41A) = *(s16 *)(ed + 0x418);
        *(s16 *)(ed + 0x41C) = (s16)mathRnd(0, 0xFFFF);
        *(s32 *)(ed + 0x410) = 0;
    }

    /* 0x422 timer: moves by dir (0x424) * iDeltaTime; flips mode at the ends */
    *(s16 *)(ed + 0x422) = (s16)(*(s16 *)(ed + 0x422) + *(s16 *)(ed + 0x424) * iDeltaTime);
    if (*(s16 *)(ed + 0x422) >= 0x80) {
        *(s16 *)(ed + 0x420) = 3;
    } else if (*(s16 *)(ed + 0x422) <= 0) {
        *(s16 *)(ed + 0x420) = 1;
    }

    /* per group (5 passes): advance phase, fill 8 entries by mode, then sprite copy */
    for (g = 0; g < 5; g++) {
        grp = ed + g * 0x90;
        *(s16 *)(grp + 0x84) = (s16)(*(s16 *)(grp + 0x84) + *(s16 *)(grp + 0x86) * iDeltaTime);

        switch (*(s16 *)(ed + 0x420)) {
        case 1:
            /* asm: 8 passes, index is 8 - counter, i.e. j + 1 */
            for (j = 0; j < 8; j++) {
                GetWaveAboutPosition(obj, grp, j + 1, &wx, &wy, &wz);
                ent = (f32 *)(grp + j * 0x10);
                ent[0] = wx;
                ent[1] = wy;
                ent[2] = wz;
            }
            break;
        case 2:
            for (j = 0; j < 8; j++) {
                t = (Cosf(((s32)*(s16 *)(ed + 0x422) << 8) + 0x8000) + 1.0f) * 0.5f;
                GetWaveAboutPosition(obj, grp, j + 1, &wx, &wy, &wz);
                GetPushPosition(obj, grp, j + 1, &px, &py, &pz);
                ent = (f32 *)(grp + j * 0x10);
                ent[0] = ((px - wx) * t) + wx;
                ent[1] = ((py - wy) * t) + wy;
                ent[2] = ((pz - wz) * t) + wz;
            }
            break;
        case 3:
            for (j = 0; j < 8; j++) {
                GetPushPosition(obj, grp, j + 1, &wx, &wy, &wz);
                ent = (f32 *)(grp + j * 0x10);
                ent[0] = wx;
                ent[1] = wy;
                ent[2] = wz;
            }
            break;
        default:
            break;
        }

        /* walk entries from the top: store scale in each entry's w, copy 0x34-stride table */
        s0 = grp + 0x70;
        s2 = 0xEF03;
        for (j = 0; j < 8; j++) {
            s3 += 0x34;
            s0 -= 0x10;
            *(f32 *)(s0 + 0x1C) = ((Sinf(*(s16 *)(ed + 0x416) - s2 + 8) / D_overlay_152_09800ECC)
                                   + D_overlay_152_09800EC8) * D_overlay_152_098012F8;
            *(f32 *)(s3 - 0x1C) = *(f32 *)(s3 - 0x28);
            *(f32 *)(s3 - 0x18) = *(f32 *)(s3 - 0x24);
            *(f32 *)(s3 - 0x14) = *(f32 *)(s3 - 0x20);
            *(f32 *)(s3 - 0x28) = *(f32 *)(s0 + 0x10);
            *(f32 *)(s3 - 0x24) = *(f32 *)(s0 + 0x14);
            *(f32 *)(s3 - 0x20) = *(f32 *)(s0 + 0x18);
            *(f32 *)(s3 - 0x10) = *(f32 *)(s0 + 0x1C) * 25.0f;
            *(f32 *)(s3 - 0xC) = *(f32 *)(s0 + 0x1C) * 25.0f;
            s2 -= 0x2225;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o152/overlay_152/BTSBWaterBoss.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 WaterBossDrawSprites(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5,
                         u8 arg6, s32 arg7) {
    u8 *state = *(u8 **)((u8 *)arg0 + 0x68);
    s32 count = 0;
    s32 g;
    s32 i;
    s32 k;
    s32 swapped;
    s32 draw;
    SpriteEntry152 tmp;
    SpriteEntry152 *e;
    f32 *p;

    if (*(s32 *)(state + 0xA8) == 0) {
        return 0;
    }

    /* collect visible entries, grouped by bit in state->unkA4 */
    for (g = 0; g < 5; g++) {
        for (i = 0; i < 8; i++) {
            p = (f32 *)(D_overlay_152_09800ED0 + (g * 0x90) + (i * 0x10));
            draw = (arg7 == 0);
            if (*(u16 *)(state + 0xA4) & (1 << g)) {
                draw = arg7;
            }
            if (draw != 0) {
                D_overlay_152_098011A0[count].depth = -camGetProjZ(p[0], p[1], p[2]);
                D_overlay_152_098011A0[count].group = (u8)g;
                D_overlay_152_098011A0[count].idx = (u8)i;
                count++;
            }
        }
    }

    if (count != 0) {
        /* bubble sort, descending by depth */
        if (count - 1 > 0) {
            do {
                swapped = 0;
                for (k = 0; k < count - 1; k++) {
                    if (D_overlay_152_098011A0[k].depth < D_overlay_152_098011A0[k + 1].depth) {
                        tmp = D_overlay_152_098011A0[k];
                        D_overlay_152_098011A0[k] = D_overlay_152_098011A0[k + 1];
                        D_overlay_152_098011A0[k + 1] = tmp;
                        swapped = 1;
                    }
                }
            } while (swapped != 0);
        }

        for (i = 0; i < count; i++) {
            e = &D_overlay_152_098011A0[i];
            p = (f32 *)(D_overlay_152_09800ED0 + (e->group * 0x90) + (e->idx * 0x10));
            camDoSpriteDirect(arg1, arg2, arg3, arg4, (s32)p[0], (s32)p[1], (s32)p[2], 0,
                              p[3], 0.0f, arg5, (s32)arg6);
        }
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o152/overlay_152/WaterBossDrawSprites.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
f32 SmoothValue(s16 arg0, s16 arg1, u16 arg2) {
    s16 diff;

    diff = mathDiffAngle(arg0, arg1);
    return ((Sinf(((s32)arg2 >> 1) + 0xC000) + 1.0f) * 0.5f * (f32)diff) + (f32)arg0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o152/overlay_152/SmoothValue.s")
#endif
