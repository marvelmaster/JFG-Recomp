#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern s32 __MODULE00102;
void mathOneFloatPY(void *obj, f32 *out);
void hitInitObjectHit(void *arg0, s16 arg1, s8 arg2, s8 arg3, s16 arg4, s16 arg5, s16 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, u16 arg11);
s16 objTvTimes(s32 arg0);
s32 trackGetIntersect(s32 a, f32 *b, f32 *c, s32 d, s32 e, void *hit);
void trackMakePolylist(s32 a, f32 *b, f32 *c, s32 *d, s32 e, s32 f, s32 g);
void amSndPlayXYZ(u16 soundId, f32 x, f32 y, f32 z, u8 arg4, void *soundMask);
void explosionStart(s16 arg0, s16 arg1, s16 arg2, s16 arg3, s32 arg4, void *arg5);
void objFreeObject(void *obj);
void squadsAddInterestingEvent(void *arg0, s16 x, s16 y, s16 z, s32 a, s32 b, s32 c);
void runlinkSetDestructTimer(s32 overlayIndex, s32 selfDestructTimer, s32 refCount);
void partUpdateTriggers(void *obj, s32 arg1);
void SquaddieLightAndAnimate(void *obj);
s32 texAnimateSprite(s32 handle, s32 *state, s32 frames, void *data, s32 dt);
void grenadeDestroy(void *arg0);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void grenadeInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *spawn = (u8 *)arg1;
    u8 *st;
    u8 *flags;
    u8 **table;
    f32 p1[3];
    f32 p2[3];
    s32 radius;
    u8 hit[0x20];

    *(f32 *)(obj + 0x1C) = 0.0f;
    *(f32 *)(obj + 0x20) = 0.0f;
    st = *(u8 **)(obj + 0x68);
    if (spawn[0x18] != 0) {
        *(f32 *)(obj + 0x24) = 0.0f;
        *(s16 *)(obj + 0x0) = 0;
        *(s16 *)(obj + 0x2) = 0;
        *(s16 *)(obj + 0x4) = 0;
    } else {
        *(f32 *)(obj + 0x24) = -1.0f;
        *(s16 *)(obj + 0x0) = *(s16 *)(spawn + 0xC);
        *(s16 *)(obj + 0x2) = *(s16 *)(spawn + 0xE);
        *(s16 *)(obj + 0x4) = (s16)mathRnd(0, 0xFFFF);
        table = *(u8 ***)(obj + 0x6C);
        *(f32 *)(obj + 0x28) = (f32)mathRnd(0, *(u8 *)table[0] - 1);
        mathOneFloatPY(obj, (f32 *)(obj + 0x1C));

        p1[0] = *(f32 *)(obj + 0xC) - *(f32 *)(obj + 0x1C) * 32.0f;
        p1[1] = *(f32 *)(obj + 0x10) - *(f32 *)(obj + 0x20) * 32.0f;
        p1[2] = *(f32 *)(obj + 0x14) - *(f32 *)(obj + 0x24) * 32.0f;
        p2[0] = *(f32 *)(obj + 0xC) + *(f32 *)(obj + 0x1C) * 32.0f;
        p2[1] = *(f32 *)(obj + 0x10) + *(f32 *)(obj + 0x20) * 32.0f;
        p2[2] = *(f32 *)(obj + 0x14) + *(f32 *)(obj + 0x24) * 32.0f;
        /* asm: 16.0f bit pattern stored in a stack word and passed by address/value */
        radius = 0x41800000;
        trackMakePolylist(1, p1, p2, &radius, 0, 0, 0);
        if (trackGetIntersect(0, p1, p2, radius, 1, hit) != 0) {
            *(f32 *)(obj + 0xC) = p2[0];
            *(f32 *)(obj + 0x10) = p2[1];
            *(f32 *)(obj + 0x14) = p2[2];
        }
        *(f32 *)(obj + 0x1C) = *(f32 *)(obj + 0x1C) * *(f32 *)(spawn + 0x10);
        *(f32 *)(obj + 0x20) = *(f32 *)(obj + 0x20) * *(f32 *)(spawn + 0x10);
        *(f32 *)(obj + 0x24) = *(f32 *)(obj + 0x24) * *(f32 *)(spawn + 0x10);
    }
    hitInitObjectHit(obj, (s16)((spawn[0xA] + 1) << 8), 1, 2, 0, 0, 0, 16.0f, 16.0f, 1.0f, 0.75f, 0x11);
    *(s16 *)(st + 0x8) = objTvTimes(spawn[0xB] * 6);
    *(u8 *)(st + 0xC) = spawn[0xA];
    *(s32 *)(st + 0x4) = 0xD;
    *(s32 *)(st + 0x0) = *(s32 *)(spawn + 0x14);
    *(u8 *)(st + 0xD) = spawn[0x18];
    *(u8 *)(st + 0xE) = spawn[0x19];
    flags = *(u8 **)(obj + 0x7C);
    *flags &= 0xFD;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o102/overlay_102/grenadeInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void grenadeDestroy(void *arg0) {
    u8 *obj = (u8 *)arg0;
    u8 *surf = *(u8 **)(obj + 0x7C);
    s16 var_v1 = 0;
    void *var_v0;

    if (surf != NULL && (surf[0] & 1) && (*(f32 *)(surf + 0x10) - *(f32 *)(obj + 0x10)) > 10.0f) {
        var_v1 = 4;
    }
    var_v0 = *(void **)*(void **)(obj + 0x68);
    if (var_v0 != NULL && *(s16 *)((u8 *)var_v0 + 0x48) != 1) {
        var_v0 = NULL;
    }
    explosionStart(var_v1, (s16)*(f32 *)(obj + 0xC), (s16)*(f32 *)(obj + 0x10), (s16)*(f32 *)(obj + 0x14), 8, var_v0);
    amSndPlayXYZ(0x22, *(f32 *)(obj + 0xC), *(f32 *)(obj + 0x10), *(f32 *)(obj + 0x14), 4, NULL);
    squadsAddInterestingEvent(NULL, (s16)*(f32 *)(obj + 0xC), (s16)*(f32 *)(obj + 0x10), (s16)*(f32 *)(obj + 0x14), 5, 1, 0x22);
    objFreeObject(obj);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o102/overlay_102/grenadeDestroy.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void grenadeControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *)arg0;
    u8 *st = *(u8 **)(obj + 0x68);
    u8 *surf = *(u8 **)(obj + 0x7C);

    runlinkSetDestructTimer(__MODULE00102, 2, 2);
    *(s16 *)(st + 0x8) = (s16)(*(s16 *)(st + 0x8) - arg1);
    if (*(s16 *)(st + 0x8) <= 0) {
        grenadeDestroy(arg0);
    } else if (st[0xD] != 0) {
        u8 *p = *(u8 **)st;
        u8 **table = *(u8 ***)(p + 0x6C);
        u8 *q;

        *(s32 *)(obj + 0x84) = 0;
        q = table[*(s8 *)(p + 0x3A)];
        if (q == NULL) {
            return;
        }
        if (q[0xA] != 0 && *(s16 *)(p + 0x48) == 0x18) {
            SquaddieLightAndAnimate(p);
        }
        {
            u8 *pos = *(u8 **)(q + 0x68) + st[0xE] * 12;

            *(f32 *)(obj + 0xC) = *(f32 *)(pos + 0);
            *(f32 *)(obj + 0x10) = *(f32 *)(pos + 4);
            *(f32 *)(obj + 0x14) = *(f32 *)(pos + 8);
        }
    } else {
        if (surf[0] & 2) {
            squadsAddInterestingEvent(arg0, (s16)*(f32 *)(obj + 0xC), (s16)*(f32 *)(obj + 0x10), (s16)*(f32 *)(obj + 0x14), 1, 2, 0);
        } else {
            f32 scale = *(f32 *)(surf + 0x14) * 0.25f;

            if (scale > 1.0f) {
                scale = 1.0f;
            }
            *(s16 *)(st + 0xA) = (s16)((f32)*(s16 *)(st + 0xA) + 256.0f * scale * (f32)arg1);
            texAnimateSprite(*(s32 *)*(u8 **)(obj + 0x6C), (s32 *)(st + 0x4), (s32)(10.0f * scale), obj + 0x28, arg1);
        }
        *(s16 *)(obj + 0x4) = *(s16 *)(st + 0xA);
        /* asm: if (st->unk4 & 2) the code adds an upper-half constant ($at) to obj->unk4;
         * that constant has no low 16 bits, so the s16 value is unchanged. */

        if ((surf[0] & 1) == 0 && *(f32 *)(surf + 0x14) > 2.0f) {
            *(s32 *)(obj + 0x84) = 1;
            partUpdateTriggers(arg0, arg1);
        } else if ((surf[0] & 1) != 0 && (*(f32 *)(surf + 0x10) - *(f32 *)(obj + 0x10)) > 10.0f) {
            *(s32 *)(obj + 0x84) = 8;
            partUpdateTriggers(arg0, arg1);
        } else {
            *(s32 *)(obj + 0x84) = 0;
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o102/overlay_102/grenadeControl.s")
#endif
