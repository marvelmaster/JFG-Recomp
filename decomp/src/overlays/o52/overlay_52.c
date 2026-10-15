#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern f32 D_overlay_52_0340237C;
extern f32 D_overlay_52_03402380;
extern f32 D_overlay_52_03402384;
extern f32 D_overlay_52_03402388;
extern f32 D_overlay_52_03402364;
extern f32 D_overlay_52_03402368;
extern f32 D_overlay_52_0340236C;
extern f32 D_overlay_52_03402370;
extern f32 D_overlay_52_03402374;
extern f32 D_overlay_52_03402378;
extern s16 D_overlay_52_03402444;
extern void *D_overlay_52_03402440;
extern void *controlModeKeys;
f32 Powerf(f32 base, s32 n);
void mainPauseDisable(s32 n);
void controlFrozen(void *a, void *b);
void *mainGetGameCharacter(s8 a, s8 b);
void charSpeak(void *obj, u8 arg1);
s32 controlGetManualAim(u8 *a0, u8 *a1, s32 a2, s32 a3, s32 a4, s32 a5, s16 *a6, s16 *a7, f32 a8);
void camSetZoom(s32 arg0, f32 arg1);
s16 dAngle(s16 a, s16 b, f32 c);
s32 mathSin(s16 angle, s8 arg1);
void func_overlay_52_034013D4_1F6FE1C(u8 *arg0, u8 *arg1, s32 arg2, f32 arg3);
void func_overlay_52_0340128C_1F6FCD4(s16 arg0, s16 arg1, s32 arg2, s16 arg3);
extern u8 D_overlay_52_03401E40[];
extern u8 D_overlay_52_03401E41[];
s32 controlPlayerGunWeight(void *arg0);
s32 objAnimSetMove(void *arg0, s8 arg1, f32 arg2);
extern f32 D_overlay_52_03401F4C[];
extern f32 D_overlay_52_03402430;
s32 func_overlay_52_03401390_1F6FDD8(u8 *arg0);
void objAnimDframe(void *obj, f32 a, f32 b);
void charAnimSoundTick(void *obj, f32 a, f32 b);
void objMoveXYZ(void *obj, f32 x, f32 y, f32 z);
f32 sqrtf(f32 x);
f32 Sinf(s16 angle);
s32 hitGetHeights(f32 x, f32 z, s32 maxCount, f32 ***out);
s32 trackGetHeights(f32 x, f32 z, s32 maxCount, f32 ***out);
extern f32 D_overlay_52_03402360;
extern u8 allweaponsCheat;
extern u8 invulnerabilityCheat;
extern u8 deformedchars;
extern s32 quickWeaponKey[];
extern s32 D_overlay_52_03402324[];
extern s32 D_overlay_52_0340233C[];
void amTunePlay(u8);
void controlDisableJoypad(s32);
void controlReadJoypad(s32);
void controlMakeGravity(void *);
void controlEmptyPlayersHand(void *);
void controlClearAimlocks(void *);
void frontSetInstrumentsHide(s32);
s32 controlSelectWeapon(void *, void *, s8, s32);
void controlSelectNextWeapon(void *, void *, s8);
void controlSelectPreviousWeapon(void *, void *, s8);
s32 controlUpdateWeapon(void *, void *, f32);
s32 controlThrowWeapon(s32);
void invincibilityShieldTransform(void *, s32, s32, s16);
void lightObject(void *, void *, s32, s32);
s32 objMakeGunMtx(void *, void *, void *, s32, void *, void *, void *, void *);
void modGenAnimMatrices(void *, void *, void *, f32, f32);
void objAnimTextures(void *, void *, void *, s8);
s32 objAnimSetFrame(void *, s32);
void partUpdateTriggers(void *, s32);
void func_overlay_52_03400C40_1F6F688(u8 *arg0, u8 *arg1, f32 arg2);
void func_overlay_52_03401108_1F6FB50(u8 *arg0, u8 *arg1, f32 arg2);
void func_overlay_52_034011E0_1F6FC28(u8 *arg0, u8 *arg1, f32 arg2);
void func_overlay_52_03401468_1F6FEB0(u8 *arg0, u8 *arg1, f32 arg2);
void func_overlay_52_03401688_1F700D0(u8 *arg0, u8 *arg1, f32 arg2);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// cf. dogBossControl (overlay_51.c): same frame structure; the extra block is the
// deformed-chars display-list writer (6 iterations, 6 halfwords each).
void girlBossControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *pl;
    u8 *chr;
    u8 *cam;
    u8 *ent;
    u8 *ent0;
    u8 *game;
    u8 *slot;
    void *shield;
    s16 *cur;
    s32 *wp;
    f32 *fp;
    f32 speed;
    f32 var_f0;
    s32 mtxRet;
    s32 chrWeapon;
    s32 i;
    s32 cnt;
    s32 ptr;
    s32 w;
    s32 k;
    s32 arrA[6];
    s32 arrB[6];
    s16 v0;
    s8 pl585;

    pl = *(u8 **)(obj + 0x68);
    chr = (u8 *)mainGetGameCharacter(*(s8 *)(pl + 0x00), *(s8 *)(pl + 0x01));
    D_overlay_52_03402440 = (void *)(pl + 0x240);
    *(s32 *)(obj + 0x84) = 0;
    *(u8 *)(pl + 0x1F4) = 0xF;
    *(u8 *)(pl + 0x1F8) = 0;
    if ((*(u8 *)(pl + 0x18E) != 0) || (*(u8 *)(pl + 0x568) == 0x2A)) {
        controlDisableJoypad(1);
    }
    if (*(u8 *)(pl + 0x568) != 0x2A) {
        v0 = *(s16 *)(pl + 0x1E2);
        *(u8 *)(pl + 0x568) = (u8)(*(u8 *)(pl + 0x568) | 0x20);
        if (v0 < -0x800) {
            *(s8 *)(pl + 0x19C) = (s8)(*(s8 *)(pl + 0x19C) + (arg1 * 8));
            if (*(s8 *)(pl + 0x19C) >= 0x29) {
                *(s8 *)(pl + 0x19C) = 0x28;
            }
        } else if (v0 >= 0x801) {
            *(s8 *)(pl + 0x19C) = (s8)(*(s8 *)(pl + 0x19C) + (arg1 * 8));
            if (*(s8 *)(pl + 0x19C) >= 0x29) {
                *(s8 *)(pl + 0x19C) = 0x28;
            }
        } else {
            *(s8 *)(pl + 0x19C) = (s8)(*(s8 *)(pl + 0x19C) - (arg1 * 8));
            if (*(s8 *)(pl + 0x19C) < 0) {
                *(s8 *)(pl + 0x19C) = 0;
            }
        }
    } else {
        v0 = *(s16 *)(pl + 0x1E2);
        *(s16 *)(pl + 0x1E2) = (s16)(v0 - (v0 >> 2));
        *(s8 *)(pl + 0x19C) = (s8)(*(s8 *)(pl + 0x19C) - (arg1 * 8));
        if (*(s8 *)(pl + 0x19C) < 0) {
            *(s8 *)(pl + 0x19C) = 0;
        }
    }
    if (*(u8 *)(pl + 0x568) != 0x23) {
        *(f32 *)(pl + 0x57C) = *(f32 *)(obj + 0x10);
    }
    D_overlay_52_03402444 = (s16)*(s8 *)(pl + 0x577);
    if (*(s8 *)(pl + 0x56B) != 0) {
        controlDisableJoypad(1);
        *(s8 *)(pl + 0x56B) = (s8)(*(s8 *)(pl + 0x56B) - arg1);
        if (*(s8 *)(pl + 0x56B) < 0) {
            *(s8 *)(pl + 0x56B) = 0;
        }
    }
    if (*(s8 *)(pl + 0x577) != 0) {
        controlDisableJoypad(1);
        *(s8 *)(pl + 0x577) = (s8)(*(s8 *)(pl + 0x577) - arg1);
        if (*(s8 *)(pl + 0x577) < 0) {
            *(s8 *)(pl + 0x577) = 0;
        }
    }
    controlReadJoypad(*(s8 *)(pl + 0x00));
    controlMakeGravity(pl);
    if (*(f32 *)(pl + 0x04) != 0.0f) {
        *(f32 *)(pl + 0x04) = 0.0f;
    }
    if (*(f32 *)(obj + 0x1C) < -20.0f) {
        *(f32 *)(obj + 0x1C) = -20.0f;
    }
    if (*(f32 *)(obj + 0x1C) > 20.0f) {
        *(f32 *)(obj + 0x1C) = 20.0f;
    }
    if (*(f32 *)(obj + 0x20) < -20.0f) {
        *(f32 *)(obj + 0x20) = -20.0f;
    }
    if (*(f32 *)(obj + 0x20) > 15.0f) {
        *(f32 *)(obj + 0x20) = 15.0f;
    }
    if (*(f32 *)(obj + 0x24) < -20.0f) {
        *(f32 *)(obj + 0x24) = -20.0f;
    }
    if (*(f32 *)(obj + 0x24) > 20.0f) {
        *(f32 *)(obj + 0x24) = 20.0f;
    }
    if (*(f32 *)(pl + 0x08) < -20.0f) {
        *(f32 *)(pl + 0x08) = -20.0f;
    }
    if (*(f32 *)(pl + 0x08) > 20.0f) {
        *(f32 *)(pl + 0x08) = 20.0f;
    }
    cam = *(u8 **)(obj + 0x4C);
    if ((*(s16 *)(cam + 0x06) < 0x100) && (*(u8 *)(pl + 0x568) != 0x2A)) {
        if (invulnerabilityCheat != 0) {
            *(s16 *)(cam + 0x06) = 0x2200;
        } else {
            *(s16 *)(cam + 0x06) = 0;
            amTunePlay(0x38);
            *(u8 *)(pl + 0x568) = 0x2A;
            controlKeys = 0;
            controlDkeys = 0;
            *(u8 *)(pl + 0x53D) = 0;
            frontSetInstrumentsHide(1);
            controlEmptyPlayersHand(obj);
            controlClearAimlocks(pl);
            func_overlay_52_034013D4_1F6FE1C(obj, pl, 0x18, 0);
        }
        *(s8 *)(pl + 0x19C) = 0;
    }
    speed = (f32)arg1;
    switch (*(u8 *)(pl + 0x568) & ~0x20) {
    case 0:
        func_overlay_52_03400C40_1F6F688(obj, pl, speed);
        break;
    case 3:
        func_overlay_52_03401108_1F6FB50(obj, pl, speed);
        break;
    case 10:
        func_overlay_52_034011E0_1F6FC28(obj, pl, speed);
        break;
    default:
        break;
    }
    if (*(s8 *)(pl + 0x1F6) != 0) {
        *(s8 *)(pl + 0x1F6) = (s8)(*(s8 *)(pl + 0x1F6) - arg1);
        if (*(s8 *)(pl + 0x1F6) < 0) {
            *(s8 *)(pl + 0x1F6) = 0;
        }
    }
    if (allweaponsCheat != 0) {
        *(u8 *)(chr + 0x6F) = 0xF;
        *(s16 *)(chr + 0x0A) = 0x7FFF;
    }
    *(u8 *)(pl + 0x540) = (u8)(*(u8 *)(pl + 0x540) & 0xFFCF);
    if (*(u8 *)(chr + 0x6F) >= 2) {
        chrWeapon = *(u8 *)(chr + 0x70);
        pl585 = *(s8 *)(pl + 0x585);
        if ((chrWeapon != pl585) && (disablejoy == 0)) {
            /* asm: a3 is not set before this call */
            controlSelectWeapon(obj, pl, pl585, 0);
        } else if ((*(s32 *)((u8 *)controlModeKeys + 0x4) & controlDkeys) != 0) {
            controlSelectNextWeapon(obj, pl, pl585);
        } else if ((*(s32 *)((u8 *)controlModeKeys + 0x8) & controlDkeys) != 0) {
            controlSelectPreviousWeapon(obj, pl, pl585);
        } else {
            game = (u8 *)mainGetGame();
            for (i = 0; i != 4; i++) {
                if (quickWeaponKey[i] & controlDkeys) {
                    if (controlSelectWeapon(obj, pl, (s8)*(u8 *)(game + 0x534 + i), i) != 0) {
                        break;
                    }
                }
            }
        }
        if (chrWeapon != *(u8 *)(chr + 0x70)) {
            *(u8 *)(pl + 0x538) = 0;
            *(u8 *)(pl + 0x53D) = 0;
            *(s8 *)(pl + 0x585) = (s8)*(u8 *)(chr + 0x70);
        }
    }
    func_overlay_52_03401468_1F6FEB0(obj, pl, speed);
    func_overlay_52_03401688_1F700D0(obj, pl, speed);
    shield = *(void **)(pl + 0x5BC);
    if (shield != NULL) {
        if ((*(u8 *)(pl + 0x568) & ~0x20) == 1) {
            invincibilityShieldTransform(shield, 0x3F800000, 0x3F400000, 0x78);
        } else {
            invincibilityShieldTransform(shield, 0x3F800000, 0x3F800000, 0x78);
        }
    }
    cur = (s16 *)D_overlay_52_03402440;
    if (deformedchars != 0) {
        arrA[0] = D_overlay_52_03402324[0];
        arrA[1] = D_overlay_52_03402324[1];
        arrA[2] = D_overlay_52_03402324[2];
        arrA[3] = D_overlay_52_03402324[3];
        arrA[4] = D_overlay_52_03402324[4];
        arrA[5] = D_overlay_52_03402324[5];
        arrB[0] = D_overlay_52_0340233C[0];
        arrB[1] = D_overlay_52_0340233C[1];
        arrB[2] = D_overlay_52_0340233C[2];
        arrB[3] = D_overlay_52_0340233C[3];
        arrB[4] = D_overlay_52_0340233C[4];
        arrB[5] = D_overlay_52_0340233C[5];
        wp = &arrA[5];
        fp = (f32 *)&arrB[5];
        for (k = 0; k < 6; k++) {
            w = *wp;
            cur[0] = (s16)((w * 6) | 0x4000);
            cur[1] = (s16)(s32)(*fp * 32768.0f);
            cur[2] = (s16)(((w * 6) + 2) | 0x4000);
            cur[3] = (s16)(s32)(*fp * 32768.0f);
            cur[4] = (s16)(((w * 6) + 4) | 0x4000);
            cur[5] = (s16)(s32)(*fp * 32768.0f);
            cur += 6;
            fp--;
            wp--;
        }
    }
    *cur = 0x1000;
    cur++;
    D_overlay_52_03402440 = (void *)cur;
    ent = *(u8 **)(*(u8 **)(obj + 0x6C) + (*(s8 *)(obj + 0x3A) * 4));
    if (ent != NULL) {
        if (*(s8 *)(ent + 0x0A) != 0) {
            ent0 = *(u8 **)ent;
            modGenAnimMatrices(ent, ent0, obj, 1.0f, 0.0f);
            mtxRet = objMakeGunMtx(obj, ent, ent0, *(u8 *)(chr + 0x70), pl + 0x78, pl + 0x544, pl + 0x548, pl + 0x54C);
            *(u8 *)(pl + 0x540) = (u8)(((mtxRet * 4) & 4) | (*(u8 *)(pl + 0x540) & 0xFFFB));
            lightObject(obj, ent, *(s32 *)(obj + 0x54), *(s32 *)(ent + (*(s8 *)(ent + 0x0B) * 4) + 0x10));
            if ((s32)*(u8 *)(ent0 + 0x11) > 0) {
                objAnimTextures(obj, ent0, ent, *(s8 *)(ent + 0x0A));
            }
            *(s8 *)(ent + 0x0A) = 0;
            var_f0 = (*(f32 *)(*(u8 **)(ent + 0x70) + 0x70) + 4.0f) - *(f32 *)(obj + 0x10);
            if (var_f0 >= 64.0f) {
                var_f0 = D_overlay_52_03402360;
            }
            *(s8 *)(*(u8 **)(obj + 0x50) + 0x0E) = (s8)(s32)(var_f0 * 4.0f);
        }
    }
    switch (controlThrowWeapon(controlUpdateWeapon(obj, pl, speed))) {
    case 1:
        if (*(s8 *)(obj + 0x3B) == 0x16) {
            objAnimSetFrame(obj, 0);
        } else {
            func_overlay_52_034013D4_1F6FE1C(obj, pl, 0x16, 0);
        }
        *(s8 *)(pl + 0x577) = 0x28;
        break;
    case 2:
        if (*(s8 *)(obj + 0x3B) == 0x31) {
            objAnimSetFrame(obj, 0);
        } else {
            func_overlay_52_034013D4_1F6FE1C(obj, pl, 0x31, 0);
        }
        *(s8 *)(pl + 0x577) = 0x28;
        break;
    default:
        break;
    }
    partUpdateTriggers(obj, arg1);
    if (controlDkeys & 0x10) {
        cnt = 5;
        slot = pl + 0x14;
        if (*(s32 *)(pl + 0x1BC) != 0) {
            do {
                ptr = *(s32 *)(slot + 0x1A8);
                if (ptr != 0) {
                    *(u8 *)(ptr + *(s8 *)(pl + 0x00) + 0x93) = 0;
                    *(s32 *)(slot + 0x1A8) = 0;
                }
                slot -= 4;
            } while (cnt-- != 0);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o52/overlay_52/girlBossControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_52_03400C40_1F6F688(u8 *arg0, u8 *arg1, f32 arg2) {
    void *player;
    s32 sp3C;
    s32 sp58;
    s16 sp56;
    s16 sp54;
    f32 sp50;
    s32 v0;
    s32 v1;
    s32 temp_a1;
    f32 f;

    player = mainGetGameCharacter(*(s8 *)arg1, *(s8 *)(arg1 + 1));
    *(u8 *)(arg1 + 0x576) = 0;
    *(u8 *)(arg1 + 0x13E) = 0;
    if ((*(u8 *)((u8 *)player + 0x70) != 7) &&
        ((*(u32 *)((u8 *)controlModeKeys + 0xC) & controlDkeys) != 0)) {
        *(u8 *)(arg1 + 0x568) = 0x23;
        *(f32 *)(arg1 + 0x57C) = *(f32 *)(arg0 + 0x10);
        *(f32 *)(arg0 + 0x20) = *(f32 *)(arg0 + 0x20) + 10.0f;
        func_overlay_52_034013D4_1F6FE1C(arg0, arg1, 6, 0.0f);
        charSpeak(arg0, 0);
        sp3C = (s32) arg2;
    } else if (controlKeys & 2) {
        *(f32 *)(arg1 + 0x10) = *(f32 *)(arg1 + 0x10) - (D_overlay_52_03402364 * arg2);
        if (*(f32 *)(arg1 + 0x10) < -3.0f) {
            *(f32 *)(arg1 + 0x10) = -3.0f;
        }
        sp3C = (s32) arg2;
    } else if (controlKeys & 1) {
        *(f32 *)(arg1 + 0x10) = *(f32 *)(arg1 + 0x10) + (D_overlay_52_03402368 * arg2);
        if (*(f32 *)(arg1 + 0x10) > 3.0f) {
            *(f32 *)(arg1 + 0x10) = 3.0f;
        }
        sp3C = (s32) arg2;
    } else {
        sp3C = (s32) arg2;
        *(f32 *)(arg1 + 0x10) = *(f32 *)(arg1 + 0x10) * Powerf(D_overlay_52_0340236C, sp3C);
        f = *(f32 *)(arg1 + 0x10);
        if ((D_overlay_52_03402370 < f) && (f < D_overlay_52_03402374)) {
            *(f32 *)(arg1 + 0x10) = 0.0f;
        }
    }

    v1 = (u16) *(s16 *)(arg1 + 0x11C);
    *(s16 *)(arg1 + 0x11C) = *(s16 *)arg0;
    if (D_overlay_52_03402444 == 0) {
        sp58 = v1;
        if (controlGetManualAim(arg0, arg1, 0xE38, 0xE38, -0x2AAA, 0x2AAA, &sp56, &sp54, arg2) != 0) {
            camSetZoom(*(s8 *)arg1, *(f32 *)(arg1 + 0x1EC));
        }
        v1 = sp58;
    } else {
        sp56 = *(s16 *)(arg1 + 0x1DC);
        sp54 = *(s16 *)(arg1 + 0x1DE) - *(s16 *)(arg1 + 0x1E2);
    }

    v0 = (u16) *(s16 *)(arg1 + 0x11C);
    *(s16 *)(arg1 + 0x11C) = (s16) v1;
    if ((v0 < v1) && ((v1 - v0) >= 0x8000)) {
        v0 = v0 + 0x10000;
    }
    if ((v1 < v0) && ((v0 - v1) >= 0x8000)) {
        v1 = v1 + 0x10000;
    }
    if (v1 < v0) {
        if ((v0 - v1) >= 0x2801) {
            v0 = v1 + 0x2800;
        }
    } else if ((v1 - v0) >= 0x2801) {
        v0 = v1 - 0x2800;
    }
    *(s16 *)arg0 = (s16) v0;

    sp50 = 1.0f - Powerf(D_overlay_52_03402378, sp3C);
    *(s16 *)(arg1 + 0x1E0) = dAngle(*(s16 *)(arg1 + 0x1E0), sp54, sp50);
    sp54 = sp54 + *(s16 *)(arg1 + 0x1E2);
    *(s16 *)(arg1 + 0x1DC) = dAngle(*(s16 *)(arg1 + 0x1DC), sp56, sp50);
    *(s16 *)(arg1 + 0x1DE) = dAngle(*(s16 *)(arg1 + 0x1DE), sp54, sp50);
    *(s16 *)(arg1 + 0x1CE) = dAngle(*(s16 *)(arg1 + 0x1CE), sp56, sp50);
    *(s16 *)(arg1 + 0x1D0) = dAngle(*(s16 *)(arg1 + 0x1D0), sp54, sp50);

    v1 = *(s16 *)(arg1 + 0x1CE);
    *(s16 *)(arg1 + 0x1C6) = (s16) (v1 + *(s16 *)arg0);
    *(s16 *)(arg1 + 0x1CA) = *(s16 *)(arg1 + 0x1C6);
    *(s16 *)(arg1 + 0x1C8) = (s16) (*(s16 *)(arg1 + 0x1D0) + *(s16 *)(arg0 + 2));
    *(s16 *)(arg1 + 0x1CC) = *(s16 *)(arg1 + 0x1C8);
    sp56 = (s16) v1;
    sp54 = *(s16 *)(arg1 + 0x1D0);

    temp_a1 = *(s8 *)(arg1 + 0x1F6);
    if (temp_a1 != 0) {
        sp54 = (s16) (sp54 + ((*(s8 *)(arg1 + 0x1F7) * mathSin((s16) ((temp_a1 << 28) >> 16),
                                                              (s8) temp_a1)) >> 8));
    }
    func_overlay_52_0340128C_1F6FCD4(sp54, sp56, *(s16 *)(arg1 + 0x1DE), *(s16 *)(arg1 + 0x1DC));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o52/overlay_52/func_overlay_52_03400C40_1F6F688.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_52_03401108_1F6FB50(u8 *arg0, u8 *arg1, f32 arg2) {
    if (*(f32 *)(arg0 + 0x20) < 0.0f) {
        if (*(f32 *)(arg0 + 0x10) < *(f32 *)(arg1 + 0x57C)) {
            *(f32 *)(arg1 + 0x10) *= Powerf(D_overlay_52_0340237C, (s32) arg2);
            if ((D_overlay_52_03402380 < *(f32 *)(arg1 + 0x10)) &&
                (*(f32 *)(arg1 + 0x10) < D_overlay_52_03402384)) {
                *(f32 *)(arg1 + 0x10) = 0.0f;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o52/overlay_52/func_overlay_52_03401108_1F6FB50.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_52_034011E0_1F6FC28(u8 *arg0, u8 *arg1, f32 arg2) {
    *(s16 *)(*(u8 **)(arg0 + 0x4C) + 0x6) = 0;
    mainPauseDisable(0xA);
    *(f32 *)(arg1 + 0x10) *= Powerf(D_overlay_52_03402388, (s32) arg2);
    *(u8 *)(arg1 + 0x19C) = 0;
    if (*(f32 *)(arg0 + 0x28) == 1.0f) {
        controlFrozen(arg0, arg1);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o52/overlay_52/func_overlay_52_034011E0_1F6FC28.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_52_0340128C_1F6FCD4(s16 arg0, s16 arg1, s32 arg2, s16 arg3) {
    s16 *cur = (s16 *) D_overlay_52_03402440;
    s16 half = arg0 >> 1;

    cur[0] = 0x12;
    cur[1] = half;
    cur[2] = 0x14;
    cur[3] = arg1;
    cur[4] = 6;
    cur[5] = half;
    cur[6] = 0x3C;
    cur[7] = (s16) (arg2 - half);
    cur[8] = 0x3E;
    cur[9] = arg3;
    D_overlay_52_03402440 = cur + 10;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o52/overlay_52/func_overlay_52_0340128C_1F6FCD4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_52_03401390_1F6FDD8(u8 *arg0) {
    f32 v = *(f32 *)(arg0 + 0x10);

    if (v < 0.0f) {
        return 0x20;
    }
    if (v > 0.0f) {
        return 0x21;
    }
    return 0x1C;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o52/overlay_52/func_overlay_52_03401390_1F6FDD8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching (same as func_overlay_50_032013D4_1F6B07C, different table and gate value)
void func_overlay_52_034013D4_1F6FE1C(u8 *arg0, u8 *arg1, s32 arg2, f32 arg3) {
    u8 var;

    if (*(s8 *)(arg0 + 0x3B) != 0x18) {
        if (controlPlayerGunWeight(arg1) != 0) {
            var = D_overlay_52_03401E41[arg2 * 5];
        } else {
            var = D_overlay_52_03401E40[arg2 * 5];
        }
        if (var != *(s8 *)(arg0 + 0x3B)) {
            objAnimSetMove(arg0, var, arg3);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o52/overlay_52/func_overlay_52_034013D4_1F6FE1C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching (ported from overlay_50 func_overlay_50_03201468_1F6B110; case values shifted for o52)
void func_overlay_52_03401468_1F6FEB0(u8 *arg0, u8 *arg1, f32 arg2) {
    s8 type = *(s8 *)(arg0 + 0x3B);
    f32 scale = D_overlay_52_03401F4C[type];
    f32 origPos = *(f32 *)(arg0 + 0x28);
    f32 f12 = origPos;
    f32 f2 = (scale * arg2) + f12;
    s32 idx = (s32) type;

    switch (type) {
    case 16:
    case 28:
        idx = func_overlay_52_03401390_1F6FDD8(arg1);
        if (*(f32 *)(arg1 + 0x10) != 0.0f) {
            f12 = 0.25f;
        }
        break;
    case 9:
    case 32:
        scale *= -*(f32 *)(arg1 + 0x10);
        idx = func_overlay_52_03401390_1F6FDD8(arg1);
        if (*(f32 *)(arg1 + 0x10) == 0.0f) {
            f12 = 0.0f;
        }
        break;
    case 10:
    case 33:
        scale *= *(f32 *)(arg1 + 0x10);
        idx = func_overlay_52_03401390_1F6FDD8(arg1);
        if (*(f32 *)(arg1 + 0x10) == 0.0f) {
            f12 = 0.0f;
        }
        break;
    case 22:
    case 49:
        if (f2 >= 1.0f) {
            idx = func_overlay_52_03401390_1F6FDD8(arg1);
            f12 = 0.0f;
        }
        break;
    case 25:
        if (f2 > 1.0f) {
            scale = (1.0f - f12) / arg2;
        }
        break;
    case 26:
        if (f2 > 1.0f) {
            scale = (1.0f - f12) / arg2;
        }
        if (*(s8 *)(arg1 + 0x56B) == 0) {
            idx = func_overlay_52_03401390_1F6FDD8(arg1);
            f12 = 0.0f;
        }
        break;
    default:
        break;
    }
    objAnimDframe(arg0, scale, arg2);
    charAnimSoundTick(arg0, origPos, scale);
    func_overlay_52_034013D4_1F6FE1C(arg0, arg1, idx, f12);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o52/overlay_52/func_overlay_52_03401468_1F6FEB0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching (ported from overlay_50 func_overlay_50_03201688_1F6B330; state ids shifted for o52)
void func_overlay_52_03401688_1F700D0(u8 *arg0, u8 *arg1, f32 arg2) {
    f32 **hitList;
    f32 **trackList;
    s32 hitCount;
    s32 trackCount;
    s32 i;
    s32 idx;
    f32 probeY;
    f32 f0;
    f32 f2;
    f32 f12;
    f32 f14;
    f32 dx;
    f32 dz;
    f32 dist;
    f32 radius;

    probeY = *(f32 *)(arg0 + 0x10) + D_overlay_52_03402430;
    *(f32 *)(arg0 + 0x1C) = Cosf((s32) *(s16 *)(arg1 + 0x11C)) * *(f32 *)(arg1 + 0x10);
    *(f32 *)(arg0 + 0x20) = *(f32 *)(arg0 + 0x20) - (controlchr_gravity * arg2);
    *(f32 *)(arg0 + 0x24) = Sinf(*(s16 *)(arg1 + 0x11C)) * -*(f32 *)(arg1 + 0x10);
    objMoveXYZ(arg0, *(f32 *)(arg0 + 0x1C) * arg2, *(f32 *)(arg0 + 0x20) * arg2,
               *(f32 *)(arg0 + 0x24) * arg2);

    if (*(u8 **)(arg1 + 0xFC) != NULL) {
        u8 *target = *(u8 **)(*(u8 **)(arg1 + 0xFC) + 0x3C);

        dx = (f32) *(s16 *)(target + 0x4) - *(f32 *)(arg0 + 0xC);
        dz = (f32) *(s16 *)(target + 0x8) - *(f32 *)(arg0 + 0x14);
        radius = (f32) *(u16 *)(target + 0xC);
        dist = sqrtf((dx * dx) + (dz * dz));
        if ((radius < dist) && (dist > 0.0f)) {
            f2 = (dist / radius) - 1.0f;
            objMoveXYZ(arg0, dx * f2, 0.0f, dz * f2);
        }
    }

    hitCount = hitGetHeights(*(f32 *)(arg0 + 0xC), *(f32 *)(arg0 + 0x14), 0x800, &hitList);
    trackCount = trackGetHeights(*(f32 *)(arg0 + 0xC), *(f32 *)(arg0 + 0x14), 0x800, &trackList);

    if ((trackCount != 0) || (hitCount != 0)) {
        f0 = *(f32 *)(arg0 + 0x10);
        if (trackCount != 0) {
            for (i = 0; i < trackCount; i++) {
                if (*trackList[i] < probeY) {
                    break;
                }
            }
            if (i >= trackCount) {
                i = trackCount - 1;
            }
            f14 = *trackList[i];
        } else {
            f14 = -32000.0f;
        }
        if (hitCount != 0) {
            for (i = 0; i < hitCount; i++) {
                if (*hitList[i] < probeY) {
                    break;
                }
            }
            if (i >= hitCount) {
                i = hitCount - 1;
            }
            f2 = *hitList[i];
        } else {
            f2 = -32000.0f;
        }
        if (f14 < f2) {
            f12 = f0 - f2;
        } else {
            f12 = f0 - f14;
        }

        if (f12 <= 0.0f) {
            if ((*(u8 *)(arg1 + 0x568) == 0x23) && (*(s8 *)(arg0 + 0x3B) == 0x19)) {
                *(u8 *)(arg1 + 0x56B) = 0xA;
                func_overlay_52_034013D4_1F6FE1C(arg0, arg1, 0x1A, 0.0f);
            } else if (*(u8 *)(arg1 + 0x568) != 0x20) {
                idx = func_overlay_52_03401390_1F6FDD8(arg1);
                func_overlay_52_034013D4_1F6FE1C(arg0, arg1, idx, 0.0f);
            }
            if (*(u8 *)(arg1 + 0x568) != 0x2A) {
                *(u8 *)(arg1 + 0x568) = 0x20;
            }
            *(f32 *)(arg0 + 0x20) = 0.0f;
            objMoveXYZ(arg0, 0.0f, -f12, 0.0f);
            return;
        }

        if (*(s8 *)(arg0 + 0x3B) == 6) {
            if (*(f32 *)(arg0 + 0x10) < *(f32 *)(arg1 + 0x57C)) {
                if (f12 > 25.0f) {
                    func_overlay_52_034013D4_1F6FE1C(arg0, arg1, 0x19, 0.0f);
                    return;
                }
            }
        }
        if (f12 > 25.0f) {
            if (*(u8 *)(arg1 + 0x568) != 0x23) {
                if (*(u8 *)(arg1 + 0x568) != 0x2A) {
                    *(u8 *)(arg1 + 0x568) = 0x23;
                }
                func_overlay_52_034013D4_1F6FE1C(arg0, arg1, 0x19, 0.0f);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o52/overlay_52/func_overlay_52_03401688_1F700D0.s")
#endif
