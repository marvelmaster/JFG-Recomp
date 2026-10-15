#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
extern s32 D_overlay_137_089017F0;
extern s16 D_overlay_137_089019D8;
extern s32 D_overlay_137_089017F4;
extern u8 D_overlay_137_089017F8[];

void *camGetPtr(void);
s32 func_overlay_137_08901580_1FD68C0(void *arg0, void *arg1, f32 *arg2);
s32 trackPolyHeight(f32 x, f32 z, f32 *out, s32 flags);
s32 trackNearestIntersection(s32 a0, void *a1, f32 *pos, f32 *hit, s32 a4, s32 a5);

extern s32 D_overlay_137_08901750;
extern u8 D_overlay_137_08901754[];
extern u8 D_overlay_137_08901758[];
extern u8 D_overlay_137_08901770[];
extern u8 D_1000A0838;
extern u8 D_1000F2D58;
extern u8 D_1000F2E58;
extern u8 NullTextureOffsets[];

f32 (*camGetProjectionMtx(void))[4];
f32 camGetProjZ(f32 x, f32 y, f32 z);
void mathMtxF2L(f32 (*)[4], void *);
void mathMtxCatF(f32 (*)[4], f32 (*)[4], f32 (*)[4]);
void matrix_SCL_RPY_XYZ(ObjectTransform *, f32 (*)[4]);
void matrix_XYZ_YPR_SCL(ObjectTransform *, f32 (*)[4], s32); /* asm passes alt*4 as 3rd arg */
void matrixYaw(s16, f32 (*)[4]);
void *mainGetGameCharacter(s8, s8);
void texDPTextureX(Gfx **, void *, s32, s32);
void flamethrowerDraw(void *, void *, Gfx **, s32 *, s32 *);
void objPrintObject(Gfx **, s32 *, s32 *, void *);
void objDrawTracer(Gfx **, s32 *, void *, void *, f32 *, f32 *, f32, s32, s32, s32);
void camDoSpriteDirect(Gfx **, s32 *, s32 *, s32, s32, s32, s32, s32, f32, f32, s32, s32);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void realReflectSurfaces(void *arg0) {
    s32 i;
    s32 j;
    s32 cnt;
    s32 found;
    s16 tri;
    u8 *rec;
    u8 *ent;
    u8 *elem;

    D_overlay_137_089017F0 = 0;
    for (i = 0; i < *(s16 *)((u8 *)arg0 + 0x1A); i++) {
        rec = *(u8 **)((u8 *)arg0 + 0x4) + i * 0x48;
        for (j = 0; j < *(s16 *)(rec + 0x28); j++) {
            ent = *(u8 **)(rec + 0xC) + j * 0x10;
            if (*(u32 *)(ent + 0xC) & 0x20000000) {
                s32 k;

                found = 1;
                cnt = D_overlay_137_089017F0;
                elem = *(u8 **)(rec + 0x4) + *(s16 *)(ent + 0x8) * 0x10;
                tri = *(s16 *)(*(u8 **)rec + ((elem[1] + *(s16 *)(ent + 0x6)) * 0xA) + 2);
                for (k = 0; k < cnt; k++) {
                    if (tri == (&D_overlay_137_089019D8)[k]) {
                        found = 0;
                    }
                }
                if (found) {
                    (&D_overlay_137_089019D8)[cnt] = tri;
                    cnt += 1;
                    D_overlay_137_089017F0 = cnt;
                    if (cnt >= 0xF) {
                        return;
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o137/overlay_137/realReflectSurfaces.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void realReflectCreateList(s32 arg0, s32 arg1) {
    void *cam;
    s32 i;
    s32 hit;
    s32 cnt;
    f32 dist;
    void *obj;
    u8 *slot;

    cam = camGetPtr();
    D_overlay_137_089017F4 = 0;
    for (i = arg0 - 1; i >= 0; i--) {
        obj = *(void **)(arg1 + i * 4);
        hit = func_overlay_137_08901580_1FD68C0(obj, cam, &dist);
        *((u8 *)obj + 0x92) = (u8)(hit != 0);
        if (hit != 0) {
            cnt = D_overlay_137_089017F4;
            slot = D_overlay_137_089017F8 + cnt * 8;
            *(void **)slot = obj;
            *(f32 *)(slot + 4) = dist;
            D_overlay_137_089017F4 = cnt + 1;
            if (cnt + 1 >= 0x3C) {
                break;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o137/overlay_137/realReflectCreateList.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// ObjectTransform layout and the Gfx word pattern follow src/camera.c and font.c.
// Object fields without a header struct use raw offsets (obj + 0xNN).
void realReflectPrint(Gfx **arg0, s32 *arg1, s32 *arg2) {
    Gfx *gfx;
    ObjectTransform tr;
    ObjectTransform tr2;
    f32 mtxA[4][4];
    f32 mtxB[4][4];
    f32 mtxC[4][4];
    f32 trcA[3];
    f32 trcB[3];
    f32 (*projMtx)[4];
    u8 *rec;
    u8 *obj;
    u8 *model;
    u8 *ext;
    u8 **list;
    u8 *ent0;
    u8 *ent1;
    u8 *hdr0;
    u8 *hdr1;
    u8 *hdrP;
    u8 *part;
    u8 *tmd;
    u8 *tcomp;
    u8 *texSrc;
    u8 *sub4C;
    u8 *flame;
    u8 *dl28;
    u8 *vs1;
    u8 *vs2;
    u8 *vTmp;
    void *tex;
    f32 dist;
    f32 diff;
    f32 dy;
    f32 saveY;
    s32 i;
    s32 k;
    s32 count;
    s32 alt;
    s32 altOff;
    s32 hasSub;
    s32 drew;
    s32 needMtx;
    s32 idx;
    s32 type;
    s32 texIdx;
    u32 fp;
    u32 tfp;
    u32 texOfs;

    /* toggle the double-buffered matrix slot and load the projection matrix */
    D_overlay_137_08901750 ^= 1;
    projMtx = camGetProjectionMtx();
    mathMtxF2L(projMtx, D_overlay_137_08901770 + (D_overlay_137_08901750 << 6));

    gfx = *arg0;
    *arg0 = gfx + 1;
    gfx->words.w0 = 0xB7000000;
    gfx->words.w1 = 0x1000;

    needMtx = 0;
    count = D_overlay_137_089017F4;
    for (i = 0; i < count; i++) {
        rec = D_overlay_137_089017F8 + i * 8;
        obj = *(u8 **)rec;
        dist = *(f32 *)(rec + 4);
        diff = *(f32 *)(obj + 0x10) - dist;
        if (diff < 0.0f) {
            diff = -diff;
        }
        dy = dist - diff;

        if (!(*(s16 *)(obj + 0x6) & 0x400)) {
            model = *(u8 **)(obj + 0x40);

            if (*(s8 *)(model + 0x1E) == 0) {
                /* parts with a sub-object list */
                ext = *(u8 **)(obj + 0x68);
                idx = *(s8 *)(obj + 0x3A);
                list = *(u8 ***)(obj + 0x6C);
                ent0 = list[idx];
                hdr0 = *(u8 **)ent0;
                hasSub = 0;
                alt = 0;
                drew = 0;
                if (hdr0[0x11] != 0) {
                    hasSub = 1;
                }
                if (*(f32 *)(model + 0xCC) > 0.0f) {
                    if (*(f32 *)(model + 0xCC) < -camGetProjZ(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14))) {
                        alt = 1;
                    }
                }
                if (idx + alt >= *(s8 *)(model + 0x1F)) {
                    alt = 0;
                }
                altOff = alt * 4;
                ent1 = list[idx + alt];
                hdr1 = *(u8 **)ent1;
                if (*(u8 *)(obj + 0x39) == 0xFF) {
                    fp = *(u32 *)(hdr1 + 0x74);
                } else {
                    fp = *(u32 *)(hdr1 + 0x78);
                }

                if (*(s8 *)(hdr0 + 0x4E) == 0) {
                    tr.y_rotation = (s16)(*(s16 *)(obj + 0x0) + 0x8000);
                    tr.x_rotation = *(s16 *)(obj + 0x2);
                    tr.z_rotation = *(s16 *)(obj + 0x4);
                    tr.scale = -*(f32 *)(obj + 0x8);
                    tr.x_position = *(f32 *)(obj + 0xC);
                    tr.y_position = dy;
                    tr.z_position = *(f32 *)(obj + 0x14);
                    matrix_SCL_RPY_XYZ(&tr, mtxA);
                    if (*(s16 *)(obj + 0x48) == 0x99) {
                        matrixYaw(*(s16 *)(ext + 0x78), mtxA);
                    }
                    mathMtxCatF(mtxA, projMtx, mtxB);
                    mathMtxF2L(mtxB, (void *)(u32)*arg1);
                    gfx = *arg0;
                    *arg0 = gfx + 1;
                    gfx->words.w0 = 0x01010040;
                    gfx->words.w1 = (u32)*arg1 + 0x80000000;
                    *arg1 += 0x40;
                    drew = 1;
                } else if (*(s8 *)(ent0 + 0xA) == 0) {
                    tr2.y_rotation = (s16)-*(s16 *)(obj + 0x0);
                    tr2.x_rotation = (s16)-*(s16 *)(obj + 0x2);
                    tr2.z_rotation = (s16)-*(s16 *)(obj + 0x4);
                    tr2.scale = 1.0f;
                    tr2.x_position = -*(f32 *)(obj + 0xC);
                    tr2.y_position = -*(f32 *)(obj + 0x10);
                    tr2.z_position = -*(f32 *)(obj + 0x14);
                    needMtx = 1;
                    matrix_XYZ_YPR_SCL(&tr2, mtxC, altOff);
                    tr.y_rotation = (s16)(*(s16 *)(obj + 0x0) + 0x8000);
                    tr.x_rotation = *(s16 *)(obj + 0x2);
                    tr.z_rotation = *(s16 *)(obj + 0x4);
                    tr.scale = -1.0f;
                    tr.x_position = *(f32 *)(obj + 0xC);
                    tr.y_position = dy;
                    tr.z_position = *(f32 *)(obj + 0x14);
                    matrix_SCL_RPY_XYZ(&tr, mtxA);
                    mathMtxCatF(mtxC, mtxA, mtxB);
                    mathMtxCatF(mtxB, projMtx, mtxB);
                    mathMtxF2L(mtxB, (void *)(u32)*arg1);
                    gfx = *arg0;
                    *arg0 = gfx + 1;
                    gfx->words.w0 = 0x01000040;
                    gfx->words.w1 = (u32)*arg1 + 0x80000000;
                    *arg1 += 0x40;
                    drew = 1;
                }

                if (drew != 0) {
                    gfx = *arg0;
                    *arg0 = gfx + 1;
                    gfx->words.w0 = 0xFA000000;
                    gfx->words.w1 = (u32)*(u8 *)(obj + 0x39) | 0xFFFFFF00;

                    gfx = *arg0;
                    *arg0 = gfx + 1;
                    gfx->words.w0 = ((*(u32 *)(ent0 + *(s8 *)(ent0 + 0xB) * 4 + 0x10) + 0x80000000) & 0xFFFFFF) | 0xBF000000;
                    gfx->words.w1 = *(u32 *)(ent1 + 0x4) + 0x80000000;

                    if (hasSub != 0) {
                        gfx = *arg0;
                        *arg0 = gfx + 1;
                        gfx->words.w0 = 0x02000050;
                        if (altOff != 0) {
                            gfx->words.w1 = (u32)&D_1000A0838;
                        } else {
                            gfx->words.w1 = *(u32 *)(ent0 + *(s8 *)(ent0 + 0xB) * 4 + 0x78) + 0x80000000;
                        }
                    }

                    gfx = *arg0;
                    *arg0 = gfx + 1;
                    gfx->words.w0 = 0x06000000;
                    gfx->words.w1 = fp + 0x80000000;

                    gfx = *arg0;
                    *arg0 = gfx + 1;
                    gfx->words.w0 = 0xBF000000;
                    gfx->words.w1 = 0;

                    type = *(s16 *)(obj + 0x48);
                    if (type == 1 || type == 0x33) {
                        if (type == 1) {
                            texIdx = *(u8 *)((u8 *)mainGetGameCharacter(*(s8 *)ext, *(s8 *)(ext + 1)) + 0x70);
                            texSrc = ext + 0x78;
                        } else {
                            texSrc = ext;
                            texIdx = *(s32 *)(obj + 0x8C);
                        }

                        tcomp = *(u8 **)(obj + 0x60);
                        if (tcomp != NULL) {
                            tmd = *(u8 **)(tcomp + 0x4);
                            if (tmd != NULL) {
                                if (texIdx >= 9) {
                                    texIdx = 8;
                                }
                                part = (*(u8 ***)(tmd + 0x6C))[texIdx];
                                if (part != NULL) {
                                    texOfs = (u32)NullTextureOffsets;
                                    hdrP = *(u8 **)part;
                                    if (*(u8 *)(obj + 0x39) < 0xFF) {
                                        tfp = *(u32 *)(hdrP + 0x78);
                                    } else {
                                        tfp = *(u32 *)(hdrP + 0x74);
                                    }
                                    if (hdrP[0x11] != 0) {
                                        texOfs = *(u32 *)(part + *(s8 *)(part + 0xB) * 4 + 0x78);
                                    }
                                    mathMtxF2L(texSrc, (void *)(u32)*arg1);
                                    gfx = *arg0;
                                    *arg0 = gfx + 1;
                                    gfx->words.w0 = 0x01810040;
                                    gfx->words.w1 = (u32)*arg1 + 0x80000000;
                                    *arg1 += 0x40;

                                    gfx = *arg0;
                                    *arg0 = gfx + 1;
                                    gfx->words.w0 = ((*(u32 *)(part + *(s8 *)(part + 0xB) * 4 + 0x10) + 0x80000000) & 0xFFFFFF) | 0xBF000000;
                                    gfx->words.w1 = *(u32 *)(part + 0x4) + 0x80000000;

                                    gfx = *arg0;
                                    *arg0 = gfx + 1;
                                    gfx->words.w1 = texOfs + 0x80000000;
                                    gfx->words.w0 = 0x02000050;

                                    gfx = *arg0;
                                    *arg0 = gfx + 1;
                                    gfx->words.w0 = 0x06000000;
                                    gfx->words.w1 = tfp + 0x80000000;

                                    gfx = *arg0;
                                    *arg0 = gfx + 1;
                                    gfx->words.w1 = 0;
                                    gfx->words.w0 = 0xBF000000;
                                }
                            }
                        }

                        if (type == 1) {
                            flame = *(u8 **)(ext + 0x564);
                            if (flame != NULL && (((*(u32 *)(flame + 0x620)) << 6) >> 26) != 0) {
                                gfx = *arg0;
                                *arg0 = gfx + 1;
                                gfx->words.w0 = 0xBC00000A;
                                gfx->words.w1 = 0;
                                flamethrowerDraw(obj, *(void **)(ext + 0x564), arg0, arg1, arg2);
                            }
                        }
                    }

                    gfx = *arg0;
                    *arg0 = gfx + 1;
                    gfx->words.w0 = 0xBC00000A;
                    gfx->words.w1 = 0;
                    texDPInit(arg0);
                    gfx = *arg0;
                    *arg0 = gfx + 1;
                    gfx->words.w1 = -1;
                    gfx->words.w0 = 0xFA000000;
                }
            } else if (*(s8 *)(model + 0x1E) == 4) {
                /* type 4 parts */
                type = *(s16 *)(obj + 0x48);
                ext = *(u8 **)(obj + 0x68);
                if (type == 0x40) {
                    tr.y_rotation = (s16)(*(s16 *)(obj + 0x0) + 0x8000);
                    tr.x_rotation = *(s16 *)(obj + 0x2);
                    tr.z_rotation = *(s16 *)(obj + 0x4);
                    tr.scale = -*(f32 *)(obj + 0x8);
                    tr.x_position = *(f32 *)(obj + 0xC);
                    tr.y_position = dy;
                    tr.z_position = *(f32 *)(obj + 0x14);
                    matrix_SCL_RPY_XYZ(&tr, mtxA);
                    mathMtxCatF(mtxA, projMtx, mtxB);
                    mathMtxF2L(mtxB, (void *)(u32)*arg1);
                    gfx = *arg0;
                    *arg0 = gfx + 1;
                    gfx->words.w0 = 0x01010040;
                    gfx->words.w1 = (u32)*arg1 + 0x80000000;
                    *arg1 += 0x40;

                    gfx = *arg0;
                    *arg0 = gfx + 1;
                    gfx->words.w0 = 0xFA000000;
                    gfx->words.w1 = (u32)*(u8 *)(obj + 0x39) | 0xFFFFFF00;
                    gfx = *arg0;
                    *arg0 = gfx + 1;
                    gfx->words.w0 = 0xFB000000;
                    gfx->words.w1 = 0xFFFFFF00;
                    gfx = *arg0;
                    *arg0 = gfx + 1;
                    gfx->words.w0 = 0xBF000000;
                    gfx->words.w1 = 0;
                    gfx = *arg0;
                    *arg0 = gfx + 1;
                    gfx->words.w0 = 0x02000050;
                    gfx->words.w1 = (u32)&D_1000A0838;
                    gfx = *arg0;
                    *arg0 = gfx + 1;
                    gfx->words.w0 = 0x06000000;
                    if (*(u8 *)(obj + 0x39) == 0xFF) {
                        gfx->words.w1 = *(u32 *)(ext + 0xC) + 0x80000000;
                    } else {
                        gfx->words.w1 = *(u32 *)(ext + 0x10) + 0x80000000;
                    }
                    gfx = *arg0;
                    *arg0 = gfx + 1;
                    gfx->words.w0 = 0xBF000000;
                    gfx->words.w1 = 0;
                    gfx = *arg0;
                    *arg0 = gfx + 1;
                    gfx->words.w0 = 0xBC00000A;
                    gfx->words.w1 = 0;
                    texDPInit(arg0);
                    gfx = *arg0;
                    *arg0 = gfx + 1;
                    gfx->words.w1 = -1;
                    gfx->words.w0 = 0xFA000000;
                    gfx = *arg0;
                    *arg0 = gfx + 1;
                    gfx->words.w1 = 0xFFFFFF00;
                    gfx->words.w0 = 0xFB000000;
                } else if (type == 0xA2) {
                    list = *(u8 ***)(obj + 0x6C);
                    sub4C = *(u8 **)(obj + 0x4C);
                    if (*(u8 *)(ext + 0x63) != 0) {
                        trcB[0] = *(f32 *)(sub4C + 0xC);
                        trcB[1] = dist - (*(f32 *)(sub4C + 0x10) - dist);
                        trcB[2] = *(f32 *)(sub4C + 0x14);
                    } else {
                        trcB[0] = *(f32 *)(sub4C + 0x18);
                        trcB[1] = dist - (*(f32 *)(sub4C + 0x1C) - dist);
                        trcB[2] = *(f32 *)(sub4C + 0x20);
                    }
                    trcA[0] = *(f32 *)(obj + 0xC);
                    trcA[1] = dy;
                    trcA[2] = *(f32 *)(obj + 0x14);
                    objDrawTracer(arg0, arg2, list[*(s8 *)(obj + 0x3A)], ext, trcA, trcB,
                                  *(f32 *)(ext + 0x6C), -1, *(s32 *)(obj + 0x8C) | 0xFF, 0x200);
                } else if (type == 0x98) {
                    if (*(s16 *)(ext + 0xA78) != 0) {
                        tex = *(void **)(*(u8 **)(model + 0xAC));
                        tr.y_rotation = (s16)(*(s16 *)(obj + 0x0) + 0x8000);
                        tr.x_rotation = *(s16 *)(obj + 0x2);
                        tr.z_rotation = *(s16 *)(obj + 0x4);
                        tr.scale = -*(f32 *)(obj + 0x8);
                        tr.x_position = *(f32 *)(obj + 0xC);
                        tr.y_position = dy;
                        tr.z_position = *(f32 *)(obj + 0x14);
                        matrix_SCL_RPY_XYZ(&tr, mtxA);
                        mathMtxCatF(mtxA, projMtx, mtxB);
                        mathMtxF2L(mtxB, (void *)(u32)*arg1);
                        gfx = *arg0;
                        *arg0 = gfx + 1;
                        gfx->words.w0 = 0x01010040;
                        gfx->words.w1 = (u32)*arg1 + 0x80000000;
                        *arg1 += 0x40;
                        texDPTextureX(arg0, tex, 0x206, 0);
                        gfx = *arg0;
                        *arg0 = gfx + 1;
                        gfx->words.w0 = 0xFA000000;
                        gfx->words.w1 = 0xFFFFFFC0;
                        gfx = *arg0;
                        *arg0 = gfx + 1;
                        gfx->words.w0 = 0xFB000000;
                        gfx->words.w1 = *(u32 *)(D_overlay_137_08901754 + ext[0xA83] * 8);

                        vs1 = ext + 0x600;
                        vs2 = ext;
                        for (k = 0; k < 3; k++) {
                            gfx = *arg0;
                            *arg0 = gfx + 1;
                            gfx->words.w0 = 0x040000BC | ((((u32)vs1 + 0x80000000 & 6) | 0x90) & 0xFF) << 16;
                            gfx->words.w1 = (u32)vs1 + 0x80000000;

                            gfx = *arg0;
                            *arg0 = gfx + 1;
                            gfx->words.w0 = 0x05F10100;
                            gfx->words.w1 = (u32)vs2 + 0x80000000;

                            vs1 += 0xB4;
                            vTmp = vs1;
                            gfx = *arg0;
                            *arg0 = gfx + 1;
                            gfx->words.w0 = 0x040000BC | ((((u32)vTmp + 0x80000000 & 6) | 0x90) & 0xFF) << 16;
                            gfx->words.w1 = (u32)vTmp + 0x80000000;

                            vs2 += 0x100;
                            gfx = *arg0;
                            *arg0 = gfx + 1;
                            gfx->words.w0 = 0x05F10100;
                            gfx->words.w1 = (u32)vs2 + 0x80000000;
                            vs1 += 0xB4;
                            vs2 += 0x100;

                            if (k == 0) {
                                gfx = *arg0;
                                *arg0 = gfx + 1;
                                gfx->words.w0 = 0xE7000000;
                                gfx->words.w1 = 0;
                                gfx = *arg0;
                                *arg0 = gfx + 1;
                                gfx->words.w0 = 0xFB000000;
                                gfx->words.w1 = *(u32 *)(D_overlay_137_08901758 + ext[0xA83] * 8);
                            }
                        }

                        gfx = *arg0;
                        *arg0 = gfx + 1;
                        gfx->words.w0 = 0xBC00000A;
                        gfx->words.w1 = 0;
                        if (ext[0xA7F] != 0) {
                            if (needMtx != 0) {
                                gfx = *arg0;
                                *arg0 = gfx + 1;
                                gfx->words.w0 = 0x01000040;
                                gfx->words.w1 = (u32)(D_overlay_137_08901770 + (D_overlay_137_08901750 << 6)) + 0x80000000;
                                needMtx = 0;
                            }
                            camDoSpriteDirect(arg0, arg1, arg2,
                                              *(s32 *)(*(u8 **)(model + 0xAC) + 0x4),
                                              (s32)*(f32 *)(obj + 0xC), (s32)dy, (s32)*(f32 *)(obj + 0x14),
                                              *(s16 *)(ext + 0xA76), *(f32 *)(ext + 0xA54), 0.0f,
                                              0x20000006, 0xC0);
                        }
                        gfx = *arg0;
                        *arg0 = gfx + 1;
                        gfx->words.w0 = 0xFA000000;
                        gfx->words.w1 = 0xFFFFFFFF;
                        gfx = *arg0;
                        *arg0 = gfx + 1;
                        gfx->words.w0 = 0xFB000000;
                        gfx->words.w1 = 0xFFFFFF00;
                    }
                } else if (type == 0x28) {
                    if (*(s16 *)(obj + 0x2) == 0) {
                        tr.y_rotation = (s16)(*(s16 *)(obj + 0x0) + 0x8000);
                        tr.x_rotation = *(s16 *)(obj + 0x2);
                        tr.z_rotation = *(s16 *)(obj + 0x4);
                        tr.scale = -*(f32 *)(obj + 0x8);
                        tr.x_position = *(f32 *)(obj + 0xC);
                        tr.y_position = dy;
                        tr.z_position = *(f32 *)(obj + 0x14);
                        matrix_SCL_RPY_XYZ(&tr, mtxA);

                        if ((*(s16 *)(*(u8 **)(ext + 0x190) + 0x6) & 0x40) != 0) {
                            gfx = *arg0;
                            *arg0 = gfx + 1;
                            gfx->words.w0 = 0xFB000000;
                            gfx->words.w1 = ((u32)ext[0x1B4] << 24) | ((u32)ext[0x1B5] << 16) | ((u32)ext[0x1B6] << 8) | (*(u32 *)(ext + 0x1D0) & 0xFF);
                        } else {
                            gfx = *arg0;
                            *arg0 = gfx + 1;
                            gfx->words.w0 = 0xFB000000;
                            gfx->words.w1 = ((u32)ext[0x1B4] << 24) | ((u32)ext[0x1B5] << 16) | ((u32)ext[0x1B6] << 8) | 0xFF;
                        }
                        gfx = *arg0;
                        *arg0 = gfx + 1;
                        gfx->words.w0 = 0xFA000000;
                        gfx->words.w1 = ((u32)ext[0x1C4] << 24) | ((u32)ext[0x1C5] << 16) | ((u32)ext[0x1C6] << 8) | ((*(u16 *)(ext + 0x1D4) >> 8) & 0xFF);

                        mathMtxCatF(mtxA, projMtx, mtxB);
                        mathMtxF2L(mtxB, (void *)(u32)*arg1);
                        gfx = *arg0;
                        *arg0 = gfx + 1;
                        gfx->words.w0 = 0x01010040;
                        gfx->words.w1 = (u32)*arg1 + 0x80000000;
                        *arg1 += 0x40;

                        texDPTextureX(arg0, *(void **)(ext + 0x190), 0x20E, *(s32 *)(ext + 0x1D0) << 8);

                        dl28 = ext + ext[0x1DA] * 0x14 * 0xA;
                        gfx = *arg0;
                        *arg0 = gfx + 1;
                        gfx->words.w0 = 0x040000D0 | ((((u32)dl28 + 0x80000000 & 6) | 0xA0) & 0xFF) << 16;
                        gfx->words.w1 = (u32)dl28 + 0x80000000;

                        gfx = *arg0;
                        *arg0 = gfx + 1;
                        gfx->words.w0 = 0x05F10100;
                        gfx->words.w1 = (u32)&D_1000F2D58;
                        gfx = *arg0;
                        *arg0 = gfx + 1;
                        gfx->words.w0 = 0x05310040;
                        gfx->words.w1 = (u32)&D_1000F2E58;
                        gfx = *arg0;
                        *arg0 = gfx + 1;
                        gfx->words.w0 = 0xBC00000A;
                        gfx->words.w1 = 0;
                        texDPInit(arg0);
                        gfx = *arg0;
                        *arg0 = gfx + 1;
                        gfx->words.w0 = 0xFB000000;
                        gfx->words.w1 = -1;
                        gfx = *arg0;
                        *arg0 = gfx + 1;
                        gfx->words.w0 = 0xFA000000;
                        gfx->words.w1 = -1;
                    }
                }
            } else if (*(s8 *)(model + 0x1E) == 1) {
                /* object printed directly with its Y set to the reflection plane */
                if (needMtx != 0) {
                    gfx = *arg0;
                    *arg0 = gfx + 1;
                    gfx->words.w0 = 0x01000040;
                    gfx->words.w1 = (u32)(D_overlay_137_08901770 + (D_overlay_137_08901750 << 6)) + 0x80000000;
                    needMtx = 0;
                }
                saveY = *(f32 *)(obj + 0x10);
                *(f32 *)(obj + 0x10) = dy;
                *(f32 *)(obj + 0x8) = -*(f32 *)(obj + 0x8);
                objPrintObject(arg0, arg1, arg2, obj);
                *(f32 *)(obj + 0x10) = saveY;
            }
        }
    }

    gfx = *arg0;
    *arg0 = gfx + 1;
    gfx->words.w0 = 0xB6000000;
    gfx->words.w1 = 0x1000;
    if (needMtx != 0) {
        gfx = *arg0;
        *arg0 = gfx + 1;
        gfx->words.w0 = 0x01000040;
        gfx->words.w1 = (u32)(D_overlay_137_08901770 + (D_overlay_137_08901750 << 6)) + 0x80000000;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o137/overlay_137/realReflectPrint.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_overlay_137_08901580_1FD68C0(void *arg0, void *arg1, f32 *arg2) {
    u8 *obj = (u8 *)arg0;
    u8 **list;
    u8 *model;
    f32 f20;
    f32 pos[3];
    f32 hit[3];
    s32 fp;
    s32 count;
    s32 k;

    model = *(u8 **)(obj + 0x40);
    if (*(s8 *)(model + 0x1E) == 0) {
        list = *(u8 ***)(obj + 0x6C);
        f20 = (f32)*(s16 *)(list[*(s8 *)(obj + 0x3A)] + 0x94) * *(f32 *)(obj + 0x8);
    } else {
        f20 = 0.0f;
    }

    fp = 0;
    if ((trackPolyHeight(*(f32 *)(obj + 0xC), *(f32 *)(obj + 0x14), arg2, 0x20000000) & 0x20000000)
        && ((*arg2 - 5.0f) < *(f32 *)(obj + 0x10))) {
        fp = 1;
        return fp;
    }

    pos[0] = *(f32 *)(obj + 0xC);
    pos[2] = *(f32 *)(obj + 0x14);
    count = D_overlay_137_089017F0;
    for (k = 0; k < count; k++) {
        f32 base = (f32)(&D_overlay_137_089019D8)[k];

        pos[1] = (base - (*(f32 *)(obj + 0x10) - base)) - f20;
        if (trackNearestIntersection(0, (u8 *)arg1 + 0xC, pos, hit, 0, 0x20000000) != 0) {
            fp = 1;
            *arg2 = hit[2]; /* asm: stores the third hit component */
            break;
        }
    }
    return fp;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o137/overlay_137/func_overlay_137_08901580_1FD68C0.s")
#endif
