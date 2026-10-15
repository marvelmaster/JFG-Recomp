#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
typedef struct SubtitleLine {
    u8 unk0;        /* 0x00: line count in script block (decremented into D_80104578) */
    u8 unk1;        /* 0x01: colour R */
    u8 unk2;        /* 0x02: colour G */
    u8 unk3;        /* 0x03: colour B */
    u8 unk4;        /* 0x04: alpha */
    u8 unk5;        /* 0x05: font index */
    u8 unk6;        /* 0x06: alignment (1 = right, 4 = centre, other = left) */
    u8 unk7;        /* 0x07: display time (x6 for objTvTimes) */
    u8 text[];      /* 0x08: text, 0x80 flags a 2-byte code */
} SubtitleLine;

extern s32 piRomGetFileSize(s32 assetIndex);
extern s8 D_800A6FB0_A7BB0;
extern s32 D_800A6FB8_A7BB8;
extern u32 *D_80104560_B1750;
extern s16 D_80104564_B1754;
extern s16 D_80104566_B1756;
extern s16 D_80104568_B1758;
extern s16 D_8010456A_B175A;
extern s16 D_8010456C_B175C;
extern s16 D_8010456E_B175E;
extern s16 D_80104570_B1760;
extern s16 D_80104572_B1762;
extern s16 D_80104574_B1764;
extern s16 D_80104576_B1766;
extern s16 D_80104578_B1768;
extern SubtitleLine *D_80104580_B1770[];
extern u8 *D_80104588_B1778[2];
extern s32 D_80104594_B1784;
extern u8 *D_80104590_B1780;

extern s32 osTvType;
extern s16 objTvTimes(s32 arg0, s16 arg1);
extern s32 frontGetLanguage(void);
extern void fontWindowDisable(s32 window);
extern void fontWindowFlushStrings(s32 window);
extern void fontWindowEnable(s32 window);
extern void fontWindowSize(s32 window, s32 a, s32 b, s32 c, s32 d);
extern void fontWindowColour(s32 window, s32 r, s32 g, s32 b, s32 a);
extern void fontWindowFontBackground(s32 window, s32 r, s32 g, s32 b, s32 a);
extern void fontWindowFontColour(s32 window, s32 r, s32 g, s32 b, s32 a, s32 alpha);
extern void fontWindowUseFont(s32 window, s32 font);
extern void fontWindowAddStringXY(s32 window, s32 x, s32 y, void *str, s32 a, s32 align);
extern s32 piRomLoadSection(u32 assetIndex, u32 address, s32 assetOffset, s32 size);
extern void func_800741AC(void);
extern void func_80073F38(void);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void subtitlesInit(void) {
    u8 *buf;

    D_80104564_B1754 = (piRomGetFileSize(5) >> 2) - 2;
    buf = (u8 *) mmAlloc(0x790, 0xFF00FFU);
    D_80104588_B1778[0] = buf;
    D_80104588_B1778[1] = buf + 0x3C0;
    D_80104560_B1750 = (u32 *) (buf + 0x780);
    D_80104594_B1784 = 0;
    D_80104574_B1764 = 0;
    D_80104566_B1756 = 0;
    D_80104568_B1758 = 0x20;
    D_80104578_B1768 = 0;
    D_8010456C_B175C = 0x20;
    D_80104570_B1760 = 0x120;
    if (osTvType == 0) {
        D_8010456E_B175E = 0xE0;
        D_80104572_B1762 = 0xF8;
    } else {
        D_8010456E_B175E = 0xCA;
        D_80104572_B1762 = 0xDE;
    }
    D_800A6FB0_A7BB0 = 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/subtitles/subtitlesInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void subtitlesFree(void) {
    if (D_800A6FB0_A7BB0 != 0) {
        mmFree(D_80104588_B1778[0]);
        fontWindowDisable(6);
        fontWindowFlushStrings(6);
        D_800A6FB0_A7BB0 = 0;
        D_80104574_B1764 = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/subtitles/subtitlesFree.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void subtitlesEnable(s32 arg0) {
    D_800A6FB8_A7BB8 = arg0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/subtitles/subtitlesEnable.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80073F38(void) {
    s32 x;
    s32 y;
    s32 i;
    SubtitleLine *line;
    s32 lineX;

    fontWindowFlushStrings(6);
    fontWindowSize(6, D_8010456C_B175C, D_8010456E_B175E, D_80104570_B1760, D_80104572_B1762);
    fontWindowColour(6, 0, 0x60, 0, (D_80104566_B1756 * 0x64) >> 8);
    fontWindowFontBackground(6, 0, 0, 0, 0);
    y = (((D_80104572_B1762 - D_8010456E_B175E) - (D_80104576_B1766 * 0xC)) - (D_80104576_B1766 * 2) + 2) >> 1;
    for (i = 0; i < D_80104576_B1766; i++) {
        line = D_80104580_B1770[i];
        fontWindowUseFont(6, line->unk5);
        if (line->unk6 == 4) {
            lineX = (D_80104570_B1760 - D_8010456C_B175C) >> 1;
        } else if (line->unk6 == 1) {
            lineX = (D_80104570_B1760 - D_8010456C_B175C) - 8;
        } else {
            lineX = 8;
        }
        x = lineX;
        fontWindowFontColour(6, line->unk1, line->unk2, line->unk3, 0xFF, (line->unk4 * D_80104566_B1756) >> 8);
        fontWindowAddStringXY(6, x, y, line->text, 1, line->unk6);
        fontWindowFontColour(6, 0, 0, 0, 0xFF, (D_80104566_B1756 * 0xFF) >> 8);
        fontWindowAddStringXY(6, x + 1, y + 1, line->text, 1, line->unk6);
        y += 0xE;
    }
    fontWindowEnable(6);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/subtitles/func_80073F38.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_800741AC(void) {
    u8 *script;
    u8 *p;
    u8 c;
    s32 done;

    script = D_80104590_B1780;
    D_80104576_B1766 = 0;
    D_8010456A_B175A = 0;
    done = 0;
    c = script[0];
    while (c != 0 && done == 0) {
        D_80104578_B1768 = c - 1;
        D_80104580_B1770[D_80104576_B1766] = (SubtitleLine *) script;
        D_8010456A_B175A = objTvTimes(script[7] * 6, D_80104576_B1766);
        p = script + 8;
        D_80104590_B1780 = p;
        while (*p != 0) {
            p += (*p & 0x80) ? 2 : 1;
            D_80104590_B1780 = p;
        }
        D_80104576_B1766 += 1;
        if (D_80104576_B1766 >= 2) {
            done = 1;
        }
        p += 1;
        D_80104590_B1780 = p;
        c = p[0];
        if (c == 0xA) {
            p += 1;
            D_80104590_B1780 = p;
            c = p[0];
        } else if (c == 0xC) {
            p += 1;
            D_80104590_B1780 = p;
            c = p[0];
            done = 1;
        }
        script = p;
    }
    if (D_80104576_B1766 > 0) {
        D_80104574_B1764 = 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/subtitles/func_800741AC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void subtitlesTick(s32 arg0) {
    if (D_800A6FB0_A7BB0 != 0) {
        if (D_800A6FB8_A7BB8 == 0) {
            D_80104574_B1764 = 0;
        }
        if (D_80104574_B1764 != 0) {
            if (D_8010456A_B175A > 0) {
                D_80104566_B1756 += arg0 * D_80104568_B1758;
                if (D_80104566_B1756 >= 0x101) {
                    D_80104566_B1756 = 0x100;
                }
                D_8010456A_B175A -= arg0;
                if (D_8010456A_B175A <= 0) {
                    func_800741AC();
                }
            } else {
                D_80104566_B1756 -= arg0 * D_80104568_B1758;
                if (D_80104566_B1756 < 0) {
                    D_80104566_B1756 = 0;
                    D_80104574_B1764 = 0;
                    fontWindowDisable(6);
                    fontWindowFlushStrings(6);
                }
            }
        }
        if (D_80104574_B1764 != 0) {
            func_80073F38();
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/subtitles/subtitlesTick.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void subtitleStart(s32 arg0) {
    s32 idx = arg0;
    s32 lang;
    u32 *entry;
    u32 hdr;

    if ((D_800A6FB0_A7BB0 != 0) && (arg0 >= 0)) {
        if (arg0 < D_80104564_B1754) {
            lang = frontGetLanguage();
            switch (lang) {
                case 2:
                    idx += 0x30;
                    break;
                case 1:
                    idx += 0x2F;
                    break;
                case 3:
                    idx += 0x31;
                    break;
                case 4:
                    idx += 0x32;
                    break;
            }
            piRomLoadSection(5, (u32) D_80104560_B1750, (idx & ~1) * 4, 0x10);
            entry = &D_80104560_B1750[idx & 1];
            hdr = entry[0];
            piRomLoadSection(4, (u32) D_80104588_B1778[D_80104594_B1784],
                             hdr ^ (hdr & 0xFF000000),
                             (entry[1] & 0xFFFFFF) - (hdr & 0xFFFFFF));
            D_80104590_B1780 = D_80104588_B1778[D_80104594_B1784];
            func_800741AC();
            D_80104594_B1784 = (D_80104594_B1784 + 1) & 1;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/subtitles/subtitleStart.s")
#endif
