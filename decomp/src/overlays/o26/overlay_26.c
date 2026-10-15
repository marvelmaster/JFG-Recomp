#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
typedef struct PointPoly {
    /* 0x00 */ u8 unk0;         /* always 0x40 */
    /* 0x01 */ u8 unk1;         /* vertex index */
    /* 0x02 */ u8 unk2;         /* vertex index */
    /* 0x03 */ u8 unk3;         /* vertex index */
    /* 0x04 */ s16 unk4;
    /* 0x06 */ s16 unk6;
    /* 0x08 */ s16 flags;       /* always 0x200 */
    /* 0x0A */ s16 prevIndex;
    /* 0x0C */ s16 nextIndex;
    /* 0x0E */ s16 index;
    /* 0x10 */ u8 unk10;        /* always 0x40 */
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ s16 unk14;
    /* 0x16 */ s16 unk16;
    /* 0x18 */ s16 unk18;       /* always 0x200 */
    /* 0x1A */ s16 unk1A;       /* always 0x200 */
    /* 0x1C */ s16 unk1C;
    /* 0x1E */ s16 unk1E;       /* always 0x200 */
} PointPoly; /* Size: 0x20 bytes */

typedef struct PolyPairRow {
    /* 0x00 */ PointPoly *first;
    /* 0x04 */ PointPoly *second;
} PolyPairRow;

typedef struct PolyCoord {
    /* 0x00 */ f32 a;           /* 2*cos + 2*sin */
    /* 0x04 */ f32 b;           /* 2*cos - 2*sin */
} PolyCoord;

extern PolyPairRow D_800A5F48[7];
extern PolyCoord *D_800A5F80[7];
extern void *pointpolys;

f32 Sinf(s16 angle);

extern void *partlists[];
extern u32 *PartTab;
extern u32 *PartTypes;
extern u32 *PartTrigTab;
extern u32 *PartTrigs;
extern s32 noparttypes;
extern s32 notrigtypes;
extern void *partgraphics;
extern s32 partlistsize;
extern void *partvertices;
extern void *pointstreams;
extern void *lines;
extern s32 maxlines;
extern s32 maxpointstreams;
extern void *trigdatbuffers;
extern s32 maxchildtriggerparticles;
extern void *D_800A5D90;
extern void *D_801008F0;
extern u8 trivlut[];
extern u8 tripartpolys[];
extern u8 rectvlut[];
extern u8 rectpartpolys[];

void partFreeLib(void);
void updateColourCycle(unkResetColourCycle *arg0, s32 arg1);
void partBuildCCTables(void);
void *func_overlay_26_01A00AF4_1F44E9C(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4);
void *func_overlay_26_01A00E60_1F45208(s32 count);
void *func_overlay_26_01A00F1C_1F452C4(s32 count);
s32 modLoadModel(s32 arg0, s32 arg1, s32 arg2);
s32 texLoadSprite(s32 spriteId, s32 arg1, s32 owner);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_26_01A00000_1F443A8(void) {
    PointPoly *first;
    PointPoly *second;
    PolyPairRow *row;
    PolyCoord *coords;
    s32 n;
    s32 j;
    s32 k;
    s32 nextK;
    s32 t0;
    s32 t1;
    s32 cnt;
    s32 extra;
    s16 angle;
    f32 c;
    f32 s;

    first = (PointPoly *) mmAlloc(0x880, 0x80808080);
    pointpolys = first;
    second = first + 34;    /* second half of the 0x880 block, 0x440 bytes in */

    for (n = 2; n < 9; n++) {
        row = &D_800A5F48[n - 2];
        row->first = first;
        row->second = second;

        cnt = n - 1;
        k = 0;
        if (cnt > 0) {
            t0 = n;
            t1 = n + 1;
            do {
                nextK = k + 1;
                first->unk1 = (u8) k;
                first->unk3 = (u8) t1;
                first->unk11 = (u8) k;
                first->unk12 = (u8) t1;
                first->unk13 = (u8) t0;
                first->unk0 = 0x40;
                first->unk2 = (u8) nextK;
                first->unk4 = 0;
                first->unk6 = 0;
                first->flags = 0x200;
                first->prevIndex = 0;
                first->nextIndex = 0x200;
                first->index = 0x200;
                first->unk10 = 0x40;
                first->unk14 = 0;
                first->unk16 = 0;
                first->unk18 = 0x200;
                first->unk1A = 0x200;
                first->unk1C = 0;
                first->unk1E = 0x200;

                second->unk1 = (u8) t0;
                second->unk2 = (u8) t1;
                second->unk11 = (u8) t0;
                second->unk13 = (u8) k;
                k = nextK;
                t0 += 1;
                t1 += 1;
                first++;
                second->unk0 = 0x40;
                second->unk3 = (u8) nextK;
                second->unk4 = 0;
                second->unk6 = 0;
                second->flags = 0x200;
                second->prevIndex = 0;
                second->nextIndex = 0x200;
                second->index = 0x200;
                second->unk10 = 0x40;
                second->unk14 = 0;
                second->unk16 = 0;
                second->unk18 = 0x200;
                second->unk1A = 0x200;
                second->unk1C = 0;
                second->unk1E = 0x200;
                second++;
            } while (nextK < cnt);
        }

        extra = k + n;
        if (n >= 3) {
            first->unk0 = 0x40;
            first->unk1 = (u8) k;
            first->unk2 = 0;
            first->unk3 = (u8) n;
            first->unk4 = 0;
            first->unk6 = 0;
            first->flags = 0x200;
            first->prevIndex = 0;
            first->nextIndex = 0x200;
            first->index = 0x200;
            first->unk10 = 0x40;
            first->unk11 = (u8) k;
            first->unk12 = (u8) n;
            first->unk13 = (u8) extra;
            first->unk14 = 0;
            first->unk16 = 0;
            first->unk18 = 0x200;
            first->unk1A = 0x200;
            first->unk1C = 0;
            first->unk1E = 0x200;
            first++;

            second->unk0 = 0x40;
            second->unk1 = (u8) extra;
            second->unk2 = (u8) n;
            second->unk3 = 0;
            second->unk4 = 0;
            second->unk6 = 0;
            second->flags = 0x200;
            second->prevIndex = 0;
            second->nextIndex = 0x200;
            second->index = 0x200;
            second->unk10 = 0x40;
            second->unk11 = (u8) extra;
            second->unk12 = 0;
            second->unk13 = (u8) k;
            second->unk14 = 0;
            second->unk16 = 0;
            second->unk18 = 0x200;
            second->unk1A = 0x200;
            second->unk1C = 0;
            second->unk1E = 0x200;
            second++;
        }
    }

    coords = (PolyCoord *) mmAlloc(0x118, 0x80808080);
    for (n = 2; n < 9; n++) {
        D_800A5F80[n - 2] = coords;
        angle = 0;
        for (j = 0; j < n; j++) {
            c = Cosf((s32) angle);
            s = Sinf(angle);
            coords->a = (2.0f * c) + (2.0f * s);
            coords->b = (2.0f * c) - (2.0f * s);
            coords++;
            angle = (s16) (angle + (s16) (0xFFFF / n));
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o26/overlay_26/func_overlay_26_01A00000_1F443A8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void partInitLib(void) {
    u32 *tab;
    s32 t1;
    s32 cont;
    s32 i;

    for (i = 0; i < 5; i++) {
        partlists[i] = NULL;
    }

    tab = (u32 *) piRomLoad(0x35);
    PartTab = tab;
    t1 = noparttypes + 1;
    if ((s32) tab[noparttypes + 1] != -1) {
        do {
            noparttypes = t1;
            cont = (s32) tab[t1 + 1] != -1;
            t1 = t1 + 1;
        } while (cont);
    }

    PartTypes = (u32 *) piRomLoad(0x36);
    if (noparttypes > 0) {
        for (i = 0; i < noparttypes; i++) {
            PartTab[i] += (u32) PartTypes;
        }
    }

    partBuildCCTables();

    tab = (u32 *) piRomLoad(0x37);
    PartTrigTab = tab;
    t1 = notrigtypes + 1;
    if ((s32) tab[notrigtypes + 1] != -1) {
        do {
            notrigtypes = t1;
            cont = (s32) tab[t1 + 1] != -1;
            t1 = t1 + 1;
        } while (cont);
    }

    PartTrigs = (u32 *) piRomLoad(0x38);
    if (notrigtypes > 0) {
        for (i = 0; i < notrigtypes; i++) {
            u8 *ty;

            PartTrigTab[i] += (u32) PartTrigs;
            ty = (u8 *) PartTrigTab[i];
            if (*(s32 *)(ty + 0x9C) != -1) {
                *(s32 *)(ty + 0x9C) = (s32) objGetTable(*(s32 *)(ty + 0x9C));
            } else {
                *(s32 *)(ty + 0x9C) = 0;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o26/overlay_26/partInitLib.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void partBuildCCTables(void) {
    unkResetColourCycle cc;
    u8 *part;
    u8 *other;
    u32 *colours;
    s32 i;
    s32 j;
    s32 count;
    s32 temp;

    for (i = 0; i < noparttypes; i++) {
        part = (u8 *) PartTab[i];
        if (*(u32 *) part & 0x400) {
            for (j = 0; j < i; j++) {
                other = (u8 *) PartTab[j];
                if (*(u16 *)(part + 0x24) == *(u16 *)(other + 0x24)) {
                    *(s32 *)(part + 0x20) = *(s32 *)(other + 0x20);
                    temp = cc.unkC->unk4;
                    *(s8 *)(part + 0x1F) = (s8) temp;
                    if ((temp & 0xFF) == 0) {
                        *(s8 *)(part + 0x1F) = 1;
                    }
                    break;
                }
            }
            if (*(s32 *)(part + 0x20) == 0) {
                initColourCycle(&cc, (s32) *(u16 *)(part + 0x24));
                count = cc.unkC->unk4;
                if (count == 0) {
                    count = 1;
                }
                if (count >= 0x100) {
                    count = 0xFF;
                }
                colours = (u32 *) mmAlloc(count * 4, 0x80808080);
                *(u32 **)(part + 0x20) = colours;
                *(s8 *)(part + 0x1F) = (s8) count;
                for (j = 0; j < count; j++) {
                    colours[j] = (cc.unk8 << 24) | (cc.unk9 << 16) | (cc.unkA << 8) | cc.unkB;
                    updateColourCycle(&cc, 1);
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o26/overlay_26/partBuildCCTables.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void partSetupLib(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6) {
    s32 total;
    s32 i;
    s32 k;
    s32 cnt;
    s32 cont;
    s16 *tbl;
    s32 v;

    partFreeLib();
    if (arg0 < 0) {
        arg0 = 0x10;
    }
    if (arg1 < 0) {
        arg1 = 0x10;
    }
    if (arg2 < 0) {
        arg2 = 0xD0;
    }
    if (arg5 < 0) {
        arg5 = 0xF;
    }
    if (arg3 < 0) {
        arg3 = 0xA0;
    }
    if (arg4 < 0) {
        arg4 = 0x40;
    }
    if (arg6 < 0) {
        arg6 = 0x20;
    }

    total = (arg0 * 3) + (arg1 * 4) + arg2 + (arg3 * 0x12) + (arg4 * 0x78);
    maxlines = arg3;
    maxpointstreams = arg4;
    partvertices = mmAlloc(total * 0xA * 2, 0x80808080);
    D_800A5D90 = (u8 *) partvertices + (total * 0xA);

    partlists[0] = func_overlay_26_01A00AF4_1F44E9C(trivlut, tripartpolys, 3, 1, arg0);
    partlists[1] = func_overlay_26_01A00AF4_1F44E9C(rectvlut, rectpartpolys, 4, 2, arg1);
    partlists[2] = func_overlay_26_01A00AF4_1F44E9C(NULL, NULL, 0, 0, arg2);
    partlists[3] = func_overlay_26_01A00AF4_1F44E9C(NULL, NULL, 0, 0, arg5);
    pointstreams = func_overlay_26_01A00F1C_1F452C4(arg4);
    lines = func_overlay_26_01A00E60_1F45208(maxlines);
    func_overlay_26_01A00000_1F443A8();

    if (partgraphics == NULL) {
        tbl = (s16 *) piRomLoad(0x3C);
        cnt = 0;
        if (tbl[0] != -1) {
            k = 1;
            do {
                cnt = k;
                cont = tbl[k] != -1;
                k = k + 1;
            } while (cont);
        }
        partlistsize = cnt;
        partgraphics = mmAlloc(cnt * 4, 0x80808080);
        for (i = 0; i < cnt; i++) {
            v = tbl[i];
            if ((v & 0xC000) == 0) {
                ((s32 *) partgraphics)[i] = modLoadModel(v, 0, v);
            } else if ((v & 0xC000) == 0x8000) {
                ((s32 *) partgraphics)[i] = texLoadSprite(v & 0x3FFF, 1, v);
            } else if ((v & 0xC000) == 0xC000) {
                ((s32 *) partgraphics)[i] = (s32) texLoadTexture(v & 0x3FFF);
            }
        }
        mmFree(tbl);
    }

    trigdatbuffers = mmAlloc(arg6 * 0x28, 0x80808080);
    for (i = 0; i < arg6; i++) {
        *(u8 *)((u8 *) trigdatbuffers + (i * 0x28) + 0x24) = 0;
    }
    maxchildtriggerparticles = arg6;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o26/overlay_26/partSetupLib.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_overlay_26_01A00AF4_1F44E9C(void *arg0, void *arg1, s32 arg2, s32 arg3, s32 arg4) {
    s32 numWords;
    s32 rem;
    s32 blockSize;
    s32 lo;
    s32 lastWord;
    s32 i;
    s32 k;
    u8 *res;
    s32 *bits;

    numWords = arg4 >> 5;
    rem = arg4 & 0x1F;
    if (rem != 0) {
        numWords = numWords + 1;
    }
    blockSize = (arg4 * 0x78) + 0x38;
    blockSize = (blockSize - (blockSize & 3)) + 4;
    res = (u8 *) mmAlloc(blockSize + (numWords * 4), 0x80808080);
    *(s32 *)(res + 0x18) = arg4;
    *(u8 **)(res + 0x20) = res + blockSize;
    *(u8 **)(res + 0x14) = res + 0x38;
    lastWord = numWords - 1;
    *(s32 *)(res + 0x24) = lastWord;
    *(s32 *)(res + 0x28) = 0;
    *(s32 *)(res + 0x1C) = 0;
    *(s32 *)(res + 0x08) = arg3;
    *(s32 *)(res + 0x04) = arg2;
    *(void **)(res + 0x0C) = arg0;
    if (arg1 != NULL) {
        lo = (0x18 / arg2) * arg3;
        if (lo >= 0x11) {
            lo = 0x10;
        }
        *(void **)(res + 0x2C) = arg1;
        *(u8 **)(res + 0x30) = (u8 *) arg1 + (lo * 0x10);
        *(u8 **)(res + 0x34) = (u8 *) arg1 + (lo * 0x20);
    } else {
        *(s32 *)(res + 0x2C) = 0;
        *(s32 *)(res + 0x30) = 0;
        *(s32 *)(res + 0x34) = 0;
    }

    /* asm: each 0x78-byte entry gets +0x4C = 0 and +0x2C = 0x80 */
    for (i = 0; i < arg4; i++) {
        *(s32 *)(res + 0x38 + (i * 0x78) + 0x4C) = 0;
        *(s16 *)(res + 0x38 + (i * 0x78) + 0x2C) = 0x80;
    }

    bits = *(s32 **)(res + 0x20);
    if (lastWord >= 0) {
        for (i = 0; i <= lastWord; i++) {
            bits[i] = -1;
        }
    }
    if (rem != 0) {
        bits[lastWord] = 0;
        for (k = 0; k < rem; k++) {
            bits[lastWord] |= (s32) (1u << k);
        }
    }
    return res;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o26/overlay_26/func_overlay_26_01A00AF4_1F44E9C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_overlay_26_01A00E60_1F45208(s32 count) {
    u8 *ret;
    u8 *elem;
    u8 *v0;
    u8 *pA;
    u8 *pB;
    u8 *pC;
    u8 *pD;
    s32 i;
    s32 j;

    ret = (u8 *) mmAlloc(count * 0x148, 0x80808080);
    elem = ret;
    for (i = 0; i < count; i++) {
        *(s32 *)(elem + 0x00) = 0;
        *(u8 *)(elem + 0x124) = 0;
        *(u8 **)(elem + 0x04) = elem + 0x28;
        pA = elem + 0x1C + 0x28;
        pB = elem + 0x1C + 0x44;
        pC = elem + 0x1C + 0x60;
        pD = elem + 0x1C + 0x7C;
        v0 = elem + 0x04;
        for (j = 0; j < 2; j++) {
            *(u8 **)(v0 + 0x04) = pA;
            *(u8 **)(v0 + 0x08) = pB;
            *(u8 **)(v0 + 0x0C) = pC;
            *(u8 **)(v0 + 0x10) = pD;
            pA += 0x70;
            pB += 0x70;
            pC += 0x70;
            pD += 0x70;
            v0 += 0x10;
        }
        elem += 0x148;
    }
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o26/overlay_26/func_overlay_26_01A00E60_1F45208.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_overlay_26_01A00F1C_1F452C4(s32 count) {
    u8 *ret;
    u8 *elem;
    u8 *v0;
    s32 i;
    s32 j;

    ret = (u8 *) mmAlloc(count * 0xC0, 0x80808080);
    elem = ret;
    for (i = 0; i < count; i++) {
        *(s32 *)(elem + 0x3C) = 0;
        *(u8 *)(elem + 0xA4) = 0;
        *(s32 *)(elem + 0x00) = 0;
        *(s32 *)(elem + 0x04) = 0;
        *(s32 *)(elem + 0x08) = 0;
        v0 = elem + 0x0C;
        for (j = 0; j < 3; j++) {
            *(s32 *)(v0 + 0x00) = 0;
            *(s32 *)(v0 + 0x04) = 0;
            *(s32 *)(v0 + 0x08) = 0;
            *(s32 *)(v0 + 0x0C) = 0;
            v0 += 0x10;
        }
        elem += 0xC0;
    }
    D_801008F0 = func_overlay_26_01A00AF4_1F44E9C(NULL, NULL, 0, 0, count * 0xF);
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o26/overlay_26/func_overlay_26_01A00F1C_1F452C4.s")
#endif
