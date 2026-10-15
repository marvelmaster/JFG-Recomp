#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern u8 multiPlayerGame;
extern s32 D_overlay_10_00A00690;      /* active spark count */
extern f32 D_overlay_10_00A00694;      /* gravity */
extern void *D_overlay_10_00A006A0[];  /* active spark pointer list */
void mathOneFloatPY(void *, void *, s16, s32); /* sig from asm: 4 args */
void texFreeTexture(void *, s32, void *);
f32 camGetProjZ(f32, f32, s32, void *);
s32 objDrawTracer(s32, s32, s32, void *, void *, void *, f32, s32, s32, s32);
void sparkFree(void *arg0);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void sparkSetGravity(f32 arg0) {
    D_overlay_10_00A00694 = arg0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o10/overlay_10/sparkSetGravity.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *sparkAdd(void *arg0) {
    u8 *src = (u8 *) arg0;
    u8 *spark = NULL;
    TextureHeader *tex;
    s32 maxSparks;
    s16 texW;
    s16 texH;
    s16 life;
    s16 alpha;
    s16 t8;
    s16 t9;

    if (multiPlayerGame != 0) {
        maxSparks = 0x28;
    } else {
        maxSparks = 0x50;
    }
    if (D_overlay_10_00A00690 < maxSparks) {
        spark = (u8 *) mmAlloc(0x58, 0xFF7F7FFF);
        if (spark != NULL) {
            tex = texLoadTexture(*(s16 *) (src + 0x18));
            *(TextureHeader **) (spark + 0x20) = tex;
            if (tex != NULL) {
                /* first byte of the texture header is width, second is height */
                texW = ((u8 *) tex)[0];
                texH = ((u8 *) tex)[1];
                t8 = (texW - 1) << 5;
                t9 = (texH - 1) << 5;
                spark[0x00] = 0x40;
                spark[0x01] = 0;
                *(s16 *) (spark + 0x04) = t8;
                *(s16 *) (spark + 0x06) = 0;
                spark[0x02] = 1;
                *(s16 *) (spark + 0x08) = t8;
                *(s16 *) (spark + 0x0A) = t9;
                spark[0x03] = 2;
                *(s16 *) (spark + 0x0C) = 0;
                *(s16 *) (spark + 0x0E) = 0;
                spark[0x10] = 0x40;
                spark[0x11] = 1;
                *(s16 *) (spark + 0x14) = t8;
                *(s16 *) (spark + 0x16) = t9;
                spark[0x12] = 2;
                *(s16 *) (spark + 0x18) = 0;
                *(s16 *) (spark + 0x1A) = 0;
                spark[0x13] = 3;
                *(s16 *) (spark + 0x1C) = 0;
                *(s16 *) (spark + 0x1E) = t9;
                *(s32 *) (spark + 0x24) = *(s32 *) (src + 0x1C);
                *(s32 *) (spark + 0x28) = *(s32 *) (src + 0x20);
                *(s16 *) (spark + 0x56) = src[0x1B];
                alpha = *(s16 *) (spark + 0x56);
                *(s16 *) (spark + 0x54) = (s16) (src[0x1A] * 6);
                life = *(s16 *) (spark + 0x54);
                spark[0x27] = (s8) alpha;
                if (life < 0x20) {
                    spark[0x27] = (s8) ((s32) (alpha * life) >> 5);
                }
                spark[0x2B] = 0xFF;
                *(f32 *) (spark + 0x2C) = *(f32 *) (src + 0x08);
                *(f32 *) (spark + 0x30) = *(f32 *) (src + 0x0C);
                *(f32 *) (spark + 0x34) = *(f32 *) (src + 0x10);
                *(f32 *) (spark + 0x38) = *(f32 *) (src + 0x08);
                *(f32 *) (spark + 0x3C) = *(f32 *) (src + 0x0C);
                *(f32 *) (spark + 0x40) = *(f32 *) (src + 0x10);
                *(f32 *) (spark + 0x4C) = -*(f32 *) (src + 0x04);
                mathOneFloatPY(arg0, spark + 0x44, life, 0x40);
                *(f32 *) (spark + 0x50) = *(f32 *) (src + 0x14);
                D_overlay_10_00A006A0[D_overlay_10_00A00690] = spark;
                D_overlay_10_00A00690 += 1;
            }
            /* texture failed: asm returns the half-set slot without registering it */
        } else {
            mmFree(spark);
            spark = NULL;
        }
    }
    return spark;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o10/overlay_10/sparkAdd.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void sparkFree(void *arg0) {
    s32 count = D_overlay_10_00A00690;
    s32 i;
    s32 j;
    u8 *tex;

    for (i = 0; i < count; i++) {
        if (D_overlay_10_00A006A0[i] == arg0) {
            /* close the gap in the list */
            for (j = i; j < count - 1; j++) {
                D_overlay_10_00A006A0[j] = D_overlay_10_00A006A0[j + 1];
            }
            tex = *(u8 **) ((u8 *) arg0 + 0x20);
            if (tex != NULL) {
                texFreeTexture(tex, 0, arg0); /* asm: a1 is 0 here */
            }
            mmFree(arg0);
            D_overlay_10_00A00690 -= 1;
            return;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o10/overlay_10/sparkFree.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void sparkFreeAll(void) {
    while (D_overlay_10_00A00690 != 0) {
        sparkFree(D_overlay_10_00A006A0[0]);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o10/overlay_10/sparkFreeAll.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void sparkUpdate(s32 arg0) {
    s32 i;
    s32 n;
    u8 *spark;
    s16 life;
    s16 alpha;
    f32 gravity;
    f32 vx;
    f32 vy;
    f32 vz;

    if (arg0 == 0) {
        return;
    }
    i = 0;
    if (D_overlay_10_00A00690 > 0) {
        do {
            spark = (u8 *) D_overlay_10_00A006A0[i];
            i += 1;
            life = *(s16 *) (spark + 0x54) - arg0;
            *(s16 *) (spark + 0x54) = life;
            if (*(s16 *) (spark + 0x54) > 0) {
                *(f32 *) (spark + 0x38) = *(f32 *) (spark + 0x2C);
                *(f32 *) (spark + 0x3C) = *(f32 *) (spark + 0x30);
                *(f32 *) (spark + 0x40) = *(f32 *) (spark + 0x34);
                vx = *(f32 *) (spark + 0x44);
                vz = *(f32 *) (spark + 0x4C);
                gravity = D_overlay_10_00A00694;
                n = arg0;
                do {
                    vy = *(f32 *) (spark + 0x48);
                    *(f32 *) (spark + 0x2C) = *(f32 *) (spark + 0x2C) + vx;
                    *(f32 *) (spark + 0x30) = *(f32 *) (spark + 0x30) + vy;
                    *(f32 *) (spark + 0x34) = *(f32 *) (spark + 0x34) + vz;
                    *(f32 *) (spark + 0x48) = vy - gravity;
                    n -= 1;
                } while (n != 0);

                life = *(s16 *) (spark + 0x54);
                alpha = *(s16 *) (spark + 0x56);
                *(s8 *) (spark + 0x27) = (s8) alpha;
                if (life < 0x20) {
                    *(s8 *) (spark + 0x27) = (s8) ((s32) (alpha * life) >> 5);
                }
            } else {
                sparkFree(spark);
                i -= 1;
            }
        } while (i < D_overlay_10_00A00690);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o10/overlay_10/sparkUpdate.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 sparkDraw(s32 arg0, s32 arg1) {
    f32 depth[0x50];
    s32 count = D_overlay_10_00A00690;
    s32 i;
    s32 pass;
    s32 result = 0;
    void *tmpPtr;
    f32 tmpKey;
    u8 *spark;

    for (i = 0; i < count; i++) {
        spark = (u8 *) D_overlay_10_00A006A0[i];
        depth[i] = camGetProjZ(*(f32 *) (spark + 0x2C), *(f32 *) (spark + 0x30), *(s32 *) (spark + 0x34), spark);
    }

    /* bubble sort ascending by depth; the asm does the same passes, odd-even ordered */
    for (pass = count - 1; pass != 0; pass--) {
        for (i = 0; i < pass; i++) {
            if (depth[i + 1] < depth[i]) {
                tmpKey = depth[i];
                depth[i] = depth[i + 1];
                depth[i + 1] = tmpKey;
                tmpPtr = D_overlay_10_00A006A0[i];
                D_overlay_10_00A006A0[i] = D_overlay_10_00A006A0[i + 1];
                D_overlay_10_00A006A0[i + 1] = tmpPtr;
            }
        }
    }

    for (i = 0; i < count; i++) {
        spark = (u8 *) D_overlay_10_00A006A0[i];
        result = objDrawTracer(arg0, arg1, *(s32 *) (spark + 0x20), spark, spark + 0x2C, spark + 0x38,
                               *(f32 *) (spark + 0x50), *(s32 *) (spark + 0x24), *(s32 *) (spark + 0x28), 0x200);
    }
    return result;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o10/overlay_10/sparkDraw.s")
#endif
