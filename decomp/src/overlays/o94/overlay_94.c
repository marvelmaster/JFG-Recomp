#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
void animseqPause(void);
void animseqPlay(void);
void animseqStartPath(u8 path);
void animseqStopPath(u8 path);
void animseqHoldPath(u8 path);
void animseqSetupGroup(s16 group);
s32 mainGetAnimGroup(void);
s32 mainGetGameFlag(s16 flag);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void flagtriggerInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *params = (u8 *)arg1;

    *(s16 *)(obj + 0x88) = params[0xA];
    *(s16 *)(obj + 0x8A) = *(s8 *)(params + 0xD);
    *(s16 *)(obj + 0x8C) = params[0xB];
    *(s16 *)(obj + 0x8E) = params[0xC];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o94/overlay_94/flagtriggerInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void flagtriggerControl(void *arg0, s32 arg1) {
    u8 *trig = (u8 *)arg0 + 0x88;   /* trigger block: s16 flag/id @0, s16 group @2, s16 @4, u8 path @5, u16 mode @6 */

    (void)arg1;
    if (*(s16 *)(trig + 0x0) < 0) {
        return;
    }
    if (mainGetAnimGroup() != *(s16 *)(trig + 0x2)) {
        return;
    }
    if (mainGetGameFlag(*(s16 *)(trig + 0x0)) == 0) {
        return;
    }

    switch (*(u16 *)(trig + 0x6)) {
    case 0:
        animseqPause();
        break;
    case 1:
        animseqPlay();
        break;
    case 2:
        animseqStartPath(trig[0x5]);
        break;
    case 3:
        animseqStopPath(trig[0x5]);
        break;
    case 4:
        animseqHoldPath(trig[0x5]);
        break;
    case 5:
        animseqSetupGroup(*(s16 *)(trig + 0x4));
        break;
    }
    *(s16 *)(trig + 0x0) = -1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o94/overlay_94/flagtriggerControl.s")
#endif
