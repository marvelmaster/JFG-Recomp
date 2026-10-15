#include "common.h"

/* decomp: externs */
extern void *partgraphics;
extern s32 partlistsize;
extern s32 D_800A5DB4_A69B4;
extern void *partlists[];
extern void *D_801008F4_B1764[];
extern void *lines;
extern s32 maxlines;
extern void *pointstreams;
extern s32 maxpointstreams;
extern void *pointpolys;
extern void *pointvtxinit;
extern void *trigdatbuffers;
extern s32 maxchildtriggerparticles;
extern struct { void *unk0; s32 unk4; } partvertices;
extern void *PartTrigTab[];
extern void *PartTab[];
extern s32 notrigtypes;
extern void *D_800A5F78_A6B78[];
extern f32 D_800A5DDC_A69DC;
extern s32 D_800A5DB8_A69B8[];
extern u8 D_800A5DE0_A69E0;
extern s32 D_80100900_B1770;
extern u8 D_80100908_B1778[];
extern f32 D_801008F8_B1768;
extern f32 D_801008FC_B176C;
void texFreeSprite(s32 arg0);
void texFreeTexture(s32 arg0);
void modFreeModel(s32 arg0);
void func_8005D930(void);
void func_8005DA70(void);
void func_8005DC3C(void);
void func_8005DC7C(void **arg0);
void partInitTriggerPos(void *arg0, s32 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5);
s32 func_8005FD34(void *arg0, s32 *arg1);
s32 func_8005FAE8(void *arg0, s32 *arg1, s32 arg2);
void func_8005FED8(u8 *arg0, s32 arg1);
void func_8006020C(u8 *arg0, u8 *arg1);
void *func_80060ED4(u8 *arg0, u8 *arg1, s16 arg2);
void func_80061B50(u8 *arg0);
void *func_80061948(s16 arg0, s32 arg1);
s32 func_80061CAC(u8 *arg0, s32 arg1);
void func_8006211C(u8 *arg0, u8 *arg1);
void func_800637E0(u8 *arg0, u8 *arg1);
void func_80063890(u8 *arg0);
void func_80063990(u8 *arg0);
void func_80063AB4(u8 *arg0);
void func_80063C14(u8 *arg0);
void func_80063CC8(u8 *arg0);
void func_80062BFC(Gfx **arg0, u8 **arg1, u8 *arg2);
void texDPTextureX(Gfx **dlist, void *tex, s32 rtile, s32 tmem);
extern u8 D_A5DE8[];
TextureHeader *texLoadSprite(s32 arg0, s32 arg1);
void *modLoadModel(s32 arg0, s32 arg1);
void texAnimateSprite(s32 arg0, void *arg1, s32 arg2, void *arg3, s32 arg4);
void texAnimateTexSprite(s32 arg0, void *arg1, s32 arg2, void *arg3, s32 arg4);
void mathOneFloatPY(s16 *arg0, void *arg1);
void mathMtxFastXFMF(void *arg0, void *arg1, void *arg2, void *arg3);
extern s32 D_800A5DD8_A69D8;
extern void *D_801008E4_B1754;
extern s32 D_801008E8_B1758;
extern s32 D_801008EC_B175C;
extern void *D_801008F0_B1760[];
extern u8 D_80100958_B17C8[];
void camSetNo(s32 arg0);
void camSetView(void **arg0, void **arg1);
void func_8005DD88(void **arg0, s32 arg1, s32 *arg2, void *arg3);
void camDoSprite(void **arg0, void **arg1, void **arg2, void *arg3, s32 arg4, s32 arg5, u8 arg6);
void func_8005E3DC(void **arg0, s32 *arg1, void *arg2);
f32 Sinf(s16 angle);
s32 trackGetIntersect(s32 arg0, u8 *arg1, s32 arg2, s32 arg3, s32 arg4, f32 *arg5);
void trackMakePolylist(s32 arg0, u8 *arg1, s32 arg2, s32 *arg3, s32 arg4, s32 arg5, s32 arg6);

const char D_800AE190[] = "Triangle";
const char D_800AE19C[] = "Rectangle";
const char D_800AE1A8[] = "Sprite";
const char D_800AE1B0[] = "Points";
const char D_800AE1B8[] = "Models";
const char D_800AE1C0[] = "\n\nUnknown trigger type in partInitTrigger %d, Max %d.\n\n";
const char D_800AE1F8[] = "\n\nUnknown trigger type in partInitTrigger %d, Max %d.\n\n";
const char D_800AE230[] = "\n\nUnknown particle type in partInitTriggerPos %d, Max %d.\n\n";
const char D_800AE26C[] = "\n\nUnknown trigger type in partInitTriggerPos %d, Max %d.\n\n";
const char D_800AE2A8[] = "particle warning: Object %s has SP emitter, but matrices not generated\n";
const char D_800AE2F0[] = "allocParticle: Illegal particle type %d\n";
const char D_800AE31C[] = "%s particle buffer full\n";
const char D_800AE338[] = "\n\nParticle of type %d has been freed twice, this is Super Safe, Honest!\n";
const char D_800AE384[] = "freeParticle: Unknown particle type %d\n";
const char D_800AE3AC[] = "%s particle buffer is empty\n";

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void partFreeLib(void) {
    func_8005DA70();
    func_8005DC3C();
    func_8005D930();
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/partFreeLib.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8005D930(void) {
    s16 *temp_v0; // s16 graphic ids (lh, stride 2)
    s16 *var_s1;
    s32 var_s0;
    s32 temp_t7;

    if (partgraphics != NULL) {
        temp_v0 = piRomLoad(0x3C);
        var_s0 = 0;
        if (partlistsize > 0) {
            var_s1 = temp_v0;
            do {
                temp_t7 = *var_s1 & 0xC000;
                switch (temp_t7) {
                case 0x8000:
                    texFreeSprite(((s32 *)partgraphics)[var_s0]);
                    break;
                case 0xC000:
                    texFreeTexture(((s32 *)partgraphics)[var_s0]);
                    break;
                case 0x0:
                    modFreeModel(((s32 *)partgraphics)[var_s0]);
                    break;
                }
                var_s0 += 1;
                var_s1 += 1;
            } while (var_s0 < partlistsize);
        }
        mmFree(temp_v0);
        mmFree(partgraphics);
        partgraphics = NULL;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_8005D930.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8005DA70(void) {
    void **var_s0;
    u8 *var_s0_2;
    u8 *var_s0_3;
    s32 var_s1;
    s32 var_s1_2;

    for (var_s0 = partlists; (u32)var_s0 < (u32)&D_801008F4_B1764[0]; var_s0++) {
        func_8005DC7C(var_s0);
    }
    D_800A5DB4_A69B4 = 0;
    if (lines != NULL) {
        var_s0_2 = lines;
        for (var_s1 = 0; var_s1 < maxlines; var_s1++, var_s0_2 += 0x148) {
            if (*(u8 *)(var_s0_2 + 0x124) != 0) {
                if (*(void **)(var_s0_2 + 0x128) != NULL) {
                    texFreeTexture((s32)*(void **)(var_s0_2 + 0x128));
                }
            }
        }
        mmFree(lines);
        lines = NULL;
    }
    if (pointstreams != NULL) {
        var_s0_3 = pointstreams;
        for (var_s1_2 = 0; var_s1_2 < maxpointstreams; var_s1_2++, var_s0_3 += 0xC0) {
            if (*(u8 *)(var_s0_3 + 0xA4) != 0) {
                if (*(void **)(var_s0_3 + 0xB8) != NULL) {
                    texFreeTexture((s32)*(void **)(var_s0_3 + 0xB8));
                }
            }
        }
        mmFree(pointstreams);
        pointstreams = NULL;
    }
    if (pointpolys != NULL) {
        mmFree(pointpolys);
        pointpolys = NULL;
    }
    if (pointvtxinit != NULL) {
        mmFree(pointvtxinit);
        pointvtxinit = NULL;
    }
    if (trigdatbuffers != NULL) {
        mmFree(trigdatbuffers);
        trigdatbuffers = NULL;
        maxchildtriggerparticles = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_8005DA70.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8005DC3C(void) {
    if (partvertices.unk0 != NULL) {
        mmFree(partvertices.unk0);
        partvertices.unk0 = NULL;
        partvertices.unk4 = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_8005DC3C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8005DC7C(void **arg0) {
    u8 *temp_s2;
    u8 *var_s0;
    s32 var_s1;
    s16 temp_v0;

    temp_s2 = *arg0;
    if (temp_s2 != NULL) {
        var_s0 = *(u8 **)(temp_s2 + 0x14);
        var_s1 = 0;
        if (*(s32 *)(temp_s2 + 0x18) > 0) {
            do {
                temp_v0 = *(s16 *)(var_s0 + 0x2C);
                switch (temp_v0) {
                case 2:
                    texFreeSprite((s32)*(void **)(var_s0 + 0x4C));
                    break;
                case 0:
                case 1:
                    texFreeTexture((s32)*(void **)(var_s0 + 0x4C));
                    break;
                case 3:
                    modFreeModel((s32)*(void **)(var_s0 + 0x4C));
                    break;
                }
                var_s1 += 1;
                var_s0 += 0x78;
            } while (var_s1 < *(s32 *)(temp_s2 + 0x18));
        }
        mmFree(temp_s2);
        *arg0 = NULL;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_8005DC7C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Entry: 0x78-byte records, arg3 = { +0x14 entries, +0x18 count }.
void func_8005DD88(void **arg0, s32 arg1, s32 *arg2, void *arg3) {
    u8 *entry;
    u8 *spr;
    u32 *dl;
    s32 i;
    s32 mode;
    s32 alpha;
    s32 brightness;
    s32 mult;
    s32 ovR = 0; /* asm: stack slots 0x60/0x64 read uninitialised, never observed */
    s32 ovG = 0;
    s32 ovB = 0;
    u8 r;
    u8 g;
    u8 b;

    if (arg3 != NULL) {
        entry = *(u8 **) ((u8 *) arg3 + 0x14);
        for (i = 0; i < *(s32 *) ((u8 *) arg3 + 0x18); i++, entry += 0x78) {
            if (*(s16 *) (entry + 0x2C) == 2) {
                mode = entry[0x70];
                spr = *(u8 **) (entry + 0x4C);
                r = entry[0x71];
                g = entry[0x72];
                b = entry[0x73];
                mult = 2;
                if (mode != 0) {
                    ovR = entry[0x74];
                    ovG = entry[0x75];
                    ovB = entry[0x76];
                }
                alpha = (*(s16 *) (entry + 0x64) >> 8) & 0xFF;
                if (*(s32 *) (entry + 0x50) & 0x800) {
                    brightness = entry[0x6F];
                    r = (u8) ((brightness * r) >> 8);
                    g = (u8) ((brightness * g) >> 8);
                    b = (u8) ((brightness * b) >> 8);
                    if (mode != 0) {
                        ovR = (brightness * ovR) >> 8;
                        ovG = (brightness * ovG) >> 8;
                        ovB = (brightness * ovB) >> 8;
                    }
                }
                if (*(s16 *) (spr + 0x6) & 0x200) {
                    /* IA2 colour override from the sprite header */
                    if (mode == 0) {
                        ovR = (spr[0xB] * r) >> 8;
                        ovG = (spr[0xC] * g) >> 8;
                        ovB = (spr[0xD] * b) >> 8;
                        r = (u8) ((spr[0x8] * r) >> 8);
                        g = (u8) ((spr[0x9] * g) >> 8);
                        b = (u8) ((spr[0xA] * b) >> 8);
                    }
                    if (mode != 2) {
                        sprSetIA2ColOverride(r, g, b, ovR & 0xFF, ovG & 0xFF, ovB & 0xFF);
                    } else {
                        sprSetIA2ColOverride(ovR & 0xFF, ovG & 0xFF, ovB & 0xFF, r, g, b);
                    }
                } else if ((((u32) r << 24) | ((u32) g << 16) | ((u32) b << 8) | alpha) != 0) {
                    /* gDPPipeSync + gDPSetPrimColor(0, 0, r, g, b, alpha) */
                    dl = (u32 *) *arg0;
                    *arg0 = dl + 2;
                    dl[0] = 0xE7000000;
                    dl[1] = 0;
                    dl = (u32 *) *arg0;
                    *arg0 = dl + 2;
                    dl[0] = 0xFA000000;
                    dl[1] = ((u32) r << 24) | ((u32) g << 16) | ((u32) b << 8) | (u32) alpha;
                }
                if (alpha != 0xFF) {
                    mult = 6;
                }
                camDoSprite(arg0, (void **) arg1, (void **) arg2, entry, (s32) spr, mult, alpha);
                if (*(s16 *) (spr + 0x6) & 0x200) {
                    sprClearIA2ColOverride();
                }
            }
        }
        /* gDPPipeSync, gDPSetPrimColor(-1), gDPSetEnvColor(-1) */
        dl = (u32 *) *arg0;
        *arg0 = dl + 2;
        dl[0] = 0xE7000000;
        dl[1] = 0;
        dl = (u32 *) *arg0;
        *arg0 = dl + 2;
        dl[0] = 0xFA000000;
        dl[1] = 0xFFFFFFFF;
        dl = (u32 *) *arg0;
        *arg0 = dl + 2;
        dl[1] = 0xFFFFFFFF;
        dl[0] = 0xFB000000;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_8005DD88.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8005E100(Gfx **arg0, MatrixS **arg1, s32 arg2, void *arg3) {
    ObjectTransform sp98;
    Gfx *temp_v0;
    Gfx *temp_v0_2;
    Gfx *temp_v0_3;
    Gfx *temp_v0_4;
    Gfx *temp_v0_5;
    Gfx *temp_v0_6;
    Gfx *temp_v0_7;
    Gfx *temp_v0_8;
    Gfx *temp_v0_9;
    u8 *var_s0;
    u8 *temp_s2;
    u8 temp_v1;
    s32 var_s3;
    s32 var_a2;

    if (arg3 != NULL) {
        temp_v0 = *arg0;
        var_s0 = *(u8 **)((u8 *)arg3 + 0x14);
        *arg0 = temp_v0 + 1;
        temp_v0->words.w0 = 0xE7000000;
        temp_v0->words.w1 = 0;
        var_a2 = *(s32 *)((u8 *)arg3 + 0x18);
        for (var_s3 = 0; var_s3 < var_a2; var_s3++, var_s0 += 0x78) {
            if (*(s16 *)(var_s0 + 0x2C) == 3) {
                temp_s2 = *(u8 **)(var_s0 + 0x4C);
                sp98.y_rotation = *(s16 *)(var_s0 + 0x0);
                sp98.x_rotation = *(s16 *)(var_s0 + 0x2);
                sp98.z_rotation = *(s16 *)(var_s0 + 0x4);
                sp98.scale = *(f32 *)(var_s0 + 0x8);
                sp98.x_position = *(f32 *)(var_s0 + 0xC);
                sp98.y_position = *(f32 *)(var_s0 + 0x10);
                sp98.z_position = *(f32 *)(var_s0 + 0x14);
                camPushModelMtx(arg0, arg1, &sp98, 1.0f, 0.0f);
                temp_v0_2 = *arg0;
                *arg0 = temp_v0_2 + 1;
                temp_v0_2->words.w1 = 0;
                temp_v0_2->words.w0 = 0xE7000000;
                if (*(u32 *)(var_s0 + 0x50) & 0x800) {
                    temp_v1 = var_s0[0x6F];
                    temp_v0_3 = *arg0;
                    *arg0 = temp_v0_3 + 1;
                    temp_v0_3->words.w0 = 0xFA000000;
                    temp_v0_3->words.w1 = (((s32)(var_s0[0x71] * temp_v1) >> 8) << 0x18)
                        | ((((s32)(var_s0[0x72] * temp_v1) >> 8) & 0xFF) << 0x10)
                        | ((((s32)(var_s0[0x73] * temp_v1) >> 8) & 0xFF) << 8) | 0xFF;
                } else {
                    temp_v0_4 = *arg0;
                    *arg0 = temp_v0_4 + 1;
                    temp_v0_4->words.w1 = -1U;
                    temp_v0_4->words.w0 = 0xFA000000;
                }
                temp_v0_5 = *arg0;
                *arg0 = temp_v0_5 + 1;
                temp_v0_5->words.w0 = (((*(s32 *)(temp_s2 + (((s8 *)temp_s2)[0xB] * 4) + 0x10)) + 0x80000000) & 0xFFFFFF) | 0xBF000000;
                temp_v0_5->words.w1 = *(s32 *)(temp_s2 + 0x4) + 0x80000000;
                temp_v0_6 = *arg0;
                *arg0 = temp_v0_6 + 1;
                temp_v0_6->words.w0 = 0x06000000;
                temp_v0_6->words.w1 = *(s32 *)(*(u8 **)temp_s2 + 0x74) + 0x80000000;
                temp_v0_7 = *arg0;
                *arg0 = temp_v0_7 + 1;
                temp_v0_7->words.w1 = 0;
                temp_v0_7->words.w0 = 0xBF000000;
            }
        }
        temp_v0_8 = *arg0;
        *arg0 = temp_v0_8 + 1;
        temp_v0_8->words.w1 = 0;
        temp_v0_8->words.w0 = 0xE7000000;
        temp_v0_9 = *arg0;
        *arg0 = temp_v0_9 + 1;
        temp_v0_9->words.w1 = -1U;
        temp_v0_9->words.w0 = 0xFA000000;
        camRestoreModelMtx(arg0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_8005E100.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Builds vertices + display-list commands for one emitter. Entries are 0x78 bytes:
// +0x0/+0x2/+0x4 rotation (y, x, z), +0x8 scale, +0xC/+0x10/+0x14 offset (x, y, z),
// +0x28 texture scale, +0x2C type (0x80 = skipped), +0x4C texture, +0x50 flags
// (0x800 = colour scaled by +0x6F), +0x54 rotation mode (1/2/4, none = pointListRPY),
// +0x64 alpha in the high byte, +0x71..+0x73 colour.
// Emitter (arg2): +0x4 verts per entry, +0x8 tris per entry, +0xC s16 point pairs,
// +0x14 entries, +0x18 count, +0x1C active flag, +0x2C/+0x30/+0x34 texture cmd addrs.
void func_8005E3DC(void **arg0, s32 *arg1, void *arg2) {
    u8 *em;
    Gfx *dl;
    u8 *vtx;
    u8 *vp;
    u8 *batchBase;
    u8 *ent;
    s16 *pts;
    u8 *texCur;
    u8 *texLast;
    s32 i;
    s32 count;
    s32 nVtx;
    s32 nTri;
    s32 nPt;
    s32 batchVtx;
    s32 batchTri;
    s32 keyCur;
    s32 keyLast;
    s32 alpha;
    s32 colR;
    s32 colG;
    s32 colB;
    s32 cmdAddr;
    s32 flags54;
    s32 mul;
    u32 addr;
    s16 vx;
    s16 vy;
    s16 vz;
    f32 scale;
    f32 scaleCur;
    f32 scaleLast;
    f32 offX;
    f32 offY;
    f32 offZ;
    f32 a;
    f32 b;
    f32 cx;
    f32 sx;
    f32 cy;
    f32 sy;
    f32 cz;
    f32 sz;
    f32 vec[3];

    keyLast = 0xFF;
    texLast = NULL;
    scaleLast = 0.0f;

    if (arg2 != NULL) {
        em = (u8 *)arg2;
        if (*(s32 *)(em + 0x1C) != 0) {
            dl = (Gfx *)*arg0;
            vtx = (u8 *)*arg1;
            count = *(s32 *)(em + 0x18);
            ent = *(u8 **)(em + 0x14);
            i = 0;
            if (count > 0 && *(s16 *)(ent + 0x2C) == 0x80) {
                do {
                    i++;
                    ent += 0x78;
                } while (i < count && *(s16 *)(ent + 0x2C) == 0x80);
            }
            nVtx = *(s32 *)(em + 0x4);
            nTri = *(s32 *)(em + 0x8);

            texDPTextureX(&dl, NULL, 0x12, 0);
            cmdAddr = *(s32 *)(em + 0x2C);
            dl->words.w0 = 0xFA000000;
            dl->words.w1 = 0xFFFFFFFF;
            dl++;

            batchVtx = 0;
            batchTri = 0;

            if (i < count) {
                texCur = *(u8 **)(ent + 0x4C);
                keyCur = (*(s16 *)(ent + 0x64) >> 8) & 0xFF;
                scaleCur = *(f32 *)(ent + 0x28);
                batchBase = vtx;

                do {
                    if (*(s16 *)(ent + 0x2C) != 0x80 && texCur == *(u8 **)(ent + 0x4C)
                        && scaleCur == *(f32 *)(ent + 0x28) && batchVtx + nVtx < 0x18
                        && keyCur == ((*(s16 *)(ent + 0x64) >> 8) & 0xFF)) {
                        /* join the current batch: emit this entry's vertices */
                        batchVtx += nVtx;
                        scale = *(f32 *)(ent + 0x8);
                        offX = *(f32 *)(ent + 0xC);
                        offY = *(f32 *)(ent + 0x10);
                        offZ = *(f32 *)(ent + 0x14);
                        pts = *(s16 **)(em + 0xC);
                        if (*(u32 *)(ent + 0x50) & 0x800) {
                            mul = *(u8 *)(ent + 0x6F);
                            colR = (*(u8 *)(ent + 0x71) * mul) >> 8;
                            colG = (*(u8 *)(ent + 0x72) * mul) >> 8;
                            colB = (*(u8 *)(ent + 0x73) * mul) >> 8;
                        } else {
                            colR = *(u8 *)(ent + 0x71);
                            colG = *(u8 *)(ent + 0x72);
                            colB = *(u8 *)(ent + 0x73);
                        }
                        alpha = keyCur;
                        flags54 = *(s32 *)(ent + 0x54);
                        nPt = 0;

                        if ((flags54 & 1) != 0) {
                            /* rotation mode 1: z (+4), y (+0) */
                            cz = Cosf(*(s16 *)(ent + 0x4));
                            sz = Sinf(*(s16 *)(ent + 0x4));
                            cy = Cosf(*(s16 *)(ent + 0x0));
                            sy = Sinf(*(s16 *)(ent + 0x0));
                            if (nVtx > 0) {
                                if (nVtx & 1) {
                                    a = (f32)pts[0] * scale;
                                    b = (f32)pts[1] * scale;
                                    pts += 2;
                                    vp = vtx;
                                    vtx += 0xA;
                                    vx = (s16)(s32)((((a * cy) * cz) - (b * sz)) + offX);
                                    vy = (s16)(s32)(((b * cz) + ((a * cy) * sz)) + offY);
                                    vz = (s16)(s32)(((-a) * sy) + offZ);
                                    *(s16 *)(vp + 0x0) = vx;
                                    *(s16 *)(vp + 0x2) = vy;
                                    *(s16 *)(vp + 0x4) = vz;
                                    vp[6] = colR;
                                    vp[7] = colG;
                                    vp[8] = colB;
                                    vp[9] = alpha;
                                    nPt = 1;
                                }
                                if (nPt != nVtx) {
                                    do {
                                        vp = vtx;
                                        vtx += 0x14;
                                        a = (f32)pts[0] * scale;
                                        b = (f32)pts[1] * scale;
                                        vx = (s16)(s32)((((a * cy) * cz) - (b * sz)) + offX);
                                        vy = (s16)(s32)(((b * cz) + ((a * cy) * sz)) + offY);
                                        vz = (s16)(s32)(((-a) * sy) + offZ);
                                        *(s16 *)(vp + 0x0) = vx;
                                        *(s16 *)(vp + 0x2) = vy;
                                        *(s16 *)(vp + 0x4) = vz;
                                        vp[6] = colR;
                                        vp[7] = colG;
                                        vp[8] = colB;
                                        vp[9] = alpha;
                                        vp += 0xA;
                                        a = (f32)pts[2] * scale;
                                        b = (f32)pts[3] * scale;
                                        vx = (s16)(s32)((((a * cy) * cz) - (b * sz)) + offX);
                                        vy = (s16)(s32)(((b * cz) + ((a * cy) * sz)) + offY);
                                        vz = (s16)(s32)(((-a) * sy) + offZ);
                                        *(s16 *)(vp + 0x0) = vx;
                                        *(s16 *)(vp + 0x2) = vy;
                                        *(s16 *)(vp + 0x4) = vz;
                                        vp[6] = colR;
                                        vp[7] = colG;
                                        vp[8] = colB;
                                        vp[9] = alpha;
                                        pts += 4;
                                        nPt += 2;
                                    } while (nPt != nVtx);
                                }
                            }
                        } else if ((flags54 & 2) != 0) {
                            /* rotation mode 2: x (+2), y (+0) */
                            cx = Cosf(*(s16 *)(ent + 0x2));
                            sx = Sinf(*(s16 *)(ent + 0x2));
                            cy = Cosf(*(s16 *)(ent + 0x0));
                            sy = Sinf(*(s16 *)(ent + 0x0));
                            if (nVtx > 0) {
                                if (nVtx & 1) {
                                    a = (f32)pts[0] * scale;
                                    b = (f32)pts[1] * scale;
                                    pts += 2;
                                    vp = vtx;
                                    vtx += 0xA;
                                    vx = (s16)(s32)(offX + (a * cy));
                                    vy = (s16)(s32)(((b * cx) - (((-a) * sy) * sx)) + offY);
                                    vz = (s16)(s32)(((((-a) * sy) * cx) + (b * sx)) + offZ);
                                    *(s16 *)(vp + 0x0) = vx;
                                    *(s16 *)(vp + 0x2) = vy;
                                    *(s16 *)(vp + 0x4) = vz;
                                    vp[6] = colR;
                                    vp[7] = colG;
                                    vp[8] = colB;
                                    vp[9] = alpha;
                                    nPt = 1;
                                }
                                if (nPt != nVtx) {
                                    do {
                                        vp = vtx;
                                        vtx += 0x14;
                                        a = (f32)pts[0] * scale;
                                        b = (f32)pts[1] * scale;
                                        vx = (s16)(s32)(offX + (a * cy));
                                        vy = (s16)(s32)(((b * cx) - (((-a) * sy) * sx)) + offY);
                                        vz = (s16)(s32)(((((-a) * sy) * cx) + (b * sx)) + offZ);
                                        *(s16 *)(vp + 0x0) = vx;
                                        *(s16 *)(vp + 0x2) = vy;
                                        *(s16 *)(vp + 0x4) = vz;
                                        vp[6] = colR;
                                        vp[7] = colG;
                                        vp[8] = colB;
                                        vp[9] = alpha;
                                        vp += 0xA;
                                        a = (f32)pts[2] * scale;
                                        b = (f32)pts[3] * scale;
                                        vx = (s16)(s32)(offX + (a * cy));
                                        vy = (s16)(s32)(((b * cx) - (((-a) * sy) * sx)) + offY);
                                        vz = (s16)(s32)(((((-a) * sy) * cx) + (b * sx)) + offZ);
                                        *(s16 *)(vp + 0x0) = vx;
                                        *(s16 *)(vp + 0x2) = vy;
                                        *(s16 *)(vp + 0x4) = vz;
                                        vp[6] = colR;
                                        vp[7] = colG;
                                        vp[8] = colB;
                                        vp[9] = alpha;
                                        pts += 4;
                                        nPt += 2;
                                    } while (nPt != nVtx);
                                }
                            }
                        } else if ((flags54 & 4) != 0) {
                            /* rotation mode 4: y (+0) only, y offset unrotated */
                            cy = Cosf(*(s16 *)(ent + 0x0));
                            sy = Sinf(*(s16 *)(ent + 0x0));
                            if (nVtx > 0) {
                                if (nVtx & 1) {
                                    a = (f32)pts[0] * scale;
                                    b = (f32)pts[1] * scale;
                                    pts += 2;
                                    vp = vtx;
                                    vtx += 0xA;
                                    vx = (s16)(s32)(offX + (a * cy));
                                    vy = (s16)(s32)(b + offY);
                                    vz = (s16)(s32)(((-a) * sy) + offZ);
                                    *(s16 *)(vp + 0x0) = vx;
                                    *(s16 *)(vp + 0x2) = vy;
                                    *(s16 *)(vp + 0x4) = vz;
                                    vp[6] = colR;
                                    vp[7] = colG;
                                    vp[8] = colB;
                                    vp[9] = alpha;
                                    nPt = 1;
                                }
                                if (nPt != nVtx) {
                                    do {
                                        vp = vtx;
                                        vtx += 0x14;
                                        a = (f32)pts[0] * scale;
                                        b = (f32)pts[1] * scale;
                                        vx = (s16)(s32)(offX + (a * cy));
                                        vy = (s16)(s32)(b + offY);
                                        vz = (s16)(s32)(((-a) * sy) + offZ);
                                        *(s16 *)(vp + 0x0) = vx;
                                        *(s16 *)(vp + 0x2) = vy;
                                        *(s16 *)(vp + 0x4) = vz;
                                        vp[6] = colR;
                                        vp[7] = colG;
                                        vp[8] = colB;
                                        vp[9] = alpha;
                                        vp += 0xA;
                                        a = (f32)pts[2] * scale;
                                        b = (f32)pts[3] * scale;
                                        vx = (s16)(s32)(offX + (a * cy));
                                        vy = (s16)(s32)(b + offY);
                                        vz = (s16)(s32)(((-a) * sy) + offZ);
                                        *(s16 *)(vp + 0x0) = vx;
                                        *(s16 *)(vp + 0x2) = vy;
                                        *(s16 *)(vp + 0x4) = vz;
                                        vp[6] = colR;
                                        vp[7] = colG;
                                        vp[8] = colB;
                                        vp[9] = alpha;
                                        pts += 4;
                                        nPt += 2;
                                    } while (nPt != nVtx);
                                }
                            }
                        } else {
                            /* no rotation mode: point list through pointListRPY */
                            if (nVtx > 0) {
                                do {
                                    vec[0] = (f32)pts[0] * scale;
                                    vec[1] = (f32)pts[1] * scale;
                                    vec[2] = 0.0f;
                                    pts += 2;
                                    pointListRPY(1, (s16 *)ent, (s32 *)vec, vec);
                                    vp = vtx;
                                    vtx += 0xA;
                                    vx = (s16)(s32)(vec[0] + offX);
                                    vy = (s16)(s32)(vec[1] + offY);
                                    vz = (s16)(s32)(vec[2] + offZ);
                                    *(s16 *)(vp + 0x0) = vx;
                                    *(s16 *)(vp + 0x2) = vy;
                                    *(s16 *)(vp + 0x4) = vz;
                                    vp[6] = colR;
                                    vp[7] = colG;
                                    vp[8] = colB;
                                    vp[9] = alpha;
                                    nPt++;
                                } while (nPt != nVtx);
                            }
                        }

                        ent += 0x78;
                        batchTri += nTri;
                        i++;
                        continue;
                    }

                    /* flush the current batch (state, texture, vertex and tri cmds) */
                    addr = (u32)batchBase + 0x80000000;
                    if (keyCur != keyLast) {
                        dl->words.w1 = 0;
                        dl->words.w0 = 0xE7000000;
                        dl++;
                        dl->words.w0 = 0xFA000000;
                        dl->words.w1 = (keyCur & 0xFF) | ~0xFF;
                        dl++;
                        keyLast = keyCur;
                    }
                    if (texCur != texLast || scaleCur != scaleLast) {
                        scaleLast = scaleCur;
                        texLast = texCur;
                        texDPTextureX(&dl, texCur, 0x12, (s32)(scaleCur * 65536.0f));
                    }
                    if (texCur != NULL) {
                        if (*texCur == 0x20) {
                            cmdAddr = *(s32 *)(em + 0x30);
                        } else if (*texCur == 0x40) {
                            cmdAddr = *(s32 *)(em + 0x2C);
                        } else {
                            cmdAddr = *(s32 *)(em + 0x34);
                        }
                    }
                    dl->words.w0 = ((((batchVtx * 8) | (addr & 6)) & 0xFF) << 16) | 0x04000000
                                   | (((batchVtx * 10) + 8) & 0xFFFF);
                    dl->words.w1 = addr;
                    dl++;
                    dl->words.w0 = (((((batchTri - 1) * 0x10) | 1) & 0xFF) << 16) | 0x05000000
                                   | ((batchTri * 0x10) & 0xFFFF);
                    dl->words.w1 = cmdAddr + 0x80000000;
                    dl++;

                    batchVtx = 0;
                    batchTri = 0;
                    if (i < count && *(s16 *)(ent + 0x2C) == 0x80) {
                        do {
                            i++;
                            ent += 0x78;
                        } while (i < count && *(s16 *)(ent + 0x2C) == 0x80);
                    }
                    if (i < count) {
                        texCur = *(u8 **)(ent + 0x4C);
                        scaleCur = *(f32 *)(ent + 0x28);
                        keyCur = (*(s16 *)(ent + 0x64) >> 8) & 0xFF;
                        batchBase = vtx;
                    }
                } while (i < count);

                /* final flush of the last open batch */
                if (batchTri != 0) {
                    addr = (u32)batchBase + 0x80000000;
                    if (keyCur != keyLast) {
                        dl->words.w1 = 0;
                        dl->words.w0 = 0xE7000000;
                        dl++;
                        dl->words.w0 = 0xFA000000;
                        dl->words.w1 = (keyCur & 0xFF) | ~0xFF;
                        dl++;
                    }
                    if (texCur != texLast || scaleCur != scaleLast) {
                        texDPTextureX(&dl, texCur, 0x12, (s32)(scaleCur * 65536.0f));
                    }
                    if (texCur != NULL) {
                        if (*texCur == 0x20) {
                            cmdAddr = *(s32 *)(em + 0x30);
                        } else if (*texCur == 0x40) {
                            cmdAddr = *(s32 *)(em + 0x2C);
                        } else {
                            cmdAddr = *(s32 *)(em + 0x34);
                        }
                    }
                    dl->words.w0 = ((((batchVtx * 8) | (addr & 6)) & 0xFF) << 16) | 0x04000000
                                   | (((batchVtx * 10) + 8) & 0xFFFF);
                    dl->words.w1 = addr;
                    dl++;
                    dl->words.w0 = (((((batchTri - 1) * 0x10) | 1) & 0xFF) << 16) | 0x05000000
                                   | ((batchTri * 0x10) & 0xFFFF);
                    dl->words.w1 = cmdAddr + 0x80000000;
                    dl++;
                }
                dl->words.w1 = 0;
                dl->words.w0 = 0xE7000000;
                dl++;
            }
            *arg0 = dl;
            *arg1 = (s32)vtx;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_8005E3DC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void partInitTrigger(void *arg0, s32 arg1, s16 arg2) {
    u8 *temp_v0;

    if (arg1 < notrigtypes) {
        temp_v0 = PartTrigTab[arg1];
        partInitTriggerPos(arg0, arg1, arg2,
                           (s16)*(f32 *)(temp_v0 + 0x4),
                           (s32)*(f32 *)(temp_v0 + 0x8),
                           (s32)*(f32 *)(temp_v0 + 0xC));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/partInitTrigger.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void partInitTriggerSPPos(void *arg0, s32 arg1, s16 arg2, s32 arg3) {
    if (arg1 < notrigtypes) {
        partInitTriggerPos(arg0, arg1, arg2, 0, 0, 0);
        ((u8 *)arg0)[0x23] = (u8)arg3;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/partInitTriggerSPPos.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void partInitTriggerPos(void *arg0, s32 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5) {
    u8 *p;
    u8 *temp_v0;
    s32 temp_v1;

    p = arg0;
    temp_v0 = PartTrigTab[arg1];
    *(s16 *)(p + 0xA) = arg2;
    *(s16 *)(p + 0xC) = 0;
    *(s16 *)(p + 0x1A) = arg3;
    *(u8 **)(p + 0x0) = temp_v0;
    *(s16 *)(p + 0x1C) = arg4;
    *(s16 *)(p + 0x20) = 0;
    p[0x23] = 0xFF;
    *(s16 *)(p + 0x1E) = arg5;
    temp_v1 = *(s32 *)temp_v0;
    if (temp_v1 & 0x4000) {
        *(s32 *)(p + 0x4) = 0x4000;
        p[0x22] = 0xFF;
        return;
    }
    if (temp_v1 & 0x400) {
        *(s32 *)(p + 0x4) = 0x400;
        p[0x22] = 0xFF;
        return;
    }
    *(s32 *)(p + 0x4) = 0;
    *(s16 *)(p + 0xE) = *(s16 *)(temp_v0 + 0x14);
    *(s16 *)(p + 0x10) = *(s16 *)(temp_v0 + 0x16);
    *(s16 *)(p + 0x12) = *(s16 *)(temp_v0 + 0x18);
    *(s16 *)(p + 0x14) = *(s16 *)(temp_v0 + 0x22);
    *(s16 *)(p + 0x16) = *(s16 *)(temp_v0 + 0x24);
    p[0x22] = 0;
    *(s16 *)(p + 0x18) = *(s16 *)(temp_v0 + 0x26);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/partInitTriggerPos.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_8005F918(s32 arg0, s16 arg1) {
    u8 *var_s0;
    s32 i;

    var_s0 = trigdatbuffers;
    for (i = 0; i < maxchildtriggerparticles; i++) {
        if (*(u8 *)(var_s0 + 0x24) == 0) {
            *(u8 *)(var_s0 + 0x24) = 1;
            *(s16 *)(var_s0 + 0xC) = 0;
            partInitTriggerPos(var_s0, arg0, arg1, 0, 0, 0);
            return var_s0;
        }
        var_s0 += 0x28;
    }
    return NULL;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_8005F918.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8005F99C(void *arg0, s32 arg1) {
    u8 *var_a2;
    void *sp1C;
    u8 *temp_a3;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_t9;
    s32 var_v1;

    var_a2 = *(u8 **)((u8 *)arg0 + 0x70) + (arg1 * 0x24);
    sp1C = PartTab[*(s16 *)(var_a2 + 0xA)];
    temp_a3 = *(u8 **)(var_a2 + 0x0);
    *(s16 *)(var_a2 + 0xC) = 0;
    if (*(s32 *)(var_a2 + 0x4) & 0x4000) {
        temp_v0 = func_8005FD34(sp1C, (s32 *)temp_a3);
        *(s8 *)(var_a2 + 0x22) = (s8)temp_v0;
    } else {
        temp_v0_2 = *(s32 *)temp_a3;
        var_t9 = temp_v0_2 & 4;
        if (temp_v0_2 & 1) {
            *(u8 *)(var_a2 + 0x8) = 0;
            *(s16 *)(var_a2 + 0xE) = *(s16 *)(temp_a3 + 0x14);
            *(s16 *)(var_a2 + 0x10) = *(s16 *)(temp_a3 + 0x16);
            *(s16 *)(var_a2 + 0x12) = *(s16 *)(temp_a3 + 0x18);
            var_t9 = *(s32 *)temp_a3 & 4;
        }
        if (var_t9 != 0) {
            var_a2[0x9] = 0;
            *(s16 *)(var_a2 + 0x14) = *(s16 *)(temp_a3 + 0x22);
            *(s16 *)(var_a2 + 0x16) = *(s16 *)(temp_a3 + 0x24);
            *(s16 *)(var_a2 + 0x18) = *(s16 *)(temp_a3 + 0x26);
        }
    }
    var_v1 = *(s32 *)(var_a2 + 0x4);
    if (var_v1 & 0x400) {
        temp_v0_3 = func_8005FAE8(sp1C, (s32 *)temp_a3, (s32)var_a2);
        var_v1 = *(s32 *)(var_a2 + 0x4);
        *(s8 *)(var_a2 + 0x22) = (s8)temp_v0_3;
    }
    *(s32 *)(var_a2 + 0x4) = var_v1 | 0x8000;
    *(s16 *)((u8 *)arg0 + 0x1A) = (s16)(*(s16 *)((u8 *)arg0 + 0x1A) + 1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_8005F99C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_8005FAE8(void *arg0, s32 *arg1, s32 arg2) {
    u8 *var_a2;
    u8 *var_a2_2;
    void *var_v1_3;
    TextureHeader *temp_v0;
    s32 var_a3;
    s32 var_v1;
    s32 var_v1_2;
    s32 temp_t4;
    s32 temp_t8;
    s16 temp_a0;
    u8 *var_v0;
    s32 i;

    if (pointstreams == NULL) {
        return 0xFF;
    }
    var_a2 = pointstreams;
    var_a3 = 0xFF;
    for (var_v1 = 0; var_v1 < maxpointstreams; var_v1++, var_a2 += 0xC0) {
        if (arg2 == *(s32 *)(var_a2 + 0xBC) && *(u8 *)(var_a2 + 0xA4) == 1) {
            *(u8 *)(var_a2 + 0xA4) = 2;
            return var_v1;
        }
    }
    var_a2_2 = pointstreams;
    for (var_v1_2 = 0; var_v1_2 < maxpointstreams; var_v1_2++, var_a2_2 += 0xC0) {
        if (*(u8 *)(var_a2_2 + 0xA4) == 0) {
            var_a3 = var_v1_2;
            break;
        }
    }
    if (var_a3 != 0xFF) {
        *(u8 *)(var_a2_2 + 0xA4) = 2;
        var_v0 = var_a2_2 + 0x44;
        temp_t4 = ((u8 *)arg0)[5] >> 4;
        *(s32 *)(var_a2_2 + 0x40) = temp_t4;
        var_v1_3 = ((void **)D_800A5F78_A6B78)[((u8 *)arg0)[5] >> 4];
        for (i = 0; i < temp_t4; i++) {
            *(f32 *)(var_v0 + 0x0) = *(f32 *)((u8 *)var_v1_3 + 0x0);
            *(f32 *)(var_v0 + 0x8) = 0.0f;
            *(f32 *)(var_v0 + 0x4) = *(f32 *)((u8 *)var_v1_3 + 0x4);
            var_v1_3 = (u8 *)var_v1_3 + 8;
            var_v0 += 0xC;
        }
        *(s32 *)(var_a2_2 + 0xA8) = *(s32 *)arg0;
        *(s32 *)(var_a2_2 + 0xAC) = *arg1;
        temp_a0 = *(s16 *)((u8 *)arg0 + 6);
        if (temp_a0 == -1) {
            *(void **)(var_a2_2 + 0xB8) = NULL;
            *(s16 *)(var_a2_2 + 0xB4) = 0;
            *(f32 *)(var_a2_2 + 0xB0) = 0.0f;
        } else {
            temp_v0 = texLoadTexture((s32)temp_a0);
            *(TextureHeader **)(var_a2_2 + 0xB8) = temp_v0;
            *(s16 *)(var_a2_2 + 0xB4) = *(s16 *)((u8 *)arg0 + 8);
            temp_t8 = (s32)temp_v0->numOfTextures >> 8;
            if (*arg1 & 0x800) {
                *(f32 *)(var_a2_2 + 0xB0) = (f32)mathRnd(0, temp_t8 - 1);
            } else if ((*(s32 *)(var_a2_2 + 0xA8) & 1) == 2) {
                *(f32 *)(var_a2_2 + 0xB0) = (f32)temp_t8 - 0.01f;
            } else {
                *(f32 *)(var_a2_2 + 0xB0) = 0.0f;
            }
        }
        *(s32 *)(var_a2_2 + 0xBC) = arg2;
    }
    return var_a3;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_8005FAE8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_8005FD34(void *arg0, s32 *arg1) {
    u8 *var_v1;
    TextureHeader *temp_v0;
    s32 var_t0;
    s32 var_v0;
    s32 var_v0_2;
    s16 temp_a0;
    s32 temp_t5;

    if (lines == NULL) {
        return 0xFF;
    }
    var_v1 = lines;
    var_t0 = 0xFF;
    for (var_v0_2 = 0; var_v0_2 < maxlines; var_v0_2++, var_v1 += 0x148) {
        if (*(u8 *)(var_v1 + 0x124) == 0) {
            *(u8 *)(var_v1 + 0x124) = 2;
            *(s32 **)(var_v1 + 0x12C) = arg1;
            *(s32 *)(var_v1 + 0x130) = 0;
            var_t0 = var_v0_2;
            break;
        }
    }
    var_v0 = var_t0;
    if (var_t0 != 0xFF) {
        *(s32 *)(var_v1 + 0x138) = *(s32 *)arg0;
        *(s32 *)(var_v1 + 0x13C) = *arg1;
        temp_a0 = *(s16 *)((u8 *)arg0 + 6);
        if (temp_a0 == -1) {
            *(void **)(var_v1 + 0x128) = NULL;
            *(s16 *)(var_v1 + 0x144) = 0;
            *(f32 *)(var_v1 + 0x140) = 0.0f;
        } else {
            temp_v0 = texLoadTexture((s32)temp_a0);
            *(TextureHeader **)(var_v1 + 0x128) = temp_v0;
            *(s16 *)(var_v1 + 0x144) = *(s16 *)((u8 *)arg0 + 8);
            temp_t5 = (s32)temp_v0->numOfTextures >> 8;
            if (*arg1 & 0x800) {
                *(f32 *)(var_v1 + 0x140) = (f32)mathRnd(0, temp_t5 - 1);
            } else if ((*(s32 *)(var_v1 + 0x138) & 1) == 2) {
                *(f32 *)(var_v1 + 0x140) = (f32)temp_t5 - 0.01f;
            } else {
                *(f32 *)(var_v1 + 0x140) = 0.0f;
            }
        }
        var_v0 = var_t0;
    }
    return var_v0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_8005FD34.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8005FED8(u8 *arg0, s32 arg1) {
    u8 *ent;
    s32 flags;
    s32 idx;

    ent = *(u8 **)(arg0 + 0x70) + arg1 * 0x24;
    *(u32 *)(ent + 0x4) &= ~0x8000;
    *(s16 *)(arg0 + 0x1A) = (s16)(*(s16 *)(arg0 + 0x1A) - 1);
    flags = *(s32 *)(ent + 0x4);
    if (flags & 0x4000) {
        idx = *(u8 *)(ent + 0x22) * 0x148;
        *(u8 *)(ent + 0x22) = 0xFF;
        *(u8 *)((u8 *)lines + idx + 0x124) = 1;
        return;
    }
    if (flags & 0x400) {
        idx = *(u8 *)(ent + 0x22) * 0xC0;
        *(u8 *)(ent + 0x22) = 0xFF;
        *(u8 *)((u8 *)pointstreams + idx + 0xA4) = 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_8005FED8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void partObjFreeTriggers(u8 *arg0) {
    u8 *def;
    s32 count;
    s32 i;

    def = *(u8 **)(arg0 + 0x40);
    if (*(s16 *)(def + 0x1C) == 0x27) {
        count = *(u8 *)(*(u8 **)(*(u8 **)(arg0 + 0x68) + 0x20) + 0x30);
    } else {
        count = *(s8 *)(def + 0x22);
    }
    for (i = 0; i < count; i++) {
        if (*(s32 *)(*(u8 **)(arg0 + 0x70) + i * 0x24 + 0x4) & 0x8000) {
            func_8005FED8(arg0, i);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/partObjFreeTriggers.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void partAdjustScaling(f32 arg0) {
    D_800A5DDC_A69DC = arg0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/partAdjustScaling.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void partUpdateTriggers(u8 *arg0, s32 arg1) {
    u32 mask;
    s32 count;
    s32 i;
    s32 off;
    u8 *ent;
    s32 flags;

    mask = *(u32 *)(arg0 + 0x84);
    if (*(s16 *)(arg0 + 0x48) == 0x27) {
        count = *(u8 *)(*(u8 **)(*(u8 **)(arg0 + 0x68) + 0x20) + 0x30);
    } else {
        count = *(s8 *)(*(u8 **)(arg0 + 0x40) + 0x22);
    }
    off = 0;
    for (i = 0; i < count; i++) {
        ent = *(u8 **)(arg0 + 0x70) + off;
        if (mask & 1) {
            flags = *(s32 *)(ent + 0x4);
            if (!(flags & 0x8000)) {
                func_8005F99C(arg0, i);
                ent = *(u8 **)(arg0 + 0x70) + off;
                flags = *(s32 *)(ent + 0x4);
            }
            if ((flags & 0x4000) || (flags & 0x400)) {
                *(s16 *)(ent + 0xC) = (s16)(*(s16 *)(ent + 0xC) + arg1);
                func_8006020C(arg0, ent);
            } else {
                *(s16 *)(ent + 0xC) = (s16)(*(s16 *)(ent + 0xC) + arg1);
                if (*(s16 *)(ent + 0xC) >= *(s16 *)(*(u8 **)ent + 0x40)) {
                    func_8006020C(arg0, ent);
                }
            }
        } else if (*(s32 *)(ent + 0x4) & 0x8000) {
            func_8005FED8(arg0, i);
        }
        off += 0x24;
        mask >>= 1;
    }
    D_800A5DDC_A69DC = 0.0f;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/partUpdateTriggers.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8006020C(u8 *arg0, u8 *arg1) {
    s32 flags;
    s16 life;
    s16 lifeMax;
    s16 rem;
    s32 s1;
    u8 *def;
    u8 *newp;

    flags = *(s32 *)(arg1 + 0x4);
    def = *(u8 **)arg1;
    if (flags & 0x4000) {
        life = *(s16 *)(arg1 + 0xC);
        lifeMax = *(s16 *)(def + 0x40);
        if (life >= lifeMax) {
            *(s16 *)(arg1 + 0xC) = (s16)(life - lifeMax);
            func_8006211C(arg0, arg1);
        }
    } else if (flags & 0x400) {
        life = *(s16 *)(arg1 + 0xC);
        lifeMax = *(s16 *)(def + 0x40);
        if (life >= lifeMax) {
            *(s16 *)(arg1 + 0xC) = (s16)(life - lifeMax);
            func_800637E0(arg0, arg1);
        }
    } else {
        life = *(s16 *)(arg1 + 0xC);
        lifeMax = *(s16 *)(def + 0x40);
        if (life >= lifeMax) {
            rem = life - lifeMax;
            do {
                *(s16 *)(arg1 + 0xC) = rem;
                for (s1 = 0; s1 < *(s16 *)(def + 0x42); s1++) {
                    newp = func_80060ED4(arg0, arg1, -1);
                    if (newp != NULL) {
                        if (*(s16 *)(arg1 + 0xC) != 0) {
                            *(f32 *)(newp + 0x1C) -= *(f32 *)D_801008F4_B1764;
                            *(f32 *)(newp + 0x20) -= D_801008F8_B1768;
                            *(f32 *)(newp + 0x24) -= D_801008FC_B176C;
                            func_80061CAC(newp, *(s16 *)(arg1 + 0xC));
                            *(f32 *)(newp + 0x1C) += *(f32 *)D_801008F4_B1764;
                            *(f32 *)(newp + 0x20) += D_801008F8_B1768;
                            *(f32 *)(newp + 0x24) += D_801008FC_B176C;
                        }
                        *(u32 *)(newp + 0x50) |= 0x80000;
                    }
                }
                life = *(s16 *)(arg1 + 0xC);
                lifeMax = *(s16 *)(def + 0x40);
                rem = life - lifeMax;
            } while (life >= lifeMax);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_8006020C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80060400(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3) {
    f32 vec[3];
    s16 rot[2];
    f32 negZ;
    f32 mag;
    f32 scl;
    s32 mode;
    s32 rnd;
    s32 idx;
    u8 *owner;
    u8 *tex;
    u8 *mtx;

    if (*(u32 *)arg3 & 0x70) {
        *(f32 *)(arg0 + 0x1C) = *(f32 *)(arg3 + 0x30);
        *(f32 *)(arg0 + 0x20) = *(f32 *)(arg3 + 0x34);
        *(f32 *)(arg0 + 0x24) = *(f32 *)(arg3 + 0x38);
    } else {
        *(f32 *)(arg0 + 0x1C) = 0.0f;
        *(f32 *)(arg0 + 0x20) = 0.0f;
        *(f32 *)(arg0 + 0x24) = 0.0f;
    }
    mode = *(s32 *)(arg3 + 0x5C) & 0x700;
    if (mode != 0) {
        if (mode & 0x100) {
            rnd = mathRnd(-*(s32 *)(arg3 + 0x74), *(s32 *)(arg3 + 0x74));
            *(f32 *)(arg0 + 0x1C) += (f32)rnd * 0.000015258789f;
        }
        if (mode & 0x200) {
            rnd = mathRnd(-*(s32 *)(arg3 + 0x78), *(s32 *)(arg3 + 0x78));
            *(f32 *)(arg0 + 0x20) += (f32)rnd * 0.000015258789f;
        }
        if (mode & 0x400) {
            rnd = mathRnd(-*(s32 *)(arg3 + 0x7C), *(s32 *)(arg3 + 0x7C));
            *(f32 *)(arg0 + 0x24) += (f32)rnd * 0.000015258789f;
        }
    }
    switch (*(u32 *)arg3 & 0x70) {
    case 0x10:
        *(f32 *)(arg0 + 0x1C) += *(f32 *)(arg1 + 0x1C);
        *(f32 *)(arg0 + 0x20) += *(f32 *)(arg1 + 0x20);
        *(f32 *)(arg0 + 0x24) += *(f32 *)(arg1 + 0x24);
        break;
    case 0x40:
        *(f32 *)(arg0 + 0x1C) *= *(f32 *)(arg1 + 0x1C);
        *(f32 *)(arg0 + 0x20) *= *(f32 *)(arg1 + 0x20);
        *(f32 *)(arg0 + 0x24) *= *(f32 *)(arg1 + 0x24);
        break;
    }
    *(f32 *)D_801008F4_B1764 = *(f32 *)(arg0 + 0x1C);
    D_801008F8_B1768 = *(f32 *)(arg0 + 0x20);
    D_801008FC_B176C = *(f32 *)(arg0 + 0x24);
    if (*(u32 *)arg3 & 4) {
        vec[0] = 0.0f;
        vec[1] = 0.0f;
        vec[2] = -*(f32 *)(arg3 + 0x3C);
        if (*(s32 *)(arg3 + 0x5C) & 0x10) {
            rnd = mathRnd(-*(s32 *)(arg3 + 0x70), *(s32 *)(arg3 + 0x70));
            vec[2] += (f32)rnd * 0.000015258789f;
        }
        negZ = -vec[2];
        rot[0] = *(s16 *)(arg2 + 0x14);
        rot[1] = *(s16 *)(arg2 + 0x16);
        if (*(s32 *)(arg3 + 0x5C) & 0x20) {
            rot[0] = (s16)(rot[0] + mathRnd(-*(s16 *)(arg3 + 0x6A), *(s16 *)(arg3 + 0x6A)));
        }
        if (*(s32 *)(arg3 + 0x5C) & 0x40) {
            rot[1] = (s16)(rot[1] + mathRnd(-*(s16 *)(arg3 + 0x6C), *(s16 *)(arg3 + 0x6C)));
        }
        mathOneFloatPY(rot, vec);
        owner = NULL;
        if (*(s8 *)(*(u8 **)(arg1 + 0x40) + 0x1E) != 0) {
            owner = *(u8 **)(*(u8 **)(arg1 + 0x6C) + *(s8 *)(arg1 + 0x3A) * 4);
        }
        idx = *(s8 *)(arg2 + 0x23);
        if (idx != -1 && owner != NULL && (tex = *(u8 **)owner) != NULL && *(s8 *)(tex + 0x4E) != 0) {
            if (*(s8 *)(owner + 0xA) != 0) {
                vec[0] = 0.0f;
                vec[1] = 0.0f;
                vec[2] = 0.0f;
            } else {
                mtx = (u8 *)((*(u16 *)(*(u8 **)(tex + 0x30) + idx * 4 + 2) << 6) +
                             *(u32 *)(owner + *(s8 *)(owner + 0xB) * 4 + 0x10));
                mathMtxFastXFMF(mtx, vec, vec, tex);
                mag = sqrtf((vec[2] * vec[2]) + ((vec[0] * vec[0]) + (vec[1] * vec[1])));
                scl = negZ;
                if (mag != 0.0f) {
                    scl = negZ / mag;
                }
                vec[0] *= scl;
                vec[1] *= scl;
                vec[2] *= scl;
            }
        } else {
            if (*(s16 **)(arg0 + 0x48) != NULL) {
                pointListRPY(1, *(s16 **)(arg0 + 0x48), (s32 *)vec, vec);
            }
        }
        *(f32 *)(arg0 + 0x1C) += vec[0];
        *(f32 *)(arg0 + 0x20) += vec[1];
        *(f32 *)(arg0 + 0x24) += vec[2];
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_80060400.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_800608EC(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3) {
    f32 vec[3];
    s16 rot[2];
    u8 *owner;
    u8 *tbl;
    s32 idx;
    s32 rnd;
    s32 flags;

    idx = *(s8 *)(arg2 + 0x23);
    if (idx == -1) {
        *(f32 *)(arg0 + 0x30) = (f32)*(s16 *)(arg2 + 0x1A);
        *(f32 *)(arg0 + 0x34) = (f32)*(s16 *)(arg2 + 0x1C);
        *(f32 *)(arg0 + 0x38) = (f32)*(s16 *)(arg2 + 0x1E);
    } else {
        owner = NULL;
        if (*(s8 *)(*(u8 **)(arg1 + 0x40) + 0x1E) == 0) {
            owner = *(u8 **)(*(u8 **)(arg1 + 0x6C) + *(s8 *)(arg1 + 0x3A) * 4);
        }
        if (owner != NULL && (tbl = *(u8 **)(owner + 0x68)) != NULL) {
            *(f32 *)(arg0 + 0x30) = *(f32 *)(tbl + idx * 0xC);
            *(f32 *)(arg0 + 0x34) = *(f32 *)(tbl + idx * 0xC + 4);
            *(f32 *)(arg0 + 0x38) = *(f32 *)(tbl + idx * 0xC + 8);
            if (*(s8 *)(*(u8 **)owner + 0x4E) == 0) {
                *(f32 *)(arg0 + 0x30) = *(f32 *)(arg0 + 0x30) * *(f32 *)(arg1 + 0x8);
                *(f32 *)(arg0 + 0x34) = *(f32 *)(arg0 + 0x34) * *(f32 *)(arg1 + 0x8);
                *(f32 *)(arg0 + 0x38) = *(f32 *)(arg0 + 0x38) * *(f32 *)(arg1 + 0x8);
                pointListRPY(1, (s16 *)arg1, (s32 *)(arg0 + 0x30), (f32 *)(arg0 + 0x30));
            } else {
                *(f32 *)(arg0 + 0x30) -= *(f32 *)(arg1 + 0xC);
                *(f32 *)(arg0 + 0x34) -= *(f32 *)(arg1 + 0x10);
                *(f32 *)(arg0 + 0x38) -= *(f32 *)(arg1 + 0x14);
            }
        } else {
            *(f32 *)(arg0 + 0x30) = 0.0f;
            *(f32 *)(arg0 + 0x34) = 0.0f;
            *(f32 *)(arg0 + 0x38) = 0.0f;
        }
    }
    *(f32 *)(arg0 + 0x3C) = *(f32 *)(arg3 + 0x58);
    if (*(u32 *)(arg3 + 0x5C) & 0x80000) {
        rnd = mathRnd(-*(s32 *)(arg3 + 0x94), *(s32 *)(arg3 + 0x94));
        *(f32 *)(arg0 + 0x3C) += (f32)rnd * 0.000015258789f;
    }
    if (*(u32 *)arg3 & 1) {
        vec[0] = 0.0f;
        vec[1] = 0.0f;
        vec[2] = -*(f32 *)(arg3 + 0x10);
        flags = *(s32 *)(arg3 + 0x5C);
        if (flags & 1) {
            rnd = mathRnd(-*(s32 *)(arg3 + 0x60), *(s32 *)(arg3 + 0x60));
            vec[2] += (f32)rnd * 0.000015258789f;
        }
        if (flags & 6) {
            rot[0] = *(s16 *)(arg2 + 0xE);
            if (flags & 2) {
                rot[0] = (s16)(rot[0] + mathRnd(-*(s16 *)(arg3 + 0x64), *(s16 *)(arg3 + 0x64)));
            }
            rot[1] = *(s16 *)(arg2 + 0x10);
            if (flags & 4) {
                rot[1] = (s16)(rot[1] + mathRnd(-*(s16 *)(arg3 + 0x66), *(s16 *)(arg3 + 0x66)));
            }
            mathOneFloatPY(rot, vec);
        } else {
            pointListRPY(1, (s16 *)(arg2 + 0xE), (s32 *)vec, vec);
        }
        *(f32 *)(arg0 + 0x30) += vec[0];
        *(f32 *)(arg0 + 0x34) += vec[1];
        *(f32 *)(arg0 + 0x38) += vec[2];
    }
    if (*(u8 *)(arg0 + 0x2E) != 4 && *(s8 *)(arg2 + 0x23) == -1) {
        pointListRPY(1, (s16 *)arg1, (s32 *)(arg0 + 0x30), (f32 *)(arg0 + 0x30));
    }
    *(f32 *)(arg0 + 0xC) = *(f32 *)(arg0 + 0x30);
    *(f32 *)(arg0 + 0x10) = *(f32 *)(arg0 + 0x34);
    *(f32 *)(arg0 + 0x14) = *(f32 *)(arg0 + 0x38);
    if (*(u8 *)(arg0 + 0x2E) == 4) {
        pointListRPY(1, (s16 *)arg1, (s32 *)(arg0 + 0xC), (f32 *)(arg0 + 0xC));
    }
    *(f32 *)(arg0 + 0xC) += *(f32 *)(arg1 + 0xC);
    *(f32 *)(arg0 + 0x10) += *(f32 *)(arg1 + 0x10);
    *(f32 *)(arg0 + 0x14) += *(f32 *)(arg1 + 0x14);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_800608EC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void partModelObjEmitModelPart(u8 *arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4) {
    u8 *tab;
    u8 *def;
    u8 *ent;
    u8 *p;
    s32 idx;
    s16 flag;

    if (arg4 < *(u8 *)(arg0 + 0x91)) {
        idx = arg4 * 6;
        tab = *(u8 **)(arg0 + 0x40) + 0xB0;
        def = (u8 *)PartTrigTab[*(s16 *)(tab + idx)];
        ent = *(u8 **)(arg0 + 0x80) + arg4 * 0x24;
        *(u8 **)(ent + 0x0) = def;
        *(s32 *)(ent + 0x4) = 0;
        *(s16 *)(ent + 0xC) = 0;
        *(s16 *)(ent + 0x1A) = 0;
        *(s16 *)(ent + 0x1C) = 0;
        *(s16 *)(ent + 0x1E) = 0;
        *(s16 *)(ent + 0x20) = 0;
        *(s16 *)(ent + 0xA) = *(s16 *)(tab + idx + 2);
        *(s16 *)(ent + 0xE) = *(s16 *)(def + 0x14);
        *(s16 *)(ent + 0x10) = *(s16 *)(def + 0x16);
        *(s16 *)(ent + 0x12) = *(s16 *)(def + 0x18);
        *(s16 *)(ent + 0x14) = *(s16 *)(def + 0x22);
        *(s16 *)(ent + 0x16) = *(s16 *)(def + 0x24);
        *(s8 *)(ent + 0x23) = -1;
        *(s16 *)(ent + 0x18) = *(s16 *)(def + 0x26);
        flag = *(s16 *)(tab + idx + 4);
        p = func_80060ED4(arg0, ent, flag);
        if (p != NULL && (arg1 != 0.0f || arg2 != 0.0f || arg3 != 0.0f)) {
            *(f32 *)(p + 0x1C) = arg1;
            *(f32 *)(p + 0x20) = arg2;
            *(f32 *)(p + 0x24) = arg3;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/partModelObjEmitModelPart.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_80060ED4(u8 *arg0, u8 *arg1, s16 arg2) {
    u8 *def;
    u8 *sdef;
    u8 *p;
    u8 *tp;
    u8 *sprite;
    TextureHeader *tex6;
    s32 ptype;
    s32 flags;
    s32 mode;
    s32 rnd;
    s32 t;
    s32 n;
    f32 f16;
    f32 f16b;
    f32 tmp;
    s16 v;

    def = (u8 *)PartTab[*(s16 *)(arg1 + 0xA)];
    ptype = (s32)((u32)*(s32 *)(def + 0x4) >> 0x1C);
    if (ptype == 5) {
        return NULL;
    }
    if (arg2 == -1) {
        arg2 = *(s16 *)(def + 0x6);
    }
    sdef = *(u8 **)arg1;
    p = func_80061948((s16)ptype, arg2);
    if (p == NULL) {
        return NULL;
    }
    *(u8 *)(p + 0x2E) = (u8)(*(u8 *)(def + 0x4) & 0xF);
    *(u8 *)(p + 0x2F) = 0;
    *(u8 **)(p + 0x48) = arg0;
    flags = *(s32 *)def;
    *(s32 *)(p + 0x50) = flags;
    *(u8 **)(p + 0x44) = *(u8 **)(def + 0x20);
    *(u8 *)(p + 0x6E) = *(u8 *)(def + 0x1F);
    if ((flags & 0x800) && *(f32 **)(arg0 + 0x54) != NULL) {
        *(s8 *)(p + 0x6F) = (s8)(**(f32 **)(arg0 + 0x54) * 255.0f);
    } else {
        *(u8 *)(p + 0x6F) = 0xFF;
    }
    f16 = *(f32 *)(sdef + 0x50);
    if (*(s32 *)(sdef + 0x5C) & 0x20000) {
        rnd = mathRnd(-*(s32 *)(sdef + 0x8C), *(s32 *)(sdef + 0x8C));
        f16 += (f32)rnd * 0.000015258789f;
    }
    *(f32 *)(p + 0x8) = *(f32 *)(def + 0x14) * f16;
    f16b = *(f32 *)(sdef + 0x54);
    if (*(s32 *)(sdef + 0x5C) & 0x40000) {
        rnd = mathRnd(-*(s32 *)(sdef + 0x90), *(s32 *)(sdef + 0x90));
        f16b += (f32)rnd * 0.000015258789f;
    }
    if (*(u32 *)sdef & 0x1000) {
        tmp = *(f32 *)(arg0 + 0x1C) * *(f32 *)(arg0 + 0x1C);
        tmp += *(f32 *)(arg0 + 0x20) * *(f32 *)(arg0 + 0x20);
        tmp += *(f32 *)(arg0 + 0x24) * *(f32 *)(arg0 + 0x24);
        *(f32 *)(p + 0x18) = sqrtf(tmp) * f16b * 0.1f;
    } else {
        *(f32 *)(p + 0x18) = *(f32 *)(def + 0x14) * f16b;
    }
    if (D_800A5DDC_A69DC != 0.0f) {
        *(f32 *)(p + 0x8) = *(f32 *)(p + 0x8) * D_800A5DDC_A69DC;
        *(f32 *)(p + 0x18) = *(f32 *)(p + 0x18) * D_800A5DDC_A69DC;
    }
    *(s16 *)(p + 0x5C) = (s16)(mathRnd(-*(s16 *)(def + 0xC), *(s16 *)(def + 0xC)) + *(s16 *)(def + 0xA));
    *(u8 *)(p + 0x70) = *(u8 *)(def + 0x18);
    if (*(u32 *)(p + 0x50) & 0x400) {
        tp = *(u8 **)(p + 0x44);
        *(u8 *)(p + 0x71) = (u8)((*(u32 *)tp & 0xFF000000) >> 0x18);
        *(u8 *)(p + 0x72) = (u8)((*(u32 *)tp & 0xFF0000) >> 0x10);
        *(u8 *)(p + 0x73) = (u8)((*(u32 *)tp & 0xFF00) >> 8);
    } else {
        *(u8 *)(p + 0x71) = *(u8 *)(def + 0x19);
        *(u8 *)(p + 0x72) = *(u8 *)(def + 0x1A);
        *(u8 *)(p + 0x73) = *(u8 *)(def + 0x1B);
    }
    *(u8 *)(p + 0x74) = *(u8 *)(def + 0x1C);
    *(u8 *)(p + 0x75) = *(u8 *)(def + 0x1D);
    *(u8 *)(p + 0x76) = *(u8 *)(def + 0x1E);
    mode = *(s32 *)(sdef + 0x5C) & 0xF00000;
    if (mode & 0x100000) {
        rnd = mathRnd(-*(u8 *)(sdef + 0x98), *(u8 *)(sdef + 0x98));
        *(u8 *)(p + 0x71) = (u8)(*(u8 *)(p + 0x71) + rnd);
    }
    if (mode & 0x200000) {
        rnd = mathRnd(-*(u8 *)(sdef + 0x99), *(u8 *)(sdef + 0x99));
        *(u8 *)(p + 0x72) = (u8)(*(u8 *)(p + 0x72) + rnd);
    }
    if (mode & 0x400000) {
        rnd = mathRnd(-*(u8 *)(sdef + 0x9A), *(u8 *)(sdef + 0x9A));
        *(u8 *)(p + 0x73) = (u8)(*(u8 *)(p + 0x73) + rnd);
    }
    *(s16 *)(p + 0x68) = *(s16 *)(def + 0x10);
    *(s16 *)(p + 0x6A) = 0;
    *(s16 *)(p + 0x6C) = *(s16 *)(def + 0x12);
    v = *(s16 *)(p + 0x5C);
    *(s16 *)(p + 0x64) = (s16)(*(u8 *)(def + 0xE) << 8);
    if (*(s16 *)(p + 0x68) < v) {
        *(s16 *)(p + 0x66) = (s16)((((s32)(*(u8 *)(def + 0xF) - *(u8 *)(def + 0xE))) << 8) / (s32)(v - *(s16 *)(p + 0x68)));
    } else {
        *(s16 *)(p + 0x66) = 0;
    }
    *(s8 *)(p + 0x77) = (s8)*(s16 *)(def + 0x8);
    ptype = *(s16 *)(p + 0x2C);
    if (ptype == 2) {
        sprite = (u8 *)texLoadSprite(arg2, 0);
        *(u8 **)(p + 0x4C) = sprite;
        if (sprite != NULL) {
            if ((*(TextureHeader **)(*(u8 **)(sprite + 0x10)))->flags & 4) {
                if (flags & 0x1000) {
                    *(s16 *)(p + 0x6) = (s16)(*(s16 *)(p + 0x6) | 8);
                } else {
                    *(s16 *)(p + 0x6) = (s16)(*(s16 *)(p + 0x6) | 4);
                }
            }
            if (*(u32 *)sdef & 0x800) {
                *(f32 *)(p + 0x28) = (f32)mathRnd(0, ((TextureHeader *)sprite)->width - 1);
            } else if ((flags & 1) == 2) {
                *(f32 *)(p + 0x28) = (f32)((TextureHeader *)sprite)->width - 0.01f;
            } else {
                *(f32 *)(p + 0x28) = 0.0f;
            }
        }
    } else if (ptype == 0 || ptype == 1) {
        if (arg2 < 0) {
            *(u8 **)(p + 0x4C) = NULL;
        } else {
            tex6 = texLoadTexture(arg2);
            if (tex6->flags & 4) {
                if (flags & 0x1000) {
                    *(s16 *)(p + 0x6) = (s16)(*(s16 *)(p + 0x6) | 8);
                } else {
                    *(s16 *)(p + 0x6) = (s16)(*(s16 *)(p + 0x6) | 4);
                }
            }
            *(TextureHeader **)(p + 0x4C) = tex6;
            *(f32 *)(p + 0x28) = 0.0f;
        }
    } else if (ptype == 3) {
        *(u8 **)(p + 0x4C) = (u8 *)modLoadModel(arg2, 0);
    }
    func_800608EC(p, arg0, arg1, sdef);
    if (*(u32 *)sdef & 0x80) {
        *(s16 *)(p + 0x0) = *(s16 *)(sdef + 0x44);
        *(s16 *)(p + 0x2) = *(s16 *)(sdef + 0x46);
        *(s16 *)(p + 0x4) = *(s16 *)(sdef + 0x48);
    } else {
        *(s16 *)(p + 0x0) = (s16)(*(s16 *)(arg0 + 0x0) + *(s16 *)(sdef + 0x44));
        *(s16 *)(p + 0x2) = (s16)(*(s16 *)(arg0 + 0x2) + *(s16 *)(sdef + 0x46));
        *(s16 *)(p + 0x4) = (s16)(*(s16 *)(arg0 + 0x4) + *(s16 *)(sdef + 0x48));
    }
    mode = *(s32 *)(sdef + 0x5C) & 0x3800;
    if (mode & 0x800) {
        rnd = mathRnd(-*(s16 *)(sdef + 0x80), *(s16 *)(sdef + 0x80));
        *(s16 *)(p + 0x0) = (s16)(*(s16 *)(p + 0x0) + rnd);
    }
    if (mode & 0x1000) {
        rnd = mathRnd(-*(s16 *)(sdef + 0x82), *(s16 *)(sdef + 0x82));
        *(s16 *)(p + 0x2) = (s16)(*(s16 *)(p + 0x2) + rnd);
    }
    if (mode & 0x2000) {
        rnd = mathRnd(-*(s16 *)(sdef + 0x84), *(s16 *)(sdef + 0x84));
        *(s16 *)(p + 0x4) = (s16)(*(s16 *)(p + 0x4) + rnd);
    }
    *(s16 *)(p + 0x5E) = *(s16 *)(sdef + 0x4A);
    *(s16 *)(p + 0x60) = *(s16 *)(sdef + 0x4C);
    *(s16 *)(p + 0x62) = *(s16 *)(sdef + 0x4E);
    mode = *(s32 *)(sdef + 0x5C) & 0x1C000;
    if (mode & 0x4000) {
        rnd = mathRnd(-*(s16 *)(sdef + 0x86), *(s16 *)(sdef + 0x86));
        *(s16 *)(p + 0x5E) = (s16)(*(s16 *)(p + 0x5E) + rnd);
    }
    if (mode & 0x8000) {
        rnd = mathRnd(-*(s16 *)(sdef + 0x88), *(s16 *)(sdef + 0x88));
        *(s16 *)(p + 0x60) = (s16)(*(s16 *)(p + 0x60) + rnd);
    }
    if (mode & 0x10000) {
        rnd = mathRnd(-*(s16 *)(sdef + 0x8A), *(s16 *)(sdef + 0x8A));
        *(s16 *)(p + 0x62) = (s16)(*(s16 *)(p + 0x62) + rnd);
    }
    func_80060400(p, arg0, arg1, sdef);
    flags = *(s32 *)(p + 0x50);
    *(f32 *)(p + 0x40) = (f32)D_800A5DB8_A69B8[(flags >> 4) & 7];
    if (flags & 0x80) {
        *(f32 *)(p + 0x40) = -*(f32 *)(p + 0x40);
    }
    if (*(u8 *)(p + 0x2E) == 5) {
        tmp = *(f32 *)(p + 0x1C) * *(f32 *)(p + 0x1C);
        tmp += *(f32 *)(p + 0x20) * *(f32 *)(p + 0x20);
        tmp += *(f32 *)(p + 0x24) * *(f32 *)(p + 0x24);
        *(f32 *)(p + 0x3C) = sqrtf(tmp);
    }
    if (*(u32 *)def & 0x40000) {
        *(void **)(p + 0x58) = func_8005F918(*(u8 *)(def + 0x27), *(u8 *)(def + 0x26));
    } else {
        *(void **)(p + 0x58) = NULL;
    }
    if (*(u32 *)sdef & 2) {
        t = *(u8 *)(arg1 + 0x8) + 1;
        *(u8 *)(arg1 + 0x8) = (u8)t;
        n = t & 0xFF;
        if (n >= *(s16 *)(sdef + 0x1A)) {
            *(s16 *)(arg1 + 0xE) = (s16)(*(s16 *)(arg1 + 0xE) + *(s16 *)(sdef + 0x1C));
            *(s16 *)(arg1 + 0x10) = (s16)(*(s16 *)(arg1 + 0x10) + *(s16 *)(sdef + 0x1E));
            *(s16 *)(arg1 + 0x12) = (s16)(*(s16 *)(arg1 + 0x12) + *(s16 *)(sdef + 0x18));
            *(u8 *)(arg1 + 0x8) = (u8)(n - *(s16 *)(sdef + 0x1A));
        }
    }
    if (*(u32 *)sdef & 8) {
        t = *(u8 *)(arg1 + 0x9) + 1;
        *(u8 *)(arg1 + 0x9) = (u8)t;
        n = t & 0xFF;
        if (n >= *(s16 *)(sdef + 0x28)) {
            *(s16 *)(arg1 + 0x14) = (s16)(*(s16 *)(arg1 + 0x14) + *(s16 *)(sdef + 0x2A));
            *(s16 *)(arg1 + 0x16) = (s16)(*(s16 *)(arg1 + 0x16) + *(s16 *)(sdef + 0x2C));
            *(s16 *)(arg1 + 0x18) = (s16)(*(s16 *)(arg1 + 0x18) + *(s16 *)(sdef + 0x2E));
            *(u8 *)(arg1 + 0x9) = (u8)(n - *(s16 *)(sdef + 0x28));
        }
    }
    if (*(void **)(p + 0x4C) == NULL && *(s16 *)(p + 0x2C) != 4) {
        func_80061B50(p);
        return NULL;
    }
    *(s32 *)(p + 0x54) = 8;
    if (*(u32 *)sdef & 0x10000) {
        *(s32 *)(p + 0x50) |= 0x200000;
    }
    if (*(u8 *)(p + 0x2E) == 3) {
        *(u8 *)(arg0 + 0xA2) = 1;
    }
    return p;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_80060ED4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_80061948(s16 arg0, s32 arg1) {
    u8 *list;
    u32 *bits;
    u8 *ret;
    s32 w;
    s32 bit;
    s32 slot;
    u32 word;

    if (arg0 >= 5) {
        return NULL;
    }
    list = partlists[arg0];
    if (list == NULL) {
        return NULL;
    }
    if (*(s32 *)(list + 0x1C) >= *(s32 *)(list + 0x18)) {
        if (*(s32 *)(list + 0x28) == 0) {
            *(s32 *)(list + 0x28) = 1;
        }
        return NULL;
    }
    bits = *(u32 **)(list + 0x20);
    if (arg1 == -1) {
        w = 0;
        while (w <= *(s32 *)(list + 0x24) && bits[w] == 0) {
            w++;
        }
        if (w > *(s32 *)(list + 0x24)) {
            return NULL;
        }
        word = bits[w];
        for (bit = 0; !(word & (1u << bit)); bit++) {
        }
        bits[w] = word & ~(1u << bit);
        slot = (w << 5) + bit;
    } else {
        w = *(s32 *)(list + 0x24);
        while (w > 0 && bits[w] == 0) {
            w--;
        }
        word = bits[w];
        if (word == 0) {
            return NULL;
        }
        for (bit = 31; !(word & (1u << bit)); bit--) {
        }
        bits[w] = word & ~(1u << bit);
        slot = (w << 5) + bit;
    }
    if (slot >= *(s32 *)(list + 0x18)) {
        return NULL;
    }
    ret = *(u8 **)(list + 0x14) + slot * 0x78;
    *(s16 *)(ret + 0x2C) = arg0;
    *(s32 *)(list + 0x1C) += 1;
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_80061948.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80061B50(u8 *arg0) {
    u8 *list;
    u32 *bits;
    s32 off;
    s32 slot;
    s32 cnt;

    switch (*(s16 *)(arg0 + 0x2C)) {
    case 0x2:
        if (*(s32 *)(arg0 + 0x4C) != 0) {
            texFreeSprite(*(s32 *)(arg0 + 0x4C));
            *(s32 *)(arg0 + 0x4C) = 0;
        }
        break;
    case 0x3:
        if (*(s32 *)(arg0 + 0x4C) != 0) {
            modFreeModel(*(s32 *)(arg0 + 0x4C));
            *(s32 *)(arg0 + 0x4C) = 0;
        }
        break;
    case 0x0:
    case 0x1:
    case 0x4:
        break;
    default:
        return;
    }
    if (*(u8 **)(arg0 + 0x58) != NULL) {
        *(u8 *)(*(u8 **)(arg0 + 0x58) + 0x24) = 0;
    }
    list = partlists[*(s16 *)(arg0 + 0x2C)];
    cnt = *(s32 *)(list + 0x1C);
    if (cnt > 0) {
        if (*(s32 *)(arg0 + 0x4C) != 0) {
            texFreeTexture(*(s32 *)(arg0 + 0x4C));
        }
        off = (s32)((u8 *)arg0 - *(u8 **)(list + 0x14));
        slot = off / 0x78;
        *(s32 *)(list + 0x1C) = cnt - 1;
        *(s16 *)(arg0 + 0x2C) = 0x80;
        bits = *(u32 **)(list + 0x20);
        bits[slot >> 5] |= 1u << (slot & 0x1F);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_80061B50.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_80061CAC(u8 *arg0, s32 arg1) {
    f32 pos[3];
    f32 dir[3];
    s32 flags;
    s32 type;
    s32 i;
    u8 *cur;
    u8 *tex;
    s16 life;
    f32 mag2;
    f32 scl;

    flags = *(s32 *)(arg0 + 0x50);
    if (flags & 0x200000) {
        *(s32 *)(arg0 + 0x50) = flags & 0xFFDFFFFF;
        return 0;
    }
    D_80100900_B1770 = arg1;
    flags = *(s32 *)(arg0 + 0x50);
    if (flags & 0x80000) {
        *(s32 *)(arg0 + 0x50) = flags ^ 0x80000;
        if (*(u8 *)(arg0 + 0x2E) == 3) {
            D_80100900_B1770 = 0;
            func_80063990(arg0);
            D_80100900_B1770 = arg1;
        }
        return 0;
    }
    if (*(s16 *)(arg0 + 0x2C) == 5) {
        return 0;
    }
    *(s16 *)(arg0 + 0x5C) = (s16)(*(s16 *)(arg0 + 0x5C) - D_80100900_B1770);
    if (*(s16 *)(arg0 + 0x5C) <= 0) {
        func_80061B50(arg0);
        return 1;
    }
    type = *(s16 *)(arg0 + 0x2C);
    if (type == 2) {
        if (*(s32 *)(arg0 + 0x50) & 1) {
            texAnimateSprite(*(s32 *)(arg0 + 0x4C), arg0 + 0x50, *(u8 *)(arg0 + 0x77), arg0 + 0x28, D_80100900_B1770);
        }
    } else if (type == 1 || type == 0) {
        tex = *(u8 **)(arg0 + 0x4C);
        if (tex != NULL) {
            texAnimateTexSprite((s32)tex, arg0 + 0x50, *(u8 *)(arg0 + 0x77), arg0 + 0x28, D_80100900_B1770);
        }
    }
    flags = *(s32 *)(arg0 + 0x50);
    if (!(flags & 0x20000)) {
        if (flags & 0x10000) {
            pos[0] = *(f32 *)(arg0 + 0xC);
            pos[1] = *(f32 *)(arg0 + 0x10);
            pos[2] = *(f32 *)(arg0 + 0x14);
        }
        type = *(u8 *)(arg0 + 0x2E);
        if (type == 2) {
            func_80063AB4(arg0);
        } else if (type == 3) {
            func_80063990(arg0);
        } else if (type == 4) {
            func_80063890(arg0);
        } else if (type == 5) {
            func_80063CC8(arg0);
        } else {
            func_80063C14(arg0);
        }
        if (*(s32 *)(arg0 + 0x50) & 0x10000) {
            cur = *(u8 **)(D_80100908_B1778 + D_800A5DE0_A69E0 * 0x10);
            if (cur == NULL || *(u8 *)(arg0 + 0x2F) < *(u8 *)(cur + 0x2F) || *(s16 *)(cur + 0x5C) < *(s16 *)(arg0 + 0x5C)) {
                *(u8 **)(D_80100908_B1778 + 0x0) = arg0;
                D_800A5DE0_A69E0 = 0;
                *(f32 *)(D_80100908_B1778 + 0x4) = pos[0];
                *(f32 *)(D_80100908_B1778 + 0x8) = pos[1];
                *(f32 *)(D_80100908_B1778 + 0xC) = pos[2];
                for (i = 1; i < 5; i++) {
                    cur = *(u8 **)(D_80100908_B1778 + i * 0x10);
                    if (cur != NULL) {
                        if (*(u8 *)(*(u8 **)(D_80100908_B1778 + D_800A5DE0_A69E0 * 0x10) + 0x2F) < *(u8 *)(cur + 0x2F)) {
                            D_800A5DE0_A69E0 = (u8)i;
                        }
                    } else {
                        D_800A5DE0_A69E0 = (u8)i;
                        i = 5;
                    }
                }
            }
        }
        if (*(s32 *)(arg0 + 0x50) & 0x400) {
            if (*(s16 *)(arg0 + 0x6C) == 0) {
                s32 n = *(u8 *)(arg0 + 0x6E);
                s32 v;
                *(s16 *)(arg0 + 0x6A) = (s16)(*(s16 *)(arg0 + 0x6A) + D_80100900_B1770);
                v = *(s16 *)(arg0 + 0x6A);
                while (v >= n) {
                    v -= n;
                }
                *(s16 *)(arg0 + 0x6A) = (s16)v;
                {
                    u8 *pal = *(u8 **)(arg0 + 0x44) + v * 4;
                    *(u8 *)(arg0 + 0x71) = pal[0];
                    *(u8 *)(arg0 + 0x72) = pal[1];
                    *(u8 *)(arg0 + 0x73) = pal[2];
                }
            } else {
                *(s16 *)(arg0 + 0x6C) = (s16)(*(s16 *)(arg0 + 0x6C) - D_80100900_B1770);
                if (*(s16 *)(arg0 + 0x6C) < 0) {
                    *(s16 *)(arg0 + 0x6A) = (s16)(*(s16 *)(arg0 + 0x6A) - *(s16 *)(arg0 + 0x6C));
                }
            }
        }
        if (*(s16 *)(arg0 + 0x68) == 0) {
            *(s16 *)(arg0 + 0x64) = (s16)(*(s16 *)(arg0 + 0x64) + (D_80100900_B1770 * *(s16 *)(arg0 + 0x66)));
        } else {
            *(s16 *)(arg0 + 0x68) = (s16)(*(s16 *)(arg0 + 0x68) - D_80100900_B1770);
            if (*(s16 *)(arg0 + 0x68) < 0) {
                *(s16 *)(arg0 + 0x68) = 0;
                *(s16 *)(arg0 + 0x64) = (s16)(*(s16 *)(arg0 + 0x64) - (*(s16 *)(arg0 + 0x68) * *(s16 *)(arg0 + 0x66)));
            }
        }
        cur = *(u8 **)(arg0 + 0x58);
        if (cur != NULL) {
            *(s16 *)(cur + 0xC) = (s16)(*(s16 *)(cur + 0xC) + arg1);
            func_8006020C(arg0, cur);
        }
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_80061CAC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8006211C(u8 *arg0, u8 *arg1) {
    u8 *part;
    u8 *ln;
    u8 *pt;
    u8 *pal;
    s32 cnt;
    s32 ptype;
    f32 pos[3];
    f32 dir[3];
    f32 len;
    f32 scl;
    f32 mag2;
    f32 x;
    f32 y;
    f32 z;

    part = (u8 *)PartTab[*(s16 *)(arg1 + 0xA)];
    if (((u32)*(s32 *)(part + 0x4) >> 0x1C) != 5) {
        return;
    }
    if (*(u8 *)(arg1 + 0x22) == 0xFF) {
        return;
    }
    ln = (u8 *)lines + *(u8 *)(arg1 + 0x22) * 0x148;
    cnt = *(s32 *)ln;
    if (cnt == 9) {
        return;
    }
    pt = *(u8 **)(ln + 4 + cnt * 4);
    *(s32 *)ln = cnt + 1;
    *(s16 *)(pt + 0x14) = *(s16 *)(part + 0xA);
    if (*(u32 *)part & 0x400) {
        if (*(u8 **)(ln + 0x130) == NULL) {
            *(s16 *)(ln + 0x134) = *(u8 *)(part + 0x1F);
            *(u8 **)(ln + 0x130) = *(u8 **)(part + 0x20);
        }
        pal = *(u8 **)(ln + 0x130);
        *(u8 *)(pt + 0x18) = (u8)((*(u32 *)pal & 0xFF000000) >> 0x18);
        *(u8 *)(pt + 0x19) = (u8)((*(u32 *)pal & 0xFF0000) >> 0x10);
        *(u8 *)(pt + 0x1A) = (u8)((*(u32 *)pal & 0xFF00) >> 8);
    } else {
        *(u8 *)(pt + 0x18) = *(u8 *)(part + 0x19);
        *(u8 *)(pt + 0x19) = *(u8 *)(part + 0x1A);
        *(u8 *)(pt + 0x1A) = *(u8 *)(part + 0x1B);
    }
    {
        s16 a = *(s16 *)(pt + 0x14);
        s16 vv;

        *(s16 *)(pt + 0xC) = *(s16 *)(part + 0x10);
        *(s16 *)(pt + 0x12) = 0;
        *(s16 *)(pt + 0x10) = *(s16 *)(part + 0x12);
        vv = *(s16 *)(pt + 0xC);
        *(s16 *)(pt + 0xE) = (s16)(*(u8 *)(part + 0xE) << 8);
        if (vv < a) {
            *(s16 *)(pt + 0x16) = (s16)((((s32)(*(u8 *)(part + 0xF) - *(u8 *)(part + 0xE))) << 8) / (s32)(a - vv));
        } else {
            *(s16 *)(pt + 0x16) = 0;
        }
    }
    pos[0] = (f32)*(s16 *)(arg1 + 0x1A);
    pos[1] = (f32)*(s16 *)(arg1 + 0x1C);
    pos[2] = (f32)*(s16 *)(arg1 + 0x1E);
    len = *(f32 *)(part + 0x14) * *(f32 *)(*(u8 **)arg1 + 0x50);
    pointListRPY(1, (s16 *)arg0, (s32 *)pos, pos);
    pos[0] += *(f32 *)(arg0 + 0xC);
    pos[1] += *(f32 *)(arg0 + 0x10);
    pos[2] += *(f32 *)(arg0 + 0x14);
    if (*(u32 *)(*(u8 **)arg1) & 0x1000) {
        x = *(f32 *)(arg0 + 0x1C);
        y = *(f32 *)(arg0 + 0x20);
        z = *(f32 *)(arg0 + 0x24);
        len = len * sqrtf((x * x) + (y * y) + (z * z)) * 0.1f;
    }
    ptype = *(s32 *)(part + 0x4) & 0xF;
    if (!(*(u32 *)part & 0x4000)) {
        dir[0] = 0.0f;
        dir[1] = 0.0f;
        dir[2] = 0.0f;
        if (ptype == 1) {
            dir[1] = len;
        } else if (ptype == 2) {
            dir[2] = len;
        } else {
            dir[0] = len;
        }
        pointListRPY(1, (s16 *)arg0, (s32 *)dir, dir);
    } else {
        dir[0] = *(f32 *)(arg0 + 0x1C);
        dir[1] = *(f32 *)(arg0 + 0x20);
        dir[2] = *(f32 *)(arg0 + 0x24);
        mag2 = (dir[2] * dir[2]) + ((dir[0] * dir[0]) + (dir[1] * dir[1]));
        if (mag2 < 0.01f) {
            scl = 1.0f;
        } else {
            scl = len / sqrtf(mag2);
        }
        x = dir[0] * scl;
        y = dir[1] * scl;
        z = dir[2] * scl;
        if (ptype == 0) {
            dir[0] = -z;
            dir[1] = y;
            dir[2] = x;
        } else if (ptype == 1) {
            dir[0] = x;
            dir[1] = -z;
            dir[2] = y;
        } else {
            dir[0] = x;
            dir[1] = y;
            dir[2] = z;
        }
    }
    *(s16 *)(pt + 0x0) = (s16)(dir[0] + pos[0]);
    *(s16 *)(pt + 0x2) = (s16)(dir[1] + pos[1]);
    *(s16 *)(pt + 0x4) = (s16)(dir[2] + pos[2]);
    *(s16 *)(pt + 0x6) = (s16)(pos[0] - dir[0]);
    *(s16 *)(pt + 0x8) = (s16)(pos[1] - dir[1]);
    *(s16 *)(pt + 0xA) = (s16)(pos[2] - dir[2]);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_8006211C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_800626B4(u8 *arg0, s32 arg1) {
    s32 n;
    s32 k;
    s32 i;
    s32 tmp[9];
    u8 *e;
    u8 *pal;
    u8 *tex;
    s16 v;

    n = *(s32 *)arg0;
    for (k = 0; k < n && *(s16 *)(*(u8 **)(arg0 + 4 + k * 4) + 0x14) < arg1; k++) {
    }
    if (k > 0) {
        *(s32 *)arg0 = n - k;
        for (i = 0; i < k; i++) {
            tmp[i] = *(s32 *)(arg0 + 4 + i * 4);
        }
        for (i = 0; i < 9 - k; i++) {
            *(s32 *)(arg0 + 4 + i * 4) = *(s32 *)(arg0 + 4 + (i + k) * 4);
        }
        for (i = 0; i < k; i++) {
            *(s32 *)(arg0 + 4 + (9 - k + i) * 4) = tmp[i];
        }
    }
    if (*(u8 *)(arg0 + 0x124) == 1 && *(s32 *)arg0 == 0) {
        tex = *(u8 **)(arg0 + 0x128);
        *(u8 *)(arg0 + 0x124) = 0;
        if (tex != NULL) {
            texFreeTexture((s32)tex);
        }
    } else {
        for (i = 0; i < *(s32 *)arg0; i++) {
            e = *(u8 **)(arg0 + 4 + i * 4);
            *(s16 *)(e + 0x14) = (s16)(*(s16 *)(e + 0x14) - arg1);
            if (*(u8 **)(arg0 + 0x130) != NULL) {
                pal = *(u8 **)(arg0 + 0x130);
                v = *(s16 *)(e + 0x10);
                if (v == 0) {
                    *(s16 *)(e + 0x12) = (s16)(*(s16 *)(e + 0x12) + arg1);
                    if (*(s16 *)(e + 0x12) >= *(s16 *)(arg0 + 0x134)) {
                        *(s16 *)(e + 0x12) = (s16)(*(s16 *)(e + 0x12) - *(s16 *)(arg0 + 0x134));
                    }
                    *(u8 *)(e + 0x18) = (u8)((*(u32 *)(pal + *(s16 *)(e + 0x12) * 4) & 0xFF000000) >> 0x18);
                    *(u8 *)(e + 0x19) = (u8)((*(u32 *)(pal + *(s16 *)(e + 0x12) * 4) & 0xFF0000) >> 0x10);
                    *(u8 *)(e + 0x1A) = (u8)((*(u32 *)(pal + *(s16 *)(e + 0x12) * 4) & 0xFF00) >> 8);
                } else {
                    *(s16 *)(e + 0x10) = (s16)(v - arg1);
                    if (*(s16 *)(e + 0x10) < 0) {
                        *(s16 *)(e + 0x12) = (s16)(*(s16 *)(e + 0x12) - *(s16 *)(e + 0x10));
                    }
                }
            }
            v = *(s16 *)(e + 0xC);
            if (v == 0) {
                *(s16 *)(e + 0xE) = (s16)(*(s16 *)(e + 0xE) + (arg1 * *(s16 *)(e + 0x16)));
            } else {
                *(s16 *)(e + 0xC) = (s16)(v - arg1);
                if (*(s16 *)(e + 0xC) < 0) {
                    *(s16 *)(e + 0xC) = 0;
                    *(s16 *)(e + 0xE) = (s16)(*(s16 *)(e + 0xE) - (*(s16 *)(e + 0xC) * *(s16 *)(e + 0x16)));
                }
            }
        }
        if (*(u8 *)(arg0 + 0x124) != 0) {
            tex = *(u8 **)(arg0 + 0x128);
            if (*(u32 *)(arg0 + 0x13C) & 0x800) {
                *(f32 *)(arg0 + 0x140) = (f32)mathRnd(0, (*(u16 *)(tex + 0x12) >> 8) - 1);
            } else {
                texAnimateTexSprite((s32)tex, arg0 + 0x138, *(s16 *)(arg0 + 0x144), arg0 + 0x140, arg1);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_800626B4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80062A4C(u8 *arg0, s32 arg1) {
    s32 *slots;
    s32 removed;
    s32 i;
    s32 d;
    s32 v;
    s32 cnt;
    s32 found;
    u8 *tex;

    slots = (s32 *)arg0;
    removed = 0;
    for (i = 0; i < *(s32 *)(arg0 + 0x3C); i++) {
        if (func_80061CAC(*(u8 **)(arg0 + i * 4), arg1) != 0) {
            slots[i] = 0;
            removed = 1;
        }
    }
    if (removed != 0) {
        cnt = 0;
        for (d = 0; d < 0xF; d++) {
            found = 0;
            for (v = d; v < 0xF; v++) {
                if (slots[v] != 0) {
                    found = 1;
                    if (d != v) {
                        slots[d] = slots[v];
                        slots[v] = 0;
                    }
                    cnt++;
                    break;
                }
            }
            if (!found) {
                slots[d] = 0;
            }
        }
        *(s32 *)(arg0 + 0x3C) = cnt;
    }
    if (*(u8 *)(arg0 + 0xA4) == 1 && *(s32 *)(arg0 + 0x3C) == 0) {
        tex = *(u8 **)(arg0 + 0xB8);
        *(u8 *)(arg0 + 0xA4) = 0;
        if (tex != NULL) {
            texFreeTexture((s32)tex);
            *(u8 **)(arg0 + 0xB8) = NULL;
        }
    }
    if (*(u8 *)(arg0 + 0xA4) != 0) {
        tex = *(u8 **)(arg0 + 0xB8);
        if (*(u32 *)(arg0 + 0xAC) & 0x800) {
            *(f32 *)(arg0 + 0xB0) = (f32)mathRnd(0, (((TextureHeader *)tex)->numOfTextures >> 8) - 1);
        } else {
            texAnimateTexSprite((s32)tex, arg0 + 0xA8, *(s16 *)(arg0 + 0xB4), arg0 + 0xB0, arg1);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_80062A4C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Point-stream draw: for each point object of the stream, converts the scaled
// stream positions to vertices (10-byte records), emits a G_VTX-style command
// and, for i > 0, a tri command that alternates between the two pointpolys
// buffers. No DKR twin found for this (JFG pointstream/pointpolys specific).
void func_80062BFC(Gfx **arg0, u8 **arg1, u8 *arg2) {
    Gfx *dl;
    u8 *vtx;
    u8 *vstart;
    u8 *obj;
    f32 *src;
    f32 *o;
    f32 scale;
    f32 offX;
    f32 offY;
    f32 offZ;
    f32 inPts[24];   /* asm sp9C */
    f32 outPts[24];  /* asm spFC */
    s32 n;
    s32 i;
    s32 k;
    s32 rem;
    s32 polyA;       /* asm sp78: pointpolys row (n) first  */
    s32 polyB;       /* asm sp7C: pointpolys row (n) second */
    s32 triCount;    /* asm sp88 */
    s32 vtxIdxA;     /* asm sp4C */
    s32 vtxIdxB;     /* asm sp48 */
    s32 texSel;      /* asm sp8C, toggles 0/1 */
    s32 fp;          /* toggles between 0 and n */
    u8 col0;
    u8 col1;
    u8 col2;
    u8 col3;

    if (*(s32 *)(arg2 + 0x3C) >= 2) {
        dl = *arg0;
        vtx = *arg1;
        n = *(s32 *)(arg2 + 0x40);
        /* PolyPairRow table (D_800A5F48 == pointpolys), row index n-2 */
        polyA = *(s32 *)((u8 *)&pointpolys + n * 8 - 0x10);
        polyB = *(s32 *)((u8 *)&pointpolys + n * 8 - 0x0C);
        triCount = (n == 2) ? 2 : n * 2;
        vtxIdxA = n * 8;
        vtxIdxB = n * 10 + 8;
        fp = 0;
        texSel = 0;
        texDPTextureX(&dl, *(void **)(arg2 + 0xB8), 0x12, (s32)(*(f32 *)(arg2 + 0xB0) * 65536.0f));

        for (i = 0; i < *(s32 *)(arg2 + 0x3C); i++) {
            obj = *(u8 **)(arg2 + i * 4);
            vstart = vtx;

            if (n > 0) {
                /* scaled input positions: stream+0x44, 3 floats per point */
                src = (f32 *)(arg2 + 0x44);
                scale = *(f32 *)(obj + 0x08);
                k = 0;
                for (rem = n & 3; k < rem; k++) {
                    inPts[k * 3 + 0] = src[k * 3 + 0] * scale;
                    inPts[k * 3 + 1] = src[k * 3 + 1] * scale;
                    inPts[k * 3 + 2] = src[k * 3 + 2] * scale;
                }
                for (; k < n; k += 4) {
                    inPts[k * 3 + 0] = src[k * 3 + 0] * scale;
                    inPts[k * 3 + 1] = src[k * 3 + 1] * scale;
                    inPts[k * 3 + 2] = src[k * 3 + 2] * scale;
                    inPts[k * 3 + 3] = src[k * 3 + 3] * scale;
                    inPts[k * 3 + 4] = src[k * 3 + 4] * scale;
                    inPts[k * 3 + 5] = src[k * 3 + 5] * scale;
                    inPts[k * 3 + 6] = src[k * 3 + 6] * scale;
                    inPts[k * 3 + 7] = src[k * 3 + 7] * scale;
                    inPts[k * 3 + 8] = src[k * 3 + 8] * scale;
                    inPts[k * 3 + 9] = src[k * 3 + 9] * scale;
                    inPts[k * 3 + 10] = src[k * 3 + 10] * scale;
                    inPts[k * 3 + 11] = src[k * 3 + 11] * scale;
                }
            }

            col0 = obj[0x71];
            col1 = obj[0x72];
            col2 = obj[0x73];
            col3 = (u8)((*(s16 *)(obj + 0x64) >> 8) & 0xFF);
            pointListRPY(n, (s16 *)obj, (s32 *)inPts, outPts);

            if (n > 0) {
                offX = *(f32 *)(obj + 0x0C);
                offY = *(f32 *)(obj + 0x10);
                offZ = *(f32 *)(obj + 0x14);
                k = 0;
                for (rem = n & 3; k < rem; k++) {
                    o = &outPts[k * 3];
                    *(s16 *)(vtx + 0x00) = (s16)(s32)(o[0] + offX);
                    *(s16 *)(vtx + 0x02) = (s16)(s32)(o[1] + offY);
                    *(s16 *)(vtx + 0x04) = (s16)(s32)(o[2] + offZ);
                    vtx[0x06] = col0;
                    vtx[0x07] = col1;
                    vtx[0x08] = col2;
                    vtx[0x09] = col3;
                    vtx += 0x0A;
                }
                for (; k < n; k += 4) {
                    o = &outPts[k * 3];
                    *(s16 *)(vtx + 0x00) = (s16)(s32)(o[0] + offX);
                    *(s16 *)(vtx + 0x02) = (s16)(s32)(o[1] + offY);
                    *(s16 *)(vtx + 0x04) = (s16)(s32)(o[2] + offZ);
                    vtx[0x06] = col0;
                    vtx[0x07] = col1;
                    vtx[0x08] = col2;
                    vtx[0x09] = col3;
                    *(s16 *)(vtx + 0x0A) = (s16)(s32)(o[3] + offX);
                    *(s16 *)(vtx + 0x0C) = (s16)(s32)(o[4] + offY);
                    *(s16 *)(vtx + 0x0E) = (s16)(s32)(o[5] + offZ);
                    vtx[0x10] = col0;
                    vtx[0x11] = col1;
                    vtx[0x12] = col2;
                    vtx[0x13] = col3;
                    *(s16 *)(vtx + 0x14) = (s16)(s32)(o[6] + offX);
                    *(s16 *)(vtx + 0x16) = (s16)(s32)(o[7] + offY);
                    *(s16 *)(vtx + 0x18) = (s16)(s32)(o[8] + offZ);
                    vtx[0x1A] = col0;
                    vtx[0x1B] = col1;
                    vtx[0x1C] = col2;
                    vtx[0x1D] = col3;
                    *(s16 *)(vtx + 0x1E) = (s16)(s32)(o[9] + offX);
                    *(s16 *)(vtx + 0x20) = (s16)(s32)(o[10] + offY);
                    *(s16 *)(vtx + 0x22) = (s16)(s32)(o[11] + offZ);
                    vtx[0x24] = col0;
                    vtx[0x25] = col1;
                    vtx[0x26] = col2;
                    vtx[0x27] = col3;
                    vtx += 0x28;
                }
            }

            /* G_VTX-style command for this stream's vertices */
            ((s32 *)dl)[0] = ((((vtxIdxA | ((u32)vstart & 6)) & 0xFF) << 16) | 0x04000000)
                           | ((vtxIdxB | (fp << 9)) & 0xFFFF);
            ((s32 *)dl)[1] = (s32)((u32)vstart + 0x80000000);
            dl++;

            if (i > 0) {
                /* tri command, texture buffer alternates between polyA / polyB */
                ((s32 *)dl)[0] = (((((triCount - 1) * 0x10) | 1) & 0xFF) << 16) | 0x05000000
                               | ((triCount * 0x10) & 0xFFFF);
                if (texSel == 0) {
                    ((s32 *)dl)[1] = (s32)((u32)polyA + 0x80000000);
                } else {
                    ((s32 *)dl)[1] = (s32)((u32)polyB + 0x80000000);
                }
                texSel ^= 1;
                dl++;
            }

            fp = (fp != 0) ? 0 : n;
        }

        *arg0 = dl;
        *arg1 = vtx;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_80062BFC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80063484(Gfx **arg0, u8 **arg1) {
    s32 i;
    u8 *stream;

    if (pointstreams != NULL) {
        stream = pointstreams;
        for (i = 0; i < maxpointstreams; i++, stream += 0xC0) {
            if (*(u8 *)(stream + 0xA4) != 0) {
                func_80062BFC(arg0, arg1, stream);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_80063484.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80063514(Gfx **arg0, u8 **arg1) {
    Gfx *dl;
    u8 *vtx;
    u8 *line;
    u8 *start;
    u8 *p;
    s32 i;
    s32 k;
    s32 n;
    s32 w0;
    s32 w1;

    if (lines != NULL) {
        dl = *arg0;
        vtx = *arg1;
        line = lines;
        for (i = 0; i < maxlines; i++, line += 0x148) {
            if (*(u8 *)(line + 0x124) != 0) {
                n = *(s32 *)(line + 0x00);
                if (n >= 2) {
                    start = vtx;
                    for (k = 0; k < n; k++) {
                        p = *(u8 **)(line + 4 + k * 4);
                        *(s16 *)(vtx + 0x00) = *(s16 *)(p + 0x00);
                        *(s16 *)(vtx + 0x02) = *(s16 *)(p + 0x02);
                        *(s16 *)(vtx + 0x04) = *(s16 *)(p + 0x04);
                        vtx[0x06] = p[0x18];
                        vtx[0x07] = p[0x19];
                        vtx[0x08] = p[0x1A];
                        vtx[0x09] = p[0x0E];
                        *(s16 *)(vtx + 0x0A) = *(s16 *)(p + 0x06);
                        *(s16 *)(vtx + 0x0C) = *(s16 *)(p + 0x08);
                        *(s16 *)(vtx + 0x0E) = *(s16 *)(p + 0x0A);
                        vtx[0x10] = p[0x18];
                        vtx[0x11] = p[0x19];
                        vtx[0x12] = p[0x1A];
                        vtx[0x13] = p[0x0E];
                        vtx += 0x14;
                    }
                    texDPTextureX(&dl, *(void **)(line + 0x128), 0x12,
                                  (s32)(*(f32 *)(line + 0x140) * 65536.0f));
                    w1 = (s32)start + 0x80000000;
                    ((s32 *)dl)[0] = ((((n * 2 * 8) | ((u32)w1 & 6)) & 0xFF) << 16) | 0x04000000 |
                                     (((n * 0x14) + 8) & 0xFFFF);
                    ((s32 *)dl)[1] = w1;
                    dl++;
                    w0 = (n * 2) - 3;
                    ((s32 *)dl)[0] = (((w0 * 0x10) | 1) & 0xFF) << 16 | 0x05000000 |
                                     ((((n * 2) - 2) * 0x10) & 0xFFFF);
                    ((s32 *)dl)[1] = (s32)D_A5DE8;
                    dl++;
                }
            }
        }
        ((s32 *)dl)[1] = 0;
        ((s32 *)dl)[0] = 0xE7000000;
        dl++;
        *arg0 = dl;
        *arg1 = vtx;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_80063514.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_800637E0(u8 *arg0, u8 *arg1) {
    u8 streamIdx = arg1[0x22];
    void *part;
    u8 *stream;
    void *ptr;

    if (streamIdx == 0xFF) {
        return;
    }
    part = PartTab[*(s16 *)(arg1 + 0x0A)];
    if ((((u32)*(s32 *)((u8 *)part + 0x4)) >> 28) != 4) {
        return;
    }
    stream = (u8 *)pointstreams + streamIdx * 0xC0;
    if (*(s32 *)(stream + 0x3C) == 0xF) {
        return;
    }
    ptr = func_80060ED4(arg0, arg1, -1);
    if (ptr != NULL) {
        *(void **)(stream + *(s32 *)(stream + 0x3C) * 4) = ptr;
        *(s32 *)(stream + 0x3C) += 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_800637E0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80063890(u8 *arg0) {
    s32 i;
    void *parent;

    for (i = 0; i < D_80100900_B1770; i++) {
        f32 oldY = *(f32 *)(arg0 + 0x20);

        *(f32 *)(arg0 + 0x30) = *(f32 *)(arg0 + 0x30) + *(f32 *)(arg0 + 0x1C);
        *(f32 *)(arg0 + 0x34) = *(f32 *)(arg0 + 0x34) + oldY;
        *(f32 *)(arg0 + 0x20) = oldY - *(f32 *)(arg0 + 0x40);
        *(f32 *)(arg0 + 0x38) = *(f32 *)(arg0 + 0x38) + *(f32 *)(arg0 + 0x24);
        *(s16 *)(arg0 + 0x00) = *(s16 *)(arg0 + 0x00) + *(s16 *)(arg0 + 0x5E);
        *(s16 *)(arg0 + 0x02) = *(s16 *)(arg0 + 0x02) + *(s16 *)(arg0 + 0x60);
        *(s16 *)(arg0 + 0x04) = *(s16 *)(arg0 + 0x04) + *(s16 *)(arg0 + 0x62);
        *(f32 *)(arg0 + 0x08) = *(f32 *)(arg0 + 0x08) + *(f32 *)(arg0 + 0x18);
    }
    parent = *(void **)(arg0 + 0x48);
    *(f32 *)(arg0 + 0x0C) = *(f32 *)(arg0 + 0x30);
    *(f32 *)(arg0 + 0x10) = *(f32 *)(arg0 + 0x34);
    *(f32 *)(arg0 + 0x14) = *(f32 *)(arg0 + 0x38);
    if (parent != NULL) {
        *(f32 *)(arg0 + 0x0C) += *(f32 *)((u8 *)parent + 0x0C);
        *(f32 *)(arg0 + 0x10) += *(f32 *)((u8 *)parent + 0x10);
        *(f32 *)(arg0 + 0x14) += *(f32 *)((u8 *)parent + 0x14);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_80063890.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80063990(u8 *arg0) {
    s32 i;
    u8 *parent;

    for (i = 0; i < D_80100900_B1770; i++) {
        *(s16 *) (arg0 + 0x00) = (s16) (*(s16 *) (arg0 + 0x00) + *(s16 *) (arg0 + 0x5E));
        *(s16 *) (arg0 + 0x02) = (s16) (*(s16 *) (arg0 + 0x02) + *(s16 *) (arg0 + 0x60));
        *(s16 *) (arg0 + 0x04) = (s16) (*(s16 *) (arg0 + 0x04) + *(s16 *) (arg0 + 0x62));
        *(f32 *) (arg0 + 0x08) = *(f32 *) (arg0 + 0x08) + *(f32 *) (arg0 + 0x18);
    }
    *(f32 *) (arg0 + 0x10) = -*(f32 *) (arg0 + 0x3C);
    *(f32 *) (arg0 + 0x0C) = 0.0f;
    *(f32 *) (arg0 + 0x14) = 0.0f;
    pointListRPY(1, (s16 *) arg0, (s32 *) (arg0 + 0x0C), (f32 *) (arg0 + 0x0C));
    parent = *(u8 **) (arg0 + 0x48);
    *(f32 *) (arg0 + 0x0C) = *(f32 *) (arg0 + 0x0C) + *(f32 *) (arg0 + 0x30);
    *(f32 *) (arg0 + 0x10) = *(f32 *) (arg0 + 0x10) + *(f32 *) (arg0 + 0x34);
    *(f32 *) (arg0 + 0x14) = *(f32 *) (arg0 + 0x14) + *(f32 *) (arg0 + 0x38);
    if (parent != NULL) {
        *(f32 *) (arg0 + 0x0C) = *(f32 *) (arg0 + 0x0C) + *(f32 *) (parent + 0x0C);
        *(f32 *) (arg0 + 0x10) = *(f32 *) (arg0 + 0x10) + *(f32 *) (parent + 0x10);
        *(f32 *) (arg0 + 0x14) = *(f32 *) (arg0 + 0x14) + *(f32 *) (parent + 0x14);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_80063990.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80063AB4(u8 *arg0) {
    f32 sp40;
    f32 sp3C;
    s32 sp38;
    s32 i;

    i = 1;
    if (D_80100900_B1770 > 0) {
        do {
            *(f32 *) (arg0 + 0x0C) = *(f32 *) (arg0 + 0x0C) + *(f32 *) (arg0 + 0x1C);
            *(f32 *) (arg0 + 0x10) = *(f32 *) (arg0 + 0x10) + *(f32 *) (arg0 + 0x20);
            *(f32 *) (arg0 + 0x14) = *(f32 *) (arg0 + 0x14) + *(f32 *) (arg0 + 0x24);
            *(f32 *) (arg0 + 0x08) = *(f32 *) (arg0 + 0x08) + *(f32 *) (arg0 + 0x18);
            *(s16 *) (arg0 + 0x00) = (s16) (*(s16 *) (arg0 + 0x00) + *(s16 *) (arg0 + 0x5E));
            *(s16 *) (arg0 + 0x02) = (s16) (*(s16 *) (arg0 + 0x02) + *(s16 *) (arg0 + 0x60));
            *(s16 *) (arg0 + 0x04) = (s16) (*(s16 *) (arg0 + 0x04) + *(s16 *) (arg0 + 0x62));
            sp38 = 0;
            sp40 = 0.0f;
            sp3C = -*(f32 *) (arg0 + 0x3C);
            pointListRPY(1, (s16 *) arg0, &sp38, (f32 *) &sp38);
            *(f32 *) (arg0 + 0x1C) = *(f32 *) (arg0 + 0x1C) + *(f32 *) &sp38;
            *(f32 *) (arg0 + 0x20) = *(f32 *) (arg0 + 0x20) + sp3C;
            *(f32 *) (arg0 + 0x20) = *(f32 *) (arg0 + 0x20) - *(f32 *) (arg0 + 0x40);
            *(f32 *) (arg0 + 0x24) = *(f32 *) (arg0 + 0x24) + sp40;
            i++;
        } while (i < D_80100900_B1770);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_80063AB4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80063C14(u8 *arg0) {
    f32 temp_f0;
    s32 i;

    i = 1;
    if (D_80100900_B1770 > 0) {
        do {
            temp_f0 = *(f32 *) (arg0 + 0x20);
            *(f32 *) (arg0 + 0x0C) = *(f32 *) (arg0 + 0x0C) + *(f32 *) (arg0 + 0x1C);
            *(f32 *) (arg0 + 0x10) = *(f32 *) (arg0 + 0x10) + temp_f0;
            *(f32 *) (arg0 + 0x20) = temp_f0 - *(f32 *) (arg0 + 0x40);
            *(f32 *) (arg0 + 0x14) = *(f32 *) (arg0 + 0x14) + *(f32 *) (arg0 + 0x24);
            *(f32 *) (arg0 + 0x08) = *(f32 *) (arg0 + 0x08) + *(f32 *) (arg0 + 0x18);
            *(s16 *) (arg0 + 0x00) = (s16) (*(s16 *) (arg0 + 0x00) + *(s16 *) (arg0 + 0x5E));
            *(s16 *) (arg0 + 0x02) = (s16) (*(s16 *) (arg0 + 0x02) + *(s16 *) (arg0 + 0x60));
            *(s16 *) (arg0 + 0x04) = (s16) (*(s16 *) (arg0 + 0x04) + *(s16 *) (arg0 + 0x62));
            i++;
        } while (i < D_80100900_B1770);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_80063C14.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80063CC8(u8 *arg0) {
    s32 i;

    i = 1;
    if (D_80100900_B1770 > 0) {
        do {
            *(f32 *) (arg0 + 0x1C) = 0.0f;
            *(f32 *) (arg0 + 0x20) = 0.0f;
            *(f32 *) (arg0 + 0x24) = -*(f32 *) (arg0 + 0x3C);
            mathOneFloatPY((s16 *) arg0, arg0 + 0x1C);
            *(f32 *) (arg0 + 0x0C) = *(f32 *) (arg0 + 0x0C) + *(f32 *) (arg0 + 0x1C);
            *(f32 *) (arg0 + 0x10) = *(f32 *) (arg0 + 0x10) + (*(f32 *) (arg0 + 0x20) - *(f32 *) (arg0 + 0x40));
            *(f32 *) (arg0 + 0x14) = *(f32 *) (arg0 + 0x14) + *(f32 *) (arg0 + 0x24);
            *(f32 *) (arg0 + 0x08) = *(f32 *) (arg0 + 0x08) + *(f32 *) (arg0 + 0x18);
            *(s16 *) (arg0 + 0x00) = (s16) (*(s16 *) (arg0 + 0x00) + *(s16 *) (arg0 + 0x5E));
            *(s16 *) (arg0 + 0x02) = (s16) (*(s16 *) (arg0 + 0x02) + *(s16 *) (arg0 + 0x60));
            *(s16 *) (arg0 + 0x04) = (s16) (*(s16 *) (arg0 + 0x04) + *(s16 *) (arg0 + 0x62));
            i++;
        } while (i < D_80100900_B1770);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/func_80063CC8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void partUpdateParticles(s32 arg0) {
    f32 hit[4];
    s32 radius;
    void **list;
    u8 *group;
    u8 *particle;
    u8 *entry;
    u8 *from;
    u8 *to;
    f32 len;
    f32 vx;
    f32 vy;
    f32 vz;
    f32 dot;
    f32 scale;
    f32 proj;
    s32 i;

    D_800A5DE0_A69E0 = 0;
    D_80100908_B1778[0] = 0;
    entry = D_80100908_B1778 + 0x10;
    *(s32 *) (entry + 0x00) = 0;
    *(s32 *) (entry + 0x10) = 0;
    *(s32 *) (entry + 0x20) = 0;
    *(s32 *) (entry + 0x30) = 0;

    list = partlists;
    do {
        group = (u8 *) *list;
        if (group != NULL) {
            particle = *(u8 **) (group + 0x14);
            if (*(s32 *) (group + 0x18) > 0) {
                for (i = 0; i < *(s32 *) (group + 0x18); i++) {
                    if (*(s16 *) (particle + 0x2C) != 0x80) {
                        func_80061CAC(particle, arg0);
                    }
                    particle += 0x78;
                }
            }
        }
        list += 4;
    } while ((u32) list < (u32) D_801008F0_B1760);

    if (lines != NULL) {
        particle = lines;
        if (maxlines > 0) {
            for (i = 0; i < maxlines; i++) {
                if (*(u8 *) (particle + 0x124) != 0) {
                    func_800626B4(particle, arg0);
                }
                particle += 0x148;
            }
        }
    }
    if (pointstreams != NULL) {
        particle = pointstreams;
        if (maxpointstreams > 0) {
            for (i = 0; i < maxpointstreams; i++) {
                if (*(u8 *) (particle + 0xA4) != 0) {
                    func_80062A4C(particle, arg0);
                }
                particle += 0xC0;
            }
        }
    }

    entry = D_80100908_B1778;
    do {
        particle = *(u8 **) entry;
        if (particle != NULL) {
            from = entry + 4;
            to = particle + 0x0C;
            radius = 0x40A00000;
            trackMakePolylist(1, from, (s32) to, &radius, 0xCE002000, 0, 0);
            if (trackGetIntersect(0, from, (s32) to, radius, 1, hit) != 0) {
                if (hit[2] > 0.75f) {
                    *(u8 *) (particle + 0x2F) = (u8) (*(u8 *) (particle + 0x2F) + 1);
                }
                vx = *(f32 *) (particle + 0x1C);
                vy = *(f32 *) (particle + 0x20);
                vz = *(f32 *) (particle + 0x24);
                len = sqrtf((vx * vx) + (vy * vy) + (vz * vz));
                if (len != 0.0f) {
                    dot = -len;
                    *(f32 *) (particle + 0x1C) = vx / dot;
                    *(f32 *) (particle + 0x20) = vy / dot;
                    *(f32 *) (particle + 0x24) = vz / dot;
                }
                if ((len < 0.8f) && (hit[2] > 0.75f)) {
                    *(f32 *) (particle + 0x1C) = 0.0f;
                    *(f32 *) (particle + 0x20) = 0.0f;
                    *(f32 *) (particle + 0x24) = 0.0f;
                    *(s32 *) (particle + 0x50) = *(s32 *) (particle + 0x50) | 0x20000;
                } else {
                    vx = *(f32 *) (particle + 0x1C);
                    vy = *(f32 *) (particle + 0x20);
                    vz = *(f32 *) (particle + 0x24);
                    scale = len * 0.66f;
                    proj = 2.0f * ((hit[3] * vz) + ((hit[1] * vx) + (hit[2] * vy)));
                    *(f32 *) (particle + 0x1C) = ((hit[1] * proj) - vx) * scale;
                    *(f32 *) (particle + 0x20) = ((hit[2] * proj) - vy) * scale;
                    *(f32 *) (particle + 0x24) = ((hit[3] * proj) - vz) * scale;
                }
            }
        }
        entry += 0x10;
    } while (entry != D_80100958_B17C8);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/partUpdateParticles.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void partDraw(void **arg0, s32 arg1) {
    s32 sp2C;
    u32 *dl;

    sp2C = *(s32 *) ((u8 *) &partvertices + (D_800A5DD8_A69D8 * 4));
    dl = (u32 *) *arg0;
    *arg0 = dl + 2;
    dl[0] = 0xE7000000;
    dl[1] = 0;
    camSetNo(0);
    camSetView(arg0, (void **) arg1); /* sig mismatch */
    func_8005E3DC(arg0, &sp2C, *partlists);
    func_8005E3DC(arg0, &sp2C, D_801008E4_B1754);
    func_80063514((Gfx **) arg0, (u8 **) &sp2C); /* sig mismatch */
    func_80063484((Gfx **) arg0, (u8 **) &sp2C); /* sig mismatch */
    func_8005DD88(arg0, arg1, &sp2C, (void *) D_801008E8_B1758);
    ((void (*)(void **, s32, s32 *, s32)) func_8005E100)(arg0, arg1, &sp2C, D_801008EC_B175C); /* sig mismatch */
    D_800A5DD8_A69D8 ^= 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/partDraw.s")
#endif

#ifdef VERSION_us
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void partNullifyCircularParticleParents(void *arg0) {
    void **list;
    u8 *group;
    u8 *particle;
    s32 i;

    list = partlists;
    do {
        group = (u8 *) *list;
        list += 4;
        particle = *(u8 **) (group + 0x14);
        for (i = 0; i < *(s32 *) (group + 0x18); i++) {
            if (*(s16 *) (particle + 0x2C) != 0x80) {
                if (*(u8 *) (particle + 0x2E) == 3) {
                    *(f32 *) (particle + 0x30) = *(f32 *) (particle + 0x30) + *(f32 *) ((u8 *) arg0 + 0x0C);
                    *(f32 *) (particle + 0x34) = *(f32 *) (particle + 0x34) + *(f32 *) ((u8 *) arg0 + 0x10);
                    *(void **) (particle + 0x48) = NULL;
                    *(f32 *) (particle + 0x38) = *(f32 *) (particle + 0x38) + *(f32 *) ((u8 *) arg0 + 0x14);
                }
            }
            particle += 0x78;
        }
    } while (list != D_801008F4_B1764);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/particles/partNullifyCircularParticleParents.s")
#endif
#endif
