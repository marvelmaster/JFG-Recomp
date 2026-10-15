#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern f32 D_overlay_77_04D00858;     /* blastdoor scale factor */
extern f32 D_overlay_77_04D0085C;     /* open/close damping (state 3) */
extern f32 D_overlay_77_04D00860;     /* open/close damping (state 2) */
void *objGetObjList(s32 *arg0, s32 *arg1);
void *mainGetGameCharacter(s32 arg0, s32 arg1);
s32 mainGetNextCharacter(void);
void hitInitObjectHit(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6, f32 arg7, f32 arg8, f32 arg9, f32 arg10, s32 arg11);
f32 Powerf(f32 arg0, s32 arg1);
f32 Sinf(s16 arg0);
#endif

/*
 * Blastdoor object layout (raw offsets, see note on each use):
 *   obj + 0x08 : f32 scale
 *   obj + 0x0C : f32 x_position
 *   obj + 0x14 : f32 z_position
 *   obj + 0x39 : u8  colour/alpha index
 *   obj + 0x48 : s16 behaviorId (0x81 = blastdoor)
 *   obj + 0x4C : ptr to hit block (u16 flags at +0x0A, bit 0 = active)
 *   obj + 0x68 : ptr to state block (see below)
 *   obj + 0x6C : ptr to display-list block (+4 / +8 are DL ptrs)
 * State block (obj->0x68):
 *   +0x00 u8 door id, +0x01 u8 state (0 closed-ish, 1 open, 2 closing, 3 opening),
 *   +0x02 u8 colour, +0x03 u8 unk, +0x04 f32 height, +0x08 f32 target open,
 *   +0x0C f32 target closed, +0x10 f32 position, +0x14 f32 velocity
 */

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void blastdoorStatus(s32 arg0, s32 arg1) {
    void **list;
    s32 start;
    s32 total;
    s32 count;
    s32 i;
    u8 *obj;
    u8 *st;

    list = (void **) objGetObjList(&start, &total);
    count = total - start;
    for (i = 0; i < count; i++) {
        obj = (u8 *) list[start + i];
        if (*(s16 *) (obj + 0x48) != 0x81) {
            continue;
        }
        st = *(u8 **) (obj + 0x68);
        if (arg0 != st[0]) {
            continue;
        }
        if (arg1 == 1) {
            if (st[1] == 2 || st[1] == 0) {
                st[1] = 3;
            }
        } else {
            if (st[1] == 3 || st[1] == 1) {
                st[1] = 2;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o77/overlay_77/blastdoorStatus.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 blastdoorOpen(s32 arg0) {
    u8 *lvl;
    u8 *ch;

    lvl = (u8 *) levelGetLevel();
    ch = (u8 *) mainGetGameCharacter(0, mainGetNextCharacter());
    switch (arg0) {
    case 2:
        return *(lvl + 0x107) != 0;
    case 3:
        return *(lvl + 0x107) == 0;
    case 4:
        return (*(u16 *) (ch + 4) & 0x1F) == 0;
    case 5:
        return (*(u16 *) (ch + 4) & 0x1F) == 1;
    case 6:
        return (*(u16 *) (ch + 4) & 0x1F) == 2;
    case 1:
        return 1;
    default:
        return 0;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o77/overlay_77/blastdoorOpen.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void blastdoorInit(void *arg0, void *arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *def = (u8 *) arg1;
    u8 *st;
    f32 rate;
    f32 scaled;

    st = *(u8 **) (obj + 0x68);
    st[0] = def[0x0A];
    *(s16 *) (obj + 0x00) = (s16) (def[0x0B] << 8);
    *(f32 *) (obj + 0x08) = (f32) (*(s16 *) (def + 0x0C)) * D_overlay_77_04D00858;
    st[2] = def[0x0E];
    st[3] = def[0x0F];
    *(f32 *) (st + 0x04) = (f32) (def[0x11] * 4);
    rate = *(f32 *) (st + 0x04);
    *(f32 *) (st + 0x08) = rate / (f32) (def[0x12] * 6);
    *(f32 *) (st + 0x0C) = -rate / (f32) (def[0x13] * 6);

    if (blastdoorOpen(def[0x10]) != 0) {
        st[1] = 1;
        *(f32 *) (st + 0x10) = *(f32 *) (st + 0x04);
    } else {
        st[1] = 0;
        *(f32 *) (st + 0x10) = 0.0f;
    }
    *(f32 *) (st + 0x14) = 0.0f;

    scaled = *(f32 *) (obj + 0x08) * 32.0f;
    hitInitObjectHit(arg0, -1, 0, 8, 0, 0, 0, scaled, scaled, -1.0f, 1.0f, 1);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o77/overlay_77/blastdoorInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void blastdoorControl(void *arg0, s32 arg1) {
    u8 *obj = (u8 *) arg0;
    u8 *st = *(u8 **) (obj + 0x68);
    u8 *hit = *(u8 **) (obj + 0x4C);
    f32 cur;

    switch (st[1]) {
    case 0:
        *(u16 *) (hit + 0x0A) = *(u16 *) (hit + 0x0A) | 1;
        break;
    case 1:
        *(u16 *) (hit + 0x0A) = *(u16 *) (hit + 0x0A) & 0xFFFE;
        break;
    case 2:
        cur = *(f32 *) (st + 0x14);
        *(f32 *) (st + 0x14) = cur + ((*(f32 *) (st + 0x0C) - cur) * (1.0f - Powerf(D_overlay_77_04D00860, arg1)));
        *(f32 *) (st + 0x10) = *(f32 *) (st + 0x10) + (*(f32 *) (st + 0x14) * (f32) arg1);
        if (*(f32 *) (st + 0x10) <= 0.0f) {
            *(f32 *) (st + 0x10) = 0.0f;
            *(f32 *) (st + 0x14) = 0.0f;
            st[1] = 0;
            *(u16 *) (hit + 0x0A) = *(u16 *) (hit + 0x0A) | 1;
        }
        break;
    case 3:
        *(u16 *) (hit + 0x0A) = *(u16 *) (hit + 0x0A) & 0xFFFE;
        cur = *(f32 *) (st + 0x14);
        *(f32 *) (st + 0x14) = cur + ((*(f32 *) (st + 0x08) - cur) * (1.0f - Powerf(D_overlay_77_04D0085C, arg1)));
        *(f32 *) (st + 0x10) = *(f32 *) (st + 0x10) + (*(f32 *) (st + 0x14) * (f32) arg1);
        if (*(f32 *) (st + 0x04) <= *(f32 *) (st + 0x10)) {
            *(f32 *) (st + 0x10) = *(f32 *) (st + 0x04);
            st[1] = 1;
            *(f32 *) (st + 0x14) = 0.0f;
        }
        break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o77/overlay_77/blastdoorControl.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void blastdoorDraw(Gfx **arg0, MatrixS **arg1, s32 arg2, ObjectTransform *arg3) {
    u8 *obj = (u8 *) arg3;
    u8 *st;
    u8 *blk;
    u8 *t0;
    u8 *t1;
    f32 x;
    f32 z;
    f32 sinOff;
    f32 cosOff;
    f32 dx;
    u8 col;

    st = *(u8 **) (obj + 0x68);
    x = *(f32 *) (obj + 0x0C);
    z = *(f32 *) (obj + 0x14);
    sinOff = Sinf(*(s16 *) obj) * *(f32 *) (st + 0x10);
    cosOff = Cosf((s32) *(s16 *) obj);
    col = st[2];

    /* first half: door offset to one side */
    (*arg0)->words.w0 = 0xE7000000;
    (*arg0)->words.w1 = 0;
    (*arg0)++;
    (*arg0)->words.w0 = 0xFA000000;
    (*arg0)->words.w1 = (col << 0x18) | (col << 0x10) | (col << 8) | obj[0x39];
    (*arg0)++;

    dx = cosOff * *(f32 *) (st + 0x10);
    *(f32 *) (obj + 0x0C) = x - dx;
    *(f32 *) (obj + 0x14) = z + sinOff;

    blk = *(u8 **) (obj + 0x6C);
    t0 = *(u8 **) (blk + 0x04);
    (*arg0)->words.w0 = 0xBF000000;
    (*arg0)->words.w1 = *(u32 *) (t0 + 0x04) + 0x80000000;
    (*arg0)++;
    camPushModelMtx(arg0, arg1, arg3, 1.0f, 0.0f);
    if (obj[0x39] == 0xFF) {
        (*arg0)->words.w0 = 0x06000000;
        (*arg0)->words.w1 = *(u32 *) (*(u8 **) t0 + 0x74) + 0x80000000;
    } else {
        (*arg0)->words.w0 = 0x06000000;
        (*arg0)->words.w1 = *(u32 *) (*(u8 **) t0 + 0x78) + 0x80000000;
    }
    (*arg0)++;

    /* second half: mirrored offset */
    *(f32 *) (obj + 0x0C) = x + dx;
    *(f32 *) (obj + 0x14) = z - sinOff;

    t1 = *(u8 **) (blk + 0x08);
    (*arg0)->words.w0 = 0xBF000000;
    (*arg0)->words.w1 = *(u32 *) (t1 + 0x04) + 0x80000000;
    (*arg0)++;
    camPushModelMtx(arg0, arg1, arg3, 1.0f, 0.0f);
    if (obj[0x39] == 0xFF) {
        (*arg0)->words.w0 = 0x06000000;
        (*arg0)->words.w1 = *(u32 *) (*(u8 **) t1 + 0x74) + 0x80000000;
    } else {
        (*arg0)->words.w0 = 0x06000000;
        (*arg0)->words.w1 = *(u32 *) (*(u8 **) t1 + 0x78) + 0x80000000;
    }
    (*arg0)++;

    (*arg0)->words.w1 = 0;
    (*arg0)->words.w0 = 0xBF000000;
    (*arg0)++;
    camRestoreModelMtx(arg0);

    (*arg0)->words.w1 = -1U;
    (*arg0)->words.w0 = 0xFA000000;
    (*arg0)++;
    texDPInit(arg0);

    *(f32 *) (obj + 0x0C) = x;
    *(f32 *) (obj + 0x14) = z;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o77/overlay_77/blastdoorDraw.s")
#endif
