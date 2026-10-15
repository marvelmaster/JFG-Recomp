#include "common.h"

/* decomp: externs */
/* Raw-offset accessors for the overlay object/player structs (no full struct yet). */
#define OV53_F32(p, o) (*(f32 *)((u8 *)(p) + (o)))
#define OV53_S32(p, o) (*(s32 *)((u8 *)(p) + (o)))
#define OV53_S16(p, o) (*(s16 *)((u8 *)(p) + (o)))
#define OV53_U8(p, o)  (*(u8 *)((u8 *)(p) + (o)))
#define OV53_S8(p, o)  (*(s8 *)((u8 *)(p) + (o)))
#define OV53_PTR(p, o) (*(void **)((u8 *)(p) + (o)))

/* display-list cursor: D_overlay_53_03503820 is a byte pointer, advanced 2 bytes per s16 word */
#define OV53_CMD(v) (*(s16 *)((u8 *)D_overlay_53_03503820 + 2) = (s16)(v), \
                     D_overlay_53_03503820 = (u8 *)D_overlay_53_03503820 + 2)
#define OV53_CMD_FIRST(v) (*(s16 *)D_overlay_53_03503820 = (s16)(v), \
                           D_overlay_53_03503820 = (u8 *)D_overlay_53_03503820 + 2)

extern f32 D_overlay_53_03503710;
extern f32 D_overlay_53_03503714;
extern f32 D_overlay_53_03503718;
extern f32 D_overlay_53_0350371C;
extern f32 D_overlay_53_03503720;
extern f32 D_overlay_53_03503724;
extern f32 D_overlay_53_03503758;
extern f32 D_overlay_53_0350375C;
extern f32 D_overlay_53_03503760;
extern f32 D_overlay_53_03503764;
extern f32 D_overlay_53_03503768;
extern f32 D_overlay_53_0350376C;
extern f32 D_overlay_53_03503770;
extern f32 D_overlay_53_03503774;
extern f32 D_overlay_53_03503778;
extern f32 D_overlay_53_0350377C;
extern f32 D_overlay_53_03503780;
extern f32 D_overlay_53_03503784;
extern f32 D_overlay_53_03503788;
extern f32 D_overlay_53_0350378C;
extern f32 D_overlay_53_03503790;
extern f32 D_overlay_53_03503794;
extern f32 D_overlay_53_03503798;
extern f32 D_overlay_53_0350379C;
extern f32 D_overlay_53_035037A0;
extern f32 D_overlay_53_035037A4;
extern f32 D_overlay_53_035037A8;
extern f32 D_overlay_53_035037AC;
extern f32 D_overlay_53_035037B0;
extern f32 D_overlay_53_035037B4;
extern f32 D_overlay_53_035037B8;
extern f32 D_overlay_53_035037BC;
extern f32 D_overlay_53_035037C0;
extern f32 D_overlay_53_035037C4;
extern f32 D_overlay_53_035037C8;
extern f32 D_overlay_53_035037CC;
extern f32 D_overlay_53_035037D0;
extern f32 D_overlay_53_035037D4;
extern f32 D_overlay_53_035037D8;
extern f32 D_overlay_53_035037DC;
extern f32 D_overlay_53_035037E0;
extern f32 D_overlay_53_035037E4;
extern f32 D_overlay_53_035037E8;
extern f32 D_overlay_53_035037EC;
extern f32 D_overlay_53_035037F0;
extern f32 D_overlay_53_035037F4;
extern f32 D_overlay_53_035037F8;
extern f32 D_overlay_53_035037FC;
extern f32 D_overlay_53_03503800;
extern f32 D_overlay_53_03503804;
extern f32 D_overlay_53_03503808;
extern f32 D_overlay_53_0350380C;
extern f32 D_overlay_53_03503810;
extern f32 D_overlay_53_03503828[];
extern f32 D_overlay_53_03503838[];
extern f32 D_overlay_53_03503848[];
extern void *D_overlay_53_03503820;
extern s16 D_overlay_53_03503824;
extern s16 D_overlay_53_03503826;
extern void *controlcam;
extern s32 *controlModeKeys;
extern u8 multiGameType;
extern u8 multiPlayerGame;
extern s8 raceGameSingleScreen;
extern u8 racingInGame;

/* functions not declared in include/ (signatures taken from call sites) */
f32 Powerf(f32 base, s32 n);
s16 dAngle(s16 a, s16 b, f32 c);
f32 Sinf(s16 angle);
s32 sprintAIJoypad(s8 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4);
s32 sprintAIPlayer(f32 arg0, f32 arg1, s8 arg2);
s32 sprintPlayerBoost(s8 arg0, void *arg1);
void sprintPlayerFire(void *arg0, s8 arg1);
void controlReadJoypad(s8 arg0);
void controlMakeGravity(void *arg0);
void controlFSUvels(f32 arg0, f32 arg1, void *arg2, void *arg3);
void controlFadePlayer(void *arg0, s32 arg1, s32 arg2);
void controlPlatform(void *arg0, void *arg1, f32 arg2);
void controlUpdateJetFlames(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4);
void controlUpdatePlayerAim(void *arg0, void *arg1, f32 arg2, f32 arg3, f32 arg4, f32 arg5, f32 arg6, s32 arg7);
void controlDisableJoypad(s32 arg0);
s32 controlGroundHits(void *arg0, void *arg1, f32 arg2);
void amSndPlay(s32 arg0, void *arg1);
void amSndPlayXYZ(s32 arg0, f32 arg1, f32 arg2, f32 arg3, s32 arg4, void *arg5);
void amSndSetPitchDirect(void *arg0, f32 arg1);
void amSndSetPitchXYZ(void *arg0, s32 arg1);
void invincibilityShieldTransform(s32 arg0, f32 arg1, f32 arg2, s32 arg3);
void frontFlashScreen(s32 arg0, s8 arg1, u32 arg2);
void charSpeak(s32 arg0, s16 arg1);
void wakeUpdateRipple(void *arg0, s32 arg1);
void camSetFOV(f32 arg0, s32 arg1);
s32 trackGetHeights(f32 arg0, f32 arg1, s32 arg2, s32 *arg3);
s32 trackNearestIntersection(s32 arg0, f32 *arg1, f32 *arg2, void **arg3, s32 arg4, s32 arg5);
s32 trackPolyHeight(f32 arg0, f32 arg1, f32 *arg2, s32 arg3);
void objAnimDframe(void *arg0, f32 arg1, f32 arg2);
s32 objAnimSetMove(void *arg0, s8 arg1, f32 arg2);
void modGenAnimMatrices(f32 arg0, f32 arg1, void *arg2, s32 arg3, void *arg4, f32 arg5, f32 arg6);
void lightObject(void *arg0, void *arg1, s32 arg2, s32 arg3);
void partUpdateTriggers(void *arg0, s32 arg1);
s32 mathSin(s16 angle);

/* overlay-internal functions (defined below) */
void hovershipControl(void *arg0, s32 arg1);
void hovershipCamera(void *arg0, void *arg1, f32 arg2);
void func_overlay_53_03500EA0_1F724D0(void *arg0, void *arg1, f32 arg2, s16 arg3, f32 arg4);
void func_overlay_53_035014F4_1F72B24(void *arg0, void *arg1, f32 arg2, s16 arg3, f32 arg4);
void func_overlay_53_03501850_1F72E80(void *arg0, void *arg1, f32 arg2, s16 arg3, f32 arg4);
f32 func_overlay_53_035019B0_1F72FE0(s16 *arg0, void *arg1, f32 arg2, s16 arg3);
void func_overlay_53_03501BB4_1F731E4(void *arg0, void *arg1, f32 arg2);
void func_overlay_53_035021E4_1F73814(void *arg0, void *arg1, s32 arg2);
void func_overlay_53_0350230C_1F7393C(void *arg0, void *arg1, s32 arg2);
void func_overlay_53_035023D0_1F73A00(void *arg0, void *arg1, s32 arg2);
void func_overlay_53_03502708_1F73D38(s32 arg0, void *arg1, void *arg2, s8 arg3);
void func_overlay_53_0350271C_1F73D4C(void *arg0, void *arg1, f32 arg2, f32 arg3);
void func_overlay_53_035028CC_1F73EFC(void *arg0, void *arg1, s32 arg2);
s32 func_overlay_53_035028DC_1F73F0C(void *arg0, f32 *arg1, s32 arg2);

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hovershipInit(s32 arg0) {
    D_overlay_53_03503828[arg0] = D_overlay_53_03503710;
    D_overlay_53_03503838[arg0] = 0.0f;
    D_overlay_53_03503848[arg0] = 0.0f;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o53/overlay_53/hovershipInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hovershipControl(void *arg0, s32 arg1) {
    void *player;
    s32 aiActive;
    s32 keepAlive;
    s32 state;
    s32 i;
    f32 stickMag;
    f32 speedScale;
    f32 blend;
    f32 turnSpeed;
    f32 pitchVec[3];
    s16 angleRot[3];
    s16 aimAngle;
    s32 nTemp;
    void *anim;
    f32 f0;
    f32 savedY;
    f32 newY;

    player = OV53_PTR(arg0, 0x68);
    OV53_S32(arg0, 0x84) = 0;
    D_overlay_53_03503820 = (u8 *)player + 0x240;

    if (OV53_U8(player, 0x568) != 3) {
        OV53_U8(player, 0x56A) = 0;
    }
    if (OV53_S8(player, 0x149) > 0) {
        controlDisableJoypad(2);
    }
    keepAlive = OV53_U8(player, 0x1FA) < 2;
    if (OV53_U8(player, 0x10D) != 0 || OV53_U8(player, 0x1F9) != 0 ||
        OV53_U8(player, 0x1FA) != 0 || OV53_U8(player, 0x198) != 0 ||
        OV53_U8(player, 0x188) != 0) {
        controlDisableJoypad(1);
        keepAlive = OV53_U8(player, 0x1FA) < 2;
    }
    if (!keepAlive) {
        OV53_U8(player, 0x1FA) = 0;
    }
    if (OV53_S8(player, 0x198) >= 2) {
        OV53_U8(player, 0x198) = 0;
    }
    controlReadJoypad(OV53_S8(player, 0x0));
    controlMakeGravity(player);

    /* clamp object and player attitude */
    if (OV53_F32(arg0, 0x1C) < -25.0f) OV53_F32(arg0, 0x1C) = -25.0f;
    if (OV53_F32(arg0, 0x1C) > 25.0f) OV53_F32(arg0, 0x1C) = 25.0f;
    if (OV53_F32(arg0, 0x20) < -20.0f) OV53_F32(arg0, 0x20) = -20.0f;
    if (OV53_F32(arg0, 0x20) > 10.0f) OV53_F32(arg0, 0x20) = 10.0f;
    if (OV53_F32(arg0, 0x24) < -25.0f) OV53_F32(arg0, 0x24) = -25.0f;
    if (OV53_F32(arg0, 0x24) > 25.0f) OV53_F32(arg0, 0x24) = 25.0f;
    if (OV53_F32(player, 0x4) < -25.0f) OV53_F32(player, 0x4) = -25.0f;
    if (OV53_F32(player, 0x4) > 25.0f) OV53_F32(player, 0x4) = 25.0f;
    if (OV53_F32(player, 0x8) < -25.0f) OV53_F32(player, 0x8) = -25.0f;
    if (OV53_F32(player, 0x8) > 25.0f) OV53_F32(player, 0x8) = 25.0f;

    controlFSUvels(25.0f, 10.0f, arg0, player);

    angleRot[0] = (s16)-OV53_S16(player, 0x11C);
    angleRot[1] = (s16)-OV53_S16(arg0, 0x2);
    angleRot[2] = (s16)-OV53_S16(arg0, 0x4);
    pitchVec[0] = 0.0f;
    pitchVec[1] = -1.0f;
    pitchVec[2] = 0.0f;
    mathOneFloatYPR(angleRot, pitchVec);
    OV53_F32(player, 0x54) = pitchVec[0];
    OV53_F32(player, 0x58) = pitchVec[1];
    OV53_F32(player, 0x50) = pitchVec[2];

    D_overlay_53_03503824 = 0;
    D_overlay_53_03503826 = 0;

    aiActive = 0;
    if (((multiPlayerGame != 0) && (multiGameType == 4)) || (racingInGame != 0)) {
        aiActive = sprintAIJoypad(OV53_S8(player, 0x0), &controlXjoy, &controlYjoy,
                                  &controlKeys, &controlDkeys);
    }

    stickMag = sqrtf((f32)((controlXjoy * controlXjoy) + (controlYjoy * controlYjoy)));
    if (stickMag > 65.0f) {
        stickMag = 65.0f;
    }
    if (stickMag != 0.0f) {
        aimAngle = (s16)(Arctanf((f32)controlXjoy, (f32)-controlYjoy) - *(s16 *)controlcam);
    } else {
        aimAngle = OV53_S16(player, 0x11C);
    }
    if ((aiActive != 0) && (stickMag != 0.0f)) {
        aimAngle += *(s16 *)controlcam;
    }

    OV53_S16(player, 0x58C) = (s16)(OV53_S16(player, 0x58C) - arg1);
    if (OV53_S16(player, 0x58C) >= 0x12D) {
        OV53_U8(player, 0x14A) = 3;
        if (stickMag < 60.0f) {
            stickMag = 60.0f;
        }
        if (((multiPlayerGame != 0) || (racingInGame != 0)) && (raceGameSingleScreen == 0)) {
            speedScale = D_overlay_53_03503714;
        } else {
            speedScale = D_overlay_53_03503718;
        }
        if (((multiPlayerGame == 0) && (racingInGame == 0)) ||
            (sprintAIPlayer(0.0f, speedScale, OV53_S8(player, 0x0)) == 0)) {
            rumbleMax((s32)OV53_S8(player, 0x0), 0x28, 0.2f);
        }
        blend = 0.0f;
    } else {
        OV53_U8(player, 0x14A) = 0;
        if (((multiPlayerGame != 0) || (racingInGame != 0)) && (raceGameSingleScreen == 0)) {
            speedScale = D_overlay_53_0350371C;
        } else {
            speedScale = D_overlay_53_03503720;
        }
        blend = D_overlay_53_03503724;
    }

    /* smooth the per-player speed scale toward speedScale */
    {
        s32 idx = OV53_S8(player, 0x0);
        f32 cur = D_overlay_53_03503828[idx];
        D_overlay_53_03503828[idx] =
            cur + ((speedScale - cur) *
                   (1.0f - ((f32 (*)(f32, f32, s32))Powerf)(blend, speedScale, arg1)));
    }

    if (OV53_S16(player, 0x58C) < 0) {
        OV53_S16(player, 0x58C) = 0;
    }
    stickMag *= D_overlay_53_03503828[OV53_S8(player, 0x0)];

    state = OV53_U8(player, 0x568);
    if (((state == 0) || (state == 5) || (state == 0xB)) &&
        !(OV53_U8(OV53_PTR(player, 0x360), 0x5) & OV53_S32(player, 0x532)) &&
        (OV53_U8(player, 0x188) == 0)) {
        OV53_U8(player, 0x185) = (u8)(OV53_U8(player, 0x185) + arg1);
        if (OV53_U8(player, 0x185) >= 0x10) {
            OV53_U8(player, 0x56A) = (u8)state;
            OV53_U8(player, 0x568) = 3;
            OV53_F32(player, 0x57C) = OV53_F32(arg0, 0x10);
        }
    } else {
        OV53_U8(player, 0x185) = 0;
    }
    if (OV53_U8(OV53_PTR(player, 0x360), 0x5) & OV53_S32(player, 0x532)) {
        OV53_F32(player, 0x57C) = OV53_F32(arg0, 0x10);
    }

    state = OV53_U8(player, 0x568);
    if ((state != 5) && (state != 0xB)) {
        controlUpdatePlayerAim(arg0, player, 1000.0f, 10.0f, 60.0f, 15.0f, 65.0f, arg1);
    } else {
        OV53_U8(player, 0x1F4) = 1;
    }
    if (OV53_U8(player, 0x568) != 0xA) {
        controlFadePlayer(player, 0, arg1);
    }

    /* ground clearance */
    if ((trackPolyHeight(OV53_F32(arg0, 0xC), OV53_F32(arg0, 0x14),
                         (f32 *)((u8 *)player + 0x5C), 0x2000) & 0x2000) &&
        (OV53_F32(player, 0x5C) < (OV53_F32(arg0, 0x10) - 16.0f))) {
        OV53_F32(player, 0x60) = (OV53_F32(arg0, 0x10) - 16.0f) - OV53_F32(player, 0x5C);
    } else {
        OV53_F32(player, 0x60) = 0.0f;
    }
    if (OV53_S16(OV53_PTR(arg0, 0x4C), 0x6) < 0x100) {
        OV53_S16(OV53_PTR(arg0, 0x4C), 0x6) = 0x100;
    }

    stickMag = func_overlay_53_035019B0_1F72FE0(arg0, player, stickMag, aimAngle);
    turnSpeed = (f32)arg1;

    state = OV53_S8(player, 0x568);
    switch (state) {
    case 0:
    case 3:
        func_overlay_53_03500EA0_1F724D0(arg0, player, stickMag, aimAngle, turnSpeed);
        break;
    case 5:
    case 11:
        func_overlay_53_035014F4_1F72B24(arg0, player, stickMag, aimAngle, turnSpeed);
        break;
    case 10:
        func_overlay_53_03501850_1F72E80(arg0, player, stickMag, aimAngle, turnSpeed);
        break;
    }
    func_overlay_53_0350271C_1F73D4C(arg0, player, stickMag, turnSpeed);
    controlPlatform(arg0, player, turnSpeed);
    func_overlay_53_03501BB4_1F731E4(arg0, player, turnSpeed);

    /* engine sound pitch */
    if (raceGameSingleScreen != 0) {
        if (OV53_PTR(player, 0xCC) == NULL) {
            amSndPlay(0x18E, (u8 *)player + 0xCC);
        }
        if (OV53_PTR(player, 0xCC) != NULL) {
            f0 = D_overlay_53_03503758 - (OV53_F32(player, 0x4) * D_overlay_53_0350375C);
            if (f0 < D_overlay_53_03503758) {
                f0 = D_overlay_53_03503758;
            }
            if (D_overlay_53_03503760 < f0) {
                f0 = D_overlay_53_03503760;
            }
            amSndSetPitchDirect(OV53_PTR(player, 0xCC), f0);
        }
    } else {
        if (OV53_PTR(player, 0xBC) == NULL) {
            amSndPlayXYZ(0x18E, OV53_F32(arg0, 0xC), OV53_F32(arg0, 0x10), OV53_F32(arg0, 0x14),
                         1, (u8 *)player + 0xBC);
        }
        if (OV53_PTR(player, 0xBC) != NULL) {
            f0 = D_overlay_53_03503764 - (OV53_F32(player, 0x4) * D_overlay_53_03503768);
            if (f0 < D_overlay_53_03503764) {
                f0 = D_overlay_53_03503764;
            }
            if (D_overlay_53_0350376C < f0) {
                f0 = D_overlay_53_0350376C;
            }
            amSndSetXYZ(OV53_PTR(player, 0xBC), OV53_F32(arg0, 0xC), OV53_F32(arg0, 0x10),
                        OV53_F32(arg0, 0x14));
            amSndSetPitchXYZ(OV53_PTR(player, 0xBC), (s32)(f0 * 100.0f) & 0xFF);
        }
    }

    state = OV53_U8(player, 0x568);
    if ((state != 5) && (state != 0xB)) {
        func_overlay_53_035023D0_1F73A00(arg0, player, arg1);
    }
    nTemp = OV53_S32(player, 0x5BC);
    if (nTemp != 0) {
        invincibilityShieldTransform(nTemp, 1.75f, 0.5f, 0x28);
    }
    func_overlay_53_035021E4_1F73814(arg0, player, arg1);

    blend = 1.0f - Powerf(D_overlay_53_03503770, (s32)arg1);
    turnSpeed = blend;
    OV53_S16(player, 0x11E) = dAngle(OV53_S16(player, 0x11E), D_overlay_53_03503824, blend);
    OV53_S16(player, 0x120) = dAngle(OV53_S16(player, 0x120), D_overlay_53_03503826, turnSpeed);

    /* emit display-list commands for the hovership model */
    OV53_CMD_FIRST(0x22);
    OV53_CMD(-(OV53_S16(player, 0x120) >> 1));
    OV53_CMD(0x1E);
    OV53_CMD(OV53_S16(player, 0x11E) * 2);
    OV53_CMD(0x10);
    OV53_CMD((s16)(OV53_F32(player, 0x14) * D_overlay_53_03503774));
    OV53_CMD(0xA);
    OV53_CMD((s16)(OV53_F32(player, 0x14) * D_overlay_53_03503778));
    OV53_CMD(0x1000);

    anim = ((void **)OV53_PTR(arg0, 0x6C))[OV53_U8(arg0, 0x3A)];
    if ((anim != NULL) && (OV53_S16(anim, 0xA) != 0)) {
        s32 animIdx = OV53_S32(anim, 0x0);
        savedY = OV53_F32(arg0, 0x10);
        newY = OV53_F32(player, 0x14) * 16.0f;
        OV53_F32(arg0, 0x10) = newY;
        if (OV53_F32(arg0, 0x10) > 20.0f) {
            OV53_F32(arg0, 0x10) = 20.0f;
        }
        OV53_F32(arg0, 0x10) = OV53_F32(arg0, 0x10) + savedY;
        OV53_S16(arg0, 0x2) = (s16)(OV53_S16(arg0, 0x2) + OV53_S16(player, 0x11E));
        OV53_S16(arg0, 0x4) = (s16)(OV53_S16(arg0, 0x4) + OV53_S16(player, 0x120));
        modGenAnimMatrices(savedY, 20.0f, anim, animIdx, arg0, OV53_F32(player, 0x48), 0.0f);
        OV53_U8(player, 0x540) = (u8)(OV53_U8(player, 0x540) & 0xFB);
        lightObject(arg0, anim, OV53_S32(arg0, 0x54),
                    OV53_S32((u8 *)anim + OV53_U8(anim, 0xB) * 4, 0x10));
        func_overlay_53_03502708_1F73D38(animIdx, anim, player, OV53_S16(anim, 0xA));
        OV53_S16(anim, 0xA) = 0;
        OV53_F32(arg0, 0x10) = savedY;
        OV53_S16(arg0, 0x2) = (s16)(OV53_S16(arg0, 0x2) - OV53_S16(player, 0x11E));
        OV53_S16(arg0, 0x4) = (s16)(OV53_S16(arg0, 0x4) - OV53_S16(player, 0x120));
    }

    if (((multiPlayerGame != 0) && (multiGameType == 4)) || (racingInGame != 0)) {
        if (*controlModeKeys & controlDkeys) {
            sprintPlayerFire(arg0, OV53_S8(player, 0x0));
        }
    } else {
        func_overlay_53_035028CC_1F73EFC(arg0, player, arg1);
    }
    controlUpdateJetFlames(arg0, player, 0, 3, arg1);
    func_overlay_53_0350230C_1F7393C(arg0, player, arg1);

    if (OV53_S8(player, 0x14B) > 0) {
        OV53_S8(player, 0x14B) = (s8)(OV53_S8(player, 0x14B) - arg1);
        OV53_S32(arg0, 0x84) = OV53_S32(arg0, 0x84) | 0x80;
    }
    partUpdateTriggers(arg0, arg1);

    if (OV53_PTR(player, 0x5E0) != NULL) {
        amSndSetXYZ(OV53_PTR(player, 0x5E0), OV53_F32(arg0, 0xC), OV53_F32(arg0, 0x10), OV53_F32(arg0, 0x14));
    }
    if (OV53_PTR(player, 0x5E4) != NULL) {
        amSndSetXYZ(OV53_PTR(player, 0x5E4), OV53_F32(arg0, 0xC), OV53_F32(arg0, 0x10), OV53_F32(arg0, 0x14));
    }
    if (OV53_PTR(player, 0x5E8) != NULL) {
        amSndSetXYZ(OV53_PTR(player, 0x5E8), OV53_F32(arg0, 0xC), OV53_F32(arg0, 0x10), OV53_F32(arg0, 0x14));
    }
    (void)i;
    (void)f0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o53/overlay_53/hovershipControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_53_03500EA0_1F724D0(void *arg0, void *arg1, f32 arg2, s16 arg3, f32 arg4) {
    s32 frames;
    f32 blend;
    f32 yawBlend;
    f32 dampScale;
    f32 sideTrim;
    f32 yawDelta;
    f32 var0;
    f32 tmp12;
    s16 angleDelta;
    u8 zone;
    s16 step;

    OV53_F32(arg1, 0x594) = D_overlay_53_0350377C;

    if (((multiPlayerGame == 0) || (multiGameType != 4)) && (racingInGame == 0) && (controlKeys & 0x10)) {
        OV53_S16(arg1, 0x1E2) = 0;
        OV53_S16(arg1, 0x1E0) = 0;
        OV53_U8(arg1, 0x568) = 0xB;
        OV53_S16(arg1, 0x1CE) = 0;
        OV53_S16(arg1, 0x1D0) = 0;
        OV53_F32(arg1, 0x1E4) = 0.0f;
        OV53_F32(arg1, 0x1E8) = 0.0f;
        OV53_S16(arg1, 0x1C6) = OV53_S16(arg0, 0x0);
        OV53_S16(arg1, 0x1C8) = OV53_S16(arg0, 0x2);
        OV53_S16(arg1, 0x1DC) = OV53_S16(arg1, 0x1CE);
        OV53_S16(arg1, 0x1CA) = OV53_S16(arg1, 0x1C6);
        OV53_S16(arg1, 0x1CC) = OV53_S16(arg1, 0x1C8);
        OV53_S16(arg1, 0x1DE) = OV53_S16(arg1, 0x1D0);
        return;
    }

    if (controlDkeys & 0x8000) {
        if (((multiPlayerGame != 0) && (multiGameType == 4)) || (racingInGame != 0)) {
            if (sprintPlayerBoost(OV53_S8(arg1, 0x0), arg0) != 0) {
                OV53_S16(arg1, 0x58C) = 0x1A4;
                if (raceGameSingleScreen != 0) {
                    amSndPlay(0x18F, 0);
                } else {
                    amSndPlayXYZ(0x18F, OV53_F32(arg0, 0xC), OV53_F32(arg0, 0x10),
                                 OV53_F32(arg0, 0x14), 4, 0);
                }
            }
        } else if (OV53_S16(arg1, 0x58C) == 0) {
            OV53_S16(arg1, 0x58C) = 0x1A4;
            amSndPlay(0x18F, 0);
        }
    }
    if (((multiPlayerGame == 0) || (multiGameType != 4)) && (racingInGame == 0) &&
        (*controlModeKeys & controlKeys)) {
        OV53_U8(arg1, 0x1F4) = 0xF;
    }

    zone = OV53_U8(arg1, 0x13E);
    if (zone >= 2) {
        arg3 = OV53_S16(arg1, 0x13C);
    }
    arg2 = -arg2;
    frames = (s32)arg4;

    if ((zone >= 2) && (OV53_S8(arg1, 0x576) != 0)) {
        step = (s16)(frames * 0x88C);
        if (OV53_U8(arg1, 0x13F) < 8) {
            OV53_S16(arg1, 0x11C) = (s16)(OV53_S16(arg1, 0x11C) - step);
        } else {
            OV53_S16(arg1, 0x11C) = (s16)(OV53_S16(arg1, 0x11C) + step);
        }
        OV53_S8(arg1, 0x576) = (s8)(OV53_S8(arg1, 0x576) - frames);
        if (OV53_S8(arg1, 0x576) < 0) {
            OV53_S8(arg1, 0x576) = 0;
        }
    } else {
        blend = (zone != 0) ? D_overlay_53_03503780 : D_overlay_53_03503784;
        /* sig mismatch: dAngle takes (rate, cur, target, rate) at this call site */
        angleDelta = ((s16 (*)(f32, s16, s16, f32))dAngle)(blend, OV53_S16(arg1, 0x11C), arg3,
                                                           1.0f - blend) -
                     OV53_S16(arg1, 0x11C);
        if (OV53_U8(arg1, 0x13E) == 0) {
            if (angleDelta < -0x280) {
                if (OV53_U8(arg1, 0x13F) > 0) {
                    OV53_U8(arg1, 0x13F) = (u8)(OV53_U8(arg1, 0x13F) - 1);
                }
            } else if (angleDelta >= 0x281) {
                if (OV53_U8(arg1, 0x13F) < 0x10) {
                    OV53_U8(arg1, 0x13F) = (u8)(OV53_U8(arg1, 0x13F) + 1);
                }
            } else {
                OV53_U8(arg1, 0x13F) = 8;
            }
        }
        tmp12 = 1.0f - Powerf(blend, frames);
        OV53_S16(arg1, 0x11C) = ((s16 (*)(f32, s16, s16, f32))dAngle)(tmp12, OV53_S16(arg1, 0x11C), arg3, tmp12);
    }

    if (arg2 > 0.0f) {
        dampScale = 0.0f;
    } else {
        dampScale = 1.0f - Powerf((arg2 * D_overlay_53_03503788) + D_overlay_53_0350378C, frames);
    }
    OV53_S16(arg1, 0x128) = ((s16 (*)(f32, s16, s16, f32))dAngle)(dampScale, OV53_S16(arg1, 0x128),
                                                                  OV53_S16(arg1, 0x11C), dampScale);

    yawDelta = arg2 * Cosf((s32)(s16)(OV53_S16(arg1, 0x11C) - OV53_S16(arg1, 0x128)));
    var0 = yawDelta;
    if (yawDelta > 0.0f) {
        var0 = 0.0f;
    }
    if (controlKeys & 0x4000) {
        yawBlend = D_overlay_53_03503790;
        var0 = 0.0f;
    } else if (var0 < OV53_F32(arg1, 0x4)) {
        yawBlend = D_overlay_53_03503794;
    } else {
        yawBlend = D_overlay_53_03503798;
    }
    sideTrim = (OV53_F32(arg1, 0x4) - var0) * (1.0f - yawBlend);
    OV53_F32(arg1, 0x4) = OV53_F32(arg1, 0x4) +
                          ((var0 - OV53_F32(arg1, 0x4)) * (1.0f - Powerf(yawBlend, frames)));
    if ((D_overlay_53_0350379C < OV53_F32(arg1, 0x4)) && (D_overlay_53_0350379C < var0)) {
        OV53_F32(arg1, 0x4) = 0.0f;
    }

    D_overlay_53_03503824 = (s16)(s32)(sideTrim * 8192.0f);
    if (D_overlay_53_03503824 < -0xC00) {
        D_overlay_53_03503824 = -0xC00;
    }
    if (D_overlay_53_03503824 >= 0xE01) {
        D_overlay_53_03503824 = 0xE00;
    }
    D_overlay_53_03503826 = (s16)(s32)((f32)angleDelta * 6.0f);
    if (D_overlay_53_03503826 < -0x1100) {
        D_overlay_53_03503826 = -0x1100;
    }
    if (D_overlay_53_03503826 >= 0x1101) {
        D_overlay_53_03503826 = 0x1100;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o53/overlay_53/func_overlay_53_03500EA0_1F724D0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_53_035014F4_1F72B24(void *arg0, void *arg1, f32 arg2, s16 arg3, f32 arg4) {
    s16 aimYaw;
    s16 aimPitch;
    s32 frames;
    f32 aimBlend;
    s8 bob;

    (void)arg2;
    (void)arg3;
    if (!(controlKeys & 0x10)) {
        OV53_U8(arg1, 0x568) = 0;
        OV53_S16(arg1, 0x104) = (s16)(0x8000 - OV53_S16(arg0, 0x0));
        return;
    }
    frames = (s32)arg4;
    OV53_F32(arg1, 0x4) = OV53_F32(arg1, 0x4) * Powerf(D_overlay_53_035037A0, frames);
    if ((D_overlay_53_035037A4 < OV53_F32(arg1, 0x4)) && (OV53_F32(arg1, 0x4) < D_overlay_53_035037A8)) {
        OV53_F32(arg1, 0x4) = 0.0f;
    }
    controlGetManualAim(arg0, arg1, 0xE38, 0xE38, -0x2AAA, 0x2AAA, &aimYaw, &aimPitch, arg4);
    aimBlend = 1.0f - Powerf(D_overlay_53_035037AC, frames);
    OV53_S16(arg1, 0x1E0) = dAngle(OV53_S16(arg1, 0x1E0), aimPitch, aimBlend);
    aimPitch += OV53_S16(arg1, 0x1E2);
    OV53_S16(arg1, 0x1DC) = dAngle(OV53_S16(arg1, 0x1DC), aimYaw, aimBlend);
    OV53_S16(arg1, 0x1DE) = dAngle(OV53_S16(arg1, 0x1DE), aimPitch, aimBlend);
    OV53_S16(arg1, 0x1CE) = dAngle(OV53_S16(arg1, 0x1CE), aimYaw, aimBlend);
    OV53_S16(arg1, 0x1D0) = dAngle(OV53_S16(arg1, 0x1D0), aimPitch, aimBlend);

    OV53_S16(arg1, 0x1C6) = (s16)(OV53_S16(arg1, 0x1CE) + OV53_S16(arg0, 0x0));
    OV53_S16(arg1, 0x1CA) = OV53_S16(arg1, 0x1C6);
    OV53_S16(arg1, 0x1C8) = (s16)(OV53_S16(arg1, 0x1D0) + OV53_S16(arg0, 0x2));
    OV53_S16(arg1, 0x1CC) = OV53_S16(arg1, 0x1C8);
    aimYaw = OV53_S16(arg1, 0x1CE);
    aimPitch = OV53_S16(arg1, 0x1D0);
    bob = OV53_S8(arg1, 0x1F6);
    if (bob != 0) {
        aimPitch += (s16)(((s32)OV53_S8(arg1, 0x1F7) * mathSin((s16)(bob << 0xC))) >> 8);
    }

    OV53_CMD_FIRST(0x24);
    OV53_CMD(OV53_S16(arg1, 0x1DE));
    OV53_CMD(0x26);
    OV53_CMD(OV53_S16(arg1, 0x1DC));
    OV53_CMD(0x18);
    OV53_CMD(aimPitch);
    OV53_CMD(0x1A);
    OV53_CMD(aimYaw);
    OV53_CMD(0x12);
    OV53_CMD(aimPitch);
    OV53_CMD(0x14);
    OV53_CMD(aimYaw);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o53/overlay_53/func_overlay_53_035014F4_1F72B24.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_53_03501850_1F72E80(void *arg0, void *arg1, f32 arg2, s16 arg3, f32 arg4) {
    s32 frames;
    f32 decay;

    (void)arg2;
    (void)arg3;
    OV53_S16(OV53_PTR(arg0, 0x4C), 0x6) = 0;
    frames = (s32)arg4;
    decay = Powerf(D_overlay_53_035037B0, frames);
    OV53_F32(arg1, 0x4) = OV53_F32(arg1, 0x4) * decay;
    OV53_U8(arg1, 0x541) = (u8)(OV53_U8(arg1, 0x541) & 0xFFF0);
    OV53_F32(arg1, 0x10) = decay * OV53_F32(arg1, 0x10);
    if (OV53_U8(arg1, 0x2) == 0) {
        OV53_F32(arg1, 0x594) = OV53_F32(arg1, 0x594) * decay;
    } else {
        OV53_F32(arg1, 0x594) = OV53_F32(arg1, 0x60) * 0.03125f;
        if (OV53_F32(arg1, 0x594) > 1.5f) {
            OV53_F32(arg1, 0x594) = 1.5f;
        }
        OV53_F32(arg0, 0x20) = OV53_F32(arg0, 0x20) * Powerf(D_overlay_53_035037B4, frames);
    }
    if (D_overlay_53_035037B8 < OV53_F32(arg0, 0x28)) {
        if (OV53_S8(arg1, 0x19C) + frames >= 0x80) {
            OV53_S16(arg0, 0x6) = (s16)(OV53_S16(arg0, 0x6) | 0x400);
            OV53_U8(arg1, 0x193) = 1;
        } else {
            OV53_U8(arg1, 0x19C) = (u8)(OV53_S8(arg1, 0x19C) + frames);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o53/overlay_53/func_overlay_53_03501850_1F72E80.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
f32 func_overlay_53_035019B0_1F72FE0(s16 *arg0, void *arg1, f32 arg2, s16 arg3) {
    u8 state = OV53_U8(arg1, 0x568);
    s16 target = arg3;

    if ((state != 0) && (state != 3)) {
        OV53_U8(arg1, 0x13E) = 0;
        OV53_U8(arg1, 0x13F) = 8;
        OV53_S8(arg1, 0x576) = 0;
    } else if (OV53_U8(arg1, 0x13E) == 0) {
        s16 diff = (s16)(*arg0 - target);
        if ((diff < -0x7000) || (diff >= 0x7001)) {
            u8 v = OV53_U8(arg1, 0x13F);
            OV53_S16(arg1, 0x13C) = target;
            if ((v == 0) || (v == 0x10)) {
                OV53_S8(arg1, 0x576) = 0x3C;
                OV53_U8(arg1, 0x13E) = 2;
            } else {
                OV53_S8(arg1, 0x576) = 0;
                OV53_U8(arg1, 0x13E) = 1;
            }
        }
    } else {
        s32 aiRes = 0;
        if (((multiPlayerGame == 0) && (racingInGame == 0)) ||
            ((aiRes = ((s32 (*)(s8, s16))sprintAIPlayer)(OV53_S8(arg1, 0x0), target)) == 0)) {
            rumbleMax((s32)OV53_S8(arg1, 0x0), 0x28, 0.2f);
        }
        if (OV53_S8(arg1, 0x576) == 0) {
            if (OV53_U8(arg1, 0x13E) >= 2) {
                s16 d = (s16)(OV53_S16(arg1, 0x13C) - *arg0);
                if ((d >= -0x38D) && (d < 0x38E)) {
                    OV53_U8(arg1, 0x13E) = 0;
                }
            } else {
                s16 d1 = (s16)(OV53_S16(arg1, 0x13C) - target);
                s16 d2 = (s16)(target - *arg0);
                if ((d1 >= -0x6FFF) && (d1 < 0x7000)) {
                    OV53_U8(arg1, 0x13E) = 0;
                }
                if ((d2 >= -0x38D) && (d2 < 0x38E)) {
                    OV53_U8(arg1, 0x13E) = 0;
                }
            }
        }
        if (OV53_U8(arg1, 0x13E) == 0) {
            OV53_U8(arg1, 0x13F) = 8;
            OV53_S8(arg1, 0x576) = 0;
        } else {
            arg2 = 0.0f;
        }
    }
    return arg2;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o53/overlay_53/func_overlay_53_035019B0_1F72FE0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_53_03501BB4_1F731E4(void *arg0, void *arg1, f32 arg2) {
    s32 frames;
    s32 groundFlags;
    f32 vx;
    f32 vz;
    f32 invDt;
    f32 tmp;
    f32 pitchIn;
    f32 pitchTerm;
    f32 v;
    f32 bank;
    f32 lim;
    f32 dvx;
    f32 dvz;
    s16 rot[3];
    f32 vec[3];

    OV53_F32(arg0, 0x20) = OV53_F32(arg0, 0x20) - ((1.0f - OV53_F32(arg1, 0x594)) * (controlchr_gravity * arg2));
    if (OV53_F32(arg0, 0x20) > 2.5f) {
        tmp = OV53_F32(arg0, 0x20);
        OV53_F32(arg0, 0x20) = tmp + ((2.5f - tmp) * (1.0f - Powerf(D_overlay_53_035037BC, (s32)arg2)));
    }

    frames = (s32)arg2;
    pitchIn = OV53_F32(arg1, 0x50);
    if (pitchIn < 0.0f) {
        v = -pitchIn - D_overlay_53_035037C0;
        if (v < 0.0f) {
            v = 0.0f;
        }
        if (D_overlay_53_035037C4 < v) {
            v = D_overlay_53_035037C4;
        }
        pitchTerm = v * 35.0f;
    } else {
        pitchTerm = 0.0f;
    }
    OV53_F32(arg1, 0x8) = 0.0f;
    OV53_F32(arg1, 0x4) = OV53_F32(arg1, 0x4) + (controlchr_gravity * (pitchIn / (4.0f - pitchTerm)) * arg2);

    OV53_S16(arg0, 0x0) = OV53_S16(arg1, 0x11C);
    OV53_F32(arg0, 0x1C) = Sinf(OV53_S16(arg1, 0x128)) * OV53_F32(arg1, 0x4);
    OV53_F32(arg0, 0x24) = Cosf((s32)OV53_S16(arg1, 0x128)) * OV53_F32(arg1, 0x4);
    OV53_F32(arg0, 0x1C) = OV53_F32(arg0, 0x1C) + (OV53_F32(arg1, 0x10) * Cosf((s32)OV53_S16(arg1, 0x128)));
    vx = OV53_F32(arg0, 0x1C);
    OV53_F32(arg0, 0x24) = OV53_F32(arg0, 0x24) - (OV53_F32(arg1, 0x10) * Sinf(OV53_S16(arg1, 0x128)));
    vz = OV53_F32(arg0, 0x24);
    if (OV53_S8(arg1, 0x149) != 0) {
        vx += OV53_F32(arg1, 0x6C);
        vz += OV53_F32(arg1, 0x70);
    }
    if (disablejoy == 1) {
        vx *= D_overlay_53_035037C8;
        vz *= D_overlay_53_035037C8;
        tmp = OV53_F32(arg1, 0x4);
        if ((tmp < -0.5f) || (tmp > 0.5f)) {
            OV53_F32(arg1, 0x4) = tmp * D_overlay_53_035037C8;
        } else {
            OV53_F32(arg1, 0x4) = 0.0f;
        }
        tmp = OV53_F32(arg1, 0x8);
        if ((tmp < -0.5f) || (tmp > 0.5f)) {
            OV53_F32(arg1, 0x8) = tmp * D_overlay_53_035037C8;
        } else {
            OV53_F32(arg1, 0x8) = 0.0f;
        }
    }
    objMoveXYZ(arg0, (vx * arg2) + OV53_F32(arg1, 0x354), OV53_F32(arg0, 0x20) * arg2,
               (vz * arg2) + OV53_F32(arg1, 0x35C));

    invDt = 1.0f / arg2;
    vec[0] = (OV53_F32(arg0, 0xC) - OV53_F32(arg1, 0x3C)) * invDt;
    vec[2] = (OV53_F32(arg0, 0x14) - OV53_F32(arg1, 0x44)) * invDt;
    groundFlags = controlGroundHits(arg0, arg1, arg2);
    OV53_F32(arg0, 0x20) = (OV53_F32(arg0, 0x10) - OV53_F32(arg1, 0x40)) * invDt;

    rot[0] = (s16)-OV53_S16(arg1, 0x128);
    rot[1] = (s16)-OV53_S16(arg0, 0x2);
    rot[2] = (s16)-OV53_S16(arg0, 0x4);
    vec[1] = 0.0f;
    mathOneFloatYPR(rot, vec);

    if (OV53_S8(arg1, 0x149) != 0) {
        OV53_S8(arg1, 0x149) = (s8)(OV53_S8(arg1, 0x149) - frames);
        if (OV53_S8(arg1, 0x149) < 0) {
            OV53_S8(arg1, 0x149) = 0;
        }
    } else {
        dvx = OV53_F32(arg1, 0x4) - vec[2];
        if (dvx > 0.5f) {
            OV53_F32(arg1, 0x4) = OV53_F32(arg1, 0x4) - (dvx - 0.5f);
        }
        if (dvx < -0.5f) {
            OV53_F32(arg1, 0x4) = OV53_F32(arg1, 0x4) - (dvx + 0.5f);
        }
        dvz = OV53_F32(arg1, 0x8) - vec[0];
        if (dvz > 0.5f) {
            OV53_F32(arg1, 0x8) = OV53_F32(arg1, 0x8) - (dvz - 0.5f);
        }
        if (dvz < -0.5f) {
            OV53_F32(arg1, 0x8) = OV53_F32(arg1, 0x8) - (dvz + 0.5f);
        }
    }

    if (groundFlags & 3) {
        bank = OV53_F32(arg1, 0xC);
        OV53_F32(arg1, 0xC) = bank + ((0.5f - bank) * (1.0f - Powerf(D_overlay_53_035037CC, frames)));
        lim = -OV53_F32(arg1, 0xC);
        if (OV53_F32(arg1, 0x4) < lim) {
            OV53_F32(arg1, 0x4) = lim;
        }
        if (OV53_F32(arg1, 0xC) < OV53_F32(arg1, 0x4)) {
            OV53_F32(arg1, 0x4) = OV53_F32(arg1, 0xC);
        }
        if (OV53_F32(arg1, 0x8) < lim) {
            OV53_F32(arg1, 0x8) = lim;
        }
        if (OV53_F32(arg1, 0xC) < OV53_F32(arg1, 0x8)) {
            OV53_F32(arg1, 0x8) = OV53_F32(arg1, 0xC);
        }
        if (((multiPlayerGame == 0) && (racingInGame == 0)) ||
            (sprintAIPlayer(OV53_F32(arg1, 0x8), lim, OV53_S8(arg1, 0x0)) == 0)) {
            if ((OV53_F32(arg1, 0x4) < -5.0f) || (OV53_F32(arg1, 0x4) > 5.0f)) {
                rumbleMax((s32)OV53_S8(arg1, 0x0), 0x32, 0.2f);
            }
        }
    } else {
        bank = OV53_F32(arg1, 0xC);
        OV53_F32(arg1, 0xC) = bank + ((25.0f - bank) * (1.0f - Powerf(0.875f, frames)));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o53/overlay_53/func_overlay_53_03501BB4_1F731E4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_53_035021E4_1F73814(void *arg0, void *arg1, s32 arg2) {
    void *obj4C = OV53_PTR(arg0, 0x4C);
    s16 count = OV53_S16(obj4C, 0x32);
    void *entry = OV53_PTR(obj4C, 0x40);
    s32 flagged = 0;
    s16 idx;
    u8 v190;

    if (count != 0) {
        idx = (s16)(count - 1);
        do {
            u16 flags = *(u16 *)((u8 *)entry + 0xA);
            entry = (u8 *)entry + 0x34;
            if (flags & 0x40) {
                flagged = 1;
            }
        } while (idx-- != 0);
    }

    v190 = OV53_U8(arg1, 0x190);
    if (v190 == 0x80) {
        OV53_U8(arg1, 0x190) = 0x3C;
        flagged = 1;
        OV53_S16(obj4C, 0x6) = (s16)(OV53_S16(obj4C, 0x6) - 0x100);
    } else {
        s32 t = v190 & 0x7F;
        OV53_U8(arg1, 0x190) = (u8)t;
        if (arg2 < t) {
            OV53_U8(arg1, 0x190) = (u8)(t - arg2);
        } else {
            OV53_U8(arg1, 0x190) = 0;
        }
    }

    if (flagged != 0) {
        charSpeak((s32)arg0, 3);
        OV53_S8(arg1, 0x148) = 8;
    } else {
        OV53_S8(arg1, 0x148) = (s8)(OV53_S8(arg1, 0x148) - arg2);
        if (OV53_S8(arg1, 0x148) < 0) {
            OV53_S8(arg1, 0x148) = 0;
        }
    }
    if (OV53_S8(arg1, 0x148) != 0) {
        frontFlashScreen(0, OV53_S8(arg1, 0x0), 0xFF0000FF);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o53/overlay_53/func_overlay_53_035021E4_1F73814.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_53_0350230C_1F7393C(void *arg0, void *arg1, s32 arg2) {
    void *obj58 = OV53_PTR(arg0, 0x58);
    u8 *flagPtr = (u8 *)OV53_PTR(obj58, 0x84);

    OV53_U8(obj58, 0x75) = 0;
    if (flagPtr != NULL) {
        *flagPtr &= 0xFFFD;
    }
    if (OV53_F32(arg1, 0x60) > 0.0f) {
        OV53_F32(OV53_PTR(arg0, 0x58), 0x80) = OV53_F32(arg1, 0x5C);
        OV53_U8(OV53_PTR(arg0, 0x58), 0x75) = 1;
        if (flagPtr != NULL) {
            if ((D_overlay_53_035037D0 > OV53_F32(arg1, 0x4)) || (D_overlay_53_035037D4 < OV53_F32(arg1, 0x4))) {
                *flagPtr |= 2;
            }
        }
    }
    wakeUpdateRipple(arg0, arg2);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o53/overlay_53/func_overlay_53_0350230C_1F7393C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_53_035023D0_1F73A00(void *arg0, void *arg1, s32 arg2) {
    s16 targetYaw;
    s16 targetPitch;
    s16 yaw;
    s16 pitch;
    s16 yawSwing;
    s16 pitchSwing;
    s16 yawTerm;
    s32 i;
    s8 flagsLeft;
    s32 sinResult;
    f32 clampF;

    targetYaw = (s16)(OV53_S16(arg1, 0x1C8) - OV53_S16(arg0, 0x2));
    if (targetYaw < 0x3001) {
        if (targetYaw < -0x1800) {
            targetYaw = -0x1800;
        }
    } else {
        targetYaw = 0x3000;
    }
    targetPitch = (s16)(OV53_S16(arg1, 0x1C6) - OV53_S16(arg0, 0x0));
    if (targetPitch < 0x1001) {
        if (targetPitch < -0x1000) {
            targetPitch = -0x1000;
        }
    } else {
        targetPitch = 0x1000;
    }

    for (i = 0; i < arg2; i++) {
        yaw = OV53_S16(arg1, 0x1D0);
        pitch = OV53_S16(arg1, 0x1CE);
        OV53_S16(arg1, 0x1D0) = (s16)(yaw + ((s32)(targetYaw - yaw) >> 2));
        OV53_S16(arg1, 0x1CE) = (s16)(pitch + ((s32)(targetPitch - pitch) >> 2));
    }

    flagsLeft = OV53_S8(arg1, 0x1F5);
    yawSwing = 0;
    pitchSwing = 0;
    if (flagsLeft > 0) {
        yawSwing = OV53_S16(arg1, 0x1DA);
        pitchSwing = OV53_S16(arg1, 0x1D8);
        OV53_S8(arg1, 0x1F5) = (s8)(flagsLeft - arg2);
    }
    clampF = (f32)yawSwing;
    if (clampF < D_overlay_53_035037D8) {
        yawSwing = -0x38E3;
    }
    if (D_overlay_53_035037DC < (f32)yawSwing) {
        yawSwing = 0x38E3;
    }
    if ((f32)pitchSwing < D_overlay_53_035037E0) {
        pitchSwing = -0xE38;
    }
    if (D_overlay_53_035037E4 < (f32)pitchSwing) {
        pitchSwing = 0xE38;
    }

    for (i = 0; i < arg2; i++) {
        yaw = OV53_S16(arg1, 0x1DE);
        pitch = OV53_S16(arg1, 0x1DC);
        OV53_S16(arg1, 0x1DE) = (s16)(yaw + ((s32)(yawSwing - yaw) >> 4));
        OV53_S16(arg1, 0x1DC) = (s16)(pitch + ((s32)(pitchSwing - pitch) >> 4));
    }

    if (OV53_S8(arg1, 0x1F4) != 0) {
        yawTerm = OV53_S16(arg1, 0x1D0);
        if (OV53_S8(arg1, 0x1F6) != 0) {
            sinResult = mathSin((s16)(OV53_S8(arg1, 0x1F6) << 0xC));
            yawTerm += (s16)((OV53_S8(arg1, 0x1F7) * sinResult) >> 8);
        }
        OV53_CMD_FIRST(0x24);
        OV53_CMD(OV53_S16(arg1, 0x1DE));
        OV53_CMD(0x26);
        OV53_CMD(OV53_S16(arg1, 0x1DC));
        OV53_CMD(0x18);
        OV53_CMD(yawTerm);
        OV53_CMD(0x1A);
        OV53_CMD(pitchSwing);
        OV53_CMD(0x12);
        OV53_CMD(yawTerm);
        OV53_CMD(0x14);
        OV53_CMD(pitchSwing);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o53/overlay_53/func_overlay_53_035023D0_1F73A00.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_53_03502708_1F73D38(s32 arg0, void *arg1, void *arg2, s8 arg3) {
    (void)arg0;
    (void)arg1;
    (void)arg2;
    (void)arg3;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o53/overlay_53/func_overlay_53_03502708_1F73D38.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_53_0350271C_1F73D4C(void *arg0, void *arg1, f32 arg2, f32 arg3) {
    void *obj = arg0;
    f32 blend;
    s8 mode;
    f32 cur;

    (void)arg2;
    blend = 1.0f - Powerf(D_overlay_53_035037E8, (s32)arg3);
    mode = OV53_S8(obj, 0x3B);
    switch (mode) {
    case 0:
        objAnimDframe(obj, 0.005f, arg3);
        if ((OV53_F32(arg1, 0x4) < D_overlay_53_035037EC) || (D_overlay_53_035037F0 < OV53_F32(arg1, 0x4))) {
            objAnimSetMove(obj, 1, OV53_F32(obj, 0x28));
        }
        cur = OV53_F32(arg1, 0x14);
        OV53_F32(arg1, 0x14) = cur + ((0.0f - cur) * blend);
        break;
    case 1:
        objAnimDframe(obj, 0.01f, arg3);
        if ((D_overlay_53_035037F4 < OV53_F32(arg1, 0x4)) && (OV53_F32(arg1, 0x4) < D_overlay_53_035037F8)) {
            objAnimSetMove(obj, 0, OV53_F32(obj, 0x28));
        }
        cur = OV53_F32(arg1, 0x14);
        if (OV53_S16(arg1, 0x58C) >= 0x12D) {
            OV53_F32(arg1, 0x14) = cur + ((2.0f - cur) * blend);
        } else {
            OV53_F32(arg1, 0x14) = cur + ((1.0f - cur) * blend);
        }
        break;
    default:
        break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o53/overlay_53/func_overlay_53_0350271C_1F73D4C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_53_035028CC_1F73EFC(void *arg0, void *arg1, s32 arg2) {
    (void)arg0;
    (void)arg2;
    OV53_S8(arg1, 0x538) = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o53/overlay_53/func_overlay_53_035028CC_1F73EFC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_53_035028DC_1F73F0C(void *arg0, f32 *arg1, s32 arg2) {
    f32 start[3];
    f32 hitY;
    void *poly;
    s32 state = 1;
    s32 done = 0;
    s32 heightCount;
    s32 *heightList;
    s32 i;
    f32 origY;
    f32 *hp;
    u8 polyType;

    (void)arg2;
    start[0] = OV53_F32(arg0, 0x0);
    start[1] = OV53_F32(arg0, 0x4);
    start[2] = OV53_F32(arg0, 0x8);
    origY = arg1[1];
    poly = NULL;

    do {
        if (trackNearestIntersection(0, start, arg1, (void **)&poly, 0, 0) == 0) {
            done = 1;
        } else if ((state != 2) && (poly != NULL) &&
                   (state = 2, polyType = OV53_U8(poly, 0x48), (polyType == 0x30) || (polyType == 0x31))) {
            start[0] = arg1[0];
            start[1] = arg1[1];
            start[2] = arg1[2];
        } else {
            state = 3;
            done = 1;
        }
    } while (!done);

    heightCount = trackGetHeights(arg1[0], arg1[2], 0, &heightList);
    for (i = heightCount - 1; i >= 0; i--) {
        hp = (f32 *)heightList[i];
        hitY = arg1[1];
        if ((*hp < hitY) && (hitY < (*hp + 1.0f))) {
            arg1[1] = *hp;
        }
    }
    heightCount = trackGetHeights(arg1[0], arg1[2], 0xC00, &heightList);
    for (i = heightCount - 1; i >= 0; i--) {
        hp = (f32 *)heightList[i];
        hitY = arg1[1];
        if (((*hp - 1.0f) < hitY) && (hitY < *hp)) {
            arg1[1] = *hp;
        }
    }
    if (state == 1) {
        if (arg1[1] < origY) {
            arg1[1] = origY;
        }
    }
    return heightCount;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o53/overlay_53/func_overlay_53_035028DC_1F73F0C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hovershipCamera(void *arg0, void *arg1, f32 arg2) {
    void *player = OV53_PTR(arg1, 0x68);
    s32 idx;
    f32 blendA = 1.0f;
    f32 blendB = 1.0f;
    f32 dx;
    f32 dz;
    f32 dist;
    f32 val;
    f32 slotB;
    s16 yawDiff;
    f32 lookAt[3];
    f32 camX;
    f32 camY;
    f32 camZ;
    f32 dx2;
    f32 dy2;
    f32 dz2;
    s16 rotYaw;
    s16 rotPitch;
    f32 offset;
    f32 dmx;
    f32 dmz;
    f32 dmd2;

    OV53_U8(player, 0x10A) = 0;
    camSetFOV(60.0f, 0);

    dx = OV53_F32(arg0, 0xC) - OV53_F32(arg1, 0xC);
    dz = OV53_F32(arg0, 0x14) - OV53_F32(arg1, 0x14);
    dist = sqrtf((dx * dx) + (dz * dz));

    idx = OV53_S8(player, 0x0);
    if ((dist > 225.0f) || (dist < 105.0f)) {
        if (OV53_U8(player, 0x574) != 0) {
            blendA = 1.0f - ((f32 (*)(f32, f32, s32))Powerf)(D_overlay_53_035037FC, dz, (s32)arg2);
        }
        val = D_overlay_53_03503848[idx];
        D_overlay_53_03503848[idx] = ((1.0f - val) * blendA) + val;
    } else {
        if (OV53_U8(player, 0x574) != 0) {
            blendA = 1.0f - ((f32 (*)(f32, f32, s32))Powerf)(D_overlay_53_03503800, dz, (s32)arg2);
        }
        val = D_overlay_53_03503848[idx];
        D_overlay_53_03503848[idx] = ((0.0f - val) * blendA) + val;
        if (D_overlay_53_03503848[idx] < D_overlay_53_03503804) {
            D_overlay_53_03503848[idx] = 0.0f;
        }
    }

    yawDiff = (s16)((Arctanf(dx, dz) - OV53_S16(arg1, 0x0)) - 0x8000);
    slotB = D_overlay_53_03503838[idx];
    if ((dist > 225.0f) && ((yawDiff >= 0x4001) || (yawDiff < -0x4000))) {
        if (OV53_U8(player, 0x574) != 0) {
            blendB = 1.0f - ((f32 (*)(f32, f32, s32))Powerf)(D_overlay_53_03503808, dz, (s32)arg2);
        }
        D_overlay_53_03503838[idx] = ((1.0f - slotB) * blendB) + slotB;
    } else {
        if (OV53_U8(player, 0x574) != 0) {
            blendB = 1.0f - ((f32 (*)(f32, f32, s32))Powerf)(D_overlay_53_0350380C, dz, (s32)arg2);
        }
        D_overlay_53_03503838[idx] = ((0.0f - slotB) * blendB) + slotB;
        if (D_overlay_53_03503838[idx] < D_overlay_53_03503810) {
            D_overlay_53_03503838[idx] = 0.0f;
        }
    }

    offset = D_overlay_53_03503838[idx];
    if (offset > 0.0f) {
        s16 targetYaw = (s16)(0x8000 - OV53_S16(player, 0x128));
        if (OV53_U8(player, 0x574) != 0) {
            blendA = 1.0f - ((f32 (*)(f32, f32, s32))Powerf)(1.0f - (offset * 0.125f), dz, (s32)arg2);
        }
        OV53_S16(player, 0x104) = ((s16 (*)(s16, s16, f32, s16))dAngle)(OV53_S16(player, 0x104), targetYaw, blendA, targetYaw);
    } else if (OV53_U8(player, 0x574) != 0) {
        OV53_S16(player, 0x104) = (s16)(0x8000 - Arctanf(dx, dz));
    }

    {
        f32 d205 = 205.0f - dist;
        f32 d125 = 125.0f - dist;
        f32 sideA = (dist > 205.0f) ? -d205 : d205;
        f32 sideB = (dist > 125.0f) ? -d125 : d125;
        f32 useD = d205;
        f32 scaleD;
        if (sideB < sideA) {
            useD = d125;
        }
        scaleD = (D_overlay_53_03503848[idx] * useD) + dist;
        camX = (Sinf(OV53_S16(player, 0x104)) * scaleD) + OV53_F32(arg1, 0xC);
        camY = OV53_F32(arg1, 0x10) + 60.0f;
        camZ = OV53_F32(arg1, 0x14) - (Cosf((s32)OV53_S16(player, 0x104)) * scaleD);
    }

    func_overlay_53_035028DC_1F73F0C((u8 *)arg1 + 0xC, &camX, 0);

    if (OV53_U8(player, 0x574) != 0) {
        blendA = 1.0f - Powerf(0.875f, (s32)arg2);
    }
    {
        void *cam = controlcam;
        f32 cx = OV53_F32(cam, 0xC);
        f32 cy = OV53_F32(cam, 0x10);
        f32 cz = OV53_F32(cam, 0x14);
        OV53_F32(arg0, 0xC) = ((camX - cx) * blendA) + cx;
        OV53_F32(arg0, 0x10) = ((camY - cy) * blendA) + cy;
        OV53_F32(arg0, 0x18) = OV53_F32(arg0, 0xC);
        OV53_F32(arg0, 0x1C) = OV53_F32(arg0, 0x10);
        OV53_F32(arg0, 0x14) = ((camZ - cz) * blendA) + cz;
        OV53_F32(arg0, 0x20) = OV53_F32(arg0, 0x14);
    }

    lookAt[0] = 0.0f;
    lookAt[1] = 40.0f;
    lookAt[2] = 0.0f;
    pointListRPY(1, arg1, (s32 *)lookAt, lookAt);

    dx2 = OV53_F32(arg0, 0xC) - (lookAt[0] + OV53_F32(arg1, 0xC));
    dy2 = OV53_F32(arg0, 0x10) - (lookAt[1] + OV53_F32(arg1, 0x10));
    dz2 = OV53_F32(arg0, 0x14) - (lookAt[2] + OV53_F32(arg1, 0x14));
    rotYaw = (s16)(0x8000 - Arctanf(dx2, dz2));
    rotPitch = (s16)Arctanf(dy2, sqrtf((dx2 * dx2) + (dz2 * dz2)));
    if (OV53_U8(player, 0x574) != 0) {
        blendB = 1.0f - Powerf(0.125f, (s32)arg2);
    }
    OV53_S16(arg0, 0x0) = dAngle(OV53_S16(arg0, 0x0), rotYaw, blendB);
    OV53_S16(arg0, 0x2) = dAngle(OV53_S16(arg0, 0x2), rotPitch, blendB);
    OV53_S16(arg0, 0x4) = dAngle(OV53_S16(arg0, 0x4), 0, blendB);

    dmx = OV53_F32(arg1, 0xC) - OV53_F32(arg0, 0xC);
    dmz = OV53_F32(arg1, 0x14) - OV53_F32(arg0, 0x14);
    dmd2 = (dmx * dmx) + (dmz * dmz);
    if (dmd2 < 1024.0f) {
        if (dmd2 != 0.0f) {
            f32 k = (32.0f / sqrtf(dmd2)) - 1.0f;
            dmx *= k;
            dmz *= k;
        }
        objMoveXYZ(arg1, dmx, 0.0f, dmz);
    }
    (void)offset;
    (void)dx2;
    (void)dy2;
    (void)dz2;
    (void)camZ;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o53/overlay_53/hovershipCamera.s")
#endif
