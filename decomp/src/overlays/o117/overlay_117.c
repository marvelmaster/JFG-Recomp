#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern u8 D_overlay_117_07500B80[];
extern f32 D_overlay_117_07500B90;
extern f32 D_overlay_117_07500B94;
extern f32 D_overlay_117_07500B98;
extern f32 D_overlay_117_07500B9C;
void *objSetupObject(void *params, s32 arg1, void *owner);
void amSndPlayXYZ(s32 soundId, f32 x, f32 y, s32 z, s32 arg4, s32 arg5);
s32 hitPlayer(f32 x, f32 y, s32 z, f32 r, s32 flag, void *out);
void hitInitObjectHit(void *obj, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, f32 a7, f32 a8, f32 a9, f32 a10, s32 a11);
void matrix_SCL_RPY_XYZ(void *trans, f32 (*mtx)[4]);
void camDoSprite(void *a0, void *a1, void *a2, void *a3, s32 a4, s32 a5, u8 a6);
f32 camGetProjZ(f32 x, f32 y, f32 z);
f32 Sinf(s16 angle);
void func_overlay_117_07500000_1FC4868(void *arg0);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_117_07500000_1FC4868(void *arg0) {
    u8 *obj = (u8 *) arg0;
    u8 *anchor = *(u8 **) (obj + 0x3C);
    u8 *d;
    u8 setup[0x24];
    void *spawned;

    if (anchor != NULL) {
        d = *(u8 **) (obj + 0x68);
        *(s16 *) (setup + 0x00) = 0xC3;
        *(s16 *) (setup + 0x04) = (s16) (s32) *(f32 *) (obj + 0x0C);
        *(s16 *) (setup + 0x06) = (s16) (s32) *(f32 *) (obj + 0x10);
        *(s16 *) (setup + 0x08) = (s16) (s32) *(f32 *) (obj + 0x14);
        *(s16 *) (setup + 0x0A) = (s16) anchor[0x14];
        *(s16 *) (setup + 0x0C) = (s16) anchor[0x15];
        *(s16 *) (setup + 0x0E) = 0;
        *(s16 *) (setup + 0x10) = 0;
        *(s16 *) (setup + 0x12) = (s16) anchor[0x17];
        setup[0x14] = 0x0A;
        setup[0x15] = 0x32;
        setup[0x16] = d[0x0C];
        setup[0x17] = d[0x0D];
        setup[0x18] = d[0x0E];
        setup[0x19] = 0x80;
        *(s16 *) (setup + 0x1A) = (s16) anchor[0x16];
        setup[0x1C] = 0x64;
        setup[0x1D] = 0x64;
        setup[0x1E] = 6;
        setup[0x1F] = 0;
        *(s16 *) (setup + 0x20) = (s16) (*(s16 *) (obj + 0x02) + 0x4000);
        *(s16 *) (setup + 0x22) = *(s16 *) (obj + 0x00);
        spawned = objSetupObject(setup, 1, anchor);
        *(void **) (d + 0x10) = spawned;
        if (spawned != NULL) {
            *(void **) ((u8 *) spawned + 0x3C) = NULL;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o117/overlay_117/func_overlay_117_07500000_1FC4868.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void regionidInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *src = (u8 *) arg1;
    u8 *d = *(u8 **) (obj + 0x68);
    u8 *ent;
    UnkLight **slot;
    s32 k;
    s32 idx;
    u8 s4;
    s32 s5;
    f32 rnd;
    f32 radius;

    *(s16 *) (obj + 0x00) = (s16) (src[0x0E] << 8);
    *(s16 *) (obj + 0x02) = (s16) (src[0x0F] << 8);
    *(s16 *) (d + 0x00) = (s16) (src[0x0B] * 0x0A);
    *(s16 *) (d + 0x02) = (s16) (src[0x0C] * 0x0A);
    *(s16 *) (d + 0x04) = (s16) (src[0x0D] * 0x0A);
    *(s16 *) (d + 0x06) = (s16) (src[0x10] << 5);
    *(s16 *) (d + 0x08) = (s16) (src[0x11] << 5);
    *(s16 *) (d + 0x0A) = (s16) (src[0x12] * 0x10);
    idx = (src[0x0A] & 3) * 4;
    d[0x0C] = D_overlay_117_07500B80[idx + 0];
    d[0x0D] = D_overlay_117_07500B80[idx + 1];
    d[0x0E] = D_overlay_117_07500B80[idx + 2];
    d[0x0F] = 0;

    s4 = src[0x13];
    rnd = D_overlay_117_07500B90;
    s5 = s4 * 2;
    ent = d + 0x14;
    for (k = 0x13; k != 0; k--) {
        *(s16 *) (ent + 0x00) = (s16) mathRnd(0, 0x10000);
        *(s16 *) (ent + 0x02) = (s16) mathRnd(0, 0x10000);
        *(s16 *) (ent + 0x04) = (s16) mathRnd(s4, s5);
        *(s16 *) (ent + 0x06) = (s16) mathRnd(0xB6, 0x16C);
        *(f32 *) (ent + 0x08) = (f32) mathRnd(0x4B, 0x64) * rnd;
        ent[0x0C] = (u8) mathRnd(-0x80, 0x7F);
        ent[0x0D] = (u8) mathRnd(4, 0xC);
        ent[0x0E] = (u8) mathRnd(-0x80, 0x7F);
        ent[0x0F] = (u8) mathRnd(1, 8);
        ent += 0x10;
    }

    slot = *(UnkLight ***) (obj + 0x74);
    if (slot != NULL) {
        UnkLight *light = *slot;

        if (light != NULL) {
            changeLightColour(light, d[0x0C], d[0x0D], d[0x0E]);
        }
    }
    radius = *(f32 *) (obj + 0x08) * 96.0f;
    hitInitObjectHit(arg0, -1, 0, 8, 0, 0, 0, radius, radius, -1.0f, 1.0f, 1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o117/overlay_117/regionidInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void regionidControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *d = *(u8 **) (obj + 0x68);
    f32 px = *(f32 *) (obj + 0x0C);
    f32 py = *(f32 *) (obj + 0x10);
    s32 pz = *(s32 *) (obj + 0x14);
    s32 hitOut[8]; /* out array size guessed */
    u8 cur = d[0x0F];
    s32 var_s6;
    s32 k;

    if (hitPlayer(px, py, pz, (f32) *(s16 *) (d + 0x0A), 0, hitOut) != 0) {
        var_s6 = cur + arg1 * 4;
        if (var_s6 >= 0x100) {
            var_s6 = 0xFF;
        }
        if (d[0x154] == 0) {
            amSndPlayXYZ(0x210, px, py, pz, 4, 0);
            d[0x154] = 1;
        }
    } else {
        var_s6 = cur - arg1 * 8;
        if (var_s6 < 0) {
            var_s6 = 0;
        }
        if (d[0x154] != 0) {
            amSndPlayXYZ(0x211, px, py, pz, 4, 0);
            d[0x154] = 0;
        }
    }
    d[0x0F] = (u8) var_s6;

    if (var_s6 != 0) {
        f32 f28 = D_overlay_117_07500B94;
        f32 f20 = (f32) *(s16 *) (d + 0x04);
        f32 f22 = ((f32) *(s16 *) (d + 0x00) - f20) * 0.5f;
        u8 *ent = d + 0x14;
        s32 e;

        for (e = 0; e < 0x13; e++) {
            /* m2c emitted a do/while that is off by one here; the asm runs arg1 steps */
            for (k = 0; k < arg1; k++) {
                f32 f2;
                f32 f14;
                f32 f18;

                *(s16 *) (ent + 0x02) = (s16) (*(s16 *) (ent + 0x02) + *(s16 *) (ent + 0x06));
                f2 = Cosf((s32) *(s16 *) (ent + 0x02)) + 1.0f;
                f14 = (f32) ((s32) *(s16 *) (ent + 0x04) << 0x10) * (3.0f - f2);
                f18 = f28 * (((f22 * f2) + f20) * *(f32 *) (ent + 0x08));
                ent[0x0C] = (u8) ((s8) ent[0x0C] + (s8) ent[0x0D]);
                ent[0x0E] = (u8) ((s8) ent[0x0E] + (s8) ent[0x0F]);
                *(s16 *) (ent + 0x00) = (s16) (*(s16 *) (ent + 0x00) + (s32) (f14 / f18));
            }
            ent += 0x10;
        }
    }

    if (*(void **) (d + 0x10) == NULL) {
        func_overlay_117_07500000_1FC4868(arg0);
    }
    if (*(void **) (d + 0x10) != NULL) {
        u8 *child = *(u8 **) (d + 0x10);
        u8 *cd = *(u8 **) (child + 0x68);
        f32 level = (f32) var_s6 / 255.0f;

        *(f32 *) (cd + 0xB8) = level;
        *(f32 *) (cd + 0xBC) = level;
    }
    if (cur != var_s6) {
        UnkLight **slot = *(UnkLight ***) (obj + 0x74);

        if (slot != NULL) {
            UnkLight *light = *slot;

            if (light != NULL) {
                changeLightIntensity(light, (u8) (var_s6 & 0xFF));
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o117/overlay_117/regionidControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void regionidDraw(void *arg0, void *arg1, void *arg2, void *arg3) {
    u8 *obj = (u8 *) arg3;
    u8 *d = *(u8 **) (obj + 0x68);
    f32 mtx[4][4];
    f32 pos[0x14][3];
    f32 keyZ[0x14];
    u8 order[0x14];
    u8 spr[0x2C];
    u8 *camObj;
    s32 *camv;
    s32 camVal;
    f32 savedX;
    f32 savedY;
    f32 f20;
    f32 f22;
    f32 f24;
    f32 f26;
    f32 f28;
    f32 f30;
    f32 sp254;
    s32 i;
    s32 j;
    s32 k;
    u8 *ent;
    u8 *e;

    if (d[0x0F] != 0) {
        camObj = *(u8 **) (obj + 0x40);
        if (camObj != NULL) {
            camv = *(s32 **) (camObj + 0xAC);
            if (camv != NULL) {
                camVal = *camv;
                savedY = *(f32 *) (obj + 0x10);
                savedX = *(f32 *) (obj + 0x08);
                *(f32 *) (obj + 0x10) = savedY + 8.0f;
                *(f32 *) (obj + 0x08) = D_overlay_117_07500B98;
                matrix_SCL_RPY_XYZ(obj, mtx);
                *(f32 *) (obj + 0x08) = savedX;
                *(f32 *) (obj + 0x10) = savedY;

                f28 = (f32) *(s16 *) (d + 0x04);
                f22 = (f32) d[0x0F] / 255.0f;
                f30 = (f32) (*(s16 *) (d + 0x02) * 2) * 0.5f;
                sp254 = ((f32) *(s16 *) (d + 0x00) - f28) * 0.5f;
                for (i = 0; i < 0x14; i++) {
                    ent = d + 0x14 + i * 0x10;
                    f24 = Cosf(*(s16 *) (ent + 0x02)) + 1.0f;
                    f20 = ((sp254 * f24) + f28) * *(f32 *) (ent + 0x08);
                    f26 = Sinf(*(s16 *) (ent + 0x00)) * f20 * f22;
                    mathMtxXFMF(mtx, f26, ((f30 * f24) + 0.0f) * f22,
                                Cosf(*(s16 *) (ent + 0x00)) * f20 * f22,
                                pos[i], pos[i] + 1, pos[i] + 2);
                    keyZ[i] = camGetProjZ(pos[i][0], pos[i][1], pos[i][2]);
                    order[i] = (u8) i;
                }

                /* insertion sort ascending by projected Z, carrying the index bytes;
                 * m2c's odd-even sorting network was unclear, so this is a reconstruction */
                for (i = 1; i < 0x14; i++) {
                    f32 kz = keyZ[i];
                    u8 ord = order[i];

                    j = i - 1;
                    while (j >= 0 && keyZ[j] > kz) {
                        keyZ[j + 1] = keyZ[j];
                        order[j + 1] = order[j];
                        j--;
                    }
                    keyZ[j + 1] = kz;
                    order[j + 1] = ord;
                }

                *(s16 *) (spr + 0x00) = 0;
                *(s16 *) (spr + 0x02) = 0;
                *(f32 *) (spr + 0x28) = 0.0f;
                sprSetIA2ColOverride(0xFF, 0xFF, 0xFF, d[0x0C], d[0x0D], d[0x0E]);
                for (k = 0; k < 0x14; k++) {
                    u8 id = order[k];

                    e = d + 0x14 + id * 0x10;
                    *(f32 *) (spr + 0x0C) = pos[id][0];
                    *(f32 *) (spr + 0x10) = pos[id][1];
                    *(f32 *) (spr + 0x14) = pos[id][2];
                    *(s16 *) (spr + 0x04) = (s16) ((s32) (s8) e[0x0E] << 8);
                    *(f32 *) (spr + 0x08) = (Sinf((s16) ((s32) (s8) e[0x0C] << 8)) * 0.125f) + D_overlay_117_07500B9C;
                    camDoSprite(arg0, arg1, arg2, spr, camVal, 7, d[0x0F]);
                }
                sprClearIA2ColOverride();
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o117/overlay_117/regionidDraw.s")
#endif
