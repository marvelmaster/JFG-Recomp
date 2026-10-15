#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
extern void *controlModeKeys;
extern u8 *D_overlay_17_011069C4;
extern s32 D_overlay_17_011069C0;
extern f32 D_overlay_17_01106820;
extern f32 D_overlay_17_01106824;
extern f32 D_overlay_17_01106828;
extern f32 D_overlay_17_0110682C;
extern f32 D_overlay_17_01106830;
extern f32 D_overlay_17_01106858;
extern f32 D_overlay_17_011068AC;
extern f32 D_overlay_17_011068B0;
extern f32 D_overlay_17_011068B4;
extern f32 D_overlay_17_011068B8;
extern f32 D_overlay_17_011068BC;
extern f32 D_overlay_17_011068C0;
extern f32 D_overlay_17_011068C4;
extern f32 D_overlay_17_011068C8;
extern f32 D_overlay_17_011068CC;
extern f32 D_overlay_17_011068D0;
void func_overlay_17_01104B84_1F2C6CC(void *, void *, s32, s32);
void func_overlay_17_01102848_1F2A390(void *, void *, f32);
void func_overlay_17_01104178_1F2BCC0(void *, s16, s16, s16);
void func_overlay_17_01104270_1F2BDB8(s16, s16);
extern f32 D_overlay_17_01106810;
extern f32 D_overlay_17_01106814;
extern f32 D_overlay_17_01106818;
extern f32 D_overlay_17_0110681C;
extern f32 D_overlay_17_01106834;
extern f32 D_overlay_17_01106838;
extern f32 D_overlay_17_0110683C;
extern f32 D_overlay_17_01106840;
extern f32 D_overlay_17_01106844;
extern s32 D_overlay_17_01106848;
extern f32 D_overlay_17_0110684C;
extern f32 D_overlay_17_01106850;
extern f32 D_overlay_17_01106854;
extern f32 D_overlay_17_011068D4;
extern f32 D_overlay_17_0110685C;
extern f32 D_overlay_17_01106860;
extern f32 D_overlay_17_01106864;
extern f32 D_overlay_17_01106868;
extern f32 D_overlay_17_0110686C;
extern f32 D_overlay_17_01106870;
extern f32 D_overlay_17_01106874;
extern f32 D_overlay_17_01106878;
extern f32 D_overlay_17_0110687C;
extern f32 D_overlay_17_01106880;
extern f32 D_overlay_17_01106884;
extern f32 D_overlay_17_01106888;
extern f32 D_overlay_17_0110688C;
extern f32 D_overlay_17_01106890;
extern f32 D_overlay_17_01106894;
extern f32 D_overlay_17_01106898;
extern f32 D_overlay_17_0110689C;
extern f32 D_overlay_17_011068A0;
extern f32 D_overlay_17_011068A4;
extern f32 D_overlay_17_011068A8;
extern s32 D_overlay_17_0110645C[];
void amSndPlay(s32, void *);
void amSndSetVol(s32, s32, s32);
extern s32 D_overlay_17_011069B0;
extern s32 D_overlay_17_011069B4;
extern s32 D_overlay_17_011069B8;
extern s32 D_overlay_17_011069BC;
extern u8 multiPlayerGame;
extern u8 numberOfPlayers;
extern u8 D_overlay_17_011062C8[];
extern u8 D_overlay_17_011062C9[];
extern u8 D_overlay_17_011062CA[];
extern f32 D_overlay_17_0110635C[];
extern f32 D_overlay_17_011063BC[];
extern f32 D_overlay_17_01106738[];
extern f32 D_overlay_17_01106758[];
extern f32 D_overlay_17_01106778[];
extern f32 D_overlay_17_01106798[];
extern f32 D_overlay_17_01106948;
extern f32 D_overlay_17_0110694C;
extern f32 D_overlay_17_01106950;
extern f32 D_overlay_17_01106954;
extern f32 D_overlay_17_01106958;
extern f32 D_overlay_17_0110695C;
extern f32 D_overlay_17_01106960;
extern f32 D_overlay_17_01106964;
extern f32 D_overlay_17_01106968;
extern f32 D_overlay_17_0110696C;
extern f32 D_overlay_17_01106970;
extern f32 D_overlay_17_01106974;
extern f32 D_overlay_17_01106978;
extern f32 D_overlay_17_0110697C;
extern f32 D_overlay_17_01106980;
extern f32 D_overlay_17_01106984;
extern f32 D_overlay_17_01106988;
extern f32 D_overlay_17_0110698C;
extern f32 D_overlay_17_01106990;
extern f32 D_overlay_17_01106994;
extern f32 D_overlay_17_01106998;
extern f32 D_overlay_17_0110699C;
extern f32 D_overlay_17_011069A0;
extern f32 D_overlay_17_011069A4;
extern f32 D_overlay_17_011069A8;
extern f32 D_overlay_17_011069AC;
f32 Sinf(s16);
void dropletAdd(f32, f32, f32, f32, f32, f32, f32, f32);
void mathOneFloatPY(s16 *, f32 *);
void charSpeak(void *, u8);
void frontFlashScreen(s32, s8, u32);
void fxNightVisionSkip(void);
void hitPlayerKilledPlayer(void *, void *, s32 *, s8);
s32 mathSin();
f32 Powerf(f32, s32);
void controlWalkingBack(void *, void *, f32 *, s32, s32, s32, f32, f32);
void controlHalfTurn(void *, void *, f32 *, s16 *, s32, s32, s32 *, f32, f32);
s32 controlGroundHits(f32, f32, void *, void *, f32);
s16 dAngle(s16, s16, f32);
s32 frontGetTargetControl(s8);
s32 lobbycamInuse();
s32 staticcamInuse();
s32 func_overlay_17_01104A44_1F2C58C(void *, f32 *);
s32 controlPlayerGunWeight(void *, s32);
void objAnimSetMove(void *, u8, s32, u8);
void charAnimSoundTick(void *, f32, f32);
void objAnimDframe(void *, f32, f32);
void mathOneFloatYPR(f32, f32, s16 *, f32 *, s16);
void sidekickpadMovePlayer(f32, f32, void *, void *, s32);
void transformerMovePlayer(f32, f32, void *, void *, s32);
void objMoveXYZ(f32, f32, void *, f32, f32, f32);
void *objSetupObject(void *, s32);
void mainPauseDisable(s32);
void controlFrozen(void *, void *);

extern f32 D_overlay_17_011067C0;
extern f32 D_overlay_17_011067C4;
extern f32 D_overlay_17_011067F8;
extern f32 D_overlay_17_011067FC;
extern f32 D_overlay_17_01106800;
extern f32 D_overlay_17_01106804;
extern f32 D_overlay_17_01106808;
extern f32 D_overlay_17_0110680C;
extern s16 *controlcam;
extern u8 weaponTable[];
extern s32 quickWeaponKey[];
extern u8 allweaponsCheat;
extern u8 invulnerabilityCheat;
extern s32 D_overlay_17_01106450[];
void controlFSUvels(void *, void *);
void controlPlatform(void *, void *, f32);
void controlSquashCheckPrior(void *, void *, s32);
void controlSquashCheckPost(void *, void *, s32);
void controlDisableJoypad(s32);
void controlReadJoypad(s8);
void controlMakeGravity(void *);
void controlFadePlayer(void *, void *, s32);
void controlSelectNextWeapon(void *, void *, s8);
void controlSelectPreviousWeapon(void *, void *, s8);
s32 controlSelectWeapon(void *, void *, s8, s32);
void controlEmptyPlayersHand(void *);
void controlClearAimlocks(void *);
void controlUpdatePlayerAim(void *, void *, s32, s32, f32, f32, f32, s32);
s32 controlUpdateWeapon(void *, void *, f32);
s32 controlThrowWeapon(s32);
void controlUpdateJetFlames(void *, void *, s32, s32, s32);
void controlSetRumble(s8, s32, s32, s32, s32);
s32 trackPolyHeight(f32, f32, void *, s32);
void wakeUpdateRipple(void *, s32);
void partUpdateTriggers(void *, s32);
void amSndPlayXYZ(s32, f32, f32, f32, s32, void *);
void amSndStopXYZ(SoundMask *);
void amSndStop(s32);
void amTunePlay(s32);
void objEnsureNotTargetted(void *);
void invincibilityShieldTransform(s32, f32, f32, s32);
void mainPlayerCollected(s8, s8, s32);
s32 mainPlayerHas(s8, s8, s32);
void modGenAnimMatrices(void *, void *, void *, f32, f32);
s32 objMakeGunMtx(void *, void *, void *, u8, void *, void *, void *, void *);
void lightObject(void *, void *, s32, s32);
void objAnimTextures(void *, void *, void *, s8);
void func_overlay_17_01101A30_1F29578(void *, void *, s32);
void func_overlay_17_01101F7C_1F29AC4(void *, void *, s32);
void func_overlay_17_01102564_1F2A0AC(void *, void *, void *, s32);
void func_overlay_17_01102A54_1F2A59C(void *, void *, f32, s16, f32);
void func_overlay_17_0110313C_1F2AC84(void *, void *, s32, s32, f32);
void func_overlay_17_01102A40_1F2A588(void *, void *, s32, s32);
void func_overlay_17_01103258_1F2ADA0(u8 *, u8 *, f32, s16, f32);
void func_overlay_17_0110430C_1F2BE54(void *, void *, s32, s32, f32);
void func_overlay_17_01104614_1F2C15C(void *, void *, s32, s32, f32);
void func_overlay_17_01104C50_1F2C798(void *, void *, s32, f32);
void func_overlay_17_011050BC_1F2CC04(void *, void *, f32);
void func_overlay_17_011056D4_1F2D21C(void *, void *, s32);
void func_overlay_17_01105930_1F2D478(void *, void *, f32, s16, f32);
void func_overlay_17_01105F08_1F2DA50(void *, void *, s32, s32, f32);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Lupus main player control (overlay 17). Conventions as func_overlay_17_01103258_1F2ADA0:
// obj = player object (raw offsets), st = obj->0x68 player state (raw offsets).
// Field offsets in st/obj follow the Juno twin (func_overlay_16_01003464_1F2147C).
// Note: st+0x540 is read as a word (asm: lw) for the 0x40 test.
// Global symbol names come from the relocated m2c draft (per-instruction relocs).
void dogControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *st;
    u8 *chr;                 /* sp5C: mainGetGameCharacter() */
    u8 *hp;                  /* obj->0x4C */
    u8 *wt;                  /* weaponTable entry (0x30 bytes) */
    u8 *anim;                /* sp60: obj->0x6C[obj->0x3A] */
    u8 *animData;            /* sp64: anim->0 */
    u8 *flagp;               /* obj->0x58->0x84 */
    u8 *game;                /* sp48: mainGetGame() */
    s16 ypr[3];              /* sp70..sp74 */
    f32 vec[3];              /* sp78..sp80 */
    f32 speed;               /* sp8C */
    s16 yaw;                 /* sp76 */
    f32 dt;                  /* sp34: arg1 as float */
    f32 f0;
    s32 sp94;                /* landing / jump flag */
    s32 sp90;                /* controlUpdateWeapon result */
    s32 sp50;                /* weapon index before select */
    s32 i;
    s32 hit;                 /* trackPolyHeight result */
    s32 ret;
    u8 tmp;
    s8 cur;
    u8 v5ed;

    D_overlay_17_011069B8 = 0;
    D_overlay_17_011069BC = 0;
    st = *(u8 **)(obj + 0x68);
    *(s32 *)(obj + 0x84) = 0;
    D_overlay_17_011069C4 = st + 0x240;
    chr = (u8 *)mainGetGameCharacter(*(s8 *)(st + 0x0), *(s8 *)(st + 0x1));
    if (st[0x568] != 3) {
        st[0x56A] = 0;
    }
    st[0x14A] = 0;
    st[0x19E] = 0;
    *(s16 *)(st + 0x11E) = 0;
    *(s16 *)(st + 0x120) = 0;
    D_overlay_17_011069B0 = 0;
    dt = (f32)arg1;
    D_overlay_17_011069B4 = 0;
    controlPlatform(obj, st, dt);
    controlSquashCheckPrior(obj, st, arg1);
    D_overlay_17_011069C0 = *(s8 *)(st + 0x577);

    /* ---- countdown timers ---- */
    if (*(s8 *)(st + 0x56B) != 0) {
        controlDisableJoypad(1);
        st[0x56B] = (u8)(*(s8 *)(st + 0x56B) - arg1);
        if (*(s8 *)(st + 0x56B) < 0) {
            st[0x56B] = 0;
        }
    }
    if (*(s8 *)(st + 0x577) != 0) {
        controlDisableJoypad(1);
        st[0x577] = (u8)(*(s8 *)(st + 0x577) - arg1);
        if (*(s8 *)(st + 0x577) < 0) {
            st[0x577] = 0;
        }
    }
    if (st[0x1F9] != 0 || st[0x1FA] != 0 || *(s8 *)(st + 0x186) != 0 || st[0x198] != 0 ||
        st[0x5EE] != 0 || st[0x568] == 0xA || *(s32 *)(st + 0x5C0) != 0) {
        controlDisableJoypad(1);
    }
    if (st[0x19F] != 0 || st[0x10D] != 0) {
        controlDisableJoypad(1);
        if (*(s8 *)(obj + 0x3B) != 0x16) {
            func_overlay_17_01104B84_1F2C6CC(obj, st, 0x16, 0);
        }
    }
    if (st[0x1FA] >= 2) {
        st[0x1FA] = 0;
        D_overlay_17_011069BC = 1;
    }
    if (st[0x198] >= 2) {
        st[0x198] = 0;
    }
    if (st[0x10D] == 4) {
        st[0x10D] = 0;
        *(f32 *)(st + 0x594) = 0.0f;
    }

    controlReadJoypad(*(s8 *)(st + 0x0));
    controlMakeGravity(st);

    /* ---- clamp position / velocity ---- */
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
    if (*(f32 *)(st + 0x4) < -20.0f) {
        *(f32 *)(st + 0x4) = -20.0f;
    }
    if (*(f32 *)(st + 0x4) > 20.0f) {
        *(f32 *)(st + 0x4) = 20.0f;
    }
    if (*(f32 *)(st + 0x8) < -20.0f) {
        *(f32 *)(st + 0x8) = -20.0f;
    }
    if (*(f32 *)(st + 0x8) > 20.0f) {
        *(f32 *)(st + 0x8) = 20.0f;
    }
    controlFSUvels(obj, st);

    /* ---- orientation vector from yaw/pitch/roll ---- */
    ypr[0] = -*(s16 *)(st + 0x11C);
    ypr[1] = -*(s16 *)(obj + 0x2);
    ypr[2] = -*(s16 *)(obj + 0x4);
    vec[0] = 0.0f;
    vec[1] = -1.0f;
    vec[2] = 0.0f;
    ((void (*)(s16 *, f32 *))mathOneFloatYPR)(ypr, vec); /* sig mismatch: asm passes (s16 *, f32 *) */
    *(f32 *)(st + 0x54) = vec[0];
    *(f32 *)(st + 0x58) = vec[1];
    *(f32 *)(st + 0x50) = vec[2];

    /* ---- stick magnitude and heading ---- */
    speed = sqrtf((f32)((controlXjoy * controlXjoy) + (controlYjoy * controlYjoy)));
    if (speed > 65.0f) {
        speed = 65.0f;
    }
    speed = speed * 0.0625f;
    if (speed != 0.0f) {
        yaw = (s16)((s32)Arctanf((f32)controlXjoy, (f32)-controlYjoy) - *controlcam);
    } else {
        yaw = *(s16 *)(st + 0x11C);
    }

    /* ---- hit-timer / ground-pound charge ---- */
    tmp = st[0x568];
    if (((tmp == 0) || (tmp == 5) || (tmp == 0xB)) && !(*(u8 *)(*(u8 **)(st + 0x360) + 0x5) & st[0x532]) &&
        st[0x10D] == 0 && st[0x19F] == 0) {
        *(s8 *)(st + 0x185) = (s8)(*(s8 *)(st + 0x185) + arg1);
        if (*(s8 *)(st + 0x185) >= 0x10) {
            *(f32 *)(st + 0x57C) = *(f32 *)(obj + 0x10);
            func_overlay_17_01104B84_1F2C6CC(obj, st, 0x10, 0);
            tmp = st[0x568];
            st[0x568] = 3;
            st[0x58E] = 0;
            st[0x56A] = tmp;
        }
    } else if (((tmp == 2) || (tmp == 1)) && !(*(u8 *)(*(u8 **)(st + 0x360) + 0x5) & st[0x532])) {
        *(s8 *)(st + 0x185) = (s8)(*(s8 *)(st + 0x185) + arg1);
        if (*(s8 *)(st + 0x185) >= 0x10) {
            *(f32 *)(st + 0x57C) = *(f32 *)(obj + 0x10);
            func_overlay_17_01104B84_1F2C6CC(obj, st, 0x10, 0);
            st[0x56A] = 0;
            st[0x568] = 3;
            st[0x58E] = 0;
        }
    } else {
        st[0x185] = 0;
    }
    if (((*(u8 *)(*(u8 **)(st + 0x360) + 0x5) & st[0x532]) && st[0x568] != 3) || st[0x568] == 4) {
        *(f32 *)(st + 0x57C) = *(f32 *)(obj + 0x10);
    }

    /* ---- aim update from the weapon table ---- */
    wt = weaponTable + (chr[0x70] * 0x30);
    if (st[0x568] != 5 && st[0x568] != 0xB && st[0x568] != 0xA) {
        controlUpdatePlayerAim(obj, st, *(s32 *)(wt + 0xC), *(s32 *)(wt + 0x14), *(f32 *)(wt + 0x18),
                               *(f32 *)(wt + 0x1C), *(f32 *)(wt + 0x20), arg1);
    } else {
        st[0x1F4] = 1;
    }
    if (st[0x568] != 0xA) {
        controlFadePlayer(st, chr, arg1);
    }

    /* ---- ground / track height ---- */
    sp94 = 0;
    hit = trackPolyHeight(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x14), st + 0x5C, 0x80002000);
    if (hit < 0 && *(f32 *)(obj + 0x10) < *(f32 *)(st + 0x5C)) {
        st[0x5EE] = 1;
    }
    if ((hit & 0x2000) && (*(f32 *)(obj + 0x10) < *(f32 *)(st + 0x5C))) {
        st[0x2] = 1;
        *(f32 *)(st + 0x60) = *(f32 *)(st + 0x5C) - *(f32 *)(obj + 0x10);
        if (st[0x3] != 1 && *(f32 *)(st + 0x74) < 0.0f) {
            func_overlay_17_01101A30_1F29578(obj, st, arg1);
        }
        if ((*(s8 *)(st + 0x1) == 6 && *(f32 *)(st + 0x60) > 12.5f) ||
            (*(s8 *)(st + 0x1) == 2 && *(f32 *)(st + 0x60) > 28.0f)) {
            sp94 = 1;
        }
    } else {
        st[0x2] = 0;
        *(f32 *)(st + 0x60) = 0.0f;
    }

    /* ---- enter state 4 (landing / jump) ---- */
    tmp = st[0x568];
    if ((((s32)tmp < 4) || (tmp == 0xB) || (tmp == 5)) && (sp94 != 0)) {
        st[0x568] = 4;
        *(s16 *)(st + 0x12A) = 0;
        *(s16 *)(st + 0x12C) = 0;
        *(s16 *)(st + 0x128) = *(s16 *)(st + 0x11C);
        if (*(s8 *)(st + 0x1) == 6) {
            func_overlay_17_01104B84_1F2C6CC(obj, st, 6, *(s32 *)(obj + 0x28));
        } else {
            st[0x53D] = 0;
            st[0x540] = (u8)(st[0x540] & 0xFF7F);
            st[0x538] = 0;
            f0 = *(f32 *)(st + 0x4);
            if ((f0 < D_overlay_17_011067C0) || (D_overlay_17_011067C4 < f0) ||
                (D_overlay_17_011067C4 < *(f32 *)(obj + 0x20))) {
                func_overlay_17_01104B84_1F2C6CC(obj, st, 0x14, *(s32 *)(obj + 0x28));
            } else {
                func_overlay_17_01104B84_1F2C6CC(obj, st, 0x15, *(s32 *)(obj + 0x28));
            }
        }
    }

    /* ---- invulnerability / death ---- */
    hp = *(u8 **)(obj + 0x4C);
    if (*(s16 *)(hp + 0x6) < 0x100 && st[0x568] != 0xA) {
        if (invulnerabilityCheat != 0) {
            *(s16 *)(hp + 0x6) = 0x2200;
        } else {
            if (*(s8 *)(st + 0x1) == 6 && st[0x568] == 4) {
                func_overlay_17_01104B84_1F2C6CC(obj, st, 0x1C, 0);
            } else {
                func_overlay_17_01104B84_1F2C6CC(obj, st, 0x17, 0);
            }
            *(s16 *)(*(u8 **)(obj + 0x4C) + 0x6) = 0;
            if (multiPlayerGame == 0) {
                amTunePlay(0x38);
            } else {
                objEnsureNotTargetted(obj);
            }
            st[0x568] = 0xA;
            controlKeys = 0;
            controlDkeys = 0;
            st[0x53D] = 0;
            controlEmptyPlayersHand(obj);
            controlClearAimlocks(st);
        }
    }
    if (st[0x568] != 0) {
        st[0x13E] = 0;
        if (st[0x568] != 1) {
            st[0x576] = 0;
        }
    }

    /* ---- state dispatch (jump table, cases 0-5, 10, 11) ---- */
    switch (st[0x568]) {
    case 0:
        func_overlay_17_01102A54_1F2A59C(obj, st, speed, yaw, dt);
        break;
    case 1:
        /* cast: defined with (s32, s32, f32); asm passes speed/yaw as float/s16 */
        ((void (*)(void *, void *, f32, s16, f32))func_overlay_17_0110313C_1F2AC84)(obj, st, speed, yaw, dt);
        break;
    case 2:
        /* cast: existing definition is an empty stub with (s32, s32); asm signature is (f32, s16, f32) */
        ((void (*)(void *, void *, f32, s16, f32))func_overlay_17_01102A40_1F2A588)(obj, st, speed, yaw, dt);
        break;
    case 3:
        func_overlay_17_01103258_1F2ADA0((u8 *)obj, st, speed, yaw, dt);
        break;
    case 5:
        ((void (*)(void *, void *, f32, s16, f32))func_overlay_17_0110430C_1F2BE54)(obj, st, speed, yaw, dt);
        break;
    case 4:
        func_overlay_17_01105930_1F2D478(obj, st, speed, yaw, dt);
        break;
    case 10:
        /* cast: defined with (s32, s32, f32); asm passes floats */
        ((void (*)(void *, void *, f32, f32, f32))func_overlay_17_01105F08_1F2DA50)(obj, st, speed, (f32)yaw, dt);
        break;
    case 11:
        ((void (*)(void *, void *, f32, s16, f32))func_overlay_17_01104614_1F2C15C)(obj, st, speed, yaw, dt);
        break;
    default:
        break;
    }

    if (st[0x1F6] != 0) {
        st[0x1F6] = (u8)(st[0x1F6] - arg1);
        if (*(s8 *)(st + 0x1F6) < 0) {
            st[0x1F6] = 0;
        }
    }

    /* ---- cheats / weapon select ---- */
    if (allweaponsCheat != 0) {
        chr[0x6F] = 0xF;
        *(u16 *)(chr + 0xA) = 0x7FFF;
    }
    if ((*(u16 *)(chr + 0xA) & 0x20) && (mainPlayerHas(*(s8 *)(st + 0x0), *(s8 *)(st + 0x1), 0xA) == 0)) {
        mainPlayerCollected(*(s8 *)(st + 0x0), *(s8 *)(st + 0x1), 0xA);
    }
    st[0x540] = (u8)(st[0x540] & 0xFFCF);
    if (chr[0x6F] >= 2) {
        sp50 = chr[0x70];
        if ((sp50 != *(s8 *)(st + 0x585)) && (disablejoy == 0)) {
            controlSelectWeapon(obj, st, *(s8 *)(st + 0x585), 0); /* asm: a3 not set here */
        } else if (*(s32 *)((u8 *)controlModeKeys + 0x4) & controlDkeys) {
            controlSelectNextWeapon(obj, st, *(s8 *)(st + 0x585));
        } else if (*(s32 *)((u8 *)controlModeKeys + 0x8) & controlDkeys) {
            controlSelectPreviousWeapon(obj, st, *(s8 *)(st + 0x585));
        } else {
            game = (u8 *)mainGetGame();
            for (i = 0; i < 4; i++) {
                if (quickWeaponKey[i] & controlDkeys) {
                    if (controlSelectWeapon(obj, st, (s8)game[i + 0x534], i) != 0) {
                        break;
                    }
                }
            }
        }
        if (sp50 != chr[0x70]) {
            st[0x538] = 0;
            st[0x53D] = 0;
            st[0x585] = chr[0x70];
        }
    }

    /* cast: defined with (s32, f32); asm passes speed as float */
    ((void (*)(void *, void *, f32, f32))func_overlay_17_01104C50_1F2C798)(obj, st, speed, dt);
    func_overlay_17_011050BC_1F2CC04(obj, st, dt);
    controlSquashCheckPost(obj, st, arg1);

    /* ---- lethal fall / damage reaction ---- */
    if ((*(s32 *)(st + 0x520) & 0x8000) && st[0x568] != 0xA && *(s16 *)(st + 0x5C8) == 0) {
        amSndPlay(0x214, st + 0xD4);
        charSpeak(obj, 3);
        hp = *(u8 **)(obj + 0x4C);
        *(s16 *)(hp + 0x6) = (s16)(*(s16 *)(hp + 0x6) - 0x900);
        hp = *(u8 **)(obj + 0x4C);
        if (*(s16 *)(hp + 0x6) >= 0x100) {
            st[0x568] = 3;
            *(f32 *)(obj + 0x20) = 6.0f;
            st[0x14B] = 0x3C;
            st[0x57A] = 0;
            *(f32 *)(st + 0x594) = D_overlay_17_011067F8;
            st[0x58E] = 0;
            *(f32 *)(st + 0x57C) = *(f32 *)(obj + 0x10);
            D_overlay_17_011069B0 |= 1;
            D_overlay_17_011069B4 |= 1;
            objAnimSetMove(obj, 5, 0, 0); /* asm: a3 not set here */
        } else {
            *(s16 *)(hp + 0x6) = 0;
            if (multiPlayerGame != 0) {
                hitPlayerKilledPlayer(obj, obj, NULL, 0); /* asm: a2/a3 not set here */
            }
        }
    } else {
        if (*(s8 *)(st + 0x14B) > 0) {
            st[0x14B] = (u8)(*(s8 *)(st + 0x14B) - arg1);
            *(s32 *)(obj + 0x84) = *(s32 *)(obj + 0x84) | 0x80;
        }
    }

    tmp = st[0x568];
    if (tmp != 5 && tmp != 0xB && tmp != 3 && tmp != 8) {
        func_overlay_17_011056D4_1F2D21C(obj, st, arg1);
    }

    /* ---- invincibility shield ---- */
    if (*(s32 *)(st + 0x5BC) != 0) {
        switch (st[0x568]) {
        case 2:
            invincibilityShieldTransform(*(s32 *)(st + 0x5BC), 1.5f, 0.5f, 0x28);
            break;
        case 4:
            invincibilityShieldTransform(*(s32 *)(st + 0x5BC), 1.5f, 0.5f, 0x78);
            break;
        case 1:
            invincibilityShieldTransform(*(s32 *)(st + 0x5BC), 1.0f, 0.75f, 0x78);
            break;
        default:
            invincibilityShieldTransform(*(s32 *)(st + 0x5BC), 1.0f, 1.0f, 0x78);
            break;
        }
    }

    /* ---- Lupus heading (yaw) ease toward 0x120 / 0 ---- */
    if (*(s8 *)(st + 0x1) == 6) {
        if (st[0x568] == 0) {
            *(s16 *)(st + 0x34A) = dAngle(*(s16 *)(st + 0x34A), *(s16 *)(st + 0x120),
                                          1.0f - Powerf(D_overlay_17_011067FC, arg1));
        } else {
            *(s16 *)(st + 0x34A) = dAngle(*(s16 *)(st + 0x34A), 0,
                                          1.0f - Powerf(D_overlay_17_01106800, arg1));
        }
        if (*(s16 *)(st + 0x34A) < 0) {
            *(s16 *)D_overlay_17_011069C4 = 0x5E;
            D_overlay_17_011069C4 += 2;
            *(s16 *)D_overlay_17_011069C4 = (s16)-*(s16 *)(st + 0x34A);
            D_overlay_17_011069C4 += 2;
        } else if (*(s16 *)(st + 0x34A) > 0) {
            *(s16 *)D_overlay_17_011069C4 = 0x52;
            D_overlay_17_011069C4 += 2;
            *(s16 *)D_overlay_17_011069C4 = (s16)-*(s16 *)(st + 0x34A);
            D_overlay_17_011069C4 += 2;
        }
    }

    func_overlay_17_01101F7C_1F29AC4(obj, st, arg1);

    /* ---- display list: heading / pitch entries ---- */
    if (*(s8 *)(st + 0x1) == 6) {
        *(s16 *)D_overlay_17_011069C4 = 0x3A;
        D_overlay_17_011069C4 += 2;
        *(s16 *)D_overlay_17_011069C4 = (s16)-*(s16 *)(obj + 0x4);
        D_overlay_17_011069C4 += 2;
    } else {
        *(s16 *)D_overlay_17_011069C4 = 0x5E;
        D_overlay_17_011069C4 += 2;
        *(s16 *)D_overlay_17_011069C4 = (s16)-*(s16 *)(obj + 0x4);
        D_overlay_17_011069C4 += 2;
    }
    if (*(s32 *)(st + 0x540) & 0x40) {
        *(s16 *)D_overlay_17_011069C4 = 0x4030;
        D_overlay_17_011069C4 += 2;
        *(s16 *)D_overlay_17_011069C4 = 0x20;
        D_overlay_17_011069C4 += 2;
        *(s16 *)D_overlay_17_011069C4 = 0x4032;
        D_overlay_17_011069C4 += 2;
        *(s16 *)D_overlay_17_011069C4 = 0x20;
        D_overlay_17_011069C4 += 2;
        *(s16 *)D_overlay_17_011069C4 = 0x4034;
        D_overlay_17_011069C4 += 2;
        *(s16 *)D_overlay_17_011069C4 = 0x20;
        D_overlay_17_011069C4 += 2;
    }
    *(s16 *)D_overlay_17_011069C4 = 0x1000;
    D_overlay_17_011069C4 += 2;

    /* ---- sound loop / flag 0x84 ---- */
    if ((*(s8 *)(st + 0x576) != 0) ||
        ((st[0x188] != 0) && (st[0x532] & *(u8 *)(*(u8 **)(st + 0x360) + 0x5)) &&
         ((*(f32 *)(obj + 0x1C) < -1.0f) || (*(f32 *)(obj + 0x1C) > 1.0f) ||
          (*(f32 *)(obj + 0x24) < -1.0f) || (*(f32 *)(obj + 0x24) > 1.0f)))) {
        *(s32 *)(obj + 0x84) = *(s32 *)(obj + 0x84) | D_overlay_17_01106450[*(u8 *)((u8 *)levelGetLevel() + 0xE2)];
        if (*(s32 *)(st + 0xC8) == 0) {
            amSndPlay(0x1C, st + 0xC8);
        }
    } else {
        *(s32 *)(obj + 0x84) = *(s32 *)(obj + 0x84) & ~6;
        if (*(s32 *)(st + 0xC8) != 0) {
            amSndStop(*(s32 *)(st + 0xC8));
        }
    }
    if ((st[0x568] == 0xA) || (st[0x10D] != 0) || (st[0x19F] != 0)) {
        obj[0x9F] = 3;
    } else {
        obj[0x9F] = 0;
    }

    /* ---- animation / gun matrices ---- */
    anim = *(u8 **)(*(u8 **)(obj + 0x6C) + (*(s8 *)(obj + 0x3A) * 4));
    if (anim != NULL && *(s8 *)(anim + 0xA) != 0) {
        animData = *(u8 **)anim;
        modGenAnimMatrices(anim, animData, obj, *(f32 *)(st + 0x48), 0.0f);
        ret = objMakeGunMtx(obj, anim, animData, chr[0x70], st + 0x78, st + 0x544, st + 0x548, st + 0x54C);
        st[0x540] = (u8)(((ret << 2) & 4) | (st[0x540] & 0xFFFB));
        lightObject(obj, anim, *(s32 *)(obj + 0x54), *(s32 *)(anim + (*(s8 *)(anim + 0xB) * 4) + 0x10));
        if (*(s8 *)(st + 0x1) == 2) {
            objAnimTextures(obj, animData, anim, *(s8 *)(anim + 0xA));
        } else {
            func_overlay_17_01102564_1F2A0AC(animData, anim, st, *(s8 *)(anim + 0xA));
        }
        anim[0xA] = 0;
        if (animData[0x2F] >= 3) {
            f0 = (*(f32 *)(*(u8 **)(anim + 0x70) + 0x1C) + 4.0f) - *(f32 *)(obj + 0x10);
            if (64.0f <= f0) {
                f0 = D_overlay_17_01106804;
            }
            *(s8 *)(*(u8 **)(obj + 0x50) + 0xE) = (s8)(s32)(f0 * 4.0f);
        }
    }

    /* ---- weapon update / throw ---- */
    sp90 = controlUpdateWeapon(obj, st, dt);
    if (controlThrowWeapon(sp90) != 0) {
        if (*(s8 *)(st + 0x1) == 6 && st[0x568] == 4) {
            if (*(s8 *)(obj + 0x3B) == 0x1B) {
                objAnimSetMove(obj, 0x1B, 0, 0); /* asm: a3 not set here */
            } else {
                func_overlay_17_01104B84_1F2C6CC(obj, st, 0x1B, 0);
            }
        } else if (*(s8 *)(obj + 0x3B) == 0xE) {
            objAnimSetMove(obj, 0xE, 0, 0); /* asm: a3 not set here */
        } else {
            func_overlay_17_01104B84_1F2C6CC(obj, st, 0xE, 0);
        }
        st[0x577] = 0x28;
    }
    controlUpdateJetFlames(obj, st, 0xF000, 0xF00, arg1);

    *(u8 *)(*(u8 **)(obj + 0x58) + 0x75) = 0;
    flagp = *(u8 **)(*(u8 **)(obj + 0x58) + 0x84);
    if (flagp != NULL) {
        *flagp = (u8)(*flagp & 0xFFFD);
    }
    if (*(s8 *)(st + 0x2) == 1) {
        if (*(f32 *)(st + 0x60) < 50.0f) {
            *(f32 *)(*(u8 **)(obj + 0x58) + 0x80) = *(f32 *)(st + 0x5C);
            *(u8 *)(*(u8 **)(obj + 0x58) + 0x75) = 1;
            if (flagp != NULL) {
                if ((*(f32 *)(st + 0x4) < -1.0f) || (*(f32 *)(st + 0x4) > 1.0f) ||
                    (*(f32 *)(st + 0x10) < -1.0f) || (*(f32 *)(st + 0x10) > 1.0f)) {
                    *flagp = (u8)(*flagp | 2);
                }
            }
        }
    }
    wakeUpdateRipple(obj, arg1);
    partUpdateTriggers(obj, arg1);

    /* ---- looping ambient sounds ---- */
    if (*(s8 *)(obj + 0x3B) == 9 || *(s8 *)(obj + 0x3B) == 0xC) {
        if (*(s32 *)(st + 0xBC) == 0) {
            amSndPlayXYZ(0x135, *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14), 1, st + 0xBC);
            *(u16 *)(st + 0xB8) = 0x135;
        } else if (*(u16 *)(st + 0xB8) == 0x135) {
            amSndSetXYZ((SoundMask *)*(s32 *)(st + 0xBC), *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10),
                        *(f32 *)(obj + 0x14));
        }
    } else {
        if (*(s32 *)(st + 0xBC) != 0 && *(u16 *)(st + 0xB8) == 0x135) {
            amSndStopXYZ((SoundMask *)*(s32 *)(st + 0xBC));
        }
    }

    if (*(s8 *)(st + 0x1) == 6) {
        if (((*(f32 *)(st + 0x4) < D_overlay_17_01106808) || (D_overlay_17_0110680C < *(f32 *)(st + 0x4)) ||
             (*(f32 *)(st + 0x8) < -0.5f) || (*(f32 *)(st + 0x8) > 0.5f)) &&
            (st[0x568] != 3) &&
            ((controlXjoy != 0) || (controlYjoy != 0) ||
             ((*(s32 *)((u8 *)controlModeKeys + 0x20) | *(s32 *)((u8 *)controlModeKeys + 0x14) |
               *(s32 *)((u8 *)controlModeKeys + 0x18) | *(s32 *)((u8 *)controlModeKeys + 0x1C)) &
              controlKeys))) {
            if ((*(s32 *)(st + 0x5D8) != 0) && (*(s8 *)(st + 0x5EC) == 1)) {
                amSndStop(*(s32 *)(st + 0x5D8));
            }
            if (*(s32 *)(st + 0x5D8) == 0) {
                st[0x5EC] = 0;
                st[0x5ED] = 0x7F;
                amSndPlay(0x1F8, st + 0x5D8);
            }
            v5ed = (u8)(st[0x5ED] - arg1);
            st[0x5ED] = v5ed;
            if (v5ed < 0x30) {
                st[0x5ED] = 0x30;
                v5ed = 0x30;
            }
            amSndSetVol(0x1F8, *(s32 *)(st + 0x5D8), v5ed);
        } else {
            if ((*(s32 *)(st + 0x5D8) != 0) && (st[0x5EC] == 0)) {
                amSndStop(*(s32 *)(st + 0x5D8));
                st[0x5EC] = 1;
                amSndPlay(0x1F9, st + 0x5D8);
            }
        }
    }
    if (*(s8 *)(st + 0x14A) != 0) {
        if (*(s32 *)(st + 0xCC) == 0) {
            amSndPlay(0x9C, st + 0xCC);
        }
    } else {
        if (*(s32 *)(st + 0xCC) != 0) {
            amSndStop(*(s32 *)(st + 0xCC));
        }
    }

    controlSetRumble(*(s8 *)(st + 0x0), D_overlay_17_011069B0, D_overlay_17_011069B4, sp90,
                     *(s16 *)(st + 0x536) / arg1);
    *(s16 *)(st + 0x536) = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o17/overlay_17/dogControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 dogCanFire(s32 arg0, void *arg1) {
    u8 *st = (u8 *)arg1;
    s32 state;

    if (*(s8 *)(st + 0x576) == 0 && *(u8 *)(st + 0x13E) == 0) {
        state = *(u8 *)(st + 0x568) & ~0x20;
        if (state == 0 || state == 5 || state == 0xB || state == 0xA ||
            (state == 3 && *(s8 *)(st + 0x14A) != 0)) {
            return 1;
        }
        if (*(u8 *)(st + 0x1) == 6 && state == 4) {
            return 1;
        }
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o17/overlay_17/dogCanFire.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_17_01101A30_1F29578(void *arg0, void *arg1, s32 arg2) {
    u8 *obj = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    u32 setup[4];
    u8 *sp;
    s32 vol;
    s32 savedA;
    s16 savedX2;
    s16 savedY4;
    f32 scale;
    void *spawned;

    vol = (s32)(-*(f32 *)(st + 0x74) * 15.0f);
    if (vol >= 0x80) {
        vol = 0x7F;
    }
    amSndPlay(0xD, st + 0xD4);
    amSndSetVol(0xD, *(s32 *)(st + 0xD4), vol & 0xFF);
    if (*(f32 *)(st + 0x74) < -5.0f) {
        sp = (u8 *)setup;
        *(s16 *)(sp + 0x0) = 0xC0;
        sp[2] = 0x10;
        *(s16 *)(sp + 0x4) = (s16)*(f32 *)(obj + 0xC);
        *(s16 *)(sp + 0x6) = (s16)*(f32 *)(st + 0x5C);
        *(s16 *)(sp + 0x8) = (s16)*(f32 *)(obj + 0x14);
        *(s16 *)(sp + 0xA) = 0x100;
        scale = -(*(f32 *)(st + 0x74) + 5.0f);
        if (scale > 10.0f) {
            scale = 10.0f;
        }
        *(f32 *)(sp + 0xC) = scale;
        spawned = objSetupObject((void *)sp, 1);
        if (spawned != NULL) {
            *(s32 *)((u8 *)spawned + 0x3C) = 0;
        }
    } else {
        savedX2 = *(s16 *)(obj + 0x2);
        savedY4 = *(s16 *)(obj + 0x4);
        savedA = *(s32 *)(obj + 0x84);
        *(s16 *)(obj + 0x4) = 0;
        *(s16 *)(obj + 0x2) = 0;
        *(f32 *)(obj + 0x10) = *(f32 *)(obj + 0x10) + *(f32 *)(st + 0x60);
        *(s32 *)(obj + 0x84) = 0x40;
        partUpdateTriggers(arg0, arg2);
        *(f32 *)(obj + 0x10) = *(f32 *)(obj + 0x10) - *(f32 *)(st + 0x60);
        *(s16 *)(obj + 0x2) = savedX2;
        *(s16 *)(obj + 0x4) = savedY4;
        *(s32 *)(obj + 0x84) = savedA;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o17/overlay_17/func_overlay_17_01101A30_1F29578.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_17_01101C44_1F2978C(void *arg0, void *arg1, f32 arg2, f32 arg3) {
    u8 *obj = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    f32 sp94 = 0.0f;
    f32 sp90 = 0.0f;
    f32 vec[3];
    s16 rot[2];
    f32 var_f0;
    f32 var_f2;
    f32 var_f12;
    f32 f20;
    f32 f22;
    f32 f24;
    f32 cosv;
    f32 pos;
    f32 zval;
    s32 hit = 0;
    s32 count;
    s32 i;

    if (*(u8 *)(st + 0x568) == 0) {
        if (*(f32 *)(st + 0x60) > 0.0f) {
            if (*(f32 *)(st + 0x4) < -1.0f) {
                if (arg3 < 0.0f) {
                    var_f0 = *(f32 *)(obj + 0x28);
                    var_f2 = arg2;
                    if (arg2 < var_f0) {
                        var_f0 -= 1.0f;
                    }
                } else {
                    var_f2 = *(f32 *)(obj + 0x28);
                    var_f0 = arg2;
                    if (var_f2 < arg2) {
                        var_f2 += 1.0f;
                    }
                }
                var_f12 = D_overlay_17_01106810;
                if ((var_f0 < var_f12) && (var_f12 <= var_f2)) {
                    hit = 1;
                    sp94 = 4.0f;
                    sp90 = 16.0f;
                } else {
                    var_f12 = D_overlay_17_01106814;
                    if ((var_f0 < var_f12) && (var_f12 < var_f2)) {
                        hit = 1;
                        sp94 = -4.0f;
                        sp90 = 16.0f;
                    }
                }
                if (hit != 0) {
                    count = 2 - (s32)(*(f32 *)(st + 0x4) + 1.0f);
                    /* asm: first trig call is Sinf, second is Cosf, both on obj->unk0 */
                    f20 = Sinf(*(s16 *)obj);
                    cosv = Cosf((s32)*(s16 *)obj);
                    f22 = *(f32 *)(obj + 0xC) + ((sp94 * cosv) + (sp90 * f20));
                    f24 = *(f32 *)(obj + 0x14) + ((sp90 * cosv) - (sp94 * f20));
                    for (i = 0; i < count; i++) {
                        pos = (f32)mathRnd(0x32, 0x64) * D_overlay_17_0110681C;
                        rot[0] = (s16)(mathRnd(-0x2555, 0x2555) + *(s16 *)obj);
                        rot[1] = (s16)mathRnd(0x2400, 0x3C00);
                        vec[2] = ((f32)mathRnd(0xC, 0x16) * D_overlay_17_01106818) + (*(f32 *)(st + 0x4) * 0.25f);
                        mathOneFloatPY(rot, vec);
                        zval = *(f32 *)(st + 0x5C);
                        dropletAdd(pos, f22, zval, f24, zval, vec[0], vec[1], vec[2]);
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o17/overlay_17/func_overlay_17_01101C44_1F2978C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_17_01101F7C_1F29AC4(void *arg0, void *arg1, s32 arg2) {
    u8 *obj = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    u8 *sub;
    u8 *ent;
    s32 count;
    s32 i;
    s32 t4 = 0;     /* asm: uninitialised stack reads in the original; only used when set */
    s32 a0v = 0;
    s32 t2 = 0;
    s32 a3 = 0;
    s32 t5 = 0;
    s32 t8;
    s16 v6;
    s32 at;
    s32 tmp;
    u8 t9;
    s32 v0tmp;

    sub = *(u8 **)(obj + 0x4C);
    count = *(s16 *)(sub + 0x32);
    ent = *(u8 **)(sub + 0x40);
    if (count > 0) {
        i = 0;
        do {
            if (ent[0xA] & 0x40) {
                t5 = 1;
                if (*(u8 *)(st + 0x1) == 2) {
                    switch (i) {
                    default:
                        D_overlay_17_011069B4 |= 1;
                        D_overlay_17_011069B0 |= 1;
                        t2 = 0xF;
                        t4 = 5;
                        break;
                    case 0:
                    case 1:
                        t8 = D_overlay_17_011069B4 | 1;
                        a3 = 0xF;
                        a0v = 4;
                        D_overlay_17_011069B0 |= 2;
                        D_overlay_17_011069B4 = t8;
                        break;
                    case 2:
                        t8 = D_overlay_17_011069B4 | 1;
                        a3 = 0xF;
                        a0v = 3;
                        D_overlay_17_011069B0 |= 4;
                        D_overlay_17_011069B4 = t8;
                        break;
                    }
                } else if (i != 0) {
                    if (i != 1) {
                        D_overlay_17_011069B4 |= 1;
                        D_overlay_17_011069B0 |= 1;
                        t2 = 0xF;
                        t4 = 5;
                    } else {
                        D_overlay_17_011069B0 |= 2;
                        D_overlay_17_011069B4 |= 1;
                        a3 = 0xF;
                        a0v = 4;
                    }
                } else {
                    D_overlay_17_011069B0 |= 4;
                    D_overlay_17_011069B4 |= 1;
                    a3 = 0xF;
                    a0v = 3;
                }
            }
            i += 1;
            ent += 0x34;
        } while (i < count);
    }
    if (t5 != 0) {
        if ((t2 != 0) && (*(u8 *)(st + 0x342) == 0)) {
            *(s8 *)(st + 0x342) = (s8)t2;
            *(u8 *)(st + 0x343) = (u8)t4;
        }
        if ((a3 != 0) && (*(u8 *)(st + 0x340) == 0)) {
            *(s8 *)(st + 0x340) = (s8)a3;
            *(u8 *)(st + 0x341) = (u8)a0v;
        }
    }
    if (*(s8 *)(st + 0x342) != 0) {
        tmp = mathSin((s16)(*(s8 *)(st + 0x342) << 0xB), &D_overlay_17_011069B0, &D_overlay_17_011069B4, (s8)a3) >> *(u8 *)(st + 0x343);
        if (*(u8 *)(st + 0x1) == 2) {
            *(s16 *)D_overlay_17_011069C4 = 0x32;
        } else {
            *(s16 *)D_overlay_17_011069C4 = 0x20;
        }
        D_overlay_17_011069C4 += 2;
        *(s16 *)D_overlay_17_011069C4 = (s16)tmp;
        D_overlay_17_011069C4 += 2;
        if (arg2 < *(s8 *)(st + 0x342)) {
            *(s8 *)(st + 0x342) = (s8)(*(s8 *)(st + 0x342) - arg2);
        } else {
            *(s8 *)(st + 0x342) = 0;
        }
    }
    if (*(s8 *)(st + 0x340) != 0) {
        tmp = mathSin((s16)(*(s8 *)(st + 0x340) << 0xB), &D_overlay_17_011069B0, &D_overlay_17_011069B4, (s8)arg2) >> *(u8 *)(st + 0x341);
        if (*(u8 *)(st + 0x1) == 2) {
            *(s16 *)D_overlay_17_011069C4 = 0x30;
        } else {
            *(s16 *)D_overlay_17_011069C4 = 0x1E;
        }
        D_overlay_17_011069C4 += 2;
        *(s16 *)D_overlay_17_011069C4 = (s16)tmp;
        D_overlay_17_011069C4 += 2;
        if (arg2 < *(s8 *)(st + 0x340)) {
            *(s8 *)(st + 0x340) = (s8)(*(s8 *)(st + 0x340) - arg2);
        } else {
            *(s8 *)(st + 0x340) = 0;
        }
    }
    v6 = *(s16 *)(sub + 0x6);
    if (v6 >= 0x100) {
        at = 0;
        if (*(u8 *)(st + 0x190) == 0x80) {
            if (*(u8 *)(st + 0x5C8) == 0) {
                *(u8 *)(st + 0x190) = 0x3C;
                t5 = 1;
                *(s16 *)(sub + 0x6) = (s16)(v6 - 0x100);
                D_overlay_17_011069B0 |= 2;
                D_overlay_17_011069B4 |= 2;
                v6 = *(s16 *)(sub + 0x6);
                at = v6 < 0x100;
            }
        } else if (*(u8 *)(st + 0x190) == 0xC0) {
            if (*(u8 *)(st + 0x5C8) == 0) {
                *(u8 *)(st + 0x190) = 0x3C;
                t5 = 1;
                *(s16 *)(sub + 0x6) = (s16)(v6 - 0x200);
                D_overlay_17_011069B0 |= 4;
                D_overlay_17_011069B4 |= 2;
                v6 = *(s16 *)(sub + 0x6);
                at = v6 < 0x100;
            }
        } else {
            if (*(u8 *)(st + 0x56F) != 0) {
                if (*(u8 *)(st + 0x190) == 0) {
                    *(u8 *)(st + 0x190) = 0x3C;
                    D_overlay_17_011069B0 |= 1;
                    D_overlay_17_011069B4 |= 1;
                    t5 = 1;
                    v6 = *(s16 *)(sub + 0x6);
                }
                at = v6 < 0x100;
            }
        }
        if (at != 0) {
            *(s16 *)(sub + 0x6) = 0;
            if (multiPlayerGame != 0) {
                hitPlayerKilledPlayer(arg0, arg0, &D_overlay_17_011069B4, (s8)arg2);
            }
        }
    }
    t9 = *(u8 *)(st + 0x190) & 0x3F;
    v0tmp = t9 & 0xFF;
    *(u8 *)(st + 0x190) = t9;
    if (arg2 < v0tmp) {
        *(u8 *)(st + 0x190) = (u8)(v0tmp - arg2);
    } else {
        *(u8 *)(st + 0x190) = 0;
    }
    if ((t5 != 0) && (*(u8 *)(st + 0x568) != 0xA)) {
        charSpeak(arg0, 3);
        *(s8 *)(st + 0x148) = 8;
    } else {
        if (arg2 < *(s8 *)(st + 0x148)) {
            *(s8 *)(st + 0x148) = (s8)(*(s8 *)(st + 0x148) - arg2);
        } else {
            *(s8 *)(st + 0x148) = 0;
        }
    }
    if (*(s8 *)(st + 0x148) != 0) {
        fxNightVisionSkip();
        frontFlashScreen(0, *(s8 *)st, 0xFF0000FF);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o17/overlay_17/func_overlay_17_01101F7C_1F29AC4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_17_01102564_1F2A0AC(void *arg0, void *arg1, void *arg2, s32 arg3) {
    u8 *obj = (u8 *)arg0;
    u8 *anim = (u8 *)arg1;
    u8 *pl = (u8 *)arg2;
    u8 *entry;
    s16 *out;
    TextureHeader *tex;
    s32 type;
    s32 count;
    s32 i;
    s32 frame;
    s32 n;
    s16 temp;
    f32 ax;
    f32 az;

    entry = *(u8 **)(anim + 0x74);
    out = *(s16 **)(anim + *(u8 *)(anim + 0xB) * 4 + 0x78);
    count = *(s32 *)(obj + 0x2C);

    for (i = 0; i < count; i++) {
        type = *(u32 *)(entry + 4) & 0xFF;
        tex = *(TextureHeader **)(*(u8 **)(obj + 0x18) + type * 8);

        switch (type) {
        case 2:
            frame = *(s16 *)entry;
            if ((*(u32 *)(entry + 4) & 0x20000) && *(u8 *)(pl + 0x568) == 0xA) {
                blinkMode = 3;
            }
            texAnimateTexture(tex, (u32 *)(entry + 4), &frame, arg3);
            *(s16 *)entry = (s16)frame;
            break;
        case 9:
        case 11:
            frame = *(s16 *)entry;
            if (*(s8 *)(pl + 0x576) == 0) {
                ax = *(f32 *)(pl + 0x10);
                if (ax < 0.0f) {
                    ax = -ax;
                }
                az = *(f32 *)(pl + 0x4);
                if (az < 0.0f) {
                    az = -az;
                }
                if (az < ax) {
                    frame += (s32)(-*(f32 *)(pl + 0x10) * 128.0f);
                } else {
                    frame += (s32)(-*(f32 *)(pl + 0x4) * 128.0f);
                }
            }
            n = tex->numOfTextures;
            if (frame >= n) {
                while (frame >= n) {
                    frame -= n;
                }
            }
            if (frame < 0) {
                while (frame < 0) {
                    frame += n;
                }
            }
            *(s16 *)entry = (s16)frame;
            break;
        }

        *out = (s16)((*(s16 *)entry >> 8) * tex->textureSize);
        out++;
        temp = *(s16 *)(entry + 2);
        if (temp >= 0) {
            *out = (s16)((temp >> 8) * tex->textureSize);
            out++;
        }
        entry += 8;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o17/overlay_17/func_overlay_17_01102564_1F2A0AC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_17_01102848_1F2A390(void *arg0, void *arg1, f32 arg2) {
    u8 *obj = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    u8 *mk = (u8 *)controlModeKeys;
    u8 state;

    state = *(u8 *)(st + 0x568);
    *(u8 *)(st + 0x56C) = 0;
    if (state == 0 || state == 5 || state == 0xB) {
        if (*(s32 *)(mk + 0x14) & controlKeys) {
            *(f32 *)(st + 0x10) = *(f32 *)(st + 0x10) - (D_overlay_17_01106820 * arg2);
            if (*(f32 *)(st + 0x10) < -2.25f) {
                *(f32 *)(st + 0x10) = -2.25f;
            }
            if (*(u8 *)(st + 0x1) == 6) {
                if (*(s8 *)(obj + 0x3B) != 0x19) {
                    func_overlay_17_01104B84_1F2C6CC(obj, st, 0x19, 0);
                }
            }
            *(u8 *)(st + 0x56C) = 1;
        } else if (*(s32 *)(mk + 0x18) & controlKeys) {
            *(f32 *)(st + 0x10) = *(f32 *)(st + 0x10) + (D_overlay_17_01106824 * arg2);
            if (*(f32 *)(st + 0x10) > 2.25f) {
                *(f32 *)(st + 0x10) = 2.25f;
            }
            if (*(u8 *)(st + 0x1) == 6) {
                if (*(s8 *)(obj + 0x3B) != 0x1A) {
                    func_overlay_17_01104B84_1F2C6CC(obj, st, 0x1A, 0);
                }
            }
            *(u8 *)(st + 0x56C) = 1;
        }
    }
    if (*(u8 *)(st + 0x56C) == 0) {
        *(f32 *)(st + 0x10) = *(f32 *)(st + 0x10) * Powerf(D_overlay_17_01106828, (s32)arg2);
        if (D_overlay_17_0110682C < *(f32 *)(st + 0x10) && *(f32 *)(st + 0x10) < D_overlay_17_01106830) {
            *(f32 *)(st + 0x10) = 0.0f;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o17/overlay_17/func_overlay_17_01102848_1F2A390.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_17_01102A40_1F2A588(void *arg0, void *arg1, s32 arg2, s32 arg3) {
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o17/overlay_17/func_overlay_17_01102A40_1F2A588.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_17_01102A54_1F2A59C(void *arg0, void *arg1, f32 arg2, s16 arg3, f32 arg4) {
    u8 *obj = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    s32 sp5C = 0;
    f32 sp58;
    f32 sp54;
    s16 sp52;
    s32 sp44;
    f32 f14;
    f32 f2;
    f32 var_f8;
    f32 var_f14;
    f32 var_f14_6;
    u8 *tgt;
    void *ctrl;

    if (*(s8 *)(st + 0x576) != 0) {
        *(s8 *)(st + 0x576) = (s8)(*(s8 *)(st + 0x576) - (s32)arg4);
        if (*(s8 *)(st + 0x576) < 0) {
            *(s8 *)(st + 0x576) = 0;
        }
    }
    if ((*(s8 *)(obj + 0x3B) == 0x11) && (*(u8 *)(st + 0x56B) == 0)) {
        func_overlay_17_01104B84_1F2C6CC(obj, st, func_overlay_17_01104A44_1F2C58C(st, &sp54), 0);
    }
    if (controlKeys & 0x10) {
        s16 t6 = *(s16 *)(st + 0x10A);
        *(s16 *)(st + 0x10A) = 0;
        *(s16 *)(st + 0x11C) = (s16)(*(s16 *)(st + 0x11C) - t6);
        arg3 = *(s16 *)(st + 0x11C);
        if (lobbycamInuse() == 0) {
            staticcamInuse();
        }
        *(s16 *)(st + 0x1E2) = 0;
        *(s16 *)(st + 0x1E0) = 0;
        *(u8 *)(st + 0x568) = 0xB;
        *(s16 *)(st + 0x1CE) = 0;
        *(s16 *)(st + 0x1D0) = 0;
        *(f32 *)(st + 0x1E4) = 0.0f;
        *(f32 *)(st + 0x1E8) = 0.0f;
        *(s16 *)(st + 0x1C6) = *(s16 *)obj;
        *(s16 *)(st + 0x1C8) = *(s16 *)(obj + 0x2);
        *(s16 *)(st + 0x1DC) = *(s16 *)(st + 0x1CE);
        *(s16 *)(st + 0x1CA) = *(s16 *)(st + 0x1C6);
        *(s16 *)(st + 0x1CC) = *(s16 *)(st + 0x1C8);
        *(s16 *)(st + 0x1DE) = *(s16 *)(st + 0x1D0);
        return;
    }
    sp44 = (s32)arg4;
    controlWalkingBack(arg0, arg1, &arg2, arg3, 0x5000, 0x6800, 5.0f, 3.0f);
    func_overlay_17_01102848_1F2A390(arg0, arg1, arg4);
    ctrl = controlModeKeys;
    if ((*(s32 *)((u8 *)ctrl + 0xC) & controlDkeys) && (*(u8 *)(st + 0x534) == 0)) {
        f14 = *(f32 *)(st + 0x4);
        if (f14 < 0.0f) {
            f14 = -f14;
        }
        if (*(u8 *)(st + 0x569) != 0) {
            *(s8 *)(st + 0x57A) = 0x14;
            *(s8 *)(st + 0x57B) = 0;
            func_overlay_17_01104B84_1F2C6CC(obj, st, 5, 0);
        } else if (!((f14 > 1.25f)) || (arg2 == 0.0f)) {
            if (*(u8 *)(st + 0x56C) == 0) {
                *(s8 *)(st + 0x57A) = 0x18;
                *(s8 *)(st + 0x57B) = 0;
                func_overlay_17_01104B84_1F2C6CC(obj, st, 4, 0);
            } else {
                goto block_20;
            }
        } else {
block_20:
            *(s8 *)(st + 0x57A) = 0;
            *(f32 *)(obj + 0x20) = *(f32 *)(obj + 0x20) + 10.0f;
            if (*(u8 **)(st + 0x510) != NULL) {
                *(f32 *)(obj + 0x20) = *(f32 *)(obj + 0x20) - *(f32 *)(*(u8 **)(st + 0x510) + 0x20);
            }
            func_overlay_17_01104B84_1F2C6CC(obj, st, 5, 0);
            charSpeak(obj, 0);
        }
        *(u8 *)(st + 0x568) = 3;
        *(u8 *)(st + 0x58E) = 0;
        *(f32 *)(st + 0x57C) = *(f32 *)(obj + 0x10);
    } else if (*(s32 *)((u8 *)ctrl + 0x10) & controlDkeys) {
        f14 = *(f32 *)(st + 0x4);
        if (f14 < 0.0f) {
            f14 = -f14;
        }
        if (f14 > 2.0f) {
            func_overlay_17_01104B84_1F2C6CC(obj, st, 8, 0);
            *(s8 *)(st + 0x576) = 0x28;
        } else {
            func_overlay_17_01104B84_1F2C6CC(obj, st, 7, 0);
        }
        *(u8 *)(st + 0x56C) = 0;
        *(u8 *)(st + 0x568) = 1;
    }
    if (*(s32 *)ctrl & controlKeys) {
        *(u8 *)(st + 0x1F4) = 0xF;
    }
    if (*(u8 *)(st + 0x569) == 0) {
        arg2 = -arg2;
    } else {
        arg3 += 0x8000;
    }
    controlHalfTurn(arg0, arg1, &arg2, &arg3, 0x6AAA, 0x38E, &sp5C, 0.0625f, arg4);
    if (sp5C != 0) {
        func_overlay_17_01104B84_1F2C6CC(obj, st, 8, 0);
    }
    sp52 = *(s16 *)(st + 0x11C);
    if ((lobbycamInuse() == 0) && (staticcamInuse() == 0)) {
        if ((*(u8 *)(st + 0x540) & 0xF) && (frontGetTargetControl(*(s8 *)st) == 0)) {
            f2 = *(f32 *)(st + 0x14);
            var_f8 = f2 + ((D_overlay_17_01106838 - f2) * (1.0f - Powerf(D_overlay_17_01106834, sp44)));
        } else {
            f2 = *(f32 *)(st + 0x14);
            var_f8 = f2 + ((D_overlay_17_01106840 - f2) * (1.0f - Powerf(D_overlay_17_0110683C, sp44)));
        }
        *(f32 *)(st + 0x14) = var_f8;
    }
    f14 = *(f32 *)(st + 0x4);
    if (f14 < 0.0f) {
        f14 = -f14;
    }
    f14 = f14 * 1.0f;
    var_f14 = f14 * f14;
    if (var_f14 > 1.0f) {
        var_f14 = 1.0f;
    }
    var_f14 = 1.0f - (((*(f32 *)(st + 0x14) - D_overlay_17_01106844) * var_f14) + D_overlay_17_01106844);
    if (*(u8 *)(st + 0x13E) != 0) {
        var_f14 = *(f32 *)&D_overlay_17_01106848;
    }
    *(s16 *)(st + 0x11C) = dAngle(*(s16 *)(st + 0x11C), arg3, 1.0f - Powerf(var_f14, sp44));
    f14 = *(f32 *)(st + 0x4);
    sp58 = f14;
    *(f32 *)(st + 0x4) = (((1.0f - Powerf(D_overlay_17_0110684C, sp44)) * (arg2 - f14)) + f14);
    sp52 = *(s16 *)(st + 0x11C) - sp52;
    if ((*(u8 *)(st + 0x568) == 0) && ((sp58 - *(f32 *)(st + 0x4)) < D_overlay_17_01106850)) {
        s8 t = *(s8 *)(obj + 0x3B);
        if ((t != 0xE) && (t != 0x1B) && (t != 0x11)) {
            *(s8 *)(st + 0x576) = 4;
            func_overlay_17_01104B84_1F2C6CC(obj, st, 8, 0);
        }
    }
    var_f14_6 = *(f32 *)(st + 0x4);
    if (var_f14_6 < 0.0f) {
        var_f14_6 = -var_f14_6;
    }
    if (var_f14_6 > 3.0f) {
        var_f14_6 = 3.0f;
    }
    *(s16 *)(st + 0x120) = (s16)(s32)((f32)sp52 * var_f14_6 * D_overlay_17_01106854);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o17/overlay_17/func_overlay_17_01102A54_1F2A59C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_17_0110313C_1F2AC84(void *arg0, void *arg1, s32 arg2, s32 arg3, f32 arg4) {
    u8 *obj = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    s8 t;

    func_overlay_17_01102848_1F2A390(obj, st, arg4);
    t = *(s8 *)(st + 0x576);
    if (t != 0) {
        *(s8 *)(st + 0x576) = (s8)(t - (s32)arg4);
        if (*(s8 *)(st + 0x576) <= 0) {
            *(s8 *)(st + 0x576) = 0;
            *(f32 *)(st + 0x4) = 0.0f;
            func_overlay_17_01104B84_1F2C6CC(obj, st, 7, 0);
        }
    } else if (*(f32 *)(obj + 0x28) == 1.0f) {
        func_overlay_17_01104B84_1F2C6CC(obj, st, 0, 0);
        *(u8 *)(st + 0x568) = 0;
        *(s8 *)(st + 0x576) = 0;
    }
    *(f32 *)(st + 0x4) = *(f32 *)(st + 0x4) * Powerf(D_overlay_17_01106858, (s32)arg4);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o17/overlay_17/func_overlay_17_0110313C_1F2AC84.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Lupus player per-frame move step. Twin of Juno func_overlay_16_01003464_1F2147C
// (arg0 = player object, arg1 = player state, arg4 = frame delta).
// Field offsets in arg1 are raw, as in the Juno twin; the 0x14A..0x594 layout is
// the same struct the other player overlays use.
void func_overlay_17_01103258_1F2ADA0(u8 *arg0, u8 *arg1, f32 arg2, s16 arg3, f32 arg4) {
    s32 frames;     /* asm: (s32)arg4, stored at 0x40(sp) */
    s32 sp60;       /* asm: st->58C (s16) at entry, stored at 0x60(sp) */
    s32 sp5C;       /* asm: sound volume */
    s32 sp68;       /* asm: old st->11C */
    s32 var;        /* asm: trimmed 57B value / Powerf-like scratch */
    s32 v0;         /* asm: sound loop counter ($v0) */
    s32 v1;         /* asm: sound loop id ($v1) */
    s32 delta;      /* asm: new st->11C - old st->11C */
    s32 iv;         /* asm: (s32)st->4 */
    s16 a0v;        /* asm: obj->4 (s16) for the display list */
    s32 half;
    s16 t14;        /* asm: (s16)(st->4 * 1400.0f) */
    f32 dist;       /* asm: st->57C - obj->10, kept at 0x4C(sp) */
    f32 sp54;       /* asm: out value of func_4A44 */
    f32 sp58;       /* asm: 1.0f - Powerf(D864, frames) */
    f32 pw;         /* asm: Powerf() result in $f0 */
    f32 tmp;        /* asm: scratch float (st->594 / st->57C / st->4) */
    f32 vel;        /* asm: var_f0, clamped |st->4| */

    frames = (s32)arg4;

    if (arg1[0x58E] == 0 && !(*(s32 *)((u8 *)controlModeKeys + 0xC) & controlKeys)) {
        arg1[0x58E] = 1;
        arg1[0x58F] = 0x3C;
        if (arg1[0x14B] == 0) {
            *(f32 *)(arg1 + 0x594) = 0.0f;
        }
        arg1[0x590] = 0;
        arg1[0x591] = 0;
    }
    arg1[0x576] = 0;

    if (((*(u8 **)(arg1 + 0x360))[5] & arg1[0x532]) && *(s8 *)(arg1 + 0x57A) == 0) {
        if (!(*(s32 *)(arg1 + 0x520) & 0x8000) || *(s16 *)(arg1 + 0x5C8) != 0) {
            /* block A: move button pressed and no pending countdown */
            arg1[0x14A] = 0;
            arg1[0x14B] = 0;
            arg1[0x568] = arg1[0x56A];
            *(f32 *)(arg1 + 0x594) = 0.0f;
            dist = *(f32 *)(arg1 + 0x57C) - *(f32 *)(arg0 + 0x10);
            if (arg1[0x1] == 2) {
                if (dist > 240.0f) {
                    arg1[0x190] = 0x80;
                } else if (dist > 400.0f) {
                    arg1[0x190] = 0xC0;
                }
            }
            func_overlay_17_01104B84_1F2C6CC(arg0, arg1, func_overlay_17_01104A44_1F2C58C(arg1, &sp54), 0);
            arg1[0x568] = 0;
            charSpeak(arg0, 1);
            if (arg1[0x1] == 6) {
                if (dist > 0.0f) {
                    if (dist >= 200.0f) {
                        sp5C = 0x64;
                    } else {
                        sp5C = (s32)(((40.0f * dist) / 200.0f) + 60.0f);
                    }
                    amSndPlay(0xF3, arg1 + 0x5DC);
                    amSndSetVol(0xF3, *(s32 *)(arg1 + 0x5DC), sp5C & 0xFF);
                }
            }
            if (*(f32 *)(arg1 + 0x60) < 1.0f) {
                /* asm: level-dependent flag word OR'd into obj+0x84; table indexed by levelGetLevel()->unkE2 */
                *(s32 *)(arg0 + 0x84) |= D_overlay_17_0110645C[*(u8 *)((u8 *)levelGetLevel() + 0xE2)];
            }
        }
    } else {
        if (*(s8 *)(arg1 + 0x57A) > 0) {
            /* countdown running: tick it down by frames */
            *(s8 *)(arg1 + 0x57A) = (s8)(*(s8 *)(arg1 + 0x57A) - frames);
            if (*(s32 *)((u8 *)controlModeKeys + 0xC) & controlKeys) {
                arg1[0x57B] = (u8)(arg1[0x57B] + frames);
            } else {
                *(s8 *)(arg1 + 0x57A) = 0;
            }
            if (*(s8 *)(arg1 + 0x57A) <= 0) {
                if (*(f32 *)(arg0 + 0x28) < 0.25f) {
                    *(f32 *)(arg0 + 0x28) = D_overlay_17_0110685C;
                }
                *(s8 *)(arg1 + 0x57A) = 0;
                charSpeak(arg0, 0);
                if (arg1[0x569] != 0) {
                    *(f32 *)(arg0 + 0x20) = *(f32 *)(arg0 + 0x20) + 10.0f;
                } else {
                    var = arg1[0x57B];
                    if (var >= 0x19) {
                        arg1[0x57B] = 0x18;
                        var = 0x18;
                    }
                    *(f32 *)(arg0 + 0x20) = *(f32 *)(arg0 + 0x20) + (6.0f + ((6.0f * (f32)var) / 24.0f));
                }
            }
            arg2 = 0.0f;
        } else if (arg1[0x1] == 6 && arg1[0x58E] != 0 && *(s16 *)(arg1 + 0x58C) > 0) {
            /* airborne / slide state, st->58C is the remaining slide budget */
            pw = Powerf(D_overlay_17_01106860, frames);
            tmp = *(f32 *)(arg1 + 0x57C);
            sp60 = *(s16 *)(arg1 + 0x58C);
            *(f32 *)(arg1 + 0x57C) = tmp + ((*(f32 *)(arg0 + 0x10) - tmp) * (1.0f - pw));
            if ((*(s32 *)((u8 *)controlModeKeys + 0x10) & controlKeys) && sp60 > 0) {
                func_overlay_17_01104B84_1F2C6CC(arg0, arg1, 0x13, 0);
                arg1[0x14A] = 0xF;
                if (*(s16 *)(arg1 + 0x58C) > 0) {
                    *(s16 *)(arg1 + 0x58C) = (s16)(*(s16 *)(arg1 + 0x58C) - frames);
                }
                arg1[0x591] = (u8)(*(s8 *)(arg1 + 0x591) + frames * 2);
                pw = Powerf(D_overlay_17_01106864, frames);
                sp58 = 1.0f - pw;
                tmp = *(f32 *)(arg1 + 0x594);
                *(f32 *)(arg1 + 0x594) = tmp + ((((Sinf((s16)(*(s8 *)(arg1 + 0x591) << 8)) * 0.125f) + 1.0f) - tmp) * sp58);
                *(f32 *)(arg0 + 0x20) = *(f32 *)(arg0 + 0x20) * Powerf(D_overlay_17_01106868, frames);
                arg1[0x14B] = 0;
                D_overlay_17_011069B0 |= 1;
                D_overlay_17_011069B4 |= 1;
            } else if ((*(s32 *)((u8 *)controlModeKeys + 0xC) & controlKeys) && sp60 > 0) {
                func_overlay_17_01104B84_1F2C6CC(arg0, arg1, 0x13, 0);
                arg1[0x14A] = 0xF;
                if (*(s16 *)(arg1 + 0x58C) > 0) {
                    *(s16 *)(arg1 + 0x58C) = (s16)(*(s16 *)(arg1 + 0x58C) - frames * 2);
                }
                pw = Powerf(D_overlay_17_0110686C, frames);
                tmp = *(f32 *)(arg1 + 0x594);
                *(f32 *)(arg1 + 0x594) = tmp + ((1.0f - tmp) * (1.0f - pw));
                pw = Powerf(D_overlay_17_01106870, frames);
                *(f32 *)(arg0 + 0x20) = *(f32 *)(arg0 + 0x20) + ((5.0f - *(f32 *)(arg0 + 0x20)) * (1.0f - pw));
                arg1[0x14B] = 0;
                D_overlay_17_011069B0 |= 2;
                D_overlay_17_011069B4 |= 1;
            } else if (arg1[0x14B] == 0) {
                *(f32 *)(arg1 + 0x594) = *(f32 *)(arg1 + 0x594) * Powerf(D_overlay_17_01106874, frames);
                if (*(f32 *)(arg1 + 0x594) < D_overlay_17_01106878) {
                    func_overlay_17_01104B84_1F2C6CC(arg0, arg1, 0x10, 0);
                    *(f32 *)(arg1 + 0x594) = 0.0f;
                }
            }
            /* asm: sound loop over 11 slots (0x258 down by 0x3C), stops after the first hit */
            if (sp60 != *(s16 *)(arg1 + 0x58C)) {
                *(s16 *)(arg1 + 0x592) = 0x168;
            }
            v0 = 0x258;
            v1 = 0x169;
            do {
                if (v0 < sp60 && v0 >= *(s16 *)(arg1 + 0x58C)) {
                    /* asm: $a2/$a3 are not set in this function on this path */
                    amSndPlay(v1 & 0xFFFF, NULL);
                    v0 = 0;
                } else {
                    v0 -= 0x3C;
                    v1 -= 1;
                }
            } while (v0 != 0);
            if (*(s16 *)(arg1 + 0x58C) <= 0) {
                arg1[0x58E] = 0;
            }
        } else if (arg1[0x58E] != 0) {
            if (*(s32 *)((u8 *)controlModeKeys + 0xC) & controlKeys) {
                pw = Powerf(D_overlay_17_0110687C, frames);
                tmp = *(f32 *)(arg1 + 0x57C);
                *(f32 *)(arg1 + 0x57C) = tmp + ((*(f32 *)(arg0 + 0x10) - tmp) * (1.0f - pw));
                if (*(s8 *)(arg1 + 0x591) < 4) {
                    arg1[0x14A] = 0xF;
                }
                func_overlay_17_01104B84_1F2C6CC(arg0, arg1, 0x13, 0);
                arg1[0x14B] = 0;
                controlWalkingBack(arg0, arg1, &arg2, (s32)arg3, 0x5000, 0x6800, 5.0f, 3.0f);
            }
            if (arg1[0x590] != 0) {
                pw = Powerf(D_overlay_17_01106880, frames);
                *(f32 *)(arg1 + 0x594) = *(f32 *)(arg1 + 0x594) * pw;
                arg1[0x590] = (u8)(*(s8 *)(arg1 + 0x590) - frames);
                if (*(s8 *)(arg1 + 0x590) <= 0) {
                    arg1[0x590] = 0;
                    arg1[0x58F] = 0x3C;
                }
                arg1[0x58E] = 1;
            } else if ((*(s32 *)((u8 *)controlModeKeys + 0xC) & controlKeys) && *(s8 *)(arg1 + 0x591) < 4) {
                arg1[0x14A] = 0xF;
                arg1[0x58E] = 2;
                arg1[0x58F] = (u8)(*(s8 *)(arg1 + 0x58F) - frames);
                pw = Powerf(D_overlay_17_01106884, frames);
                *(f32 *)(arg0 + 0x20) = *(f32 *)(arg0 + 0x20) * pw;
                tmp = *(f32 *)(arg1 + 0x594);
                pw = Powerf(D_overlay_17_01106888, frames);
                *(f32 *)(arg1 + 0x594) = tmp + ((D_overlay_17_0110688C - tmp) * (1.0f - pw));
                if (*(s8 *)(arg1 + 0x58F) <= 0) {
                    arg1[0x590] = 0xC;
                    arg1[0x591] = (u8)(*(s8 *)(arg1 + 0x591) + 1);
                }
                D_overlay_17_011069B0 |= 1;
                D_overlay_17_011069B4 |= 1;
            } else {
                if (arg1[0x58E] == 2) {
                    arg1[0x590] = 0xC;
                    arg1[0x591] = (u8)(*(s8 *)(arg1 + 0x591) + 1);
                }
                arg1[0x58E] = 1;
                if (arg1[0x14B] == 0) {
                    *(f32 *)(arg1 + 0x594) = *(f32 *)(arg1 + 0x594) * Powerf(D_overlay_17_01106890, frames);
                    if (*(f32 *)(arg1 + 0x594) < D_overlay_17_01106894) {
                        *(f32 *)(arg1 + 0x594) = 0.0f;
                    }
                    if (*(f32 *)(arg0 + 0x10) < (*(f32 *)(arg1 + 0x57C) - 120.0f)) {
                        if (arg0[0x3B] != 0x10) {
                            func_overlay_17_01104B84_1F2C6CC(arg0, arg1, 0x10, 0);
                        }
                    }
                }
            }
        } else if (arg1[0x14B] == 0) {
            if (*(f32 *)(arg1 + 0x594) != 0.0f) {
                *(f32 *)(arg1 + 0x594) = *(f32 *)(arg1 + 0x594) * Powerf(D_overlay_17_01106898, frames);
                if (*(f32 *)(arg1 + 0x594) < D_overlay_17_0110689C) {
                    *(f32 *)(arg1 + 0x594) = 0.0f;
                }
            }
            if (*(f32 *)(arg0 + 0x10) < (*(f32 *)(arg1 + 0x57C) - 120.0f)) {
                if (arg0[0x3B] != 0x10) {
                    func_overlay_17_01104B84_1F2C6CC(arg0, arg1, 0x10, 0);
                }
            }
        }
    }

    controlWalkingBack(arg0, arg1, &arg2, (s32)arg3, 0x5000, 0x6800, 5.0f, 3.0f);
    func_overlay_17_01102848_1F2A390(arg0, arg1, arg4);
    if (arg1[0x569] == 0) {
        arg2 = -arg2;
    } else {
        arg3 = (s16)(arg3 + 0x8000);
    }
    sp68 = *(s16 *)(arg1 + 0x11C);
    tmp = *(f32 *)(arg1 + 0x4);
    pw = Powerf(D_overlay_17_011068A0, frames);
    *(f32 *)(arg1 + 0x4) = ((1.0f - pw) * (arg2 - tmp)) + tmp;
    pw = Powerf(D_overlay_17_011068A4, frames);
    *(s16 *)(arg1 + 0x11C) = dAngle(*(s16 *)(arg1 + 0x11C), arg3, 1.0f - pw);
    iv = (s32)*(f32 *)(arg1 + 0x4);
    vel = (f32)iv;
    if (vel < 0.0f) {
        vel = (f32)(-iv);
    }
    if (vel > 3.0f) {
        vel = 3.0f;
    }
    delta = *(s16 *)(arg1 + 0x11C) - sp68;
    *(s16 *)(arg1 + 0x120) = (s16)(s32)((f32)delta * vel * D_overlay_17_011068A8 * 3.0f);
    if (arg1[0x14A] != 0) {
        /* display list: 16 halfwords, cursor kept in D_overlay_17_011069C4 */
        a0v = *(s16 *)(arg0 + 0x4);
        half = a0v >> 1;
        t14 = (s16)(s32)(*(f32 *)(arg1 + 0x4) * 1400.0f);
        *(s16 *)D_overlay_17_011069C4 = 0x22;
        D_overlay_17_011069C4 += 2;
        *(s16 *)D_overlay_17_011069C4 = (s16)(a0v + half);
        D_overlay_17_011069C4 += 2;
        *(s16 *)D_overlay_17_011069C4 = 0x10;
        D_overlay_17_011069C4 += 2;
        *(s16 *)D_overlay_17_011069C4 = (s16)(a0v + half);
        D_overlay_17_011069C4 += 2;
        *(s16 *)D_overlay_17_011069C4 = 0x82;
        D_overlay_17_011069C4 += 2;
        *(s16 *)D_overlay_17_011069C4 = (s16)(a0v + half);
        D_overlay_17_011069C4 += 2;
        *(s16 *)D_overlay_17_011069C4 = 0x94;
        D_overlay_17_011069C4 += 2;
        *(s16 *)D_overlay_17_011069C4 = (s16)(a0v + half);
        D_overlay_17_011069C4 += 2;
        *(s16 *)D_overlay_17_011069C4 = 0x1E;
        D_overlay_17_011069C4 += 2;
        *(s16 *)D_overlay_17_011069C4 = t14;
        D_overlay_17_011069C4 += 2;
        *(s16 *)D_overlay_17_011069C4 = 0xC;
        D_overlay_17_011069C4 += 2;
        *(s16 *)D_overlay_17_011069C4 = t14;
        D_overlay_17_011069C4 += 2;
        *(s16 *)D_overlay_17_011069C4 = 0x7E;
        D_overlay_17_011069C4 += 2;
        *(s16 *)D_overlay_17_011069C4 = t14;
        D_overlay_17_011069C4 += 2;
        *(s16 *)D_overlay_17_011069C4 = 0x90;
        D_overlay_17_011069C4 += 2;
        *(s16 *)D_overlay_17_011069C4 = t14;
        D_overlay_17_011069C4 += 2;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o17/overlay_17/func_overlay_17_01103258_1F2ADA0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_17_01104178_1F2BCC0(void *arg0, s16 arg1, s16 arg2, s16 arg3) {
    u8 *st = (u8 *)arg0;
    u8 *cur = D_overlay_17_011069C4;

    if (*(u8 *)(st + 0x1) == 6) {
        *(s16 *)cur = 0x36;
        cur += 2;
        *(s16 *)cur = arg2;
        cur += 2;
        *(s16 *)cur = 0x38;
        cur += 2;
        *(s16 *)cur = arg3;
        cur += 2;
    } else {
        *(s16 *)cur = 0x5A;
        cur += 2;
        *(s16 *)cur = arg2;
        cur += 2;
        *(s16 *)cur = 0x5C;
        cur += 2;
        *(s16 *)cur = arg3;
        cur += 2;
    }
    D_overlay_17_011069C4 = cur;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o17/overlay_17/func_overlay_17_01104178_1F2BCC0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_17_01104270_1F2BDB8(s16 arg0, s16 arg1) {
    s16 val = arg0;
    u8 *cur = D_overlay_17_011069C4;

    if (val >= 0x2AAB) {
        val = 0x2AAA;
    } else if (val < -0x2AAA) {
        val = -0x2AAA;
    }
    *(s16 *)cur = 0x30;
    cur += 2;
    *(s16 *)cur = val;
    cur += 2;
    *(s16 *)cur = 0x32;
    cur += 2;
    *(s16 *)cur = arg1;
    cur += 2;
    D_overlay_17_011069C4 = cur;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o17/overlay_17/func_overlay_17_01104270_1F2BDB8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_17_0110430C_1F2BE54(void *arg0, void *arg1, s32 arg2, s32 arg3, f32 arg4) {
    u8 *obj = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    s32 sp3C;
    f32 temp_f2;
    f32 damp;
    s16 aimA;
    s16 aimB;
    s16 yaw;
    s16 pitch;
    s32 sway;

    *(u8 *)(st + 0x576) = 0;
    *(u8 *)(st + 0x13E) = 0;
    if (!(controlKeys & 0x10) && D_overlay_17_011069C0 == 0) {
        *(u8 *)(st + 0x568) = 0;
        *(s16 *)(st + 0x11C) = (s16)(*(s16 *)(st + 0x11C) - 0x18E3);
        *(s16 *)(obj + 0x0) = (s16)(*(s16 *)(obj + 0x0) - 0x18E3);
        *(s16 *)(st + 0x1CE) = (s16)(*(s16 *)(st + 0x1CE) + 0x18E3);
        *(s16 *)(st + 0x104) = (s16)(0x8000 - *(s16 *)(obj + 0x0));
        return;
    }

    func_overlay_17_01102848_1F2A390(obj, st, arg4);
    sp3C = (s32)arg4;
    *(f32 *)(st + 0x4) = *(f32 *)(st + 0x4) * Powerf(D_overlay_17_011068AC, sp3C);
    temp_f2 = *(f32 *)(st + 0x4);
    if (D_overlay_17_011068B0 < temp_f2 && temp_f2 < D_overlay_17_011068B4) {
        *(f32 *)(st + 0x4) = 0.0f;
    }
    if (D_overlay_17_011069C0 == 0) {
        controlGetManualAim(obj, st, 0xE38, 0xE38, -0x2AAA, 0x2AAA, &aimA, &aimB, arg4);
        aimA = (s16)(aimA - 0x18E3);
    } else {
        aimA = *(s16 *)(st + 0x1DC);
        aimB = (s16)(*(s16 *)(st + 0x1DE) - *(s16 *)(st + 0x1E2));
    }
    damp = 1.0f - Powerf(D_overlay_17_011068B8, sp3C);
    *(s16 *)(st + 0x1E0) = dAngle(*(s16 *)(st + 0x1E0), aimB, damp);
    aimB = (s16)(aimB + *(s16 *)(st + 0x1E2));
    *(s16 *)(st + 0x1DC) = dAngle(*(s16 *)(st + 0x1DC), aimA, damp);
    *(s16 *)(st + 0x1DE) = dAngle(*(s16 *)(st + 0x1DE), aimB, damp);
    *(s16 *)(st + 0x1CE) = dAngle(*(s16 *)(st + 0x1CE), aimA, damp);
    *(s16 *)(st + 0x1D0) = dAngle(*(s16 *)(st + 0x1D0), aimB, damp);
    yaw = *(s16 *)(st + 0x1CE);
    *(s16 *)(st + 0x1C6) = (s16)(yaw + *(s16 *)(obj + 0x0));
    *(s16 *)(st + 0x1C8) = (s16)(*(s16 *)(st + 0x1D0) + *(s16 *)(obj + 0x2));
    *(s16 *)(st + 0x1CA) = *(s16 *)(st + 0x1C6);
    *(s16 *)(st + 0x1CC) = *(s16 *)(st + 0x1C8);
    aimA = yaw;
    pitch = *(s16 *)(st + 0x1D0);
    sway = 0;
    if (*(s8 *)(st + 0x1F6) != 0) {
        sway = ((s32)(*(s8 *)(st + 0x1F7) * mathSin((s16)(*(s8 *)(st + 0x1F6) << 0xC), *(s8 *)(st + 0x1F6)))) >> 8;
    }
    func_overlay_17_01104270_1F2BDB8(*(s16 *)(st + 0x1DE), *(s16 *)(st + 0x1DC));
    func_overlay_17_01104178_1F2BCC0(st, (s16)(-*(s16 *)(obj + 0x4)), (s16)(pitch + sway), aimA);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o17/overlay_17/func_overlay_17_0110430C_1F2BE54.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_17_01104614_1F2C15C(void *arg0, void *arg1, s32 arg2, s32 arg3, f32 arg4) {
    u8 *obj = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    u8 *mk = (u8 *)controlModeKeys;
    u8 *target;
    s16 aimA;
    s16 aimB;
    s16 yaw;
    s16 pitch;
    s32 sp40;
    s32 sway;
    f32 step;
    f32 damp;
    f32 temp_f2;

    target = (u8 *)mainGetGameCharacter(*(s8 *)(st + 0x0), *(s8 *)(st + 0x1));
    *(u8 *)(st + 0x576) = 0;
    *(u8 *)(st + 0x13E) = 0;
    if (!(controlKeys & 0x10) && D_overlay_17_011069C0 == 0) {
        *(u8 *)(st + 0x568) = 0;
        *(s16 *)(st + 0x104) = (s16)(0x8000 - *(s16 *)(obj + 0x0));
        return;
    }

    func_overlay_17_01102848_1F2A390(obj, st, arg4);
    sp40 = (s32)arg4;
    if (frontGetTargetControl(*(s8 *)(st + 0x0)) != 0 && target[0x70] != 7 &&
        ((*(s32 *)(mk + 0x20) | *(s32 *)(mk + 0x1C)) & controlKeys) != 0) {
        if (*(u8 *)(st + 0x199) != 0) {
            step = D_overlay_17_011068BC * arg4;
        } else {
            step = D_overlay_17_011068C0 * arg4;
        }
        if (*(s32 *)(mk + 0x1C) & controlKeys) {
            *(f32 *)(st + 0x4) = *(f32 *)(st + 0x4) - step;
            if (*(f32 *)(st + 0x4) < -4.0625f) {
                *(f32 *)(st + 0x4) = -4.0625f;
            }
        } else {
            *(f32 *)(st + 0x4) = *(f32 *)(st + 0x4) + step;
            if (*(f32 *)(st + 0x4) > 3.0f) {
                *(f32 *)(st + 0x4) = 3.0f;
            }
        }
    } else {
        *(f32 *)(st + 0x4) = *(f32 *)(st + 0x4) * Powerf(D_overlay_17_011068C4, sp40);
        temp_f2 = *(f32 *)(st + 0x4);
        if (D_overlay_17_011068C8 < temp_f2 && temp_f2 < D_overlay_17_011068CC) {
            *(f32 *)(st + 0x4) = 0.0f;
        }
    }
    if (D_overlay_17_011069C0 == 0) {
        if (controlGetManualAim(obj, st, 0xE38, 0xE38, -0x2AAA, 0x2AAA, &aimA, &aimB, arg4) != 0) {
            camSetZoom(*(s8 *)(st + 0x0), *(s32 *)(st + 0x1EC));
        }
    } else {
        aimA = *(s16 *)(st + 0x1DC);
        aimB = (s16)(*(s16 *)(st + 0x1DE) - *(s16 *)(st + 0x1E2));
    }
    damp = 1.0f - Powerf(D_overlay_17_011068D0, sp40);
    *(s16 *)(st + 0x1E0) = dAngle(*(s16 *)(st + 0x1E0), aimB, damp);
    aimB = (s16)(aimB + *(s16 *)(st + 0x1E2));
    *(s16 *)(st + 0x1DC) = dAngle(*(s16 *)(st + 0x1DC), aimA, damp);
    *(s16 *)(st + 0x1DE) = dAngle(*(s16 *)(st + 0x1DE), aimB, damp);
    *(s16 *)(st + 0x1CE) = dAngle(*(s16 *)(st + 0x1CE), aimA, damp);
    *(s16 *)(st + 0x1D0) = dAngle(*(s16 *)(st + 0x1D0), aimB, damp);
    yaw = *(s16 *)(st + 0x1CE);
    *(s16 *)(st + 0x1C6) = (s16)(yaw + *(s16 *)(obj + 0x0));
    *(s16 *)(st + 0x1CA) = *(s16 *)(st + 0x1C6);
    *(s16 *)(st + 0x1C8) = (s16)(*(s16 *)(st + 0x1D0) + *(s16 *)(obj + 0x2));
    *(s16 *)(st + 0x1CC) = *(s16 *)(st + 0x1C8);
    aimA = yaw;
    pitch = *(s16 *)(st + 0x1D0);
    sway = 0;
    if (*(s8 *)(st + 0x1F6) != 0) {
        sway = ((s32)(*(s8 *)(st + 0x1F7) * mathSin((s16)(*(s8 *)(st + 0x1F6) << 0xC), *(s8 *)(st + 0x1F6)))) >> 8;
    }
    func_overlay_17_01104270_1F2BDB8(*(s16 *)(st + 0x1DE), *(s16 *)(st + 0x1DC));
    func_overlay_17_01104178_1F2BCC0(st, (s16)(-*(s16 *)(obj + 0x4)), (s16)(pitch + sway), aimA);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o17/overlay_17/func_overlay_17_01104614_1F2C15C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_17_01104A44_1F2C58C(void *arg0, f32 *arg1) {
    u8 *st = (u8 *)arg0;
    f32 var_f0;
    f32 var_f12;
    f32 var_f2;
    s32 var_v1;

    var_f0 = *(f32 *)(st + 0x4);
    if (var_f0 < 0.0f) {
        var_f0 = -var_f0;
    }
    var_f2 = *(f32 *)(st + 0x10);
    if (var_f2 < 0.0f) {
        var_f2 = -var_f2;
    }
    var_f12 = var_f0;
    if (var_f0 < var_f2) {
        var_f12 = var_f2;
    }
    if (var_f12 < D_overlay_17_011068D4) {
        if (*(u8 *)(st + 0x1FA) != 0) {
            var_v1 = 9;
        } else if (*(u8 *)(st + 0x1F9) != 0) {
            var_v1 = 9;
        } else if (*(u8 *)(st + 0x198) != 0) {
            var_v1 = 9;
        } else {
            var_v1 = mathRnd(9, 0xD);
        }
        *arg1 = 0.0f;
    } else if (*(u8 *)(st + 0x569) != 0) {
        var_v1 = 3;
    } else if (var_f12 > 3.5f) {
        var_v1 = 2;
    } else {
        var_v1 = 0;
        if (var_f12 > 2.0f) {
            var_v1 = 1;
        }
    }
    return var_v1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o17/overlay_17/func_overlay_17_01104A44_1F2C58C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_17_01104B84_1F2C6CC(void *arg0, void *arg1, s32 arg2, s32 arg3) {
    u8 *obj = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    u8 var_a3;

    if (*(u8 *)(st + 0x1F4) != 0) {
        var_a3 = D_overlay_17_011062C9[arg2 * 5];
    } else if (controlPlayerGunWeight(arg1, arg2) != 0) {
        var_a3 = D_overlay_17_011062CA[arg2 * 5];
    } else {
        var_a3 = D_overlay_17_011062C8[arg2 * 5];
    }
    if (var_a3 != *(s8 *)(obj + 0x3B)) {
        objAnimSetMove(arg0, var_a3, arg3, var_a3);
        D_overlay_17_011069B8 += 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o17/overlay_17/func_overlay_17_01104B84_1F2C6CC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_17_01104C50_1F2C798(void *arg0, void *arg1, s32 arg2, f32 arg3) {
    u8 *obj = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    f32 sp30;
    f32 sp2C;
    f32 sp28;
    s32 sp24;
    f32 temp_f0;
    f32 var_f0;
    f32 var_f12;
    f32 var_f2;
    s8 temp_v1;
    s8 var_v0;

    var_f0 = *(f32 *)(st + 0x4);
    if (var_f0 < 0.0f) {
        var_f0 = -var_f0;
    }
    var_f2 = *(f32 *)(st + 0x10);
    if (var_f2 < 0.0f) {
        var_f2 = -var_f2;
    }
    var_f12 = var_f0;
    if (var_f0 < var_f2) {
        var_f12 = var_f2;
    }
    sp24 = (s32)*(s8 *)(obj + 0x3B);
    sp2C = *(f32 *)(obj + 0x28);
    temp_f0 = *(f32 *)(obj + 0x28);
    sp28 = temp_f0;
    temp_v1 = *(s8 *)(st + 0x1);
    var_v0 = *(s8 *)(obj + 0x3B);
    if (temp_v1 == 6) {
        sp30 = D_overlay_17_011063BC[var_v0];
    } else {
        sp30 = D_overlay_17_0110635C[var_v0];
    }
    switch (var_v0) {
    case 0:
    case 1:
    case 2:
    case 3:
        sp30 *= var_f12;
        sp24 = func_overlay_17_01104A44_1F2C58C(st, &sp2C);
        break;
    case 6:
        if (temp_v1 == 6) {
            if (temp_f0 == 1.0f) {
                if ((D_overlay_17_01106948 < var_f12) || (D_overlay_17_01106948 < *(f32 *)(obj + 0x20))) {
                    sp24 = 0x14;
                } else {
                    sp24 = 0x15;
                }
            }
        }
        break;
    case 7:
        if (D_overlay_17_011069BC != 0) {
            sp24 = func_overlay_17_01104A44_1F2C58C(st, &sp2C);
            sp2C = 0.0f;
        }
        break;
    case 8:
        if (*(s8 *)(st + 0x576) == 0) {
            sp24 = 0;
            sp2C = 0.0f;
        }
        break;
    case 9:
    case 10:
    case 11:
    case 12:
    case 13:
    case 18:
        if (D_overlay_17_0110694C < var_f12) {
            sp24 = func_overlay_17_01104A44_1F2C58C(st, &sp2C);
            sp2C = 0.25f;
        } else if ((temp_f0 + (sp30 * arg3)) > 1.0f) {
            if (*(u8 *)(st + 0x1FA) != 0) {
                *(s8 *)(obj + 0x3B) = -1;
                sp24 = 9;
            } else if (*(u8 *)(st + 0x1F9) != 0) {
                *(s8 *)(obj + 0x3B) = -1;
                sp24 = 9;
            } else if (*(u8 *)(st + 0x198) != 0) {
                *(s8 *)(obj + 0x3B) = -1;
                sp24 = 9;
            } else {
                sp24 = mathRnd(9, 0xD);
            }
            sp2C = 0.0f;
        }
        break;
    case 14:
        if (D_overlay_17_01106950 < temp_f0) {
            sp24 = 0;
            sp2C = 0.25f;
        }
        break;
    case 21:
        if ((D_overlay_17_01106954 < var_f12) || (D_overlay_17_01106954 < *(f32 *)(obj + 0x20))) {
            sp24 = 0x14;
        }
        break;
    case 20:
        sp30 *= var_f12;
        if (var_f12 < D_overlay_17_01106958) {
            if (*(f32 *)(obj + 0x20) < D_overlay_17_01106958) {
                sp24 = 0x15;
            }
        }
        break;
    case 22:
        if (*(u8 *)(st + 0x19F) == 0) {
            if (*(u8 *)(st + 0x10D) == 0) {
                sp24 = func_overlay_17_01104A44_1F2C58C(st, &sp2C);
                sp2C = 0.0f;
            }
        }
        break;
    case 25:
    case 26:
        if (D_overlay_17_0110695C < var_f2) {
            if (var_f2 < D_overlay_17_01106960) {
                sp24 = func_overlay_17_01104A44_1F2C58C(st, &sp2C);
            }
        }
        break;
    case 27:
        if (D_overlay_17_01106964 < temp_f0) {
            sp24 = 0x15;
            sp2C = 0.25f;
        }
        break;
    default:
        break;
    }
    objAnimDframe(arg0, sp30, arg3);
    charAnimSoundTick(arg0, sp28, sp30);
    func_overlay_17_01101C44_1F2978C(arg0, arg1, sp28, sp30);
    func_overlay_17_01104B84_1F2C6CC(arg0, arg1, sp24, *(s32 *)&sp2C);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o17/overlay_17/func_overlay_17_01104C50_1F2C798.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_17_011050BC_1F2CC04(void *arg0, void *arg1, f32 arg2) {
    u8 *obj = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    f32 sp5C;
    f32 sp58;
    f32 sp40;
    f32 sp3C;
    s32 sp34;
    s16 rot[3];
    f32 vec[3];
    f32 sp4C;
    s16 var_a2;
    s16 var_a0;
    s16 var_a2_2;
    s16 var_a2_3;
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
    f32 var_f12;
    f32 var_f14;
    s32 temp_v0;
    s8 temp_v0_2;

    if (*(u8 *)(st + 0x568) == 5) {
        *(s16 *)(st + 0x11C) = (s16)(*(s16 *)(st + 0x11C) - 0x18E3);
    }
    *(f32 *)(obj + 0x20) = *(f32 *)(obj + 0x20) - ((1.0f - *(f32 *)(st + 0x594)) * (controlchr_gravity * arg2));
    *(f32 *)(st + 0x8) = 0.0f;
    *(f32 *)(st + 0x74) = *(f32 *)(obj + 0x20);
    *(s16 *)obj = *(s16 *)(st + 0x11C);
    if (*(u8 *)(st + 0x568) == 4) {
        var_a2 = *(s16 *)(st + 0x128);
    } else if (*(u8 *)(st + 0x13E) != 0) {
        var_a2 = *(s16 *)(st + 0x13C);
    } else {
        var_a2 = *(s16 *)(st + 0x11C);
    }
    rot[0] = var_a2;
    sp3C = Sinf(var_a2);
    temp_f0 = Cosf((s32)rot[0]);
    *(f32 *)(obj + 0x1C) = *(f32 *)(st + 0x4) * sp3C;
    *(f32 *)(obj + 0x24) = *(f32 *)(st + 0x4) * temp_f0;
    var_a2_2 = *(s16 *)(st + 0x11C);
    var_a0 = var_a2_2;
    if (*(u8 *)(st + 0x13E) != 0) {
        var_a2_2 = *(s16 *)(st + 0x13C);
        var_a0 = var_a2_2;
    }
    rot[0] = var_a2_2;
    *(f32 *)(obj + 0x1C) = *(f32 *)(obj + 0x1C) + (*(f32 *)(st + 0x10) * Cosf((s32)var_a0));
    var_f12 = *(f32 *)(obj + 0x1C);
    *(f32 *)(obj + 0x24) = *(f32 *)(obj + 0x24) - (*(f32 *)(st + 0x10) * Sinf(rot[0]));
    var_f14 = *(f32 *)(obj + 0x24);
    if (*(u8 *)(st + 0x149) != 0) {
        var_f12 += *(f32 *)(st + 0x6C);
        var_f14 += *(f32 *)(st + 0x70);
    }
    if (disablejoy == 1) {
        var_f12 *= D_overlay_17_01106968;
        temp_f0_2 = *(f32 *)(st + 0x4);
        var_f14 *= D_overlay_17_01106968;
        if ((temp_f0_2 < -0.5f) || (temp_f0_2 > 0.5f)) {
            *(f32 *)(st + 0x4) = temp_f0_2 * D_overlay_17_01106968;
        } else {
            *(f32 *)(st + 0x4) = 0.0f;
        }
        temp_f0_3 = *(f32 *)(st + 0x8);
        if ((temp_f0_3 < -0.5f) || (temp_f0_3 > 0.5f)) {
            *(f32 *)(st + 0x8) = temp_f0_3 * D_overlay_17_01106968;
        } else {
            *(f32 *)(st + 0x8) = 0.0f;
        }
    }
    if (*(u8 *)(st + 0x10D) != 0) {
        sidekickpadMovePlayer(var_f12, var_f14, arg0, arg1, (s32)arg2);
    }
    if (*(u8 *)(st + 0x19F) != 0) {
        transformerMovePlayer(var_f12, var_f14, arg0, arg1, (s32)arg2);
    }
    objMoveXYZ(var_f12, var_f14, arg0, (var_f12 * arg2) + *(f32 *)(st + 0x354), *(f32 *)(obj + 0x20) * arg2, (var_f14 * arg2) + *(f32 *)(st + 0x35C));
    temp_f2 = 1.0f / arg2;
    temp_f12 = (*(f32 *)(obj + 0xC) - *(f32 *)(st + 0x3C)) * temp_f2;
    sp40 = temp_f2;
    temp_f14 = (*(f32 *)(obj + 0x14) - *(f32 *)(st + 0x44)) * temp_f2;
    sp5C = temp_f12;
    sp58 = temp_f14;
    temp_v0 = controlGroundHits(temp_f12, temp_f14, arg0, arg1, arg2);
    *(f32 *)(obj + 0x1C) = (*(f32 *)(obj + 0xC) - *(f32 *)(st + 0x3C)) * temp_f2;
    *(f32 *)(obj + 0x20) = (*(f32 *)(obj + 0x10) - *(f32 *)(st + 0x40)) * temp_f2;
    *(f32 *)(obj + 0x24) = (*(f32 *)(obj + 0x14) - *(f32 *)(st + 0x44)) * temp_f2;
    if ((*(u8 *)(st + 0x534) != 0 && *(f32 *)(obj + 0x20) > 0.0f) ||
        (*(u8 *)(st + 0x510) != 0 && *(u8 *)(st + 0x532) != 0)) {
        *(f32 *)(obj + 0x20) = 0.0f;
    }
    if (*(u8 *)(st + 0x13E) != 0) {
        var_a2_3 = *(s16 *)(st + 0x13C);
    } else {
        var_a2_3 = *(s16 *)(st + 0x11C);
    }
    rot[0] = (s16)(-var_a2_3);
    rot[1] = (s16)(-*(s16 *)(obj + 0x2));
    sp34 = temp_v0;
    rot[2] = (s16)(-*(s16 *)(obj + 0x4));
    sp4C = temp_f14;
    vec[1] = 0.0f;
    vec[0] = temp_f12;
    mathOneFloatYPR(temp_f12, temp_f14, rot, vec, var_a2_3);
    temp_v0_2 = *(s8 *)(st + 0x149);
    if (temp_v0_2 != 0) {
        *(s8 *)(st + 0x149) = (s8)(temp_v0_2 - (s32)arg2);
        if (*(s8 *)(st + 0x149) < 0) {
            *(s8 *)(st + 0x149) = 0;
        }
    } else {
        temp_f0_4 = *(f32 *)(st + 0x4);
        temp_f2_2 = temp_f0_4 - sp4C;
        if (temp_f2_2 > 0.5f) {
            *(f32 *)(st + 0x4) = temp_f0_4 - (temp_f2_2 - 0.5f);
        }
        if (temp_f2_2 < -0.5f) {
            *(f32 *)(st + 0x4) = *(f32 *)(st + 0x4) - (temp_f2_2 + 0.5f);
        }
        temp_f0_5 = *(f32 *)(st + 0x8);
        temp_f2_3 = temp_f0_5 - vec[0];
        if (temp_f2_3 > 0.5f) {
            *(f32 *)(st + 0x8) = temp_f0_5 - (temp_f2_3 - 0.5f);
        }
        if (temp_f2_3 < -0.5f) {
            *(f32 *)(st + 0x8) = *(f32 *)(st + 0x8) - (temp_f2_3 + 0.5f);
        }
    }
    if (sp34 != 0) {
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
        *(u8 *)(st + 0x199) = 1;
    } else {
        *(u8 *)(st + 0x199) = 0;
    }
    if (*(u8 *)(st + 0x568) == 5) {
        *(s16 *)(st + 0x11C) = (s16)(*(s16 *)(st + 0x11C) + 0x18E3);
        *(s16 *)obj = (s16)(*(s16 *)obj + 0x18E3);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o17/overlay_17/func_overlay_17_011050BC_1F2CC04.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_17_011056D4_1F2D21C(void *arg0, void *arg1, s32 arg2) {
    u8 *obj = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    f32 var_f0;
    f32 var_f0_2;
    s16 temp_v0;
    s16 temp_v0_3;
    s16 temp_v1;
    s16 temp_v1_2;
    s16 var_a1;
    s16 var_a1_2;
    s16 var_s1;
    s16 var_s1_2;
    s16 var_s1_3;
    s32 i;
    s8 temp_v0_2;
    s8 temp_v0_4;

    var_s1 = *(s16 *)(st + 0x1C8) - *(s16 *)(obj + 0x2);
    if (var_s1 < -0x1800) {
        var_s1 = -0x1800;
    }
    if (var_s1 >= 0x3001) {
        var_s1 = 0x3000;
    }
    var_a1 = *(s16 *)(st + 0x1C6) - *(s16 *)obj;
    if (var_a1 < -0x1000) {
        var_a1 = -0x1000;
    }
    if (var_a1 >= 0x1001) {
        var_a1 = 0x1000;
    }
    for (i = 0; i < arg2; i++) {
        temp_v0 = *(s16 *)(st + 0x1D0);
        temp_v1 = *(s16 *)(st + 0x1CE);
        *(s16 *)(st + 0x1D0) = (s16)(temp_v0 + ((s32)(var_s1 - temp_v0) >> 2));
        *(s16 *)(st + 0x1CE) = (s16)(temp_v1 + ((s32)(var_a1 - temp_v1) >> 2));
    }
    temp_v0_2 = *(s8 *)(st + 0x1F5);
    var_s1_2 = 0;
    var_a1_2 = 0;
    if (temp_v0_2 > 0) {
        var_s1_2 = *(s16 *)(st + 0x1DA);
        var_a1_2 = *(s16 *)(st + 0x1D8);
        *(s8 *)(st + 0x1F5) = (s8)(temp_v0_2 - arg2);
    }
    var_f0 = (f32)var_s1_2;
    if (var_f0 < D_overlay_17_0110696C) {
        var_s1_2 = -0x38E3;
        var_f0 = (f32)-0x38E3;
    }
    var_f0_2 = (f32)var_a1_2;
    if (D_overlay_17_01106970 < var_f0) {
        var_s1_2 = 0x38E3;
    }
    if (var_f0_2 < D_overlay_17_01106974) {
        var_a1_2 = -0xE38;
        var_f0_2 = (f32)-0xE38;
    }
    if (D_overlay_17_01106978 < var_f0_2) {
        var_a1_2 = 0xE38;
    }
    for (i = 0; i < arg2; i++) {
        temp_v0_3 = *(s16 *)(st + 0x1DE);
        temp_v1_2 = *(s16 *)(st + 0x1DC);
        *(s16 *)(st + 0x1DE) = (s16)(temp_v0_3 + ((s32)(var_s1_2 - temp_v0_3) >> 4));
        *(s16 *)(st + 0x1DC) = (s16)(temp_v1_2 + ((s32)(var_a1_2 - temp_v1_2) >> 4));
    }
    if (*(u8 *)(st + 0x1F4) != 0) {
        temp_v0_4 = *(s8 *)(st + 0x1F6);
        var_s1_3 = *(s16 *)(st + 0x1D0);
        if (temp_v0_4 != 0) {
            var_s1_3 += (s32)(*(u8 *)(st + 0x1F7) * mathSin((s16)(temp_v0_4 << 0xC), var_a1_2)) >> 8;
        }
        func_overlay_17_01104270_1F2BDB8(*(s16 *)(st + 0x1DE), *(s16 *)(st + 0x1DC));
        func_overlay_17_01104178_1F2BCC0(st, (s16)(*(s16 *)(obj + 0x4) * -1), var_s1_3, *(s16 *)(st + 0x1CE));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o17/overlay_17/func_overlay_17_011056D4_1F2D21C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_17_01105930_1F2D478(void *arg0, void *arg1, f32 arg2, s16 arg3, f32 arg4) {
    u8 *obj = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    s32 sp64;
    s16 sp5A;
    f32 sp48;
    f32 sp44;
    f32 *sp40;
    f32 *sp3C;
    f32 temp_f0;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 temp_f12;
    f32 temp_f14;
    f32 temp_f14_2;
    f32 var_f0;
    f32 var_f2;
    f32 var_f2_2;
    f32 var_f2_3;
    f32 var_f6;
    s16 temp_a0;
    s32 temp_f6;
    s32 var_v1;
    s32 var_v1_2;
    s32 var_v1_3;

    if (*(u8 *)(st + 0x1) == 6) {
        var_f0 = 8.0f;
        var_f6 = D_overlay_17_01106980;
        sp40 = D_overlay_17_01106778;
        sp3C = D_overlay_17_01106798;
        arg2 *= D_overlay_17_01106984;
        sp48 = D_overlay_17_0110697C;
    } else {
        *(u8 *)(st + 0x541) = (u8)(*(u8 *)(st + 0x541) & 0xFFF0);
        var_f0 = 24.0f;
        var_f6 = D_overlay_17_0110698C;
        sp40 = D_overlay_17_01106738;
        sp3C = D_overlay_17_01106758;
        sp48 = D_overlay_17_01106988;
    }
    sp44 = var_f6;
    if ((*(u8 *)(st + 0x2) == 0) ||
        ((*(f32 *)(st + 0x60) < var_f0) &&
         (((*(u8 **)(st + 0x360))[5] & *(u8 *)(st + 0x532)) || (*(f32 *)(obj + 0x20) > 5.0f)))) {
        *(s8 *)(st + 0x57A) = 0;
        *(u8 *)(st + 0x568) = 3;
        *(u8 *)(st + 0x58E) = 0;
        *(f32 *)(st + 0x57C) = *(f32 *)(obj + 0x10);
        *(f32 *)(st + 0x594) = 0.0f;
    }
    controlWalkingBack(arg0, arg1, &arg2, arg3, 0x5000, 0x6800, 5.0f, 3.0f);
    func_overlay_17_01102848_1F2A390(arg0, arg1, arg4);
    if (*(s32 *)((u8 *)controlModeKeys + 0xC) & controlDkeys) {
        *(s8 *)(st + 0x57A) = 0;
        *(f32 *)(st + 0x57C) = *(f32 *)(obj + 0x10);
        *(f32 *)(obj + 0x20) = *(f32 *)(obj + 0x20) + 12.0f;
        if (*(f32 *)(obj + 0x20) > 12.0f) {
            *(f32 *)(obj + 0x20) = 12.0f;
        }
        if (*(u8 *)(st + 0x1) == 6) {
            func_overlay_17_01104B84_1F2C6CC(arg0, arg1, 0x18, 0);
        } else {
            func_overlay_17_01104B84_1F2C6CC(arg0, arg1, 5, 0);
        }
        charSpeak(arg0, 0);
        temp_f6 = (s32)arg4;
    } else {
        temp_f6 = (s32)arg4;
        *(f32 *)(obj + 0x20) = Powerf(D_overlay_17_01106990, temp_f6) * *(f32 *)(obj + 0x20);
    }
    if (*(u8 *)(st + 0x569) == 0) {
        arg2 = -arg2;
    } else {
        arg3 += 0x8000;
    }
    if (*(u8 *)(st + 0x568) == 4) {
        *(u8 *)(st + 0x19E) = 1;
        temp_f0 = *(f32 *)(st + 0x60) * sp48;
        *(f32 *)(st + 0x594) = temp_f0;
        if (temp_f0 > 1.5f) {
            *(f32 *)(st + 0x594) = 1.5f;
        }
    }
    var_f2 = *(f32 *)(st + 0x4);
    if (var_f2 < 0.0f) {
        var_f2 = -var_f2;
    }
    var_v1 = (s32)var_f2;
    if (var_v1 >= 7) {
        var_v1 = 6;
    }
    temp_f0_2 = sp40[var_v1];
    sp5A = *(s16 *)(st + 0x11C);
    temp_f14 = ((sp40[var_v1 + 1] - temp_f0_2) * (var_f2 - (f32)var_v1)) + temp_f0_2;
    *(s16 *)(st + 0x11C) = dAngle(*(s16 *)(st + 0x11C), arg3, 1.0f - Powerf(1.0f - temp_f14, temp_f6));
    temp_f12 = *(f32 *)(st + 0x4);
    *(f32 *)(st + 0x4) = ((1.0f - Powerf(1.0f - sp44, temp_f6)) * (arg2 - temp_f12)) + temp_f12;
    var_f2_2 = *(f32 *)(st + 0x4);
    if (var_f2_2 < 0.0f) {
        var_f2_2 = -var_f2_2;
    }
    var_v1_2 = (s32)var_f2_2;
    if (var_v1_2 >= 7) {
        var_v1_2 = 6;
    }
    temp_f0_3 = sp3C[var_v1_2];
    temp_f14_2 = temp_f0_3 + ((var_f2_2 - (f32)var_v1_2) * (sp3C[var_v1_2 + 1] - temp_f0_3));
    var_f2_3 = *(f32 *)(st + 0x4);
    temp_a0 = *(s16 *)(st + 0x11C) - sp5A;
    *(s16 *)(st + 0x128) = dAngle(*(s16 *)(st + 0x128), *(s16 *)(st + 0x11C), 1.0f - Powerf(1.0f - temp_f14_2, temp_f6));
    if (var_f2_3 < 0.0f) {
        var_f2_3 = -var_f2_3;
    }
    var_v1_3 = (s32)((f32)temp_a0 * 1.5f * var_f2_3);
    if (var_v1_3 < -0x1000) {
        var_v1_3 = -0x1000;
    }
    if (var_v1_3 >= 0x1001) {
        var_v1_3 = 0x1000;
    }
    sp64 = var_v1_3;
    *(s16 *)(st + 0x12C) = dAngle(*(s16 *)(st + 0x12C), (s16)var_v1_3, 1.0f - Powerf(D_overlay_17_01106994, temp_f6));
    *(s16 *)D_overlay_17_011069C4 = 4;
    D_overlay_17_011069C4 += 2;
    *(s16 *)D_overlay_17_011069C4 = *(s16 *)(st + 0x12C);
    D_overlay_17_011069C4 += 2;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o17/overlay_17/func_overlay_17_01105930_1F2D478.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_17_01105F08_1F2DA50(void *arg0, void *arg1, s32 arg2, s32 arg3, f32 arg4) {
    u8 *obj = (u8 *)arg0;
    u8 *st = (u8 *)arg1;
    u8 setup[0x14];
    f32 temp_f0;
    f32 temp_f2;
    f32 temp_f2_2;
    s8 temp_v0_2;
    u8 temp_v0;
    u8 *tbl;
    u8 *tmp;
    u8 *hdr;
    u8 *ents;
    u8 *ent;

    if (numberOfPlayers == 1) {
        mainPauseDisable(0xA);
    }
    *(s16 *)(*(u8 **)(obj + 0x4C) + 0x6) = 0;
    temp_f0 = Powerf(D_overlay_17_01106998, (s32)arg4);
    *(f32 *)(st + 0x4) = *(f32 *)(st + 0x4) * temp_f0;
    temp_f2 = *(f32 *)(st + 0x4);
    if ((D_overlay_17_0110699C < temp_f2) && (temp_f2 < D_overlay_17_011069A0)) {
        *(f32 *)(st + 0x4) = 0.0f;
    }
    *(f32 *)(st + 0x10) = *(f32 *)(st + 0x10) * temp_f0;
    temp_f2_2 = *(f32 *)(st + 0x10);
    if ((D_overlay_17_0110699C < temp_f2_2) && (temp_f2_2 < D_overlay_17_011069A4)) {
        *(f32 *)(st + 0x10) = 0.0f;
    }
    *(u8 *)(st + 0x541) = (u8)(*(u8 *)(st + 0x541) & 0xFFF0);
    if (*(s16 *)(st + 0x2) == 0) {
        *(f32 *)(st + 0x594) = *(f32 *)(st + 0x594) * temp_f0;
    } else {
        *(f32 *)(st + 0x594) = 0.875f;
        *(f32 *)(obj + 0x20) = *(f32 *)(obj + 0x20) * Powerf(D_overlay_17_011069A8, (s32)arg4);
        temp_v0 = *(u8 *)(st + 0x18A);
        if ((s32)temp_v0 < 0xF0) {
            *(u8 *)(st + 0x18A) = (u8)(temp_v0 + 1);
        }
        temp_v0_2 = *(s8 *)(st + 0x18B);
        if ((s32)arg4 >= temp_v0_2) {
            tbl = *(u8 **)(obj + 0x6C);
            tmp = *(u8 **)(tbl + *(u8 *)(obj + 0x3A) * 4);
            hdr = *(u8 **)tmp;
            ents = *(u8 **)(tmp + 0x70);
            ent = ents + mathRnd(0, *(u8 *)(hdr + 0x2F) - 1) * 0xC;
            if (*(f32 *)(ent + 0x4) < *(f32 *)(st + 0x5C)) {
                *(s16 *)setup = 0xBA;
                setup[0x2] = 0x14;
                setup[0x3] = 0;
                *(s16 *)(setup + 0x4) = (s16)(s32)*(f32 *)(ent + 0x0);
                *(s16 *)(setup + 0x6) = (s16)(s32)*(f32 *)(ent + 0x4);
                *(s16 *)(setup + 0x8) = (s16)(s32)*(f32 *)(ent + 0x8);
                *(s16 *)(setup + 0xA) = (s16)mathRnd(-0x8000, 0x7FFF);
                *(f32 *)(setup + 0xC) = (f32)mathRnd(0, 0x23) * D_overlay_17_011069AC;
                *(f32 *)(setup + 0x10) = *(f32 *)(st + 0x5C);
                {
                    u8 *spawned = (u8 *)objSetupObject(setup, 1);
                    if (spawned != NULL) {
                        *(s32 *)(spawned + 0x3C) = 0;
                    }
                }
            }
            *(s8 *)(st + 0x18B) = (s8)((s32)*(u8 *)(st + 0x18A) >> 2);
        } else {
            *(s8 *)(st + 0x18B) = (s8)(temp_v0_2 - (s32)arg4);
        }
    }
    *(u8 *)(st + 0x19C) = 0;
    if (*(f32 *)(obj + 0x28) == 1.0f) {
        controlFrozen(arg0, arg1);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o17/overlay_17/func_overlay_17_01105F08_1F2DA50.s")
#endif
