#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
void __osPiGetAccess(void);
void __osPiRelAccess(void);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 osCartTest4_6105(s32 arg0) {
    s32 temp_v0;

    __osPiGetAccess();
    while (*(volatile s32 *) 0xA4600010 & 3) {
    }
    temp_v0 = *(s32 *) (arg0 | 0xB0000A5C | 0xA0000000);
    __osPiRelAccess();
    if (temp_v0 != 0x1740FFF9) {
        return 0;
    }
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o133/overlay_133/osCartTest4_6105.s")
#endif
