#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern s8 D_800F2D59;
extern s8 D_800F2D5A;
extern s8 D_800F2D5B;
extern s16 D_800F2D5C;
extern s16 D_800F2D5E;
extern s16 D_800F2D62;
extern s16 D_800F2D66;
extern u8 D_800F2D68[];
extern s32 explosionNoTypes;
extern u32 *explosionTypeData;
extern MemoryPoolSlot *explosionTypes;
extern s8 swpolygons;
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *objInitExplosions(void) {
    u32 *table;
    u32 *idxp;
    u8 *obj;
    u8 *base;
    u8 *p;
    u8 *rec;
    s32 idx;
    s32 v1;
    s32 i;
    s32 cnt;
    s32 t1 = 0;
    s32 t2 = 0;
    s32 k;

    table = piRomLoad(0x3FU);
    explosionNoTypes = 0;
    v1 = 0;
    if (table[0] != (u32) -1) {
        idx = 1;
        do {
            explosionNoTypes = idx;
            v1 = idx;
            idx++;
        } while (table[idx - 1] != (u32) -1);
    }
    explosionNoTypes = v1 - 1;

    explosionTypeData = piRomLoad(0x40U);
    explosionTypes = mmAlloc(explosionNoTypes * 4, 0xC0C040FFU);

    if (explosionNoTypes > 0) {
        idxp = table;
        do {
            obj = (u8 *) explosionTypeData + *idxp;
            *(u8 **) ((u8 *) explosionTypes + t2) = obj;

            *(u8 **) (obj + 0x0C) = obj + *(u32 *) (obj + 0x0C);
            *(u8 **) (obj + 0x10) = obj + *(u32 *) (obj + 0x10);
            *(u8 **) (obj + 0x14) = obj + *(u32 *) (obj + 0x14);
            *(u8 **) (obj + 0x18) = obj + *(u32 *) (obj + 0x18);
            *(u8 **) (obj + 0x1C) = obj + *(u32 *) (obj + 0x1C);
            *(u8 **) (obj + 0x20) = obj + *(u32 *) (obj + 0x20);
            *(u8 **) (obj + 0x24) = obj + *(u32 *) (obj + 0x24);
            *(u8 **) (obj + 0x28) = obj + *(u32 *) (obj + 0x28);

            *(s16 *) (obj + 0x00) = 0x4B;
            obj[0x03] = 0;
            obj[0x02] = 0x58;

            rec = *(u8 **) (obj + 0x18);
            cnt = obj[0x31];
            for (i = 0; i < cnt; i++) {
                *(s16 *) rec = 0x73;
                rec[2] = 0x22;
                rec[3] = 0;
                rec += 0x22;
            }

            rec = *(u8 **) (obj + 0x28);
            t1 += 1;
            cnt = obj[0x32];
            for (i = 0; i < cnt; i++) {
                *(s16 *) rec = 0x80;
                rec[2] = 0x1C;
                rec[3] = 0;
                rec += 0x1C;
            }

            t2 += 4;
            idxp++;
        } while (t1 < explosionNoTypes);
    }
    mmFree(table);

    D_800F2D59 = 0;
    D_800F2D5A = 3;
    D_800F2D5B = 1;
    D_800F2D5C = 0;
    D_800F2D5E = 0x400;
    D_800F2D62 = 0;
    D_800F2D66 = 0;
    swpolygons = 0x40;

    base = D_800F2D68;
    base[3] = 3;
    base[2] = 2;
    *(s16 *) (base + 0x08) = 0x800;
    base[0] = 0x40;
    *(s16 *) (base + 0x0E) = 0;
    *(s16 *) (base + 0x0A) = 0x400;
    *(s16 *) (base + 0x06) = 0x400;
    *(s16 *) (base + 0x04) = 0;
    base[1] = 0;

    p = base + 0x10;
    k = 2;
    do {
        *(s16 *) (p + 0x04) = 0x800;
        *(s16 *) (p + 0x14) = 0x800;
        *(s16 *) (p + 0x18) = 0;
        p[0x03] = k + 1;
        p[0x01] = k;
        p[0x11] = k;
        p[0x72] = k + 8;
        p[0x62] = k + 9;
        p[0x73] = k + 9;
        p[0x21] = k + 2;
        p[0x31] = k + 2;
        p[0x23] = k + 3;
        p[0x52] = k + 6;
        p[0x61] = k + 6;
        p[0x71] = k + 6;
        p[0x42] = k + 7;
        p[0x53] = k + 7;
        p[0x63] = k + 7;
        p[0x32] = k + 4;
        p[0x41] = k + 4;
        p[0x51] = k + 4;
        p[0x22] = k + 5;
        p[0x33] = k + 5;
        p[0x43] = k + 5;
        *(s16 *) (p + 0x38) = 0x800;
        *(s16 *) (p + 0x44) = 0x800;
        *(s16 *) (p + 0x54) = 0x800;
        *(s16 *) (p + 0x78) = 0x800;
        *(s16 *) (p + 0x24) = 0;
        *(s16 *) (p + 0x34) = 0;
        *(s16 *) (p + 0x58) = 0;
        *(s16 *) (p + 0x64) = 0;
        *(s16 *) (p + 0x74) = 0;
        *(s16 *) (p + 0x26) = 0x400;
        *(s16 *) (p + 0x2A) = 0;
        *(s16 *) (p + 0x2E) = 0;
        p[0x20] = 0x40;
        *(s16 *) (p + 0x36) = 0x400;
        *(s16 *) (p + 0x3A) = 0x400;
        *(s16 *) (p + 0x3E) = 0;
        p[0x30] = 0x40;
        *(s16 *) (p + 0x46) = 0x400;
        *(s16 *) (p + 0x4A) = 0;
        *(s16 *) (p + 0x4E) = 0;
        p[0x40] = 0x40;
        *(s16 *) (p + 0x56) = 0x400;
        *(s16 *) (p + 0x5A) = 0x400;
        *(s16 *) (p + 0x5E) = 0;
        p[0x50] = 0x40;
        *(s16 *) (p + 0x66) = 0x400;
        *(s16 *) (p + 0x6A) = 0;
        *(s16 *) (p + 0x6E) = 0;
        p[0x60] = 0x40;
        *(s16 *) (p + 0x76) = 0x400;
        *(s16 *) (p + 0x7A) = 0x400;
        *(s16 *) (p + 0x7E) = 0;
        p[0x70] = 0x40;
        p += 0x80;

        p[-0x7E] = k + 3;
        *(s16 *) (p - 0x7A) = 0x400;
        *(s16 *) (p - 0x76) = 0;
        *(s16 *) (p - 0x72) = 0;
        p[-0x80] = 0x40;
        p[-0x6E] = k + 2;
        p[-0x6D] = k + 3;
        *(s16 *) (p - 0x6A) = 0x400;
        *(s16 *) (p - 0x66) = 0x400;
        *(s16 *) (p - 0x62) = 0;
        p[-0x70] = 0x40;

        k += 8;
    } while (k != 0x12);

    p[0x01] = (u8) k;
    p[0x02] = 1;
    p[0x03] = (u8) (k + 1);
    *(s16 *) (p + 0x04) = 0;
    *(s16 *) (p + 0x06) = 0x400;
    *(s16 *) (p + 0x0A) = 0;
    *(s16 *) (p + 0x0E) = 0;
    p[0x00] = 0x40;
    p[0x11] = (u8) k;
    p[0x12] = 0;
    p[0x13] = 1;
    *(s16 *) (p + 0x14) = 0;
    *(s16 *) (p + 0x16) = 0x400;
    *(s16 *) (p + 0x18) = 0x800;
    *(s16 *) (p + 0x1A) = 0x400;
    *(s16 *) (p + 0x1E) = 0;
    p[0x10] = 0x40;

    return (void *) (base + 0x120);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o33/overlay_33/objInitExplosions.s")
#endif
