#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
#define RD_U8(p, off)  (*(u8 *)((u8 *)(p) + (off)))
#define RD_S8(p, off)  (*(s8 *)((u8 *)(p) + (off)))
#define RD_S16(p, off) (*(s16 *)((u8 *)(p) + (off)))
#define RD_U16(p, off) (*(u16 *)((u8 *)(p) + (off)))
#define RD_S32(p, off) (*(s32 *)((u8 *)(p) + (off)))
#define RD_F32(p, off) (*(f32 *)((u8 *)(p) + (off)))
#define RD_PTR(p, off) (*(u8 **)((u8 *)(p) + (off)))

extern u8 D_overlay_143_08F02FE0[];   /* 0x10-byte records: f32 x, f32 y, f32 z, s32 duration */
extern s32 D_overlay_143_08F02F78;
extern s32 D_overlay_143_08F03270;
extern void *D_overlay_143_08F032D0;  /* shockwave texture */

s32 objTvTimes(s32);
void squadsGetChildPolyPosition(s32, f32 *, f32 *, f32 *);
void fxCpuTextureRequired(s32, void *);
void texDPTextureX(Gfx **, void *, s32, s32);
extern s32 D_overlay_143_08F02F74;
f32 Sinf(s16 angle);
f32 sqrtf(f32 x);
void *squadsGetClosestPlayer(void);
void objFreeObject(void *obj);
void amSndPlay(u16 soundID, void *handlePtr);
void amSndSetVol(u16 soundID, s32 handle, u8 volume);
void amSndPlayXYZ(u16 soundID, s32 x, s32 y, s32 z, s32 flags, void *handle);
void amSndStop(s32 handle);
extern s32 D_overlay_143_08F032C8;
extern s32 iDeltaTime;
extern u8 *CpuTexSpaceA[4];   /* cf. src/fx.c */
extern u8 *CpuTexSpaceB[4];
extern u8 D_overlay_143_08F02BC0[];   /* initial fire base pattern */
extern u8 D_overlay_143_08F02F7C;     /* ping-pong buffer selector */
extern s32 D_overlay_143_08F02F80;    /* one-shot: copy base pattern */
extern s32 D_overlay_143_08F03274;    /* phase-6 done flag */
extern void *D_overlay_143_08F032B0;  /* FatBob part A (cf. phase 4) */
extern void *D_overlay_143_08F032B4;  /* FatBob part B (cf. phase 4) */
extern void *D_overlay_143_08F032C0;  /* switch/pad object A (+0x3A active) */
extern void *D_overlay_143_08F032C4;  /* switch/pad object B (+0x3A active) */
extern s32 D_overlay_143_08F032CC;    /* side toggle (0/1) */
void *objSetupObject(void *params, s32 arg1);
void objSetFlashPartColour(s32 r, s32 g, s32 b, s32 mode);
void damagecrateChangeHitsmin(s32 arg0, s32 arg1);
void ClearMissionFields(s32 arg0, s32 arg1);
s32 CheckLineOfSight(void *, void *);
s32 TryToSetMission(s32, s32, s32, s32, s32);
void UpdateOrSetAnim(s32, s32, s32);
void damagecrateRepair(void *);
void explosionStart(s32, s16, s16, s16, s32, s32);
void objEnsureNotTargetted(void *, void *);
void **objGetObjList(s32 *, s32 *);
void **squadsGetSquadronList(s32 *);
extern u8 D_overlay_143_08F03278[];  /* FatBob state block (boss base+0xA8) */
extern void *D_overlay_143_08F032B8;
extern void *D_overlay_143_08F032BC;
extern u8 D_overlay_143_08F02F70[];  /* per-sub entry count bytes */
extern u8 *D_overlay_143_08F02F64[]; /* per-sub pattern pointers */
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_143_08F00000_1FD9998(s32 arg0, f32 *arg1, f32 *arg2, f32 *arg3) {
    s32 remain;
    s32 idx;
    u8 *rec;

    remain = arg0;
    idx = D_overlay_143_08F03270;
    if (remain > 0) {
        for (;;) {
            idx -= 1;
            if (idx < 0) {
                idx = 0x28;
            }
            if (idx == D_overlay_143_08F03270) {
                break;
            }
            remain -= RD_S32(D_overlay_143_08F02FE0 + (idx * 0x10), 0xC);
            if (remain <= 0) {
                break;
            }
        }
    }
    rec = D_overlay_143_08F02FE0 + (idx * 0x10);
    *arg1 = RD_F32(rec, 0);
    *arg2 = RD_F32(rec, 4);
    *arg3 = RD_F32(rec, 8);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o143/overlay_143/func_overlay_143_08F00000_1FD9998.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_143_08F0007C_1FD9A14(void *arg0, s32 arg1, f32 *arg2, f32 *arg3, f32 *arg4) {
    s32 temp;

    switch (arg1) {
    case -1:
        *arg2 = RD_F32(arg0, 0xC) + 332.0f;
        *arg3 = RD_F32(arg0, 0x10) + 183.0f;
        *arg4 = RD_F32(arg0, 0x14) - 388.0f;
        return;
    case -2:
        *arg2 = RD_F32(arg0, 0xC) - 332.0f;
        *arg3 = RD_F32(arg0, 0x10) + 183.0f;
        *arg4 = RD_F32(arg0, 0x14) - 388.0f;
        return;
    case -3:
        do {
            temp = mathRnd(9, 0x10);
        } while (temp == D_overlay_143_08F02F78);
        D_overlay_143_08F02F78 = temp;
        squadsGetChildPolyPosition(temp, arg2, arg3, arg4);
        return;
    case -4:
        squadsGetChildPolyPosition(mathRnd(0xB, 0xC), arg2, arg3, arg4);
        return;
    case -6:
        squadsGetChildPolyPosition(mathRnd(0xD, 0xE), arg2, arg3, arg4);
        return;
    case -5:
        squadsGetChildPolyPosition(mathRnd(9, 0xA), arg2, arg3, arg4);
        return;
    case -7:
        squadsGetChildPolyPosition(mathRnd(0xF, 0x10), arg2, arg3, arg4);
        return;
    case -8:
        func_overlay_143_08F00000_1FD9998(objTvTimes(0x28), arg2, arg3, arg4);
        return;
    default:
        squadsGetChildPolyPosition(arg1, arg2, arg3, arg4);
        return;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o143/overlay_143/func_overlay_143_08F0007C_1FD9A14.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void FatBobDrawShockWave(Gfx **arg0, s32 (**arg1)[4][4], ObjectTransform *arg2) {
    Gfx *dl;
    Gfx *sp68;
    u8 *sp6C;
    s32 (*sp64)[4][4];
    u32 addrA;
    u32 addrB;
    u32 addrC;
    u32 addrD;

    sp68 = *arg0;
    sp6C = RD_PTR(arg2, 0x68);
    sp64 = *arg1;
    fxCpuTextureRequired(2, D_overlay_143_08F032D0);
    texDPTextureX(&sp68, D_overlay_143_08F032D0, 0x20E, 0);

    dl = sp68;
    sp68 = dl + 1;
    dl->words.w0 = 0xFA000000;
    dl->words.w1 = 0xFFFF00FF;
    dl = sp68;
    sp68 = dl + 1;
    dl->words.w1 = 0xE5000000;
    dl->words.w0 = 0xFB000000;
    camPushModelMtx(&sp68, (MatrixS **) &sp64, arg2, 1.0f, 0.0f);

    dl = sp68;
    sp68 = dl + 1;
    dl->words.w0 = 0xE7000000;
    dl->words.w1 = 0;

    addrA = (u32) sp6C + (RD_U8(sp6C, 0x6F8) * 0xF0 * 2);
    addrB = addrA + 0x80000300;
    dl = sp68;
    sp68 = dl + 1;
    dl->words.w0 = (((((s32) addrB & 6) | 0xC0) & 0xFF) << 0x10) | 0x04000000 | 0xF8;
    dl->words.w1 = addrB;
    dl = sp68;
    sp68 = dl + 1;
    dl->words.w1 = (u32) sp6C + 0x80000000;
    dl->words.w0 = 0x05B100C0;

    addrC = addrA + 0x800003DC;
    dl = sp68;
    sp68 = dl + 1;
    dl->words.w0 = 0x059100A0;
    dl->words.w1 = (u32) sp6C + 0x800000C0;
    dl = sp68;
    sp68 = dl + 1;
    dl->words.w0 = (((((s32) addrC & 6) | 0xC0) & 0xFF) << 0x10) | 0x04000000 | 0xF8;
    dl->words.w1 = addrC;
    dl = sp68;
    sp68 = dl + 1;
    dl->words.w1 = (u32) sp6C + 0x80000160;
    dl->words.w0 = 0x05B100C0;

    addrD = addrA + 0x800004B8;
    dl = sp68;
    sp68 = dl + 1;
    dl->words.w1 = (u32) sp6C + 0x80000220;
    dl->words.w0 = 0x059100A0;
    dl = sp68;
    sp68 = dl + 1;
    dl->words.w0 = (((((s32) addrD & 6) | 0x30) & 0xFF) << 0x10) | 0x04000000 | 0x44;
    dl->words.w1 = addrD;
    dl = sp68;
    sp68 = dl + 1;
    dl->words.w1 = (u32) sp6C + 0x800002C0;
    dl->words.w0 = 0x05310040;

    camPopModelMtx(&sp68);

    dl = sp68;
    sp68 = dl + 1;
    dl->words.w0 = 0xE7000000;
    dl->words.w1 = 0;
    dl = sp68;
    sp68 = dl + 1;
    dl->words.w0 = 0xFB000000;
    dl->words.w1 = -1U;
    dl = sp68;
    sp68 = dl + 1;
    dl->words.w0 = 0xFA000000;
    dl->words.w1 = -1U;

    *arg0 = sp68;
    *arg1 = sp64;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o143/overlay_143/FatBobDrawShockWave.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void FatBobShockWaveInit(void *arg0, s32 arg1) {
    u8 *base;
    u8 *r1;
    u8 *r2;
    u8 *r3;
    s32 cnt;
    s32 idx;
    s32 idx2;
    s32 tcount;
    s32 hi1;
    s32 hi2;
    s32 hi3;
    s32 hi4;
    s32 t1;
    s32 t1b;
    s16 a1;
    s16 a2;
    s16 tex7;

    base = RD_PTR(arg0, 0x68);
    cnt = 0x63;
    r1 = base + 0x300;
    do {
        RD_S16(r1, 0) = 0;
        RD_S16(r1, 2) = 0;
        RD_S16(r1, 4) = 0;
        RD_U8(r1, 6) = 0xFF;
        RD_U8(r1, 7) = 0xFF;
        RD_U8(r1, 8) = 0xFF;
        RD_U8(r1, 9) = 0xFF;
        r1 += 0xA;
        cnt -= 1;
    } while (cnt != 0);

    RD_S16(D_overlay_143_08F032D0, 6) = (s16) (RD_S16(D_overlay_143_08F032D0, 6) & 0xFEFF);
    RD_U8(base, 0x6F9) = 0;
    /* sig mismatch: fxCpuTextureRequired takes 2 args, asm passes the texture twice */
    ((void (*)(s32, void *, void *)) fxCpuTextureRequired)(2, D_overlay_143_08F032D0, D_overlay_143_08F032D0);

    tex7 = (s16) ((RD_S8(D_overlay_143_08F032D0, 1) - 1) << 5);
    a1 = 0;
    a2 = (s16) ((RD_S8(D_overlay_143_08F032D0, 0) - 1) << 5);
    idx = 0;
    tcount = 0;
    r1 = base;
    do {
        /* R1 = current record, R2 = R1 + 0x20, R3 = next R1 */
        hi1 = idx % 24;
        t1 = idx + 2;
        RD_S16(r1, 4) = a1;
        RD_S16(r1, 0xC) = a1;
        RD_S16(r1, 0x14) = a1;
        RD_S16(r1, 8) = a2;
        RD_S16(r1, 0x18) = a2;
        RD_S16(r1, 0x1C) = a2;
        tcount += 4;
        RD_S16(r1, 6) = 0;
        RD_S16(r1, 0xA) = tex7;
        RD_S16(r1, 0xE) = tex7;
        RD_U8(r1, 0) = 0x40;
        RD_S16(r1, 0x16) = 0;
        RD_U8(r1, 1) = (u8) hi1;
        RD_U8(r1, 0x11) = (u8) hi1;
        hi2 = (idx + 3) % 24;
        RD_S16(r1, 0x1A) = 0;
        RD_S16(r1, 0x1E) = tex7;
        RD_U8(r1, 0x10) = 0x40;

        r2 = r1 + 0x20;
        idx2 = t1;
        RD_U8(r2, -0x1E) = (u8) hi2;
        RD_U8(r2, -0xD) = (u8) hi2;
        RD_U8(r2, -0x1D) = (u8) ((idx + 1) % 24);
        RD_U8(r2, -0xE) = (u8) (t1 % 24);
        if (t1 >= 0x15) {
            idx2 = 0;
        }
        hi3 = idx2 % 24;
        t1b = idx2 + 2;
        RD_S16(r2, 4) = a2;
        RD_S16(r2, 0xC) = a2;
        RD_S16(r2, 0x14) = a2;
        RD_S16(r2, 8) = a1;
        RD_S16(r2, 0x18) = a1;
        RD_S16(r2, 0x1C) = a1;
        idx = t1b;
        RD_S16(r2, 6) = 0;
        RD_S16(r2, 0xA) = tex7;
        RD_S16(r2, 0xE) = tex7;
        RD_U8(r1, 0x20) = 0x40;
        RD_S16(r2, 0x16) = 0;
        RD_U8(r2, 1) = (u8) hi3;
        RD_U8(r2, 0x11) = (u8) hi3;
        hi4 = (idx2 + 3) % 24;
        RD_S16(r2, 0x1A) = 0;
        RD_S16(r2, 0x1E) = tex7;
        RD_U8(r2, 0x10) = 0x40;

        r3 = r2 + 0x20;
        RD_U8(r3, -0x1E) = (u8) hi4;
        RD_U8(r3, -0xD) = (u8) hi4;
        RD_U8(r3, -0x1D) = (u8) ((idx2 + 1) % 24);
        RD_U8(r3, -0xE) = (u8) (t1b % 24);
        if (t1b >= 0x15) {
            idx = 0;
        }
        r1 = r3;
    } while (tcount != 0x30);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o143/overlay_143/FatBobShockWaveInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void FatBobShockWaveControl(void *arg0, s32 arg1) {
    u8 *base;
    u8 *r1;
    void *closest;
    s32 angle;
    s32 v;
    s32 vol;
    f32 sn;
    f32 cs;
    f32 dx;
    f32 dz;
    f32 dist;
    f32 dy;
    u8 *tgt;

    base = RD_PTR(arg0, 0x68);
    r1 = base + 0x300 + (RD_U8(base, 0x6F8) * 0x1E0);
    for (angle = 0; angle != 0x10A9A; angle += 0xAAA) {
        sn = Sinf((s16) angle);
        cs = Cosf((s32) (s16) angle);
        RD_S16(r1, 0xA) = (s16) (s32) (sn * (f32) (RD_S32(base, 0x6EC) + 0xA));
        RD_S16(r1, 0xE) = (s16) (s32) (cs * (f32) (RD_S32(base, 0x6EC) + 0xA));
        RD_S16(r1, 0x0) = (s16) (s32) (sn * (f32) (RD_S32(base, 0x6EC) - 0xA));
        RD_S16(r1, 0x4) = (s16) (s32) (cs * (f32) (RD_S32(base, 0x6EC) - 0xA));
        RD_S16(r1, 0xC) = 0;
        RD_S16(r1, 0x2) = 0x32;
        r1 += 0x14;
    }
    if (RD_U8(base, 0x6F9) == 0) {
        closest = squadsGetClosestPlayer();
        dx = RD_F32(closest, 0xC) - RD_F32(arg0, 0xC);
        dz = RD_F32(closest, 0x14) - RD_F32(arg0, 0x14);
        dist = sqrtf((dx * dx) + (dz * dz)) - (f32) RD_S32(base, 0x6EC);
        if (dist < 0.0f) {
            dist = -dist;
        }
        dy = RD_F32(closest, 0x10) - RD_F32(arg0, 0x10);
        if (dist < 30.0f && dy < 50.0f) {
            tgt = RD_PTR(closest, 0x4C);
            RD_S16(tgt, 0x6) = (s16) (RD_S16(tgt, 0x6) - 0x500);
            RD_U8(base, 0x6F9) = 1;
        }
    }
    RD_U8(base, 0x6F8) = (u8) (RD_U8(base, 0x6F8) ^ 1);
    v = RD_S32(base, 0x6EC) + (arg1 * 5);
    RD_S32(base, 0x6EC) = v;
    if (v >= 0x515) {
        objFreeObject(arg0);
        v = RD_S32(base, 0x6EC);
    }
    if (v >= 0x1B2 && v < 0x1D9 && D_overlay_143_08F02F74 == 0) {
        amSndPlay(0x20F, &D_overlay_143_08F02F74);
    }
    if (D_overlay_143_08F02F74 != 0) {
        vol = ((RD_S32(base, 0x6EC) * 0x50) / 1300) + 0x2F;
        if (vol >= 0x80) {
            vol = 0x7F;
        }
        if (vol < 0) {
            vol = 0x2F;
        }
        amSndSetVol(0x20F, D_overlay_143_08F02F74, (u8) vol);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o143/overlay_143/FatBobShockWaveControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// FatBob boss main control. base = obj+0x68 (boss state), st = base+0xA8 (state block
// D_overlay_143_08F03278): st+0 active, st+1 phase (low nibble = phase, 0x10 steps),
// st+2 sub-state, st+3 countdown, st+8..+0x24 child object pointer array [8],
// st+0x28 / st+0x30 signed pattern byte rows.
// Field layout of the boss state (base) and the ex sub-struct (arg0->unk4C->unk40)
// is taken from the asm; cf. FatBobPhaseChange above (same offsets).
void BTSBFatBob(void *arg0) {
    u8 *base;
    u8 *st;
    u8 *ex;          /* arg0->unk4C->unk40 */
    u8 *ref;         /* base->unk24->unk68 (asm spC4) */
    u8 *player;      /* squadsGetClosestPlayer() (asm spC0) */
    u8 *obj;
    u8 *child;
    u8 *ch68;
    u8 *s1;
    u8 *s2;
    u8 *rec;
    u8 *sub4c;
    s8 *pat;
    void **objList;
    void **sqList;
    s32 objStart;
    s32 objEnd;
    s32 sqCount;
    s32 cnt;
    s32 half;
    s32 n;
    s32 idx;
    s32 v;
    s32 a2;
    s32 t7;
    s32 t3;
    s32 t9;
    s32 sub;
    f32 sp8C;
    f32 sp88;
    f32 sp84;
    f32 sp80;
    f32 sp7C;
    f32 sp78;
    f32 sp74;
    f32 sp70;
    f32 sp6C;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 horiz;
    f32 dist;

    base = RD_PTR(arg0, 0x68);
    ref = RD_PTR(RD_PTR(base, 0x24), 0x68);   /* asm: base->unk24->unk68 */
    player = (u8 *) squadsGetClosestPlayer();  /* asm: called unconditionally */
    st = RD_PTR(base, 0xA8);

    if (st == NULL) {
        /* one-time init of the boss state block */
        objList = objGetObjList(&objStart, &objEnd);
        sqList = squadsGetSquadronList(&sqCount);
        st = D_overlay_143_08F03278;
        RD_PTR(base, 0xA8) = st;
        st[1] = 1;
        st[2] = 0;
        D_overlay_143_08F032C8 = 0;
        /* asm: D_2F0 = arg0->unk40->unkAC->[0]->unk10->[0] */
        D_overlay_143_08F032D0 =
            RD_PTR(RD_PTR(RD_PTR(RD_PTR(RD_PTR(arg0, 0x40), 0xAC), 0), 0x10), 0);

        if (sqCount != 0) {
            idx = sqCount - 1;
            do {
                obj = (u8 *) sqList[idx];
                if (D_overlay_143_08F032B4 != NULL) {
                    D_overlay_143_08F032B0 = RD_PTR(obj, 0x68);
                    if (RD_U16(D_overlay_143_08F032B0, 0x2C) != 0x144) {
                        D_overlay_143_08F032B8 = obj;
                        RD_U8(D_overlay_143_08F032B0, 0x1A) =
                            (RD_U8(D_overlay_143_08F032B0, 0x1A) & 0x0F) | 0x30;
                        RD_U8(D_overlay_143_08F032B0, 0x1) = 5;
                        RD_U8(D_overlay_143_08F032B0, 0x30) = 7;
                    }
                } else {
                    D_overlay_143_08F032B4 = RD_PTR(obj, 0x68);
                    if (RD_U16(D_overlay_143_08F032B4, 0x2C) != 0x144) {
                        D_overlay_143_08F032BC = obj;
                        RD_U8(D_overlay_143_08F032B4, 0x1A) =
                            (RD_U8(D_overlay_143_08F032B4, 0x1A) & 0x0F) | 0x30;
                        RD_U8(D_overlay_143_08F032B4, 0x1) = 5;
                        RD_U8(D_overlay_143_08F032B4, 0x30) = 7;
                    }
                }
            } while (idx-- != 0);
        }

        /* scan object list for type 0x5B: first to C0, second to C4 */
        if (objStart < objEnd) {
            idx = objStart;
            do {
                obj = (u8 *) objList[idx];
                if (RD_S16(obj, 0x48) == 0x5B) {
                    if (D_overlay_143_08F032C0 == NULL) {
                        D_overlay_143_08F032C0 = obj;
                    } else {
                        D_overlay_143_08F032C4 = obj;
                        break;
                    }
                }
                idx += 1;
            } while (idx < objEnd);
        }

        damagecrateChangeHitsmin(0x2CC, 0x7FFF);
        D_overlay_143_08F03274 = 0;
        sub4c = RD_PTR(arg0, 0x4C);
        cnt = RD_S16(sub4c, 0x32);
        if (cnt != 0) {
            ex = RD_PTR(sub4c, 0x40);
            idx = cnt - 1;
            do {
                rec = ex + idx * 0x34;
                RD_U8(rec, 0x2F) = 0;
                RD_U8(rec, 0x30) = RD_U8(rec, 0x30) | 0x20;
            } while (idx-- != 0);
        }
    }

    /* EF0: clamp base->unk6 from the reference object while phase < 3 */
    if ((RD_U8(st, 1) & 0xF) < 3) {
        RD_S16(RD_PTR(arg0, 0x4C), 6) = RD_S16(ref, 0x2A);
    }

    if (D_overlay_143_08F03274 == 0) {
        damagecrateRepair(D_overlay_143_08F032C0);
        damagecrateRepair(D_overlay_143_08F032C4);
    }

    /* countdown; when it hits zero, drop the 0x30 flag bits from arg0->unk84 */
    if (RD_U8(st, 3) != 0) {
        RD_U8(st, 3) = RD_U8(st, 3) - 1;
        if (RD_U8(st, 3) == 0) {
            RD_S32(arg0, 0x84) = RD_S32(arg0, 0x84) & ~0x30;
        }
    }

    /* reset the 8 child objects */
    if (RD_PTR(st, 8) != NULL) {
        for (idx = 0; idx < 8; idx++) {
            child = RD_PTR(st, 8 + idx * 4);
            ch68 = RD_PTR(child, 0x68);
            s1 = RD_PTR(ch68, 0);
            s2 = RD_PTR(s1, 0x68);
            RD_F32(child, 0xC) = 0.0f;
            RD_F32(child, 0x10) = -1000.0f;
            RD_F32(child, 0x14) = 0.0f;
            RD_S32(child, 0x8C) = 0;
            RD_S16(child, 0x6) = RD_S16(child, 0x6) | 0x400;
            RD_S16(s2, 0xA78) = 0;
            RD_S16(s2, 0xA7A) = 0;
        }
    }

    if (RD_U8(st, 0) != 0) {
        sub = RD_U8(st, 2);
        cnt = D_overlay_143_08F02F70[sub];
        half = cnt >> 1;
        pat = (s8 *) D_overlay_143_08F02F64[sub];
        n = cnt;
        if (RD_S8(D_overlay_143_08F032C0, 0x3A) != 0) {
            n = cnt - half;
        }
        if (RD_S8(D_overlay_143_08F032C4, 0x3A) != 0) {
            pat += half * 2;
            n -= half;
        }

        if (n != 0) {
            /* fill the two pattern rows (st+0x28 / st+0x30) */
            idx = n - 1;
            do {
                RD_S8(st, 0x28 + idx) = pat[0];
                RD_S8(st, 0x30 + idx) = pat[1];
                pat += 2;
            } while (idx-- != 0);

            /* per entry: aim child objects between the two sample points */
            idx = n - 1;
            do {
                func_overlay_143_08F0007C_1FD9A14(arg0, RD_S8(st, 0x28 + idx), &sp8C, &sp88, &sp84);
                func_overlay_143_08F0007C_1FD9A14(arg0, RD_S8(st, 0x30 + idx), &sp80, &sp7C, &sp78);
                if (RD_S8(st, 0x30 + idx) == -8) {
                    sp74 = sp80;
                    sp70 = sp7C;
                    sp6C = sp78;
                }
                child = RD_PTR(st, 8 + idx * 4);
                ch68 = RD_PTR(child, 0x68);
                s1 = RD_PTR(ch68, 0);
                RD_F32(s1, 0xC) = sp8C;
                s2 = RD_PTR(s1, 0x68);
                RD_F32(s1, 0x10) = sp88;
                RD_F32(s1, 0x14) = sp84;

                dx = sp80 - sp8C;
                dy = sp7C - sp88;
                dz = sp78 - sp84;
                horiz = sqrtf((dx * dx) + (dz * dz));
                dist = sqrtf((dy * dy) + ((dx * dx) + (dz * dz)));

                RD_S16(s1, 0x0) = (s16) (0x4000 - (s32) Arctanf(dz, dx));
                RD_S16(s1, 0x2) = (s16) ((s32) Arctanf(horiz, dy) + 0x4000);
                v = (s32) dist;
                RD_S16(s2, 0xA78) = (s16) v;
                RD_S16(s2, 0xA7A) = (s16) v;
                RD_S16(s1, 0x2E) = RD_S16(player, 0x2E);
                RD_S32(child, 0x8C) = v;
                RD_S16(child, 0x6) = RD_S16(child, 0x6) & 0xFBFF;
            } while (idx-- != 0);
        }

        if (RD_U8(st, 2) == 2) {
            RD_U8(st, 0) = 0;
            RD_U8(st, 1) = RD_U8(st, 1) + 0x10;
            explosionStart(0x10, (s16) (s32) sp74, (s16) (s32) sp70, (s16) (s32) sp6C, 0x64, 0);
        }
    }

    /* track the two pattern objects B0/B4 (positions copied from the ex sub-struct) */
    ex = RD_PTR(RD_PTR(arg0, 0x4C), 0x40);
    if (RD_U8(D_overlay_143_08F032B0, 0x30) != 7 && RD_U8(D_overlay_143_08F032B0, 0x30) != 0xA) {
        RD_F32(D_overlay_143_08F032B8, 0xC) = RD_F32(ex, 0x450);
        RD_F32(D_overlay_143_08F032B8, 0x10) = RD_F32(ex, 0x454);
        RD_F32(D_overlay_143_08F032B8, 0x14) = RD_F32(ex, 0x458);
    }
    if (RD_U8(D_overlay_143_08F032B4, 0x30) != 7 && RD_U8(D_overlay_143_08F032B4, 0x30) != 0xA) {
        RD_F32(D_overlay_143_08F032BC, 0xC) = RD_F32(ex, 0x484);
        RD_F32(D_overlay_143_08F032BC, 0x10) = RD_F32(ex, 0x488);
        RD_F32(D_overlay_143_08F032BC, 0x14) = RD_F32(ex, 0x48C);
    }
    RD_U8(D_overlay_143_08F032B0, 0x91) = 3;
    RD_U8(D_overlay_143_08F032B4, 0x91) = 3;

    RD_PTR(base, 0x64) = player;
    RD_S16(base, 0x10) = (s16) ((s32) Arctanf(RD_F32(arg0, 0xC) - RD_F32(player, 0xC),
                                              RD_F32(arg0, 0x14) - RD_F32(player, 0x14))
                               - RD_S16(arg0, 0x0));

    switch (RD_U8(st, 1) & 0xF) {
    case 1:
        v = RD_U16(base, 0x5A);
        t7 = v & 4;
        if (!(v & 2) && RD_S16(ex, 0x470) >= 0x701) {
            RD_U16(base, 0xA0) = RD_U16(base, 0xA0) | 2;
            RD_U8(ex, 0x474) = RD_U8(ex, 0x474) | 0x40;
            objEnsureNotTargetted(arg0, base);
            if (RD_U8(D_overlay_143_08F032B0, 0x30) == 1) {
                RD_U8(D_overlay_143_08F032B0, 0x1) = RD_U8(D_overlay_143_08F032B0, 0x63);
                RD_U8(D_overlay_143_08F032B0, 0x30) = 3;
                RD_U8(D_overlay_143_08F032B0, 0x1A) =
                    (RD_U8(D_overlay_143_08F032B0, 0x1A) & 0x0F) | 0x40;
            } else {
                RD_U8(D_overlay_143_08F032B0, 0x30) = 0xA;
            }
            t7 = RD_U16(base, 0x5A) & 4;
        }
        if (t7 == 0 && RD_S16(ex, 0x4A4) >= 0x701) {
            RD_U16(base, 0xA0) = RD_U16(base, 0xA0) | 4;
            RD_U8(ex, 0x4A8) = RD_U8(ex, 0x4A8) | 0x40;
            objEnsureNotTargetted(arg0, base);
            if (RD_U8(D_overlay_143_08F032B4, 0x30) == 1) {
                RD_U8(D_overlay_143_08F032B4, 0x1) = RD_U8(D_overlay_143_08F032B4, 0x63);
                RD_U8(D_overlay_143_08F032B4, 0x30) = 3;
                RD_U8(D_overlay_143_08F032B4, 0x1A) =
                    (RD_U8(D_overlay_143_08F032B4, 0x1A) & 0x0F) | 0x40;
            } else {
                RD_U8(D_overlay_143_08F032B4, 0x30) = 0xA;
            }
        }
        break;

    case 2:
        v = RD_U16(base, 0x5A);
        t3 = v & 0x10;
        if (!(v & 8) && RD_S16(ex, 0x43C) >= 0x701) {
            RD_U16(base, 0xA0) = RD_U16(base, 0xA0) | 8;
            RD_U8(ex, 0x440) = RD_U8(ex, 0x440) | 0x40;
            objEnsureNotTargetted(arg0, base);
            t3 = RD_U16(base, 0x5A) & 0x10;
        }
        if (t3 == 0 && RD_S16(ex, 0x3D4) >= 0x701) {
            RD_U16(base, 0xA0) = RD_U16(base, 0xA0) | 0x10;
            RD_U8(ex, 0x3D8) = RD_U8(ex, 0x3D8) | 0x40;
            objEnsureNotTargetted(arg0, base);
        }
        break;

    default:
        /* case 3 and others: no change */
        break;
    }

    /* clear arg0->unk84 pending bits once the matching base->unk5A bit is set */
    v = RD_S32(arg0, 0x84);
    if (v & 1) {
        if (RD_U16(base, 0x5A) & 0x10) {
            v = v & ~1;
            RD_S32(arg0, 0x84) = v;
        }
    }
    t3 = v & 4;
    if (v & 2) {
        if (RD_U16(base, 0x5A) & 8) {
            v = v & ~2;
            RD_S32(arg0, 0x84) = v;
        }
        t3 = v & 4;
    }
    t9 = v & 8;
    if (t3 != 0) {
        if (RD_U16(base, 0x5A) & 2) {
            v = v & ~4;
            RD_S32(arg0, 0x84) = v;
        }
        t9 = v & 8;
    }
    if (t9 != 0 && (RD_U16(base, 0x5A) & 4)) {
        v = v & ~8;
        RD_S32(arg0, 0x84) = v;
    }

    /* append the player position to the 0x29-entry ring buffer */
    idx = D_overlay_143_08F03270;
    rec = D_overlay_143_08F02FE0 + idx * 0x10;
    RD_F32(rec, 0x0) = RD_F32(RD_PTR(player, 0x4C), 0xC);
    RD_F32(rec, 0x4) = RD_F32(RD_PTR(player, 0x4C), 0x10);
    RD_F32(rec, 0x8) = RD_F32(RD_PTR(player, 0x4C), 0x14);
    RD_U8(rec, 0xC) = (u8) iDeltaTime;
    idx += 1;
    D_overlay_143_08F03270 = idx;
    if (idx >= 0x29) {
        D_overlay_143_08F03270 = 0;
    }

    /* line-of-sight check, then pick the next animation */
    if (RD_U8(ref, 0x30) == 3 && RD_U8(base, 0x4A) == 0 && RD_U8(base, 0x1A) != 5) {
        if (CheckLineOfSight(arg0, base) != 0 && TryToSetMission(0x10, 5, 0, 0, 0) != 0) {
            v = RD_U8(st, 1);
            if (v == 4 || (RD_S8(D_overlay_143_08F032C0, 0x3A) != 0 &&
                           RD_S8(D_overlay_143_08F032C4, 0x3A) != 0 && v == 3)) {
                v = (RD_U8(st, 1) + 0x10) & 0xFF;
                RD_U8(st, 1) = v;
            }
            if (v == 1) {
                a2 = 5;
            } else if (v == 2) {
                a2 = 6;
            } else {
                a2 = 7;
                if (v != 3) {
                    a2 = 0x22;
                }
            }
            UpdateOrSetAnim(6, 0x3F800000, a2);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o143/overlay_143/BTSBFatBob.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// FatBob boss phase transition; arg1 is the phase/event id (switch 1..10).
// base = obj+0x68 (boss state), st = base+0xA8 (st+0 flag, st+1 phase, st+2 sub, st+3 mode).
void FatBobPhaseChange(void *arg0, s32 arg1) {
    u8 *base;
    u8 *st;
    u8 *closest;
    u8 *sub4c;     /* obj+0x4C */
    u8 *ex;        /* obj+0x4C -> +0x40 */
    u8 *rec;
    u8 *child;
    u8 *slot;
    s32 cnt;
    s32 idx;
    s32 off;
    s32 count;
    f32 px;
    f32 py;
    f32 pz;
    f32 cx;
    f32 cy;
    f32 cz;
    u8 spawnA[0x18];   /* asm sp+0x84 record */
    u8 spawnB[0x0C];   /* asm sp+0x60 record */
    u8 spawnC[0x18];   /* asm sp+0x38 record */

    base = RD_PTR(arg0, 0x68);
    st = RD_PTR(base, 0xA8);
    closest = (u8 *) squadsGetClosestPlayer();   /* asm: called unconditionally before the switch */

    switch (arg1) {
    case 1:
        if (D_overlay_143_08F032CC != 0) {
            if (RD_U16(base, 0x5A) & 8) {
                D_overlay_143_08F032CC = 0;
            }
        } else if (RD_U16(base, 0x5A) & 0x10) {
            D_overlay_143_08F032CC = 1;
        }
        ex = RD_PTR(RD_PTR(arg0, 0x4C), 0x40);
        if (D_overlay_143_08F032CC != 0) {
            RD_S32(arg0, 0x84) |= 2;
            RD_U8(ex, 0x440) &= 0xDF;
            RD_U8(ex, 0x43F) = 0x64;
            RD_U16(base, 0xA4) |= 0x20;
        } else {
            RD_S32(arg0, 0x84) |= 1;
            RD_U8(ex, 0x3D8) &= 0xDF;
            RD_U8(ex, 0x3D7) = 0x64;
            RD_U16(base, 0xA4) |= 0x10;
        }
        objSetFlashPartColour(0xFF, 0xFF, 0xFF, 1);
        break;

    case 2:
        RD_U8(st, 1) += 0x10;
        RD_S32(arg0, 0x84) = 0;
        ex = RD_PTR(RD_PTR(arg0, 0x4C), 0x40);
        if (D_overlay_143_08F032CC != 0) {
            if (RD_U16(base, 0x5A) & 8) {
                break;
            }
            RD_U8(ex, 0x440) |= 0x20;
            RD_U8(ex, 0x43F) = 0;
            px = RD_F32(ex, 0x41C);
            py = RD_F32(ex, 0x420);
            pz = RD_F32(ex, 0x424);
        } else {
            if (RD_U16(base, 0x5A) & 0x10) {
                break;
            }
            RD_U8(ex, 0x3D8) |= 0x20;
            RD_U8(ex, 0x3D7) = 0;
            px = RD_F32(ex, 0x3B4);
            py = RD_F32(ex, 0x3B8);
            pz = RD_F32(ex, 0x3BC);
        }
        /* spawn record A: 0x2D4 at closest-relative offsets, /10 deltas to the player */
        RD_S16(spawnA, 0x0) = 0x2D4;
        RD_U8(spawnA, 0x2) = 0x18;
        RD_U8(spawnA, 0x3) = 0;
        RD_S16(spawnA, 0x4) = (s16) (s32) px;
        RD_S16(spawnA, 0x6) = (s16) (s32) py;
        RD_S16(spawnA, 0x8) = (s16) (s32) pz;
        RD_U8(spawnA, 0xA) = 0;
        RD_U8(spawnA, 0xB) = 0x64;
        RD_S16(spawnA, 0xC) = (s16) (s32) ((RD_F32(closest, 0xC) - px) / 10.0f);
        RD_S16(spawnA, 0xE) = (s16) (s32) ((RD_F32(closest, 0x10) - py) / 10.0f);
        RD_S16(spawnA, 0x10) = (s16) (s32) ((RD_F32(closest, 0x14) - pz) / 10.0f);
        RD_PTR(spawnA, 0x14) = arg0;
        /* sig mismatch: asm passes the three positions as f32 bit patterns */
        ((void (*)(u16, f32, f32, f32, s32, void *))amSndPlayXYZ)(0x95, (f32) RD_S16(spawnA, 0x4),
            (f32) RD_S16(spawnA, 0x6), (f32) RD_S16(spawnA, 0x8), 4, NULL);
        child = objSetupObject(spawnA, 1);
        if (child != NULL) {
            RD_S32(child, 0x3C) = 0;
        }
        break;

    case 3:
        if (D_overlay_143_08F032CC != 0) {
            if (RD_U16(base, 0x5A) & 2) {
                D_overlay_143_08F032CC = 0;
            }
        } else if (RD_U16(base, 0x5A) & 4) {
            D_overlay_143_08F032CC = 1;
        }
        ex = RD_PTR(RD_PTR(arg0, 0x4C), 0x40);
        if (D_overlay_143_08F032CC != 0) {
            RD_S32(arg0, 0x84) |= 4;
            RD_U8(ex, 0x474) &= 0xDF;
            RD_U8(ex, 0x473) = 0x64;
            RD_U16(base, 0xA4) |= 2;
        } else {
            RD_S32(arg0, 0x84) |= 8;
            RD_U8(ex, 0x4A8) &= 0xDF;
            RD_U8(ex, 0x4A7) = 0x64;
            RD_U16(base, 0xA4) |= 4;
        }
        objSetFlashPartColour(0xFF, 0xFF, 0xFF, 1);
        D_overlay_143_08F032C8 = 1;
        break;

    case 4:
        D_overlay_143_08F032C8 = 0;
        if (D_overlay_143_08F032CC != 0) {
            rec = (u8 *) D_overlay_143_08F032B0;
        } else {
            rec = (u8 *) D_overlay_143_08F032B4;
        }
        if (RD_U8(rec, 0x30) != 0xA) {
            RD_U8(rec, 0x30) = 0;
            RD_U8(rec, 0x63) = 0;
            RD_U8(rec, 0x0) = 0;
            RD_U8(rec, 0x91) = 3;
        }
        break;

    case 5:
        RD_S32(arg0, 0x84) = 0;
        ex = RD_PTR(RD_PTR(arg0, 0x4C), 0x40);
        RD_U8(ex, 0x474) |= 0x20;
        RD_U8(ex, 0x473) = 0;
        RD_U8(ex, 0x4A8) |= 0x20;
        RD_U8(ex, 0x4A7) = 0;
        RD_U8(st, 1) += 0x10;
        break;

    case 6:
        sub4c = RD_PTR(arg0, 0x4C);
        ex = RD_PTR(sub4c, 0x40);
        if (RD_S32(ex, 0x33C) & 0x20000000) {
            count = RD_S16(sub4c, 0x32);
            if (count != 0) {
                /* asm do/while: body runs count times, tests the pre-decrement index */
                idx = count - 1;
                off = idx * 0x34;
                do {
                    rec = ex + off;
                    if (!(RD_S32(rec, 0x30) & 0x40000000)) {
                        RD_U8(rec, 0x2F) = 0x64;
                        RD_U8(rec, 0x30) &= 0xDF;
                    }
                    off -= 0x34;
                } while (idx-- != 0);
            }
            RD_U16(base, 0xA4) = 0xFFFF;
            objSetFlashPartColour(0xFF, 0xFF, 0xFF, 0xB);
        }
        damagecrateChangeHitsmin(0x2CC, 1);
        D_overlay_143_08F03274 = 1;
        if (RD_S8(D_overlay_143_08F032C0, 0x3A) == 0 || RD_S8(D_overlay_143_08F032C4, 0x3A) == 0) {
            RD_U8(st, 0) = 1;
            RD_U8(st, 2) = 0;
        } else {
            ClearMissionFields(1, 0);
            RD_U8(base, 0x4B) = 0;
            RD_U8(st, 1) += 0x10;
        }
        break;

    case 7:
        RD_U8(st, 2) = 1;
        break;

    case 8:
        RD_U8(st, 2) = 2;
        break;

    case 10:
        /* spawn record B: 0x2CA, lo-res child positions, obj Y */
        RD_S16(spawnB, 0x0) = 0x2CA;
        RD_U8(spawnB, 0x2) = 0xA;
        squadsGetChildPolyPosition(0xE, &cx, &cy, &cz);
        RD_S16(spawnB, 0x4) = (s16) (s32) cx;
        RD_S16(spawnB, 0x6) = (s16) (s32) RD_F32(arg0, 0x10);
        RD_S16(spawnB, 0x8) = (s16) (s32) cz;
        child = objSetupObject(spawnB, 1);
        if (child != NULL) {
            RD_S32(child, 0x3C) = 0;
        }
        squadsGetChildPolyPosition(0xC, &cx, &cy, &cz);
        RD_S16(spawnB, 0x4) = (s16) (s32) cx;
        RD_S16(spawnB, 0x6) = (s16) (s32) RD_F32(arg0, 0x10);
        RD_S16(spawnB, 0x8) = (s16) (s32) cz;
        child = objSetupObject(spawnB, 1);
        if (child != NULL) {
            RD_S32(child, 0x3C) = 0;
        }
        amSndPlay(0x1CC, NULL);
        RD_S32(arg0, 0x84) |= 0x30;
        RD_U8(st, 3) = 2;
        RD_U8(st, 1) = RD_U8(st, 1) & 0xF;
        D_overlay_143_08F032CC ^= 1;

        switch (RD_U8(st, 1)) {
        case 1:
            if ((RD_U16(base, 0x5A) & 6) == 6) {
                RD_U8(st, 1) = 2;
            }
            break;
        case 2:
            if ((RD_U16(base, 0x5A) & 0x18) == 0x18) {
                RD_U8(st, 1) = 3;
                /* spawn record C: 0xDB, 0x18 ... ptr to obj at +0x14 */
                RD_S16(spawnC, 0x0) = 0xDB;
                RD_U8(spawnC, 0x2) = 0x18;
                RD_S16(spawnC, 0x4) = 0;
                RD_S16(spawnC, 0x6) = 0;
                RD_S16(spawnC, 0x8) = 0;
                RD_S16(spawnC, 0xA) = 0;
                RD_S16(spawnC, 0xC) = 0;
                RD_S16(spawnC, 0xE) = 0;
                RD_U8(spawnC, 0x10) = 0x28;
                RD_U8(spawnC, 0x11) = 2;
                RD_PTR(spawnC, 0x14) = arg0;
                slot = st + 0x1C;
                cnt = 7;
                do {
                    child = objSetupObject(spawnC, 1);
                    RD_PTR(slot, 0x8) = child;
                    RD_S32(child, 0x8C) = 0x64;
                    slot -= 4;
                } while (cnt-- != 0);
            }
            break;
        case 3:
            if (RD_S8(D_overlay_143_08F032C0, 0x3A) != 0 && RD_S8(D_overlay_143_08F032C4, 0x3A) != 0) {
                RD_U8(st, 1) = 4;
            }
            break;
        }
        break;

    default:
        break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o143/overlay_143/FatBobPhaseChange.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void GalaxianBatsMover(void *arg0) {
    u8 *data;
    u8 *other;
    u16 timer;

    data = RD_PTR(arg0, 0x68);
    other = RD_PTR(data, 0x64);
    if (D_overlay_143_08F032C8 != 0) {
        RD_S16(RD_PTR(arg0, 0x4C), 0x6) = -0x400;
    }
    timer = (u16)(RD_U16(data, 0xA8) + iDeltaTime);
    RD_U16(data, 0xA8) = timer;
    if (timer >= 0xB5) {
        RD_U16(data, 0xAA) = 1;
    }
    if (RD_U8(data, 0x18) != 0 || RD_U16(data, 0xAA) != 0) {
        RD_S16(RD_PTR(arg0, 0x4C), 0x6) = -0x400;
        return;
    }
    RD_F32(data, 0x38) = RD_F32(RD_PTR(other, 0x4C), 0x18);
    RD_F32(data, 0x3C) = RD_F32(RD_PTR(other, 0x4C), 0x1C);
    RD_F32(data, 0x40) = RD_F32(RD_PTR(other, 0x4C), 0x20);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o143/overlay_143/GalaxianBatsMover.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void GalaxianBatsSoundsHandler(void *arg0) {
    u8 *first;
    u8 *node;
    u8 *pick;
    s32 pickIdx;
    s32 i;

    if (RD_S32(arg0, 0x84) == 0 && mathRnd(0, 0x64) >= 0x60) {
        first = RD_PTR(arg0, 0x58);
        pickIdx = mathRnd(0, RD_U8(arg0, 0));
        pick = first;
        i = 0;
        for (node = first; node != NULL; node = RD_PTR(RD_PTR(node, 0x68), 0x28)) {
            if (i == pickIdx) {
                pick = node;
            }
            i += 1;
        }
        if (pick != NULL && RD_S16(RD_PTR(pick, 0x68), 0xA6) > 0) {
            amSndPlayXYZ(0x1E3, RD_S32(pick, 0xC), RD_S32(pick, 0x10), RD_S32(pick, 0x14), 4,
                         (u8 *)arg0 + 0x84);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o143/overlay_143/GalaxianBatsSoundsHandler.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Procedural fire for the Fat Bob boss. tex[0] = row stride (width), tex[1] =
// height, IA16 output pixels at tex + 0x20. Each call reseeds the bottom row of
// the old buffer, diffuses the new buffer upwards from it, cools it by 3 and
// writes IA16 (I = value, A = value * (value >> 4) clamped to 0xFF). Rows with
// an even countdown (height - 1 - row) are stored with their 32-bit words
// swapped (halfword index ^ 2), as the RDP expects (cf. jfg-re docs/textures.md).
void GenerateFireTexture(s32 idx, u8 *tex, s32 unused) {
    u8 *oldBuf;
    u8 *newBuf;
    u8 *seed;
    u8 *s0;
    u8 *s1;
    u8 *s2;
    u8 *d;
    u8 *in;
    u16 *out;
    s32 width;
    s32 height;
    s32 count;
    s32 x;
    s32 y;
    s32 row;
    s32 i;
    s32 v;
    s32 a;
    s32 swizzled;

    width = tex[0];
    height = tex[1];
    count = width * height;

    if (D_overlay_143_08F02F7C != 0) {
        oldBuf = CpuTexSpaceA[idx];
    } else {
        oldBuf = CpuTexSpaceB[idx];
    }

    /* reseed the bottom row of the old buffer */
    seed = oldBuf + (height - 1) * width;
    if (width != 0) {
        for (x = 0; x < width; x++) {
            seed[x] = (u8) mathRnd(0, 0xFF);
        }
    }

    /* flip the selector; the new buffer is the one it now points at */
    D_overlay_143_08F02F7C = (u8) (D_overlay_143_08F02F7C ^ 1);
    if (D_overlay_143_08F02F7C != 0) {
        newBuf = CpuTexSpaceA[idx];
    } else {
        newBuf = CpuTexSpaceB[idx];
    }

    /* diffuse rows 0 .. height-2 of newBuf from oldBuf rows y and y+1 */
    if (height - 1 != 0) {
        for (y = 0; y < height - 1; y++) {
            s0 = oldBuf + y * width;
            s1 = s0 + width;
            s2 = s1 + width;
            d = newBuf + y * width;
            /* asm: first pixel uses the previous row's last pixel as left neighbour */
            d[0] = (u8) ((s1[0] + s0[0] + s2[-1] + s1[1]) >> 2);
            for (x = 1; x < width - 1; x++) {
                d[x] = (u8) ((s1[x] + s0[x] + s1[x - 1] + s1[x + 1]) >> 2);
            }
            /* asm: last pixel reads the next row's first pixel as right neighbour */
            d[width - 1] = (u8) ((s1[width - 1] + s0[width - 1] + s1[width - 2] + s0[width]) >> 2);
        }
    }

    /* cool the whole new buffer */
    for (i = 0; i < count; i++) {
        v = newBuf[i] - 3;
        if (v < 0) {
            v = 0;
        }
        newBuf[i] = (u8) v;
    }

    /* one-shot: start from the base pattern */
    if (D_overlay_143_08F02F80 != 0) {
        for (i = 0; i < count; i++) {
            newBuf[i] = D_overlay_143_08F02BC0[i];
        }
        D_overlay_143_08F02F80 = 0;
    }

    /* convert to IA16 */
    out = (u16 *) (tex + 0x20);
    in = newBuf;
    for (row = 0; row < height; row++) {
        swizzled = ((height - 1 - row) & 1) == 0;
        for (x = 0; x < width; x++) {
            v = in[x];
            a = v;
            if ((v >> 4) != 0) {
                a = v * (v >> 4);
            }
            if (a >= 0x100) {
                a = 0xFF;
            }
            out[swizzled ? (x ^ 2) : x] = (u16) (a | (v << 8));
        }
        in += width;
        out += width;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o143/overlay_143/GenerateFireTexture.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void _AutoExit00143(void) {
    if (D_overlay_143_08F02F74 != 0) {
        amSndStop(D_overlay_143_08F02F74);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o143/overlay_143/_AutoExit00143.s")
#endif
