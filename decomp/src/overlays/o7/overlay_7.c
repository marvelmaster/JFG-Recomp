#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
typedef struct HintCacheSlot {
    s32 id;
    void *data;
} HintCacheSlot;

typedef struct HintQueueEntry {
    s16 unk0;
    s16 unk2;
    void *unk4;
} HintQueueEntry;

typedef struct HintEntry {
    u8 unk0;
    u8 unk1;
    u8 unk2;
    u8 unk3;
    s16 unk4;
    s16 unk6;
} HintEntry;

typedef struct HintListEntry {
    s16 unk0;
    s16 unk2;
    s32 unk4;
    s16 unk8;
    s16 unkA;
    s16 unkC;
    s16 unkE;
} HintListEntry;

extern s32 D_overlay_7_00702A20;
extern s32 D_overlay_7_00702A24;
extern s32 D_overlay_7_00702A28;
extern s32 D_overlay_7_00702A2C;
extern s32 D_overlay_7_00702A30;
extern s32 D_overlay_7_00702A34;
extern s32 D_overlay_7_00702A38;
extern s32 D_overlay_7_00702A3C;
extern s32 D_overlay_7_00702A40;
extern s32 D_overlay_7_00702A44;
extern s32 D_overlay_7_00702A48;
extern s32 D_overlay_7_00702A4C;
extern void *D_overlay_7_00702A50;
extern void *D_overlay_7_00702A54;
extern void *D_overlay_7_00702A58;
extern void *D_overlay_7_00702A5C;
extern s32 D_overlay_7_00702A64;
extern s32 D_overlay_7_00702A68;
extern s32 D_overlay_7_00702A6C;
extern s32 D_overlay_7_00702A70;
extern s32 D_overlay_7_00702A74;
extern s32 D_overlay_7_00702A78[12];
extern HintCacheSlot D_overlay_7_00702C58[32];
extern s32 D_overlay_7_00702C5C;
extern HintQueueEntry D_overlay_7_00702D58[16];
extern u8 D_overlay_7_00702A04[];
extern u8 D_overlay_7_00702A14[];

void hinttextFreeObject(void);
void mrHintsTalk(void);
void func_overlay_7_00700DF0_1EFBF18(void);
s32 func_overlay_7_007012E0_1EFC408(s16 arg0);
s32 mainGetGameFlag(s32 flag);
void mmFree(void *data);
MemoryPoolSlot *mmAlloc(s32 size, u32 colourTag);
s32 func_overlay_7_00700390_1EFB4B8(s32 arg0, s32 arg1);
void *func_overlay_7_00700B00_1EFBC28(s32 arg0, s32 arg1, s32 arg2);
void *func_overlay_7_00700988_1EFBAB0(s32 arg0, s32 arg1);
void *func_overlay_7_00700578_1EFB6A0(s32 arg0, s32 arg1);
void func_overlay_7_0070070C_1EFB834(void);
s32 func_overlay_7_007007E4_1EFB90C(s32 arg0);
MemoryPoolSlot *func_overlay_7_00700C90_1EFBDB8(s32 arg0, u32 arg1);
typedef struct HintRect {
    s16 x0;
    s16 y0;
    s16 x1;
    s16 y1;
    s32 scale;
} HintRect;

extern s32 D_overlay_7_00702C30;
extern s32 D_overlay_7_00702C34;
extern s32 D_overlay_7_00702C38;
extern s32 D_overlay_7_00702C3C;
extern s32 D_overlay_7_00702C40;
extern s32 D_overlay_7_00702C44;
extern s32 D_overlay_7_00702C48;
extern s32 D_overlay_7_00702C4C;
extern s32 D_overlay_7_00702C50;
extern s8 D_overlay_7_00702960[];
extern char D_overlay_7_00702ADC[];
extern char D_overlay_7_00702AE0[];
extern char D_overlay_7_00702AE4[];

s32 mainPlayerHas(s32 arg0, s32 arg1, s32 arg2);
s32 mainAnyoneHas(s32 arg0);
void mainPlayerCollected(s32 arg0, s32 arg1, s32 arg2);
void mainPlayerDropped(s32 arg0, s32 arg1, s32 arg2);
void *mainGetGameCharacter(s8 arg0, s8 arg1);
void *objGetPlayerNo(s32 player);
void *controlGetWeaponDef(s32 arg0);
void amTunePlay(s32 seqID);
void amTuneStop(void);
s32 amTuneGetSeqNo(void);
void fontBackground(s32 red, s32 green, s32 blue, s32 alpha);
void fontPrintXY(s32 displayList, s32 xpos, s32 ypos, char *text, s32 alignmentFlags);
u8 *fontGetLine(s32 font, u8 *text, s32 width, char **line);
s32 fontYSpacing(s32 font);
void fontSetButtonMode(s32 mode);
void frontDrawRectangles(s32 gfxp, s32 count, void *rects, s32 flag);
void func_overlay_7_00701F80_1EFD0A8(s32 arg0);
void func_overlay_7_007020D4_1EFD1FC(s32 arg0);
void func_overlay_7_007016B4_1EFC7DC(void);
void func_overlay_7_007017E8_1EFC910(s32 arg0);
s32 func_overlay_7_007023D4_1EFD4FC(s32 arg0, void *arg1, s32 arg2);
void *objSetupObject(void *setup, s32 arg1);
void controlSetPlayerSetup(s16 arg0, s16 arg1, s16 arg2, s16 arg3);
s32 frontGetMode(void);
s32 mainGetNextCharacter(void);
extern void *D_overlay_7_00702A60;
typedef struct HintObjSetup {
    s16 id;
    u8 unk2;
    u8 unk3;
    s16 x;
    s16 y;
    s16 z;
    s8 w;
    s8 unkB;
    f32 scale;
} HintObjSetup;
/* decomp: end externs */
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hinttextFree(void) {
    s32 i;

    hinttextFreeObject();
    D_overlay_7_00702A64 = -1;
    D_overlay_7_00702A68 = -1;
    D_overlay_7_00702A6C = 0;
    D_overlay_7_00702A74 = 0;
    if (D_overlay_7_00702A50 != NULL) {
        mmFree(D_overlay_7_00702A50);
    }
    if (D_overlay_7_00702A54 != NULL) {
        mmFree(D_overlay_7_00702A54);
    }
    for (i = 0; i < 32; i++) {
        if (D_overlay_7_00702A48 != 0 && D_overlay_7_00702C58[i].data != NULL) {
            mmFree(D_overlay_7_00702C58[i].data);
        }
        D_overlay_7_00702C58[i].id = -1;
        D_overlay_7_00702C58[i].data = NULL;
    }
    D_overlay_7_00702A48 = 0;
    D_overlay_7_00702A4C = 0;
    D_overlay_7_00702A20 = 0;
    D_overlay_7_00702A24 = 0;
    D_overlay_7_00702A28 = 0;
    D_overlay_7_00702A30 = -1;
    D_overlay_7_00702A34 = -1;
    D_overlay_7_00702A38 = 0;
    D_overlay_7_00702A3C = 0;
    D_overlay_7_00702A40 = 0;
    D_overlay_7_00702A50 = NULL;
    D_overlay_7_00702A54 = NULL;
    D_overlay_7_00702A58 = NULL;
    D_overlay_7_00702A5C = NULL;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/hinttextFree.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hinttextStart(s32 arg0, s32 arg1) {
    s32 i;
    s32 lang;
    s32 idx;
    s32 remaining;
    s32 a1;
    s32 v1;
    u8 *item;
    HintEntry *entry;

    hinttextFree();
    if (arg0 >= 0 && arg0 < 0x2D) {
        D_overlay_7_00702A6C = arg1;
        D_overlay_7_00702A50 = piRomLoad(8);
        lang = frontGetLanguage();
        switch (lang) {
        case 1:
            idx = 0xB;
            break;
        case 2:
            idx = 0xD;
            break;
        case 3:
            idx = 0xF;
            break;
        case 4:
            idx = 0x11;
            break;
        default:
            idx = 9;
            break;
        }
        D_overlay_7_00702A54 = piRomLoad(idx);

        /* each item: s16 count, then count entries of 8 bytes at +2 */
        item = (u8 *)D_overlay_7_00702A50;
        for (i = 0; i < arg0; i++) {
            item += *(s16 *)item * 8 + 2;
        }

        remaining = *(s16 *)item - 1;
        entry = (HintEntry *)(item + 2);
        while (remaining != 0) {
            /* the asm leaves a1 clobbered by the calls above, so 0 is passed here */
            a1 = func_overlay_7_00700390_1EFB4B8(entry->unk0 & 0x7F, 0);
            if (entry->unk0 & 0x80) {
                a1 = (a1 == 0);
            }
            v1 = func_overlay_7_00700390_1EFB4B8(entry->unk2 & 0x7F, a1);
            if (entry->unk2 & 0x80) {
                v1 = (v1 == 0);
            }
            if (entry->unk1 == 0) {
                if (a1 != 0 && v1 != 0) {
                    break;
                }
            } else if (entry->unk1 == 1) {
                if (a1 != 0 || v1 != 0) {
                    break;
                }
            } else if (a1 != 0) {
                break;
            }
            entry++;
            remaining--;
        }

        D_overlay_7_00702A70 = entry->unk6;
        D_overlay_7_00702A74 = entry->unk3;
        if (func_overlay_7_00700578_1EFB6A0(entry->unk4, 3) != NULL) {
            D_overlay_7_00702A24 = 1;
        }
        func_overlay_7_00700DF0_1EFBF18();
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/hinttextStart.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_7_0070032C_1EFB454(void) {
    s32 count = 0;
    s32 i;

    for (i = 0; i < 12; i++) {
        if (mainGetGameFlag(D_overlay_7_00702A78[i]) != 0) {
            count++;
        }
    }
    return count;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/func_overlay_7_0070032C_1EFB454.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_7_00700390_1EFB4B8(s32 arg0, s32 arg1) {
    u8 *obj;
    u8 *state;
    u8 *chr;

    obj = objGetPlayerNo(0);
    if (obj == NULL) {
        return 1;
    }
    state = *(u8 **)(obj + 0x68);
    chr = mainGetGameCharacter(state[0], state[1]);
    switch (arg0) {
    case 1:
        return D_overlay_7_00702A6C;
    case 2:
        return mainPlayerHas(state[0], state[1], 1);
    case 3:
        return mainAnyoneHas(0x15);
    case 4:
        return *(u16 *)(chr + 0xA) & 0x20;
    case 5:
        return mainGetGameFlag(0x20);
    case 6:
        return mainGetGameFlag(0x59);
    case 7:
        return mainGetGameFlag(0x21);
    case 8:
        return mainGetGameFlag(0x22);
    case 9:
        return mainGetGameFlag(0x23);
    case 10:
        return func_overlay_7_0070032C_1EFB454() == 0;
    case 11:
        return func_overlay_7_0070032C_1EFB454() < 7;
    case 12:
        return func_overlay_7_0070032C_1EFB454() >= 7;
    case 13:
        return func_overlay_7_0070032C_1EFB454() == 0xC;
    case 14:
        return mainGetGameFlag(0x58);
    case 15:
        return state[0x189] == 0;
    case 16:
        return state[0x189] == 2;
    case 17:
        return mainGetGameFlag(0x24);
    case 18:
        return mainAnyoneHas(0x16);
    case 19:
        return mainGetGameFlag(0x2B);
    case 20:
        return mainAnyoneHas(0x11);
    default:
        return 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/func_overlay_7_00700390_1EFB4B8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_overlay_7_00700578_1EFB6A0(s32 arg0, s32 arg1) {
    void *result = NULL;
    HintQueueEntry *entry;

    if (D_overlay_7_00702A28 != 0) {
        D_overlay_7_00702A30 = arg0;
        D_overlay_7_00702A34 = arg1;
        return NULL;
    }
    D_overlay_7_00702A30 = -1;
    D_overlay_7_00702A34 = -1;
    if (D_overlay_7_00702A4C >= 0x10) {
        return NULL;
    }

    if (arg1 == 2) {
        D_overlay_7_00702A68 = arg0;
        D_overlay_7_00702A28 = 2;
    } else if (arg1 == 1) {
        D_overlay_7_00702A5C = func_overlay_7_00700988_1EFBAB0(1, 0);
        if (func_overlay_7_007007E4_1EFB90C(0) != 0) {
            result = D_overlay_7_00702A5C;
            D_overlay_7_00702A44 = 1;
        }
    } else {
        D_overlay_7_00702A58 = func_overlay_7_00700988_1EFBAB0(4, 0);
        D_overlay_7_00702A38 = 0;
        D_overlay_7_00702A3C = 0;
        D_overlay_7_00702A40 = 0;
        D_overlay_7_00702A44 = arg1;
        result = D_overlay_7_00702A58;
    }

    if (result != NULL) {
        entry = &D_overlay_7_00702D58[D_overlay_7_00702A4C];
        entry->unk0 = (s16)arg0;
        entry->unk2 = (s16)arg1;
        entry->unk4 = result;
        D_overlay_7_00702A4C++;
    }
    if (runlinkIsModuleLoaded(0x20) != 0) {
        mrHintsTalk();
    }
    return result;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/func_overlay_7_00700578_1EFB6A0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_7_0070070C_1EFB834(void) {
    HintQueueEntry *entry;

    if (D_overlay_7_00702A4C > 0) {
        D_overlay_7_00702A4C--;
        if (D_overlay_7_00702A4C > 0) {
            hinttextFreeObject();
            entry = &D_overlay_7_00702D58[D_overlay_7_00702A4C - 1];
            D_overlay_7_00702A44 = entry->unk2;
            if (entry->unk2 != 1) {
                D_overlay_7_00702A58 = entry->unk4;
                D_overlay_7_00702A38 = 0;
                D_overlay_7_00702A3C = 0;
                D_overlay_7_00702A40 = 0;
            } else {
                D_overlay_7_00702A5C = entry->unk4;
                if (func_overlay_7_007007E4_1EFB90C(0) == 0) {
                    func_overlay_7_0070070C_1EFB834();
                }
            }
            if (runlinkIsModuleLoaded(0x20) != 0) {
                mrHintsTalk();
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/func_overlay_7_0070070C_1EFB834.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_7_007007E4_1EFB90C(s32 arg0) {
    HintListEntry *list;
    s32 visible = 0;
    s32 i;
    s32 cursor;

    list = D_overlay_7_00702A5C;
    if (list == NULL) {
        return 0;
    }
    for (i = 0; i < list->unk0; i++) {
        if (func_overlay_7_007012E0_1EFC408(list[i].unk8) != 0) {
            visible++;
        }
    }
    if (visible == 0) {
        return 0;
    }

    cursor = list->unk2;
    if (arg0 > 0) {
        do {
            cursor++;
            if (cursor >= list->unk0) {
                break;
            }
        } while (func_overlay_7_007012E0_1EFC408(list[cursor].unk8) == 0);
    } else if (arg0 < 0) {
        do {
            cursor--;
            if (cursor < 0) {
                break;
            }
        } while (func_overlay_7_007012E0_1EFC408(list[cursor].unk8) == 0);
    } else if (func_overlay_7_007012E0_1EFC408(list[cursor].unk8) == 0) {
        do {
            cursor--;
            if (cursor < 0) {
                break;
            }
        } while (func_overlay_7_007012E0_1EFC408(list[cursor].unk8) == 0);
        if (cursor < 0) {
            cursor = list->unk2;
            do {
                cursor++;
                if (cursor >= list->unk0) {
                    break;
                }
            } while (func_overlay_7_007012E0_1EFC408(list[cursor].unk8) == 0);
        }
    }

    if (cursor >= 0 && cursor < list->unk0) {
        list->unk2 = cursor;
    }
    return visible;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/func_overlay_7_007007E4_1EFB90C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_overlay_7_00700988_1EFBAB0(s32 arg0, s32 arg1) {
    HintCacheSlot *slot;
    s32 idx;
    s32 lang;
    s32 langIdx;
    void *data;

    for (slot = D_overlay_7_00702C58; slot < &D_overlay_7_00702C58[32]; slot++) {
        if (slot->data != NULL && slot->id == arg0) {
            return slot->data;
        }
    }

    idx = 0;
    if (D_overlay_7_00702C5C != 0) {
        do {
            idx++;
            if (idx >= 0x20) {
                break;
            }
        } while (D_overlay_7_00702C58[idx].data != NULL);
    }
    if (idx >= 0x20) {
        return NULL;
    }

    slot = &D_overlay_7_00702C58[idx];
    lang = frontGetLanguage();
    switch (lang) {
    case 1:
        langIdx = 0xC;
        break;
    case 2:
        langIdx = 0xE;
        break;
    case 4:
        langIdx = 0x12;
        break;
    default:
        langIdx = 0xA;
        break;
    }

    if (arg1 != 1) {
        data = func_overlay_7_00700B00_1EFBC28(arg0, langIdx, arg0);
    } else {
        data = func_overlay_7_00700C90_1EFBDB8(arg0, langIdx);
    }
    slot->data = data;
    if (data != NULL) {
        slot->id = arg0;
        D_overlay_7_00702A48++;
    }
    return data;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/func_overlay_7_00700988_1EFBAB0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_overlay_7_00700B00_1EFBC28(s32 arg0, s32 arg1, s32 arg2) {
    u32 *offsets;
    s32 start;
    s32 size;
    u8 *buf;
    u8 *rec;
    u8 cmd;

    offsets = (u32 *)D_overlay_7_00702A54;
    start = offsets[arg0];
    size = offsets[arg0 + 1] - start;
    buf = (u8 *)mmAlloc(size, 0xFF00FF);
    if (buf != NULL) {
        piRomLoadSection(arg1, (u32)buf, start, size);
        rec = buf;
        if (*rec != 0) {
            cmd = *rec;
            do {
                switch (cmd) {
                case 1:
                    cmd = rec[4];
                    rec += 4;
                    break;
                case 2:
                case 3:
                case 4:
                case 5:
                    /* 24-bit offset in the word, command in the top byte: rebase to a pointer */
                    *(u32 *)rec = ((*(u32 *)rec & 0xFFFFFF) | 0x80000000) + (u32)buf;
                    rec[0] = cmd;
                    rec += 4;
                    cmd = rec[0];
                    break;
                case 6:
                case 7:
                    cmd = rec[8];
                    rec += 8;
                    break;
                default:
                    cmd = 0;
                    break;
                }
            } while (cmd != 0);
        }
    }
    return buf;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/func_overlay_7_00700B00_1EFBC28.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
MemoryPoolSlot *func_overlay_7_00700C90_1EFBDB8(s32 arg0, u32 arg1) {
    u32 *offsets;
    s32 start;
    s32 size;
    HintListEntry *list;
    HintListEntry *e;
    s32 i;

    offsets = (u32 *)D_overlay_7_00702A54;
    start = offsets[arg0];
    size = offsets[arg0 + 1] - start;
    list = (HintListEntry *)mmAlloc(size, 0xFF00FF);
    if (list != NULL) {
        piRomLoadSection(arg1, (u32)list, start, size);
        for (i = 0; i < list->unk0; i++) {
            e = &list[i];
            if (e->unk4 != 0) {
                e->unk4 += (s32)list;
            } else if (e->unkC == 0x4000) {
                e->unk4 = (s32)D_overlay_7_00702A04;
            } else {
                e->unk4 = (s32)D_overlay_7_00702A14;
            }
        }
    }
    return (MemoryPoolSlot *)list;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/func_overlay_7_00700C90_1EFBDB8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hinttextStop(void) {
    D_overlay_7_00702A24 = 0;
    D_overlay_7_00702A2C = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/hinttextStop.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 hinttextActive(void) {
    return D_overlay_7_00702A24;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/hinttextActive.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 hinttextActiveMagic(void) {
    return D_overlay_7_00702A28;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/hinttextActiveMagic.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hinttextStopMagic(void) {
    D_overlay_7_00702A28 = 0;
    if (D_overlay_7_00702A30 != -1) {
        func_overlay_7_00700578_1EFB6A0(D_overlay_7_00702A30, D_overlay_7_00702A34);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/hinttextStopMagic.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 hinttextTriedToEnd(void) {
    return D_overlay_7_00702A2C;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/hinttextTriedToEnd.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_7_00700DF0_1EFBF18(void) {
    D_overlay_7_00702C4C = 0;
    D_overlay_7_00702C50 = 0;
    D_overlay_7_00702A2C = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/func_overlay_7_00700DF0_1EFBF18.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_7_00700E0C_1EFBF34(s32 arg0) {
    s32 buttons;
    s32 stickX;
    s32 stickY;

    buttons = joyGetPressed(0);
    stickX = joyGetStickX(0);
    stickY = joyGetStickY(0);
    D_overlay_7_00702C30 = buttons & 0x8000;
    D_overlay_7_00702C34 = buttons & 0x4000;
    D_overlay_7_00702C38 = buttons & 0x1000;
    D_overlay_7_00702C3C = 0;
    D_overlay_7_00702C40 = 0;
    D_overlay_7_00702C44 = 0;
    D_overlay_7_00702C48 = 0;
    /* Stick dead zone and repeat timers. The asm X-axis dead-zone thresholds look
       inconsistent (-0x1D/-0x1E), so both axes are written symmetrically here. */
    if (stickY >= -0x1E && stickY < 0x1F) {
        D_overlay_7_00702C50 = 0;
    } else if (stickY >= 0x1F) {
        if (D_overlay_7_00702C50 > 0) {
            D_overlay_7_00702C50 -= arg0;
            if (D_overlay_7_00702C50 <= 0) {
                D_overlay_7_00702C50 = 0xA;
                D_overlay_7_00702C3C = 1;
            }
        } else {
            D_overlay_7_00702C50 = 0x14;
            D_overlay_7_00702C3C = 1;
        }
    } else if (stickY < -0x1E) {
        if (D_overlay_7_00702C50 < 0) {
            D_overlay_7_00702C50 += arg0;
            if (D_overlay_7_00702C50 >= 0) {
                D_overlay_7_00702C50 = -0xA;
                D_overlay_7_00702C40 = 1;
            }
        } else {
            D_overlay_7_00702C50 = -0x14;
            D_overlay_7_00702C40 = 1;
        }
    }
    if (stickX >= -0x1E && stickX < 0x1F) {
        D_overlay_7_00702C4C = 0;
    } else if (stickX >= 0x1F) {
        if (D_overlay_7_00702C4C > 0) {
            D_overlay_7_00702C4C -= arg0;
            if (D_overlay_7_00702C4C <= 0) {
                D_overlay_7_00702C4C = 0xA;
                D_overlay_7_00702C48 = 1;
            }
        } else {
            D_overlay_7_00702C4C = 0x14;
            D_overlay_7_00702C48 = 1;
        }
    } else if (stickX < -0x1E) {
        if (D_overlay_7_00702C4C < 0) {
            D_overlay_7_00702C4C += arg0;
            if (D_overlay_7_00702C4C <= 0) {
                D_overlay_7_00702C4C = -0xA;
                D_overlay_7_00702C44 = 1;
            }
        } else {
            D_overlay_7_00702C4C = -0x14;
            D_overlay_7_00702C44 = 1;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/func_overlay_7_00700E0C_1EFBF34.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_7_00701018_1EFC140(s32 arg0) {
    s32 visibleLines;

    visibleLines = (0x58 / fontYSpacing(2)) - 1;
    if (D_overlay_7_00702A38 != 0) {
        if (D_overlay_7_00702A38 < 0) {
            D_overlay_7_00702A38 += 1;
            D_overlay_7_00702A3C -= 1;
        } else {
            D_overlay_7_00702A38 -= 1;
            D_overlay_7_00702A3C += 1;
        }
    } else if (D_overlay_7_00702A40 != 0 && D_overlay_7_00702C30 != 0) {
        D_overlay_7_00702A38 = visibleLines;
        if (runlinkIsModuleLoaded(0x20) != 0) {
            mrHintsTalk();
        }
    } else if (D_overlay_7_00702A3C >= visibleLines && D_overlay_7_00702C34 != 0) {
        D_overlay_7_00702A38 = -visibleLines;
        if (runlinkIsModuleLoaded(0x20) != 0) {
            mrHintsTalk();
        }
    }
    if (D_overlay_7_00702A40 == 0 && D_overlay_7_00702C30 != 0) {
        if (D_overlay_7_00702A44 == 4 && D_overlay_7_00702A4C >= 2) {
            func_overlay_7_0070070C_1EFB834();
        } else if (D_overlay_7_00702A44 == 3 && D_overlay_7_00702A74 != 0) {
            func_overlay_7_00700578_1EFB6A0(D_overlay_7_00702A70, D_overlay_7_00702A74);
        } else {
            D_overlay_7_00702A2C = 1;
        }
    } else if (D_overlay_7_00702C34 != 0 && D_overlay_7_00702A4C >= 2) {
        func_overlay_7_0070070C_1EFB834();
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/func_overlay_7_00701018_1EFC140.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_7_00701214_1EFC33C(s32 arg0) {
    u8 *list;

    list = (u8 *)D_overlay_7_00702A5C;
    if (D_overlay_7_00702C34 != 0) {
        func_overlay_7_0070070C_1EFB834();
    } else if (D_overlay_7_00702C30 != 0) {
        func_overlay_7_007016B4_1EFC7DC();
    } else if (D_overlay_7_00702C3C != 0 && *(s16 *)(list + 2) > 0) {
        func_overlay_7_007007E4_1EFB90C(-1);
    } else if (D_overlay_7_00702C40 != 0 && *(s16 *)(list + 2) < *(s16 *)list - 1) {
        func_overlay_7_007007E4_1EFB90C(1);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/func_overlay_7_00701214_1EFC33C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_7_007012E0_1EFC408(s16 arg0) {
    u8 *obj;
    u8 *state;
    u8 *chr;

    state = NULL;
    chr = NULL;
    obj = objGetPlayerNo(0);
    if (obj != NULL) {
        state = *(u8 **)(obj + 0x68);
        if (state != NULL) {
            chr = mainGetGameCharacter(state[0], state[1]);
        }
    }
    switch ((u32)arg0) {
    case 0:
        return mainPlayerHas(state[0], state[1], 1) == 0;
    case 1:
        return mainAnyoneHas(0x10) == 0 && mainAnyoneHas(0x11) == 0;
    case 2:
        return mainAnyoneHas(0x11) == 0;
    case 3:
        return (*(u16 *)(chr + 0xA) & 0x20) == 0;
    case 4:
        return mainAnyoneHas(0x15) == 0;
    case 5:
        return mainGetGameFlag(0x20) == 0;
    case 6:
        return mainGetGameFlag(0x21) == 0;
    case 7:
        return mainGetGameFlag(0x21);
    case 8:
        return mainGetGameFlag(0x22) == 0;
    case 9:
        return mainGetGameFlag(0x22);
    case 10:
        return mainGetGameFlag(0x23) == 0;
    case 11:
        return mainGetGameFlag(0x23);
    case 12:
        return mainGetGameFlag(0x24) == 0;
    case 14:
        return mainAnyoneHas(0x16) == 0;
    case 15:
        return amTuneGetSeqNo() != 0x3C;
    case 16:
        return amTuneGetSeqNo() != 0x3D;
    case 17:
        return amTuneGetSeqNo() != 0x3E;
    case 18:
        return amTuneGetSeqNo() != 0x41;
    case 19:
        return mainGetGameFlag(0x2B);
    case 20:
        return mainGetGameFlag(0x2B) == 0;
    default:
        return 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/func_overlay_7_007012E0_1EFC408.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_7_00701504_1EFC62C(s32 arg0) {
    u8 *obj;
    u8 *state;
    u8 *chr;

    state = NULL;
    chr = NULL;
    obj = objGetPlayerNo(0);
    if (obj != NULL) {
        state = *(u8 **)(obj + 0x68);
        if (state != NULL) {
            chr = mainGetGameCharacter(state[0], state[1]);
        }
    }
    switch (arg0) {
    case 0:
        return mainPlayerHas(state[0], state[1], 0);
    case 1:
        return mainPlayerHas(state[0], state[1], 0x10);
    case 2:
        return mainGetGameFlag(0x2C) != 0 && mainGetGameFlag(0x2D) != 0 && mainGetGameFlag(0x2E) != 0;
    case 3:
        return mainPlayerHas(state[0], state[1], 0x14);
    case 4:
        return *(s16 *)(chr + 0x12) >= 5;
    case 5:
        return *(s16 *)(chr + 0x12) >= 0xA;
    case 6:
        return mainPlayerHas(state[0], state[1], 0x17) != 0
            && mainPlayerHas(state[0], state[1], 0x18) != 0
            && mainPlayerHas(state[0], state[1], 0x19) != 0;
    case 7:
        return mainPlayerHas(state[0], state[1], 0x1A);
    default:
        return 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/func_overlay_7_00701504_1EFC62C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_7_007016B4_1EFC7DC(void) {
    u8 *list;
    u8 *entry;
    s16 cmd;
    s16 alt;
    s16 chain;

    list = (u8 *)D_overlay_7_00702A5C;
    if (list != NULL) {
        entry = list + (*(s16 *)(list + 2) * 0x10) + 4;
        if (func_overlay_7_00701504_1EFC62C(*(s16 *)(entry + 6)) != 0) {
            cmd = *(s16 *)(entry + 8);
            switch (cmd & 0xF000) {
            case 0x0:
                func_overlay_7_007017E8_1EFC910(cmd);
                break;
            case 0x1000:
                func_overlay_7_00700578_1EFB6A0(cmd & 0xFFF, 4);
                break;
            case 0x2000:
                func_overlay_7_00700578_1EFB6A0(cmd & 0xFFF, 1);
                break;
            case 0x3000:
                D_overlay_7_00702A68 = cmd & 0xFFF;
                D_overlay_7_00702A28 = 2;
                break;
            case 0x4000:
                func_overlay_7_0070070C_1EFB834();
                break;
            default:
                D_overlay_7_00702A24 = 0;
                break;
            }
            chain = *(s16 *)(entry + 0xC);
            if (chain != -1) {
                func_overlay_7_00700578_1EFB6A0(chain, 4);
            }
        } else {
            alt = *(s16 *)(entry + 0xA);
            if (alt != -1) {
                func_overlay_7_00700578_1EFB6A0(alt, 4);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/func_overlay_7_007016B4_1EFC7DC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_7_007017E8_1EFC910(s32 arg0) {
    u8 *obj;
    u8 *state;
    u8 *chr;
    u8 *weapon;
    s32 off;
    s32 v;

    state = NULL;
    chr = NULL;
    obj = objGetPlayerNo(0);
    if (obj != NULL) {
        state = *(u8 **)(obj + 0x68);
        if (state != NULL) {
            chr = mainGetGameCharacter(state[0], state[1]);
        }
    }
    switch (arg0) {
    case 0:
        mainPlayerCollected(state[0], state[1], 1);
        D_overlay_7_00702A28 = 1;
        D_overlay_7_00702A64 = 0x17D;
        break;
    case 1:
        mainPlayerCollected(state[0], state[1], 0x10);
        D_overlay_7_00702A28 = 1;
        D_overlay_7_00702A64 = 0x18A;
        break;
    case 2:
        mainPlayerCollected(state[0], state[1], 0x11);
        mainPlayerDropped(state[0], state[1], 0x10);
        D_overlay_7_00702A28 = 1;
        D_overlay_7_00702A64 = 0x185;
        break;
    case 3:
    case 4:
        if (arg0 == 4) {
            mainPlayerDropped(state[0], state[1], 0x17);
            mainPlayerDropped(state[0], state[1], 0x18);
            mainPlayerDropped(state[0], state[1], 0x19);
        }
        weapon = controlGetWeaponDef(5);
        *(u16 *)(chr + 0xA) |= 0x20;
        chr[0x6F] += 1;
        *(s16 *)(chr + 0x3E) = *(s16 *)(weapon + 0x24);
        *(s16 *)(chr + 0x1E) = *(s16 *)(weapon + 0x28);
        chr[0x59] = weapon[0x3];
        D_overlay_7_00702A28 = 1;
        D_overlay_7_00702A64 = 0x271;
        break;
    case 5:
        mainPlayerCollected(state[0], state[1], 0x15);
        mainPlayerDropped(state[0], state[1], 0x14);
        D_overlay_7_00702A28 = 1;
        D_overlay_7_00702A64 = 0x27D;
        break;
    case 6:
        *(s16 *)chr = (s16)(*(s16 *)(chr + 2) * 5 + 4);
        *(s16 *)(*(u8 **)(obj + 0x4C) + 6) = (s16)(*(s16 *)chr << 8);
        *(s16 *)(chr + 0x12) -= 5;
        break;
    case 7:
        for (v = 0; v != 0x10; v += 4) {
            off = v * 2;
            if (*(u16 *)(chr + 0xA) & (1 << v)) {
                *(u16 *)(chr + off + 0x14) = *(u16 *)(chr + off + 0x34);
            }
            if (*(u16 *)(chr + 0xA) & (1 << (v + 1))) {
                *(u16 *)(chr + off + 0x16) = *(u16 *)(chr + off + 0x36);
            }
            if (*(u16 *)(chr + 0xA) & (1 << (v + 2))) {
                *(u16 *)(chr + off + 0x18) = *(u16 *)(chr + off + 0x38);
            }
            if (*(u16 *)(chr + 0xA) & (1 << (v + 3))) {
                *(u16 *)(chr + off + 0x1A) = *(u16 *)(chr + off + 0x3A);
            }
        }
        *(s16 *)(chr + 0x12) -= 0xA;
        break;
    case 8:
        mainSetGameFlag(0x20, 1);
        mainPlayerDropped(state[0], state[1], 0x1A);
        D_overlay_7_00702A28 = 1;
        D_overlay_7_00702A64 = 0x2E6;
        break;
    case 9:
        mainSetGameFlag(0x21, 1);
        D_overlay_7_00702A28 = 1;
        D_overlay_7_00702A64 = 0x2E8;
        break;
    case 10:
        mainSetGameFlag(0x22, 1);
        D_overlay_7_00702A28 = 1;
        D_overlay_7_00702A64 = 0x2E9;
        break;
    case 11:
        mainSetGameFlag(0x23, 1);
        D_overlay_7_00702A28 = 1;
        D_overlay_7_00702A64 = 0x2EA;
        break;
    case 12:
        mainSetGameFlag(0x24, 1);
        D_overlay_7_00702A28 = 1;
        D_overlay_7_00702A64 = 0x2EB;
        break;
    case 13:
        mainPlayerCollected(state[0], state[1], 0x16);
        D_overlay_7_00702A28 = 1;
        D_overlay_7_00702A64 = 0x2C1;
        break;
    case 14:
        amTuneStop();
        amTunePlay(0x3C);
        break;
    case 15:
        amTuneStop();
        amTunePlay(0x3D);
        break;
    case 16:
        amTuneStop();
        amTunePlay(0x3E);
        break;
    case 17:
        amTuneStop();
        amTunePlay(0x41);
        break;
    case 18:
        mainSetGameFlag(0x2B, 1);
        D_overlay_7_00702A28 = 1;
        D_overlay_7_00702A64 = 0x6C;
        break;
    default:
        func_overlay_7_0070070C_1EFB834();
        break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/func_overlay_7_007017E8_1EFC910.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hinttextUpdate(s32 arg0, s32 arg1) {
    func_overlay_7_00700E0C_1EFBF34(arg1);
    if (D_overlay_7_00702A24 != 0 && D_overlay_7_00702A28 == 0) {
        if (D_overlay_7_00702A44 != 1 && D_overlay_7_00702A58 != NULL) {
            func_overlay_7_00701018_1EFC140(arg1);
        } else if (D_overlay_7_00702A5C != NULL) {
            func_overlay_7_00701214_1EFC33C(arg1);
        }
        D_overlay_7_00702A20 += arg1 * 0x10;
        if (D_overlay_7_00702A20 >= 0x101) {
            D_overlay_7_00702A20 = 0x100;
        }
    } else if (D_overlay_7_00702A20 > 0) {
        D_overlay_7_00702A20 -= arg1 * 0x10;
        if (D_overlay_7_00702A20 <= 0) {
            if (D_overlay_7_00702A28 == 0) {
                hinttextFree();
            } else {
                D_overlay_7_00702A20 = 0;
            }
        }
    }
    fontSetButtonMode(1);
    if (D_overlay_7_00702A20 != 0) {
        if (D_overlay_7_00702A44 != 1) {
            func_overlay_7_00701F80_1EFD0A8(arg0);
        } else {
            func_overlay_7_007020D4_1EFD1FC(arg0);
        }
    }
    fontSetButtonMode(0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/hinttextUpdate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_7_00701E34_1EFCF5C(s32 arg0, s8 *arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    HintRect rects[24];
    s8 *rec;
    s32 count;

    count = 0;
    rec = arg1;
    if (*rec >= 0) {
        do {
            rects[count].x0 = (s16)(rec[1] + arg2);
            if (rec[0] != 0) {
                rects[count].x0 = (s16)(rects[count].x0 + arg4);
            }
            rects[count].y0 = (s16)(rec[3] + arg3);
            if (rec[2] != 0) {
                rects[count].y0 = (s16)(rects[count].y0 + arg5);
            }
            rects[count].x1 = (s16)(rec[5] + arg2);
            if (rec[4] != 0) {
                rects[count].x1 = (s16)(rects[count].x1 + arg4);
            }
            rects[count].y1 = (s16)(rec[7] + arg3);
            if (rec[6] != 0) {
                rects[count].y1 = (s16)(rects[count].y1 + arg5);
            }
            rects[count].scale = (rec[8] * arg6) >> 7;
            count++;
            rec += 9;
        } while (*rec >= 0 && count != 24);
    }
    frontDrawRectangles(arg0, count, rects, 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/func_overlay_7_00701E34_1EFCF5C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_7_00701F80_1EFD0A8(s32 arg0) {
    func_overlay_7_00701E34_1EFCF5C(arg0, D_overlay_7_00702960, 0x5C, 0x14, 0xD0, 0x58,
                                    (D_overlay_7_00702A20 * 0xA0) >> 8);
    D_overlay_7_00702A40 = func_overlay_7_007023D4_1EFD4FC(arg0, D_overlay_7_00702A58, D_overlay_7_00702A3C);
    fontBackground(0, 0, 0, 0);
    fontColour(0xFF, 0xC0, 0, 0xFF, (D_overlay_7_00702A20 * 0xFF) >> 8);
    if (D_overlay_7_00702A3C != 0) {
        fontPrintXY(arg0, 0xC4, 0x14, D_overlay_7_00702ADC, 0xC);
    }
    if (D_overlay_7_00702A40 != 0
        || (D_overlay_7_00702A44 == 4 && D_overlay_7_00702A4C >= 2)
        || (D_overlay_7_00702A44 == 3 && D_overlay_7_00702A74 != 0)) {
        fontPrintXY(arg0, 0xC4, 0x6C, D_overlay_7_00702AE0, 0xC);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/func_overlay_7_00701F80_1EFD0A8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_7_007020D4_1EFD1FC(s32 arg0) {
    u8 *list;
    u8 *entry;
    u8 *text;
    u8 *lineEnd;
    char *line;
    u8 saved;
    s32 i;
    s32 lineH;
    s32 maxLines;
    s32 alpha;
    s32 x;
    s32 y;
    s32 indent;

    func_overlay_7_00701E34_1EFCF5C(arg0, D_overlay_7_00702960, 0x5C, 0x14, 0xD0, 0x58,
                                    (D_overlay_7_00702A20 * 0xA0) >> 8);
    i = 0;
    text = NULL;
    lineH = fontYSpacing(2);
    maxLines = (0x58 / lineH) - 1;
    fontUseFont(2);
    fontBackground(0, 0, 0, 0);
    list = (u8 *)D_overlay_7_00702A5C;
    alpha = (D_overlay_7_00702A20 * 0xFF) >> 8;
    y = ((0x58 - maxLines * lineH) >> 1) + 0x14;
    if (*(s16 *)list > 0) {
        while (maxLines > 0 && i < *(s16 *)list) {
            entry = list + i * 0x10;
            x = 0x60;
            indent = 1;
            if (i == *(s16 *)(list + 2)) {
                fontColour(0xFF, 0xFF, 0xFF, 0xFF, alpha);
            } else {
                fontColour(0, 0xC0, 0xC0, 0xFF, alpha);
            }
            text = *(u8 **)(entry + 4);
            if (func_overlay_7_007012E0_1EFC408(*(s16 *)(entry + 8)) == 0) {
                text = NULL;
            }
            while (text != NULL && maxLines > 0) {
                lineEnd = fontGetLine(2, text, 0xC8, &line);
                text = lineEnd;
                if (lineEnd != NULL) {
                    saved = *lineEnd;
                    *lineEnd = 0;
                    fontPrintXY(arg0, x, y, line, 0);
                    *lineEnd = saved;
                    y += lineH;
                    if (indent != 0) {
                        x += 8;
                        indent = 0;
                    }
                    maxLines--;
                }
            }
            i++;
        }
    }
    fontBackground(0, 0, 0, 0);
    fontColour(0xFF, 0xC0, 0, 0xFF, alpha);
    if (i < *(s16 *)list || text != NULL) {
        fontPrintXY(arg0, 0xC4, 0x6C, D_overlay_7_00702AE4, 0xC);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/func_overlay_7_007020D4_1EFD1FC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_7_007023D4_1EFD4FC(s32 arg0, void *arg1, s32 arg2) {
    u8 *fp;
    u8 *text;
    u8 *lineEnd;
    char *line;
    u8 saved;
    s32 skip;
    s32 lines;
    s32 lineH;
    s32 x;
    s32 y;
    s32 width;
    s32 alignFlags;
    s32 indent;
    s32 done;
    s32 ret;

    skip = arg2;
    fp = (u8 *)arg1;
    done = 0;
    ret = 0;
    lineH = fontYSpacing(2);
    lines = (0x58 / lineH) - 1;
    fontBackground(0, 0, 0, 0);
    fontColour(0xFF, 0xFF, 0xFF, 0xFF, (D_overlay_7_00702A20 * 0xFF) >> 8);
    fontUseFont(2);
    y = ((0x58 - lines * lineH) >> 1) + 0x14;
    do {
        alignFlags = 0;
        x = 0x60;
        width = 0xC8;
        indent = 0;
        text = NULL;
        switch (fp[0]) {
        case 1:
            if (skip == 0) {
                lines--;
                y += lineH;
            } else {
                skip--;
            }
            fp += 4;
            break;
        case 2:
            text = (u8 *)(u32)((*(u32 *)fp & 0xFFFFFF) | 0x80000000);
            fp += 4;
            alignFlags = 4;
            x = 0xC4;
            break;
        case 3:
            text = (u8 *)(u32)((*(u32 *)fp & 0xFFFFFF) | 0x80000000);
            fp += 4;
            break;
        case 4:
            text = (u8 *)(u32)((*(u32 *)fp & 0xFFFFFF) | 0x80000000);
            fp += 4;
            alignFlags = 1;
            x = 0x127;
            break;
        case 5:
            text = (u8 *)(u32)((*(u32 *)fp & 0xFFFFFF) | 0x80000000);
            fp += 4;
            indent = 1;
            break;
        case 6:
            fontColour(fp[1], fp[2], fp[3], fp[5], (fp[6] * D_overlay_7_00702A20) >> 8);
            fp += 8;
            break;
        case 7:
            fontBackground(fp[1], fp[2], fp[3], fp[5]);
            fp += 8;
            break;
        default:
            done = 1;
            break;
        }
        while (text != NULL && lines >= 0) {
            if (indent != 0) {
                x += 8;
                width -= 8;
            }
            lineEnd = fontGetLine(2, text, width, &line);
            text = lineEnd;
            if (text != NULL) {
                if (skip == 0) {
                    lines--;
                    if (lines >= 0) {
                        saved = *lineEnd;
                        *lineEnd = 0;
                        fontPrintXY(arg0, x, y, line, alignFlags);
                        *lineEnd = saved;
                        y += lineH;
                    }
                } else {
                    skip--;
                }
            }
            if (indent != 0) {
                x -= 8;
                width += 8;
                indent = 0;
            }
        }
        if (lines < 0) {
            ret = 1;
            done = 1;
        }
    } while (!done);
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/func_overlay_7_007023D4_1EFD4FC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hinttextLoadObject(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 arg4) {
    HintObjSetup setup;

    if (D_overlay_7_00702A64 != -1) {
        hinttextFreeObject();
        setup.unk2 = 0x10;
        setup.unk3 = 0;
        setup.unkB = 0;
        setup.x = (s16) arg0;
        setup.y = (s16) arg1;
        setup.z = (s16) arg2;
        setup.w = (s8) arg3;
        setup.scale = arg4;
        setup.id = (s16) D_overlay_7_00702A64;
        D_overlay_7_00702A60 = objSetupObject(&setup, 1);
        if (D_overlay_7_00702A60 != NULL) {
            *(s32 *)((u8 *)D_overlay_7_00702A60 + 0x3C) = 0;
        }
        D_overlay_7_00702A64 = -1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/hinttextLoadObject.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hinttextFreeObject(void) {
    if (D_overlay_7_00702A60 != NULL) {
        *(s32 *)((u8 *)D_overlay_7_00702A60 + 0x88) = 1;
        D_overlay_7_00702A60 = NULL;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/hinttextFreeObject.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hinttextStartLevel(void) {
    s32 nextCharacter;
    void *player;

    if (D_overlay_7_00702A68 != -1) {
        player = objGetPlayerNo(0);
        if (player != NULL) {
            controlSetPlayerSetup((s16) *(f32 *)((u8 *)player + 0xC),
                                  (s16) (*(f32 *)((u8 *)player + 0x10) + 2.0f),
                                  (s16) *(f32 *)((u8 *)player + 0x14),
                                  *(s16 *)player);
        }
        nextCharacter = mainGetNextCharacter();
        mainChangeLevel(D_overlay_7_00702A68, nextCharacter, 0, frontGetMode(), 1, 0);
        D_overlay_7_00702A68 = -1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o7/overlay_7/hinttextStartLevel.s")
#endif
