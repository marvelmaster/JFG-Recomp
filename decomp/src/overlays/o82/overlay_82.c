#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
typedef struct ChestAnim {
    f32 unk0;
    s32 unk4;
    s32 unk8;
} ChestAnim;

static f32 u32AsF32(u32 bits) {
    union {
        u32 u;
        f32 f;
    } v;
    v.u = bits;
    return v.f;
}

void *camGetPtr(void);
f32 Powerf(f32 base, s32 n);
f32 Sinf(s16 angle);
s16 dAngle(s16 a, s16 b, f32 c);
s32 mathDiffAngle(s16 a, s16 b);
void amSndPlay(u16 soundID, void *handlePtr);
void amDittyPlay(s32 arg0);
void controlPlayerOpenChest(void *arg0, void *arg1);
s32 controlPlayerOpeningChest(void *arg0, void *arg1);
void *objSetupObject(s16 *arg0, s32 arg1);
void *objGetPlayerNo(s32 arg0);
void objFreeObject(void *arg0);
s32 objAnimDframe(void *arg0, f32 arg1, f32 arg2);
void modGenAnimMatrices(void *arg0, s32 arg1, void *arg2, f32 arg3, f32 arg4);
void hinttextStop(void);
void hitInitObjectHit(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 arg7, f32 arg8,
                      f32 arg9, f32 arg10, s32 arg11);
void objAnimSetMove(void *arg0, s32 arg1, s32 arg2, void *arg3);
void mainPauseDisable(s32 arg0);
s32 func_overlay_82_052013C0_1FAE138(s32 arg0);
void func_overlay_82_05200340_1FAD0B8(void *arg0, void *arg1, u32 arg2);
void func_overlay_82_05200E6C_1FADBE4(void *arg0, void *arg1, void *arg2, s32 arg3);
s32 func_overlay_82_05200F8C_1FADD04(u8 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4);
void func_overlay_82_05201778_1FAE4F0(void);
void chestcameraInit(void *arg0);
extern ChestAnim D_overlay_82_052017A4;
extern ChestAnim D_overlay_82_052017B0;
extern ChestAnim D_overlay_82_052017BC;
extern ChestAnim D_overlay_82_052017C8;
extern ChestAnim D_overlay_82_052017D4;
extern ChestAnim D_overlay_82_052017E0;
extern f32 D_overlay_82_052017F0;
extern f32 D_overlay_82_052017F4;
extern f32 D_overlay_82_05201814;
extern f32 D_overlay_82_05201830;
extern f32 D_overlay_82_05201834;
extern f32 D_overlay_82_05201838;
extern f32 D_overlay_82_0520183C;
extern f32 D_overlay_82_05201840;
extern f32 D_overlay_82_052018F0;
extern f32 D_overlay_82_052018F4;
extern f32 D_overlay_82_052018F8;
extern f32 D_overlay_82_052018FC;
extern f32 D_overlay_82_05201900;
extern s16 D_overlay_82_05201904;
extern f32 D_overlay_82_05201908;
extern f32 D_overlay_82_0520190C;
extern s16 D_overlay_82_05201910;
extern void *D_overlay_82_052017A0;
void func_overlay_82_0520165C_1FAE3D4(s16 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6);
void *mainGetGameCharacter(s32 arg0, s32 arg1);
s32 mainGetNextCharacter(void);
s32 mainPlayerHas(s32 arg0, s32 arg1, s32 arg2);
void mainPlayerCollected(s32 arg0, s32 arg1, s32 arg2);
s32 mainAnyoneHas(s32 arg0);
void *controlGetWeaponDef(s32 arg0);
void hinttextStart(s32 arg0, s32 arg1);
void hinttextFreeObject(void);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void chestcameraInit(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *chest = *(u8 **)(obj + 0x68);
    u8 *cam = (u8 *)camGetPtr();
    f32 temp_f0, temp_f14;

    D_overlay_82_052018F0 = *(f32 *)(obj + 0xC);
    D_overlay_82_052018F4 = *(f32 *)(obj + 0x10) + ((480.0f * *(f32 *)(obj + 0x8)) + 8.0f);
    D_overlay_82_052018F8 = *(f32 *)(obj + 0x14);
    temp_f0 = *(f32 *)(cam + 0xC) - *(f32 *)(obj + 0xC);
    temp_f14 = *(f32 *)(cam + 0x14) - *(f32 *)(obj + 0x14);
    D_overlay_82_052018FC = sqrtf((temp_f0 * temp_f0) + (temp_f14 * temp_f14));
    D_overlay_82_05201900 = *(f32 *)(cam + 0x10) - D_overlay_82_052018F4;
    D_overlay_82_05201904 = (s16)(0x8000 - Arctanf(temp_f0, temp_f14));
    D_overlay_82_05201908 = *(f32 *)(chest + 0x8);
    D_overlay_82_0520190C = *(f32 *)(chest + 0xC);
    D_overlay_82_05201910 = (s16)(*(s16 *)(chest + 0x6) - *(s16 *)(obj + 0x0));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o82/overlay_82/chestcameraInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void chestcameraUpdate(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    f32 temp_f2, temp_f12, temp_f0, temp_f14, temp_f2_2;
    s16 temp_s0, temp_s1;
    s32 temp_v1;
    s32 var_s1;

    temp_f2 = 1.0f - Powerf(D_overlay_82_052017F0, arg1);
    D_overlay_82_052018FC += (D_overlay_82_05201908 - D_overlay_82_052018FC) * temp_f2;
    var_s1 = arg1 - 1;
    D_overlay_82_05201900 += (D_overlay_82_0520190C - D_overlay_82_05201900) * temp_f2;
    if (arg1 != 0) {
        do {
            temp_v1 = mathDiffAngle(D_overlay_82_05201904, D_overlay_82_05201910) >> 4;
            if (temp_v1 < -0x200) {
                D_overlay_82_05201904 -= 0x200;
            } else if (temp_v1 >= 0x201) {
                D_overlay_82_05201904 += 0x200;
            } else {
                D_overlay_82_05201904 += temp_v1;
            }
            var_s1 -= 1;
        } while (var_s1 != 0);
    }
    temp_f12 = Sinf(D_overlay_82_05201904) * D_overlay_82_052018FC;
    temp_f0 = Cosf((s32)D_overlay_82_05201904);
    *(f32 *)(obj + 0xC) = D_overlay_82_052018F0 + temp_f12;
    temp_f14 = -temp_f0 * D_overlay_82_052018FC;
    *(f32 *)(obj + 0x10) = D_overlay_82_052018F4 + D_overlay_82_05201900;
    *(f32 *)(obj + 0x14) = D_overlay_82_052018F8 + temp_f14;
    temp_s0 = (s16)(0x8000 - Arctanf(temp_f12, temp_f14));
    temp_s1 = (s16)Arctanf(D_overlay_82_05201900, D_overlay_82_052018FC);
    temp_f2_2 = 1.0f - Powerf(D_overlay_82_052017F4, arg1);
    *(s16 *)(obj + 0x0) = dAngle(*(s16 *)(obj + 0x0), temp_s0, temp_f2_2);
    *(s16 *)(obj + 0x2) = dAngle(*(s16 *)(obj + 0x2), temp_s1, temp_f2_2);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o82/overlay_82/chestcameraUpdate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_82_05200340_1FAD0B8(void *arg0, void *arg1, u32 arg2) {
    u8 *obj = (u8 *)arg0;
    u8 *out = (u8 *)arg1;
    ChestAnim *var_v0;
    f32 sp1C;

    switch (arg2) {
    case 0:
        var_v0 = &D_overlay_82_052017A4;
        break;
    case 1:
        var_v0 = &D_overlay_82_052017B0;
        break;
    case 2:
        var_v0 = &D_overlay_82_052017BC;
        break;
    case 4:
        var_v0 = &D_overlay_82_052017C8;
        break;
    case 5:
        var_v0 = &D_overlay_82_052017D4;
        break;
    case 6:
        var_v0 = &D_overlay_82_052017E0;
        break;
    default:
        var_v0 = NULL;
        break;
    }
    if (var_v0 != NULL) {
        sp1C = var_v0->unk0 + (-210.0f * *(f32 *)(obj + 0x8));
        *(f32 *)(out + 0x1C) = (f32)var_v0->unk4;
        *(f32 *)(out + 0x20) = (f32)var_v0->unk8;
        *(f32 *)(out + 0x10) = Sinf(*(s16 *)(obj + 0x0)) * sp1C;
        *(f32 *)(out + 0x14) = 0.0f;
        *(f32 *)(out + 0x18) = Cosf((s32)*(s16 *)(obj + 0x0)) * sp1C;
        return;
    }
    *(f32 *)(out + 0x10) = 0.0f;
    *(f32 *)(out + 0x14) = 0.0f;
    *(f32 *)(out + 0x18) = 0.0f;
    *(f32 *)(out + 0x1C) = 8.0f;
    *(f32 *)(out + 0x20) = 4.0f;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o82/overlay_82/func_overlay_82_05200340_1FAD0B8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void chestInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *ld = (u8 *)arg1;
    u8 *temp_a3;
    u8 temp_t9;
    u16 temp_t2;

    temp_a3 = *(u8 **)(obj + 0x68);
    *(s16 *)(temp_a3 + 0) = 0;
    *(f32 *)(obj + 0x8) = (f32)((f32)ld[0xB] * **(f32 **)(obj + 0x40) * D_overlay_82_05201814);
    *(s16 *)(obj + 0x0) = (s16)*(u16 *)(ld + 0xC);
    func_overlay_82_05200340_1FAD0B8(arg0, temp_a3, 0);
    temp_t9 = ld[0xA];
    temp_a3[5] = temp_t9;
    if (func_overlay_82_052013C0_1FAE138(temp_t9 & 0xFF) != 0) {
        temp_a3[4] = 5;
    } else {
        temp_a3[4] = 0;
    }
    *(f32 *)(temp_a3 + 0xC) = (f32)*(u16 *)(ld + 0xE);
    temp_t2 = *(u16 *)(ld + 0x10);
    *(f32 *)(temp_a3 + 0x8) = (f32)temp_t2;
    *(s16 *)(temp_a3 + 0x6) = (s16)*(u16 *)(ld + 0x12);
    objAnimSetMove(arg0, 0, 0, temp_a3);
    hitInitObjectHit(arg0, -1, 0, 8, 0, 0, 0, 4.0f, 4.0f, -1.0f, 1.0f, 1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o82/overlay_82/chestInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void chestControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *chest;
    u8 *player;
    u8 *pdata;
    u8 *sp5C = NULL;
    u8 setup[0x24];
    f32 sp78;
    u8 var_v1;
    s16 temp_v0_2, temp_t4, var_v1_2;
    s32 temp_t9, temp_v1_2;
    f32 temp_f0, temp_f0_2, temp_f0_3, temp_f12, temp_f14, temp_f2;
    void *temp_v0_3;
    u8 *temp_v0_4;
    u8 *temp_a0;
    void **temp_v0_5;
    u8 *temp_a0_2;
    u8 temp_v1_3;

    player = (u8 *)objGetPlayerNo(0);
    if (player != NULL) {
        pdata = *(u8 **)(player + 0x68);
        chest = *(u8 **)(obj + 0x68);
        var_v1 = chest[4];
        switch (var_v1) {
        case 0:
            if ((joyGetPressed(0) & 0x8000) && (pdata[0x568] == 0) && (*(s16 *)(*(u8 **)(player + 0x4C) + 6) >= 0x100)) {
                func_overlay_82_05200340_1FAD0B8(arg0, chest, pdata[1]);
                temp_f12 = (*(f32 *)(obj + 0xC) + *(f32 *)(chest + 0x10)) - *(f32 *)(player + 0xC);
                temp_f0 = *(f32 *)(chest + 0x1C);
                temp_f2 = *(f32 *)(player + 0x10) - (*(f32 *)(obj + 0x10) + *(f32 *)(chest + 0x14));
                temp_f14 = (*(f32 *)(obj + 0x14) + *(f32 *)(chest + 0x18)) - *(f32 *)(player + 0x14);
                temp_v1_2 = *(s16 *)(player + 0x0) - *(s16 *)(obj + 0x0);
                if (((temp_f12 * temp_f12) + (temp_f14 * temp_f14) < (temp_f0 * temp_f0)) && (temp_f2 >= -4.0f) &&
                    (temp_f2 <= *(f32 *)(chest + 0x20)) && ((temp_v1_2 < -0x6000) || (temp_v1_2 >= 0x6001))) {
                    chest[4] = 1;
                    chestcameraInit(arg0);
                    mainPauseDisable(0xA);
                    pdata[0x1FA] = 1;
                    controlPlayerOpenChest(player, pdata);
                }
            }
            var_v1 = chest[4];
            break;
        case 1:
            mainPauseDisable(0xA);
            temp_v0_2 = mathDiffAngle(*(s16 *)(pdata + 0x11C),
                                      Arctanf(*(f32 *)(player + 0xC) - *(f32 *)(obj + 0xC),
                                              *(f32 *)(player + 0x14) - *(f32 *)(obj + 0x14)));
            temp_t4 = (s16)(arg1 << 6);
            var_v1_2 = temp_v0_2;
            if (temp_v0_2 < -temp_t4) {
                var_v1_2 = (s16)(arg1 * -0x40);
            }
            if (temp_t4 < var_v1_2) {
                var_v1_2 = temp_t4;
            }
            *(s16 *)(pdata + 0x11C) = (s16)(*(s16 *)(pdata + 0x11C) + var_v1_2);
            if (controlPlayerOpeningChest(player, pdata) == 0) {
                chest[4] = 2;
            }
            if (chest[4] == 2) {
                amSndPlay(0xF2, NULL);
                *(s16 *)(setup + 0x0) = 0xC3;
                *(s16 *)(setup + 0x4) = (s16)*(f32 *)(obj + 0xC);
                *(s16 *)(setup + 0x6) = (s16)(*(f32 *)(obj + 0x10) + (230.0f * *(f32 *)(obj + 0x8)));
                *(s16 *)(setup + 0x8) = (s16)*(f32 *)(obj + 0x14);
                *(s16 *)(setup + 0xA) = (s16)(*(f32 *)(obj + 0x8) * 400.0f);
                *(s16 *)(setup + 0xE) = 0;
                *(s16 *)(setup + 0x10) = 0;
                *(s16 *)(setup + 0x12) = 0x20;
                setup[0x14] = 0xA;
                setup[0x15] = 0x32;
                setup[0x16] = 0;
                setup[0x17] = 0x55;
                setup[0x18] = 0xFF;
                setup[0x19] = 0;
                *(s16 *)(setup + 0x1A) = 0;
                setup[0x1C] = 0x64;
                setup[0x1D] = 0x64;
                setup[0x1E] = 6;
                setup[0x1F] = 0;
                *(s16 *)(setup + 0x20) = 0x4000;
                *(s16 *)(setup + 0xC) = (s16)(*(f32 *)(obj + 0x8) * 240.0f);
                *(s16 *)(setup + 0x22) = *(s16 *)(obj + 0x0);
                temp_v0_3 = objSetupObject((s16 *)setup, 1);
                if (temp_v0_3 != NULL) {
                    *(void **)(obj + 0x88) = temp_v0_3;
                    *(s32 *)(obj + 0x8C) = 0;
                    *(s32 *)((u8 *)temp_v0_3 + 0x3C) = 0;
                }
            }
            var_v1 = chest[4];
            break;
        case 2:
            mainPauseDisable(0xA);
            sp78 = *(f32 *)(obj + 0x28);
            if (objAnimDframe(arg0, u32AsF32(0x3C088889), (f32)arg1) != 0) {
                chest[4] = 3;
                temp_f0_2 = 480.0f * *(f32 *)(obj + 0x8);
                if (func_overlay_82_05200F8C_1FADD04(chest[5], *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10) + temp_f0_2,
                                                     *(f32 *)(obj + 0x14), temp_f0_2) != 0) {
                    amDittyPlay(0xF);
                } else {
                    *(s32 *)(obj + 0x8C) = 0x80;
                }
            }
            if ((sp78 < D_overlay_82_05201830) && (D_overlay_82_05201830 <= *(f32 *)(obj + 0x28))) {
                amSndPlay(0x200, NULL);
            } else if ((sp78 < D_overlay_82_05201834) && (D_overlay_82_05201834 <= *(f32 *)(obj + 0x28))) {
                amSndPlay(0x201, NULL);
            } else if ((sp78 < D_overlay_82_05201838) && (D_overlay_82_05201838 <= *(f32 *)(obj + 0x28))) {
                amSndPlay(0x202, NULL);
            }
            var_v1 = chest[4];
            break;
        case 3:
            mainPauseDisable(0xA);
            sp5C = *(u8 **)(obj + 0x88);
            if (sp5C != NULL) {
                temp_v1_2 = *(s32 *)(obj + 0x8C) + arg1;
                *(s32 *)(obj + 0x8C) = temp_v1_2;
                if (temp_v1_2 >= 0x81) {
                    objFreeObject(sp5C);
                    *(void **)(obj + 0x88) = NULL;
                } else {
                    temp_v0_4 = *(u8 **)(sp5C + 0x68);
                    temp_f0_3 = Sinf((s16)(temp_v1_2 << 8));
                    temp_v0_4[0xCB] = (u8)(s32)(255.0f * temp_f0_3);
                    *(f32 *)(temp_v0_4 + 0xB4) = *(f32 *)(obj + 0x8) * D_overlay_82_0520183C * temp_f0_3;
                    *(f32 *)(temp_v0_4 + 0xA8) = (f32)((*(s32 *)(obj + 0x8C) * 0xA * 2) + 0x140);
                    *(s32 *)(sp5C + 0x88) = 1;
                }
            }
            if (joyGetPressed(0) & 0xD000) {
                chest[4] = 4;
                func_overlay_82_05201778_1FAE4F0();
                pdata[0x1FA] = 2;
                hinttextStop();
                amSndPlay(0xF4, NULL);
                if ((sp5C != NULL) && (*(u8 **)(obj + 0x88) != NULL)) {
                    objFreeObject(sp5C);
                    *(void **)(obj + 0x88) = NULL;
                }
            }
            var_v1 = chest[4];
            break;
        case 4:
            sp78 = *(f32 *)(obj + 0x28);
            if (objAnimDframe(arg0, u32AsF32(0xBC888889), (f32)arg1) != 0) {
                chest[4] = 5;
            }
            if ((*(f32 *)(obj + 0x28) <= D_overlay_82_05201840) && (D_overlay_82_05201840 < sp78)) {
                amSndPlay(0x200, NULL);
            }
            var_v1 = chest[4];
            break;
        }
        if (((var_v1 == 1) || (var_v1 == 2) || (var_v1 == 3)) && (pdata[0x5C8] < 0xA)) {
            pdata[0x5C8] = 0xA;
        }
        temp_a0 = *(u8 **)(*(u8 **)(obj + 0x6C) + (obj[0x3A] * 4));
        if ((temp_a0 != NULL) && (*(s16 *)(temp_a0 + 0xA) != 0)) {
            modGenAnimMatrices(temp_a0, *(s32 *)(temp_a0 + 0x0), arg0, 1.0f, 0.0f);
            func_overlay_82_05200E6C_1FADBE4(*(void **)(temp_a0 + 0x0), temp_a0, chest, arg1);
            *(s16 *)(temp_a0 + 0xA) = 0;
        }
        temp_v0_5 = *(void ***)(obj + 0x74);
        if (temp_v0_5 != NULL) {
            temp_a0_2 = (u8 *)*temp_v0_5;
            if (temp_a0_2 != NULL) {
                temp_v1_3 = chest[4];
                temp_t9 = *(s32 *)(chest + 0x0) + arg1;
                *(s32 *)(chest + 0x0) = temp_t9;
                if ((temp_v1_3 == 4) || (temp_v1_3 == 5) || (temp_t9 & 0x20)) {
                    turnLightOff((UnkLight *)temp_a0_2);
                } else {
                    turnLightOn((UnkLight *)temp_a0_2);
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o82/overlay_82/chestControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_82_05200E6C_1FADBE4(void *arg0, void *arg1, void *arg2, s32 arg3) {
    u8 *hdr = (u8 *)arg0;
    u8 *obj = (u8 *)arg1;
    u8 *ctl = (u8 *)arg2;
    u8 *ent;
    u8 *def;
    s16 *out;
    s32 i;
    s32 type;
    s32 off;

    ent = *(u8 **)(obj + 0x74);
    out = *(s16 **)(obj + 0x78 + (*(s8 *)(obj + 0xB) * 4));
    for (i = 0; i < *(u8 *)(hdr + 0x2C); i++) {
        type = *(u32 *)(ent + 0x4) & 0xFF;
        off = type * 8;
        def = *(u8 **)(*(u8 **)(hdr + 0x18) + off);
        if ((type == 3) || (off == 0x20) || (off == 0x40)) {
            if ((ctl[0x4] == 4) || (ctl[0x4] == 5) || (*(u32 *)ctl & 0x20)) {
                *(s16 *)ent = 0;
            } else {
                *(s16 *)ent = 0x100;
            }
        }
        *out++ = (s16)((*(s16 *)ent >> 8) * *(s16 *)(def + 0x16));
        if (*(s16 *)(ent + 0x2) >= 0) {
            *out++ = (s16)((*(s16 *)(ent + 0x2) >> 8) * *(s16 *)(def + 0x16));
        }
        ent += 8;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o82/overlay_82/func_overlay_82_05200E6C_1FADBE4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_82_05200F8C_1FADD04(u8 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    void *player;
    u8 *pdata;
    u8 *chr;
    u8 *def;
    s32 bit;
    s32 slot = 0;
    s32 objId = 0;
    s32 hint = 0;
    s32 found = 0;
    s32 needCheck = 0;

    player = objGetPlayerNo(0);
    if (player == NULL) {
        return 0;
    }
    pdata = *(u8 **)((u8 *)player + 0x68);
    chr = (u8 *)mainGetGameCharacter(0, (s8)pdata[0x1]);

    switch (arg0) {
    case 0:
        slot = 3;
        objId = 0x1A9;
        hint = 0x16;
        found = 1;
        break;
    case 1:
        slot = 1;
        objId = 0x1D3;
        hint = 0x17;
        found = 1;
        break;
    case 2:
    case 3:
        slot = 2;
        objId = 0x1E1;
        hint = 0x19;
        found = 1;
        break;
    case 4:
        slot = 9;
        objId = 0x24E;
        hint = 0x1A;
        found = 1;
        break;
    case 5:
        slot = 8;
        objId = 0x272;
        hint = 0x1B;
        found = 1;
        break;
    case 6:
        slot = 3;
        objId = 0x270;
        hint = 0x1C;
        needCheck = 1;
        break;
    case 7:
        slot = 0x10;
        objId = 0x18A;
        hint = 0x1D;
        needCheck = 1;
        break;
    case 8:
    case 10:
        slot = 0xE;
        objId = 0x2F4;
        hint = 0x1E;
        found = 1;
        break;
    case 9:
        slot = 0xD;
        objId = 0x2F5;
        hint = 0x1F;
        found = 1;
        break;
    case 11:
        slot = 0xC;
        objId = 0x2F6;
        hint = 0x20;
        found = 1;
        break;
    case 12:
        slot = 0xB;
        objId = 0x317;
        hint = 0x21;
        found = 1;
        break;
    case 13:
        slot = 0xA;
        objId = 0x316;
        hint = 0x22;
        found = 1;
        break;
    case 14:
        slot = 7;
        objId = 0x2F1;
        hint = 0x23;
        found = 1;
        break;
    case 15:
        slot = 6;
        objId = 0x2F2;
        hint = 0x24;
        found = 1;
        break;
    case 16:
        slot = 4;
        objId = 0x2F3;
        hint = 0x25;
        found = 1;
        break;
    case 17:
        slot = 0x16;
        objId = 0x2C1;
        hint = 0x26;
        needCheck = 1;
        break;
    case 18:
        slot = 9;
        objId = 0x2F0;
        hint = 0x27;
        needCheck = 1;
        break;
    case 19:
        slot = 1;
        objId = 0x17D;
        hint = 0x28;
        needCheck = 1;
        break;
    case 20:
        slot = 5;
        objId = 0x271;
        hint = 0x29;
        found = 1;
        break;
    }

    if (found != 0) {
        bit = 1 << slot;
        if (!(*(u16 *)(chr + 0xA) & bit)) {
            def = (u8 *)controlGetWeaponDef(slot);
            *(u16 *)(chr + 0xA) = (u16)(*(u16 *)(chr + 0xA) | bit);
            chr[0x6F] = (u8)(chr[0x6F] + 1);
            *(s16 *)(chr + 0x34 + (slot * 2)) = *(s16 *)(def + 0x24);
            *(s16 *)(chr + 0x14 + (slot * 2)) = *(s16 *)(def + 0x28);
            chr[0x54 + slot] = def[0x3];
            func_overlay_82_0520165C_1FAE3D4((s16)objId, arg1, arg2, arg3, 8.0f, arg4, 1.0f);
            hinttextStart(hint, 0);
            return 1;
        }
    }
    if ((needCheck != 0) && (mainPlayerHas(0, (s8)pdata[0x1], slot) == 0)) {
        mainPlayerCollected(0, (s8)pdata[0x1], slot);
        func_overlay_82_0520165C_1FAE3D4((s16)objId, arg1, arg2, arg3, 8.0f, arg4, 1.0f);
        hinttextStart(hint, 0);
        return 1;
    }
    hinttextStart(0x2A, 0);
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o82/overlay_82/func_overlay_82_05200F8C_1FADD04.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_82_052013C0_1FAE138(s32 arg0) {
    u8 *chr = (u8 *)mainGetGameCharacter(0, mainGetNextCharacter());
    u16 flags = *(u16 *)(chr + 0xA);

    switch (arg0) {
    case 0:
        return (flags & 0x8) != 0;
    case 1:
        return (flags & 0x2) != 0;
    case 2:
    case 3:
        return (flags & 0x4) != 0;
    case 4:
        return (flags & 0x200) != 0;
    case 5:
        return (flags & 0x100) != 0;
    case 6:
        return mainPlayerHas(0, mainGetNextCharacter(), 3) != 0;
    case 7:
        return (mainAnyoneHas(0x10) != 0) || (mainAnyoneHas(0x11) != 0);
    case 8:
    case 10:
        return (flags & 0x4000) != 0;
    case 9:
        return (flags & 0x2000) != 0;
    case 11:
        return (flags & 0x1000) != 0;
    case 12:
        return (flags & 0x800) != 0;
    case 13:
        return (flags & 0x400) != 0;
    case 14:
        return (flags & 0x80) != 0;
    case 15:
        return (flags & 0x40) != 0;
    case 16:
        return (flags & 0x10) != 0;
    case 17:
        return mainAnyoneHas(0x16) != 0;
    case 18:
        return mainPlayerHas(0, mainGetNextCharacter(), 9) != 0;
    case 19:
        return mainPlayerHas(0, mainGetNextCharacter(), 1) != 0;
    case 20:
        return (flags & 0x20) != 0;
    default:
        return 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o82/overlay_82/func_overlay_82_052013C0_1FAE138.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_82_0520165C_1FAE3D4(s16 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6) {
    u8 setup[0x10];
    void *obj;

    hinttextFreeObject();
    *(s16 *)(setup + 0x0) = arg0;
    setup[0x2] = 0x10;
    setup[0x3] = 0;
    *(s16 *)(setup + 0x4) = (s16)arg1;
    *(s16 *)(setup + 0x6) = (s16)arg2;
    *(s16 *)(setup + 0x8) = (s16)arg3;
    setup[0xA] = (u8)(s32)arg4;
    setup[0xB] = (u8)(s32)arg5;
    *(f32 *)(setup + 0xC) = arg6;
    obj = objSetupObject((s16 *)setup, 1);
    D_overlay_82_052017A0 = obj;
    if (obj != NULL) {
        *(s32 *)((u8 *)obj + 0x3C) = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o82/overlay_82/func_overlay_82_0520165C_1FAE3D4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_82_05201778_1FAE4F0(void) {
    if (D_overlay_82_052017A0 != NULL) {
        *(s32 *)((u8 *)D_overlay_82_052017A0 + 0x88) = 1;
        D_overlay_82_052017A0 = NULL;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o82/overlay_82/func_overlay_82_05201778_1FAE4F0.s")
#endif
