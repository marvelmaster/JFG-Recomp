#include "common.h"

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
f32 alCents2Ratio(s32 cents) {
    f32 base;
    f32 ratio = 1.0f;
    s32 n = cents;

    if (n >= 0) {
        base = 1.000577807f;
    } else {
        base = 0.9994225502f;
        n = -n;
    }
    while (n != 0) {
        if (n & 1) {
            ratio *= base;
        }
        base *= base;
        n >>= 1;
    }
    return ratio;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/cents2ratio/alCents2Ratio.s")
#endif
