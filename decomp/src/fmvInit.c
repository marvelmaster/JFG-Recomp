#include "common.h"

typedef struct FmvPlayer {
    s32 unk0;
    u8 pad4[0x10];
    s32 unk14;
    s32 unk18;
    s32 unk1C;
    s32 unk20;
} FmvPlayer;

u32 *Table[2];
FmvPlayer Player[2];

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 fmvInit(void) {
    FmvPlayer *var_v1;
    s32 temp_v0;
    s32 var_a0;

    Table[0] = piRomLoad(0x45U);
    var_v1 = Player;
    var_a0 = 1;
    do {
        temp_v0 = var_a0;
        *(s8 *)&var_v1->unk0 = -1;
        var_v1->unk14 = 0;
        var_v1->unk18 = 0;
        var_v1->unk1C = 0;
        var_v1->unk20 = 0;
        var_v1 += 1;
        var_a0 -= 1;
    } while (var_a0 != 0);
    return temp_v0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/fmvInit/fmvInit.s")
#endif
