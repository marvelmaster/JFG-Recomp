#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#include "PR/libaudio.h"
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void alLink(ALLink *ln, ALLink *to) {
    ln->next = to->next;
    ln->prev = to;
    if (to->next) {
        to->next->prev = ln;
    }
    to->next = ln;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/sl/alLink.s")
#endif

void func_8008BDDC(void) {
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void alUnlink(ALLink *ln) {
    if (ln->next) {
        ln->next->prev = ln->prev;
    }
    if (ln->prev) {
        ln->prev->next = ln->next;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/sl/alUnlink.s")
#endif
