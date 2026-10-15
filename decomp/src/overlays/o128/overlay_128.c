#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
typedef struct TotemPoleRacer {
    /* 0x00 */ u16 unk0;
    /* 0x02 */ s8 unk2;
    /* 0x03 */ u8 pad03;
    /* 0x04 */ f32 unk4;
    /* 0x08 */ f32 unk8;
    /* 0x0C */ f32 unkC;
} TotemPoleRacer;

typedef struct TotemPoleSetup {
    /* 0x00 */ u8 pad00[0xA];
    /* 0x0A */ u16 unkA;
    /* 0x0C */ u8 unkC;
    /* 0x0D */ u8 unkD;
    /* 0x0E */ u8 pad0E;
    /* 0x0F */ u8 unkF;
    /* 0x10 */ s8 unk10;
    /* 0x11 */ s8 unk11;
} TotemPoleSetup;

extern f32 D_overlay_128_080002C0;
void hitInitObjectHit(Object *obj, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6,
                      f32 f1, f32 f2, f32 f3, f32 f4, s32 a7);
s32 mainGetGameFlag(u16 flag);
void objAnimSetMove(void *obj, s32 a1, f32 speed);
void amDittyPlay(s32 id);
void instQueueMsg(void *obj, s32 msg);
void modSetTextureFrame(void *arg0, s32 arg1, s32 arg2, void *arg3);
void objAnimDframe(void *obj, s32 animBits, f32 frame);
void *objGetPlayerNo(s32 playerNo);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void totemPoleInit(Object *arg0, TotemPoleSetup *arg1) {
    TotemPoleRacer *racer;

    racer = (TotemPoleRacer *)arg0->racer;
    arg0->segment.trans.scale = **(f32 **)((u8 *)arg0 + 0x40) *
                                ((f32)arg1->unkC * D_overlay_128_080002C0);
    arg0->segment.trans.y_rotation = (s16)(arg1->unkD << 8);
    racer->unk0 = arg1->unkA;
    if (mainGetGameFlag(arg1->unkA) != 0) {
        objAnimSetMove(arg0, 0, 1.0f);
        racer->unk2 = 1;
    } else {
        objAnimSetMove(arg0, 0, 0.0f);
        racer->unk2 = 0;
    }
    racer->unk4 = (f32)arg1->unkF;
    racer->unk8 = arg0->segment.trans.y_position + (f32)arg1->unk10;
    racer->unkC = arg0->segment.trans.y_position + (f32)arg1->unk11;
    hitInitObjectHit(arg0, -1, 0, 8, 0, 0, 0, 32.0f, 32.0f, -1.0f, 1.0f, 1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o128/overlay_128/totemPoleInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void totemPoleControl(Object *arg0, s32 arg1) {
    TotemPoleRacer *racer;
    Object *player;
    f32 dx;
    f32 dz;
    f32 py;

    racer = (TotemPoleRacer *)arg0->racer;
    switch (racer->unk2) {
    case 0:
        player = (Object *)objGetPlayerNo(0);
        dx = player->segment.trans.x_position - arg0->segment.trans.x_position;
        dz = player->segment.trans.z_position - arg0->segment.trans.z_position;
        py = player->segment.trans.y_position;
        if ((((dx * dx) + (dz * dz)) < (racer->unk4 * racer->unk4)) &&
            (py < racer->unkC) && (racer->unk8 < py)) {
            racer->unk2 = 1;
            mainSetGameFlag((s32)racer->unk0, 1);
            amDittyPlay(0x1D);
            instQueueMsg(player->racer, 0x1BC);
        }
        break;
    case 1:
        modSetTextureFrame((*(void ***)((u8 *)arg0 + 0x6C))[0], 0, 0x100, arg0);
        objAnimDframe(arg0, 0x3C8B4396, (f32)arg1);
        break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o128/overlay_128/totemPoleControl.s")
#endif
