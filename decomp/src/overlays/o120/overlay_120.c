#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern f32 D_overlay_120_07800AFC;
extern f32 D_overlay_120_07800B00;
extern f32 D_overlay_120_07800B04;
extern f32 D_overlay_120_07800AE0;
extern f32 D_overlay_120_07800AE4;
extern f32 D_overlay_120_07800AE8;
extern f32 D_overlay_120_07800AEC;
extern f32 D_overlay_120_07800AF0;
extern f32 D_overlay_120_07800AF4;
extern f32 D_overlay_120_07800AF8;
extern s32 __MODULE00120;
extern u8 multiPlayerGame;
f32 Powerf(f32 base, s32 n);
void killLight(UnkLight *light, s32 arg1);
void objFreeObject(void *obj);
void *objSetupObject(void *params, s32 arg1);
void partUpdateTriggers(void *obj, s32 arg1);
void sparkAdd(s16 *params);
s32 texAnimateSprite(s32 a0, s32 *a1, s32 a2, void *a3, s32 a4);
void runlinkSetDestructTimer(s32 a0, s32 a1, s32 a2);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fireExplosionInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *src = (u8 *) arg1;
    u8 *d = *(u8 **) (obj + 0x68);

    d[0x00] = 4;
    d[0x02] = 0;
    d[0x01] = (u8) *(s8 *) (src + 0x10);
    *(s32 *) (d + 0x08) = 0;
    d[0x03] = (u8) *(s8 *) (src + 0x12);
    d[0x0C] = (u8) *(s8 *) (src + 0x11);
    *(s16 *) (d + 0x04) = *(s16 *) (src + 0x0A);
    *(s16 *) (d + 0x06) = *(s16 *) (src + 0x0C);
    d[0x0D] = (u8) *(s8 *) (src + 0x13);
    *(s32 *) (d + 0x10) = *(s32 *) (src + 0x14);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o120/overlay_120/fireExplosionInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fireExplosionControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *d = *(u8 **) (obj + 0x68);
    u8 *owner;
    u8 *tgt;
    u8 *spawned;
    s32 animState;
    u8 spark[0x24];   /* sparkAdd init block (asm sp+0x6C) */
    u8 rec60[0x0C];   /* spawn record (asm sp+0x60) */
    u8 rec48[0x14];   /* spawn record (asm sp+0x48) */
    u8 rec9C[0x24];   /* spawn record (asm sp+0x9C) */
    s32 rndXLo;       /* asm sp+0xC8 */
    s32 rndXHi;       /* asm sp+0xC4 */
    s32 rndYLo;       /* asm sp+0xE0 */
    s32 rndYHi;       /* asm sp+0xDC */
    s32 rndCLo;       /* asm sp+0xD8 */
    s32 rndCHi;       /* asm sp+0xD4 */
    s32 rndDLo;       /* asm sp+0xD0 */
    s32 rndDHi;       /* asm sp+0xCC */
    s32 type;
    s32 n;
    s32 i;
    s32 v;
    s32 w;

    runlinkSetDestructTimer(__MODULE00120, 2, 2);
    animState = 1;
    if (texAnimateSprite(*(s32 *) *(u8 **) (obj + 0x6C), &animState, 0xF, obj + 0x28, arg1) != 0) {
        objFreeObject(arg0);
        return;
    }

    /* obj->0x78 -> object -> byte 0x3B drains by arg1 * 4, floored at 0 */
    owner = *(u8 **) (obj + 0x78);
    if (owner != NULL) {
        tgt = *(u8 **) owner;
        if (tgt != NULL) {
            w = tgt[0x3B] - arg1 * 4;
            if (w < 0) {
                w = 0;
            }
            tgt[0x3B] = (u8) w;
        }
    }

    if (*(s8 *) d != 0) {
        *(s8 *) d = (s8) (*(s8 *) d - 1);

        /* d[1] == 2: spark burst */
        if (d[1] == 2) {
            *(f32 *) (spark + 0x08) = *(f32 *) (obj + 0x0C);
            *(f32 *) (spark + 0x0C) = *(f32 *) (obj + 0x10);
            *(f32 *) (spark + 0x10) = *(f32 *) (obj + 0x14);
            *(s16 *) (spark + 0x18) = 0x14;
            spark[0x1A] = 0x0A;
            spark[0x1B] = 0xFF;
            *(s32 *) (spark + 0x1C) = -0x7F01;
            *(s32 *) (spark + 0x20) = 0xFF0000FF;
            n = 4;
            if (multiPlayerGame != 0) {
                n = 2;
            }
            /* asm: loop runs n times (decrement in branch delay slot) */
            for (i = n; i != 0; i--) {
                *(s16 *) (spark + 0x00) = (s16) mathRnd(-0x8000, 0x7FFF);
                *(s16 *) (spark + 0x02) = (s16) mathRnd(0x1000, 0x3000);
                *(f32 *) (spark + 0x04) = (f32) mathRnd(0x46, 0x5A) * D_overlay_120_07800AE0;
                *(f32 *) (spark + 0x14) = (f32) mathRnd(0x19, 0x32) * D_overlay_120_07800AE0;
                sparkAdd((s16 *) spark);
            }
        }

        /* spawn record for the object objSetupObject creates below */
        if (d[1] == 2) {
            type = 0x14A;
        } else if (d[3] == 0) {
            type = 0x139;
        } else {
            type = 0x138;
        }
        *(s16 *) (rec9C + 0x00) = (s16) type;
        *(s16 *) (rec9C + 0x04) = (s16) (s32) *(f32 *) (obj + 0x0C);
        *(s16 *) (rec9C + 0x06) = (s16) (s32) *(f32 *) (obj + 0x10);
        *(s16 *) (rec9C + 0x08) = (s16) (s32) *(f32 *) (obj + 0x14);
        rec9C[0x1C] = d[0x0C];
        *(s32 *) (rec9C + 0x20) = *(s32 *) (d + 0x10);

        switch (d[1]) {
        case 0:
            rndXLo = -0x8000;
            rndXHi = 0x7FFF;
            rndYLo = 0x3000;
            rndYHi = 0x3C00;
            rndCLo = 0x32;
            rndCHi = 0x4B;
            rndDLo = 0x96;
            rndDHi = 0xB4;
            *(s16 *) (rec9C + 0x0E) = 0xB4;
            *(f32 *) (rec9C + 0x18) = D_overlay_120_07800AE8;
            break;
        case 1:
            v = *(s16 *) (d + 0x04);
            rndXLo = v - 0x3000;
            rndXHi = v + 0x3000;
            v = *(s16 *) (d + 0x06);
            rndYLo = v - 0x2000;
            rndYHi = v + 0x2000;
            rndCLo = 0x32;
            rndCHi = 0x4B;
            rndDLo = 0x96;
            rndDHi = 0xB4;
            *(s16 *) (rec9C + 0x0E) = 0xB4;
            *(f32 *) (rec9C + 0x18) = D_overlay_120_07800AEC;
            break;
        case 2:
            if (*(s8 *) (d + 0x0D) != 0) {
                v = *(s16 *) (d + 0x04);
                rndXLo = v - 0x3000;
                rndXHi = v + 0x3000;
                w = *(s16 *) (d + 0x06);
                rndYLo = w - 0x2000;
                rndYHi = w + 0x2000;
            } else {
                rndXLo = -0x8000;
                rndXHi = 0x7FFF;
                rndYLo = 0x1000;
                rndYHi = 0x2000;
            }
            rndCLo = 0xF;
            rndCHi = 0x19;
            rndDLo = 0x32;
            rndDHi = 0x50;
            *(s16 *) (rec9C + 0x0E) = 0x78;
            *(f32 *) (rec9C + 0x18) = D_overlay_120_07800AF0;
            break;
        default:
            /* asm: no writes; loop below reuses stale rnd* stack slots */
            break;
        }

        /* scatter loop: count 3 / 2 / 1 by arg1 */
        if (d[1] != 0 && multiPlayerGame == 0) {
            n = 3;
            if (arg1 >= 4) {
                n = 2;
            }
            if (arg1 >= 5) {
                n = 1;
            }
            for (i = n; i != 0; i--) {
                *(s16 *) (rec9C + 0x0A) = (s16) mathRnd(rndXLo, rndXHi);
                *(s16 *) (rec9C + 0x0C) = (s16) mathRnd(rndYLo, rndYHi);
                *(f32 *) (rec9C + 0x10) = (f32) mathRnd(rndCLo, rndCHi) * D_overlay_120_07800AF4;
                *(f32 *) (rec9C + 0x14) = (f32) mathRnd(rndDLo, rndDHi) * D_overlay_120_07800AE4;
                spawned = objSetupObject(rec9C, 1);
                if (spawned != NULL) {
                    *(s32 *) (spawned + 0x3C) = 0;
                }
            }
        }

        /* d[1] == 1 with timer just expired: spawn 0x13D when height is in band */
        if (multiPlayerGame == 0 && d[1] == 1 && *(s8 *) (d + 0x0D) != 0 && *(s8 *) d == 0) {
            v = *(s16 *) (d + 0x06);
            if (v >= 0x3001 && v < 0x5000 && arg1 < 5) {
                *(s16 *) (rec60 + 0x00) = 0x13D;
                *(s16 *) (rec60 + 0x04) = (s16) (s32) *(f32 *) (obj + 0x0C);
                *(s16 *) (rec60 + 0x06) = (s16) (s32) *(f32 *) (obj + 0x10);
                *(s16 *) (rec60 + 0x08) = (s16) (s32) *(f32 *) (obj + 0x14);
                rec60[0x0A] = (u8) (s32) (*(f32 *) (rec9C + 0x10) * 85.0f);
                rec60[0x0B] = (u8) (*(s16 *) (rec9C + 0x0C) >> 7);
                spawned = objSetupObject(rec60, 1);
                if (spawned != NULL) {
                    *(s32 *) (spawned + 0x3C) = 0;
                }
            }
        }
    }

    /* d[2] == 0: owner byte 0x3B set to 0x80 */
    if (*(s8 *) (d + 0x02) == 0) {
        owner = *(u8 **) (obj + 0x78);
        if (owner != NULL) {
            tgt = *(u8 **) owner;
            if (tgt != NULL) {
                tgt[0x3B] = 0x80;
            }
        }
    }

    if (*(s8 *) (d + 0x02) >= 0 && d[1] < 2) {
        if (*(s8 *) (d + 0x02) == 0 || *(s8 *) (d + 0x02) >= 0x14) {
            *(s16 *) (rec48 + 0x00) = 0x13B;
            *(s16 *) (rec48 + 0x04) = (s16) (s32) *(f32 *) (obj + 0x0C);
            *(s16 *) (rec48 + 0x06) = (s16) (s32) (*(f32 *) (obj + 0x10) + 3.0f);
            *(s16 *) (rec48 + 0x08) = (s16) (s32) *(f32 *) (obj + 0x14);
            *(s16 *) (rec48 + 0x0A) = 0;
            *(s16 *) (rec48 + 0x0C) = -0x4000;
            if (*(s8 *) (d + 0x02) == 0) {
                *(s16 *) (rec48 + 0x0E) = 0x46;
                *(f32 *) (rec48 + 0x10) = 0.5f;
            } else {
                *(s16 *) (rec48 + 0x0E) = 0x2D;
                *(f32 *) (rec48 + 0x10) = D_overlay_120_07800AF8;
            }
            spawned = objSetupObject(rec48, 1);
            if (spawned != NULL) {
                *(s32 *) (spawned + 0x3C) = 0;
            }
        }
        if (*(s8 *) (d + 0x02) >= 0x14) {
            d[0x02] = 0xFF;
        } else {
            d[0x02] = (u8) (*(s8 *) (d + 0x02) + arg1);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o120/overlay_120/fireExplosionControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void smokingfireInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *src = (u8 *) arg1;
    u8 hdr[0x18];

    *(f32 *) (obj + 0x08) = (f32) *(s8 *) (src + 0x0A) * D_overlay_120_07800AFC;
    *(s16 *) (obj + 0x8E) = 0xFF;
    *(s16 *) (obj + 0x8C) = (s16) (*(s8 *) (src + 0x0B) * 6);

    hdr[0x00] = 1;
    hdr[0x01] = 3;
    hdr[0x02] = 0x31;
    hdr[0x03] = 0xFF;
    *(s16 *) (hdr + 0x04) = 0;
    *(s16 *) (hdr + 0x06) = 0;
    *(s16 *) (hdr + 0x08) = 0;
    *(s16 *) (hdr + 0x0A) = 0;
    *(s16 *) (hdr + 0x0C) = 0x100;
    *(s16 *) (hdr + 0x0E) = 0x100;
    hdr[0x13] = 0xFF;
    *(s16 *) (hdr + 0x14) = 0x12;
    hdr[0x16] = 0;
    hdr[0x17] = 0;

    *(s32 *) (obj + 0x88) = addObjectLight((Object *) arg0, (ObjectHeader48 *) hdr);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o120/overlay_120/smokingfireInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void smokingfireControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *) arg0;
    s32 sp3C;
    u8 *light;

    runlinkSetDestructTimer(__MODULE00120, 2, 2);
    *(s16 *) (obj + 0x8C) = (s16) (*(s16 *) (obj + 0x8C) - arg1);
    if (*(s16 *) (obj + 0x8C) > 0) {
        *(s32 *) (obj + 0x84) = 1;
        partUpdateTriggers(arg0, arg1);
        sp3C = 9;
        texAnimateSprite(*(s32 *) *(u8 **) (obj + 0x6C), &sp3C, 0xA, obj + 0x28, arg1);
        if (*(s16 *) (obj + 0x8C) < 0x40) {
            *(f32 *) (obj + 0x08) = *(f32 *) (obj + 0x08) * Powerf(D_overlay_120_07800B00, arg1);
            light = *(u8 **) (obj + 0x88);
            *(s16 *) (obj + 0x8E) = (s16) (*(s16 *) (obj + 0x8C) * 4);
            if (light != NULL) {
                changeLightIntensity((UnkLight *) light, (u8) (*(s16 *) (obj + 0x8E) & 0xFF));
            }
        }
    } else {
        light = *(u8 **) (obj + 0x88);
        if (light != NULL) {
            killLight((UnkLight *) light, arg1);
        }
        objFreeObject(arg0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o120/overlay_120/smokingfireControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fireringInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *src = (u8 *) arg1;

    *(s16 *) (obj + 0x00) = *(s16 *) (src + 0x0A);
    *(s16 *) (obj + 0x02) = *(s16 *) (src + 0x0C);
    *(f32 *) (obj + 0x08) = D_overlay_120_07800B04;
    *(f32 *) (obj + 0x88) = *(f32 *) (src + 0x10) / (f32) *(s16 *) (src + 0x0E);
    *(s16 *) (obj + 0x8E) = 0xFF;
    *(s16 *) (obj + 0x8C) = *(s16 *) (src + 0x0E);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o120/overlay_120/fireringInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fireringControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *) arg0;
    s16 t;

    runlinkSetDestructTimer(__MODULE00120, 2, 2);
    *(s16 *) (obj + 0x8C) = (s16) (*(s16 *) (obj + 0x8C) - arg1);
    if (*(s16 *) (obj + 0x8C) > 0) {
        *(f32 *) (obj + 0x08) = *(f32 *) (obj + 0x08) + *(f32 *) (obj + 0x88) * (f32) arg1;
        t = *(s16 *) (obj + 0x8C);
        if (t < 0x20) {
            *(s16 *) (obj + 0x8E) = (s16) (t * 8);
        }
    } else {
        objFreeObject(arg0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o120/overlay_120/fireringControl.s")
#endif
