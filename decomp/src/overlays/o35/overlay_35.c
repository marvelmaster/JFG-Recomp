#include "common.h"

#ifdef NON_MATCHING
/* decomp: externs */
extern u8 *cacheLine;
void fontCreateDisplayList(FontCharDataAlt *font);
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fontInit(void) {
    s32 width;
    s32 height;
    DialogueBoxBackground *box;
    DialogueTextElement *elem;
    FontCharDataAlt *font;
    u8 **slot;
    s32 i;
    s32 j;
    s16 off;

    viGetCurrentSize(&width, &height);

    box = Window;
    do {
        box->xpos = 0;
        box->ypos = 0;
        box->x1 = 0;
        box->y1 = 0;
        box->x2 = width - 1;
        box->y2 = height - 1;
        box->width = width;
        box->height = height;
        box->backgroundColourR = 0;
        box->backgroundColourG = 0;
        box->backgroundColourB = 0;
        box->backgroundColourA = 0;
        box->textColourR = 0xFF;
        box->textColourG = 0xFF;
        box->textColourB = 0xFF;
        box->textColourA = 0;
        box->textBGColourR = 0xFF;
        box->textBGColourG = 0xFF;
        box->textBGColourB = 0xFF;
        box->textBGColourA = 0;
        box->opacity = 0xFF;
        box->font = 0;
        box->flags = 0;
        box->textOffsetX = 0;
        box->textOffsetY = 0;
        box->textBox = NULL;
        box++;
    } while ((u32) box < (u32) &dxTable);

    elem = String;
    do {
        elem->number = 0xFF;
        elem->text = NULL;
        elem->textColourR = 0xFF;
        elem->textColourG = 0xFF;
        elem->textColourB = 0xFF;
        elem->textColourA = 0;
        elem->textBGColourR = 0xFF;
        elem->textBGColourG = 0xFF;
        elem->textBGColourB = 0xFF;
        elem->textBGColourA = 0;
        elem->nextBox = NULL;
        elem++;
    } while ((u32) elem < (u32) Window);

    cache = (u32 *) mmAlloc(0x8010, 0xFF0000FFU);
    cacheLine = (u8 *) mmAlloc(0x1000, 0xFF0000FFU);
    cache = (u32 *) ((u8 *) cache + 0x10);

    off = 0;
    for (i = 0; i < 0x1000; i += 0x10) {
        cacheLine[i + 0] = 0xFF;
        cacheLine[i + 4] = 0;
        *(s16 *) (cacheLine + i + 2) = off;
        off += 0x80;
        cacheLine[i + 5] = 0;
    }

    Font = (FontCharDataAlt *) piRomLoad(0x3A);
    combineBuffer = (char *) mmAlloc(0x200, 0xFF0000FFU);
    convertBuffer = (char *) mmAlloc(0x200, 0xFF0000FFU);
    printBuffer = (char *) mmAlloc(0x200, 0xFF0000FFU);

    font = Font;
    slot = (u8 **) &dxTable;
    do {
        *slot = (u8 *) mmAlloc(0x400, 0xFF0000FFU);
        for (j = 0; j < 0x100; j++) {
            s32 srcOffset = *(u32 *) ((u8 *) font + 4) + j * *(s16 *) ((u8 *) font + 8);

            piRomLoadSection(0x3B, (u32) combineBuffer, srcOffset, 0x20);
            (*slot)[j] = ((u8 *) combineBuffer)[8];
        }
        fontCreateDisplayList(font);
        slot++;
        font++;
    } while ((u32) slot != (u32) &cache);

    fontInUse = 0;
    squash = 0;
    buttonMode = 0;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/overlays/o35/overlay_35/fontInit.s")
#endif
