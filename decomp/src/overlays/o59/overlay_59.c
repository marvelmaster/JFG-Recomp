#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
typedef struct CreditsEntry {
    s32 unk0;
    s16 unk4;
    s16 unk6;
    s16 unk8;
    u8 unkA;
    u8 unkB;
} CreditsEntry;

void amSndPlay(u16 soundID, void *handlePtr);
void fontColour(s32 red, s32 green, s32 blue, s32 alpha, s32 opacity);
void fontPrintXY(Gfx **displayList, s16 xpos, s16 ypos, char *text, s32 alignmentFlags);
void fontUseFont(s32 font);
void mainTitlePageInit(s16 arg0, s32 arg1, s32 arg2, s16 arg3);
extern Gfx *frontgfx;
extern s16 D_overlay_59_03B0077C[];
extern s16 D_overlay_59_03B00780[];
extern s32 D_overlay_59_03B00570[];
extern s16 D_overlay_59_03B006C4[];
extern CreditsEntry D_overlay_59_03B00BC0[5];
extern s16 D_overlay_59_03B00BFC;
extern s16 *D_overlay_59_03B00C00;
extern s16 D_overlay_59_03B00C04;
extern s16 D_overlay_59_03B00C06;
extern u8 D_overlay_59_03B00C08;
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *frontCreditsInit(void) {
    s32 i;

    D_overlay_59_03B00BC0[0].unk0 = 0;
    D_overlay_59_03B00BC0[0].unk4 = 0;
    D_overlay_59_03B00BC0[0].unkA = 0;
    D_overlay_59_03B00BC0[0].unk6 = D_overlay_59_03B0077C[0];
    D_overlay_59_03B00BC0[0].unk8 = D_overlay_59_03B00780[0];
    for (i = 1; i < 5; i++) {
        D_overlay_59_03B00BC0[i].unk0 = 0;
        D_overlay_59_03B00BC0[i].unk4 = 0;
        D_overlay_59_03B00BC0[i].unkA = 0;
        D_overlay_59_03B00BC0[i].unk6 = D_overlay_59_03B0077C[i & 1];
        D_overlay_59_03B00BC0[i].unk8 = D_overlay_59_03B00780[i];
    }
    D_overlay_59_03B00BFC = 0;
    D_overlay_59_03B00C04 = 0;
    D_overlay_59_03B00C06 = 0;
    D_overlay_59_03B00C00 = D_overlay_59_03B006C4;
    D_overlay_59_03B00C08 = 0;
    return &D_overlay_59_03B00BC0[4];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o59/overlay_59/frontCreditsInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void frontCredits(s32 arg0) {
    CreditsEntry *entry;
    CreditsEntry *d;
    s32 var_a1;
    s32 var_s1;
    s32 var_s1_2;
    s32 var_s1_3;
    s32 temp_v0;
    s32 temp_v0_2;
    s16 var_a3;
    s16 temp_a0;
    s16 idx;
    s16 *ptr;

    var_a1 = 1;
    for (var_s1 = 0; var_s1 < 5; var_s1++) {
        entry = &D_overlay_59_03B00BC0[var_s1];
        if (entry->unk0 != 0) {
            if (entry->unk4 > 0) {
                temp_v0 = arg0 * 8;
                if (entry->unkA == 0) {
                    entry->unk4 = (s16)(entry->unk4 - arg0);
                    var_a1 = 0;
                }
                if (var_s1 & 1) {
                    entry->unk6 = (s16)(entry->unk6 - temp_v0);
                    if (entry->unk6 < 0xA0) {
                        entry->unk6 = 0xA0;
                    }
                } else {
                    entry->unk6 = (s16)(entry->unk6 + temp_v0);
                    if (entry->unk6 >= 0xA1) {
                        entry->unk6 = 0xA0;
                    }
                }
            } else if (entry->unkA == 0) {
                temp_v0_2 = arg0 * 8;
                if (var_s1 & 1) {
                    entry->unk6 = (s16)(entry->unk6 + temp_v0_2);
                    if (entry->unk6 >= 0x17D) {
                        entry->unk6 = 0x17C;
                        entry->unk0 = 0;
                    } else {
                        var_a1 = 0;
                    }
                } else {
                    entry->unk6 = (s16)(entry->unk6 - temp_v0_2);
                    if (entry->unk6 < -0x3C) {
                        entry->unk6 = -0x3C;
                        entry->unk0 = 0;
                    } else {
                        var_a1 = 0;
                    }
                }
            }
        }
    }

    var_a3 = D_overlay_59_03B00C06;
    if (var_a3 == 0) {
        D_overlay_59_03B00BFC = (s16)(D_overlay_59_03B00BFC - arg0);
        if (D_overlay_59_03B00BFC <= 0) {
            temp_a0 = D_overlay_59_03B00C00[0];
            if (temp_a0 == -4) {
                D_overlay_59_03B00C06 = 1;
                mainTitlePageInit(temp_a0, var_a1, 1, var_a3);
                var_a3 = D_overlay_59_03B00C06;
            } else if (temp_a0 == -3) {
                D_overlay_59_03B00C00 = D_overlay_59_03B00C00 + 1;
                idx = D_overlay_59_03B00C00[0];
                D_overlay_59_03B00BC0[idx].unkA = 0;
                D_overlay_59_03B00BC0[idx].unk4 = 0;
                D_overlay_59_03B00C00 = D_overlay_59_03B00C00 + 1;
            } else if (temp_a0 == -1) {
                if (var_a1 != 0) {
                    amSndPlay(0x1C4, 0);
                    D_overlay_59_03B00C08 = 0;
                    D_overlay_59_03B00C00 = D_overlay_59_03B00C00 + 1;
                    var_s1_2 = D_overlay_59_03B00C00[0];
                    D_overlay_59_03B00C00 = D_overlay_59_03B00C00 + 1;
                    D_overlay_59_03B00BFC = D_overlay_59_03B00C00[0];
                    D_overlay_59_03B00C00 = D_overlay_59_03B00C00 + 1;
                    if (var_s1_2 != 0) {
                        entry = &D_overlay_59_03B00BC0[0];
                        do {
                            if (entry->unk0 == 0) {
                                var_s1_2 -= 1;
                                entry->unk0 = D_overlay_59_03B00570[D_overlay_59_03B00C04];
                                D_overlay_59_03B00C04 += 1;
                                entry->unk4 = D_overlay_59_03B00BFC;
                            }
                            entry += 1;
                        } while (var_s1_2 != 0);
                    }
                    if (D_overlay_59_03B00C00[0] == -2) {
                        do {
                            ptr = D_overlay_59_03B00C00 + 1;
                            D_overlay_59_03B00C00 = ptr;
                            idx = ptr[0];
                            D_overlay_59_03B00BC0[idx].unkA = 1;
                            D_overlay_59_03B00C00 = ptr + 1;
                        } while (D_overlay_59_03B00C00[0] == -2);
                    }
                    var_a3 = D_overlay_59_03B00C06;
                } else if (D_overlay_59_03B00C08 == 0) {
                    amSndPlay(0x1C4, 0);
                    D_overlay_59_03B00C08 = 1;
                    var_a3 = D_overlay_59_03B00C06;
                }
            }
        }
    }

    if (var_a3 == 0) {
        fontUseFont(2);
        for (var_s1_3 = 0; var_s1_3 < 5; var_s1_3++) {
            d = &D_overlay_59_03B00BC0[var_s1_3];
            if (d->unk0 != 0) {
                fontColour(0, 0, 0, 0xFF, 0xFF);
                fontPrintXY(&frontgfx, d->unk6, d->unk8, (char *)d->unk0, 0xC);
                fontColour(0xFF, 0xFF, 0xFF, 0xFF, 0xFF);
                fontPrintXY(&frontgfx, d->unk6 + 1, d->unk8 + 1, (char *)d->unk0, 0xC);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o59/overlay_59/frontCredits.s")
#endif
