#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
typedef struct AnimshipKey {
    s16 key;        /* 0x00: object id, negative terminates the table */
    s16 count;      /* 0x02 */
    void *data;     /* 0x04: 0x10-byte records */
} AnimshipKey;

extern AnimshipKey D_overlay_73_04900AC0[];

s32 fxAllocateCone(s16 a0, s16 a1, s16 a2, s16 a3, s32 a4, f32 a5, f32 a6, s32 a7, s32 a8, s32 a9);
s32 hitInitObjectHit(void *obj, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6,
                     f32 f1, f32 f2, f32 f3, f32 f4, s32 a7);
void fxFreeCone(s32 cone);
void amSndStopXYZ(s32 handle);
void fxMakeConeLength(void *cone, s16 length, u8 alpha);
void fxMakeConeTextureCoords(void *cone, s16 phase);
s32 mathSin(s16 angle, s32 arg1);
void animobjControl(void *obj, s32 arg1);
void fxDrawCone(Gfx **dl, s32 coneId, s32 mode, u8 flag);
f32 camGetProjZ(f32 arg0, f32 arg1, f32 arg2);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animshipInit(u8 *arg0, s32 arg1) {
    AnimshipKey *key;
    void **table;
    void **entry;
    u8 *wd;
    u8 *state;
    u8 *rec;
    u8 *cone;
    u8 *vtx;
    void *data;
    s32 count;
    s32 i;
    u16 vi;

    key = D_overlay_73_04900AC0;
    count = 0;
    data = NULL;
    if (key[0].key >= 0) {
        do {
            if (*(s16 *)(arg0 + 0x4A) == key->key) {
                count = key->count;
                data = key->data;
            }
            key++;
        } while (data == NULL && key->key >= 0);
    }

    table = *(void ***)(arg0 + 0x6C);
    entry = (void **)table[(s8)arg0[0x3A]];
    wd = (u8 *)entry[0];

    if (data != NULL && wd != NULL) {
        state = *(u8 **)(arg0 + 0x68);
        i = count - 1;
        if (count != 0) {
            rec = (u8 *)data;
            cone = state;
            do {
                vi = *(u16 *)(*(u8 **)(wd + 0x30) + ((s8)rec[0]) * 4);
                vtx = *(u8 **)(wd + 0x1C) + (vi * 0xA);
                *(s32 *)(cone + 0) = fxAllocateCone(*(s16 *)(vtx + 0), *(s16 *)(vtx + 2),
                                                    *(s16 *)(vtx + 4), *(s16 *)(rec + 6),
                                                    *(s16 *)(rec + 8), *(f32 *)(rec + 0xC),
                                                    (f32)*(s16 *)(rec + 0xA), rec[1],
                                                    *(s16 *)(rec + 2), *(s16 *)(rec + 4));
                cone[9] = (u8)mathRnd(0, 0xFF);
                cone[0xA] = (s8)rec[0];
                cone[0xB] = (u8)*(u16 *)(*(u8 **)(wd + 0x30) + ((s8)rec[0]) * 4 + 2);
                cone += 0xC;
                rec += 0x10;
            } while (i-- != 0);
        }
    }

    if (*(s16 *)(arg0 + 0x48) == 0x96) {
        hitInitObjectHit(arg0, -1, 0, 8, 0, 0, 0, 20.0f, 20.0f, -1.0f, 1.0f, 0x11);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o73/overlay_73/animshipInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animshipControl(u8 *arg0, s32 arg1) {
    u8 *cone;
    u8 *obj;
    s32 i;
    u8 v0;
    u8 v1;
    u8 t5;
    u8 mid;
    s32 angle;
    s32 scaled;
    s16 amp;

    cone = *(u8 **)(arg0 + 0x68);
    i = 0xF;
    do {
        obj = *(u8 **)(cone + 0);
        if (obj != NULL) {
            v0 = cone[7];
            v1 = cone[8];
            if (v0 < v1) {
                cone[7] = (u8)(v0 + arg1);
                v0 = cone[7] & 0xFF;
                if (v0 >= v1) {
                    cone[7] = v1;
                    v0 = v1;
                }
                mid = cone[5];
                cone[4] = (u8)(mid + (((s32)((cone[6] - mid) * v0)) / (s32)v1));
            }
            t5 = (u8)(cone[9] + (arg1 * 0x10));
            cone[9] = t5;
            amp = *(s16 *)(obj + 0x20);
            angle = mathSin((s16)(t5 << 8), arg1 * 0x10);
            scaled = ((((angle * amp) >> 0x14) + amp) * cone[4]) >> 8;
            fxMakeConeTextureCoords(obj, (s16)(cone[9] << 8));
            fxMakeConeLength(obj, (s16)scaled, cone[4]);
        }
        cone += 0xC;
    } while (i-- != 0);

    animobjControl(arg0, arg1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o73/overlay_73/animshipControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animshipFree(u8 *arg0) {
    s32 *cone;
    s32 i;

    cone = *(s32 **)(arg0 + 0x68);
    i = 0xF;
    do {
        if (cone[0] != 0) {
            fxFreeCone(cone[0]);
        }
        cone = (s32 *)((u8 *)cone + 0xC);
    } while (i-- != 0);

    if (*(s32 *)(arg0 + 0x88) != 0) {
        amSndStopXYZ(*(s32 *)(arg0 + 0x88));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o73/overlay_73/animshipFree.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animshipDrawThrusters(Gfx **arg0, MatrixS **arg1, u8 *arg2) {
    u8 *s3;
    u8 *hdr;
    u8 *rec;
    u8 *vecp;
    u8 *pp;
    s16 order[16];
    f32 depth[16];
    u8 *recs[16];
    u32 f4s[16];
    f32 vec3[3];
    f32 scale;
    f32 x;
    f32 y;
    f32 z;
    s16 s4 = 0xF;
    s32 n5 = 0;
    s32 cnt;
    s32 outer;
    s32 i;
    s32 j;
    s16 s4Old;

    s3 = *(u8 **) (*(u8 **) (arg2 + 0x6C) + (s8) arg2[0x3A] * 4);
    hdr = *(u8 **) s3;
    rec = *(u8 **) (arg2 + 0x68);

    if (*(s32 *) rec != 0) {
        do {
            s4Old = s4;
            if (rec[4] != 0) {
                vecp = *(u8 **) (s3 + 0x68) + rec[0xA] * 0xC;
                if (*(s8 *) (hdr + 0x4E) == 0) {
                    pointListRPY(1, (s16 *) arg2, (s32 *) vecp, vec3);
                    scale = *(f32 *) (arg2 + 0x08);
                    x = vec3[0] * scale + *(f32 *) (arg2 + 0x0C);
                    y = vec3[1] * scale + *(f32 *) (arg2 + 0x10);
                    z = vec3[2] * scale + *(f32 *) (arg2 + 0x14);
                } else {
                    x = *(f32 *) (vecp + 0x0);
                    y = *(f32 *) (vecp + 0x4);
                    z = *(f32 *) (vecp + 0x8);
                }

                order[n5] = (s16) n5;
                depth[n5] = camGetProjZ(x, y, z);
                recs[n5] = rec;
                pp = *(u8 **) (s3 + 0x10 + (s8) s3[0x0B] * 4);
                f4s[n5] = (u32) (pp + (rec[0xB] << 6));
                n5++;
            }
            s4 = (s16) (s4 - 1);
            rec += 0xC;
        } while (s4Old != 0 && *(s32 *) rec != 0);
    }

    if (n5 > 0) {
        cnt = n5 - 1;
        outer = cnt;
        if (cnt > 0) {
            do {
                if (outer > 0) {
                    for (j = 0; j < outer; j++) {
                        s16 a1 = order[j + 1];
                        s16 a2 = order[j];

                        if (depth[a1] < depth[a2]) {
                            order[j] = a1;
                            order[j + 1] = a2;
                        }
                    }
                }
                outer--;
            } while (outer > 0);
        }

        if (*(s8 *) (hdr + 0x4E) == 0) {
            camPushModelMtx(arg0, arg1, (ObjectTransform *) arg2, 1.0f, 0.0f);
            for (i = 0; i < n5; i++) {
                u8 *r = recs[order[i]];

                fxDrawCone(arg0, *(s32 *) r, 6, r[4]);
            }
        } else {
            for (i = 0; i < n5; i++) {
                Gfx *g = *arg0;
                u8 *r = recs[order[i]];

                *arg0 = g + 1;
                g->words.w0 = 0x01810040;
                g->words.w1 = f4s[order[i]] + 0x80000000;
                fxDrawCone(arg0, *(s32 *) r, 6, r[4]);
            }
        }

        {
            Gfx *end = *arg0;

            *arg0 = end + 1;
            end->words.w0 = 0xBC00000A;
            end->words.w1 = 0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o73/overlay_73/animshipDrawThrusters.s")
#endif
