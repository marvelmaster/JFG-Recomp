#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
typedef struct TokenPlayerState {
    /* 0x00 */ s8 unk0;
    /* 0x01 */ s8 unk1;
} TokenPlayerState;

typedef struct TokenObj {
    /* 0x00 */ s16 unk0;
    /* 0x02 */ u8 pad2[0x0A];
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ u8 pad18[0x50];
    /* 0x68 */ TokenPlayerState *unk68;
} TokenObj;

typedef struct TokenCharacter {
    /* 0x00 */ u8 pad0[0x12];
    /* 0x12 */ s16 unk12;
} TokenCharacter;

void amSndPlay(s32, s32);
void *mainGetGameCharacter(f32, s8, s8);
void objFreeObject(void *);
void *objGetPlayerNo(s32);
void runlinkSetDestructTimer(s32, s32, s32);
extern s32 __MODULE00119;
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void robotTokenControl(void *arg0, s32 arg1) {
    TokenObj *obj = arg0;
    TokenObj *player;
    TokenPlayerState *pstate;
    TokenCharacter *ch;
    f32 dx;
    f32 dy;
    f32 dz;
    s16 count;

    runlinkSetDestructTimer(__MODULE00119, 2, 2);
    obj->unk0 = (s16) (obj->unk0 + (arg1 << 8));
    player = objGetPlayerNo(0);
    if (player != NULL) {
        pstate = player->unk68;
        if (pstate != NULL) {
            dx = obj->unkC - player->unkC;
            dy = obj->unk10 - player->unk10;
            dz = obj->unk14 - player->unk14;
            if (((dx * dx) + (dy * dy) + (dz * dz)) < 1600.0f) {
                ch = mainGetGameCharacter(dz, pstate->unk0, pstate->unk1);
                count = ch->unk12;
                if (count < 0x7D00) {
                    ch->unk12 = (s16) (count + 1);
                }
                amSndPlay(0x1EB, 0);
                objFreeObject(obj);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o119/overlay_119/robotTokenControl.s")
#endif
