#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
typedef struct FrogObj {
    /* 0x00 */ s16 unk0;       /* y rotation */
    /* 0x02 */ u8 pad2[0xA];
    /* 0x0C */ f32 unkC;       /* x position */
    /* 0x10 */ f32 unk10;      /* y position */
    /* 0x14 */ f32 unk14;      /* z position */
    /* 0x18 */ u8 pad18[0x04];
    /* 0x1C */ f32 unk1C;      /* x velocity */
    /* 0x20 */ u8 pad20[0x04];
    /* 0x24 */ f32 unk24;      /* z velocity */
    /* 0x28 */ u8 pad28[0x3A - 0x28];
    /* 0x3A */ s8 unk3A;
    /* 0x3B */ u8 pad3B[0x68 - 0x3B];
    /* 0x68 */ struct FrogState *unk68; /* per-frog state */
    /* 0x6C */ u8 pad6C[0x84 - 0x6C];
    /* 0x84 */ s32 unk84;
} FrogObj;

typedef struct FrogState {
    /* 0x00 */ f32 unk0;       /* home x */
    /* 0x04 */ f32 unk4;       /* home y */
    /* 0x08 */ f32 unk8;       /* home z */
    /* 0x0C */ f32 unkC;       /* speed (from spawn data) */
    /* 0x10 */ f32 unk10;      /* squared reach radius */
    /* 0x14 */ u8 unk14;       /* state: 0 idle, 1 lunge, 2 dead, 3/4 recover, 5 death fade */
    /* 0x15 */ u8 unk15;       /* nonzero: free the object when hit */
    /* 0x16 */ s16 unk16;      /* timer */
    /* 0x18 */ s8 unk18;
    /* 0x19 */ s8 unk19;       /* cooldown after hit */
    /* 0x1A */ s16 unk1A;      /* heading */
    /* 0x1C */ f32 unk1C;
    /* 0x20 */ f32 unk20;
    /* 0x24 */ f32 unk24;
    /* 0x28 */ f32 unk28;
    /* 0x2C */ f32 unk2C;
    /* 0x30 */ f32 unk30;
    /* 0x34 */ f32 unk34;
    /* 0x38 */ f32 unk38;
    /* 0x3C */ s32 unk3C;
} FrogState;

typedef struct FrogSpawn {
    /* 0x0A */ s16 unkA;
    /* 0x0C */ u8 unkC;
} FrogSpawn;

f32 Sinf(s16);
s32 hitPlayer(f32, f32, f32, s32, s32, void **);
void objAnimSetFrame(void *, f32, ...);
void objFreeObject(void *);
void objMoveXYZ(void *, f32, s32, f32);
void objMoveXYZnocheck();
void partUpdateTriggers(void *, s32, s32);
s32 trackGetHeights(f32, f32, s32, s32 ***);

extern s32 D_FFC00300;
extern f32 D_overlay_99_063006D0;
extern f32 D_overlay_99_063006EC;
extern f32 D_overlay_99_063006F0;
extern f32 D_overlay_99_063006F4;
extern f32 D_overlay_99_063006F8;
extern f32 D_overlay_99_063006FC;
extern f32 D_overlay_99_06300700;
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frogInit(void *arg0, void *arg1) {
    FrogObj *obj = arg0;
    FrogSpawn *spawn = arg1;
    FrogState *st = obj->unk68;

    st->unk15 = spawn->unkC;
    st->unk0 = obj->unkC;
    st->unk4 = obj->unk10;
    st->unk8 = obj->unk14;
    st->unk14 = 0;
    st->unkC = (f32) spawn->unkA;
    st->unk10 = st->unkC * st->unkC;
    st->unk20 = obj->unkC;
    st->unk19 = 0;
    st->unk3C = 0x100;
    st->unk30 = 1.0f;
    st->unk34 = 1.0f;
    st->unk38 = 1.0f;
    st->unk24 = obj->unk14;
    obj->unk3A = 0;
}

void frogControl(void *arg0, s32 arg1) {
    FrogObj *obj = arg0;
    FrogState *st;
    FrogObj *player;
    s32 **sp40;
    s32 moving;
    s32 var_v0;
    s32 var_v1;
    s32 temp_v1_2;
    s32 temp_v0;
    s32 temp_t4;
    f32 dt;
    f32 var_f2;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 temp_f0_2;
    f32 temp_f2;
    f32 temp_f2_2;
    f32 temp_f6;
    f32 ex;
    f32 ez;

    dt = (f32) arg1;
    var_f2 = dt;
    if (D_FFC00300 == 0) {
        var_f2 = dt * D_overlay_99_063006D0;
    }
    st = obj->unk68;

    switch (st->unk14) {
    case 0:
        objAnimSetFrame(obj, 0.0f, arg1);
        moving = 0;
        if (st->unk19 > 0) {
            st->unk19 = (s8) (st->unk19 - arg1);
        }
        if (hitPlayer(obj->unkC, obj->unk10, obj->unk14, 0x42C00000, 1, (void **) &player) > 0) {
            dx = obj->unkC - player->unkC;
            dy = obj->unk10 - player->unk10;
            dz = obj->unk14 - player->unk14;
            if ((st->unk19 <= 0) && (((dx * dx) + (dy * dy) + (dz * dz)) < 1600.0f)) {
                if (st->unk15 != 0) {
                    objFreeObject(obj);
                } else {
                    st->unk14 = 2;
                }
                break;
            }
            st->unk1C = 72.0f;
            if (st->unk15 != 0) {
                st->unk1C = (f32) (st->unk1C * D_overlay_99_063006EC);
            }
            st->unk1A = (s16) (Arctanf(-dx, -dz) + 0x8000);
            moving = 1;
        } else {
            st->unk16 = (s16) (st->unk16 - arg1);
            if (st->unk16 < 0) {
                moving = 1;
                st->unk1C = (f32) mathRnd(0x28, 0x48);
                st->unk1A = (s16) (mathRnd(-0x4000, 0x4000) + obj->unk0);
            }
        }
        if (moving != 0) {
            var_v0 = 0;
            var_v1 = 0;
            do {
                st->unk28 = (f32) (Sinf(st->unk1A) * st->unk1C);
                temp_f2 = Cosf((s32) st->unk1A) * -st->unk1C;
                st->unk2C = temp_f2;
                ex = (obj->unkC + st->unk28) - st->unk0;
                var_v0 += 1;
                ez = (obj->unk14 + temp_f2) - st->unk8;
                if (((ex * ex) + (ez * ez)) < st->unk10) {
                    var_v1 = 1;
                } else {
                    st->unk1A = (s16) (st->unk1A + 0x4000);
                }
            } while ((var_v0 < 4) && (var_v1 == 0));
            if (var_v1 == 0) {
                st->unk1A = (s16) Arctanf(st->unk0 - obj->unkC, st->unk8 - obj->unk14);
            }
            st->unk14 = 1;
            st->unk20 = obj->unkC;
            st->unk18 = 0x20;
            st->unk24 = obj->unk14;
            obj->unk0 = (s16) -st->unk1A;
        }
        break;
    case 1:
        temp_v1_2 = st->unk19;
        st->unk18 = (s8) (st->unk18 - arg1);
        if (temp_v1_2 > 0) {
            st->unk19 = (s8) (temp_v1_2 - arg1);
        }
        if (st->unk18 < 0) {
            st->unk14 = 0;
            temp_v0 = mathRnd(0, 0x12C);
            st->unk18 = 0;
            st->unk16 = (s16) temp_v0;
        }
        objAnimSetFrame(obj, (32.0f - (f32) st->unk18) * 0.03125f);
        temp_f6 = Cosf(st->unk18 << 0xA) + 1.0f;
        obj->unkC = st->unk20;
        temp_f2_2 = temp_f6 * 0.5f;
        obj->unk14 = st->unk24;
        obj->unk1C = (f32) (st->unk28 * temp_f2_2);
        obj->unk24 = (f32) (st->unk2C * temp_f2_2);
        objMoveXYZnocheck(0x3F800000);
        objMoveXYZ(obj, obj->unk1C, 0, obj->unk24);
        if (trackGetHeights(obj->unkC, obj->unk14, 0x800, &sp40) != 0) {
            obj->unk10 = 0.0f;
            objMoveXYZnocheck();
            objMoveXYZ(obj, 0.0f, **sp40, 0.0f);
        }
        if ((st->unk19 <= 0) && ((st->unk18 < 6) || (st->unk18 >= 0x1B))
            && (hitPlayer(obj->unkC, obj->unk10, obj->unk14, 0x42200000, 0, (void **) &player) != 0)) {
            if (st->unk15 != 0) {
                objFreeObject(obj);
            } else {
                st->unk14 = 2;
            }
        }
        break;
    case 2:
        st->unk30 = (f32) (st->unk30 - (D_overlay_99_063006F4 * var_f2));
        if (st->unk30 < D_overlay_99_063006F0) {
            st->unk30 = D_overlay_99_063006F0;
            st->unk14 = 3;
            st->unk16 = 0x28;
        }
        break;
    case 3:
        st->unk16 = (s16) (st->unk16 - arg1);
        if (st->unk16 < 0) {
            st->unk14 = 4;
        }
        break;
    case 4:
        temp_f0_2 = st->unk30;
        if (temp_f0_2 > 1.0f) {
            st->unk30 = 1.0f;
            st->unk14 = 0;
            st->unk16 = 0;
            st->unk19 = 0x3C;
        } else {
            st->unk30 = (f32) (temp_f0_2 + (D_overlay_99_063006F8 * var_f2));
        }
        break;
    case 5:
        obj->unk84 = 1;
        partUpdateTriggers(obj, arg1, arg1);
        st->unk34 = (f32) (st->unk34 + (D_overlay_99_063006FC * dt));
        st->unk38 = (f32) (st->unk38 - (D_overlay_99_06300700 * dt));
        if (st->unk38 < D_overlay_99_063006FC) {
            st->unk38 = (f32) D_overlay_99_063006FC;
            temp_t4 = st->unk3C - (arg1 << 5);
            st->unk3C = temp_t4;
            if (temp_t4 <= 0) {
                st->unk3C = 0;
                objFreeObject(obj);
            }
        }
        break;
    default:
        break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o99/overlay_99/frogInit.s")

#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o99/overlay_99/frogControl.s")
#endif
