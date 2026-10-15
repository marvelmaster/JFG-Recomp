#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
typedef struct AntTimer {
    /* 0x00 */ u16 unk0;    /* shares offset 0xA8 of the state */
    /* 0x02 */ u16 unk2;    /* remaining patrol steps */
    /* 0x04 */ u32 unk4;    /* 0 = patrolling/active, 1 = done */
    /* 0x06 */ s16 unk6;    /* heading offset */
} AntTimer;

typedef struct AntState {
    /* 0x00 */ u8 unk0;     /* bit 6 selects the weapon slot */
    /* 0x01 */ u8 pad1[0x2];
    /* 0x03 */ u8 unk3;     /* bit 6 mirrors !weapon slot */
    /* 0x04 */ u8 pad4[0x34];
    /* 0x38 */ f32 unk38;
    /* 0x3C */ f32 unk3C;
    /* 0x40 */ f32 unk40;
    /* 0x44 */ u8 pad44[0x0D];
    /* 0x51 */ u8 unk51;    /* fire cooldown */
    /* 0x52 */ u8 pad52[0xA8 - 0x52];
    /* 0xA8 */ AntTimer timer;
} AntState;

typedef struct AntObj {
    /* 0x00 */ s16 unk0;    /* y rotation */
    /* 0x02 */ s16 unk2;
    /* 0x04 */ u8 pad4[0x8];
    /* 0x0C */ f32 unkC;
    /* 0x10 */ f32 unk10;
    /* 0x14 */ f32 unk14;
    /* 0x18 */ u8 pad18[0x50];
    /* 0x68 */ AntState *unk68;
} AntObj;

void *squadsGetClosestPlayer();
void squadsFireWeapon(u32, s32, s32, void *);
u8 objTvTimes(s32);
void runlinkSetDestructTimer(s32, s32, s32);
f32 Sinf(s32);
extern s32 __MODULE00138;
extern s32 iDeltaTime;
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void AntShipMover(void *arg0) {
    AntObj *obj = arg0;
    AntState *st;
    AntObj *player;
    AntTimer *t;
    u32 dist;
    s32 distS;
    f32 dx;
    f32 dz;
    f32 d2;
    s32 bit6;

    st = obj->unk68;
    player = squadsGetClosestPlayer();
    dx = obj->unkC - player->unkC;
    dz = obj->unk14 - player->unk14;
    d2 = (dx * dx) + (dz * dz);
    if (d2 >= 2147483648.0f) {
        dist = ((u32) (s32) (d2 - 2147483648.0f)) | 0x80000000U;
    } else {
        distS = (s32) d2;
        if (distS < 0) {
            distS = -1;
        }
        dist = (u32) distS;
    }
    runlinkSetDestructTimer(__MODULE00138, 2, 2);
    t = &st->timer;
    if (t->unk4 != 0) {
        st->unk38 = player->unkC;
        st->unk3C = player->unk10 + 400.0f;
        st->unk40 = player->unk14;
        if (dist < 0x57E40U) {
            t->unk4 = 0;
            t->unk2 = mathRnd(7, 0xC);
            goto block_15;
        }
        if (dist < 0x57E400U) {
            if (iDeltaTime < (s32) st->unk51) {
                st->unk51 = (u8) (st->unk51 - iDeltaTime);
            } else {
                bit6 = (st->unk0 >> 6) & 1;
                squadsFireWeapon((u32) bit6, 0, 0, player);
                st->unk3 = (u8) ((((bit6 ^ 1) << 6) & 0x40) | (st->unk3 & 0xFFBF));
                st->unk51 = objTvTimes(0xC);
            }
            st->unk3C = player->unk10 + 200.0f;
        }
    } else {
        if (iDeltaTime < (s32) t->unk0) {
            t->unk0 = (u16) (t->unk0 - iDeltaTime);
            goto block_18;
        }
block_15:
        if (t->unk2 == 0) {
            t->unk4 = 1;
            st->unk51 = 0;
            return;
        }
        t->unk2 = (u16) (t->unk2 - 1);
        t->unk6 = (s16) (mathRnd(-0x1D4C, 0x1D4C) - 0x8000);
        t->unk0 = (u16) objTvTimes(mathRnd(0x19, 0x28));
block_18:
        st->unk38 = (f32) ((Sinf(obj->unk0 + t->unk6) * 1000.0f) + obj->unkC);
        st->unk3C = player->unk10 + 400.0f;
        st->unk40 = (f32) ((Cosf(obj->unk0 + t->unk6) * 1000.0f) + obj->unk14);
        obj->unk2 = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o138/overlay_138/AntShipMover.s")
#endif
