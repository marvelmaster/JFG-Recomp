#include "common.h"

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void alHeapInit(ALHeap *hp, u8 *base, s32 len) {
    hp->base = base;
    hp->len = len;
    hp->cur = hp->base;
    hp->count = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/slHeap/alHeapInit.s")
#endif

void func_8008BD1C(void) {
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *alHeapDBAlloc(u8 *file, s32 line, ALHeap *hp, s32 num, s32 size) {
    s32 bytes;
    u8 *ptr = 0;

    bytes = (num * size + 0xF) & ~0xF;

    if ((hp->cur + bytes) <= (hp->base + hp->len)) {
        ptr = hp->cur;
        hp->cur += bytes;
    }

    return ptr;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/slHeap/alHeapDBAlloc.s")
#endif
