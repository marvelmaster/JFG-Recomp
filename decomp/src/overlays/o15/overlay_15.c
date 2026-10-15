#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
/* decomp: batch 72 externs */
extern u8 D_overlay_15_00F0807C[];
extern u8 D_overlay_15_00F08130[];
extern u8 D_overlay_15_00F0823C[];
extern u8 D_overlay_15_00F08644[];
extern u8 D_overlay_15_00F08674[];
extern u8 D_overlay_15_00F086A4[];
extern u8 D_overlay_15_00F086C4[];
extern f32 D_overlay_15_00F08820;
extern f32 D_overlay_15_00F08824;
extern f32 D_overlay_15_00F08828;
extern f32 D_overlay_15_00F0882C;
extern f32 D_overlay_15_00F08830;
extern f32 D_overlay_15_00F08834;
extern f32 D_overlay_15_00F08838;
extern f32 D_overlay_15_00F0883C;
extern f32 D_overlay_15_00F08840;
extern f32 D_overlay_15_00F08844;
extern f32 D_overlay_15_00F0891C;
extern f32 D_overlay_15_00F08920;
extern f32 D_overlay_15_00F08924;
extern f32 D_overlay_15_00F08928;
extern f32 D_overlay_15_00F0892C;
extern f32 D_overlay_15_00F08930;
extern f32 D_overlay_15_00F08934;
extern f32 D_overlay_15_00F08938;
extern f32 D_overlay_15_00F0893C;
extern f32 D_overlay_15_00F08940;
extern f32 D_overlay_15_00F08944;
extern f32 D_overlay_15_00F08948;
extern f32 D_overlay_15_00F0894C;
extern f32 D_overlay_15_00F08950;
extern f32 D_overlay_15_00F08954;
extern f32 D_overlay_15_00F08958;
extern f32 D_overlay_15_00F0895C;
extern f32 D_overlay_15_00F08960;
extern f32 D_overlay_15_00F08964;
extern f32 D_overlay_15_00F08968;
extern f32 D_overlay_15_00F0896C;
extern f32 D_overlay_15_00F08970;
extern f32 D_overlay_15_00F08974;
extern f32 D_overlay_15_00F08978;
extern f32 D_overlay_15_00F0897C;
extern f32 D_overlay_15_00F08980;
extern f32 D_overlay_15_00F08984;
extern f32 D_overlay_15_00F08988;
extern f32 D_overlay_15_00F0898C;
extern f32 D_overlay_15_00F08990;
extern f32 D_overlay_15_00F08994;
extern f32 D_overlay_15_00F08998;
extern f32 D_overlay_15_00F0899C;
extern f32 D_overlay_15_00F089A0;
extern f32 D_overlay_15_00F089A4;
extern f32 D_overlay_15_00F089A8;
extern f32 D_overlay_15_00F089AC;
extern f32 D_overlay_15_00F089B0;
extern s16 D_overlay_15_00F089CE;
extern s32 D_overlay_15_00F089D0;
extern f32 D_overlay_15_00F089D8;
extern f32 D_overlay_15_00F089DC;
extern f32 D_overlay_15_00F089E0;
extern f32 D_overlay_15_00F089E4;
void objMoveXYZ(u8 *obj, f32 dx, f32 dy, f32 dz);
s32 controlPlayerGunWeight(u8 *a0, s32 a1);
void objAnimSetMove(u8 *obj, u8 move, s32 a, u8 b);
void controlSetTransition(u8 *a0, u8 *a1, void *a2, s32 a3);
void controlMakeGravity(f32 a, u8 *b, s32 c, s32 d);
void mainPauseDisable(s32 n);
extern u8 multiPlayerGame;
extern u8 numberOfPlayers;
void hitPlayerKilledPlayer(u8 *a, u8 *b, s32 *c, s8 d);
void fxNightVisionSkip(void);
void frontFlashScreen(s32 a, s32 b, s32 c);
f32 controlMakeV(f32 a, f32 b, u8 *c, void *d, f32 e);
s32 controlGroundHits(f32 a, f32 b, void *c, void *d, f32 e);
void mathOneFloatYPR(f32 a, f32 b, s16 *c, f32 *d, s16 e);
void sidekickpadMovePlayer(f32 a, f32 b, void *c, void *d, s32 e);
void transformerMovePlayer(f32 a, f32 b, void *c, void *d, s32 e);
void controlFrozen(void *a, void *b);
void charAnimSoundTick(u8 *obj, f32 a, f32 b);
void objAnimDframe(u8 *obj, f32 a, f32 b);
void func_overlay_15_00F07724_1F1B0A4(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3);
extern u8 D_overlay_15_00F08338[];
extern f32 D_overlay_15_00F0873C;
extern f32 D_overlay_15_00F08740;
extern f32 D_overlay_15_00F08744;
extern f32 D_overlay_15_00F08748;
extern f32 D_overlay_15_00F0874C;
extern f32 D_overlay_15_00F08750;
extern f32 D_overlay_15_00F0877C;
extern f32 D_overlay_15_00F08778;
extern f32 D_overlay_15_00F08780;
extern f32 D_overlay_15_00F08784;
extern f32 D_overlay_15_00F08788;
extern f32 D_overlay_15_00F0878C;
extern f32 D_overlay_15_00F08790;
extern f32 D_overlay_15_00F08794;
extern f32 D_overlay_15_00F08798;
extern f32 D_overlay_15_00F0879C;
extern f32 D_overlay_15_00F087A0;
extern f32 D_overlay_15_00F087A4;
extern f32 D_overlay_15_00F087A8;
extern f32 D_overlay_15_00F087AC;
extern f32 D_overlay_15_00F087B0;
extern f32 D_overlay_15_00F087B4;
extern f32 D_overlay_15_00F087B8;
extern f32 D_overlay_15_00F087BC;
extern f32 D_overlay_15_00F087C0;
extern f32 D_overlay_15_00F087C4;
extern f32 D_overlay_15_00F087C8;
extern f32 D_overlay_15_00F087CC;
extern f32 D_overlay_15_00F087D0;
extern f32 D_overlay_15_00F087D4;
extern f32 D_overlay_15_00F087D8;
extern f32 D_overlay_15_00F087DC;
extern f32 D_overlay_15_00F087E0;
extern f32 D_overlay_15_00F087E4;
extern f32 D_overlay_15_00F087E8;
extern f32 D_overlay_15_00F087EC;
extern f32 D_overlay_15_00F087F0;
extern f32 D_overlay_15_00F087F4;
extern f32 D_overlay_15_00F087F8;
extern f32 D_overlay_15_00F087FC;
extern f32 D_overlay_15_00F08800;
extern f32 D_overlay_15_00F08804;
extern f32 D_overlay_15_00F08808;
extern f32 D_overlay_15_00F0880C;
extern f32 D_overlay_15_00F08810;
extern f32 D_overlay_15_00F08814;
extern f32 D_overlay_15_00F08818;
extern f32 D_overlay_15_00F0881C;
extern s32 D_overlay_15_00F089C0;
extern s32 D_overlay_15_00F089C4;
extern u8 *D_overlay_15_00F089C8;
extern s16 D_overlay_15_00F089CC;
extern f32 D_overlay_15_00F089D4;
extern void *controlModeKeys;
void amSndPlayXYZ(u16 soundId, f32 x, f32 y, f32 z, u8 arg4, void *soundMask);
void amSndPlay(s32 soundId, void *handlePtr, void *arg2);
void amSndSetVol(s32 soundId, s32 a, s32 b);
void charSpeak(u8 *obj, u8 arg1);
s32 dropletAdd(f32, f32, f32, f32, f32, f32, f32, f32);
void dropletUpdate(s32 id, s32 n);
void mathOneFloatPY(s16 *a, f32 *b);
void partUpdateTriggers(void *obj, s32 arg1);
void *objSetupObject(void *params, s32 arg1);
s32 controlCeiling(f32 x, f32 y, f32 z, f32 r, f32 h);
void controlHalfTurn(u8 *a0, u8 *a1, f32 *a2, s16 *a3, s32 a4, s32 a5, s32 *a6, f32 a7, f32 a8);
void controlWalkingBack(u8 *a0, u8 *a1, f32 *a2, s32 a3, s32 a4, s32 a5, f32 a6, f32 a7);
s16 dAngle(s16 a, s16 b, f32 c);
f32 Powerf(f32 base, s32 n);
f32 Sinf(s16 angle);
s32 mathSin(s16 angle, s32 n);
s32 mathDiffAngle(s32 a, s32 b);
void camSetZoom(s8 n, s32 zoom);
s32 controlGetManualAim(u8 *a0, u8 *a1, s32 a2, s32 a3, s32 a4, s32 a5, s16 *a6, s16 *a7, f32 a8);
s32 frontGetTargetControl(s8 n);
void *mainGetGameCharacter(s8 a, s8 b);
s32 lobbycamInuse(f32 t, void *cam);
s32 staticcamInuse(f32 t, s32 n);
void func_overlay_15_00F04B4C_1F184CC(u8 *a0, u8 *a1, s32 a2, f32 a3);
void func_overlay_15_00F05180_1F18B00(u8 *a0, u8 *a1, s32 a2, s32 a3);
s32 func_overlay_15_00F05020_1F189A0(u8 *a0);
void func_overlay_15_00F04088_1F17A08(s16 a0, s16 a1, s32 a2, s16 a3);
s32 girlCanFire(u8 *arg0, u8 *arg1);

/* girlControl (Vela) externs */
extern u8 weaponTable[];
extern s32 quickWeaponKey[];
extern u8 allweaponsCheat;
extern u8 invulnerabilityCheat;
extern u8 deformedchars;
extern u8 *controlcam;
extern f32 D_overlay_15_00F086F0;
extern f32 D_overlay_15_00F086F4;
extern f32 D_overlay_15_00F086F8;
extern f32 D_overlay_15_00F086FC;
extern f32 D_overlay_15_00F08734;
extern f32 D_overlay_15_00F08738;
extern u8 D_overlay_15_00F08310[];
extern s32 D_overlay_15_00F0832C[];
extern s32 D_overlay_15_00F08614[];
extern s32 D_overlay_15_00F0862C[];
void controlPlatform(u8 *a, u8 *b, f32 c);
void controlAttitude(u8 *a, u8 *b, f32 c);
void controlSquashCheckPrior(u8 *a, u8 *b, s32 c);
void controlSquashCheckPost(u8 *a, u8 *b, s32 c);
void controlReadJoypad(s8 n);
void controlDisableJoypad(s32 n);
void controlFSUvels(s32 a, s32 b, u8 *c, u8 *d);
void controlEmptyPlayersHand(u8 *a);
void controlClearAimlocks(u8 *a);
void controlFadePlayer(u8 *a, s32 b, s32 c);
void controlFireDummyShot(u8 *a, u8 *b);
void controlGrabOK(u8 *a, u8 *b, f32 c, s16 d, f32 e, void *f);
void controlHangOK(u8 *a, u8 *b, f32 c, f32 d, f32 e, void *f);
void controlSelectNextWeapon(u8 *a, u8 *b, s8 c);
void controlSelectPreviousWeapon(u8 *a, u8 *b, s8 c);
s32 controlSelectWeapon(void *a, u8 *b, s32 c);
void controlSetRumble(s8 a, s32 b, s32 c, s32 d, s32 e);
s32 controlThrowWeapon(s32 a);
void controlUpdateBreathing(u8 *a, f32 b);
void controlUpdateJetFlames(u8 *a, u8 *b, s32 c, s32 d, s32 e);
void controlUpdatePlayerAim(u8 *a, u8 *b, s32 c, s32 d, f32 e, f32 f, f32 g, s32 h);
s32 controlUpdateWeapon(u8 *a, u8 *b, f32 c);
void amSndStop(s32 a);
void amTunePlay(s32 a);
void mainPlayerCollected(s8 a, s8 b, s32 c);
s32 mainPlayerHas(s8 a, s8 b, s32 c);
void objAnimSetFrame(u8 *a, s32 b);
void objEnsureNotTargetted(u8 *a);
s32 objMakeGunMtx(u8 *a, void *b, void *c, u8 d, u8 *e, u8 *f, u8 *g, u8 *h);
s32 trackPolyHeight(f32 x, f32 y, u8 *a, s32 b);
void wakeUpdateRipple(u8 *a, s32 b);
void modGenAnimMatrices(void *a, void *b, u8 *c, f32 d, f32 e);
void lightObject(u8 *a, void *b, s32 c, s32 d);
void invincibilityShieldTransform(s32 a, s32 b, s32 c, s32 d);
u8 func_overlay_15_00F01C80_1F15600(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3);
void func_overlay_15_00F01E14_1F15794(u8 *arg0, u8 *arg1, s32 arg2);
void func_overlay_15_00F020B4_1F15A34(u8 *arg0, u8 *arg1, s32 arg2);
void func_overlay_15_00F025FC_1F15F7C(u8 *arg0, u8 *arg1, s32 arg2);
void func_overlay_15_00F02B2C_1F164AC(u8 *arg0, u8 *arg1, f32 arg2, s16 arg3, f32 arg4);
void func_overlay_15_00F03274_1F16BF4(u8 *arg0, u8 *arg1, f32 arg2, s32 arg3, f32 arg4);
void func_overlay_15_00F03564_1F16EE4(u8 *arg0, u8 *arg1, f32 arg2, s16 arg3, f32 arg4);
void func_overlay_15_00F03740_1F170C0(u8 *arg0, u8 *arg1, f32 arg2, s16 arg3, f32 arg4);
void func_overlay_15_00F0418C_1F17B0C(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, f32 arg4);
void func_overlay_15_00F04658_1F17FD8(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, f32 arg4);
void func_overlay_15_00F04A58_1F183D8(s32 arg0, u8 *arg1, s32 arg2);
void func_overlay_15_00F05328_1F18CA8(u8 *arg0, u8 *arg1, f32 arg2, f32 arg3);
void func_overlay_15_00F05ED4_1F19854(u8 *arg0, u8 *arg1, f32 arg2);
void func_overlay_15_00F0663C_1F19FBC(u8 *arg0, u8 *arg1, s32 arg2);
void func_overlay_15_00F068BC_1F1A23C(u8 *arg0, u8 *arg1, f32 arg2);
void func_overlay_15_00F06B3C_1F1A4BC(u8 *arg0, u8 *arg1, f32 arg2, s16 arg3, f32 arg4);
void func_overlay_15_00F06DDC_1F1A75C(u8 *arg0, u8 *arg1, s32 arg2);
void func_overlay_15_00F06E40_1F1A7C0(u8 *arg0);
void func_overlay_15_00F06EBC_1F1A83C(u8 *arg0, u8 *arg1, f32 arg2, s16 arg3, f32 arg4);
void func_overlay_15_00F07890_1F1B210(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, f32 arg4);
void func_overlay_15_00F07BC8_1F1B548(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, f32 arg4);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Vela (girl) main player control. arg0 = object, state = object+0x68 (player state).
// Field names are raw offsets (no jfg-re names used yet).
void girlControl(u8 *arg0, s32 arg1) {
    u8 *state;
    u8 *sp90;
    u8 *wt;
    Game *sp7C;
    u8 *temp_v0_16;
    u8 *temp_s1;
    u8 *temp_a0_3;
    s32 sp84;
    s32 sp80;
    s32 spCC;
    s32 var_a3;
    s32 *var_v1;
    s32 temp_v0_5;
    s32 temp_v0_10;
    s32 temp_v0_14;
    s32 temp_v0_15;
    s32 sp60[6];
    u32 sp48[6];
    s32 *var_v0;
    f32 *var_v1_2;
    u8 *p_dl;
    u8 *sp94;
    s32 var_a0;
    s32 var_t7;
    s32 var_t3;
    s32 var_t5;
    s32 temp_lo;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_4;
    f32 sp3C;
    f32 spC4;
    f32 fspAA;
    s16 spAA;
    s16 spA4[3];
    f32 spB0[3];
    f32 var_f0;
    f32 var_f10;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f0_6;
    f32 temp_f0_7;
    f32 temp_f0_8;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f4;
    f32 temp_f8;
    f32 temp_f18;
    f32 temp_f18_2;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 temp_v0_6;
    s32 temp_v0_9;
    s32 temp_v0_11;
    s32 temp_v0_13;
    s32 temp_a2;
    s32 temp_a1;
    s32 temp_t1;
    s32 temp_t7;
    s32 temp_v1;
    s32 temp_v0;
    s32 temp_v0_7;
    s32 temp_v0_8;
    s32 temp_a0_5;
    s32 var_a0_2;
    s32 temp_s4_dummy;
    f32 vecX;
    s32 *temp_v1_4;

    /* asm: state = obj->0x68; clears of globals D_0 / D_4 / D_E (scratch flags). */
    D_overlay_15_00F089D0 = 0;
    state = *(u8 **)(arg0 + 0x68);
    *(s32 *)(arg0 + 0x84) = 0;
    D_overlay_15_00F089C8 = state + 0x240;
    D_overlay_15_00F089CE = 0;
    sp90 = mainGetGameCharacter((s8)state[0], (s8)state[1]);
    if (state[0x568] != 3) {
        state[0x56A] = 0;
    }
    state[0x19E] = 0;
    *(s16 *)(state + 0x11E) = 0;
    *(s16 *)(state + 0x120) = 0;
    D_overlay_15_00F089C0 = 0;
    D_overlay_15_00F089C4 = 0;
    temp_v0 = state[0x568];
    if ((temp_v0 == 6) || (temp_v0 == 8) || (temp_v0 == 7) || (temp_v0 == 0xC)) {
        *(s32 *)(state + 0x510) = *(s32 *)(state + 0x16C);
    } else {
        *(s32 *)(state + 0x16C) = 0;
    }
    sp3C = (f32) arg1;
    controlPlatform(arg0, state, sp3C);
    controlAttitude(arg0, state, sp3C);
    controlSquashCheckPrior(arg0, state, arg1);
    D_overlay_15_00F089D4 = 0.0625f;
    if (multiPlayerGame != 0) {
        temp_v0_2 = (s8)state[0x189];
        if (temp_v0_2 == 2) {
            D_overlay_15_00F089D4 = D_overlay_15_00F086F0;
        } else if (temp_v0_2 >= 4) {
            D_overlay_15_00F089D4 = D_overlay_15_00F086F4;
        }
    }
    D_overlay_15_00F089CC = (s16) (s8)state[0x577];
    if ((s8)state[0x56B] != 0) {
        controlDisableJoypad(1);
        state[0x56B] = (s8) ((s8)state[0x56B] - arg1);
        if ((s8)state[0x56B] < 0) {
            state[0x56B] = 0;
        }
    }
    if ((s8)state[0x577] != 0) {
        controlDisableJoypad(1);
        state[0x577] = (s8) ((s8)state[0x577] - arg1);
        if ((s8)state[0x577] < 0) {
            state[0x577] = 0;
        }
    }
    if ((state[0x1F9] != 0) || (state[0x1FA] != 0) || ((s8)state[0x186] != 0) || (state[0x198] != 0) || (state[0x5EE] != 0) || (state[0x568] == 0xA) || (*(s32 *)(state + 0x5C0) != 0)) {
        controlDisableJoypad(1);
    }
    if ((state[0x19F] != 0) || (state[0x10D] != 0)) {
        controlDisableJoypad(1);
        if (arg0[0x3B] != 0x2F) {
            func_overlay_15_00F05180_1F18B00(arg0, state, 0x2F, 0);
        }
    }
    if ((s32) state[0x1FA] >= 2) {
        state[0x1FA] = 0;
    }
    if ((s32) state[0x198] >= 2) {
        state[0x198] = 0;
    }
    if (state[0x10D] == 4) {
        state[0x10D] = 0;
        *(f32 *)(state + 0x594) = 0.0f;
    }
    controlReadJoypad((s8) state[0]);
    /* asm: single-arg call with a0 = state; f12/a1-a3 not set in this block */
    ((void (*)(u8 *))controlMakeGravity)(state); /* sig mismatch */
    if (*(f32 *)(arg0 + 0x1C) < -20.0f) {
        *(f32 *)(arg0 + 0x1C) = -20.0f;
    }
    if (*(f32 *)(arg0 + 0x1C) > 20.0f) {
        *(f32 *)(arg0 + 0x1C) = 20.0f;
    }
    if (*(f32 *)(arg0 + 0x20) < -20.0f) {
        *(f32 *)(arg0 + 0x20) = -20.0f;
    }
    if (*(f32 *)(arg0 + 0x20) > 15.0f) {
        *(f32 *)(arg0 + 0x20) = 15.0f;
    }
    if (*(f32 *)(arg0 + 0x24) < -20.0f) {
        *(f32 *)(arg0 + 0x24) = -20.0f;
    }
    if (*(f32 *)(arg0 + 0x24) > 20.0f) {
        *(f32 *)(arg0 + 0x24) = 20.0f;
    }
    if (*(f32 *)(state + 0x4) < -20.0f) {
        *(f32 *)(state + 0x4) = -20.0f;
    }
    if (*(f32 *)(state + 0x4) > 20.0f) {
        *(f32 *)(state + 0x4) = 20.0f;
    }
    if (*(f32 *)(state + 0x8) < -20.0f) {
        *(f32 *)(state + 0x8) = -20.0f;
    }
    if (*(f32 *)(state + 0x8) > 20.0f) {
        *(f32 *)(state + 0x8) = 20.0f;
    }
    controlFSUvels(0x41A00000, 0x41700000, arg0, state);
    spA4[0] = -*(s16 *)(state + 0x11C);
    spA4[1] = -*(s16 *)(arg0 + 0x2);
    spA4[2] = -*(s16 *)(arg0 + 0x4);
    spB0[2] = 0.0f;
    spB0[0] = 0.0f;
    spB0[1] = -1.0f;
    /* sig mismatch: asm passes (s16 *rot, f32 *vec) only */
    ((void (*)(s16 *, f32 *))mathOneFloatYPR)(spA4, spB0);
    *(f32 *)(state + 0x54) = spB0[0];
    *(f32 *)(state + 0x58) = spB0[1];
    *(f32 *)(state + 0x50) = spB0[2];
    temp_f0_2 = sqrtf((f32) ((controlXjoy * controlXjoy) + (controlYjoy * controlYjoy)));
    spC4 = temp_f0_2;
    if (spC4 > 65.0f) {
        spC4 = 65.0f;
    }
    temp_f4 = spC4 * D_overlay_15_00F089D4;
    spC4 = temp_f4;
    if (temp_f4 != 0.0f) {
        spAA = Arctanf((f32) controlXjoy, (f32) -controlYjoy) - *(s16 *)controlcam;
    } else {
        spAA = *(s16 *)(state + 0x11C);
    }
    temp_v0_3 = state[0x568];
    if (((temp_v0_3 == 0) || (temp_v0_3 == 5) || (temp_v0_3 == 0xB)) && !((*(u8 **)(state + 0x360))[5] & state[0x532]) && (state[0x10D] == 0) && (state[0x19F] == 0)) {
        state[0x185] = (s8) (state[0x185] + arg1);
        if ((s8)state[0x185] >= 0x10) {
            *(f32 *)(state + 0x57C) = (f32) *(s32 *)(arg0 + 0x10);
            func_overlay_15_00F05180_1F18B00(arg0, state, 0x19, 0);
            temp_t7 = state[0x568];
            state[0x568] = 3;
            state[0x58E] = 0;
            state[0x56A] = temp_t7;
        }
    } else if (((temp_v0_3 == 2) || (temp_v0_3 == 1)) && ((((*(u8 **)(state + 0x360))[5] & state[0x532]) == 0)) && !((*(u8 **)(state + 0x360))[6] & state[0x532]) && !((*(u8 **)(state + 0x360))[7] & state[0x532])) {
        state[0x185] = (s8) (state[0x185] + arg1);
        if ((s8)state[0x185] >= 0x10) {
            *(f32 *)(state + 0x57C) = (f32) *(s32 *)(arg0 + 0x10);
            func_overlay_15_00F05180_1F18B00(arg0, state, 0x19, 0);
            temp_t1 = state[0x568];
            state[0x568] = 3;
            state[0x58E] = 0;
            state[0x56A] = temp_t1;
        }
    } else {
        state[0x185] = 0;
    }
    if ((((*(u8 **)(state + 0x360))[5] & state[0x532]) && (state[0x568] != 3)) || (state[0x568] == 4)) {
        *(f32 *)(state + 0x57C) = (f32) *(s32 *)(arg0 + 0x10);
    }
    /* weapon table entry (0x30 bytes) for the current character */
    wt = weaponTable + sp90[0x70] * 0x30;
    if ((state[0x568] != 5) && (state[0x568] != 0xB) && (state[0x568] != 0xA)) {
        controlUpdatePlayerAim(arg0, state, *(s32 *)(wt + 0xC), *(s32 *)(wt + 0x14), *(f32 *)(wt + 0x18), *(f32 *)(wt + 0x1C), *(f32 *)(wt + 0x20), arg1);
    } else {
        if (state[0x1F4] != 0) {
            state[0x1F8] = (s8) ((s8)state[0x1F8] - arg1);
            if ((s8)state[0x1F8] < 0) {
                state[0x1F8] = 0;
            }
        }
        state[0x1F4] = 1;
    }
    if (state[0x568] != 0xA) {
        controlFadePlayer(state, 0, arg1);
    }
    func_overlay_15_00F06E40_1F1A7C0(state);
    if ((state[0x568] != 4) || (arg0[0x3B] != 0x2D)) {
        temp_f2 = *(f32 *)(state + 0x138);
        var_f10 = ((1.0f - Powerf(D_overlay_15_00F086F8, arg1)) * (0.0f - temp_f2)) + temp_f2;
    } else {
        temp_f2_2 = *(f32 *)(state + 0x138);
        var_f10 = ((1.0f - Powerf(D_overlay_15_00F086FC, arg1)) * (1.0f - temp_f2_2)) + temp_f2_2;
    }
    *(f32 *)(state + 0x138) = var_f10;
    spCC = 0;
    temp_v0_5 = trackPolyHeight(*(f32 *)(arg0 + 0xC), *(f32 *)(arg0 + 0x14), state + 0x5C, 0x80002000);
    if ((temp_v0_5 & 0x80000000) && (*(f32 *)(arg0 + 0x10) < *(f32 *)(state + 0x5C))) {
        state[0x5EE] = 1;
    }
    if ((temp_v0_5 & 0x2000) && ((temp_f0_3 = *(f32 *)(state + 0x5C)), (*(f32 *)(arg0 + 0x10) < temp_f0_3))) {
        state[0x2] = 1;
        *(f32 *)(state + 0x60) = (f32) (temp_f0_3 - *(f32 *)(arg0 + 0x10));
        if ((state[0x3] != 1) && (*(f32 *)(state + 0x74) < 0.0f)) {
            func_overlay_15_00F020B4_1F15A34(arg0, state, arg1);
        }
        if (D_overlay_15_00F089DC < *(f32 *)(state + 0x60)) {
            spCC = 1;
        }
    } else {
        state[0x2] = 0;
        *(f32 *)(state + 0x60) = 0.0f;
    }
    temp_v0_6 = state[0x568];
    if ((((s32) temp_v0_6 < 4) || (temp_v0_6 == 0xB) || (temp_v0_6 == 5)) && (spCC != 0)) {
        temp_f0_4 = *(f32 *)(state + 0x4);
        state[0x568] = 4;
        *(s16 *)(state + 0x12A) = 0;
        *(s16 *)(state + 0x12C) = 0;
        *(u8 *)(state + 0x540) = (u8) (state[0x540] & 0xFF7F);
        state[0x53D] = 0;
        state[0x538] = 0;
        *(s16 *)(state + 0x128) = *(s16 *)(state + 0x11C);
        if ((temp_f0_4 > -0.5f) && (temp_f0_4 < 0.5f)) {
            func_overlay_15_00F05180_1F18B00(arg0, state, 0x2C, 0);
        } else {
            func_overlay_15_00F05180_1F18B00(arg0, state, 0x2D, 0);
        }
    }
    temp_v1_4 = (s32 *)(*(u8 **)(arg0 + 0x4C));
    if ((*(s16 *)((u8 *)temp_v1_4 + 0x6) < 0x100) && (state[0x568] != 0xA)) {
        if (invulnerabilityCheat != 0) {
            *(s16 *)((u8 *)temp_v1_4 + 0x6) = 0x2200;
        } else {
            *(s16 *)((u8 *)temp_v1_4 + 0x6) = 0;
            if (multiPlayerGame == 0) {
                amTunePlay(0x38);
            } else {
                objEnsureNotTargetted(arg0);
            }
            state[0x568] = 0xA;
            controlKeys = 0;
            controlDkeys = 0;
            state[0x53D] = 0;
            controlEmptyPlayersHand(arg0);
            controlClearAimlocks(state);
            state[0x194] = 0;
            /* asm: single-arg call with a0 = state; other argument registers not set */
            ((void (*)(u8 *))controlMakeGravity)(state); /* sig mismatch */
            func_overlay_15_00F05180_1F18B00(arg0, state, 0x18, 0);
        }
    }
    if ((state[0x568] != 0) && (state[0x568] != 2)) {
        state[0x13E] = 0;
        if (state[0x568] != 1) {
            state[0x576] = 0;
        }
    }
    controlUpdateBreathing(state, sp3C);
    temp_v0_7 = state[0x568];
    switch (temp_v0_7) {                            /* switch 1 */
    case 0:
        func_overlay_15_00F02B2C_1F164AC(arg0, state, spC4, spAA, sp3C);
        break;
    case 1:
        func_overlay_15_00F03274_1F16BF4(arg0, state, spC4, spAA, sp3C);
        break;
    case 2:
        func_overlay_15_00F03564_1F16EE4(arg0, state, spC4, spAA, sp3C);
        break;
    case 3:
        func_overlay_15_00F03740_1F170C0(arg0, state, spC4, spAA, sp3C);
        break;
    case 5:
        func_overlay_15_00F0418C_1F17B0C(arg0, state, *(s32 *)&spC4, spAA, sp3C);
        break;
    case 6:
        func_overlay_15_00F068BC_1F1A23C(arg0, state, sp3C);
        break;
    case 8:
        func_overlay_15_00F06B3C_1F1A4BC(arg0, state, spC4, spAA, sp3C);
        break;
    case 7:
        func_overlay_15_00F06DDC_1F1A75C(arg0, state, *(s32 *)&sp3C);
        break;
    case 4:
        func_overlay_15_00F06EBC_1F1A83C(arg0, state, spC4, spAA, sp3C);
        break;
    case 10:
        fspAA = (f32) spAA;
        func_overlay_15_00F07890_1F1B210(arg0, state, *(s32 *)&spC4, *(s32 *)&fspAA, sp3C);
        break;
    case 11:
        func_overlay_15_00F04658_1F17FD8(arg0, state, *(s32 *)&spC4, spAA, sp3C);
        break;
    case 12:
        func_overlay_15_00F07BC8_1F1B548(arg0, state, *(s32 *)&spC4, spAA, sp3C);
        break;
    }
    if ((state[0x568] != 3) && (state[0x14A] != 0)) {
        if ((state[0x568] != 0xA) && (state[0x568] != 4) && ((s8)state[0x14B] <= 0)) {
            *(f32 *)(state + 0x594) = 0.0f;
        }
        state[0x14A] = 0;
    }
    if (state[0x568] == 4) {
        state[0x53C] = 1;
    } else if (state[0x568] != 3) {
        state[0x53C] = 0;
    }
    temp_v0_8 = (s8)state[0x1F6];
    if (temp_v0_8 != 0) {
        state[0x1F6] = (s8) (temp_v0_8 - arg1);
        if ((s8)state[0x1F6] < 0) {
            state[0x1F6] = 0;
        }
    }
    if (allweaponsCheat != 0) {
        sp90[0x6F] = 0xF;
        *(u16 *)(sp90 + 0xA) = 0x7FFF;
    }
    if ((*(u16 *)(sp90 + 0xA) & 0x20) && (mainPlayerHas((s8) state[0], state[1], 0xA) == 0)) {
        mainPlayerCollected((s8) state[0], state[1], 0xA);
    }
    state[0x540] = (u8) (state[0x540] & 0xFFCF);
    if ((s32) sp90[0x6F] >= 2) {
        temp_v0_9 = sp90[0x70];
        sp84 = (s32) temp_v0_9;
        temp_a2 = (s8)state[0x585];
        if ((temp_v0_9 != temp_a2) && (disablejoy == 0)) {
            controlSelectWeapon(arg0, state, temp_a2);
        } else if (*(s32 *)((u8 *) controlModeKeys + 0x4) & controlDkeys) {
            controlSelectNextWeapon(arg0, state, temp_a2);
        } else if (*(s32 *)((u8 *) controlModeKeys + 0x8) & controlDkeys) {
            controlSelectPreviousWeapon(arg0, state, temp_a2);
        } else {
            sp80 = 0;
            var_a3 = sp80;
            sp7C = mainGetGame();
            var_v1 = &quickWeaponKey[var_a3];
loop_170:
            if (*var_v1 & controlDkeys) {
                sp80 = var_a3;
                temp_v0_10 = controlSelectWeapon(arg0, state, (s8) ((u8 *)sp7C)[0x534 + var_a3]);
                if (temp_v0_10 == 0) {
                    goto block_174;
                }
            } else {
block_174:
                var_a3 += 1;
                var_v1 += 1;
                if (var_a3 != 4) {
                    goto loop_170;
                }
            }
        }
        if (sp84 != sp90[0x70]) {
            state[0x538] = 0;
            state[0x53D] = 0;
            state[0x585] = (s8) sp90[0x70];
        }
    }
    func_overlay_15_00F05328_1F18CA8(arg0, state, spC4, sp3C);
    func_overlay_15_00F05ED4_1F19854(arg0, state, sp3C);
    controlSquashCheckPost(arg0, state, arg1);
    if ((s8)state[0x189] < 4) {
        temp_v0_11 = state[0x568];
        if ((temp_v0_11 == 0) || (temp_v0_11 == 5) || (temp_v0_11 == 0xB)) {
            controlHangOK(arg0, state, spC4, (f32) spAA, sp3C, D_overlay_15_00F08310);
        } else if (temp_v0_11 == 3) {
            controlGrabOK(arg0, state, spC4, spAA, sp3C, D_overlay_15_00F08310);
        }
    }
    if (((*(u32 *)(state + 0x520)) & 0x8000) && (state[0x568] != 0xA) && (*(s16 *)(state + 0x5C8) == 0)) {
        amSndPlay(0x214, state + 0xD4, 0); /* asm: a2 not set in this block */
        charSpeak(arg0, 3);
        *(s16 *)(*(u8 **)(arg0 + 0x4C) + 0x6) = (s16) (*(s16 *)(*(u8 **)(arg0 + 0x4C) + 0x6) - 0x900);
        if (*(s16 *)(*(u8 **)(arg0 + 0x4C) + 0x6) >= 0) {
            state[0x568] = 3;
            *(f32 *)(arg0 + 0x20) = 6.0f;
            *(s8 *)(state + 0x14B) = 0x3C;
            state[0x57A] = 0;
            *(f32 *)(state + 0x594) = (f32) D_overlay_15_00F08734;
            *(f32 *)(state + 0x57C) = (f32) *(f32 *)(arg0 + 0x10);
            D_overlay_15_00F089C0 |= 1;
            D_overlay_15_00F089C4 |= 1;
            objAnimSetMove(arg0, 6, 0, 0); /* asm: a3 not set in this block */
        } else {
            *(s16 *)(*(u8 **)(arg0 + 0x4C) + 0x6) = 0;
            if (multiPlayerGame != 0) {
                hitPlayerKilledPlayer(arg0, arg0, 0, 0); /* asm: a2/a3 not set in this block */
            }
        }
    } else {
        s8 temp_v0_12 = *(s8 *)(state + 0x14B);
        if (temp_v0_12 > 0) {
            *(s8 *)(state + 0x14B) = (s8) (temp_v0_12 - arg1);
            *(s32 *)(arg0 + 0x84) = (s32) (*(s32 *)(arg0 + 0x84) | 0x80);
        }
    }
    temp_v0_13 = state[0x568];
    if ((temp_v0_13 != 5) && (temp_v0_13 != 0xB) && (temp_v0_13 != 3) && (temp_v0_13 != 8) && (temp_v0_13 != 0xC) && (temp_v0_13 != 6) && (temp_v0_13 != 7)) {
        func_overlay_15_00F0663C_1F19FBC(arg0, state, arg1);
    }
    temp_a0_5 = *(s32 *)(state + 0x5BC);
    if (temp_a0_5 != 0) {
        temp_a1 = state[0x568];
        switch (temp_a1) {                          /* switch 2; irregular */
        case 2:
            invincibilityShieldTransform(temp_a0_5, 0x3FC00000, 0x3F000000, 0x28);
            break;
        case 4:
            invincibilityShieldTransform(temp_a0_5, 0x3FC00000, 0x3F000000, 0x78);
            break;
        case 1:
            invincibilityShieldTransform(temp_a0_5, 0x3F800000, 0x3F400000, 0x78);
            break;
        default:
            invincibilityShieldTransform(temp_a0_5, 0x3F800000, 0x3F800000, 0x78);
            break;
        }
    }
    func_overlay_15_00F025FC_1F15F7C(arg0, state, arg1);
    if ((*(u8 *)(state + 0x540)) & 0x40) {
        /* asm: six display-list halfwords (0x4030/0x4032/0x4034 with 0x20 operands), pointer += 12 */
        p_dl = D_overlay_15_00F089C8;
        *(s16 *)(p_dl + 0) = 0x4030;
        *(s16 *)(p_dl + 2) = 0x20;
        *(s16 *)(p_dl + 4) = 0x4032;
        *(s16 *)(p_dl + 6) = 0x20;
        *(s16 *)(p_dl + 8) = 0x4034;
        *(s16 *)(p_dl + 10) = 0x20;
        D_overlay_15_00F089C8 = p_dl + 12;
    }
    func_overlay_15_00F04A58_1F183D8((s32) arg0, state, arg1);
    if ((deformedchars != 0) && (state[0x189] != 2)) {
        sp60[0] = D_overlay_15_00F08614[0];
        sp60[1] = D_overlay_15_00F08614[1];
        sp60[2] = D_overlay_15_00F08614[2];
        sp60[3] = D_overlay_15_00F08614[3];
        sp60[4] = D_overlay_15_00F08614[4];
        sp60[5] = D_overlay_15_00F08614[5];
        sp48[0] = D_overlay_15_00F0862C[0];
        sp48[1] = D_overlay_15_00F0862C[1];
        sp48[2] = D_overlay_15_00F0862C[2];
        sp48[3] = D_overlay_15_00F0862C[3];
        sp48[4] = D_overlay_15_00F0862C[4];
        sp48[5] = D_overlay_15_00F0862C[5];
        /* asm: 6 iterations (counter tested before its delay-slot decrement) */
        var_a0 = 6;
        var_v0 = &sp60[5];
        var_v1_2 = (f32 *) &sp48[5];
        do {
            p_dl = D_overlay_15_00F089C8;
            *(s16 *)p_dl = (s16) ((*var_v0 * 6) | 0x4000);
            temp_f18 = *(f32 *)var_v1_2 * 32768.0f;
            p_dl += 2;
            if (temp_f18 >= 2147483648.0f) {
                var_t7 = (s32) (temp_f18 - 2147483648.0f) | 0x80000000;
            } else {
                var_t7 = (s32) temp_f18;
                if (var_t7 < 0) {
                    var_t7 = -1;
                }
            }
            *(s16 *)p_dl = (s16) var_t7;
            p_dl += 2;
            *(s16 *)p_dl = (s16) (((*var_v0 * 6) + 2) | 0x4000);
            temp_f8 = *(f32 *)var_v1_2 * 32768.0f;
            p_dl += 2;
            if (temp_f8 >= 2147483648.0f) {
                var_t3 = (s32) (temp_f8 - 2147483648.0f) | 0x80000000;
            } else {
                var_t3 = (s32) temp_f8;
                if (var_t3 < 0) {
                    var_t3 = -1;
                }
            }
            *(s16 *)p_dl = (s16) var_t3;
            temp_lo = *var_v0 * 6;
            p_dl += 2;
            var_v0 -= 1;
            *(s16 *)p_dl = (s16) ((temp_lo + 4) | 0x4000);
            temp_f18_2 = *(f32 *)var_v1_2 * 32768.0f;
            p_dl += 2;
            if (temp_f18_2 >= 2147483648.0f) {
                var_t5 = (s32) (temp_f18_2 - 2147483648.0f) | 0x80000000;
            } else {
                var_t5 = (s32) temp_f18_2;
                if (var_t5 < 0) {
                    var_t5 = -1;
                }
            }
            *(s16 *)p_dl = (s16) var_t5;
            var_v1_2 -= 1;
            p_dl += 2;
            D_overlay_15_00F089C8 = p_dl;
            var_a0 -= 1;
        } while (var_a0 != 0);
    }
    *(s16 *)D_overlay_15_00F089C8 = 0x1000;
    D_overlay_15_00F089C8 += 2;
    if ((state[0x576] != 0) || ((state[0x188] != 0) && (state[0x532] & (*(u8 **)(state + 0x360))[5]) && (((temp_f0_5 = *(f32 *)(arg0 + 0x1C)) < -1.0f) || (temp_f0_5 > 1.0f) || ((temp_f0_6 = *(f32 *)(arg0 + 0x24)) < -1.0f) || (temp_f0_6 > 1.0f)))) {
        *(s32 *)(arg0 + 0x84) = (s32) (*(s32 *)(arg0 + 0x84) | D_overlay_15_00F0832C[((u8 *)levelGetLevel())[0xE2]]);
        if (*(s32 *)(state + 0xC8) == 0) {
            amSndPlay(0x1C, state + 0xC8, 0); /* asm: a2 not set in this block */
        }
    } else {
        *(s32 *)(arg0 + 0x84) = (s32) (*(s32 *)(arg0 + 0x84) & ~6);
        temp_a0_2 = *(s32 *)(state + 0xC8);
        if (temp_a0_2 != 0) {
            amSndStop(temp_a0_2);
        }
    }
    temp_a0_3 = *(u8 **)(*(u8 **)(arg0 + 0x6C) + ((s8)arg0[0x3A] * 4));
    if ((temp_a0_3 != NULL) && ((s8)temp_a0_3[0xA] != 0)) {
        temp_s1 = *(u8 **)temp_a0_3;
        sp94 = temp_a0_3;
        modGenAnimMatrices(temp_a0_3, temp_s1, arg0, *(f32 *)(state + 0x48), 0.0f);
        state[0x540] = (u8) (((objMakeGunMtx(arg0, sp94, temp_s1, sp90[0x70], state + 0x78, state + 0x544, state + 0x548, state + 0x54C) * 4) & 4) | (state[0x540] & 0xFFFB));
        lightObject(arg0, sp94, *(s32 *)(arg0 + 0x54), *(s32 *)(sp94 + ((s8)sp94[0xB] * 4) + 0x10));
        if (temp_s1[0x11] > 0) {
            func_overlay_15_00F01C80_1F15600(temp_s1, sp94, state, (s8)sp94[0xA]);
        }
        sp94[0xA] = 0;
        var_f0 = (*(f32 *)(*(u8 **)(sp94 + 0x70) + 0x70) + 4.0f) - *(f32 *)(arg0 + 0x10);
        if (var_f0 >= 64.0f) {
            var_f0 = D_overlay_15_00F08738;
        }
        *(s8 *)(*(u8 **)(arg0 + 0x50) + 0xE) = (s8) (s32) (var_f0 * 4.0f);
    }
    if (state[0x568] == 4) {
        func_overlay_15_00F01E14_1F15794(arg0, state, arg1);
    } else if ((((u8 *)levelGetLevel())[0xE0] != 0) && (*(s8 *)(state + 0x12E) != 0) && (*(s8 *)(state + 0x1) == 0)) {
        *(s32 *)(arg0 + 0x84) = (s32) (*(s32 *)(arg0 + 0x84) | 0x200);
    }
    temp_v0_14 = controlUpdateWeapon(arg0, state, sp3C);
    temp_v0_15 = controlThrowWeapon(temp_v0_14);
    switch (temp_v0_15) {                           /* switch 3; irregular */
    case 1:
        if (arg0[0x3B] == 0x16) {
            objAnimSetFrame(arg0, 0);
        } else {
            func_overlay_15_00F05180_1F18B00(arg0, state, 0x16, 0);
        }
        state[0x577] = 0x28;
        break;
    case 2:
        if (arg0[0x3B] == 0x31) {
            objAnimSetFrame(arg0, 0);
        } else {
            func_overlay_15_00F05180_1F18B00(arg0, state, 0x31, 0);
        }
        state[0x577] = 0x28;
        break;
    }
    if (D_overlay_15_00F089CE != 0) {
        controlFireDummyShot(arg0, state);
    }
    controlUpdateJetFlames(arg0, state, 0x800, 0x400, arg1);
    *(u8 *)(*(u8 **)(arg0 + 0x58) + 0x75) = 0;
    temp_v0_16 = *(u8 **)(*(u8 **)(arg0 + 0x58) + 0x84);
    if (temp_v0_16 != NULL) {
        *temp_v0_16 = (u8) (*temp_v0_16 & 0xFD);
    }
    if (state[0x2] == 1) {
        if (*(f32 *)(state + 0x60) < 50.0f) {
            *(f32 *)(*(u8 **)(arg0 + 0x58) + 0x80) = (f32) *(f32 *)(state + 0x5C);
            *(u8 *)(*(u8 **)(arg0 + 0x58) + 0x75) = 1;
            if (temp_v0_16 != NULL) {
                if ((state[0x533] == 0) && ((temp_f0_7 = *(f32 *)(state + 0x4)), (temp_f0_7 < -1.0f) || (temp_f0_7 > 1.0f) || (temp_f0_8 = *(f32 *)(state + 0x10)), (temp_f0_8 < -1.0f) || (temp_f0_8 > 1.0f))) {
                    *temp_v0_16 |= 2;
                }
            }
        }
    }
    wakeUpdateRipple(arg0, arg1);
    partUpdateTriggers(arg0, arg1);
    *(s32 *)(arg0 + 0x84) = (s32) (*(s32 *)(arg0 + 0x84) & ~0x18);
    if (state[0x14A] != 0) {
        if (*(s32 *)(state + 0xCC) == 0) {
            amSndPlay(0x9C, state + 0xCC, 0); /* asm: a2 not set in this block */
        }
    } else {
        temp_a0_4 = *(s32 *)(state + 0xCC);
        if (temp_a0_4 != 0) {
            amSndStop(temp_a0_4);
        }
    }
    controlSetRumble((s8) state[0], D_overlay_15_00F089C0, D_overlay_15_00F089C4, temp_v0_14, *(s16 *)(state + 0x536) / arg1);
    *(s16 *)(state + 0x536) = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o15/overlay_15/girlControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 girlCanFire(u8 *arg0, u8 *arg1) {
    s32 temp_t8;
    s8 temp_v0;

    if ((arg1[0x576] == 0) && (arg1[0x13E] == 0)) {
        temp_v0 = arg0[0x3B];
        if (temp_v0 != 8) {
            temp_t8 = arg1[0x568] & ~0x20;
            if ((temp_t8 == 0) || (temp_t8 == 5) || (temp_t8 == 0xB) || (temp_t8 == 0xA) || ((temp_t8 == 3) && (arg1[0x14A] != 0))) {
                return 1;
            }
            if (((temp_v0 == 0x16) || (temp_v0 == 0x31)) && (arg1[0x53D] != 0)) {
                return 1;
            }
            if (((temp_v0 == 0xE) || (temp_v0 == 0x22)) && ((*(u8 **)(arg0 + 0x6C))[0x5E] == 0)) {
                return 1;
            }
            return 0;
        }
        return 0;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o15/overlay_15/girlCanFire.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 func_overlay_15_00F01C80_1F15600(u8 *arg0, u8 *arg1, u8 *arg2, s32 arg3) {
    TextureHeader *temp_s1;
    u8 *var_s0;
    u8 *out;
    s32 sp54;
    s16 temp_lo;
    s16 temp_v0;
    u8 temp_s3;
    u8 var_s3;
    u8 var_v0;

    temp_s3 = arg0[0x2C];
    var_v0 = temp_s3;
    var_s0 = *(u8 **)(arg1 + 0x74);
    out = *(u8 **)(arg1 + arg1[0xB] * 4 + 0x78);
    var_s3 = temp_s3 - 1;
    if (temp_s3 != 0) {
        do {
            temp_s1 = *(TextureHeader **)(*(u8 **)(arg0 + 0x18) + (*(u32 *)(var_s0 + 4) & 0xFF) * 8);
            if (temp_s1->numOfTextures >= 0x101) {
                sp54 = *(s16 *)var_s0;
                if (temp_s1->frameAdvanceDelay != 0) {
                    if ((*(u32 *)(var_s0 + 4) & 0x20000) && ((arg2[0x10D] != 0) || (arg2[0x19F] != 0) || (arg2[0x568] == 0xA))) {
                        blinkMode = 3;
                    }
                    texAnimateTexture(temp_s1, (u32 *)(var_s0 + 4), &sp54, arg3);
                }
                *(s16 *)var_s0 = (s16) sp54;
            }
            temp_lo = (s16) ((*(s16 *)var_s0 >> 8) * temp_s1->textureSize);
            *(s16 *)out = temp_lo;
            out += 2;
            var_s0 += 8;
            temp_v0 = *(s16 *)(var_s0 - 6);
            if (temp_v0 >= 0) {
                *(s16 *)out = (s16) ((temp_v0 >> 8) * temp_s1->textureSize);
                out += 2;
            }
            var_v0 = var_s3;
            var_s3 -= 1;
        } while (var_s3 != 0);
    }
    return var_v0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o15/overlay_15/func_overlay_15_00F01C80_1F15600.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_15_00F01E14_1F15794(u8 *arg0, u8 *arg1, s32 arg2) {
    f32 sp7C;
    f32 sp74;
    f32 sp78 = 0.0f;
    s16 sp6A;
    s16 sp68;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f22;
    f32 temp_f24;
    s32 temp_v0;
    s32 var_s0;
    u8 *temp_s1;
    u8 *temp_s1_2;
    f32 key;

    temp_f20 = *(f32 *)(arg1 + 0x5C) + 1.0f;
    temp_s1 = *(u8 **)(*(u8 **)(*(u8 **)(arg0 + 0x6C) + arg0[0x3A] * 4) + 0x68);
    temp_s1_2 = temp_s1 + 0xC;
    key = *(f32 *)(temp_s1 + 0x10);
    if ((*(f32 *)(arg1 + 0x5C4) < temp_f20) && (temp_f20 < key)) {
        charSpeak(arg0, 0xB);
        amSndPlayXYZ(0xF7, *(f32 *)(arg0 + 0xC), *(f32 *)(arg0 + 0x10), *(f32 *)(arg0 + 0x14), 4, arg1 + 0xE8);
        *(s16 *)(arg1 + 0x5CA) = 0x14;
    }
    *(f32 *)(arg1 + 0x5C4) = key;
    if (key < temp_f20) {
        *(s16 *)(arg1 + 0x5CA) = 0;
    }
    if (*(s16 *)(arg1 + 0x5CA) != 0) {
        s32 temp_s4 = *(s32 *)(arg0 + 0x84);
        *(s32 *)(arg0 + 0x84) = 0x100;
        partUpdateTriggers(arg0, arg2);
        *(s32 *)(arg0 + 0x84) = temp_s4;
        var_s0 = arg2 - 1;
        if (arg2 != 0) {
            f32 temp_f24b = D_overlay_15_00F0873C;
            f32 temp_f22b = D_overlay_15_00F08740;
            do {
                temp_f20_2 = (f32) mathRnd(0x32, 0x64) * temp_f22b;
                sp68 = (s16) (mathRnd(-0x800, 0x800) + *(s16 *)arg0);
                sp6A = (s16) (mathRnd(0x1000, 0x2000) + 0x1000);
                sp7C = (f32) -mathRnd(0x2A, 0x34) * temp_f24b;
                mathOneFloatPY(&sp68, &sp74);
                temp_v0 = dropletAdd(temp_f20_2, *(f32 *)(temp_s1 + 0xC), key, *(f32 *)(temp_s1 + 0x14), *(f32 *)(arg1 + 0x5C), sp74, sp78, sp7C);
                if (var_s0 > 0) {
                    if (temp_v0 != 0) {
                        dropletUpdate(temp_v0, var_s0);
                    }
                }
                var_s0 -= 1;
            } while (var_s0 != 0);
        }
        if (*(s16 *)(arg1 + 0x5CA) < 0xF) {
            amSndPlayXYZ(0xF8, *(f32 *)(arg0 + 0xC), *(f32 *)(arg0 + 0x10), *(f32 *)(arg0 + 0x14), 4, arg1 + 0xEC);
        }
        if (arg2 < *(s16 *)(arg1 + 0x5CA)) {
            *(s16 *)(arg1 + 0x5CA) = (s16) (*(s16 *)(arg1 + 0x5CA) - arg2);
        } else {
            *(s16 *)(arg1 + 0x5CA) = 0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o15/overlay_15/func_overlay_15_00F01E14_1F15794.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_15_00F020B4_1F15A34(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 sp44;
    s32 sp40;
    f32 sp38;
    u8 setup[0x10];
    s16 sp26;
    s16 sp24;
    f32 var_f0;
    s32 var_v0;
    u8 *temp_v0;

    var_v0 = (s32) (-*(f32 *)(arg1 + 0x74) * 15.0f);
    if (var_v0 >= 0x80) {
        var_v0 = 0x7F;
    }
    sp44 = var_v0;
    amSndPlay(0xD, arg1 + 0xD4, arg0);
    amSndSetVol(0xD, *(s32 *)(arg1 + 0xD4), var_v0 & 0xFF);
    if (*(f32 *)(arg1 + 0x74) < -5.0f) {
        *(s16 *)(setup + 0x0) = 0xC0;
        setup[0x2] = 0x10;
        *(s16 *)(setup + 0x4) = (s16) (s32) *(f32 *)(arg0 + 0xC);
        *(s16 *)(setup + 0x6) = (s16) (s32) *(f32 *)(arg1 + 0x5C);
        *(s16 *)(setup + 0xA) = 0x100;
        *(s16 *)(setup + 0x8) = (s16) (s32) *(f32 *)(arg0 + 0x14);
        var_f0 = -(*(f32 *)(arg1 + 0x74) + 5.0f);
        if (var_f0 > 10.0f) {
            var_f0 = 10.0f;
        }
        sp38 = var_f0;
        temp_v0 = objSetupObject(setup, 1);
        if (temp_v0 != NULL) {
            *(s32 *)(temp_v0 + 0x3C) = 0;
        }
    } else {
        sp40 = *(s32 *)(arg0 + 0x84);
        sp26 = *(s16 *)(arg0 + 0x2);
        sp24 = *(s16 *)(arg0 + 0x4);
        *(s16 *)(arg0 + 0x2) = 0;
        *(s16 *)(arg0 + 0x4) = 0;
        *(f32 *)(arg0 + 0x10) = *(f32 *)(arg0 + 0x10) + *(f32 *)(arg1 + 0x60);
        *(s32 *)(arg0 + 0x84) = 0x40;
        partUpdateTriggers(arg0, arg2);
        *(s16 *)(arg0 + 0x4) = sp24;
        *(s16 *)(arg0 + 0x2) = sp26;
        *(f32 *)(arg0 + 0x10) = *(f32 *)(arg0 + 0x10) - *(f32 *)(arg1 + 0x60);
        *(s32 *)(arg0 + 0x84) = sp40;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o15/overlay_15/func_overlay_15_00F020B4_1F15A34.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_15_00F022C4_1F15C44(u8 *arg0, u8 *arg1, f32 arg2, f32 arg3) {
    f32 sp94 = 0.0f;
    f32 sp90 = 0.0f;
    f32 sp88;
    f32 sp80;
    f32 sp84 = 0.0f;
    s16 sp7E;
    s16 sp7C;
    f32 temp_f0_2;
    f32 temp_f14;
    f32 temp_f20;
    f32 temp_f20_2;
    f32 temp_f22;
    f32 temp_f24;
    f32 temp_f26;
    f32 temp_f28;
    f32 var_f0;
    f32 var_f2;
    s32 temp_s0;
    s32 var_s0;
    s32 var_v0;

    if (arg1[0x568] == 0) {
        if (*(f32 *)(arg1 + 0x60) > 0.0f) {
            temp_f14 = *(f32 *)(arg1 + 0x4);
            if (temp_f14 < -1.0f) {
                var_v0 = 0;
                if (arg3 < 0.0f) {
                    var_f0 = *(f32 *)(arg0 + 0x28);
                    var_f2 = arg2;
                    if (arg2 < var_f0) {
                        var_f0 -= 1.0f;
                    }
                } else {
                    var_f2 = *(f32 *)(arg0 + 0x28);
                    var_f0 = arg2;
                    if (var_f2 < arg2) {
                        var_f2 += 1.0f;
                    }
                }
                if ((var_f0 < D_overlay_15_00F08744) && (D_overlay_15_00F08744 <= var_f2)) {
                    var_v0 = 1;
                    sp94 = 4.0f;
                    sp90 = 16.0f;
                } else if ((var_f0 < D_overlay_15_00F08748) && (D_overlay_15_00F08748 < var_f2)) {
                    var_v0 = 1;
                    sp94 = -4.0f;
                    sp90 = 16.0f;
                }
                if (var_v0 != 0) {
                    temp_s0 = 2 - (s32) (temp_f14 + 1.0f);
                    temp_f20 = Sinf(*(s16 *)arg0);
                    temp_f0_2 = Cosf((s32) *(s16 *)arg0);
                    temp_f22 = *(f32 *)(arg0 + 0xC) + ((sp94 * temp_f0_2) + (sp90 * temp_f20));
                    temp_f24 = *(f32 *)(arg0 + 0x14) + ((sp90 * temp_f0_2) - (sp94 * temp_f20));
                    var_s0 = temp_s0 - 1;
                    if (temp_s0 != 0) {
                        temp_f28 = D_overlay_15_00F0874C;
                        temp_f26 = D_overlay_15_00F08750;
                        do {
                            temp_f20_2 = (f32) mathRnd(0x32, 0x64) * temp_f26;
                            sp7C = (s16) (mathRnd(-0x2555, 0x2555) + *(s16 *)arg0);
                            sp7E = (s16) mathRnd(0x2400, 0x3C00);
                            sp88 = ((f32) mathRnd(0xC, 0x16) * temp_f28) + (*(f32 *)(arg1 + 0x4) * 0.25f);
                            mathOneFloatPY(&sp7C, &sp80);
                            temp_f0_2 = *(f32 *)(arg1 + 0x5C);
                            dropletAdd(temp_f20_2, temp_f22, temp_f0_2, temp_f24, temp_f0_2, sp80, sp84, sp88);
                            var_s0 -= 1;
                        } while (var_s0 != 0);
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o15/overlay_15/func_overlay_15_00F022C4_1F15C44.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_15_00F025FC_1F15F7C(u8 *arg0, u8 *arg1, s32 arg2) {
    s32 sp28 = 0; /* stack locals read before written in the asm */
    s32 sp20 = 0;
    s16 var_v0;
    s16 var_v1_2;
    s32 temp_a0;
    s32 temp_t0;
    s32 temp_v0;
    s32 temp_v0_2;
    s32 temp_v0_3;
    s32 var_a0;
    s32 var_at;
    s32 var_t1;
    s32 var_t3;
    s8 temp_a3;
    s8 temp_a3_2;
    s8 temp_a3_3;
    s8 temp_a3_4;
    s8 temp_v0_4;
    s8 var_t0;
    s8 var_t2;
    u32 var_v1;
    u8 temp_a0_2;
    u8 temp_t8;
    u8 *temp_t1;
    u8 *temp_t1_2;
    u8 *temp_t1_3;
    u8 *var_a3;

    temp_t1 = *(u8 **)(arg0 + 0x4C);
    var_v0 = *(s16 *)(temp_t1 + 0x32);
    var_a3 = *(u8 **)(temp_t1 + 0x40);
    var_v1 = 0;
    var_t3 = 0;
    var_t0 = 0;
    var_t2 = 0;
    var_t1 = sp20;
    var_a0 = sp28;
    if (var_v0 > 0) {
        do {
            if (var_a3[0xA] & 0x40) {
                var_t3 = 1;
                switch (var_v1) {
                case 0:
                case 1:
                case 2:
                case 3:
                    D_overlay_15_00F089C0 |= 1;
                    D_overlay_15_00F089C4 |= 1;
                    var_t0 = 0xF;
                    var_v0 = *(s16 *)(*(u8 **)(arg0 + 0x4C) + 0x32);
                    var_a0 = 5;
                    break;
                case 4:
                case 5:
                case 6:
                case 7:
                    D_overlay_15_00F089C0 |= 1;
                    D_overlay_15_00F089C4 |= 1;
                    var_t0 = 0xF;
                    var_v0 = *(s16 *)(*(u8 **)(arg0 + 0x4C) + 0x32);
                    var_a0 = 5;
                    break;
                case 8:
                    D_overlay_15_00F089C0 |= 2;
                    D_overlay_15_00F089C4 |= 1;
                    var_t2 = 0xF;
                    var_v0 = *(s16 *)(*(u8 **)(arg0 + 0x4C) + 0x32);
                    var_t1 = 4;
                    break;
                default:
                    D_overlay_15_00F089C0 |= 4;
                    D_overlay_15_00F089C4 |= 1;
                    var_t2 = 0xF;
                    var_v0 = *(s16 *)(*(u8 **)(arg0 + 0x4C) + 0x32);
                    var_t1 = 3;
                    break;
                }
            }
            var_v1 += 1;
            var_a3 += 0x34;
        } while ((s32) var_v1 < var_v0);
        sp28 = var_a0;
        sp20 = var_t1;
    }
    if (var_t3 != 0) {
        if ((var_t0 != 0) && (arg1[0x342] == 0)) {
            arg1[0x342] = var_t0;
            arg1[0x343] = (u8) sp28;
        }
        if ((var_t2 != 0) && (arg1[0x340] == 0)) {
            arg1[0x340] = var_t2;
            arg1[0x341] = (u8) sp20;
        }
    }
    temp_a3 = arg1[0x342];
    if (temp_a3 != 0) {
        temp_v0 = mathSin((s16) (temp_a3 << 0xB), (s32) &D_overlay_15_00F089C0);
        *(s16 *)(D_overlay_15_00F089C8 + 0) = 8;
        D_overlay_15_00F089C8 += 2;
        temp_t0 = temp_v0 >> arg1[0x343];
        *(s16 *)(D_overlay_15_00F089C8 + 2) = (s16) temp_t0;
        D_overlay_15_00F089C8 += 2;
        *(s16 *)(D_overlay_15_00F089C8 + 2) = 0x14;
        D_overlay_15_00F089C8 += 2;
        *(s16 *)(D_overlay_15_00F089C8 + 2) = (s16) -temp_t0;
        D_overlay_15_00F089C8 += 2;
        temp_a3_2 = arg1[0x342];
        if (arg2 < temp_a3_2) {
            arg1[0x342] = (s8) (temp_a3_2 - arg2);
        } else {
            arg1[0x342] = 0;
        }
    }
    temp_a3_3 = arg1[0x340];
    if (temp_a3_3 != 0) {
        temp_v0_2 = mathSin((s16) (temp_a3_3 << 0xB), (s32) &D_overlay_15_00F089C0);
        *(s16 *)(D_overlay_15_00F089C8 + 0) = 6;
        D_overlay_15_00F089C8 += 2;
        temp_a0 = (s32) (temp_v0_2 >> arg1[0x341]) >> 1;
        *(s16 *)(D_overlay_15_00F089C8 + 2) = (s16) temp_a0;
        D_overlay_15_00F089C8 += 2;
        *(s16 *)(D_overlay_15_00F089C8 + 2) = 0x3C;
        D_overlay_15_00F089C8 += 2;
        *(s16 *)(D_overlay_15_00F089C8 + 2) = (s16) temp_a0;
        D_overlay_15_00F089C8 += 2;
        temp_a3_4 = arg1[0x340];
        if (arg2 < temp_a3_4) {
            arg1[0x340] = (s8) (temp_a3_4 - arg2);
        } else {
            arg1[0x340] = 0;
        }
    }
    var_v1_2 = *(s16 *)(*(u8 **)(arg0 + 0x4C) + 0x6);
    if (var_v1_2 >= 0x100) {
        temp_a0_2 = arg1[0x190];
        var_at = 0;
        if (temp_a0_2 == 0x80) {
            if (arg1[0x5C8] == 0) {
                arg1[0x190] = 0x3C;
                temp_t1_2 = *(u8 **)(arg0 + 0x4C);
                var_t3 = 1;
                *(s16 *)(temp_t1_2 + 0x6) = (s16) (*(s16 *)(temp_t1_2 + 0x6) - 0x100);
                D_overlay_15_00F089C0 |= 2;
                D_overlay_15_00F089C4 |= 2;
                var_v1_2 = *(s16 *)(*(u8 **)(arg0 + 0x4C) + 0x6);
                var_at = var_v1_2 < 0x100;
            }
        } else if (temp_a0_2 == 0xC0) {
            if (arg1[0x5C8] == 0) {
                arg1[0x190] = 0x3C;
                temp_t1_3 = *(u8 **)(arg0 + 0x4C);
                var_t3 = 1;
                *(s16 *)(temp_t1_3 + 0x6) = (s16) (*(s16 *)(temp_t1_3 + 0x6) - 0x200);
                D_overlay_15_00F089C0 |= 4;
                D_overlay_15_00F089C4 |= 2;
                var_v1_2 = *(s16 *)(*(u8 **)(arg0 + 0x4C) + 0x6);
                var_at = var_v1_2 < 0x100;
            }
        } else if (arg1[0x56F] != 0) {
            if (temp_a0_2 == 0) {
                arg1[0x190] = 0x3C;
                D_overlay_15_00F089C0 |= 1;
                D_overlay_15_00F089C4 |= 1;
                var_t3 = 1;
                var_v1_2 = *(s16 *)(*(u8 **)(arg0 + 0x4C) + 0x6);
            }
            var_at = var_v1_2 < 0x100;
        }
        if (var_at != 0) {
            *(s16 *)(*(u8 **)(arg0 + 0x4C) + 0x6) = 0;
            if (multiPlayerGame != 0) {
                hitPlayerKilledPlayer(arg0, arg0, &D_overlay_15_00F089C4, arg1[0x340]);
            }
        }
    }
    temp_t8 = arg1[0x190] & 0x3F;
    arg1[0x190] = temp_t8;
    temp_v0_3 = temp_t8 & 0xFF;
    if (arg2 < temp_v0_3) {
        arg1[0x190] = (u8) (temp_v0_3 - arg2);
    } else {
        arg1[0x190] = 0;
    }
    if ((var_t3 != 0) && (arg1[0x568] != 0xA)) {
        charSpeak(arg0, 3);
        arg1[0x148] = 8;
    } else {
        temp_v0_4 = arg1[0x148];
        if (arg2 < temp_v0_4) {
            arg1[0x148] = (s8) (temp_v0_4 - arg2);
        } else {
            arg1[0x148] = 0;
        }
    }
    if (arg1[0x148] != 0) {
        fxNightVisionSkip();
        frontFlashScreen(0, arg1[0], 0xFF0000FF);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o15/overlay_15/func_overlay_15_00F025FC_1F15F7C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_15_00F02B2C_1F164AC(u8 *arg0, u8 *arg1, f32 arg2, s16 arg3, f32 arg4) {
    s32 sp5C;
    f32 sp58;
    s16 sp56;
    s32 sp48;
    f32 temp_f14;
    f32 temp_f14_2;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 var_f10;
    f32 var_f14;
    f32 var_f14_2;
    f32 var_f14_3;
    f32 var_f14_4;
    f32 var_f14_5;
    f32 var_f14_6;
    s16 temp_t6;
    u8 *temp_v0_2;
    s8 temp_v0;
    s8 temp_v0_4;
    u8 *temp_v0_3;
    u8 blk20;

    temp_v0 = arg1[0x576];
    if (temp_v0 != 0) {
        arg1[0x576] = (u8) (temp_v0 - (s32) arg4);
        if ((s8) arg1[0x576] < 0) {
            arg1[0x576] = 0;
        }
    }
    if ((arg0[0x3B] == 0x1A) && (arg1[0x56B] == 0)) {
        func_overlay_15_00F05180_1F18B00(arg0, arg1, func_overlay_15_00F05020_1F189A0(arg1), 0);
    }
    if (controlKeys & 0x10) {
        temp_t6 = *(s16 *)(arg1 + 0x10A);
        *(s16 *)(arg1 + 0x10A) = 0;
        *(s16 *)(arg1 + 0x11C) = (s16) (*(s16 *)(arg1 + 0x11C) - temp_t6);
        arg3 = *(s16 *)(arg1 + 0x11C);
        if (lobbycamInuse(arg2, arg1) == 0) {
            staticcamInuse(arg2, *(s32 *)(arg1 + 0x5C0));
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
    sp48 = (s32) arg4;
    controlWalkingBack(arg0, arg1, &arg2, arg3, 0x5000, 0x6800, 5.0f, 3.0f);
    func_overlay_15_00F04B4C_1F184CC(arg0, arg1, 0, arg4);
    temp_f2 = *(f32 *)(arg1 + 0x4);
    var_f14 = temp_f2;
    if (temp_f2 < 0.0f) {
        var_f14 = -var_f14;
    }
    temp_v0_2 = (u8 *) controlModeKeys;
    blk20 = 1;
    if ((*(s32 *)(temp_v0_2 + 0xC) & controlDkeys) && (arg1[0x534] == 0)) {
        if (arg1[0x569] != 0) {
            arg1[0x57A] = 0x14;
            arg1[0x57B] = 0;
            func_overlay_15_00F05180_1F18B00(arg0, arg1, 7, 0);
            blk20 = 0;
        } else if (!(var_f14 > 1.25f) || (arg2 == 0.0f)) {
            if (arg1[0x56C] == 0) {
                arg1[0x57A] = 0x18;
                arg1[0x57B] = 0;
                func_overlay_15_00F05180_1F18B00(arg0, arg1, 5, 0);
                blk20 = 0;
            }
        }
        if (blk20) {
            arg1[0x57A] = 0;
            *(f32 *)(arg0 + 0x20) = *(f32 *)(arg0 + 0x20) + 10.0f;
            temp_v0_3 = *(u8 **)(arg1 + 0x510);
            if (temp_v0_3 != NULL) {
                *(f32 *)(arg0 + 0x20) = *(f32 *)(arg0 + 0x20) - *(f32 *)(temp_v0_3 + 0x20);
            }
            func_overlay_15_00F05180_1F18B00(arg0, arg1, 6, 0);
            charSpeak(arg0, 0);
        }
        arg1[0x568] = 3;
        arg1[0x58E] = 0;
        *(f32 *)(arg1 + 0x57C) = *(f32 *)(arg0 + 0x10);
    } else if (*(s32 *)(temp_v0_2 + 0x10) & controlDkeys) {
        var_f14_2 = var_f14;
        if (var_f14_2 > 2.0f) {
            arg1[0x568] = 1;
            func_overlay_15_00F05180_1F18B00(arg0, arg1, 0xF, 0);
            arg1[0x576] = 0x28;
        } else if (D_overlay_15_00F08778 < arg2) {
            arg1[0x568] = 2;
            func_overlay_15_00F05180_1F18B00(arg0, arg1, 4, 0);
        } else {
            arg1[0x568] = 1;
            func_overlay_15_00F05180_1F18B00(arg0, arg1, 0xD, 0);
        }
        arg1[0x56C] = 0;
    }
    if (*(s32 *)temp_v0_2 & controlKeys) {
        arg1[0x1F4] = 0xF;
    }
    if (!((*(u8 **)(arg1 + 0x360))[5] & arg1[0x532])) {
        arg1[0x1F4] = 0;
    }
    if (arg1[0x569] == 0) {
        arg2 = -arg2;
    } else {
        arg3 += 0x8000;
    }
    controlHalfTurn(arg0, arg1, &arg2, &arg3, 0x6AAA, 0x38E, &sp5C, D_overlay_15_00F089D4, arg4);
    if (sp5C != 0) {
        func_overlay_15_00F05180_1F18B00(arg0, arg1, 0xF, 0);
    }
    sp56 = *(s16 *)(arg1 + 0x11C);
    if ((lobbycamInuse(arg2, arg1) == 0) && (staticcamInuse(arg2, *(s32 *)(arg1 + 0x5C0)) == 0)) {
        if ((arg1[0x540] & 0xF) && (frontGetTargetControl((s8) arg1[0]) == 0)) {
            temp_f2_2 = *(f32 *)(arg1 + 0x14);
            var_f10 = temp_f2_2 + ((D_overlay_15_00F08780 - temp_f2_2) * (1.0f - Powerf(D_overlay_15_00F0877C, sp48)));
        } else {
            temp_f14_2 = *(f32 *)(arg1 + 0x14);
            var_f10 = temp_f14_2 + ((D_overlay_15_00F08788 - temp_f14_2) * (1.0f - Powerf(D_overlay_15_00F08784, sp48)));
        }
        *(f32 *)(arg1 + 0x14) = var_f10;
    }
    var_f14_3 = *(f32 *)(arg1 + 0x4);
    if (var_f14_3 < 0.0f) {
        var_f14_3 = -var_f14_3;
    }
    temp_f14 = var_f14_3;
    var_f14_4 = temp_f14 * temp_f14;
    if (var_f14_4 > 1.0f) {
        var_f14_4 = 1.0f;
    }
    var_f14_5 = 1.0f - (((*(f32 *)(arg1 + 0x14) - D_overlay_15_00F0878C) * var_f14_4) + D_overlay_15_00F0878C);
    if (arg1[0x13E] != 0) {
        var_f14_5 = D_overlay_15_00F08790;
    }
    *(s16 *)(arg1 + 0x11C) = dAngle(*(s16 *)(arg1 + 0x11C), arg3, 1.0f - Powerf(var_f14_5, sp48));
    temp_f14_2 = *(f32 *)(arg1 + 0x4);
    sp58 = temp_f14_2;
    temp_f2_4 = *(f32 *)(arg1 + 0x4);
    *(f32 *)(arg1 + 0x4) = ((1.0f - Powerf(D_overlay_15_00F08794, sp48)) * (arg2 - temp_f2_4)) + temp_f2_4;
    sp56 = (s16) (*(s16 *)(arg1 + 0x11C) - sp56);
    if ((arg1[0x568] == 0) && ((temp_f14_2 - *(f32 *)(arg1 + 0x4)) < -0.5f)) {
        temp_v0_4 = arg0[0x3B];
        if ((temp_v0_4 != 0x16) && (temp_v0_4 != 0x31) && (temp_v0_4 != 0x1A)) {
            arg1[0x576] = 4;
            func_overlay_15_00F05180_1F18B00(arg0, arg1, 0xF, 0);
        }
    }
    var_f14_6 = *(f32 *)(arg1 + 0x4);
    if (var_f14_6 < 0.0f) {
        var_f14_6 = -var_f14_6;
    }
    if (var_f14_6 > 3.0f) {
        var_f14_6 = 3.0f;
    }
    *(s16 *)(arg1 + 0x120) = (s16) ((s32) ((f32) sp56 * var_f14_6 * D_overlay_15_00F08798));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o15/overlay_15/func_overlay_15_00F02B2C_1F164AC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_15_00F03274_1F16BF4(u8 *arg0, u8 *arg1, f32 arg2, s32 arg3, f32 arg4) {
    s32 temp_f8;
    s8 temp_v0;
    s8 temp_v0_2;

    if ((*(s32 *)((u8 *) controlModeKeys + 0xC) & controlKeys) && (arg1[0x56C] == 0) && (controlCeiling(*(f32 *)(arg1 + 0xC), *(f32 *)(arg1 + 0x10), *(f32 *)(arg1 + 0x14), 52.0f, 13.0f) != 0)) {
        arg1[0x568] = 0;
        func_overlay_15_00F05180_1F18B00(arg0, arg1, func_overlay_15_00F05020_1F189A0(arg1), 0);
        arg1[0x576] = 0;
    } else {
        temp_v0 = arg1[0x576];
        if (temp_v0 != 0) {
            temp_f8 = (s32) arg4;
            arg1[0x576] = (u8) (temp_v0 - temp_f8);
            *(f32 *)(arg1 + 0x10) = *(f32 *)(arg1 + 0x10) * Powerf(D_overlay_15_00F0879C, temp_f8);
            if ((s8) arg1[0x576] <= 0) {
                arg1[0x576] = 0;
                *(f32 *)(arg1 + 0x4) = 0.0f;
                *(f32 *)(arg1 + 0x10) = 0.0f;
                if ((D_overlay_15_00F087A0 < arg2) && !(controlKeys & 0x10)) {
                    arg1[0x568] = 2;
                    func_overlay_15_00F05180_1F18B00(arg0, arg1, 0x17, 0);
                } else {
                    func_overlay_15_00F05180_1F18B00(arg0, arg1, 0xE, 0);
                }
            }
        }
    }
    if ((arg1[0x568] == 1) && (arg1[0x576] == 0)) {
        if (controlKeys & 0x10) {
            if (girlCanFire(arg0, arg1) != 0) {
                arg1[0x568] = 5;
                *(s16 *)(arg1 + 0x11C) = (s16) (*(s16 *)(arg1 + 0x11C) - *(s16 *)(arg1 + 0x10A));
                *(s16 *)(arg1 + 0x10A) = 0;
                *(s16 *)(arg1 + 0x1E2) = 0;
                *(s16 *)(arg1 + 0x1E0) = 0;
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
        }
        func_overlay_15_00F04B4C_1F184CC(arg0, arg1, 1, arg4);
        temp_v0_2 = arg0[0x3B];
        if ((temp_v0_2 != 0xB) && (temp_v0_2 != 0x32)) {
            if (*(s32 *)((u8 *) controlModeKeys + 0x0) & controlKeys) {
                arg1[0x1F4] = 0xF;
            }
            if (!((*(u8 **)(arg1 + 0x360))[5] & arg1[0x532])) {
                arg1[0x1F4] = 0;
            }
            if (D_overlay_15_00F087A4 < arg2) {
                arg1[0x568] = 2;
                func_overlay_15_00F05180_1F18B00(arg0, arg1, 0x17, 0);
            }
        }
    }
    *(f32 *)(arg1 + 0x4) = *(f32 *)(arg1 + 0x4) * Powerf(D_overlay_15_00F087A8, (s32) arg4);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o15/overlay_15/func_overlay_15_00F03274_1F16BF4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_15_00F03564_1F16EE4(u8 *arg0, u8 *arg1, f32 arg2, s16 arg3, f32 arg4) {
    s32 sp44;
    s32 temp_f4;
    f32 temp_f2;

    if ((*(s32 *)((u8 *) controlModeKeys + 0xC) & controlKeys) && (arg1[0x56C] == 0) && (controlCeiling(*(f32 *)(arg0 + 0xC), *(f32 *)(arg0 + 0x10), *(f32 *)(arg0 + 0x14), 52.0f, 13.0f) != 0)) {
        func_overlay_15_00F05180_1F18B00(arg0, arg1, 8, 0);
        arg1[0x568] = 0;
        return;
    }
    func_overlay_15_00F04B4C_1F184CC(arg0, arg1, 2, arg4);
    controlWalkingBack(arg0, arg1, &arg2, arg3, 0x5000, 0x6800, 1.25f, 1.25f);
    if (arg1[0x569] == 0) {
        arg2 = -arg2;
    } else {
        arg3 += 0x8000;
    }
    controlHalfTurn(arg0, arg1, &arg2, &arg3, 0x6AAA, 0x38E, &sp44, D_overlay_15_00F087AC, arg4);
    temp_f4 = (s32) arg4;
    temp_f2 = *(f32 *)(arg1 + 0x4);
    *(f32 *)(arg1 + 0x4) = ((1.0f - Powerf(D_overlay_15_00F087B0, temp_f4)) * (arg2 - temp_f2)) + temp_f2;
    *(s16 *)(arg1 + 0x11C) = dAngle(*(s16 *)(arg1 + 0x11C), arg3, 1.0f - Powerf(D_overlay_15_00F087B4, temp_f4));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o15/overlay_15/func_overlay_15_00F03564_1F16EE4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_15_00F03740_1F170C0(u8 *arg0, u8 *arg1, f32 arg2, s16 arg3, f32 arg4) {
    s32 sp30;
    f32 sp44;
    s32 sp4C;
    f32 temp_f0;
    f32 temp_f14;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f2_5;
    s16 temp_a1;
    s32 temp_f10;
    s32 temp_f18;
    s32 var_v0_2;
    s32 var_v1;
    s8 temp_v0_2;
    u8 temp_v0;
    u8 var_v0;
    u8 *pkeys;
    u8 skip16;

    arg1[0x576] = 0;
    if (!(*(s32 *)((u8 *) controlModeKeys + 0xC) & controlKeys)) {
        arg1[0x58E] = 1;
    }
    pkeys = *(u8 **)(arg1 + 0x360);
    if ((pkeys[5] & arg1[0x532]) && (arg1[0x57A] == 0)) {
        if (!(*(u16 *)(arg1 + 0x520) & 0x8000) || (arg1[0x5C8] != 0)) {
            arg1[0x14A] = 0;
            arg1[0x14B] = 0;
            *(f32 *)(arg1 + 0x594) = 0.0f;
            arg1[0x568] = arg1[0x56A];
            temp_f0 = *(f32 *)(arg1 + 0x57C) - *(f32 *)(arg0 + 0x10);
            if (arg1[0x1] == 0) {
                if (temp_f0 > 240.0f) {
                    arg1[0x190] = 0x80;
                } else if (temp_f0 > 400.0f) {
                    arg1[0x190] = 0xC0;
                }
            } else if (temp_f0 > 400.0f) {
                arg1[0x190] = 0x80;
            }
            if (temp_f0 > 120.0f) {
                func_overlay_15_00F05180_1F18B00(arg0, arg1, 0x1A, 0);
                arg1[0x56B] = 0x1E;
                arg1[0x568] = 0;
            } else {
                temp_v0 = arg1[0x568];
                if (temp_v0 == 2) {
                    func_overlay_15_00F05180_1F18B00(arg0, arg1, 4, 0);
                } else if (temp_v0 == 1) {
                    func_overlay_15_00F05180_1F18B00(arg0, arg1, 0xD, 0);
                } else {
                    func_overlay_15_00F05180_1F18B00(arg0, arg1, func_overlay_15_00F05020_1F189A0(arg1), 0);
                    arg1[0x568] = 0;
                }
            }
            charSpeak(arg0, 1);
            if (*(f32 *)(arg1 + 0x60) < 1.0f) {
                *(s32 *)(arg0 + 0x84) = *(s32 *)(arg0 + 0x84) | *(s32 *)(D_overlay_15_00F08338 + *(u8 *)((u8 *) levelGetLevel() + 0xE2) * 4);
            }
        }
    } else {
        temp_v0_2 = arg1[0x57A];
        if (temp_v0_2 > 0) {
            temp_f18 = (s32) arg4;
            arg1[0x57A] = (u8) (temp_v0_2 - temp_f18);
            if (*(s32 *)((u8 *) controlModeKeys + 0xC) & controlKeys) {
                arg1[0x57B] = (u8) (arg1[0x57B] + temp_f18);
            } else {
                arg1[0x57A] = 0;
            }
            if ((s8) arg1[0x57A] <= 0) {
                if (*(f32 *)(arg0 + 0x28) < 0.25f) {
                    *(f32 *)(arg0 + 0x28) = D_overlay_15_00F087B8;
                }
                arg1[0x57A] = 0;
                charSpeak(arg0, 0);
                if (arg1[0x569] != 0) {
                    *(f32 *)(arg0 + 0x20) = *(f32 *)(arg0 + 0x20) + 10.0f;
                } else {
                    var_v0 = arg1[0x57B];
                    if ((s32) var_v0 >= 0x19) {
                        arg1[0x57B] = 0x18;
                        var_v0 = 0x18;
                    }
                    *(f32 *)(arg0 + 0x20) = *(f32 *)(arg0 + 0x20) + (6.0f + ((6.0f * (f32) var_v0) / 24.0f));
                }
            }
            arg2 = 0.0f;
        } else if (arg1[0x14A] != 0) {
            *(f32 *)(arg0 + 0x28) = 0.0f;
            temp_f10 = (s32) arg4;
            sp30 = temp_f10;
            temp_f2 = *(f32 *)(arg1 + 0x57C);
            temp_a1 = *(s16 *)(arg1 + 0x58C);
            *(f32 *)(arg1 + 0x57C) = temp_f2 + ((*(f32 *)(arg0 + 0x10) - temp_f2) * (1.0f - Powerf(D_overlay_15_00F087BC, temp_f10)));
            if ((*(s32 *)((u8 *) controlModeKeys + 0x10) & controlKeys) && (temp_a1 > 0)) {
                *(s16 *)(arg1 + 0x58C) = (s16) (temp_a1 - temp_f10);
                arg1[0x591] = (u8) ((s8) arg1[0x591] + (temp_f10 * 2));
                sp4C = temp_a1;
                temp_f14 = 1.0f - Powerf(D_overlay_15_00F087C0, temp_f10);
                sp44 = temp_f14;
                temp_f2_2 = *(f32 *)(arg1 + 0x594);
                *(f32 *)(arg1 + 0x594) = temp_f2_2 + ((((Sinf((s16) ((s8) arg1[0x591] << 8)) * 0.125f) + 1.0f) - temp_f2_2) * temp_f14);
                *(f32 *)(arg0 + 0x20) = *(f32 *)(arg0 + 0x20) * Powerf(D_overlay_15_00F087C4, temp_f10);
                D_overlay_15_00F089C0 |= 1;
                D_overlay_15_00F089C4 |= 1;
            } else if ((*(s32 *)((u8 *) controlModeKeys + 0xC) & controlKeys) && (temp_a1 > 0)) {
                *(s16 *)(arg1 + 0x58C) = (s16) (temp_a1 - (temp_f10 * 2));
                sp4C = temp_a1;
                temp_f2_3 = *(f32 *)(arg1 + 0x594);
                *(f32 *)(arg1 + 0x594) = temp_f2_3 + ((1.0f - temp_f2_3) * (1.0f - Powerf(D_overlay_15_00F087C8, temp_f10)));
                temp_f2_4 = *(f32 *)(arg0 + 0x20);
                *(f32 *)(arg0 + 0x20) = temp_f2_4 + ((5.0f - temp_f2_4) * (1.0f - Powerf(D_overlay_15_00F087CC, temp_f10)));
                D_overlay_15_00F089C0 |= 2;
                D_overlay_15_00F089C4 |= 1;
            } else {
                sp4C = temp_a1;
                *(f32 *)(arg1 + 0x594) = *(f32 *)(arg1 + 0x594) * Powerf(D_overlay_15_00F087D0, temp_f10);
                if (*(f32 *)(arg1 + 0x594) < D_overlay_15_00F087D4) {
                    func_overlay_15_00F05180_1F18B00(arg0, arg1, 0x19, 0);
                    arg1[0x14A] = 0;
                    *(f32 *)(arg1 + 0x594) = 0.0f;
                }
            }
            if (temp_a1 != *(s16 *)(arg1 + 0x58C)) {
                *(s16 *)(arg1 + 0x592) = 0x168;
            }
            var_v1 = 0;
            if (*(s16 *)(arg1 + 0x58C) < 0x259) {
                var_v0_2 = 0;
                for (;;) {
                    if ((var_v0_2 >= *(s16 *)(arg1 + 0x58C)) && (var_v0_2 < temp_a1)) {
                        amSndPlay((var_v1 + 0x15F) & 0xFFFF, 0, 0);
                        break;
                    }
                    var_v1 += 1;
                    var_v0_2 += 0x3C;
                    if (var_v1 == 0xB) {
                        break;
                    }
                }
            }
            if (*(s32 *)((u8 *) controlModeKeys + 0x0) & controlKeys) {
                arg1[0x1F4] = 0xF;
            }
        } else if ((arg1[0x1] == 4) && (arg1[0x189] == 0) && (arg1[0x58E] != 0) && (*(s16 *)(arg1 + 0x58C) > 0) && ((*(s32 *)((u8 *) controlModeKeys + 0xC) | *(s32 *)((u8 *) controlModeKeys + 0x10)) & controlKeys)) {
            func_overlay_15_00F05180_1F18B00(arg0, arg1, 0x2E, 0);
            arg1[0x14B] = 0;
            arg1[0x14A] = 1;
            *(s16 *)(arg1 + 0x128) = *(s16 *)(arg1 + 0x11C);
        } else if (arg1[0x14B] == 0) {
            if (*(f32 *)(arg0 + 0x10) < (*(f32 *)(arg1 + 0x57C) - 120.0f)) {
                if (arg0[0x3B] != 0x19) {
                    func_overlay_15_00F05180_1F18B00(arg0, arg1, 0x19, 0);
                }
            }
        }
    }
    sp30 = (s32) arg4;
    controlWalkingBack(arg0, arg1, &arg2, arg3, 0x5000, 0x6800, 5.0f, 3.0f);
    if (arg1[0x569] == 0) {
        arg2 = -arg2;
    } else {
        arg3 += 0x8000;
    }
    temp_f2_5 = *(f32 *)(arg1 + 0x4);
    *(f32 *)(arg1 + 0x4) = ((1.0f - Powerf(1.0f - ((*(f32 *)(arg1 + 0x594) * D_overlay_15_00F087D8) + D_overlay_15_00F087DC), sp30)) * (arg2 - temp_f2_5)) + temp_f2_5;
    *(s16 *)(arg1 + 0x11C) = dAngle(*(s16 *)(arg1 + 0x11C), arg3, 1.0f - Powerf(1.0f - ((*(f32 *)(arg1 + 0x594) * D_overlay_15_00F087E0) + D_overlay_15_00F087E4), sp30));
    if (arg1[0x14A] != 0) {
        *(s16 *)(arg1 + 0x128) = dAngle(*(s16 *)(arg1 + 0x128), *(s16 *)(arg1 + 0x11C), 1.0f - Powerf(D_overlay_15_00F087E8, sp30));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o15/overlay_15/func_overlay_15_00F03740_1F170C0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_15_00F04088_1F17A08(s16 arg0, s16 arg1, s32 arg2, s16 arg3) {
    u8 *p = D_overlay_15_00F089C8;
    s32 temp_v0;

    *(s16 *) p = 0x12;
    temp_v0 = arg0 >> 1;
    p += 2; *(s16 *)(p + 2) = (s16) temp_v0;
    p += 2; *(s16 *)(p + 2) = 0x14;
    p += 2; *(s16 *)(p + 2) = arg1;
    p += 2; *(s16 *)(p + 2) = 6;
    p += 2; *(s16 *)(p + 2) = (s16) temp_v0;
    p += 2; *(s16 *)(p + 2) = 0x3C;
    p += 2; *(s16 *)(p + 2) = (s16) (arg2 - temp_v0);
    p += 2; *(s16 *)(p + 2) = 0x3E;
    p += 2; *(s16 *)(p + 2) = arg3;
    p += 2;
    D_overlay_15_00F089C8 = p;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o15/overlay_15/func_overlay_15_00F04088_1F17A08.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_15_00F0418C_1F17B0C(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, f32 arg4) {
    s16 sp56;
    s16 sp54;
    f32 sp4C;
    s32 sp3C;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    s16 temp_v1;
    s16 var_v1;
    s32 temp_f6;
    s8 temp_a1;
    u8 *p;

    mainGetGameCharacter((s8) arg1[0], (s8) arg1[1]);
    arg1[0x576] = 0;
    arg1[0x13E] = 0;
    if (!(controlKeys & 0x10) && (D_overlay_15_00F089CC == 0)) {
        arg1[0x568] = 1;
        *(s16 *)(arg1 + 0x104) = (s16) (0x8000 - *(s16 *)arg0);
        return;
    }
    temp_f6 = (s32) arg4;
    sp3C = temp_f6;
    *(f32 *)(arg1 + 0x10) = *(f32 *)(arg1 + 0x10) * Powerf(D_overlay_15_00F087EC, temp_f6);
    temp_f2 = *(f32 *)(arg1 + 0x10);
    if ((D_overlay_15_00F087F0 < temp_f2) && (temp_f2 < D_overlay_15_00F087F4)) {
        *(f32 *)(arg1 + 0x10) = 0.0f;
    }
    *(f32 *)(arg1 + 0x4) = *(f32 *)(arg1 + 0x4) * Powerf(D_overlay_15_00F087F8, sp3C);
    temp_f2_2 = *(f32 *)(arg1 + 0x4);
    if ((D_overlay_15_00F087FC < temp_f2_2) && (temp_f2_2 < D_overlay_15_00F08800)) {
        *(f32 *)(arg1 + 0x4) = 0.0f;
    }
    if (D_overlay_15_00F089CC == 0) {
        if (controlGetManualAim(arg0, arg1, 0xE38, 0xE38, -0x2AAA, 0x2AAA, &sp56, &sp54, arg4) != 0) {
            camSetZoom((s8) arg1[0], *(s32 *)(arg1 + 0x1EC));
        }
    } else {
        sp56 = *(s16 *)(arg1 + 0x1DC);
        sp54 = (s16) (*(s16 *)(arg1 + 0x1DE) - *(s16 *)(arg1 + 0x1E2));
    }
    temp_f2_3 = 1.0f - Powerf(D_overlay_15_00F08804, sp3C);
    if (*(s16 *)(arg1 + 0x1E2) < -0xA80) {
        *(s16 *)(arg1 + 0x1E2) = -0xA80;
    }
    if (*(s16 *)(arg1 + 0x1E2) >= 0x1556) {
        *(s16 *)(arg1 + 0x1E2) = 0x1555;
    }
    sp4C = temp_f2_3;
    *(s16 *)(arg1 + 0x1E0) = dAngle(*(s16 *)(arg1 + 0x1E0), sp54, temp_f2_3);
    sp54 += *(s16 *)(arg1 + 0x1E2);
    *(s16 *)(arg1 + 0x1DC) = dAngle(*(s16 *)(arg1 + 0x1DC), sp56, sp4C);
    *(s16 *)(arg1 + 0x1DE) = dAngle(*(s16 *)(arg1 + 0x1DE), sp54, sp4C);
    *(s16 *)(arg1 + 0x1CE) = dAngle(*(s16 *)(arg1 + 0x1CE), sp56, sp4C);
    *(s16 *)(arg1 + 0x1D0) = dAngle(*(s16 *)(arg1 + 0x1D0), sp54, sp4C);
    temp_v1 = *(s16 *)(arg1 + 0x1CE);
    *(s16 *)(arg1 + 0x1C6) = (s16) (temp_v1 + *(s16 *)arg0);
    *(s16 *)(arg1 + 0x1CA) = *(s16 *)(arg1 + 0x1C6);
    *(s16 *)(arg1 + 0x1C8) = (s16) (*(s16 *)(arg1 + 0x1D0) + *(s16 *)(arg0 + 0x2));
    *(s16 *)(arg1 + 0x1CC) = *(s16 *)(arg1 + 0x1C8);
    sp56 = temp_v1;
    var_v1 = 0;
    sp54 = *(s16 *)(arg1 + 0x1D0);
    temp_a1 = (s8) arg1[0x1F6];
    if (temp_a1 != 0) {
        var_v1 = (s16) (((s32) (mathSin((s16) (temp_a1 << 0xC), temp_a1) * (s8) arg1[0x1F7])) >> 9);
    }
    p = D_overlay_15_00F089C8;
    *(s16 *) p = 6;
    p += 2; *(s16 *)(p + 2) = (s16) (sp54 + var_v1);
    p += 2; *(s16 *)(p + 2) = 8;
    p += 2; *(s16 *)(p + 2) = sp56;
    p += 2; *(s16 *)(p + 2) = 0x12;
    p += 2; *(s16 *)(p + 2) = var_v1;
    p += 2; *(s16 *)(p + 2) = 0x3C;
    p += 2; *(s16 *)(p + 2) = (s16) (*(s16 *)(arg1 + 0x1DE) - sp54);
    p += 2; *(s16 *)(p + 2) = 0x3E;
    p += 2; *(s16 *)(p + 2) = (s16) (*(s16 *)(arg1 + 0x1DC) - sp56);
    p += 2;
    D_overlay_15_00F089C8 = p;
    if (((frontGetTargetControl((s8) arg1[0]) != 0) && ((*(s32 *)((u8 *) controlModeKeys + 0x20) | *(s32 *)((u8 *) controlModeKeys + 0x1C)) & controlKeys)) || (*(s32 *)((u8 *) controlModeKeys + 0xC) & controlDkeys)) {
        arg1[0x568] = 0xB;
        func_overlay_15_00F05180_1F18B00(arg0, arg1, func_overlay_15_00F05020_1F189A0(arg1), 0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o15/overlay_15/func_overlay_15_00F0418C_1F17B0C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_15_00F04658_1F17FD8(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, f32 arg4) {
    s16 sp56;
    s16 sp54;
    f32 sp50;
    u8 *sp4C;
    s32 sp3C;
    f32 temp_f2_2;
    f32 var_f0;
    s16 temp_v1;
    s32 temp_a0;
    s32 temp_f16;
    s8 temp_a1;
    u8 *temp_v0;

    temp_v0 = mainGetGameCharacter((s8) arg1[0], (s8) arg1[1]);
    arg1[0x576] = 0;
    arg1[0x13E] = 0;
    if (!(controlKeys & 0x10) && (D_overlay_15_00F089CC == 0)) {
        arg1[0x568] = 0;
        *(s16 *)(arg1 + 0x104) = (s16) (0x8000 - *(s16 *)arg0);
        return;
    }
    sp4C = temp_v0;
    temp_a0 = 0;
    if ((frontGetTargetControl((s8) arg1[0]) != 0) && (temp_v0[0x70] != 7) && (temp_a0 = *(s32 *)((u8 *) controlModeKeys + 0x1C), (((*(s32 *)((u8 *) controlModeKeys + 0x20) | temp_a0) & controlKeys) != 0))) {
        if (temp_a0 & controlKeys) {
            *(f32 *)(arg1 + 0x4) = *(f32 *)(arg1 + 0x4) - (D_overlay_15_00F08808 * arg4);
            var_f0 = -(65.0f * D_overlay_15_00F089D4);
            if (*(f32 *)(arg1 + 0x4) < var_f0) {
                *(f32 *)(arg1 + 0x4) = var_f0;
            }
        } else {
            var_f0 = 3.0f;
            *(f32 *)(arg1 + 0x4) = *(f32 *)(arg1 + 0x4) + (D_overlay_15_00F0880C * arg4);
            if (*(f32 *)(arg1 + 0x4) > 3.0f) {
                *(f32 *)(arg1 + 0x4) = var_f0;
            }
        }
        sp3C = (s32) arg4;
    } else {
        temp_f16 = (s32) arg4;
        sp3C = temp_f16;
        *(f32 *)(arg1 + 0x4) = *(f32 *)(arg1 + 0x4) * Powerf(D_overlay_15_00F08810, temp_f16);
        if ((D_overlay_15_00F08814 < *(f32 *)(arg1 + 0x4)) && (*(f32 *)(arg1 + 0x4) < D_overlay_15_00F08818)) {
            *(f32 *)(arg1 + 0x4) = 0.0f;
        }
    }
    func_overlay_15_00F04B4C_1F184CC(arg0, arg1, 0, arg4);
    if (D_overlay_15_00F089CC == 0) {
        if (controlGetManualAim(arg0, arg1, 0xE38, 0xE38, -0x2AAA, 0x2AAA, &sp56, &sp54, arg4) != 0) {
            camSetZoom((s8) arg1[0], *(s32 *)(arg1 + 0x1EC));
        }
    } else {
        sp56 = *(s16 *)(arg1 + 0x1DC);
        sp54 = (s16) (*(s16 *)(arg1 + 0x1DE) - *(s16 *)(arg1 + 0x1E2));
    }
    temp_f2_2 = 1.0f - Powerf(D_overlay_15_00F0881C, sp3C);
    sp50 = temp_f2_2;
    *(s16 *)(arg1 + 0x1E0) = dAngle(*(s16 *)(arg1 + 0x1E0), sp54, temp_f2_2);
    sp54 += *(s16 *)(arg1 + 0x1E2);
    *(s16 *)(arg1 + 0x1DC) = dAngle(*(s16 *)(arg1 + 0x1DC), sp56, sp50);
    *(s16 *)(arg1 + 0x1DE) = dAngle(*(s16 *)(arg1 + 0x1DE), sp54, sp50);
    *(s16 *)(arg1 + 0x1CE) = dAngle(*(s16 *)(arg1 + 0x1CE), sp56, sp50);
    *(s16 *)(arg1 + 0x1D0) = dAngle(*(s16 *)(arg1 + 0x1D0), sp54, sp50);
    temp_v1 = *(s16 *)(arg1 + 0x1CE);
    *(s16 *)(arg1 + 0x1C6) = (s16) (temp_v1 + *(s16 *)arg0);
    *(s16 *)(arg1 + 0x1CA) = *(s16 *)(arg1 + 0x1C6);
    *(s16 *)(arg1 + 0x1C8) = (s16) (*(s16 *)(arg1 + 0x1D0) + *(s16 *)(arg0 + 0x2));
    *(s16 *)(arg1 + 0x1CC) = *(s16 *)(arg1 + 0x1C8);
    sp56 = temp_v1;
    sp54 = *(s16 *)(arg1 + 0x1D0);
    temp_a1 = (s8) arg1[0x1F6];
    if (temp_a1 != 0) {
        sp54 += (s16) (((s32) (arg1[0x1F7] * mathSin((s16) (temp_a1 << 0xC), temp_a1))) >> 8);
    }
    func_overlay_15_00F04088_1F17A08(sp54, sp56, *(s16 *)(arg1 + 0x1DE), *(s16 *)(arg1 + 0x1DC));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o15/overlay_15/func_overlay_15_00F04658_1F17FD8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_15_00F04A58_1F183D8(s32 arg0, u8 *arg1, s32 arg2) {
    f32 temp_f12;
    f32 var_f0;
    f32 var_f14;
    s32 var_s0;
    s32 var_s2;
    u8 *p;

    var_f14 = *(f32 *)(arg1 + 0x4);
    temp_f12 = *(f32 *)(arg1 + 0x10);
    var_f0 = temp_f12;
    if (var_f14 < 0.0f) {
        var_f14 = -var_f14;
    }
    var_s2 = 0;
    if (var_f0 < 0.0f) {
        var_f0 = -var_f0;
    }
    if (var_f0 < var_f14) {
        var_s2 = -(s32) Arctanf(temp_f12, var_f14);
    }
    var_s0 = arg2 - 1;
    if (arg2 != 0) {
        do {
            *(s32 *)(arg1 + 0x580) = *(s32 *)(arg1 + 0x580) + (mathDiffAngle(*(s32 *)(arg1 + 0x580), var_s2) >> 4);
            var_s0 -= 1;
        } while (var_s0 != 0);
    }
    p = D_overlay_15_00F089C8;
    *(s16 *) p = 0x56;
    p += 2; *(s16 *)(p + 2) = (s16) *(s32 *)(arg1 + 0x580);
    p += 2;
    D_overlay_15_00F089C8 = p;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o15/overlay_15/func_overlay_15_00F04A58_1F183D8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_15_00F04B4C_1F184CC(u8 *a0, u8 *a1, s32 a2, f32 a3) {
    s32 sp34;
    f32 sp20;
    u8 *var_a2;
    f32 temp_f12;
    f32 temp_f2;
    f32 var_f0;
    f32 var_f14;
    f32 var_f2;
    s8 temp_v0;
    s8 temp_v1;
    s8 var_v1;

    var_v1 = a1[0x584];
    a1[0x56C] = 0;
    if (((var_v1 == 1) || (var_v1 == 2) || (var_v1 == 3) || (var_v1 == 4)) && (*(f32 *)(a0 + 0x28) == 1.0f)) {
        a1[0x584] = 0;
        var_v1 = a1[0x584];
        *(f32 *)(a1 + 0x10) = 0.0f;
    }
    if (var_v1 == 0) {
        if (a2 == 2) {
            if (*(s32 *)((u8 *) controlModeKeys + 0x14) & controlKeys) {
                a1[0x584] = 3;
                func_overlay_15_00F05180_1F18B00(a0, a1, 0x33, 0);
                *(f32 *)(a0 + 0x28) = 0.0f;
                a1[0x56C] = 1;
            } else if (*(s32 *)((u8 *) controlModeKeys + 0x18) & controlKeys) {
                a1[0x584] = 4;
                func_overlay_15_00F05180_1F18B00(a0, a1, 0xC, 0);
                *(f32 *)(a0 + 0x28) = 0.0f;
                a1[0x56C] = 1;
            }
        } else if (a2 == 1) {
            if (*(s32 *)((u8 *) controlModeKeys + 0x14) & controlKeys) {
                a1[0x584] = 1;
                func_overlay_15_00F05180_1F18B00(a0, a1, 0x32, 0);
                *(f32 *)(a0 + 0x28) = 0.0f;
                a1[0x56C] = 1;
            } else if (*(s32 *)((u8 *) controlModeKeys + 0x18) & controlKeys) {
                a1[0x584] = 2;
                func_overlay_15_00F05180_1F18B00(a0, a1, 0xB, 0);
                *(f32 *)(a0 + 0x28) = 0.0f;
                a1[0x56C] = 1;
            }
        } else {
            if (*(s32 *)((u8 *) controlModeKeys + 0x14) & controlKeys) {
                *(f32 *)(a1 + 0x10) = *(f32 *)(a1 + 0x10) - (D_overlay_15_00F08820 * a3);
                if (*(f32 *)(a1 + 0x10) < -2.5f) {
                    *(f32 *)(a1 + 0x10) = -2.5f;
                }
                sp34 = 9;
                a1[0x56C] = 1;
            } else if (*(s32 *)((u8 *) controlModeKeys + 0x18) & controlKeys) {
                *(f32 *)(a1 + 0x10) = *(f32 *)(a1 + 0x10) + (D_overlay_15_00F08824 * a3);
                if (*(f32 *)(a1 + 0x10) > 2.5f) {
                    *(f32 *)(a1 + 0x10) = 2.5f;
                }
                sp34 = 0xA;
                a1[0x56C] = 1;
            }
            if (a1[0x56C] != 0) {
                var_f0 = *(f32 *)(a1 + 0x10);
                if (var_f0 < 0.0f) {
                    var_f0 = -var_f0;
                }
                var_f2 = *(f32 *)(a1 + 0x4);
                if (var_f2 < 0.0f) {
                    var_f2 = -var_f2;
                }
                if (var_f2 < var_f0) {
                    func_overlay_15_00F05180_1F18B00(a0, a1, sp34, *(s32 *)(a0 + 0x28));
                }
            }
        }
    }
    temp_v0 = a1[0x584];
    var_a2 = NULL;
    switch (temp_v0) {
    case 3:
        if (a0[0x3B] == 0x33) {
            var_a2 = D_overlay_15_00F08644;
            sp20 = D_overlay_15_00F08828;
        }
        break;
    case 4:
        if (a0[0x3B] == 0xC) {
            var_a2 = D_overlay_15_00F08644;
            sp20 = D_overlay_15_00F0882C;
        }
        break;
    case 1:
        if (a0[0x3B] == 0x32) {
            var_a2 = D_overlay_15_00F08674;
            sp20 = D_overlay_15_00F08830;
        }
        break;
    case 2:
        if (a0[0x3B] == 0xB) {
            var_a2 = D_overlay_15_00F08674;
            sp20 = D_overlay_15_00F08834;
        }
        break;
    }
    if (var_a2 != NULL) {
        temp_f12 = *(f32 *)(a0 + 0x28);
        var_f14 = temp_f12 + (sp20 * a3);
        if (var_f14 < 0.0f) {
            var_f14 = 0.0f;
        }
        if (var_f14 > 1.0f) {
            var_f14 = 1.0f;
        }
        temp_v1 = a1[0x584];
        *(f32 *)(a1 + 0x10) = controlMakeV(temp_f12, var_f14, a0, var_a2, a3);
        if ((temp_v1 == 3) || (temp_v1 == 1)) {
            *(f32 *)(a1 + 0x10) = -*(f32 *)(a1 + 0x10);
        }
        a1[0x56C] = 1;
    }
    if (a1[0x56C] == 0) {
        a1[0x584] = 0;
        *(f32 *)(a1 + 0x10) = *(f32 *)(a1 + 0x10) * Powerf(D_overlay_15_00F08838, (s32) a3);
        temp_f2 = *(f32 *)(a1 + 0x10);
        if ((D_overlay_15_00F0883C < temp_f2) && (temp_f2 < D_overlay_15_00F08840)) {
            *(f32 *)(a1 + 0x10) = 0.0f;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o15/overlay_15/func_overlay_15_00F04B4C_1F184CC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_15_00F05020_1F189A0(u8 *a0) {
    f32 var_f0;
    f32 var_f2;
    f32 var_f12;
    f32 temp_f14;
    s32 var_v1;

    var_f0 = *(f32 *)(a0 + 0x4);
    if (var_f0 < 0.0f) {
        var_f0 = -var_f0;
    }
    temp_f14 = *(f32 *)(a0 + 0x10);
    var_f2 = temp_f14;
    if (temp_f14 < 0.0f) {
        var_f2 = -var_f2;
    }
    var_f12 = var_f0;
    if (var_f0 < var_f2) {
        var_f12 = var_f2;
    }
    if (var_f12 < D_overlay_15_00F08844) {
        if (a0[0x1FA] != 0) {
            var_v1 = 0x10;
        } else if (a0[0x1F9] != 0) {
            var_v1 = 0x10;
        } else if (a0[0x198] != 0) {
            var_v1 = 0x10;
        } else {
            var_v1 = mathRnd(0x10, 0x15);
        }
    } else if (var_f0 < var_f2) {
        if (temp_f14 < 0.0f) {
            var_v1 = 9;
        } else {
            var_v1 = 0xA;
        }
    } else if (a0[0x569] != 0) {
        var_v1 = 3;
    } else if (var_f12 > 3.0f) {
        var_v1 = 2;
    } else {
        var_v1 = 0;
        if (var_f12 > 1.75f) {
            var_v1 = 1;
        }
    }
    return var_v1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o15/overlay_15/func_overlay_15_00F05020_1F189A0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_15_00F05180_1F18B00(u8 *a0, u8 *a1, s32 a2, s32 a3) {
    u8 var_a3;
    u8 var_s0;

    if (a1[0x5CC] != 0) {
        var_a3 = D_overlay_15_00F08130[a2 * 5 + 2];
        var_s0 = D_overlay_15_00F08130[var_a3 * 5 + 3];
    } else if ((a1[0x1F4] != 0) && (controlPlayerGunWeight(a1, a2) != 0)) {
        var_a3 = D_overlay_15_00F08130[a2 * 5 + 1];
        var_s0 = D_overlay_15_00F08130[var_a3 * 5 + 4];
    } else if (((s32 (*)(u8 *))controlPlayerGunWeight)(a1) != 0) { /* sig mismatch: 1-arg call */
        var_a3 = D_overlay_15_00F08130[a2 * 5 + 2];
        var_s0 = D_overlay_15_00F08130[var_a3 * 5 + 3];
    } else {
        var_a3 = D_overlay_15_00F08130[a2 * 5];
        var_s0 = D_overlay_15_00F08130[var_a3 * 5 + 3];
    }
    if (var_a3 != a0[0x3B]) {
        objAnimSetMove(a0, var_a3, a3, var_a3);
        D_overlay_15_00F089D0 += 1;
    }
    controlSetTransition(a0, a1, D_overlay_15_00F0807C, var_s0 & 0xFF);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o15/overlay_15/func_overlay_15_00F05180_1F18B00.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_15_00F05328_1F18CA8(u8 *arg0, u8 *arg1, f32 arg2, f32 arg3) {
    f32 sp38;
    f32 sp34;
    f32 sp30;
    f32 sp28;
    f32 sp24;
    f32 temp_f0;
    f32 temp_f18;
    f32 temp_f4;
    f32 temp_f8;
    f32 var_f12;
    f32 var_f14;
    f32 var_f16;
    f32 var_f2;
    s8 temp_v0;
    s8 var_s0;

    temp_f4 = *(f32 *)(arg1 + 0x4);
    sp28 = temp_f4;
    var_f16 = temp_f4;
    if (temp_f4 < 0.0f) {
        var_f16 = -temp_f4;
    }
    temp_f8 = *(f32 *)(arg1 + 0x10);
    sp24 = temp_f8;
    var_f14 = temp_f8;
    if (temp_f8 < 0.0f) {
        var_f14 = -temp_f8;
    }
    temp_f18 = *(f32 *)(arg0 + 0x20);
    var_f12 = temp_f18;
    if (temp_f18 < 0.0f) {
        var_f12 = -var_f12;
    }
    var_f2 = var_f16;
    if (var_f16 < var_f14) {
        var_f2 = var_f14;
    }
    temp_v0 = arg0[0x3B];
    temp_f0 = *(f32 *)(arg0 + 0x28);
    var_s0 = temp_v0;
    sp34 = temp_f0;
    sp30 = temp_f0;
    sp38 = *(f32 *)(D_overlay_15_00F0823C + (temp_v0 * 4));
    switch (temp_v0) {
    case 0x0:
    case 0x1D:
    case 0x26:
        sp38 *= var_f2;
        if (arg1[0x569] != 0) {
            var_s0 = 3;
        } else if (var_f2 < D_overlay_15_00F0891C) {
            var_s0 = ((arg1[0x1FA] != 0) || (arg1[0x1F9] != 0) || (arg1[0x198] != 0)) ? 0x10 : mathRnd(0x10, 0x15);
            sp34 = 0.0f;
        } else if (var_f16 < var_f14) {
            var_s0 = (sp24 < 0.0f) ? 9 : 10;
            sp34 = 0.25f;
        } else if (var_f2 > 1.75f) {
            var_s0 = 1;
        }
        break;
    case 0x1:
    case 0x1E:
    case 0x27:
        sp38 *= var_f2;
        if (var_f16 < var_f14) {
            var_s0 = (sp24 < 0.0f) ? 9 : 10;
            sp34 = 0.25f;
        } else if (var_f2 < 1.75f) {
            var_s0 = 0;
        } else if (var_f2 > 3.0f) {
            var_s0 = 2;
        }
        break;
    case 0x2:
    case 0x1F:
    case 0x28:
        sp38 *= var_f2;
        if (var_f16 < var_f14) {
            var_s0 = (sp24 < 0.0f) ? 9 : 10;
            sp34 = 0.25f;
        } else if (var_f2 < 3.0f) {
            var_s0 = 1;
        }
        break;
    case 0x3:
    case 0x1B:
    case 0x29:
        sp38 *= var_f2;
        if ((var_f2 < D_overlay_15_00F08920) && (arg2 <= sp28)) {
            var_s0 = ((arg1[0x1FA] != 0) || (arg1[0x1F9] != 0) || (arg1[0x198] != 0)) ? 0x10 : mathRnd(0x10, 0x15);
            sp34 = 0.0f;
        } else if (var_f16 < var_f14) {
            var_s0 = (sp24 < 0.0f) ? 9 : 10;
            sp34 = 0.25f;
        } else if (arg1[0x569] == 0) {
            var_s0 = 0;
        }
        break;
    case 0x4:
        sp38 *= var_f2;
        if (var_f2 < D_overlay_15_00F08924) {
            var_s0 = 0x17;
            sp34 = 0.0f;
        }
        break;
    case 0x5:
        if ((temp_f0 + (sp38 * arg3)) > 0.75f) {
            *(f32 *)(arg0 + 0x28) = 0.75f;
            sp38 = 0.0f;
        }
        break;
    case 0x8:
        if (temp_f0 == 1.0f) {
            var_s0 = func_overlay_15_00F05020_1F189A0(arg1);
            sp34 = 0.0f;
        }
        break;
    case 0x9:
    case 0xA:
    case 0x20:
    case 0x21:
    case 0x2A:
    case 0x2B:
        sp38 *= var_f14;
        if ((var_f2 < D_overlay_15_00F08928) && (arg1[0x56C] == 0)) {
            var_s0 = ((arg1[0x1FA] != 0) || (arg1[0x1F9] != 0) || (arg1[0x198] != 0)) ? 0x10 : mathRnd(0x10, 0x15);
            sp34 = 0.0f;
        } else if (var_f14 < var_f16) {
            if (arg1[0x569] != 0) {
                var_s0 = 3;
            } else if (var_f16 < 1.75f) {
                var_s0 = 0;
            } else {
                var_s0 = 2;
                if (var_f16 < 3.0f) {
                    var_s0 = 1;
                }
            }
            sp34 = 0.25f;
        }
        break;
    case 0xB:
        if (arg1[0x584] != 2) {
            var_s0 = 0xE;
            sp34 = 0.0f;
        }
        break;
    case 0x32:
        if (arg1[0x584] != 1) {
            var_s0 = 0xE;
            sp34 = 0.0f;
        }
        break;
    case 0xC:
        if (arg1[0x584] != 4) {
            var_s0 = 4;
            if (var_f2 < D_overlay_15_00F0892C) {
                var_s0 = 0x17;
            }
            sp34 = 0.0f;
        }
        break;
    case 0x33:
        if (arg1[0x584] != 3) {
            var_s0 = 4;
            if (var_f2 < D_overlay_15_00F08930) {
                var_s0 = 0x17;
            }
            sp34 = 0.0f;
        }
        break;
    case 0xD:
        if (controlKeys & 0x10) {
            sp38 *= 2.0f;
        }
        if (D_overlay_15_00F08934 < temp_f0) {
            var_s0 = 0xE;
        }
        sp34 = 0.0f;
        break;
    case 0xE:
    case 0x22:
        if (D_overlay_15_00F08938 < var_f2) {
            var_s0 = 4;
            sp34 = 0.0f;
        }
        break;
    case 0xF:
        if (arg1[0x576] == 0) {
            var_s0 = 0;
            sp34 = 0.0f;
        }
        break;
    case 0x10:
    case 0x11:
    case 0x12:
    case 0x13:
    case 0x14:
    case 0x15:
    case 0x1C:
        if ((temp_f0 + (sp38 * arg3)) > 1.0f) {
            if ((arg1[0x1FA] != 0) || (arg1[0x1F9] != 0) || (arg1[0x198] != 0)) {
                var_s0 = 0x10;
            } else {
                var_s0 = mathRnd(0x10, 0x15);
            }
            arg0[0x3B] = -1;
            sp34 = 0.0f;
        }
        if (D_overlay_15_00F0893C < var_f2) {
            var_s0 = 3;
            if (arg1[0x569] == 0) {
                var_s0 = 0;
            }
            sp34 = 0.25f;
        }
        break;
    case 0x16:
    case 0x31:
        if (D_overlay_15_00F08940 < temp_f0) {
            temp_v0 = arg1[0x568];
            var_s0 = 0xE;
            if ((temp_v0 == 1) || (temp_v0 == 5)) {
                sp34 = 0.0f;
            } else {
                var_s0 = func_overlay_15_00F05020_1F189A0(arg1);
                sp34 = 0.0f;
            }
        }
        break;
    case 0x17:
        if (D_overlay_15_00F08944 < var_f2) {
            var_s0 = 4;
            sp34 = 0.0f;
        }
        break;
    case 0x2C:
        if (((D_overlay_15_00F08948 < var_f2) || (D_overlay_15_00F08948 < temp_f18))
            && (*(u8 *)(*(u8 **)(*(u8 **)(arg0 + 0x6C) + arg0[0x3A] * 4) + 0x5E) == 0)) {
            var_s0 = 0x2D;
            sp34 = 0.0f;
        } else if (arg1[0x1FB] != 0) {
            var_s0 = 0x34;
            sp34 = 0.0f;
        } else if (var_f12 > 1.0f) {
            sp38 *= var_f12;
        }
        break;
    case 0x34:
        if (((D_overlay_15_00F0894C < var_f2) || (D_overlay_15_00F0894C < temp_f18))
            && (*(u8 *)(*(u8 **)(*(u8 **)(arg0 + 0x6C) + arg0[0x3A] * 4) + 0x5E) == 0)) {
            var_s0 = 0x2D;
            sp34 = 0.0f;
        } else if (arg1[0x1FB] == 0) {
            var_s0 = 0x2C;
            sp34 = 0.0f;
        } else if (var_f12 > 1.0f) {
            sp38 *= var_f12;
        }
        break;
    case 0x2D:
        if ((var_f2 < 0.5f) && (temp_f18 < 0.5f)
            && (*(u8 *)(*(u8 **)(*(u8 **)(arg0 + 0x6C) + arg0[0x3A] * 4) + 0x5E) == 0)) {
            var_s0 = 0x34;
            if (arg1[0x1FB] == 0) {
                var_s0 = 0x2C;
            }
            sp34 = 0.0f;
        } else if (var_f2 < var_f12) {
            sp38 *= var_f12;
        } else {
            sp38 *= var_f2;
        }
        break;
    case 0x24:
        if ((temp_f0 + (sp38 * arg3)) > 1.0f) {
            var_s0 = 0x19;
            sp34 = 0.0f;
        }
        break;
    case 0x25:
        if ((temp_f0 + (sp38 * arg3)) > 1.0f) {
            var_s0 = 0x23;
            sp34 = 0.0f;
        }
        break;
    case 0x2F:
        if ((arg1[0x19F] == 0) && (arg1[0x10D] == 0)) {
            var_s0 = func_overlay_15_00F05020_1F189A0(arg1);
            sp34 = 0.0f;
        }
        break;
    case 0x30:
        if (arg1[0x1FA] == 0) {
            var_s0 = func_overlay_15_00F05020_1F189A0(arg1);
            sp34 = 0.0f;
        } else if ((temp_f0 < D_overlay_15_00F08950) && (D_overlay_15_00F08950 <= (temp_f0 + (sp38 * arg3)))) {
            D_overlay_15_00F089CE = 1;
        }
        break;
    }
    objAnimDframe(arg0, sp38, arg3);
    charAnimSoundTick(arg0, sp30, sp38);
    func_overlay_15_00F022C4_1F15C44(arg0, arg1, sp30, sp38);
    func_overlay_15_00F05180_1F18B00(arg0, arg1, (s32) var_s0, *(s32 *)&sp34);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o15/overlay_15/func_overlay_15_00F05328_1F18CA8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_15_00F05ED4_1F19854(u8 *arg0, u8 *arg1, f32 arg2) {
    f32 sp3C;
    f32 sp44;
    f32 sp4C;
    s32 sp34;
    s16 sp2C;
    s16 sp2E;
    s16 sp30;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f0_4;
    f32 temp_f0_5;
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 temp_f2_5;
    f32 temp_f2_6;
    f32 var_f0;
    f32 var_f0_2;
    f32 var_f12;
    f32 var_f14;
    s16 var_a0;
    s16 var_a0_2;
    s16 var_a2;
    s16 var_a2_2;
    s16 var_a2_3;
    s32 temp_v0_3;
    s8 temp_v0_4;
    u8 temp_v0;
    u8 temp_v0_2;

    *(f32 *)(arg0 + 0x20) = *(f32 *)(arg0 + 0x20) - ((1.0f - *(f32 *)(arg1 + 0x594)) * (controlchr_gravity * arg2));
    temp_v0 = arg1[0x568];
    *(f32 *)(arg1 + 0x74) = *(f32 *)(arg0 + 0x20);
    if ((temp_v0 != 2) && (temp_v0 != 0xA)) {
        temp_f2 = *(f32 *)(arg1 + 0x50);
        if (temp_f2 < 0.0f) {
            var_f0 = -temp_f2 - D_overlay_15_00F08954;
            if (var_f0 < 0.0f) {
                var_f0 = 0.0f;
            }
            if (D_overlay_15_00F08958 < var_f0) {
                var_f0 = D_overlay_15_00F08958;
            }
            var_f0_2 = var_f0 * 35.0f;
        } else {
            var_f0_2 = 0.0f;
        }
        *(f32 *)(arg1 + 0x4) = *(f32 *)(arg1 + 0x4) + (controlchr_gravity * (temp_f2 / (4.0f - var_f0_2)) * arg2);
    }
    *(f32 *)(arg1 + 0x8) = 0.0f;
    *(s16 *)arg0 = *(s16 *)(arg1 + 0x11C);
    temp_v0_2 = arg1[0x568];
    if ((temp_v0_2 == 4) || ((temp_v0_2 == 3) && (arg1[0x14A] != 0))) {
        var_a2 = *(s16 *)(arg1 + 0x128);
    } else {
        var_a2 = *(s16 *)(arg1 + 0x11C);
    }
    var_a0 = var_a2;
    if (arg1[0x13E] != 0) {
        var_a2 = *(s16 *)(arg1 + 0x13C);
        var_a0 = var_a2;
    }
    sp2E = var_a2;
    sp3C = Sinf(var_a0);
    temp_f0 = Cosf((s32) sp2E);
    if (arg1[0x568] != 0xC) {
        *(f32 *)(arg0 + 0x1C) = *(f32 *)(arg1 + 0x4) * sp3C;
        *(f32 *)(arg0 + 0x24) = *(f32 *)(arg1 + 0x4) * temp_f0;
    }
    var_a2_2 = *(s16 *)(arg1 + 0x11C);
    var_a0_2 = var_a2_2;
    if (arg1[0x13E] != 0) {
        var_a2_2 = *(s16 *)(arg1 + 0x13C);
        var_a0_2 = var_a2_2;
    }
    sp2E = var_a2_2;
    *(f32 *)(arg0 + 0x1C) = *(f32 *)(arg0 + 0x1C) + (*(f32 *)(arg1 + 0x10) * Cosf((s32) var_a0_2));
    var_f12 = *(f32 *)(arg0 + 0x1C);
    *(f32 *)(arg0 + 0x24) = *(f32 *)(arg0 + 0x24) - (*(f32 *)(arg1 + 0x10) * Sinf(sp2E));
    var_f14 = *(f32 *)(arg0 + 0x24);
    if (arg1[0x149] != 0) {
        var_f12 += *(f32 *)(arg1 + 0x6C);
        var_f14 += *(f32 *)(arg1 + 0x70);
    }
    if (disablejoy == 1) {
        var_f12 *= D_overlay_15_00F0895C;
        temp_f2_2 = *(f32 *)(arg1 + 0x4);
        var_f14 *= D_overlay_15_00F0895C;
        if ((temp_f2_2 < -0.5f) || (temp_f2_2 > 0.5f)) {
            *(f32 *)(arg1 + 0x4) = temp_f2_2 * D_overlay_15_00F0895C;
        } else {
            *(f32 *)(arg1 + 0x4) = 0.0f;
        }
        temp_f2_3 = *(f32 *)(arg1 + 0x8);
        if ((temp_f2_3 < -0.5f) || (temp_f2_3 > 0.5f)) {
            *(f32 *)(arg1 + 0x8) = temp_f2_3 * D_overlay_15_00F0895C;
        } else {
            *(f32 *)(arg1 + 0x8) = 0.0f;
        }
    }
    if (arg1[0x10D] != 0) {
        sidekickpadMovePlayer(var_f12, var_f14, arg0, arg1, (s32) arg2);
    }
    if (arg1[0x19F] != 0) {
        transformerMovePlayer(var_f12, var_f14, arg0, arg1, (s32) arg2);
    }
    /* m2c: 6-arg call, the 4-arg prototype below does not match */
    ((void (*)(f32, f32, u8 *, f32, f32, f32)) objMoveXYZ)(var_f12, var_f14, arg0,
        (var_f12 * arg2) + *(f32 *)(arg1 + 0x354),
        (*(f32 *)(arg0 + 0x20) * arg2) + *(f32 *)(arg1 + 0x358),
        (var_f14 * arg2) + *(f32 *)(arg1 + 0x35C));
    if (arg1[0x568] == 4) {
        if (arg1[0x2] != 0) {
            temp_f0_2 = *(f32 *)(arg1 + 0x5C);
            temp_f2_4 = *(f32 *)(arg0 + 0x10);
            if (((temp_f0_2 - D_overlay_15_00F089D8) < temp_f2_4) && (*(f32 *)(arg0 + 0x20) < 4.0f)) {
                objMoveXYZ(arg0, 0.0f, (temp_f0_2 - D_overlay_15_00F089DC) - temp_f2_4, 0.0f);
            }
        }
    }
    temp_f0_3 = 1.0f / arg2;
    temp_f12 = (*(f32 *)(arg0 + 0xC) - *(f32 *)(arg1 + 0x3C)) * temp_f0_3;
    sp44 = temp_f0_3;
    temp_f14 = (*(f32 *)(arg0 + 0x14) - *(f32 *)(arg1 + 0x44)) * temp_f0_3;
    temp_v0_3 = controlGroundHits(temp_f12, temp_f14, arg0, arg1, arg2);
    *(f32 *)(arg0 + 0x1C) = (*(f32 *)(arg0 + 0xC) - *(f32 *)(arg1 + 0x3C)) * temp_f0_3;
    *(f32 *)(arg0 + 0x20) = (*(f32 *)(arg0 + 0x10) - *(f32 *)(arg1 + 0x40)) * temp_f0_3;
    *(f32 *)(arg0 + 0x24) = (*(f32 *)(arg0 + 0x14) - *(f32 *)(arg1 + 0x44)) * temp_f0_3;
    if (((arg1[0x534] != 0) && (*(f32 *)(arg0 + 0x20) > 0.0f))
        || ((*(u8 **)(arg1 + 0x510) != NULL) && (arg1[0x532] != 0))) {
        *(f32 *)(arg0 + 0x20) = 0.0f;
    }
    if (arg1[0x13E] != 0) {
        var_a2_3 = *(s16 *)(arg1 + 0x13C);
    } else {
        var_a2_3 = *(s16 *)(arg1 + 0x11C);
    }
    sp2C = -var_a2_3;
    sp2E = -*(s16 *)(arg0 + 0x2);
    sp34 = temp_v0_3;
    sp30 = -*(s16 *)(arg0 + 0x4);
    sp3C = temp_f14;
    sp44 = temp_f12;
    mathOneFloatYPR(temp_f12, temp_f14, &sp2C, &sp44, var_a2_3);
    temp_v0_4 = arg1[0x149];
    if (temp_v0_4 != 0) {
        arg1[0x149] = (s8) (temp_v0_4 - (s32) arg2);
        if ((s8) arg1[0x149] < 0) {
            arg1[0x149] = 0;
        }
    } else {
        temp_f2_5 = *(f32 *)(arg1 + 0x4);
        temp_f0_4 = temp_f2_5 - sp3C;
        if (temp_f0_4 > 0.5f) {
            *(f32 *)(arg1 + 0x4) = temp_f2_5 - (temp_f0_4 - 0.5f);
        }
        if (temp_f0_4 < -0.5f) {
            *(f32 *)(arg1 + 0x4) = *(f32 *)(arg1 + 0x4) - (temp_f0_4 + 0.5f);
        }
        temp_f2_6 = *(f32 *)(arg1 + 0x8);
        temp_f0_5 = temp_f2_6 - sp44;
        if (temp_f0_5 > 0.5f) {
            *(f32 *)(arg1 + 0x8) = temp_f2_6 - (temp_f0_5 - 0.5f);
        }
        if (temp_f0_5 < -0.5f) {
            *(f32 *)(arg1 + 0x8) = *(f32 *)(arg1 + 0x8) - (temp_f0_5 + 0.5f);
        }
    }
    if (sp34 != 0) {
        if (*(f32 *)(arg1 + 0x4) < -2.0f) {
            *(f32 *)(arg1 + 0x4) = -2.0f;
        }
        if (*(f32 *)(arg1 + 0x4) > 2.0f) {
            *(f32 *)(arg1 + 0x4) = 2.0f;
        }
        if (*(f32 *)(arg1 + 0x8) < -2.0f) {
            *(f32 *)(arg1 + 0x8) = -2.0f;
        }
        if (*(f32 *)(arg1 + 0x8) > 2.0f) {
            *(f32 *)(arg1 + 0x8) = 2.0f;
        }
        if (*(f32 *)(arg1 + 0x10) < -1.75f) {
            *(f32 *)(arg1 + 0x10) = -1.75f;
        }
        if (*(f32 *)(arg1 + 0x10) > 1.75f) {
            *(f32 *)(arg1 + 0x10) = 1.75f;
        }
        arg1[0x199] = 1;
        return;
    }
    arg1[0x199] = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o15/overlay_15/func_overlay_15_00F05ED4_1F19854.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_15_00F0663C_1F19FBC(u8 *arg0, u8 *arg1, s32 arg2) {
    f32 var_f0;
    f32 var_f0_2;
    s16 temp_a1;
    s16 temp_v0_2;
    s16 temp_v0_4;
    s16 temp_v1;
    s16 temp_v1_2;
    s16 var_a0;
    s16 var_a1;
    s16 var_a1_2;
    s16 var_s1;
    s16 var_s1_2;
    s16 var_s1_3;
    s8 temp_v0_3;
    s8 temp_v0_5;
    u8 temp_v0;
    s32 i;

    temp_v0 = arg1[0x568];
    var_s1 = 0;
    var_a1 = 0;
    if ((temp_v0 != 0xA) && (temp_v0 != 2)) {
        var_s1 = *(s16 *)(arg1 + 0x1C8) - *(s16 *)(arg0 + 0x2);
        if (var_s1 < -0x2AAA) {
            var_s1 = -0x2AAA;
        }
        if (var_s1 >= 0x2AAB) {
            var_s1 = 0x2AAA;
        }
        var_a1 = *(s16 *)(arg1 + 0x1C6) - *(s16 *)(arg0 + 0x0);
        if (var_a1 < -0x1000) {
            var_a1 = -0x1000;
        }
        if (var_a1 >= 0x1001) {
            var_a1 = 0x1000;
        }
    }
    for (i = 0; i < arg2; i++) {
        temp_v0_2 = *(s16 *)(arg1 + 0x1D0);
        temp_v1 = *(s16 *)(arg1 + 0x1CE);
        *(s16 *)(arg1 + 0x1D0) = (s16) (temp_v0_2 + ((s32) (var_s1 - temp_v0_2) >> 2));
        *(s16 *)(arg1 + 0x1CE) = (s16) (temp_v1 + ((s32) (var_a1 - temp_v1) >> 2));
    }
    temp_v0_3 = arg1[0x1F5];
    var_s1_2 = 0;
    var_a1_2 = 0;
    if ((temp_v0_3 > 0) && (arg1[0x568] != 0xA)) {
        var_s1_2 = *(s16 *)(arg1 + 0x1DA);
        var_f0 = (f32) var_s1_2;
        if (var_f0 < D_overlay_15_00F08960) {
            var_s1_2 = -0x38E3;
        }
        if (D_overlay_15_00F08964 < (f32) var_s1_2) {
            var_s1_2 = 0x38E3;
        }
        var_a1_2 = *(s16 *)(arg1 + 0x1D8);
        var_f0_2 = (f32) var_a1_2;
        if (var_f0_2 < D_overlay_15_00F08968) {
            var_a1_2 = -0xE38;
        }
        if (D_overlay_15_00F0896C < (f32) var_a1_2) {
            var_a1_2 = 0xE38;
        }
        arg1[0x1F5] = (s8) (temp_v0_3 - arg2);
    }
    for (i = 0; i < arg2; i++) {
        temp_v0_4 = *(s16 *)(arg1 + 0x1DE);
        temp_v1_2 = *(s16 *)(arg1 + 0x1DC);
        *(s16 *)(arg1 + 0x1DE) = (s16) (temp_v0_4 + ((s32) (var_s1_2 - temp_v0_4) >> 4));
        *(s16 *)(arg1 + 0x1DC) = (s16) (temp_v1_2 + ((s32) (var_a1_2 - temp_v1_2) >> 4));
    }
    if (arg1[0x1F4] != 0) {
        temp_v0_5 = arg1[0x1F6];
        temp_a1 = *(s16 *)(arg1 + 0x1CE);
        var_s1_3 = *(s16 *)(arg1 + 0x1D0);
        if (temp_v0_5 != 0) {
            var_s1_3 += (s32) ((s8) arg1[0x1F7] * mathSin((s16) (temp_v0_5 << 0xC), (s32) temp_a1)) >> 8;
        }
        func_overlay_15_00F04088_1F17A08(var_s1_3, temp_a1, *(s16 *)(arg1 + 0x1DE), *(s16 *)(arg1 + 0x1DC));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o15/overlay_15/func_overlay_15_00F0663C_1F19FBC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_15_00F068BC_1F1A23C(u8 *arg0, u8 *arg1, f32 arg2) {
    f32 temp_f0;
    s32 temp_f4;
    s32 temp_lo;
    s32 temp_v1;
    s8 temp_a0;
    s8 temp_a0_2;
    s8 temp_v0;
    s8 var_v0;

    *(f32 *)(arg1 + 0x4) = 0.0f;
    *(f32 *)(arg1 + 0x10) = 0.0f;
    *(f32 *)(arg1 + 0x8) = 0.0f;
    *(f32 *)(arg0 + 0x1C) = 0.0f;
    temp_f4 = (s32) arg2;
    *(f32 *)(arg0 + 0x24) = 0.0f;
    var_v0 = arg1[0x579];
    if (var_v0 > 0) {
        temp_v1 = var_v0 - temp_f4;
        if (temp_v1 >= 0) {
            arg1[0x579] = (s8) (var_v0 - temp_f4);
            var_v0 = arg1[0x579];
            *(s16 *)(arg1 + 0x11C) = (s16) (*(s16 *)(arg1 + 0x11C) - (*(s16 *)(arg1 + 0x17C) * temp_f4));
        } else {
            temp_lo = *(s16 *)(arg1 + 0x17C) * var_v0;
            arg1[0x579] = 0;
            var_v0 = arg1[0x579];
            *(s16 *)(arg1 + 0x11C) = (s16) (*(s16 *)(arg1 + 0x11C) - temp_lo);
        }
        if (var_v0 == 0) {
            *(f32 *)(arg0 + 0x20) = 0.0f;
            arg1[0x194] = 1;
            controlMakeGravity(arg2, arg1, temp_f4, temp_f4);
            func_overlay_15_00F05180_1F18B00(arg0, arg1, 0x23, 0);
        }
    } else {
        temp_a0 = arg1[0x578];
        if (temp_a0 > 0) {
            temp_v0 = temp_a0 - temp_f4;
            if (var_v0 == 0) {
                if (temp_v0 >= 0) {
                    arg1[0x578] = temp_v0;
                    *(f32 *)(arg1 + 0x4) = (f32) *(s16 *)(arg1 + 0x170);
                    *(f32 *)(arg1 + 0x10) = (f32) *(s16 *)(arg1 + 0x174);
                } else {
                    temp_f0 = (f32) temp_a0;
                    arg1[0x578] = 0;
                    *(f32 *)(arg1 + 0x4) = (f32) ((*(s16 *)(arg1 + 0x170) * temp_f0) / arg2);
                    *(f32 *)(arg1 + 0x10) = (f32) ((*(s16 *)(arg1 + 0x174) * temp_f0) / arg2);
                }
                if (arg1[0x578] == 0) {
                    arg1[0x194] = 0;
                    controlMakeGravity(arg2, arg1, temp_f4, temp_f4);
                }
            }
        }
    }
    if (*(s16 *)(arg1 + 0x184) == 0) {
        arg1[0x194] = 0;
        ((void (*)(u8 *))controlMakeGravity)(arg1); /* sig mismatch: 1-arg call */
        *(f32 *)(arg1 + 0x57C) = *(f32 *)(arg0 + 0x10);
        func_overlay_15_00F05180_1F18B00(arg0, arg1, 0x19, 0);
        arg1[0x568] = 3;
        arg1[0x58E] = 0;
    } else {
        temp_a0_2 = arg1[0x578];
        if ((temp_a0_2 == 0) && (*(u8 *)(*(u8 **)(arg1 + 0x360) + 5) & arg1[0x532])) {
            arg1[0x149] = 8;
            *(f32 *)(arg1 + 0x6C) = 2.0f * Sinf(*(s16 *)(arg1 + 0x11C));
            *(f32 *)(arg1 + 0x70) = 2.0f * Cosf((s32) *(s16 *)(arg1 + 0x11C));
            func_overlay_15_00F05180_1F18B00(arg0, arg1, func_overlay_15_00F05020_1F189A0(arg1), 0);
            arg1[0x568] = 0;
            arg1[0x58E] = 0;
        } else if ((temp_a0_2 == 0) && (*(u8 *)(*(u8 **)(arg1 + 0x360) + 6) & arg1[0x532])) {
            arg1[0x568] = 8;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o15/overlay_15/func_overlay_15_00F068BC_1F1A23C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_15_00F06B3C_1F1A4BC(u8 *arg0, u8 *arg1, f32 arg2, s16 arg3, f32 arg4) {
    f32 sp34;
    f32 sp30;
    f32 sp2C;
    f32 temp_f0;
    s8 temp_v0;
    s32 z;
    s32 c6;

    *(f32 *)(arg1 + 0x4) = 0.0f;
    *(f32 *)(arg1 + 0x10) = 0.0f;
    *(f32 *)(arg1 + 0x8) = 0.0f;
    *(f32 *)(arg0 + 0x1C) = 0.0f;
    *(f32 *)(arg0 + 0x24) = 0.0f;
    if (*(u8 *)(*(u8 **)(arg1 + 0x360) + 5) & arg1[0x532]) {
        arg1[0x149] = 8;
        *(f32 *)(arg1 + 0x6C) = 2.0f * Sinf(*(s16 *)(arg1 + 0x11C));
        *(f32 *)(arg1 + 0x70) = 2.0f * Cosf((s32) *(s16 *)(arg1 + 0x11C));
        func_overlay_15_00F05180_1F18B00(arg0, arg1, func_overlay_15_00F05020_1F189A0(arg1), 0);
        arg1[0x568] = 0;
    } else {
        if (arg2 == 0.0f) {
            arg1[0x578] = 1;
        }
        sp2C = Cosf((s32) arg3);
        sp30 = Cosf((s32) *(s16 *)(arg1 + 0x11C));
        sp34 = Sinf(*(s16 *)(arg1 + 0x11C));
        temp_f0 = Sinf(arg3);
        temp_v0 = arg1[0x578];
        if (((temp_v0 != 0) && (arg2 > 2.0f) && (D_overlay_15_00F08970 < ((temp_f0 * sp34) + (sp30 * sp2C)))) || (*(s32 *)((u8 *) controlModeKeys + 0xC) & controlDkeys)) {
            *(f32 *)(arg0 + 0x20) = sqrtf(2.0f * controlchr_gravity * (*(f32 *)(arg1 + 0x178) - *(f32 *)(arg0 + 0x10))) + (1.0f + (0.5f * controlchr_gravity * arg4));
            *(f32 *)(arg1 + 0x4) = -1.0f;
            func_overlay_15_00F05180_1F18B00(arg0, arg1, 0x24, 0);
            arg1[0x568] = 7;
        } else {
            /* z: second-branch condition, c6: ground-hit flag */
            z = ((temp_v0 == 0) || !(arg2 > 2.0f) || !(((temp_f0 * sp34) + (sp30 * sp2C)) < D_overlay_15_00F08974))
                && !(*(s32 *)((u8 *) controlModeKeys + 0x10) & controlDkeys);
            c6 = *(u8 *)(*(u8 **)(arg1 + 0x360) + 6) & arg1[0x532];
            if (!(z && c6)) {
                *(f32 *)(arg1 + 0x57C) = *(f32 *)(arg0 + 0x10);
                func_overlay_15_00F05180_1F18B00(arg0, arg1, 0x19, 0);
                arg1[0x568] = 3;
                arg1[0x58E] = 0;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o15/overlay_15/func_overlay_15_00F06B3C_1F1A4BC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_15_00F06DDC_1F1A75C(u8 *arg0, u8 *arg1, s32 arg2) {
    if (*(u8 *)(*(u8 **)(arg1 + 0x360) + 5) & arg1[0x532]) {
        func_overlay_15_00F05180_1F18B00(arg0, arg1, func_overlay_15_00F05020_1F189A0(arg1), 0);
        arg1[0x568] = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o15/overlay_15/func_overlay_15_00F06DDC_1F1A75C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_15_00F06E40_1F1A7C0(u8 *arg0) {
    f32 t = *(f32 *)(arg0 + 0x138) * -10.0f;

    D_overlay_15_00F089D8 = t + 44.0f;
    D_overlay_15_00F089DC = t + 44.5f;
    D_overlay_15_00F089E0 = t + 45.0f;
    D_overlay_15_00F089E4 = t + 50.0f;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o15/overlay_15/func_overlay_15_00F06E40_1F1A7C0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_15_00F06EBC_1F1A83C(u8 *arg0, u8 *arg1, f32 arg2, s16 arg3, f32 arg4) {
    s16 sp5E;
    s16 sp5C;
    s16 sp5A;
    f32 sp54;
    f32 sp48;
    f32 sp44;
    s32 sp30;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f2_3;
    f32 temp_f2_4;
    f32 var_f14;
    f32 var_f14_2;
    f32 var_f14_3;
    f32 var_f14_4;
    f32 var_f16;
    s16 temp_v0_2;
    s16 var_a3;
    s16 var_a3_2;
    s32 temp_f10;
    s32 temp_f10_2;
    s32 temp_f10_3;
    s32 temp_f10_4;
    u8 *temp_v0;
    u8 *temp_v1;
    u8 *temp_v1_2;
    u8 *elem;
    u8 *d;

    arg1[0x541] &= 0xF0;
    if (controlCeiling(*(f32 *)(arg0 + 0xC), *(f32 *)(arg0 + 0x10), *(f32 *)(arg0 + 0x14), 52.0f, 13.0f) == 0) {
        arg1[0x1FB] = 1;
    } else {
        arg1[0x1FB] = 0;
    }
    temp_f0 = *(f32 *)(arg1 + 0x60);
    if ((arg1[0x2] != 0) && ((D_overlay_15_00F089D8 < temp_f0) || (arg1[0x533] != 0))) {
        if (temp_f0 < D_overlay_15_00F089E4) {
            arg1[0x19E] = 1;
        }
        if ((*(s32 *)((u8 *) controlModeKeys + 0xC) & controlDkeys) && (*(f32 *)(arg1 + 0x60) < D_overlay_15_00F089E4) && (arg1[0x1FB] == 0)) {
            arg1[0x57A] = 0;
            *(f32 *)(arg1 + 0x57C) = *(f32 *)(arg0 + 0x10);
            *(f32 *)(arg0 + 0x20) = *(f32 *)(arg0 + 0x20) + 10.0f;
            temp_v0 = *(u8 **)(arg1 + 0x510);
            if (temp_v0 != NULL) {
                *(f32 *)(arg0 + 0x20) = *(f32 *)(arg0 + 0x20) - *(f32 *)(temp_v0 + 0x20);
            }
            func_overlay_15_00F05180_1F18B00(arg0, arg1, 6, 0);
            arg1[0x568] = 3;
            arg1[0x58E] = 0;
            *(f32 *)(arg1 + 0x594) = 0.0f;
            charSpeak(arg0, 0);
            sp30 = (s32) arg4;
        } else {
            func_overlay_15_00F06E40_1F1A7C0(arg1);
            if (*(s32 *)((u8 *) controlModeKeys + 0x10) & controlKeys) {
                var_f16 = 1.0f;
                var_f14 = 0.0f;
            } else if (*(s32 *)((u8 *) controlModeKeys + 0xC) & controlKeys) {
                var_f16 = 1.0f;
                if (*(f32 *)(arg1 + 0x60) < D_overlay_15_00F089E0) {
                    var_f14 = 0.0f;
                } else {
                    var_f14 = 2.5f;
                }
            } else {
                var_f16 = D_overlay_15_00F08978;
                var_f14 = 0.0f;
            }
            sp44 = var_f14;
            temp_f10 = (s32) arg4;
            sp48 = var_f16;
            sp30 = temp_f10;
            temp_f2 = *(f32 *)(arg1 + 0x594);
            *(f32 *)(arg1 + 0x594) = temp_f2 + ((var_f16 - temp_f2) * (1.0f - Powerf(0.875f, temp_f10)));
            temp_f2_2 = *(f32 *)(arg0 + 0x20);
            *(f32 *)(arg0 + 0x20) = temp_f2_2 + ((var_f14 - temp_f2_2) * (1.0f - Powerf(D_overlay_15_00F0897C, temp_f10)));
            elem = *(u8 **)(*(u8 **)(arg0 + 0x6C) + arg0[0x3A] * 4);
            if (*(f32 *)(*(u8 **)(elem + 0x68) + 0x10) < *(f32 *)(arg1 + 0x5C)) {
                if (arg1[0x12F] != 0) {
                    amSndPlayXYZ((mathRnd(0, 2) + 0xD4) & 0xFFFF, *(f32 *)(arg0 + 0xC), *(f32 *)(arg0 + 0x10), *(f32 *)(arg0 + 0x14), 4, NULL);
                }
                if (arg1[0x12E] != 0) {
                    /* m2c also passed -5.0f and sp30 here; 4-arg prototype used */
                    func_overlay_15_00F07724_1F1B0A4(arg0, arg1, 0, 0x42120000);
                }
            }
        }
    } else if (*(u8 *)(*(u8 **)(arg1 + 0x360) + 5) & arg1[0x532]) {
        func_overlay_15_00F05180_1F18B00(arg0, arg1, func_overlay_15_00F05020_1F189A0(arg1), 0);
        arg1[0x568] = 0;
        arg1[0x58E] = 0;
        *(f32 *)(arg1 + 0x594) = 0.0f;
        sp30 = (s32) arg4;
    } else {
        arg1[0x568] = 3;
        arg1[0x58E] = 0;
        *(f32 *)(arg1 + 0x594) = 0.0f;
        sp30 = (s32) arg4;
    }
    *(f32 *)(arg1 + 0x10) = *(f32 *)(arg1 + 0x10) * Powerf(D_overlay_15_00F08980, sp30);
    temp_f2_3 = *(f32 *)(arg1 + 0x10);
    if (D_overlay_15_00F08984 < temp_f2_3) {
        if (temp_f2_3 < D_overlay_15_00F08988) {
            *(f32 *)(arg1 + 0x10) = 0.0f;
        }
    }
    controlWalkingBack(arg0, arg1, &arg2, (s32) arg3, 0x5000, 0x6800, 5.0f, 3.0f);
    if (arg1[0x569] == 0) {
        arg2 = -arg2;
    } else {
        arg3 += 0x8000;
    }
    var_f14_2 = *(f32 *)(arg1 + 0x4);
    if (var_f14_2 < 0.0f) {
        var_f14_2 = -var_f14_2;
    }
    temp_f10_2 = (s32) var_f14_2;
    temp_v1 = D_overlay_15_00F086A4 + (temp_f10_2 * 4);
    temp_f0_2 = *(f32 *)(temp_v1 + 0x0);
    sp5E = *(s16 *)(arg1 + 0x11C);
    *(s16 *)(arg1 + 0x11C) = dAngle(*(s16 *)(arg1 + 0x11C), arg3, 1.0f - Powerf(1.0f - (((*(f32 *)(temp_v1 + 0x4) - temp_f0_2) * (var_f14_2 - (f32) temp_f10_2)) + temp_f0_2), sp30));
    temp_f2_4 = *(f32 *)(arg1 + 0x4);
    *(f32 *)(arg1 + 0x4) = ((1.0f - Powerf(D_overlay_15_00F0898C, sp30)) * (arg2 - temp_f2_4)) + temp_f2_4;
    var_f14_3 = *(f32 *)(arg1 + 0x4);
    if (var_f14_3 < 0.0f) {
        var_f14_3 = -var_f14_3;
    }
    temp_f10_3 = (s32) var_f14_3;
    temp_v1_2 = D_overlay_15_00F086C4 + (temp_f10_3 * 4);
    temp_f0_3 = *(f32 *)(temp_v1_2 + 0x0);
    var_f14_4 = *(f32 *)(arg1 + 0x4);
    *(s16 *)(arg1 + 0x128) = dAngle(*(s16 *)(arg1 + 0x128), *(s16 *)(arg1 + 0x11C), 1.0f - Powerf(1.0f - (temp_f0_3 + ((var_f14_3 - (f32) temp_f10_3) * (*(f32 *)(temp_v1_2 + 0x4) - temp_f0_3))), sp30));
    if (var_f14_4 < 0.0f) {
        var_f14_4 = -var_f14_4;
    }
    temp_f10_4 = (s32) ((f32) (s16) (*(s16 *)(arg1 + 0x11C) - sp5E) * (3.0f + var_f14_4));
    var_a3 = (s16) temp_f10_4;
    if ((s16) temp_f10_4 < -0x2000) {
        var_a3 = -0x2000;
    }
    if (var_a3 >= 0x2001) {
        var_a3 = 0x2000;
    }
    sp5C = var_a3;
    sp54 = var_f14_4;
    *(s16 *)(arg1 + 0x12C) = dAngle(*(s16 *)(arg1 + 0x12C), var_a3, 1.0f - Powerf(D_overlay_15_00F08990, sp30));
    /* sprite command pairs: write cmd, advance 2, write value at +2, advance 2 */
    d = D_overlay_15_00F089C8;
    *(s16 *)(d + 0) = 4;
    D_overlay_15_00F089C8 += 2;
    var_a3_2 = 0;
    *(s16 *)(D_overlay_15_00F089C8 + 2) = (s16) *(s16 *)(arg1 + 0x12C);
    D_overlay_15_00F089C8 += 2;
    if (arg0[0x3B] == 0x2D) {
        temp_v0_2 = (s16) Arctanf(*(f32 *)(arg0 + 0x20), var_f14_4);
        var_a3_2 = temp_v0_2;
        if (temp_v0_2 < -0x2000) {
            var_a3_2 = -0x2000;
        }
        if (var_a3_2 >= 0x2001) {
            var_a3_2 = 0x2000;
        }
    }
    sp5A = var_a3_2;
    *(s16 *)(arg1 + 0x12A) = dAngle(*(s16 *)(arg1 + 0x12A), var_a3_2, 1.0f - Powerf(D_overlay_15_00F08994, sp30));
    d = D_overlay_15_00F089C8;
    *(s16 *)(d + 0) = 0;
    D_overlay_15_00F089C8 += 2;
    *(s16 *)(D_overlay_15_00F089C8 + 2) = *(s16 *)(arg1 + 0x12A);
    D_overlay_15_00F089C8 += 2;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o15/overlay_15/func_overlay_15_00F06EBC_1F1A83C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_15_00F07724_1F1B0A4(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3) {
    u8 setup[0x14];
    u8 *temp_v0;
    u8 *temp_v1;
    u8 *temp_v0_2;

    temp_v0 = *(u8 **)(arg0 + 0x6C);
    if (temp_v0 != NULL) {
        temp_v1 = *(u8 **)temp_v0;
        if ((temp_v1 != NULL) && ((s8)temp_v1[0x2D] >= 2) && (*(f32 *)(*(u8 **)(temp_v0 + 0x68) + 0x10) < *(f32 *)(arg1 + 0x5C))) {
            *(s16 *)(setup + 0x0) = 0xBA;
            setup[0x2] = 0x14;
            setup[0x3] = 0;
            *(s16 *)(setup + 0x4) = (s16) *(f32 *)(*(u8 **)(temp_v0 + 0x68) + 0xC);
            *(s16 *)(setup + 0x6) = (s16) *(f32 *)(*(u8 **)(temp_v0 + 0x68) + 0x10);
            *(s16 *)(setup + 0x8) = (s16) *(f32 *)(*(u8 **)(temp_v0 + 0x68) + 0x14);
            *(s16 *)(setup + 0xA) = mathRnd(-0x8000, 0x7FFF);
            *(f32 *)(setup + 0xC) = (f32) mathRnd(0, 0x23) * D_overlay_15_00F08998;
            *(f32 *)(setup + 0x10) = *(f32 *)(arg1 + 0x5C);
            temp_v0_2 = objSetupObject(setup, 1);
            if (temp_v0_2 != NULL) {
                *(s32 *)(temp_v0_2 + 0x3C) = 0;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o15/overlay_15/func_overlay_15_00F07724_1F1B0A4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_15_00F07890_1F1B210(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, f32 arg4) {
    u8 setup[0x14];
    f32 temp_f0;
    f32 temp_f2;
    f32 temp_f2_2;
    s32 temp_f6;
    s8 temp_v0_2;
    u8 temp_v0;
    u8 *temp_a2;
    u8 *temp_v1;
    u8 *temp_v0_3;

    if (numberOfPlayers == 1) {
        mainPauseDisable(0xA);
    }
    *(s16 *)(*(u8 **)(arg0 + 0x4C) + 6) = 0;
    temp_f6 = (s32) arg4;
    temp_f0 = Powerf(D_overlay_15_00F0899C, temp_f6);
    *(f32 *)(arg1 + 0x4) = *(f32 *)(arg1 + 0x4) * temp_f0;
    temp_f2 = *(f32 *)(arg1 + 0x4);
    if ((D_overlay_15_00F089A0 < temp_f2) && (temp_f2 < D_overlay_15_00F089A4)) {
        *(f32 *)(arg1 + 0x4) = 0.0f;
    }
    *(f32 *)(arg1 + 0x10) = *(f32 *)(arg1 + 0x10) * temp_f0;
    temp_f2_2 = *(f32 *)(arg1 + 0x10);
    if ((D_overlay_15_00F089A0 < temp_f2_2) && (temp_f2_2 < D_overlay_15_00F089A8)) {
        *(f32 *)(arg1 + 0x10) = 0.0f;
    }
    arg1[0x541] &= 0xF0;
    if (arg1[0x2] == 0) {
        *(f32 *)(arg1 + 0x594) = *(f32 *)(arg1 + 0x594) * temp_f0;
    } else {
        *(f32 *)(arg1 + 0x594) = 0.875f;
        *(f32 *)(arg0 + 0x20) = *(f32 *)(arg0 + 0x20) * Powerf(D_overlay_15_00F089AC, temp_f6);
        temp_v0 = arg1[0x18A];
        if ((s32) temp_v0 < 0xF0) {
            arg1[0x18A] = (u8) (temp_v0 + 1);
        }
        temp_v0_2 = arg1[0x18B];
        if (temp_f6 >= temp_v0_2) {
            temp_a2 = *(u8 **)(*(u8 **)(arg0 + 0x6C) + arg0[0x3A] * 4);
            temp_v1 = *(u8 **)(temp_a2 + 0x70) + (mathRnd(0, (s8) (*(u8 **)temp_a2)[0x2F] - 1) * 0xC);
            if (*(f32 *)(temp_v1 + 0x4) < *(f32 *)(arg1 + 0x5C)) {
                *(s16 *)(setup + 0x0) = 0xBA;
                setup[0x2] = 0x14;
                setup[0x3] = 0;
                *(s16 *)(setup + 0x4) = (s16) *(f32 *)(temp_v1 + 0x0);
                *(s16 *)(setup + 0x6) = (s16) *(f32 *)(temp_v1 + 0x4);
                *(s16 *)(setup + 0x8) = (s16) *(f32 *)(temp_v1 + 0x8);
                *(s16 *)(setup + 0xA) = mathRnd(-0x8000, 0x7FFF);
                *(f32 *)(setup + 0xC) = (f32) mathRnd(0, 0x23) * D_overlay_15_00F089B0;
                *(f32 *)(setup + 0x10) = *(f32 *)(arg1 + 0x5C);
                temp_v0_3 = objSetupObject(setup, 1);
                if (temp_v0_3 != NULL) {
                    *(s32 *)(temp_v0_3 + 0x3C) = 0;
                }
            }
            arg1[0x18B] = (s8) ((s32) arg1[0x18A] >> 2);
        } else {
            arg1[0x18B] = (s8) (temp_v0_2 - temp_f6);
        }
    }
    arg1[0x19C] = 0;
    if (*(f32 *)(arg0 + 0x28) == 1.0f) {
        controlFrozen(arg0, arg1);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o15/overlay_15/func_overlay_15_00F07890_1F1B210.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_15_00F07BC8_1F1B548(u8 *arg0, u8 *arg1, s32 arg2, s32 arg3, f32 arg4) {
    s32 temp_f4;
    s8 temp_v0;
    s32 temp_a0;
    s32 temp_lo;
    f32 temp_f0;
    u8 *temp_v0_2;
    u8 temp_v1;

    temp_f4 = (s32) arg4;
    *(f32 *)(arg1 + 0x4) = 0.0f;
    *(f32 *)(arg1 + 0x8) = 0.0f;
    *(f32 *)(arg1 + 0x10) = 0.0f;
    *(f32 *)(arg0 + 0x1C) = 0.0f;
    *(f32 *)(arg0 + 0x24) = 0.0f;
    if (*(s8 *)(arg0 + 0x3B) != 0x23) {
        func_overlay_15_00F05180_1F18B00(arg0, arg1, 0x23, 0);
    }

    temp_v0 = *(s8 *)(arg1 + 0x578);
    temp_a0 = temp_v0 - temp_f4;
    if (temp_v0 != 0) {
        if (temp_a0 >= 0) {
            *(f32 *)(arg0 + 0x1C) = *(f32 *)(arg1 + 0x170);
            *(f32 *)(arg0 + 0x24) = *(f32 *)(arg1 + 0x174);
            *(s8 *)(arg1 + 0x578) = (s8) (temp_v0 - temp_f4);
            *(s16 *)(arg1 + 0x11C) = (s16) (*(s16 *)(arg1 + 0x11C) - (*(s16 *)(arg1 + 0x17C) * temp_f4));
        } else if (temp_v0 > 0) {
            temp_f0 = (f32) temp_v0;
            *(f32 *)(arg0 + 0x1C) = (*(f32 *)(arg1 + 0x170) * temp_f0) / arg4;
            *(f32 *)(arg0 + 0x24) = (*(f32 *)(arg1 + 0x174) * temp_f0) / arg4;
            temp_lo = *(s16 *)(arg1 + 0x17C) * temp_v0;
            *(s8 *)(arg1 + 0x578) = 0;
            *(s16 *)(arg1 + 0x11C) = (s16) (*(s16 *)(arg1 + 0x11C) - temp_lo);
        }
    } else {
        temp_v0_2 = *(u8 **)(arg1 + 0x360);
        temp_v1 = *(u8 *)(arg1 + 0x532);
        if (temp_v0_2[6] & temp_v1) {
            func_overlay_15_00F05180_1F18B00(arg0, arg1, 0x25, 0);
            *(u8 *)(arg1 + 0x568) = 8;
            *(f32 *)(arg1 + 0x57C) = *(f32 *)(arg1 + 0x178);
            *(f32 *)(arg0 + 0x20) = 0.0f;
            *(u8 *)(arg1 + 0x14A) = 0;
            *(u8 *)(arg1 + 0x14B) = 0;
            *(f32 *)(arg1 + 0x594) = 0.0f;
        } else if (temp_v0_2[5] & temp_v1) {
            *(u8 *)(arg1 + 0x568) = 0;
            func_overlay_15_00F05180_1F18B00(arg0, arg1, func_overlay_15_00F05020_1F189A0(arg1), 0);
        } else if ((*(f32 *)(arg1 + 0x4AC) < *(f32 *)(arg1 + 0x178)) || (*(u8 *)(arg1 + 0x533) != 0)) {
            *(f32 *)(arg1 + 0x57C) = *(f32 *)(arg0 + 0x10);
            func_overlay_15_00F05180_1F18B00(arg0, arg1, 0x19, 0);
            *(u8 *)(arg1 + 0x568) = 3;
            *(u8 *)(arg1 + 0x58E) = 0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o15/overlay_15/func_overlay_15_00F07BC8_1F1B548.s")
#endif
