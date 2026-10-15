#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern u8 D_overlay_126_07E01250;
extern u8 D_overlay_126_07E012A0[];
extern u8 D_overlay_126_07E01268[];
extern s16 tvals[];
extern f32 D_overlay_126_07E01270;
extern f32 D_overlay_126_07E01294;
extern u8 D_overlay_126_07E01254;
extern f32 D_overlay_126_07E01274;
extern f32 D_overlay_126_07E01278;
extern f32 D_overlay_126_07E0127C;
extern f32 D_overlay_126_07E01280;
extern f32 D_overlay_126_07E01284;
extern f32 D_overlay_126_07E01288;
extern f32 D_overlay_126_07E0128C;
extern f32 D_overlay_126_07E01290;
void **objGetPlayerlist(s32 *count);
void **objGetAnimPlayerlist(s32 *count);
f32 Sinf(s16 angle);
void partUpdateTriggers(void *obj, s32 arg1);
void setupClearScreen(void *dl);
void updateColourCycle(void *cycle, s32 arg1, void *arg2);
void amSndPlay(u16 soundId, void *handle);
void amSndSetPitchDirect(s32 handle, f32 pitch);
void amSndStop(s32 handle);
void camPushFloatModelMtx(Gfx **dl, s32 *arg1, Mtx *mtx);
void frontDrawRectangle(Gfx **dl, s32 x, s32 y, s32 w, s32 h, s32 colour);
void mathTranslateMtx(Mtx *mtx, s32 x, f32 y, s32 z);
void matrixScale(f32 x, f32 y, f32 z, Mtx *mtx);
void matrixYaw(s16 yaw, Mtx *mtx);
void texDPTextureX(Gfx **dl, s32 a, s32 b, s32 c);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void teleportEffectInit(void *arg0, void *arg1) {
    u8 *state;
    u8 *ent;
    s16 *tv;
    s32 i;
    s32 v1;
    s32 a1v;
    s16 angle;
    s32 k;
    f32 scale;
    f32 f26;
    f32 f22;
    ObjectHeader48 hdr;

    if (D_overlay_126_07E01250 == 0) {
        ent = D_overlay_126_07E012A0;
        tv = tvals;
        v1 = 0x7E0;
        do {
            for (i = 0; i < 8; i++) {
                s32 ai = i * 2;

                ent[0x00] = 0x40;
                ent[0x01] = (u8) ai;
                ent[0x02] = (u8) ((ai + 2) & 0xF);
                ent[0x03] = (u8) ((ai + 1) & 0xF);
                *(s16 *)(ent + 0x04) = (s16) v1;
                a1v = v1 - 0xFC;
                *(s16 *)(ent + 0x06) = tv[0];
                *(s16 *)(ent + 0x08) = (s16) a1v;
                *(s16 *)(ent + 0x0A) = tv[0];
                *(s16 *)(ent + 0x0C) = (s16) v1;
                *(s16 *)(ent + 0x0E) = tv[1];
                ent[0x10] = 0x40;
                ent[0x11] = (u8) ((ai + 2) & 0xF);
                ent[0x12] = (u8) ((ai + 1) & 0xF);
                ent[0x13] = (u8) ((ai + 3) & 0xF);
                *(s16 *)(ent + 0x14) = (s16) a1v;
                *(s16 *)(ent + 0x16) = tv[0];
                *(s16 *)(ent + 0x18) = (s16) v1;
                *(s16 *)(ent + 0x1A) = tv[1];
                *(s16 *)(ent + 0x1C) = (s16) a1v;
                *(s16 *)(ent + 0x1E) = tv[1];
                ent += 0x20;
                v1 = a1v;
            }
            tv += 2;
            v1 = 0x7E0;
        } while (tv != (s16 *)D_overlay_126_07E01268);
        D_overlay_126_07E01250 = 1;
    }

    state = *(u8 **)((u8 *)arg0 + 0x68);
    *(s16 *)(state + 0xF90) = *(s16 *)((u8 *)arg1 + 0x22) >> 1;
    scale = *(f32 *)*(u8 **)((u8 *)arg0 + 0x40);
    *(f32 *)(state + 0xF94) = (scale * (f32) *(u16 *)((u8 *)arg1 + 0x24)) / 100.0f;
    f26 = (f32) *(u16 *)((u8 *)arg1 + 0x26);
    state[0xFC9] = 0;
    *(f32 *)(state + 0xFBC) = 0.5f;
    *(f32 *)(state + 0xF98) = (scale * f26) / 100.0f;
    f22 = D_overlay_126_07E01270;

    angle = 0;
    for (k = 0; k < 4; k++) {
        *(s16 *)(state + 0xF88 + k * 2) = angle;
        *(s16 *)(state + 0xF00 + k * 2) = -0x4000;
        *(s16 *)(state + 0xF10 + k * 2) = 0;
        *(s16 *)(state + 0xF08 + k * 2) = *(s16 *)((u8 *)arg1 + 0xA + k * 2);
        angle += 0x1000;
        *(s16 *)(state + 0xF18 + k * 2) = *(s16 *)((u8 *)arg1 + 0x12 + k * 2);
        state[0xF40 + k] = 0;
        state[0xF44 + k] = ((u8 *)arg1)[0x1A + k];
        *(f32 *)(state + 0xFAC + k * 4) = 1.0f;
        *(f32 *)(state + 0xF20 + k * 4) =
            (f32) (s16) (s32) (*(f32 *)((u8 *)arg0 + 0x10) + (f32) *(s16 *)((u8 *)arg1 + 0x22));
        *(f32 *)(state + 0xF9C + k * 4) = *(f32 *)(state + 0xF94) - f22;
        initColourCycle((unkResetColourCycle *) (state + 0xF48 + k * 0x10), ((u8 *)arg1)[0x1E + k]);

        hdr.unk0 = 1;
        hdr.unk1 = 3;
        hdr.unk2 = 0x40;
        hdr.unk3 = 0xFF;
        hdr.unk4 = 0;
        hdr.unk5 = 0;
        hdr.unk6 = 0;
        hdr.unk8 = 0;
        hdr.unkC = 0x78;
        hdr.unkE = 0x78;
        hdr.unk12 = 0xFF;
        hdr.unk14 = 0xFFFF;
        hdr.unk16 = 0;
        *(s32 *)(state + 0xF2C + k * 4) = addObjectLight(NULL, &hdr);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o126/overlay_126/teleportEffectInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void teleportEffectControl(void *arg0, s32 arg1) {
    u8 *obj;
    u8 *state;
    u8 *cand;
    void **list;
    s32 count;
    s32 rem;
    s32 k;
    s32 pass;
    s32 i;
    s32 j;
    s32 ang;
    s32 ringIdx;
    s32 cnt20;
    s32 angStep;
    u8 *vtx;
    u8 *s2;
    u8 toggle;
    u8 v;
    UnkLight *light;
    f32 minD;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 d2;
    f32 dt;
    f32 prevY;
    f32 fac;
    f32 vel;
    f32 sinT;
    f32 cosT;
    f32 sinF88;
    f32 sinF00;
    f32 cosF00;
    f32 f90f;
    f32 savedY;
    f32 base;
    f32 step;
    f32 twoF;
    f32 ring[6];

    obj = (u8 *)arg0;
    state = *(u8 **)(obj + 0x68);
    minD = D_overlay_126_07E01274;

    /* nearest player search (only while FC0 is unset) */
    if (*(u8 **)(state + 0xFC0) == NULL) {
        list = objGetPlayerlist(&count);
        pass = 0;
        do {
            if (count > 0) {
                rem = count & 3;
                k = 0;
                if (rem != 0) {
                    do {
                        cand = (u8 *)list[k];
                        dx = *(f32 *)(cand + 0xC) - *(f32 *)(obj + 0xC);
                        dy = *(f32 *)(cand + 0x10) - *(f32 *)(obj + 0x10);
                        dz = *(f32 *)(cand + 0x14) - *(f32 *)(obj + 0x14);
                        d2 = (dx * dx) + (dy * dy) + (dz * dz);
                        if (d2 < minD) {
                            minD = d2;
                            *(u8 **)(state + 0xFC0) = cand;
                        }
                        k++;
                    } while (k != rem);
                }
                if (k != count) {
                    do {
                        cand = (u8 *)list[k];
                        dx = *(f32 *)(cand + 0xC) - *(f32 *)(obj + 0xC);
                        dy = *(f32 *)(cand + 0x10) - *(f32 *)(obj + 0x10);
                        dz = *(f32 *)(cand + 0x14) - *(f32 *)(obj + 0x14);
                        d2 = (dx * dx) + (dy * dy) + (dz * dz);
                        if (d2 < minD) {
                            minD = d2;
                            *(u8 **)(state + 0xFC0) = cand;
                        }
                        cand = (u8 *)list[k + 1];
                        dx = *(f32 *)(cand + 0xC) - *(f32 *)(obj + 0xC);
                        dy = *(f32 *)(cand + 0x10) - *(f32 *)(obj + 0x10);
                        dz = *(f32 *)(cand + 0x14) - *(f32 *)(obj + 0x14);
                        d2 = (dx * dx) + (dy * dy) + (dz * dz);
                        if (d2 < minD) {
                            minD = d2;
                            *(u8 **)(state + 0xFC0) = cand;
                        }
                        cand = (u8 *)list[k + 2];
                        dx = *(f32 *)(cand + 0xC) - *(f32 *)(obj + 0xC);
                        dy = *(f32 *)(cand + 0x10) - *(f32 *)(obj + 0x10);
                        dz = *(f32 *)(cand + 0x14) - *(f32 *)(obj + 0x14);
                        d2 = (dx * dx) + (dy * dy) + (dz * dz);
                        if (d2 < minD) {
                            minD = d2;
                            *(u8 **)(state + 0xFC0) = cand;
                        }
                        cand = (u8 *)list[k + 3];
                        dx = *(f32 *)(cand + 0xC) - *(f32 *)(obj + 0xC);
                        dy = *(f32 *)(cand + 0x10) - *(f32 *)(obj + 0x10);
                        dz = *(f32 *)(cand + 0x14) - *(f32 *)(obj + 0x14);
                        d2 = (dx * dx) + (dy * dy) + (dz * dz);
                        if (d2 < minD) {
                            minD = d2;
                            *(u8 **)(state + 0xFC0) = cand;
                        }
                        k += 4;
                    } while (k != count);
                }
            }
            list = objGetAnimPlayerlist(&count);
            pass++;
        } while (pass != 2);
    }

    /* toggle the double-buffered vertex area */
    toggle = state[0xFC8] ^ 1;
    state[0xFC8] = toggle;
    vtx = state + (toggle & 0xFF) * 0x780;
    dt = (f32)arg1;
    angStep = arg1 << 8;

    /* per-light / per-petal update (4 indices) */
    for (i = 0; i < 4; i++) {
        *(s16 *)(state + 0xF88 + i * 2) = (s16)(*(s16 *)(state + 0xF88 + i * 2) + angStep);
        v = state[0xF44 + i];
        /* asm: reads F30 + 4*i here (Init stores lights at F2C + 4*k) */
        light = *(UnkLight **)(state + 0xF30 + i * 4);
        if (arg1 < (s32)v) {
            state[0xF44 + i] = (u8)(v - arg1);
            turnLightOff(light);
            continue;
        }

        state[0xF44 + i] = 0;
        s2 = state + i * 0x10;
        prevY = *(f32 *)(state + 0xF20 + i * 4);
        fac = *(f32 *)(state + 0xFAC + i * 4);
        if (fac == 0.0f) {
            *(s16 *)(state + 0xF00 + i * 2) = (s16)(s32)((f32)*(s16 *)(state + 0xF00 + i * 2) +
                ((f32)(*(s16 *)(state + 0xF08 + i * 2) * arg1) * *(f32 *)(state + 0xFBC)));
            *(s16 *)(state + 0xF10 + i * 2) =
                (s16)(*(s16 *)(state + 0xF10 + i * 2) + *(s16 *)(state + 0xF18 + i * 2) * arg1);
            *(s16 *)(state + 0xF88 + i * 2) = (s16)(*(s16 *)(state + 0xF88 + i * 2) + angStep);
            sinF88 = Sinf(*(s16 *)(state + 0xF88 + i * 2));
            cosF00 = Cosf((s32)*(s16 *)(state + 0xF00 + i * 2));
            *(f32 *)(state + 0xF9C + i * 4) =
                (cosF00 * D_overlay_126_07E01278) +
                (*(f32 *)(state + 0xF94) + (D_overlay_126_07E01278 * sinF88));
            f90f = (f32)*(s16 *)(state + 0xF90);
            sinF00 = Sinf(*(s16 *)(state + 0xF00 + i * 2));
            *(f32 *)(state + 0xF20 + i * 4) =
                (f32)(s16)(s32)((sinF00 * f90f) + (*(f32 *)(obj + 0x10) + f90f));
        } else {
            *(f32 *)(state + 0xF20 + i * 4) = prevY - (dt * fac);
            *(f32 *)(state + 0xFAC + i * 4) = fac + (dt * D_overlay_126_07E0127C);
            if (*(f32 *)(state + 0xF20 + i * 4) < *(f32 *)(obj + 0x10)) {
                *(f32 *)(state + 0xF20 + i * 4) = *(f32 *)(obj + 0x10);
                *(f32 *)(state + 0xFAC + i * 4) = 0.0f;
            }
        }

        /* fade toward 0xFF, arg1 steps */
        if (arg1 > 0) {
            k = 0;
            do {
                v = state[0xF40 + i];
                state[0xF40 + i] = (u8)(v + ((0xFF - v) >> 3));
                k++;
            } while (k < arg1);
        }
        state[0xF40 + i] = 0xFF;

        updateColourCycle(s2 + 0xF48, arg1, state + i * 2);

        *(f32 *)((u8 *)light + 0x18) = *(f32 *)(obj + 0xC);
        *(f32 *)((u8 *)light + 0x1C) = *(f32 *)(state + 0xF20 + i * 4);
        *(f32 *)((u8 *)light + 0x20) = *(f32 *)(obj + 0x14);
        turnLightOn(light);
        changeLightColour(light, s2[0xF50], s2[0xF51], s2[0xF52]);
        changeLightIntensity(light, state[0xF40 + i]);

        /* ring of 3 bands x 16 vertices; band heights in ring[] */
        ring[0] = 8.0f;
        ring[1] = 1.0f;
        ring[2] = 1.0f;
        ring[3] = -1.0f;
        ring[4] = -1.0f;
        ring[5] = -8.0f;
        vel = (*(f32 *)(state + 0xF20 + i * 4) - prevY) / dt;
        if (vel < 0.0f) {
            if (vel < D_overlay_126_07E01280) {
                vel = D_overlay_126_07E01284;
            }
            ring[5] = -4.0f;
            ring[0] = 8.0f * (1.0f - vel);
        } else {
            if (D_overlay_126_07E01288 < vel) {
                vel = D_overlay_126_07E0128C;
            }
            ring[0] = 4.0f;
            ring[5] = -8.0f * (1.0f + vel);
        }

        ringIdx = 0;
        do {
            ang = 0;
            j = 0;
            do {
                /* asm calls Sinf/Cosf twice each here (same angle, pure) */
                sinT = Sinf((s16)ang) * 15.0f;
                cosT = Cosf(ang) * 15.0f;

                /* vertex A */
                *(s16 *)(vtx + 0x0) = (s16)(s32)sinT;
                *(s16 *)(vtx + 0x2) = (s16)(s32)ring[ringIdx];
                *(s16 *)(vtx + 0x4) = (s16)(s32)cosT;
                vtx[0x6] = 0xFF;
                vtx[0x7] = 0xFF;
                vtx[0x8] = 0xFF;
                vtx[0x9] = 0xFF;

                /* vertex B */
                *(s16 *)(vtx + 0xA) = (s16)(s32)sinT;
                *(s16 *)(vtx + 0xC) = (s16)(s32)ring[ringIdx + 1];
                *(s16 *)(vtx + 0xE) = (s16)(s32)cosT;
                vtx[0x10] = 0xFF;
                vtx[0x11] = 0xFF;
                vtx[0x12] = 0xFF;
                vtx[0x13] = 0xFF;

                vtx += 0x14;
                ang += 0x2000;
                j++;
            } while (j != 8);
            ringIdx += 2;
        } while (ringIdx != 6);
    }

    *(f32 *)(state + 0xFBC) = *(f32 *)(state + 0xFBC) + (D_overlay_126_07E01290 * dt);
    *(s16 *)(state + 0xFCA) = (s16)(*(s16 *)(state + 0xFCA) + arg1);

    if (*(s16 *)(state + 0xFCA) >= 0x164) {
        savedY = *(f32 *)(obj + 0x10);
        *(s32 *)(obj + 0x84) = 1;
        *(f32 *)(obj + 0x10) = savedY + *(f32 *)(state + 0xF20);
        partUpdateTriggers(obj, arg1);
        *(f32 *)(obj + 0x10) = savedY;

        if (state[0xFC9] == 0) {
            setupClearScreen(&D_overlay_126_07E01254);
            state[0xFC9] = 1;
            f90f = (f32)*(s16 *)(state + 0xF90);
            *(s32 *)(obj + 0x84) = 3;
            twoF = f90f + f90f;
            base = twoF + savedY;
            step = twoF / 5.0f;
            cnt20 = 0;
            do {
                partUpdateTriggers(obj, 2);
                *(f32 *)(obj + 0x10) = *(f32 *)(obj + 0x10) + step;
                if (base < *(f32 *)(obj + 0x10)) {
                    *(f32 *)(obj + 0x10) = base - (*(f32 *)(obj + 0x10) - base);
                    step = -step;
                } else if (*(f32 *)(obj + 0x10) < savedY) {
                    *(f32 *)(obj + 0x10) = (savedY - *(f32 *)(obj + 0x10)) + savedY;
                    step = -step;
                }
                cnt20++;
            } while (cnt20 != 20);
        }

        if (*(s16 *)(state + 0xFCA) >= 0x168) {
            *(s16 *)(state + 0xFCA) = 0x168;
            cand = *(u8 **)(state + 0xFC0);
            *(s16 *)(cand + 0x6) = (s16)(*(s16 *)(cand + 0x6) | 0x400);
            if (*(s32 *)(state + 0xFC4) != 0) {
                amSndStop(*(s32 *)(state + 0xFC4));
            }
        }
    } else {
        if (*(s32 *)(state + 0xFC4) == 0) {
            amSndPlay(0xDC, state + 0xFC4);
        }
        amSndSetPitchDirect(*(s32 *)(state + 0xFC4), ((f32)*(s16 *)(state + 0xFCA) / 360.0f) + 0.5f);
        if (*(s16 *)(state + 0xFCA) >= 0x12D) {
            amSndPlay(0xDB, NULL);
        }
    }

    if (*(f32 *)(state + 0xFBC) >= 5.0f) {
        *(f32 *)(state + 0xFBC) = 5.0f;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o126/overlay_126/teleportEffectControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void teleportEffectDraw(Gfx **arg0, s32 *arg1, s32 *arg2, void *arg3) {
    Gfx *dl;
    s32 dlArg1;
    s32 dlArg2;
    Mtx mtx;
    s32 order[4];
    s32 swapped;
    s32 tmp;
    s32 k;
    s32 idx;
    s32 i;
    u32 v;
    u8 *state;
    u8 *ent;
    u8 *tbl;
    u8 *src;
    f32 f20;
    f32 fbc;
    s32 vpW;
    s32 vpH;

    dl = *arg0;
    dlArg1 = *arg1;
    dlArg2 = *arg2;
    state = *(u8 **)((u8 *)arg3 + 0x68);

    if (*(s16 *)(state + 0xFCA) < 0x164) {
        texDPTextureX(&dl, *(s32 *)*(u8 **)((u8 *)arg3 + 0x6C), 0x207, 0);
        f20 = *(f32 *)((u8 *)arg3 + 0x10);

        order[0] = 0;
        order[1] = 1;
        order[2] = 2;
        order[3] = 3;
        do {
            swapped = 0;
            for (k = 0; k < 3; k++) {
                if (*(f32 *)(state + 0xF9C + order[k + 1] * 4) < *(f32 *)(state + 0xF9C + order[k] * 4)) {
                    tmp = order[k];
                    order[k] = order[k + 1];
                    order[k + 1] = tmp;
                    swapped = 1;
                }
            }
        } while (swapped != 0);

        for (k = 0; k < 4; k++) {
            idx = order[k];
            ent = state + idx * 0x1E0 + state[0xFC8] * 0x780;
            if (state[0xF40 + idx] != 0) {
                *(s16 *)arg3 = *(s16 *)(state + 0xF10 + idx * 2);
                *(f32 *)((u8 *)arg3 + 0x10) = *(f32 *)(state + 0xF20 + idx * 4) + f20;
                mathTranslateMtx(&mtx, *(s32 *)((u8 *)arg3 + 0xC), *(f32 *)(state + 0xF20 + idx * 4),
                                 *(s32 *)((u8 *)arg3 + 0x14));
                matrixScale(*(f32 *)(state + 0xF9C + idx * 4), *(f32 *)(state + 0xF98),
                            *(f32 *)(state + 0xF9C + idx * 4), &mtx);
                matrixYaw(*(s16 *)(state + 0xF10 + idx * 2), &mtx);
                camPushFloatModelMtx(&dl, &dlArg1, &mtx);

                dl->words.w0 = 0xE7000000;
                dl->words.w1 = 0;
                dl++;
                dl->words.w0 = 0xFA000000;
                dl->words.w1 = state[0xF40 + idx] | ~0xFF;
                dl++;
                src = state + idx * 0x10;
                dl->words.w0 = 0xFB000000;
                dl->words.w1 = state[0xF40 + idx] | (src[0xF50] << 0x18) | (src[0xF51] << 0x10) | (src[0xF52] << 8);
                dl++;

                tbl = D_overlay_126_07E012A0;
                for (i = 0; i < 3; i++) {
                    v = (u32) ent + 0x80000000;
                    dl->words.w0 = (((v & 6) | 0x80) & 0xFF) << 0x10 | 0x040000A8;
                    dl->words.w1 = v;
                    dl++;
                    dl->words.w0 = 0x05F10100;
                    dl->words.w1 = (u32) tbl + 0x80000000;
                    dl++;
                    ent += 0xA0;
                    tbl += 0x100;
                }
            }
        }

        camRestoreModelMtx(&dl);
        *(f32 *)((u8 *)arg3 + 0x10) = f20;
        viGetCurrentSize(&vpW, &vpH);
        fbc = *(f32 *)(state + 0xFBC);
        if (!(D_overlay_126_07E01294 < fbc)) {
            frontDrawRectangle(&dl, 0, 0, vpW, vpH, (s32) ((fbc * 255.0f) / 10.0f) | ~0xFF);
        }
    }

    *arg0 = dl;
    *arg1 = dlArg1;
    *arg2 = dlArg2;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o126/overlay_126/teleportEffectDraw.s")
#endif
