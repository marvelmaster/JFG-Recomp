#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
#define CAMLIGHT_COUNT 0x31
#define CAMLIGHT_MAX   0x32

typedef struct CamLight {
    s16 rot[3];      /* 0x00 */
    u8 type;         /* 0x06 bit flags: 0x01/0x02/0x04 sprite & flare, 0x20 follows object, 0x40 blocks, 0x80 directional */
    s8 intensity;    /* 0x07 0..0x10 */
    f32 scale;       /* 0x08 */
    f32 pos[3];      /* 0x0C world position */
    void *parent;    /* 0x18 */
    f32 offs[3];     /* 0x1C local offset */
    f32 dir[3];      /* 0x28 direction */
    s8 vtxIdx;       /* 0x34 */
    u8 hasOffs;      /* 0x35 */
    u8 dirty;        /* 0x36 */
    s8 zbIdx;        /* 0x37 */
    u8 col[4];       /* 0x38 r,g,b,alpha */
    s32 spr;         /* 0x3C sprite handle */
    f32 radius;      /* 0x40 */
    f32 invRadius;   /* 0x44 */
    f32 range;       /* 0x48 */
    f32 invRange;    /* 0x4C */
} CamLight;

extern CamLight D_800F5B60_B1760[CAMLIGHT_COUNT];
extern s32 D_800A1108_A1D08;   /* active light count */
extern s32 D_800A110C_A1D0C;   /* visibility scan cursor */
extern s32 D_800A1110_A1D10;   /* shared sprite handle */
extern s32 D_800A1020_A1C20[];
extern s32 D_800A1048_A1C48[];
extern s32 D_800A1088_A1C88[];
extern Gfx *D_800F5B50_B1750;
extern void *D_800F5B54_B1754;
extern void *D_800F5B58_B1758;

void *camGetPtr(void);
void *camGetInvProjMtx(void);
void camDoSprite(void **arg0, void **arg1, void **arg2, void *arg3, s32 arg4, s32 arg5, u8 arg6);
s32 texLoadSprite(s32 spriteId, s32 arg1, void *owner, void *src);
void texFreeSprite(s32 handle, void *owner);
void mathOneFloatPY(void *obj, f32 *out, ...);
s32 camProjectPoint(f32 x, f32 y, f32 z, f32 *sx, f32 *sy, s32 flag);
s8 mainAddZBCheck(s32 x, s32 y, s32 z);
s32 mainGetZBCheck(s8 idx);
s32 trackNearestIntersection(s32 a, void *from, void *to, void *out, s32 mask, s32 c);
void sprSetIA2ColOverride(u8 r, u8 g, u8 b, u8 a0, u8 a1, u8 a2);
void sprClearIA2ColOverride(void);
void viGetCurrentSize(s32 *w, s32 *h);
void texDPInit(Gfx **dl);
void func_80024340(s32 count, void *entries, u8 *outR, u8 *outG, u8 *outB, u8 *outA);
void func_80024440(void *list, f32 scale, f32 x, f32 y, f32 z, f32 dx, f32 dy, f32 dz, f32 alpha, f32 size);
void camlightDelete(void *arg0);
void camlightUpdate(CamLight *cl);
void func_80023FB4(void *cam, CamLight *cl);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camlightInit(void) {
    CamLight *cl = D_800F5B60_B1760;
    s32 i = CAMLIGHT_COUNT;

    do {
        cl->type = 0;
        cl->spr = 0;
        cl++;
    } while (i--);
    D_800A110C_A1D0C = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camlight/camlightInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 camlightFlush(void) {
    CamLight *cl = D_800F5B60_B1760;
    s32 i = CAMLIGHT_COUNT;
    s32 last;

    do {
        camlightDelete(cl);
        last = i;
        cl++;
    } while (i--);
    return last;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camlight/camlightFlush.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
CamLight *camlightAdd(s32 arg0, void *arg1) {
    u8 *src = arg1;
    CamLight *cl;
    CamLight *next;
    f32 scale;
    s16 spriteId;

    if (D_800A1108_A1D08 >= CAMLIGHT_MAX) {
        return NULL;
    }
    cl = D_800F5B60_B1760;
    if (cl->type != 0) {
        do {
            next = cl + 1;
            cl = next;
        } while (next->type != 0);
    }
    D_800A1108_A1D08 += 1;

    cl->rot[0] = *(s16 *)(src + 0x2);
    cl->rot[1] = *(s16 *)(src + 0x4);
    cl->rot[2] = *(s16 *)(src + 0x6);
    cl->type = src[0x0];
    cl->intensity = (src[0x1F] == 0) ? 0 : 0x10;
    scale = (f32) (u8) src[0x1];
    cl->parent = (void *) arg0;
    cl->scale = scale * 0.05f;
    cl->offs[0] = *(f32 *)(src + 0x8);
    cl->offs[1] = *(f32 *)(src + 0xC);
    cl->offs[2] = *(f32 *)(src + 0x10);
    cl->hasOffs = 0;
    if (arg0 != 0 && (cl->offs[0] != 0.0f || cl->offs[1] != 0.0f || cl->offs[2] != 0.0f)) {
        cl->hasOffs = 1;
    }
    cl->vtxIdx = *(s8 *)(src + 0x1E);
    cl->dirty = 3;
    cl->zbIdx = -1;

    camlightUpdate(cl);

    cl->col[0] = src[0x14];
    cl->col[1] = src[0x15];
    cl->col[2] = src[0x16];
    cl->col[3] = src[0x17];
    spriteId = *(s16 *)(src + 0x18);
    if (spriteId >= 0) {
        cl->spr = texLoadSprite(spriteId, 0, cl, arg1);
    } else {
        cl->spr = 0;
    }
    cl->radius = (f32) *(s16 *)(src + 0x1A);
    cl->invRadius = 1.0f / cl->radius;
    cl->range = (f32) *(s16 *)(src + 0x1C);
    cl->invRange = 1.0f / cl->range;
    if (D_800A1108_A1D08 == 1) {
        D_800A1110_A1D10 = texLoadSprite(0x49, 0, cl, arg1);
    }
    return cl;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camlight/camlightAdd.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camlightDelete(void *arg0) {
    CamLight *cl = arg0;
    s32 handle;
    s32 remaining;
    if (cl == NULL) {
        return;
    }
    if (cl->type == 0) {
        return;
    }
    cl->type = 0;
    handle = cl->spr;
    if (handle != 0) {
        texFreeSprite(handle, cl);
        cl->spr = 0;
    }
    remaining = D_800A1108_A1D08 - 1;
    D_800A1108_A1D08 = remaining;
    if (remaining == 0) {
        if (D_800A1110_A1D10 != 0) {
            texFreeSprite(D_800A1110_A1D10, cl);
            D_800A1110_A1D10 = 0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camlight/camlightDelete.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camlightUpdateAll(void) {
    CamLight *cl;
    s32 i;

    if (D_800A1108_A1D08 > 0) {
        cl = D_800F5B60_B1760;
        i = CAMLIGHT_COUNT;
        do {
            if (cl->type != 0) {
                camlightUpdate(cl);
            }
            cl++;
        } while (i--);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camlight/camlightUpdateAll.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camlightUpdate(CamLight *cl) {
    u8 *parent;
    u8 *inst;
    s32 doDir;
    s16 pidx;

    if (cl == NULL) {
        return;
    }
    parent = cl->parent;
    doDir = cl->dirty & 2;
    if ((cl->dirty & 1) || parent != NULL) {
        if (parent == NULL) {
            cl->pos[0] = cl->offs[0];
            cl->pos[1] = cl->offs[1];
            cl->pos[2] = cl->offs[2];
        } else if (cl->vtxIdx >= 0) {
            pidx = *(s8 *)(parent + 0x3A);
            inst = *(u8 **)(*(u8 **)(parent + 0x6C) + pidx * 4);
            if (inst != NULL && *(u8 **)inst != NULL &&
                cl->vtxIdx < (s32) (*(u8 **)inst)[0x2D]) {
                f32 *v = (f32 *) (*(u8 **)(inst + 0x68) + cl->vtxIdx * 0xC);
                cl->pos[0] = v[0];
                cl->pos[1] = v[1];
                cl->pos[2] = v[2];
            }
        } else if (cl->hasOffs) {
            pointListRPY(1, (s16 *) parent, (s32 *) cl->offs, cl->pos);
            cl->pos[0] += *(f32 *) (parent + 0x0C);
            cl->pos[1] += *(f32 *) (parent + 0x10);
            cl->pos[2] += *(f32 *) (parent + 0x14);
        } else {
            cl->pos[0] = *(f32 *) (parent + 0x0C);
            cl->pos[1] = *(f32 *) (parent + 0x10);
            cl->pos[2] = *(f32 *) (parent + 0x14);
        }
        doDir = cl->dirty & 2;
    }
    if (doDir != 0 || parent != NULL) {
        cl->dir[2] = -1.0f;
        mathOneFloatPY(cl, cl->dir, cl->dir);
        if (parent != NULL) {
            pointListRPY(1, (s16 *) parent, (s32 *) cl->dir, cl->dir);
        }
        cl->dir[0] = -cl->dir[0];
        cl->dir[1] = -cl->dir[1];
        cl->dir[2] = -cl->dir[2];
    }
    cl->dirty = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camlight/camlightUpdate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80023FB4(void *cam, CamLight *cl) {
    s32 pad[10];
    s32 out;

    if (trackNearestIntersection(0, (u8 *) cam + 0xC, (u8 *) cl + 0xC, &out, 0x2404, 0) == 0) {
        cl->intensity = (s8) (cl->intensity + 5);
        if (cl->intensity >= 0x11) {
            cl->intensity = 0x10;
        }
    } else {
        cl->intensity = (s8) (cl->intensity - 5);
        if (cl->intensity < 0) {
            cl->intensity = 0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camlight/func_80023FB4.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camlightVisibilityCheck(void) {
    void *cam;
    CamLight *cl;
    s32 budget;
    s32 cursor;
    s32 newCursor = 0;
    f32 vec[3];
    f32 sx;
    f32 sy;
    f32 dx;
    f32 dy;
    f32 dz;
    f32 r2;
    u8 t;

    if (D_800A1108_A1D08 > 0) {
        cam = camGetPtr();
        budget = 4;
        cursor = D_800A110C_A1D0C;
        do {
            cl = &D_800F5B60_B1760[cursor];
            cursor += 1;
            if (cursor >= CAMLIGHT_MAX) {
                cursor = 0;
            }
            t = cl->type;
            if (t & 0x20) {
                if (mainGetZBCheck(cl->zbIdx) == 0) {
                    cl->intensity = (s8) (cl->intensity + 8);
                    if (cl->intensity >= 0x11) {
                        cl->intensity = 0x10;
                    }
                } else {
                    cl->intensity = (s8) (cl->intensity - 8);
                    if (cl->intensity < 0) {
                        cl->intensity = 0;
                    }
                }
                vec[2] = 256.0f;
                mathOneFloatPY(cl, vec);
                vec[0] += *(f32 *) ((u8 *) cam + 0x0C);
                vec[1] += *(f32 *) ((u8 *) cam + 0x10);
                vec[2] += *(f32 *) ((u8 *) cam + 0x14);
                if (camProjectPoint(vec[0], vec[1], vec[2], &sx, &sy, 1) != 0) {
                    cl->zbIdx = mainAddZBCheck((s32) sx, (s32) sy, 3);
                } else {
                    cl->zbIdx = -1;
                }
            } else if (t != 0) {
                dx = cl->pos[0] - *(f32 *) ((u8 *) cam + 0x0C);
                dy = cl->pos[1] - *(f32 *) ((u8 *) cam + 0x10);
                dz = cl->pos[2] - *(f32 *) ((u8 *) cam + 0x14);
                r2 = (dx * dx) + (dy * dy) + (dz * dz);
                if (r2 < cl->radius * cl->radius) {
                    if (t & 0x40) {
                        if (budget != 0) {
                            func_80023FB4(cam, cl);
                            budget -= 1;
                            if (budget == 0) {
                                newCursor = cursor;
                            }
                        }
                    } else {
                        cl->intensity = 0x10;
                    }
                } else {
                    cl->intensity = 0;
                }
            }
        } while (cursor != D_800A110C_A1D0C);
        if (budget == 0) {
            D_800A110C_A1D0C = newCursor;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camlight/camlightVisibilityCheck.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80024340(s32 count, void *entries, u8 *outR, u8 *outG, u8 *outB, u8 *outA) {
    s32 n = count;
    u8 *e = entries;
    s32 bestR = 0;
    s32 bestG = 0;
    s32 bestB = 0;
    s32 bestA = 0;
    u8 valR = 0;
    u8 valG = 0;
    u8 valB = 0;
    s32 prod;

    while (n--) {
        u8 a = e[3];

        prod = e[0] * a;
        if (bestR < prod) {
            bestR = prod;
            valR = e[0];
        }
        prod = e[1] * a;
        if (bestG < prod) {
            bestG = prod;
            valG = e[1];
        }
        prod = e[2] * a;
        if (bestB < prod) {
            bestB = prod;
            valB = e[2];
        }
        if (bestA < a) {
            bestA = a;
        }
        e += 4;
    }
    *outR = valR;
    *outG = valG;
    *outB = valB;
    *outA = bestA;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camlight/func_80024340.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80024440(void *list, f32 scale, f32 x, f32 y, f32 z, f32 dx, f32 dy, f32 dz, f32 alpha, f32 size) {
    u8 *e = list;
    s16 rot[3];
    f32 wx;
    f32 wy;
    f32 wz;
    f32 sc;
    f32 next;
    u32 *gfx;

    rot[0] = 0;
    rot[1] = 0;
    rot[2] = 0;
    if (e == NULL) {
        return;
    }
    if (*(f32 *) (e + 0x4) == 0.0f) {
        return;
    }
    do {
        wx = (*(f32 *) e * dx) + x;
        wy = (*(f32 *) e * dy) + y;
        wz = (*(f32 *) e * dz) + z;
        sc = *(f32 *) (e + 0x4) * size;
        gfx = (u32 *) D_800F5B50_B1750;
        D_800F5B50_B1750 = (Gfx *) (gfx + 2);
        gfx[0] = 0xFA000000;
        gfx[1] = ((u32) e[0x9] << 24) | ((u32) e[0xA] << 16) | ((u32) e[0xB] << 8) |
                 ((s32) (*(f32 *) (e + 0xC) * alpha) & 0xFF);
        camDoSprite((void **) &D_800F5B50_B1750, (void **) &D_800F5B54_B1754,
                    (void **) &D_800F5B58_B1758, rot, D_800A1110_A1D10, 4, 0);
        next = *(f32 *) (e + 0x14);
        e += 0x10;
    } while (next != 0.0f);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camlight/func_80024440.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void camlightDraw(void **dl, void **a1, void **a2) {
    s32 entryCount;
    s32 vpW;
    s32 vpH;
    u8 maxR;
    u8 maxG;
    u8 maxB;
    u8 maxA;
    u8 colBuf[0x31 * 4];
    s32 colCount = 0;
    f32 viewDir[3];
    f32 lpos[3];
    f32 ldir[3];
    f32 refl[3];
    f32 dist = 0.0f;
    f32 dot;
    f32 fade;
    f32 atten;
    f32 flare;
    f32 radial;
    f32 sprScale;
    void *cam;
    f32 *inv;
    CamLight *cl;
    s32 i;
    s32 rgb;
    s16 rot[3];
    void *flareTex;

    if (D_800A1108_A1D08 <= 0) {
        return;
    }
    D_800F5B50_B1750 = *dl;
    D_800F5B54_B1754 = *a1;
    D_800F5B58_B1758 = *a2;
    cam = camGetPtr();
    inv = (f32 *) camGetInvProjMtx();
    viewDir[0] = -*(f32 *) ((u8 *) inv + 0x20);
    viewDir[1] = -*(f32 *) ((u8 *) inv + 0x24);
    viewDir[2] = -*(f32 *) ((u8 *) inv + 0x28);

    cl = D_800F5B60_B1760;
    for (i = 0; i < CAMLIGHT_COUNT; i++, cl++) {
        if (cl->type == 0 || cl->intensity <= 0 || (s32) cl->col[3] <= 0) {
            continue;
        }
        if (cl->type & 0x20) {
            f32 tmp[3];

            tmp[2] = -1.0f;
            mathOneFloatPY(cl, tmp);
            ldir[0] = -tmp[0];
            ldir[1] = -tmp[1];
            ldir[2] = -tmp[2];
            lpos[0] = (tmp[0] * -256.0f) + *(f32 *) ((u8 *) cam + 0x0C);
            lpos[1] = (tmp[1] * -256.0f) + *(f32 *) ((u8 *) cam + 0x10);
            lpos[2] = (tmp[2] * -256.0f) + *(f32 *) ((u8 *) cam + 0x14);
            atten = 1.0f;
        } else {
            f32 vx = cl->pos[0] - *(f32 *) ((u8 *) cam + 0x0C);
            f32 vy = cl->pos[1] - *(f32 *) ((u8 *) cam + 0x10);
            f32 vz = cl->pos[2] - *(f32 *) ((u8 *) cam + 0x14);
            f32 len2 = (vx * vx) + (vy * vy) + (vz * vz);
            f32 inv_len = 1.0f;

            lpos[0] = cl->pos[0];
            lpos[1] = cl->pos[1];
            lpos[2] = cl->pos[2];
            dist = len2;
            if (len2 > 0.0f) {
                dist = sqrtf(len2);
                inv_len = 1.0f / dist;
            }
            ldir[0] = vx * inv_len;
            ldir[1] = vy * inv_len;
            ldir[2] = vz * inv_len;
            atten = 1.0f;
            if (cl->type & 0x80) {
                atten = (cl->dir[0] * ldir[0]) + (cl->dir[1] * ldir[1]) + (cl->dir[2] * ldir[2]);
            }
        }
        dot = (viewDir[0] * ldir[0]) + (viewDir[1] * ldir[1]) + (viewDir[2] * ldir[2]);
        fade = atten * dot;
        if (fade > 0.7071f) {
            f32 spot = fade * ((fade - 0.7071f) * 3.4141345f);
            f32 t;
            u8 *c;

            sprScale = (f32) cl->intensity * 0.0625f;
            if (dist < cl->range) {
                t = cl->invRange * dist;
                if (t < 0.5f) {
                    radial = spot;
                } else {
                    radial = 2.0f * ((1.0f - t) * spot);
                }
                c = &colBuf[colCount * 4];
                c[0] = cl->col[0];
                c[1] = cl->col[1];
                c[2] = cl->col[2];
                c[3] = (u8) (s32) ((f32) cl->col[3] * radial);
                colCount += 1;
            }
            if (!(cl->type & 0x20)) {
                t = dist * cl->invRadius;
                if (t > 0.5f) {
                    radial = 2.0f * (1.0f - t);
                } else {
                    radial = 1.0f;
                }
            } else {
                radial = 1.0f;
            }
            if (cl->spr != 0) {
                sprSetIA2ColOverride(0xFF, 0xFF, 0xFF, cl->col[0], cl->col[1], cl->col[2]);
                camDoSprite((void **) &D_800F5B50_B1750, (void **) &D_800F5B54_B1754,
                            (void **) &D_800F5B58_B1758, &rot[0], cl->spr, 0x204,
                            (s32) (255.0f * spot * radial));
                sprClearIA2ColOverride();
            }
            if (cl->type & 0x4) {
                flareTex = D_800A1088_A1C88;
            } else if (cl->type & 0x2) {
                flareTex = D_800A1048_A1C48;
            } else {
                flareTex = NULL;
            }
            if (spot > 0.7795f && flareTex != NULL) {
                flare = (spot - 0.7795f) * 4.535147f;
                radial = spot * spot;
                refl[0] = (fade * 2.0f * viewDir[0]) - ldir[0];
                refl[1] = (fade * 2.0f * viewDir[1]) - ldir[1];
                refl[2] = (fade * 2.0f * viewDir[2]) - ldir[2];
                func_80024440(flareTex, flare, lpos[0], lpos[1], lpos[2],
                              refl[0], refl[1], refl[2], radial, flare * flare * sprScale * radial);
            }
        }
    }
    if (colCount > 0) {
        s32 w;
        s32 h;
        Gfx *g;

        viGetCurrentSize(&vpW, &vpH);
        func_80024340(colCount, colBuf, &maxR, &maxG, &maxB, &maxA);
        g = D_800F5B50_B1750;
        D_800F5B50_B1750 = g + 1;
        g->words.w0 = 0x06000000;
        g->words.w1 = (u32) D_800A1020_A1C20;
        g = D_800F5B50_B1750;
        D_800F5B50_B1750 = g + 1;
        g->words.w0 = 0xFA000000;
        g->words.w1 = ((u32) maxR << 24) | ((u32) maxG << 16) | ((u32) maxB << 8) | maxA;
        g = D_800F5B50_B1750;
        D_800F5B50_B1750 = g + 1;
        w = vpW;
        h = vpH;
        g->words.w0 = ((w & 0x3FF) << 14) | 0xF6000000 | ((h & 0x3FF) * 4);
        g->words.w1 = 0;
        g = D_800F5B50_B1750;
        D_800F5B50_B1750 = g + 1;
        g->words.w1 = 0;
        g->words.w0 = 0xE7000000;
    }
    texDPInit(&D_800F5B50_B1750);
    *dl = D_800F5B50_B1750;
    *a1 = D_800F5B54_B1754;
    *a2 = D_800F5B58_B1758;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/camlight/camlightDraw.s")
#endif
