#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
void lightDefaultObjectLight(s32 arg0, s32 arg1, s16 arg2, s16 arg3, s32 arg4);
void hitInit(void);
void resetVars(void);
void objInitExplosions(void);
s32 piRomGetFileSize(s32 arg0);
void func_overlay_34_022002C8_1F54D90(void *arg0, s32 arg1);
extern MemoryPoolSlot *objregion;
extern Object **deletelist;
extern MemoryPoolSlot *playerlist;
extern s32 *animplayerlist;
extern u16 *objindex;
extern s32 objindex_max;
extern u32 *RomTab;
extern s32 MaxTypes;
extern MemoryPoolSlot **objdeflist;
extern u16 *objdefno;
extern MemoryPoolSlot *objTempBuf;
extern s32 objTempBufSize;
extern Object **NoAddObjList;
extern f32 obj_olddt;
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void objInitObjects(void) {
    s32 t;
    s32 k;
    s32 v1;

    lightDefaultObjectLight(0xAA, 0x55, 0, -0x2000, 0);
    objregion = mmAllocRegion(0x19000, 0x200);
    deletelist = (Object **)mmAlloc(0x320, 0xFFFF);
    hitInit();
    playerlist = mmAlloc(0x10, 0xFFFF);
    animplayerlist = (s32 *)mmAlloc(0x40, 0xFFFF);
    objindex = (u16 *)piRomLoad(0x30);
    objindex_max = (piRomGetFileSize(0x30) >> 1) - 1;
    if (objindex[objindex_max] == 0) {
        /* loop walks down to the last non-zero objindex entry */
        t = objindex_max - 1;
        do {
            objindex_max = t;
            v1 = t;
            t = v1 - 1;
        } while (objindex[v1] == 0);
    }
    objTempBufSize = 0x2000;
    objTempBuf = mmAlloc(0x2000, 0xFFFF);
    RomTab = piRomLoad(0x2E);
    MaxTypes = 0;
    v1 = 0;
    if (RomTab[0] != -1) {
        k = 1;
        do {
            MaxTypes = k;
            v1 = k;
            k = v1 + 1;
        } while (RomTab[v1] != -1);
    }
    MaxTypes = v1 - 1;
    objdeflist = (MemoryPoolSlot **)mmAlloc(MaxTypes * 4, -1);
    objdefno = (u16 *)mmAlloc(MaxTypes * 2, -1);
    if (MaxTypes > 0) {
        for (k = 0; k < MaxTypes; k++) {
            objdefno[k] = 0;
        }
    }
    Ftables = (s32 *)piRomLoad(0x18);
    Findex = (s32 *)piRomLoad(0x19);
    Fmax = 0;
    if (Findex[0] != -1) {
        k = 1;
        do {
            Fmax = k;
            v1 = k;
            k = v1 + 1;
        } while (Findex[v1] != -1);
    }
    func_overlay_34_022002C8_1F54D90(&Ftables[Findex[5]], (Findex[6] - Findex[5]) * 4);
    ObjList = (Object **)mmAlloc(0x800, 0xFFFF);
    NoAddObjList = (Object **)mmAlloc(0x100, 0xFFFF);
    obj_olddt = 2.0f;
    resetVars();
    objInitExplosions();
    runlinkFreeCode(0x21);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o34/overlay_34/objInitObjects.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
/* Per 4-byte group: 2-bit fields of the 4 input bytes are regrouped into 4 bytes,
   then each byte has its 0x55 and 0xAA bit pairs swapped. */
void func_overlay_34_022002C8_1F54D90(void *arg0, s32 arg1) {
    u8 *p = arg0;
    s32 n = arg1 >> 2;
    s32 i;

    for (i = 0; i < n; i++) {
        u8 b0 = p[0];
        u8 b1 = p[1];
        u8 b2 = p[2];
        u8 b3 = p[3];
        u8 s0 = ((b3 & 0xC0) >> 6) | (b0 & 0xC0) | ((b1 & 0xC0) >> 2) | ((b2 & 0xC0) >> 4);
        u8 s1 = ((b3 & 0x30) >> 4) | ((b0 & 0x30) << 2) | (b1 & 0x30) | ((b2 & 0x30) >> 2);
        u8 s2 = ((b3 & 0x0C) >> 2) | ((b0 & 0x0C) << 4) | ((b1 & 0x0C) << 2) | (b2 & 0x0C);
        u8 s3 = (b3 & 0x03) | (b0 << 6) | ((b1 & 0x03) << 4) | ((b2 & 0x03) << 2);
        p[0] = ((s0 & 0x55) << 1) | ((s0 & 0xAA) >> 1);
        p[1] = ((s1 & 0x55) << 1) | ((s1 & 0xAA) >> 1);
        p[2] = ((s2 & 0x55) << 1) | ((s2 & 0xAA) >> 1);
        p[3] = ((s3 & 0x55) << 1) | ((s3 & 0xAA) >> 1);
        p += 4;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o34/overlay_34/func_overlay_34_022002C8_1F54D90.s")
#endif
