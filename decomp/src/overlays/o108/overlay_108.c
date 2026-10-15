#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern f32 D_overlay_108_06C00230;
extern s32 __MODULE00108;
void hitInitObjectHit(Object *obj, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6,
                      f32 f1, f32 f2, f32 f3, f32 f4, s32 a7);
void amSndPlay(u16 soundID, void *handlePtr);
void *objGetPlayerNo(s32 playerNo);
void objFreeObject(void *obj);
void runlinkSetDestructTimer(s32 module, s32 a1, s32 a2);
s32 mainPlayerHas(s8 a0, s8 a1, u8 a2);
void mainPlayerCollected(s8 a0, s8 a1, u8 a2);
void instQueueMsg(void *obj, s32 msg);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void keyInit(Object *arg0, void *arg1) {
    f32 var_f0;

    *(u8 *)arg0->racer = (u8)(*(s16 *)((u8 *)arg0 + 0x4A) - 0x258);
    var_f0 = (f32)((u8 *)arg1)[0xB] * 0.015625f;
    if (var_f0 < D_overlay_108_06C00230) {
        var_f0 = D_overlay_108_06C00230;
    }
    arg0->segment.trans.scale = **(f32 **)((u8 *)arg0 + 0x40) * var_f0;
    hitInitObjectHit(arg0, -1, 1, 1, 0, 0, 0, 30.0f, 30.0f, -1.0f, 1.0f, 0x11);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o108/overlay_108/keyInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void keyControl(Object *arg0, s32 arg1) {
    Object *player;
    s8 *playerRacer;
    u8 *keyRacer;
    f32 dx, dz, dy;

    runlinkSetDestructTimer(__MODULE00108, 2, 2);
    keyRacer = (u8 *)arg0->racer;
    arg0->segment.trans.y_rotation += (s16)(arg1 << 7);
    player = (Object *)objGetPlayerNo(0);
    if (player != NULL) {
        playerRacer = (s8 *)player->racer;
        if (mainPlayerHas(playerRacer[0], playerRacer[1], *keyRacer) != 0) {
            objFreeObject(arg0);
        } else {
            dx = player->segment.trans.x_position - arg0->segment.trans.x_position;
            dz = player->segment.trans.z_position - arg0->segment.trans.z_position;
            if (((dx * dx) + (dz * dz)) < 1024.0f) {
                dy = arg0->segment.trans.y_position;
                if (((dy + -45.0f) < player->segment.trans.y_position) &&
                    (player->segment.trans.y_position < (dy + 45.0f))) {
                    mainPlayerCollected(playerRacer[0], playerRacer[1], *keyRacer);
                    amSndPlay(0x1F4, 0);
                    instQueueMsg(playerRacer, *keyRacer + 0x170);
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o108/overlay_108/keyControl.s")
#endif
