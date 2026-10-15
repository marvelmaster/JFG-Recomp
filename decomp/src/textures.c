#include "common.h"

const char D_800ADD40[] = "Error: Texture no %x out of range on load. !!\n";
const char D_800ADD70[] = "Restore to %x\n";
const char D_800ADD80[] = "Restore1 to %x\n";
const char D_800ADD90[] = "TEX Error: Palette memory overflow!!\n";
const char D_800ADDB8[] = "TEX Error: TexTab overflow!!\n";
const char D_800ADDD8[] = "texFreeTexture: NULL tex!!\n";
const char D_800ADDF4[] = "TEX Error: Tryed to deallocate non-existent texture!!\n";
const char D_800ADE2C[] = "SRPBUF overflow!!\n";
const char D_800ADE40[] = "Error: Sprite table overflow!!\n";
const char D_800ADE60[] = "texFreeSprite: NULL sprite!!\n";
const char D_800ADE80[] = "TEXSPR Error: Tryed to deallocate non-existent sprite!!\n";

enum TriangleBatchFlags {
    BATCH_FLAGS_NONE = 0,
    BATCH_FLAGS_BIT0 = (1 << 0),
    BATCH_FLAGS_BIT1 = (1 << 1),
    BATCH_FLAGS_BIT2 = (1 << 2),
    BATCH_FLAGS_BIT3 = (1 << 3),
    BATCH_FLAGS_BIT4 = (1 << 4),
    BATCH_FLAGS_BIT5 = (1 << 5),
    BATCH_FLAGS_BIT6 = (1 << 6),
    BATCH_FLAGS_BIT7 = (1 << 7),
    BATCH_FLAGS_BIT8 = (1 << 8),
    BATCH_FLAGS_BIT9 = (1 << 9),
    BATCH_FLAGS_BIT10 = (1 << 10),
    BATCH_FLAGS_BIT11 = (1 << 11),
    BATCH_FLAGS_BIT12 = (1 << 12),
    BATCH_FLAGS_BIT13 = (1 << 13),
    BATCH_FLAGS_BIT14 = (1 << 14),
    BATCH_FLAGS_BIT15 = (1 << 15),
    BATCH_FLAGS_BIT16 = (1 << 16),
    BATCH_FLAGS_BIT17 = (1 << 17),
    BATCH_FLAGS_BIT18 = (1 << 18),
    BATCH_FLAGS_BIT19 = (1 << 19),
    BATCH_FLAGS_BIT20 = (1 << 20),
    BATCH_FLAGS_BIT21 = (1 << 21),
    BATCH_FLAGS_BIT22 = (1 << 22),
    BATCH_FLAGS_BIT23 = (1 << 23),
    BATCH_FLAGS_BIT24 = (1 << 24),
    BATCH_FLAGS_BIT25 = (1 << 25),
    BATCH_FLAGS_BIT26 = (1 << 26),
    BATCH_FLAGS_BIT27 = (1 << 27),
    BATCH_FLAGS_BIT28 = (1 << 28),
    BATCH_FLAGS_BIT29 = (1 << 29),
    BATCH_FLAGS_BIT30 = (1 << 30),
    BATCH_FLAGS_BIT31 = (1 << 31)
};

void texFreeTexture(TextureHeader *tex); // Non Matching

typedef struct TextureCacheEntry {
    s32 id;
    TextureHeader *texture;
} TextureCacheEntry;

typedef struct Sprite {
    /* 0x00 */ s16 baseTextureId;
    /* 0x02 */ s16 numberOfFrames; // 1 means static texture
    /* 0x04 */ s16 numberOfInstances;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ u8 pad8[8];
    /* 0x10 */ TextureHeader **frames;
    union {
        /* 0x0C */ u8 val[1];  // Actual size varies.
        /* 0x0C */ u8 *ptr[1]; // Display list?
    } unkC;
} Sprite;

typedef struct SpriteCacheEntry {
    s32 id;
    Sprite *sprite;
} SpriteCacheEntry;

extern SpriteCacheEntry *D_800FF9EC;
extern s32 D_800FF9FC;
extern s32 D_800FFA00;
extern s32 D_800FFA04;
extern u8 *D_800FFA08;
void func_800577D8(u8 *hdr, Sprite *sprite, s32 idx);
extern s32 D_800FF9F8;

/* decomp: externs */
#ifdef NON_MATCHING
extern TextureCacheEntry *D_800FF9C8;
extern MemoryPoolSlot *D_800FF9CC;
extern s32 D_800FF9D0;
extern s32 D_800FF9D8[2];
extern s32 D_800FF9E0;
extern s32 D_800FF9E4;
extern u32 *D_800FF9E8;
extern MemoryPoolSlot *D_800FF9F0;
extern TextureHeader *D_800FFA0C;
extern s32 mmColourTagUnk1;
void func_80057B8C(TextureHeader *tex, Gfx *_dlist);
s32 texAnimateSprite(u8 *arg0, s32 *arg1, s32 arg2, f32 *arg3, s32 arg4);
void fxCpuTextureRequired(s32 arg0, void *arg1); /* fx.c */
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void texInitTextures(void) {
    s32 i;
    s32 lastIdx;

    D_800FF9C8 = (TextureCacheEntry *) mmAlloc(0x15E0, 0xFF00FFFFU);
    D_800FF9CC = mmAlloc(0x280, 0xFF00FFFFU);
    D_800FF9D0 = 0;
    D_800FF9E0 = 0;
    D_800FF9C0[0] = (s32 *) piRomLoad(3U);
    D_800FF9C0[1] = (s32 *) piRomLoad(1U);

    i = 0;
    if (D_800FF9C0[0][0] != -1) {
        do {
            i++;
        } while (D_800FF9C0[0][i] != -1);
    }
    D_800FF9D8[0] = i - 1;

    i = 0;
    if (D_800FF9C0[1][0] != -1) {
        do {
            i++;
        } while (D_800FF9C0[1][i] != -1);
    }
    D_800FF9D8[1] = i - 1;

    D_800FF9EC = (SpriteCacheEntry *) mmAlloc(0x320, 0xFF00FFFFU);
    D_800FF9F0 = mmAlloc(0x200, 0xFF00FFFFU);
    D_800FF9F8 = 0;
    D_800FF9E8 = piRomLoad(0x16U);
    D_800FF9F4 = 0;

    lastIdx = 0;
    if (D_800FF9E8[0] != -1) {
        i = 1;
        do {
            D_800FF9F4 = i;
            lastIdx = i;
            i = lastIdx + 1;
        } while (D_800FF9E8[lastIdx] != -1);
    }
    D_800FF9F4 = lastIdx - 1;
    D_800FFA0C = (TextureHeader *) mmAlloc(0x28, 0xFF00FFFFU);
    D_800FF9E4 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/textures/texInitTextures.s")
#endif

void texDisableModes(s32 flags) {
    D_800A5838 |= flags;
}

void texEnableModes(s32 flags) {
    D_800A5838 &= ~flags;
}

void texModelTextureLoad(u8 arg0) {
    D_800A583C = arg0;
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
TextureHeader *texLoadTexture(s32 arg0) {
    s32 bank;
    s32 idx;
    s32 i;
    s32 texId;
    s32 freeSlot;
    s32 romStart;
    s32 romSize;
    s32 uncompSize;
    s32 allocSize;
    s32 tmp;
    s32 *romEntry;
    u32 section;
    u8 *buf;

    texId = arg0 & 0xFFFF;
    section = 2;
    bank = 0;
    idx = texId;
    if (texId & 0x8000) {
        bank = 1;
        idx = texId & 0x7FFF;
        section = 0;
    }
    if (idx >= D_800FF9D8[bank] || idx < 0) {
        texId = 0;
    }

    for (i = 0; i < D_800FF9D0; i++) {
        if (texId == D_800FF9C8[i].id) {
            *(u16 *) &D_800FF9C8[i].texture->ciPaletteOffset += 1;
            return D_800FF9C8[i].texture;
        }
    }

    romEntry = &D_800FF9C0[bank][idx];
    romStart = romEntry[0];
    romSize = romEntry[1] - romStart;
    mmColourTagUnk1 = texId;
    piRomLoadSection(section, (u32) D_800FFA0C, romStart, 0x28);

    if (D_800FFA0C->unk19 == 0) {
        if (D_800A584C != 0) {
            buf = mmAllocAtAddr(romSize + 0x90, (u8 *) D_800A584C, D_800A5830);
        } else {
            buf = ((u8 * (*)(s32, u32)) mmAlloc2)(romSize + 0x90, D_800A5830); /* sig mismatch */
        }
        mmColourTagUnk1 = -1;
        if (buf == NULL) {
            return NULL;
        }
        piRomLoadSection(section, (u32) buf, romStart, romSize);
    } else {
        uncompSize = rzipUncompressSize((u8 *) D_800FFA0C + 0x20);
        if (uncompSize < romSize) {
            allocSize = romSize;
        } else {
            allocSize = uncompSize;
        }
        allocSize += 0x20;
        if (D_800A584C != 0) {
            buf = mmAllocAtAddr(allocSize + 0x90, (u8 *) D_800A584C, D_800A5830);
        } else {
            buf = ((u8 * (*)(s32, u32)) mmAlloc2)(allocSize + 0x90, D_800A5830); /* sig mismatch */
        }
        mmColourTagUnk1 = -1;
        if (buf == NULL) {
            return NULL;
        }
        tmp = ((s32) buf + allocSize) - romSize;
        tmp -= tmp % 16;
        piRomLoadSection(section, (u32) tmp, romStart, romSize);
        rzipUncompress((u8 *) tmp + 0x20, buf);
        romSize = uncompSize;
    }

    freeSlot = -1;
    for (i = 0; i < D_800FF9D0; i++) {
        if (D_800FF9C8[i].id == -1) {
            freeSlot = i;
        }
    }
    if (freeSlot == -1) {
        freeSlot = D_800FF9D0;
        D_800FF9D0++;
    }
    D_800FF9C8[freeSlot].id = texId;
    D_800FF9C8[freeSlot].texture = (TextureHeader *) buf;
    func_80057B8C((TextureHeader *) buf, (Gfx *) mmAlign16(buf + romSize));

    if (D_800FF9E0 >= 0x280) {
        return NULL;
    }
    if (D_800FF9D0 >= 0x2BD) {
        return NULL;
    }
    return (TextureHeader *) buf;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/textures/texLoadTexture.s")
#endif

#if 0 /* old NON_EQUIVALENT attempt */
extern s32 D_800FF9D0;
extern TextureCacheEntry *D_800FF9C8;
void texFreeTexture(TextureHeader *tex) {
    s32 i;
    s32 j;
    s32 texId;

    if (tex != NULL) {
        tex->numberOfInstances--;
        if (tex->numberOfInstances <= 0) {
            for (i = 0; i < D_800FF9D0; i++) {
                j = i << 1;
                if (tex == D_800FF9C8[j].texture) {
                    texId = -1;
                    mmFree(tex);
                    D_800FF9C8[j].id = texId;
                    D_800FF9C8[j].texture = (TextureHeader *) texId;
                    break;
                }
            }
        }
    }
}
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void texFreeTexture(TextureHeader *tex) {
    s32 i;

    if (tex != NULL) {
        (*(u16 *) &tex->ciPaletteOffset)--;
        if (*(u16 *) &tex->ciPaletteOffset == 0) {
            for (i = 0; i < D_800FF9D0; i++) {
                if (tex == D_800FF9C8[i].texture) {
                    mmFree(tex);
                    D_800FF9C8[i].id = -1;
                    D_800FF9C8[i].texture = (TextureHeader *) -1;
                    return;
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/textures/texFreeTexture.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 texGetTextureNum(s32 arg0) {
    s32 i;

    for (i = 0; i < D_800FF9D0; i++) {
        if (arg0 == (s32) D_800FF9C8[i].texture) {
            return D_800FF9C8[i].id;
        }
    }
    return -1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/textures/texGetTextureNum.s")
#endif

void texLoadTextureAddr(s32 arg0, s32 arg1) {
    D_800A584C = arg1;
    texLoadTexture(arg0);
    D_800A584C = 0;
}

void setTexMemColour(s32 tagId) {
    D_800A5830 = tagId;
}

typedef struct Struct_Unk_8007B46C {
    u8 pad0[0x12];
    u16 unk12;
    u8 pad14[2];
    s16 unk16;
    u8 pad17[8];
} Struct_Unk_8007B46C;

TextureHeader *texFrame(TextureHeader *arg0, s32 arg1) {
    TextureHeader *ret = arg0 + 1;
    if ((arg1 > 0) && (arg1 < arg0->numOfTextures << 8)) {
        ret = (TextureHeader *) (((u8 *) arg0) + ((arg1 >> 16) * arg0->textureSize)) + 1;
    }
    return ret;
}

/**
 * Resets all render settings to the default state.
 * The next draw call will be forced to apply all settings instead of skipping unecessary steps.
 */
void texDPInit(Gfx **dlist) {
    D_800A5838 = 0;
    D_800FFA14 = 0;
    D_800FFA18 = 0;
    D_800FFA10 = 0;
    D_800FFA1C = 0;
    D_800FFA20 = 1;
    D_800FFA24 = 1;
    if (dlist != NULL) {
        gDPPipeSync((*dlist)++);
        gSPSetGeometryMode((*dlist)++, G_FOG | G_SHADING_SMOOTH | G_SHADE | G_ZBUFFER);
    }
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
typedef struct TexDPEntry {
    Gfx *unk0;
    Gfx *unk4;
    u32 unk8;
    u32 unkC;
} TexDPEntry;

extern TexDPEntry D_800A52B0[];
extern TexDPEntry D_800A55B0[];
extern TexDPEntry D_800A56B0[];
extern u8 D_800A5840;

void texDPTextureX(Gfx **dlist, TextureHeader *tex, s32 flags, s32 frameArg) {
    Gfx *gdl;
    u8 *frameCur;
    u8 *frameNext;
    TexDPEntry *tbl;
    s32 frame;
    s32 numFrames;
    s32 texSize;
    s32 mode;
    s32 sel;
    s32 combined;
    s32 key;
    u32 tmp;
    s32 i;

    gdl = *dlist;
    frame = frameArg >> 16;
    tbl = D_800A52B0;

    if (tex != NULL) {
        /* numOfTextures keeps the frame count in its upper byte */
        numFrames = (s32) tex->numOfTextures >> 8;
        if (numFrames >= 2 && frame < numFrames && D_800A583C == 0) {
            texSize = tex->textureSize;
            frameCur = (u8 *) tex + frame * texSize + 0x20;
            frameNext = frameCur;
            if ((tex->flags & 0x40) && (tex->unk1B < 2)) {
                i = frame + 1;
                if (i >= numFrames) {
                    i = numFrames - 1;
                    if (tex->unk18 != 0) {
                        i = 0;
                    }
                }
                frameNext = (u8 *) tex + i * texSize + 0x20;
            }
        } else {
            frameNext = (u8 *) tex + 0x20;
            frameCur = frameNext;
        }

        flags |= tex->flags;

        if (frameCur != (u8 *) D_800FFA14 || frameNext != (u8 *) D_800FFA18) {
            D_800FFA14 = (s32) frameCur;
            D_800FFA18 = (s32) frameNext;
            gdl->words.w1 = (u32) frameCur;
            gdl->words.w0 = *(u32 *) tex->cmd;
            gdl++;
            if (tex->unk1B >= 2) {
                gdl->words.w0 = 0x06000000;
                gdl->words.w1 = (u32) (tex->cmd + 1);
                gdl++;
            } else {
                gdl->words.w0 = 0x07060030;
                gdl->words.w1 = (u32) (tex->cmd + 1) + 0x80000000;
                gdl++;
                if ((tex->flags & 0x40) && (tex->unk1B < 2)) {
                    gdl->words.w1 = (u32) frameNext;
                    gdl->words.w0 = *(u32 *) ((u8 *) (tex->cmd + 1) + 0x30);
                    gdl++;
                    gdl->words.w0 = 0x07060030;
                    gdl->words.w1 = (u32) ((u8 *) (tex->cmd + 1) + 0x38) + 0x80000000;
                    gdl++;
                }
            }
        }
        sel = 1;
        tbl = D_800A52B0;
    } else {
        tbl = D_800A55B0;
        sel = 0;
    }

    if ((flags & 0x80) && D_800A5840 != 0) {
        flags = (flags & ~0x80) | 4;
    }
    key = flags & ~D_800A5838;
    mode = (key & 0x70) >> 4;

    if (sel != 0) {
        if (tex->unk1B >= 2) {
            mode = ((key & 0x70) >> 4) + 0x20;
            if (key & 0x80) {
                mode += 8;
            }
        } else if (key & 0x80) {
            mode = ((key & 0x70) >> 4) + 8;
        } else if (key & 0x100) {
            mode = ((key & 0x70) >> 4) + 0x10;
        } else if (key & 0x200) {
            mode = ((key & 0x70) >> 4) + 0x18;
        } else {
            mode = (key & 0x70) >> 4;
        }
    } else {
        if (key & 0x400) {
            mode = ((key & 0x70) >> 4) + 8;
        }
    }

    {
        TexDPEntry *ent = &tbl[mode];
        combined = ent->unkC | (key & ent->unk8);
        tmp = ((u32) mode << 8) | combined;
    }

    if (D_800FFA1C != (s32) tmp || (s32) tbl != D_800FFA10) {
        D_800FFA1C = (s32) tmp;
        D_800FFA10 = (s32) tbl;

        gdl->words.w0 = 0xE7000000;
        gdl->words.w1 = 0;
        gdl++;

        if (combined & 2) {
            if (D_800FFA20 == 0) {
                gdl->words.w1 = 1;
                gdl->words.w0 = 0xB7000000;
                gdl++;
            }
            D_800FFA20 = 1;
        } else {
            if (D_800FFA20 != 0) {
                gdl->words.w1 = 1;
                gdl->words.w0 = 0xB6000000;
                gdl++;
            }
            D_800FFA20 = 0;
        }

        if (combined & 8) {
            if (D_800FFA24 == 0) {
                gdl->words.w1 = 0x10000;
                gdl->words.w0 = 0xB7000000;
                gdl++;
            }
            D_800FFA24 = 1;
        } else {
            if (D_800FFA24 != 0) {
                gdl->words.w1 = 0x10000;
                gdl->words.w0 = 0xB6000000;
                gdl++;
            }
            D_800FFA24 = 0;
        }

        /* two Gfx words copied from the table entry */
        {
            TexDPEntry *ent = &tbl[mode];
            Gfx *src0 = (Gfx *) ((u8 *) ent->unk0 + (combined >> 3) * 8);
            Gfx *src1 = (Gfx *) ((u8 *) ent->unk4 + combined * 8);
            gdl->words.w0 = src0->words.w0;
            gdl->words.w1 = src0->words.w1;
            gdl++;
            gdl->words.w0 = src1->words.w0;
            gdl->words.w1 = src1->words.w1;
            gdl++;
        }
    }

    *dlist = gdl;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/textures/texDPTextureX.s")
#endif

void sprSetTextureFilter(s32 arg0) {
    D_800A5834 = arg0;
}

void sprSetIA2ColOverride(u8 arg0, u8 arg1, u8 arg2, u8 arg3, u8 arg4, u8 arg5) {
    D_800FFA28 = arg0;
    D_800FFA29 = arg1;
    D_800FFA2A = arg2;
    D_800FFA2B = arg3;
    D_800FFA2C = arg4;
    D_800FFA2D = arg5;
    D_800A5844 = 1;
}

void sprClearIA2ColOverride(void) {
    D_800A5844 = 0;
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Sprite-side twin of texDPTextureX: same mode table (D_800A56B0) and the same
// RDP mode-state block, followed by per-frame tile texture commands.
typedef struct SpriteDPSrc {
    /* 0x00 */ u8 frameCount;     // animation frames; the frame position wraps modulo this
    /* 0x01 */ u8 loop;           // non-zero: wrap to frame 0 at the end, else hold last frame
    /* 0x02 */ s16 numTextures;   // frameCount * tilesPerFrame entries in frames[]
    /* 0x04 */ s16 unk4;          // not read by sprDPset
    /* 0x06 */ s16 flags;         // 0x40 = multi-tile path
    /* 0x08 */ u8 primR;
    /* 0x09 */ u8 primG;
    /* 0x0A */ u8 primB;
    /* 0x0B */ u8 envR;
    /* 0x0C */ u8 envG;
    /* 0x0D */ u8 envB;
    /* 0x10 */ TextureHeader **frames;
    /* 0x14 */ u8 *tileRecCount;  // Gfx records copied per tile
    /* 0x18 */ u32 unk18;         // [0]: Gfx record list (0x40 path); [frame]: DL pointer (plain path)
} SpriteDPSrc;

void sprDPset(Gfx **dlist, SpriteDPSrc *spr, s32 flags, f32 frameArg, u8 alpha) {
    Gfx *gdl;
    TexDPEntry *tbl;
    TexDPEntry *ent;
    Gfx *src0;
    Gfx *src1;
    Gfx *recs;
    TextureHeader *tex;
    TextureHeader *texNext;
    f32 pos;
    s32 frame;
    s32 nextFrame;
    s32 tilesPerFrame;
    s32 key;
    s32 mode;
    s32 envA;
    s32 combined;
    s32 tmp;
    s32 i;
    s32 j;
    s32 count;

    gdl = *dlist;
    pos = frameArg;
    /* wrap the frame position into [0, frameCount) */
    if ((f32) spr->frameCount <= pos) {
        pos -= (f32) ((s32) (pos / (f32) spr->frameCount) * spr->frameCount);
    } else if (pos < 0.0f) {
        pos = 0.0f;
    }
    frame = (s32) pos;

    key = (flags | spr->flags) & ~D_800A5838;

    mode = 0;
    if (key & 0x40) {
        mode = 1;
        /* fractional part of the position, as a blend alpha */
        envA = (u8) (s32) ((pos - (f32) frame) * 255.0f);
    } else {
        envA = 0xFF;
    }

    switch (key & 0xC000) {
    case 0x4000:
        mode |= 8;
        break;
    case 0x8000:
        mode |= 0x10;
        break;
    }
    if (D_800A5834 == 0) {
        mode |= 2;
    }

    if (key & 0x200) {
        mode |= 4;
        if (D_800A5844 == 0) {
            gdl->words.w0 = 0xFA000000;
            gdl->words.w1 = ((u32) spr->primR << 24) | ((u32) spr->primG << 16) | ((u32) spr->primB << 8) | alpha;
            gdl++;
            gdl->words.w0 = 0xFB000000;
            gdl->words.w1 = ((u32) spr->envR << 24) | ((u32) spr->envG << 16) | ((u32) spr->envB << 8) | envA;
            gdl++;
        } else {
            gdl->words.w0 = 0xFA000000;
            gdl->words.w1 = ((u32) D_800FFA28 << 24) | ((u32) D_800FFA29 << 16) | ((u32) D_800FFA2A << 8) | alpha;
            gdl++;
            gdl->words.w0 = 0xFB000000;
            gdl->words.w1 = ((u32) D_800FFA2B << 24) | ((u32) D_800FFA2C << 16) | ((u32) D_800FFA2D << 8) | envA;
            gdl++;
        }
    } else if (key & 0x40) {
        gdl->words.w0 = 0xFB000000;
        gdl->words.w1 = (envA & 0xFF) | 0xFFFFFF00;
        gdl++;
    }

    tbl = D_800A56B0;
    ent = &tbl[mode];
    combined = ent->unkC | (key & ent->unk8);
    tmp = (mode << 8) | combined;

    if (D_800FFA1C != tmp || (s32) tbl != D_800FFA10) {
        D_800FFA1C = tmp;
        D_800FFA10 = (s32) tbl;

        gdl->words.w0 = 0xE7000000;
        gdl->words.w1 = 0;
        gdl++;

        if (combined & 2) {
            if (D_800FFA20 == 0) {
                gdl->words.w1 = 1;
                gdl->words.w0 = 0xB7000000;
                gdl++;
            }
            D_800FFA20 = 1;
        } else {
            if (D_800FFA20 != 0) {
                gdl->words.w1 = 1;
                gdl->words.w0 = 0xB6000000;
                gdl++;
            }
            D_800FFA20 = 0;
        }

        if (combined & 8) {
            if (D_800FFA24 == 0) {
                gdl->words.w1 = 0x10000;
                gdl->words.w0 = 0xB7000000;
                gdl++;
            }
            D_800FFA24 = 1;
        } else {
            if (D_800FFA24 != 0) {
                gdl->words.w1 = 0x10000;
                gdl->words.w0 = 0xB6000000;
                gdl++;
            }
            D_800FFA24 = 0;
        }

        /* two Gfx words copied from the table entry */
        ent = &tbl[mode];
        src0 = (Gfx *) ((u8 *) ent->unk0 + (combined >> 3) * 8);
        src1 = (Gfx *) ((u8 *) ent->unk4 + combined * 8);
        gdl->words.w0 = src0->words.w0;
        gdl->words.w1 = src0->words.w1;
        gdl++;
        gdl->words.w0 = src1->words.w0;
        gdl->words.w1 = src1->words.w1;
        gdl++;
    }

    D_800FFA14 = 0;
    D_800FFA18 = 0;

    /* first texture of the sprite decides whether a CPU texture copy is needed */
    tex = spr->frames[0];
    if (tex->numberOfInstances != 0) {
        fxCpuTextureRequired(tex->numberOfInstances, tex);
    }

    if (spr->flags & 0x40) {
        tilesPerFrame = (s16) spr->numTextures / (s32) spr->frameCount;
        nextFrame = frame + 1;
        if (nextFrame >= spr->frameCount) {
            nextFrame -= 1;
            if (spr->loop != 0) {
                nextFrame = 0;
            }
        }
        recs = (Gfx *) (u32) spr->unk18;

        if (tilesPerFrame > 0) {
            for (i = 0; i < tilesPerFrame; i++) {
                tex = spr->frames[tilesPerFrame * frame + i];
                texNext = spr->frames[tilesPerFrame * nextFrame + i];
                gdl->words.w0 = 0x07070038;
                gdl->words.w1 = (u32) tex->cmd + 0x80000000;
                gdl++;
                gdl->words.w0 = 0x07070038;
                gdl->words.w1 = (u32) texNext->cmd + 0x80000038;
                gdl++;

                count = spr->tileRecCount[i];
                for (j = 0; j < count; j++) {
                    gdl->words.w0 = recs->words.w0;
                    gdl->words.w1 = recs->words.w1;
                    gdl++;
                    recs++;
                }
            }
        }

        gdl->words.w0 = 0xE7000000;
        gdl->words.w1 = 0;
        gdl++;
    } else {
        gdl->words.w0 = 0x06000000;
        /* per-frame DL pointer stored at 0x18 + frame * 4 */
        gdl->words.w1 = *(u32 *) ((u8 *) spr + 0x18 + frame * 4);
        gdl++;
    }

    if (key & 0x200) {
        gdl->words.w1 = 0xFFFFFFFF;
        gdl->words.w0 = 0xFA000000;
        gdl++;
    }

    *dlist = gdl;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/textures/sprDPset.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
Sprite *texLoadSprite(s32 arg0, s32 arg1) {
    SpriteCacheEntry *cache;
    u8 *hdr;
    Sprite *sprite;
    s32 count;
    s32 i;
    s32 freeIdx;
    s32 newSlot;
    s32 nEntries;
    s32 nFrames;
    s32 n;
    s32 sizeHdr;
    s32 offB;
    s32 offC;
    s32 offC2;
    s32 offD;
    s32 total;
    s32 loadFail;

    D_800FF9FC = arg1;
    if (arg0 < 0 || arg0 >= D_800FF9F4) {
        return NULL;
    }

    /* already cached: bump the instance count */
    cache = (SpriteCacheEntry *) D_800FF9EC;
    count = D_800FF9F8;
    for (i = 0; i < count; i++) {
        if (arg0 == cache[i].id) {
            sprite = cache[i].sprite;
            sprite->numberOfInstances += 1;
            return sprite;
        }
    }

    /* find a free cache slot (the last one with id == -1), else append */
    freeIdx = -1;
    for (i = 0; i < count; i++) {
        if (cache[i].id == -1) {
            freeIdx = i;
        }
    }
    newSlot = 0;
    if (freeIdx == -1) {
        newSlot = 1;
        freeIdx = count;
        D_800FF9F8 = count + 1;
    }

    hdr = (u8 *) D_800FF9F0;
    piRomLoadSection(0x15, (u32) hdr, (s32) D_800FF9E8[arg0], (s32) (D_800FF9E8[arg0 + 1] - D_800FF9E8[arg0]));

    nEntries = *(s16 *) (hdr + 0x2);
    nFrames = hdr[nEntries + 0x14];
    n = (nFrames < nEntries) ? nEntries : nFrames;

    sizeHdr = (s32) mmAlign16((u8 *) (nEntries * 4 + 0x18));
    offB = sizeHdr + n * 2 * 0x10;
    offC = offB + n * 4 * 8 + nEntries * 8;
    offC2 = offC + n * 4;
    offD = offC2 + n * 0x14 * 2;
    total = (s32) mmAlign16((u8 *) (n * 2 + offD));

    /* mmAlloc2 is declared as void in memory.h but returns the block */
    sprite = (Sprite *) ((void *(*)(s32, u32)) mmAlloc2)(total, 0xFF00FFFF);
    if (sprite == NULL) {
        if (newSlot) {
            D_800FF9F8 -= 1;
        }
        return NULL;
    }

    D_800FFA08 = (u8 *) sprite + sizeHdr;
    D_800FFA04 = (s32) ((u8 *) sprite + offB);
    D_800FFA00 = (s32) ((u8 *) sprite + offC2);
    *(u8 **) ((u8 *) sprite + 0x10) = (u8 *) sprite + offC;
    *(u8 **) ((u8 *) sprite + 0x14) = (u8 *) sprite + offD;

    loadFail = 0;
    if (nFrames > 0) {
        for (i = 0; i < nFrames; i++) {
            D_800A5830 = 0xFF0163;
            sprite->frames[i] = texLoadTexture(*(s16 *) hdr + i);
            if (sprite->frames[i] == NULL) {
                loadFail = 1;
            }
            D_800A5830 = 0xFF00FFFF;
            D_800FF9E4 = 1;
        }
    }
    D_800FF9E4 = 0;

    if (loadFail != 0) {
        for (i = 0; i < nFrames; i++) {
            if (sprite->frames[i] != NULL) {
                texFreeTexture(sprite->frames[i]);
            }
        }
        if (newSlot) {
            D_800FF9F8 -= 1;
        }
        mmFree(sprite);
        return NULL;
    }

    sprite->numberOfFrames = (s16) nFrames;
    sprite->pad8[0] = hdr[0x8];
    sprite->pad8[1] = hdr[0x9];
    sprite->pad8[2] = hdr[0xA];
    sprite->pad8[3] = hdr[0xB];
    sprite->pad8[4] = hdr[0xC];
    sprite->pad8[5] = hdr[0xD];
    *(u8 *) sprite = (u8) nEntries;

    if (nEntries > 0) {
        i = 0;
        do {
            *(s32 *) ((u8 *) sprite + 0x18 + i * 4) = D_800FFA04;
            func_800577D8(hdr, sprite, i);
            if (sprite->unk6 & 0x40) {
                i = nEntries;
            }
            i++;
        } while (i < nEntries);
    }

    if (*(s16 *) (hdr + 0xE) & 0x200) {
        sprite->unk6 |= 0x200;
    }

    if (D_800FF9F8 >= 0x64) {
        return NULL;
    }
    cache[freeIdx].id = arg0;
    cache[freeIdx].sprite = sprite;
    sprite->numberOfInstances = 1;
    return sprite;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/textures/texLoadSprite.s")
#endif

#ifdef NON_MATCHING

void texFreeSprite(Sprite *sprite) {
    s32 i;
    s32 frame;
    s32 spriteId;

    if (sprite != 0) {
        sprite->numberOfInstances--;
        if (sprite->numberOfInstances <= 0) {
            for (i = 0; i < D_800FF9F8; i++) {
                if (sprite == D_800FF9EC[i].sprite) {

                    if (D_800FF9EC[i].sprite == 0) {}

                    for (frame = 0; frame < sprite->numberOfFrames; frame++) {
                        texFreeTexture(sprite->frames[frame]);
                    }
                    spriteId = -1;
                    mmFree(sprite);
                    D_800FF9EC[i].id = spriteId;
                    D_800FF9EC[i].sprite = (Sprite *) spriteId;
                    break;
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/textures/texFreeSprite.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_800577D8(u8 *hdr, Sprite *sprite, s32 idx) {
    u8 *ent;
    s32 start;
    s32 end;
    s32 hdrX;
    s32 hdrY;
    s32 dl;
    s32 dlStart;
    u8 *vtx;
    u8 *tri;
    s32 s6;
    s32 t4;
    s32 t5;
    s32 count;
    s32 vaddr;
    s32 quadVtx;
    u8 *lens;

    lens = *(u8 **) ((u8 *) sprite + 0x14);
    ent = hdr + idx;
    start = ent[0x14];
    end = ent[0x15];
    hdrX = *(s16 *) (hdr + 0x4);
    hdrY = *(s16 *) (hdr + 0x6);
    dl = D_800FFA04;
    vtx = (u8 *) D_800FFA00;
    tri = D_800FFA08;
    dlStart = dl;
    s6 = 0;
    t4 = 0;
    t5 = 0;

    if (idx == 0 || start < end) {
        TextureHeader *first = sprite->frames[start];
        *((u8 *) sprite + 1) = first->unk18;
        sprite->unk6 = (s16) (first->flags & 0xC07B);
    }

    while (start < end) {
        TextureHeader *tex = sprite->frames[start];
        s32 w = tex->width;
        s32 h = tex->height;
        s32 x0 = (u8) tex->unk3 - hdrX;
        s32 y0 = hdrY - (u8) tex->unk4;
        s32 yTop = y0 - 1;
        s32 xRight = x0 + w - 1;
        s32 yBot = y0 - h;
        s32 t0_4;
        s32 t2_2;
        s32 t6;
        s32 t9;
        s32 v1_5;

        /* four vertices, 0xA bytes each */
        *(s16 *) (vtx + 0x00) = (s16) x0;
        *(s16 *) (vtx + 0x02) = (s16) yTop;
        *(s16 *) (vtx + 0x04) = 0;
        vtx[0x06] = vtx[0x07] = vtx[0x08] = vtx[0x09] = 0xFF;
        *(s16 *) (vtx + 0x0A) = (s16) xRight;
        *(s16 *) (vtx + 0x0C) = (s16) yTop;
        *(s16 *) (vtx + 0x0E) = 0;
        vtx[0x10] = vtx[0x11] = vtx[0x12] = vtx[0x13] = 0xFF;
        *(s16 *) (vtx + 0x14) = (s16) xRight;
        *(s16 *) (vtx + 0x16) = (s16) yBot;
        *(s16 *) (vtx + 0x18) = 0;
        vtx[0x1A] = vtx[0x1B] = vtx[0x1C] = vtx[0x1D] = 0xFF;
        *(s16 *) (vtx + 0x1E) = (s16) x0;
        *(s16 *) (vtx + 0x20) = (s16) yBot;
        *(s16 *) (vtx + 0x22) = 0;
        vtx[0x24] = vtx[0x25] = vtx[0x26] = vtx[0x27] = 0xFF;
        quadVtx = (s32) vtx;
        vtx += 0x28;

        if (sprite->unk6 & 0x40) {
            if (dl != dlStart) {
                lens[s6] = (s8) ((dl - dlStart) >> 3);
                s6 += 1;
                dlStart = dl;
            }
        } else {
            Gfx *g = (Gfx *) dl;
            s32 nc = tex->numberOfCommands;
            g->words.w0 = ((nc & 0xFF) << 16) | 0x07000000 | ((nc * 8) & 0xFFFF);
            g->words.w1 = (u32) tex->cmd + 0x80000000;
            dl += 8;
        }

        if (t5 == 0) {
            Gfx *g = (Gfx *) dl;
            count = end - start;
            dl += 8;
            if (count >= 6) {
                count = 5;
            }
            vaddr = quadVtx + 0x80000000;
            g->words.w0 = ((((count * 4 * 8) | (vaddr & 6)) & 0xFF) << 16) | 0x04000000
                        | ((((count * 0x28) + 8) | 0x200) & 0xFFFF);
            g->words.w1 = vaddr;
        }

        ((Gfx *) dl)->words.w1 = (u32) tri + 0x80000000;
        ((Gfx *) dl)->words.w0 = 0x05110020;

        t0_4 = t4 + 3;
        t2_2 = t4 + 1;
        t6 = (w - 1) << 5;
        t9 = (h - 1) << 5;
        t5 += 1;
        v1_5 = t4 + 4;
        dl += 8;

        tri[0x00] = 0x40;
        tri[0x01] = (u8) t0_4;
        tri[0x02] = (u8) (t4 + 2);
        tri[0x03] = (u8) t2_2;
        *(s16 *) (tri + 0x04) = (s16) t6;
        *(s16 *) (tri + 0x06) = (s16) t9;
        *(s16 *) (tri + 0x08) = (s16) t6;
        *(s16 *) (tri + 0x0A) = 0;
        *(s16 *) (tri + 0x0C) = 1;
        *(s16 *) (tri + 0x0E) = 0;
        tri[0x10] = 0x40;
        tri[0x11] = (u8) v1_5;
        tri[0x12] = (u8) t0_4;
        tri[0x13] = (u8) t2_2;
        *(s16 *) (tri + 0x14) = 1;
        *(s16 *) (tri + 0x16) = (s16) t9;
        *(s16 *) (tri + 0x18) = (s16) t6;
        *(s16 *) (tri + 0x1A) = (s16) t9;
        *(s16 *) (tri + 0x1C) = 1;
        *(s16 *) (tri + 0x1E) = 0;
        tri += 0x20;

        t4 = v1_5;
        start += 1;
        if (t5 >= 5) {
            t5 = 0;
            t4 = 0;
        }
    }

    if (sprite->unk6 & 0x40) {
        lens[s6] = (s8) ((dl - dlStart) >> 3);
        lens[s6 + 1] = 0;
    }

    ((Gfx *) dl)->words.w0 = 0xE7000000;
    ((Gfx *) dl)->words.w1 = 0;
    ((Gfx *) dl + 1)->words.w0 = 0xB8000000;
    ((Gfx *) dl + 1)->words.w1 = 0;

    D_800FFA04 = dl + 0x10;
    D_800FFA00 = (s32) vtx;
    D_800FFA08 = tri;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/textures/func_800577D8.s")
#endif

// builD_tex_list in DKR
void func_80057B8C(TextureHeader *tex, Gfx *_dlist) {
    Gfx *dlist = _dlist;
    if (tex) {}
    tex->cmd = dlist;
    func_80057C50(&dlist, tex, 0, 0);
    // tex->flags & 0x40 - U clamp flag. Wrap
    if (tex->unk1B < 2 && tex->flags & 0x40) {
        if (!(tex->format & 0xF)) {
            func_80057C50(&dlist, tex, 1, (0x1000 - tex->textureSize) >> 3);
        } else {
            func_80057C50(&dlist, tex, 1, 0x100);
        }
    }
    tex->numberOfCommands = dlist - tex->cmd;
}

// Shrunk builD_tex_list
#if 0 /* old NON_EQUIVALENT attempt */
void func_80057C50(Gfx **dlist, TextureHeader *tex, s32 rtile, s32 tmem) {
    s32 tileImgSiz;
    s32 imgSiz;
    s32 imgSizIncr;
    s32 imgSizShift;
    s32 imgFmt;
    s32 tileLine;
    s32 texFlags;
    s32 line;
    s32 imgSizTileBytes;
    s32 i;
    s32 var_v1;
    u32 texFormat;
    u8 texHeight;
    u8 texWidth;

    texFormat = tex->format & 0xF;
    texFlags = (tex->format >> 4) & 0xF;
    texHeight = tex->height;
    texWidth = tex->width;
    switch (texFormat) {
        case 0:
            tileImgSiz = G_IM_SIZ_32b;
            imgSiz = 3;
            imgSizIncr = G_IM_SIZ_32b_INCR;
            imgSizShift = G_IM_SIZ_32b_SHIFT;
            imgSizTileBytes = G_IM_SIZ_32b_TILE_BYTES;
            break;
        case 1:
        case 4:
            tileImgSiz = G_IM_SIZ_16b;
            imgSiz = 2;
            imgSizIncr = G_IM_SIZ_16b_INCR;
            imgSizShift = G_IM_SIZ_16b_SHIFT;
            imgSizTileBytes = G_IM_SIZ_16b_TILE_BYTES;
            break;
        case 2:
        case 5:
            tileImgSiz = G_IM_SIZ_8b;
            imgSiz = 2;
            imgSizIncr = G_IM_SIZ_8b_INCR;
            imgSizShift = G_IM_SIZ_8b_SHIFT;
            imgSizTileBytes = G_IM_SIZ_8b_TILE_BYTES;
            break;
        default:
            tileImgSiz = G_IM_SIZ_4b;
            imgSiz = 2;
            imgSizIncr = G_IM_SIZ_4b_INCR;
            imgSizShift = G_IM_SIZ_4b_SHIFT;
            imgSizTileBytes = G_IM_SIZ_4b_TILE_BYTES;
            break;
    }
    switch (texFormat) {
        case 0:
        case 1:
            imgFmt = G_IM_FMT_RGBA;
            if ((texFlags == 0) || (texFlags == 2)) {
                tex->flags |= 4;
            }
            break;
        case 4:
        case 5:
        case 6:
            imgFmt = G_IM_FMT_IA;
            tex->flags |= 4;
            break;
        default:
            imgFmt = G_IM_FMT_I;
            break;
    }
    if (tileImgSiz == 0) {
        line = texWidth * 2;
    } else {
        line = texWidth * imgSizTileBytes;
    }
    if (tex->unk1B >= 2) {
        var_v1 = 0;
        for (i = 0; i < tex->unk1B; i++) {
            var_v1 += (texWidth >> i) * (texHeight >> i);
        }
        gDPSetTextureImage((*dlist)++, imgFmt, imgSiz, 1, OS_PHYSICAL_TO_K0(tex + 1));
        // gDPSetTile - Maybe not? arg3 is just using the first 13 bits, 0-12
        gDPSetTile((*dlist)++, imgFmt, imgSiz, 0, tmem & 0x1FF, G_TX_LOADTILE, 0, 0, 0, 0, 0, 0, 0);
        gDPLoadSync((*dlist)++);
        gDPLoadBlock((*dlist)++, G_TX_LOADTILE, 0, 0, (((s32) (var_v1 + imgSizIncr) >> imgSizShift) - 1), 0);
        gDPPipeSync((*dlist)++);
        i = 0;
        while (i < tex->unk1B) {
            tileLine = ((line) + 7) >> 3;
            gDPSetTile((*dlist)++, imgFmt, tileImgSiz, tileLine, tmem & 0x1FF, rtile, 0, tex->unk1E, (tex->unk1F - i),
                       i, tex->unk1C, (tex->isCompressed - i), i);
            gDPSetTileSize((*dlist)++, rtile, 0, 0, ((texWidth) -1) << G_TEXTURE_IMAGE_FRAC,
                           ((texHeight) -1) << G_TEXTURE_IMAGE_FRAC);
            i++;
            tmem += tileLine * texHeight;
            rtile++;
            texWidth = (u8) ((s32) texWidth >> 1);
            texHeight = (u8) ((s32) texHeight >> 1);
            line >>= 1;
        }
        gSPTexture((*dlist)++, 0, 0, (tex->unk1B - 1), 0, 1);
        gSPEndDisplayList((*dlist)++);
    } else {
        gDkrDPLoadMultiBlockS((*dlist)++,                 // pkt
                              OS_PHYSICAL_TO_K0(tex + 1), // timg
                              tmem,                       // tmem
                              rtile,                      // rtile
                              imgFmt,                     // fmt
                              imgSiz,                     // sizblk
                              tileImgSiz,                 // siztile
                              imgSizIncr,                 // sizincr
                              0,                          // sizbytes
                              imgSizShift,                // sizshift
                              line,                       // line
                              texWidth,                   // width
                              texHeight,                  // height
                              0,                          // pal
                              tex->unk1C,                 // cms
                              tex->unk1E,                 // cmt
                              tex->isCompressed,          // masks
                              tex->unk1F,                 // maskt
                              0,                          // shifts
                              0                           // shiftt
        );
        // //gDPLoadTextureBlock
        // {
        //     gDPSetTextureImage((*dlist)++, imgFmt, imgSiz, 1, OS_PHYSICAL_TO_K0(tex + 1));
        //     gDPSetTile((*dlist)++, imgFmt, imgSiz, 0, arg3 & 0x1FF, G_TX_LOADTILE, 0, tex->unk1E, tex->unk1F, 0,
        //     tex->unk1C, tex->isCompressed, 0); gDPLoadSync((*dlist)++); gDPLoadBlock((*dlist)++, G_TX_LOADTILE, 0, 0,
        //     (((s32) ((texWidth * texHeight) + imgSizIncr) >> imgSizShift) - 1), 0); gDPPipeSync((*dlist)++);
        //     gDPSetTile(
        //         (*dlist)++,//pkt
        //         imgFmt,//fmt
        //         tileImgSiz,//siz
        //         (((s32) (line + 7) >> 3) & 0x1FF),//line
        //         (arg3 & 0x1FF),//tmem
        //         arg2,//tile
        //         0,//palette
        //         tex->unk1E,//cmt
        //         tex->unk1F,//maskt
        //         0,//shiftt
        //         tex->unk1C,//cms
        //         tex->isCompressed,//masks
        //         0//shifts
        //     );
        //     gDPSetTileSize(
        //         (*dlist)++,//pkt
        //         arg2,//tile
        //         0,//uls
        //         0,//ult
        //         ((texWidth)-1) << G_TEXTURE_IMAGE_FRAC,//lrs
        //         ((texHeight)-1) << G_TEXTURE_IMAGE_FRAC//lrt
        //     );
        // }
    }
}
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Builds the RDP texture load command list for one tile (rtile) of a texture.
// Writes the RDP words directly as the asm does (no gDP macros); the layout of
// the header fields comes from TextureHeader (include/structs.h) and the
// texture bank notes in jfg-re docs/textures.md. cf. DKR material_init
// (textures_sprites.c) for the same LoadTextureBlock sequence.
void func_80057C50(Gfx **dlist, TextureHeader *tex, s32 rtile, s32 tmem) {
    Gfx *dl;
    s32 texFormat;
    s32 texFlags;
    s32 width;
    s32 height;
    s32 imgFmt;      // asm sp70 (G_IM_FMT: 0 RGBA, 3 IA, 4 I)
    s32 imgSiz;      // asm sp80 (G_IM_SIZ for SETTIMG)
    s32 tileSiz;     // asm sp84 (G_IM_SIZ for SETTILE, 0 = 4b)
    s32 imgSizIncr;  // asm sp7C
    s32 imgSizShift; // asm sp78
    s32 tileBytes;   // first-switch value (bytes per texel, used for line)
    s32 line;
    s32 texelTotal;
    s32 tileLine;
    s32 lrs;
    s32 i;

    texFormat = tex->format & 0xF;
    texFlags = (tex->format >> 4) & 0xF;
    height = tex->height;
    width = tex->width;

    switch (texFormat) {
        case 0:
            tileSiz = 3;
            imgSiz = 3;
            imgSizIncr = 0;
            imgSizShift = 0;
            tileBytes = 2;
            break;
        case 1:
        case 4:
            tileSiz = 2;
            imgSiz = 2;
            imgSizIncr = 0;
            imgSizShift = 0;
            tileBytes = 2;
            break;
        case 2:
        case 5:
            tileSiz = 1;
            imgSiz = 2;
            imgSizIncr = 1;
            imgSizShift = 1;
            tileBytes = 1;
            break;
        default:
            tileSiz = 0;
            imgSiz = 2;
            imgSizIncr = 3;
            imgSizShift = 2;
            tileBytes = 0;
            break;
    }

    switch (texFormat) {
        case 0:
        case 1:
            imgFmt = 0;
            if (texFlags == 0 || texFlags == 2) {
                tex->flags |= 4;
            }
            break;
        case 4:
        case 5:
        case 6:
            imgFmt = 3;
            tex->flags |= 4;
            break;
        default:
            imgFmt = 4;
            break;
    }

    if (tileSiz != 0) {
        line = width * tileBytes;
    } else {
        line = width >> 1;
    }

    dl = *dlist;

    if (tex->unk1B >= 2) {
        // Mip-chain path: one SETTILE/SETTILESIZE pair per level.
        texelTotal = 0;
        for (i = 0; i < tex->unk1B; i++) {
            texelTotal += (width >> i) * (height >> i);
        }

        // G_SETTIMG
        dl->words.w0 = 0xFD000000 | ((imgFmt & 7) << 21) | ((imgSiz & 3) << 19);
        dl->words.w1 = (u32) (tex + 1) + 0x80000000;
        dl++;

        // G_SETTILE (load tile 7, line 0)
        dl->words.w0 = 0xF5000000 | ((imgFmt & 7) << 21) | ((tileSiz & 3) << 19) | (tmem & 0x1FF);
        dl->words.w1 = 0x07000000;
        dl++;

        // G_RDPLOADSYNC
        dl->words.w0 = 0xE6000000;
        dl->words.w1 = 0;
        dl++;

        // G_LOADBLOCK
        lrs = ((texelTotal + imgSizIncr) >> imgSizShift) - 1;
        if (!(lrs < 0x7FF)) {
            lrs = 0x7FF;
        }
        dl->words.w0 = 0xF3000000;
        dl->words.w1 = ((lrs & 0xFFF) << 12) | 0x07000000;
        dl++;

        // G_RDPPIPESYNC
        dl->words.w0 = 0xE7000000;
        dl->words.w1 = 0;
        dl++;

        i = 0;
        do {
            tileLine = (line + 7) >> 3;

            // G_SETTILE (rtile)
            dl->words.w0 = 0xF5000000 | ((imgFmt & 7) << 21) | ((tileSiz & 3) << 19) | ((tileLine & 0x1FF) << 9) |
                           (tmem & 0x1FF);
            dl->words.w1 = ((rtile & 7) << 24) | ((tex->unk1E & 3) << 18) | (((tex->unk1F - i) & 0xF) << 14) |
                           ((i & 0xF) << 10) | ((tex->unk1C & 3) << 8) | (((tex->isCompressed - i) & 0xF) << 4) |
                           (i & 0xF);
            dl++;

            // G_SETTILESIZE (rtile)
            dl->words.w0 = 0xF2000000;
            dl->words.w1 = ((rtile & 7) << 24) | ((((width - 1) << 2) & 0xFFF) << 12) | (((height - 1) << 2) & 0xFFF);
            dl++;

            tmem += tileLine * height;
            rtile++;
            width >>= 1;
            height >>= 1;
            line >>= 1;
            i++;
        } while (i < tex->unk1B);

        // G_TEXTURE (level = unk1B - 1, on)
        dl->words.w0 = 0xBB000001 | ((((tex->unk1B - 1) & 7)) << 11);
        dl->words.w1 = 0;
        dl++;

        // G_ENDDL
        dl->words.w0 = 0xB8000000;
        dl->words.w1 = 0;
        dl++;
    } else {
        // Single-level path: load the whole texture with one LOADBLOCK.
        // G_SETTIMG
        dl->words.w0 = 0xFD000000 | ((imgFmt & 7) << 21) | ((imgSiz & 3) << 19);
        dl->words.w1 = (u32) (tex + 1) + 0x80000000;
        dl++;

        // G_SETTILE (load tile 7, line 0, with cmt/maskt/cms/masks)
        dl->words.w0 = 0xF5000000 | ((imgFmt & 7) << 21) | ((tileSiz & 3) << 19) | (tmem & 0x1FF);
        dl->words.w1 = 0x07000000 | ((tex->unk1E & 3) << 18) | ((tex->unk1F & 0xF) << 14) |
                       ((tex->unk1C & 3) << 8) | ((tex->isCompressed & 0xF) << 4);
        dl++;

        // G_RDPLOADSYNC
        dl->words.w0 = 0xE6000000;
        dl->words.w1 = 0;
        dl++;

        // G_LOADBLOCK
        lrs = ((width * height + imgSizIncr) >> imgSizShift) - 1;
        if (!(lrs < 0x7FF)) {
            lrs = 0x7FF;
        }
        dl->words.w0 = 0xF3000000;
        dl->words.w1 = ((lrs & 0xFFF) << 12) | 0x07000000;
        dl++;

        // G_RDPPIPESYNC
        dl->words.w0 = 0xE7000000;
        dl->words.w1 = 0;
        dl++;

        tileLine = (line + 7) >> 3;

        // G_SETTILE (rtile)
        dl->words.w0 = 0xF5000000 | ((imgFmt & 7) << 21) | ((tileSiz & 3) << 19) | ((tileLine & 0x1FF) << 9) |
                       (tmem & 0x1FF);
        dl->words.w1 = ((rtile & 7) << 24) | ((tex->unk1E & 3) << 18) | ((tex->unk1F & 0xF) << 14) |
                       ((tex->unk1C & 3) << 8) | ((tex->isCompressed & 0xF) << 4);
        dl++;

        // G_SETTILESIZE (rtile)
        dl->words.w0 = 0xF2000000;
        dl->words.w1 = ((rtile & 7) << 24) | ((((width - 1) << 2) & 0xFFF) << 12) | (((height - 1) << 2) & 0xFFF);
        dl++;
    }

    *dlist = dl;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/textures/func_80057C50.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 texAnimateSprite(u8 *arg0, s32 *arg1, s32 arg2, f32 *arg3, s32 arg4) {
    Sprite *sprite;
    TextureHeader *first;
    s32 flags;
    s32 pingPong;
    s32 reverse;
    s32 done;
    f32 cur;
    f32 lo;
    f32 hi;
    f32 pos;
    f32 step;

    sprite = (Sprite *) arg0;
    flags = *arg1;
    if (!(flags & 1)) {
        return 0;
    }

    first = sprite->frames[0];
    cur = *arg3;
    pingPong = flags & 4;
    reverse = flags & 8;
    done = 0;

    if (!(first->flags & 0x40)) {
        if (pingPong) {
            hi = (f32) arg0[0] - 0.5f;
            lo = reverse ? 0.5f : 0.0f;
        } else {
            lo = 0.0f;
            hi = (f32) arg0[0] - 0.01f;
        }
    } else {
        lo = 0.0f;
        if (!pingPong && reverse && first->unk18 != 0) {
            hi = (f32) arg0[0];
        } else {
            hi = (f32) arg0[0] - 1.0f;
        }
    }

    step = (f32) (arg2 * arg4) / 60.0f;

    if (flags & 2) {
        pos = cur - step;
        if (pos < lo) {
            done = 1;
            if (pingPong) {
                if (reverse) {
                    pos = (lo - pos) + lo;
                    *arg1 = flags & ~2;
                } else {
                    pos = lo;
                }
            } else {
                if (reverse) {
                    pos += hi;
                } else {
                    pos = lo;
                }
            }
        }
    } else {
        pos = cur + step;
        if (hi < pos) {
            done = 1;
            if (pingPong) {
                pos = hi - (pos - hi);
                *arg1 = flags | 2;
            } else if (reverse) {
                pos -= hi;
            } else {
                pos = hi;
            }
        }
    }

    *arg3 = pos;
    return done;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/textures/texAnimateSprite.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void texAnimateTexSprite(TextureHeader *tex, s32 *arg1, s32 arg2, f32 *arg3, s32 arg4) {
    TextureHeader *frameTable;
    struct {
        u8 numFrames;          /* 0x00 (sprite byte at 0x24 of the stack frame) */
        u8 pad1[0xF];
        TextureHeader **frames; /* 0x10 */
    } sprite;

    frameTable = tex;
    sprite.numFrames = (u8) (tex->numOfTextures >> 8);
    sprite.frames = &frameTable;
    texAnimateSprite((u8 *) &sprite, arg1, arg2, arg3, arg4);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/textures/texAnimateTexSprite.s")
#endif

void texAnimateTexture(TextureHeader *texture, u32 *triangleBatchInfoFlags, s32 *arg2, s32 updateRate) {
    s32 breakVar;
    u16 *frameAdvanceDelay;
    u8 blink;
    s32 arg2Temp = *arg2;
    s32 flags = *triangleBatchInfoFlags;

    if (flags & BATCH_FLAGS_BIT17) {
        blink = blinkMode;
        if (!(flags & BATCH_FLAGS_BIT18)) {
            if (blink == 0) {
                if (mathRnd(0, 1000) > 985) {
                    flags &= ~BATCH_FLAGS_BIT19;
                    flags |= BATCH_FLAGS_BIT18;
                }
            } else if (blink != 2) {
                flags &= ~BATCH_FLAGS_BIT19;
                flags |= BATCH_FLAGS_BIT18;
            }
        } else if (!(flags & BATCH_FLAGS_BIT19)) {
            arg2Temp += texture->frameAdvanceDelay * updateRate;
            if (arg2Temp >= texture->numOfTextures) {
                if (blink == 3) {
                    arg2Temp = texture->numOfTextures - 1;
                } else {
                    arg2Temp = ((texture->numOfTextures * 2) - arg2Temp) - 1;
                    if (arg2Temp < 0) {
                        arg2Temp = 0;
                        flags &= ~(BATCH_FLAGS_BIT19 | BATCH_FLAGS_BIT18);
                    } else {
                        flags |= BATCH_FLAGS_BIT19;
                    }
                }
            }
        } else {
            arg2Temp -= texture->frameAdvanceDelay * updateRate;
            if (arg2Temp < 0) {
                arg2Temp = 0;
                flags &= ~(BATCH_FLAGS_BIT19 | BATCH_FLAGS_BIT18);
            }
        }
        blinkMode = 0;
    } else if (flags & BATCH_FLAGS_BIT18) {
        if (!(flags & BATCH_FLAGS_BIT19)) {
            arg2Temp += texture->frameAdvanceDelay * updateRate;
        } else {
            // Probably a fake match var, but it works.
            frameAdvanceDelay = &texture->frameAdvanceDelay;
            arg2Temp -= (*frameAdvanceDelay) * updateRate;
        }
        do {
            breakVar = FALSE;
            if (arg2Temp < 0) {
                arg2Temp = -arg2Temp;
                flags &= ~BATCH_FLAGS_BIT19;
                breakVar = TRUE;
            }
            if (arg2Temp >= texture->numOfTextures) {
                arg2Temp = ((texture->numOfTextures * 2) - arg2Temp) - 1;
                flags |= BATCH_FLAGS_BIT19;
                breakVar = TRUE;
            }
        } while (breakVar);
    } else if (!(flags & BATCH_FLAGS_BIT19)) {
        arg2Temp += texture->frameAdvanceDelay * updateRate;
        while (arg2Temp >= texture->numOfTextures) {
            arg2Temp -= texture->numOfTextures;
        }
    } else {
        arg2Temp -= texture->frameAdvanceDelay * updateRate;
        while (arg2Temp < 0) {
            arg2Temp += texture->numOfTextures;
        }
    }
    *arg2 = arg2Temp;
    *triangleBatchInfoFlags = flags;
}

void initColourCycle(unkResetColourCycle *arg0, s32 arg1) {
    arg0->unkC = (unkResetColourCycle *) objGetTable(arg1);
    resetColourCycle(arg0);
}

void resetColourCycle(unkResetColourCycle *arg0) {
    unkResetColourCycle *temp_v0;

    temp_v0 = arg0->unkC;
    arg0->unk0 = 0;
    arg0->unk4 = 0;
    arg0->unk8 = temp_v0->unk8;
    arg0->unk9 = temp_v0->unk9;
    arg0->unkA = temp_v0->unkA;
    arg0->unkB = temp_v0->unkB;
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
typedef struct ColourCycleFrame {
    u8 r;
    u8 g;
    u8 b;
    u8 a;
    s32 time;
} ColourCycleFrame;

typedef struct ColourCycleTable {
    s32 numFrames; /* 0x00 */
    s32 period;    /* 0x04 */
    ColourCycleFrame frames[1]; /* 0x08 */
} ColourCycleTable;

void updateColourCycle(unkResetColourCycle *arg0, s32 arg1) {
    ColourCycleTable *table = (ColourCycleTable *) arg0->unkC;
    ColourCycleFrame *cur;
    ColourCycleFrame *next;
    s32 time;
    s32 idx;
    s32 nextIdx;
    s32 lerp;

    if (table->numFrames >= 2) {
        time = arg0->unk4 + arg1;
        arg0->unk4 = time;
        if (time >= table->period) {
            do {
                time -= table->period;
                arg0->unk4 = time;
            } while (time - table->period >= table->period);
        }

        idx = arg0->unk0;
        while (time >= table->frames[idx].time) {
            time -= table->frames[idx].time;
            idx++;
            if (idx >= table->numFrames) {
                idx = 0;
            }
        }
        arg0->unk4 = time;
        arg0->unk0 = idx;

        nextIdx = idx + 1;
        if (nextIdx >= table->numFrames) {
            nextIdx = 0;
        }
        cur = &table->frames[idx];
        next = &table->frames[nextIdx];
        lerp = (time << 16) / cur->time;

        arg0->unk8 = (u8) ((((u32) ((next->r - cur->r) * lerp)) >> 16) + cur->r);
        arg0->unk9 = (u8) ((((u32) ((next->g - cur->g) * lerp)) >> 16) + cur->g);
        arg0->unkA = (u8) ((((u32) ((next->b - cur->b) * lerp)) >> 16) + cur->b);
        arg0->unkB = (u8) ((((u32) ((next->a - cur->a) * lerp)) >> 16) + cur->a);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/textures/updateColourCycle.s")
#endif

void resetMixCycle(PulsatingLightData *data) {
    s32 i;
    data->currentFrame = 0;
    data->time = 0;
    data->totalTime = 0;
    data->outColorValue = data->frames[0].value;
    for (i = 0; i < data->numberFrames; i++) {
        data->totalTime += data->frames[i].time;
    }
}

void updateMixCycle(PulsatingLightData *data, s32 timeDelta) {
    s32 thisFrameIndex, nextFrameIndex;

    if (data->numberFrames > 1) {
        data->time += timeDelta;
        while (data->time >= data->totalTime) {
            data->time -= data->totalTime;
        }
        while (data->time >= data->frames[data->currentFrame].time) {
            data->time -= data->frames[data->currentFrame].time;
            data->currentFrame++;
            if (data->currentFrame >= data->numberFrames) {
                data->currentFrame = 0;
            }
        }
        thisFrameIndex = data->currentFrame;
        nextFrameIndex = thisFrameIndex + 1;
        if (nextFrameIndex >= data->numberFrames) {
            nextFrameIndex = 0;
        }

        data->outColorValue = data->frames[thisFrameIndex].value +
                              ((data->frames[nextFrameIndex].value * data->time) / data->frames[thisFrameIndex].time);
    }
}
