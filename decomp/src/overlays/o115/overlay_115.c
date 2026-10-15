#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
typedef struct NightvisionRacer {
    /* 0x00 */ f32 unk0;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ u8 unkC;
    /* 0x0D */ u8 unkD;
    /* 0x0E */ u8 unkE;
    /* 0x0F */ u8 unkF;
} NightvisionRacer;

typedef struct NightvisionSetup {
    /* 0x00 */ u8 pad00[0xA];
    /* 0x0A */ u16 unkA;
    /* 0x0C */ s8 unkC;
    /* 0x0D */ s8 unkD;
    /* 0x0E */ u8 unkE;
    /* 0x0F */ u8 unkF;
} NightvisionSetup;

extern s16 trackFade;
extern s16 trackFadeEnd;
extern u16 joyGetPressed(s32 player);
void hitInitObjectHit(Object *obj, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6,
                      f32 f1, f32 f2, f32 f3, f32 f4, s32 a7);
s32 fxNightVision(void);
void fxInitNightVision(s32 arg);
void fxFreeNightVision(s32 arg);
s32 mainPlayerHas(s8 a0, s8 a1, s32 a2, void *a3);
void *objGetPlayerNo(s32 playerNo);
void cutcameraActivate(u8 arg);
void cutcameraUpdate(s32 a0, s32 a1, s32 a2, void *a3);
void blastdoorStatus(u8 arg, s32 b);
s32 camGetListPtr(void);
void amSndPlay(u16 soundID, void *handlePtr);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void nightvisionpadInit(Object *arg0, NightvisionSetup *arg1) {
    f32 temp_f0;
    NightvisionRacer *racer;

    racer = (NightvisionRacer *)arg0->racer;
    temp_f0 = (f32)arg1->unkA;
    racer->unk0 = temp_f0 * temp_f0;
    racer->unk4 = arg0->segment.trans.y_position + (f32)arg1->unkC;
    racer->unk8 = arg0->segment.trans.y_position + (f32)arg1->unkD;
    racer->unkC = arg1->unkE;
    racer->unkE = 0;
    racer->unkF = 0;
    racer->unkD = arg1->unkF;
    hitInitObjectHit(arg0, -1, 0, 8, 0, 0, 0, 32.0f, 32.0f, -1.0f, 1.0f, 1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o115/overlay_115/nightvisionpadInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void nightvisionpadControl(Object *arg0, s32 arg1) {
    Object *player;
    u8 *playerRacer;
    NightvisionRacer *racer;
    s32 fxResult;
    f32 dx;
    f32 dz;
    f32 py;

    player = (Object *)objGetPlayerNo(0);
    if (player != NULL) {
        playerRacer = (u8 *)player->racer;
        racer = (NightvisionRacer *)arg0->racer;
        fxResult = fxNightVision();
        trackFade = (s16)((fxResult * 6) + 0x40);
        if (trackFade >= 0x100) {
            trackFade = 0xFF;
        }
        trackFadeEnd = trackFade;
        switch (racer->unkE) {
        case 0:
            if (joyGetPressed(0) & 0x8000) {
                if (mainPlayerHas(((s8 *)playerRacer)[0], ((s8 *)playerRacer)[1], 0x16, playerRacer) != 0) {
                    dx = player->segment.trans.x_position - arg0->segment.trans.x_position;
                    dz = player->segment.trans.z_position - arg0->segment.trans.z_position;
                    py = player->segment.trans.y_position;
                    if ((((dx * dx) + (dz * dz)) < racer->unk0) && (racer->unk4 < py) && (py < racer->unk8)) {
                        if (fxResult != 0) {
                            racer->unkE = 2;
                            racer->unkF = 0x3C;
                            cutcameraActivate(racer->unkC);
                            blastdoorStatus(racer->unkC, 0);
                        } else {
                            racer->unkE = 1;
                            racer->unkF = 0x3C;
                            cutcameraActivate(racer->unkD);
                            blastdoorStatus(racer->unkD, 0);
                        }
                    }
                }
            }
            break;
        case 1:
            if (*(s32 *)(playerRacer + 0x5C0) == 0) {
                racer->unkE = 3;
                cutcameraActivate(racer->unkC);
                if (*(s32 *)(playerRacer + 0x5C0) != 0) {
                    cutcameraUpdate(camGetListPtr(), *(s32 *)(playerRacer + 0x5C0), arg1, playerRacer);
                }
                blastdoorStatus(racer->unkC, 1);
                fxInitNightVision(0);
                amSndPlay(0x1EF, 0);
            }
            break;
        case 2:
            if (*(s32 *)(playerRacer + 0x5C0) == 0) {
                racer->unkE = 3;
                cutcameraActivate(racer->unkD);
                if (*(s32 *)(playerRacer + 0x5C0) != 0) {
                    cutcameraUpdate(camGetListPtr(), *(s32 *)(playerRacer + 0x5C0), arg1, playerRacer);
                }
                blastdoorStatus(racer->unkD, 1);
                fxFreeNightVision(0);
                amSndPlay(0x1EF, 0);
            }
            break;
        case 3:
            if (*(s32 *)(playerRacer + 0x5C0) == 0) {
                racer->unkE = 0;
            }
            break;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o115/overlay_115/nightvisionpadControl.s")
#endif
