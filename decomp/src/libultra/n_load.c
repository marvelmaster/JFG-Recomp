#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
s32 *func_80092994(s32 *cmd, u8 *arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s32 arg6);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Filter layout as used by n_alLoadParam (raw offsets):
//   +0x14 loop.start  +0x18 loop.end  +0x1C loop.count  +0x20 table
//   +0x24 bookSize    +0x30 sample    +0x34 lastsam     +0x38 first
//   +0x3C memin
// cf. DKR alAdpcmPull (libultra/src/audio/load.c) for the overall structure.
Acmd *n_alAdpcmPull(void *arg0, s16 *outp, s32 count, Acmd *arg3) {
    u8 *f = (u8 *) arg0;
    s32 *cmd = (s32 *) arg3;
    s32 *cmdP;
    ALWaveTable *table;
    ALADPCMBook *book;
    s16 inp = 0;
    s32 looped;
    s32 decoded = 0;
    s32 nSam;
    s32 nLeft;
    s32 tsam;
    s32 nframes;
    s32 nbytes;
    s32 op;
    s32 bEnd;
    s32 overflow;
    s32 nOver;
    s32 adj;

    if (count == 0) {
        return arg3;
    }

    table = *(ALWaveTable **)(f + 0x20);
    book = table->waveInfo.adpcmWave.book;

    // aLoadADPCM(bookSize, book)  (book->book sits at +8)
    cmdP = cmd;
    cmd += 2;
    cmdP[0] = (*(s32 *)(f + 0x24) & 0xFFFFFF) | 0x0B000000;
    cmdP[1] = ((u32) book + 8) & 0x1FFFFFFF;

    looped = (u32) *(s32 *)(f + 0x18) < (u32) (*(s32 *)(f + 0x30) + count);
    if (looped) {
        looped = *(s32 *)(f + 0x1C) != 0;
    }

    if (looped) {
        nSam = *(s32 *)(f + 0x18) - *(s32 *)(f + 0x30);
    } else {
        nSam = count;
    }
    if (*(s32 *)(f + 0x34) != 0) {
        nLeft = 0x10 - *(s32 *)(f + 0x34);
    } else {
        nLeft = 0;
    }
    tsam = nSam - nLeft;
    if (tsam < 0) {
        tsam = 0;
    }
    nframes = (tsam + 0xF) >> 4;
    nbytes = nframes * 9;

    if (looped) {
        cmd = func_80092994(cmd, f, tsam, nbytes, *outp, inp, *(s32 *)(f + 0x38));
        if (*(s32 *)(f + 0x34) != 0) {
            *outp += *(s32 *)(f + 0x34) * 2;
        } else {
            *outp += 0x20;
        }

        // loop start point becomes the new state
        *(s32 *)(f + 0x34) = *(s32 *)(f + 0x14) & 0xF;
        *(s32 *)(f + 0x3C) = (s32) table->base + ((u32) *(s32 *)(f + 0x14) >> 4) * 9 + 9;
        *(s32 *)(f + 0x30) = *(s32 *)(f + 0x14);

        bEnd = *outp;
        while (nSam < count) {
            count -= nSam;

            // destination for the next (post-loop) chunk, 32 byte aligned
            op = (((nframes + 1) << 5) + bEnd + 0x10) & ~0x1F;
            bEnd += nSam * 2;

            if (*(s32 *)(f + 0x1C) != -1 && *(s32 *)(f + 0x1C) != 0) {
                *(s32 *)(f + 0x1C) -= 1;
            }

            if ((u32) count < (u32) (*(s32 *)(f + 0x18) - *(s32 *)(f + 0x14))) {
                nSam = count;
            } else {
                nSam = *(s32 *)(f + 0x18) - *(s32 *)(f + 0x14);
            }

            tsam = nSam + *(s32 *)(f + 0x34) - 0x10;
            if (tsam < 0) {
                tsam = 0;
            }
            nframes = (tsam + 0xF) >> 4;
            nbytes = nframes * 9;

            cmd = func_80092994(cmd, f, tsam, nbytes, op, inp, *(s32 *)(f + 0x38) | 2);
            cmdP = cmd;
            cmd += 2;
            cmdP[0] = ((*(s32 *)(f + 0x34) * 2 + op) & 0xFFFFFF) | 0x0A000000;
            cmdP[1] = ((bEnd & 0xFFFF) << 16) | ((nSam * 2) & 0xFFFF);
        }

        *(s32 *)(f + 0x34) = (*(s32 *)(f + 0x34) + count) & 0xF;
        *(s32 *)(f + 0x30) += count;
        *(s32 *)(f + 0x3C) += nframes * 9;
        return (Acmd *) cmd;
    }

    // unlooped case
    nSam = nframes * 16;
    overflow = (*(s32 *)(f + 0x3C) + nbytes) - ((s32) table->base + table->len);
    if (overflow < 0) {
        overflow = 0;
    }
    nOver = (overflow / 9) * 0x10;
    if (nSam + nLeft < nOver) {
        nOver = nSam + nLeft;
    }
    nbytes -= overflow;

    if ((nOver - (nOver & 0xF)) < count) {
        decoded = 1;
        cmd = func_80092994(cmd, f, nSam - nOver, nbytes, *outp, inp, *(s32 *)(f + 0x38));
        if (*(s32 *)(f + 0x34) != 0) {
            *outp += *(s32 *)(f + 0x34) * 2;
        } else {
            *outp += 0x20;
        }
        *(s32 *)(f + 0x34) = (*(s32 *)(f + 0x34) + count) & 0xF;
        *(s32 *)(f + 0x30) += count;
        *(s32 *)(f + 0x3C) += nframes * 9;
    } else {
        *(s32 *)(f + 0x34) = 0;
        *(s32 *)(f + 0x3C) += nframes * 9;
    }

    if (nOver != 0) {
        *(s32 *)(f + 0x34) = 0;
        if (decoded) {
            adj = ((nLeft + nSam) - nOver) * 2;
        } else {
            adj = 0;
        }
        cmdP = cmd;
        cmd += 2;
        cmdP[0] = ((*outp + adj) & 0xFFFFFF) | 0x02000000;
        cmdP[1] = nOver * 2;
    }
    return (Acmd *) cmd;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_load/n_alAdpcmPull.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alLoadParam(void *filter, s32 paramID, ALWaveTable *param) {
    u8 *f = (u8 *) filter;
    ALADPCMloop *loop;
    ALRawLoop *rloop;
    ALADPCMBook *book;
    ALWaveTable *wave;

    switch (paramID) {
    case 5:
        *(ALWaveTable **)(f + 0x20) = param;
        *(s32 *)(f + 0x3C) = (s32) param->base;
        *(s32 *)(f + 0x30) = 0;
        switch (param->type) {
        case 0:
            param->len = (param->len / 9) * 9;
            book = param->waveInfo.adpcmWave.book;
            *(s32 *)(f + 0x24) = book->order * 2 * book->npredictors * 8;
            loop = param->waveInfo.adpcmWave.loop;
            if (loop != NULL) {
                *(u32 *)(f + 0x14) = loop->start;
                *(u32 *)(f + 0x18) = loop->end;
                *(u32 *)(f + 0x1C) = loop->count;
                bcopy(loop->state, *(void **)(f + 0x10), 0x20); // +0x10 is the lstate pointer
            } else {
                *(s32 *)(f + 0x1C) = 0;
                *(s32 *)(f + 0x18) = 0;
                *(s32 *)(f + 0x14) = 0;
            }
            break;
        case 1:
            rloop = param->waveInfo.rawWave.loop;
            if (rloop != NULL) {
                *(u32 *)(f + 0x14) = rloop->start;
                *(u32 *)(f + 0x18) = rloop->end;
                *(u32 *)(f + 0x1C) = rloop->count;
            } else {
                *(s32 *)(f + 0x1C) = 0;
                *(s32 *)(f + 0x18) = 0;
                *(s32 *)(f + 0x14) = 0;
            }
            break;
        }
        break;
    case 4:
        *(s32 *)(f + 0x34) = 0;
        *(s32 *)(f + 0x38) = 1;
        *(s32 *)(f + 0x30) = 0;
        wave = *(ALWaveTable **)(f + 0x20);
        if (wave != NULL) {
            *(s32 *)(f + 0x3C) = (s32) wave->base;
            if (wave->type == 0) {
                loop = wave->waveInfo.adpcmWave.loop;
                if (loop != NULL) {
                    *(u32 *)(f + 0x1C) = loop->count;
                }
            } else if (wave->type == 1) {
                rloop = wave->waveInfo.rawWave.loop;
                if (rloop != NULL) {
                    *(u32 *)(f + 0x1C) = rloop->count;
                }
            }
        }
        break;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_load/n_alLoadParam.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 *func_80092994(s32 *cmd, u8 *arg1, s32 arg2, s32 arg3, s16 arg4, s16 arg5, s32 arg6) {
    s32 skip;
    s32 dmaRet;
    s32 *p;

    if (arg3 > 0) {
        dmaRet = ((s32 (*)(void *, s32, s32)) *(void **)(arg1 + 0x28))(
            *(void **)(arg1 + 0x3C), arg3, *(s32 *)(arg1 + 0x2C));
        skip = dmaRet & 7;
        arg3 += skip;
        cmd[0] = ((((arg3 - (arg3 & 7)) + 8) & 0xFFF) << 12) | 0x04000000 | (arg5 & 0xFFF);
        cmd[1] = dmaRet - skip;
        cmd += 2;
    } else {
        skip = 0;
    }
    if (arg6 & 2) {
        p = cmd;
        cmd += 2;
        p[0] = 0x0F000000;
        p[1] = *(s32 *)(arg1 + 0x10) & 0x1FFFFFFF;
    }
    p = cmd;
    cmd += 2;
    p[0] = ((*(s32 *)(arg1 + 0xC) & 0x1FFFFFFF) & 0xFFFFFF) | 0x01000000;
    p[1] = ((arg6 & 0xF) << 28) | (((arg2 * 2) & 0xFFF) << 16) | ((skip & 0xF) << 12) | (arg4 & 0xFFF);
    *(s32 *)(arg1 + 0x38) = 0;
    return cmd;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_load/func_80092994.s")
#endif
