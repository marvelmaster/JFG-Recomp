#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern void *exceptionList;
extern s32 numexceptions;
void *trackGetTrack(void);
s32 trackGetCubeBlockList(s32 *blockList, s16 minX, s16 minY, s16 minZ, s16 maxX, s16 maxY, s16 maxZ);
void func_overlay_110_06E00054_1FC0E04(s16 x, s16 y, s16 z, s16 dx, s16 dy, s16 dz);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void markerboxInit(void *arg0, void *arg1, s32 arg2) {
    if (*(s16 *)((u8 *)arg0 + 0x4A) == 0x1C8) {
        func_overlay_110_06E00054_1FC0E04(
            *(s16 *)((u8 *)arg1 + 0x4),
            *(s16 *)((u8 *)arg1 + 0x6),
            *(s16 *)((u8 *)arg1 + 0x8),
            *(s16 *)((u8 *)arg1 + 0xA),
            *(s16 *)((u8 *)arg1 + 0xC),
            *(s16 *)((u8 *)arg1 + 0xE));
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o110/overlay_110/markerboxInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_110_06E00054_1FC0E04(s16 x, s16 y, s16 z, s16 dx, s16 dy, s16 dz) {
    s32 blockList[35];
    s32 minX;
    s32 minY;
    s32 minZ;
    s32 maxX;
    s32 maxY;
    s32 maxZ;
    s32 count;
    s32 i;
    s32 j;
    s16 vertCount;
    s16 vx;
    s16 vy;
    s16 vz;
    u8 *track;
    u8 *block;
    u8 *vert;
    u8 *entry;

    minX = x - dx;
    maxX = x + dx;
    minY = y - dy;
    maxY = y + dy;
    minZ = z - dz;
    maxZ = z + dz;

    count = trackGetCubeBlockList(blockList, minX, minY, minZ, maxX, maxY, maxZ);
    if (count != 0) {
        if (exceptionList == NULL) {
            exceptionList = mmAlloc(0x400, 0xFFFF);
            numexceptions = 0;
        }
        if (exceptionList != NULL) {
            track = trackGetTrack();
            if (track != NULL && count > 0) {
                for (i = 0; i < count && numexceptions < 0x80; i++) {
                    block = *(u8 **)(track + 4) + blockList[i] * 0x48;
                    vertCount = *(s16 *)(block + 0x24);
                    vert = *(u8 **)block;
                    for (j = 0; j < vertCount && numexceptions < 0x80; j++) {
                        vx = *(s16 *)(vert + 0);
                        vy = *(s16 *)(vert + 2);
                        vz = *(s16 *)(vert + 4);
                        if (vx >= minX && vx <= maxX && vy >= minY && vy <= maxY && vz >= minZ && vz <= maxZ) {
                            entry = (u8 *)exceptionList + numexceptions * 8;
                            *(u8 **)entry = vert + 6;
                            *(s16 *)(entry + 4) = *(s16 *)(vert + 6);
                            *(s16 *)(entry + 6) = *(s16 *)(vert + 8);
                            numexceptions++;
                        }
                        vert += 0xA;
                    }
                }
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o110/overlay_110/func_overlay_110_06E00054_1FC0E04.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void trackFadeExceptions(void) {
    s32 i;
    u8 *entry;

    if (exceptionList != NULL && numexceptions != 0) {
        for (i = 0; i < numexceptions; i++) {
            entry = (u8 *)exceptionList + i * 8;
            *(s16 *)(*(u8 **)entry) = *(s16 *)(entry + 4);
            *(s16 *)(*(u8 **)entry + 2) = *(s16 *)(entry + 6);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o110/overlay_110/trackFadeExceptions.s")
#endif
