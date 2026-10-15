#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
extern f32 D_overlay_93_05D00370;
extern s16 D_overlay_93_05D002B0[];
s32 mainGetGameFlag(u8 flag);
void hitInitObjectHit(void *arg0, s16 arg1, s8 arg2, s8 arg3, s16 arg4, s16 arg5, s16 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, u16 arg11);
void partUpdateTriggers(void *obj, s32 arg1);
void sparkAdd(void *params);
void amSndPlayXYZ(u16 soundId, f32 x, f32 y, f32 z, u8 arg4, void *soundMask);
void *objGetPlayerNo(s32 playerNo);
void instQueueMsg(s32 arg0, s16 arg1);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void flagtargetInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *params = (u8 *)arg1;
    u8 flagId = params[0xA];

    *(s16 *)(obj + 0x0) = *(s16 *)(params + 0xC);
    *(s16 *)(obj + 0x2) = *(s16 *)(params + 0xE);
    *(s32 *)(obj + 0x88) = flagId;
    if (mainGetGameFlag(flagId) != 0) {
        obj[0x3A] = 1;
    } else {
        obj[0x3A] = 0;
    }
    hitInitObjectHit(obj, params[0xB] << 8, 0, 8, 0, 0, 0, 20.0f, 20.0f, -1.0f, 1.0f, 0x11);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o93/overlay_93/flagtargetInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void flagtargetControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *target;
    u8 *player;
    u8 spark[0x24];   /* sparkAdd() parameter block, asm 0x48..0x68 on the stack */
    f32 scale;
    s32 i;
    s32 flagId;
    s16 msg;

    (void)arg1;
    if (*(s8 *)(obj + 0x3A) != 0) {
        return;
    }
    target = *(u8 **)(obj + 0x4C);
    if (target == NULL) {
        return;
    }
    if (*(u8 **)(obj + 0x5C) == NULL) {
        return;
    }

    *(s16 *)(target + 0x6) = (s16)(*(s16 *)(target + 0x6) - *(s16 *)(*(u8 **)(obj + 0x5C) + 0x130));
    if (*(s16 *)(target + 0x6) > 0) {
        return;
    }

    *(u8 *)(obj + 0x3A) = 1;
    *(s32 *)(obj + 0x84) = 1;
    partUpdateTriggers(obj, 2);

    *(f32 *)(spark + 0x8) = *(f32 *)(obj + 0xC);
    *(f32 *)(spark + 0xC) = *(f32 *)(obj + 0x10);
    *(f32 *)(spark + 0x10) = *(f32 *)(obj + 0x14);
    *(s16 *)(spark + 0x18) = 0x14;
    spark[0x1A] = 0xA;
    spark[0x1B] = 0xFF;
    *(s32 *)(spark + 0x1C) = -0x7F01;
    *(s32 *)(spark + 0x20) = 0xFF0000FF;

    scale = D_overlay_93_05D00370;
    /* asm loop: the counter is tested before the delay-slot decrement, so the body runs 12 times */
    for (i = 11; i >= 0; i--) {
        *(s16 *)(spark + 0x0) = (s16)mathRnd(-0x8000, 0x7FFF);
        *(s16 *)(spark + 0x2) = (s16)mathRnd(-0x3000, 0x3C00);
        *(f32 *)(spark + 0x4) = (f32)mathRnd(0x46, 0x5A) * scale;
        *(f32 *)(spark + 0x14) = (f32)mathRnd(0x19, 0x32) * scale;
        sparkAdd(spark);
    }

    *(s16 *)(target + 0x6) = 0;
    amSndPlayXYZ(0x1F0, *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14), 4, NULL);
    flagId = *(s32 *)(obj + 0x88);
    mainSetGameFlag(flagId, 1);

    msg = D_overlay_93_05D002B0[flagId];
    if (msg != -1) {
        player = objGetPlayerNo(0);
        if (player != NULL) {
            instQueueMsg(*(s32 *)(player + 0x68), msg);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o93/overlay_93/flagtargetControl.s")
#endif
