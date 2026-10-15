#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
void objFreeObject(void *obj);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void craterInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *params = (u8 *)arg1;
    f32 *timer = *(f32 **)(obj + 0x68);
    f32 *scale = *(f32 **)(obj + 0x50);

    *scale = *scale * *(f32 *)(params + 0x10);
    *(s16 *)(obj + 0x0) = *(s16 *)(params + 0xA);
    *timer = *(f32 *)(params + 0xC);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o84/overlay_84/craterInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void craterControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    f32 *timer = *(f32 **)(obj + 0x68);

    if (*timer > 0.0f) {
        *timer = *timer - ((f32)arg1 / 60.0f);
    } else {
        u8 life = *(u8 *)(obj + 0x39);

        if ((s32)life < arg1 * 2) {
            *(u8 *)(obj + 0x39) = 0;
        } else {
            *(u8 *)(obj + 0x39) = (u8)(life - arg1 * 2);
        }
        if (*(u8 *)(obj + 0x39) == 0) {
            objFreeObject(arg0);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o84/overlay_84/craterControl.s")
#endif
