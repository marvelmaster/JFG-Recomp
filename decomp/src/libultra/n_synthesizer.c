#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
#include "PR/n_libaudio.h"

/* raw access for fields without a header struct (aux bus entries are 0x48 bytes) */
#define SYN_FIELD(p, off, type) (*(type *)((u8 *)(p) + (off)))

extern s32 n_currParam;
extern s32 n_paramMax;
extern void n_alFxPull(void);
s32 func_8008C76C(s32 arg0);
s32 func_8008C80C(void **arg0);
Acmd *n_alSavePull(s32 samples, Acmd *cmd);
void _n_collectPVoices(void);
void alN_PVoiceNew(void *pvoice, ALDMANew dma, ALHeap *heap);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alSynNew(ALSynConfig *c) {
    ALHeap *heap;
    s32 i;
    s32 j;
    u8 *aux;
    u8 *sub;
    void *pvBlock;
    void *pv;
    void *paramBlock;
    void *param;
    void **list;

    heap = c->heap;
    n_syn->head = NULL;
    n_syn->numPVoices = c->maxPVoices;
    n_syn->curSamples = 0;
    n_syn->paramSamples = 0;
    n_syn->outputRate = c->outputRate;
    n_syn->maxOutSamples = 0xB8;
    n_syn->dma = (ALDMANew)c->dmaproc;
    n_syn->sv_dramout = 0;
    n_syn->sv_first = 1;

    if (c->maxFXbusses < 3) {
        n_syn->maxAuxBusses = c->maxFXbusses;
    } else {
        n_syn->maxAuxBusses = 2;
    }
    n_syn->auxBus = alHeapDBAlloc(NULL, 0, heap, n_syn->maxAuxBusses, 0x48);

    for (i = 0; i < n_syn->maxAuxBusses; i++) {
        aux = (u8 *)n_syn->auxBus + i * 0x48;
        SYN_FIELD(aux, 0x14, s32) = 0;
        SYN_FIELD(aux, 0x18, s32) = c->maxPVoices;
        SYN_FIELD(aux, 0x1C, void *) = alHeapDBAlloc(NULL, 0, heap, c->maxPVoices, 4);
        if (c->fxType[i] != 0) {
            SYN_FIELD(aux, 0x20, ALFxRef) = n_alSynAllocFX((s16)i, c, heap);
        } else {
            SYN_FIELD(aux, 0x20, ALFxRef) = NULL;
        }
        SYN_FIELD(aux, 0x44, void *) = alHeapDBAlloc(NULL, 0, heap, 1, 0x38);
        sub = (u8 *)SYN_FIELD(aux, 0x44, void *);
        SYN_FIELD(sub, 2, s16) = 0;
        SYN_FIELD(sub, 0x2C, void *) = alHeapDBAlloc(NULL, 0, heap, 1, 8);
        SYN_FIELD(sub, 0x30, void *) = alHeapDBAlloc(NULL, 0, heap, 1, 8);
    }

    n_syn->mainBus = alHeapDBAlloc(NULL, 0, heap, 1, 0x14);
    SYN_FIELD(n_syn->mainBus, 4, void *) = (void *)n_alFxPull;

    n_syn->pFreeList.next = NULL;
    n_syn->pFreeList.prev = NULL;
    n_syn->pAllocList.next = NULL;
    n_syn->pAllocList.prev = NULL;
    n_syn->pLameList.next = NULL;
    n_syn->pLameList.prev = NULL;

    /* physical voices: each goes on the free list and is attached to every aux bus */
    pvBlock = alHeapDBAlloc(NULL, 0, heap, c->maxPVoices, 0xC0);
    for (i = 0; i < c->maxPVoices; i++) {
        pv = (u8 *)pvBlock + i * 0xC0;
        alLink((ALLink *)pv, (ALLink *)&n_syn->pFreeList);
        SYN_FIELD(pv, 8, void *) = NULL;
        alN_PVoiceNew(pv, n_syn->dma, heap);
        for (j = 0; j < n_syn->maxAuxBusses; j++) {
            aux = (u8 *)n_syn->auxBus + j * 0x48;
            list = SYN_FIELD(aux, 0x1C, void **);
            list[SYN_FIELD(aux, 0x14, s32)] = pv;
            SYN_FIELD(aux, 0x14, s32) += 1;
        }
    }

    /* param pool */
    paramBlock = alHeapDBAlloc(NULL, 0, heap, c->maxUpdates, 0x24);
    n_syn->paramList = NULL;
    for (i = 0; i < c->maxUpdates; i++) {
        param = (u8 *)paramBlock + i * 0x24;
        *(struct ALParam_s **)param = n_syn->paramList;
        n_syn->paramList = (struct ALParam_s *)param;
    }

    n_syn->heap = heap;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_synthesizer/n_alSynNew.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
Acmd *n_alAudioFrame(Acmd *cmdList, s32 *cmdLen, s16 *outBuf, s32 outLen) {
    void *filter;
    Acmd *cmd;
    s32 dram;
    s32 chunk;
    s32 ret;

    cmd = cmdList;
    dram = (s32)outBuf;
    if (n_syn->head == NULL) {
        *cmdLen = 0;
        return cmdList;
    }

    n_syn->paramSamples = func_8008C80C(&filter);
    while ((n_syn->paramSamples - n_syn->curSamples) < outLen) {
        n_syn->paramSamples &= ~0xF;
        ret = ((s32 (*)(void *))(*(void **)((u8 *)filter + 8)))(filter);
        *(s32 *)((u8 *)filter + 0x10) += func_8008C76C(ret);
        n_syn->paramSamples = func_8008C80C(&filter);
    }

    n_syn->paramSamples &= ~0xF;
    while (outLen > 0) {
        if (n_syn->maxOutSamples < outLen) {
            chunk = n_syn->maxOutSamples;
        } else {
            chunk = outLen;
        }
        n_syn->sv_dramout = dram;
        cmd = n_alSavePull(n_syn->curSamples, cmd);
        outLen -= chunk;
        dram += chunk * 2 * 2;
        n_syn->curSamples += chunk;
    }

    *cmdLen = ((s32)cmd - (s32)cmdList) >> 3;
    _n_collectPVoices();
    return cmd;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_synthesizer/n_alAudioFrame.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
struct ALParam_s *__n_allocParam(void) {
    struct ALParam_s *volatile param;

    param = NULL;
    if (n_syn->paramList != NULL) {
        param = n_syn->paramList;
        n_syn->paramList = *(struct ALParam_s **)param;
        *(struct ALParam_s **)param = NULL;
        n_currParam += 1;
        if (n_paramMax < n_currParam) {
            n_paramMax = n_currParam;
        }
    }
    return param;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_synthesizer/__n_allocParam.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void _n_freeParam(struct ALParam_s *param) {
    *(struct ALParam_s **)param = n_syn->paramList;
    n_syn->paramList = param;
    n_currParam -= 1;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_synthesizer/_n_freeParam.s")
#endif

void func_8008C6B8(void) {
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void _n_collectPVoices(void) {
    ALLink *pv;

    while (n_syn->pLameList.next != NULL) {
        pv = n_syn->pLameList.next;
        alUnlink(pv);
        alLink(pv, &n_syn->pFreeList);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_synthesizer/_n_collectPVoices.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void _n_freePVoice(void *pvoice) {
    alUnlink((ALLink *)pvoice);
    alLink((ALLink *)pvoice, &n_syn->pLameList);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_synthesizer/_n_freePVoice.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_8008C76C(s32 arg0) {
    volatile f32 t;

    t = ((f32)arg0 * (f32)n_syn->outputRate) / 1000000.0f + 0.5f;
    return (s32)t;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_synthesizer/func_8008C76C.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 _n_timeToSamples(s32 arg0) {
    return func_8008C76C(arg0) & ~0xF;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_synthesizer/_n_timeToSamples.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_8008C80C(void **arg0) {
    ALPlayer *volatile p;
    s32 diff;
    s32 volatile best = 0x7FFFFFFF;

    *arg0 = NULL;
    for (p = n_syn->head; p != NULL; p = p->next) {
        diff = p->samplesLeft - n_syn->curSamples;
        if (diff < best) {
            *arg0 = p;
            best = diff;
        }
    }
    return ((ALPlayer *)*arg0)->samplesLeft;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_synthesizer/func_8008C80C.s")
#endif
