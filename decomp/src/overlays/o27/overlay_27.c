#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
extern MemoryPoolSlot *D_overlay_27_01B00440;
extern s32 D_overlay_27_01B00444;
extern s32 D_overlay_27_01B00448;

s32 func_overlay_27_01B00000_1F45710(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_27_01B00000_1F45710(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s8 *out = (s8 *)arg0;
    s32 a1 = arg1 << 6;
    s32 a2 = arg2 << 6;
    s32 a3 = arg3 << 6;
    s32 d1 = arg4 - arg1;
    s32 d2 = arg5 - arg2;
    s32 d3 = arg6 - arg3;
    s32 i;

    for (i = 0; i < 64; i++) {
        out[0] = (s8)(a1 >> 6);
        out[1] = (s8)(a2 >> 6);
        out[2] = (s8)(a3 >> 6);
        a1 += d1;
        a2 += d2;
        a3 += d3;
        out += 3;
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o27/overlay_27/func_overlay_27_01B00000_1F45710.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void underWaterLightsInit(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *slot;

    slot = (u8 *)mmAlloc(0x300, -1U);
    D_overlay_27_01B00440 = (MemoryPoolSlot *)slot;
    if (slot != NULL) {
        func_overlay_27_01B00000_1F45710(slot, obj[0xFE], obj[0xFF], obj[0x100], obj[0xFB], obj[0xFC], obj[0xFD]);
        func_overlay_27_01B00000_1F45710(slot + 0xC0, obj[0xFB], obj[0xFC], obj[0xFD], obj[0xF8], obj[0xF9], obj[0xFA]);
        func_overlay_27_01B00000_1F45710(slot + 0x180, obj[0xF8], obj[0xF9], obj[0xFA], obj[0xFB], obj[0xFC], obj[0xFD]);
        func_overlay_27_01B00000_1F45710(slot + 0x240, obj[0xFB], obj[0xFC], obj[0xFD], obj[0xFE], obj[0xFF], obj[0x100]);
        D_overlay_27_01B00448 = 0;
        D_overlay_27_01B00444 = obj[0xF7];
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o27/overlay_27/underWaterLightsInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void _AutoExit00027(void) {
    if (D_overlay_27_01B00440 != NULL) {
        mmFree(D_overlay_27_01B00440);
        D_overlay_27_01B00440 = NULL;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o27/overlay_27/_AutoExit00027.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void underWaterLightsUpdate(u8 *arg0, void *arg1, s32 arg2) {
    u8 *table = (u8 *) D_overlay_27_01B00440;
    u8 *flags = arg0;
    u8 *ent;
    s32 count;
    s32 phase;
    s32 i;

    if (table == NULL) {
        return;
    }

    phase = (D_overlay_27_01B00448 + arg2) & 0xFF;
    D_overlay_27_01B00448 = phase;
    ent = *(u8 **) ((u8 *) arg1 + 0x04);
    count = *(s16 *) ((u8 *) arg1 + 0x1A);

    for (i = 0; i < count; i++) {
        u8 *e = ent + i * 0x48;
        u8 *cols;
        u8 *src;
        u8 *vt;
        s16 *clear;
        s32 n;
        s32 nv;
        s32 j;

        if (flags[i] == 0) {
            continue;
        }

        cols = *(u8 **) (e + 0x34);
        if (cols != NULL) {
            clear = *(s16 **) (cols + 0x04);
            n = (*(s16 *) (e + 0x24) + 0xF) >> 4;
            for (j = 0; j < n; j++) {
                clear[j] = 0;
            }

            src = *(u8 **) cols;
            vt = *(u8 **) e;
            nv = *(s16 *) (e + 0x24);
            if (D_overlay_27_01B00444 == 1) {
                for (j = 0; j < nv; j++) {
                    s32 idx = (*(s16 *) (vt + 0x4) + *(s16 *) (vt + 0x0) + *(s16 *) (vt + 0x2) + phase) & 0xFF;
                    u8 *t = table + idx * 3;

                    vt[6] = (u8) ((t[0] * src[0]) >> 8);
                    vt[7] = (u8) ((t[1] * src[1]) >> 8);
                    vt[8] = (u8) ((t[2] * src[2]) >> 8);
                    src += 3;
                    vt += 0xA;
                }
            } else {
                for (j = 0; j < nv; j++) {
                    s32 idx = (*(s16 *) (vt + 0x4) + *(s16 *) (vt + 0x0) + *(s16 *) (vt + 0x2) + phase) & 0xFF;
                    u8 *t = table + idx * 3;

                    vt[6] = (t[0] < src[0]) ? src[0] : t[0];
                    vt[7] = (t[1] < src[1]) ? src[1] : t[1];
                    vt[8] = (t[2] < src[2]) ? src[2] : t[2];
                    src += 3;
                    vt += 0xA;
                }
            }
        }
        e[0x32] = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o27/overlay_27/underWaterLightsUpdate.s")
#endif
