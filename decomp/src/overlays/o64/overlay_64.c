#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern f32 D_overlay_64_04000D60;
extern u8 D_84000C60;
void camDoSprite(Gfx **dl, s32 arg1, s32 arg2, void *obj, s32 arg4, s32 arg5, s32 arg6);
void texDPTextureX(Gfx **dl, s32 texture, s32 arg2, s32 arg3);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_64_04000000_1F85A18(void **arg0, void *arg1, s32 arg2) {
    f32 *fl;
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 sp20;
    f32 temp_f18;
    f32 temp_f6;
    u8 *vtx;

    fl = (f32 *) arg1;
    sp20 = -fl[2];
    sp24 = 0.0f;
    sp28 = 0.0f;
    sp30 = 0.0f;
    sp34 = 0.0f;
    sp2C = fl[2];
    pointListRPY(2, (s16 *) arg1, (s32 *) &sp20, &sp20);
    temp_f18 = sp20 + fl[3];
    sp20 = temp_f18;
    sp24 += fl[4];
    sp28 += fl[5];
    sp2C += fl[3];
    temp_f6 = sp30 + fl[4];
    sp30 = temp_f6;
    sp34 += fl[5];

    vtx = (u8 *) *arg0;
    *(s16 *) (vtx + 0x0) = (s16) temp_f18;
    *(s16 *) (vtx + 0x2) = (s16) sp24;
    *(s16 *) (vtx + 0x4) = (s16) sp28;
    vtx[0x6] = 0xFF;
    vtx[0x7] = 0xFF;
    vtx[0x8] = 0xFF;
    vtx[0x9] = (u8) arg2;
    vtx += 0xA;
    *(s16 *) (vtx + 0x0) = (s16) sp2C;
    *(s16 *) (vtx + 0x2) = (s16) temp_f6;
    *(s16 *) (vtx + 0x4) = (s16) sp34;
    vtx[0x6] = 0xFF;
    vtx[0x7] = 0xFF;
    vtx[0x8] = 0xFF;
    vtx[0x9] = (u8) arg2;
    vtx += 0xA;
    *arg0 = vtx;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o64/overlay_64/func_overlay_64_04000000_1F85A18.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_64_04000244_1F85C5C(void *arg0) {
    u8 *base;
    f32 sp30;
    void *sp2C;
    s32 var_s0;
    u8 temp_t8;
    u8 *temp_v0;

    base = (u8 *) arg0;
    if (base[0x2E] != 0) {
        temp_t8 = base[0x2F] ^ 1;
        base[0x2F] = temp_t8;
        sp2C = base + ((temp_t8 & 0xFF) * 0xB4) + 0xF0;
        sp30 = *(f32 *) (base + 0x8);
        *(f32 *) (base + 0x8) = (f32) *(s16 *) (base + 0x18);
        func_overlay_64_04000000_1F85A18(&sp2C, base, base[0x23]);
        *(f32 *) (base + 0x8) = sp30;
        var_s0 = base[0x2D] - 1;
        do {
            if (var_s0 < 0) {
                var_s0 = 7;
            }
            temp_v0 = base + (var_s0 * 0x18);
            func_overlay_64_04000000_1F85A18(&sp2C, temp_v0 + 0x30, temp_v0[0x37]);
            var_s0 -= 1;
        } while (var_s0 != base[0x2C]);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o64/overlay_64/func_overlay_64_04000244_1F85C5C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_64_04000340_1F85D58(void *arg0, void *arg1, s32 arg2) {
    u8 *lt;
    u8 *particle;
    u8 *ctrl;
    u8 *light;
    s32 temp_lo;
    s16 temp_t8;
    s8 temp_a0;
    u8 temp_t3;
    u8 temp_v0;
    u8 var_a3;
    u8 var_v0;

    lt = (u8 *) arg1;
    var_a3 = lt[0x2E];
    if (var_a3 != 0) {
        var_v0 = lt[0x2C];
        do {
            temp_lo = var_v0 * 0x18;
            var_v0 += 1;
            particle = lt + temp_lo + 0x30;
            if ((s32) var_v0 >= 8) {
                var_v0 = 0;
            }
            *(s8 *) (particle + 0x6) = (s8) (*(s8 *) (particle + 0x6) - 1);
            temp_a0 = *(s8 *) (particle + 0x6);
            if (temp_a0 < 0) {
                lt[0x2C] = var_v0;
                lt[0x2E] = (u8) (lt[0x2E] - 1);
            } else {
                *(s8 *) (particle + 0x7) = (s8) ((s32) (temp_a0 * 0x24 * lt[0x23]) >> 8);
            }
        } while (var_v0 != lt[0x2D]);
        var_a3 = lt[0x2E];
    }

    ctrl = *(u8 **) ((u8 *) arg0 + 0x68);
    temp_t8 = *(s16 *) (ctrl + 0x2);
    lt[0x23] = (u8) temp_t8;
    if (((s32) var_a3 < 8) && (temp_t8 & 0xFF)) {
        temp_v0 = lt[0x2D];
        lt[0x2E] = (u8) (var_a3 + 1);
        temp_t3 = temp_v0 + 1;
        particle = lt + (temp_v0 * 0x18) + 0x30;
        lt[0x2D] = temp_t3;
        if ((temp_t3 & 0xFF) >= 8) {
            lt[0x2D] = 0;
        }
        *(s16 *) (particle + 0x0) = *(s16 *) (lt + 0x0);
        *(s16 *) (particle + 0x2) = *(s16 *) (lt + 0x2);
        *(s8 *) (particle + 0x6) = 7;
        *(s16 *) (particle + 0x4) = *(s16 *) (lt + 0x4);
        *(s8 *) (particle + 0x7) = (s8) ((s32) (7 * 0x24 * lt[0x23]) >> 8);
        *(f32 *) (particle + 0x8) = (f32) *(s16 *) (lt + 0x18);
        *(f32 *) (particle + 0xC) = *(f32 *) (lt + 0xC);
        *(f32 *) (particle + 0x10) = *(f32 *) (lt + 0x10);
        *(f32 *) (particle + 0x14) = *(f32 *) (lt + 0x14);
    }

    *(s16 *) (lt + 0x0) = (s16) (*(s16 *) (lt + 0x0) + *(s16 *) (lt + 0x1A) * arg2);
    *(s16 *) (lt + 0x2) = (s16) (*(s16 *) (lt + 0x2) + (*(s16 *) (lt + 0x1C) * arg2));
    *(f32 *) (lt + 0x10) = (f32) *(s16 *) (lt + 0x6);
    *(f32 *) (lt + 0xC) = 0.0f;
    *(f32 *) (lt + 0x14) = 0.0f;
    *(s16 *) (lt + 0x4) = (s16) (*(s16 *) (lt + 0x4) + (*(s16 *) (lt + 0x1E) * arg2));
    pointListRPY(1, (s16 *) lt, (s32 *) (lt + 0xC), (f32 *) (lt + 0xC));
    *(f32 *) (lt + 0xC) = *(f32 *) (lt + 0xC) + *(f32 *) ((u8 *) arg0 + 0xC);
    light = *(u8 **) (lt + 0x28);
    *(f32 *) (lt + 0x10) = *(f32 *) (lt + 0x10) + *(f32 *) ((u8 *) arg0 + 0x10);
    *(f32 *) (lt + 0x14) = *(f32 *) (lt + 0x14) + *(f32 *) ((u8 *) arg0 + 0x14);
    if (light != NULL) {
        *(f32 *) (light + 0x18) = *(f32 *) (lt + 0xC);
        *(f32 *) (light + 0x1C) = *(f32 *) (lt + 0x10);
        *(f32 *) (light + 0x20) = *(f32 *) (lt + 0x14);
        changeLightIntensity((UnkLight *) light, lt[0x23]);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o64/overlay_64/func_overlay_64_04000340_1F85D58.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_64_040005E8_1F86000(void *arg0, void *arg1, s32 arg2) {
    func_overlay_64_04000340_1F85D58(arg0, arg1, arg2);
    func_overlay_64_04000244_1F85C5C(arg1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o64/overlay_64/func_overlay_64_040005E8_1F86000.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 lightShowInit(void *arg0, void *arg1) {
    s32 hdrBuf[6];
    u8 *hdr;
    u8 *ctrl;
    u8 *slot;
    u8 *entry;
    u8 *lightData;
    u8 *alloc;
    u8 count;
    s32 i;
    f32 var_f6;

    hdr = (u8 *) hdrBuf;
    lightData = (u8 *) arg1;
    ctrl = *(u8 **) ((u8 *) arg0 + 0x68);
    alloc = (u8 *) mmAlloc(lightData[0xA] * 0x258, 0xFF0000FFU);
    *(u8 **) (ctrl + 0x4) = alloc;
    if (alloc != NULL) {
        slot = alloc;
        ctrl[0] = lightData[0xA];
        *(s16 *) (ctrl + 0x2) = (s16) lightData[0xB];
        count = lightData[0xA];
        entry = lightData + 0xC;
        for (i = 0; i < count; i++) {
            *(s16 *) (slot + 0x0) = (s16) (((s8) entry[0]) << 8);
            *(s16 *) (slot + 0x2) = (s16) (((s8) entry[1]) << 8);
            *(s16 *) (slot + 0x4) = (s16) (((s8) entry[2]) << 8);
            *(s16 *) (slot + 0x6) = (s16) (entry[0xB] * 4);
            var_f6 = (f32) (u8) entry[9];
            *(f32 *) (slot + 0x8) = var_f6 * D_overlay_64_04000D60;
            *(f32 *) (slot + 0xC) = 0.0f;
            *(f32 *) (slot + 0x14) = 0.0f;
            *(f32 *) (slot + 0x10) = (f32) *(s16 *) (slot + 0x6);
            pointListRPY(1, (s16 *) slot, (s32 *) (slot + 0xC), (f32 *) (slot + 0xC));
            *(f32 *) (slot + 0xC) = *(f32 *) (slot + 0xC) + *(f32 *) ((u8 *) arg0 + 0xC);
            *(f32 *) (slot + 0x10) = *(f32 *) (slot + 0x10) + *(f32 *) ((u8 *) arg0 + 0x10);
            *(f32 *) (slot + 0x14) = *(f32 *) (slot + 0x14) + *(f32 *) ((u8 *) arg0 + 0x14);
            *(s16 *) (slot + 0x18) = (s16) entry[0xA];
            *(s16 *) (slot + 0x1A) = (s16) (entry[3] * 0x10);
            *(s16 *) (slot + 0x1C) = (s16) (entry[4] * 0x10);
            *(s16 *) (slot + 0x1E) = (s16) (entry[5] * 0x10);
            slot[0x20] = entry[6];
            slot[0x21] = entry[7];
            slot[0x22] = entry[8];
            *(f32 *) (slot + 0x24) = 0.0f;
            slot[0x23] = lightData[0xB];
            if (entry[0xC] & 1) {
                hdr[0x0] = 1;
                hdr[0x1] = 3;
                hdr[0x2] = (s8) entry[0xC];
                hdr[0x3] = 0xFF;
                *(s16 *) (hdr + 0x4) = 0;
                *(s16 *) (hdr + 0x6) = 0;
                *(s16 *) (hdr + 0x8) = 0;
                *(s16 *) (hdr + 0xA) = 0;
                *(s16 *) (hdr + 0xC) = 0xC0;
                *(s16 *) (hdr + 0xE) = 0xC0;
                hdr[0x10] = slot[0x20];
                hdr[0x11] = slot[0x21];
                hdr[0x12] = slot[0x22];
                hdr[0x13] = slot[0x23];
                *(s16 *) (hdr + 0x14) = -1;
                hdr[0x16] = 0;
                hdr[0x17] = 0;
                *(void **) (slot + 0x28) = (void *) addObjectLight(NULL, (ObjectHeader48 *) hdr);
            } else {
                *(void **) (slot + 0x28) = NULL;
            }
            slot[0x2C] = 0;
            slot[0x2D] = 0;
            slot[0x2E] = 0;
            slot[0x2F] = 1;
            entry += 0xE;
            slot += 0x258;
        }
    } else {
        ctrl[0] = 0;
    }
    *(s32 *) ((u8 *) arg0 + 0x3C) = 0;
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o64/overlay_64/lightShowInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 lightShowControl(void *arg0, s32 arg1) {
    u8 *temp_v1;
    u8 *var_s1;
    u8 temp_s0;
    u8 var_s0;
    u8 var_v0;

    temp_v1 = *(u8 **) ((u8 *) arg0 + 0x68);
    temp_s0 = temp_v1[0];
    var_s1 = *(u8 **) (temp_v1 + 0x4);
    var_v0 = temp_s0;
    var_s0 = temp_s0 - 1;
    if (temp_s0 != 0) {
        do {
            func_overlay_64_040005E8_1F86000(arg0, var_s1, arg1);
            var_s1 += 0x258;
            var_v0 = var_s0;
            var_s0 -= 1;
        } while (var_s0 != 0);
    }
    return var_v0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o64/overlay_64/lightShowControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_64_04000954_1F8636C(void **arg0, void *arg1) {
    u8 *slot;
    u32 *gfx;
    u32 vtxAddr;
    s32 temp_v1;
    s32 temp_a0;

    slot = (u8 *) arg1;
    if (slot[0x2E] != 0) {
        gfx = (u32 *) *arg0;
        *arg0 = gfx + 2;
        gfx[1] = 0xFFFFFFFF;
        gfx[0] = 0xFA000000;

        gfx = (u32 *) *arg0;
        *arg0 = gfx + 2;
        gfx[0] = 0xFB000000;
        gfx[1] = (slot[0x20] << 24) | (slot[0x21] << 16) | (slot[0x22] << 8) | 0xFF;

        gfx = (u32 *) *arg0;
        *arg0 = gfx + 2;
        vtxAddr = (u32) (slot + slot[0x2F] * 0xB4) + 0x800000F0;
        temp_v1 = slot[0x2E] * 2;
        temp_a0 = temp_v1 + 2;
        gfx[0] = ((((temp_a0 * 8) | (vtxAddr & 6)) & 0xFF) << 16) | 0x04000000 | (((temp_a0 * 0xA) + 8) & 0xFFFF);
        gfx[1] = vtxAddr;

        gfx = (u32 *) *arg0;
        *arg0 = gfx + 2;
        gfx[1] = (u32) &D_84000C60;
        gfx[0] = ((((temp_v1 - 1) * 0x10) | 1) & 0xFF) << 16 | 0x05000000 | ((temp_v1 * 0x10) & 0xFFFF);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o64/overlay_64/func_overlay_64_04000954_1F8636C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_64_04000A84_1F8649C(Gfx **arg0, s32 arg1, s32 arg2, void *arg3, s32 arg4) {
    u8 *slot;

    slot = (u8 *) arg3;
    if (slot[0x23] != 0) {
        sprSetIA2ColOverride(0xFF, 0xFF, 0xFF, slot[0x20], slot[0x21], slot[0x22]);
        camDoSprite(arg0, arg1, arg2, arg3, arg4, 0xE, (s32) slot[0x23]);
        sprClearIA2ColOverride();
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o64/overlay_64/func_overlay_64_04000A84_1F8649C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void lightShowDraw(Gfx **arg0, s32 arg1, s32 arg2, void *arg3) {
    u8 *ctrl;
    u8 *var_s1;
    u8 count;
    s32 i;
    u32 *gfx;

    ctrl = *(u8 **) ((u8 *) arg3 + 0x68);
    camRestoreModelMtx(arg0);
    texDPTextureX(arg0, *(s32 *) *(u8 **) ((u8 *) arg3 + 0x6C), 0x213, 0);
    count = ctrl[0];
    if (count != 0) {
        var_s1 = *(u8 **) (ctrl + 0x4);
        for (i = 0; i < count; i++) {
            func_overlay_64_04000954_1F8636C((void **) arg0, var_s1);
            var_s1 += 0x258;
        }
        var_s1 = *(u8 **) (ctrl + 0x4);
        for (i = 0; i < count; i++) {
            func_overlay_64_04000A84_1F8649C(arg0, arg1, arg2, var_s1,
                *(s32 *) *(u8 **) (*(u8 **) ((u8 *) arg3 + 0x40) + 0xAC));
            var_s1 += 0x258;
        }
    }

    gfx = (u32 *) *arg0;
    *arg0 = (Gfx *) (gfx + 2);
    gfx[1] = 0;
    gfx[0] = 0xE7000000;

    gfx = (u32 *) *arg0;
    *arg0 = (Gfx *) (gfx + 2);
    gfx[0] = 0xFA000000;
    gfx[1] = 0xFFFFFFFF;

    gfx = (u32 *) *arg0;
    *arg0 = (Gfx *) (gfx + 2);
    gfx[1] = 0xFFFFFFFF;
    gfx[0] = 0xFB000000;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o64/overlay_64/lightShowDraw.s")
#endif
