#include "common.h"

const char D_800ADF00[] = "SCREEN: No out of range!!\n";

/* decomp: externs */
#ifdef NON_MATCHING
extern u8 D_800A4F20_A5B20[];
extern u8 D_800A4F48_A5B48[];
extern u32 D_800A4F70_A5B70;
extern u8 D_A4F78[];
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
MemoryPoolSlot *screenLoad(s32 arg0) {
    u32 *table;
    u32 *p;
    u32 *entry;
    s32 count;
    s32 gaps;
    s32 offset;
    s32 romStart;
    s32 romSize;
    s32 outSize;
    s32 tmp;
    MemoryPoolSlot *out;
    MemoryPoolSlot *hdr;

    table = piRomLoad(0x14U);
    p = table;
    count = 0;
    if (*p != -1U) {
        do {
            count += 1;
            p += 4;
        } while (p[1] != -1);
    }
    gaps = count - 1;
    if (gaps == 0) {
        mmFree(table);
        return (MemoryPoolSlot *) 0x80100000;
    }
    if ((arg0 < 0) || (arg0 >= gaps)) {
        offset = 0;
    } else {
        offset = arg0 * 4;
    }
    entry = (u32 *) ((u8 *) table + offset);
    romStart = entry[0];
    out = NULL;
    romSize = entry[1] - romStart;
    hdr = mmAlloc(0x10, 0xFFFFU);
    if (hdr != NULL) {
        piRomLoadSection(0x13U, (u32) hdr, romStart, 0x10);
        outSize = rzipUncompressSize((u8 *) hdr) + 0x80;
        mmFree(hdr);
        out = mmAlloc(outSize, 0xFFFFU);
        if (out != NULL) {
            tmp = ((s32) out + outSize) - romSize;
            tmp = tmp - (tmp & 0xF);
            piRomLoadSection(0x13U, (u32) tmp, romStart, romSize);
            rzipUncompress((u8 *) tmp, (u8 *) out);
        }
    }
    mmFree(table);
    return out;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/screen/screenLoad.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void screenDraw(Gfx **arg0, s32 arg1, s32 arg2) {
    s32 w;
    s32 h;
    u32 var_s0;
    s32 var_a1;
    s32 var_t0;
    s32 var_ra;
    s32 temp_t0;
    s32 var_a2;
    u32 var_t1;
    u32 var_s1;
    u32 var_s2;
    Gfx *cmd;
    Gfx *e1;
    Gfx *e2;
    Gfx *e3;
    Gfx *e4;
    Gfx *e5;

    var_s0 = arg1 + 0x10;
    viGetCurrentSize(&w, &h);
    var_a2 = 0;
    if (((w != 0x140) || (h != 0xF0)) && (arg2 != 0)) {
        cmd = *arg0;
        var_ra = w * 4;
        var_a1 = 0;
        var_t0 = 0;
        var_t1 = (u32) (h << 0x10) / 40U;
        *arg0 = cmd + 1;
        cmd->words.w0 = 0x06000000;
        var_s1 = 0x50000U / (u32) w;
        cmd->words.w1 = (u32) D_800A4F48_A5B48;
        var_s2 = 0x3C000U / (u32) h;
    } else {
        cmd = *arg0;
        var_a1 = (h - 0xF0) << 0xF;
        var_t0 = (w - 0x140) * 2;
        *arg0 = cmd + 1;
        var_t1 = 0x60000;
        var_ra = var_t0 + 0x500;
        var_s1 = 0x400;
        var_s2 = 0x400;
        cmd->words.w0 = 0x06000000;
        cmd->words.w1 = (u32) D_800A4F20_A5B20;
    }
    do {
        temp_t0 = var_a1 + var_t1;
        e1 = *arg0;
        e1->words.w0 = D_800A4F70_A5B70;
        var_a2 += 6;
        e1->words.w1 = var_s0;
        var_s0 += 0xF00;
        e2 = e1 + 1;
        e2->words.w0 = 0x07060030;
        e2->words.w1 = (u32) D_A4F78;
        e3 = e2 + 1;
        e3->words.w1 = (((var_t0 & 0xFFF) << 0xC) | ((var_a1 >> 0xE) & 0xFFF));
        e3->words.w0 = ((var_ra & 0xFFF) << 0xC) | 0xE4000000 | ((temp_t0 >> 0xE) & 0xFFF);
        var_a1 = temp_t0;
        e4 = e3 + 1;
        e4->words.w1 = 0;
        e4->words.w0 = 0xB3000000;
        e5 = e4 + 1;
        e5->words.w1 = ((var_s1 << 0x10) | (var_s2 & 0xFFFF));
        e5->words.w0 = 0xB2000000;
        *arg0 = e5 + 1;
    } while (var_a2 != 0xF0);
    texDPInit(arg0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/screen/screenDraw.s")
#endif
