#include "common.h"

/* decomp: externs */
typedef struct ModelSlotEntry {
    s32 key;
    void *ptr;
} ModelSlotEntry;

// memory.h declares mmAlloc2 as void, but the asm uses its return value.
typedef void *(*ModAllocPtrFn)(s32 size, u32 colourTag);
#define MODEL_ALLOC(size, tag) (((ModAllocPtrFn) mmAlloc2)((size), (tag)))

extern u32 *D_800F6F10_B1750;
extern ModelSlotEntry *D_800F6F14_B1754;
extern s32 *D_800F6F18_B1758;
extern s32 D_800F6F1C_B175C;
extern s32 D_800F6F20_B1760;
extern s32 D_800F6F24_B1764;
extern u8 *D_800F6F28_B1768;
extern u8 *D_800F6F2C_B176C;
extern ModelSlotEntry *D_800F6F30_B1770;
extern u8 *D_800F6F34_B1774;
extern u8 *D_800F6F38_B1778;
extern void *D_800F6F3C_B177C;
extern s32 D_800F6F40_B1780;
extern void *D_800F6F58_B1798;
extern s32 D_800F6F54_B1794;
extern s32 D_800A2EC0_A3AC0;
extern u8 D_800A2EC4_A3AC4;
extern u8 antsasmrpants;
extern s8 D_800A5840;
extern s8 D_800F6F48_B1788[3];
extern s16 D_800F6F4C_B178C[3];
extern s32 D_800F6F44_B1784;
extern s16 D_800A2ECC_A3ACC;
extern void *D_800A2EC8_A3AC8;
void texLoadTextureAddr(s32 arg0, s32 arg1);
u8 *texGetTextureNum(s32 arg0);

s32 rzipUncompressSizeROM(s32 assetIndex, s32 assetOffset);
void texFreeTexture(void *tex);
s32 makeModelGfx(void *dst, void *hdr, s32 a, s32 b, s32 start, s32 end, s32 c);
s32 func_8003B640(void *src, void *dst, s32 size);
void *func_8003BED0(void *hdr);
void *func_8003BF58(void *hdr, s32 arg1);
void func_8003BE68(s32 count, void *dst);
void func_8003C6D0(void *hdr);
s32 func_8003C8A8(void *hdr, s32 modelNo);
void texModelTextureLoad(s32 on);
void texDPTextureX(Gfx **dl, void *tex, s32 rtile, s32 tmem);
void func_8003E100(void);
void func_8003E13C(Gfx **dl, s8 *ids, s8 *out, void *hdr, s32 segIdx, s32 mode);
void func_8003CB50(void *inst);
void *func_8003CCC8(s32 arg0);
u8 *func_8003CD70(s16 animId);
void modFreeAnim(void *anim);
void mathTranslateMtx(void *mtx, f32 x, f32 y, f32 z);
void matrixYaw(s16 angle, void *mtx);
void matrixRoll(s16 angle, void *mtx);
void matrixPitch(s16 angle, void *mtx);
void texDPInit(Gfx **dl);
void matrixScale(f32 x, f32 y, f32 z, void *mtx);
void matrix_SCL_RPY_XYZ(void *obj, void *mtx, void *ext);
void mathTransY(void *mtx, f32 y);
void mathSquashY(void *mtx, f32 y);
void camConvertMatrixList(void *mtx, s32 count);
s32 mainGetPauseMode(void);
void *controlPlayerTiltList(void *obj);
void *controlSidekickTiltList(void *obj);
void *mizarTiltList(void *obj);
void *multiCharArmGetTiltList(void *obj);
void *frontMenuPodiumGetTiltList(void *obj);
void *frontMultiStatsBarGetTiltList(void);
void *frontKeyboardGetTiltList(void);
void *GetBaddyData(void);
void *osCic6105SendData(void *obj);
void gen_anim_data(void **out, void *mtx, void *dst, void *src, s32 count, void *tilt);

const char D_800AC900[] = "Error: Model no. out of range on load. !!\n";
const char D_800AC92C[] = "TEXTURE ERROR!!\n%d,%d\n";
const char D_800AC944[] = "Error: Model table overflow!!\n";
const char D_800AC964[] = "CREATE LOD MODEL :: null model pointer!";
const char D_800AC98C[] = "WARNING :: createModelInstance called with NULL pointer\n";
const char D_800AC9C8[] = "MODELS Error: Tryed to deallocate non-existent model!\n";
const char D_800ACA00[] = "MODELS Error : cannot free NULL model instance pointer!!\n";
const char D_800ACA3C[] = "modLoadAnim: Overflowed AnimTab!\n";
const char D_800ACA60[] = "modFreeAnim : NULL anim!!\n";
const char D_800ACA7C[] = "Anim Error: Tryed to deallocate non-existent anim!!\n";
const char D_800ACAB4[] = "modLoadAnimEvent: Overflowed AnimEventTab!\n";
const char D_800ACAE0[] = "modFreeAnimEvents : NULL anim event table!!\n";
const char D_800ACB10[] = "Anim Event Error: Tryed to deallocate non-existent anim event!\n";

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_8003B640(void *src, void *dst, s32 size) {
    u16 *s = src;
    u16 *d = dst;
    s32 count = (size + 1) >> 1;
    s32 i;

    for (i = 0; i < count; i++) {
        d[i] = s[i];
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/models/func_8003B640.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void modInitModels(void) {
    u32 *table;
    s32 i;
    s32 last;
    u8 *buf;

    D_800F6F14_B1754 = (ModelSlotEntry *) mmAlloc(0x2A8, 0xFF00FFU);
    D_800F6F18_B1758 = (s32 *) mmAlloc(0x190, 0xFF00FFU);
    D_800F6F1C_B175C = 0;
    D_800F6F24_B1764 = 0;
    D_800F6F58_B1798 = (void *) mmAlloc(0x2000, 0xFF00FFU);
    table = piRomLoad(0x26U);
    D_800F6F10_B1750 = table;
    D_800F6F20_B1760 = 0;
    last = 0;
    if (table[0] != -1U) {
        i = 1;
        do {
            D_800F6F20_B1760 = i;
            last = i;
            i = last + 1;
        } while (table[i] != -1U);
    }
    D_800F6F20_B1760 = last - 1;
    buf = (u8 *) mmAlloc(0xA0, 0xFF00FFU);
    D_800F6F28_B1768 = buf;
    D_800F6F2C_B176C = buf + 0x80;
    D_800F6F38_B1778 = buf + 0x80;
    D_800F6F34_B1774 = buf + 0x90;
    D_800F6F30_B1770 = (ModelSlotEntry *) mmAlloc(0x800, 0xFF00FFU);
    D_800F6F3C_B177C = (void *) mmAlloc(0x100, 0xFF00FFU);
    D_800F6F40_B1780 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/models/modInitModels.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Rebases a stored offset in the model header into an absolute pointer.
static void modRebasePtr(u8 *hdr, s32 off) {
    s32 value = *(s32 *) (hdr + off);
    *(u8 **) (hdr + off) = hdr + value;
}

void *modLoadModel(s32 arg0, s32 arg1) {
    s32 flag;
    s32 modelNo;
    s32 i;
    s32 j;
    s32 slot;
    s32 fromFreeList;
    s32 newSlot;
    s32 romStart;
    s32 romSize;
    s32 bufSize;
    s32 count;
    s32 prevEnd;
    s32 end;
    s32 n;
    s16 cnt16;
    u8 *hdr;
    u8 *comp;
    u8 *inst;
    u8 *ent;
    u8 *rec;
    u8 b;
    void *tex;

    flag = arg0 & 0x8000;
    modelNo = arg0 ^ flag;
    if (modelNo >= D_800F6F20_B1760) {
        modelNo = 0;
    }
    if (antsasmrpants != 0) {
        if (modelNo == 0x1BD) {
            modelNo = 0x383;
        }
        if (modelNo == 0x1BE) {
            modelNo = 0x384;
        }
    }

    // Already loaded: hand out another instance.
    for (i = 0; i < D_800F6F1C_B175C; i++) {
        if (modelNo == D_800F6F14_B1754[i].key) {
            hdr = D_800F6F14_B1754[i].ptr;
            if (flag != 0) {
                inst = func_8003BED0(hdr);
            } else {
                inst = func_8003BF58(hdr, arg1 & 3);
            }
            if (inst != NULL) {
                *(s16 *) (hdr + 0x4C) = (s16) (*(s16 *) (hdr + 0x4C) + 1);
                if (flag == 0) {
                    func_8003CB50(inst);
                }
            }
            return inst;
        }
    }

    fromFreeList = 0;
    newSlot = 0;
    if (D_800F6F24_B1764 > 0) {
        D_800F6F24_B1764 -= 1;
        slot = D_800F6F18_B1758[D_800F6F24_B1764];
        fromFreeList = 1;
    } else {
        slot = D_800F6F1C_B175C;
        newSlot = 1;
        D_800F6F1C_B175C += 1;
    }

    romStart = D_800F6F10_B1750[modelNo];
    romSize = D_800F6F10_B1750[modelNo + 1] - romStart;
    bufSize = rzipUncompressSizeROM(0x27, romStart) + 0x80;
    hdr = MODEL_ALLOC(bufSize, 0xFF0000FFU);
    if (hdr == NULL) {
        if (fromFreeList) {
            D_800F6F24_B1764 += 1;
        }
        if (newSlot) {
            D_800F6F1C_B175C -= 1;
        }
        return NULL;
    }
    comp = hdr + bufSize - romSize;
    piRomLoadSection(0x27U, (u32) comp, romStart, romSize);
    rzipUncompress(comp, hdr);

    count = *(s32 *) (hdr + 0x7C);
    if (count != 0) {
        *(u8 **) (hdr + 0x84) = MODEL_ALLOC(count * 4 + 4, 0xFF0000FFU);
        if (*(u8 **) (hdr + 0x84) == NULL) {
            if (fromFreeList) {
                D_800F6F24_B1764 += 1;
            }
            if (newSlot) {
                D_800F6F1C_B175C -= 1;
            }
            return NULL;
        }
    } else {
        *(u8 **) (hdr + 0x84) = NULL;
    }

    modRebasePtr(hdr, 0x18);
    modRebasePtr(hdr, 0x1C);
    modRebasePtr(hdr, 0x20);
    modRebasePtr(hdr, 0x24);
    modRebasePtr(hdr, 0x80);
    modRebasePtr(hdr, 0x30);
    modRebasePtr(hdr, 0x34);
    modRebasePtr(hdr, 0x38);
    modRebasePtr(hdr, 0x6C);
    if (*(s32 *) (hdr + 0x70) != 0) {
        modRebasePtr(hdr, 0x70);
    }
    if (*(s32 *) (hdr + 0x54) != 0) {
        modRebasePtr(hdr, 0x54);
    }
    *(s32 *) (hdr + 0x58) = 0;
    modRebasePtr(hdr, 0x68);
    *(s16 *) (hdr + 0x4C) = 1;
    *(s8 *) (hdr + 0x4E) = 0;
    *(void **) (hdr + 0x60) = NULL;
    *(void **) (hdr + 0x50) = NULL;
    *(void **) (hdr + 0x28) = NULL;
    *(void **) (hdr + 0x74) = NULL;
    *(void **) (hdr + 0x78) = NULL;

    // Load and validate the textures referenced by the header.
    count = *(u8 *) (hdr + 0x10);
    for (i = 0; i < count; i++) {
        ent = *(u8 **) (hdr + 0x18) + i * 8;
        tex = texLoadTexture(*(s16 *) (ent + 6));
        *(void **) ent = tex;
        if (tex == NULL) {
            for (j = 0; j < i; j++) {
                texFreeTexture(*(void **) (*(u8 **) (hdr + 0x18) + j * 8));
                *(void **) (*(u8 **) (hdr + 0x18) + j * 8) = NULL;
            }
            for (j = i; j < count; j++) {
                *(void **) (*(u8 **) (hdr + 0x18) + j * 8) = NULL;
            }
            goto failed;
        }
    }

    cnt16 = *(s16 *) (hdr + 0x16);
    if (cnt16 > 0) {
        rec = *(u8 **) (hdr + 0x24);
        for (n = 0; n < cnt16; n++) {
            b = *rec;
            if (!(b == 0xFF || (s32) b < (s32) *(u8 *) (hdr + 0x10))) {
                goto failed;
            }
            rec += 0x10;
        }
    }

    if (func_8003C8A8(hdr, modelNo) != 0) {
        goto failed;
    }
    if (*(u8 *) (hdr + 0x11) != 0) {
        *(u8 **) (hdr + 0x28) = MODEL_ALLOC(*(u8 *) (hdr + 0x10) * 8, 0xFF0000FFU);
        if (*(u8 **) (hdr + 0x28) == NULL) {
            goto failed;
        }
    }

    count = *(s32 *) (hdr + 0x7C);
    if (count != 0) {
        prevEnd = 0;
        i = 0;
        if (count > 0) {
            for (i = 0; i < count; i++) {
                end = *(*(u8 **) (hdr + 0x80) + i) - 1;
                makeModelGfx(*(u8 **) (hdr + 0x84) + i * 4, hdr, 0, 0, prevEnd, end, 0);
                prevEnd = end + 1;
            }
        }
        makeModelGfx(*(u8 **) (hdr + 0x84) + i * 4, hdr, 0, 0, prevEnd, 0xFF, 0);
        goto build_done;
    }

    *(s8 *) (hdr + 0x2C) = makeModelGfx(hdr + 0x74, hdr, 0, 0, 0, 0xFF, 0);
    if (*(s32 *) (hdr + 0x74) == 0) {
        goto failed;
    }
    makeModelGfx(hdr + 0x78, hdr, 4, 0, 0, 0xFF, 0);
    if (*(s32 *) (hdr + 0x78) == 0) {
        goto failed;
    }

build_done:
    if (flag != 0) {
        inst = func_8003BED0(hdr);
    } else {
        inst = func_8003BF58(hdr, arg1 & 3);
    }
    if (inst == NULL) {
        goto failed;
    }
    if (flag == 0) {
        func_8003CB50(inst);
    }
    D_800F6F14_B1754[slot].key = modelNo;
    D_800F6F14_B1754[slot].ptr = hdr;
    if (D_800F6F1C_B175C < 0x55) {
        return inst;
    }

failed:
    if (newSlot) {
        D_800F6F1C_B175C -= 1;
    }
    if (fromFreeList) {
        D_800F6F24_B1764 += 1;
    }
    func_8003C6D0(hdr);
    return NULL;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/models/modLoadModel.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8003BE68(s32 count, void *dst) {
    f32 *m = dst;
    s32 i;

    for (i = 0; i < count; i++) {
        m[0] = 1.0f;
        m[1] = 0.0f;
        m[2] = 0.0f;
        m[3] = 0.0f;
        m[4] = 0.0f;
        m[5] = 1.0f;
        m[6] = 0.0f;
        m[7] = 0.0f;
        m[8] = 0.0f;
        m[9] = 0.0f;
        m[10] = 1.0f;
        m[11] = 0.0f;
        m[12] = 0.0f;
        m[13] = 0.0f;
        m[14] = 0.0f;
        m[15] = 1.0f;
        m += 16;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/models/func_8003BE68.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_8003BED0(void *arg0) {
    u8 *hdr = arg0;
    u8 *inst;
    s32 n = *(s16 *) (hdr + 0x12) * 10;

    inst = MODEL_ALLOC(n + 0x10, 0xFFFFU);
    if (inst != NULL) {
        *(void **) (inst + 0x00) = hdr;
        *(u8 **) (inst + 0x04) = inst + 0x10;
        inst[0x0A] = 2;
        inst[0x0B] = 0;
        *(s32 *) (inst + 0x0C) = 0;
        func_8003B640(*(void **) (hdr + 0x1C), inst + 0x10, n);
    }
    return inst;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/models/func_8003BED0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_8003BF58(void *arg0, s32 arg1) {
    u8 *hdr = arg0;
    u8 *inst;
    s32 v1 = 0;
    s32 v0 = 0;
    s32 a3;
    s32 t2;
    s32 t4;
    s32 t5;
    s32 lo;
    s32 a2;
    s32 total;
    s32 i;
    s32 j;
    s32 b;
    s32 k;
    s32 cnt;
    s32 idx;
    s32 ptrVal;
    u8 *p74;
    u8 *d;
    u8 *dst;
    u8 *src;
    u8 *dst68;
    s16 *vtx;
    f32 *o;

    if (*(s8 *) (hdr + 0x4E) != 0) {
        v1 = *(s8 *) (hdr + 0x4F) << 6;
    }
    a3 = *(s16 *) (hdr + 0x12) * 10;
    if (a3 & 7) {
        a3 = (a3 - (a3 & 7)) + 8;
    }
    t2 = hdr[0x2E] * 12;
    if (t2 & 3) {
        t2 = (t2 - (t2 & 3)) + 4;
    }
    t4 = hdr[0x2F] * 12;
    if (t4 & 3) {
        t4 = (t4 - (t4 & 3)) + 4;
    }
    t5 = hdr[0x2D] * 12;
    if (t5 & 3) {
        t5 = (t5 - (t5 & 3)) + 4;
    }
    if (hdr[0x11] != 0) {
        v0 = (hdr[0x10] * 8) + 0xA8;
    }
    lo = a3 * arg1;
    a2 = v1 * 2;
    total = a2 + lo + t2 + t4 + t5 + v0 + 0x98;

    inst = MODEL_ALLOC(total, 0xFFFFU);
    if (inst == NULL) {
        return NULL;
    }

    if (*(s8 *) (hdr + 0x4F) != 0 && v1 != 0) {
        *(u8 **) (inst + 0x10) = inst + 0x98;
        *(u8 **) (inst + 0x14) = inst + 0x98 + v1;
        func_8003BE68(*(s8 *) (hdr + 0x4F), inst + 0x98);
        func_8003BE68(*(s8 *) (hdr + 0x4F), *(u8 **) (inst + 0x14));
    } else {
        *(u8 **) (inst + 0x10) = NULL;
        *(u8 **) (inst + 0x14) = NULL;
    }

    if (arg1 > 0) {
        *(u8 **) (inst + 0x18) = inst + a2 + 0x98;
    } else {
        *(u8 **) (inst + 0x18) = *(u8 **) (hdr + 0x1C);
    }
    if (arg1 >= 2) {
        *(u8 **) (inst + 0x1C) = *(u8 **) (inst + 0x18) + a3;
    } else {
        *(u8 **) (inst + 0x1C) = *(u8 **) (inst + 0x18);
    }
    *(u8 **) (inst + 0x6C) = (hdr[0x2E] != 0) ? inst + a2 + lo + 0x98 : NULL;
    *(u8 **) (inst + 0x70) = (hdr[0x2F] != 0) ? inst + a2 + lo + t2 + 0x98 : NULL;
    *(u8 **) (inst + 0x68) = (hdr[0x2D] != 0) ? inst + a2 + lo + t2 + t4 + 0x98 : NULL;

    if (hdr[0x11] != 0) {
        p74 = inst + a2 + lo + t2 + t4 + t5 + 0x98;
        *(u8 **) (inst + 0x74) = p74;
        d = p74 + hdr[0x10] * 8;
        ptrVal = (s32) d;
        if (ptrVal & 7) {
            ptrVal = (ptrVal - (ptrVal & 7)) + 8;
        }
        d = (u8 *) ptrVal;
        *(u8 **) (inst + 0x78) = d;
        *(u8 **) (inst + 0x7C) = d + 0x50;
        for (k = 0; k < 2; k++) {
            for (j = 0; j < 0x50; j += 8) {
                s16 *zp = (s16 *) (*(u8 **) (inst + 0x78 + k * 4) + j);

                zp[0] = 0;
                zp[1] = 0;
                zp[2] = 0;
                zp[3] = 0;
            }
        }
    } else {
        *(u8 **) (inst + 0x74) = NULL;
        *(u8 **) (inst + 0x78) = NULL;
        *(u8 **) (inst + 0x7C) = NULL;
    }

    for (i = 0; i < arg1; i++) {
        dst = *(u8 **) (inst + 0x18 + i * 4);
        src = *(u8 **) (hdr + 0x1C);
        cnt = *(s16 *) (hdr + 0x12);
        for (j = 0; j < cnt; j++) {
            *(s16 *) (dst + j * 10 + 0) = *(s16 *) (src + j * 10 + 0);
            *(s16 *) (dst + j * 10 + 2) = *(s16 *) (src + j * 10 + 2);
            *(s16 *) (dst + j * 10 + 4) = *(s16 *) (src + j * 10 + 4);
            dst[j * 10 + 6] = src[j * 10 + 6];
            dst[j * 10 + 7] = src[j * 10 + 7];
            dst[j * 10 + 8] = src[j * 10 + 8];
            dst[j * 10 + 9] = src[j * 10 + 9];
        }
    }

    if (*(s8 *) (hdr + 0x4E) == 0) {
        dst68 = *(u8 **) (inst + 0x68);
        cnt = hdr[0x2D];
        for (i = 0; i < cnt; i++) {
            idx = *(u16 *) (*(u8 **) (hdr + 0x30) + i * 4);
            vtx = (s16 *) (*(u8 **) (hdr + 0x1C) + idx * 10);
            o = (f32 *) (dst68 + i * 12);
            o[0] = (f32) vtx[0];
            o[1] = (f32) vtx[1];
            o[2] = (f32) vtx[2];
        }
    } else {
        for (k = 2; k != 0; k--) {
            if (k == 2) {
                cnt = hdr[0x2D];
                dst68 = *(u8 **) (inst + 0x68);
            } else {
                cnt = hdr[0x2E];
                dst68 = *(u8 **) (inst + 0x6C);
            }
            for (i = 0; i < cnt; i++) {
                o = (f32 *) (dst68 + i * 12);
                o[0] = 0.0f;
                o[1] = 0.0f;
                o[2] = 0.0f;
            }
        }
    }

    if (*(u8 **) (inst + 0x74) != NULL) {
        cnt = hdr[0x10];
        for (i = 0; i < cnt; i++) {
            u8 *dd = *(u8 **) (inst + 0x74) + i * 8;
            u8 *ss = *(u8 **) (hdr + 0x28) + i * 8;
            *(s16 *) (dd + 0) = *(s16 *) (ss + 0);
            *(s16 *) (dd + 2) = *(s16 *) (ss + 2);
            *(s32 *) (dd + 4) = *(s32 *) (ss + 4);
        }
    }

    for (i = 0; i < 17; i++) {
        *(s32 *) (inst + 0x20 + i * 4) = 0;
    }

    *(void **) (inst + 0x00) = hdr;
    inst[0x08] = 0;
    inst[0x0B] = 0;
    *(s32 *) (inst + 0x0C) = 0;
    inst[0x0A] = 2;
    *(s16 *) (inst + 0x24) = 0;
    *(f32 *) (inst + 0x38) = 0.0f;
    *(f32 *) (inst + 0x28) = 0.0f;
    *(u8 **) (inst + 0x04) = *(u8 **) (inst + 0x18);

    func_8003B640(hdr + 0x3C, inst + 0x8C, 0xC);
    return inst;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/models/func_8003BF58.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void modFreeModel(void *arg0) {
    u8 *inst = arg0;
    u8 *hdr;
    u8 *anim;
    s32 i;
    s32 k;
    s32 idx;

    if (inst != NULL) {
        hdr = *(u8 **) (inst + 0x00);
        if (*(u8 **) (inst + 0x0C) != NULL) {
            mmFree(*(u8 **) (inst + 0x0C));
        }
        if (*(u8 *) (hdr + 0x64) != 0) {
            for (k = 0; k < 2; k++) {
                anim = *(u8 **) (inst + 0x80 + k * 4);
                if (anim != NULL) {
                    modFreeAnim(anim);
                }
            }
        }
        mmFree(inst);
        *(s16 *) (hdr + 0x4C) = (s16) (*(s16 *) (hdr + 0x4C) - 1);
        if (*(s16 *) (hdr + 0x4C) <= 0) {
            idx = -1;
            for (i = 0; i < D_800F6F1C_B175C; i++) {
                if (hdr == D_800F6F14_B1754[i].ptr) {
                    idx = i;
                }
            }
            if (idx != -1) {
                func_8003C6D0(hdr);
                D_800F6F18_B1758[D_800F6F24_B1764] = idx;
                D_800F6F24_B1764 += 1;
                D_800F6F14_B1754[idx].key = -1;
                D_800F6F14_B1754[idx].ptr = (void *) -1;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/models/modFreeModel.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8003C6D0(void *arg0) {
    u8 *hdr = arg0;
    s32 i;
    s32 count;
    s32 s;
    s32 idx;
    void *tex;

    count = *(u8 *) (hdr + 0x10);
    for (i = 0; i < count; i++) {
        tex = *(void **) (*(u8 **) (hdr + 0x18) + i * 8);
        if (tex != NULL) {
            texFreeTexture(tex);
        }
    }
    if (*(u8 **) (hdr + 0x60) != NULL) {
        mmFree(*(u8 **) (hdr + 0x60));
    }
    if (*(u8 **) (hdr + 0x28) != NULL) {
        mmFree(*(u8 **) (hdr + 0x28));
    }
    if (*(u8 **) (hdr + 0x74) != NULL) {
        mmFree(*(u8 **) (hdr + 0x74));
    }
    if (*(u8 **) (hdr + 0x78) != NULL) {
        mmFree(*(u8 **) (hdr + 0x78));
    }
    if (*(s8 *) (hdr + 0x4E) != 0) {
        if (*(u8 *) (hdr + 0x64) == 0) {
            if (*(u8 **) (hdr + 0x50) != NULL) {
                s = 0;
                for (idx = 0; idx < *(s8 *) (hdr + 0x4E); idx++) {
                    modFreeAnim(*(void **) (*(u8 **) (hdr + 0x50) + idx * 4));
                    s += 1;
                }
                mmFree(*(u8 **) (hdr + 0x50));
            }
        }
        if (*(u8 **) (hdr + 0x5C) != NULL) {
            mmFree(*(u8 **) (hdr + 0x5C));
        }
        mmFree(*(u8 **) (hdr + 0x58));
    }
    if (*(u8 **) (hdr + 0x84) != NULL) {
        s32 k = *(s32 *) (hdr + 0x7C);
        s32 off = k * 4;
        do {
            mmFree(*(void **) (*(u8 **) (hdr + 0x84) + off));
            off -= 4;
            k -= 1;
        } while (k != 0);
        mmFree(*(u8 **) (hdr + 0x84));
    }
    mmFree(hdr);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/models/func_8003C6D0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_8003C8A8(void *arg0, s32 arg1) {
    u8 *hdr = arg0;
    u16 *tab; /* asm: lhu */
    s32 t1;
    s32 t2;
    s32 s0;
    s32 a3;
    s32 s1;
    s32 off;
    s32 s2;
    s32 v;
    void *anim;

    piRomLoadSection(0x28U, (u32) D_800F6F2C_B176C, (arg1 & ~3) * 2, 0x10);
    tab = (u16 *) (D_800F6F2C_B176C + ((arg1 & 3) * 2));
    t1 = tab[0] >> 1;
    t2 = tab[1] >> 1;
    *(s8 *) (hdr + 0x4E) = (s8) (t2 - t1);
    if (t1 == t2) {
        return 0;
    }

    s0 = t1 & 3;
    a3 = ((*(s8 *) (hdr + 0x4E) & ~3) + 4) * 2;
    if (s0 != 0) {
        a3 += 8;
    }
    piRomLoadSection(0x29U, (u32) D_800F6F28_B1768, (t1 & ~3) * 2, a3);

    *(void **) (hdr + 0x58) = func_8003CCC8(arg1);
    if (*(void **) (hdr + 0x58) == NULL) {
        return 1;
    }
    if (*(u8 *) (hdr + 0x64) == 0) {
        *(void **) (hdr + 0x50) = MODEL_ALLOC(*(s8 *) (hdr + 0x4E) * 4, 0xFF0000FFU);
    }
    *(void **) (hdr + 0x5C) = MODEL_ALLOC(*(s8 *) (hdr + 0x4E) * 2, 0xFF0000FFU);

    if (*(u8 *) (hdr + 0x64) == 0) {
        s1 = 0;
        off = s0 * 2;
        s2 = 0;
        if (*(u8 **) (hdr + 0x50) == NULL) {
            mmFree(*(void **) (hdr + 0x58));
            return 1;
        }
        do {
            anim = func_8003CD70(*(s16 *) (D_800F6F28_B1768 + off));
            *(void **) (*(u8 **) (hdr + 0x50) + s2) = anim;
            s2 += 4;
            if (anim == NULL) {
                s32 k = 0;
                s32 s2b = 0;
                if (s1 > 0) {
                    do {
                        modFreeAnim(*(void **) (*(u8 **) (hdr + 0x50) + s2b));
                        k += 1;
                        s2b += 4;
                    } while (k != s1);
                }
                mmFree(*(void **) (hdr + 0x50));
                mmFree(*(void **) (hdr + 0x58));
                mmFree(*(void **) (hdr + 0x5C));
                *(void **) (hdr + 0x50) = NULL;
                return 1;
            }
            *(s16 *) (*(u8 **) (hdr + 0x5C) + s1 * 2) = *(s16 *) (D_800F6F28_B1768 + off);
            s1 += 1;
            off += 2;
        } while (s1 < *(s8 *) (hdr + 0x4E));
        return 0;
    }

    s1 = 0;
    off = s0 * 2;
    if (*(s8 *) (hdr + 0x4E) > 0) {
        v = 0;
        do {
            *(s16 *) (*(u8 **) (hdr + 0x5C) + v) = *(s16 *) (D_800F6F28_B1768 + off);
            s1 += 1;
            v += 2;
            off += 2;
        } while (s1 < *(s8 *) (hdr + 0x4E));
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/models/func_8003C8A8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8003CB50(void *arg0) {
    u8 *inst = arg0;
    u8 *hdr;
    u8 *anim;
    u8 *frames;

    hdr = *(u8 **) (inst + 0x00);
    *(s32 *) (inst + 0x24) = 0;
    *(s16 *) (inst + 0x5C) = 0;
    *(s16 *) (inst + 0x5E) = 0;
    inst[0x08] = 0;
    *(f32 *) (inst + 0x30) = 0.0f;
    *(f32 *) (inst + 0x28) = 0.0f;
    *(f32 *) (inst + 0x40) = 0.0f;
    *(f32 *) (inst + 0x38) = 0.0f;

    if (*(s8 *) (hdr + 0x4E) != 0) {
        if (*(u8 *) (hdr + 0x64) != 0) {
            *(void **) (inst + 0x80) = func_8003CD70(*(s16 *) *(u8 **) (hdr + 0x5C));
            *(void **) (inst + 0x84) = func_8003CD70(*(s16 *) *(u8 **) (hdr + 0x5C));
            anim = *(u8 **) (inst + 0x80);
            *(s16 *) (inst + 0x88) = *(s16 *) *(u8 **) (hdr + 0x5C);
            *(s16 *) (inst + 0x8A) = *(s16 *) *(u8 **) (hdr + 0x5C);
        } else {
            anim = *(u8 **) (*(u8 **) (hdr + 0x50) + *(u16 *) (inst + 0x24) * 4);
        }

        frames = anim + 8;
        *(u8 **) (inst + 0x60) = frames;
        inst[0x08] = (u8) (*(s8 *) (anim + 1) & 0xF0);
        *(f32 *) (inst + 0x38) = (f32) frames[3];
        if (*(s8 *) (inst + 0x08) == 0) {
            *(f32 *) (inst + 0x38) = *(f32 *) (inst + 0x38) - 1.0f;
        }
        inst[0x09] = *(s8 *) (inst + 0x08);
        *(u8 **) (inst + 0x64) = frames;
        *(u16 *) (inst + 0x26) = *(u16 *) (inst + 0x24);
        *(f32 *) (inst + 0x2C) = *(f32 *) (inst + 0x28);
        *(f32 *) (inst + 0x3C) = *(f32 *) (inst + 0x38);
        *(f32 *) (inst + 0x44) = *(f32 *) (inst + 0x40);
        *(f32 *) (inst + 0x34) = *(f32 *) (inst + 0x30);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/models/func_8003CB50.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_8003CCC8(s32 arg0) {
    u8 *entry;
    u8 *buf;
    s32 off;
    s32 size;

    piRomLoadSection(0x2CU, (u32) D_800F6F38_B1778, (arg0 & ~1) * 4, 0x10);
    entry = D_800F6F38_B1778 + ((arg0 & 1) * 4);
    off = *(s32 *) entry;
    size = *(s32 *) (entry + 4) - off;
    buf = MODEL_ALLOC(size, 0xFF0000FFU);
    if (buf == NULL) {
        return NULL;
    }
    piRomLoadSection(0x2DU, (u32) buf, off, size);
    return buf;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/models/func_8003CCC8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 *func_8003CD70(s16 arg0) {
    s32 freeIdx = -1;
    s32 i;
    u8 *entry;
    u8 *buf;
    s32 off;
    s32 size;

    for (i = 0; i < D_800F6F40_B1780; i++) {
        if (arg0 == D_800F6F30_B1770[i].key) {
            buf = D_800F6F30_B1770[i].ptr;
            *(s8 *) buf += 1;
            return buf;
        }
        if (D_800F6F30_B1770[i].key == -1) {
            freeIdx = i;
        }
    }

    if (freeIdx == -1) {
        freeIdx = D_800F6F40_B1780;
        if (D_800F6F40_B1780 >= 0x100) {
            return NULL;
        }
        D_800F6F40_B1780 += 1;
    }

    piRomLoadSection(0x2AU, (u32) D_800F6F34_B1774, (arg0 & ~1) * 4, 0x10);
    entry = D_800F6F34_B1774 + ((arg0 & 1) * 4);
    off = *(s32 *) entry;
    size = *(s32 *) (entry + 4) - off;
    buf = MODEL_ALLOC(size, 0xFF00FFU);
    if (buf == NULL) {
        return NULL;
    }
    piRomLoadSection(0x2BU, (u32) buf, off, size);
    *buf = 1;
    D_800F6F30_B1770[freeIdx].key = arg0;
    D_800F6F30_B1770[freeIdx].ptr = buf;
    return buf;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/models/func_8003CD70.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void modFreeAnim(void *arg0) {
    s8 *anim = arg0;
    s32 i;
    s32 idx = -1;

    if (anim != NULL) {
        *anim -= 1;
        if (*anim <= 0) {
            for (i = 0; i < D_800F6F40_B1780; i++) {
                if (arg0 == D_800F6F30_B1770[i].ptr) {
                    idx = i;
                }
            }
            if (idx != -1) {
                mmFree(arg0);
                D_800F6F30_B1770[idx].key = -1;
                D_800F6F30_B1770[idx].ptr = (void *) -1;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/models/modFreeAnim.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void modGenAnimMatrices(void *arg0, void *arg1, void *arg2, f32 arg3, f32 arg4) {
    u8 *inst = arg0;
    u8 *hdr = arg1;
    u8 *obj = arg2;
    u8 *ext;
    u8 *parent;
    u8 *curMtx;
    u8 *anim;
    u8 *slotPtr;
    u8 *sflag;
    u8 *src;
    u8 *dstTab;
    u8 *outp;
    u8 *tilt;
    u8 *e;
    u8 *vtxBase;
    u8 *m;
    u8 *v9;
    u8 t8;
    u8 b6;
    s16 *rot;
    s16 kind;
    s16 *vtx;
    s16 vi;
    s16 mi;
    s32 a3;
    s32 i;
    s32 v;
    s32 cnt;
    s32 cntPos;
    s32 f10;
    s32 t9;
    f32 f0;
    f32 f2;
    f32 mtx[16];
    f32 sp64;
    f32 sp60;
    f32 sp5C;
    void *spD0;

    ext = *(u8 **) (obj + 0x68);
    kind = *(s16 *) (obj + 0x48);
    parent = NULL;
    rot = NULL;
    if (kind == 0x18) {
        parent = *(u8 **) (ext + 0x24);
        if (parent != NULL) {
            rot = *(s16 **) (*(u8 **) (parent + 0x68) + 0x54);
        }
    }

    if (kind == 0x18 && parent != NULL && rot != NULL && (*(u32 *) ext & 0x200)) {
        mathTranslateMtx(mtx, *(f32 *) (obj + 0xC), *(f32 *) (obj + 0x10), *(f32 *) (obj + 0x14));
        matrixYaw(rot[0], mtx);
        matrixRoll(rot[2], mtx);
        matrixPitch(rot[1], mtx);
        matrixYaw((s16) (*(s16 *) (obj + 0x00) - rot[0]), mtx);
        matrixScale(*(f32 *) (obj + 0x8), *(f32 *) (obj + 0x8), *(f32 *) (obj + 0x8), mtx);
    } else if (kind == 0xA7) {
        for (i = 0; i < 4; i++) {
            src = ext + 0x48 + i * 16;
            mtx[i * 4 + 0] = *(f32 *) (src + 0);
            mtx[i * 4 + 1] = *(f32 *) (src + 4);
            mtx[i * 4 + 2] = *(f32 *) (src + 8);
            mtx[i * 4 + 3] = *(f32 *) (src + 12);
        }
    } else {
        matrix_SCL_RPY_XYZ(obj, mtx, ext);
        if (arg4 != 0.0f) {
            mathTransY(mtx, arg4);
        }
        if (arg3 != 1.0f) {
            mathSquashY(mtx, arg3);
        }
    }

    a3 = 1;
    *(s8 *) (inst + 0x0B) = (u8) (*(s8 *) (inst + 0x0B) ^ 1);
    curMtx = *(u8 **) (inst + 0x10 + *(s8 *) (inst + 0x0B) * 4);
    spD0 = curMtx;
    *(u8 **) (inst + 0x04) = *(u8 **) (inst + 0x18 + *(s8 *) (inst + 0x0B) * 4);
    *(f32 *) (inst + 0x28) = *(f32 *) (inst + 0x38) * *(f32 *) (obj + 0x28);
    if (*(s16 *) (inst + 0x5E) != 0) {
        a3 = 2;
    }

    if (*(u8 *) (hdr + 0x64) != 0) {
        for (i = 0; i < a3; i++) {
            u16 *cur24 = (u16 *) (inst + 0x24 + i * 2);
            s16 *prev88 = (s16 *) (inst + 0x88 + i * 2);

            anim = *(u8 **) (inst + 0x80 + i * 4);
            if (anim != NULL && *prev88 != *cur24) {
                modFreeAnim(anim);
                anim = NULL;
                *(u8 **) (inst + 0x80 + i * 4) = NULL;
            }
            if (anim == NULL) {
                sflag = inst + i;
                anim = func_8003CD70(((s16 *) *(u8 **) (hdr + 0x5C))[*cur24]);
                *(u8 **) (inst + 0x80 + i * 4) = anim;
                *prev88 = *cur24;
                slotPtr = anim + 8;
                *(u8 **) (inst + 0x60 + i * 4) = slotPtr;
                sflag[8] = (u8) (*(s8 *) (anim + 1) & 0xF0);
                *(f32 *) (inst + 0x38 + i * 4) = (f32) (*(u8 **) (inst + 0x60 + i * 4))[3];
                if (*(s8 *) (sflag + 8) == 0) {
                    *(f32 *) (inst + 0x38 + i * 4) = *(f32 *) (inst + 0x38 + i * 4) - 1.0f;
                }
                t9 = *(s8 *) (anim + 1) & 0xF;
                if (t9 != 0) {
                    *(s16 *) (inst + 0x5E) = 0x3FF;
                    a3 = 2;
                    *(s16 *) (inst + 0x5C) = (s16) (0x3FF / t9);
                }
            }
        }
    }

    if (a3 > 0) {
        for (i = 0; i < a3; i++) {
            cnt = *(s8 *) (hdr + 0x4F);
            src = *(u8 **) (hdr + 0x58) + *(u16 *) (inst + 0x24 + i * 2) * cnt;
            dstTab = *(u8 **) (hdr + 0x54);
            for (v = 0; v < cnt; v++) {
                dstTab[v * 0x10 + i + 2] = *(s8 *) (src + v);
            }

            if (*(u8 *) (hdr + 0x64) != 0) {
                m = *(u8 **) (inst + 0x80 + i * 4);
            } else {
                m = *(u8 **) (*(u8 **) (hdr + 0x50) + *(u16 *) (inst + 0x24 + i * 2) * 4);
            }
            f0 = *(f32 *) (inst + 0x28 + i * 4);
            f10 = (s32) f0;
            t8 = (*(u8 **) (inst + 0x60 + i * 4))[5];
            f2 = (f32) f10;
            if (f2 != f0) {
                *(s16 *) (inst + 0x58 + i * 2) = (s16) t8;
            } else {
                *(s16 *) (inst + 0x58 + i * 2) = 0;
            }
            if (*(s8 *) (inst + i + 8) != 0 && f2 == (*(f32 *) (inst + 0x38 + i * 4) - 1.0f)) {
                *(s16 *) (inst + 0x58 + i * 2) = (s16) (-(s32) t8 * f10);
            }
            *(u8 **) (inst + 0x4C + (i + 1) * 4) = m + *(s16 *) (m + 2) + (t8 * f10);
        }
    }

    if (*(s16 *) (inst + 0x5E) != 0) {
        if (*(s16 *) (obj + 0x48) != 1) {
            if (D_800F6F54_B1794 != 0) {
                *(s16 *) (inst + 0x5E) = (s16) (*(s16 *) (inst + 0x5E) - *(s16 *) (inst + 0x5C));
            }
        } else if (mainGetPauseMode() == 0) {
            *(s16 *) (inst + 0x5E) = (s16) (*(s16 *) (inst + 0x5E) - *(s16 *) (inst + 0x5C));
        }
        if (*(s16 *) (inst + 0x5E) < 0) {
            *(s16 *) (inst + 0x5E) = 0;
        }
    }

    switch (*(s16 *) (obj + 0x48)) {
    case 0x1:
        tilt = controlPlayerTiltList(obj);
        break;
    case 0x33:
        tilt = *(u8 **) (obj + 0x68) + 0x4E;
        break;
    case 0x93:
        tilt = *(u8 **) (obj + 0x68) + 4;
        break;
    case 0x2:
        tilt = controlSidekickTiltList(obj);
        break;
    case 0x18:
        tilt = mizarTiltList(obj);
        break;
    case 0x6C:
        tilt = multiCharArmGetTiltList(obj);
        break;
    case 0x5C:
        tilt = frontMenuPodiumGetTiltList(obj);
        break;
    case 0x65:
        tilt = frontMultiStatsBarGetTiltList();
        break;
    case 0x83:
        tilt = frontKeyboardGetTiltList();
        break;
    case 0x82:
        tilt = *(u8 **) (obj + 0x68) + 0x42;
        break;
    case 0x90:
        tilt = GetBaddyData();
        break;
    default:
        tilt = &D_800A2EC4_A3AC4;
        break;
    }

    gen_anim_data(&spD0, mtx, inst + 0x20, *(u8 **) (hdr + 0x54), *(s8 *) (hdr + 0x4F), tilt);

    // Position/normal transforms for the three vertex groups.
    cntPos = hdr[0x2D];
    outp = *(u8 **) (inst + 0x68);
    for (i = 0; i < cntPos; i++) {
        e = *(u8 **) (hdr + 0x30) + i * 4;
        vi = *(u16 *) e;
        mi = *(u16 *) (e + 2);
        vtx = (s16 *) (*(u8 **) (hdr + 0x1C) + vi * 10);
        mathMtxXFMF((float (*)[4]) (curMtx + (mi << 6)), (f32) vtx[0], (f32) vtx[1], (f32) vtx[2],
                    (f32 *) outp, (f32 *) (outp + 4), (f32 *) (outp + 8));
        outp += 12;
    }

    cntPos = hdr[0x2E];
    outp = *(u8 **) (inst + 0x6C);
    for (i = 0; i < cntPos; i++) {
        e = *(u8 **) (hdr + 0x34) + i * 12;
        vi = *(u16 *) e;
        mi = *(s8 *) (e + 2);
        vtx = (s16 *) (*(u8 **) (hdr + 0x1C) + vi * 10);
        mathMtxXFMF((float (*)[4]) (curMtx + (mi << 6)), (f32) vtx[0], (f32) vtx[1], (f32) vtx[2],
                    (f32 *) outp, (f32 *) (outp + 4), (f32 *) (outp + 8));
        outp += 12;
    }

    cntPos = hdr[0x2F];
    outp = *(u8 **) (inst + 0x70);
    for (i = 0; i < cntPos; i++) {
        e = *(u8 **) (hdr + 0x38) + i * 12;
        vi = *(u16 *) e;
        mi = *(s8 *) (e + 2);
        vtx = (s16 *) (*(u8 **) (hdr + 0x1C) + vi * 10);
        mathMtxXFMF((float (*)[4]) (curMtx + (mi << 6)), (f32) vtx[0], (f32) vtx[1], (f32) vtx[2],
                    (f32 *) outp, (f32 *) (outp + 4), (f32 *) (outp + 8));
        outp += 12;
    }

    if (kind == 0x18 && parent != NULL) {
        *(f32 *) (ext + 0x74) = *(f32 *) (obj + 0xC);
        *(f32 *) (ext + 0x78) = *(f32 *) (obj + 0x10);
        *(f32 *) (ext + 0x7C) = *(f32 *) (obj + 0x14);
        *(f32 *) (ext + 0x80) = *(f32 *) (obj + 0xC);
        *(f32 *) (ext + 0x84) = *(f32 *) (obj + 0x10);
        *(f32 *) (ext + 0x88) = *(f32 *) (obj + 0x14);
        b6 = ext[0x06];
        if ((b6 & 3) < 2) {
            ext[0x06] = (u8) ((((b6 & 3) + 1) & 3) | (b6 & 0xFC));
        }

        v9 = osCic6105SendData(obj);
        if (v9 != NULL) {
            m = curMtx + (v9[0x30] << 6);
            mathMtxXFMF((float (*)[4]) m, (f32) *(s8 *) (v9 + 0x31), (f32) *(s8 *) (v9 + 0x32), (f32) *(s8 *) (v9 + 0x33),
                        (f32 *) (ext + 0x68), (f32 *) (ext + 0x6C), (f32 *) (ext + 0x70));
            mathMtxXFMF((float (*)[4]) m, (f32) *(s8 *) (v9 + 0x31), (f32) *(s8 *) (v9 + 0x32), (f32) *(s8 *) (v9 + 0x33) - 64.0f,
                        &sp64, &sp60, &sp5C);
            *(u16 *) (ext + 0x9C) = Arctanf(*(f32 *) (ext + 0x68) - sp64, *(f32 *) (ext + 0x70) - sp5C);
            if (v9[0x3A] != 0) {
                vtxBase = curMtx + (v9[0x3A] << 6);
                *(f32 *) (ext + 0x74) = *(f32 *) (vtxBase + 0x30);
                *(f32 *) (ext + 0x78) = *(f32 *) (vtxBase + 0x34);
                *(f32 *) (ext + 0x7C) = *(f32 *) (vtxBase + 0x38);
            }
            if (v9[0x3D] != 0) {
                vtxBase = curMtx + (v9[0x3D] << 6);
                *(f32 *) (ext + 0x80) = *(f32 *) (vtxBase + 0x30);
                *(f32 *) (ext + 0x84) = *(f32 *) (vtxBase + 0x34);
                *(f32 *) (ext + 0x88) = *(f32 *) (vtxBase + 0x38);
            }
        } else {
            *(f32 *) (ext + 0x68) = *(f32 *) (obj + 0xC);
            *(f32 *) (ext + 0x6C) = *(f32 *) (obj + 0x10);
            *(f32 *) (ext + 0x70) = *(f32 *) (obj + 0x14);
            *(u16 *) (ext + 0x9C) = (u16) *(s16 *) (obj + 0x00);
        }
    }

    camConvertMatrixList(curMtx, *(s8 *) (hdr + 0x4F));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/models/modGenAnimMatrices.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void modelSetModelFlags(s32 arg0) {
    D_800A2EC0_A3AC0 = arg0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/models/modelSetModelFlags.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 modelGetModelFlags(void) {
    return D_800A2EC0_A3AC0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/models/modelGetModelFlags.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Appends 8-byte Gfx words to the cursor and advances it.
static void gfxPush(Gfx **cur, u32 w0, u32 w1) {
    u32 *p = (u32 *) *cur;

    p[0] = w0;
    p[1] = w1;
    *cur = *cur + 1;
}

s32 makeModelGfx(void *dst, void *hdr, s32 a, s32 b, s32 start, s32 end, s32 c) {
    u8 *h = hdr;
    u8 *ent = *(u8 **) (h + 0x24);
    u8 *pairs = *(u8 **) (h + 0x28);
    s32 nEnt = *(s16 *) (h + 0x16);
    Gfx *cur = D_800F6F58_B1798;
    void *lastTex = (void *) -1;
    s32 lastFlags = -1;
    s32 count = 0;
    s32 i;
    s32 nGfx;
    void *buf;

    texModelTextureLoad(1);
    if (a & 4) {
        D_800A5840 = 1;
    }
    b = ~b;
    if (start == 0 && c == 0) {
        func_8003E100();
        texDPInit(&cur);
    } else if (c != 0) {
        func_8003E100();
        texDPInit(NULL);
        gfxPush(&cur, 0xE7000000, 0);
        gfxPush(&cur, 0xB7000000, 0x10001);
    }

    for (i = 0; i < nEnt; i++) {
        u8 *e = ent + i * 0x10;
        u32 flags = *(u32 *) (e + 0xC);
        s32 seg = *(s8 *) (e + 1);

        if (seg >= start && seg <= end && !(flags & 0x400)) {
            s32 vOff = *(s16 *) (e + 0x8);
            s32 vCount = *(s16 *) (e + 0x6);
            u32 vtxAddr = *(u32 *) (h + 0x20) + vOff * 0x10;
            s32 matId = e[0];
            s32 s2 = *(s16 *) (e + 0x16) - vCount;
            void *tex;
            s32 texFlags;
            s32 hasTex;
            s32 spB8;

            if (matId == 0xFF || c != 0) {
                tex = NULL;
                texFlags = 0;
                hasTex = 0;
            } else {
                tex = *(void **) (*(u8 **) (h + 0x18) + matId * 8);
                texFlags = e[0xB] << 14;
                hasTex = 1;
            }
            if (h[0x11] != 0 && tex != NULL && (tex != lastTex || texFlags != lastFlags)) {
                *(s32 *) pairs = texFlags;
                *(s16 *) (pairs + 2) = -1;
                *(s32 *) (pairs + 4) = (flags & ~0xFF) | matId;
                if (*(s16 *) ((u8 *) tex + 6) & 0x40) {
                    s16 v = (s16) (texFlags + 0x100);

                    *(s16 *) (pairs + 2) = v;
                    if (v >= *(u16 *) ((u8 *) tex + 0x12)) {
                        if (*(u8 *) ((u8 *) tex + 0x18) != 0) {
                            *(s16 *) (pairs + 2) = 0;
                        } else {
                            *(s16 *) (pairs + 2) = v - 0x100;
                        }
                    }
                }
                pairs += 8;
                count += 1;
            }
            lastTex = tex;
            lastFlags = texFlags;
            spB8 = *(s16 *) (e + 0x18) - vOff;

            texDPTextureX(&cur, tex, (flags | a | D_800A2EC0_A3AC0) & b, texFlags);
            if (*(s8 *) (h + 0x4E) == 0) {
                s32 t = (vCount * 0xA) & 0x0FFFFFFF;

                gfxPush(&cur,
                        ((((s2 * 8) | (t & 6)) & 0xFF) << 16) | 0x04000000 | (((s2 * 0xA) + 8) & 0xFFFF),
                        t);
            } else {
                s8 ids[3];
                s32 s0 = 0;
                s32 s1 = 0;

                func_8003E13C(&cur, (s8 *) (e + 1), ids, h, i, 0);
                if (s2 > 0) {
                    s32 a2;

                    do {
                        s32 v1;
                        s32 vt;
                        s32 w0;

                        gfxPush(&cur, 0xBC00000A, (u32) (ids[s0] << 6));
                        a2 = (s0 < 2) ? *(s8 *) (e + s0 + 4) : s2;
                        v1 = a2 - s1;
                        vt = ((vCount + s1) * 0xA) & 0x0FFFFFFF;
                        w0 = ((((v1 * 8) | (vt & 6)) & 0xFF) << 16) | 0x04000000 |
                             ((((v1 * 0xA) + 8) | (s1 << 9)) & 0xFFFF);
                        s1 = a2;
                        s0 += 1;
                        gfxPush(&cur, w0, vt);
                    } while (a2 < s2);
                }
            }
            gfxPush(&cur,
                    (((((spB8 - 1) * 0x10) | hasTex) & 0xFF) << 16) | 0x05000000 | ((spB8 * 0x10) & 0xFFFF),
                    vtxAddr & 0x0FFFFFFF);
        }
    }
    gfxPush(&cur, 0xE7000000, 0);
    gfxPush(&cur, 0xB8000000, 0);

    nGfx = (s32) (cur - (Gfx *) D_800F6F58_B1798);
    buf = MODEL_ALLOC(nGfx * 8, 0xFF0000FF);
    *(void **) dst = buf;
    if (buf != NULL) {
        u32 *s = (u32 *) D_800F6F58_B1798;
        u32 *d = (u32 *) buf;

        for (i = 0; i < nGfx * 2; i++) {
            d[i] = s[i];
        }
    }
    texModelTextureLoad(0);
    D_800A5840 = 0;
    return count;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/models/makeModelGfx.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8003E100(void) {
    s32 k;

    for (k = 0; k < 3; k++) {
        D_800F6F48_B1788[k] = -1;
        D_800F6F4C_B178C[k] = 0x3E8;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/models/func_8003E100.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_8003E13C(Gfx **dl, s8 *ids, s8 *out, void *hdr, s32 segIdx, s32 mode) {
    u8 *h = hdr;
    s32 k;
    s32 i;

    for (k = 0; k < 3; k++) {
        s8 tag = D_800F6F48_B1788[k];

        if (tag != -1) {
            D_800F6F4C_B178C[k] -= 1;
            if (D_800F6F4C_B178C[k] <= 0) {
                s32 v;

                D_800F6F4C_B178C[k] = 1;
                v = segIdx + 1;
                if (v < *(s16 *) (h + 0x16)) {
                    do {
                        u8 *e = *(u8 **) (h + 0x24) + v * 0x10;

                        if (tag == *(s8 *) (e + 1) || tag == *(s8 *) (e + 2) || tag == *(s8 *) (e + 3)) {
                            v = *(s16 *) (h + 0x16);
                        } else {
                            D_800F6F4C_B178C[k] += 1;
                        }
                        v += 1;
                    } while (v < *(s16 *) (h + 0x16));
                }
            }
        }
    }

    for (i = 0; i < 3; i++) {
        s8 id = ids[i];

        out[i] = -1;
        if (id != -1) {
            for (k = 0; k < 3; k++) {
                if (D_800F6F48_B1788[k] == id) {
                    out[i] = k + 1;
                }
            }
            if (out[i] == -1) {
                s32 slot = -1;
                s32 best = 0;

                for (k = 0; k < 3 && slot == -1; k++) {
                    if (D_800F6F48_B1788[k] == -1) {
                        slot = k;
                    }
                }
                if (slot == -1) {
                    for (k = 0; k < 3; k++) {
                        s8 t = D_800F6F48_B1788[k];

                        if (t != ids[0] && t != ids[1] && t != ids[2]) {
                            if (best < D_800F6F4C_B178C[k]) {
                                best = D_800F6F4C_B178C[k];
                                slot = k;
                            }
                        }
                    }
                }
                /* asm: slot can stay -1 here and the asm would write before the table */
                D_800F6F48_B1788[slot] = id;
                D_800F6F4C_B178C[slot] = 0;
                out[i] = slot + 1;
                gfxPush(dl, (((out[i] | 0x80) & 0xFF) << 16) | 0x01000000 | 0x40,
                        ((id << 6) + mode) & 0x0FFFFFFF);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/models/func_8003E13C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Severed-limb model builder. Walks the part's groups (16 B, header +0x24),
// transforms the vertices of each group's triangles (10 B, vertex input at
// blk+4) through the bone matrix, writes 16 B triangle records into
// obj->+0x68 (+8 cursor) and builds the display list in a fresh allocation.
// Output vertices are then recentred on their average into obj->+0xC..+0x14.
// Layout cf. jfg-re docs/technical-notes.md + model_parser.py: header +0x16
// group count, +0x18 texture records (8 B), +0x20 triangles (16 B),
// +0x24 groups (16 B). Other structs are raw offsets (no typed layout here).
void modMakeLimbModel(void **outDl, void *objArg, void *srcArg, s32 flags, s32 mask,
                      s32 minType, s32 maxType) {
    u8 *obj = (u8 *) objArg;
    u8 *src = (u8 *) srcArg;
    u8 *blk = (*(u8 ***)(src + 0x6C))[*(s8 *)(src + 0x3A)];
    u8 *part = *(u8 **) blk;
    u8 *geo = *(u8 **)(obj + 0x68);
    u8 *vIn = *(u8 **)(blk + 4);
    u8 *texRec = *(u8 **)(part + 0x28);
    u8 *vOut = *(u8 **)(geo + 4);
    u8 *fp = *(u8 **)(geo + 8);
    u8 *triOut = fp;
    u8 *batchStart = vOut;
    u32 *dl = (u32 *) D_800F6F58_B1798;
    u8 *lastTex = (u8 *) -1;
    s32 lastTmem = -1;
    s32 tileFlags = 0;
    s32 invMask = ~mask;
    s32 batchVerts = 0;
    s32 haveTex = 0;
    s32 numGroups, g, i, k, recIdx, nRec, recStart, nTri, cnt, lv, vi, sel, tmem, texIdx;
    s32 sumX, sumY, sumZ;
    u8 *group, *rec, *idx, *tex, *v, *mtx, *base, *p, *res;
    f32 ox, oy, oz, avgX, avgY, avgZ, cntF;
    u32 addr;

    texDPInit((Gfx **) &dl);
    numGroups = *(s16 *)(part + 0x16);
    group = *(u8 **)(part + 0x24);
    for (g = 0; g < numGroups; g++, group += 0x10) {
        /* asm: group type (+1) must lie within [minType, maxType] */
        if (*(s8 *)(group + 1) < minType || maxType < *(s8 *)(group + 1)) {
            continue;
        }
        if (*(u32 *)(group + 0xC) & 0x400) {
            continue;
        }

        texIdx = *(u8 *)group;
        recIdx = 0;
        if (texIdx == 0xFF) {
            tex = NULL;
            tmem = 0;
            haveTex = 0;
        } else {
            tex = *(u8 **)(*(u8 **)(part + 0x18) + texIdx * 8);
            tmem = *(u8 *)(group + 0xB) << 14;
            haveTex = 1;
        }

        tileFlags = (tileFlags | flags | D_800A2EC0_A3AC0) & invMask;

        if (part[0x11] != 0 && tex != NULL) {
            if (tex != lastTex || tmem != lastTmem) {
                *(s16 *)(texRec + 0) = (s16) tmem;
                *(s16 *)(texRec + 2) = -1;
                *(s32 *)(texRec + 4) = (*(s32 *)(group + 0xC) & ~0xFF) | texIdx;
                if (*(s16 *)(tex + 6) & 0x40) {
                    *(s16 *)(texRec + 2) = (s16) (tmem + 0x100);
                    if (*(s16 *)(texRec + 2) >= *(u16 *)(tex + 0x12)) {
                        if (*(u8 *)(tex + 0x18) == 0) {
                            *(s16 *)(texRec + 2) = (s16) (*(s16 *)(texRec + 2) - 0x100);
                        } else {
                            *(s16 *)(texRec + 2) = 0;
                        }
                    }
                }
                texRec += 8;
            }
        }
        lastTex = tex;
        lastTmem = tmem;
        texDPTextureX((Gfx **) &dl, tex, tileFlags, tmem);

        recStart = *(s16 *)(group + 8);
        rec = *(u8 **)(part + 0x20) + (recStart << 4);
        nRec = *(s16 *)(group + 0x18) - recStart;
        if (nRec > 0) {
            do {
                sumX = 0;
                sumY = 0;
                sumZ = 0;
                k = 0;
                idx = rec;
                do {
                    lv = idx[1];
                    vi = lv + *(s16 *)(group + 6);
                    v = vIn + vi * 10;
                    if (lv < *(s8 *)(group + 4)) {
                        sel = *(s8 *)(group + 1);
                    } else if (lv < *(s8 *)(group + 5)) {
                        sel = *(s8 *)(group + 2);
                    } else {
                        sel = *(s8 *)(group + 3);
                    }
                    mtx = *(u8 **)(blk + 0x10 + *(s8 *)(blk + 0xB) * 4) + (sel << 6);
                    mathMtxXFMF((f32 (*)[4]) mtx, (f32) *(s16 *)(v + 0), (f32) *(s16 *)(v + 2),
                                (f32) *(s16 *)(v + 4), &ox, &oy, &oz);
                    /* asm: running sums per triangle (s3/s4/s5). Computed but never stored. */
                    sumX = (s32) ((f32) sumX + ox);
                    sumY = (s32) ((f32) sumY + oy);
                    sumZ = (s32) ((f32) sumZ + oz);
                    *(s16 *)(vOut + 0) = (s16) (s32) ox;
                    *(s16 *)(vOut + 2) = (s16) (s32) oy;
                    *(s16 *)(vOut + 4) = (s16) (s32) oz;
                    vOut[6] = v[6];
                    vOut[7] = v[7];
                    vOut[8] = v[8];
                    vOut[9] = v[9];
                    vOut += 10;
                    idx += 1;
                    k += 1;
                } while (k < 3);

                /* 16 B triangle record: 0x40, three batch-local vertex indices,
                   then halfwords 4..0xF copied from the group record */
                triOut[0] = 0x40;
                triOut[1] = (u8) batchVerts;
                triOut[2] = (u8) (batchVerts + 1);
                triOut[3] = (u8) (batchVerts + 2);
                *(s16 *)(triOut + 4) = *(s16 *)(rec + 4);
                *(s16 *)(triOut + 6) = *(s16 *)(rec + 6);
                *(s16 *)(triOut + 8) = *(s16 *)(rec + 8);
                *(s16 *)(triOut + 10) = *(s16 *)(rec + 10);
                *(s16 *)(triOut + 12) = *(s16 *)(rec + 12);
                *(s16 *)(triOut + 14) = *(s16 *)(rec + 14);
                triOut += 0x10;
                batchVerts += 3;
                rec += 0x10;

                if (batchVerts == 0x18) {
                    /* full batch: 24 verts -> one VTX cmd (0xC0 = 24*8, 0xF8 = 24*10+8)
                       followed by 8 triangle cmds */
                    addr = (u32) batchStart & 0x0FFFFFFF;
                    dl[0] = ((((addr & 6) | 0xC0) & 0xFF) << 16) | 0x04000000 | 0xF8;
                    dl[1] = addr;
                    dl += 2;
                    for (i = 0; i < 8; i++) {
                        dl[1] = (u32) fp & 0x0FFFFFFF;
                        dl[0] = ((haveTex & 0xFF) << 16) | 0x05000010;
                        dl += 2;
                        fp += 0x10;
                    }
                    batchStart = vOut;
                    batchVerts = 0;
                }
                recIdx += 1;
            } while (recIdx < nRec);
        }

        /* asm: flush the partial batch at the end of the group */
        if (batchVerts != 0) {
            addr = (u32) batchStart & 0x0FFFFFFF;
            dl[0] = ((((batchVerts * 8) | (addr & 6)) & 0xFF) << 16) | 0x04000000
                    | (((batchVerts * 10) + 8) & 0xFFFF);
            dl[1] = addr;
            dl += 2;
            nTri = batchVerts / 3;
            batchVerts = 0;
            batchStart = vOut;
            for (i = 0; i < nTri; i++) {
                dl[1] = (u32) fp & 0x0FFFFFFF;
                dl[0] = ((haveTex & 0xFF) << 16) | 0x05000010;
                dl += 2;
                fp += 0x10;
            }
        }
    }

    /* RDP pipe sync + end display list */
    dl[0] = 0xE7000000;
    dl[1] = 0;
    dl += 2;
    dl[0] = 0xB8000000;
    dl[1] = 0;
    dl += 2;

    cnt = ((u8 *) dl - (u8 *) D_800F6F58_B1798) >> 3;
    res = MODEL_ALLOC(cnt * 8, 0xFF0000FF);
    *outDl = res;
    if (res != NULL) {
        u32 *out = (u32 *) res;
        u32 *srcDl = (u32 *) D_800F6F58_B1798;
        for (i = 0; i < cnt; i++) {
            out[0] = srcDl[0];
            out[1] = srcDl[1];
            out += 2;
            srcDl += 2;
        }
    }

    /* recentre output vertices on their average */
    base = *(u8 **)(geo + 4);
    cnt = (s32) (vOut - base) / 10;
    avgX = 0.0f;
    avgY = 0.0f;
    avgZ = 0.0f;
    p = base;
    for (i = 0; i < cnt; i++, p += 10) {
        avgX += (f32) *(s16 *)(p + 0);
        avgY += (f32) *(s16 *)(p + 2);
        avgZ += (f32) *(s16 *)(p + 4);
    }
    cntF = (f32) cnt;
    avgX = avgX / cntF;
    avgY = avgY / cntF;
    avgZ = avgZ / cntF;
    p = base;
    for (i = 0; i < cnt; i++, p += 10) {
        *(s16 *)(p + 0) = (s16) (s32) ((f32) *(s16 *)(p + 0) - avgX);
        *(s16 *)(p + 2) = (s16) (s32) ((f32) *(s16 *)(p + 2) - avgY);
        *(s16 *)(p + 4) = (s16) (s32) ((f32) *(s16 *)(p + 4) - avgZ);
    }
    *(f32 *)(obj + 0xC) = avgX;
    *(f32 *)(obj + 0x10) = avgY;
    *(f32 *)(obj + 0x14) = avgZ;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/models/modMakeLimbModel.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s16 *modLoadAnimEvents(s16 arg0) {
    ModelSlotEntry *tbl = (ModelSlotEntry *) D_800F6F3C_B177C;
    s32 slot = -1;
    s32 i;
    s32 *offs;
    s32 size;
    void *buf;

    for (i = 0; i < D_800F6F44_B1784; i++) {
        if (tbl[i].key == (s32) arg0) {
            *(s16 *) tbl[i].ptr += 1;
            return (s16 *) tbl[i].ptr;
        }
        if (tbl[i].key == -1) {
            slot = i;
        }
    }
    if (slot == -1) {
        slot = D_800F6F44_B1784;
        if (D_800F6F44_B1784 >= 0x20) {
            return NULL;
        }
        D_800F6F44_B1784 += 1;
    }
    piRomLoadSection(0x43, (u32) D_800F6F34_B1774, ((s32) arg0 & ~1) * 4, 0x10);
    offs = (s32 *) D_800F6F34_B1774 + (arg0 & 1);
    size = offs[1] - offs[0];
    buf = MODEL_ALLOC(size, 0xFF00FF);
    if (buf == NULL) {
        return NULL;
    }
    piRomLoadSection(0x44, (u32) buf, offs[0], size);
    *(s16 *) buf = 1;
    tbl[slot].key = (s32) arg0;
    tbl[slot].ptr = buf;
    return (s16 *) buf;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/models/modLoadAnimEvents.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void modFreeAnimEvents(s16 *arg0) {
    ModelSlotEntry *tbl;
    s32 found = -1;
    s32 i;

    if (arg0 != NULL) {
        *arg0 -= 1;
        if (*arg0 <= 0) {
            tbl = (ModelSlotEntry *) D_800F6F3C_B177C;
            for (i = 0; i < D_800F6F44_B1784; i++) {
                if (tbl[i].ptr == (void *) arg0) {
                    found = i;
                }
            }
            if (found != -1) {
                mmFree(arg0);
                tbl[found].key = -1;
                tbl[found].ptr = (void *) -1;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/models/modFreeAnimEvents.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *modGetMakeBuffer(s32 *arg0) {
    *arg0 = 0x400;
    return D_800F6F58_B1798;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/models/modGetMakeBuffer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void modSetTextureFrame(void *arg0, s32 arg1, s16 arg2) {
    u8 *obj = (u8 *) arg0;
    u8 *hdr = *(u8 **) obj;
    u8 *ent = *(u8 **) (obj + 0x74);
    s16 *out = *(s16 **) (obj + 0x78 + *(s8 *) (obj + 0xB) * 4);
    s32 i;

    for (i = 0; i < hdr[0x2C]; i++) {
        s32 idx = *(s32 *) (ent + 4) & 0xFF;
        u8 *tex = *(u8 **) (*(u8 **) (hdr + 0x18) + idx * 8);

        if (idx == arg1) {
            *(s16 *) ent = arg2;
        }
        *out++ = (s16) ((*(s16 *) ent >> 8) * *(s16 *) (tex + 0x16));
        if (*(s16 *) (ent + 2) >= 0) {
            *out++ = (s16) ((*(s16 *) (ent + 2) >> 8) * *(s16 *) (tex + 0x16));
        }
        ent += 8;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/models/modSetTextureFrame.s")
#endif

#ifdef VERSION_us
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void modSuspendModelTextures(s16 *arg0) {
    ModelSlotEntry *slot;
    s32 *out;
    u8 *ptr;
    u8 *base;
    s32 i;
    s32 j;
    s32 k;
    s32 n;
    s32 found;
    s32 word;

    D_800A2ECC_A3ACC = 0;
    D_800A2EC8_A3AC8 = mmAlloc(0x3E8, 0xFF00FF);
    out = (s32 *) D_800A2EC8_A3AC8;
    for (i = 0; i < D_800F6F1C_B175C && D_800A2ECC_A3ACC < 0x7D; i++) {
        slot = &D_800F6F14_B1754[i];
        if (slot->key == -1) {
            continue;
        }
        ptr = (u8 *) slot->ptr;
        found = 0;
        if (arg0[0] != -1) {
            for (j = 0; ; j++) {
                if (arg0[j] == slot->key) {
                    found = 1;
                }
                if (arg0[j + 1] == -1 || found) {
                    break;
                }
            }
        }
        if (found) {
            continue;
        }
        n = *(u8 *) (ptr + 0x10);
        for (k = 0; k < n && D_800A2ECC_A3ACC < 0x7D; k++) {
            base = *(u8 **) (ptr + 0x18);
            word = *(s32 *) (base + k * 8);
            out[0] = (s32) texGetTextureNum(word);
            out[1] = word;
            texFreeTexture((void *) word);
            D_800A2ECC_A3ACC += 1;
            out += 2;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/models/modSuspendModelTextures.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void modResumeModelTextures(void) {
    s32 *tbl;
    s32 i;

    if (D_800A2EC8_A3AC8 != NULL) {
        tbl = (s32 *) D_800A2EC8_A3AC8;
        for (i = 0; i < D_800A2ECC_A3ACC; i++) {
            if (tbl[i * 2 + 1] != 0) {
                texLoadTextureAddr(tbl[i * 2], tbl[i * 2 + 1]);
            }
        }
        mmFree(D_800A2EC8_A3AC8);
        D_800A2ECC_A3ACC = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/models/modResumeModelTextures.s")
#endif
#endif
