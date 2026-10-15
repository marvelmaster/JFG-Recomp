#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#define RD_U8(p, off)  (*(u8 *)((u8 *)(p) + (off)))
#define RD_S8(p, off)  (*(s8 *)((u8 *)(p) + (off)))
#define RD_S16(p, off) (*(s16 *)((u8 *)(p) + (off)))
#define RD_F32(p, off) (*(f32 *)((u8 *)(p) + (off)))
#define RD_PTR(p, off) (*(u8 **)((u8 *)(p) + (off)))
#define RD_S32(p, off) (*(s32 *)((u8 *)(p) + (off)))
#define RD_U16(p, off) (*(u16 *)((u8 *)(p) + (off)))
extern f32 D_overlay_105_06901F00;
extern f32 D_overlay_105_06901F04;
extern f32 D_overlay_105_06901F08;
extern f32 D_overlay_105_06901F0C;
void hitInitObjectHit(void *obj, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6, f32 f0, f32 f1, f32 f2, f32 f3, s32 a11);
f32 Powerf(f32 base, s32 n);
f32 Sinf(s16 angle);
void amSndPlayXYZ(u16 soundId, f32 x, f32 y, f32 z, u8 arg4, void *soundMask);
void amSndStopXYZ(void *soundMask);
void amSndSetPitchXYZ(void *soundMask, s32 pitch);
void func_overlay_105_069015F4_1FBBE24(void *arg0, void *arg1, void *arg2);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Bridge state (obj+0x68, "data"): +0x00 path table ptr (= data+0x30), +0x08 f32 (placement +0x0E * D1F00),
// +0x0C f32 (+0x20 * D1F04 / (count-1)), +0x20 f32 (placement +0x0B), +0x24 f32 (placement +0x0A),
// +0x2C s16 (placement +0x10, path spacing), +0x2E u8 direction, +0x2F u8 (model vertex-ref count - 1).
// Path table entries are 0x28 bytes: +0x00 f32 along-path coord, +0x04 f32, +0x10 f32, +0x18/+0x1C f32,
// +0x24 s32 integer coord. Model header (Prop+0x00) fields used: +0x12 s16 vertex count, +0x1C vertex
// array (stride 0xA), +0x2D u8 vertex-ref count, +0x30 u16 vertex-ref indices (stride 4).
// Prop+0x18 / +0x1C are per-vertex s16 buffers (stride 0xA), Prop+0x8E / +0x92 are s16 min / max Y.
// Layout cross-checked against jfg-re docs/levels.md (bridge behavior 55) and
// jfg_forge/core/level_objects.py (hitBridgeInit scale/yaw from placement +0x0C / +0x0D).
void hitBridgeInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *pl = (u8 *)arg1;
    u8 *data;
    u8 *prop;
    u8 *hdr;
    u8 *tbl;
    u8 *ent;
    u8 *vtx;
    u8 *bufA;
    u8 *bufB;
    u8 *refs;
    s32 count;
    s32 last;
    s32 spanX;
    s32 baseX;
    s32 lastX;
    s32 vcount;
    s32 x;
    s32 newX;
    s32 idx;
    s32 maxY;
    s32 minY;
    s32 i;
    s32 k;
    f32 f0;
    f32 f2;
    f32 f16;

    RD_F32(obj, 0x8) = RD_F32(RD_PTR(obj, 0x40), 0) * ((f32)RD_U8(pl, 0xC) * 0.015625f);
    RD_S16(obj, 0x2) = 0;
    RD_S16(obj, 0x0) = (s16)(RD_U8(pl, 0xD) << 8);
    RD_S16(obj, 0x4) = 0;
    hitInitObjectHit(arg0, -1, 0, 8, 0, 0, 0, 32.0f, 32.0f, -1.0f, 1.0f, 1);

    maxY = 0;
    prop = *(u8 **)(RD_PTR(obj, 0x6C) + RD_S8(obj, 0x3A) * 4);
    data = RD_PTR(obj, 0x68);
    hdr = RD_PTR(prop, 0);

    count = RD_U8(hdr, 0x2D);
    RD_U8(data, 0x2F) = (u8)(count - 1);
    RD_F32(data, 0x20) = (f32)RD_U8(pl, 0xB);
    RD_F32(data, 0x8) = (f32)RD_U8(pl, 0xE) * D_overlay_105_06901F00;
    RD_U8(data, 0x2E) = 0;
    RD_F32(data, 0xC) = (RD_F32(data, 0x20) * D_overlay_105_06901F04) / (f32)RD_U8(data, 0x2F);
    RD_F32(data, 0x24) = (f32)RD_U8(pl, 0xA);
    RD_S32(data, 0x4) = 0;
    RD_U8(data, 0x2F) = (u8)(count - 1);
    RD_PTR(data, 0) = data + 0x30;
    RD_S16(data, 0x2C) = (s16)RD_U8(pl, 0x10);

    // Seed the path table from the model's vertex references (u16 index, stride 4).
    tbl = RD_PTR(data, 0);
    refs = RD_PTR(hdr, 0x30);
    vtx = RD_PTR(hdr, 0x1C);
    for (i = 0; i < count; i++) {
        vtx = RD_PTR(hdr, 0x1C) + RD_U16(refs, i * 4) * 0xA;
        ent = tbl + i * 0x28;
        RD_S32(ent, 0x24) = RD_S16(vtx, 0);
        RD_F32(ent, 0x0) = (f32)RD_S16(vtx, 0);
        RD_F32(ent, 0x4) = (f32)RD_S16(vtx, 2);
        RD_F32(ent, 0x8) = (f32)RD_S16(vtx, 4);
    }

    last = RD_U8(data, 0x2F);
    spanX = RD_S16(data, 0x2C);
    baseX = RD_S32(tbl, 0x24);
    lastX = RD_S32(tbl + last * 0x28, 0x24);
    vcount = RD_S16(hdr, 0x12);

    // Vertices lying in [baseX, lastX] are clamped to the path, and the highest
    // resulting X is kept in maxY (asm: s4).
    bufA = RD_PTR(prop, 0x18);
    bufB = RD_PTR(prop, 0x1C);
    vtx = RD_PTR(hdr, 0x1C);
    for (i = 0; i < vcount; i++) {
        x = RD_S16(vtx, 0);
        if (lastX < x) {
            RD_S16(bufA, 0) = (s16)((x - lastX) + (spanX * last + baseX));
            RD_S16(bufB, 0) = RD_S16(bufA, 0);
            if (maxY < RD_S16(bufA, 0)) {
                maxY = RD_S16(bufA, 0);
            }
        }
        vtx += 0xA;
        bufA += 0xA;
        bufB += 0xA;
    }

    // Path entries 1..last get evenly spaced X coordinates; vertices sitting on
    // the old coordinate of an entry are moved onto the new one.
    for (i = 1; i <= last; i++) {
        newX = (s16)(spanX * i + baseX);
        bufA = RD_PTR(prop, 0x18);
        bufB = RD_PTR(prop, 0x1C);
        vtx = RD_PTR(hdr, 0x1C);
        for (k = 0; k < vcount; k++) {
            if (RD_S16(vtx, 0) == RD_S32(tbl + i * 0x28, 0x24)) {
                RD_S16(bufA, 0) = (s16)newX;
                RD_S16(bufB, 0) = (s16)newX;
            }
            vtx += 0xA;
            bufA += 0xA;
            bufB += 0xA;
        }
        RD_S32(tbl + i * 0x28, 0x24) = (s16)newX;
        RD_F32(tbl + i * 0x28, 0x0) = (f32)(s16)newX;
    }

    // Per-entry height from the midpoint coordinate f16 (first and last entry).
    f2 = RD_F32(tbl, 0);
    f16 = ((RD_F32(tbl + last * 0x28, 0) - f2) * 0.5f) + f2;
    f0 = (f32)last;
    if (RD_F32(tbl, 0x28) < f16) {
        k = 1;
        do {
            RD_F32(tbl + k * 0x28, 0xC) = RD_F32(data, 0xC) * f0;
            RD_F32(tbl + k * 0x28, 0x10) = (RD_F32(tbl + k * 0x28, 0xC) / RD_F32(data, 0x24)) +
                                           RD_F32(tbl + k * 0x28, -0x18);
            f0 -= 2.0f;
            k++;
        } while (RD_F32(tbl + k * 0x28, 0) < f16);
        f0 = (f32)RD_U8(data, 0x2F);
    }

    // Walk backwards from entry last-1 while the entry is still at or past f16.
    k = last - 1;
    if (f16 <= RD_F32(tbl + k * 0x28, 0)) {
        do {
            RD_F32(tbl + k * 0x28, 0xC) = RD_F32(data, 0xC) * f0;
            RD_F32(tbl + k * 0x28, 0x10) = (RD_F32(tbl + k * 0x28, 0xC) / RD_F32(data, 0x24)) +
                                           RD_F32(tbl + k * 0x28, 0x38);
            f0 -= 2.0f;
            k--;
        } while (f16 <= RD_F32(tbl + k * 0x28, 0));
    }

    for (i = 0; i <= last; i++) {
        ent = tbl + i * 0x28;
        RD_F32(ent, 0x18) = RD_F32(ent, 0x4) - RD_F32(ent, 0x10);
        RD_F32(ent, 0x1C) = RD_F32(ent, 0x18);
    }

    // Final pass: vertices inside the path get their Y offset from the path
    // height; minY (asm: var_s0) tracks the lowest result.
    minY = RD_S16(prop, 0x8E);
    baseX = RD_S32(tbl, 0x24);
    lastX = RD_S32(tbl + last * 0x28, 0x24);
    vtx = RD_PTR(hdr, 0x1C);
    bufA = RD_PTR(prop, 0x18);
    bufB = RD_PTR(prop, 0x1C);
    for (i = 0; i < vcount; i++) {
        x = RD_S16(bufA, 0);
        if (baseX <= x && x <= lastX) {
            idx = (s16)((x - baseX) / RD_S16(data, 0x2C)) * 0x28;
            RD_S16(bufA, 2) = (s16)(RD_S16(vtx, 2) - (s32)RD_F32(tbl + idx, 0x10));
            RD_S16(bufB, 2) = (s16)(RD_S16(vtx, 2) - (s16)(s32)RD_F32(tbl + idx, 0x10));
            if (RD_S16(bufA, 2) < minY) {
                minY = RD_S16(bufA, 2);
            }
        }
        vtx += 0xA;
        bufA += 0xA;
        bufB += 0xA;
    }

    RD_PTR(prop, 0x4) = RD_PTR(prop, 0x18);
    RD_S16(prop, 0x8E) = (s16)minY;
    RD_S16(prop, 0x92) = (s16)maxY;
    RD_F32(obj, 0x34) = (f32)maxY * RD_F32(obj, 0x8);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o105/overlay_105/hitBridgeInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Per-frame bridge controller. arg0 = bridge object, arg1 = frame delta (dt; /60 for time, also Powerf exponent).
// Object: +0x3A s8 prop index, +0x5C hit/player state, +0x68 bridge data, +0x6C prop pointer table,
// +0x8 scale, +0xC/+0x10/+0x14 world position (f32).
// Bridge data (obj+0x68, see hitBridgeInit): +0x00 path table, +0x04 sound handle (its address is also the
// sound mask slot), +0x08 decay base, +0x10 phase, +0x14 amplitude, +0x18 previous swing value, +0x1C peak,
// +0x20/+0x24 f32 divisors, +0x28 pitch helper, +0x2C s16 segment spacing, +0x2E s8 state
// (0 idle, 1/2 swinging, 3 settling), +0x2F u8 last path index (entry count - 1).
// Path entry (0x28 bytes): +0x00 f32 along-path coord, +0x04 f32 base, +0x0C f32 force, +0x10 f32 weight,
// +0x14 f32 displacement, +0x18/+0x1C f32 target/previous, +0x20 f32 offset, +0x24 s32 integer coord,
// +0x40/+0x44 f32 end point (read by hitBridgeMoveY).
// Prop (obj+0x6C[idx]): +0x0 model header, +0x4 current vertex buffer (stride 0xA; flipped via +0xB
// between the buffers at +0x18/+0x1C), +0x8E s16 min Y, +0x94 s16 max Y (read here; hitBridgeInit writes
// its maxY to +0x92), +0xC third argument of func_overlay_105_069015F4_1FBBE24.
// Header: +0x12 s16 vertex count, +0x1C vertex array (stride 0xA, s16 +2 = rest Y).
// Hit state (obj+0x5C): +0x132 u8 active flag, +0x134 ptr to record (+0x0 f32 X, +0x10 f32 velocity),
// +0x104/+0x110 f32 output min/max Y.
// Powerf is called with its 2-arg prototype; the asm also sets f14/a1 for some of these calls, which
// Powerf ignores.
void hitBridgeControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *data;
    u8 *hit;
    u8 *rec;
    u8 *prop;
    u8 *hdr;
    u8 *tbl;
    u8 *ent;
    u8 *vb;
    u8 *hv;
    s32 i;
    s32 count;
    s32 state;
    s32 seg;
    s32 pitch;
    s32 toggle;
    s32 eidx;
    s32 vcount;
    s32 vx;
    s32 pathLo;
    s32 pathHi;
    s16 minY;
    s16 maxY;
    s16 vy;
    f32 f0;
    f32 f14;
    f32 sinv;
    f32 spanW;

    data = RD_PTR(obj, 0x68);
    hit = RD_PTR(obj, 0x5C);
    rec = RD_PTR(hit, 0x134);
    prop = ((u8 **)RD_PTR(obj, 0x6C))[RD_S8(obj, 0x3A)];
    hdr = RD_PTR(prop, 0x0);
    tbl = RD_PTR(data, 0x0);
    count = RD_U8(data, 0x2F);
    spanW = (f32)RD_S16(data, 0x2C);

    /* entry +0x1C = entry +0x18 for every path entry */
    for (i = 0; i <= count; i++) {
        ent = tbl + i * 0x28;
        RD_F32(ent, 0x1C) = RD_F32(ent, 0x18);
    }

    state = RD_S8(data, 0x2E);
    if (state == 0 && RD_U8(hit, 0x132) != 0) {
        f0 = RD_F32(rec, 0x0);
        if (RD_F32(tbl, 0x0) < f0 && f0 < RD_F32(tbl, count * 0x28) && RD_F32(rec, 0x10) < 0.0f) {
            RD_S8(data, 0x2E) = 1;
            RD_F32(data, 0x10) = 0.0f;
            RD_F32(data, 0x18) = 0.0f;
            RD_F32(data, 0x1C) = 1.0f;
            RD_F32(data, 0x14) = (50.0f / RD_F32(data, 0x20)) * -RD_F32(rec, 0x10);
            if (count >= 2) {
                f14 = 50.0f * (-RD_F32(rec, 0x10) / (f32)arg1);
                seg = (s16)(s32)((RD_F32(rec, 0x0) - RD_F32(tbl, 0x0)) / spanW);
                for (i = 1; i < count; i++) {
                    ent = tbl + i * 0x28;
                    RD_F32(ent, 0xC) = Powerf(D_overlay_105_06901F08, seg) * f14;
                    RD_F32(ent, 0x14) = (RD_F32(ent, 0xC) * RD_F32(ent, 0x10)) / RD_F32(data, 0x24);
                }
            }
            if (RD_PTR(data, 0x4) != 0) {
                amSndStopXYZ(RD_PTR(data, 0x4));
            }
            amSndPlayXYZ(0xBE, RD_F32(obj, 0xC), RD_F32(obj, 0x10), RD_F32(obj, 0x14), 4, data + 4);
            if (RD_PTR(data, 0x4) != 0) {
                RD_F32(data, 0x28) = 2.0f * RD_F32(data, 0x14);
                pitch = (s32)(100.0f - RD_F32(data, 0x28));
                amSndSetPitchXYZ(RD_PTR(data, 0x4), pitch & 0xFF);
            }
        }
    }

    state = RD_S8(data, 0x2E);
    if (state == 1 || state == 2) {
        if (RD_F32(data, 0x1C) == 0.0f) {
            RD_S8(data, 0x2E) = 3;
        } else {
            /* flip the vertex-buffer toggle and point prop+4 at the other buffer */
            toggle = RD_U8(prop, 0xB) ^ 1;
            RD_U8(prop, 0xB) = (u8)toggle;
            RD_PTR(prop, 0x4) = RD_PTR(prop, 0x18 + toggle * 4);

            RD_F32(data, 0x1C) = 0.0f;
            RD_F32(data, 0x10) = RD_F32(data, 0x10) + ((f32)arg1 / 60.0f);
            sinv = Sinf((s16)(s32)(((RD_F32(data, 0x14) * RD_F32(data, 0x10)) / D_overlay_105_06901F0C) * 65536.0f));

            if (count >= 2) {
                for (i = 1; i < count; i++) {
                    ent = tbl + i * 0x28;
                    if (sinv >= 0.0f && RD_S8(data, 0x2E) == 2) {
                        RD_F32(ent, 0x14) = RD_F32(ent, 0x14) * Powerf(RD_F32(data, 0x8), i);
                    }
                    f0 = RD_F32(ent, 0x14);
                    if (f0 < 1.0f) {
                        RD_F32(ent, 0x14) = 0.0f;
                        f0 = 0.0f;
                    }
                    if (RD_F32(data, 0x1C) < f0) {
                        RD_F32(data, 0x1C) = f0;
                        f0 = RD_F32(ent, 0x14);
                    }
                    RD_F32(ent, 0x20) = (f0 * sinv) + RD_F32(ent, 0x10);
                    RD_F32(ent, 0x18) = RD_F32(ent, 0x4) - RD_F32(ent, 0x20);
                }
            }

            /* vertex pass: rest Y of each vertex offset by the path entry it sits on */
            minY = RD_S16(prop, 0x8E);
            maxY = RD_S16(prop, 0x94);
            pathLo = RD_S32(tbl, 0x24);
            pathHi = RD_S32(tbl, count * 0x28 + 0x24);
            vb = RD_PTR(prop, 0x4);
            hv = RD_PTR(hdr, 0x1C);
            vcount = RD_S16(hdr, 0x12);
            for (i = 0; i < vcount; i++) {
                vx = RD_S16(vb, i * 0xA);
                if (vx >= pathLo && pathHi >= vx) {
                    eidx = (s16)((s32)(vx - pathLo) / RD_S16(data, 0x2C));
                    vy = (s16)(RD_S16(hv, i * 0xA + 2) - (s16)(s32)RD_F32(tbl + eidx * 0x28, 0x20));
                    RD_S16(vb, i * 0xA + 2) = vy;
                    if (vy < minY) {
                        minY = vy;
                    } else if (maxY < vy) {
                        maxY = vy;
                    }
                }
            }
            RD_F32(hit, 0x104) = ((f32)minY * RD_F32(obj, 0x8)) + RD_F32(obj, 0x10);
            RD_F32(hit, 0x110) = ((f32)maxY * RD_F32(obj, 0x8)) + RD_F32(obj, 0x10);

            if (RD_F32(data, 0x1C) > 4.0f) {
                if (sinv >= 0.0f && RD_F32(data, 0x18) < 0.0f) {
                    if (RD_PTR(data, 0x4) != 0) {
                        amSndStopXYZ(RD_PTR(data, 0x4));
                    }
                    amSndPlayXYZ(0xBE, RD_F32(obj, 0xC), RD_F32(obj, 0x10), RD_F32(obj, 0x14), 4, data + 4);
                    if (RD_PTR(data, 0x4) != 0) {
                        RD_F32(data, 0x28) = RD_F32(data, 0x28) * Powerf(RD_F32(data, 0x8), arg1);
                        pitch = (s32)(100.0f - RD_F32(data, 0x28));
                        amSndSetPitchXYZ(RD_PTR(data, 0x4), pitch & 0xFF);
                    }
                } else if (sinv < RD_F32(data, 0x18) && RD_S8(data, 0x2E) == 1) {
                    if (RD_PTR(data, 0x4) != 0) {
                        amSndStopXYZ(RD_PTR(data, 0x4));
                    }
                    amSndPlayXYZ(0xBF, RD_F32(obj, 0xC), RD_F32(obj, 0x10), RD_F32(obj, 0x14), 4, data + 4);
                    if (RD_PTR(data, 0x4) != 0) {
                        RD_F32(data, 0x28) = RD_F32(data, 0x28) * Powerf(RD_F32(data, 0x8), arg1);
                        pitch = (s32)(100.0f - RD_F32(data, 0x28));
                        amSndSetPitchXYZ(RD_PTR(data, 0x4), pitch & 0xFF);
                    }
                }
            }

            if (sinv <= RD_F32(data, 0x18)) {
                RD_S8(data, 0x2E) = 2;
            } else if (RD_F32(data, 0x18) < sinv) {
                RD_S8(data, 0x2E) = 1;
            }
            RD_F32(data, 0x18) = sinv;
            func_overlay_105_069015F4_1FBBE24(prop, hdr, RD_PTR(prop, 0xC));
        }
    } else if (state == 3 && RD_U8(hit, 0x132) == 0) {
        RD_S8(data, 0x2E) = 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o105/overlay_105/hitBridgeControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hitBridgeMoveY(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    u8 *obj = (u8 *)arg0;
    u8 *data;
    u8 *hit;
    u8 *tbl;
    u8 *ent;
    s32 idx;
    f32 spanW;
    f32 sp48;
    f32 sp44;
    f32 sp40;
    f32 sp38;
    f32 sp28;
    f32 f2;
    f32 f12;
    f32 f14;
    f32 f18;

    data = RD_PTR(obj, 0x68);
    hit = RD_PTR(obj, 0x5C);
    spanW = (f32)RD_S16(data, 0x2C);
    mathMtxXFMF((void *)(hit + (RD_U8(hit, 0x12B) << 6)), *arg1, *arg2, *arg3, &sp48, &sp44, &sp40);
    tbl = RD_PTR(data, 0);
    sp28 = RD_F32(tbl, 0);
    if (sp28 < sp48 && sp48 < RD_F32(tbl, RD_U8(data, 0x2F) * 0x28)) {
        idx = (s32)((sp48 - sp28) / spanW);
        ent = tbl + idx * 0x28;
        f2 = (sp48 - RD_F32(ent, 0)) / spanW;
        f12 = RD_F32(ent, 0x1C);
        f14 = RD_F32(ent, 0x18);
        f18 = f12 + f2 * (RD_F32(ent, 0x44) - f12);
        sp38 = f14 + f2 * (RD_F32(ent, 0x40) - f14);
        if (f18 < sp44 && RD_S8(data, 0x2E) == 2) {
            sp44 += (sp38 - f18) + 1.0f;
        } else if (sp44 < f18 && RD_S8(data, 0x2E) == 1) {
            sp44 += (sp38 - f18) - 1.0f;
        }
    }
    mathMtxXFMF((void *)(hit + (RD_U8(hit, 0x12B) << 6) + 0x80), sp48, sp44, sp40, arg1, arg2, arg3);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o105/overlay_105/hitBridgeMoveY.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void hitBridgeMoveWith(void *arg0, f32 *arg1, f32 *arg2, f32 *arg3, f32 *arg4, f32 *arg5, f32 *arg6) {
    u8 *obj = (u8 *)arg0;
    u8 *data;
    u8 *hit;
    u8 *tbl;
    u8 *ent;
    f32 spanW;
    f32 sp2C;
    f32 sp4C;
    f32 sp48;
    f32 f2;
    f32 f12;
    f32 f14;
    f32 f16;

    data = RD_PTR(obj, 0x68);
    hit = RD_PTR(obj, 0x5C);
    spanW = (f32)RD_S16(data, 0x2C);
    tbl = RD_PTR(data, 0);
    sp2C = RD_F32(tbl, 0);
    f2 = *arg1;
    if (sp2C < f2 && f2 < RD_F32(tbl, RD_U8(data, 0x2F) * 0x28)) {
        ent = tbl + ((s32)((f2 - sp2C) / spanW) * 0x28);
        f14 = RD_F32(ent, 0x1C);
        f12 = (f2 - RD_F32(ent, 0)) / spanW;
        sp4C = f14 + f12 * (RD_F32(ent, 0x44) - f14);
        f16 = RD_F32(ent, 0x18);
        sp48 = f16 + f12 * (RD_F32(ent, 0x40) - f16);
        *arg2 += sp48 - sp4C;
    }
    mathMtxXFMF((void *)(hit + (RD_U8(hit, 0x12B) << 6) + 0x80), *arg1, *arg2, *arg3, arg4, arg5, arg6);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o105/overlay_105/hitBridgeMoveWith.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Builds the collision planes for a bridge mesh: one plane per triangle (pass 1),
// then one "bent" edge plane per triangle edge that has a valid neighbour (pass 2).
// arg0 = object: +0x04 vertex base (s16 xyz, stride 0xA).
// arg1 = mesh table: +0x16 s16 group count, +0x20 triangle array (stride 0x10: +0 flag byte,
//        +1..+3 local vertex indices, cf. jfg-re docs/technical-notes.md "Triangles 16 B"),
//        +0x24 group array (stride 0x10: +0x6 s16 vertex base, +0x8 s16 first triangle,
//        +0xC u32 render flags (0x880 = group skipped in pass 2), +0x18 s16 end triangle).
// arg2 = collision output: +0x00 triangle records (stride 0xE: +0 u16 self plane index,
//        +2/+4/+6 u16 per-edge plane/neighbour index, +8/+A/+C u16 copy of the original
//        neighbour indices), +0x08 u8 per-triangle edge flags (bit k = edge k),
//        +0x0C plane array (stride 0x10: f32 nx, ny, nz, d).
// Pass-2 neighbour indices >= the pass-1 plane count (or the 0x8000 marked ones) are ignored.
void func_overlay_105_069015F4_1FBBE24(void *arg0, void *arg1, void *arg2) {
    u8 *obj = (u8 *)arg0;
    u8 *mesh = (u8 *)arg1;
    u8 *out = (u8 *)arg2;
    u8 *verts;
    u8 *tris;
    u8 *groups;
    u8 *recs;
    u8 *flags;
    u8 *planes;
    u8 *grp;
    u8 *tr;
    u8 *rec;
    u8 *nr;
    u8 *nbPl;
    u8 *selfPl;
    u8 *pl;
    u8 *pa;
    u8 *pb;
    u8 *vA;
    u8 *vB;
    u8 *vC;
    s32 groupCount;
    s32 planeCount;
    s32 firstAdjPlane;
    s32 g;
    s32 tri;
    s32 triStart;
    s32 triEnd;
    s32 vbase;
    s32 k;
    s32 kNext;
    s32 j;
    s32 nb;
    s32 selfId;
    f32 ax;
    f32 ay;
    f32 az;
    f32 bx;
    f32 by;
    f32 bz;
    f32 cx;
    f32 cy;
    f32 cz;
    f32 e1x;
    f32 e1y;
    f32 e1z;
    f32 e2x;
    f32 e2y;
    f32 e2z;
    f32 nx;
    f32 ny;
    f32 nz;
    f32 len;
    f32 d;
    f32 px;
    f32 py;
    f32 pz;
    f32 qx;
    f32 qy;
    f32 qz;
    f32 ox;
    f32 oy;
    f32 oz;
    f32 cnx;
    f32 cny;
    f32 cnz;
    f32 nbnx;
    f32 nbny;
    f32 nbnz;
    f32 p5x;
    f32 p5y;
    f32 p5z;
    f32 n5x;
    f32 n5y;
    f32 n5z;

    verts = RD_PTR(obj, 0x4);
    tris = RD_PTR(mesh, 0x20);
    groups = RD_PTR(mesh, 0x24);
    recs = RD_PTR(out, 0x0);
    flags = RD_PTR(out, 0x8);
    planes = RD_PTR(out, 0xC);
    groupCount = RD_S16(mesh, 0x16);

    // Pass 1: one plane per triangle of every group, from its three vertices.
    planeCount = 0;
    for (g = 0; g < groupCount; g++) {
        grp = groups + g * 0x10;
        vbase = RD_S16(grp, 0x6);
        triStart = RD_S16(grp, 0x8);
        triEnd = RD_S16(grp, 0x18);
        for (tri = triStart; tri < triEnd; tri++) {
            tr = tris + tri * 0x10;
            vA = verts + (RD_U8(tr, 0x1) + vbase) * 0xA;
            vB = verts + (RD_U8(tr, 0x2) + vbase) * 0xA;
            vC = verts + (RD_U8(tr, 0x3) + vbase) * 0xA;
            ax = (f32)RD_S16(vA, 0x0);
            ay = (f32)RD_S16(vA, 0x2);
            az = (f32)RD_S16(vA, 0x4);
            bx = (f32)RD_S16(vB, 0x0);
            by = (f32)RD_S16(vB, 0x2);
            bz = (f32)RD_S16(vB, 0x4);
            cx = (f32)RD_S16(vC, 0x0);
            cy = (f32)RD_S16(vC, 0x2);
            cz = (f32)RD_S16(vC, 0x4);

            e1x = bx - ax;
            e1y = by - ay;
            e1z = bz - az;
            e2x = cx - bx;
            e2y = cy - by;
            e2z = cz - bz;
            nx = (e1y * e2z) - (e1z * e2y);
            ny = (e1z * e2x) - (e1x * e2z);
            nz = (e1x * e2y) - (e1y * e2x);
            len = sqrtf((nx * nx) + (ny * ny) + (nz * nz));
            if (len > 0.0f) {
                nx = nx / len;
                ny = ny / len;
                nz = nz / len;
            }

            pl = planes + planeCount * 0x10;
            RD_F32(pl, 0x0) = nx;
            RD_F32(pl, 0x4) = ny;
            RD_F32(pl, 0x8) = nz;
            RD_F32(pl, 0xC) = -((ax * nx) + (ay * ny) + (az * nz));
            planeCount++;

            rec = recs + tri * 0xE;
            RD_U16(rec, 0x2) = RD_U16(rec, 0x8);
            RD_U16(rec, 0x4) = RD_U16(rec, 0xA);
            RD_U16(rec, 0x6) = RD_U16(rec, 0xC);
            flags[tri] &= 0xF8;
        }
    }

    // Pass 2: for every group (not 0x880-flagged) and every triangle edge k (corner k -> k+1),
    // if the neighbour plane is a pass-1 plane, build the plane through the edge bent by
    // the two face normals (A' = P + 10 * (own normal + neighbour normal)).
    firstAdjPlane = planeCount;
    for (g = 0; g < groupCount; g++) {
        grp = groups + g * 0x10;
        vbase = RD_S16(grp, 0x6);
        triStart = RD_S16(grp, 0x8);
        triEnd = RD_S16(grp, 0x18);
        if ((RD_S32(grp, 0xC) & 0x880) != 0) {
            triEnd = triStart - 1;
        }
        for (tri = triStart; tri < triEnd; tri++) {
            tr = tris + tri * 0x10;
            rec = recs + tri * 0xE;
            selfId = RD_U16(rec, 0x0);
            selfPl = planes + selfId * 0x10;
            cnx = RD_F32(selfPl, 0x0);
            cny = RD_F32(selfPl, 0x4);
            cnz = RD_F32(selfPl, 0x8);

            for (k = 0; k < 3; k++) {
                kNext = (k + 1) % 3;
                nb = RD_U16(rec, 0x2 + k * 2);
                if (nb < firstAdjPlane) {
                    nbPl = planes + nb * 0x10;
                    pa = verts + (RD_U8(tr, 0x1 + k) + vbase) * 0xA;
                    pb = verts + (RD_U8(tr, 0x1 + kNext) + vbase) * 0xA;
                    px = (f32)RD_S16(pa, 0x0);
                    py = (f32)RD_S16(pa, 0x2);
                    pz = (f32)RD_S16(pa, 0x4);
                    qx = (f32)RD_S16(pb, 0x0);
                    qy = (f32)RD_S16(pb, 0x2);
                    qz = (f32)RD_S16(pb, 0x4);

                    nbnx = RD_F32(nbPl, 0x0);
                    nbny = RD_F32(nbPl, 0x4);
                    nbnz = RD_F32(nbPl, 0x8);
                    ox = ((nbnx + cnx) * 10.0f) + px;
                    oy = ((nbny + cny) * 10.0f) + py;
                    oz = ((nbnz + cnz) * 10.0f) + pz;

                    e1x = qx - px;
                    e1y = qy - py;
                    e1z = qz - pz;
                    e2x = ox - qx;
                    e2y = oy - qy;
                    e2z = oz - qz;
                    nx = (e1y * e2z) - (e1z * e2y);
                    ny = (e1z * e2x) - (e1x * e2z);
                    nz = (e1x * e2y) - (e1y * e2x);
                    len = sqrtf((nx * nx) + (ny * ny) + (nz * nz));
                    if (len > 0.0f) {
                        nx = nx / len;
                        ny = ny / len;
                        nz = nz / len;
                    }
                    d = -((px * nx) + (py * ny) + (pz * nz));

                    // Neighbour triangle's back-references to this triangle now point at the
                    // plane being created (flagged 0x8000).
                    if (nb != selfId) {
                        nr = recs + nb * 0xE;
                        for (j = 0; j < 6; j += 2) {
                            if (RD_U16(nr, 0x2 + j) == selfId) {
                                RD_U16(nr, 0x2 + j) = (u16)(planeCount | 0x8000);
                            }
                        }
                    }
                    RD_U16(rec, 0x2 + k * 2) = (u16)planeCount;

                    // Edge flag: neighbour is a different plane, so test whether the two
                    // points pushed off each face (+5 along its normal) lie on opposite sides.
                    nbPl = planes + nb * 0x10;
                    nbnx = RD_F32(nbPl, 0x0);
                    nbny = RD_F32(nbPl, 0x4);
                    nbnz = RD_F32(nbPl, 0x8);
                    if ((RD_F32(planes + selfId * 0x10, 0x0) != nbnx) ||
                        (RD_F32(planes + selfId * 0x10, 0x4) != nbny) ||
                        (RD_F32(planes + selfId * 0x10, 0x8) != nbnz)) {
                        n5x = (nbnx * 5.0f) + px;
                        n5y = (nbny * 5.0f) + py;
                        n5z = (nbnz * 5.0f) + pz;
                        p5x = px + (RD_F32(planes + selfId * 0x10, 0x0) * 5.0f);
                        p5y = py + (RD_F32(planes + selfId * 0x10, 0x4) * 5.0f);
                        p5z = pz + (RD_F32(planes + selfId * 0x10, 0x8) * 5.0f);
                        if ((((p5x * nx) + (p5y * ny) + (p5z * nz) + d) < 0.0f) &&
                            (-(((n5x * nx) + (n5y * ny) + (n5z * nz)) + d) < 0.0f)) {
                            flags[tri] |= 1 << k;
                        }
                    } else if (nb == selfId) {
                        flags[tri] |= 1 << k;
                    }

                    pl = planes + planeCount * 0x10;
                    RD_F32(pl, 0x0) = nx;
                    RD_F32(pl, 0x4) = ny;
                    RD_F32(pl, 0x8) = nz;
                    RD_F32(pl, 0xC) = d;
                    planeCount++;
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o105/overlay_105/func_overlay_105_069015F4_1FBBE24.s")
#endif
