#include "common.h"

/* decomp: externs */
#ifdef NON_MATCHING
typedef struct Obj139 {
    /* 0x00 */ u8 pad00[0xC];
    /* 0x0C */ f32 unkC;        /* x */
    /* 0x10 */ u8 pad10[0x4];
    /* 0x14 */ f32 unk14;       /* z */
    /* 0x18 */ u8 pad18[0x30];
    /* 0x48 */ s16 unk48;       /* object type */
    /* 0x4A */ u8 pad4A[0x1E];
    /* 0x68 */ void *unk68;     /* per-type state */
    /* 0x6C */ u8 pad6C[0x34];
    /* 0xA0 */ u8 unkA0;        /* nonzero = not a candidate */
} Obj139;

extern s32 __MODULE00139;
extern s32 SquadsModuleFlags;
extern void *D_overlay_139_08B003F0[32];  /* food object list */
extern s32 D_overlay_139_08B00470;        /* food object count */

void **objGetObjList(s32 *, s32 *);
void runlinkSetDestructTimer(s32, s32, s32); /* asm passes 3 args */
s32 IsPointInRegionIdx(f32 x, f32 z, s32 region);
f32 GetRangeSquared2D(f32 x0, f32 z0, f32 x1, f32 z1);
void squadsMakeFoodList(void);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void _AutoInit00139(void) {
    squadsMakeFoodList();
    SquadsModuleFlags |= 4;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o139/overlay_139/_AutoInit00139.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void squadsMakeFoodList(void) {
    s32 start;
    s32 end;
    s32 i;
    s32 include;
    s32 count;
    void **list;
    Obj139 *obj;
    u8 *state;

    list = objGetObjList(&start, &end);
    runlinkSetDestructTimer(__MODULE00139, 2, 2);
    D_overlay_139_08B00470 = 0;

    if (start < end) {
        for (i = start; i != end; i++) {
            obj = (Obj139 *)list[i];
            if (obj->unkA0 != 0) {
                continue;
            }
            include = 0;
            switch (obj->unk48) {
                case 0x18:
                    state = (u8 *)obj->unk68;
                    if ((state[2] & 1) || (*(s16 *)(state + 0xA6) <= 0)) {
                        include = 1;
                    }
                    break;
                case 0x40:
                    state = (u8 *)obj->unk68;
                    if (state[0x17] == 0 || state[0x17] == 2) {
                        include = 1;
                    }
                    break;
                case 0x4D:
                    include = 1;
                    break;
            }
            if (include != 0) {
                count = D_overlay_139_08B00470;
                D_overlay_139_08B003F0[count] = obj;
                D_overlay_139_08B00470 = count + 1;
                if (count + 1 >= 0x20) {
                    break;
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o139/overlay_139/squadsMakeFoodList.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *squadsGetClosestFood(s16 arg0, s16 arg1, s32 arg2, s32 arg3) {
    s32 best = 0x7FFFFFFF;
    s32 range2 = arg2 * arg2;
    void *result = NULL;
    s32 i;
    s32 dist;
    Obj139 *obj;

    for (i = 0; i < D_overlay_139_08B00470; i++) {
        obj = (Obj139 *)D_overlay_139_08B003F0[i];
        dist = (s32)GetRangeSquared2D((f32)arg0, (f32)arg1, obj->unkC, obj->unk14);
        if (dist < range2) {
            if (arg3 == 0 || IsPointInRegionIdx(obj->unkC, obj->unk14, arg3) != 0) {
                if (dist < best) {
                    best = dist;
                    result = obj;
                }
            }
        }
    }
    return result;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o139/overlay_139/squadsGetClosestFood.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 squadsIsFoodAvailable(s32 arg0) {
    s32 i;
    Obj139 *obj;

    for (i = 0; i < D_overlay_139_08B00470; i++) {
        obj = (Obj139 *)D_overlay_139_08B003F0[i];
        if (IsPointInRegionIdx(obj->unkC, obj->unk14, arg0) != 0) {
            return 1;
        }
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o139/overlay_139/squadsIsFoodAvailable.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 squadsIsObjectEdible(s32 arg0) {
    s32 i;

    for (i = 0; i < D_overlay_139_08B00470; i++) {
        if (arg0 == (s32)D_overlay_139_08B003F0[i]) {
            return 1;
        }
    }
    return 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o139/overlay_139/squadsIsObjectEdible.s")
#endif
