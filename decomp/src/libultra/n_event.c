#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern s32 D_80105020_B1750;
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alEvtqNew(ALEventQueue *evtq, ALEventListItem *items, s32 itemCount) {
    s32 i;

    /* asm: queue header is larger than ALEventQueue; s16 count @0x10, u16 missed @0x12, s16 max @0x14 */
    evtq->freeList.next = NULL;
    evtq->freeList.prev = NULL;
    evtq->allocList.next = NULL;
    evtq->allocList.prev = NULL;
    *(s16 *)((u8 *)evtq + 0x10) = 0;
    *(u16 *)((u8 *)evtq + 0x12) = 0;
    *(s16 *)((u8 *)evtq + 0x14) = 0;

    for (i = 0; i < itemCount; i++) {
        alLink((ALLink *)&items[i], (ALLink *)evtq);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_event/n_alEvtqNew.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
ALMicroTime n_alEvtqNextEvent(ALEventQueue *evtq, ALEvent *evt) {
    OSIntMask mask;
    ALEventListItem *item;
    ALMicroTime delta;

    mask = osSetIntMask(1);
    item = (ALEventListItem *)evtq->allocList.next;
    if (item != NULL) {
        alUnlink((ALLink *)item);
        bcopy(&item->evt, evt, 0x10); /* asm: bcopy 16 bytes */
        alLink((ALLink *)item, (ALLink *)evtq);
        delta = item->delta;
        *(s16 *)((u8 *)evtq + 0x10) = (s16)(*(s16 *)((u8 *)evtq + 0x10) - 1);
    } else {
        evt->type = -1;
        delta = 0;
    }
    osSetIntMask(mask);
    return delta;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_event/n_alEvtqNextEvent.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alEvtqPostEvent(ALEventQueue *evtq, ALEvent *evt, ALMicroTime delta) {
    OSIntMask mask;
    ALEventListItem *item;
    ALLink *cur;
    ALLink *next;
    s32 infinite = 0;

    mask = osSetIntMask(1);
    item = (ALEventListItem *)evtq->freeList.next;
    if (item == NULL) {
        /* asm: missed-event counter saturates at 60000 */
        if (*(u16 *)((u8 *)evtq + 0x12) < 60000) {
            *(u16 *)((u8 *)evtq + 0x12) = (u16)(*(u16 *)((u8 *)evtq + 0x12) + 1);
        }
        osSetIntMask(mask);
        return;
    }

    alUnlink((ALLink *)item);
    bcopy(evt, &item->evt, 0x10); /* asm: bcopy 16 bytes (JFG event size), not sizeof(ALEvent) */
    *(s16 *)((u8 *)evtq + 0x10) = (s16)(*(s16 *)((u8 *)evtq + 0x10) + 1);
    if (*(s16 *)((u8 *)evtq + 0x14) < *(s16 *)((u8 *)evtq + 0x10)) {
        *(s16 *)((u8 *)evtq + 0x14) = *(s16 *)((u8 *)evtq + 0x10);
    }
    if (delta == 0x7FFFFFFF) {
        infinite = -1;
    }

    cur = &evtq->allocList;
    for (;;) {
        if (cur->next == NULL) {
            item->delta = (infinite != 0) ? 0 : delta;
            alLink((ALLink *)item, cur);
            break;
        }
        next = cur->next;
        if (delta < ((ALEventListItem *)next)->delta) {
            item->delta = delta;
            ((ALEventListItem *)next)->delta -= delta;
            alLink((ALLink *)item, cur);
            break;
        }
        delta -= ((ALEventListItem *)next)->delta;
        cur = next;
    }
    osSetIntMask(mask);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_event/n_alEvtqPostEvent.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
/* arg0 is the owning synth (N_ALSynth); paramSamples is at +0x1C in the asm */
void n_alEvtqPostExternEvent(void *drvr, ALEventQueue *evtq, ALEvent *evt, s32 delta) {
    OSIntMask mask;
    ALEventListItem *item;
    ALLink *cur;
    ALLink *next;
    s32 infinite = 0;
    s32 base;

    mask = osSetIntMask(1);
    item = (ALEventListItem *)evtq->freeList.next;
    if (item == NULL) {
        if (*(u16 *)((u8 *)evtq + 0x12) < 60000) {
            *(u16 *)((u8 *)evtq + 0x12) = (u16)(*(u16 *)((u8 *)evtq + 0x12) + 1);
        }
        osSetIntMask(mask);
        return;
    }

    alUnlink((ALLink *)item);
    bcopy(evt, &item->evt, 0x10); /* asm: bcopy 16 bytes (JFG event size), not sizeof(ALEvent) */
    *(s16 *)((u8 *)evtq + 0x10) = (s16)(*(s16 *)((u8 *)evtq + 0x10) + 1);
    if (*(s16 *)((u8 *)evtq + 0x14) < *(s16 *)((u8 *)evtq + 0x10)) {
        *(s16 *)((u8 *)evtq + 0x14) = *(s16 *)((u8 *)evtq + 0x10);
    }

    base = *(s32 *)((u8 *)drvr + 0x1C);
    if (delta == 0x7FFFFFFF) {
        infinite = -1;
    } else {
        D_80105020_B1750 += delta;
        if (D_80105020_B1750 < base) {
            D_80105020_B1750 = base;
        }
        delta = D_80105020_B1750 - base;
    }

    cur = &evtq->allocList;
    for (;;) {
        if (cur->next == NULL) {
            item->delta = (infinite != 0) ? 0 : delta;
            alLink((ALLink *)item, cur);
            break;
        }
        next = cur->next;
        if (delta < ((ALEventListItem *)next)->delta) {
            item->delta = delta;
            ((ALEventListItem *)next)->delta -= delta;
            alLink((ALLink *)item, cur);
            break;
        }
        delta -= ((ALEventListItem *)next)->delta;
        cur = next;
    }
    osSetIntMask(mask);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_event/n_alEvtqPostExternEvent.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void n_alEvtqFlushType(ALEventQueue *evtq, s16 type) {
    OSIntMask mask;
    ALEventListItem *item;
    ALEventListItem *next;

    mask = osSetIntMask(1);
    item = (ALEventListItem *)evtq->allocList.next;
    while (item != NULL) {
        next = (ALEventListItem *)item->node.next;
        if (item->evt.type == type) {
            if (next != NULL) {
                next->delta += item->delta;
            }
            alUnlink((ALLink *)item);
            alLink((ALLink *)item, (ALLink *)evtq);
            *(s16 *)((u8 *)evtq + 0x10) = (s16)(*(s16 *)((u8 *)evtq + 0x10) - 1);
        }
        item = next;
    }
    osSetIntMask(mask);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/libultra/n_event/n_alEvtqFlushType.s")
#endif
