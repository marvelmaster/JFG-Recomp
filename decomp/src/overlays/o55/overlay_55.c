#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
typedef struct FmvPlayerRaw {
    s8 id;          /* 0x00: -1 = free slot */
    s8 mode;        /* 0x01 */
    u8 flags;       /* 0x02: bit0 dir, bit1 reverse, bit2 loop, bit7 init pending */
    s8 unk3;        /* 0x03: arg3 */
    s32 pos;        /* 0x04: frame position (<<8 fixed point) */
    s16 unk8;       /* 0x08: arg1 */
    s16 unkA;       /* 0x0A: arg2 */
    u8 pad_C[2];
    s8 unkE;        /* 0x0E: buffer slot A */
    s8 unkF;        /* 0x0F: buffer slot B */
    s8 tile[4];     /* 0x10: tile index held by each buffer slot */
    void *buf[4];   /* 0x14: buffers from mmAlloc */
} FmvPlayerRaw;

typedef struct FmvEntry {
    s16 unk0;       /* 0x00: width-ish factor */
    s16 unk2;       /* 0x02: height-ish factor */
    s16 unk4;       /* 0x04: frame count */
    u8 unk6;        /* 0x06: type */
    u8 unk7;        /* 0x07: rate */
    s32 unk8;       /* 0x08: ROM offset */
    s32 unkC;       /* 0x0C: per-tile size */
} FmvEntry;

extern FmvPlayerRaw Player[];
extern FmvEntry *Table[];                       /* Table[0] is the entry base */
extern u8 D_overlay_55_03700B80[];
extern u8 D_overlay_55_03700BA8[];

void fmvStop(FmvPlayerRaw *arg0);
void viFrameRateReset(void);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
FmvPlayerRaw *fmvStart(s8 arg0, s16 arg1, s16 arg2, s8 arg3, s32 arg4) {
    FmvPlayerRaw *p;
    FmvPlayerRaw *cur;
    FmvEntry *e;
    s32 idx;
    s32 div;
    s32 size;
    s32 i;
    s8 t7;
    u8 type;

    /* asm: scans Player[] for a free slot; the loop reads one entry
     * past the candidate before giving up. */
    cur = Player;
    idx = 2;
    if (cur->id >= 0) {
        idx = 1;
        do {
            t7 = cur[1].id;
            cur++;
            if (t7 < 0) {
                break;
            }
        } while (idx-- != 0);
    }
    if (idx < 0) {
        return NULL;
    }
    p = cur;

    e = Table[0] + arg0;
    type = e->unk6;
    switch (type) {
    case 0:
        div = 0x20;
        p->mode = 0;
        break;
    case 1:
        div = 4;
        p->mode = 3;
        break;
    case 2:
        div = 8;
        p->mode = 2;
        break;
    case 3:
        div = 0x10;
        p->mode = 1;
        break;
    default:
        div = 0;
        p->mode = 0;
        break;
    }

    size = (s32)(e->unk0 * div * e->unk2) >> 3;
    if (size != 0) {
        p->id = arg0;
        p->unk3 = arg3;
        p->flags = (u8)(arg4 | 0x80);
        p->pos = 0;
        p->unk8 = arg1;
        p->unkA = arg2;
        p->unkE = -1;
        p->unkF = -1;
        for (i = 0; i < 4; i++) {
            p->tile[i] = -1;
            p->buf[i] = mmAlloc(size, -1);
        }
        if (p->buf[0] == NULL || p->buf[1] == NULL || p->buf[2] == NULL || p->buf[3] == NULL) {
            fmvStop(p);
            p = NULL;
        } else {
            p->tile[0] = 0;
            piRomLoadSection(0x46, (u32)p->buf[0], e->unk8, e->unkC);
            p->tile[1] = 1;
            piRomLoadSection(0x46, (u32)p->buf[1], e->unk8 + e->unkC, e->unkC);
            viFrameRateReset();
        }
    }
    return p;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o55/overlay_55/fmvStart.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fmvStop(FmvPlayerRaw *arg0) {
    s32 i;

    if (arg0 != NULL && arg0->id != -1) {
        arg0->id = -1;
        for (i = 0; i < 4; i++) {
            if (arg0->buf[i] != NULL) {
                mmFree(arg0->buf[i]);
                arg0->buf[i] = NULL;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o55/overlay_55/fmvStop.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fmvUpdate(FmvPlayerRaw *arg0, s32 arg1) {
    FmvEntry *e;
    s32 limit;
    s32 pos;
    s32 lo;
    s32 sum;
    s32 diff;
    s32 tile;
    s32 next;
    s32 t0;
    s32 t1;
    s32 i;
    u8 fl;

    if (arg0 == NULL || arg0->id == -1) {
        return;
    }
    e = Table[0] + arg0->id;
    if (arg0->flags & 4) {
        limit = (e->unk4 << 8) - 1;
    } else {
        limit = (e->unk4 - 1) << 8;
    }

    if (arg0->flags & 0x80) {
        pos = arg0->pos;
        arg0->flags = arg0->flags & 0xFF7F;
    } else {
        pos = arg0->pos;
        lo = ((s32)(e->unk7 << 8) / 60) * arg1;
        do {
            sum = pos + lo;
            if (arg0->flags & 1) {
                diff = pos - lo;
                arg0->pos = diff;
                pos = diff;
                if (diff < 0) {
                    fl = arg0->flags;
                    if (fl & 4) {
                        if (fl & 2) {
                            arg0->pos = -diff;
                            arg0->flags = fl & ~1;
                        } else {
                            arg0->pos = pos + limit;
                        }
                        pos = arg0->pos;
                    } else {
                        arg0->pos = 0;
                        pos = 0;
                    }
                }
            } else {
                arg0->pos = sum;
                pos = sum;
                if (limit < sum) {
                    fl = arg0->flags;
                    if (fl & 2) {
                        pos = (limit - sum) + limit;
                        arg0->pos = pos;
                        arg0->flags = fl | 1;
                    } else {
                        if (fl & 4) {
                            arg0->pos = pos - limit;
                            pos = arg0->pos;
                        } else {
                            arg0->pos = limit;
                            pos = limit;
                        }
                    }
                }
            }
        } while (pos < 0 || limit < pos);
    }

    tile = pos >> 8;
    next = tile + 1;
    if (next >= e->unk4) {
        next = 0;
    }

    /* asm: find which buffer slots already hold the current / next tile */
    t0 = -1;
    t1 = -1;
    i = 3;
    do {
        if (arg0->tile[i] == tile) {
            t0 = i;
        }
        if (arg0->tile[i] == next) {
            t1 = i;
        }
    } while (i-- != 0);

    if (t0 < 0) {
        i = 3;
        do {
            if (i != t1 && i != arg0->unkE && i != arg0->unkF) {
                arg0->tile[i] = (s8)tile;
                piRomLoadSection(0x46, (u32)arg0->buf[i], e->unk8 + (tile * e->unkC), e->unkC);
                t0 = i;
                break;
            }
        } while (i-- != 0);
    }

    if (t1 < 0) {
        i = 3;
        do {
            if (i != t0 && i != arg0->unkE && i != arg0->unkF) {
                arg0->tile[i] = (s8)next;
                piRomLoadSection(0x46, (u32)arg0->buf[i], e->unk8 + (next * e->unkC), e->unkC);
                t1 = i;
                break;
            }
        } while (i-- != 0);
    }

    arg0->unkE = (s8)t0;
    arg0->unkF = (s8)t1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o55/overlay_55/fmvUpdate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
/* Appends one 64-bit display list command and advances the list pointer. */
static void fmvGfxWord(Gfx **dl, u32 hi, u32 lo) {
    Gfx *g = *dl;

    *dl = g + 1;
    g->words.w0 = hi;
    g->words.w1 = lo;
}

void fmvDraw(FmvPlayerRaw *arg0, Gfx **arg1, f32 arg2) {
    FmvEntry *e;
    u32 s0;
    u32 s1;
    s32 w0;
    s32 var_t2;
    s32 var_t3;
    s32 stride;
    s32 t6;
    s32 t5;
    s32 spE4;
    s32 t8;
    s32 t8_2;
    s32 t8_3;
    s32 v1_3;
    s32 a3;
    s32 a3_2;
    s32 t0_2;
    s32 t4_2;
    s32 sp54;
    s32 sp4C;
    s32 sp48;
    s32 sp44;
    s32 sp40;
    s32 sp50;
    s32 sp58;
    s32 lo;
    u8 c;

    if (arg0 == NULL || arg0->id == -1) {
        return;
    }
    e = Table[0] + arg0->id;
    s0 = (u32)arg0->buf[arg0->unkE];
    w0 = e->unk0;
    var_t3 = e->unk2;
    s1 = (u32)arg0->buf[arg0->unkF];

    if (arg2 == 1.0f) {
        fmvGfxWord(arg1, 0x06000000, (u32)D_overlay_55_03700B80);
    } else {
        fmvGfxWord(arg1, 0x06000000, (u32)D_overlay_55_03700BA8);
    }
    c = arg0->unk3;
    fmvGfxWord(arg1, 0xFA000000, (c << 24) | (c << 16) | (c << 8) | 0xFF);
    c = arg0->pos & 0xFF;
    fmvGfxWord(arg1, 0xFB000000, (c << 24) | (c << 16) | (c << 8) | c);

    t6 = arg0->unk8 * 4;
    stride = w0 * 2;
    t5 = arg0->unkA << 16;
    spE4 = t5;

    if (var_t3 != 0) {
        v1_3 = (s32)(1024.0f / arg2) & 0xFFFF;
        t8 = (0x800 / stride) & ~1;
        t8_2 = ((((stride + 7) >> 3) & 0x1FF) << 9) | 0xF5100000;
        t8_3 = (((w0 - 1) * 4) & 0xFFF) << 12;
        sp54 = t8_2 | 0x100;
        sp4C = t8_3 | 0x01000000;
        sp48 = ((((s32)((f32)w0 * arg2 * 4.0f) + t6) & 0xFFF) << 12) | 0xE4000000;
        sp44 = (t6 & 0xFFF) << 12;
        sp40 = (v1_3 << 16) | v1_3;
        sp50 = t8_3;
        sp58 = t8_2;
        do {
            var_t2 = var_t3;
            if (t8 < var_t3) {
                var_t2 = t8;
                var_t3 -= t8;
            } else {
                var_t3 = 0;
            }
            t0_2 = (w0 * var_t2) - 1;
            a3 = (t0_2 < 0x7FF) ? t0_2 : 0x7FF;
            a3_2 = a3;
            t4_2 = ((var_t2 - 1) * 4) & 0xFFF;

            fmvGfxWord(arg1, 0xFD100000, s1);
            fmvGfxWord(arg1, 0xF5100100, 0x07080200);
            t5 += (s32)((f32)var_t2 * (arg2 * 65536.0f));
            fmvGfxWord(arg1, 0xE6000000, 0);
            fmvGfxWord(arg1, 0xF3000000, ((a3 & 0xFFF) << 12) | 0x07000000);
            fmvGfxWord(arg1, 0xE7000000, 0);
            fmvGfxWord(arg1, sp54, 0x01080200);
            fmvGfxWord(arg1, 0xF2000000, sp4C | t4_2);
            fmvGfxWord(arg1, 0xFD100000, s0);
            fmvGfxWord(arg1, 0xF5100000, 0x07080200);
            fmvGfxWord(arg1, 0xE6000000, 0);
            fmvGfxWord(arg1, 0xF3000000, ((a3_2 & 0xFFF) << 12) | 0x07000000);
            fmvGfxWord(arg1, 0xE7000000, 0);
            fmvGfxWord(arg1, sp58, 0x00080200);
            fmvGfxWord(arg1, 0xF2000000, sp50 | t4_2);
            fmvGfxWord(arg1, sp48 | ((t5 >> 14) & 0xFFF), sp44 | ((spE4 >> 14) & 0xFFF));
            fmvGfxWord(arg1, 0xB3000000, 0);
            fmvGfxWord(arg1, 0xB2000000, sp40);
            spE4 = t5;
            lo = var_t2 * stride;
            s0 += lo;
            s1 += lo;
        } while (var_t3 != 0);
    }

    texDPInit(arg1);
    fmvGfxWord(arg1, 0xFA000000, 0xFFFFFFFF);
    fmvGfxWord(arg1, 0xFB000000, 0xFFFFFFFF);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o55/overlay_55/fmvDraw.s")
#endif
