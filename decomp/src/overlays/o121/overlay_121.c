#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
typedef struct ShardParticle {
    /* 0x00 */ s32 x;        /* 16.16 fixed point */
    /* 0x04 */ s32 y;
    /* 0x08 */ s32 z;
    /* 0x0C */ s32 vx;
    /* 0x10 */ s32 vy;       /* 0x7530 (gravity) is subtracted every tick */
    /* 0x14 */ s32 vz;
    /* 0x18 */ s16 cornerX[3];
    /* 0x1E */ s16 cornerY[3];
    /* 0x24 */ s16 cornerZ[3];
    /* 0x2A */ u8 pad2A[2];
} ShardParticle; /* Size: 0x2C bytes per shard */

typedef struct ShardCluster {
    /* 0x00 */ ShardParticle *shards;
    /* 0x04 */ s16 *vtx;          /* 0x1E bytes per shard (3 vertices of 0xA bytes) */
    /* 0x08 */ void *unk8;        /* 0x10 bytes per shard */
    /* 0x0C */ void *unkC;        /* written by func_overlay_121_079004D0_1FC72D8 */
    /* 0x10 */ void *setup;       /* arg1->unk10 */
    /* 0x14 */ s32 floorY;        /* 16.16 fixed point */
    /* 0x18 */ u16 count;
    /* 0x1A */ s16 timer;
    /* 0x1C */ u8 pad1C[4];
    /* 0x20 */ f32 centerX;
    /* 0x24 */ f32 centerY;
    /* 0x28 */ f32 centerZ;
} ShardCluster;

void func_overlay_121_079004D0_1FC72D8(void *a0, void *a1, void *a2, s32 a3, s32 a4, s32 a5, s32 a6);
s32 objFreeObject(void *obj);
void *modGetMakeBuffer(s32 *arg0);
s32 modelGetModelFlags(void);
void texDPTextureX(Gfx **dlist, void *tex, s32 rtile, s32 tmem);
extern f32 D_overlay_121_07901030;
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
/* asm: mmAlloc2 is declared void in memory.h but the asm uses its return value */
static void *shardAlloc(s32 size) {
    return ((void *(*)(s32, u32))mmAlloc2)(size, 0xFF0000FFU);
}

s32 shardClusterInit(void *arg0, void *arg1) {
    ShardCluster *cl;
    u8 *setup;
    void **list;
    u8 *rec;
    u8 *ent;
    s32 count;
    s32 i;
    s32 sumX;
    s32 sumY;
    s32 sumZ;
    ShardParticle *first;

    cl = *(ShardCluster **)((u8 *)arg0 + 0x68);
    setup = *(u8 **)((u8 *)arg1 + 0x10);
    list = *(void ***)(setup + 0x6C);
    rec = *(u8 **)list[*(s8 *)(setup + 0x3A)];
    count = *(s16 *)(rec + 0x16);
    ent = *(u8 **)(rec + 0x24);

    cl->shards = NULL;
    cl->vtx = NULL;
    cl->unk8 = NULL;
    cl->unkC = NULL;
    cl->setup = *(void **)((u8 *)arg1 + 0x10);
    cl->floorY = (s32)(*(f32 *)((u8 *)arg1 + 0xC) * 65536.0f);
    cl->count = 0;
    cl->timer = 0xC8;

    for (i = 0; i < count; i++, ent += 0x10) {
        s32 h = *(s8 *)(ent + 1);

        if (h < *(u8 *)((u8 *)arg1 + 0xA)) {
            continue;
        }
        if (*(u8 *)((u8 *)arg1 + 0xB) < h) {
            continue;
        }
        if (*(u32 *)(ent + 0xC) & 0x400) {
            continue;
        }
        cl->count = (u16)(cl->count + *(s16 *)(ent + 0x18) - *(s16 *)(ent + 0x8));
    }

    cl->shards = (ShardParticle *)shardAlloc(cl->count * 0x2C);
    if (cl->shards != NULL) {
        cl->vtx = (s16 *)shardAlloc(cl->count * 0x1E);
        if (cl->vtx != NULL) {
            cl->unk8 = shardAlloc(cl->count * 0x10);
            if (cl->unk8 != NULL) {
                func_overlay_121_079004D0_1FC72D8((u8 *)cl + 0xC, arg0, *(void **)((u8 *)arg1 + 0x10), 6, 0,
                                                  *(u8 *)((u8 *)arg1 + 0xA), *(u8 *)((u8 *)arg1 + 0xB));
                if (cl->unkC != NULL) {
                    /* asm: the shard pointer is never advanced in this loop, so the
                     * first shard's position is summed count times and then divided by count */
                    first = cl->shards;
                    sumX = 0;
                    sumY = 0;
                    sumZ = 0;
                    for (i = 0; i < cl->count; i++) {
                        sumX += first->x;
                        sumY += first->y;
                        sumZ += first->z;
                    }
                    cl->centerX = (f32)sumX / (f32)cl->count;
                    cl->centerY = (f32)sumY / (f32)cl->count;
                    cl->centerZ = (f32)sumZ / (f32)cl->count;
                    return 0;
                }
            }
        }
    }
    return objFreeObject(arg0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o121/overlay_121/shardClusterInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void shardClusterControl(void *arg0, s32 arg1) {
    ShardCluster *cl = *(ShardCluster **)((u8 *)arg0 + 0x68);
    ShardParticle *sh = cl->shards;
    s16 *out = cl->vtx;
    s32 i;
    s32 k;
    s32 vyNew;
    s32 yNew;
    s32 zNew;
    s32 bounce;

    for (i = 0; i < cl->count; i++) {
        vyNew = sh->vy - 0x7530;
        sh->x = sh->x + sh->vx;
        yNew = sh->y + vyNew;
        zNew = sh->z + sh->vz;
        sh->y = yNew;
        sh->z = zNew;
        sh->vy = vyNew;

        if (yNew < cl->floorY) {
            sh->y = cl->floorY;
            bounce = -(vyNew >> 1);
            sh->vy = bounce;
            if (bounce == 0 || (((u32)sh->x + (u32)zNew) & 1) != 0) {
                sh->vx = 0;
                sh->vy = 0;
                sh->vz = 0;
            }
        }

        for (k = 0; k < 3; k++) {
            s32 idx = 2 - k;

            out[0] = (s16)(sh->cornerX[idx] + (sh->x >> 16));
            out[1] = (s16)(sh->cornerY[idx] + (sh->y >> 16));
            out[2] = (s16)(sh->cornerZ[idx] + (sh->z >> 16));
            out += 5;
        }
        sh++;
    }

    if (arg1 < cl->timer) {
        cl->timer = (s16)(cl->timer - arg1 * 2);
        return;
    }
    cl->timer = 0;
    {
        u8 *ob = (u8 *)arg0;
        s32 v3 = *(u8 *)(ob + 0x39);
        s32 v2 = arg1 * 2;

        if (v2 < v3) {
            *(u8 *)(ob + 0x39) = (u8)(v3 - v2);
            return;
        }
    }
    objFreeObject(arg0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o121/overlay_121/shardClusterControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void shardClusterDestroy(void *arg0) {
    ShardCluster *cl = *(ShardCluster **)((u8 *)arg0 + 0x68);

    if (cl->vtx != NULL) {
        mmFree(cl->vtx);
    }
    if (cl->shards != NULL) {
        mmFree(cl->shards);
    }
    if (cl->unk8 != NULL) {
        mmFree(cl->unk8);
    }
    if (cl->unkC != NULL) {
        mmFree(cl->unkC);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o121/overlay_121/shardClusterDestroy.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
/* Builds the shard display list for one cluster and publishes it through outDL
 * (= &cl->unkC). obj holds the cluster at +0x68; setup holds the model list at +0x6C
 * and the model index at +0x3A. flagsOr/flagsClear feed the texture state and
 * minH/maxH filter entries by their height byte. Layouts follow jfg-re
 * docs/technical-notes.md (texture records 8 B, groups 16 B, triangles 16 B, vertices 10 B). */
void func_overlay_121_079004D0_1FC72D8(void *outDL, void *obj, void *setup, s32 flagsOr, s32 flagsClear, s32 minH, s32 maxH) {
    ShardCluster *cl;
    void **list;
    u8 *mdl;
    u8 *rec;
    u8 *ent;
    u8 *grp;
    u8 *grpBase;
    u8 *texTable;
    u8 *texOut;
    u8 *vtxBase;
    u8 *mtxBank;
    u8 *vtx;
    u8 *triCursor;
    u8 *src;
    u8 *out;
    u8 *sv;
    ShardParticle *fp;
    Gfx *dlStart;
    Gfx *dl;
    Gfx *outBuf;
    Gfx *gSrc;
    Gfx *gDst;
    void *tex;
    void *prevTex;
    s32 prevTexArg;
    s32 texArg;
    s32 texFlags;
    s32 keepMask;
    s32 modelFlags;
    s32 makeInfo;
    s32 hasTex;
    s32 nEnt;
    s32 nGrp;
    s32 nCmds;
    s32 vtxCount;
    s32 i;
    s32 g;
    s32 k;
    s32 n;
    s32 h;
    s32 bone;
    s32 sumX;
    s32 sumY;
    s32 sumZ;
    u32 batch;
    u32 batchAddr;
    u32 triAddr;
    u8 vi;
    f32 px;
    f32 py;
    f32 pz;
    f32 x0;
    f32 y0;
    f32 z0;
    f32 x1;
    f32 y1;
    f32 z1;
    f32 x2;
    f32 y2;
    f32 z2;
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
    f32 speed;

    cl = *(ShardCluster **)((u8 *)obj + 0x68);
    list = *(void ***)((u8 *)setup + 0x6C);
    mdl = (u8 *)list[*(s8 *)((u8 *)setup + 0x3A)];
    rec = *(u8 **)mdl;
    nEnt = *(s16 *)(rec + 0x16);
    ent = *(u8 **)(rec + 0x24);
    texOut = *(u8 **)(rec + 0x28);
    texTable = *(u8 **)(rec + 0x18);
    grpBase = *(u8 **)(rec + 0x20);
    vtxBase = *(u8 **)(mdl + 0x04);
    mtxBank = *(u8 **)(mdl + 0x10 + *(s8 *)(mdl + 0x0B) * 4);

    modelFlags = modelGetModelFlags();
    keepMask = ~flagsClear;
    texFlags = 0;
    prevTex = (void *)-1;
    prevTexArg = -1;
    vtxCount = 0;
    fp = cl->shards;
    vtx = (u8 *)cl->vtx;
    batchAddr = (u32)vtx;
    triCursor = (u8 *)cl->unk8;
    triAddr = (u32)cl->unk8;

    dlStart = (Gfx *)modGetMakeBuffer(&makeInfo);
    dl = dlStart;
    texDPInit(&dl);

    for (i = 0; i < nEnt; i++, ent += 0x10) {
        h = *(s8 *)(ent + 0x01);
        if (h < minH || maxH < h) {
            continue;
        }
        if (*(u32 *)(ent + 0x0C) & 0x400) {
            continue;
        }

        if (ent[0] == 0xFF) {
            tex = NULL;
            texArg = 0;
            hasTex = 0;
        } else {
            tex = *(void **)(texTable + ent[0] * 8);
            texArg = ent[0x0B] << 14;
            hasTex = 1;
        }

        texFlags = (texFlags | flagsOr | modelFlags) & keepMask;
        if (rec[0x11] != 0 && tex != NULL) {
            if (tex != prevTex || texArg != prevTexArg) {
                /* texture record: s16 arg, s16 offset, u32 (flags | texture index) */
                *(s16 *)(texOut + 0) = (s16)texArg;
                *(s16 *)(texOut + 2) = -1;
                *(u32 *)(texOut + 4) = (*(u32 *)(ent + 0x0C) & ~0xFFU) | ent[0];
                if (*(s16 *)((u8 *)tex + 0x06) & 0x40) {
                    *(s16 *)(texOut + 2) = (s16)(texArg + 0x100);
                    if (*(s16 *)(texOut + 2) >= *(u16 *)((u8 *)tex + 0x12)) {
                        if (((u8 *)tex)[0x18] != 0) {
                            *(s16 *)(texOut + 2) = 0;
                        } else {
                            *(s16 *)(texOut + 2) = (s16)(*(s16 *)(texOut + 2) - 0x100);
                        }
                    }
                }
                texOut += 8;
            }
        }
        prevTex = tex;
        prevTexArg = texArg;
        texDPTextureX(&dl, tex, texFlags, texArg);

        grp = grpBase + *(s16 *)(ent + 0x08) * 0x10;
        nGrp = *(s16 *)(ent + 0x18) - *(s16 *)(ent + 0x08);
        for (g = 0; g < nGrp; g++) {
            sumX = 0;
            sumY = 0;
            sumZ = 0;
            for (k = 0; k < 3; k++) {
                vi = grp[1 + k];
                if (vi < *(s8 *)(ent + 0x04)) {
                    bone = *(s8 *)(ent + 0x01);
                } else if (vi < *(s8 *)(ent + 0x05)) {
                    bone = *(s8 *)(ent + 0x02);
                } else {
                    bone = *(s8 *)(ent + 0x03);
                }
                src = vtxBase + (vi + *(s16 *)(ent + 0x06)) * 0x0A;
                mathMtxXFMF((float (*)[4])(mtxBank + (bone << 6)), (f32)*(s16 *)(src + 0),
                            (f32)*(s16 *)(src + 2), (f32)*(s16 *)(src + 4), &px, &py, &pz);
                sumX = (s32)((f32)sumX + px);
                sumY = (s32)((f32)sumY + py);
                sumZ = (s32)((f32)sumZ + pz);

                out = vtx + k * 0x0A;
                *(s16 *)(out + 0) = (s16)(s32)px;
                *(s16 *)(out + 2) = (s16)(s32)py;
                *(s16 *)(out + 4) = (s16)(s32)pz;
                out[6] = src[6];
                out[7] = src[7];
                out[8] = src[8];
                out[9] = src[9];
            }

            /* triangle record: flag 0x40, three batch vertex indices, three (s,t) pairs from the group */
            triCursor[0] = 0x40;
            triCursor[1] = (u8)vtxCount;
            triCursor[2] = (u8)(vtxCount + 1);
            triCursor[3] = (u8)(vtxCount + 2);
            *(s16 *)(triCursor + 4) = *(s16 *)(grp + 4);
            *(s16 *)(triCursor + 6) = *(s16 *)(grp + 6);
            *(s16 *)(triCursor + 8) = *(s16 *)(grp + 8);
            *(s16 *)(triCursor + 10) = *(s16 *)(grp + 10);
            *(s16 *)(triCursor + 12) = *(s16 *)(grp + 12);
            *(s16 *)(triCursor + 14) = *(s16 *)(grp + 14);
            triCursor += 0x10;
            vtxCount += 3;
            grp += 0x10;

            /* centroid, 16.16 fixed point */
            fp->x = (sumX << 16) / 3;
            fp->y = (sumY << 16) / 3;
            fp->z = (sumZ << 16) / 3;

            /* face normal of the shard triangle, scaled by a random speed */
            x0 = (f32)*(s16 *)(vtx + 0x00);
            y0 = (f32)*(s16 *)(vtx + 0x02);
            z0 = (f32)*(s16 *)(vtx + 0x04);
            x1 = (f32)*(s16 *)(vtx + 0x0A);
            y1 = (f32)*(s16 *)(vtx + 0x0C);
            z1 = (f32)*(s16 *)(vtx + 0x0E);
            x2 = (f32)*(s16 *)(vtx + 0x14);
            y2 = (f32)*(s16 *)(vtx + 0x16);
            z2 = (f32)*(s16 *)(vtx + 0x18);
            e1x = x1 - x0;
            e1y = y1 - y0;
            e1z = z1 - z0;
            e2x = x2 - x1;
            e2y = y2 - y1;
            e2z = z2 - z1;
            nx = e1y * e2z - e1z * e2y;
            ny = e1z * e2x - e1x * e2z;
            nz = e1x * e2y - e1y * e2x;
            len = sqrtf(nx * nx + ny * ny + nz * nz);
            if (len > 0.0f) {
                nx /= len;
                ny /= len;
                nz /= len;
            }
            speed = (f32)mathRnd(0x32, 0x12C) * D_overlay_121_07901030;
            fp->vx = (s32)(nx * speed);
            fp->vy = (s32)(ny * speed);
            fp->vz = (s32)(nz * speed);

            /* corners relative to the centroid, stored in reverse vertex order */
            for (k = 0; k < 3; k++) {
                sv = vtx + k * 0x0A;
                fp->cornerX[2 - k] = (s16)(*(s16 *)(sv + 0) - (fp->x >> 16));
                fp->cornerY[2 - k] = (s16)(*(s16 *)(sv + 2) - (fp->y >> 16));
                fp->cornerZ[2 - k] = (s16)(*(s16 *)(sv + 4) - (fp->z >> 16));
            }
            fp++;
            vtx += 0x1E;

            if (vtxCount == 0x18) {
                /* full batch of 8 triangles: vertex load, then 8 triangle draws */
                batch = batchAddr & 0x0FFFFFFF;
                dl->words.w0 = ((((batch & 6) | 0xC0) & 0xFF) << 16) | 0x04000000 | 0xF8;
                dl->words.w1 = batch;
                dl++;
                for (n = 0; n < 8; n++) {
                    dl->words.w1 = triAddr & 0x0FFFFFFF;
                    dl->words.w0 = ((hasTex & 0xFF) << 16) | 0x05000000 | 0x10;
                    triAddr += 0x10;
                    dl++;
                }
                batchAddr = (u32)vtx;
                vtxCount = 0;
            }
        }

        /* flush the partial batch at the end of the entry */
        if (vtxCount != 0) {
            batch = batchAddr & 0x0FFFFFFF;
            dl->words.w0 = (((vtxCount * 8 | (batch & 6)) & 0xFF) << 16) | 0x04000000
                           | ((vtxCount * 0x0A + 8) & 0xFFFF);
            dl->words.w1 = batch;
            dl++;
            for (n = 0; n < vtxCount / 3; n++) {
                dl->words.w1 = triAddr & 0x0FFFFFFF;
                dl->words.w0 = ((hasTex & 0xFF) << 16) | 0x05000000 | 0x10;
                triAddr += 0x10;
                dl++;
            }
            batchAddr = (u32)vtx;
            vtxCount = 0;
        }
    }

    dl->words.w1 = 0;
    dl->words.w0 = 0xE7000000; /* G_RDPPIPESYNC */
    dl++;
    dl->words.w1 = 0;
    dl->words.w0 = 0xB8000000; /* G_ENDDL */
    dl++;

    nCmds = (s32)(dl - dlStart);
    outBuf = (Gfx *)shardAlloc(nCmds * 8);
    *(Gfx **)outDL = outBuf;
    if (outBuf != NULL) {
        gSrc = dlStart;
        gDst = outBuf;
        for (n = 0; n < nCmds; n++) {
            gDst->words.w0 = gSrc->words.w0;
            gDst->words.w1 = gSrc->words.w1;
            gDst++;
            gSrc++;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o121/overlay_121/func_overlay_121_079004D0_1FC72D8.s")
#endif
