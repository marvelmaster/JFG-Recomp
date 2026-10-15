#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern s8 beamScrollFlag;
extern MemoryPoolSlot *generalBuffer;
extern s32 globflags;
extern LevelHeader *level;
extern s32 nohitsflag;
extern s32 skyflags;
extern s32 skyframe;
extern s32 track;
extern s32 trackwaveanim;
extern s32 watereffectframe;
extern TextureHeader *watereffecttexture;
void func_overlay_24_018001F8_1F41D28(s32 arg0, s32 arg1, LevelHeader **arg2);
void animseqLoadLevelData(s32 arg0);
void camSetMode(s32 arg0);
void initSky(s32 arg0);
void modelSetModelFlags(s32 arg0);
void objLoadObjList(s32 arg0, s32 arg1);
void objSetupPlayers(s32 arg0);
void realReflectSurfaces(s32 arg0);
void shadowChangeBuffer(void);
void shadowGenerate(s32 arg0, s32 arg1);
void shadowInitBuffers(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern MemoryPoolSlot *PLgrps;
extern MemoryPoolSlot *PLlist;
extern MemoryPoolSlot *PLpolys;
extern s32 PLno;
extern MemoryPoolSlot *TrackMem;
extern MemoryPoolSlot *trackEdges;
extern u32 *D_overlay_24_01801990;
extern s32 numtexturescrolls;
extern s8 cpuTraceTrackBufStatus;
void func_overlay_24_01800908_1F42438(void *arg0, void *arg1, void *arg2);
s32 func_overlay_24_01800CE4_1F42814(void *arg0);
s32 func_overlay_24_018016E0_1F43210(void *arg0, s32 arg1, void *arg2, void *arg3);
void func_overlay_24_018018B4_1F433E4(void *arg0);
void mathBreakPoint(void);
s32 osCartDmaTest3_6105(void);
void trackLightAllocate(u8 arg0, u8 arg1);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void trackInit(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    LevelHeader *temp_v0;

    generalBuffer = mmAlloc(0x800, 0xFFFFU);
    temp_v0 = levelGetLevel();
    level = temp_v0;
    nohitsflag = 0;
    if (temp_v0->unk6C == 1 || temp_v0->unk6C == 2) {
        nohitsflag = 1;
    }
    func_overlay_24_018001F8_1F41D28(arg0, 1, &level);
    trackwaveanim = 0;
    camSetMode(mainGetNumberOfCameras() - 1);
    objLoadObjList(arg4, 0);
    objLoadObjList(arg3, 1);
    animseqLoadLevelData(arg5);
    objSetupPlayers(arg2);
    globflags = 0;
    shadowInitBuffers(track, trackwaveanim, 0x1F4, 0xC8, 0x64);
    shadowGenerate(2, 0);
    shadowGenerate(1, 0);
    shadowChangeBuffer();
    shadowGenerate(2, 0);
    shadowGenerate(1, 0);
    shadowChangeBuffer();
    if (*(u8 *) ((u8 *) level + 0x68) == 0) {
        modelSetModelFlags(0);
    }
    initSky(arg1);
    if (*(u8 *) ((u8 *) level + 0x68) == 0) {
        modelSetModelFlags(8);
    }
    skyframe = 0;
    skyflags = 0x10000;
    if (*(s16 *) ((u8 *) level + 0x88) != -1) {
        watereffecttexture = texLoadTexture((s32) *(s16 *) ((u8 *) level + 0x88));
        watereffectframe = 0;
    }
    beamScrollFlag = 0;
    if (*(s8 *) ((u8 *) level + 0xF2) != 0) {
        realReflectSurfaces(track);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o24/overlay_24/trackInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Track block loader. Sets up the track pools, reads the track block from ROM (table
// D_overlay_24_01801990, -1 terminated, entry = {start, end} offsets), decompresses it to
// the top of the track buffer, relocates its internal pointers, builds the 0x48-byte
// segment records (cf. docs/levels.md: 0x48-byte segments, 10-byte vertices, 8-byte
// texture records), shrinks the track allocation to the used size and loads the textures.
// The asm only reads arg0; arg1/arg2 are passed by trackInit and unused.
void func_overlay_24_018001F8_1F41D28(s32 arg0, s32 arg1, LevelHeader **arg2) {
    u32 *romTable;
    u32 *romEntry;
    u8 *trk;
    u8 *segs;
    u8 *bounds;
    u8 *seg;
    u8 *pool;
    u8 *aligned;
    u8 *blk;
    u8 *data;
    u8 *vtx;
    u8 *dst;
    u8 *zeroDst;
    s32 romCount;
    s32 romIdx;
    s32 romStart;
    s32 romSize;
    s32 bufAddr;
    s32 segCount;
    s32 i;
    s32 k;
    s32 off;
    s32 boundsOff;
    s32 n;
    s32 bytes;
    s32 usedSize;
    s32 delay;

    setTexMemColour(0xFF00FF);
    PLlist = mmAlloc(*(s16 *) ((u8 *) level + 0xEA) * 4, 0xFFFF00FFU);
    PLgrps = mmAlloc(*(s16 *) ((u8 *) level + 0xEA) * 2, 0xFFFF00FFU);
    PLpolys = mmAlloc(*(s16 *) ((u8 *) level + 0xEA) * 2, 0xFFFF00FFU);
    trackEdges = mmAlloc(*(s16 *) ((u8 *) level + 0xEC) * 0x30, 0xFFFF00FFU);
    PLno = 0;
    TrackMem = mmAlloc(0x9F000, 0xFFFF00FFU);
    track = (s32) TrackMem;
    if (TrackMem == NULL) {
        mathBreakPoint();
    }
    mainPreNMI();
    romTable = piRomLoad(0x24);
    D_overlay_24_01801990 = romTable;
    romCount = 0;
    while (romTable[romCount] != 0xFFFFFFFFU) {
        romCount++;
    }
    romIdx = arg0;
    if (arg0 >= romCount - 1) {
        romIdx = 0;
    }
    romEntry = &romTable[romIdx];
    romStart = romEntry[0];
    romSize = romEntry[1] - romStart;
    // decompression buffer sits at the top of the track pool, 16-byte aligned (rounded toward zero)
    bufAddr = track - romSize + 0x9F000;
    bufAddr -= bufAddr % 16;
    mainPreNMI();
    piRomLoadSection(0x25U, bufAddr, romStart, romSize);
    rzipUncompress((u8 *) bufAddr, (u8 *) track);
    mmFree(D_overlay_24_01801990);
    mainPreNMI();

    // relocate the track header's internal pointers (offsets -> addresses)
    trk = (u8 *) track;
    *(s32 *) (trk + 0x00) += track;
    *(s32 *) (trk + 0x04) += track;
    *(s32 *) (trk + 0x08) += track;
    *(s32 *) (trk + 0x0C) += track;
    *(s32 *) (trk + 0x10) += track;
    *(s32 *) (trk + 0x14) += track;

    // relocate pointers in each 0x48-byte segment record
    segCount = *(s16 *) (trk + 0x1A);
    segs = *(u8 **) (trk + 0x04);
    for (i = 0, off = 0; i < segCount; i++, off += 0x48) {
        seg = segs + off;
        *(s32 *) (seg + 0x00) += track;
        *(s32 *) (seg + 0x04) += track;
        *(s32 *) (seg + 0x0C) += track;
        *(s32 *) (seg + 0x18) += track;
    }

    // per segment: carve its mask arrays / collision data out of the free area at track+0x2C
    bounds = *(u8 **) (trk + 0x08);
    pool = trk + *(s32 *) (trk + 0x2C);
    for (i = 0, off = 0, boundsOff = 0; i < segCount; i++, off += 0x48, boundsOff += 0xC) {
        seg = segs + off;
        aligned = mmAlign4(pool);
        *(u8 **) (seg + 0x10) = aligned;
        pool = aligned + *(s16 *) (seg + 0x26) * 4;
        *(u8 **) (seg + 0x14) = pool;
        func_overlay_24_01800908_1F42438(seg, bounds + boundsOff, (void *) i);
        pool += *(s16 *) (seg + 0x26);
        *(u8 **) (seg + 0x20) = pool;
        aligned = mmAlign16(pool + *(s16 *) (seg + 0x26));
        *(u8 **) (seg + 0x1C) = aligned;
        pool = mmAlign4(aligned + func_overlay_24_01800CE4_1F42814(seg) * 0x10);
        *(s16 *) (seg + 0x3C) = 0;
        *(u8 **) (seg + 0x40) = pool;
        func_overlay_24_018018B4_1F433E4(seg);
        pool += *(s16 *) (seg + 0x3E) * 2;
    }

    // with the cart DMA test passing as 0, store the record index in each texture record
    if (osCartDmaTest3_6105() == 0) {
        data = *(u8 **) (trk + 0x00);
        for (i = 0; i < *(s16 *) (trk + 0x18); i++) {
            *(s32 *) (data + i * 8) = i;
        }
    }

    // shrink the track allocation down to the used part, then re-place it
    usedSize = (s32) (pool - trk);
    mainPreNMI();
    delay = mmGetDelay();
    mmSetDelay(0);
    mmFree(TrackMem);
    mmAllocAtAddr(usedSize, (u8 *) TrackMem, 0xFFFF00FFU);
    mmSetDelay(delay);
    mainPreNMI();

    // load each texture record's texture
    data = *(u8 **) (trk + 0x00);
    for (i = 0; i < *(s16 *) (trk + 0x18); i++) {
        *(s32 *) (data + i * 8) = (s32) texLoadTexture(*(s32 *) (data + i * 8) | 0x8000);
    }

    // per segment: allocate the 0x7F7F7FFF block for the per-vertex data
    mainPreNMI();
    segCount = *(s16 *) (trk + 0x1A);
    segs = *(u8 **) (trk + 0x04);
    for (i = 0, off = 0; i < segCount; i++, off += 0x48) {
        seg = segs + off;
        n = *(s16 *) (seg + 0x24);
        bytes = (((n + 15) >> 4) * 2) + n * 3 + 8;
        blk = (u8 *) mmAlloc(bytes, 0x7F7F7FFF);
        if (blk != NULL) {
            *(u8 **) (seg + 0x34) = blk;
            zeroDst = blk + 8;
            dst = blk + (((n + 15) >> 4) * 2) + 8;
            *(u8 **) (blk + 0x00) = dst;
            *(u8 **) (blk + 0x04) = zeroDst;
            vtx = *(u8 **) (seg + 0x00);
            // 3 bytes (vertex bytes 6..8, 10-byte stride) per vertex
            for (k = 0; k < n; k++) {
                dst[k * 3 + 0] = vtx[k * 10 + 6];
                dst[k * 3 + 1] = vtx[k * 10 + 7];
                dst[k * 3 + 2] = vtx[k * 10 + 8];
            }
            // (n + 15) / 16 halfwords cleared at the start of the block
            for (k = 0; k < ((n + 15) >> 4); k++) {
                *(s16 *) (zeroDst + k * 2) = 0;
            }
            *(u8 *) (seg + 0x32) = 0;
        }
    }

    mainPreNMI();
    setTexMemColour(0xFF00FFFF);
    numtexturescrolls = 0;
    trackLightAllocate(*(u8 *) ((u8 *) level + 0x105), *(u8 *) ((u8 *) level + 0x106));
    cpuTraceTrackBufStatus = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o24/overlay_24/func_overlay_24_018001F8_1F41D28.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Per time-entry (table at obj+0x4, 0x10 bytes each): builds bounding-box cell masks
// for each entry in [rec->lo, rec->hi) from the 3 triangle vertices (vertex table at obj+0x0,
// 10-byte stride, group offset rec->0x6). Outputs: s32 mask array at obj+0x10 and u8 mask
// array at obj+0x14, both indexed by entry number.
void func_overlay_24_01800908_1F42438(void *arg0, void *arg1, void *arg2) {
    u8 *obj = (u8 *) arg0;
    s16 *bounds = (s16 *) arg1;
    u8 *recs;
    u8 *table;
    u8 *verts;
    u8 *rec;
    u8 *entry;
    s16 *vtx;
    s32 count;
    s32 i;
    s32 k;
    s32 v;
    s32 lo;
    s32 hi;
    s32 grp;
    s32 minX, maxX, minY, maxY, minZ, maxZ;
    s32 x, y, z;
    s32 step;
    s32 cur;
    s32 edge;
    s32 bit;
    s32 mask;
    u8 yMask;

    count = *(s16 *) (obj + 0x28);
    recs = *(u8 **) (obj + 0xC);
    table = *(u8 **) (obj + 0x4);
    verts = *(u8 **) (obj + 0x0);
    for (i = 0; i < count; i++) {
        rec = recs + i * 0x10;
        lo = *(s16 *) (rec + 0x8);
        hi = *(s16 *) (rec + 0x18);
        grp = *(s16 *) (rec + 0x6);
        for (k = lo; k < hi; k++) {
            entry = table + k * 0x10;
            if (entry[0] & 0x80) {
                *(s32 *) (*(u8 **) (obj + 0x10) + k * 4) = 0;
                (*(u8 **) (obj + 0x14))[k] = 0;
            } else {
                minX = 0x7FBC;
                maxX = -0x7FBC;
                minY = 0x7FBC;
                maxY = -0x7FBC;
                minZ = 0x7FBC;
                maxZ = -0x7FBC;
                for (v = 0; v < 3; v++) {
                    vtx = (s16 *) (verts + ((s32) entry[v + 1] + grp) * 10);
                    x = vtx[0];
                    y = vtx[1];
                    z = vtx[2];
                    if (x < minX) minX = x;
                    if (x > maxX) maxX = x;
                    if (y < minY) minY = y;
                    if (y > maxY) maxY = y;
                    if (z < minZ) minZ = z;
                    if (z > maxZ) maxZ = z;
                }

                mask = 0;
                step = ((s32) (bounds[3] - bounds[0]) >> 4) + 1;
                cur = bounds[0];
                edge = cur + step;
                for (bit = 0; bit < 16; bit++) {
                    if (edge >= minX && maxX >= cur) {
                        mask |= 1 << bit;
                    }
                    edge += step;
                    cur += step;
                }

                step = ((s32) (bounds[5] - bounds[2]) >> 4) + 1;
                cur = bounds[2];
                edge = cur + step;
                for (bit = 0; bit < 16; bit++) {
                    if (edge >= minZ && maxZ >= cur) {
                        mask |= 1 << (16 + bit);
                    }
                    edge += step;
                    cur += step;
                }
                *(s32 *) (*(u8 **) (obj + 0x10) + k * 4) = mask;

                yMask = 0;
                step = ((s32) (bounds[4] - bounds[1]) >> 3) + 1;
                cur = bounds[1];
                edge = cur + step;
                for (bit = 0; bit < 8; bit++) {
                    if (edge >= minY && maxY >= cur) {
                        yMask |= 1 << bit;
                    }
                    edge += step;
                    cur += step;
                }
                (*(u8 **) (obj + 0x14))[k] = yMask;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o24/overlay_24/func_overlay_24_01800908_1F42438.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Track surface builder. Pass 1: for each time entry in each record range (not flagged 0x80)
// computes the unit normal of its triangle (vertices from obj+0x0 via entry bytes 1..3) and
// appends a plane (nx, ny, nz, d) to obj+0x1C, clearing the entry flag byte at obj+0x20.
// Pass 2 (skipped when nohitsflag is set, and for records with flags & 0x880) walks the
// triangle edges against neighbouring triangles (8-byte records at obj+0x18: u16 self,
// u16 nb[3]), updates the entry/flag bytes and appends further planes.
// Returns the number of planes emitted.
// Layout notes (raw offsets, cf. func_overlay_24_01800908): rec+0x18 is read as the range
// end even though records are 0x10 apart (as in the asm).
s32 func_overlay_24_01800CE4_1F42814(void *arg0) {
    u8 *obj = (u8 *) arg0;
    u8 *verts;
    u8 *entries;
    u8 *recs;
    u8 *edges;
    u8 *entryFlags;
    f32 *planes;
    f32 *pl;
    f32 *selfPl;
    f32 *nbPl;
    s16 *va;
    s16 *vb;
    s16 *vc;
    u8 *e;
    u8 *rec;
    s32 count;
    s32 fp;
    s32 fp0;
    s32 i;
    s32 t;
    s32 j;
    s32 k;
    s32 grp;
    s32 lo;
    s32 hi;
    s32 r;
    s32 nb;
    s32 selfIdx;
    s32 vA;
    s32 vB;
    s32 vC;
    f32 ax, ay, az, bx, by, bz, cx, cy, cz;
    f32 ux, uy, uz, vx, vy, vz;
    f32 nx, ny, nz, len, sx, sy, sz;
    f32 selfNx, selfNy, selfNz;
    f32 sumX, sumY, sumZ;
    f32 wX, wY, wZ;
    f32 aX, aY, aZ, nX, nY, nZ;
    f32 qdot, dot, f20, len2;

    verts = *(u8 **) (obj + 0x00);
    entries = *(u8 **) (obj + 0x04);
    recs = *(u8 **) (obj + 0x0C);
    edges = *(u8 **) (obj + 0x18);
    planes = *(f32 **) (obj + 0x1C);
    entryFlags = *(u8 **) (obj + 0x20);
    count = *(s16 *) (obj + 0x28);
    fp = 0;

    /* pass 1: triangle normals and planes */
    for (i = 0; i < count; i++) {
        rec = recs + i * 0x10;
        grp = *(s16 *) (rec + 0x6);
        lo = *(s16 *) (rec + 0x8);
        hi = *(s16 *) (rec + 0x18);
        for (t = lo; t < hi; t++) {
            e = entries + t * 0x10;
            if (e[0] & 0x80) {
                continue;
            }
            va = (s16 *) (verts + (e[1] + grp) * 10);
            vb = (s16 *) (verts + (e[2] + grp) * 10);
            vc = (s16 *) (verts + (e[3] + grp) * 10);
            ax = (f32) va[0]; ay = (f32) va[1]; az = (f32) va[2];
            bx = (f32) vb[0]; by = (f32) vb[1]; bz = (f32) vb[2];
            cx = (f32) vc[0]; cy = (f32) vc[1]; cz = (f32) vc[2];
            ux = bx - ax; uy = by - ay; uz = bz - az;
            vx = cx - bx; vy = cy - by; vz = cz - bz;
            nx = (uy * vz) - (uz * vy);
            ny = (uz * vx) - (ux * vz);
            nz = (ux * vy) - (uy * vx);
            len = sqrtf((nx * nx) + (ny * ny) + (nz * nz));
            sx = nx; sy = ny; sz = nz;
            if (len > 0.0f) {
                sx = nx / len;
                sy = ny / len;
                sz = nz / len;
            }
            entryFlags[t] = 0;
            pl = planes + fp * 4;
            pl[0] = sx;
            pl[1] = sy;
            pl[2] = sz;
            pl[3] = -((ax * sx) + (ay * sy) + (az * sz));
            fp++;
        }
    }
    fp0 = fp;

    if (nohitsflag == 0) {
        /* pass 2: edge adjacency against earlier planes */
        for (i = 0; i < count; i++) {
            rec = recs + i * 0x10;
            grp = *(s16 *) (rec + 0x6);
            lo = *(s16 *) (rec + 0x8);
            hi = *(s16 *) (rec + 0x18);
            if ((*(s32 *) (rec + 0xC) & 0x880) || lo >= hi) {
                continue;
            }
            for (t = lo; t < hi; t++) {
                e = entries + t * 0x10;
                if (e[0] & 0x80) {
                    continue;
                }
                selfIdx = *(u16 *) (edges + t * 8);
                selfPl = planes + selfIdx * 4;
                selfNx = selfPl[0];
                selfNy = selfPl[1];
                selfNz = selfPl[2];
                for (j = 0; j < 3; j++) {
                    vA = e[1 + j] + grp;
                    vB = e[1 + (j + 1) % 3] + grp;
                    vC = e[1 + (j + 2) % 3] + grp;
                    nb = *(u16 *) (edges + t * 8 + 2 + j * 2);
                    if (nb >= fp0) {
                        continue;
                    }

                    if ((e[0] & 1) && (entries[nb * 0x10] & 2)) {
                        r = func_overlay_24_018016E0_1F43210(arg0, nb, verts + vA * 10, verts + vB * 10);
                        e[0] &= 0xFE;
                        entryFlags[nb] |= 1 << (r + 3);
                    } else if (e[0] & 2) {
                        if (entries[nb * 0x10] & 1) {
                            entries[nb * 0x10] &= 0xFE;
                            entryFlags[t] |= 1 << (j + 3);
                        }
                    }

                    nbPl = planes + nb * 4;
                    sumX = nbPl[0] + selfNx;
                    sumY = nbPl[1] + selfNy;
                    sumZ = nbPl[2] + selfNz;

                    va = (s16 *) (verts + vA * 10);
                    vb = (s16 *) (verts + vB * 10);
                    vc = (s16 *) (verts + vC * 10);
                    aX = (f32) va[0]; aY = (f32) va[1]; aZ = (f32) va[2];
                    bx = (f32) vb[0]; by = (f32) vb[1]; bz = (f32) vb[2];
                    ux = bx - aX; uy = by - aY; uz = bz - aZ;
                    wX = ((sumX * 5.0f) + aX) - aX;
                    wY = ((sumY * 5.0f) + aY) - aY;
                    wZ = ((sumZ * 5.0f) + aZ) - aZ;
                    nX = (uy * wZ) - (uz * wY);
                    nY = (uz * wX) - (ux * wZ);
                    nZ = (ux * wY) - (uy * wX);
                    len = sqrtf((nX * nX) + (nY * nY) + (nZ * nZ));
                    if (len > 0.0f) {
                        nX /= len;
                        nY /= len;
                        nZ /= len;
                    }

                    if (nb != selfIdx) {
                        for (k = 0; k < 6; k += 2) {
                            if (*(u16 *) (edges + nb * 8 + 2 + k) == selfIdx) {
                                *(u16 *) (edges + nb * 8 + 2 + k) = (u16) (fp | 0x8000);
                            }
                        }

                        qdot = nbPl[3] + ((((f32) vc[0]) * nbPl[0]) + (((f32) vc[1]) * nbPl[1]) + (((f32) vc[2]) * nbPl[2]));
                        if (qdot < 0.0f) {
                            entryFlags[t] |= 1 << j;
                        }

                        dot = (nbPl[2] * selfNz) + ((selfNx * nbPl[0]) + (selfNy * nbPl[1]));
                        if (dot < 0.0f) {
                            f20 = uy;
                            if (by < aY) {
                                f20 = -uy;
                            }
                            len2 = sqrtf((ux * ux) + (uz * uz));
                            if (f20 <= len2) {
                                e[0] |= 1 << (j + 2);
                            }
                        }
                    } else {
                        entryFlags[t] |= 1 << j;
                    }

                    *(u16 *) (edges + t * 8 + 2 + j * 2) = (u16) fp;
                    pl = planes + fp * 4;
                    pl[0] = nX;
                    pl[1] = nY;
                    pl[2] = nZ;
                    pl[3] = -((aX * nX) + (aY * nY) + (aZ * nZ));
                    fp++;
                }
            }
        }
    }

    return fp;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o24/overlay_24/func_overlay_24_01800CE4_1F42814.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Searches the triangles of record(s) covering time arg1 for an edge equal to (arg2, arg3)
// in either vertex order. Returns the last matching triangle edge index j (0..2), or -1.
s32 func_overlay_24_018016E0_1F43210(void *arg0, s32 arg1, void *arg2, void *arg3) {
    u8 *obj = (u8 *) arg0;
    s16 *p = (s16 *) arg2;
    s16 *q = (s16 *) arg3;
    u8 *recs;
    u8 *table;
    u8 *verts;
    u8 *rec;
    s16 *va;
    s16 *vb;
    s32 result;
    s32 count;
    s32 i;
    s32 j;
    s32 nxt;
    s32 grp;

    result = -1;
    count = *(s16 *) (obj + 0x28);
    recs = *(u8 **) (obj + 0xC);
    table = *(u8 **) (obj + 0x4) + arg1 * 0x10;
    verts = *(u8 **) (obj + 0x0);
    for (i = 0; i < count; i++) {
        rec = recs + i * 0x10;
        if (arg1 < *(s16 *) (rec + 0x8) || arg1 >= *(s16 *) (rec + 0x18)) {
            continue;
        }
        grp = *(s16 *) (rec + 0x6);
        for (j = 0; j < 3; j++) {
            nxt = (j + 1 < 3) ? j + 1 : 0;
            va = (s16 *) (verts + ((s32) table[j + 1] + grp) * 10);
            vb = (s16 *) (verts + ((s32) table[nxt + 1] + grp) * 10);
            if ((p[0] == va[0] && p[1] == va[1] && p[2] == va[2] &&
                 q[0] == vb[0] && q[1] == vb[1] && q[2] == vb[2]) ||
                (p[0] == vb[0] && p[1] == vb[1] && p[2] == vb[2] &&
                 q[0] == va[0] && q[1] == va[1] && q[2] == va[2])) {
                result = j;
                break;
            }
        }
    }
    return result;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o24/overlay_24/func_overlay_24_018016E0_1F43210.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_24_018018B4_1F433E4(void *arg0) {
    u8 *obj = (u8 *) arg0;
    u8 *recs;
    u8 *rec;
    s32 count;
    s32 i;
    s32 recOff;
    s16 minVal;
    s16 val;

    *(s16 *) (obj + 0x44) = -0x2710;
    recs = *(u8 **) (obj + 0xC);
    count = 0;
    for (i = 0, recOff = 0; i < *(s16 *) (obj + 0x28); i++, recOff += 0x10) {
        rec = recs + recOff;
        if (*(s32 *) (rec + 0xC) & 0x2000) {
            ((s16 *) *(u8 **) (obj + 0x40))[count] = i;
            count++;
            minVal = *(s16 *) (obj + 0x44);
            val = *(s16 *) (*(u8 **) (obj + 0x0) + *(s16 *) (rec + 0x6) * 10 + 2);
            if (minVal == -0x2710 || minVal < val) {
                *(s16 *) (obj + 0x44) = val;
            }
        }
    }
    *(s16 *) (obj + 0x3E) = count;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o24/overlay_24/func_overlay_24_018018B4_1F433E4.s")
#endif
