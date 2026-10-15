#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
typedef struct SpinlightRacer {
    /* 0x00 */ s32 unk0;
    /* 0x04 */ s32 unk4;
    /* 0x08 */ u8 unk8;
    /* 0x09 */ u8 unk9;
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 unkB;
    /* 0x0C */ s16 unkC;
    /* 0x0E */ s16 unkE;
} SpinlightRacer;

typedef struct SpinlightSetup {
    /* 0x00 */ u8 pad00[0xA];
    /* 0x0A */ u8 unkA;
    /* 0x0B */ u8 unkB;
    /* 0x0C */ u8 unkC;
    /* 0x0D */ u8 unkD;
    /* 0x0E */ u8 unkE;
    /* 0x0F */ u8 unkF;
    /* 0x10 */ u8 unk10;
    /* 0x11 */ u8 unk11;
    /* 0x12 */ u8 unk12;
    /* 0x13 */ u8 unk13;
    /* 0x14 */ u8 pad14;
    /* 0x15 */ u8 unk15;
    /* 0x16 */ u8 unk16;
    /* 0x17 */ u8 unk17;
    /* 0x18 */ u8 unk18;
    /* 0x19 */ u8 pad19;
    /* 0x1A */ s16 unk1A;
} SpinlightSetup;

f32 Sinf(s16 angle);
s32 camlightAdd(Object *obj, s8 *light, void *setup);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void spinlightInit(Object *arg0, SpinlightSetup *arg1) {
    u8 sp48[0x18];
    u8 sp28[0x20];
    SpinlightRacer *racer;
    u8 temp_v0;
    s8 temp_a3;

    temp_v0 = arg1->unkA;
    temp_a3 = ((s8 *)arg0->segment.header)[0x1F];
    racer = (SpinlightRacer *)arg0->racer;
    if ((s32)temp_v0 < temp_a3) {
        arg0->segment.pad18[0x22] = temp_v0;
    } else {
        arg0->segment.pad18[0x22] = temp_a3 - 1;
    }
    arg0->segment.trans.y_rotation = (s16)(arg1->unkB << 8);
    arg0->segment.trans.x_rotation = (s16)(arg1->unkC << 8);
    racer->unk9 = (u8)(arg0->segment.trans.y_rotation >> 8);
    racer->unkA = (u8)(arg0->segment.trans.x_rotation >> 8);
    racer->unk0 = 0;
    racer->unkB = (u8)(arg0->segment.trans.z_rotation >> 8);
    racer->unk4 = 0;
    if (arg1->unk12 != 0) {
        sp48[0x00] = 3;
        sp48[0x01] = arg1->unk11;
        sp48[0x02] = 0x61;
        sp48[0x03] = -1;
        *(s16 *)&sp48[0x04] = 0;
        *(s16 *)&sp48[0x06] = 0;
        *(s16 *)&sp48[0x08] = 0;
        *(s16 *)&sp48[0x0A] = 0;
        *(s16 *)&sp48[0x0C] = (s16)(arg1->unk12 * 4);
        *(s16 *)&sp48[0x0E] = (s16)(arg1->unk12 * 4);
        sp48[0x10] = arg1->unkD;
        sp48[0x11] = arg1->unkE;
        sp48[0x12] = arg1->unkF;
        sp48[0x13] = arg1->unk10;
        *(s16 *)&sp48[0x14] = -1;
        sp48[0x16] = arg1->unk16;
        sp48[0x17] = arg1->unk17;
        racer->unk0 = addObjectLight(arg0, (ObjectHeader48 *)sp48);
    }
    if (arg1->unk15 != 0) {
        sp28[0x00] = 0xC4;
        sp28[0x01] = 0x50;
        *(s16 *)&sp28[0x02] = (s16)(arg1->unk16 << 8);
        *(s16 *)&sp28[0x04] = (s16)(arg1->unk17 << 8);
        *(s16 *)&sp28[0x06] = 0;
        *(f32 *)&sp28[0x08] = 0.0f;
        *(f32 *)&sp28[0x0C] = 0.0f;
        *(f32 *)&sp28[0x10] = 0.0f;
        sp28[0x14] = arg1->unkD;
        sp28[0x15] = arg1->unkE;
        sp28[0x16] = arg1->unkF;
        sp28[0x17] = arg1->unk13;
        *(s16 *)&sp28[0x18] = 0x61;
        *(s16 *)&sp28[0x1A] = (s16)(arg1->unk15 * 4);
        *(s16 *)&sp28[0x1C] = (s16)(arg1->unk15 * 4);
        sp28[0x1E] = -1;
        racer->unk4 = camlightAdd(arg0, (s8 *)sp28, arg1);
    }
    racer->unkC = 0;
    racer->unk8 = arg1->unk18;
    racer->unkE = (s16)arg1->unk1A;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o123/overlay_123/spinlightInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void spinlightControl(Object *arg0, s32 arg1) {
    SpinlightRacer *racer;
    s16 period;
    s32 temp_lo;
    u8 temp_v0;

    racer = (SpinlightRacer *)arg0->racer;
    racer->unkC = (s16)(racer->unkC + arg1);
    period = racer->unkE;
    while (racer->unkC >= period) {
        racer->unkC = (s16)(racer->unkC - period);
    }
    arg0->segment.trans.y_rotation = (s16)(racer->unk9 << 8);
    arg0->segment.trans.x_rotation = (s16)(racer->unkA << 8);
    temp_lo = ((s32)racer->unkC << 16) / racer->unkE;
    temp_v0 = racer->unk8;
    switch (temp_v0) {
    case 1:
        arg0->segment.trans.y_rotation =
            (s16)(arg0->segment.trans.y_rotation + (s32)(16384.0f * Sinf((s16)temp_lo)));
        break;
    case 2:
        arg0->segment.trans.y_rotation =
            (s16)(arg0->segment.trans.y_rotation + (s32)(8192.0f * Sinf((s16)temp_lo)));
        break;
    case 3:
        arg0->segment.trans.x_rotation =
            (s16)(arg0->segment.trans.x_rotation + (s32)(16384.0f * Sinf((s16)temp_lo)));
        break;
    case 4:
        arg0->segment.trans.x_rotation =
            (s16)(arg0->segment.trans.x_rotation + (s32)(8192.0f * Sinf((s16)temp_lo)));
        break;
    default:
        arg0->segment.trans.y_rotation = (s16)(arg0->segment.trans.y_rotation + temp_lo);
        break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o123/overlay_123/spinlightControl.s")
#endif
