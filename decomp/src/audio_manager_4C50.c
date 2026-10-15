#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern void *D_800F2B10_B1750;
extern void *D_800F2B18_B1758;
extern void *D_800F2B2C_B176C;
extern void *D_800F2B40_B1780;
extern void *D_800F2B54_B1794;
extern u8 D_800F2B68_B17A8[];
extern u8 D_800F2B7C_B17BC[];
extern u8 D_800F2B90_B17D0[];
extern u8 D_800F2BA4_B17E4[];
extern u8 D_800F2C94_B1784[];
f32 _depth2Cents(u8 arg0);
f32 __sinf(f32 x, void *ctx); /* sig: asm also passes arg0 in $a0 */
#endif

const char D_800AAB00[] = "am: Unknown OSCILLATOR type %d\n";
const char D_800AAB20[] = "am: Out of oscillator states\n";

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amVibratoInit(void) {
    u8 *a0, *a1, *a2, *a3;
    u8 *v0;

    D_800F2B10_B1750 = &D_800F2B18_B1758;
    D_800F2B18_B1758 = &D_800F2B2C_B176C;
    v0 = (u8 *)&D_800F2B54_B1794;
    D_800F2B2C_B176C = &D_800F2B40_B1780;
    a3 = D_800F2BA4_B17E4;
    a2 = D_800F2B90_B17D0;
    a1 = D_800F2B7C_B17BC;
    a0 = D_800F2B68_B17A8;
    D_800F2B40_B1780 = &D_800F2B54_B1794;
    do {
        *(u8 **)v0 = a0;
        *(u8 **)a0 = a1;
        *(u8 **)a1 = a2;
        *(u8 **)a2 = a3;
        v0 = a3;
        a3 += 0x50;
        a2 += 0x50;
        a1 += 0x50;
        a0 += 0x50;
    } while (a3 != D_800F2C94_B1784);
    *(u8 **)v0 = NULL;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_4C50/amVibratoInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 amInitOsc(void **arg0, f32 *arg1, s32 arg2, u8 arg3, u8 arg4, u8 arg5) {
    u8 *osc;
    s32 ret = 0;
    u8 type = arg2 & 0xFF;
    u8 a3 = arg3 & 0xFF;
    s32 cents;
    f32 ratio;
    u16 t;

    osc = (u8 *)D_800F2B10_B1750;
    if (osc != NULL) {
        D_800F2B10_B1750 = *(void **)osc;
        osc[4] = type;
        *arg0 = osc;
        ret = arg5 << 0xE;
        switch (type) {
        case 0x1:
            t = arg4 >> 1;
            *(u16 *)(osc + 8) = 0;
            *(u16 *)(osc + 6) = 0x103 - a3;
            osc[0xC] = (u8)t;
            osc[0xD] = (u8)(0x7F - t);
            *arg1 = (f32)(osc[0xD]);
            break;
        case 0x2:
            t = 0x100 - a3;
            *(u16 *)(osc + 6) = t;
            *(u16 *)(osc + 8) = t;
            osc[5] = 0;
            osc[0xE] = (u8)(0x7F - arg4);
            osc[0xD] = 0x7F;
            osc[0xC] = 0x7F;
            *arg1 = 127.0f;
            break;
        case 0x3:
            *(u16 *)(osc + 6) = 0x100 - a3;
            *(u16 *)(osc + 8) = 0;
            osc[0xC] = 0x7F;
            osc[0xD] = arg4;
            *arg1 = 127.0f;
            break;
        case 0x4:
            t = 0x7F - arg4;
            *(u16 *)(osc + 6) = 0x100 - a3;
            *(u16 *)(osc + 8) = 0;
            osc[0xC] = (u8)t;
            osc[0xD] = arg4;
            *arg1 = (f32)(osc[0xC]);
            break;
        case 0x80:
            *(f32 *)(osc + 0xC) = _depth2Cents(arg4);
            *(u16 *)(osc + 8) = 0;
            *(u16 *)(osc + 6) = 0x103 - a3;
            *arg1 = 1.0f;
            break;
        case 0x81:
            t = 0x100 - a3;
            *(u16 *)(osc + 6) = t;
            *(u16 *)(osc + 8) = t;
            osc[5] = 0;
            cents = (s32)_depth2Cents(arg4);
            *(f32 *)(osc + 0xC) = alCents2Ratio(-cents);
            ratio = alCents2Ratio(cents);
            *(f32 *)(osc + 0x10) = ratio;
            *arg1 = ratio;
            break;
        case 0x82:
            t = 0x100 - a3;
            *(u16 *)(osc + 6) = t;
            *(u16 *)(osc + 8) = t;
            cents = (s32)_depth2Cents(arg4);
            *(s32 *)(osc + 0x10) = cents * 2;
            *(s32 *)(osc + 0xC) = cents;
            *arg1 = alCents2Ratio(cents);
            break;
        case 0x83:
            t = 0x100 - a3;
            *(u16 *)(osc + 6) = t;
            *(u16 *)(osc + 8) = t;
            cents = (s32)_depth2Cents(arg4);
            *(s32 *)(osc + 0xC) = -cents;
            *(s32 *)(osc + 0x10) = cents * 2;
            *arg1 = alCents2Ratio(-cents);
            break;
        }
    }
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_4C50/amInitOsc.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 amUpdateOsc(u8 *arg0, f32 *arg1) {
    u8 *osc = arg0;
    s32 ret = 0x3E80;
    u16 phase;
    u16 period;
    s32 var;
    f32 angle;
    f32 val;

    switch (osc[4]) {
    case 0x1:
        phase = *(u16 *)(osc + 8) + 1;
        var = phase;
        *(u16 *)(osc + 8) = phase;
        period = *(u16 *)(osc + 6);
        if (var >= (s32)period) {
            *(u16 *)(osc + 8) = 0;
            var = 0;
        }
        angle = ((f32)var / (f32)(u32)period) * 6.2831855f;
        val = (f32)osc[0xD] + (f32)osc[0xC] * __sinf(angle, osc);
        *arg1 = val;
        break;
    case 0x2:
        if (osc[5] == 0) {
            *arg1 = (f32)osc[0xE];
            osc[5] = 1;
        } else {
            *arg1 = (f32)osc[0xD];
            osc[5] = 0;
        }
        ret = *(u16 *)(osc + 6) * 0x3E80;
        break;
    case 0x3:
        phase = *(u16 *)(osc + 8) + 1;
        var = phase;
        *(u16 *)(osc + 8) = phase;
        period = *(u16 *)(osc + 6);
        if ((s32)period < var) {
            *(u16 *)(osc + 8) = 0;
            var = 0;
        }
        *arg1 = (f32)osc[0xC] - ((f32)var / (f32)(u32)period) * (f32)osc[0xD];
        break;
    case 0x4:
        phase = *(u16 *)(osc + 8) + 1;
        var = phase;
        *(u16 *)(osc + 8) = phase;
        period = *(u16 *)(osc + 6);
        if ((s32)period < var) {
            *(u16 *)(osc + 8) = 0;
            var = 0;
        }
        *arg1 = (f32)osc[0xC] + ((f32)var / (f32)(u32)period) * (f32)osc[0xD];
        break;
    case 0x80:
        phase = *(u16 *)(osc + 8) + 1;
        var = phase;
        *(u16 *)(osc + 8) = phase;
        period = *(u16 *)(osc + 6);
        if (var >= (s32)period) {
            *(u16 *)(osc + 8) = 0;
            var = 0;
        }
        val = alCents2Ratio((s32)(__sinf(((f32)var / (f32)(u32)period) * 6.2831855f, osc) * *(f32 *)(osc + 0xC)));
        *arg1 = val;
        break;
    case 0x81:
        if (osc[5] == 0) {
            osc[5] = 1;
            *arg1 = *(f32 *)(osc + 0xC);
        } else {
            osc[5] = 0;
            *arg1 = *(f32 *)(osc + 0x10);
        }
        ret = *(u16 *)(osc + 6) * 0x3E80;
        break;
    case 0x82:
        phase = *(u16 *)(osc + 8) + 1;
        var = phase;
        *(u16 *)(osc + 8) = phase;
        period = *(u16 *)(osc + 6);
        if ((s32)period < var) {
            *(u16 *)(osc + 8) = 0;
            var = 0;
        }
        val = alCents2Ratio((s32)((f32)*(s32 *)(osc + 0xC) - ((f32)var / (f32)(u32)period) * (f32)*(s32 *)(osc + 0x10)));
        *arg1 = val;
        break;
    case 0x83:
        phase = *(u16 *)(osc + 8) + 1;
        var = phase;
        *(u16 *)(osc + 8) = phase;
        period = *(u16 *)(osc + 6);
        if ((s32)period < var) {
            *(u16 *)(osc + 8) = 0;
            var = 0;
        }
        val = alCents2Ratio((s32)(((f32)var / (f32)(u32)period) * (f32)*(s32 *)(osc + 0x10) + (f32)*(s32 *)(osc + 0xC)));
        *arg1 = val;
        break;
    }
    return ret;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_4C50/amUpdateOsc.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amStopOsc(void *arg0) {
    *(void **)arg0 = D_800F2B10_B1750;
    D_800F2B10_B1750 = arg0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_4C50/amStopOsc.s")
#endif

#if 0
f32 _depth2Cents(u8 arg0) {
    f32 var_f0;
    f32 var_f2;
    u32 temp_t8;

    var_f0 = 1.030992985f;
    var_f2 = 1.0f;
    if (arg0 != 0) {
        do {
            if (arg0 & 1) {
                var_f2 *= var_f0;
            }
            var_f0 *= var_f0;
            temp_t8 = (arg0 >> 1);
            arg0 = temp_t8 & 0xFF;
        } while (temp_t8 != 0);
    }
    return var_f2;
}
#else
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
f32 _depth2Cents(u8 arg0) {
    f32 base = 1.030992985f;
    f32 acc = 1.0f;
    u32 n = arg0;

    if (n != 0) {
        do {
            if (n & 1) {
                acc *= base;
            }
            base *= base;
            n = (n >> 1) & 0xFF;
        } while (n != 0);
    }
    return acc;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/audio_manager_4C50/_depth2Cents.s")
#endif
#endif
