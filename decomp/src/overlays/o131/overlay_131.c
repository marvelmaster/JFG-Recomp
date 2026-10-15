#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern s32 __MODULE00131;
extern f32 D_overlay_131_083007C4[];
extern f32 D_overlay_131_083007D4[];
extern u8 D_overlay_131_083007E4[];
extern f32 D_overlay_131_083007F0;
f32 Sinf(s32 angle);
void runlinkSetDestructTimer(s32 a, s32 b, s32 c);
void objMoveXYZ(void *obj, f32 x, f32 y, f32 z);
void trackLightMove(s32 id, f32 x, f32 y, f32 z);
void trackLightDelete(s32 id);
s32 trackLightAdd(f32 x, f32 y, f32 z, f32 radius, f32 range, s32 a, s32 b, s32 c);
void objFreeObject(void *obj);
void partUpdateTriggers(void *obj, s32 arg);
void squadsAddInterestingEvent(void *obj, s16 x, s16 y, s16 z, s32 a, s32 b, s32 c);
s16 objTvTimes(s32 arg);
void mathOneFloatPY(void *obj);
void hitInitObjectHit(void *arg0, s16 arg1, s8 arg2, s8 arg3, s16 arg4, s16 arg5, s16 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, u16 arg11);
s32 trackNearestIntersection(s32 a, void *from, void *to, void *out, s32 mask, s32 c);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void twisterInit(void *arg0, void *arg1) {
    u8 *obj;
    u8 *pl;
    u8 *st;
    s32 idx;
    f32 f0;

    obj = (u8 *) arg0;
    pl = (u8 *) arg1;
    *(f32 *) (obj + 0x1C) = 0.0f;
    *(f32 *) (obj + 0x20) = 0.0f;
    *(f32 *) (obj + 0x24) = -*(f32 *) (pl + 0x10);
    *(s16 *) (obj + 0x00) = *(s16 *) (pl + 0xC);
    *(s16 *) (obj + 0x04) = 0;
    *(s16 *) (obj + 0x02) = *(s16 *) (pl + 0xE);
    mathOneFloatPY(obj + 0x1C);

    idx = pl[0xA] - 1;
    if (idx < 0) {
        idx = 0;
    } else if (idx >= 4) {
        idx = 3;
    }

    st = *(u8 **) (obj + 0x68);
    st[0x10] = 0;
    *(f32 *) (st + 0x00) = *(f32 *) (obj + 0x0C);
    *(f32 *) (st + 0x04) = *(f32 *) (obj + 0x10);
    *(f32 *) (st + 0x08) = *(f32 *) (obj + 0x14);
    *(s16 *) (st + 0x12) = objTvTimes(pl[0xB] * 6);
    *(s32 *) (st + 0x18) = *(s32 *) (pl + 0x14);
    st[0x11] = (u8) (0xFE - idx);
    *(f32 *) (st + 0x14) = D_overlay_131_083007C4[idx];
    f0 = D_overlay_131_083007D4[idx];
    hitInitObjectHit(obj, pl[0xA] << 8, 1, 4, 0, 0, 0, f0, f0, -1.0f, 1.0f, 0x11);
    *(s32 *) (obj + 0x88) = 0;
    *(s32 *) (obj + 0x8C) = trackLightAdd(*(f32 *) (obj + 0x0C), *(f32 *) (obj + 0x10), *(f32 *) (obj + 0x14),
                                          400.0f, 250.0f, 0x40, 0x20, 0xFF);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o131/overlay_131/twisterInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void twisterControl(void *arg0, s32 arg1) {
    u8 *obj;
    u8 *st;
    u8 *ps;
    u8 hit[0x28];
    s32 done;
    s32 flags;
    s32 r;
    f32 dt;
    f32 sn;

    obj = (u8 *) arg0;
    runlinkSetDestructTimer(__MODULE00131, 2, 2);
    st = *(u8 **) (obj + 0x68);
    done = 0;
    if (*(s16 *) (st + 0x12) > 0 && *(s16 *) (*(u8 **) (obj + 0x4C) + 6) > 0) {
        *(s32 *) (obj + 0x84) = 0;
        if (st[0x11] < 0xFF) {
            *(s32 *) (obj + 0x84) = 4;
            st[0x11] = st[0x11] + 1;
        }
        if (arg1 < *(s16 *) (st + 0x12)) {
            dt = (f32) arg1;
        } else {
            dt = (f32) *(s16 *) (st + 0x12);
        }

        if (st[0x10] == 0) {
            objMoveXYZ(obj, *(f32 *) (obj + 0x1C) * dt, *(f32 *) (obj + 0x20) * dt, *(f32 *) (obj + 0x24) * dt);
            if (*(s32 *) (obj + 0x8C) != 0) {
                trackLightMove(*(s32 *) (obj + 0x8C), *(f32 *) (obj + 0x0C), *(f32 *) (obj + 0x10), *(f32 *) (obj + 0x14));
            }
            *(s32 *) (obj + 0x88) = *(s32 *) (obj + 0x88) + (arg1 << 11);
            sn = Sinf(*(s32 *) (obj + 0x88));
            ps = *(u8 **) (obj + 0x70);
            *(s16 *) (ps + 0x1A) = (s16) (s32) (sn * -*(f32 *) (st + 0x14));
            *(s16 *) (ps + 0x3E) = -*(s16 *) (ps + 0x1A);
            *(s32 *) (obj + 0x84) = *(s32 *) (obj + 0x84) | 3;

            if (*(s16 *) (*(u8 **) (st + 0x18) + 0x48) == 1) {
                squadsAddInterestingEvent(obj, (s16) (s32) *(f32 *) (obj + 0x0C), (s16) (s32) *(f32 *) (obj + 0x10),
                                          (s16) (s32) *(f32 *) (obj + 0x14), 4, 1, 0);
            }

            r = trackNearestIntersection((s32) obj, *(u8 **) (obj + 0x4C) + 0x0C, obj + 0x0C, hit, 0, 0);
            st[0x10] = (u8) r;
            if ((r & 0xFF) != 0) {
                *(f32 *) (st + 0x00) = *(f32 *) (hit + 0x04);
                *(f32 *) (st + 0x04) = *(f32 *) (hit + 0x08);
                *(f32 *) (st + 0x08) = *(f32 *) (hit + 0x0C);
                *(s32 *) (st + 0x0C) = *(s32 *) (hit + 0x24);
                objMoveXYZ(obj, *(f32 *) (st + 0x00) - *(f32 *) (obj + 0x0C),
                           *(f32 *) (st + 0x04) - *(f32 *) (obj + 0x10),
                           *(f32 *) (st + 0x08) - *(f32 *) (obj + 0x14));
                flags = *(s32 *) (st + 0x0C);
                if (!(flags & 0x2000) || (flags & 0x8000)) {
                    *(s32 *) (obj + 0x84) = *(s32 *) (obj + 0x84) | 4;
                }
            } else {
                *(f32 *) (st + 0x00) = *(f32 *) (obj + 0x0C);
                *(f32 *) (st + 0x04) = *(f32 *) (obj + 0x10);
                *(f32 *) (st + 0x08) = *(f32 *) (obj + 0x14);
            }
            *(s16 *) (st + 0x12) = *(s16 *) (st + 0x12) - arg1;
        } else {
            flags = *(s32 *) (st + 0x0C);
            if (flags & 0x8000) {
                *(s32 *) (obj + 0x84) = *(s32 *) (obj + 0x84) | 0x0C;
            } else if (flags & 0x2000) {
                *(s16 *) (obj + 0x02) = 0;
                *(s32 *) (obj + 0x84) = *(s32 *) (obj + 0x84) | 0x18;
                *(s16 *) (obj + 0x04) = 0;
            } else {
                *(s32 *) (obj + 0x84) = *(s32 *) (obj + 0x84) | 0x24;
            }
            done = 1;
        }
    } else {
        done = 1;
    }

    partUpdateTriggers(obj, 2);
    if (done != 0) {
        if (*(s32 *) (obj + 0x8C) != 0) {
            trackLightDelete(*(s32 *) (obj + 0x8C));
        }
        objFreeObject(obj);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o131/overlay_131/twisterControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void twisterDraw(void **arg0, void **arg1, void **arg2, void *arg3) {
    u8 *obj;
    u8 *st;
    u8 *ent;
    Gfx *dl;
    s16 pos[3];
    f32 vec[3];
    f32 sp98;
    f32 sp78;
    s32 mdl;
    s32 i;

    obj = (u8 *) arg3;
    runlinkSetDestructTimer(__MODULE00131, 2, 2);
    st = *(u8 **) (obj + 0x68);
    pos[0] = 0;
    pos[1] = 0;
    pos[2] = 0;
    sp98 = 0.0f;
    sp78 = *(f32 *) (st + 0x14) * D_overlay_131_083007F0;
    mdl = *(s32 *) *(u8 **) (obj + 0x6C);
    ent = D_overlay_131_083007E4;

    for (i = 0; i < 2; i++) {
        vec[0] = Sinf(*(s32 *) (obj + 0x88)) * *(f32 *) (st + 0x14);
        if (i == 0) {
            vec[0] = -vec[0];
        }
        vec[1] = 0.0f;
        vec[2] = 0.0f;
        pointListRPY(1, (s16 *) obj, (s32 *) vec, vec);
        vec[0] += *(f32 *) (obj + 0x0C);
        vec[1] += *(f32 *) (obj + 0x10);
        vec[2] += *(f32 *) (obj + 0x14);
        sprSetIA2ColOverride(ent[0], ent[1], ent[2], ent[3], ent[4], ent[5]);
        camDoSprite(arg0, arg1, arg2, pos, mdl, 0x0E, 0xFF);
        ent += 6;
    }
    sprClearIA2ColOverride();

    dl = (Gfx *) *arg0;
    dl->words.w1 = 0;
    dl->words.w0 = 0xE7000000;
    dl++;
    dl->words.w0 = 0xFA000000;
    dl->words.w1 = -1;
    dl++;
    dl->words.w1 = -1;
    dl->words.w0 = 0xFB000000;
    dl++;
    *arg0 = dl;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o131/overlay_131/twisterDraw.s")
#endif
