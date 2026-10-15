#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern s32 __MODULE00104;
extern f32 D_overlay_104_068006B0;
extern f32 D_overlay_104_068006B4;
void trackMakePolylist(s32 a, f32 *b, f32 *c, f32 *d, s32 e, s32 f, s32 g);
s32 trackGetIntersect(s32 a, f32 *b, f32 *c, f32 d, s32 e, void *hit);
s32 hitPlayer(f32 x, f32 y, f32 z, f32 r, s32 a4, void **out);
s32 mainGetGameFlag(s32 flag, s32 *out, s32 arg2);
void *mainGetGameCharacter(s8 a0, s8 a1, s32 a2, void *a3);
void objAnimDframe(void *obj, f32 rate, f32 frame);
void objFreeObject(void *obj);
void partUpdateTriggers(void *obj, s32 arg1, s32 arg2);
void runlinkSetDestructTimer(s32 module, s32 a1, s32 a2);
void texAnimateSprite(void *arg0, s32 *arg1, s32 arg2, void *arg3, s32 arg4);
void instQueueMsg(void *obj, s32 msg);
void amSndPlay(u16 soundID, void *handlePtr);
/* end decomp: externs */
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void healthPickupInit(void *arg0, void *arg1, s32 arg2) {
    u8 *obj = (u8 *) arg0;
    u8 *rec = (u8 *) arg1;
    u8 *d = *(u8 **) (obj + 0x68);
    f32 ptsA[3];
    f32 ptsB[3];
    f32 radius;
    f32 offY;
    void *hitOut;
    s32 type;

    if ((arg2 == 0) && (rec[0x3] != 1)) {
        u8 *node = *(u8 **) (*(u8 **) (obj + 0x40) + 0x50);

        offY = *(f32 *) (node + 0x4);
        radius = *(f32 *) (node + 0xC);
        ptsA[0] = *(f32 *) (obj + 0xC);
        ptsA[1] = *(f32 *) (obj + 0x10) + offY + radius;
        ptsA[2] = *(f32 *) (obj + 0x14);
        ptsB[0] = *(f32 *) (obj + 0xC);
        ptsB[1] = (*(f32 *) (obj + 0x10) + offY) - radius;
        ptsB[2] = *(f32 *) (obj + 0x14);
        trackMakePolylist(1, ptsA, ptsB, &radius, 0x2000, 0, 0);
        if (trackGetIntersect(0, ptsA, ptsB, radius, 1, &hitOut) != 0) {
            *(f32 *) (obj + 0xC) = ptsB[0];
            *(f32 *) (obj + 0x10) = ptsB[1] - offY;
            *(f32 *) (obj + 0x14) = ptsB[2];
        }
    }
    *(f32 *) (d + 0x0) = *(f32 *) (obj + 0xC);
    *(f32 *) (d + 0x4) = *(f32 *) (obj + 0x10);
    *(f32 *) (d + 0x8) = *(f32 *) (obj + 0x14);
    *(u8 *) (d + 0xC) = (u8) *(s16 *) (obj + 0x2E);
    *(s16 *) (d + 0xE) = 0;
    *(s16 *) (d + 0x10) = 0;
    *(s8 *) (d + 0xD) = (s8) rec[0xB];
    *(s16 *) (d + 0x12) = *(s16 *) (rec + 0x0);
    *(u8 *) (d + 0x14) = rec[0xC];
    if (rec[0x3] == 1) {
        *(s16 *) (d + 0x10) = 0x1E0;
    }
    type = (s8) rec[0xA];
    *(s32 *) (obj + 0x8C) = 0xFF;
    *(s32 *) (obj + 0x88) = type;
    *(f32 *) (obj + 0x8) = **(f32 **) (obj + 0x40);
    if (type == 1) {
        *(f32 *) (obj + 0x8) = *(f32 *) (obj + 0x8) * D_overlay_104_068006B0;
    }
    if (type == 2) {
        *(f32 *) (obj + 0x8) = *(f32 *) (obj + 0x8) * D_overlay_104_068006B4;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o104/overlay_104/healthPickupInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void healthPickupControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *d = *(u8 **) (obj + 0x68);
    s32 sp70;
    void *hitObj;
    u8 *hit4C;
    u8 *hitData;
    u8 *ch;
    s32 nHits;
    s32 nearHit = 0;
    s32 v0;
    s32 a2;
    s32 rnd;
    u32 animBits = 0x3C23D70A;

    runlinkSetDestructTimer(__MODULE00104, 2, 2);
    if (*(s16 *) (d + 0x10) != 0) {
        *(s16 *) (d + 0x10) = (s16) (*(s16 *) (d + 0x10) - arg1);
        v0 = *(s16 *) (d + 0x10);
        if (v0 <= 0) {
            objFreeObject(arg0);
            return;
        }
        if (v0 < 0x80) {
            *(s32 *) (obj + 0x8C) = v0 * 2;
        }
    }

    if (*(s32 *) (obj + 0x8C) == 0) {
        u8 *flagByte = *(u8 **) (obj + 0x7C);

        *(f32 *) (obj + 0xC) = *(f32 *) (d + 0x0);
        *(f32 *) (obj + 0x10) = *(f32 *) (d + 0x4);
        *(f32 *) (obj + 0x14) = *(f32 *) (d + 0x8);
        *(s16 *) (obj + 0x2E) = (s16) d[0xC];
        if (flagByte != NULL) {
            *flagByte |= 2;
        }
    }

    if (*(s16 *) (d + 0x12) == 0xE9) {
        if (mainGetGameFlag(d[0x14] + 0x2F, &sp70, 0xC) != 0) {
            objFreeObject(arg0);
            return;
        }
        objAnimDframe(arg0, *(f32 *) &animBits, (f32) arg1);
    } else {
        sp70 = 9;
        texAnimateSprite(*(void **) (*(u8 **) (obj + 0x6C) + ((s8) obj[0x3A] * 4)), &sp70, 0xC, obj + 0x28, arg1);
    }

    nHits = hitPlayer(*(f32 *) (obj + 0xC), *(f32 *) (obj + 0x10), *(f32 *) (obj + 0x14), 250.0f, 0, &hitObj);
    if (nHits != 0) {
        u8 *h = (u8 *) hitObj;
        f32 dx = *(f32 *) (obj + 0xC) - *(f32 *) (h + 0xC);
        f32 dy = *(f32 *) (obj + 0x10) - *(f32 *) (h + 0x10);
        f32 dz = *(f32 *) (obj + 0x14) - *(f32 *) (h + 0x14);

        if ((((dx * dx) + (dy * dy)) + (dz * dz)) < 1024.0f) {
            nearHit = 1;
        }
    }

    if (*(s32 *) (obj + 0x8C) == 0) {
        *(s16 *) (d + 0xE) = (s16) (*(s16 *) (d + 0xE) - arg1);
        if (*(s16 *) (d + 0xE) > 0) {
            return;
        }
        *(s16 *) (d + 0xE) = 0;
        if (nearHit == 0) {
            *(s32 *) (obj + 0x8C) = arg1;
        }
        return;
    }

    v0 = *(s32 *) (obj + 0x8C) + (arg1 * 4);
    if (v0 < 0x100) {
        *(s32 *) (obj + 0x8C) = v0;
    } else {
        *(s32 *) (obj + 0x8C) = 0xFF;
    }
    if (nHits == 0) {
        return;
    }

    rnd = mathRnd(0, 0x3E8);
    if (rnd >= 0x321) {
        *(s32 *) (obj + 0x84) = *(s32 *) (obj + 0x84) | 1;
    } else {
        *(s32 *) (obj + 0x84) = *(s32 *) (obj + 0x84) & ~1;
    }
    partUpdateTriggers(arg0, arg1, nearHit);
    if (nearHit == 0) {
        return;
    }

    hit4C = *(u8 **) ((u8 *) hitObj + 0x4C);
    hitData = *(u8 **) ((u8 *) hitObj + 0x68);
    if (*(s16 *) (hit4C + 0x6) < 0x100) {
        return;
    }
    ch = (u8 *) mainGetGameCharacter((s8) hitData[0], (s8) hitData[1], nearHit, hitData);

    if (*(s16 *) (d + 0x12) == 0xE9) {
        if (*(s16 *) (ch + 0x2) >= 0xC) {
            instQueueMsg(hitData, 0x13F);
            return;
        }
        *(s16 *) (ch + 0x2) = (s16) (*(s16 *) (ch + 0x2) + 1);
        *(s16 *) (hit4C + 0x6) = (s16) (((*(s16 *) (ch + 0x2) * 5) + 4) << 8);
        instQueueMsg(hitData, 0x87);
        amSndPlay(0x1E7, 0);
        a2 = (*(s16 *) (ch + 0x2) * 5) + 4;
        mainSetGameFlag(d[0x14] + 0x2F, 1);
        v0 = a2 << 8;
    } else {
        a2 = (*(s16 *) (ch + 0x2) * 5) + 4;
        if (*(s32 *) (obj + 0x88) == 1) {
            *(s16 *) (hit4C + 0x6) = (s16) (*(s16 *) (hit4C + 0x6) + 0x500);
            amSndPlay(0x229, 0);
            v0 = a2 << 8;
        } else if (*(s32 *) (obj + 0x88) == 2) {
            v0 = a2 << 8;
            *(s16 *) (hit4C + 0x6) = (s16) v0;
            amSndPlay(0x22A, 0);
        } else {
            *(s16 *) (hit4C + 0x6) = (s16) (*(s16 *) (hit4C + 0x6) + 0x100);
            amSndPlay(0x228, 0);
            v0 = a2 << 8;
        }
        instQueueMsg(hitData, *(s32 *) (obj + 0x88) + 0x84);
    }

    if (v0 < *(s16 *) (hit4C + 0x6)) {
        *(s16 *) (hit4C + 0x6) = (s16) v0;
    }
    if (d[0xD] != 0) {
        *(s16 *) (d + 0xE) = (s16) (d[0xD] * 0x3C);
        *(s32 *) (obj + 0x8C) = 0;
    } else {
        objFreeObject(arg0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o104/overlay_104/healthPickupControl.s")
#endif
