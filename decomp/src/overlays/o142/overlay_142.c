#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
#define RD_U8(p, off)  (*(u8 *)((u8 *)(p) + (off)))
#define RD_S16(p, off) (*(s16 *)((u8 *)(p) + (off)))
#define RD_U16(p, off) (*(u16 *)((u8 *)(p) + (off)))
#define RD_S32(p, off) (*(s32 *)((u8 *)(p) + (off)))
#define RD_F32(p, off) (*(f32 *)((u8 *)(p) + (off)))
#define RD_PTR(p, off) (*(u8 **)((u8 *)(p) + (off)))

extern u8 *D_overlay_142_08E01570;  /* line pool, 0x14-byte records (x0,y0,x1,y1,u8,u8) */
extern u8 *D_overlay_142_08E01574;  /* BSP node pool, 0x14-byte records */
extern u8 *D_overlay_142_08E01578;  /* split candidate pool, 0x14-byte records */
extern s32 D_overlay_142_08E0157C;  /* line count */
extern s32 D_overlay_142_08E01580;  /* node count (starts at 1) */
extern s32 D_overlay_142_08E01584;  /* candidate count */
extern s32 D_overlay_142_08E01588;  /* best candidate index */
extern s32 D_overlay_142_08E0158C;  /* split line point A x (int) */
extern s32 D_overlay_142_08E01590;  /* split line point A y (int) */
extern s32 D_overlay_142_08E01594;  /* split line point B x (int) */
extern s32 D_overlay_142_08E01598;  /* split line point B y (int) */
extern f32 D_overlay_142_08E0159C;  /* split line slope */
extern f32 D_overlay_142_08E015A0;  /* split line intercept */
extern s32 __MODULE00142;

s32 mathDiffAngle(s16, s16);
f32 Sinf(s16);
void _bzero(void *, s32);
s32 GetRegionIndex(void *, s32);
s32 runlinkSetDestructTimer(s32, s32, s32); /* asm passes 3 args */
void func_overlay_142_08E001BC_1FD8074(f32 arg0, f32 arg1, f32 arg2, f32 arg3, u8 arg4, u8 arg5);
void func_overlay_142_08E003B0_1FD8268(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 *arg4, f32 *arg5);
s32 func_overlay_142_08E002F4_1FD81AC(s32 arg0, s32 arg1);
u16 func_overlay_142_08E00930_1FD87E8(u8 *arg0, u8 *arg1, s32 arg2);
void func_overlay_142_08E00CFC_1FD8BB4(u8 *arg0, u8 *arg1);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_142_08E00000_1FD7EB8(u8 *arg0) {
    s32 rem;
    u8 *cur;
    u8 *next;
    s16 angCur;
    s16 angNext;
    s16 angLink;
    u16 count;

    count = RD_U16(arg0, 0x12);
    cur = D_overlay_142_08E01570 + (RD_U16(arg0, 0x10) * 0x14);
    if (count <= 1) {
        return 1;
    }
    rem = count - 1;
    do {
        angCur = Arctanf(RD_F32(cur, 0xC) - RD_F32(cur, 4), RD_F32(cur, 8) - RD_F32(cur, 0));
        if (rem == 0) {
            next = D_overlay_142_08E01570 + (RD_U16(arg0, 0x10) * 0x14);
        } else {
            next = cur + 0x14;
        }
        angNext = Arctanf(RD_F32(next, 0xC) - RD_F32(next, 4), RD_F32(next, 8) - RD_F32(next, 0));
        if ((RD_F32(next, 0) != RD_F32(cur, 8)) || (RD_F32(next, 4) != RD_F32(cur, 0xC))) {
            angLink = Arctanf(RD_F32(next, 4) - RD_F32(cur, 0xC), RD_F32(next, 0) - RD_F32(cur, 8));
            if ((mathDiffAngle(angCur, angLink) < 0) || (mathDiffAngle(angLink, angNext) < 0)) {
                return 0;
            }
        } else if (mathDiffAngle(angCur, angNext) < 0) {
            return 0;
        }
        cur = next;
    } while (rem-- != 0);
    return 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o142/overlay_142/func_overlay_142_08E00000_1FD7EB8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_142_08E001BC_1FD8074(f32 arg0, f32 arg1, f32 arg2, f32 arg3, u8 arg4, u8 arg5) {
    if (!((arg0 == arg2) && (arg1 == arg3))) {
        if (D_overlay_142_08E0157C >= 0xC00) {
            /* asm: spins forever when the line pool is full */
            for (;;) {}
        }
        RD_F32(D_overlay_142_08E01570 + (D_overlay_142_08E0157C * 0x14), 0) = arg0;
        RD_F32(D_overlay_142_08E01570 + (D_overlay_142_08E0157C * 0x14), 4) = arg1;
        RD_F32(D_overlay_142_08E01570 + (D_overlay_142_08E0157C * 0x14), 8) = arg2;
        RD_F32(D_overlay_142_08E01570 + (D_overlay_142_08E0157C * 0x14), 0xC) = arg3;
        RD_U8(D_overlay_142_08E01570 + (D_overlay_142_08E0157C * 0x14), 0x10) = arg4;
        RD_U8(D_overlay_142_08E01570 + (D_overlay_142_08E0157C * 0x14), 0x11) = arg5;
        D_overlay_142_08E0157C += 1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o142/overlay_142/func_overlay_142_08E001BC_1FD8074.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_142_08E002C0_1FD8178(s32 arg0, s32 arg1) {
    s32 t;

    if (arg1 < arg0) {
        t = arg0;
    } else {
        t = arg1;
    }
    return t;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o142/overlay_142/func_overlay_142_08E002C0_1FD8178.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_142_08E002DC_1FD8194(s32 arg0) {
    s32 t;

    t = -arg0;
    if (arg0 >= 0) {
        t = arg0;
    }
    return t;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o142/overlay_142/func_overlay_142_08E002DC_1FD8194.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_142_08E002F4_1FD81AC(s32 arg0, s32 arg1) {
    s32 cross;
    s32 absDx;

    cross = func_overlay_142_08E002DC_1FD8194(
        ((D_overlay_142_08E01598 - D_overlay_142_08E01590) * (arg0 - D_overlay_142_08E0158C))
        - ((arg1 - D_overlay_142_08E01590) * (D_overlay_142_08E01594 - D_overlay_142_08E0158C)));
    absDx = func_overlay_142_08E002DC_1FD8194(D_overlay_142_08E01594 - D_overlay_142_08E0158C);
    return cross < func_overlay_142_08E002C0_1FD8178(absDx,
        func_overlay_142_08E002DC_1FD8194(D_overlay_142_08E01598 - D_overlay_142_08E01590));
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o142/overlay_142/func_overlay_142_08E002F4_1FD81AC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_142_08E003B0_1FD8268(f32 arg0, f32 arg1, f32 arg2, f32 arg3, f32 *arg4, f32 *arg5) {
    f32 slope;
    f32 intercept;

    if (arg0 == arg2) {
        *arg4 = 0.0f;
        *arg5 = 0.0f;
        return;
    }
    slope = (arg3 - arg1) / (arg2 - arg0);
    intercept = arg1 - (slope * arg0);
    *arg4 = (D_overlay_142_08E015A0 - intercept) / (slope - D_overlay_142_08E0159C);
    *arg5 = (*arg4 * slope) + intercept;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o142/overlay_142/func_overlay_142_08E003B0_1FD8268.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_142_08E00444_1FD82FC(u8 *arg0) {
    s32 bestDiff;
    u8 *cand;
    u8 *seg;
    u8 *rec;
    u8 *best;
    s32 outer;
    s32 inner;
    s32 outIdx;
    s16 cnt2;
    s16 cnt3;
    s16 cnt4;
    s32 diff;
    s32 absDiff;
    f32 x0;
    f32 y0;
    f32 x1;
    f32 y1;
    s32 t4;
    s32 s5;

    bestDiff = 0x7FFFFFFF;
    D_overlay_142_08E01584 = 0;
    cand = D_overlay_142_08E01570 + (RD_U16(arg0, 0x10) * 0x14);
    outer = RD_U16(arg0, 0x12) - 1;
    if (RD_U16(arg0, 0x12) != 0) {
        do {
            if (RD_F32(cand, 8) != RD_F32(cand, 0)) {
                cnt2 = 0;
                cnt3 = 0;
                cnt4 = 0;
                D_overlay_142_08E0159C = (RD_F32(cand, 0xC) - RD_F32(cand, 4)) / (RD_F32(cand, 8) - RD_F32(cand, 0));
                D_overlay_142_08E015A0 = RD_F32(cand, 4) - (D_overlay_142_08E0159C * RD_F32(cand, 0));

                seg = D_overlay_142_08E01570 + (RD_U16(arg0, 0x10) * 0x14);
                inner = RD_U16(arg0, 0x12) - 1;
                if (RD_U16(arg0, 0x12) != 0) {
                    do {
                        if (outer != inner) {
                            f32 segX0 = RD_F32(seg, 0);
                            f32 segY0 = RD_F32(seg, 4);
                            f32 segX1 = RD_F32(seg, 8);
                            f32 segY1 = RD_F32(seg, 0xC);

                            t4 = 0;
                            if (segY0 < ((D_overlay_142_08E0159C * segX0) + D_overlay_142_08E015A0)) {
                                t4 = 1;
                            }
                            s5 = 0;
                            if (segY1 < ((D_overlay_142_08E0159C * segX1) + D_overlay_142_08E015A0)) {
                                s5 = 1;
                            }
                            if ((segX1 == RD_F32(cand, 0)) && (segY1 == RD_F32(cand, 4))) {
                                s5 = t4;
                            }
                            if ((segX0 == RD_F32(cand, 8)) && (segY0 == RD_F32(cand, 0xC))) {
                                t4 = s5;
                            }
                            if (t4 != s5) {
                                cnt4 += 1;
                            } else if (t4 != 0) {
                                cnt3 += 1;
                            } else {
                                cnt2 += 1;
                            }
                        }
                        seg += 0x14;
                        inner -= 1;
                    } while (inner != 0);
                }

                diff = cnt3 - cnt2;
                absDiff = diff;
                if (diff < 0) {
                    absDiff = -diff;
                }
                if (absDiff < bestDiff) {
                    D_overlay_142_08E01584 = 0;
                    bestDiff = absDiff;
                }
                if (!(bestDiff < absDiff)) {
                    rec = D_overlay_142_08E01578 + (D_overlay_142_08E01584 * 0x14);
                    RD_F32(rec, 0) = D_overlay_142_08E0159C;
                    RD_F32(rec, 4) = D_overlay_142_08E015A0;
                    RD_S32(rec, 8) = (s32) (cand - D_overlay_142_08E01570) / 20;
                    RD_S16(rec, 0xC) = cnt2;
                    RD_S16(rec, 0xE) = cnt3;
                    RD_S32(rec, 0x10) = cnt4;
                    if (D_overlay_142_08E01584 < 0x20) {
                        D_overlay_142_08E01584 += 1;
                    }
                }
            }
            cand += 0x14;
            outer -= 1;
        } while (outer != 0);
    }

    outIdx = D_overlay_142_08E01584 - 1;
    if (D_overlay_142_08E01584 != 0) {
        rec = D_overlay_142_08E01578 + (outIdx * 0x14);
        do {
            rec -= 0x14;
            if (RD_S32(rec, 0x10) < 0x0FFFFFFF) {
                D_overlay_142_08E01588 = outIdx;
            }
            outIdx -= 1;
        } while (outIdx != 0);
    }

    best = D_overlay_142_08E01578 + (D_overlay_142_08E01588 * 0x14);
    D_overlay_142_08E0159C = RD_F32(best, 0);
    RD_F32(arg0, 8) = D_overlay_142_08E0159C;
    D_overlay_142_08E015A0 = RD_F32(best, 4);
    RD_F32(arg0, 0xC) = D_overlay_142_08E015A0;
    D_overlay_142_08E01588 = RD_S32(best, 8);
    rec = D_overlay_142_08E01570 + (D_overlay_142_08E01588 * 0x14);
    D_overlay_142_08E0158C = (s32) RD_F32(rec, 0);
    D_overlay_142_08E01590 = (s32) RD_F32(rec, 4);
    D_overlay_142_08E01594 = (s32) RD_F32(rec, 8);
    D_overlay_142_08E01598 = (s32) RD_F32(rec, 0xC);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o142/overlay_142/func_overlay_142_08E00444_1FD82FC.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u16 func_overlay_142_08E00930_1FD87E8(u8 *arg0, u8 *arg1, s32 arg2) {
    u8 *cur;
    f32 sp6C;
    f32 sp68;
    u16 remaining;
    u16 retv;
    s32 side0;
    s32 side1;
    s32 t1;
    u16 count;

    count = RD_U16(arg0, 0x12);
    RD_U16(arg1, 0x10) = (u16) D_overlay_142_08E0157C;
    cur = D_overlay_142_08E01570 + (RD_U16(arg0, 0x10) * 0x14);
    remaining = count - 1;
    retv = count;
    if (count != 0) {
        do {
            side0 = 0;
            if (RD_F32(cur, 4) < ((D_overlay_142_08E0159C * RD_F32(cur, 0)) + D_overlay_142_08E015A0)) {
                side0 = 1;
            }
            side1 = 0;
            if (RD_F32(cur, 0xC) < ((D_overlay_142_08E0159C * RD_F32(cur, 8)) + D_overlay_142_08E015A0)) {
                side1 = 1;
            }
            if (func_overlay_142_08E002F4_1FD81AC((s32) RD_F32(cur, 0), (s32) RD_F32(cur, 4)) != 0) {
                side0 = side1;
            }
            if (func_overlay_142_08E002F4_1FD81AC((s32) RD_F32(cur, 8), (s32) RD_F32(cur, 0xC)) != 0) {
                side1 = side0;
            }
            if (D_overlay_142_08E01588 == ((s32) (cur - D_overlay_142_08E01570) / 20)) {
                s32 ang = Arctanf(RD_F32(cur, 0xC) - RD_F32(cur, 4), RD_F32(cur, 8) - RD_F32(cur, 0));

                sp6C = (Sinf((s16) (ang * -1)) * 100.0f) + RD_F32(cur, 0);
                sp68 = (Cosf((s32) (s16) (ang * -1)) * 100.0f) + RD_F32(cur, 4);
                t1 = 0;
                if (sp68 < ((D_overlay_142_08E0159C * sp6C) + D_overlay_142_08E015A0)) {
                    t1 = 1;
                }
                retv = remaining;
                if (arg2 == t1) {
                    func_overlay_142_08E001BC_1FD8074(RD_F32(cur, 0), RD_F32(cur, 4), RD_F32(cur, 8), RD_F32(cur, 0xC),
                        RD_U8(cur, 0x10), RD_U8(cur, 0x11));
                }
            } else {
                if (side0 != side1) {
                    func_overlay_142_08E003B0_1FD8268(RD_F32(cur, 0), RD_F32(cur, 4), RD_F32(cur, 8), RD_F32(cur, 0xC), &sp6C, &sp68);
                    if (side0 == arg2) {
                        func_overlay_142_08E001BC_1FD8074(RD_F32(cur, 0), RD_F32(cur, 4), sp6C, sp68, RD_U8(cur, 0x10), RD_U8(cur, 0x11));
                    } else {
                        func_overlay_142_08E001BC_1FD8074(sp6C, sp68, RD_F32(cur, 8), RD_F32(cur, 0xC), RD_U8(cur, 0x10), RD_U8(cur, 0x11));
                    }
                    retv = remaining;
                } else {
                    retv = remaining;
                    if (side0 == arg2) {
                        func_overlay_142_08E001BC_1FD8074(RD_F32(cur, 0), RD_F32(cur, 4), RD_F32(cur, 8), RD_F32(cur, 0xC),
                            RD_U8(cur, 0x10), RD_U8(cur, 0x11));
                        retv = remaining;
                    }
                }
            }
            cur += 0x14;
            remaining -= 1;
        } while (remaining != 0);
    }
    RD_S16(arg1, 0x12) = (s16) (D_overlay_142_08E0157C - RD_U16(arg1, 0x10));
    return retv;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o142/overlay_142/func_overlay_142_08E00930_1FD87E8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_142_08E00CFC_1FD8BB4(u8 *arg0, u8 *arg1) {
    u8 *cur;
    u8 *prev;

    cur = arg1;
    prev = arg0;
    for (;;) {
        if (func_overlay_142_08E00000_1FD7EB8(cur) != 0) {
            break;
        }
        func_overlay_142_08E00444_1FD82FC(cur);
        if (!((prev == NULL) || (RD_F32(cur, 8) != RD_F32(prev, 8)) || (RD_F32(cur, 0xC) != RD_F32(prev, 0xC)))) {
            break;
        }
        RD_PTR(cur, 0) = D_overlay_142_08E01574 + (D_overlay_142_08E01580 * 0x14);
        D_overlay_142_08E01580 += 1;
        func_overlay_142_08E00930_1FD87E8(cur, RD_PTR(cur, 0), 1);
        RD_PTR(cur, 4) = D_overlay_142_08E01574 + (D_overlay_142_08E01580 * 0x14);
        D_overlay_142_08E01580 += 1;
        func_overlay_142_08E00930_1FD87E8(cur, RD_PTR(cur, 4), 0);
        func_overlay_142_08E00CFC_1FD8BB4(cur, RD_PTR(cur, 0));
        prev = cur;
        cur = RD_PTR(cur, 4);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o142/overlay_142/func_overlay_142_08E00CFC_1FD8BB4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void CreateBSP(u8 *arg0, s32 arg1) {
    u8 *sp4C;
    u8 *pts;
    u8 *ptsEnd;
    u8 *cur;
    u8 *nxt;
    u8 *sub;
    u8 *subPts;
    u8 *subEnd;
    u8 *out;
    u8 *a2;
    u8 *a3;
    u8 *leafBase;
    u8 *leafCur;
    u8 *src;
    s32 regionIdx;
    s32 n;
    s32 k;
    s32 flag;
    s32 subN;
    s32 left;
    s32 cnt;
    s32 i;
    s32 savedDelay;

    regionIdx = GetRegionIndex(arg0, arg1);
    runlinkSetDestructTimer(__MODULE00142, 2, 2);
    D_overlay_142_08E01570 = (u8 *) mmAlloc(0xF000, -1U);
    D_overlay_142_08E01574 = (u8 *) mmAlloc(0x2800, -1U);
    D_overlay_142_08E01578 = (u8 *) mmAlloc(0x2800, -1U);
    _bzero(D_overlay_142_08E01570, 0xF000);
    _bzero(D_overlay_142_08E01574, 0x2800);
    _bzero(D_overlay_142_08E01578, 0x2800);
    D_overlay_142_08E0157C = 0;
    D_overlay_142_08E01580 = 1;

    n = RD_S32(arg0, 4);
    pts = RD_PTR(arg0, 0);
    ptsEnd = pts + (n * 4) - 4;
    sp4C = D_overlay_142_08E01574;
    for (k = 0; k < n; k++) {
        cur = pts + (k * 4);
        nxt = (cur < ptsEnd) ? (cur + 4) : pts;
        func_overlay_142_08E001BC_1FD8074((f32) RD_S16(cur, 0), (f32) RD_S16(cur, 2),
            (f32) RD_S16(nxt, 0), (f32) RD_S16(nxt, 2), k, regionIdx & 0xFF);
    }
    RD_S16(sp4C, 0x12) = (s16) D_overlay_142_08E0157C;

    if (arg1 != 0) {
        sub = RD_PTR(arg0, 0x10);
        if (sub != NULL) {
            do {
                if ((RD_S32(sub, 0x14) & 1) && !(RD_S32(arg0, 0x14) & 0x12)) {
                    flag = GetRegionIndex(sub, (s32) sp4C);
                    subN = RD_S32(sub, 4);
                    subPts = RD_PTR(sub, 0);
                    subEnd = subPts + (subN * 4) - 4;
                    for (k = 0; k < subN; k++) {
                        cur = subPts + (k * 4);
                        nxt = (cur < subEnd) ? (cur + 4) : subPts;
                        func_overlay_142_08E001BC_1FD8074((f32) RD_S16(cur, 0), (f32) RD_S16(cur, 2),
                            (f32) RD_S16(nxt, 0), (f32) RD_S16(nxt, 2), k, flag & 0xFF);
                    }
                    RD_S16(sp4C, 0x12) = (s16) D_overlay_142_08E0157C;
                }
                sub = RD_PTR(sub, 0x10);
            } while (sub != NULL);
        }
    }

    func_overlay_142_08E00CFC_1FD8BB4(NULL, sp4C);

    out = (u8 *) mmAlloc((D_overlay_142_08E01580 * 0x14) + (D_overlay_142_08E0157C * 0x14), -1U);
    RD_PTR(arg0, 0x18) = out;
    a3 = out;
    leafBase = out + (D_overlay_142_08E01580 * 0x14);
    RD_PTR(arg0, 0x1C) = leafBase;
    leafCur = leafBase;
    a2 = D_overlay_142_08E01574;
    left = D_overlay_142_08E01580 - 1;
    if (D_overlay_142_08E01580 != 0) {
        do {
            if (RD_S32(a2, 4) != 0) {
                RD_PTR(a3, 0) = out + ((((s32) (RD_PTR(a2, 0) - D_overlay_142_08E01574)) / 20) * 0x14);
                RD_PTR(a3, 4) = out + ((((s32) (RD_PTR(a2, 4) - D_overlay_142_08E01574)) / 20) * 0x14);
                RD_F32(a3, 8) = RD_F32(a2, 8);
                RD_S32(a3, 0x10) = 0;
                RD_F32(a3, 0xC) = RD_F32(a2, 0xC);
            } else {
                RD_S16(a3, 0) = (s16) ((s32) (leafCur - leafBase) / 20);
                RD_S32(a3, 0x10) = 1;
                RD_U16(a3, 2) = RD_U16(a2, 0x12);
                cnt = RD_U16(a2, 0x12);
                src = D_overlay_142_08E01570 + (RD_U16(a2, 0x10) * 0x14);
                for (i = 0; i < cnt; i++) {
                    RD_S32(leafCur, 0) = RD_S32(src, 0);
                    RD_S32(leafCur, 4) = RD_S32(src, 4);
                    RD_S32(leafCur, 8) = RD_S32(src, 8);
                    RD_S32(leafCur, 0xC) = RD_S32(src, 0xC);
                    RD_U8(leafCur, 0x10) = RD_U8(src, 0x10);
                    RD_U8(leafCur, 0x11) = RD_U8(src, 0x11);
                    leafCur += 0x14;
                    src += 0x14;
                }
            }
            a2 += 0x14;
            a3 += 0x14;
            left -= 1;
        } while (left != 0);
    }

    savedDelay = mmGetDelay();
    mmSetDelay(0);
    mmFree(RD_PTR(arg0, 0x18));
    mmSetDelay(savedDelay);
    mmAllocAtAddr((D_overlay_142_08E01580 * 0x14) + (((s32) (leafCur - leafBase) / 20) * 0x14),
        RD_PTR(arg0, 0x18), -1U);
    savedDelay = mmGetDelay();
    mmSetDelay(0);
    mmFree(D_overlay_142_08E01570);
    mmFree(D_overlay_142_08E01574);
    mmFree(D_overlay_142_08E01578);
    mmSetDelay(savedDelay);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o142/overlay_142/CreateBSP.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void CreateBSPFromRegion(u8 *arg0) {
    CreateBSP(arg0, 1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o142/overlay_142/CreateBSPFromRegion.s")
#endif
