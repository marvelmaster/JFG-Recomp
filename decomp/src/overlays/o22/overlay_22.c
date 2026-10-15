#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
#define FIELD(type, p, off) (*(type *)((u8 *)(p) + (off)))

/* functions defined in this file */
void func_overlay_22_01600000_1F3C688(void *obj, void *ext, s32 delta);
void sidekickpadInit(void *obj, void *params);
void sidekickpadControl(void *obj, s32 delta);
void sidekickpadFree(void *obj);
void func_overlay_22_01600F18_1F3D5A0(Gfx **dl);
void func_overlay_22_0160114C_1F3D7D4(Gfx **dl, void *mtx, s32 delta);
void robotDisplay(Gfx **dl, s32 arg1, s32 delta);
void func_overlay_22_016020EC_1F3E774(s32 level);
void func_overlay_22_016022C4_1F3E94C(void *obj);
void func_overlay_22_01602310_1F3E998(void *cam);
void robotFinished(void *obj);
void func_overlay_22_01602410_1F3EA98(void *obj);
s32 robotUpdateObjectives(s32 bit, s32 kind);
void func_overlay_22_016025B8_1F3EC40(void *obj);
void robotPauseInit(void);

/* engine functions used here (signatures from other translation units) */
void *objSetupObject();
void objFreeObject(void *obj);
void amSndStopXYZ(void *soundMask);
void amSndPlayXYZ(s32 soundId, f32 x, f32 y, f32 z, s32 flags, void *soundMask);
void amSndPlay(s32 soundId, s32 volume);
void amTunePlay(s32 seq);
void amTuneSetVolume(s32 volume);
u8 amTuneGetSeqNo(void);
void amTuneSetFadeScaled(f32 scale, s32 time);
void amDittyPlay(s32 id);
void hitInitObjectHit(void *obj, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, f32 f7, f32 f8, f32 f9, f32 f10, s32 a11);
void **objGetObjList(s32 *first, s32 *last);
void *objGetPlayerNo(s32 player);
void *mainGetGameCharacter(s32 a, s32 b);
s32 mainGetGameFlag(s32 flag);
void mainPlayerCollected(s32 a, s32 b, s32 c);
s32 mainAnyoneHas();
void mainPauseDisable(s32 arg);
s32 mainGameWindowChanging(void);
void mainSetGameWindow(s16 x0, s16 y0, s16 x1, s16 y1, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8);
void mainSetPauseMode(s32 mode);
void mainGameWindowSize(s32 *a, s32 *b, s32 *c, s32 *d);
s32 mainGetNextCharacter(s8 *player);
s32 frontGetMode(void);
void animseqSetupGroup(s32 group);
void animseqStartNoisyFade(s32 a, s32 b, s32 c, s32 d, s32 e);
s32 camGetPtr(void);
void sidekickpadCamera(void *cam, s32 mode);
void sidekickpadCameraInit(void *arg0, s32 arg1, s32 arg2);
f32 Powerf(f32 base, s32 n);
f32 Sinf(f32 k, s16 angle, f32 *a, f32 *b);
s16 dAngle(s16 a, s16 b, f32 c);
void objMoveXYZ(f32 limit, void *obj, f32 dx, f32 dy, f32 dz);
f32 sqrtf(f32 x);
void partUpdateTriggers(void *obj, s32 delta);
void setupClearScreen(void *p);
void lightObject(void *obj, void *tbl, s32 a, s32 b);
void objAnimDframe(void *obj, f32 speed, f32 dt);
void modGenAnimMatrices(void *tbl, void *model, void *obj, f32 a, f32 b);
void rcpClearZBuffer(Gfx **dl, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
void rcpTileWrite(Gfx **dl, s32 *pix, s32 a, s32 b, s32 c, s32 d, s32 e, s32 f);
void fontBackground(s32 a, s32 b, s32 c, s32 d);
void fontColour(u8 r, u8 g, u8 b, u8 a, s32 alpha);
void fontPrintXY(Gfx **dl, s32 x, s32 y, char *str, s32 size);
void fontUseFont();
f32 camGetFOV(void);
void camSetNo(s32 n);
void camOverrideProjScales(f32 a, f32 b);
void camSetFOV(f32 fov, s32 force);
void camSetView(Gfx **dl, s32 a);
void camResetView(Gfx **dl);
void camStandardPersp(Gfx **dl, void *mtx);
void animswitchInit(void *obj, s32 arg);
void glassInit(void *obj, s32 arg);
void robotcollectableInit(void *obj, s32 arg);
void robottargetInit(void *obj, s32 arg);

/* globals */
extern u8 D_overlay_22_01603240[];
extern u8 *D_overlay_22_01603410;
extern s32 D_overlay_22_0160340C;
extern s8 D_overlay_22_01603414;
extern void *D_overlay_22_01603418;
extern u8 D_overlay_22_01603420;
extern u8 D_overlay_22_01603424;
extern s16 D_overlay_22_01603428;
extern s16 D_overlay_22_0160342C;
extern s16 D_overlay_22_01603430;
extern u8 D_overlay_22_01603434;
extern s8 D_overlay_22_01603438;
extern s8 D_overlay_22_0160343C;
extern s8 D_overlay_22_01603440;
extern s8 D_overlay_22_0160341C;
extern u8 D_overlay_22_01603444[];
extern u8 D_overlay_22_016033FC[];
extern u8 D_overlay_22_016034C0[];
extern u8 D_overlay_22_016033D8[];
extern u8 D_overlay_22_016033E4[];
extern u8 D_overlay_22_016033F0[];
extern s16 D_overlay_22_016033C0[];
extern s16 D_overlay_22_016031E0[];
extern s16 D_overlay_22_016031EC[];
extern s16 D_overlay_22_01603214[];
extern s16 D_overlay_22_0160322C[];
extern s32 D_overlay_22_01603500[];
extern char D_overlay_22_01603530[];
extern char D_overlay_22_01603534[];
extern f32 D_overlay_22_01603568;
extern f32 D_overlay_22_0160356C;
extern f32 D_overlay_22_01603570;
extern f32 D_overlay_22_01603574;
extern f32 D_overlay_22_01603578;
extern f32 D_overlay_22_0160357C;
extern f32 D_overlay_22_01603580;
extern f32 D_overlay_22_01603584;
extern f32 D_overlay_22_01603588;
extern f32 D_overlay_22_0160358C;
extern f32 D_overlay_22_01603590;
extern u8 D_1000A0838[];
extern s32 D_800FF37C;
extern u8 D_800FF383;
extern void *robotBorder;
extern s32 robotButton[];
extern u8 robotCollected;
extern u8 robotDestroyed;
extern u16 robotFlags;
extern s32 robotTime;
extern u8 robotMission;
extern void *front_text;
extern u8 cooperativeGame;
extern s32 animTemp;
extern s16 fadeA;
extern s16 fadeCount;
extern f32 D_overlay_22_01603594;
extern f32 D_overlay_22_01603598;
extern f32 D_overlay_22_0160359C;
extern f32 D_overlay_22_016035A0;
extern f32 D_overlay_22_016035B0;
extern f32 D_overlay_22_016035B4;
extern f32 D_overlay_22_016035B8;
extern f32 D_overlay_22_016035BC;
extern f32 D_overlay_22_016035C0;
extern s16 D_overlay_22_016035C4;
extern s16 D_overlay_22_016035C6;
extern s16 D_overlay_22_016035C8;
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_22_01600000_1F3C688(void *obj, void *ext, s32 delta) {
    void *spawned;
    void *child;

    if (FIELD(u8, ext, 0x1B) != 0) {
        FIELD(s16, D_overlay_22_01603444, 4) = (s16) FIELD(f32, obj, 0xC);
        FIELD(s16, D_overlay_22_01603444, 6) = (s16) (FIELD(f32, obj, 0x10) + 70.0f);
        FIELD(s16, D_overlay_22_01603444, 8) = (s16) FIELD(f32, obj, 0x14);
        FIELD(u8, ext, 0x1B) = 0;
        FIELD(void *, ext, 0x1C) = objSetupObject(D_overlay_22_01603444, 1, ext);
    }
    spawned = FIELD(void *, ext, 0x1C);
    if (spawned != NULL) {
        child = FIELD(void *, spawned, 0x68);
        if (FIELD(u8, ext, 0x17) != 0) {
            FIELD(s16, child, 2) = (s16) (FIELD(s16, child, 2) + (delta * 4));
            if (FIELD(s16, child, 2) >= 0x100) {
                FIELD(s16, child, 2) = 0xFF;
            }
        } else {
            FIELD(s16, child, 2) = (s16) (FIELD(s16, child, 2) - (delta * 0x10));
            if (FIELD(s16, child, 2) < 0) {
                FIELD(s16, child, 2) = 0;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o22/overlay_22/func_overlay_22_01600000_1F3C688.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void sidekickpadInit(void *obj, void *params) {
    void *ext;
    void *cfg;

    ext = FIELD(void *, obj, 0x68);
    FIELD(f32, ext, 0x0) = (f32) FIELD(u8, params, 0xA);
    FIELD(f32, ext, 0x4) = FIELD(f32, obj, 0x10) + (f32) FIELD(s8, params, 0xB);
    FIELD(void *, ext, 0xC) = NULL;
    FIELD(void *, ext, 0x10) = NULL;
    FIELD(u8, ext, 0x14) = 0;
    FIELD(f32, ext, 0x8) = FIELD(f32, obj, 0x10) + (f32) FIELD(s8, params, 0xC);
    FIELD(u8, ext, 0x16) = 0;
    FIELD(u8, ext, 0x17) = 0;
    FIELD(u8, ext, 0x19) = 0;
    FIELD(s8, ext, 0x1A) = -1;
    FIELD(u8, ext, 0x1B) = 1;
    FIELD(void *, ext, 0x1C) = NULL;
    FIELD(u8, ext, 0x15) = FIELD(u8, params, 0xD);

    cfg = FIELD(void *, FIELD(void *, obj, 0x40), 0xAC);
    robotBorder = FIELD(void *, cfg, 0);
    robotButton[0] = FIELD(s32, cfg, 0x4);
    robotButton[1] = FIELD(s32, cfg, 0x8);
    robotButton[2] = FIELD(s32, cfg, 0xC);
    hitInitObjectHit(obj, -1, 0, 8, 0, 0, 0, 32.0f, 32.0f, -1.0f, 1.0f, 1);
    FIELD(s32, obj, 0x88) = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o22/overlay_22/sidekickpadInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void sidekickpadControl(void *obj, s32 delta) {
    void *ext;
    void *player;
    void *pext;
    void *chr;
    void *target;
    u16 buttons;
    u8 state;
    u8 tstate;
    u8 sp41;
    s32 sp38;
    s8 tmp8;
    f32 dx;
    f32 dz;
    f32 py;
    f32 distSq;
    f32 radius;

    ext = FIELD(void *, obj, 0x68);
    player = objGetPlayerNo(0);
    pext = FIELD(void *, player, 0x68);
    chr = mainGetGameCharacter(FIELD(u8, pext, 0), FIELD(u8, pext, 1));

    buttons = joyGetPressed(FIELD(u8, pext, 0));
    if (cooperativeGame != 0) {
        buttons = buttons | joyGetPressed(1);
    }

    FIELD(u8, ext, 0x16) = 0;
    FIELD(s32, obj, 0x84) = 0;
    func_overlay_22_01600000_1F3C688(obj, ext, delta);

    state = FIELD(u8, ext, 0x17);
    if (state < 0xC) {
        switch (state) {
        case 0:
            dx = FIELD(f32, player, 0xC) - FIELD(f32, obj, 0xC);
            dz = FIELD(f32, player, 0x14) - FIELD(f32, obj, 0x14);
            py = FIELD(f32, player, 0x10);
            distSq = (dx * dx) + (dz * dz);
            if (distSq < D_overlay_22_01603568) {
                FIELD(u8, ext, 0x16) = 1;
                if ((buttons & 0x8000) && FIELD(void *, pext, 0x50C) != NULL && FIELD(u8, pext, 0x568) == 0
                    && FIELD(s16, FIELD(void *, player, 0x4C), 6) >= 0x100
                    && (FIELD(s16, chr, 0x12) > 0 || FIELD(u8, ext, 0x15) == 5)) {
                    radius = FIELD(f32, ext, 0x0);
                    if (distSq < (radius * radius) && py < FIELD(f32, ext, 0x8) && FIELD(f32, ext, 0x4) < py) {
                        FIELD(void *, ext, 0xC) = pext;
                        FIELD(u8, ext, 0x17) = 1;
                        FIELD(u8, pext, 0x10D) = 2;
                        sidekickpadCameraInit(obj, 0, 1);
                        mainPauseDisable(0xA);
                        func_overlay_22_016020EC_1F3E774(FIELD(u8, ext, 0x15));
                    }
                }
            }
            break;
        case 1:
            mainPauseDisable(0xA);
            D_overlay_22_01603428 = (s16) (D_overlay_22_01603428 - delta);
            if (D_overlay_22_01603428 <= 0) {
                D_overlay_22_01603430 = 0;
                D_overlay_22_0160342C = 1;
                D_overlay_22_0160343C = 0;
                mainSetGameWindow(0, 0, 0x140, 0xF0, 0x18, 0x1E, 0xA8, 0x8A, 0x20);
                FIELD(u8, ext, 0x17) = 2;
            }
            break;
        case 2:
            mainPauseDisable(0xA);
            if (mainGameWindowChanging() == 0) {
                D_overlay_22_01603430 = 1;
                D_overlay_22_01603438 = 0;
                D_overlay_22_0160343C = 2;
                D_overlay_22_01603440 = 0;
                FIELD(u8, ext, 0x17) = 3;
                animseqStartNoisyFade(0, 0x40, 0xFF, 0xFF, 0x14);
            }
            break;
        case 3:
            mainPauseDisable(0xA);
            if (fadeA == 0xFF) {
                animseqSetupGroup(1);
                fadeA = 0xFF;
                FIELD(u8, ext, 0x17) = 4;
            }
            break;
        case 4:
            mainPauseDisable(0xA);
            D_overlay_22_01603424 = (u8) animTemp;
            if (buttons & 0x9000) {
                amSndPlay(0x16B, 0);
                if (amTuneGetSeqNo() != 0x59) {
                    amTuneSetFadeScaled(0.25f, 0);
                    FIELD(s8, ext, 0x19) = 0xF;
                    FIELD(u8, ext, 0x1A) = 0x59;
                } else {
                    FIELD(s8, ext, 0x19) = 0;
                    FIELD(u8, ext, 0x1A) = 0xFF;
                }
                FIELD(u8, ext, 0x17) = 5;
            } else if (buttons & 0x4000) {
                amSndPlay(0x16B, 0);
                sp41 = amTuneGetSeqNo();
                if (sp41 != FIELD(u8, levelGetLevel(), 0x72)) {
                    amTuneSetFadeScaled(0.25f, 0);
                    FIELD(s8, ext, 0x19) = 0xF;
                    FIELD(u8, ext, 0x1A) = FIELD(u8, levelGetLevel(), 0x72);
                } else {
                    FIELD(s8, ext, 0x19) = 0;
                    FIELD(u8, ext, 0x1A) = 0xFF;
                }
                FIELD(u8, ext, 0x17) = 6;
            }
            break;
        case 5:
            mainPauseDisable(0xA);
            FIELD(s8, ext, 0x19) = (s8) (FIELD(s8, ext, 0x19) - delta);
            if (FIELD(s8, ext, 0x19) <= 0) {
                func_overlay_22_016022C4_1F3E94C(FIELD(void *, ext, 0xC));
                animseqSetupGroup(0);
                setupClearScreen(D_overlay_22_016033FC);
                mainSetGameWindow(0x18, 0x1E, 0xA8, 0x8A, 0, 0, 0x140, 0xF0, -1);
                D_overlay_22_01603430 = 0;
                D_overlay_22_0160342C = 0;
                FIELD(u8, ext, 0x17) = 7;
                if (FIELD(u8, ext, 0x15) != 5) {
                    FIELD(s16, chr, 0x12) = (s16) (FIELD(s16, chr, 0x12) - 1);
                }
                tmp8 = (s8) FIELD(u8, ext, 0x1A);
                if (tmp8 != -1) {
                    amTunePlay(tmp8 & 0xFF);
                    amTuneSetVolume(0x7F);
                    FIELD(u8, ext, 0x1A) = 0xFF;
                }
            }
            break;
        case 6:
            mainPauseDisable(0xA);
            FIELD(s8, ext, 0x19) = (s8) (FIELD(s8, ext, 0x19) - delta);
            if (FIELD(s8, ext, 0x19) <= 0) {
                target = FIELD(void *, ext, 0xC);
                FIELD(u8, target, 0x10D) = 4;
                sidekickpadCameraInit(obj, FIELD(f32, target, 0x104), NULL);
                sidekickpadCamera(camGetPtr(), 2);
                animseqSetupGroup(0);
                setupClearScreen(D_overlay_22_016033FC);
                mainSetGameWindow(0x18, 0x1E, 0xA8, 0x8A, 0, 0, 0x140, 0xF0, -1);
                D_overlay_22_01603430 = 0;
                D_overlay_22_0160342C = 0;
                tmp8 = (s8) FIELD(u8, ext, 0x1A);
                FIELD(u8, ext, 0x17) = 0;
                if (tmp8 != -1) {
                    amTunePlay(tmp8 & 0xFF);
                    amTuneSetVolume(0x7F);
                    FIELD(u8, ext, 0x1A) = 0xFF;
                }
            }
            break;
        case 7:
            target = FIELD(void *, ext, 0xC);
            tstate = FIELD(u8, target, 0x10D);
            if (tstate == 0) {
                FIELD(u8, ext, 0x17) = 0;
            } else if (tstate == 5) {
                D_overlay_22_0160343C = 0;
                FIELD(u8, ext, 0x17) = 8;
                D_overlay_22_01603414 = 0;
                D_overlay_22_01603434 = 2;
            } else if (tstate == 3) {
                func_overlay_22_016025B8_1F3EC40(target);
                if (D_overlay_22_0160340C == 5 && D_overlay_22_01603414 != 0) {
                    FIELD(u8, ext, 0x17) = 0xB;
                    sp38 = mainGetNextCharacter(&D_overlay_22_01603414);
                    mainChangeLevel(0x157, sp38, 0, frontGetMode(), 0, 0);
                } else if (D_overlay_22_0160340C == 4 && D_overlay_22_01603414 != 0) {
                    FIELD(u8, ext, 0x17) = 0xB;
                    sp38 = mainGetNextCharacter(&D_overlay_22_01603414);
                    mainChangeLevel(0x134, sp38, 0, frontGetMode(), 0, 0);
                } else {
                    D_overlay_22_0160343C = 0;
                    D_overlay_22_0160342C = 1;
                    D_overlay_22_01603430 = 0;
                    FIELD(u8, ext, 0x17) = 8;
                    D_overlay_22_01603434 = 2;
                    if (D_overlay_22_01603414 != 0) {
                        animseqStartNoisyFade(0, 0x40, 0xFF, 0xFF, 0x3C);
                        amTuneSetFadeScaled(0.5f, 0x28);
                        if (D_overlay_22_0160341C == 2) {
                            amDittyPlay(0x2B);
                        } else {
                            amDittyPlay(0xF);
                        }
                    }
                    mainSetGameWindow(0, 0, 0x140, 0xF0, 0x18, 0x1E, 0xA8, 0x8A, 0x20);
                }
            }
            FIELD(u8, ext, 0x16) = 1;
            break;
        case 8:
            mainPauseDisable(0xA);
            if (mainGameWindowChanging() == 0) {
                D_overlay_22_01603430 = 1;
                if (FIELD(s16, chr, 0x12) > 0 || FIELD(u8, ext, 0x15) == 5) {
                    D_overlay_22_01603438 = 7;
                    D_overlay_22_0160343C = 3;
                    D_overlay_22_01603440 = 0;
                } else {
                    D_overlay_22_01603438 = 8;
                    D_overlay_22_0160343C = 2;
                    D_overlay_22_01603440 = 1;
                }
                D_overlay_22_01603424 = 0;
                if ((buttons & 0x9000) && D_overlay_22_01603438 == 7) {
                    amSndPlay(0x16B, 0);
                    FIELD(u8, ext, 0x17) = 9;
                    if (D_overlay_22_01603414 == 0) {
                        animseqStartNoisyFade(0, 0x40, 0xFF, 0xFF, 0x14);
                    }
                    if (D_overlay_22_01603418 != NULL) {
                        objFreeObject(D_overlay_22_01603418);
                        D_overlay_22_01603418 = NULL;
                    }
                    amTuneSetFadeScaled(1.0f, 0x7F);
                } else if (buttons & 0x4000) {
                    amSndPlay(0x16B, 0);
                    amTuneSetFadeScaled(0.25f, 0);
                    FIELD(s8, ext, 0x19) = 0xF;
                    FIELD(u8, ext, 0x17) = 0xA;
                } else if (buttons & 0x2000) {
                    amSndPlay(0x16C, 0);
                    D_overlay_22_01603434 = (u8) (D_overlay_22_01603434 + 1);
                    if (D_overlay_22_01603434 >= 3) {
                        D_overlay_22_01603434 = 0;
                    }
                }
            }
            break;
        case 9:
            mainPauseDisable(0xA);
            if (fadeA == 0xFF) {
                D_overlay_22_01603438 = 0;
                D_overlay_22_0160343C = 2;
                D_overlay_22_01603440 = 0;
                animseqSetupGroup(1);
                fadeA = 0xFF;
                FIELD(u8, ext, 0x17) = 4;
                func_overlay_22_01602410_1F3EA98(pext);
                FIELD(u8, pext, 0x10D) = 2;
                func_overlay_22_016020EC_1F3E774(FIELD(u8, ext, 0x15));
            }
            break;
        case 10:
            mainPauseDisable(0xA);
            FIELD(s8, ext, 0x19) = (s8) (FIELD(s8, ext, 0x19) - delta);
            if (FIELD(s8, ext, 0x19) <= 0) {
                sidekickpadCameraInit(obj, FIELD(f32, pext, 0x104), NULL);
                sidekickpadCamera(camGetPtr(), 2);
                func_overlay_22_01602410_1F3EA98(pext);
                setupClearScreen(D_overlay_22_016033FC);
                mainSetGameWindow(0x18, 0x1E, 0xA8, 0x8A, 0, 0, 0x140, 0xF0, -1);
                D_overlay_22_01603430 = 0;
                D_overlay_22_0160342C = 0;
                fadeCount = 0;
                fadeA = 0;
                FIELD(u8, ext, 0x17) = 0;
                if (D_overlay_22_01603418 != NULL) {
                    objFreeObject(D_overlay_22_01603418);
                    D_overlay_22_01603418 = NULL;
                }
                amTunePlay(FIELD(u8, levelGetLevel(), 0x72));
                amTuneSetVolume(0x7F);
            }
            break;
        case 11:
            mainPauseDisable(0xA);
            break;
        }
        state = FIELD(u8, ext, 0x17);
    }
    if (state != 0 && FIELD(u8, pext, 0x5C8) < 0xA) {
        FIELD(u8, pext, 0x5C8) = 0xA;
    }
    if (FIELD(u8, ext, 0x17) != 0) {
        amSndPlayXYZ(0xFC, FIELD(f32, obj, 0xC), FIELD(f32, obj, 0x10), FIELD(f32, obj, 0x14), 1, (u8 *) ext + 0x10);
    } else {
        target = FIELD(void *, ext, 0x10);
        if (target != NULL) {
            amSndStopXYZ(target);
        }
    }
    partUpdateTriggers(obj, delta);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o22/overlay_22/sidekickpadControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void sidekickpadFree(void *obj) {
    void *ext;
    void *snd;

    if (D_overlay_22_01603418 != NULL) {
        objFreeObject(D_overlay_22_01603418);
        D_overlay_22_01603418 = NULL;
    }
    robotBorder = NULL;
    robotButton[0] = 0;
    robotButton[1] = 0;
    robotButton[2] = 0;
    ext = FIELD(void *, obj, 0x68);
    snd = FIELD(void *, ext, 0x10);
    if (snd != NULL) {
        amSndStopXYZ(snd);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o22/overlay_22/sidekickpadFree.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_22_01600F18_1F3D5A0(Gfx **dl) {
    s32 width;
    s32 height;
    s32 unk54;
    s32 unk50;
    s32 winW;
    s32 winH;
    Gfx *g;

    viGetCurrentSize(&width, &height);
    mainGameWindowSize(&unk54, &unk50, &winW, &winH);

    g = *dl;
    *dl = g + 1;
    g->words.w0 = 0x06000000;
    g->words.w1 = (u32) D_overlay_22_016034C0;

    g = *dl;
    *dl = g + 1;
    g->words.w0 = 0xED000000;
    g->words.w1 = ((((s32) ((f32) (width - 1) * 4.0f)) & 0xFFF) << 0xC)
                | ((s32) (((f32) (u32) (height - 1)) * 4.0f) & 0xFFF);

    if (winW < width) {
        g = *dl;
        *dl = g + 1;
        g->words.w0 = ((width & 0x3FF) << 0xE) | 0xF6000000 | ((winH & 0x3FF) * 4);
        g->words.w1 = (winW & 0x3FF) << 0xE;
    }
    if (winH < height) {
        g = *dl;
        *dl = g + 1;
        g->words.w0 = ((width & 0x3FF) << 0xE) | 0xF6000000 | ((height & 0x3FF) * 4);
        g->words.w1 = (winH & 0x3FF) * 4;
    }

    g = *dl;
    *dl = g + 1;
    g->words.w1 = 0;
    g->words.w0 = 0xE7000000;

    g = *dl;
    *dl = g + 1;
    g->words.w1 = (u32) -1;
    g->words.w0 = 0xFA000000;

    g = *dl;
    *dl = g + 1;
    g->words.w1 = (u32) -1;
    g->words.w0 = 0xFB000000;

    camSetScissor(dl);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o22/overlay_22/func_overlay_22_01600F18_1F3D5A0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_22_0160114C_1F3D7D4(Gfx **dl, void *mtx, s32 delta) {
    ObjectTransform xf;
    void *model;
    void *table;
    void *spawn;
    void *model2;
    Gfx *g;
    f32 savedFov;
    f32 ratio;
    f32 dt;
    s32 vpW;
    s32 vpH;
    s32 winX0;
    s32 winY0;
    s32 winX1;
    s32 winY1;
    s32 passes;
    s32 idx;
    s32 k;
    u32 dlAddr;
    u32 color;

    if (robotBorder != NULL) {
        model = FIELD(void *, robotBorder, 0);
        if (model != NULL) {
            table = robotBorder;
            savedFov = camGetFOV();
            viGetCurrentSize(&vpW, &vpH);
            mainGameWindowSize(&winX0, &winY0, &winX1, &winY1);
            ratio = (f32) ((winX1 - winX0) - 0x90) / (f32) (vpW - 0x90);

            xf.y_rotation = -0x8000;
            xf.x_rotation = 0;
            xf.z_rotation = 0;
            xf.unk6 = 0;
            xf.scale = (D_overlay_22_0160356C * ratio) + 1.0f;
            xf.x_position = 360.0f * ratio;
            xf.y_position = -240.0f * ratio;
            xf.z_position = -520.0f;

            camSetNo(0);
            camOverrideProjScales(1.0f, 1.0f);
            camSetFOV(45.0f, 1);
            camSetView(dl, 0);
            camResetView(dl);
            camStandardPersp(dl, mtx);
            rcpClearZBuffer(dl, vpW, vpH, winX0, winY0, winX1, winY1);

            g = *dl;
            *dl = g + 1;
            g->words.w1 = (u32) -1;
            g->words.w0 = 0xFA000000;
            camPushModelMtx(dl, mtx, &xf, 1.0f, 0.0f);

            g = *dl;
            *dl = g + 1;
            g->words.w0 = ((FIELD(u32, table, (FIELD(s8, table, 0xB) * 4) + 0x10) + 0x80000000) & 0xFFFFFF) | 0xBF000000;
            g->words.w1 = FIELD(u32, table, 4) + 0x80000000;

            g = *dl;
            *dl = g + 1;
            g->words.w1 = (u32) D_1000A0838;
            g->words.w0 = 0x02000050;

            g = *dl;
            *dl = g + 1;
            g->words.w0 = 0x06000000;
            g->words.w1 = FIELD(u32, model, 0x74) + 0x80000000;

            if (D_overlay_22_01603414 >= 0) {
                spawn = D_overlay_22_01603418;
                if (spawn != NULL) {
                    table = FIELD(void *, FIELD(void *, spawn, 0x6C), 0);
                    model2 = FIELD(void *, table, 0);
                    FIELD(s32, spawn, 0x8C) = FIELD(s32, spawn, 0x88);
                    FIELD(s32, spawn, 0x88) = FIELD(s16, spawn, 0);

                    if (D_overlay_22_01603414 == 0xA) {
                        dt = (f32) delta;
                        FIELD(f32, spawn, 0x8) = FIELD(f32, spawn, 0x8) + (dt * D_overlay_22_01603574);
                        if (D_overlay_22_01603570 < FIELD(f32, spawn, 0x8)) {
                            FIELD(f32, spawn, 0x8) = D_overlay_22_01603570;
                        }
                        objAnimDframe(spawn, 0.01f, dt);
                        FIELD(f32, spawn, 0xC) = -80.0f;
                        FIELD(f32, spawn, 0x10) = 10.0f;
                        FIELD(f32, spawn, 0x14) = -106.0f;
                        modGenAnimMatrices(table, model2, spawn, 1.0f, 0.0f);
                    } else if (D_overlay_22_01603414 == 8) {
                        FIELD(f32, spawn, 0x8) = FIELD(f32, spawn, 0x8) + ((f32) delta * D_overlay_22_0160357C);
                        if (D_overlay_22_01603578 < FIELD(f32, spawn, 0x8)) {
                            FIELD(f32, spawn, 0x8) = D_overlay_22_01603578;
                        }
                        xf.scale = FIELD(f32, spawn, 0x8);
                        xf.x_position = -168.0f;
                        xf.y_position = 102.0f;
                        xf.z_position = -500.0f;
                    } else if (D_overlay_22_01603414 == 7) {
                        dt = (f32) delta;
                        FIELD(f32, spawn, 0x8) = FIELD(f32, spawn, 0x8) + (dt * D_overlay_22_01603584);
                        if (D_overlay_22_01603580 < FIELD(f32, spawn, 0x8)) {
                            FIELD(f32, spawn, 0x8) = D_overlay_22_01603580;
                        }
                        objAnimDframe(spawn, 0.01f, dt);
                        FIELD(f32, spawn, 0xC) = -132.0f;
                        FIELD(f32, spawn, 0x10) = 34.0f;
                        FIELD(f32, spawn, 0x14) = -350.0f;
                        modGenAnimMatrices(table, model2, spawn, 1.0f, 0.0f);
                    } else if (D_overlay_22_01603414 == 6 || D_overlay_22_01603414 == 9) {
                        FIELD(f32, spawn, 0x8) = FIELD(f32, spawn, 0x8) + ((f32) delta * D_overlay_22_0160358C);
                        if (D_overlay_22_01603588 < FIELD(f32, spawn, 0x8)) {
                            FIELD(f32, spawn, 0x8) = D_overlay_22_01603588;
                        }
                        xf.scale = FIELD(f32, spawn, 0x8);
                        xf.x_position = -42.0f;
                        xf.y_position = 6.0f;
                        xf.z_position = 88.0f;
                    } else {
                        FIELD(f32, spawn, 0x8) = FIELD(f32, spawn, 0x8) + ((f32) delta * D_overlay_22_01603590);
                        if (FIELD(f32, spawn, 0x8) > 1.25f) {
                            FIELD(f32, spawn, 0x8) = 1.25f;
                        }
                        xf.scale = FIELD(f32, spawn, 0x8);
                        xf.x_position = -168.0f;
                        xf.y_position = 102.0f;
                        xf.z_position = -500.0f;
                    }
                    lightObject(spawn, table, FIELD(s32, spawn, 0x54), 0);

                    passes = 1;
                    if (D_overlay_22_01603414 == 5) {
                        passes = 3;
                        FIELD(s16, spawn, 0) = (s16) (FIELD(s16, spawn, 0) + (delta << 9));
                    } else {
                        FIELD(s16, spawn, 0) = (s16) (FIELD(s16, spawn, 0) + (delta << 8));
                    }

                    g = *dl;
                    *dl = g + 1;
                    g->words.w1 = 0;
                    g->words.w0 = 0xE7000000;

                    g = *dl;
                    *dl = g + 1;
                    g->words.w0 = ((FIELD(u32, table, (FIELD(s8, table, 0xB) * 4) + 0x10) + 0x80000000) & 0xFFFFFF) | 0xBF000000;
                    g->words.w1 = FIELD(u32, table, 4) + 0x80000000;

                    for (idx = passes - 1; idx >= 0; idx--) {
                        if (idx == 2) {
                            dlAddr = FIELD(u32, model2, 0x78);
                            xf.y_rotation = (s16) FIELD(s32, spawn, 0x8C);
                            color = 0xFF555555;
                        } else if (idx == 1) {
                            dlAddr = FIELD(u32, model2, 0x78);
                            xf.y_rotation = (s16) FIELD(s32, spawn, 0x88);
                            color = 0xFFAAAAAA;
                        } else {
                            dlAddr = FIELD(u32, model2, 0x74);
                            xf.y_rotation = FIELD(s16, spawn, 0);
                            color = 0xFFFFFFFF;
                        }
                        g = *dl;
                        *dl = g + 1;
                        g->words.w1 = color;
                        g->words.w0 = 0xFA000000;
                        if (FIELD(s8, model2, 0x4E) == 0) {
                            camPushModelMtx(dl, mtx, &xf, 1.0f, 0.0f);
                        }
                        g = *dl;
                        *dl = g + 1;
                        g->words.w0 = 0x06000000;
                        g->words.w1 = dlAddr + 0x80000000;
                    }
                }
            }

            g = *dl;
            *dl = g + 1;
            g->words.w1 = 0;
            g->words.w0 = 0xBF000000;
            camRestoreModelMtx(dl);
            texDPInit(dl);
            camSetFOV(savedFov, 1);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o22/overlay_22/func_overlay_22_0160114C_1F3D7D4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void robotDisplay(Gfx **dl, s32 arg1, s32 delta) {
    char textBuf[16];
    char timeStr[8];
    char *p;
    s16 *labelIdx;
    u8 *itemIdx;
    s32 btn;
    s32 yPos;
    s32 yRow;
    s32 textIdx;
    s32 itemCount;
    s32 count;
    s32 bit;
    s32 mode;
    s32 value;
    s32 divisor;
    s32 i;
    s32 k;
    s32 textY;
    s32 alpha;

    if (D_overlay_22_01603430 < 0) {
        D_overlay_22_0160342C = (s16) (D_overlay_22_0160342C - (delta * 8));
        if (D_overlay_22_0160342C < 0) {
            D_overlay_22_0160342C = 0;
        }
    } else if (D_overlay_22_01603430 > 0) {
        D_overlay_22_0160342C = (s16) (D_overlay_22_0160342C + (delta * 8));
        if (D_overlay_22_0160342C >= 0x100) {
            D_overlay_22_0160342C = 0xFF;
        }
    }
    alpha = D_overlay_22_0160342C;
    if (alpha == 0) {
        return;
    }

    fontBackground(0, 0, 0, 0);
    func_overlay_22_01600F18_1F3D5A0(dl);
    if (D_overlay_22_0160343C > 0) {
        yPos = 0x5C - (D_overlay_22_0160343C * 0xA);
        i = 0;
        fontUseFont(2);
        fontColour(0xFF, 0xFF, 0xFF, 0xFF, alpha);
        do {
            btn = robotButton[D_overlay_22_01603440 + i];
            rcpTileWrite(dl, &btn, 0xC8, yPos, 0xFF, 0xFF, 0xFF, alpha);
            fontPrintXY(dl, 0xD4, yPos, FIELD(char *, front_text, D_overlay_22_0160322C[D_overlay_22_01603438 + i] * 4), 8);
            i += 1;
            yPos += 0x14;
        } while (i < D_overlay_22_0160343C);
    }

    count = FIELD(u8, D_overlay_22_01603410, 2);
    bit = 1 << count;
    mode = D_overlay_22_01603434;
    if (D_overlay_22_01603424 != 0) {
        mode = 1;
        if ((s32) D_overlay_22_01603424 < bit) {
            mode = 0;
        }
    }

    if (mode == 2) {
        fontUseFont(2, count);
        fontColour(0xFF, 0xFF, 0x20, 0xFF, alpha);
        fontPrintXY(dl, 0xA0, 0x9E, FIELD(char *, front_text, 0x80C), 4);
        fontPrintXY(dl, 0xA0, 0xB7, FIELD(char *, front_text, 0x810), 4);
        fontColour(0xFF, 0xFF, 0xFF, 0xFF, alpha);
        sprintf(textBuf, D_overlay_22_01603530, robotCollected);
        fontPrintXY(dl, 0xA0, 0xA8, textBuf, 4);
        sprintf(textBuf, D_overlay_22_01603534, robotDestroyed);
        fontPrintXY(dl, 0xA0, 0xC1, textBuf, 4);
    } else {
        textIdx = 0x1D7;
        if (mode == 0) {
            textIdx = 0x1D6;
            itemCount = count;
            itemIdx = D_overlay_22_01603410 + 4;
            bit = 1;
        } else {
            itemCount = FIELD(u8, D_overlay_22_01603410, 3);
            itemIdx = D_overlay_22_01603410 + 0x10;
        }
        fontUseFont(2, count);
        fontColour(0xFF, 0xFF, 0x20, 0xFF, alpha);
        fontPrintXY(dl, 0xA0, 0x9E, FIELD(char *, front_text, textIdx * 4), 4);

        yRow = 0xAA;
        if (itemCount == 0) {
            fontColour(0xFF, 0xFF, 0xFF, 0xFF, alpha);
            fontPrintXY(dl, 0xA0, 0xAA, FIELD(char *, front_text, 0x55C), 4);
        } else {
            for (k = 0; k < itemCount; k++) {
                if (D_overlay_22_01603424 & bit) {
                    fontColour(0xFF, 0xFF, 0xFF, 0xFF, alpha);
                } else if (D_overlay_22_01603420 & bit) {
                    fontColour(0x40, 0xFF, 0x00, 0xFF, alpha);
                } else {
                    fontColour(0xFF, 0x40, 0x00, 0xFF, alpha);
                }
                fontPrintXY(dl, 0xA0, yRow, FIELD(char *, front_text, D_overlay_22_016031EC[*itemIdx] * 4), 4);
                itemIdx += 4;
                yRow += 0xA;
                bit *= 2;
            }
        }
    }

    if (D_overlay_22_01603414 >= 0) {
        fontUseFont(2, (u8) arg1);
        textY = (D_overlay_22_01603414 == 0) ? 0x54 : 0x7A;
        fontColour(0x00, 0x00, 0x00, 0xFF, alpha);
        fontPrintXY(dl, 0x61, textY + 1, FIELD(char *, front_text, D_overlay_22_01603214[D_overlay_22_01603414] * 4), 0xC);
        fontColour(D_overlay_22_016033D8[D_overlay_22_01603414], D_overlay_22_016033E4[D_overlay_22_01603414],
                   D_overlay_22_016033F0[D_overlay_22_01603414], 0xFF, alpha);
        fontPrintXY(dl, 0x60, textY, FIELD(char *, front_text, D_overlay_22_01603214[D_overlay_22_01603414] * 4), 0xC);
    }

    func_overlay_22_0160114C_1F3D7D4(dl, (void *) arg1, delta);

    fontUseFont(2);
    fontColour(0x00, 0x00, 0x40, 0xFF, alpha);
    fontPrintXY(dl, 0xA0, 0x1A, FIELD(char *, front_text, D_overlay_22_016031E0[D_overlay_22_0160340C] * 4), 4);
    fontColour(0x00, 0x00, 0x40, 0xFF, alpha);
    fontPrintXY(dl, 0xA0, 0x86, FIELD(char *, front_text, 0x754), 4);

    if (robotMission != 0) {
        p = timeStr;
        value = (s32) (robotTime * 0x64) / 60;
        for (k = 0; ; k++) {
            divisor = D_overlay_22_01603500[k];
            if (divisor == -1) {
                *p++ = ':';
            } else if (divisor == -2) {
                *p++ = '.';
            } else if (divisor > 0) {
                *p++ = (char) ((value / divisor) + 0x30);
                value %= divisor;
            }
            if (divisor == 0) {
                break;
            }
        }
        *p = 0;
        fontUseFont(2, (u8) value, (s32 *) p, -1);
        fontColour(0x00, 0x00, 0x00, 0xFF, alpha);
        fontPrintXY(dl, 0x62, 0x2C, timeStr, 4);
        fontColour(0xE0, 0xE0, 0xFF, 0xFF, alpha);
        fontPrintXY(dl, 0x60, 0x2A, timeStr, 4);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o22/overlay_22/robotDisplay.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_22_016020EC_1F3E774(s32 arg0) {
    s32 first;
    s32 last;
    void **list;
    void *obj;
    s16 behaviour;
    s32 param;

    robotCollected = 0;
    robotDestroyed = 0;
    robotFlags = 0;
    robotTime = 0;
    D_overlay_22_01603420 = 0;
    D_overlay_22_01603424 = 0;
    D_overlay_22_01603434 = 0;
    D_overlay_22_0160340C = arg0;
    D_overlay_22_01603410 = D_overlay_22_01603240 + (arg0 << 6);
    D_overlay_22_01603414 = -1;

    list = objGetObjList(&first, &last);
    if (first < last) {
        do {
            obj = list[first];
            first += 1;
            behaviour = FIELD(s16, obj, 0x48);
            if (behaviour == 0x66) {
                param = FIELD(s32, obj, 0x3C);
                if (param != 0) {
                    robottargetInit(obj, param);
                }
            } else if (behaviour == 0x67) {
                param = FIELD(s32, obj, 0x3C);
                if (param != 0) {
                    robotcollectableInit(obj, param);
                }
            } else if (behaviour == 0x60) {
                param = FIELD(s32, obj, 0x3C);
                if (param != 0) {
                    animswitchInit(obj, param);
                }
            } else if (behaviour == 0x4E && FIELD(s32, obj, 0x88) <= 0) {
                param = FIELD(s32, obj, 0x3C);
                if (param != 0) {
                    glassInit(obj, param);
                    FIELD(s16, obj, 0x6) = (s16) (FIELD(s16, obj, 0x6) & ~0x400);
                }
            }
        } while (first < last);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o22/overlay_22/func_overlay_22_016020EC_1F3E774.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_22_016022C4_1F3E94C(void *arg0) {
    void *temp;
    u16 val;

    robotMission = 1;
    FIELD(u8, arg0, 0x10D) = 1;
    val = FIELD(u16, D_overlay_22_01603410, 0);
    temp = FIELD(void *, FIELD(void *, arg0, 0x50C), 0x68);
    FIELD(s16, temp, 0x1E) = 6;
    FIELD(u16, temp, 0x1C) = val;
    func_overlay_22_01602310_1F3E998(temp);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o22/overlay_22/func_overlay_22_016022C4_1F3E94C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_22_01602310_1F3E998(void *arg0) {
    s32 first;
    s32 last;
    void *obj;
    void **list;
    void *pad[2];

    list = objGetObjList(&first, &last);
    if (first < last) {
        do {
            obj = list[first];
            first += 1;
            if (FIELD(s16, obj, 0x48) == 0x68 && FIELD(s16, FIELD(void *, obj, 0x68), 0x16) == 0) {
                FIELD(f32, arg0, 0x0) = FIELD(f32, obj, 0xC);
                FIELD(f32, arg0, 0x4) = FIELD(f32, obj, 0x10);
                FIELD(f32, arg0, 0x8) = FIELD(f32, obj, 0x14);
                FIELD(s16, arg0, 0x60) = (s16) (FIELD(s16, obj, 0x0) + 0x8000);
                FIELD(s16, arg0, 0x62) = (s16) -FIELD(s16, obj, 0x2);
                FIELD(s16, arg0, 0x64) = 0;
            }
        } while (first < last);
    }
    FIELD(s16, arg0, 0x90) = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o22/overlay_22/func_overlay_22_01602310_1F3E998.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void robotFinished(void *arg0) {
    FIELD(u8, arg0, 0x10D) = 3;
    D_overlay_22_01603424 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o22/overlay_22/robotFinished.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_22_01602410_1F3EA98(void *arg0) {
    void *ext;

    robotMission = 0;
    ext = FIELD(void *, arg0, 0x50C);
    FIELD(u8, arg0, 0x10D) = 4;
    ext = FIELD(void *, ext, 0x68);
    FIELD(s16, ext, 0x90) = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o22/overlay_22/func_overlay_22_01602410_1F3EA98.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 robotUpdateObjectives(s32 arg0, s32 arg1) {
    u8 *entry;
    s32 count;
    s32 pass;
    s32 mask;
    s32 i;
    s32 ret;
    u16 flagMask;

    switch (arg1) {
    case 0:
        robotCollected += 1;
        break;
    case 1:
        robotDestroyed += 1;
        break;
    default:
        break;
    }
    if (arg0 >= 0) {
        robotFlags |= (u16) (1 << arg0);
    }

    D_overlay_22_01603420 = 0;
    mask = 1;
    pass = 1;
    count = FIELD(u8, D_overlay_22_01603410, 2);
    entry = D_overlay_22_01603410 + 4;
    do {
        for (i = 0; i < count; i++) {
            switch (FIELD(u8, entry, 1)) {
            case 0:
                if ((s32) robotCollected >= (s32) FIELD(s16, entry, 2)) {
                    D_overlay_22_01603420 |= mask;
                }
                break;
            case 1:
                if ((s32) robotDestroyed >= (s32) FIELD(s16, entry, 2)) {
                    D_overlay_22_01603420 |= mask;
                }
                break;
            default:
                flagMask = FIELD(u16, entry, 2);
                if (flagMask == (robotFlags & flagMask)) {
                    D_overlay_22_01603420 |= mask;
                }
                break;
            }
            entry += 4;
            mask *= 2;
        }
        ret = pass;
        count = FIELD(u8, D_overlay_22_01603410, 3);
        entry = D_overlay_22_01603410 + 0x10;
    } while (pass-- != 0);
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o22/overlay_22/robotUpdateObjectives.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_22_016025B8_1F3EC40(void *arg0) {
    u8 *entry;
    s32 next;
    s16 setup[4];
    void *game;
    s32 value;

    D_overlay_22_01603414 = 0;
    entry = D_overlay_22_01603410 + 0x1C;
    if (D_overlay_22_01603414 < 5 && robotTime < FIELD(u8, entry, 0) * 0x3C
        && robotCollected >= FIELD(u8, entry, 2) && robotDestroyed >= FIELD(u8, entry, 3)) {
        next = D_overlay_22_01603414 + 1;
        if (FIELD(u16, entry, 4) == (robotFlags & FIELD(u16, entry, 4))) {
            do {
                D_overlay_22_01603414 = (s8) next;
                entry += 6;
                if (!(D_overlay_22_01603414 < 5 && robotTime < FIELD(u8, entry, 0) * 0x3C
                      && robotCollected >= FIELD(u8, entry, 2) && robotDestroyed >= FIELD(u8, entry, 3))) {
                    break;
                }
                next = D_overlay_22_01603414 + 1;
            } while (FIELD(u16, entry, 4) == (robotFlags & FIELD(u16, entry, 4)));
        }
    }

    game = mainGetGame();
    value = D_overlay_22_0160340C;
    if ((s32) FIELD(u8, game, value + 0x28) < D_overlay_22_01603414) {
        FIELD(u8, game, value + 0x28) = (u8) D_overlay_22_01603414;
        D_overlay_22_0160341C = 2;
    } else if (D_overlay_22_01603414 > 0) {
        D_overlay_22_0160341C = 1;
    } else {
        D_overlay_22_0160341C = 0;
    }

    if (D_overlay_22_0160340C == 0 && D_overlay_22_01603414 >= 4 && !(D_800FF383 & 1)) {
        D_overlay_22_01603414 = 6;
        mainSetGameFlag(0x49, 1);
    } else if (D_overlay_22_0160340C == 1 && D_overlay_22_01603414 >= 4
               && mainAnyoneHas(0x1A, D_overlay_22_01603414, game) == 0 && mainGetGameFlag(0x20) == 0) {
        mainPlayerCollected(FIELD(u8, arg0, 0), FIELD(u8, arg0, 1), 0x1A);
        D_overlay_22_01603414 = 7;
    } else if (D_overlay_22_0160340C == 2 && D_overlay_22_01603414 >= 4 && mainAnyoneHas(0x1B) == 0) {
        mainPlayerCollected(0, 0, 0x1B);
        mainPlayerCollected(0, 1, 0x1B);
        mainPlayerCollected(0, 2, 0x1B);
        D_overlay_22_01603414 = 8;
    } else if (D_overlay_22_0160340C == 3 && D_overlay_22_01603414 >= 4 && !(D_800FF383 & 4)) {
        D_overlay_22_01603414 = 9;
        mainSetGameFlag(0x4B, 1);
    } else if (FIELD(u8, game, 0x28) == 5 && FIELD(u8, game, 0x29) == 5 && FIELD(u8, game, 0x2A) == 5
               && FIELD(u8, game, 0x2B) == 5 && !(D_800FF37C & 0x20000)) {
        mainSetGameFlag(0x11, 1);
        D_overlay_22_01603414 = 0xA;
    }

    D_overlay_22_01603418 = NULL;
    setup[0] = D_overlay_22_016033C0[D_overlay_22_01603414];
    setup[1] = 0;
    setup[2] = 0;
    setup[3] = 0;
    if (setup[0] >= 0) {
        D_overlay_22_01603418 = objSetupObject(setup, 0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o22/overlay_22/func_overlay_22_016025B8_1F3EC40.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void robotPauseInit(void) {
    D_overlay_22_01603434 = 2;
    D_overlay_22_01603424 = 0;
    D_overlay_22_01603430 = 0;
    D_overlay_22_0160342C = 1;
    D_overlay_22_01603438 = 2;
    D_overlay_22_0160343C = 3;
    D_overlay_22_01603440 = 0;
    mainSetGameWindow(0, 0, 0x140, 0xF0, 0x18, 0x1E, 0xA8, 0x8A, 0x20);
    mainSetPauseMode(1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o22/overlay_22/robotPauseInit.s")
#endif


#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void robotPauseUpdate(void) {
    u16 pressed;
    void *player;
    void *pext;

    if (mainGameWindowChanging() == 0) {
        D_overlay_22_01603430 = 1;
        pressed = joyGetPressed(0);
        if (cooperativeGame != 0) {
            pressed = pressed | joyGetPressed(1);
        }
        if (D_overlay_22_01603438 == 2) {
            if (pressed & 0x9000) {
                amSndPlay(0x16B, 0);
                setupClearScreen(D_overlay_22_016033FC);
                mainSetGameWindow(0x18, 0x1E, 0xA8, 0x8A, 0, 0, 0x140, 0xF0, -1);
                D_overlay_22_01603430 = 0;
                D_overlay_22_0160342C = 0;
                mainSetPauseMode(0);
                return;
            }
            if (pressed & 0x4000) {
                amSndPlay(0x16B, 0);
                D_overlay_22_01603438 = 5;
                D_overlay_22_0160343C = 2;
                D_overlay_22_01603440 = 0;
            } else if (pressed & 0x2000) {
                amSndPlay(0x16C, 0);
                D_overlay_22_01603434 = (u8) (D_overlay_22_01603434 + 1);
                if ((D_overlay_22_01603434 & 0xFF) >= 3) {
                    D_overlay_22_01603434 = 0;
                }
            }
        } else {
            if (pressed & 0x9000) {
                amSndPlay(0x16B, 0);
                player = objGetPlayerNo(0);
                if (player != NULL) {
                    pext = FIELD(void *, player, 0x68);
                    if (pext != NULL) {
                        FIELD(u8, pext, 0x10D) = 5;
                    }
                }
                mainSetPauseMode(0);
                return;
            }
            if (pressed & 0x4000) {
                amSndPlay(0x16B, 0);
                D_overlay_22_01603438 = 2;
                D_overlay_22_0160343C = 3;
                D_overlay_22_01603440 = 0;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o22/overlay_22/robotPauseUpdate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void sidekickpadCameraInit(void *arg0, s32 arg1, s32 arg2) {
    f32 dx;
    f32 dz;
    void *cam;

    cam = (void *) camGetPtr();
    D_overlay_22_016035B0 = FIELD(f32, arg0, 0xC);
    D_overlay_22_016035B4 = FIELD(f32, arg0, 0x10) + 50.0f;
    D_overlay_22_016035B8 = FIELD(f32, arg0, 0x14);
    dx = FIELD(f32, cam, 0xC) - FIELD(f32, arg0, 0xC);
    dz = FIELD(f32, cam, 0x14) - FIELD(f32, arg0, 0x14);
    D_overlay_22_016035BC = sqrtf((dx * dx) + (dz * dz));
    D_overlay_22_016035C0 = FIELD(f32, cam, 0x10) - D_overlay_22_016035B4;
    if (arg2 != 0) {
        D_overlay_22_016035C4 = (s16) (0x8000 - Arctanf(dx, dz));
    } else {
        D_overlay_22_016035C4 = (s16) arg1;
    }
    D_overlay_22_016035C6 = 0;
    D_overlay_22_01603428 = 0x12C;
    D_overlay_22_016035C8 = (s16) arg2;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o22/overlay_22/sidekickpadCameraInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void sidekickpadCamera(void *cam, s32 mode) {
    s16 yawTarget;
    s16 pitchTarget;
    f32 blend;
    f32 sinOut;
    f32 cosOut;
    f32 radius;
    f32 zTerm;

    if (D_overlay_22_016035C8 != 0) {
        /* asm: a1 = mode, a0 not set by caller here */
        blend = 1.0f - ((f32 (*)(f32, void *, s32)) Powerf)(D_overlay_22_01603594, cam, mode);
    } else {
        blend = 1.0f;
    }
    D_overlay_22_016035C6 = (s16) (D_overlay_22_016035C6 + (mode * 0xC));
    D_overlay_22_016035BC = D_overlay_22_016035BC + ((200.0f - D_overlay_22_016035BC) * blend);
    D_overlay_22_016035C0 = D_overlay_22_016035C0 + ((75.0f - D_overlay_22_016035C0) * blend);
    if (D_overlay_22_016035C6 >= 0xC1) {
        D_overlay_22_016035C6 = 0xC0;
    }
    D_overlay_22_016035C4 = (s16) (D_overlay_22_016035C4 + (D_overlay_22_016035C6 * mode));

    sinOut = Sinf(blend, D_overlay_22_016035C4, &D_overlay_22_016035BC, &D_overlay_22_016035C0);
    radius = sinOut * D_overlay_22_016035BC;
    cosOut = Cosf((s32) D_overlay_22_016035C4);
    FIELD(f32, cam, 0xC) = D_overlay_22_016035B0 + radius;
    zTerm = -cosOut * D_overlay_22_016035BC;
    FIELD(f32, cam, 0x10) = D_overlay_22_016035B4 + D_overlay_22_016035C0;
    FIELD(f32, cam, 0x14) = D_overlay_22_016035B8 + zTerm;
    yawTarget = (s16) (0x8000 - Arctanf(radius, zTerm));
    pitchTarget = (s16) Arctanf(D_overlay_22_016035C0, D_overlay_22_016035BC);
    if (D_overlay_22_016035C8 != 0) {
        /* asm: a1 = mode; a0 is not preserved across the calls above */
        blend = 1.0f - ((f32 (*)(f32, void *, s32)) Powerf)(0.875f, (void *) 0, mode);
    } else {
        blend = 1.0f;
    }
    FIELD(s16, cam, 0x0) = dAngle(FIELD(s16, cam, 0x0), yawTarget, blend);
    FIELD(s16, cam, 0x2) = dAngle(FIELD(s16, cam, 0x2), pitchTarget, blend);
    D_overlay_22_016035C8 = 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o22/overlay_22/sidekickpadCamera.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void sidekickpadMovePlayer(void *arg0, void *arg1, s32 arg2) {
    void **list;
    s32 first;
    s32 last;
    void *obj;
    void *found;
    void *ext;
    s8 kind;
    u8 phase;
    f32 sx;
    f32 ang;
    f32 targetY;
    f32 dX;
    f32 dY;
    f32 dZ;
    f32 f0;
    f32 f2;
    f32 f2b;
    f32 limit;
    f32 scaledY;

    list = objGetObjList(&first, &last);
    found = NULL;
    while (first < last) {
        obj = list[first];
        first = first + 1;
        if (FIELD(s16, obj, 0x48) == 0x5D) {
            found = obj;
        }
    }

    if (found != NULL) {
        ext = FIELD(void *, found, 0x68);
        FIELD(u8, ext, 0x18) = (u8) (FIELD(u8, ext, 0x18) + arg2);
        phase = FIELD(u8, ext, 0x18);
        sx = FIELD(f32, found, 0xC);
        ang = ((f32 (*)(s32, void *)) Sinf)((s32) (phase << 8), found); /* sig mismatch */
        targetY = (ang * 8.0f) + FIELD(f32, found, 0x10);
        kind = FIELD(s8, arg1, 1);
        if (kind == 1) {
            targetY = targetY + 45.0f;
        } else if (kind == 2) {
            targetY = targetY + 55.0f;
        } else {
            targetY = targetY + 47.5f;
        }
        dX = sx - FIELD(f32, arg0, 0xC);
        dY = targetY - FIELD(f32, arg0, 0x10);
        dZ = FIELD(f32, found, 0x14) - FIELD(f32, arg0, 0x14);

        /* sig mismatch: asm passes f12, f14, a0 and a1 */
        f0 = ((f32 (*)(f32, f32, s8, s32)) Powerf)(D_overlay_22_01603598, dY, kind, arg2);
        FIELD(f32, arg0, 0x20) = FIELD(f32, arg0, 0x20) * f0;
        f2 = FIELD(f32, arg1, 0x594);
        FIELD(f32, arg1, 0x594) = f2 + ((1.0f - f2) * (1.0f - f0));

        /* asm: a1 = arg2; a0 is not preserved across the calls above */
        f2b = 1.0f - ((f32 (*)(f32, void *, s32)) Powerf)(D_overlay_22_0160359C, (void *) 0, arg2);
        scaledY = dY * f2b;
        limit = (f32) arg2 * D_overlay_22_016035A0;
        if (limit < scaledY) {
            scaledY = limit;
        }
        objMoveXYZ(limit, arg0, dX * f2b, scaledY, dZ * f2b);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o22/overlay_22/sidekickpadMovePlayer.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void robotMissionFree(void) {
    robotMission = 0;
    fadeA = 0;
    fadeCount = 0;
    D_overlay_22_01603430 = 0;
    D_overlay_22_0160342C = 0;
    if (D_overlay_22_01603418 != NULL) {
        objFreeObject(D_overlay_22_01603418);
    }
    mainSetGameWindow(0x18, 0x1E, 0xA8, 0x8A, 0, 0, 0x140, 0xF0, -1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o22/overlay_22/robotMissionFree.s")
#endif
