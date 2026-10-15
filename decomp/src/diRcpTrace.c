#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
typedef struct DiRcpTraceEntry {
    u32 unk0;
    s32 unk4;
    s32 unk8;
} DiRcpTraceEntry;

MemoryPoolSlot *mmAlloc(s32 size, u32 colourTag);
extern DiRcpTraceEntry *D_800A64B0_A70B0[2];
extern s32 D_801012A0_B1750[2];
extern s32 D_800A64B8_A70B8;
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void diRcpTraceInit(void) {
    D_800A64B0_A70B0[0] = (DiRcpTraceEntry *) mmAlloc(0x600, 0xFFFFFF);
    D_800A64B0_A70B0[1] = (DiRcpTraceEntry *) mmAlloc(0x600, 0xFFFFFF);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/diRcpTrace/diRcpTraceInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void diRcpTraceReset(void) {
    s32 *p = &D_800A64B8_A70B8;
    s32 idx = 1 - *p;

    *p = idx;
    D_801012A0_B1750[idx] = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/diRcpTrace/diRcpTraceReset.s")
#endif

const char D_800AE670[] = "diRcpTrace: Buffer not allocated!\n";
const char D_800AE694[] = "diRcpTrace: Buffer overflow!\n";

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void diRcpTrace(s32 arg0, s32 arg1, s32 arg2) {
    s32 idx = D_800A64B8_A70B8;
    DiRcpTraceEntry *buf = D_800A64B0_A70B0[idx];
    s32 count;

    if (buf != NULL) {
        count = D_801012A0_B1750[idx];
        if (count < 0x80) {
            buf[count].unk0 = arg0;
            D_800A64B0_A70B0[D_800A64B8_A70B8][D_801012A0_B1750[D_800A64B8_A70B8]].unk4 = arg1;
            D_800A64B0_A70B0[D_800A64B8_A70B8][D_801012A0_B1750[D_800A64B8_A70B8]].unk8 = arg2;
            D_801012A0_B1750[D_800A64B8_A70B8] += 1;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/diRcpTrace/diRcpTrace.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void diRcpTraceGetInfo(u32 arg0, s32 *arg1, s32 *arg2, s32 *arg3, s32 *arg4, s32 *arg5, s32 *arg6) {
    s32 prev = 1 - D_800A64B8_A70B8;
    s32 count = D_801012A0_B1750[prev];
    DiRcpTraceEntry *buf = D_800A64B0_A70B0[prev];
    DiRcpTraceEntry *hitBefore = NULL; /* entry with the largest key <= arg0 */
    DiRcpTraceEntry *hitAfter = NULL;  /* entry with the smallest key > arg0 */
    u32 bestBefore = 0;
    u32 bestAfter = 0xFFFFFFFF;
    s32 i;

    for (i = 0; i < count; i++) {
        DiRcpTraceEntry *e = &buf[i];

        if (arg0 >= e->unk0) {
            if (bestBefore < e->unk0) {
                bestBefore = e->unk0;
                hitBefore = e;
            }
        } else if (e->unk0 < bestAfter) {
            bestAfter = e->unk0;
            hitAfter = e;
        }
    }

    if (hitBefore != NULL) {
        *arg1 = hitBefore->unk4;
        *arg2 = hitBefore->unk8;
        *arg3 = hitBefore->unk0;
    } else {
        *arg1 = 0;
    }
    if (hitAfter != NULL) {
        *arg4 = hitAfter->unk4;
        *arg5 = hitAfter->unk8;
        *arg6 = hitAfter->unk0;
        return;
    }
    *arg4 = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/diRcpTrace/diRcpTraceGetInfo.s")
#endif
