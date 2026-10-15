#include "common.h"

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 __alCSeqNextDelta(void *seq, u32 *delta) {
    /* raw offsets: +0x4 channel mask, +0x10 subtract value,
       +0x14 subtract-pending flag, +0xB8 per-channel s32 delta[16] */
    u8 *base = (u8 *)seq;
    u32 mask = *(u32 *)(base + 0x4);
    s32 sub = *(s32 *)(base + 0x10);
    s32 *deltas = (s32 *)(base + 0xB8);
    u32 minDelta = (u32)-1;
    s32 i;

    if (mask == 0) {
        return 0;
    }
    for (i = 0; i < 16; i++) {
        if ((mask >> i) & 1) {
            if (*(s32 *)(base + 0x14) != 0) {
                deltas[i] -= sub;
            }
            if ((u32)deltas[i] < minDelta) {
                minDelta = (u32)deltas[i];
            }
        }
    }
    *(s32 *)(base + 0x14) = 0;
    *delta = minDelta;
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_cseqnextdelta/__alCSeqNextDelta.s")
#endif
