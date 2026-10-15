#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
void partInitTriggerPos(void *arg0, s32 arg1, s16 arg2, s16 arg3, s16 arg4, s16 arg5);
void partUpdateTriggers(void *obj, s32 arg1);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void bubblerInit(void *arg0, void *arg1) {
    partInitTriggerPos(*(void **)((u8 *)arg0 + 0x70), ((u8 *)arg1)[0xB], ((u8 *)arg1)[0xA], 0, 0, 0);
    *(s32 *)((u8 *)arg0 + 0x88) = *(u16 *)((u8 *)arg1 + 0xC);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o78/overlay_78/bubblerInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void bubblerControl(void *arg0, s32 arg1) {
    if (*(s32 *)((u8 *)arg0 + 0x88) >= mathRnd(0, 0x400)) {
        *(s32 *)((u8 *)arg0 + 0x84) = 1;
    } else {
        *(s32 *)((u8 *)arg0 + 0x84) = 0;
    }
    partUpdateTriggers(arg0, arg1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o78/overlay_78/bubblerControl.s")
#endif
