#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#define RD_U8(p, off)  (*(u8 *)((u8 *)(p) + (off)))
#define RD_S8(p, off)  (*(s8 *)((u8 *)(p) + (off)))
#define RD_S16(p, off) (*(s16 *)((u8 *)(p) + (off)))
#define RD_S32(p, off) (*(s32 *)((u8 *)(p) + (off)))
#define RD_F32(p, off) (*(f32 *)((u8 *)(p) + (off)))
#define RD_PTR(p, off) (*(u8 **)((u8 *)(p) + (off)))

extern s32 __MODULE00089;

void objRegisterDependancy(void *obj, void *target);
void lightObject(void *obj, void *model, s32 arg2, void *arg3);
void modGenAnimMatrices(void *model, void *anim, void *obj, f32 arg3, f32 arg4);
void objAnimTextures(void *obj, void *anim, void *model, s8 arg3);
s32 objFreeObject(void *obj);
void runlinkSetDestructTimer(s32 module, s32 a, s32 b);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 GetVtxPosition(void *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    u8 *model = *(u8 **)(RD_PTR(arg0, 0x6C) + RD_S8(arg0, 0x3A) * 4);
    u8 *header = RD_PTR(model, 0x00);
    s32 count = RD_S16(header, 0x16);
    u8 *sub = RD_PTR(header, 0x24);
    s32 i, j, k;

    if (RD_U8(arg0, 0xA0) != 0) {
        *arg2 = RD_F32(arg0, 0x0C);
        *arg3 = RD_F32(arg0, 0x10);
        *arg4 = RD_F32(arg0, 0x14);
        return 0;
    }

    for (i = 0; i < count; i++, sub += 0x10) {
        s32 start;
        s32 num;
        u8 *vtx;

        if (RD_S32(sub, 0x0C) & 0x400) {
            continue;
        }
        start = RD_S16(sub, 0x08);
        num = RD_S16(sub, 0x18) - start;
        vtx = RD_PTR(header, 0x20) + start * 0x10;

        for (j = 0; j < num; j++, vtx += 0x10) {
            for (k = 0; k < 3; k++) {
                s32 idx = RD_U8(vtx, 1 + k);
                s32 vi = idx + RD_S16(sub, 0x06);

                if (vi == arg1) {
                    u8 *v = RD_PTR(model, 0x04) + vi * 0x0A;
                    s32 sel;
                    u8 *mtx;

                    if (idx < RD_S8(sub, 0x04)) {
                        sel = RD_S8(sub, 0x01);
                    } else if (idx < RD_S8(sub, 0x05)) {
                        sel = RD_S8(sub, 0x02);
                    } else {
                        sel = RD_S8(sub, 0x03);
                    }
                    mtx = RD_PTR(model + RD_S8(model, 0x0B) * 4, 0x10) + (sel << 6);
                    mathMtxXFMF(mtx, (f32)RD_S16(v, 0x00), (f32)RD_S16(v, 0x02), (f32)RD_S16(v, 0x04),
                                arg2, arg3, arg4);
                    return 1;
                }
            }
        }
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o89/overlay_89/GetVtxPosition.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void electrocutionInit(void *arg0, void *arg1) {
    u8 *state = RD_PTR(arg0, 0x68);
    s32 parent = RD_S32(arg1, 0x0C);

    RD_U8(state, 0x22) = 0;
    RD_S32(state, 0x00) = parent;
    objRegisterDependancy(arg0, (void *)parent);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o89/overlay_89/electrocutionInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 electrocutionControl(void *arg0, s32 arg1) {
    u8 *state = RD_PTR(arg0, 0x68);
    u8 *parent;
    u8 *model;
    u8 *header;
    s32 k;
    s32 last = 0;

    runlinkSetDestructTimer(__MODULE00089, 2, 2);
    if (RD_U8(state, 0x23) != 0) {
        return objFreeObject(arg0);
    }
    parent = RD_PTR(state, 0x00);
    model = *(u8 **)(RD_PTR(parent, 0x6C) + RD_S8(parent, 0x3A) * 4);
    header = RD_PTR(model, 0x00);

    if (RD_S16(parent, 0x48) != 0x18 && RD_U8(model, 0x0A) != 0) {
        if (RD_S8(header, 0x4E) != 0) {
            modGenAnimMatrices(model, header, arg0, 1.0f, 0.0f);
            lightObject(arg0, model, RD_S32(arg0, 0x54), RD_PTR(model + RD_S8(model, 0x0B) * 4, 0x10));
        } else {
            if (RD_U8(header, 0x11) != 0) {
                RD_S8(model, 0x0B) = (s8)(1 - RD_S8(model, 0x0B));
            }
            lightObject(arg0, model, RD_S32(arg0, 0x54), RD_PTR(model + RD_S8(model, 0x0B) * 4, 0x10));
        }
        if (RD_U8(header, 0x11) > 0) {
            objAnimTextures(arg0, header, model, RD_S8(model, 0x0A));
        }
        RD_S8(model, 0x0A) = 0;
    }

    /* asm: five jiggling entries; s16 offsets at state+0x12..0x1A, s8 dirs at state+0x1D..0x21 */
    if (RD_U8(state, 0x22) == 0) {
        s32 i;

        RD_U8(state, 0x22) = mathRnd(5, 0x12);
        for (i = 4; i >= 0; i--) {
            RD_S16(state, 0x12 + i * 2) = mathRnd(0, RD_S16(header, 0x12) - 1);
            if (mathRnd(0, 1) != 0) {
                RD_S8(state, 0x1D + i) = 1;
            } else {
                RD_S8(state, 0x1D + i) = -1;
            }
        }
    }

    for (k = 5; k != 0; k--) {
        s32 i = k - 1;

        RD_S16(state, 0x12 + i * 2) = (s16)(RD_S16(state, 0x12 + i * 2) + RD_S8(state, 0x1D + i));
        if (RD_S16(header, 0x12) < RD_S16(state, 0x12 + i * 2)) {
            RD_S16(state, 0x12 + i * 2) = 0;
        }
        last = k;
        if (RD_S16(state, 0x12 + i * 2) < 0) {
            RD_S16(state, 0x12 + i * 2) = (s16)(RD_S16(header, 0x12) - 1);
        }
    }
    RD_U8(state, 0x22) = (u8)(RD_U8(state, 0x22) - 1);
    return last;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o89/overlay_89/electrocutionControl.s")
#endif
