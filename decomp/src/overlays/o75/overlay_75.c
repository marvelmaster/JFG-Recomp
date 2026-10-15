#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern f32 D_overlay_75_04B015DC;
extern f32 D_overlay_75_04B015E0;
extern f32 D_overlay_75_04B015E4;
extern f32 D_overlay_75_04B015E8;
extern f32 D_overlay_75_04B015EC;
extern f32 D_overlay_75_04B015F0;
extern f32 D_overlay_75_04B015F4;
extern f32 D_overlay_75_04B015F8;
extern f32 D_overlay_75_04B015FC;
extern s16 D_overlay_75_04B01600;
extern f32 D_overlay_75_04B01604;
extern f32 D_overlay_75_04B01608;
extern s16 D_overlay_75_04B0160C;
extern u8 D_overlay_75_04B013E0[];
extern s32 D_overlay_75_04B013E8;
extern s32 D_overlay_75_04B013F4;
extern s32 D_overlay_75_04B01400;
extern s32 D_overlay_75_04B0140C;
extern u8 D_overlay_75_04B01410[];
extern u8 D_overlay_75_04B014D0[];
extern char D_overlay_75_04B01540[];
extern char D_overlay_75_04B01554[];
extern char D_overlay_75_04B0156C[];
extern char D_overlay_75_04B01578[];
extern char D_overlay_75_04B01598[];
extern char D_overlay_75_04B015A4[];
extern char D_overlay_75_04B015B4[];
extern void *arcadeScreen;
extern u8 racingReturnSetup;
void *camGetPtr(void);
f32 Powerf(f32);
s32 mathDiffAngle(s16, s16);
void amDittyPlay(s32);
void amSndPlay();
s32 frontGetMode(void);
void *mainGetGameCharacter(s8, s8, void *);
void mainPauseDisable(s32);
void *objGetPlayerNo(s32);
s32 mainPlayerHas(s32, s32, s32);
void camDo2DSprite(Gfx **dl, s32 arg1, s32 arg2, s16 *spr, s32 arg4, s32 arg5, s32 arg6);
void camSetView(Gfx **dl, s32 arg1);
void camStandardOrtho(Gfx **dl, s32 arg1);
void fontBackground(s32, s32, s32, s32);
void fontColour(s32, s32, s32, s32, s32);
void fontPrintXY(Gfx **dl, s32 x, s32 y, char *str, s32 arg5);
void fontUseFont(s32);
void frontDrawRectangles(Gfx **dl, s32 arg1, s16 *rect, s32 arg3);
u32 *func_overlay_75_04B00F00_1FA8030(s16);
void func_overlay_75_04B00F38_1FA8068(Gfx **dl, s32 arg1, s32 arg2, s32 arg3);
void func_overlay_75_04B01224_1FA8354(Gfx **dl, u32 *arg1, s32 arg2, void *arg3);
extern u32 D_800FF32C;
extern u32 D_800FF340;
extern u32 D_800FF368;
extern char D_overlay_75_04B015C4[];
extern char D_overlay_75_04B015C8[];
extern char D_overlay_75_04B015CC[];
extern u8 D_overlay_75_04B01500[];
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void arcadecameraInit(void *arg0) {
    u8 *obj;
    u8 *ctrl;
    u8 *cam;
    f32 sp2C;
    f32 sp28;
    f32 sp24;
    f32 temp_f0;
    f32 temp_f14;

    obj = (u8 *) arg0;
    ctrl = *(u8 **) (obj + 0x68);
    cam = (u8 *) camGetPtr();
    D_overlay_75_04B015EC = *(f32 *) (obj + 0xC);
    D_overlay_75_04B015F0 = *(f32 *) (obj + 0x10);
    D_overlay_75_04B015F4 = *(f32 *) (obj + 0x14);
    D_overlay_75_04B015E0 = *(f32 *) (ctrl + 0x18);
    D_overlay_75_04B015E4 = *(f32 *) (ctrl + 0x1C);
    D_overlay_75_04B015E8 = *(f32 *) (ctrl + 0x20);
    temp_f0 = *(f32 *) (cam + 0xC) - D_overlay_75_04B015EC;
    sp28 = *(f32 *) (cam + 0x10) - D_overlay_75_04B015F0;
    temp_f14 = *(f32 *) (cam + 0x14) - D_overlay_75_04B015F4;
    sp2C = temp_f0;
    sp24 = temp_f14;
    D_overlay_75_04B015F8 = sqrtf((temp_f0 * temp_f0) + (temp_f14 * temp_f14));
    D_overlay_75_04B015FC = sp28;
    D_overlay_75_04B01600 = (s16) (0x8000 - Arctanf(sp2C, temp_f14));
    D_overlay_75_04B01604 = *(f32 *) (ctrl + 0xC);
    D_overlay_75_04B01608 = *(f32 *) (ctrl + 0x10);
    D_overlay_75_04B0160C = (s16) *(s32 *) (ctrl + 0x14);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o75/overlay_75/arcadecameraInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void arcadecameraUpdate(void *arg0, s32 arg1) {
    u8 *obj;
    f32 sp40;
    f32 sp3C;
    f32 sp38;
    s32 temp_v1;
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f2;
    s16 temp_s0;
    s16 temp_s3;
    s32 var_s2;

    obj = (u8 *) arg0;
    temp_f2 = 1.0f - Powerf(D_overlay_75_04B015DC);
    D_overlay_75_04B015F8 += (D_overlay_75_04B01604 - D_overlay_75_04B015F8) * temp_f2;
    D_overlay_75_04B015FC += (D_overlay_75_04B01608 - D_overlay_75_04B015FC) * temp_f2;
    if (arg1 != 0) {
        var_s2 = arg1 - 1;
        do {
            temp_v1 = mathDiffAngle(D_overlay_75_04B01600, D_overlay_75_04B0160C) >> 4;
            if (temp_v1 < -0x200) {
                D_overlay_75_04B01600 -= 0x200;
            } else if (temp_v1 >= 0x201) {
                D_overlay_75_04B01600 += 0x200;
            } else {
                D_overlay_75_04B01600 += temp_v1;
            }
            var_s2 -= 1;
        } while (var_s2 != 0);
    }
    *(f32 *) (obj + 0xC) = (Sinf(D_overlay_75_04B01600) * D_overlay_75_04B015F8) + D_overlay_75_04B015EC;
    *(f32 *) (obj + 0x10) = D_overlay_75_04B015F0 + D_overlay_75_04B015FC;
    *(f32 *) (obj + 0x14) = D_overlay_75_04B015F4 - (Cosf((s32) D_overlay_75_04B01600) * D_overlay_75_04B015F8);
    temp_f12 = *(f32 *) (obj + 0xC) - D_overlay_75_04B015E0;
    sp3C = *(f32 *) (obj + 0x10) - D_overlay_75_04B015E4;
    sp40 = temp_f12;
    temp_f14 = *(f32 *) (obj + 0x14) - D_overlay_75_04B015E8;
    sp38 = temp_f14;
    temp_s3 = 0x8000 - Arctanf(temp_f12, temp_f14);
    temp_s0 = Arctanf(sp3C, sqrtf((sp40 * sp40) + (temp_f14 * temp_f14)));
    if (arg1 != 0) {
        var_s2 = arg1 - 1;
        do {
            *(s16 *) (obj + 0x0) = (s16) (*(s16 *) (obj + 0x0) + (mathDiffAngle(*(s16 *) (obj + 0x0), temp_s3) >> 4));
            *(s16 *) (obj + 0x2) = (s16) (*(s16 *) (obj + 0x2) + (mathDiffAngle(*(s16 *) (obj + 0x2), temp_s0) >> 4));
            var_s2 -= 1;
        } while (var_s2 != 0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o75/overlay_75/arcadecameraUpdate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void arcadeInit(void *arg0, void *arg1) {
    u8 *obj;
    u8 *spawn;
    u8 *ctrl;
    u8 temp_v0;

    obj = (u8 *) arg0;
    spawn = (u8 *) arg1;
    ctrl = *(u8 **) (obj + 0x68);
    *(s16 *) (obj + 0x0) = (s16) (spawn[0x16] << 8);
    temp_v0 = spawn[0xA];
    *(f32 *) (ctrl + 0x0) = (f32) (temp_v0 * temp_v0);
    *(f32 *) (ctrl + 0x4) = *(f32 *) (obj + 0x10) + (f32) ((s8) spawn[0xB]);
    *(f32 *) (ctrl + 0x8) = *(f32 *) (obj + 0x10) + (f32) ((s8) spawn[0xC]);
    *(f32 *) (ctrl + 0xC) = (f32) (spawn[0xD] * 4);
    *(f32 *) (ctrl + 0x10) = (f32) (((s8) spawn[0xE]) * 4);
    *(s32 *) (ctrl + 0x14) = (s32) (((s8) spawn[0xF]) << 8);
    *(f32 *) (ctrl + 0x18) = *(f32 *) (obj + 0xC) + (f32) (((s8) spawn[0x10]) * 4);
    *(f32 *) (ctrl + 0x1C) = *(f32 *) (obj + 0x10) + (f32) (((s8) spawn[0x11]) * 4);
    *(f32 *) (ctrl + 0x20) = *(f32 *) (obj + 0x14) + (f32) (((s8) spawn[0x12]) * 4);
    *(u8 *) (ctrl + 0x28) = 0;
    *(s16 *) (ctrl + 0x24) = *(s16 *) (spawn + 0x14);
    *(u8 *) (ctrl + 0x2A) = 0;
    *(u8 *) (ctrl + 0x2B) = 0;
    *(void **) (ctrl + 0x2C) = NULL;
    *(u8 *) (ctrl + 0x29) = spawn[0x17];
    if (*(s16 *) (ctrl + 0x24) == 0x18D) {
        if (mainPlayerHas(0, 0, 0x1B) == 0) {
            *(s16 *) (ctrl + 0x24) = 0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o75/overlay_75/arcadeInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void arcadeControl(void *arg0, s32 arg1) {
    u8 *obj;
    u8 *ctrl;
    u8 *player;
    u8 *playerCtrl;
    u8 *racer;
    u8 *chr;
    u8 *cam;
    u16 var_a0;
    u8 temp_v0_3;
    u8 temp_t7;
    u8 temp_v1;
    s32 temp_t0;
    s16 temp_v0_2;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f2;

    obj = (u8 *) arg0;
    ctrl = *(u8 **) (obj + 0x68);
    player = (u8 *) objGetPlayerNo(0);
    if (player != NULL) {
        playerCtrl = *(u8 **) (player + 0x68);
        var_a0 = joyGetPressed(0);
        if (ctrl[0x2B] != 0) {
            var_a0 = 0;
        }
        chr = *(u8 **) (ctrl + 0x2C);
        *(s16 *) (ctrl + 0x26) = (s16) (*(s16 *) (ctrl + 0x26) + arg1);
        if (chr == NULL) {
            if ((var_a0 & 0x8000) && (*(s32 *) (playerCtrl + 0x568) == 0) &&
                (*(s16 *) (*(u8 **) (player + 0x4C) + 0x6) >= 0x100)) {
                temp_v0_2 = *(s16 *) (obj + 0x0) - *(s16 *) (player + 0x0);
                if ((temp_v0_2 >= -0x1FFF) && (temp_v0_2 < 0x2000)) {
                    temp_f0 = *(f32 *) (player + 0xC) - *(f32 *) (obj + 0xC);
                    temp_f2 = *(f32 *) (player + 0x14) - *(f32 *) (obj + 0x14);
                    if (((temp_f0 * temp_f0) + (temp_f2 * temp_f2)) < *(f32 *) (ctrl + 0x0)) {
                        temp_f0_2 = *(f32 *) (player + 0x10);
                        if ((*(f32 *) (ctrl + 0x4) <= temp_f0_2) && (temp_f0_2 <= *(f32 *) (ctrl + 0x8))) {
                            *(u8 *) (playerCtrl + 0x198) = 1;
                            *(u8 **) (ctrl + 0x2C) = player;
                            *(s16 *) (ctrl + 0x26) = 0;
                            arcadecameraInit(arg0);
                            mainPauseDisable(0xA);
                        }
                    }
                }
            }
            temp_v0_3 = ctrl[0x2A];
            temp_t0 = arg1 * 4;
            if (temp_t0 < (s32) temp_v0_3) {
                ctrl[0x2A] = (u8) (temp_v0_3 - temp_t0);
            } else {
                ctrl[0x2A] = 0;
            }
        } else {
            racer = *(u8 **) (chr + 0x68);
            if ((s32) ctrl[0x2A] >= 0x81) {
                if (*(s16 *) (ctrl + 0x24) == 0) {
                    if (var_a0 & 0xC000) {
                        *(u8 *) (racer + 0x198) = 2;
                        *(u8 **) (ctrl + 0x2C) = NULL;
                    }
                } else if (var_a0 & 0x4000) {
                    *(u8 *) (racer + 0x198) = 2;
                    *(u8 **) (ctrl + 0x2C) = NULL;
                } else {
                    temp_v1 = ctrl[0x28];
                    if ((temp_v1 == 0) && (var_a0 & 0x8000)) {
                        cam = (u8 *) mainGetGameCharacter(racer[0x0], racer[0x1], racer);
                        if (*(s16 *) (cam + 0x12) > 0) {
                            amDittyPlay(0xD);
                            *(s16 *) (cam + 0x12) = (s16) (*(s16 *) (cam + 0x12) - 1);
                            ctrl[0x28] = 1;
                        } else {
                            amSndPlay(0x16E, 0);
                        }
                    } else if ((temp_v1 != 0) && (var_a0 & 0x9000)) {
                        amSndPlay(0x171, 0, racer);
                        ctrl[0x2B] = 1;
                        racingReturnSetup = ctrl[0x29];
                        mainChangeLevel((s32) *(s16 *) (ctrl + 0x24), 3, 0, frontGetMode(), 1, 0);
                    }
                }
            }
            temp_t7 = ctrl[0x2A] + arg1;
            ctrl[0x2A] = temp_t7;
            if ((temp_t7 & 0xFF) >= 0xC1) {
                ctrl[0x2A] = 0xC0;
            }
        }
        chr = *(u8 **) (ctrl + 0x2C);
        if (chr != NULL) {
            racer = *(u8 **) (chr + 0x68);
            if (*(s32 *) (racer + 0x5C8) < 0xA) {
                *(s32 *) (racer + 0x5C8) = 0xA;
            }
        }
        if ((s32) ctrl[0x2A] < 0x41) {
            if (arg0 == arcadeScreen) {
                arcadeScreen = NULL;
            }
        } else {
            arcadeScreen = arg0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o75/overlay_75/arcadeControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_75_04B00830_1FA7960(Gfx **arg0, s32 arg1) {
    u8 *var_v0;
    u8 *var_v0_2;
    s32 temp_t0;
    s32 temp_t1;
    s32 temp_t3;
    s32 temp_t4;
    s32 temp_t5;
    s32 temp_t6;
    s32 temp_t6_2;

    var_v0 = D_overlay_75_04B013E0;
    do {
        temp_t6 = *(s32 *) (var_v0 + 0x8);
        var_v0 += 0xC;
        *(s32 *) (var_v0 - 0x4) = (temp_t6 & ~0xFF) | (arg1 & 0xFF);
    } while ((u32) var_v0 < (u32) D_overlay_75_04B014D0);
    temp_t0 = *(s32 *) (D_overlay_75_04B013E0 + 0x8);
    temp_t1 = *(s32 *) (D_overlay_75_04B013E0 + 0x14);
    D_overlay_75_04B013E8 = D_overlay_75_04B01400;
    var_v0_2 = D_overlay_75_04B01410;
    D_overlay_75_04B013F4 = D_overlay_75_04B0140C;
    do {
        temp_t3 = *(s32 *) (var_v0_2 + 0x8);
        temp_t4 = *(s32 *) (var_v0_2 + 0x14);
        temp_t5 = *(s32 *) (var_v0_2 + 0x20);
        temp_t6_2 = *(s32 *) (var_v0_2 + 0x2C);
        var_v0_2 += 0x30;
        *(s32 *) (var_v0_2 - 0x40) = temp_t3;
        *(s32 *) (var_v0_2 - 0x34) = temp_t4;
        *(s32 *) (var_v0_2 - 0x28) = temp_t5;
        *(s32 *) (var_v0_2 - 0x1C) = temp_t6_2;
    } while (var_v0_2 != D_overlay_75_04B014D0);
    *(s32 *) (D_overlay_75_04B013E0 + 0xE0) = temp_t0;
    *(s32 *) (D_overlay_75_04B013E0 + 0xEC) = temp_t1;
    frontDrawRectangles(arg0, 0x14, (s16 *) D_overlay_75_04B013E0, 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o75/overlay_75/func_overlay_75_04B00830_1FA7960.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void arcadeDrawScreen(Gfx **arg0, s32 arg1, s32 arg2, void *arg3) {
    u8 *ctrl;
    u8 *cam;
    u8 *racer;
    char sp120[0x40];
    char spE0[0x40];
    char spA0[0x40];
    s32 sp9C;
    s16 sp9A;
    s16 sp98;
    s16 sp96;
    s16 sp94;
    f32 sp90;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    s16 sp6C;
    s16 sp6A;
    s16 sp68;
    s32 sp64;
    u32 *sp60;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_t0;
    s32 temp_t1;
    s32 temp_t2;
    s32 temp_t2_2;
    s32 temp_t2_3;
    s32 temp_t5;
    s32 temp_t9;
    s16 var_a0;
    u32 *temp_v0_2;
    u8 *temp_v0_3;
    u8 *temp_v1;
    u32 *gfx;

    mainPauseDisable(0xA);
    ctrl = *(u8 **) ((u8 *) arg3 + 0x68);
    if (ctrl[0x2A] >= 0x41) {
        fontBackground(0, 0, 0, 0);
        temp_t9 = (ctrl[0x2A] - 0x40) * 4;
        var_t0 = temp_t9;
        if (temp_t9 >= 0x101) {
            var_t0 = 0x100;
        }
        temp_t5 = (s32) (var_t0 * 0x5A) >> 8;
        temp_t2 = (s32) (var_t0 * 0x78) >> 8;
        sp94 = 0xA0 - temp_t2;
        sp96 = 0x78 - temp_t5;
        sp98 = temp_t2 + 0xA0;
        sp9A = temp_t5 + 0x78;
        sp9C = 0xE0;
        frontDrawRectangles(arg0, 1, &sp94, 0);
        temp_t2_2 = (ctrl[0x2A] - 0x80) * 4;
        var_s1 = temp_t2_2;
        if (temp_t2_2 > 0) {
            if (temp_t2_2 >= 0x100) {
                var_s1 = 0xFF;
            }
            temp_v0_2 = func_overlay_75_04B00F00_1FA8030(*(s16 *) (ctrl + 0x24));
            sp60 = temp_v0_2;
            var_a0 = *(s16 *) (ctrl + 0x24);
            if ((var_a0 != 0) && (ctrl[0x28] == 0) && (*(s16 *) (ctrl + 0x26) & 0x200)) {
                func_overlay_75_04B01224_1FA8354(arg0, temp_v0_2, var_s1, ctrl);
            } else {
                temp_v0_3 = *(u8 **) ((u8 *) arg3 + 0x40);
                if (temp_v0_3 != NULL) {
                    temp_v1 = *(u8 **) (temp_v0_3 + 0xAC);
                    if (temp_v1 != NULL) {
                        temp_t1 = *(s32 *) temp_v1;
                        if (temp_t1 != 0) {
                            sp68 = 0;
                            sp6A = 0;
                            sp6C = 0;
                            sp64 = temp_t1;
                            sp70 = 1.0f;
                            sp7C = 1.0f;
                            sp74 = 0.0f;
                            sp78 = 0.0f;
                            sp90 = 0.0f;
                            camStandardOrtho(arg0, arg1);
                            sprSetTextureFilter(0);
                            gfx = (u32 *) *arg0;
                            *arg0 = (Gfx *) (gfx + 2);
                            gfx[0] = 0xFA000000;
                            gfx[1] = (((s32) (var_s1 * 0xE0) >> 8) & 0xFF) | ~0xFF;
                            gfx = (u32 *) *arg0;
                            *arg0 = (Gfx *) (gfx + 2);
                            gfx[0] = 0xFB000000;
                            gfx[1] = 0xFFFFFFFF;
                            camDo2DSprite(arg0, arg1, arg2, &sp68, temp_t1, 4, var_s1);
                            sprSetTextureFilter(1);
                            camSetView(arg0, arg1);
                            gfx = (u32 *) *arg0;
                            *arg0 = (Gfx *) (gfx + 2);
                            gfx[1] = 0xFFFFFFFF;
                            gfx[0] = 0xFA000000;
                            var_a0 = *(s16 *) (ctrl + 0x24);
                        }
                        if (var_a0 == 0x18D) {
                            func_overlay_75_04B00830_1FA7960(arg0, var_s1);
                        }
                    }
                }
            }
            if (ctrl[0x28] != 0) {
                sprintf(sp120, D_overlay_75_04B01540);
            } else {
                sprintf(sp120, D_overlay_75_04B01554);
            }
            sprintf(spE0, D_overlay_75_04B0156C, ctrl[0x28]);
            sprintf(spA0, D_overlay_75_04B01578);
            fontUseFont(2);
            fontColour(0x20, 0xFF, 0x20, 0xFF, var_s1);
            fontPrintXY(arg0, 0xA0, 0x28, D_overlay_75_04B01598, 1);
            fontColour(0xFF, 0xFF, 0xFF, 0xFF, var_s1);
            func_overlay_75_04B00F38_1FA8068(arg0, 0xA0, 0x28, (u32) *sp60 >> 0x12);
            if (*(s16 *) (ctrl + 0x24) != 0) {
                if ((*(s16 *) (ctrl + 0x26) & 0x20) || (ctrl[0x28] != 0)) {
                    fontColour(0xFF, 0xFF, 0x40, 0xFF, var_s1);
                    fontPrintXY(arg0, 0xA0, 0x9E, sp120, 4);
                }
            }
            fontColour(0xFF, 0xFF, 0xFF, 0xFF, var_s1);
            fontPrintXY(arg0, 0xA0, 0xB2, spE0, 4);
            fontColour(0xFF, 0x80, 0x20, 0xFF, var_s1);
            fontPrintXY(arg0, 0xA0, 0xC2, spA0, 4);
        }
        if (*(s16 *) (ctrl + 0x24) == 0) {
            gfx = (u32 *) *arg0;
            *arg0 = (Gfx *) (gfx + 2);
            gfx[1] = 0x808080A0;
            gfx[0] = 0xFA000000;
            gfx = (u32 *) *arg0;
            *arg0 = (Gfx *) (gfx + 2);
            gfx[1] = 0xFFFFFFFF;
            gfx[0] = 0xFB000000;
            gfx = (u32 *) *arg0;
            *arg0 = (Gfx *) (gfx + 2);
            gfx[0] = 0x06000000;
            gfx[1] = (u32) D_overlay_75_04B014D0;
            gfx = (u32 *) *arg0;
            *arg0 = (Gfx *) (gfx + 2);
            gfx[0] = ((sp98 & 0x3FF) << 0xE) | 0xF6000000 | ((sp9A & 0x3FF) * 4);
            gfx[1] = ((sp94 & 0x3FF) << 0xE) | ((sp96 & 0x3FF) * 4);
            texDPInit(arg0);
            temp_t2_3 = (ctrl[0x2A] - 0x80) * 4;
            var_s1_2 = temp_t2_3;
            if (temp_t2_3 > 0) {
                if (temp_t2_3 >= 0x100) {
                    var_s1_2 = 0xFF;
                }
                fontUseFont(2);
                fontColour(0, 0, 0, 0xFF, var_s1_2);
                fontPrintXY(arg0, 0xA1, 0x9F, D_overlay_75_04B015A4, 0xC);
                fontColour(0xFF, 0xE0, 0x10, 0xFF, var_s1_2);
                fontPrintXY(arg0, 0xA0, 0x9E, D_overlay_75_04B015B4, 0xC);
            }
            gfx = (u32 *) *arg0;
            *arg0 = (Gfx *) (gfx + 2);
            gfx[1] = 0xFFFFFFFF;
            gfx[0] = 0xFA000000;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o75/overlay_75/arcadeDrawScreen.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u32 *func_overlay_75_04B00F00_1FA8030(s16 arg0) {
    if (arg0 == 0x102) {
        return &D_800FF32C;
    }
    if (arg0 == 0x18D) {
        return &D_800FF340;
    }
    return &D_800FF368;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o75/overlay_75/func_overlay_75_04B00F00_1FA8030.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Prints a time value as M:SS.hhh-style digits. Divisions are signed in the asm.
void func_overlay_75_04B00F38_1FA8068(Gfx **dl, s32 arg1, s32 arg2, s32 arg3) {
    s32 minutes;
    s32 secTens;
    s32 secOnes;
    s32 tenths;
    s32 hundredths;
    s32 rem;
    char digit;

    minutes = arg3 / 60000;
    rem = arg3 - minutes * 60000;
    secTens = rem / 6000;
    rem -= secTens * 6000;
    secOnes = rem / 1000;
    rem -= secOnes * 1000;
    tenths = rem / 100;
    rem -= tenths * 100;
    hundredths = rem / 10;
    rem -= hundredths * 10;

    fontUseFont(2);
    digit = (char) (minutes + 0x30);
    fontPrintXY(dl, arg1 + 4, arg2, &digit, 4);
    digit = (char) (secTens + 0x30);
    fontPrintXY(dl, arg1 + 0xC, arg2, &digit, 4);
    fontPrintXY(dl, arg1 + 0x12, arg2, D_overlay_75_04B015C4, 4);
    digit = (char) (secOnes + 0x30);
    fontPrintXY(dl, arg1 + 0x18, arg2, &digit, 4);
    digit = (char) (tenths + 0x30);
    fontPrintXY(dl, arg1 + 0x20, arg2, &digit, 4);
    fontPrintXY(dl, arg1 + 0x26, arg2, D_overlay_75_04B015C8, 4);
    digit = (char) (hundredths + 0x30);
    fontPrintXY(dl, arg1 + 0x2C, arg2, &digit, 4);
    digit = (char) (rem + 0x30);
    fontPrintXY(dl, arg1 + 0x34, arg2, &digit, 4);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o75/overlay_75/func_overlay_75_04B00F38_1FA8068.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// asm: arg3 (a3) is never read. The loop runs 5 times: the counter is
// decremented in the bnez delay slot, so the test sees the old value.
void func_overlay_75_04B01224_1FA8354(Gfx **dl, u32 *arg1, s32 arg2, void *arg3) {
    u32 *entry;
    s32 y;
    s32 count;
    char glyph[2];

    entry = arg1;
    fontUseFont(2);
    fontBackground(0, 0, 0, 0);
    fontColour(0xFF, 0xE0, 0x20, 0xFF, arg2);
    fontPrintXY(dl, 0xA0, 0x44, D_overlay_75_04B015CC, 4);
    glyph[1] = 0;
    y = 0x54;
    count = 4;
    do {
        fontColour(0xFF, 0xFF, 0xFF, 0xFF, arg2);
        func_overlay_75_04B00F38_1FA8068(dl, 0x74, y, *entry >> 18);
        fontColour(0x20, 0x80, 0xFF, 0xFF, arg2);
        glyph[0] = (char) D_overlay_75_04B01500[(*entry >> 12) & 0x3F];
        fontPrintXY(dl, 0xB8, y, glyph, 4);
        glyph[0] = (char) D_overlay_75_04B01500[(*entry >> 6) & 0x3F];
        fontPrintXY(dl, 0xC0, y, glyph, 4);
        glyph[0] = (char) D_overlay_75_04B01500[*entry & 0x3F];
        fontPrintXY(dl, 0xC8, y, glyph, 4);
        entry++;
        y += 0xC;
    } while (count-- != 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o75/overlay_75/func_overlay_75_04B01224_1FA8354.s")
#endif
