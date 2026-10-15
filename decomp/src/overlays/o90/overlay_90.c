#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#define RD_U8(p, off)  (*(u8 *)((u8 *)(p) + (off)))
#define RD_S8(p, off)  (*(s8 *)((u8 *)(p) + (off)))
#define RD_S16(p, off) (*(s16 *)((u8 *)(p) + (off)))
#define RD_S32(p, off) (*(s32 *)((u8 *)(p) + (off)))
#define RD_F32(p, off) (*(f32 *)((u8 *)(p) + (off)))
#define RD_PTR(p, off) (*(u8 **)((u8 *)(p) + (off)))

extern f32 D_overlay_90_05A006D0;
extern f32 D_overlay_90_05A006D4;
extern f32 D_overlay_90_05A006D8;
extern f32 D_overlay_90_05A006DC;
extern f32 D_overlay_90_05A006E0;
extern f32 D_overlay_90_05A006E4;
extern s32 D_overlay_90_05A00670[4];
extern s32 D_overlay_90_05A00680[4];
extern s32 D_overlay_90_05A00690[4];
extern s32 D_overlay_90_05A006A0[4];
extern s32 D_overlay_90_05A006B0[4];
extern f32 D_overlay_90_05A006C0[4];

void mathOneFloatPY(void *obj, f32 *out);
s16 trackGetBlock(f32 x, f32 y, f32 z, s32 frame);
void sparkAdd(void *spark);
void sparkSetGravity(f32 gravity);
void partUpdateTriggers(void *obj, s32 arg1);
void objFreeObject(void *obj);
void func_overlay_90_05A00000_1FB2D20(void *arg0, void *arg1);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_90_05A00000_1FB2D20(void *arg0, void *arg1) {
    RD_F32(arg0, 0x24) = (f32)(-RD_S16(arg1, 0x1C)) * D_overlay_90_05A006D0;
    mathOneFloatPY(arg0, (f32 *)((u8 *)arg0 + 0x1C));
    RD_F32(arg0, 0x0C) = RD_F32(arg1, 0x10);
    RD_F32(arg0, 0x10) = RD_F32(arg1, 0x14);
    RD_F32(arg0, 0x14) = RD_F32(arg1, 0x18);
    /* asm: trackGetBlock gets the frame/arg1 in a3 */
    RD_S16(arg0, 0x2E) = trackGetBlock(RD_F32(arg0, 0x0C), RD_F32(arg0, 0x10), RD_F32(arg0, 0x14),
                                       (s32)arg1);
    RD_U8(arg1, 0x00) = 0;
    RD_S32(arg0, 0x88) = RD_S32(arg0, 0x8C);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o90/overlay_90/func_overlay_90_05A00000_1FB2D20.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fireworkInit(void *arg0, void *arg1) {
    u8 *state = RD_PTR(arg0, 0x68);
    u8 *lightSlot;
    s32 idx = RD_U8(arg1, 0x13) & 3;

    RD_S16(arg0, 0x00) = RD_S16(arg1, 0x0A);
    RD_S16(arg0, 0x02) = RD_S16(arg1, 0x0C);
    RD_F32(arg0, 0x24) = (f32)(-RD_S16(arg1, 0x0E)) * D_overlay_90_05A006D4;
    mathOneFloatPY(arg0, (f32 *)((u8 *)arg0 + 0x1C));

    RD_U8(state, 0x00) = 0;
    RD_U8(state, 0x01) = RD_U8(arg1, 0x10);
    RD_U8(state, 0x02) = RD_U8(arg1, 0x11);
    RD_U8(state, 0x03) = RD_U8(arg1, 0x12);
    RD_S8(state, 0x05) = (s8)D_overlay_90_05A00670[idx];
    RD_S8(state, 0x06) = (s8)D_overlay_90_05A00680[idx];
    RD_S8(state, 0x07) = (s8)D_overlay_90_05A00690[idx];
    RD_S16(state, 0x08) = (s16)D_overlay_90_05A006A0[idx];
    RD_S16(state, 0x0A) = (s16)D_overlay_90_05A006B0[idx];
    RD_F32(state, 0x0C) = D_overlay_90_05A006C0[idx];
    RD_F32(state, 0x10) = RD_F32(arg0, 0x0C);
    RD_F32(state, 0x14) = RD_F32(arg0, 0x10);
    RD_F32(state, 0x18) = RD_F32(arg0, 0x14);
    RD_S16(state, 0x1C) = RD_S16(arg1, 0x0E);
    RD_S16(state, 0x1E) = (s16)((RD_S16(arg1, 0x16) * 0x3C) / 100);

    lightSlot = RD_PTR(arg0, 0x74);
    if (lightSlot != NULL) {
        u8 *light = *(u8 **)lightSlot;

        if (light != NULL) {
            changeLightColour((UnkLight *)light, RD_U8(state, 0x01), RD_U8(state, 0x02), RD_U8(state, 0x03));
        }
    }
    RD_S32(arg0, 0x88) = (s32)((RD_S16(arg1, 0x14) * 0x3C) / 100);
    RD_S32(arg0, 0x8C) = RD_S16(state, 0x1E);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o90/overlay_90/fireworkInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fireworkControl(void *arg0, s32 arg1) {
    u8 *state = RD_PTR(arg0, 0x68);
    u8 *lightSlot = RD_PTR(arg0, 0x74);
    UnkLight *sp40 = (lightSlot != NULL) ? (UnkLight *)*(u8 **)lightSlot : NULL;
    s32 i;
    s32 count;
    s32 t4;
    s32 v0;

    RD_S32(arg0, 0x84) = 0;
    RD_F32(arg0, 0x08) = RD_F32(RD_PTR(arg0, 0x40), 0x00);
    RD_S32(arg0, 0x8C) = RD_S32(arg0, 0x8C) - arg1;

    if (RD_S32(arg0, 0x88) > 0) {
        RD_S16(arg0, 0x06) = (s16)(RD_S16(arg0, 0x06) | 0x400);
        t4 = RD_S32(arg0, 0x88) - arg1;
        RD_S32(arg0, 0x88) = t4;
        if (t4 <= 0) {
            RD_S32(arg0, 0x8C) = RD_S16(state, 0x1E) + t4;
        }
        goto done;
    }

    if (RD_U8(state, 0x00) == 0) {
        RD_S16(arg0, 0x06) = (s16)(RD_S16(arg0, 0x06) & 0xFBFF);
        for (i = 0; i < arg1; i++) {
            f32 f0 = RD_F32(arg0, 0x1C);
            f32 f2 = RD_F32(arg0, 0x20);
            f32 f12;

            RD_F32(arg0, 0x0C) = RD_F32(arg0, 0x0C) + f0;
            f12 = RD_F32(arg0, 0x24);
            RD_F32(arg0, 0x10) = RD_F32(arg0, 0x10) + f2;
            RD_F32(arg0, 0x1C) = f0 * D_overlay_90_05A006DC;
            RD_F32(arg0, 0x24) = f12 * D_overlay_90_05A006DC;
            RD_F32(arg0, 0x20) = f2 - D_overlay_90_05A006D8;
            RD_F32(arg0, 0x14) = RD_F32(arg0, 0x14) + f12;
        }
        /* asm: trackGetBlock is called with 3 args here (a3 unused) */
        RD_S16(arg0, 0x2E) = ((s16 (*)(f32, f32, f32))trackGetBlock)(RD_F32(arg0, 0x0C),
                                                                    RD_F32(arg0, 0x10),
                                                                    RD_F32(arg0, 0x14));
        if (RD_F32(arg0, 0x20) < 0.0f) {
            RD_U8(state, 0x00) = 1;
        }
        if (sp40 != NULL) {
            changeLightIntensity(sp40, 0x40);
        }
        RD_S32(arg0, 0x84) = 1;
        goto done;
    }

    if (RD_U8(state, 0x00) < 3) {
        u8 spark[0x24];

        RD_F32(arg0, 0x08) = RD_F32(arg0, 0x08) * RD_F32(state, 0x0C);
        RD_F32(spark, 0x08) = RD_F32(arg0, 0x0C);
        RD_F32(spark, 0x0C) = RD_F32(arg0, 0x10);
        RD_F32(spark, 0x10) = RD_F32(arg0, 0x14);
        RD_F32(spark, 0x14) = 10.0f;
        RD_S16(spark, 0x18) = 0x14;
        RD_U8(spark, 0x1B) = 0xFF;
        RD_S32(spark, 0x1C) = -1;
        RD_S32(spark, 0x20) = (RD_U8(state, 0x01) << 24) | (RD_U8(state, 0x02) << 16) |
                              (RD_U8(state, 0x03) << 8) | 0xFF;
        sparkSetGravity(D_overlay_90_05A006E0);

        count = RD_U8(state, 0x05) >> 1;
        for (i = 0; i < count; i++) {
            RD_S16(spark, 0x00) = mathRnd(-0x8000, 0x7FFF);
            RD_S16(spark, 0x02) = mathRnd(-0x4000, 0x4000);
            RD_F32(spark, 0x04) = (f32)mathRnd(RD_S16(state, 0x08), RD_S16(state, 0x0A)) * D_overlay_90_05A006E4;
            RD_U8(spark, 0x1A) = mathRnd(RD_U8(state, 0x06), RD_U8(state, 0x07));
            sparkAdd(spark);
        }
        RD_U8(state, 0x00) = (u8)(RD_U8(state, 0x00) + 1);
        if (sp40 != NULL) {
            changeLightIntensity(sp40, 0xFF);
        }
        goto done;
    }

    RD_S16(arg0, 0x06) = (s16)(RD_S16(arg0, 0x06) | 0x400);
    v0 = (u8)(RD_U8(state, 0x00) + arg1) & 0xFF;
    RD_U8(state, 0x00) = (u8)v0;
    if (v0 >= 0x7B) {
        if (RD_S16(state, 0x1E) == 0) {
            objFreeObject(arg0);
            return;
        }
        func_overlay_90_05A00000_1FB2D20(arg0, state);
        goto done;
    }
    if (sp40 != NULL) {
        changeLightIntensity(sp40, (s32)(255.0f * (1.0f - ((f32)(v0 - 2) / 120.0f))) & 0xFF);
    }

done:
    partUpdateTriggers(arg0, arg1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o90/overlay_90/fireworkControl.s")
#endif
