#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
s32 texLoadSprite(s32 spriteId, s32 arg1);
void texFreeTexture(TextureHeader *tex);
void texFreeSprite(s32 spriteId);
extern s32 D_overlay_8_008016C0;
extern s32 D_overlay_8_008017A0;
extern s32 D_overlay_8_008017A4;
extern TextureHeader *D_overlay_8_008017A8;
extern TextureHeader *D_overlay_8_008017AC;
extern TextureHeader *D_overlay_8_008017B0;
extern TextureHeader *D_overlay_8_008017B4;
extern TextureHeader *D_overlay_8_008017B8;
extern s32 D_overlay_8_008017BC;
extern u8 D_overlay_8_008017C0[];
extern u8 D_overlay_8_00802CC0[];
extern s8 D_overlay_8_00802CD6;
extern s32 D_overlay_8_00802D38;
extern u8 rainbowblood;
void func_overlay_8_00800000_1EFF168(void);
extern f32 D_overlay_8_00801790;
extern f32 D_overlay_8_00801794;
typedef struct BloodSpurt {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    f32 unk14;
    f32 unk18;
    f32 unk1C;
    f32 unk20;
    f32 unk24;
    f32 unk28;
    f32 unk2C;
    f32 unk30;
    f32 unk34;
    f32 unk38;
    s16 unk3C;
    s16 unk3E;
    s16 unk40;
    s16 unk42;
    s16 unk44;
    s16 unk46;
    s16 unk48;
    u8 unk4A;
    u8 unk4B;
    s16 unk4C;
    s16 unk4E;
    u8 unk50;
    u8 unk51;
    u8 unk52;
} BloodSpurt;
typedef struct BloodHitSprite {
    f32 unk0;
    f32 unk4;
    f32 unk8;
    f32 unkC;
    f32 unk10;
    s8 unk14;
    u8 unk15;
    u8 unk16;
} BloodHitSprite;
typedef struct TrackHit {
    s32 found;
    f32 pos[3];
    f32 nrm[4];
    s32 unkCC;
    u32 flags;
    s32 surf;
} TrackHit;
f32 Sinf(s16 angle);
void amSndPlayXYZ(s32 sfxId, f32 x, f32 y, f32 z, s32 arg4, s32 arg5);
s32 texAnimateSprite(s32 spriteId, s32 *frame, s32 arg2, void *arg3, s32 arg4);
void *trackGetTrack(void);
s32 trackNearestIntersection(s32 arg0, void *arg1, void *arg2, TrackHit *hit, s32 arg4, s32 arg5);
extern s32 D_overlay_8_008016C4[];
extern u8 D_overlay_8_00801660[];
extern u8 D_overlay_8_00801680[];
extern s32 D_overlay_8_00801724[];
extern f32 D_overlay_8_00801798;
extern f32 D_overlay_8_0080179C;
void texDPTextureX(void **dl, s32 texture, s32 arg2, s32 arg3);
void objDrawTracer(void **dl, void **vtx, s32 texture, void *arg3, void *spur, f32 *pos, f32 scale, s32 color, s32 envColor, s32 arg9);
f32 camGetProjZ(f32 x, f32 y, void *arg2, f32 arg3);
void camDoSpriteDirect(void **dl, s32 *arg1, void **vtx, s32 spriteId, s32 x, s32 y, s32 z, s32 arg7, f32 scale, f32 arg9, s32 arg10, s32 arg11);
void sprSetIA2ColOverride(u8 r, u8 g, u8 b, u8 a, u8 a2, u8 a3);
void sprClearIA2ColOverride(void);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_8_00800000_1EFF168(void) {
    s32 i;
    u8 *slot;

    D_overlay_8_008017A8 = texLoadTexture(0x170);
    D_overlay_8_008017AC = texLoadTexture(0x171);
    D_overlay_8_008017B0 = texLoadTexture(0x172);
    D_overlay_8_008017B4 = texLoadTexture(0x173);
    D_overlay_8_008017B8 = texLoadTexture(0x174);
    D_overlay_8_008017BC = texLoadSprite(0x43, 1);

    slot = D_overlay_8_008017C0;
    for (i = 0; i < 0x40; i++) {
        slot[0x4A] = 0;
        slot += 0x54;
    }
    D_overlay_8_00802CD6 = 0;
    D_overlay_8_008016C0 = 1;
    D_overlay_8_008017A0 = 0;
    D_overlay_8_008017A4 = 0;
    D_overlay_8_00802D38 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o8/overlay_8/func_overlay_8_00800000_1EFF168.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void bloodSpurtFreeLib(void) {
    s32 i;
    u8 *slot;

    if (D_overlay_8_008016C0 != 0) {
        if (D_overlay_8_008017A8 != NULL) {
            texFreeTexture(D_overlay_8_008017A8);
        }
        if (D_overlay_8_008017AC != NULL) {
            texFreeTexture(D_overlay_8_008017AC);
        }
        if (D_overlay_8_008017B0 != NULL) {
            texFreeTexture(D_overlay_8_008017B0);
        }
        if (D_overlay_8_008017B4 != NULL) {
            texFreeTexture(D_overlay_8_008017B4);
        }
        if (D_overlay_8_008017B8 != NULL) {
            texFreeTexture(D_overlay_8_008017B8);
        }
        if (D_overlay_8_008017BC != 0) {
            texFreeSprite(D_overlay_8_008017BC);
        }
        slot = D_overlay_8_008017C0;
        for (i = 0; i < 0x40; i++) {
            slot[0x4A] = 0;
            slot += 0x54;
        }
        D_overlay_8_00802CD6 = 0;
    }
    D_overlay_8_008016C0 = 0;
    D_overlay_8_008017A0 = 0;
    D_overlay_8_008017A4 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o8/overlay_8/bloodSpurtFreeLib.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void bloodSpurtAdd(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, s32 arg6, s32 arg7, f32 arg8) {
    s32 i;
    u8 *slot;

    if (D_overlay_8_008016C0 == 0) {
        func_overlay_8_00800000_1EFF168();
    }
    if (D_overlay_8_008017A0 < 0x40) {
        /* find first free slot (active flag at +0x4A) */
        slot = D_overlay_8_008017C0;
        i = 0;
        while (i < 0x40 && slot[0x4A] != 0) {
            i++;
            slot += 0x54;
        }
        if (i < 0x40) {
            *(f32 *)(slot + 0x18) = arg3;
            *(f32 *)(slot + 0x1C) = arg4;
            *(f32 *)(slot + 0x20) = arg5;
            slot[0x4A] = 1;
            *(s16 *)(slot + 0x3C) = 0x12C;
            *(f32 *)(slot + 0x0C) = arg0;
            *(f32 *)(slot + 0x10) = arg1;
            *(f32 *)(slot + 0x24) = 0.0f;
            *(f32 *)(slot + 0x28) = arg8;
            *(f32 *)(slot + 0x00) = arg0;
            *(f32 *)(slot + 0x04) = arg1;
            *(f32 *)(slot + 0x14) = arg2;
            *(f32 *)(slot + 0x08) = arg2;
            slot[0x4B] = mathRnd(0, 1);
            *(s16 *)(slot + 0x4C) = arg6 << 5;
            *(s16 *)(slot + 0x4E) = arg6 << 5;
            if (rainbowblood != 0) {
                slot[0x50] = mathRnd(0, 7);
            } else {
                slot[0x50] = arg7;
            }
            slot[0x51] = mathRnd(0, 2);
            D_overlay_8_008017A0 += 1;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o8/overlay_8/bloodSpurtAdd.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void bloodHitSpriteAdd(f32 arg0, f32 arg1, f32 arg2, s32 arg3, s32 arg4) {
    s32 i;
    u8 *slot;

    if (D_overlay_8_008016C0 == 0) {
        func_overlay_8_00800000_1EFF168();
    }
    if (D_overlay_8_008017A4 < 5) {
        /* find first free slot (active flag at +0x16, 0x18-byte entries) */
        slot = D_overlay_8_00802CC0;
        i = 0;
        while (i < 5 && slot[0x16] != 0) {
            i++;
            slot += 0x18;
        }
        if (i < 5) {
            *(f32 *)(slot + 0x00) = arg0;
            *(f32 *)(slot + 0x04) = arg1;
            *(f32 *)(slot + 0x08) = arg2;
            *(f32 *)(slot + 0x0C) = 0.0f;
            *(s8 *)(slot + 0x14) = (s8) arg3;
            *(u8 *)(slot + 0x15) = (u8) arg4;
            slot[0x16] = 1;
            D_overlay_8_008017A4 += 1;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o8/overlay_8/bloodHitSpriteAdd.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void bloodSpurtUpdateAll(s32 arg0) {
    TrackHit hit;
    BloodSpurt *spur;
    BloodHitSprite *hs;
    s32 i;
    s32 texFrame;
    f32 dt;
    f32 floorY;
    f32 cosRnd;
    f32 sinRnd;
    f32 cosA;
    f32 sinA;
    f32 cosB;
    f32 sinB;
    f32 t2;
    f32 t12;
    f32 t14;
    f32 t16;
    f32 t18;
    f32 t22;
    f32 t2b;
    f32 t12b;
    f32 t14b;
    s16 yawA;
    s16 yawB;
    s16 rndAng;
    s16 negYaw;
    s16 prevScale;
    f32 vel;
    s32 parity;

    dt = (f32) arg0;
    floorY = (f32) *(s16 *) ((u8 *) trackGetTrack() + 0x24) - 1000.0f;
    texFrame = 1;
    spur = (BloodSpurt *) D_overlay_8_008017C0;
    i = 0;
    do {
        switch (spur->unk4A) {
        case 1:
            vel = spur->unk1C;
            spur->unk4 = spur->unk4 + vel * dt;
            if (spur->unk4 < floorY) {
                spur->unk4A = 0;
                D_overlay_8_008017A0 -= 1;
            } else {
                parity = i & 1;
                spur->unk0 = spur->unk0 + spur->unk18 * dt;
                spur->unk8 = spur->unk8 + spur->unk20 * dt;
                spur->unk1C = vel - D_overlay_8_00801790 * dt;
                if ((parity != 0 && D_overlay_8_00802D38 != 0) || (parity == 0 && D_overlay_8_00802D38 == 0)) {
                        if (trackNearestIntersection(0, &spur->unkC, spur, &hit, 0x2000, 0) != 0) {
                            spur->unk2C = hit.nrm[0];
                            spur->unk30 = hit.nrm[1];
                            spur->unk34 = hit.nrm[2];
                            spur->unk38 = hit.nrm[3];
                            spur->unk0 = hit.pos[0];
                            spur->unk4 = hit.pos[1];
                            spur->unk8 = hit.pos[2];
                            spur->unk4E = (s16) ((0xFF - (((hit.flags >> 22) & 7) << 5)) << 5);
                            spur->unk28 = spur->unk28 * (2.0f + ((f32) (mathRnd(0, 0xFF) - 0x80) * D_overlay_8_00801794));
                            amSndPlayXYZ((mathRnd(0, 3) + 0xAA) & 0xFFFF, spur->unk0, spur->unk4, spur->unk8, 4, 0);
                            if (hit.found == 0 && hit.surf != 3) {
                                yawA = (s16) (Arctanf(hit.nrm[1], sqrtf((hit.nrm[2] * hit.nrm[2]) + (hit.nrm[0] * hit.nrm[0]))) - 0x4000);
                                yawB = (s16) Arctanf(-hit.nrm[0], -hit.nrm[2]);
                                rndAng = (s16) mathRnd(-0x8000, 0x7FFF);
                                cosRnd = Cosf((s32) rndAng);
                                sinRnd = Sinf(rndAng);
                                negYaw = -yawA;
                                cosA = Cosf((s32) negYaw);
                                sinA = Sinf(negYaw);
                                cosB = Cosf((s32) yawB);
                                sinB = Sinf(yawB);
                                t18 = 10.0f * sinRnd;
                                t16 = spur->unk28;
                                t2 = ((-10.0f * cosRnd) + t18) * t16;
                                t22 = 10.0f * cosRnd;
                                t12 = (t22 - (-10.0f * sinRnd)) * t16;
                                t14 = t12 * cosA;
                                spur->unk40 = (s16) (s32) (t12 * sinA);
                                spur->unk52 = 1;
                                spur->unk3E = (s16) (s32) ((t2 * cosB) + (t14 * sinB));
                                spur->unk42 = (s16) (s32) ((t14 * cosB) - (t2 * sinB));
                                t2b = (t22 + t18) * t16;
                                t12b = (t22 - t18) * t16;
                                t14b = t12b * cosA;
                                spur->unk46 = (s16) (s32) (t12b * sinA);
                                spur->unk44 = (s16) (s32) ((t2b * cosB) + (t14b * sinB));
                                spur->unk48 = (s16) (s32) ((t14b * cosB) - (t2b * sinB));
                            } else {
                                spur->unk52 = 0;
                            }
                            spur->unk4A = 2;
                        } else {
                            spur->unkC = spur->unk0;
                            spur->unk10 = spur->unk4;
                            spur->unk14 = spur->unk8;
                        }
                    }
                }
            break;
        case 2:
            prevScale = spur->unk4C;
            spur->unk4C = (s16) (prevScale + ((s32) (spur->unk4E - prevScale) >> 1));
            if (texAnimateSprite(D_overlay_8_008017BC, &texFrame, 0xC, &spur->unk24, arg0) != 0) {
                spur->unk4A = 3;
            }
            break;
        case 3:
            spur->unk3C = (s16) (spur->unk3C - arg0);
            if (spur->unk3C < 0) {
                spur->unk4A = 0;
                D_overlay_8_008017A0 -= 1;
            }
            break;
        }
        i++;
        spur++;
    } while (i < 0x40);

    D_overlay_8_00802D38 ^= 1;
    texFrame = 1;
    hs = (BloodHitSprite *) D_overlay_8_00802CC0;
    for (i = 0; i < 5; i++) {
        if (hs->unk16 != 0 && texAnimateSprite(D_overlay_8_008017BC, &texFrame, 0xF, &hs->unkC, arg0) != 0) {
            hs->unk16 = 0;
            D_overlay_8_008017A4 -= 1;
        }
        hs++;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o8/overlay_8/bloodSpurtUpdateAll.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Display-list writer: appends one 64-bit Gfx command and advances the cursor.
static void bloodGfxPut(void **cur, u32 w0, u32 w1) {
    u32 *p = (u32 *) *cur;

    p[0] = w0;
    p[1] = w1;
    *cur = (u8 *) *cur + 8;
}

void bloodSpurtsDraw(void **arg0, s32 *arg1, void **arg2) {
    void *dl;
    s32 spC0;
    void *vtx;
    u8 *v;
    BloodSpurt *spur;
    BloodHitSprite *hs;
    s32 i;
    s32 n;
    s32 k;
    s32 lastAlpha;
    s32 *colTbl;
    s32 rgb;
    s32 color;
    s32 envColor;
    s32 alpha;
    s32 hitTimer;
    void *texPtr;
    f32 projZf;
    f32 f2;
    f32 off;
    f32 zScale;
    f32 px;
    f32 py;
    f32 pz;
    f32 spLen;
    f32 vscale;
    f32 dist;
    f32 tracerPos[3];
    u8 sprAlpha;
    u8 r;
    u8 *c;
    s32 *fxTbl;

    dl = *arg0;
    spC0 = *arg1;
    vtx = *arg2;
    lastAlpha = 0;
    spur = (BloodSpurt *) D_overlay_8_008017C0;
    i = 0;
    do {
        if (spur->unk4A != 0) {
            lastAlpha = spur->unk4C;
            rgb = ((lastAlpha * 0xFF) >> 5) & 0xFF00;
            color = rgb | (rgb << 8) | (rgb << 16) | 0xFF;
            colTbl = &D_overlay_8_008016C4[spur->unk50 * 3];
            envColor = (((colTbl[2] * lastAlpha) >> 5) & 0xFF00) | (((lastAlpha * colTbl[0]) << 11) & 0xFF000000) |
                       ((lastAlpha * colTbl[1] * 8) & 0xFF0000) | 0xFF;
        }
        if ((spur->unk4A == 2 || spur->unk4A == 3) && spur->unk52 != 0) {
            hitTimer = spur->unk3C;
            alpha = 0xFF;
            if (hitTimer < 0x78) {
                alpha = (hitTimer * 0xFF) / 120;
            }
            texPtr = ((void **) &D_overlay_8_008017B0)[spur->unk51];
            if (texPtr != NULL) {
                texDPTextureX(&dl, (s32) texPtr, 0x203, 0);
                bloodGfxPut(&dl, 0xE7000000, 0);
                bloodGfxPut(&dl, 0xFA000000, (color & ~0xFF) | alpha);
                bloodGfxPut(&dl, 0xFB000000, (envColor & ~0xFF) | alpha);
                bloodGfxPut(&dl, 0x04000030 | (((((u32) vtx + 0x80000000) & 6) | 0x20) & 0xFF) << 16, (u32) vtx + 0x80000000);
                bloodGfxPut(&dl, 0x05110020, 0x80000040);

                /* asm: a2 receives the raw bits of unk8, a3 is not set before the call */
                projZf = -camGetProjZ(spur->unk0, spur->unk4, *(void **) &spur->unk8, 0.0f);
                f2 = projZf;
                if (projZf < 0.0f) {
                    f2 = -projZf;
                }
                off = f2 - 250.0f;
                if (off < 0.0f) {
                    off = 0.0f;
                }
                if (off > 1024.0f) {
                    off = 1024.0f;
                }
                zScale = 2.0f + (off * D_overlay_8_00801798);
                px = (spur->unk2C * zScale) + spur->unk0;
                py = (spur->unk30 * zScale) + spur->unk4;
                pz = (spur->unk34 * zScale) + spur->unk8;

                /* four 10-byte vertices at +0x00, +0x0A, +0x14, +0x1E: pos (s16 x3) then rgba */
                v = (u8 *) vtx;
                *(s16 *) (v + 0x00) = (s16) ((f32) spur->unk3E + px);
                *(s16 *) (v + 0x02) = (s16) ((f32) spur->unk40 + py);
                *(s16 *) (v + 0x04) = (s16) ((f32) spur->unk42 + pz);
                *(s16 *) (v + 0x0A) = (s16) ((f32) spur->unk44 + px);
                *(s16 *) (v + 0x0C) = (s16) ((f32) spur->unk46 + py);
                *(s16 *) (v + 0x0E) = (s16) ((f32) spur->unk48 + pz);
                *(s16 *) (v + 0x14) = (s16) (px - (f32) spur->unk44);
                *(s16 *) (v + 0x16) = (s16) (py - (f32) spur->unk46);
                *(s16 *) (v + 0x18) = (s16) (pz - (f32) spur->unk48);
                *(s16 *) (v + 0x1E) = (s16) (px - (f32) spur->unk3E);
                *(s16 *) (v + 0x20) = (s16) (py - (f32) spur->unk40);
                *(s16 *) (v + 0x22) = (s16) (pz - (f32) spur->unk42);
                for (k = 0; k < 4; k++) {
                    c = v + (k == 0 ? 0 : k == 1 ? 0x0A : k == 2 ? 0x14 : 0x1E) + 6;
                    c[0] = 0xFF;
                    c[1] = 0xFF;
                    c[2] = 0xFF;
                    c[3] = 0xFF;
                }
                vtx = v + 0x28;
            }
        }
        switch (spur->unk4A) {
        case 1:
            spLen = sqrtf((spur->unk18 * spur->unk18) + (spur->unk1C * spur->unk1C) + (spur->unk20 * spur->unk20));
            if (spLen == 0.0f) {
                vscale = 0.0f;
            } else {
                vscale = 40.0f / spLen;
            }
            dist = vscale * spur->unk28;
            tracerPos[0] = spur->unk0 - (spur->unk18 * dist);
            tracerPos[1] = spur->unk4 - (spur->unk1C * dist);
            tracerPos[2] = spur->unk8 - (spur->unk20 * dist);
            objDrawTracer(&dl, &vtx, (s32) ((void **) &D_overlay_8_008017A8)[spur->unk4B],
                          (spur->unk4B == 0) ? (void *) D_overlay_8_00801660 : (void *) D_overlay_8_00801680, spur, tracerPos,
                          spur->unk28 * 8.0f, color, envColor, 0x200);
            break;
        case 2:
            sprSetIA2ColOverride((u8) ((lastAlpha * 0xFF) >> 0xD), (u8) ((lastAlpha * 0xFF) >> 0xD),
                                 (u8) ((lastAlpha * 0xFF) >> 0xD), (u8) ((colTbl[0] * lastAlpha) >> 0xD),
                                 (u8) ((colTbl[1] * lastAlpha) >> 0xD), (u8) ((colTbl[2] * lastAlpha) >> 0xD));
            camDoSpriteDirect(&dl, &spC0, &vtx, D_overlay_8_008017BC, (s32) spur->unk0, (s32) spur->unk4, (s32) spur->unk8, 0,
                              spur->unk28 * D_overlay_8_0080179C, spur->unk24, 0xE, 0xFF);
            sprClearIA2ColOverride();
            break;
        }
        i++;
        spur++;
    } while (i < 0x40);

    hs = (BloodHitSprite *) D_overlay_8_00802CC0;
    for (n = 0; n != 5; n++) {
        if (hs->unk16 != 0) {
            sprAlpha = (u8) hs->unk14;
            fxTbl = &D_overlay_8_00801724[hs->unk15 * 3];
            r = (u8) (((s32) (sprAlpha * 0xFF) >> 8) & 0xFF);
            sprSetIA2ColOverride(r, r, r, (u8) (((fxTbl[0] * sprAlpha) >> 8) & 0xFF), (u8) (((fxTbl[1] * sprAlpha) >> 8) & 0xFF),
                                 (u8) (((fxTbl[2] * sprAlpha) >> 8) & 0xFF));
            camDoSpriteDirect(&dl, &spC0, &vtx, D_overlay_8_008017BC, (s32) hs->unk0, (s32) hs->unk4, (s32) hs->unk8, 0, 4.0f,
                              hs->unkC, 0xE, 0xFF);
        }
        hs++;
    }
    sprClearIA2ColOverride();
    bloodGfxPut(&dl, 0xFA000000, 0xFFFFFFFF);

    *arg0 = dl;
    *arg1 = spC0;
    *arg2 = vtx;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o8/overlay_8/bloodSpurtsDraw.s")
#endif
