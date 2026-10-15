#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
extern s16 *D_overlay_16_010080D8;
extern f32 D_overlay_16_01007ECC;
extern f32 D_overlay_16_01007ED0;
extern f32 D_overlay_16_01007ED4;
extern void *controlModeKeys;
s32 mathDiffAngle(s32, s32);
s32 controlCeiling(f32, f32, s32, f32, f32);
void controlWalkingBack(void *, void *, f32 *, s16, s32, s32, f32, f32);
void controlHalfTurn(void *, void *, f32 *, s16 *, s32, s32, void *, f32, f32);
s32 lobbycamInuse();
s32 staticcamInuse();
extern f32 D_overlay_16_01007EA0;
extern f32 D_overlay_16_01007EA4;
extern f32 D_overlay_16_01007EA8;
extern f32 D_overlay_16_01007EAC;
extern f32 D_overlay_16_01007EB0;
extern f32 D_overlay_16_01007EB4;
extern f32 D_overlay_16_01007EB8;
extern f32 D_overlay_16_01007EBC;
extern f32 D_overlay_16_01007EC0;
s16 dAngle(s16, s16, f32);
f32 Powerf(f32, s32);
void func_overlay_16_01004934_1F2294C(void *, void *, s32, f32);
void func_overlay_16_01004F78_1F22F90(void *, void *, s32, s32);
void amSndPlay(s32, void *, s32, void *);
void amSndSetVol(s32, s32, s32);
void *objSetupObject(s16 *, s32);
void partUpdateTriggers(void *, s32);
f32 Sinf(s16);
void dropletAdd(f32, f32, f32, f32, f32, f32, f32, f32);
void mathOneFloatPY(s16 *, f32 *);
extern f32 D_overlay_16_01007E6C;
extern f32 D_overlay_16_01007E70;
extern f32 D_overlay_16_01007E74;
extern f32 D_overlay_16_01007E78;
extern f32 D_overlay_16_01007EC4;
extern f32 D_overlay_16_01007EC8;
s32 func_overlay_16_01004E08_1F22E20(void *);
extern f32 D_overlay_16_01007F0C;
extern f32 D_overlay_16_01007F10;
extern f32 D_overlay_16_01007F14;
extern f32 D_overlay_16_01007F18;
extern f32 D_overlay_16_01007F1C;
extern f32 D_overlay_16_01007F20;
extern f32 D_overlay_16_01007F24;
extern f32 D_overlay_16_01007F28;
extern f32 D_overlay_16_01007F2C;
extern f32 D_overlay_16_01007F30;
extern f32 D_overlay_16_01007F34;
extern f32 D_overlay_16_01007F38;
extern f32 D_overlay_16_01007F3C;
extern s16 D_overlay_16_010080DC;
extern f32 D_overlay_16_010080E4;
extern f32 D_overlay_16_01007F40;
extern f32 D_overlay_16_01007F44;
extern f32 D_overlay_16_01007F48;
extern f32 D_overlay_16_01007F4C;
extern f32 D_overlay_16_01007F50;
extern f32 D_overlay_16_01007F54;
extern f32 D_overlay_16_01007F58;
extern f32 D_overlay_16_01007F5C;
extern f32 D_overlay_16_01007F60;
extern u8 D_overlay_16_01007D7C;
extern u8 D_overlay_16_01007DAC;
f32 controlMakeV(f32, f32, void *, void *, f32);
void camSetZoom(s8, s32);
s32 controlGetManualAim(void *, void *, s32, s32, s32, s32, s16 *, s16 *, f32);
s32 frontGetTargetControl(s8);
void *mainGetGameCharacter(s8, s8);
s32 mathSin(s16, s8);
extern f32 D_overlay_16_01007F64;
extern u8 D_overlay_16_01007870[];
extern u8 D_overlay_16_010077E4[];
extern s32 D_overlay_16_010080E0;
s32 controlPlayerGunWeight(void *);
void controlSetTransition(void *, void *, void *, s32);
void objAnimSetMove(void *, u8, s32, u8);
s32 controlGroundHits(f32, f32, void *, void *, f32);
void mathOneFloatYPR(f32, f32, s16 *, f32 *, s16);
void objMoveXYZ(f32, f32, void *, f32, f32, f32);
void sidekickpadMovePlayer(f32, f32, void *, void *, s32);
void transformerMovePlayer(f32, f32, void *, void *, s32);
extern f32 D_overlay_16_0100806C;
extern f32 D_overlay_16_01008070;
extern f32 D_overlay_16_01008074;
extern f32 D_overlay_16_01007974[];
extern f32 D_overlay_16_01008034;
extern f32 D_overlay_16_01008038;
extern f32 D_overlay_16_0100803C;
extern f32 D_overlay_16_01008040;
extern f32 D_overlay_16_01008044;
extern f32 D_overlay_16_01008048;
extern f32 D_overlay_16_0100804C;
extern f32 D_overlay_16_01008050;
extern f32 D_overlay_16_01008054;
extern f32 D_overlay_16_01008058;
extern f32 D_overlay_16_0100805C;
extern f32 D_overlay_16_01008060;
extern f32 D_overlay_16_01008064;
extern f32 D_overlay_16_01008068;
extern s16 D_overlay_16_010080DE;
void charAnimSoundTick(void *, f32, f32);
void objAnimDframe(void *, f32, f32);
extern f32 D_overlay_16_01008078;
extern f32 D_overlay_16_0100807C;
extern f32 D_overlay_16_01008080;
extern f32 D_overlay_16_01008084;
extern f32 D_overlay_16_01007DDC[];
extern f32 D_overlay_16_01007DFC[];
extern f32 D_overlay_16_01008088;
extern f32 D_overlay_16_0100808C;
extern f32 D_overlay_16_01008090;
extern f32 D_overlay_16_01008094;
extern f32 D_overlay_16_01008098;
extern f32 D_overlay_16_0100809C;
extern f32 D_overlay_16_010080A0;
extern f32 D_overlay_16_010080A4;
void charSpeak(void *, u8);
extern f32 D_overlay_16_010080A8;
extern f32 D_overlay_16_010080AC;
extern f32 D_overlay_16_010080B0;
extern f32 D_overlay_16_010080B4;
extern f32 D_overlay_16_010080B8;
extern f32 D_overlay_16_010080BC;
extern u8 numberOfPlayers;
void mainPauseDisable(s32);
void controlFrozen(void *, void *);
void controlMakeGravity(f32, void *, s32, s32);
extern f32 D_overlay_16_010080C0;
extern f32 D_overlay_16_010080C4;
extern s32 D_overlay_16_010080D0;
extern s32 D_overlay_16_010080D4;
extern s32 D_overlay_16_01007A6C[];
extern f32 D_overlay_16_01007ED8;
extern f32 D_overlay_16_01007EDC;
extern f32 D_overlay_16_01007EE0;
extern f32 D_overlay_16_01007EE4;
extern f32 D_overlay_16_01007EE8;
extern f32 D_overlay_16_01007EEC;
extern f32 D_overlay_16_01007EF0;
extern f32 D_overlay_16_01007EF4;
extern f32 D_overlay_16_01007EF8;
extern f32 D_overlay_16_01007EFC;
extern f32 D_overlay_16_01007F00;
extern f32 D_overlay_16_01007F04;
extern f32 D_overlay_16_01007F08;
extern u8 multiPlayerGame;
void hitPlayerKilledPlayer(u8 *, u8 *, s32 *, s8);
void fxNightVisionSkip(void);
void frontFlashScreen(s32, s32, s32);

extern u8 arithmeticSums[];
extern u8 weaponTable[];
extern s32 quickWeaponKey[];
extern s16 *controlcam;
extern u8 allweaponsCheat;
extern u8 invulnerabilityCheat;
extern u8 deformedchars;
extern u8 D_overlay_16_01007A44[];
extern s32 D_overlay_16_01007A60[];
extern s32 D_overlay_16_01007D4C[];
extern s32 D_overlay_16_01007D64[];
extern f32 D_overlay_16_01007E20;
extern f32 D_overlay_16_01007E24;
extern f32 D_overlay_16_01007E28;
extern f32 D_overlay_16_01007E2C;
extern f32 D_overlay_16_01007E30;
extern f32 D_overlay_16_01007E68;
void controlAttitude(void *, void *, f32);
void controlClearAimlocks(void *);
void controlDisableJoypad(s32);
void controlEmptyPlayersHand(void *, u8);
void controlFSUvels(void *, void *);
void controlFadePlayer(void *, s32, s32);
void controlFireDummyShot(void *, void *);
void controlGrabOK(void *, void *, f32, s16, f32, void *);
void controlHangOK(void *, void *, f32, f32, f32, void *);
void controlPlatform(void *, void *, f32);
void controlReadJoypad(s32);
void controlSelectNextWeapon(void *, void *, s8);
void controlSelectPreviousWeapon(void *, void *, s8);
s32 controlSelectWeapon(void *, void *, s8, s32);
void controlSetRumble(s8, s32, s32, s32, s32);
void controlSquashCheckPost(void *, void *, s32);
void controlSquashCheckPrior(void *, void *, s32);
s32 controlThrowWeapon(s32);
void controlUpdateJetFlames(void *, void *, s32, s32, s32);
void controlUpdatePlayerAim(void *, void *, s32, s32, f32, f32, f32, s32);
s32 controlUpdateWeapon(void *, void *, f32);
void func_overlay_16_01001B48_1F1FB60(void *, void *, s32);
void func_overlay_16_01002220_1F20238(u8 *, u8 *, s32);
void func_overlay_16_01002708_1F20720(u8 *, u8 *, f32, s16, f32);
void func_overlay_16_01002EB4_1F20ECC(void *, void *, f32, s16, f32);
void func_overlay_16_0100321C_1F21234(void *, void *, f32, s16, f32);
void func_overlay_16_01003464_1F2147C(u8 *, u8 *, f32, s16, f32);
void func_overlay_16_01003F30_1F21F48(void *, void *, f32, s16, f32);
void func_overlay_16_01004440_1F22458(void *, void *, f32, s16, f32);
void func_overlay_16_01004840_1F22858(s32, void *, s32);
void func_overlay_16_01005120_1F23138(void *, void *, f32, f32);
void func_overlay_16_01005BB8_1F23BD0(void *, void *, f32);
void func_overlay_16_01006290_1F242A8(void *, void *, s32);
void func_overlay_16_0100650C_1F24524(void *, void *, f32, s16, f32);
void func_overlay_16_01006AEC_1F24B04(void *, void *, s32, s32, f32);
void func_overlay_16_01006E24_1F24E3C(void *, void *, f32);
void func_overlay_16_010070A4_1F250BC(void *, void *, f32, s16, f32);
void func_overlay_16_01007344_1F2535C(void *, void *, s32);
void func_overlay_16_010073A8_1F253C0(void *, void *, s32, s32, f32);
void invincibilityShieldTransform(void *, s32, s32, s16);
void lightObject(void *, void *, s32, s32);
void objAnimTextures(void *, void *, void *, s8);
void modGenAnimMatrices(void *, void *, void *, f32, f32);
s32 objMakeGunMtx(void *, void *, void *, u8, void *, void *, void *, void *);
void objEnsureNotTargetted(void *);
void amTunePlay(u8);
void amSndStop(s32);
s32 mainPlayerHas(s8, s8, s32);
void mainPlayerCollected(s8, s8, s32);
s32 trackPolyHeight(f32, f32, void *, s32);
void wakeUpdateRipple(void *, s32);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Layout notes: st = obj->unk68 (player state, raw offsets), chr = mainGetGameCharacter() result.
// cf. overlay_16 conventions: u8* raw offsets, D_overlay_16_010080D8 is a s16 display-list cursor.
void boyControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *st;
    u8 *chr;
    u8 *game;
    u8 *inst;
    u8 *model;
    u8 *flags;
    u8 *tbl;
    u8 *w;
    u8 *cobj;
    u8 *shield;
    u8 *objRef58;
    u8 mask;
    u8 v6;
    f32 fArg1;
    f32 stickMag;
    f32 stickAngF;
    f32 f0;
    f32 vec[3];
    s16 rot[3];
    s16 stickAng;
    s32 landedFlag;
    s32 prevWeapon;
    s32 tp;
    s32 v;
    s32 v2;
    s32 t;
    s32 i;
    s32 k;
    s32 iv;
    s32 fl;
    s32 q;
    s32 wret;
    s32 dlInt[6];
    s32 dlFlt[6];

    /* ---- prologue: state setup ---- */
    D_overlay_16_010080E0 = 0;
    st = *(u8 **)(obj + 0x68);
    *(s32 *)(obj + 0x84) = 0;
    D_overlay_16_010080D8 = (s16 *)(st + 0x240);
    D_overlay_16_010080DE = 0;
    chr = (u8 *)mainGetGameCharacter(*(s8 *)st, *(s8 *)(st + 1));
    if (*(u8 *)(st + 0x568) != 3) {
        *(u8 *)(st + 0x56A) = 0;
    }
    *(u8 *)(st + 0x19E) = 0;
    *(s16 *)(st + 0x11E) = 0;
    *(s16 *)(st + 0x120) = 0;
    D_overlay_16_010080D0 = 0;
    D_overlay_16_010080D4 = 0;
    v = *(u8 *)(st + 0x568);
    if (v == 6 || v == 8 || v == 7 || v == 0xC) {
        *(s32 *)(st + 0x510) = *(s32 *)(st + 0x16C);
    } else {
        *(s32 *)(st + 0x16C) = 0;
    }
    fArg1 = (f32)arg1;
    controlPlatform(obj, st, fArg1);
    controlAttitude(obj, st, fArg1);
    controlSquashCheckPrior(obj, st, arg1);

    /* ---- stick-speed scale ---- */
    D_overlay_16_010080E4 = 0.0625f;
    if (multiPlayerGame != 0) {
        v2 = *(s8 *)(st + 0x189);
        if (v2 == 2 || v2 == 7) {
            D_overlay_16_010080E4 = D_overlay_16_01007E20;
        } else if (v2 >= 4) {
            D_overlay_16_010080E4 = D_overlay_16_01007E24;
        }
    }
    if (*(u16 *)((u8 *)arithmeticSums + 4) != 0xDB4F) {
        D_overlay_16_010080E4 = D_overlay_16_01007E28;
    }
    D_overlay_16_010080DC = *(s8 *)(st + 0x577);

    /* ---- timers that count down by arg1 ---- */
    if (*(s8 *)(st + 0x56B) != 0) {
        controlDisableJoypad(1);
        *(s8 *)(st + 0x56B) = (s8)(*(s8 *)(st + 0x56B) - arg1);
        if (*(s8 *)(st + 0x56B) < 0) {
            *(s8 *)(st + 0x56B) = 0;
        }
    }
    if (*(s8 *)(st + 0x577) != 0) {
        controlDisableJoypad(1);
        *(s8 *)(st + 0x577) = (s8)(*(s8 *)(st + 0x577) - arg1);
        if (*(s8 *)(st + 0x577) < 0) {
            *(s8 *)(st + 0x577) = 0;
        }
    }
    if (*(u8 *)(st + 0x1F9) != 0 || *(u8 *)(st + 0x1FA) != 0 || *(s8 *)(st + 0x186) != 0 || *(u8 *)(st + 0x198) != 0 || *(u8 *)(st + 0x5EE) != 0 || *(u8 *)(st + 0x568) == 0xA || *(s32 *)(st + 0x5C0) != 0) {
        controlDisableJoypad(1);
    }
    if (*(u8 *)(st + 0x10D) != 0 || *(u8 *)(st + 0x19F) != 0) {
        controlDisableJoypad(1);
        if (*(s8 *)(obj + 0x3B) != 0x27) {
            func_overlay_16_01004F78_1F22F90(obj, st, 0x27, 0);
        }
    }
    if ((s32)*(u8 *)(st + 0x1FA) >= 2) {
        *(u8 *)(st + 0x1FA) = 0;
    }
    if ((s32)*(u8 *)(st + 0x198) >= 2) {
        *(u8 *)(st + 0x198) = 0;
    }
    if (*(u8 *)(st + 0x10D) == 4) {
        *(u8 *)(st + 0x10D) = 0;
        *(f32 *)(st + 0x594) = 0.0f;
    }

    /* ---- joypad read, gravity, position clamps ---- */
    controlReadJoypad(*(s8 *)st);
    ((void (*)(void *))controlMakeGravity)(st); /* sig mismatch: asm passes only a0 */
    if (*(f32 *)(obj + 0x1C) < -50.0f) {
        *(f32 *)(obj + 0x1C) = -50.0f;
    }
    if (*(f32 *)(obj + 0x1C) > 50.0f) {
        *(f32 *)(obj + 0x1C) = 50.0f;
    }
    if (*(f32 *)(obj + 0x20) < -50.0f) {
        *(f32 *)(obj + 0x20) = -50.0f;
    }
    if (*(f32 *)(obj + 0x20) > 50.0f) {
        *(f32 *)(obj + 0x20) = 50.0f;
    }
    if (*(f32 *)(obj + 0x24) < -50.0f) {
        *(f32 *)(obj + 0x24) = -50.0f;
    }
    if (*(f32 *)(obj + 0x24) > 50.0f) {
        *(f32 *)(obj + 0x24) = 50.0f;
    }
    if (*(f32 *)(st + 0x4) < -50.0f) {
        *(f32 *)(st + 0x4) = -50.0f;
    }
    if (*(f32 *)(st + 0x4) > 50.0f) {
        *(f32 *)(st + 0x4) = 50.0f;
    }
    if (*(f32 *)(st + 0x8) < -50.0f) {
        *(f32 *)(st + 0x8) = -50.0f;
    }
    if (*(f32 *)(st + 0x8) > 50.0f) {
        *(f32 *)(st + 0x8) = 50.0f;
    }
    controlFSUvels(obj, st);

    /* ---- attitude vector from stick/obj angles ---- */
    rot[0] = -*(s16 *)(st + 0x11C);
    rot[1] = -*(s16 *)(obj + 0x2);
    rot[2] = -*(s16 *)(obj + 0x4);
    vec[0] = 0.0f;
    vec[1] = -1.0f;
    vec[2] = 0.0f;
    ((void (*)(s16 *, f32 *))mathOneFloatYPR)(rot, vec); /* sig mismatch: asm passes (s16 *, f32 *) only */
    *(f32 *)(st + 0x54) = vec[0];
    *(f32 *)(st + 0x58) = vec[1];
    *(f32 *)(st + 0x50) = vec[2];

    /* ---- stick magnitude and heading ---- */
    stickMag = sqrtf((f32)(controlXjoy * controlXjoy + controlYjoy * controlYjoy));
    if (stickMag > 65.0f) {
        stickMag = 65.0f;
    }
    stickMag = stickMag * D_overlay_16_010080E4;
    if (stickMag != 0.0f) {
        stickAng = (s16)(Arctanf((f32)controlXjoy, (f32)(-controlYjoy)) - *controlcam);
    } else {
        stickAng = *(s16 *)(st + 0x11C);
    }

    /* ---- ground-attack / trigger input ---- */
    v = *(u8 *)(st + 0x568);
    tbl = *(u8 **)(st + 0x360);
    mask = *(u8 *)(st + 0x532);
    if ((v == 0 || v == 5 || v == 0xB) && !(tbl[5] & mask) && *(u8 *)(st + 0x10D) == 0 && *(u8 *)(st + 0x19F) == 0) {
        *(s8 *)(st + 0x185) = (s8)(*(s8 *)(st + 0x185) + arg1);
        if (*(s8 *)(st + 0x185) >= 0x10) {
            *(f32 *)(st + 0x57C) = *(f32 *)(obj + 0x10);
            func_overlay_16_01004F78_1F22F90(obj, st, 0x18, 0);
            t = *(u8 *)(st + 0x568);
            *(u8 *)(st + 0x568) = 3;
            *(u8 *)(st + 0x58E) = 0;
            *(u8 *)(st + 0x56A) = (u8)t;
        }
    } else if ((v == 2 || v == 1) && !(tbl[5] & mask) && !(tbl[6] & mask) && !(tbl[7] & mask)) {
        *(s8 *)(st + 0x185) = (s8)(*(s8 *)(st + 0x185) + arg1);
        if (*(s8 *)(st + 0x185) >= 0x10) {
            *(f32 *)(st + 0x57C) = *(f32 *)(obj + 0x10);
            func_overlay_16_01004F78_1F22F90(obj, st, 0x18, 0);
            t = *(u8 *)(st + 0x568);
            *(u8 *)(st + 0x568) = 3;
            *(u8 *)(st + 0x58E) = 0;
            *(u8 *)(st + 0x56A) = (u8)t;
        }
    } else {
        *(s8 *)(st + 0x185) = 0;
    }
    tbl = *(u8 **)(st + 0x360);
    mask = *(u8 *)(st + 0x532);
    if (((tbl[5] & mask) && *(u8 *)(st + 0x568) != 3) || *(u8 *)(st + 0x568) == 4) {
        *(f32 *)(st + 0x57C) = *(f32 *)(obj + 0x10);
    }

    /* ---- aim / weapon aim parameters from weapon table (stride 0x30) ---- */
    w = weaponTable + *(u8 *)(chr + 0x70) * 0x30;
    v = *(u8 *)(st + 0x568);
    if (v != 5 && v != 0xB && v != 0xA) {
        controlUpdatePlayerAim(obj, st, *(s32 *)(w + 0xC), *(s32 *)(w + 0x14), *(f32 *)(w + 0x18), *(f32 *)(w + 0x1C), *(f32 *)(w + 0x20), arg1);
    } else {
        if (*(s8 *)(st + 0x1F4) != 0) {
            *(s8 *)(st + 0x1F8) = (s8)(*(s8 *)(st + 0x1F8) - arg1);
            if (*(s8 *)(st + 0x1F8) < 0) {
                *(s8 *)(st + 0x1F8) = 0;
            }
        }
        *(s8 *)(st + 0x1F4) = 1;
    }
    if (*(u8 *)(st + 0x568) != 0xA) {
        controlFadePlayer(st, 0, arg1);
    }

    /* ---- ground / platform tracking ---- */
    landedFlag = 0;
    tp = trackPolyHeight(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x14), st + 0x5C, 0x8000A000);
    if (tp < 0 && *(f32 *)(obj + 0x10) < *(f32 *)(st + 0x5C)) {
        *(u8 *)(st + 0x5EE) = 1;
    }
    if ((tp & 0x2000) && *(f32 *)(obj + 0x10) < *(f32 *)(st + 0x5C)) {
        *(u8 *)(st + 0x2) = 1;
        *(u8 *)(st + 0x18D) = 0;
        *(f32 *)(st + 0x60) = *(f32 *)(st + 0x5C) - *(f32 *)(obj + 0x10);
        if (*(u8 *)(st + 0x3) != 1) {
            if (*(f32 *)(st + 0x74) < 0.0f) {
                func_overlay_16_01001B48_1F1FB60(obj, st, arg1);
            }
        }
        if (48.5f < *(f32 *)(st + 0x60)) {
            landedFlag = 1;
        }
    } else if ((tp & 0x8000) && *(f32 *)(obj + 0x10) < *(f32 *)(st + 0x5C) && *(f32 *)(st + 0x5C) < *(f32 *)(obj + 0x10) + 50.0f) {
        *(u8 *)(st + 0x2) = 0;
        t = *(u8 *)(st + 0x18D) + arg1;
        *(u8 *)(st + 0x18D) = (u8)t;
        if ((t & 0xFF) >= 0x81) {
            *(u8 *)(st + 0x18D) = 0x80;
        }
        *(f32 *)(st + 0x60) = *(f32 *)(st + 0x5C) - *(f32 *)(obj + 0x10);
    } else {
        *(u8 *)(st + 0x2) = 0;
        *(f32 *)(st + 0x60) = 0.0f;
        v6 = *(u8 *)(st + 0x18D);
        if (arg1 < (s32)v6) {
            *(u8 *)(st + 0x18D) = (u8)(v6 - arg1);
        } else {
            *(u8 *)(st + 0x18D) = 0;
        }
    }

    /* ---- landing / fall state ---- */
    v = *(u8 *)(st + 0x568);
    if (((s32)v < 4 || v == 0xB || v == 5) && landedFlag != 0) {
        *(u8 *)(st + 0x568) = 4;
        *(s16 *)(st + 0x12A) = 0;
        *(s16 *)(st + 0x12C) = 0;
        *(u8 *)(st + 0x540) = (u8)(*(u8 *)(st + 0x540) & 0x7F);
        *(u8 *)(st + 0x53D) = 0;
        *(u8 *)(st + 0x538) = 0;
        *(s16 *)(st + 0x128) = *(s16 *)(st + 0x11C);
        f0 = *(f32 *)(st + 0x4);
        if (!(f0 < D_overlay_16_01007E2C)) {
            if (!(D_overlay_16_01007E30 < f0)) {
                if (D_overlay_16_01007E30 < *(f32 *)(obj + 0x20)) {
                    func_overlay_16_01004F78_1F22F90(obj, st, 0x25, 0);
                } else {
                    func_overlay_16_01004F78_1F22F90(obj, st, 0x26, 0);
                }
            } else {
                func_overlay_16_01004F78_1F22F90(obj, st, 0x25, 0);
            }
        } else {
            func_overlay_16_01004F78_1F22F90(obj, st, 0x25, 0);
        }
    }

    /* ---- out-of-bounds / death check ---- */
    cobj = *(u8 **)(obj + 0x4C);
    v = *(u8 *)(st + 0x568);
    if (*(s16 *)(cobj + 0x6) < 0x100 && v != 0xA) {
        if (invulnerabilityCheat != 0) {
            *(s16 *)(cobj + 0x6) = 0x2200;
        } else {
            *(s16 *)(cobj + 0x6) = 0;
            if (multiPlayerGame == 0) {
                amTunePlay(0x38);
            } else {
                objEnsureNotTargetted(obj);
            }
            *(u8 *)(st + 0x568) = 0xA;
            controlKeys = 0;
            controlDkeys = 0;
            *(u8 *)(st + 0x53D) = 0;
            ((void (*)(void *))controlEmptyPlayersHand)(obj); /* sig mismatch: asm passes only a0 */
            controlClearAimlocks(st);
            *(u8 *)(st + 0x194) = 0;
            ((void (*)(void *))controlMakeGravity)(st); /* sig mismatch: asm passes only a0 */
            func_overlay_16_01004F78_1F22F90(obj, st, 0x17, 0);
        }
    }

    /* ---- reset gravity/attack timers for non-airborne states ---- */
    v = *(u8 *)(st + 0x568);
    if (v != 0 && v != 2) {
        *(u8 *)(st + 0x13E) = 0;
        if (v != 1) {
            *(u8 *)(st + 0x576) = 0;
        }
    }

    /* ---- main state machine (jump table in asm, cases 0..12) ---- */
    switch (*(u8 *)(st + 0x568)) {
    case 0:
        func_overlay_16_01002708_1F20720(obj, st, stickMag, stickAng, fArg1);
        break;
    case 1:
        func_overlay_16_01002EB4_1F20ECC(obj, st, stickMag, stickAng, fArg1);
        break;
    case 2:
        func_overlay_16_0100321C_1F21234(obj, st, stickMag, stickAng, fArg1);
        break;
    case 3:
        func_overlay_16_01003464_1F2147C(obj, st, stickMag, stickAng, fArg1);
        break;
    case 5:
        func_overlay_16_01003F30_1F21F48(obj, st, stickMag, stickAng, fArg1);
        break;
    case 6:
        func_overlay_16_01006E24_1F24E3C(obj, st, fArg1);
        break;
    case 8:
        func_overlay_16_010070A4_1F250BC(obj, st, stickMag, stickAng, fArg1);
        break;
    case 7:
        func_overlay_16_01007344_1F2535C(obj, st, *(s32 *)&fArg1);
        break;
    case 4:
        func_overlay_16_0100650C_1F24524(obj, st, stickMag, stickAng, fArg1);
        break;
    case 10:
        stickAngF = (f32)stickAng;
        func_overlay_16_01006AEC_1F24B04(obj, st, *(s32 *)&stickMag, *(s32 *)&stickAngF, fArg1);
        break;
    case 11:
        func_overlay_16_01004440_1F22458(obj, st, stickMag, stickAng, fArg1);
        break;
    case 12:
        func_overlay_16_010073A8_1F253C0(obj, st, *(s32 *)&stickMag, (s32)stickAng, fArg1);
        break;
    }

    /* ---- post state-machine: hits, dodge, anim flags ---- */
    if (*(u8 *)(st + 0x568) != 3 && *(s8 *)(st + 0x14A) != 0) {
        if (*(u8 *)(st + 0x568) != 0xA && *(u8 *)(st + 0x568) != 4) {
            *(f32 *)(st + 0x594) = 0.0f;
        }
        *(s8 *)(st + 0x14A) = 0;
    }
    v = *(u8 *)(st + 0x568);
    if (v == 4) {
        *(u8 *)(st + 0x53C) = 1;
    } else if (v != 3) {
        *(u8 *)(st + 0x53C) = 0;
    }
    if (*(s8 *)(st + 0x1F6) != 0) {
        *(s8 *)(st + 0x1F6) = (s8)(*(s8 *)(st + 0x1F6) - arg1);
        if (*(s8 *)(st + 0x1F6) < 0) {
            *(s8 *)(st + 0x1F6) = 0;
        }
    }

    /* ---- weapon select / cheats ---- */
    if (allweaponsCheat != 0) {
        *(u8 *)(chr + 0x6F) = 0xF;
        *(u16 *)(chr + 0xA) = 0x7FFF;
    }
    if ((*(u16 *)(chr + 0xA) & 0x20) && mainPlayerHas(*(s8 *)st, *(s8 *)(st + 1), 0xA) == 0) {
        mainPlayerCollected(*(s8 *)st, *(s8 *)(st + 1), 0xA);
    }
    *(u8 *)(st + 0x540) = (u8)(*(u8 *)(st + 0x540) & 0xCF);
    if ((s32)*(u8 *)(chr + 0x6F) >= 2) {
        prevWeapon = *(u8 *)(chr + 0x70);
        if (prevWeapon != *(s8 *)(st + 0x585) && disablejoy == 0) {
            controlSelectWeapon(obj, st, *(s8 *)(st + 0x585), 0); /* asm: a3 not set on this path */
        } else if (*(s32 *)((u8 *)controlModeKeys + 4) & controlDkeys) {
            controlSelectNextWeapon(obj, st, *(s8 *)(st + 0x585));
        } else if (*(s32 *)((u8 *)controlModeKeys + 8) & controlDkeys) {
            controlSelectPreviousWeapon(obj, st, *(s8 *)(st + 0x585));
        } else {
            game = (u8 *)mainGetGame();
            for (i = 0; i != 4; i++) {
                if (quickWeaponKey[i] & controlDkeys) {
                    if (controlSelectWeapon(obj, st, (s8)*(u8 *)(game + 0x534 + i), i) != 0) {
                        break;
                    }
                }
            }
        }
        if (prevWeapon != *(u8 *)(chr + 0x70)) {
            *(u8 *)(st + 0x538) = 0;
            *(u8 *)(st + 0x53D) = 0;
            *(s8 *)(st + 0x585) = (s8)*(u8 *)(chr + 0x70);
        }
    }

    /* ---- per-frame controls and collision helpers ---- */
    func_overlay_16_01005120_1F23138(obj, st, stickMag, fArg1);
    func_overlay_16_01005BB8_1F23BD0(obj, st, fArg1);
    controlSquashCheckPost(obj, st, arg1);
    if (*(s8 *)(st + 0x189) < 4) {
        v = *(u8 *)(st + 0x568);
        if (v == 0 || v == 5 || v == 0xB) {
            controlHangOK(obj, st, stickMag, (f32)stickAng, fArg1, D_overlay_16_01007A44);
        } else if (v == 3) {
            controlGrabOK(obj, st, stickMag, stickAng, fArg1, D_overlay_16_01007A44);
        }
    }
    v = *(u8 *)(st + 0x568);
    if (v != 5 && v != 0xB && v != 3 && v != 8) {
        func_overlay_16_01006290_1F242A8(obj, st, arg1);
    }

    /* ---- shield effect ---- */
    shield = *(u8 **)(st + 0x5BC);
    if (shield != NULL) {
        v = *(u8 *)(st + 0x568);
        switch (v) {
        case 2:
            invincibilityShieldTransform(shield, 0x3FC00000, 0x3F000000, 0x28);
            break;
        case 4:
            invincibilityShieldTransform(shield, 0x3FC00000, 0x3F000000, 0x78);
            break;
        case 1:
            invincibilityShieldTransform(shield, 0x3F800000, 0x3F400000, 0x78);
            break;
        default:
            invincibilityShieldTransform(shield, 0x3F800000, 0x3F800000, 0x78);
            break;
        }
    }
    func_overlay_16_01002220_1F20238(obj, st, arg1);

    /* ---- display list: 6 halfwords when flag 0x40 set in st+0x540 (word read) ---- */
    if (*(s32 *)(st + 0x540) & 0x40) {
        *D_overlay_16_010080D8 = 0x4024;
        D_overlay_16_010080D8 += 1;
        *D_overlay_16_010080D8 = 0x20;
        D_overlay_16_010080D8 += 1;
        *D_overlay_16_010080D8 = 0x4026;
        D_overlay_16_010080D8 += 1;
        *D_overlay_16_010080D8 = 0x20;
        D_overlay_16_010080D8 += 1;
        *D_overlay_16_010080D8 = 0x4028;
        D_overlay_16_010080D8 += 1;
        *D_overlay_16_010080D8 = 0x20;
        D_overlay_16_010080D8 += 1;
    }
    func_overlay_16_01004840_1F22858((s32)obj, st, arg1);

    /* ---- deformed-characters display list (6 iterations, arrays read backwards) ---- */
    if (deformedchars != 0 && *(s8 *)(st + 0x189) != 2) {
        dlInt[0] = D_overlay_16_01007D4C[0];
        dlInt[1] = D_overlay_16_01007D4C[1];
        dlInt[5] = D_overlay_16_01007D4C[5];
        dlInt[4] = D_overlay_16_01007D4C[4];
        dlInt[2] = D_overlay_16_01007D4C[2];
        dlInt[3] = D_overlay_16_01007D4C[3];
        dlFlt[0] = D_overlay_16_01007D64[0];
        dlFlt[2] = D_overlay_16_01007D64[2];
        dlFlt[1] = D_overlay_16_01007D64[1];
        dlFlt[3] = D_overlay_16_01007D64[3];
        dlFlt[4] = D_overlay_16_01007D64[4];
        dlFlt[5] = D_overlay_16_01007D64[5];
        for (k = 5; k >= 0; k--) {
            iv = dlInt[k] * 6;
            fl = (s32)(*(f32 *)&dlFlt[k] * 32768.0f);
            *D_overlay_16_010080D8 = (s16)(iv | 0x4000);
            D_overlay_16_010080D8 += 1;
            *D_overlay_16_010080D8 = (s16)fl;
            D_overlay_16_010080D8 += 1;
            *D_overlay_16_010080D8 = (s16)((iv + 2) | 0x4000);
            D_overlay_16_010080D8 += 1;
            *D_overlay_16_010080D8 = (s16)fl;
            D_overlay_16_010080D8 += 1;
            *D_overlay_16_010080D8 = (s16)((iv + 4) | 0x4000);
            D_overlay_16_010080D8 += 1;
            *D_overlay_16_010080D8 = (s16)fl;
            D_overlay_16_010080D8 += 1;
        }
    }
    *D_overlay_16_010080D8 = 0x1000;
    D_overlay_16_010080D8 += 1;

    /* ---- sound / flags from stick and position ---- */
    if (*(s8 *)(st + 0x576) != 0 || (*(u8 *)(st + 0x188) != 0 && (*(u8 *)(st + 0x532) & *(*(u8 **)(st + 0x360) + 5)) && (*(f32 *)(obj + 0x1C) < -1.0f || *(f32 *)(obj + 0x1C) > 1.0f || *(f32 *)(obj + 0x24) < -1.0f || *(f32 *)(obj + 0x24) > 1.0f))) {
        *(s32 *)(obj + 0x84) |= D_overlay_16_01007A60[*(u8 *)((u8 *)levelGetLevel() + 0xE2)];
        if (*(s32 *)(st + 0xC8) == 0) {
            ((void (*)(s32, void *))amSndPlay)(0x1C, st + 0xC8); /* sig mismatch: asm passes 2 args */
        }
    } else {
        *(s32 *)(obj + 0x84) &= ~6;
        if (*(s32 *)(st + 0xC8) != 0) {
            amSndStop(*(s32 *)(st + 0xC8));
        }
    }
    v = *(u8 *)(st + 0x568);
    if (v == 0xA || *(u8 *)(st + 0x10D) != 0 || *(u8 *)(st + 0x19F) != 0) {
        *(u8 *)(obj + 0x9F) = 3;
    } else {
        *(u8 *)(obj + 0x9F) = 0;
    }

    /* ---- gun / anim matrices for current object model ---- */
    inst = *(u8 **)(*(u8 **)(obj + 0x6C) + *(s8 *)(obj + 0x3A) * 4);
    if (inst != NULL) {
        if (*(s8 *)(inst + 0xA) != 0) {
            model = *(u8 **)inst;
            modGenAnimMatrices(inst, model, obj, *(f32 *)(st + 0x48), 0.0f);
            t = objMakeGunMtx(obj, inst, model, *(u8 *)(chr + 0x70), st + 0x78, st + 0x544, st + 0x548, st + 0x54C);
            *(u8 *)(st + 0x540) = (u8)(((t << 2) & 4) | (*(u8 *)(st + 0x540) & 0xFB));
            lightObject(obj, inst, *(s32 *)(obj + 0x54), *(s32 *)(inst + 0x10 + *(s8 *)(inst + 0xB) * 4));
            if ((s32)*(u8 *)(model + 0x11) > 0) {
                objAnimTextures(obj, model, inst, *(s8 *)(inst + 0xA));
            }
            *(u8 *)(inst + 0xA) = 0;
            f0 = (*(f32 *)(*(u8 **)(inst + 0x70) + 0x70) + 4.0f) - *(f32 *)(obj + 0x10);
            if (64.0f <= f0) {
                f0 = D_overlay_16_01007E68;
            }
            *(s8 *)(*(u8 **)(obj + 0x50) + 0xE) = (s8)(s32)(f0 * 4.0f);
        }
    }

    /* ---- weapon update / throw ---- */
    wret = controlUpdateWeapon(obj, st, fArg1);
    switch (controlThrowWeapon(wret)) {
    case 1:
        if (*(s8 *)(obj + 0x3B) == 0x15) {
            objAnimSetMove(obj, 0x15, 0, 0); /* asm: a3 not set on this path */
        } else {
            func_overlay_16_01004F78_1F22F90(obj, st, 0x15, 0);
        }
        *(u8 *)(st + 0x577) = 0x28;
        break;
    case 2:
        if (*(s8 *)(obj + 0x3B) == 0x2E) {
            objAnimSetMove(obj, 0x2E, 0, 0); /* asm: a3 not set on this path */
        } else {
            func_overlay_16_01004F78_1F22F90(obj, st, 0x2E, 0);
        }
        *(u8 *)(st + 0x577) = 0x28;
        break;
    }
    if (D_overlay_16_010080DE != 0) {
        controlFireDummyShot(obj, st);
    }
    controlUpdateJetFlames(obj, st, 0x100, 0x80, arg1);

    /* ---- objRef58 (camera/effects record) ---- */
    objRef58 = *(u8 **)(obj + 0x58);
    *(f32 *)(objRef58 + 0x80) = *(f32 *)(st + 0x5C);
    *(u8 *)(objRef58 + 0x75) = 0;
    flags = *(u8 **)(objRef58 + 0x84);
    if (flags != NULL) {
        *flags = (u8)(*flags & 0xFD);
    }
    if (*(u8 *)(st + 0x2) == 1) {
        if (*(f32 *)(st + 0x60) < 50.0f) {
            *(f32 *)(objRef58 + 0x80) = *(f32 *)(st + 0x5C);
            *(u8 *)(objRef58 + 0x75) = 1;
            if (flags != NULL) {
                if (*(f32 *)(st + 0x4) < -1.0f || *(f32 *)(st + 0x4) > 1.0f || *(f32 *)(st + 0x10) < -1.0f || *(f32 *)(st + 0x10) > 1.0f) {
                    *flags = (u8)(*flags | 2);
                }
            }
        }
    }
    wakeUpdateRipple(obj, arg1);
    partUpdateTriggers(obj, arg1);

    /* ---- continuous sound on st+0xCC ---- */
    if (*(s8 *)(st + 0x14A) != 0) {
        if (*(s32 *)(st + 0xCC) == 0) {
            ((void (*)(s32, void *))amSndPlay)(0x9C, st + 0xCC); /* sig mismatch: asm passes 2 args */
        }
    } else {
        if (*(s32 *)(st + 0xCC) != 0) {
            amSndStop(*(s32 *)(st + 0xCC));
        }
    }

    /* ---- rumble ---- */
    q = (s32)*(s16 *)(st + 0x536) / arg1;
    controlSetRumble(*(s8 *)st, D_overlay_16_010080D0, D_overlay_16_010080D4, wret, q);
    *(s16 *)(st + 0x536) = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o16/overlay_16/boyControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 boyCanFire(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    s32 kind;
    s32 state;
    u8 *p;

    if (*(s8 *)(st + 0x576) != 0) {
        goto ret0;
    }
    if (*(u8 *)(st + 0x13E) != 0) {
        goto ret0;
    }
    kind = *(s8 *)(obj + 0x3B);
    if (kind == 8) {
        goto ret0;
    }
    state = *(u8 *)(st + 0x568) & ~0x20;
    if (state == 0 || state == 5 || state == 0xB || state == 0xA) {
        goto ret1;
    }
    if (state == 3 && *(s8 *)(st + 0x14A) != 0) {
ret1:
        return 1;
    }
    p = *(u8 **)(*(u8 **)(obj + 0x6C));
    if (kind == 0x15 || kind == 0x2E) {
        if (*(s8 *)(st + 0x53D) != 0) {
            return 1;
        }
    }
    if (kind == 0xE || kind == 0x21) {
        if (*(s16 *)(p + 0x5E) == 0) {
            return 1;
        }
    }
ret0:
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o16/overlay_16/boyCanFire.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_16_01001B48_1F1FB60(void *arg0, void *arg1, s32 arg2) {
    u8 *ob = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    s32 vol;
    s16 setup[6];
    f32 sp38;
    s32 sp40;
    s16 sp24;
    s16 sp26;
    f32 var_f0;
    void *temp_v0;

    vol = (s32)(-*(f32 *)(st + 0x74) * 15.0f);
    if (vol >= 0x80) {
        vol = 0x7F;
    }
    amSndPlay(0xD, st + 0xD4, arg2, arg0);
    amSndSetVol(0xD, *(s32 *)(st + 0xD4), vol & 0xFF);
    if (*(f32 *)(st + 0x74) < -5.0f) {
        setup[0] = 0xC0;
        ((u8 *)setup)[2] = 0x10;
        setup[2] = (s16)(s32)*(f32 *)(ob + 0xC);
        setup[3] = (s16)(s32)*(f32 *)(st + 0x5C);
        setup[5] = 0x100;
        setup[4] = (s16)(s32)*(f32 *)(ob + 0x14);
        var_f0 = -(*(f32 *)(st + 0x74) + 5.0f);
        if (var_f0 > 10.0f) {
            var_f0 = 10.0f;
        }
        sp38 = var_f0;
        temp_v0 = objSetupObject(setup, 1);
        if (temp_v0 != NULL) {
            *(s32 *)((u8 *)temp_v0 + 0x3C) = 0;
        }
    } else {
        sp40 = *(s32 *)(ob + 0x84);
        sp26 = *(s16 *)(ob + 0x2);
        sp24 = *(s16 *)(ob + 0x4);
        *(s16 *)(ob + 0x2) = 0;
        *(s16 *)(ob + 0x4) = 0;
        *(f32 *)(ob + 0x10) = *(f32 *)(ob + 0x10) + *(f32 *)(st + 0x60);
        *(s32 *)(ob + 0x84) = 0x40;
        partUpdateTriggers(arg0, arg2);
        *(s16 *)(ob + 0x4) = sp24;
        *(s16 *)(ob + 0x2) = sp26;
        *(f32 *)(ob + 0x10) = *(f32 *)(ob + 0x10) - *(f32 *)(st + 0x60);
        *(s32 *)(ob + 0x84) = sp40;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o16/overlay_16/func_overlay_16_01001B48_1F1FB60.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_16_01001D58_1F1FD70(void *arg0, void *arg1, f32 arg2, f32 arg3) {
    u8 *ob = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    f32 xs[2];
    f32 ys[2];
    s32 cnt[2];
    s16 rot[2];
    f32 vec[2];
    f32 spZ;
    f32 var_f2;
    f32 var_f14;
    f32 bx;
    f32 by;
    f32 sinA;
    f32 cosA;
    f32 spd;
    f32 u60;
    s32 n;
    s32 k;
    s32 j;
    s32 c;

    if (*(f32 *)(st + 0x60) == 0.0f) {
        return;
    }
    n = 0;
    if (arg3 < 0.0f) {
        var_f2 = *(f32 *)(ob + 0x28);
        var_f14 = arg2;
        if (arg2 < var_f2) {
            var_f2 -= 1.0f;
        }
    } else {
        var_f14 = *(f32 *)(ob + 0x28);
        var_f2 = arg2;
        if (var_f14 < arg2) {
            var_f14 += 1.0f;
        }
    }
    if (*(u8 *)(st + 0x568) == 0 && *(f32 *)(st + 0x60) > 0.0f && *(f32 *)(st + 0x4) < -1.0f) {
        if (var_f2 < D_overlay_16_01007E6C && D_overlay_16_01007E6C <= var_f14) {
            xs[0] = 4.0f;
            ys[0] = 16.0f;
            n = 1;
            cnt[0] = 2 - (s32)(*(f32 *)(st + 0x4) + 1.0f);
        }
        if (var_f2 < D_overlay_16_01007E70 && D_overlay_16_01007E70 <= var_f14) {
            xs[n] = -4.0f;
            ys[n] = 16.0f;
            cnt[n] = 2 - (s32)(*(f32 *)(st + 0x4) + 1.0f);
            n += 1;
        }
    }
    if (*(u8 *)(st + 0x568) == 4) {
        u60 = *(f32 *)(st + 0x60);
        if (u60 >= 45.0f && u60 <= 48.5f && *(f32 *)(st + 0x4) < -1.0f && var_f2 < 0.875f && var_f14 >= 0.875f) {
            ys[0] = -12.0f;
            xs[0] = -6.0f;
            ys[1] = -12.0f;
            xs[1] = 6.0f;
            n = 2;
            c = 2 - (s32)(*(f32 *)(st + 0x4) + 1.0f);
            cnt[0] = c;
            cnt[1] = c;
        }
    }
    for (k = n - 1; k >= 0; k--) {
        sinA = Sinf(*(s16 *)ob);
        cosA = Cosf((s32)*(s16 *)ob);
        bx = (ys[k] * sinA) + (xs[k] * cosA) + *(f32 *)(ob + 0xC);
        by = ((ys[k] * cosA) - (xs[k] * sinA)) + *(f32 *)(ob + 0x14);
        for (j = 0; j < cnt[k]; j++) {
            spd = (f32)mathRnd(0x32, 0x64) * D_overlay_16_01007E78;
            rot[0] = (s16)(mathRnd(-0x2555, 0x2555) + *(s16 *)ob);
            rot[1] = (s16)mathRnd(0x2400, 0x3C00);
            spZ = ((f32)mathRnd(0xC, 0x16) * D_overlay_16_01007E74) + (*(f32 *)(st + 0x4) * 0.25f);
            mathOneFloatPY(rot, vec);
            dropletAdd(spd, bx, *(f32 *)(st + 0x5C), by, *(f32 *)(st + 0x5C), vec[0], vec[1], spZ);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o16/overlay_16/func_overlay_16_01001D58_1F1FD70.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_16_01002220_1F20238(u8 *arg0, u8 *arg1, s32 arg2) {
    u8 *cfg;
    u8 *ent;
    s32 shiftA;   /* asm: sp28 (stored after the loop, read below) */
    s32 shiftB;   /* asm: sp20 (stored after the loop, read below) */
    s32 i;
    s32 count;
    s32 flag3;    /* var_t3: an object with flag 0x40 was seen */
    s32 t0;       /* 0xF when case A ran: unk342 / unk343 */
    s32 t2;       /* 0xF when case B/C ran: unk340 / unk341 */
    s32 at;
    s32 v1;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_t0;
    s32 temp_a0;
    s32 temp_t8;
    s32 temp_v0_4;
    s32 temp_v0_5;
    s8 temp_a3;
    s8 temp_a3_3;

    cfg = *(u8 **)(arg0 + 0x4C);
    count = *(s16 *)(cfg + 0x32);
    ent = *(u8 **)(cfg + 0x40);
    flag3 = 0;
    t0 = 0;
    t2 = 0;
    /* asm: sp28/sp20 are read from the stack before they are first stored
     * (only when the loop body never ran); they are only consumed on the
     * paths where t0/t2 were set, so zero-init is equivalent. */
    shiftA = 0;
    shiftB = 0;

    for (i = 0; i < count; i++) {
        if ((*(u16 *)(ent + 0xA) & 0x40) != 0) {
            flag3 = 1;
            switch (i) {
            case 0:
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
            case 6:
            case 7:
                /* asm: cases 0-3 and 4-7 jump to identical code */
                D_overlay_16_010080D0 |= 1;
                D_overlay_16_010080D4 |= 1;
                t0 = 0xF;
                count = *(s16 *)(*(u8 **)(arg0 + 0x4C) + 0x32);
                shiftA = 5;
                break;
            case 8:
                D_overlay_16_010080D0 |= 2;
                D_overlay_16_010080D4 |= 1;
                t2 = 0xF;
                count = *(s16 *)(*(u8 **)(arg0 + 0x4C) + 0x32);
                shiftB = 4;
                break;
            default:
                D_overlay_16_010080D0 |= 4;
                D_overlay_16_010080D4 |= 1;
                t2 = 0xF;
                count = *(s16 *)(*(u8 **)(arg0 + 0x4C) + 0x32);
                shiftB = 3;
                break;
            }
        }
        ent += 0x34;
    }

    if (flag3 != 0) {
        if (t0 != 0 && *(s8 *)(arg1 + 0x342) == 0) {
            arg1[0x342] = (u8)t0;
            arg1[0x343] = (u8)shiftA;
        }
        if (t2 != 0 && *(s8 *)(arg1 + 0x340) == 0) {
            arg1[0x340] = (u8)t2;
            arg1[0x341] = (u8)shiftB;
        }
    }

    /* unk342 countdown: emit 4 display-list-style s16 words */
    temp_a3 = *(s8 *)(arg1 + 0x342);
    if (temp_a3 != 0) {
        /* sig mismatch: asm passes &D0 in $a1 as the second argument */
        temp_v0 = ((s32 (*)(s16, s32))mathSin)((s16)(temp_a3 << 0xB), (s32)&D_overlay_16_010080D0);
        D_overlay_16_010080D8[0] = 8;
        temp_t0 = temp_v0 >> arg1[0x343];
        D_overlay_16_010080D8[1] = (s16)temp_t0;
        D_overlay_16_010080D8[2] = 0x14;
        D_overlay_16_010080D8[3] = (s16)-temp_t0;
        D_overlay_16_010080D8 += 4;
        if (arg2 < temp_a3) {
            arg1[0x342] = (u8)(temp_a3 - arg2);
        } else {
            arg1[0x342] = 0;
        }
    }

    /* unk340 countdown */
    temp_a3_3 = *(s8 *)(arg1 + 0x340);
    if (temp_a3_3 != 0) {
        temp_v0_2 = ((s32 (*)(s16, s32))mathSin)((s16)(temp_a3_3 << 0xB), (s32)&D_overlay_16_010080D0);
        D_overlay_16_010080D8[0] = 6;
        temp_a0 = (temp_v0_2 >> arg1[0x341]) >> 1;
        D_overlay_16_010080D8[1] = (s16)temp_a0;
        D_overlay_16_010080D8[2] = 0x3C;
        D_overlay_16_010080D8[3] = (s16)temp_a0;
        D_overlay_16_010080D8 += 4;
        if (arg2 < temp_a3_3) {
            arg1[0x340] = (u8)(temp_a3_3 - arg2);
        } else {
            arg1[0x340] = 0;
        }
    }

    v1 = *(s16 *)(*(u8 **)(arg0 + 0x4C) + 0x6);
    if (v1 >= 0x100) {
        if (arg1[0x190] == 0x80) {
            if (*(s16 *)(arg1 + 0x5C8) == 0) {
                arg1[0x190] = 0x3C;
                cfg = *(u8 **)(arg0 + 0x4C);
                flag3 = 1;
                *(s16 *)(cfg + 0x6) = (s16)(*(s16 *)(cfg + 0x6) - 0x100);
                D_overlay_16_010080D0 |= 2;
                D_overlay_16_010080D4 |= 2;
                v1 = *(s16 *)(*(u8 **)(arg0 + 0x4C) + 0x6);
            }
        } else if (arg1[0x190] == 0xC0) {
            if (*(s16 *)(arg1 + 0x5C8) == 0) {
                arg1[0x190] = 0x3C;
                cfg = *(u8 **)(arg0 + 0x4C);
                flag3 = 1;
                *(s16 *)(cfg + 0x6) = (s16)(*(s16 *)(cfg + 0x6) - 0x200);
                D_overlay_16_010080D0 |= 4;
                D_overlay_16_010080D4 |= 2;
                v1 = *(s16 *)(*(u8 **)(arg0 + 0x4C) + 0x6);
            }
        }
        at = (v1 < 0x100);
        if (at != 0) {
            *(s16 *)(*(u8 **)(arg0 + 0x4C) + 0x6) = 0;
            if (multiPlayerGame != 0) {
                /* asm: 4th arg ($a3) is the unk340 byte as read before the decrement */
                hitPlayerKilledPlayer(arg0, arg0, &D_overlay_16_010080D4, temp_a3_3);
            }
        }
    }

    temp_t8 = arg1[0x190] & 0x3F;
    arg1[0x190] = (u8)temp_t8;
    temp_v0_4 = temp_t8 & 0xFF;
    if (arg2 < temp_v0_4) {
        arg1[0x190] = (u8)(temp_v0_4 - arg2);
    } else {
        arg1[0x190] = 0;
    }

    if (flag3 != 0 && arg1[0x568] != 0xA) {
        charSpeak(arg0, 3);
        arg1[0x148] = 8;
    } else {
        temp_v0_5 = *(s8 *)(arg1 + 0x148);
        if (arg2 < temp_v0_5) {
            arg1[0x148] = (u8)(temp_v0_5 - arg2);
        } else {
            arg1[0x148] = 0;
        }
    }

    if (*(s8 *)(arg1 + 0x148) != 0) {
        fxNightVisionSkip();
        frontFlashScreen(0, *(s8 *)arg1, 0xFF0000FF);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o16/overlay_16/func_overlay_16_01002220_1F20238.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// cf. Vela func_overlay_15_00F02B2C_1F164AC (same control flow, different offsets/constants)
void func_overlay_16_01002708_1F20720(u8 *arg0, u8 *arg1, f32 arg2, s16 arg3, f32 arg4) {
    s32 sp54;      /* controlHalfTurn "turned" out flag */
    s32 sp40;      /* asm: (s32)arg4, passed to Powerf */
    s16 sp4E;      /* asm: unk11C delta scratch */
    f32 sp50;      /* asm: unk4 before this frame's update */
    f32 absV;      /* asm: $f14 scratch (|unk4| and friends) */
    f32 blend;     /* asm: var_f14_5 */
    f32 unk14;     /* asm: copy of unk14 */
    u8 *obj510;
    s8 obj3B;
    s16 temp_t6;

    /* unk576 countdown by (s32)arg4, floored at 0 when it goes negative */
    if (*(s8 *)(arg1 + 0x576) != 0) {
        *(s8 *)(arg1 + 0x576) = (s8)(*(s8 *)(arg1 + 0x576) - (s32)arg4);
        if (*(s8 *)(arg1 + 0x576) < 0) {
            *(s8 *)(arg1 + 0x576) = 0;
        }
    }
    if (*(s8 *)(arg0 + 0x3B) == 0x19 && *(s8 *)(arg1 + 0x56B) == 0) {
        func_overlay_16_01004F78_1F22F90(arg0, arg1, func_overlay_16_01004E08_1F22E20(arg1), 0);
    }

    if (controlKeys & 0x10) {
        temp_t6 = *(s16 *)(arg1 + 0x10A);
        *(s16 *)(arg1 + 0x10A) = 0;
        *(s16 *)(arg1 + 0x11C) = (s16)(*(s16 *)(arg1 + 0x11C) - temp_t6);
        arg3 = *(s16 *)(arg1 + 0x11C);
        if (lobbycamInuse(arg0, arg1) == 0) {
            staticcamInuse();
        }
        *(s16 *)(arg1 + 0x1E2) = 0;
        *(s16 *)(arg1 + 0x1E0) = 0;
        arg1[0x568] = 0xB;
        *(s16 *)(arg1 + 0x1CE) = 0;
        *(s16 *)(arg1 + 0x1D0) = 0;
        *(f32 *)(arg1 + 0x1E4) = 0.0f;
        *(f32 *)(arg1 + 0x1E8) = 0.0f;
        *(s16 *)(arg1 + 0x1C6) = *(s16 *)arg0;
        *(s16 *)(arg1 + 0x1C8) = *(s16 *)(arg0 + 0x2);
        *(s16 *)(arg1 + 0x1DC) = *(s16 *)(arg1 + 0x1CE);
        *(s16 *)(arg1 + 0x1CA) = *(s16 *)(arg1 + 0x1C6);
        *(s16 *)(arg1 + 0x1CC) = *(s16 *)(arg1 + 0x1C8);
        *(s16 *)(arg1 + 0x1DE) = *(s16 *)(arg1 + 0x1D0);
        return;
    }

    sp40 = (s32)arg4;
    controlWalkingBack(arg0, arg1, &arg2, arg3, 0x5000, 0x6800, 5.0f, 3.0f);
    func_overlay_16_01004934_1F2294C(arg0, arg1, 0, arg4);

    if ((*(s32 *)((u8 *)controlModeKeys + 0xC) & controlDkeys) && arg1[0x534] == 0) {
        absV = *(f32 *)(arg1 + 0x4);
        if (absV < 0.0f) {
            absV = -absV;
        }
        if (arg1[0x569] != 0) {
            arg1[0x57A] = 7;
            arg1[0x57B] = 0;
            func_overlay_16_01004F78_1F22F90(arg0, arg1, 7, 0);
        } else if (((absV > 1.25f) && (arg2 != 0.0f)) || (arg1[0x56C] != 0)) {
            arg1[0x57A] = 0;
            if (multiPlayerGame != 0 && *(s8 *)(arg1 + 0x189) == 7) {
                *(f32 *)(arg0 + 0x20) = *(f32 *)(arg0 + 0x20) + 12.0f;
            } else {
                *(f32 *)(arg0 + 0x20) = *(f32 *)(arg0 + 0x20) + 10.0f;
            }
            obj510 = *(u8 **)(arg1 + 0x510);
            if (obj510 != NULL) {
                *(f32 *)(arg0 + 0x20) = *(f32 *)(arg0 + 0x20) - *(f32 *)(obj510 + 0x20);
            }
            func_overlay_16_01004F78_1F22F90(arg0, arg1, 6, 0);
            charSpeak(arg0, 0);
        } else {
            arg1[0x57A] = 0x18;
            arg1[0x57B] = 0;
            func_overlay_16_01004F78_1F22F90(arg0, arg1, 5, 0);
        }
        arg1[0x568] = 3;
        arg1[0x58E] = 0;
        *(f32 *)(arg1 + 0x57C) = *(f32 *)(arg0 + 0x10);
    } else if ((*(s32 *)((u8 *)controlModeKeys + 0x10) & controlDkeys) && *(s8 *)(arg1 + 0x189) < 4) {
        absV = *(f32 *)(arg1 + 0x4);
        if (absV < 0.0f) {
            absV = -absV;
        }
        if (absV > 2.0f) {
            arg1[0x568] = 1;
            *(s16 *)(arg1 + 0x5CA) = 0;
            func_overlay_16_01004F78_1F22F90(arg0, arg1, 0xF, 0);
            arg1[0x576] = 0x28;
        } else if (arg2 > 0.5f) {
            arg1[0x568] = 2;
            *(s16 *)(arg1 + 0x5CA) = 0;
            func_overlay_16_01004F78_1F22F90(arg0, arg1, 4, 0);
        } else {
            arg1[0x568] = 1;
            *(s16 *)(arg1 + 0x5CA) = 0;
            func_overlay_16_01004F78_1F22F90(arg0, arg1, 0xD, 0);
        }
        arg1[0x56C] = 0;
    }

    if (*(s32 *)((u8 *)controlModeKeys) & controlKeys) {
        arg1[0x1F4] = 0xF;
    }
    if (!((*(u8 **)(arg1 + 0x360))[5] & arg1[0x532])) {
        arg1[0x1F4] = 0;
    }

    if (arg1[0x569] == 0) {
        arg2 = -arg2;
    } else {
        arg3 = (s16)(arg3 + 0x8000);
    }
    controlHalfTurn(arg0, arg1, &arg2, &arg3, 0x6AAA, 0x71C, &sp54, D_overlay_16_010080E4, arg4);
    if (sp54 != 0) {
        func_overlay_16_01004F78_1F22F90(arg0, arg1, 0xF, 0);
    }

    sp4E = *(s16 *)(arg1 + 0x11C);
    if (lobbycamInuse() == 0 && staticcamInuse() == 0) {
        if ((*(u16 *)(arg1 + 0x540) & 0xF) != 0 && frontGetTargetControl(*(s8 *)arg1) == 0) {
            unk14 = *(f32 *)(arg1 + 0x14);
            *(f32 *)(arg1 + 0x14) = unk14 + ((D_overlay_16_01007EA4 - unk14) * (1.0f - Powerf(D_overlay_16_01007EA0, sp40)));
        } else {
            unk14 = *(f32 *)(arg1 + 0x14);
            *(f32 *)(arg1 + 0x14) = unk14 + ((D_overlay_16_01007EAC - unk14) * (1.0f - Powerf(D_overlay_16_01007EA8, sp40)));
        }
    }

    absV = *(f32 *)(arg1 + 0x4);
    if (absV < 0.0f) {
        absV = -absV;
    }
    absV = absV * absV;
    if (absV > 1.0f) {
        absV = 1.0f;
    }
    blend = 1.0f - (((*(f32 *)(arg1 + 0x14) - D_overlay_16_01007EB0) * absV) + D_overlay_16_01007EB0);
    if (arg1[0x13E] != 0) {
        blend = D_overlay_16_01007EB4;
    }
    *(s16 *)(arg1 + 0x11C) = dAngle(*(s16 *)(arg1 + 0x11C), arg3, 1.0f - Powerf(blend, sp40));

    sp50 = *(f32 *)(arg1 + 0x4);
    *(f32 *)(arg1 + 0x4) = ((1.0f - Powerf(D_overlay_16_01007EB8, sp40)) * (arg2 - *(f32 *)(arg1 + 0x4))) + *(f32 *)(arg1 + 0x4);
    sp4E = (s16)(*(s16 *)(arg1 + 0x11C) - sp4E);

    if (arg1[0x568] == 0 && (sp50 - *(f32 *)(arg1 + 0x4)) < D_overlay_16_01007EBC) {
        obj3B = *(s8 *)(arg0 + 0x3B);
        if (obj3B != 0x15 && obj3B != 0x2E && obj3B != 0x19) {
            arg1[0x576] = 4;
            func_overlay_16_01004F78_1F22F90(arg0, arg1, 0xF, 0);
        }
    }

    absV = *(f32 *)(arg1 + 0x4);
    if (absV < 0.0f) {
        absV = -absV;
    }
    if (absV > 3.0f) {
        absV = 3.0f;
    }
    *(s16 *)(arg1 + 0x120) = (s16)((s32)((f32)sp4E * absV * D_overlay_16_01007EC0));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o16/overlay_16/func_overlay_16_01002708_1F20720.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_16_01002EB4_1F20ECC(void *arg0, void *arg1, f32 arg2, s16 arg3, f32 arg4) {
    u8 *ob = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    s32 var_v0;
    s32 temp_f4;
    s8 temp_v0;

    var_v0 = 0;
    if (*(f32 *)(st + 0x60) > 30.0f) {
        *(s16 *)(st + 0x5CA) = (s16)(*(s16 *)(st + 0x5CA) + (s32)arg4);
        if (*(s16 *)(st + 0x5CA) >= 0x79) {
            var_v0 = 1;
        }
    } else {
        *(s16 *)(st + 0x5CA) = 0;
    }
    if ((var_v0 != 0 || (*(s32 *)((u8 *)controlModeKeys + 0xC) & controlKeys)) && *(u8 *)(st + 0x56C) == 0 &&
        controlCeiling(*(f32 *)(ob + 0xC), *(f32 *)(ob + 0x10), *(s32 *)(ob + 0x14), 60.0f, 15.0f) != 0) {
        func_overlay_16_01004F78_1F22F90(arg0, arg1, func_overlay_16_01004E08_1F22E20(arg1), 0);
        *(u8 *)(st + 0x568) = 0;
        *(s8 *)(st + 0x576) = 0;
    } else {
        temp_v0 = *(s8 *)(st + 0x576);
        if (temp_v0 != 0) {
            temp_f4 = (s32)arg4;
            *(s8 *)(st + 0x576) = (s8)(temp_v0 - temp_f4);
            *(f32 *)(st + 0x10) = *(f32 *)(st + 0x10) * Powerf(D_overlay_16_01007EC4, temp_f4);
            if (*(s8 *)(st + 0x576) <= 0) {
                *(s8 *)(st + 0x576) = 0;
                *(f32 *)(st + 0x4) = 0.0f;
                *(f32 *)(st + 0x10) = 0.0f;
                if (arg2 > 0.5f && !(controlKeys & 0x10)) {
                    *(u8 *)(st + 0x568) = 2;
                    func_overlay_16_01004F78_1F22F90(arg0, arg1, 0x16, 0);
                } else {
                    func_overlay_16_01004F78_1F22F90(arg0, arg1, 0xE, 0);
                }
            }
        }
    }
    if (*(u8 *)(st + 0x568) == 1 && *(s8 *)(st + 0x576) == 0) {
        if ((controlKeys & 0x10) && boyCanFire(arg0, arg1) != 0) {
            *(u8 *)(st + 0x568) = 5;
            *(s16 *)(st + 0x11C) = (s16)(*(s16 *)(st + 0x11C) - *(s16 *)(st + 0x10A));
            *(s16 *)(st + 0x10A) = 0;
            *(s16 *)(st + 0x1E2) = 0;
            *(s16 *)(st + 0x1E0) = 0;
            *(s16 *)(st + 0x1CE) = 0;
            *(s16 *)(st + 0x1D0) = 0;
            *(f32 *)(st + 0x1E4) = 0.0f;
            *(f32 *)(st + 0x1E8) = 0.0f;
            *(s16 *)(st + 0x1C6) = *(s16 *)ob;
            *(s16 *)(st + 0x1C8) = *(s16 *)(ob + 0x2);
            *(s16 *)(st + 0x1DC) = *(s16 *)(st + 0x1CE);
            *(s16 *)(st + 0x1CA) = *(s16 *)(st + 0x1C6);
            *(s16 *)(st + 0x1CC) = *(s16 *)(st + 0x1C8);
            *(s16 *)(st + 0x1DE) = *(s16 *)(st + 0x1D0);
            return;
        }
        func_overlay_16_01004934_1F2294C(arg0, arg1, 1, arg4);
        if (*(s8 *)(ob + 0x3B) != 0xB && *(s8 *)(ob + 0x3B) != 0x31) {
            if (*(s32 *)((u8 *)controlModeKeys) & controlKeys) {
                *(u8 *)(st + 0x1F4) = 0xF;
            }
            if (!(*(u8 *)(*(u8 **)(st + 0x360) + 5) & *(u8 *)(st + 0x532))) {
                *(u8 *)(st + 0x1F4) = 0;
            }
            if (arg2 > 0.5f) {
                func_overlay_16_01004F78_1F22F90(arg0, arg1, 0x16, 0);
                *(u8 *)(st + 0x568) = 2;
            }
        }
    }
    *(f32 *)(st + 0x4) = *(f32 *)(st + 0x4) * Powerf(D_overlay_16_01007EC8, (s32)arg4);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o16/overlay_16/func_overlay_16_01002EB4_1F20ECC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_16_0100321C_1F21234(void *arg0, void *arg1, f32 arg2, s16 arg3, f32 arg4) {
    u8 *ob = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    s32 sp38;
    s32 sp44;
    f32 temp_f2;
    s32 var_v0;

    var_v0 = 0;
    if (*(f32 *)(st + 0x60) > 15.0f) {
        *(s16 *)(st + 0x5CA) = (s16)(*(s16 *)(st + 0x5CA) + (s32)arg4);
        if (*(s16 *)(st + 0x5CA) >= 0x79) {
            var_v0 = 1;
        }
    } else {
        *(s16 *)(st + 0x5CA) = 0;
    }
    if ((var_v0 != 0 || (*(s32 *)((u8 *)controlModeKeys + 0xC) & controlKeys)) && *(u8 *)(st + 0x56C) == 0 &&
        controlCeiling(*(f32 *)(ob + 0xC), *(f32 *)(ob + 0x10), *(s32 *)(ob + 0x14), 60.0f, 15.0f) != 0) {
        func_overlay_16_01004F78_1F22F90(arg0, arg1, 8, 0);
        *(u8 *)(st + 0x568) = 0;
        return;
    }
    sp38 = (s32)arg4;
    func_overlay_16_01004934_1F2294C(arg0, arg1, 2, arg4);
    controlWalkingBack(arg0, arg1, &arg2, arg3, 0x5000, 0x6800, 1.25f, 1.25f);
    if (*(u8 *)(st + 0x569) == 0) {
        arg2 = -arg2;
    } else {
        arg3 = (s16)(arg3 + 0x8000);
    }
    controlHalfTurn(arg0, arg1, &arg2, &arg3, 0x6AAA, 0x71C, &sp44, D_overlay_16_01007ECC, arg4);
    temp_f2 = *(f32 *)(st + 0x4);
    *(f32 *)(st + 0x4) = ((1.0f - Powerf(D_overlay_16_01007ED0, sp38)) * (arg2 - temp_f2)) + temp_f2;
    *(s16 *)(st + 0x11C) = dAngle(*(s16 *)(st + 0x11C), arg3, 1.0f - Powerf(D_overlay_16_01007ED4, sp38));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o16/overlay_16/func_overlay_16_0100321C_1F21234.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Juno player per-frame move step. Same shape as func_overlay_16_01002708_1F20720
// (arg0 = player object, arg1 = player state, arg4 = frame delta).
void func_overlay_16_01003464_1F2147C(u8 *arg0, u8 *arg1, f32 arg2, s16 arg3, f32 arg4) {
    s32 frames;     /* asm: (s32)arg4, truncated; reloaded from 0x30(sp) */
    s32 i;
    s32 off;        /* asm: v0, steps by 0x3C */
    s16 temp_a1;    /* asm: $t0, st->unk58C at entry to the 0x14A branch */
    f32 temp_f0;
    f32 temp_f2;
    f32 pw;         /* asm: Powerf result in $f0 */
    f32 var_f0;
    u8 var_v0;

    frames = (s32)arg4;
    arg1[0x576] = 0;
    if (!(*(s32 *)((u8 *)controlModeKeys + 0xC) & controlKeys)) {
        arg1[0x58E] = 1;
    }

    if (((*(u8 **)(arg1 + 0x360))[5] & arg1[0x532]) && *(s8 *)(arg1 + 0x57A) == 0) {
        /* block A: move button pressed and no pending countdown */
        *(s8 *)(arg1 + 0x14A) = 0;
        *(s8 *)(arg1 + 0x14B) = 0;
        *(f32 *)(arg1 + 0x594) = 0.0f;
        arg1[0x568] = arg1[0x56A];
        temp_f0 = *(f32 *)(arg1 + 0x57C) - *(f32 *)(arg0 + 0x10);
        if (*(s8 *)(arg1 + 0x1) == 1) {
            if (temp_f0 > 240.0f) {
                arg1[0x190] = 0x80;
            } else if (temp_f0 > 400.0f) {
                arg1[0x190] = 0xC0;
            }
        } else if (temp_f0 > 400.0f) {
            arg1[0x190] = 0x80;
        }
        if (temp_f0 > 120.0f) {
            func_overlay_16_01004F78_1F22F90(arg0, arg1, 0x19, 0);
            arg1[0x56B] = 0x1E;
            arg1[0x568] = 0;
        } else if (arg1[0x568] == 2) {
            func_overlay_16_01004F78_1F22F90(arg0, arg1, 4, 0);
        } else if (arg1[0x568] == 1) {
            func_overlay_16_01004F78_1F22F90(arg0, arg1, 0xD, 0);
        } else {
            func_overlay_16_01004F78_1F22F90(arg0, arg1, func_overlay_16_01004E08_1F22E20(arg1), 0);
            arg1[0x568] = 0;
        }
        charSpeak(arg0, 1);
        if (*(f32 *)(arg1 + 0x60) < 1.0f) {
            /* asm: level-dependent flag word OR'd into obj+0x84; table indexed by levelGetLevel()->unkE2 */
            *(s32 *)(arg0 + 0x84) |= D_overlay_16_01007A6C[*(u8 *)((u8 *)levelGetLevel() + 0xE2)];
        }
    } else if (*(s8 *)(arg1 + 0x57A) > 0) {
        /* countdown running: tick it down by frames */
        *(s8 *)(arg1 + 0x57A) = (s8)(*(s8 *)(arg1 + 0x57A) - frames);
        if (*(s32 *)((u8 *)controlModeKeys + 0xC) & controlKeys) {
            arg1[0x57B] = (u8)(arg1[0x57B] + frames);
        } else {
            *(s8 *)(arg1 + 0x57A) = 0;
        }
        if (*(s8 *)(arg1 + 0x57A) <= 0) {
            if (*(f32 *)(arg0 + 0x28) < 0.25f) {
                *(f32 *)(arg0 + 0x28) = D_overlay_16_01007ED8;
            }
            *(s8 *)(arg1 + 0x57A) = 0;
            charSpeak(arg0, 0);
            if (arg1[0x569] != 0) {
                *(f32 *)(arg0 + 0x20) = *(f32 *)(arg0 + 0x20) + 10.0f;
            } else {
                var_v0 = arg1[0x57B];
                if (var_v0 >= 0x19) {
                    arg1[0x57B] = 0x18;
                    var_v0 = 0x18;
                }
                if (multiPlayerGame != 0 && *(s8 *)(arg1 + 0x189) == 7) {
                    var_f0 = 15.0f;
                } else {
                    var_f0 = 12.0f;
                }
                *(f32 *)(arg0 + 0x20) = *(f32 *)(arg0 + 0x20) + (6.0f + (((var_f0 - 6.0f) * (f32)var_v0) / 24.0f));
            }
        }
        arg2 = 0.0f;
    } else if (*(s8 *)(arg1 + 0x14A) != 0) {
        /* branch 0x14A: airborne / slide state */
        *(f32 *)(arg0 + 0x28) = 0.0f;
        pw = Powerf(D_overlay_16_01007EDC, frames);
        temp_f2 = *(f32 *)(arg1 + 0x57C);
        *(f32 *)(arg1 + 0x57C) = temp_f2 + ((*(f32 *)(arg0 + 0x10) - temp_f2) * (1.0f - pw));
        temp_a1 = *(s16 *)(arg1 + 0x58C);
        if (((*(s32 *)((u8 *)controlModeKeys + 0x10)) & controlKeys) && temp_a1 > 0) {
            *(s16 *)(arg1 + 0x58C) = (s16)(temp_a1 - frames);
            *(s8 *)(arg1 + 0x591) = (s8)(*(s8 *)(arg1 + 0x591) + frames * 2);
            pw = Powerf(D_overlay_16_01007EE0, frames);
            *(f32 *)(arg1 + 0x594) = *(f32 *)(arg1 + 0x594)
                + ((((Sinf((s16)(*(s8 *)(arg1 + 0x591) << 8)) * 0.125f) + 1.0f) - *(f32 *)(arg1 + 0x594)) * (1.0f - pw));
            *(f32 *)(arg0 + 0x20) = *(f32 *)(arg0 + 0x20) * Powerf(D_overlay_16_01007EE4, frames);
            D_overlay_16_010080D0 |= 1;
            D_overlay_16_010080D4 |= 1;
        } else if ((*(s32 *)((u8 *)controlModeKeys + 0xC) & controlKeys) && temp_a1 > 0) {
            *(s16 *)(arg1 + 0x58C) = (s16)(temp_a1 - frames * 2);
            pw = Powerf(D_overlay_16_01007EE8, frames);
            *(f32 *)(arg1 + 0x594) = *(f32 *)(arg1 + 0x594) + ((1.0f - *(f32 *)(arg1 + 0x594)) * (1.0f - pw));
            pw = Powerf(D_overlay_16_01007EEC, frames);
            *(f32 *)(arg0 + 0x20) = *(f32 *)(arg0 + 0x20) + ((5.0f - *(f32 *)(arg0 + 0x20)) * (1.0f - pw));
            D_overlay_16_010080D0 |= 2;
            D_overlay_16_010080D4 |= 1;
        } else {
            *(f32 *)(arg1 + 0x594) = *(f32 *)(arg1 + 0x594) * Powerf(D_overlay_16_01007EF0, frames);
            if (*(f32 *)(arg1 + 0x594) < D_overlay_16_01007EF4) {
                func_overlay_16_01004F78_1F22F90(arg0, arg1, 0x18, 0);
                *(s8 *)(arg1 + 0x14A) = 0;
                *(f32 *)(arg1 + 0x594) = 0.0f;
            }
        }
        if (temp_a1 != *(s16 *)(arg1 + 0x58C)) {
            *(s16 *)(arg1 + 0x592) = 0x168;
        }
        if (*(s16 *)(arg1 + 0x58C) < 0x259) {
            /* asm: sound loop over 11 slots, stops after the first hit */
            for (i = 0, off = 0; i != 0xB; i++, off += 0x3C) {
                if (off >= *(s16 *)(arg1 + 0x58C) && off < temp_a1) {
                    /* asm: $a2/$a3 are not set in this function on this path */
                    amSndPlay((i + 0x15F) & 0xFFFF, NULL, 0, NULL);
                    break;
                }
            }
        }
        if (*(s32 *)controlModeKeys & controlKeys) {
            arg1[0x1F4] = 0xF;
        }
    } else if (*(f32 *)(arg0 + 0x10) < (*(f32 *)(arg1 + 0x57C) - 120.0f) && *(s8 *)(arg0 + 0x3B) != 0x18) {
        func_overlay_16_01004F78_1F22F90(arg0, arg1, 0x18, 0);
    } else if (*(s8 *)(arg1 + 0x1) == 5 && *(s8 *)(arg1 + 0x189) == 0 && *(s8 *)(arg1 + 0x58E) != 0
               && *(s16 *)(arg1 + 0x58C) > 0) {
        if (((*(s32 *)((u8 *)controlModeKeys + 0xC)) | (*(s32 *)((u8 *)controlModeKeys + 0x10))) & controlKeys) {
            func_overlay_16_01004F78_1F22F90(arg0, arg1, 0x33, 0);
            arg1[0x14A] = 1;
            *(s16 *)(arg1 + 0x128) = *(s16 *)(arg1 + 0x11C);
        }
    }

    controlWalkingBack(arg0, arg1, &arg2, arg3, 0x5000, 0x6800, 5.0f, 3.0f);
    if (arg1[0x569] == 0) {
        arg2 = -arg2;
    } else {
        arg3 = (s16)(arg3 + 0x8000);
    }
    pw = Powerf(1.0f - ((*(f32 *)(arg1 + 0x594) * D_overlay_16_01007EF8) + D_overlay_16_01007EFC), frames);
    temp_f2 = *(f32 *)(arg1 + 0x4);
    *(f32 *)(arg1 + 0x4) = ((1.0f - pw) * (arg2 - temp_f2)) + temp_f2;
    pw = Powerf(1.0f - ((*(f32 *)(arg1 + 0x594) * D_overlay_16_01007F00) + D_overlay_16_01007F04), frames);
    *(s16 *)(arg1 + 0x11C) = dAngle(*(s16 *)(arg1 + 0x11C), arg3, 1.0f - pw);
    if (*(s8 *)(arg1 + 0x14A) != 0) {
        pw = Powerf(D_overlay_16_01007F08, frames);
        *(s16 *)(arg1 + 0x128) = dAngle(*(s16 *)(arg1 + 0x128), *(s16 *)(arg1 + 0x11C), 1.0f - pw);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o16/overlay_16/func_overlay_16_01003464_1F2147C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_16_01003DB0_1F21DC8(s16 arg0, s16 arg1, s16 arg2, s16 arg3) {
    s32 temp;

    if (arg0 < -0x2AAA) {
        arg0 = -0x2AAA;
    }
    if (arg2 >= 0x2AAB) {
        arg2 = 0x2AAA;
    }
    if (arg2 < -0x2AAA) {
        arg2 = -0x2AAA;
    }
    *D_overlay_16_010080D8 = 6;
    temp = (s32)((f32)arg0 * 0.5f);
    D_overlay_16_010080D8 += 1;
    *D_overlay_16_010080D8 = (s16)temp;
    D_overlay_16_010080D8 += 1;
    *D_overlay_16_010080D8 = 8;
    D_overlay_16_010080D8 += 1;
    *D_overlay_16_010080D8 = arg1;
    D_overlay_16_010080D8 += 1;
    *D_overlay_16_010080D8 = 0x12;
    D_overlay_16_010080D8 += 1;
    *D_overlay_16_010080D8 = (s16)(arg0 - temp);
    D_overlay_16_010080D8 += 1;
    *D_overlay_16_010080D8 = 0x3C;
    D_overlay_16_010080D8 += 1;
    arg2 = (s16)(arg2 - temp);
    *D_overlay_16_010080D8 = arg2;
    D_overlay_16_010080D8 += 1;
    *D_overlay_16_010080D8 = 0x3E;
    D_overlay_16_010080D8 += 1;
    arg3 = (s16)(arg3 - arg1);
    *D_overlay_16_010080D8 = arg3;
    D_overlay_16_010080D8 += 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o16/overlay_16/func_overlay_16_01003DB0_1F21DC8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_16_01003F20_1F21F38(void) {
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o16/overlay_16/func_overlay_16_01003F20_1F21F38.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_16_01003F30_1F21F48(void *arg0, void *arg1, f32 arg2, s16 arg3, f32 arg4) {
    u8 *ob = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    s16 sp56;
    s16 sp54;
    f32 sp4C;
    s32 sp3C;
    s32 temp_f6;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    s16 temp_v1;
    s16 var_v1;
    s8 temp_a1;
    u8 *cur;

    mainGetGameCharacter(*(s8 *)st, *(s8 *)(st + 1));
    *(s8 *)(st + 0x576) = 0;
    *(u8 *)(st + 0x13E) = 0;
    if (!(controlKeys & 0x10) && D_overlay_16_010080DC == 0) {
        *(u8 *)(st + 0x568) = 1;
        *(s16 *)(st + 0x104) = (s16)(0x8000 - *(s16 *)ob);
        return;
    }
    temp_f6 = (s32)arg4;
    sp3C = temp_f6;
    *(f32 *)(st + 0x10) = *(f32 *)(st + 0x10) * Powerf(D_overlay_16_01007F0C, temp_f6);
    temp_f2 = *(f32 *)(st + 0x10);
    if (D_overlay_16_01007F10 < temp_f2 && temp_f2 < D_overlay_16_01007F14) {
        *(f32 *)(st + 0x10) = 0.0f;
    }
    *(f32 *)(st + 0x4) = *(f32 *)(st + 0x4) * Powerf(D_overlay_16_01007F18, sp3C);
    temp_f2_2 = *(f32 *)(st + 0x4);
    if (D_overlay_16_01007F1C < temp_f2_2 && temp_f2_2 < D_overlay_16_01007F20) {
        *(f32 *)(st + 0x4) = 0.0f;
    }
    if (D_overlay_16_010080DC == 0) {
        if (controlGetManualAim(arg0, arg1, 0xE38, 0xE38, -0x2AAA, 0x2AAA, &sp56, &sp54, arg4) != 0) {
            camSetZoom(*(s8 *)st, *(s32 *)(st + 0x1EC));
        }
    } else {
        sp56 = *(s16 *)(st + 0x1DC);
        sp54 = (s16)(*(s16 *)(st + 0x1DE) - *(s16 *)(st + 0x1E2));
    }
    temp_f2_3 = 1.0f - Powerf(D_overlay_16_01007F24, sp3C);
    if (*(s16 *)(st + 0x1E2) < -0xA80) {
        *(s16 *)(st + 0x1E2) = -0xA80;
    }
    if (*(s16 *)(st + 0x1E2) >= 0x1556) {
        *(s16 *)(st + 0x1E2) = 0x1555;
    }
    sp4C = temp_f2_3;
    *(s16 *)(st + 0x1E0) = dAngle(*(s16 *)(st + 0x1E0), sp54, temp_f2_3);
    sp54 = (s16)(sp54 + *(s16 *)(st + 0x1E2));
    *(s16 *)(st + 0x1DC) = dAngle(*(s16 *)(st + 0x1DC), sp56, sp4C);
    *(s16 *)(st + 0x1DE) = dAngle(*(s16 *)(st + 0x1DE), sp54, sp4C);
    *(s16 *)(st + 0x1CE) = dAngle(*(s16 *)(st + 0x1CE), sp56, sp4C);
    *(s16 *)(st + 0x1D0) = dAngle(*(s16 *)(st + 0x1D0), sp54, sp4C);
    temp_v1 = *(s16 *)(st + 0x1CE);
    *(s16 *)(st + 0x1C6) = (s16)(temp_v1 + *(s16 *)ob);
    *(s16 *)(st + 0x1CA) = *(s16 *)(st + 0x1C6);
    *(s16 *)(st + 0x1C8) = (s16)(*(s16 *)(st + 0x1D0) + *(s16 *)(ob + 0x2));
    *(s16 *)(st + 0x1CC) = *(s16 *)(st + 0x1C8);
    sp56 = temp_v1;
    var_v1 = 0;
    sp54 = *(s16 *)(st + 0x1D0);
    temp_a1 = *(s8 *)(st + 0x1F6);
    if (temp_a1 != 0) {
        var_v1 = (s16)(((s32)(mathSin((s16)(temp_a1 << 0xC), temp_a1) * *(s8 *)(st + 0x1F7))) >> 9);
    }
    cur = (u8 *)D_overlay_16_010080D8;
    ((s16 *)cur)[0] = 6;
    ((s16 *)cur)[1] = (s16)(sp54 + var_v1);
    ((s16 *)cur)[2] = 8;
    ((s16 *)cur)[3] = sp56;
    ((s16 *)cur)[4] = 0x12;
    ((s16 *)cur)[5] = var_v1;
    ((s16 *)cur)[6] = 0x3C;
    ((s16 *)cur)[7] = (s16)(*(s16 *)(st + 0x1DE) - sp54);
    ((s16 *)cur)[8] = 0x3E;
    ((s16 *)cur)[9] = (s16)(*(s16 *)(st + 0x1DC) - sp56);
    D_overlay_16_010080D8 = (s16 *)cur + 10;
    if (*(f32 *)(st + 0x60) > 30.0f) {
        *(s16 *)(st + 0x5CA) = (s16)(*(s16 *)(st + 0x5CA) + sp3C);
    } else {
        *(s16 *)(st + 0x5CA) = 0;
    }
    if ((frontGetTargetControl(*(s8 *)st) != 0 && ((*(s32 *)((u8 *)controlModeKeys + 0x20) | *(s32 *)((u8 *)controlModeKeys + 0x1C)) & controlKeys)) ||
        (*(s32 *)((u8 *)controlModeKeys + 0xC) & controlDkeys) || *(s16 *)(st + 0x5CA) >= 0x79) {
        *(u8 *)(st + 0x568) = 0xB;
        func_overlay_16_01004F78_1F22F90(arg0, arg1, func_overlay_16_01004E08_1F22E20(arg1), 0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o16/overlay_16/func_overlay_16_01003F30_1F21F48.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_16_01004440_1F22458(void *arg0, void *arg1, f32 arg2, s16 arg3, f32 arg4) {
    u8 *ob = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    s16 sp56;
    s16 sp54;
    f32 sp50;
    void *temp_v0;
    s32 sp3C;
    s32 temp_f16;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 var_f0;
    s32 temp_a0;
    s16 temp_v1;
    s8 temp_a1;

    temp_v0 = mainGetGameCharacter(*(s8 *)st, *(s8 *)(st + 1));
    *(s8 *)(st + 0x576) = 0;
    *(u8 *)(st + 0x13E) = 0;
    if (!(controlKeys & 0x10) && D_overlay_16_010080DC == 0) {
        *(u8 *)(st + 0x568) = 0;
        *(s16 *)(st + 0x104) = (s16)(0x8000 - *(s16 *)ob);
        return;
    }
    if (frontGetTargetControl(*(s8 *)st) != 0 && *(s8 *)((u8 *)temp_v0 + 0x70) != 7 &&
        (temp_a0 = *(s32 *)((u8 *)controlModeKeys + 0x1C), ((*(s32 *)((u8 *)controlModeKeys + 0x20) | temp_a0) & controlKeys) != 0)) {
        if (temp_a0 & controlKeys) {
            *(f32 *)(st + 0x4) = *(f32 *)(st + 0x4) - (D_overlay_16_01007F28 * arg4);
            var_f0 = -(65.0f * D_overlay_16_010080E4);
            if (*(f32 *)(st + 0x4) < var_f0) {
                *(f32 *)(st + 0x4) = var_f0;
            }
        } else {
            *(f32 *)(st + 0x4) = *(f32 *)(st + 0x4) + (D_overlay_16_01007F2C * arg4);
            if (*(f32 *)(st + 0x4) > 3.0f) {
                *(f32 *)(st + 0x4) = 3.0f;
            }
        }
        sp3C = (s32)arg4;
    } else {
        temp_f16 = (s32)arg4;
        sp3C = temp_f16;
        *(f32 *)(st + 0x4) = *(f32 *)(st + 0x4) * Powerf(D_overlay_16_01007F30, temp_f16);
        temp_f2 = *(f32 *)(st + 0x4);
        if (D_overlay_16_01007F34 < temp_f2 && temp_f2 < D_overlay_16_01007F38) {
            *(f32 *)(st + 0x4) = 0.0f;
        }
    }
    func_overlay_16_01004934_1F2294C(arg0, arg1, 0, arg4);
    if (D_overlay_16_010080DC == 0) {
        if (controlGetManualAim(arg0, arg1, 0xE38, 0xE38, -0x2AAA, 0x2AAA, &sp56, &sp54, arg4) != 0) {
            camSetZoom(*(s8 *)st, *(s32 *)(st + 0x1EC));
        }
    } else {
        sp56 = *(s16 *)(st + 0x1DC);
        sp54 = (s16)(*(s16 *)(st + 0x1DE) - *(s16 *)(st + 0x1E2));
    }
    temp_f2_2 = 1.0f - Powerf(D_overlay_16_01007F3C, sp3C);
    sp50 = temp_f2_2;
    *(s16 *)(st + 0x1E0) = dAngle(*(s16 *)(st + 0x1E0), sp54, temp_f2_2);
    sp54 = (s16)(sp54 + *(s16 *)(st + 0x1E2));
    *(s16 *)(st + 0x1DC) = dAngle(*(s16 *)(st + 0x1DC), sp56, sp50);
    *(s16 *)(st + 0x1DE) = dAngle(*(s16 *)(st + 0x1DE), sp54, sp50);
    *(s16 *)(st + 0x1CE) = dAngle(*(s16 *)(st + 0x1CE), sp56, sp50);
    *(s16 *)(st + 0x1D0) = dAngle(*(s16 *)(st + 0x1D0), sp54, sp50);
    temp_v1 = *(s16 *)(st + 0x1CE);
    *(s16 *)(st + 0x1C6) = (s16)(temp_v1 + *(s16 *)ob);
    *(s16 *)(st + 0x1CA) = *(s16 *)(st + 0x1C6);
    *(s16 *)(st + 0x1C8) = (s16)(*(s16 *)(st + 0x1D0) + *(s16 *)(ob + 0x2));
    *(s16 *)(st + 0x1CC) = *(s16 *)(st + 0x1C8);
    sp56 = temp_v1;
    sp54 = *(s16 *)(st + 0x1D0);
    temp_a1 = *(s8 *)(st + 0x1F6);
    if (temp_a1 != 0) {
        sp54 = (s16)(sp54 + (((s32)(*(s8 *)(st + 0x1F7) * mathSin((s16)(temp_a1 << 0xC), temp_a1))) >> 8));
    }
    func_overlay_16_01003DB0_1F21DC8(sp54, sp56, *(s16 *)(st + 0x1DE), *(s16 *)(st + 0x1DC));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o16/overlay_16/func_overlay_16_01004440_1F22458.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_16_01004840_1F22858(s32 arg0, void *arg1, s32 arg2) {
    u8 *st = (u8 *)arg1;
    f32 var_f0;
    f32 var_f14;
    s32 var_s2;
    s32 i;

    var_f14 = *(f32 *)(st + 0x4);
    var_f0 = *(f32 *)(st + 0x10);
    if (var_f14 < 0.0f) {
        var_f14 = -var_f14;
    }
    var_s2 = 0;
    if (var_f0 < 0.0f) {
        var_f0 = -var_f0;
    }
    if (var_f0 < var_f14) {
        var_s2 = -(s32)Arctanf(*(f32 *)(st + 0x10), var_f14);
    }
    if (arg2 != 0) {
        i = arg2 - 1;
        do {
            *(s32 *)(st + 0x580) = (mathDiffAngle(*(s32 *)(st + 0x580), var_s2) >> 4) + *(s32 *)(st + 0x580);
        } while (i--);
    }
    *D_overlay_16_010080D8 = 0x44;
    D_overlay_16_010080D8 += 1;
    *D_overlay_16_010080D8 = (s16)*(s32 *)(st + 0x580);
    D_overlay_16_010080D8 += 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o16/overlay_16/func_overlay_16_01004840_1F22858.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_16_01004934_1F2294C(void *arg0, void *arg1, s32 arg2, f32 arg3) {
    u8 *ob = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    s32 sp34;
    f32 sp20;
    void *var_a2;
    f32 temp_f12;
    f32 temp_f2;
    f32 var_f0;
    f32 var_f14;
    f32 var_f2;
    s8 temp_v0;
    s8 temp_v1;
    s8 var_v1;

    var_v1 = *(s8 *)(st + 0x584);
    *(u8 *)(st + 0x56C) = 0;
    if ((var_v1 == 1 || var_v1 == 2 || var_v1 == 3 || var_v1 == 4) && *(f32 *)(ob + 0x28) == 1.0f) {
        *(s8 *)(st + 0x584) = 0;
        var_v1 = *(s8 *)(st + 0x584);
        *(f32 *)(st + 0x10) = 0.0f;
    }
    if (var_v1 == 0) {
        if (arg2 == 2) {
            if (*(s32 *)((u8 *)controlModeKeys + 0x14) & controlKeys) {
                *(s8 *)(st + 0x584) = 3;
                func_overlay_16_01004F78_1F22F90(arg0, arg1, 0x32, 0);
                *(f32 *)(ob + 0x28) = 0.0f;
                *(u8 *)(st + 0x56C) = 1;
            } else if (*(s32 *)((u8 *)controlModeKeys + 0x18) & controlKeys) {
                *(s8 *)(st + 0x584) = 4;
                func_overlay_16_01004F78_1F22F90(arg0, arg1, 0xC, 0);
                *(f32 *)(ob + 0x28) = 0.0f;
                *(u8 *)(st + 0x56C) = 1;
            }
        } else if (arg2 == 1) {
            if (*(s32 *)((u8 *)controlModeKeys + 0x14) & controlKeys) {
                *(s8 *)(st + 0x584) = 1;
                func_overlay_16_01004F78_1F22F90(arg0, arg1, 0x31, 0);
                *(f32 *)(ob + 0x28) = 0.0f;
                *(u8 *)(st + 0x56C) = 1;
            } else if (*(s32 *)((u8 *)controlModeKeys + 0x18) & controlKeys) {
                *(s8 *)(st + 0x584) = 2;
                func_overlay_16_01004F78_1F22F90(arg0, arg1, 0xB, 0);
                *(f32 *)(ob + 0x28) = 0.0f;
                *(u8 *)(st + 0x56C) = 1;
            }
        } else {
            if (*(s32 *)((u8 *)controlModeKeys + 0x14) & controlKeys) {
                *(f32 *)(st + 0x10) = *(f32 *)(st + 0x10) - (D_overlay_16_01007F40 * arg3);
                if (*(f32 *)(st + 0x10) < -2.5f) {
                    *(f32 *)(st + 0x10) = -2.5f;
                }
                sp34 = 9;
                *(u8 *)(st + 0x56C) = 1;
            } else if (*(s32 *)((u8 *)controlModeKeys + 0x18) & controlKeys) {
                *(f32 *)(st + 0x10) = *(f32 *)(st + 0x10) + (D_overlay_16_01007F44 * arg3);
                if (*(f32 *)(st + 0x10) > 2.5f) {
                    *(f32 *)(st + 0x10) = 2.5f;
                }
                sp34 = 0xA;
                *(u8 *)(st + 0x56C) = 1;
            }
            if (*(u8 *)(st + 0x56C) != 0) {
                var_f0 = *(f32 *)(st + 0x10);
                if (var_f0 < 0.0f) {
                    var_f0 = -var_f0;
                }
                var_f2 = *(f32 *)(st + 0x4);
                if (var_f2 < 0.0f) {
                    var_f2 = -var_f2;
                }
                if (var_f2 < var_f0) {
                    func_overlay_16_01004F78_1F22F90(arg0, arg1, sp34, *(s32 *)(ob + 0x28));
                }
            }
        }
    }
    temp_v0 = *(s8 *)(st + 0x584);
    var_a2 = NULL;
    switch (temp_v0) {
    case 3:
        if (*(s8 *)(ob + 0x3B) == 0x32) {
            var_a2 = &D_overlay_16_01007D7C;
            sp20 = D_overlay_16_01007F48;
        }
        break;
    case 4:
        if (*(s8 *)(ob + 0x3B) == 0xC) {
            var_a2 = &D_overlay_16_01007D7C;
            sp20 = D_overlay_16_01007F4C;
        }
        break;
    case 1:
        if (*(s8 *)(ob + 0x3B) == 0x31) {
            var_a2 = &D_overlay_16_01007DAC;
            sp20 = D_overlay_16_01007F50;
        }
        break;
    case 2:
        if (*(s8 *)(ob + 0x3B) == 0xB) {
            var_a2 = &D_overlay_16_01007DAC;
            sp20 = D_overlay_16_01007F54;
        }
        break;
    }
    if (var_a2 != NULL) {
        temp_f12 = *(f32 *)(ob + 0x28);
        var_f14 = temp_f12 + (sp20 * arg3);
        if (var_f14 < 0.0f) {
            var_f14 = 0.0f;
        }
        if (var_f14 > 1.0f) {
            var_f14 = 1.0f;
        }
        temp_v1 = *(s8 *)(st + 0x584);
        *(f32 *)(st + 0x10) = controlMakeV(temp_f12, var_f14, arg0, var_a2, arg3);
        if (temp_v1 == 3 || temp_v1 == 1) {
            *(f32 *)(st + 0x10) = -*(f32 *)(st + 0x10);
        }
        *(u8 *)(st + 0x56C) = 1;
    }
    if (*(u8 *)(st + 0x56C) == 0) {
        *(s8 *)(st + 0x584) = 0;
        *(f32 *)(st + 0x10) = *(f32 *)(st + 0x10) * Powerf(D_overlay_16_01007F58, (s32)arg3);
        temp_f2 = *(f32 *)(st + 0x10);
        if (D_overlay_16_01007F5C < temp_f2 && temp_f2 < D_overlay_16_01007F60) {
            *(f32 *)(st + 0x10) = 0.0f;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o16/overlay_16/func_overlay_16_01004934_1F2294C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_16_01004E08_1F22E20(void *arg0) {
    u8 *obj = (u8 *)arg0;
    f32 absX;
    f32 absY;
    f32 temp_f14;
    f32 mag;
    s32 kind;

    absX = *(f32 *)(obj + 0x4);
    if (absX < 0.0f) {
        absX = -absX;
    }
    temp_f14 = *(f32 *)(obj + 0x10);
    absY = temp_f14;
    if (temp_f14 < 0.0f) {
        absY = -absY;
    }
    mag = absX;
    if (absX < absY) {
        mag = absY;
    }
    if (mag < D_overlay_16_01007F64) {
        if (obj[0x1FA] != 0) {
            kind = 0x10;
        } else if (obj[0x1F9] != 0 || *(s8 *)(obj + 0x1F4) != 0) {
            kind = 0x12;
        } else if (obj[0x198] != 0) {
            kind = 0x12;
        } else {
            kind = mathRnd(0x10, 0x13);
        }
    } else if (absX < absY) {
        kind = (temp_f14 < 0.0f) ? 9 : 0xA;
    } else if (obj[0x569] != 0) {
        kind = 3;
    } else if (mag > 3.5f) {
        kind = 2;
    } else {
        kind = 0;
        if (mag > 1.75f) {
            kind = 1;
        }
    }
    return kind;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o16/overlay_16/func_overlay_16_01004E08_1F22E20.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_16_01004F78_1F22F90(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    u8 *obj = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    u8 var_a3;
    u8 var_s0;

    if (*(s32 *)(st + 0x5CC) != 0) {
        var_a3 = D_overlay_16_01007870[arg2 * 5 + 2];
        var_s0 = D_overlay_16_01007870[var_a3 * 5 + 3];
    } else if (*(s8 *)(st + 0x1F4) != 0 && controlPlayerGunWeight(st) != 0) {
        var_a3 = D_overlay_16_01007870[arg2 * 5 + 1];
        var_s0 = D_overlay_16_01007870[var_a3 * 5 + 4];
    } else if (controlPlayerGunWeight(st) != 0) {
        var_a3 = D_overlay_16_01007870[arg2 * 5 + 2];
        var_s0 = D_overlay_16_01007870[var_a3 * 5 + 3];
    } else {
        var_a3 = D_overlay_16_01007870[arg2 * 5];
        var_s0 = D_overlay_16_01007870[var_a3 * 5 + 3];
    }
    if (var_a3 != obj[0x3B]) {
        objAnimSetMove(obj, var_a3, arg3, var_a3);
        D_overlay_16_010080E0 += 1;
    }
    controlSetTransition(obj, st, D_overlay_16_010077E4, var_s0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o16/overlay_16/func_overlay_16_01004F78_1F22F90.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_16_01005120_1F23138(void *arg0, void *arg1, f32 arg2, f32 arg3) {
    u8 *obj = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    f32 sp30;
    f32 sp28;
    f32 sp20;
    f32 temp_f16;
    f32 var_f12;
    f32 var_f14;
    f32 var_f18;
    f32 var_f2;
    s32 var_s0;
    s32 kind;
    f32 temp_f0;
    f32 temp_f4;
    u8 temp_v0_2;

    temp_f4 = *(f32 *)(st + 0x4);
    sp20 = temp_f4;
    var_f14 = temp_f4;
    if (temp_f4 < 0.0f) {
        var_f14 = -temp_f4;
    }
    temp_f16 = *(f32 *)(st + 0x10);
    var_f12 = temp_f16;
    if (temp_f16 < 0.0f) {
        var_f12 = -var_f12;
    }
    var_f2 = var_f14;
    if (var_f14 < var_f12) {
        var_f2 = var_f12;
    }
    kind = (s8)obj[0x3B];
    temp_f0 = *(f32 *)(obj + 0x28);
    var_s0 = kind;
    var_f18 = temp_f0;
    sp28 = temp_f0;
    sp30 = D_overlay_16_01007974[kind];

    switch (kind) {
    case 0:
    case 28:
    case 36:
        sp30 *= var_f2;
        if (st[0x569] != 0) {
            var_s0 = 3;
        } else if (var_f2 < D_overlay_16_01008034) {
            if (st[0x1FA] != 0) {
                var_f18 = 0.0f;
                var_s0 = 0x10;
            } else if (st[0x1F9] != 0 || st[0x1F4] != 0) {
                var_f18 = 0.0f;
                var_s0 = 0x12;
            } else if (st[0x198] != 0) {
                var_f18 = 0.0f;
                var_s0 = 0x12;
            } else {
                var_s0 = mathRnd(0x10, 0x13);
                var_f18 = 0.0f;
            }
        } else if (var_f14 < var_f12) {
            var_f18 = 0.25f;
            var_s0 = (temp_f16 < 0.0f) ? 9 : 10;
        } else if (var_f2 > 1.75f) {
            var_s0 = 1;
        }
        break;
    case 1:
    case 29:
    case 35:
        sp30 *= var_f2;
        if (var_f14 < var_f12) {
            var_f18 = 0.25f;
            var_s0 = (temp_f16 < 0.0f) ? 9 : 10;
        } else if (var_f2 < 1.75f) {
            var_s0 = 0;
        } else if (var_f2 > 3.5f) {
            var_s0 = 2;
        }
        break;
    case 2:
    case 30:
    case 34:
        sp30 *= var_f2;
        if (var_f14 < var_f12) {
            var_f18 = 0.25f;
            var_s0 = (temp_f16 < 0.0f) ? 9 : 10;
        } else if (var_f2 < 3.5f) {
            var_s0 = 1;
        }
        break;
    case 3:
    case 26:
        sp30 *= var_f2;
        if (var_f2 < D_overlay_16_01008038 && arg2 <= sp20) {
            if (st[0x1FA] != 0) {
                var_f18 = 0.0f;
                var_s0 = 0x10;
            } else if (st[0x1F9] != 0 || st[0x1F4] != 0) {
                var_f18 = 0.0f;
                var_s0 = 0x12;
            } else if (st[0x198] != 0) {
                var_f18 = 0.0f;
                var_s0 = 0x12;
            } else {
                var_s0 = mathRnd(0x10, 0x13);
                var_f18 = 0.0f;
            }
        } else if (var_f14 < var_f12) {
            var_f18 = 0.25f;
            var_s0 = (temp_f16 < 0.0f) ? 9 : 10;
        } else if (st[0x569] == 0) {
            var_s0 = 0;
        }
        break;
    case 4:
    case 44:
        sp30 *= var_f2;
        if (var_f2 < D_overlay_16_0100803C) {
            var_f18 = 0.0f;
            var_s0 = 0x16;
        }
        break;
    case 5:
        if ((temp_f0 + (sp30 * arg3)) > 0.75f) {
            *(f32 *)(obj + 0x28) = 0.75f;
            sp30 = 0.0f;
        }
        break;
    case 8:
        if (temp_f0 == 1.0f) {
            var_s0 = func_overlay_16_01004E08_1F22E20(st);
            var_f18 = 0.0f;
        }
        break;
    case 9:
    case 10:
    case 31:
    case 32:
    case 47:
    case 48:
        sp30 *= var_f12;
        if (var_f2 < D_overlay_16_01008040 && st[0x56C] == 0) {
            if (st[0x1FA] != 0) {
                var_f18 = 0.0f;
                var_s0 = 0x10;
            } else if (st[0x1F9] != 0 || st[0x1F4] != 0) {
                var_f18 = 0.0f;
                var_s0 = 0x12;
            } else if (st[0x198] != 0) {
                var_f18 = 0.0f;
                var_s0 = 0x12;
            } else {
                var_s0 = mathRnd(0x10, 0x13);
                var_f18 = 0.0f;
            }
        } else if (var_f12 < var_f14) {
            if (st[0x569] != 0) {
                var_f18 = 0.25f;
                var_s0 = 3;
            } else if (var_f14 < 1.75f) {
                var_f18 = 0.25f;
                var_s0 = 0;
            } else {
                var_s0 = 2;
                if (var_f14 < 3.5f) {
                    var_f18 = 0.25f;
                    var_s0 = 1;
                } else {
                    var_f18 = 0.25f;
                }
            }
        }
        break;
    case 11:
        if (st[0x584] != 2) {
            var_f18 = 0.0f;
            var_s0 = 0xE;
        }
        break;
    case 49:
        if (st[0x584] != 1) {
            var_f18 = 0.0f;
            var_s0 = 0xE;
        }
        break;
    case 12:
        if (st[0x584] != 4) {
            var_s0 = 4;
            if (var_f2 < D_overlay_16_01008044) {
                var_f18 = 0.0f;
                var_s0 = 0x16;
            } else {
                var_f18 = 0.0f;
            }
        }
        break;
    case 50:
        if (st[0x584] != 3) {
            var_s0 = 4;
            if (var_f2 < D_overlay_16_01008048) {
                var_f18 = 0.0f;
                var_s0 = 0x16;
            } else {
                var_f18 = 0.0f;
            }
        }
        break;
    case 13:
        var_f18 = 0.0f;
        if (controlKeys & 0x10) {
            sp30 *= 2.0f;
        }
        if (D_overlay_16_0100804C < temp_f0) {
            var_s0 = 0xE;
        }
        break;
    case 14:
    case 33:
        if (D_overlay_16_01008050 < var_f2) {
            var_f18 = 0.0f;
            var_s0 = 4;
        }
        break;
    case 15:
        if (st[0x576] == 0) {
            var_s0 = func_overlay_16_01004E08_1F22E20(st);
            var_f18 = 0.0f;
        }
        break;
    case 16:
    case 17:
    case 18:
    case 19:
    case 20:
    case 27:
    case 45:
        if ((temp_f0 + (sp30 * arg3)) > 1.0f) {
            if (st[0x1FA] != 0) {
                var_s0 = 0x10;
                obj[0x3B] = 0xFF;
            } else if (st[0x1F9] != 0 || st[0x1F4] != 0) {
                obj[0x3B] = 0xFF;
                var_s0 = 0x12;
            } else if (st[0x198] != 0) {
                var_s0 = 0x12;
                obj[0x3B] = 0xFF;
            } else {
                var_s0 = mathRnd(0x10, 0x13);
            }
            var_f18 = 0.0f;
        }
        if (D_overlay_16_01008054 < var_f2) {
            var_s0 = 3;
            if (st[0x569] == 0) {
                var_f18 = 0.25f;
                var_s0 = 0;
            } else {
                var_f18 = 0.25f;
            }
        }
        break;
    case 21:
    case 46:
        if (D_overlay_16_01008058 < temp_f0) {
            temp_v0_2 = st[0x568];
            if (temp_v0_2 == 1 || temp_v0_2 == 5) {
                var_f18 = 0.0f;
                var_s0 = 0xE;
            } else {
                var_s0 = func_overlay_16_01004E08_1F22E20(st);
                var_f18 = 0.0f;
            }
        }
        break;
    case 22:
        if (D_overlay_16_0100805C < var_f2) {
            var_f18 = 0.0f;
            var_s0 = 4;
        }
        break;
    case 38:
        if (D_overlay_16_01008060 < var_f2 || D_overlay_16_01008060 < *(f32 *)(obj + 0x20)) {
            var_s0 = 0x25;
        }
        break;
    case 37:
        sp30 *= var_f2;
        if (var_f2 < D_overlay_16_01008064) {
            if (*(f32 *)(obj + 0x20) < D_overlay_16_01008064) {
                var_s0 = 0x26;
            }
        }
        break;
    case 43:
        if (st[0x1FA] == 0) {
            var_s0 = func_overlay_16_01004E08_1F22E20(st);
            var_f18 = 0.0f;
        } else if (temp_f0 < D_overlay_16_01008068 && D_overlay_16_01008068 <= (temp_f0 + (sp30 * arg3))) {
            D_overlay_16_010080DE = 1;
        }
        break;
    case 41:
        if ((temp_f0 + (sp30 * arg3)) > 1.0f) {
            var_f18 = 0.0f;
            var_s0 = 0x18;
        }
        break;
    case 42:
        if ((temp_f0 + (sp30 * arg3)) > 1.0f) {
            var_f18 = 0.0f;
            var_s0 = 0x28;
        }
        break;
    case 39:
        if (st[0x19F] == 0 && st[0x10D] == 0) {
            var_s0 = func_overlay_16_01004E08_1F22E20(st);
            var_f18 = 0.0f;
        }
        break;
    default:
        break;
    }
    objAnimDframe(obj, sp30, arg3);
    charAnimSoundTick(obj, sp28, sp30);
    func_overlay_16_01001D58_1F1FD70(obj, st, sp28, sp30);
    func_overlay_16_01004F78_1F22F90(obj, st, var_s0, *(s32 *)&var_f18);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o16/overlay_16/func_overlay_16_01005120_1F23138.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_16_01005BB8_1F23BD0(void *arg0, void *arg1, f32 arg2) {
    u8 *obj = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    f32 temp_f2;
    f32 temp_f0_2;
    f32 temp_f12;
    f32 temp_f14;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f12;
    f32 var_f14;
    f32 sp3C;
    f32 vec[3];
    s16 rot[3];
    s16 var_a2;
    s16 var_a0;
    s16 var_a2_2;
    s16 var_a0_2;
    s16 var_a2_3;
    s32 groundHit;
    u8 temp_v0;
    u8 temp_v0_2;
    s8 temp_v0_4;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f2_5;
    f32 temp_f0_3;
    f32 temp_f0_4;

    *(f32 *)(obj + 0x20) = *(f32 *)(obj + 0x20) - ((1.0f - *(f32 *)(st + 0x594)) * (controlchr_gravity * arg2));
    temp_v0 = st[0x568];
    *(f32 *)(st + 0x74) = *(f32 *)(obj + 0x20);
    if (temp_v0 != 2 && temp_v0 != 0xA) {
        temp_f2 = *(f32 *)(st + 0x50);
        if (temp_f2 < 0.0f) {
            var_f0 = -temp_f2 - D_overlay_16_0100806C;
            if (var_f0 < 0.0f) {
                var_f0 = 0.0f;
            }
            if (D_overlay_16_01008070 < var_f0) {
                var_f0 = D_overlay_16_01008070;
            }
            var_f0_2 = var_f0 * 35.0f;
        } else {
            var_f0_2 = 0.0f;
        }
        *(f32 *)(st + 0x4) = *(f32 *)(st + 0x4) + (controlchr_gravity * (temp_f2 / (4.0f - var_f0_2)) * arg2);
    }
    *(f32 *)(st + 0x8) = 0.0f;
    *(s16 *)(obj + 0x0) = *(s16 *)(st + 0x11C);
    temp_v0_2 = st[0x568];
    if (temp_v0_2 == 4 || (temp_v0_2 == 3 && st[0x14A] != 0)) {
        var_a2 = *(s16 *)(st + 0x128);
    } else {
        var_a2 = *(s16 *)(st + 0x11C);
    }
    var_a0 = var_a2;
    if (st[0x13E] != 0) {
        var_a2 = *(s16 *)(st + 0x13C);
        var_a0 = var_a2;
    }
    sp3C = Sinf(var_a0);
    temp_f0_2 = Cosf((s32)var_a2);
    if (st[0x568] != 0xC) {
        *(f32 *)(obj + 0x1C) = *(f32 *)(st + 0x4) * sp3C;
        *(f32 *)(obj + 0x24) = *(f32 *)(st + 0x4) * temp_f0_2;
    }
    var_a2_2 = *(s16 *)(st + 0x11C);
    var_a0_2 = var_a2_2;
    if (st[0x13E] != 0) {
        var_a2_2 = *(s16 *)(st + 0x13C);
        var_a0_2 = var_a2_2;
    }
    *(f32 *)(obj + 0x1C) = *(f32 *)(obj + 0x1C) + (*(f32 *)(st + 0x10) * Cosf((s32)var_a0_2));
    var_f12 = *(f32 *)(obj + 0x1C);
    *(f32 *)(obj + 0x24) = *(f32 *)(obj + 0x24) - (*(f32 *)(st + 0x10) * Sinf(var_a2_2));
    var_f14 = *(f32 *)(obj + 0x24);
    if (st[0x149] != 0) {
        var_f12 += *(f32 *)(st + 0x6C);
        var_f14 += *(f32 *)(st + 0x70);
    }
    if (disablejoy == 1) {
        var_f12 *= D_overlay_16_01008074;
        temp_f2_2 = *(f32 *)(st + 0x4);
        var_f14 *= D_overlay_16_01008074;
        if (temp_f2_2 < -0.5f || temp_f2_2 > 0.5f) {
            *(f32 *)(st + 0x4) = temp_f2_2 * D_overlay_16_01008074;
        } else {
            *(f32 *)(st + 0x4) = 0.0f;
        }
        temp_f2_3 = *(f32 *)(st + 0x8);
        if (temp_f2_3 < -0.5f || temp_f2_3 > 0.5f) {
            *(f32 *)(st + 0x8) = temp_f2_3 * D_overlay_16_01008074;
        } else {
            *(f32 *)(st + 0x8) = 0.0f;
        }
    }
    if (st[0x10D] != 0) {
        sidekickpadMovePlayer(var_f12, var_f14, obj, st, (s32)arg2);
    }
    if (st[0x19F] != 0) {
        transformerMovePlayer(var_f12, var_f14, obj, st, (s32)arg2);
    }
    objMoveXYZ(var_f12, var_f14, obj, (var_f12 * arg2) + *(f32 *)(st + 0x354), *(f32 *)(obj + 0x20) * arg2,
               (var_f14 * arg2) + *(f32 *)(st + 0x35C));
    temp_f0_2 = 1.0f / arg2;
    temp_f12 = (*(f32 *)(obj + 0xC) - *(f32 *)(st + 0x3C)) * temp_f0_2;
    temp_f14 = (*(f32 *)(obj + 0x14) - *(f32 *)(st + 0x44)) * temp_f0_2;
    groundHit = controlGroundHits(temp_f12, temp_f14, obj, st, arg2);
    *(f32 *)(obj + 0x1C) = (*(f32 *)(obj + 0xC) - *(f32 *)(st + 0x3C)) * temp_f0_2;
    *(f32 *)(obj + 0x20) = (*(f32 *)(obj + 0x10) - *(f32 *)(st + 0x40)) * temp_f0_2;
    *(f32 *)(obj + 0x24) = (*(f32 *)(obj + 0x14) - *(f32 *)(st + 0x44)) * temp_f0_2;
    if ((st[0x534] != 0 && *(f32 *)(obj + 0x20) > 0.0f) || (st[0x510] != 0 && st[0x532] != 0)) {
        *(f32 *)(obj + 0x20) = 0.0f;
    }
    if (st[0x13E] != 0) {
        var_a2_3 = *(s16 *)(st + 0x13C);
    } else {
        var_a2_3 = *(s16 *)(st + 0x11C);
    }
    rot[0] = -var_a2_3;
    rot[1] = -*(s16 *)(obj + 0x2);
    rot[2] = -*(s16 *)(obj + 0x4);
    vec[0] = temp_f12;
    vec[1] = 0.0f;
    vec[2] = temp_f14;
    mathOneFloatYPR(temp_f12, temp_f14, rot, vec, var_a2_3);
    temp_v0_4 = st[0x149];
    if (temp_v0_4 != 0) {
        st[0x149] = (s8)(temp_v0_4 - (s32)arg2);
        if (*(s8 *)(st + 0x149) < 0) {
            st[0x149] = 0;
        }
    } else {
        temp_f2_4 = *(f32 *)(st + 0x4);
        temp_f0_3 = temp_f2_4 - vec[2];
        if (temp_f0_3 > 0.5f) {
            *(f32 *)(st + 0x4) = temp_f2_4 - (temp_f0_3 - 0.5f);
        }
        if (temp_f0_3 < -0.5f) {
            *(f32 *)(st + 0x4) = *(f32 *)(st + 0x4) - (temp_f0_3 + 0.5f);
        }
        temp_f2_5 = *(f32 *)(st + 0x8);
        temp_f0_4 = temp_f2_5 - vec[0];
        if (temp_f0_4 > 0.5f) {
            *(f32 *)(st + 0x8) = temp_f2_5 - (temp_f0_4 - 0.5f);
        }
        if (temp_f0_4 < -0.5f) {
            *(f32 *)(st + 0x8) = *(f32 *)(st + 0x8) - (temp_f0_4 + 0.5f);
        }
    }
    if (groundHit != 0) {
        if (*(f32 *)(st + 0x4) < -2.0f) {
            *(f32 *)(st + 0x4) = -2.0f;
        }
        if (*(f32 *)(st + 0x4) > 2.0f) {
            *(f32 *)(st + 0x4) = 2.0f;
        }
        if (*(f32 *)(st + 0x8) < -2.0f) {
            *(f32 *)(st + 0x8) = -2.0f;
        }
        if (*(f32 *)(st + 0x8) > 2.0f) {
            *(f32 *)(st + 0x8) = 2.0f;
        }
        if (*(f32 *)(st + 0x10) < -1.75f) {
            *(f32 *)(st + 0x10) = -1.75f;
        }
        if (*(f32 *)(st + 0x10) > 1.75f) {
            *(f32 *)(st + 0x10) = 1.75f;
        }
        st[0x199] = 1;
        return;
    }
    st[0x199] = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o16/overlay_16/func_overlay_16_01005BB8_1F23BD0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_16_01006290_1F242A8(void *arg0, void *arg1, s32 arg2) {
    u8 *obj = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    s16 var_s1;
    s16 var_s1_2;
    s16 var_s1_3;
    s16 var_a1;
    s16 var_a1_2;
    s16 var_a0;
    s32 v;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s16 temp_v0_3s;
    s16 temp_v1_2;
    s16 temp_v0;
    s16 temp_v1;
    s16 temp_a1;
    f32 var_f0;
    f32 var_f0_2;

    v = st[0x568];
    if (v != 0xA) {
        var_s1 = 0;
        if (v != 2) {
            var_s1 = (s16)(*(s16 *)(st + 0x1C8) - *(s16 *)(obj + 0x2));
            if (var_s1 < -0x2AAA) {
                var_s1 = -0x2AAA;
            }
            if (var_s1 > 0x2AAA) {
                var_s1 = 0x2AAA;
            }
            var_a1 = (s16)(*(s16 *)(st + 0x1C6) - *(s16 *)(obj + 0x0));
            if (var_a1 < -0x1000) {
                var_a1 = -0x1000;
            }
            if (var_a1 > 0x1000) {
                var_a1 = 0x1000;
            }
        } else {
            var_a1 = 0;
        }
    } else {
        var_s1 = 0;
        var_a1 = 0;
    }
    var_a0 = 0;
    if (arg2 > 0) {
        do {
            temp_v0 = *(s16 *)(st + 0x1D0);
            temp_v1 = *(s16 *)(st + 0x1CE);
            var_a0 += 1;
            *(s16 *)(st + 0x1D0) = (s16)(temp_v0 + ((s32)(var_s1 - temp_v0) >> 2));
            *(s16 *)(st + 0x1CE) = (s16)(temp_v1 + ((s32)(var_a1 - temp_v1) >> 2));
        } while (var_a0 < arg2);
        v = st[0x568];
    }
    var_s1_2 = 0;
    if (v != 0xA && (s8)st[0x1F5] > 0) {
        s32 remain = (s8)st[0x1F5];
        var_s1_2 = *(s16 *)(st + 0x1DA);
        st[0x1F5] = (u8)(remain - arg2);
        var_f0 = (f32)var_s1_2;
        if (var_f0 < D_overlay_16_01008078) {
            var_s1_2 = -0x38E3;
            var_f0 = (f32)-0x38E3;
        }
        if (D_overlay_16_0100807C < var_f0) {
            var_s1_2 = 0x38E3;
        }
        var_a1_2 = *(s16 *)(st + 0x1D8);
        var_f0_2 = (f32)var_a1_2;
        if (var_f0_2 < D_overlay_16_01008080) {
            var_a1_2 = -0xE38;
            var_f0_2 = (f32)-0xE38;
        }
        if (D_overlay_16_01008084 < var_f0_2) {
            var_a1_2 = 0xE38;
        }
    } else {
        var_a1_2 = 0;
    }
    var_a0 = 0;
    if (arg2 > 0) {
        do {
            temp_v0_3s = *(s16 *)(st + 0x1DE);
            temp_v1_2 = *(s16 *)(st + 0x1DC);
            var_a0 += 1;
            *(s16 *)(st + 0x1DE) = (s16)(temp_v0_3s + ((s32)(var_s1_2 - temp_v0_3s) >> 4));
            *(s16 *)(st + 0x1DC) = (s16)(temp_v1_2 + ((s32)(var_a1_2 - temp_v1_2) >> 4));
        } while (var_a0 < arg2);
    }
    if (st[0x1F4] != 0) {
        s8 temp_v0_4 = (s8)st[0x1F6];
        temp_a1 = *(s16 *)(st + 0x1CE);
        var_s1_3 = *(s16 *)(st + 0x1D0);
        if (temp_v0_4 != 0) {
            var_s1_3 = (s16)(var_s1_3 + (((s32)((s8)st[0x1F7] * mathSin((s16)(temp_v0_4 << 0xC), (s8)temp_a1))) >> 8));
        }
        func_overlay_16_01003DB0_1F21DC8(var_s1_3, temp_a1, *(s16 *)(st + 0x1DE), *(s16 *)(st + 0x1DC));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o16/overlay_16/func_overlay_16_01006290_1F242A8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_16_0100650C_1F24524(void *arg0, void *arg1, f32 arg2, s16 arg3, f32 arg4) {
    u8 *obj = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    s32 frames;
    f32 temp_f0;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f2_5;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f0_3;
    s32 temp_f18;
    s32 temp_f6_2;
    s32 var_v1;
    s32 var_at;
    s32 var_a3;
    s16 sp46;
    f32 temp_f2_st;

    frames = (s32)arg4;
    st[0x541] = (u8)(st[0x541] & 0xFFF0);
    if (st[0x2] == 0 || *(f32 *)(st + 0x60) < 45.0f) {
        st[0x568] = 3;
        st[0x58E] = 0;
        *(f32 *)(st + 0x57C) = *(f32 *)(obj + 0x10);
        *(f32 *)(st + 0x594) = 0.0f;
    }
    controlWalkingBack(obj, st, &arg2, arg3, 0x5000, 0x6800, 5.0f, 3.0f);
    if (*(s32 *)((u8 *)controlModeKeys + 0xC) & controlDkeys) {
        st[0x57A] = 0;
        *(f32 *)(st + 0x57C) = *(f32 *)(obj + 0x10);
        *(f32 *)(obj + 0x20) = *(f32 *)(obj + 0x20) + 12.0f;
        if (*(f32 *)(obj + 0x20) > 12.0f) {
            *(f32 *)(obj + 0x20) = 12.0f;
        }
        func_overlay_16_01004F78_1F22F90(obj, st, 6, 0);
        charSpeak(obj, 0);
    } else {
        *(f32 *)(obj + 0x20) = Powerf(D_overlay_16_01008088, frames) * *(f32 *)(obj + 0x20);
    }
    if (st[0x569] == 0) {
        arg2 = -arg2;
    } else {
        arg3 = (s16)(arg3 + 0x8000);
    }
    if (st[0x568] == 4) {
        st[0x19E] = 1;
        temp_f0 = *(f32 *)(st + 0x60) * D_overlay_16_0100808C;
        *(f32 *)(st + 0x594) = temp_f0;
        if (temp_f0 > 1.5f) {
            *(f32 *)(st + 0x594) = 1.5f;
        }
    }
    var_f0 = *(f32 *)(st + 0x4);
    if (var_f0 < 0.0f) {
        var_f0 = -var_f0;
    }
    temp_f18 = (s32)var_f0;
    temp_f2 = D_overlay_16_01007DDC[temp_f18];
    sp46 = *(s16 *)(st + 0x11C);
    *(s16 *)(st + 0x11C) = dAngle(*(s16 *)(st + 0x11C), arg3,
                                  1.0f - Powerf(1.0f - (((D_overlay_16_01007DDC[temp_f18 + 1] - temp_f2) * (var_f0 - (f32)temp_f18)) + temp_f2), frames));
    temp_f2_2 = *(f32 *)(st + 0x4);
    *(f32 *)(st + 0x4) = ((1.0f - Powerf(D_overlay_16_01008090, frames)) * (arg2 - temp_f2_2)) + temp_f2_2;
    *(f32 *)(st + 0x10) = *(f32 *)(st + 0x10) * Powerf(D_overlay_16_01008094, frames);
    temp_f2_3 = *(f32 *)(st + 0x10);
    if (D_overlay_16_01008098 < temp_f2_3 && temp_f2_3 < D_overlay_16_0100809C) {
        *(f32 *)(st + 0x10) = 0.0f;
    }
    var_f0_2 = *(f32 *)(st + 0x4);
    if (var_f0_2 < 0.0f) {
        var_f0_2 = -var_f0_2;
    }
    temp_f6_2 = (s32)var_f0_2;
    temp_f2_4 = D_overlay_16_01007DFC[temp_f6_2];
    temp_f2_5 = *(f32 *)(st + 0x4);
    *(s16 *)(st + 0x128) = dAngle(*(s16 *)(st + 0x128), *(s16 *)(st + 0x11C),
                                  1.0f - Powerf(1.0f - (temp_f2_4 + ((var_f0_2 - (f32)temp_f6_2) * (D_overlay_16_01007DFC[temp_f6_2 + 1] - temp_f2_4))), frames));
    var_f0_3 = temp_f2_5;
    if (temp_f2_5 < 0.0f) {
        var_f0_3 = -var_f0_3;
    }
    var_a3 = (s32)((f32)(s16)(*(s16 *)(st + 0x11C) - sp46) * 1.5f * var_f0_3);
    if (var_a3 < -0x1000) {
        var_a3 = -0x1000;
    }
    if (var_a3 > 0x1000) {
        var_a3 = 0x1000;
    }
    var_v1 = (s32)(temp_f2_5 * 512.0f);
    if (var_v1 > 0) {
        var_v1 = 0;
    }
    if (var_v1 < -0x2000) {
        var_v1 = -0x2000;
    }
    *(s16 *)(st + 0x12C) = dAngle(*(s16 *)(st + 0x12C), (s16)var_a3, 1.0f - Powerf(D_overlay_16_010080A0, frames));
    *(s16 *)(st + 0x12A) = dAngle(*(s16 *)(st + 0x12A), (s16)var_v1, 1.0f - Powerf(D_overlay_16_010080A4, frames));
    *D_overlay_16_010080D8++ = 4;
    *D_overlay_16_010080D8++ = *(s16 *)(st + 0x12C);
    *D_overlay_16_010080D8++ = 0;
    *D_overlay_16_010080D8++ = *(s16 *)(st + 0x12A);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o16/overlay_16/func_overlay_16_0100650C_1F24524.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_16_01006AEC_1F24B04(void *arg0, void *arg1, s32 arg2, s32 arg3, f32 arg4) {
    u8 *obj = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    s32 frames;
    f32 temp_f0;
    f32 temp_f2;
    f32 ex;
    f32 ey;
    f32 ez;
    u8 *a2;
    u8 *list;
    u8 *ent;
    u8 *hdr;
    u8 setup[0x14];
    u8 temp_v0;
    s8 temp_v0_2;
    u8 *spawned;

    if (numberOfPlayers == 1) {
        mainPauseDisable(0xA);
    }
    *(u8 *)(*(u8 **)(obj + 0x4C) + 0x6) = 0;
    frames = (s32)arg4;
    temp_f0 = Powerf(D_overlay_16_010080A8, frames);
    *(f32 *)(st + 0x4) = *(f32 *)(st + 0x4) * temp_f0;
    temp_f2 = *(f32 *)(st + 0x4);
    if (D_overlay_16_010080AC < temp_f2 && temp_f2 < D_overlay_16_010080B0) {
        *(f32 *)(st + 0x4) = 0.0f;
    }
    *(f32 *)(st + 0x10) = *(f32 *)(st + 0x10) * temp_f0;
    temp_f2 = *(f32 *)(st + 0x10);
    if (D_overlay_16_010080AC < temp_f2 && temp_f2 < D_overlay_16_010080B4) {
        *(f32 *)(st + 0x10) = 0.0f;
    }
    st[0x541] = (u8)(st[0x541] & 0xFFF0);
    if (st[0x2] == 0) {
        *(f32 *)(st + 0x594) = *(f32 *)(st + 0x594) * temp_f0;
    } else {
        *(f32 *)(st + 0x594) = 0.875f;
        *(f32 *)(obj + 0x20) = *(f32 *)(obj + 0x20) * Powerf(D_overlay_16_010080B8, frames);
        temp_v0 = st[0x18A];
        if ((s32)temp_v0 < 0xF0) {
            st[0x18A] = (u8)(temp_v0 + 1);
        }
        temp_v0_2 = (s8)st[0x18B];
        if (frames >= temp_v0_2) {
            a2 = *(u8 **)(*(u8 **)(obj + 0x6C) + obj[0x3A] * 4);
            list = *(u8 **)(a2 + 0x70);
            hdr = *(u8 **)(a2 + 0x0);
            ent = list + mathRnd(0, hdr[0x2F] - 1) * 0xC;
            if (*(f32 *)(ent + 0x4) < *(f32 *)(st + 0x5C)) {
                ex = *(f32 *)(ent + 0x0);
                ey = *(f32 *)(ent + 0x4);
                ez = *(f32 *)(ent + 0x8);
                *(s16 *)(setup + 0x0) = 0xBA;
                setup[0x2] = 0x14;
                setup[0x3] = 0;
                *(s16 *)(setup + 0x4) = (s16)ex;
                *(s16 *)(setup + 0x6) = (s16)ey;
                *(s16 *)(setup + 0x8) = (s16)ez;
                *(s16 *)(setup + 0xA) = mathRnd(-0x8000, 0x7FFF);
                *(f32 *)(setup + 0xC) = (f32)mathRnd(0, 0x23) * D_overlay_16_010080BC;
                *(f32 *)(setup + 0x10) = *(f32 *)(st + 0x5C);
                spawned = objSetupObject((s16 *)setup, 1);
                if (spawned != NULL) {
                    *(s32 *)(spawned + 0x3C) = 0;
                }
            }
            st[0x18B] = (u8)((s8)((s32)st[0x18A] >> 2));
        } else {
            st[0x18B] = (u8)(temp_v0_2 - frames);
        }
    }
    st[0x19C] = 0;
    if (*(f32 *)(obj + 0x28) == 1.0f) {
        controlFrozen(obj, st);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o16/overlay_16/func_overlay_16_01006AEC_1F24B04.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_16_01006E24_1F24E3C(void *arg0, void *arg1, f32 arg2) {
    u8 *obj = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    f32 temp_f0;
    s32 temp_f4;
    s32 temp_lo;
    s32 temp_v1;
    s8 temp_a0;
    s8 temp_a0_2;
    s8 temp_v0;
    s8 var_v0;

    *(f32 *)(st + 0x4) = 0.0f;
    *(f32 *)(st + 0x10) = 0.0f;
    *(f32 *)(st + 0x8) = 0.0f;
    *(f32 *)(obj + 0x1C) = 0.0f;
    temp_f4 = (s32)arg2;
    *(f32 *)(obj + 0x24) = 0.0f;
    var_v0 = (s8)st[0x579];
    if (var_v0 > 0) {
        temp_v1 = var_v0 - temp_f4;
        if (temp_v1 >= 0) {
            st[0x579] = (u8)(var_v0 - temp_f4);
            var_v0 = (s8)st[0x579];
            *(s16 *)(st + 0x11C) = (s16)(*(s16 *)(st + 0x11C) - (*(s16 *)(st + 0x17C) * temp_f4));
        } else {
            temp_lo = *(s16 *)(st + 0x17C) * var_v0;
            st[0x579] = 0;
            var_v0 = (s8)st[0x579];
            *(s16 *)(st + 0x11C) = (s16)(*(s16 *)(st + 0x11C) - temp_lo);
        }
        if (var_v0 == 0) {
            *(f32 *)(obj + 0x20) = 0.0f;
            st[0x194] = 1;
            controlMakeGravity(arg2, st, temp_f4, temp_f4);
            func_overlay_16_01004F78_1F22F90(obj, st, 0x28, 0);
        }
    } else {
        temp_a0 = (s8)st[0x578];
        if (temp_a0 > 0) {
            temp_v0 = (s8)(temp_a0 - temp_f4);
            if (var_v0 == 0) {
                if (temp_v0 >= 0) {
                    st[0x578] = (u8)temp_v0;
                    *(f32 *)(st + 0x4) = *(f32 *)(st + 0x170);
                    *(f32 *)(st + 0x10) = *(f32 *)(st + 0x174);
                } else if (temp_v0 < 0 && temp_a0 > 0) {
                    temp_f0 = (f32)temp_a0;
                    st[0x578] = 0;
                    *(f32 *)(st + 0x4) = (*(f32 *)(st + 0x170) * temp_f0) / arg2;
                    *(f32 *)(st + 0x10) = (*(f32 *)(st + 0x174) * temp_f0) / arg2;
                }
                if ((s8)st[0x578] == 0) {
                    st[0x194] = 0;
                    controlMakeGravity(arg2, st, temp_f4, temp_f4);
                }
            }
        }
    }
    if (*(s32 *)(st + 0x184) == 0) {
        st[0x194] = 0;
        ((void (*)(void *))controlMakeGravity)(st); /* sig mismatch: asm passes only a0 */
        *(f32 *)(st + 0x57C) = *(f32 *)(obj + 0x10);
        func_overlay_16_01004F78_1F22F90(obj, st, 0x18, 0);
        st[0x568] = 3;
        st[0x58E] = 0;
    } else {
        temp_a0_2 = (s8)st[0x578];
        if (temp_a0_2 == 0 && (*(u8 **)(st + 0x360))[5] & st[0x532]) {
            st[0x149] = 8;
            *(f32 *)(st + 0x6C) = 2.0f * Sinf(*(s16 *)(st + 0x11C));
            *(f32 *)(st + 0x70) = 2.0f * Cosf((s32)*(s16 *)(st + 0x11C));
            func_overlay_16_01004F78_1F22F90(obj, st, func_overlay_16_01004E08_1F22E20(st), 0);
            st[0x568] = 0;
            st[0x58E] = 0;
        } else if (temp_a0_2 == 0 && (*(u8 **)(st + 0x360))[6] & st[0x532]) {
            st[0x568] = 8;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o16/overlay_16/func_overlay_16_01006E24_1F24E3C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_16_010070A4_1F250BC(void *arg0, void *arg1, f32 arg2, s16 arg3, f32 arg4) {
    u8 *obj = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    u8 *p360 = *(u8 **)(st + 0x360);
    u8 *cmk = (u8 *)controlModeKeys;
    f32 sp2C;
    f32 sp30;
    f32 sp34;
    f32 temp_f0;
    s8 temp_v0;
    s32 condA;
    s32 condB;
    f32 dot;

    *(f32 *)(st + 0x4) = 0.0f;
    *(f32 *)(st + 0x8) = 0.0f;
    *(f32 *)(st + 0x10) = 0.0f;
    *(f32 *)(obj + 0x1C) = 0.0f;
    *(f32 *)(obj + 0x24) = 0.0f;
    if (p360[5] & st[0x532]) {
        st[0x149] = 8;
        *(f32 *)(st + 0x6C) = 2.0f * Sinf(*(s16 *)(st + 0x11C));
        *(f32 *)(st + 0x70) = 2.0f * Cosf(*(s16 *)(st + 0x11C));
        func_overlay_16_01004F78_1F22F90(obj, st, func_overlay_16_01004E08_1F22E20(st), 0);
        st[0x568] = 0;
    } else {
        if (arg2 == 0.0f) {
            st[0x578] = 1;
        }
        sp2C = Cosf((s32)arg3);
        sp30 = Cosf((s32)*(s16 *)(st + 0x11C));
        sp34 = Sinf(*(s16 *)(st + 0x11C));
        temp_f0 = Sinf(arg3);
        temp_v0 = st[0x578];
        dot = (temp_f0 * sp34) + (sp30 * sp2C);
        condA = ((temp_v0 != 0) && (arg2 > 2.0f) && (D_overlay_16_010080C0 < dot)) ||
                (*(s32 *)(cmk + 0xC) & controlDkeys);
        if (condA) {
            *(f32 *)(obj + 0x20) = (f32)(sqrtf(2.0f * controlchr_gravity * (*(f32 *)(st + 0x178) - *(f32 *)(obj + 0x10))) +
                                         (1.0f + (0.5f * controlchr_gravity * arg4)));
            *(f32 *)(st + 0x4) = -1.0f;
            func_overlay_16_01004F78_1F22F90(obj, st, 0x29, 0);
            st[0x568] = 7;
        } else {
            condB = ((temp_v0 == 0) || !(arg2 > 2.0f) || !(dot < D_overlay_16_010080C4)) &&
                    !(*(s32 *)(cmk + 0x10) & controlDkeys);
            if (!condB || !(p360[6] & st[0x532])) {
                /* block_15 */
                *(f32 *)(st + 0x57C) = *(f32 *)(obj + 0x10);
                func_overlay_16_01004F78_1F22F90(obj, st, 0x18, 0);
                st[0x568] = 3;
                st[0x58E] = 0;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o16/overlay_16/func_overlay_16_010070A4_1F250BC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_16_01007344_1F2535C(void *arg0, void *arg1, s32 arg2) {
    u8 *obj = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    if (st[0x532] & (*(u8 **)(st + 0x360))[5]) {
        func_overlay_16_01004F78_1F22F90(obj, st, func_overlay_16_01004E08_1F22E20(st), 0);
        st[0x568] = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o16/overlay_16/func_overlay_16_01007344_1F2535C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_16_010073A8_1F253C0(void *arg0, void *arg1, s32 arg2, s32 arg3, f32 arg4) {
    u8 *obj = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    s32 temp_f4;
    s32 temp_a0;
    s32 temp_lo;
    s8 temp_v0;
    f32 temp_f0;
    u8 *p360;
    u8 temp_v1;

    temp_f4 = (s32)arg4;
    *(f32 *)(st + 0x4) = 0.0f;
    *(f32 *)(st + 0x8) = 0.0f;
    *(f32 *)(st + 0x10) = 0.0f;
    *(f32 *)(obj + 0x1C) = 0.0f;
    *(f32 *)(obj + 0x24) = 0.0f;
    if (obj[0x3B] != 0x28) {
        func_overlay_16_01004F78_1F22F90(obj, st, 0x28, 0);
    }
    temp_v0 = (s8)st[0x578];
    temp_a0 = temp_v0 - temp_f4;
    if (temp_v0 != 0) {
        if (temp_a0 >= 0) {
            *(f32 *)(obj + 0x1C) = *(f32 *)(st + 0x170);
            *(f32 *)(obj + 0x24) = *(f32 *)(st + 0x174);
            st[0x578] = (u8)((s8)st[0x578] - temp_f4);
            *(s16 *)(st + 0x11C) = (s16)(*(s16 *)(st + 0x11C) - (*(s16 *)(st + 0x17C) * temp_f4));
        } else if (temp_a0 < 0 && temp_v0 > 0) {
            temp_f0 = (f32)temp_v0;
            *(f32 *)(obj + 0x1C) = (*(f32 *)(st + 0x170) * temp_f0) / arg4;
            *(f32 *)(obj + 0x24) = (*(f32 *)(st + 0x174) * temp_f0) / arg4;
            temp_lo = *(s16 *)(st + 0x17C) * (s8)st[0x578];
            st[0x578] = 0;
            *(s16 *)(st + 0x11C) = (s16)(*(s16 *)(st + 0x11C) - temp_lo);
        }
    } else {
        p360 = *(u8 **)(st + 0x360);
        temp_v1 = st[0x532];
        if (p360[6] & temp_v1) {
            func_overlay_16_01004F78_1F22F90(obj, st, 0x2A, 0);
            st[0x568] = 8;
            *(f32 *)(st + 0x57C) = *(f32 *)(st + 0x178);
            *(f32 *)(obj + 0x20) = 0.0f;
            st[0x14A] = 0;
            st[0x14B] = 0;
            *(f32 *)(st + 0x594) = 0.0f;
        } else if (p360[5] & temp_v1) {
            st[0x568] = 0;
            func_overlay_16_01004F78_1F22F90(obj, st, func_overlay_16_01004E08_1F22E20(st), 0);
        } else if (*(f32 *)(st + 0x4AC) < *(f32 *)(st + 0x178) || st[0x533] != 0) {
            *(f32 *)(st + 0x57C) = *(f32 *)(obj + 0x10);
            func_overlay_16_01004F78_1F22F90(obj, st, 0x18, 0);
            st[0x568] = 3;
            st[0x58E] = 0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o16/overlay_16/func_overlay_16_010073A8_1F253C0.s")
#endif
