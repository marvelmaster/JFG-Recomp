#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern s16 D_overlay_107_06B01080[];
extern u8 D_overlay_107_06B01088[];   /* objSetupObject parameter block */
extern u8 D_overlay_107_06B010F0[];   /* light table, 8 entries of 0x20 bytes */
extern s16 D_overlay_107_06B011F0[];  /* sin/cos table, 0x80 bytes */
extern u8 D_overlay_107_06B01270;     /* flag; also the end of the sin/cos table */
extern f32 D_overlay_107_06B010E0;
extern u8 D_86B010F0[];
s32 hitPlayer(f32, f32, s32, f32, s32, void **);
void instQueueMsg(void *, s32);
void objFreeObject(void *);
void *objSetupObject(void *, s32);
void amSndPlayXYZ(s32, s32, s32, s32, s32, void *);
void amSndStopXYZ(void *);
void objMoveXYZ(void *, f32, f32, f32);
s32 objTvTimes(s32);
void updateColourCycle(void *, s32);
f32 Sinf(s16);
void texDPTextureX(Gfx **, s32, s32, s32);
s32 camDoSprite(Gfx **, void *, void *, void *, s32, s32, s32);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void invincibilityInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *src = (u8 *) arg1;

    s32 b;

    *(s16 *) (obj + 0x88) = *(s8 *) (src + 0x0A) * 0x3C;
    b = *(s8 *) (src + 0x0B) * 0x3C;
    *(s16 *) (obj + 0x8C) = 0;
    *(s16 *) (obj + 0x8E) = 0xFF;
    *(s16 *) (obj + 0x8A) = b;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o107/overlay_107/invincibilityInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void invincibilityControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *) arg0;
    s16 *timers = (s16 *) (obj + 0x88);
    void *hits[0xA];
    s32 hitCount;
    s32 i;
    u8 *d;
    u8 *hitObj;

    hitCount = hitPlayer(*(f32 *) (obj + 0x0C), *(f32 *) (obj + 0x10), *(s32 *) (obj + 0x14), 40.0f, 0, hits);

    if (timers[3] == 0) {
        timers[2] = (s16) (timers[2] - arg1);
        if (timers[2] <= 0) {
            timers[2] = 0;
            if (hitCount == 0) {
                timers[3] = (s16) arg1;
            }
        }
        return;
    }

    *(s16 *) obj = (s16) (*(s16 *) obj + (arg1 << 8));
    timers[3] = (s16) (timers[3] + (arg1 * 4));
    if (timers[3] >= 0x100) {
        timers[3] = 0xFF;
    }
    if (hitCount <= 0) {
        return;
    }
    for (i = 0; i < hitCount; i++) {
        hitObj = (u8 *) hits[i];
        d = *(u8 **) (hitObj + 0x68);
        if (*(s16 *) (d + 0x5C8) == 0) {
            void *spawned;

            if (*(void **) (d + 0x5BC) == NULL) {
                *(void **) (D_overlay_107_06B01088 + 0x54) = hitObj;
                *(s16 *) (D_overlay_107_06B01088 + 0x04) = (s16) (s32) *(f32 *) (hitObj + 0x0C);
                *(s16 *) (D_overlay_107_06B01088 + 0x06) = (s16) (s32) *(f32 *) (hitObj + 0x10);
                *(s16 *) (D_overlay_107_06B01088 + 0x08) = (s16) (s32) *(f32 *) (hitObj + 0x14);
                spawned = objSetupObject(D_overlay_107_06B01088, 1);
                *(void **) (d + 0x5BC) = spawned;
                if (spawned != NULL) {
                    *(s32 *) ((u8 *) spawned + 0x3C) = 0;
                }
            }
            spawned = *(void **) (d + 0x5BC);
            if (spawned != NULL) {
                *(s16 *) (*(u8 **) ((u8 *) spawned + 0x68) + 0x4C2) = timers[0];
            }
            *(s16 *) (d + 0x5C8) = timers[0];
            timers[2] = timers[1];
            if (timers[2] == 0) {
                objFreeObject(arg0);
            } else {
                timers[3] = 0;
            }
            instQueueMsg(d, 0x89);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o107/overlay_107/invincibilityControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void invincibilityShieldInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *d = *(u8 **) (obj + 0x68);
    u8 *src = (u8 *) arg1;
    u8 hdr[0x18];
    s32 k;
    s32 angle;
    s32 n;
    s32 a0 = 0;
    s32 v1 = 0x7E0;
    s32 a1;
    s32 a2;
    s32 a3;
    u8 *e;
    s16 *sc;

    for (k = 0; k < 3; k++) {
        u8 *s1 = src + 2 * k;
        u8 *s4 = src + 4 * k;

        *(s16 *) (d + 0x43C + 2 * k) = *(s16 *) (s1 + 0x0E);
        *(s16 *) (d + 0x442 + 2 * k) = *(s16 *) (s1 + 0x14);
        *(s16 *) (d + 0x448 + 2 * k) = *(s16 *) (s1 + 0x1A);
        *(s16 *) (d + 0x44E + 2 * k) = *(s16 *) (s1 + 0x20);
        *(s16 *) (d + 0x458 + 2 * k) = *(s16 *) (s1 + 0x26);
        *(s16 *) (d + 0x45E + 2 * k) = *(s16 *) (s1 + 0x2C);
        *(s16 *) (d + 0x464 + 2 * k) = *(s16 *) (s1 + 0x38);
        *(s16 *) (d + 0x46A + 2 * k) = *(s16 *) (s1 + 0x3E);
        *(f32 *) (d + 0x470 + 4 * k) = *(f32 *) (s4 + 0x44);
        initColourCycle((unkResetColourCycle *) (d + 0x488 + 0x10 * k), *(s16 *) (s1 + 0x32));
        *(s16 *) (d + 0x4F0 + 2 * k) = D_overlay_107_06B01080[k];

        /* local ObjectHeader48 for addObjectLight */
        hdr[0x00] = 1;
        hdr[0x01] = 3;
        hdr[0x02] = 0x40;
        hdr[0x03] = 0xFF;
        *(s16 *) (hdr + 0x04) = 0;
        *(s16 *) (hdr + 0x06) = 0;
        *(s16 *) (hdr + 0x08) = 0;
        *(s16 *) (hdr + 0x0A) = 0;
        *(s16 *) (hdr + 0x0C) = 0x78;
        *(s16 *) (hdr + 0x0E) = 0x78;
        hdr[0x13] = 0xFF;
        *(s16 *) (hdr + 0x14) = -1;
        hdr[0x16] = 0;
        hdr[0x17] = 0;
        *(s32 *) (d + 0x4F4 + 4 * (k + 1)) = addObjectLight(NULL, (ObjectHeader48 *) hdr);
    }

    *(s16 *) (d + 0x438) = *(s16 *) (src + 0x0A);
    *(f32 *) (d + 0x4C4) = 1.0f;
    *(s16 *) (d + 0x43A) = *(s16 *) (src + 0x0C);
    *(f32 *) (d + 0x4C8) = 1.0f;
    *(f32 *) (d + 0x4B8) = 1.0f;
    *(f32 *) (d + 0x4BC) = 1.0f;
    *(s16 *) (d + 0x4C0) = *(s16 *) (d + 0x43A);
    *(s32 *) (d + 0x454) = *(s32 *) (src + 0x54);

    if (D_overlay_107_06B01270 == 0) {
        e = D_overlay_107_06B010F0;
        for (n = 0; n < 8; n++) {
            a1 = (s16) (v1 - 0xFC);
            a2 = a0 + 2;
            a3 = a0 + 1;
            e[0x00] = 0x40;
            e[0x01] = (u8) a0;
            e[0x02] = (u8) a2;
            e[0x03] = (u8) a3;
            *(s16 *) (e + 0x04) = (s16) v1;
            *(s16 *) (e + 0x06) = 0;
            *(s16 *) (e + 0x08) = (s16) a1;
            *(s16 *) (e + 0x0A) = 0;
            *(s16 *) (e + 0x0C) = (s16) v1;
            *(s16 *) (e + 0x0E) = 0x1E0;
            e[0x10] = 0x40;
            e[0x11] = (u8) a2;
            e[0x12] = (u8) a3;
            e[0x13] = (u8) (a0 + 3);
            *(s16 *) (e + 0x14) = (s16) a1;
            *(s16 *) (e + 0x16) = 0;
            *(s16 *) (e + 0x18) = (s16) v1;
            *(s16 *) (e + 0x1A) = 0x1E0;
            *(s16 *) (e + 0x1C) = (s16) a1;
            *(s16 *) (e + 0x1E) = 0x1E0;
            e += 0x20;
            a0 = a2;
            v1 = a1;
        }

        /* 32 entries: sin at [2i], cos at [2i+1], angle steps 0x800 */
        sc = D_overlay_107_06B011F0;
        angle = 0;
        do {
            sc[0] = (s16) (s32) (Sinf(angle) * 100.0f);
            sc[1] = (s16) (s32) (Cosf(angle) * 100.0f);
            sc += 2;
            angle += 0x800;
        } while ((u8 *) sc != &D_overlay_107_06B01270);
    }

    amSndPlayXYZ(0xF9, *(s32 *) (obj + 0x0C), *(s32 *) (obj + 0x10), *(s32 *) (obj + 0x14), 1, d + 0x504);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o107/overlay_107/invincibilityShieldInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void invincibilityShieldControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *d = *(u8 **) (obj + 0x68);
    u8 *pos = *(u8 **) (d + 0x454);
    void *light;
    u8 *fp;
    u8 *t0;
    u8 *cc;
    u8 *color;
    u8 *vtx;
    s16 *tbl;
    f32 f20;
    f32 f22;
    s32 k;
    s32 i;
    s32 j;
    s32 idx;
    s32 q;
    s32 yc;
    s16 ang;
    s16 cur;
    s16 x;
    s16 z;

    if (*(s16 *) (d + 0x4C2) > 0) {
        *(s16 *) (d + 0x4C2) = (s16) (*(s16 *) (d + 0x4C2) - arg1);
        if (*(s16 *) (d + 0x4C2) <= 0) {
            /* timer expired: lights and sound off, shield gone */
            obj[0x39] = 0;
            for (i = 0; i < 3; i++) {
                light = *(void **) (d + 0x4F8 + 4 * i);
                if (light != NULL) {
                    turnLightOff((UnkLight *) light);
                }
            }
            if (*(void **) (d + 0x504) != NULL) {
                amSndStopXYZ(*(void **) (d + 0x504));
            }
            return;
        }

        if (*(void **) (d + 0x504) == NULL) {
            amSndPlayXYZ(0xF9, *(s32 *) (obj + 0x0C), *(s32 *) (obj + 0x10), *(s32 *) (obj + 0x14), 1, d + 0x504);
        }

        for (i = 0; i < 3; i++) {
            light = *(void **) (d + 0x4F8 + 4 * i);
            if (light != NULL) {
                turnLightOn((UnkLight *) light);
            }
        }

        /* per channel k (0..2): angle/offset step, colour cycle, light colour */
        for (k = 0; k < 3; k++) {
            fp = d + 2 * k;
            t0 = d + 4 * k;
            cc = d + 0x488 + 0x10 * k;
            color = d + 0x490 + 0x10 * k;

            *(s16 *) (fp + 0x458) = (s16) (*(s16 *) (fp + 0x458) + *(s16 *) (fp + 0x45E) * arg1);
            *(s16 *) (fp + 0x458) = (s16) (*(s16 *) (fp + 0x458) & 0x1FFF);
            *(s16 *) (fp + 0x43C) = (s16) (*(s16 *) (fp + 0x43C) + *(s16 *) (fp + 0x442) * arg1);
            *(s16 *) (fp + 0x464) = (s16) (*(s16 *) (fp + 0x464) + *(s16 *) (fp + 0x46A) * arg1);
            *(f32 *) (t0 + 0x47C) = *(f32 *) (t0 + 0x470) * Sinf(*(s16 *) (fp + 0x464)) + 1.0f;
            updateColourCycle(cc, arg1);

            light = *(void **) (t0 + 0x4F8);
            if (light != NULL) {
                changeLightColour((UnkLight *) light, color[0], color[1], color[2]);
            }
        }

        objMoveXYZ(obj,
                   *(f32 *) (pos + 0x0C) - *(f32 *) (obj + 0x0C),
                   *(f32 *) (pos + 0x10) - *(f32 *) (obj + 0x10),
                   *(f32 *) (pos + 0x14) - *(f32 *) (obj + 0x14));
        amSndSetXYZ(*(SoundMask **) (d + 0x504), *(f32 *) (obj + 0x0C), *(f32 *) (obj + 0x10), *(f32 *) (obj + 0x14));

        q = (s32) (*(s16 *) (d + 0x4C2) * 0xFE) / objTvTimes(0x78);
        if (q < 0xFF) {
            obj[0x39] = (u8) q;
        } else {
            obj[0x39] = 0xFE;
        }
        amSndSetVolXYZ(*(SoundMask **) (d + 0x504), (u8) (obj[0x39] >> 1));

        /* lerp of the per-channel values, once per unit of delta */
        for (k = 0; k < arg1; k++) {
            cur = *(s16 *) (d + 0x43A);
            *(s16 *) (d + 0x43A) = (s16) (cur + ((*(s16 *) (d + 0x4C0) - cur) >> 2));
            *(f32 *) (d + 0x4C4) = *(f32 *) (d + 0x4C4) + (*(f32 *) (d + 0x4B8) - *(f32 *) (d + 0x4C4)) * 0.125f;
            *(f32 *) (d + 0x4C8) = *(f32 *) (d + 0x4C8) + (*(f32 *) (d + 0x4BC) - *(f32 *) (d + 0x4C8)) * 0.125f;
            for (j = 0; j < 3; j++) {
                *(s16 *) (d + 0x4F0 + 2 * j) = (s16) (*(s16 *) (d + 0x4F0 + 2 * j) + (arg1 << 8));
            }
        }

        /* flip double-buffer index; vertex output is at d + index * 0x10E * 2 */
        *(s16 *) (d + 0x4F6) = (s16) (*(s16 *) (d + 0x4F6) ^ 1);
        vtx = d + *(s16 *) (d + 0x4F6) * 0x10E * 2;

        for (k = 0; k < 3; k++) {
            fp = d + 2 * k;
            t0 = d + 4 * k;
            f20 = *(f32 *) (t0 + 0x47C) * *(f32 *) (d + 0x4C4);
            f22 = (f32) *(s16 *) (d + 0x438) * *(f32 *) (d + 0x4C8);
            idx = *(s16 *) (fp + 0x458) >> 8;
            ang = *(s16 *) (fp + 0x43C);

            for (i = 0; i < 9; i++) {
                idx = (idx + *(s16 *) (fp + 0x448)) & 0x1F;
                tbl = D_overlay_107_06B011F0 + 2 * idx;
                ang = (s16) (ang + *(s16 *) (fp + 0x44E));

                x = (s16) (s32) ((f32) tbl[0] * f20);
                z = (s16) (s32) ((f32) tbl[1] * f20);
                yc = (s32) (Sinf(ang) * f22) + *(s16 *) (d + 0x43A);

                /* two vertices (y +/- 0x28), 0x0A bytes each, RGBA FF FF FF 80 */
                *(s16 *) (vtx + 0x00) = x;
                *(s16 *) (vtx + 0x02) = (s16) (yc + 0x28);
                *(s16 *) (vtx + 0x04) = z;
                vtx[0x06] = 0xFF;
                vtx[0x07] = 0xFF;
                vtx[0x08] = 0xFF;
                vtx[0x09] = 0x80;
                *(s16 *) (vtx + 0x0A) = x;
                *(s16 *) (vtx + 0x0C) = (s16) (yc - 0x28);
                *(s16 *) (vtx + 0x0E) = z;
                vtx[0x10] = 0xFF;
                vtx[0x11] = 0xFF;
                vtx[0x12] = 0xFF;
                vtx[0x13] = 0x80;
                vtx += 0x14;
            }

            /* tbl / ang still hold the values of the last inner iteration */
            *(f32 *) (t0 + 0x4CC) = (f32) (s16) (s32) ((f32) tbl[0] * f20 * *(f32 *) (obj + 0x08)) + *(f32 *) (obj + 0x0C);
            *(f32 *) (t0 + 0x4D8) = (f32) (s16) (s32) (Sinf(ang) * f22 + (f32) *(s16 *) (d + 0x43A)) * *(f32 *) (obj + 0x08)
                                    + *(f32 *) (obj + 0x10);
            *(f32 *) (t0 + 0x4E4) = (f32) (s16) (s32) ((f32) tbl[1] * f20 * *(f32 *) (obj + 0x08) + *(f32 *) (obj + 0x14));

            light = *(void **) (t0 + 0x4F8);
            if (light != NULL) {
                *(f32 *) ((u8 *) light + 0x18) = *(f32 *) (t0 + 0x4CC);
                *(f32 *) ((u8 *) light + 0x1C) = *(f32 *) (t0 + 0x4D8);
                *(f32 *) ((u8 *) light + 0x20) = *(f32 *) (t0 + 0x4E4);
                changeLightIntensity((UnkLight *) light, obj[0x39]);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o107/overlay_107/invincibilityShieldControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void invincibilityShieldTransform(void *arg0, f32 arg1, f32 arg2, s32 arg3) {
    u8 *d = *(u8 **) ((u8 *) arg0 + 0x68);

    *(s16 *) (d + 0x4C0) = arg3;
    *(f32 *) (d + 0x4B8) = arg1;
    *(f32 *) (d + 0x4BC) = arg2;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o107/overlay_107/invincibilityShieldTransform.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objDrawInvincibilityShield(Gfx **arg0, s32 (**arg1)[4][4], s32 *arg2, ObjectTransform *arg3) {
    u8 *obj = (u8 *) arg3;
    Gfx *spA4;
    s32 (*spA0)[4][4];
    s32 sp9C;
    u8 *d;
    u8 *pos;
    u8 *model;
    u8 *texObj;
    u8 *s0p;
    u8 *s1p;
    Gfx *gfx;
    u32 k0;
    s32 i;
    f32 saveX;
    f32 saveY;
    f32 saveZ;
    f32 saveScale;

    if (obj[0x39] == 0) {
        return;
    }
    spA4 = *arg0;
    spA0 = *arg1;
    sp9C = *arg2;
    d = *(u8 **) (obj + 0x68);
    pos = *(u8 **) (d + 0x454);
    *(f32 *) (obj + 0x0C) = *(f32 *) (pos + 0x0C);
    *(f32 *) (obj + 0x10) = *(f32 *) (pos + 0x10);
    *(f32 *) (obj + 0x14) = *(f32 *) (pos + 0x14);

    model = *(u8 **) (obj + 0x40);
    texObj = *(u8 **) (model + 0xAC);
    texDPTextureX(&spA4, *(s32 *) texObj, 0x207, 0);

    gfx = spA4;
    spA4 = gfx + 1;
    gfx->words.w0 = 0xFA000000;
    gfx->words.w1 = (u32) obj[0x39] | ~0xFFu;

    s1p = d + (s32) (*(s16 *) (d + 0x4F6)) * 0x10E * 2;
    s0p = d;
    for (i = 0; i < 0x30; i += 0x10) {
        camPushModelMtx(&spA4, (MatrixS **) &spA0, (ObjectTransform *) obj, 1.0f, 0.0f);

        gfx = spA4;
        spA4 = gfx + 1;
        gfx->words.w0 = 0xFB000000;
        gfx->words.w1 = ((u32) s0p[0x492] << 8) | ((u32) s0p[0x490] << 0x18)
                      | ((u32) s0p[0x491] << 0x10) | (u32) obj[0x39];

        k0 = (u32) s1p + 0x80000000u;
        gfx = spA4;
        spA4 = gfx + 1;
        gfx->words.w0 = ((((k0 & 6) | 0x90) & 0xFF) << 0x10) | 0x04000000 | 0xBC;
        gfx->words.w1 = k0;

        gfx = spA4;
        spA4 = gfx + 1;
        gfx->words.w0 = 0x05F10100;
        gfx->words.w1 = (u32) D_86B010F0;

        s1p += 0xB4;
        camPopModelMtx(&spA4);
        s0p += 0x10;
    }

    saveX = *(f32 *) (obj + 0x0C);
    saveY = *(f32 *) (obj + 0x10);
    saveZ = *(f32 *) (obj + 0x14);
    saveScale = *(f32 *) (obj + 0x08);
    *(f32 *) (obj + 0x08) = D_overlay_107_06B010E0;

    for (i = 0; i < 3; i++) {
        *(s16 *) (obj + 0x04) = *(s16 *) (d + 0x4F0 + 2 * i);
        *(f32 *) (obj + 0x0C) = *(f32 *) (d + 0x4CC + 4 * i);
        *(f32 *) (obj + 0x10) = *(f32 *) (d + 0x4D8 + 4 * i);
        *(f32 *) (obj + 0x14) = *(f32 *) (d + 0x4E4 + 4 * i);
        sprSetIA2ColOverride(0xFF, 0xFF, 0xFF, d[0x490 + 0x10 * i], d[0x491 + 0x10 * i], d[0x492 + 0x10 * i]);

        model = *(u8 **) (obj + 0x40);
        texObj = *(u8 **) (model + 0xAC);
        camDoSprite(&spA4, (void *) &spA0, (void *) &sp9C, (void *) obj, *(s32 *) (texObj + 4), 0x206, obj[0x39]);
    }
    sprClearIA2ColOverride();

    *(f32 *) (obj + 0x0C) = saveX;
    *(f32 *) (obj + 0x10) = saveY;
    *(f32 *) (obj + 0x14) = saveZ;
    *(s16 *) (obj + 0x04) = 0;
    *(f32 *) (obj + 0x08) = saveScale;

    *arg0 = spA4;
    *arg1 = spA0;
    *arg2 = sp9C;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o107/overlay_107/objDrawInvincibilityShield.s")
#endif
