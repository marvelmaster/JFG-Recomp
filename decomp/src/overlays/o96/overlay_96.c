#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#define RD_U8(p, off)  (*(u8 *)((u8 *)(p) + (off)))
#define RD_S8(p, off)  (*(s8 *)((u8 *)(p) + (off)))
#define RD_S16(p, off) (*(s16 *)((u8 *)(p) + (off)))
#define RD_S32(p, off) (*(s32 *)((u8 *)(p) + (off)))
#define RD_F32(p, off) (*(f32 *)((u8 *)(p) + (off)))
#define RD_PTR(p, off) (*(u8 **)((u8 *)(p) + (off)))

extern f32 D_overlay_96_06000630;
extern f32 D_overlay_96_06000634;
extern s32 __MODULE00096;

void mathOneFloatPY(void *obj, void *out, s32 a2, s32 a3);
void runlinkSetDestructTimer(s32 module, s32 a, s32 b);
void controlEmptyPlayersHand(void *obj);
void objFreeObject(void *obj);
s32 objMoveXYZ(void *obj, f32 x, f32 y, f32 z);
void partUpdateTriggers(void *obj, s32 arg1);
void trackLightMove(void *light, f32 x, f32 y, f32 z);
s16 trackNearestIntersection(void *obj, f32 *start, f32 *dir, void *hit, s32 a, s32 b);
void hitBridgeMoveWith(void *obj, f32 *a1, f32 *a2, f32 *a3, f32 *a4, f32 *a5, f32 *a6);
void amSndPlayXYZ(u16 soundId, f32 x, f32 y, f32 z, u8 flags, void *handle);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void flareInit(void *arg0, void *arg1) {
    u8 *state = RD_PTR(arg0, 0x68);

    RD_F32(arg0, 0x24) = -RD_F32(arg1, 0x10);
    RD_S16(arg0, 0x00) = RD_S16(arg1, 0x0A);
    RD_S16(arg0, 0x04) = 0;
    RD_S16(arg0, 0x02) = RD_S16(arg1, 0x0C);
    /* asm: a2 = arg1, a3 is not set by this function */
    mathOneFloatPY(arg0, (u8 *)arg0 + 0x1C, (s32)arg1, 0);

    RD_S32(state, 0x04) = 0;
    RD_S32(state, 0x08) = 0;
    RD_S16(state, 0x1C) = 0;
    RD_S16(state, 0x1E) = (s16)(RD_U8(arg1, 0x0F) * 6);
    RD_S32(state, 0x00) = RD_S32(arg1, 0x14);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o96/overlay_96/flareInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void flareControl(void *arg0, s32 arg1) {
    u8 *state = RD_PTR(arg0, 0x68);
    s16 life;
    f32 f0;

    runlinkSetDestructTimer(__MODULE00096, 2, 2);

    life = RD_S16(state, 0x1E);
    if (life == 0) {
        s32 owner = RD_S32(state, 0x00);

        if (owner != 0) {
            controlEmptyPlayersHand((void *)owner);
        }
        objFreeObject(arg0);
        return;
    }

    if (arg1 >= life) {
        RD_S16(state, 0x1E) = 0;
        f0 = (f32)life;
    } else {
        RD_S16(state, 0x1E) = (s16)(life - arg1);
        f0 = (f32)arg1;
    }

    if (RD_S32(state, 0x00) != 0) {
        return;
    }

    if (RD_S16(state, 0x1C) == 0) {
        /* free flight: move, then sweep for a hit along the path */
        f32 start[3];
        f32 mvx;
        f32 mvy;
        f32 mvz;
        u8 hit[0x30];
        s16 res;

        start[0] = RD_F32(arg0, 0x0C);
        start[1] = RD_F32(arg0, 0x10);
        start[2] = RD_F32(arg0, 0x14);
        RD_S16(arg0, 0x02) = (s16)(RD_S16(arg0, 0x02) + (arg1 << 10));
        RD_S16(arg0, 0x00) = (s16)(RD_S16(arg0, 0x00) + (arg1 << 11));

        mvx = RD_F32(arg0, 0x1C) * f0;
        mvy = RD_F32(arg0, 0x20) * f0 + D_overlay_96_06000630 * f0 * f0;
        mvz = RD_F32(arg0, 0x24) * f0;
        objMoveXYZ(arg0, mvx, mvy, mvz);
        RD_F32(arg0, 0x20) = RD_F32(arg0, 0x20) + D_overlay_96_06000634 * f0;

        res = trackNearestIntersection(arg0, start, (f32 *)((u8 *)arg0 + 0x0C), hit, 0, 0);
        RD_S16(state, 0x1C) = res;

        if (res != 0) {
            f32 len2 = RD_F32(arg0, 0x1C) * RD_F32(arg0, 0x1C) +
                       RD_F32(arg0, 0x20) * RD_F32(arg0, 0x20) +
                       RD_F32(arg0, 0x24) * RD_F32(arg0, 0x24);
            f32 inv = len2;
            f32 nx;
            f32 ny;
            f32 nz;

            if (len2 > 0.0f) {
                inv = 1.0f / sqrtf(len2);
            }
            nx = (RD_F32(hit, 0x04) - RD_F32(arg0, 0x1C) * inv) - RD_F32(arg0, 0x0C);
            ny = (RD_F32(hit, 0x08) - RD_F32(arg0, 0x20) * inv) - RD_F32(arg0, 0x10);
            nz = (RD_F32(hit, 0x0C) - RD_F32(arg0, 0x24) * inv) - RD_F32(arg0, 0x14);
            objMoveXYZ(arg0, nx, ny, nz);

            RD_S32(state, 0x0C) = RD_S32(hit, 0x00);
            if (RD_PTR(hit, 0x00) != NULL) {
                u8 *hobj = RD_PTR(hit, 0x00);

                if (RD_S16(hobj, 0x48) == 7) {
                    RD_S32(state, 0x0C) = 0;
                    RD_S16(state, 0x1E) = 10;
                } else {
                    u8 *model = RD_PTR(hobj, 0x5C);

                    mathMtxXFMF(model + (RD_U8(model, 0x12B) << 6), RD_F32(arg0, 0x0C), RD_F32(arg0, 0x10),
                                RD_F32(arg0, 0x14), (f32 *)(state + 0x10), (f32 *)(state + 0x14),
                                (f32 *)(state + 0x18));
                }
            } else {
                s32 flags = RD_S32(hit, 0x24);
                s32 type = RD_S32(hit, 0x28);

                if (flags & 0x2000) {
                    RD_S16(arg0, 0x02) = 0;
                    RD_S16(arg0, 0x04) = 0;
                    RD_S32(arg0, 0x84) = 6;
                    partUpdateTriggers(arg0, arg1);
                    objFreeObject(arg0);
                    amSndPlayXYZ(0x214, RD_F32(arg0, 0x0C), RD_F32(arg0, 0x10), RD_F32(arg0, 0x14), 4, NULL);
                    return;
                }
                if (type == 3) {
                    RD_F32(arg0, 0x1C) = RD_F32(hit, 0x10) * 8.0f;
                    RD_F32(arg0, 0x20) = RD_F32(hit, 0x14);
                    RD_F32(arg0, 0x24) = RD_F32(hit, 0x18) * 8.0f;
                    RD_S16(state, 0x1C) = 0;
                }
            }
        }

        /* block_20 */
        {
            u8 *light = RD_PTR(state, 0x04);

            if (light != NULL) {
                trackLightMove(light, RD_F32(arg0, 0x0C), RD_F32(arg0, 0x10), RD_F32(arg0, 0x14));
            }
        }
        RD_S32(arg0, 0x84) = 1;
        partUpdateTriggers(arg0, arg1);
    } else {
        /* attached to a moving object */
        u8 *obj = RD_PTR(state, 0x0C);

        if (obj == NULL) {
            return;
        }
        if (RD_S16(obj, 0x48) == 0x37) {
            hitBridgeMoveWith(obj, (f32 *)(state + 0x10), (f32 *)(state + 0x14), (f32 *)(state + 0x18),
                              (f32 *)((u8 *)arg0 + 0x0C), (f32 *)((u8 *)arg0 + 0x10), (f32 *)((u8 *)arg0 + 0x14));
        } else if (RD_S16(obj, 0x48) == 0x4E) {
            if (RD_S32(obj, 0x88) <= 0) {
                RD_S32(state, 0x0C) = 0;
                RD_S16(state, 0x1C) = 0;
                RD_F32(arg0, 0x1C) = 0.0f;
                RD_F32(arg0, 0x20) = 0.0f;
                RD_F32(arg0, 0x24) = 0.0f;
            }
        } else {
            u8 *model = RD_PTR(obj, 0x5C);

            if (RD_S16(model, 0x12C) != 0) {
                f32 mx;
                f32 my;
                f32 mz;

                mathMtxXFMF(model + (RD_U8(model, 0x12B) << 6) + 0x80, RD_F32(state, 0x10), RD_F32(state, 0x14),
                            RD_F32(state, 0x18), &mx, &my, &mz);
                RD_S16(arg0, 0x00) = (s16)((RD_S16(arg0, 0x00) + RD_S16(obj, 0x00)) - RD_S16(model, 0x128));
                RD_S16(arg0, 0x02) = (s16)((RD_S16(arg0, 0x02) + RD_S16(obj, 0x02)) - RD_S16(model, 0x126));
                RD_S16(arg0, 0x04) = (s16)((RD_S16(arg0, 0x04) + RD_S16(obj, 0x04)) - RD_S16(model, 0x124));
                objMoveXYZ(arg0, mx - RD_F32(arg0, 0x0C), my - RD_F32(arg0, 0x10), mz - RD_F32(arg0, 0x14));
            }
        }
        {
            u8 *light = RD_PTR(state, 0x04);

            if (light != NULL) {
                trackLightMove(light, RD_F32(arg0, 0x0C), RD_F32(arg0, 0x10), RD_F32(arg0, 0x14));
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o96/overlay_96/flareControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void flareThrow(void *arg0, s16 arg1, s16 arg2, f32 arg3) {
    RD_S32(RD_PTR(arg0, 0x68), 0x00) = 0;
    RD_S16(arg0, 0x02) = arg2;
    RD_F32(arg0, 0x24) = -arg3;
    RD_S16(arg0, 0x00) = arg1;
    mathOneFloatPY(arg0, (u8 *)arg0 + 0x1C, arg2, arg1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o96/overlay_96/flareThrow.s")
#endif
