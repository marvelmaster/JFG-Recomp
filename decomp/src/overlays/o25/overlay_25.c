#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
void func_overlay_25_019000C4_1F4399C(void *arg0, s32 arg1, s32 arg2);
void func_overlay_25_01900174_1F43A4C(void *arg0, s32 arg1, s32 arg2);
void func_overlay_25_01900208_1F43AE0(void *arg0, s32 arg1, s32 arg2);
void func_overlay_25_01900260_1F43B38(void *arg0, s32 arg1, s32 arg2);
void *func_overlay_25_01900728_1F44000(s32 arg0, s32 arg1);
void amCreateAudioMgr(void *c, s32 priority, void *sched);
void amGo(void);
void amSetMuteMode(s32 behaviour);
void amVibratoInit(void);
void alSurround_OutputType(s32 mode);
void alSurround_ReverbSetup(s32 a, s32 b);
void gsSndpNew(void *cfg);
void n_alCSPSetMessageQ(void *seqp, OSMesgQueue *mq);
u8 *piRomGetSectionPtr(u32 assetIndex, u32 assetOffset);
extern ALHeap hp;
extern u8 audioHeap[];
extern void *tuneCSeqs;
extern void *tuneCSeqp;
extern void *tuneSeqPlayer;
extern void *ambientSeqPlayer;
extern OSMesgQueue animCtrlQueue;
extern OSMesg animCtrlMesgBuf;
extern s32 maxSound;
extern u32 maxSequence;
extern u8 *seqIndex;
extern s32 seqIndexSize;
extern u32 *seqLen;
extern u8 *seqFile;
extern u8 *seqBankPtr;
extern u8 *sfxIndex;
extern s32 sfxIndexSize;
extern void amInitOsc(void);
extern void amUpdateOsc(void);
extern void amStopOsc(void);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_25_01900000_1F438D8(void *arg0, s32 arg1) {
    s32 i;

    for (i = 0; i < *(s16 *)((u8 *)arg0 + 2); i++) {
        *(s32 *)((u8 *)arg0 + 4 + 8 * i) += arg1;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o25/overlay_25/func_overlay_25_01900000_1F438D8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_25_0190003C_1F43914(void *arg0, s32 arg1) {
    s32 i;
    s32 val;

    if (*(s16 *)arg0 == 0x4231) {
        for (i = 0; i < *(s16 *)((u8 *)arg0 + 2); i++) {
            val = *(s32 *)((u8 *)arg0 + 4 + 4 * i) + (s32) arg0;
            *(s32 *)((u8 *)arg0 + 4 + 4 * i) = val;
            if (val != 0) {
                func_overlay_25_019000C4_1F4399C((void *) val, (s32) arg0, arg1);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o25/overlay_25/func_overlay_25_0190003C_1F43914.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_25_019000C4_1F4399C(void *arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 val;

    if (*(u8 *)((u8 *)arg0 + 2) == 0) {
        val = *(s32 *)((u8 *)arg0 + 8);
        *(u8 *)((u8 *)arg0 + 2) = 1;
        if (val != 0) {
            val += arg1;
            *(s32 *)((u8 *)arg0 + 8) = val;
            func_overlay_25_01900174_1F43A4C((void *) val, arg1, arg2);
        }
        for (i = 0; i < *(s16 *)arg0; i++) {
            val = *(s32 *)((u8 *)arg0 + 0xC + 4 * i) + arg1;
            *(s32 *)((u8 *)arg0 + 0xC + 4 * i) = val;
            if (val != 0) {
                func_overlay_25_01900174_1F43A4C((void *) val, arg1, arg2);
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o25/overlay_25/func_overlay_25_019000C4_1F4399C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_25_01900174_1F43A4C(void *arg0, s32 arg1, s32 arg2) {
    s32 i;
    s32 val;

    if (*(u8 *)((u8 *)arg0 + 3) == 0) {
        *(u8 *)((u8 *)arg0 + 3) = 1;
        for (i = 0; i < *(s16 *)((u8 *)arg0 + 0xE); i++) {
            val = *(s32 *)((u8 *)arg0 + 0x10 + 4 * i) + arg1;
            *(s32 *)((u8 *)arg0 + 0x10 + 4 * i) = val;
            func_overlay_25_01900208_1F43AE0((void *) val, arg1, arg2);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o25/overlay_25/func_overlay_25_01900174_1F43A4C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_25_01900208_1F43AE0(void *arg0, s32 arg1, s32 arg2) {
    s32 val;

    if (*(u8 *)((u8 *)arg0 + 0xE) == 0) {
        val = *(s32 *)((u8 *)arg0 + 8) + arg1;
        *(u8 *)((u8 *)arg0 + 0xE) = 1;
        *(s32 *)((u8 *)arg0 + 0) += arg1;
        *(s32 *)((u8 *)arg0 + 4) += arg1;
        *(s32 *)((u8 *)arg0 + 8) = val;
        func_overlay_25_01900260_1F43B38((void *) val, arg1, arg2);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o25/overlay_25/func_overlay_25_01900208_1F43AE0.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_25_01900260_1F43B38(void *arg0, s32 arg1, s32 arg2) {
    u8 type;
    s32 val;

    if (*(u8 *)((u8 *)arg0 + 9) == 0) {
        type = *(u8 *)((u8 *)arg0 + 8);
        *(u8 *)((u8 *)arg0 + 9) = 1;
        *(s32 *)((u8 *)arg0 + 0) += arg2;
        if (type == 0) {
            val = *(s32 *)((u8 *)arg0 + 0xC);
            *(s32 *)((u8 *)arg0 + 0x10) += arg1;
            if (val != 0) {
                *(s32 *)((u8 *)arg0 + 0xC) = val + arg1;
            }
        } else if (type == 1) {
            val = *(s32 *)((u8 *)arg0 + 0xC);
            if (val != 0) {
                *(s32 *)((u8 *)arg0 + 0xC) = val + arg1;
            }
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o25/overlay_25/func_overlay_25_01900260_1F43B38.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_overlay_25_019002D0_1F43BA8(void *arg0, s32 arg1) {
    s16 evt;

    /* asm: arg1 is spilled to the stack and never read again */
    evt = 0xE;
    n_alEvtqPostEvent((ALEventQueue *) ((u8 *) arg0 + 0x48), (void *) &evt, 0);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o25/overlay_25/func_overlay_25_019002D0_1F43BA8.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void amInit(s32 arg0) {
    u32 *romTbl;
    s32 cfgA[8];
    s32 cfgB[5];
    s32 size;
    s32 count;
    s32 i;
    u32 maxLen;

    tuneCSeqp = &tuneCSeqs;
    alHeapInit(&hp, audioHeap, 0x2F990);
    romTbl = piRomLoad(0x33);

    sfxBankPtr = (ALBankFile *) mmAlloc(romTbl[2] - romTbl[1], 0xFFFFFF);
    piRomLoadSection(0x34, (u32) sfxBankPtr, romTbl[1], romTbl[2] - romTbl[1]);
    func_overlay_25_0190003C_1F43914((void *) sfxBankPtr, (s32) piRomGetSectionPtr(0x34, romTbl[2]));

    sfxIndexSize = romTbl[6] - romTbl[5];
    sfxIndex = (u8 *) mmAlloc(sfxIndexSize, 0xFFFFFF);
    piRomLoadSection(0x34, (u32) sfxIndex, romTbl[5], sfxIndexSize);
    maxSound = (u32) sfxIndexSize / 10U;

    seqIndexSize = romTbl[5] - romTbl[4];
    seqIndex = (u8 *) mmAlloc(seqIndexSize, 0xFFFFFF);
    piRomLoadSection(0x34, (u32) seqIndex, romTbl[4], seqIndexSize);
    maxSequence = (u32) seqIndexSize / 3U;

    seqBankPtr = (u8 *) mmAlloc(romTbl[0], 0xFFFFFF);
    piRomLoadSection(0x34, (u32) seqBankPtr, 0, romTbl[0]);
    func_overlay_25_0190003C_1F43914((void *) seqBankPtr, (s32) piRomGetSectionPtr(0x34, romTbl[0]));

    seqFile = (u8 *) alHeapDBAlloc(NULL, 0, &hp, 1, 4);
    piRomLoadSection(0x34, (u32) seqFile, romTbl[3], 4);
    size = (*(s16 *) (seqFile + 2) * 8) + 4;
    seqFile = (u8 *) mmAlloc(size, 0xFFFFFF);
    piRomLoadSection(0x34, (u32) seqFile, romTbl[3], size);
    func_overlay_25_01900000_1F438D8(seqFile, (s32) piRomGetSectionPtr(0x34, romTbl[3]));

    count = *(s16 *) (seqFile + 2);
    seqLen = (u32 *) mmAlloc(count * 4, 0xFFFFFF);
    maxLen = 0;
    for (i = 0; i < count; i++) {
        seqLen[i] = *(u32 *) (seqFile + 8 * i + 8);
        if (seqLen[i] & 1) {
            seqLen[i] += 1;
        }
        if (maxLen < seqLen[i]) {
            maxLen = seqLen[i];
        }
    }

    cfgA[0] = 0x2C;
    cfgA[1] = 0x28;
    cfgA[2] = 0x80;
    cfgA[3] = 1;
    cfgA[4] = 0;
    cfgA[5] = (s32) &hp;
    cfgA[6] = 0;
    *(u8 *) &cfgA[7] = 6;
    amCreateAudioMgr(cfgA, 0xC, (void *) arg0);

    tuneSeqPlayer = func_overlay_25_01900728_1F44000(0x20, 0x96);
    ambientSeqPlayer = func_overlay_25_01900728_1F44000(0x10, 0x32);

    cfgB[0] = 0x20;
    cfgB[1] = 0xC8;
    cfgB[2] = 0x10;
    cfgB[3] = (s32) &hp;
    *(s16 *) &cfgB[4] = 5;
    gsSndpNew(cfgB);

    amGo();
    amSetMuteMode(0);
    mmFree(romTbl);
    amVibratoInit();
    alSurround_OutputType(4);
    alSurround_ReverbSetup(0, 3);
    osCreateMesgQueue(&animCtrlQueue, &animCtrlMesgBuf, 1);
    n_alCSPSetMessageQ(tuneSeqPlayer, &animCtrlQueue);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o25/overlay_25/amInit.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_overlay_25_01900728_1F44000(s32 arg0, s32 arg1) {
    s32 cfg[7];
    void *seqp;

    cfg[0] = arg0;
    cfg[1] = arg1;
    *(u8 *) &cfg[2] = 0x10;
    cfg[3] = (s32) &hp;
    cfg[4] = (s32) amInitOsc;
    cfg[5] = (s32) amUpdateOsc;
    cfg[6] = (s32) amStopOsc;
    seqp = alHeapDBAlloc(NULL, 0, &hp, 1, 0x90);
    n_alCSPNew(seqp, (ALSeqpConfig *) cfg);
    func_overlay_25_019002D0_1F43BA8(seqp, *(s32 *) ((u8 *) seqBankPtr + 4));
    return seqp;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o25/overlay_25/func_overlay_25_01900728_1F44000.s")
#endif
