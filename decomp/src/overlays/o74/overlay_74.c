#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
void hitInitObjectHit(void *arg0, s16 arg1, s8 arg2, s8 arg3, s16 arg4, s16 arg5, s16 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, u16 arg11);
void animseqStartPath(s32 arg0);
void animseqHoldPath(s32 arg0);
extern f32 D_overlay_74_04A00240;
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animswitchInit(void *arg0, void *arg1) {
    u8 *obj = arg0;
    u8 *def = arg1;
    f32 temp_f0;
    f32 var_f6;

    obj[0x88] = def[0xA] & 1;
    obj[0x89] = def[0xB];
    obj[0x8A] = def[0xC];
    *(s16 *)(obj + 0x8C) = (s16)(*(u16 *)(def + 0x12) * 6);
    *(s16 *)(obj + 0x8E) = *(s16 *)(obj + 0x8C);
    *(s16 *)(obj + 0x0) = *(s16 *)(def + 0xE);
    *(s16 *)(obj + 0x2) = *(s16 *)(def + 0x10);
    var_f6 = (f32)def[0xD];
    *(f32 *)(obj + 0x8) = var_f6 * D_overlay_74_04A00240;
    if ((*(s8 *)(*(u8 **)(obj + 0x40) + 0x1F) > 0) && (obj[0x88] != 0)) {
        obj[0x3A] = 1;
    }
    temp_f0 = *(f32 *)(obj + 0x8) * 8.0f;
    hitInitObjectHit(arg0, 0x100, 1, 1, 0, 0, 0, temp_f0, temp_f0, -1.0f, 1.0f, 1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o74/overlay_74/animswitchInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void animswitchControl(void *arg0, s32 arg1) {
    u8 *obj = arg0;
    u8 *v0;
    u8 var_v1;

    if (obj[0x8A] == 1) {
        v0 = obj + 0x88;
        var_v1 = v0[0];
        if (var_v1 != 0) {
            *(s16 *)(v0 + 6) = (s16)(*(s16 *)(v0 + 6) - arg1);
            if (*(s16 *)(v0 + 6) <= 0) {
                v0[0] = 0;
            }
            var_v1 = v0[0];
        } else if (*(s16 *)(*(u8 **)(obj + 0x4C) + 6) != 0x100) {
            v0[0] = 1;
            var_v1 = 1;
            *(s16 *)(v0 + 6) = *(s16 *)(v0 + 4);
        }
    } else {
        if (*(s16 *)(*(u8 **)(obj + 0x4C) + 6) != 0x100) {
            obj[0x88] ^= 1;
        }
        v0 = obj + 0x88;
        var_v1 = v0[0];
    }
    if (var_v1 != 0) {
        if (*(s8 *)(*(u8 **)(obj + 0x40) + 0x1F) > 0) {
            obj[0x3A] = 1;
        }
        /* asm also leaves extra args in a1-a3; the callee only takes the path index */
        animseqStartPath(v0[1]);
    } else {
        obj[0x3A] = 0;
        /* asm also leaves extra args in a1-a3; the callee only takes the path index */
        animseqHoldPath(v0[1]);
    }
    *(s16 *)(*(u8 **)(obj + 0x4C) + 6) = 0x100;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o74/overlay_74/animswitchControl.s")
#endif
