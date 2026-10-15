#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern s32 D_overlay_81_05100BE0;
extern u8 D_overlay_81_05100BE8[];
extern TextureHeader *D_overlay_81_05100C08;
extern s32 D_overlay_81_05100C2C;
extern s32 D_overlay_81_05100C44;
extern s32 D_overlay_81_05100C5C;
extern s32 D_overlay_81_05100C74;
extern f32 D_overlay_81_05100C10;
extern f32 D_overlay_81_05100C14;
extern f32 D_overlay_81_05100C18;
extern u8 D_overlay_81_05100C20[];
void texFreeTexture(TextureHeader *tex);
void texDPTextureX(Gfx **dl, TextureHeader *tex, s32 arg2, s32 arg3);
f32 Sinf(s32 angle);
void mathRpyXyzMtx(f32 (*mtx)[4], s16 *rpy);
void mathMtxCatF(f32 (*a)[4], f32 (*b)[4], f32 (*out)[4]);
s32 camGetProjOrgMtx(void);
void *camGetRotationMtx(void);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_81_05100000_1FABF58(void) {
    TextureHeader *tex;
    s16 width;

    tex = texLoadTexture(0x257);
    D_overlay_81_05100C08 = tex;
    if (tex != NULL) {
        width = (tex->width - 1) << 5;
        *(s16 *)(D_overlay_81_05100BE8 + 0x8) = width;
        *(s16 *)(D_overlay_81_05100BE8 + 0xE) = width;
        *(s16 *)(D_overlay_81_05100BE8 + 0x14) = width;
        *(s16 *)(D_overlay_81_05100BE8 + 0x1A) = width;
        *(s16 *)(D_overlay_81_05100BE8 + 0x1C) = width;
        *(s16 *)(D_overlay_81_05100BE8 + 0x1E) = width;
        D_overlay_81_05100C2C = 0;
        D_overlay_81_05100C44 = 0;
        D_overlay_81_05100C5C = 0;
        D_overlay_81_05100C74 = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o81/overlay_81/func_overlay_81_05100000_1FABF58.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *chargeEffectCreate(s32 arg0, s32 arg1, s32 arg2, f32 arg3, f32 arg4) {
    u8 *rec;
    u8 *arr;
    u8 *p;
    s32 idx;
    s32 i;
    s32 k;

    rec = NULL;
    if (D_overlay_81_05100BE0 >= 4) {
        return NULL;
    }
    if (D_overlay_81_05100BE0 == 0) {
        func_overlay_81_05100000_1FABF58();
    }

    /* find the next free header slot in the 0x18-byte table */
    idx = 0;
    if (*(void **)(D_overlay_81_05100C20 + 0xC) != NULL) {
        do {
            idx++;
        } while (*(void **)(D_overlay_81_05100C20 + idx * 0x18 + 0x24) != NULL);
    }

    rec = D_overlay_81_05100C20 + idx * 0x18;
    rec[0] = 0;
    rec[1] = 0;
    rec[2] = 0;
    rec[3] = (u8) arg0;
    rec[4] = 0;
    rec[5] = (u8) arg1;
    rec[6] = (u8) arg2;
    rec[7] = (u8) (s32) (arg3 * D_overlay_81_05100C10);
    *(f32 *)(rec + 0x8) = arg4 * D_overlay_81_05100C14;

    arr = (u8 *) mmAlloc(arg0 * 0x68, 0xFF00FF);
    *(u8 **)(rec + 0xC) = arr;
    if (arr == NULL) {
        return NULL;
    }

    /* clear the first byte of each particle */
    for (i = 0; i < arg0; i++) {
        arr[i * 0x18] = 0;
    }

    /* sub-arrays used as vertex/colour buffers */
    *(u8 **)(rec + 0x10) = arr + arg0 * 0x18;
    *(u8 **)(rec + 0x14) = arr + arg0 * 0x18 + arg0 * 0x28;

    for (k = 0; k < 2; k++) {
        p = *(u8 **)(rec + 0x10 + k * 4);
        for (i = 0; i < arg0 * 4; i++) {
            p[0x6 + i * 0xA] = 0xFF;
            p[0x7 + i * 0xA] = 0xFF;
            p[0x8 + i * 0xA] = 0xFF;
            p[0x9 + i * 0xA] = 0xFF;
        }
    }

    D_overlay_81_05100BE0 += 1;
    return rec;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o81/overlay_81/chargeEffectCreate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void chargeEffectFree(void *arg0) {
    u8 *rec;
    void *arr;
    s32 count;

    rec = (u8 *) arg0;
    arr = *(void **)(rec + 0xC);
    if (arr != NULL) {
        mmFree(arr);
        *(u8 **)(rec + 0xC) = (u8 *) arr - 0x18;
        count = D_overlay_81_05100BE0 - 1;
        if (D_overlay_81_05100BE0 == 1 && D_overlay_81_05100C08 != NULL) {
            /* asm also passes arg0 in a1, callee ignores it */
            texFreeTexture(D_overlay_81_05100C08);
            D_overlay_81_05100C08 = NULL;
        }
        D_overlay_81_05100BE0 = count;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o81/overlay_81/chargeEffectFree.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void chargeEffectSetPower(void *arg0, f32 arg1) {
    u8 *rec;
    f32 power;

    rec = (u8 *) arg0;
    power = arg1;
    if (power < 0.0f) {
        power = 0.0f;
    }
    if (power > 1.0f) {
        power = 1.0f;
    }
    rec[2] = (s8) (s32) ((f32) rec[3] * power);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o81/overlay_81/chargeEffectSetPower.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 chargeEffectUpdate(void *arg0, s32 arg1) {
    u8 *rec;
    u8 *p;
    u8 *newp;
    s32 i;
    s32 spawn;
    s32 ret;
    s32 k;
    s32 angA;
    s32 angB;
    f32 size;
    f32 vel;
    f32 sinA;
    f32 dt;

    rec = (u8 *) arg0;
    spawn = 0;
    if (rec[0] != 0) {
        p = *(u8 **)(rec + 0xC);
        if (rec[3] > 0) {
            for (i = 0; i < (s32) rec[3]; i++, p += 0x18) {
                if (p[0] != 0) {
                    *(s16 *)(p + 0x2) = (s16) (*(s16 *)(p + 0x2) + arg1 * 0x10);
                    dt = (f32) arg1;
                    if (*(s16 *)(p + 0x2) >= 0x100) {
                        *(s16 *)(p + 0x2) = 0xFF;
                    }
                    *(f32 *)(p + 0x14) = *(f32 *)(p + 0x14) + D_overlay_81_05100C18 * dt;
                    *(f32 *)(p + 0x10) = *(f32 *)(p + 0x10) - *(f32 *)(p + 0x14) * dt;
                    if (*(f32 *)(p + 0x10) <= 0.0f) {
                        p[0] = 0;
                        rec[0] = (u8) (rec[0] - 1);
                    }
                }
            }
        }
    }

    if (rec[0] < rec[2]) {
        spawn = rec[2] - rec[0];
        if (spawn >= 5) {
            spawn = 4;
        }
    }
    ret = spawn;

    for (k = 0; k < spawn; k++) {
        /* find the first inactive particle */
        newp = *(u8 **)(rec + 0xC);
        if (newp[0] != 0) {
            do {
                i = newp[0x18];
                newp += 0x18;
            } while (i != 0);
        }

        angA = mathRnd(-0x8000, 0x7FFF);
        angB = mathRnd(0, rec[7] << 7);
        size = (f32) mathRnd(0x3C, 0x64);

        newp[0] = 1;
        *(s16 *)(newp + 0x2) = 0;
        vel = size * *(f32 *)(rec + 0x8);
        newp[1] = (u8) mathRnd((s32) rec[5], (s32) rec[6]);

        sinA = Sinf(angB);
        *(f32 *)(newp + 0x4) = Sinf(angA) * (vel * sinA);
        *(f32 *)(newp + 0x8) = Cosf(angB) * vel;
        *(f32 *)(newp + 0xC) = Cosf(angA) * (vel * Sinf(angB));
        *(f32 *)(newp + 0x10) = 1.0f;
        *(f32 *)(newp + 0x14) = 0.0f;
        rec[0] = (u8) (rec[0] + 1);

        ret = spawn - 1 - k;
    }
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o81/overlay_81/chargeEffectUpdate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void chargeEffectDraw(Gfx **dl, void *arg1, void *arg2, s16 *vec, void *arg4, f32 (*arg5)[4]) {
    u8 *rec;
    u8 *p;

    s32 count;
    s32 i;
    s32 which;
    s32 x;
    s32 y;
    s32 z;
    s32 colR;
    s32 colB;
    s32 envDiv;
    s32 projAddr;
    s32 vtxAddr;
    s32 s;
    f32 scale;
    f32 px;
    f32 py;
    f32 pz;
    f32 sx;
    f32 sy;
    f32 sz;
    f32 view[4][4];
    f32 rotM[4][4];
    f32 combM[4][4];
    f32 finalM[4][4];
    s16 rpy[3];
    void *camRot;
    Gfx *gdl;

    rec = (u8 *) arg2;
    if (rec[0] == 0) {
        return;
    }

    camRot = camGetRotationMtx();
    rpy[0] = vec[0];
    rpy[1] = vec[1];
    rpy[2] = vec[2];

    /* view matrix copy with the translation row cleared */
    for (i = 0; i < 16; i++) {
        ((f32 *) view)[i] = ((f32 *) arg5)[i];
    }
    view[3][0] = 0.0f;
    view[3][1] = 0.0f;
    view[3][2] = 0.0f;

    mathRpyXyzMtx(rotM, rpy);
    mathMtxCatF(rotM, view, combM);
    mathMtxCatF(combM, (f32 (*)[4]) camRot, finalM);

    projAddr = camGetProjOrgMtx();
    gdl = *dl;
    *dl = gdl + 1;
    gdl->words.w0 = 0x01010040;
    gdl->words.w1 = projAddr + 0x80000000;

    texDPTextureX(dl, D_overlay_81_05100C08, 0x216, 0);

    gdl = *dl;
    envDiv = ((s32) (rec[0] << 0x10)) / (s32) rec[3];
    *dl = gdl + 1;
    gdl->words.w0 = 0xFB000000;
    gdl->words.w1 = ((((s32) (envDiv * -0xFF) >> 0x10) + 0xFF) << 0x18)
                  | ((((s32) (envDiv * 0xFF) >> 0x10) & 0xFF) << 8) | 0xFF;

    which = 1 - rec[4];
    rec[4] = (u8) which;
    p = *(u8 **)(rec + 0x10 + ((which & 0xFF) << 2));
    count = (s32) rec[3];

    for (i = 0; i < count; i++) {
        u8 *cur;

        cur = *(u8 **)(rec + 0xC) + i * 0x18;
        if (cur[0] != 0) {
            scale = *(f32 *)(cur + 0x10);
            mathMtxXFMF(finalM, *(f32 *)(cur + 0x4) * scale, *(f32 *)(cur + 0x8) * scale,
                     *(f32 *)(cur + 0xC) * scale, &sx, &sy, &sz);
            x = (s32) sx;
            y = (s32) sy;
            z = (s32) sz;
            s = cur[1];

            gdl = *dl;
            *dl = gdl + 1;
            gdl->words.w0 = 0xFA000000;
            colR = (s32) (scale * 0.0f) + 0xFF;
            colB = ((s32) (scale * -170.0f) + 0xFF) & 0xFF;
            gdl->words.w1 = (colR << 0x18) | ((colR & 0xFF) << 0x10) | (colB << 8) | 0xFF;

            vtxAddr = (s32) p + 0x80000000;
            gdl = *dl;
            *dl = gdl + 1;
            gdl->words.w0 = ((((vtxAddr & 6) | 0x20) & 0xFF) << 0x10) | 0x04000000 | 0x30;
            gdl->words.w1 = vtxAddr;

            gdl = *dl;
            *dl = gdl + 1;
            gdl->words.w0 = 0x05110020;
            gdl->words.w1 = (u32) D_overlay_81_05100BE8 + 0x80000000;

            /* four vertices, 0xA bytes each, around the projected centre */
            *(s16 *)(p + 0x0) = (s16) (x - s);
            *(s16 *)(p + 0x2) = (s16) (y + s);
            *(s16 *)(p + 0x4) = (s16) z;
            p[0x9] = cur[2];
            *(s16 *)(p + 0xA) = (s16) (x + s);
            *(s16 *)(p + 0xC) = (s16) (y + s);
            *(s16 *)(p + 0xE) = (s16) z;
            p[0x13] = cur[2];
            *(s16 *)(p + 0x14) = (s16) (x - s);
            *(s16 *)(p + 0x16) = (s16) (y - s);
            *(s16 *)(p + 0x18) = (s16) z;
            p[0x1D] = cur[2];
            *(s16 *)(p + 0x1E) = (s16) (x + s);
            *(s16 *)(p + 0x20) = (s16) (y - s);
            *(s16 *)(p + 0x22) = (s16) z;
            p[0x27] = cur[2];
            p += 0x28;
        }
    }

    camRestoreModelMtx(dl);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o81/overlay_81/chargeEffectDraw.s")
#endif
