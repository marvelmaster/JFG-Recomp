#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
void __osPiGetAccess(void);
void __osPiRelAccess(void);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 osCartTest3_6105(s32 arg0) {
    s32 temp_v0;

    __osPiGetAccess();
    while (*(volatile s32 *) 0xA4600010 & 3) {
    }
    temp_v0 = *(s32 *) (arg0 | 0xB0000454 | 0xA0000000);
    __osPiRelAccess();
    if (temp_v0 != 0x0109082B) {
        return 0;
    }
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o111/overlay_111/osCartTest3_6105.s")
#endif
