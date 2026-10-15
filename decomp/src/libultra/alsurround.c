#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern u8 D_80105010_B1750;
extern u8 D_80105011_B1751;
extern u8 D_80105012_B1752;
extern u8 D_80105014_B1754[];
extern u8 D_80105016_B1756[];
extern u8 D_80105018_B1758[];
void alSurround_ReverbSetup(s32 arg0, u8 arg1);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void alSurround_OutputType(u8 arg0) {
    s32 i;

    D_80105010_B1750 = 0;
    D_80105011_B1751 = 0;
    D_80105012_B1752 = 0;
    switch (arg0) {
    case 1:
        D_80105011_B1751 = 1;
        break;
    case 3:
        D_80105012_B1752 = 1;
        break;
    case 4:
        D_80105010_B1750 = 1;
        break;
    }
    for (i = 0; i < 2; i++) {
        alSurround_ReverbSetup(i, 0);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/alsurround/alSurround_OutputType.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void alSurround_ReverbSetup(s32 arg0, u8 arg1) {
    u8 var;

    var = arg1;
    if (var == 0) {
        var = D_80105018_B1758[arg0];
    }
    D_80105014_B1754[arg0] = 0;
    D_80105016_B1756[arg0] = 0;
    switch (var) {
    case 2:
        if (D_80105010_B1750 != 0) {
            D_80105016_B1756[arg0] = 1;
        }
        break;
    case 3:
        if (D_80105010_B1750 != 0) {
            D_80105014_B1754[arg0] = 1;
        }
        break;
    case 4:
        if (D_80105011_B1751 == 0) {
            D_80105014_B1754[arg0] = 1;
        }
        break;
    case 5:
        if (D_80105011_B1751 == 0) {
            D_80105014_B1754[arg0] = 1;
            D_80105016_B1756[arg0] = 1;
        }
        break;
    }
    D_80105018_B1758[arg0] = var;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/alsurround/alSurround_ReverbSetup.s")
#endif
