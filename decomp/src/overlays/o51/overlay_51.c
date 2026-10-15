#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern f32 D_overlay_51_03301CE4;
extern f32 D_overlay_51_03301CE8;
extern f32 D_overlay_51_03301CEC;
extern f32 D_overlay_51_03301CF0;
extern f32 D_overlay_51_03301CF4;
extern f32 D_overlay_51_03301CF8;
extern f32 D_overlay_51_03301CFC;
extern f32 D_overlay_51_03301D00;
extern f32 D_overlay_51_03301D04;
extern f32 D_overlay_51_03301D08;
extern f32 D_overlay_51_03301D58;
extern s16 *D_overlay_51_03301D60;
extern s16 D_overlay_51_03301D64;
extern void *controlModeKeys;
f32 Powerf(f32, s32);
s16 dAngle(s16, s16, f32);
s32 mathSin(s16, s8);
void mainPauseDisable(s32);
void controlFrozen(void *, void *, void *);
void camSetZoom(s8, s32);
void charSpeak(void *, s32);
s32 controlGetManualAim(void *, void *, s32, s32, s32, s32, s16 *, s16 *, f32);
void *mainGetGameCharacter(f32, s8, s8);
void func_overlay_51_03301038_1F6D7B8(s16, s16);
void func_overlay_51_03300F44_1F6D6C4(void *, s16, s16);
void func_overlay_51_03301118_1F6D898(void *, void *, s32, f32);
s32 func_overlay_51_033010D4_1F6D854(void *);
extern f32 D_overlay_51_033018FC[];
extern u8 D_overlay_51_03301869[];
f32 Sinf(s16 arg0);
s32 hitGetHeights(f32 arg0, f32 arg1, s32 arg2, f32 ***arg3);
s32 trackGetHeights(f32 arg0, f32 arg1, s32 arg2, f32 ***arg3);
s32 objMoveXYZ(void *arg0, f32 arg1, f32 arg2, f32 arg3);
s32 objAnimSetMove(void *, s8, f32);
s32 objAnimDframe(void *, f32, f32);
void charAnimSoundTick(void *, f32, f32);
extern f32 D_overlay_51_03301CE0;
extern s32 quickWeaponKey[];
extern u8 allweaponsCheat;
extern u8 invulnerabilityCheat;
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
void func_overlay_51_033008F0_1F6D070(void *, void *, f32);
void func_overlay_51_03300DC0_1F6D540(void *, void *, f32);
void func_overlay_51_03300E98_1F6D618(void *, void *, f32);
void func_overlay_51_03301170_1F6D8F0(void *, void *, f32);
void func_overlay_51_0330134C_1F6DACC(void *, void *, f32);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void dogBossControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *pl;
    u8 *chr;
    u8 *cam;
    u8 *ent;
    u8 *ent0;
    u8 *game;
    u8 *slot;
    void *shield;
    f32 speed;
    f32 var_f0;
    s32 mtxRet;
    s32 sp48;
    s32 i;
    s32 cnt;
    s32 ptr;
    s16 v0;
    s8 pl585;

    pl = *(u8 **)(obj + 0x68);
    /* sig mismatch: decl in this file takes (f32, s8, s8); asm passes (s8, s8) */
    chr = (u8 *)((void *(*)(s8, s8))mainGetGameCharacter)(*(s8 *)(pl + 0x00), *(s8 *)(pl + 0x01));
    D_overlay_51_03301D60 = (s16 *)(pl + 0x240);
    *(s32 *)(obj + 0x84) = 0;
    *(u8 *)(pl + 0x1F4) = 0xF;
    *(u8 *)(pl + 0x1F8) = 0;
    *(u8 *)(pl + 0x14A) = 0;
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
    D_overlay_51_03301D64 = (s16)*(s8 *)(pl + 0x577);
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
            func_overlay_51_03301118_1F6D898(obj, pl, 0x17, 0);
        }
        *(s8 *)(pl + 0x19C) = 0;
    }
    switch (*(u8 *)(pl + 0x568) & ~0x20) {
    default:
        speed = (f32)arg1;
        break;
    case 0:
        speed = (f32)arg1;
        func_overlay_51_033008F0_1F6D070(obj, pl, speed);
        break;
    case 3:
        speed = (f32)arg1;
        func_overlay_51_03300DC0_1F6D540(obj, pl, speed);
        break;
    case 10:
        speed = (f32)arg1;
        func_overlay_51_03300E98_1F6D618(obj, pl, speed);
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
        sp48 = *(u8 *)(chr + 0x70);
        pl585 = *(s8 *)(pl + 0x585);
        if ((sp48 != pl585) && (disablejoy == 0)) {
            /* asm does not set a3 before this call */
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
        if (sp48 != *(u8 *)(chr + 0x70)) {
            *(u8 *)(pl + 0x538) = 0;
            *(u8 *)(pl + 0x53D) = 0;
            *(s8 *)(pl + 0x585) = (s8)*(u8 *)(chr + 0x70);
        }
    }
    func_overlay_51_03301170_1F6D8F0(obj, pl, speed);
    func_overlay_51_0330134C_1F6DACC(obj, pl, speed);
    shield = *(void **)(pl + 0x5BC);
    if (shield != NULL) {
        if ((*(u8 *)(pl + 0x568) & ~0x20) == 1) {
            invincibilityShieldTransform(shield, 0x3F800000, 0x3F400000, 0x78);
        } else {
            invincibilityShieldTransform(shield, 0x3F800000, 0x3F800000, 0x78);
        }
    }
    *D_overlay_51_03301D60 = 0x1000;
    D_overlay_51_03301D60 = (s16 *)((u8 *)D_overlay_51_03301D60 + 2);
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
                var_f0 = D_overlay_51_03301CE0;
            }
            *(s8 *)(*(u8 **)(obj + 0x50) + 0x0E) = (s8)(s32)(var_f0 * 4.0f);
        }
    }
    if (controlThrowWeapon(controlUpdateWeapon(obj, pl, speed)) != 0) {
        if (*(s8 *)(obj + 0x3B) == 0xE) {
            objAnimSetFrame(obj, 0);
        } else {
            func_overlay_51_03301118_1F6D898(obj, pl, 0xE, 0);
        }
        *(s8 *)(pl + 0x577) = 0x28;
    }
    partUpdateTriggers(obj, arg1);
    if (controlDkeys & 0x10) {
        cnt = 5;
        slot = pl + 0x14;
        if (*(s32 *)(pl + 0x1BC) != 0) {
            /* asm: bnez on the pre-decrement counter, so the body runs 6 times */
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
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o51/overlay_51/dogBossControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_51_033008F0_1F6D070(void *arg0, void *arg1, f32 arg2) {
    u8 *obj = (u8 *)arg0;
    u8 *pl = (u8 *)arg1;
    u8 *chr;
    s32 n = (s32)arg2;
    s32 savedYaw;
    s32 yawNew;
    s32 target;
    s32 oldYaw;
    s16 manualYaw;
    s16 manualPitch;
    s16 yawDelta;
    f32 angleStep;
    f32 temp_f2;
    s8 pitchKick;

    chr = (u8 *)mainGetGameCharacter(arg2, pl[0x0], pl[0x1]);
    *(s8 *)(pl + 0x576) = 0;
    *(s16 *)(pl + 0x13E) = 0;
    if ((chr[0x70] != 7) && (*(s32 *)((u8 *)controlModeKeys + 0xC) & controlDkeys)) {
        *(u8 *)(pl + 0x568) = 0x23;
        *(f32 *)(pl + 0x57C) = *(f32 *)(obj + 0x10);
        *(f32 *)(obj + 0x20) = *(f32 *)(obj + 0x20) + 10.0f;
        func_overlay_51_03301118_1F6D898(arg0, arg1, 5, 0);
        charSpeak(arg0, 0);
    } else if (controlKeys & 2) {
        *(f32 *)(pl + 0x10) = *(f32 *)(pl + 0x10) - (D_overlay_51_03301CE4 * arg2);
        if (*(f32 *)(pl + 0x10) < -3.0f) {
            *(f32 *)(pl + 0x10) = -3.0f;
        }
    } else if (controlKeys & 1) {
        *(f32 *)(pl + 0x10) = *(f32 *)(pl + 0x10) + (D_overlay_51_03301CE8 * arg2);
        if (*(f32 *)(pl + 0x10) > 3.0f) {
            *(f32 *)(pl + 0x10) = 3.0f;
        }
    } else {
        /* sig mismatch: asm passes arg2 as a float and as (s32) */
        *(f32 *)(pl + 0x10) = *(f32 *)(pl + 0x10) * ((f32 (*)(f32, f32, s32))Powerf)(D_overlay_51_03301CEC, arg2, n);
        temp_f2 = *(f32 *)(pl + 0x10);
        if ((D_overlay_51_03301CF0 < temp_f2) && (temp_f2 < D_overlay_51_03301CF4)) {
            *(f32 *)(pl + 0x10) = 0.0f;
        }
    }
    savedYaw = *(s16 *)(pl + 0x11C) & 0xFFFF;
    *(s16 *)(pl + 0x11C) = *(s16 *)obj;
    yawNew = savedYaw;
    if (D_overlay_51_03301D64 == 0) {
        if (controlGetManualAim(arg0, arg1, 0xE38, 0xE38, -0x2AAA, 0x2AAA, &manualYaw, &manualPitch, arg2) != 0) {
            camSetZoom(pl[0x0], *(s32 *)(pl + 0x1EC));
        }
    } else {
        manualYaw = *(s16 *)(pl + 0x1DC);
        manualPitch = *(s16 *)(pl + 0x1DE) - *(s16 *)(pl + 0x1E2);
    }
    oldYaw = *(s16 *)(pl + 0x11C) & 0xFFFF;
    *(s16 *)(pl + 0x11C) = (s16)yawNew;
    target = oldYaw;
    if ((oldYaw < yawNew) && ((yawNew - oldYaw) >= 0x8000)) {
        target = oldYaw + 0x10000;
    }
    if ((yawNew < target) && ((target - yawNew) >= 0x8000)) {
        yawNew += 0x10000;
    }
    if (yawNew < target) {
        if ((target - yawNew) >= 0x2801) {
            target = yawNew;
        }
    } else if ((yawNew - target) >= 0x2801) {
        target = yawNew - 0x2800;
    }
    *(s16 *)obj = (s16)target;
    /* sig mismatch: asm passes arg2 as a float and as (s32) */
    angleStep = 1.0f - ((f32 (*)(f32, f32, s32))Powerf)(D_overlay_51_03301CF8, arg2, n);
    *(s16 *)(pl + 0x1E0) = dAngle(*(s16 *)(pl + 0x1E0), manualPitch, angleStep);
    manualPitch += *(s16 *)(pl + 0x1E2);
    *(s16 *)(pl + 0x1DC) = dAngle(*(s16 *)(pl + 0x1DC), manualYaw, angleStep);
    *(s16 *)(pl + 0x1DE) = dAngle(*(s16 *)(pl + 0x1DE), manualPitch, angleStep);
    *(s16 *)(pl + 0x1CE) = dAngle(*(s16 *)(pl + 0x1CE), manualYaw, angleStep);
    *(s16 *)(pl + 0x1D0) = dAngle(*(s16 *)(pl + 0x1D0), manualPitch, angleStep);
    yawDelta = *(s16 *)(pl + 0x1CE);
    *(s16 *)(pl + 0x1C6) = (s16)(yawDelta + *(s16 *)obj);
    *(s16 *)(pl + 0x1CA) = *(s16 *)(pl + 0x1C6);
    *(s16 *)(pl + 0x1C8) = (s16)(*(s16 *)(pl + 0x1D0) + *(s16 *)(obj + 0x2));
    *(s16 *)(pl + 0x1CC) = *(s16 *)(pl + 0x1C8);
    manualYaw = yawDelta;
    manualPitch = *(s16 *)(pl + 0x1D0);
    pitchKick = (s8)pl[0x1F6];
    if (pitchKick != 0) {
        manualPitch += (s32)(((s8)pl[0x1F7]) * mathSin((s16)(pitchKick << 0xC), pitchKick)) >> 8;
    }
    func_overlay_51_03301038_1F6D7B8(*(s16 *)(pl + 0x1DE), *(s16 *)(pl + 0x1DC));
    func_overlay_51_03300F44_1F6D6C4(arg1, manualPitch, manualYaw);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o51/overlay_51/func_overlay_51_033008F0_1F6D070.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_51_03300DC0_1F6D540(void *arg0, void *arg1, f32 arg2) {
    if ((*(f32 *)((u8 *)arg0 + 0x20) < 0.0f) && (*(f32 *)((u8 *)arg0 + 0x10) < *(f32 *)((u8 *)arg1 + 0x57C))) {
        /* sig mismatch: asm passes arg2 as a float and as (s32) */
        *(f32 *)((u8 *)arg1 + 0x10) = *(f32 *)((u8 *)arg1 + 0x10) * ((f32 (*)(f32, f32, s32))Powerf)(D_overlay_51_03301CFC, arg2, (s32)arg2);
        if ((D_overlay_51_03301D00 < *(f32 *)((u8 *)arg1 + 0x10)) && (*(f32 *)((u8 *)arg1 + 0x10) < D_overlay_51_03301D04)) {
            *(f32 *)((u8 *)arg1 + 0x10) = 0.0f;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o51/overlay_51/func_overlay_51_03300DC0_1F6D540.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_51_03300E98_1F6D618(void *arg0, void *arg1, f32 arg2) {
    f32 temp_f10;

    *(s16 *)(*(u8 **)((u8 *)arg0 + 0x4C) + 0x6) = 0;
    mainPauseDisable(0xA);
    temp_f10 = *(f32 *)((u8 *)arg1 + 0x10) * Powerf(D_overlay_51_03301D08, (s32)arg2);
    *(s8 *)((u8 *)arg1 + 0x19C) = 0;
    *(f32 *)((u8 *)arg1 + 0x10) = temp_f10;
    if (*(f32 *)((u8 *)arg0 + 0x28) == 1.0f) {
        controlFrozen(arg0, arg1, arg1);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o51/overlay_51/func_overlay_51_03300E98_1F6D618.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_51_03300F44_1F6D6C4(void *arg0, s16 arg1, s16 arg2) {
    if (*(s8 *)((u8 *)arg0 + 0x1) == 6) {
        D_overlay_51_03301D60[0] = 0x36;
        D_overlay_51_03301D60[1] = arg1;
        D_overlay_51_03301D60[2] = 0x38;
        D_overlay_51_03301D60[3] = arg2;
        D_overlay_51_03301D60 += 4;
        return;
    }
    D_overlay_51_03301D60[0] = 0x5A;
    D_overlay_51_03301D60[1] = arg1;
    D_overlay_51_03301D60[2] = 0x5C;
    D_overlay_51_03301D60[3] = arg2;
    D_overlay_51_03301D60 += 4;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o51/overlay_51/func_overlay_51_03300F44_1F6D6C4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_51_03301038_1F6D7B8(s16 arg0, s16 arg1) {
    s16 var_a0;

    var_a0 = arg0;
    if (var_a0 >= 0x2AAB) {
        var_a0 = 0x2AAA;
    } else if (var_a0 < -0x2AAA) {
        var_a0 = -0x2AAA;
    }
    D_overlay_51_03301D60[0] = 0x30;
    D_overlay_51_03301D60[1] = var_a0;
    D_overlay_51_03301D60[2] = 0x32;
    D_overlay_51_03301D60[3] = arg1;
    D_overlay_51_03301D60 += 4;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o51/overlay_51/func_overlay_51_03301038_1F6D7B8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_51_033010D4_1F6D854(void *arg0) {
    f32 temp_f0 = *(f32 *)((u8 *)arg0 + 0x10);

    if (temp_f0 < 0.0f) {
        return 0;
    }
    if (temp_f0 > 0.0f) {
        return 0;
    }
    return 0x12;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o51/overlay_51/func_overlay_51_033010D4_1F6D854.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_51_03301118_1F6D898(void *arg0, void *arg1, s32 arg2, f32 arg3) {
    s8 temp_v0;
    u8 temp_a1;

    temp_v0 = *(s8 *)((u8 *)arg0 + 0x3B);
    if (temp_v0 != 0x17) {
        temp_a1 = D_overlay_51_03301869[arg2 * 5];
        if (temp_a1 != temp_v0) {
            objAnimSetMove(arg0, temp_a1, arg3);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o51/overlay_51/func_overlay_51_03301118_1F6D898.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_51_03301170_1F6D8F0(void *arg0, void *arg1, f32 arg2) {
    f32 var_f20;
    f32 var_f12;
    f32 sp34;
    f32 temp_f2;
    s32 sp2C;
    s8 temp_v0;

    temp_v0 = *(s8 *)((u8 *)arg0 + 0x3B);
    var_f20 = D_overlay_51_033018FC[temp_v0];
    sp2C = temp_v0;
    var_f12 = *(f32 *)((u8 *)arg0 + 0x28);
    sp34 = var_f12;
    temp_f2 = (var_f20 * arg2) + var_f12;
    switch (temp_v0) {
    case 18:
        sp2C = func_overlay_51_033010D4_1F6D854(arg1);
        if (*(f32 *)((u8 *)arg1 + 0x10) != 0.0f) {
            var_f12 = 0.25f;
        }
        break;
    case 0:
        var_f20 *= *(f32 *)((u8 *)arg1 + 0x10);
        sp2C = func_overlay_51_033010D4_1F6D854(arg1);
        if (*(f32 *)((u8 *)arg1 + 0x10) == 0.0f) {
            var_f12 = 0.0f;
        }
        break;
    case 14:
        if (temp_f2 >= 1.0f) {
            sp2C = func_overlay_51_033010D4_1F6D854(arg1);
            var_f12 = 0.0f;
        }
        break;
    case 16:
        if (temp_f2 > 1.0f) {
            var_f20 = (1.0f - var_f12) / arg2;
        }
        break;
    case 17:
        if (temp_f2 > 1.0f) {
            var_f20 = (1.0f - var_f12) / arg2;
        }
        if (*(s8 *)((u8 *)arg1 + 0x56B) == 0) {
            sp2C = func_overlay_51_033010D4_1F6D854(arg1);
            var_f12 = 0.0f;
        }
        break;
    default:
        break;
    }
    objAnimDframe(arg0, var_f20, arg2);
    charAnimSoundTick(arg0, sp34, var_f20);
    func_overlay_51_03301118_1F6D898(arg0, arg1, sp2C, var_f12);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o51/overlay_51/func_overlay_51_03301170_1F6D8F0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_51_0330134C_1F6DACC(void *arg0, void *arg1, f32 arg2) {
    u8 *obj = arg0;
    u8 *st = arg1;
    f32 f0;
    f32 f2;
    f32 f12;
    f32 f14;
    f32 f16;
    f32 f18;
    f32 dist;
    f32 radius;
    f32 k;
    f32 **sp28;
    f32 **sp2C;
    s32 hitCount;
    s32 trackCount;
    s32 idx;
    s32 i;
    s32 ptr;
    u8 state;
    void *temp_v1;
    void *temp_v0;

    f16 = *(f32 *)(obj + 0x10) + D_overlay_51_03301D58;
    *(f32 *)(obj + 0x1C) = Cosf((s32)*(s16 *)(st + 0x11C)) * *(f32 *)(st + 0x10);
    *(f32 *)(obj + 0x20) = *(f32 *)(obj + 0x20) - (controlchr_gravity * arg2);
    *(f32 *)(obj + 0x24) = Sinf(*(s16 *)(st + 0x11C)) * -*(f32 *)(st + 0x10);
    objMoveXYZ(obj, *(f32 *)(obj + 0x1C) * arg2, *(f32 *)(obj + 0x20) * arg2, *(f32 *)(obj + 0x24) * arg2);

    temp_v1 = *(void **)(st + 0xFC);
    if (temp_v1 != NULL) {
        temp_v0 = *(void **)((u8 *)temp_v1 + 0x3C);
        f14 = (f32)*(s16 *)((u8 *)temp_v0 + 0x4) - *(f32 *)(obj + 0xC);
        f18 = (f32)*(s16 *)((u8 *)temp_v0 + 0x8) - *(f32 *)(obj + 0x14);
        radius = (f32)*(u16 *)((u8 *)temp_v0 + 0xC);
        dist = sqrtf((f14 * f14) + (f18 * f18));
        if ((radius < dist) && (dist > 0.0f)) {
            k = (dist / radius) - 1.0f;
            objMoveXYZ(obj, f14 * k, 0.0f, f18 * k);
        }
    }

    hitCount = hitGetHeights(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x14), 0x800, &sp28);
    trackCount = trackGetHeights(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x14), 0x800, &sp2C);
    if ((trackCount != 0) || (hitCount != 0)) {
        if (trackCount != 0) {
            /* first track entry at or above the object's top, else the last one */
            i = 0;
            if (trackCount > 0) {
                do {
                    if (*sp2C[i] < f16) {
                        break;
                    }
                    i += 1;
                } while (i != trackCount);
            }
            idx = i;
            if (!(idx < trackCount)) {
                idx = trackCount - 1;
            }
            f14 = *sp2C[idx];
        } else {
            f14 = -32000.0f;
        }
        if (hitCount != 0) {
            i = 0;
            if (hitCount > 0) {
                do {
                    if (*sp28[i] < f16) {
                        break;
                    }
                    i += 1;
                } while (i != hitCount);
            }
            idx = i;
            if (!(idx < hitCount)) {
                idx = hitCount - 1;
            }
            f2 = *sp28[idx];
        } else {
            f2 = -32000.0f;
        }
        if (f14 < f2) {
            f12 = *(f32 *)(obj + 0x10) - f2;
        } else {
            f12 = *(f32 *)(obj + 0x10) - f14;
        }

        f0 = *(f32 *)(obj + 0x10);
        if (f12 <= 0.0f) {
            state = st[0x568];
            if ((state == 0x23) && (*(s8 *)(obj + 0x3B) == 0x10)) {
                st[0x56B] = 0xA;
                func_overlay_51_03301118_1F6D898(obj, st, 0x11, 0.0f);
                state = st[0x568];
            } else if (state != 0x20) {
                ptr = func_overlay_51_033010D4_1F6D854(st);
                func_overlay_51_03301118_1F6D898(obj, st, ptr, 0.0f);
                state = st[0x568];
            }
            if (state != 0x2A) {
                st[0x568] = 0x20;
            }
            *(f32 *)(obj + 0x20) = 0.0f;
            objMoveXYZ(obj, 0.0f, -f12, 0.0f);
        } else {
            if ((*(s8 *)(obj + 0x3B) == 5) && (f0 < *(f32 *)(st + 0x57C)) && (25.0f < f12)) {
                func_overlay_51_03301118_1F6D898(obj, st, 0x10, 0.0f);
            } else if (25.0f < f12) {
                state = st[0x568];
                if (state != 0x23) {
                    if (state != 0x2A) {
                        st[0x568] = 0x23;
                    }
                    func_overlay_51_03301118_1F6D898(obj, st, 0x10, 0.0f);
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o51/overlay_51/func_overlay_51_0330134C_1F6DACC.s")
#endif
