#include "common.h"
#ifdef NON_MATCHING
/* decomp: externs */
typedef struct FontCacheLine {
    u8 font;
    u8 charIdx;
    u16 offset;
    u8 state;
    u8 chain;
    s16 f6;
    s16 f8;
    u8 fA;
    u8 fB;
    u8 fC;
    u8 fD;
    u8 fE;
    u8 fF;
} FontCacheLine;
extern void *cacheLine;
extern u8 D_A6E98[];
extern s8 D_800A78A0[];
extern u32 D_800A7828[];
extern u32 D_800A7838[];
extern u32 D_800A7848[];
#endif

enum WindowFlags {
    DIALOGUE_BOX_UNUSED_01 = 0x0001,
    DIALOGUE_BOX_VERTS = 0x4000,
    WINDOW_CLOSED = 0x7FFF,
    WINDOW_OPEN = 0x8000,
    DIALOGUE_BOX_UNK_02 = 0xBFFF,
    DIALOGUE_BOX_UNUSED_02 = 0xFFFE
};

// typedef enum HorizontalAlignmentFlags {
//     HORZ_ALIGN_LEFT   = 0,
//     HORZ_ALIGN_RIGHT  = 1,
//     HORZ_ALIGN_CENTER = 4
// } HorizontalAlignmentFlags;

// typedef enum VerticalAlignmentFlags {
//     VERT_ALIGN_TOP    = 0,
//     VERT_ALIGN_BOTTOM = 2,
//     VERT_ALIGN_MIDDLE = 8
// } VerticalAlignmentFlags;

// typedef enum AlignmentFlags {
//     ALIGN_TOP_LEFT      = VERT_ALIGN_TOP    | HORZ_ALIGN_LEFT,
//     ALIGN_TOP_CENTER    = VERT_ALIGN_TOP    | HORZ_ALIGN_CENTER,
//     ALIGN_TOP_RIGHT     = VERT_ALIGN_TOP    | HORZ_ALIGN_RIGHT,
//     ALIGN_MIDDLE_LEFT   = VERT_ALIGN_MIDDLE | HORZ_ALIGN_LEFT,
//     ALIGN_MIDDLE_CENTER = VERT_ALIGN_MIDDLE | HORZ_ALIGN_CENTER,
//     ALIGN_MIDDLE_RIGHT  = VERT_ALIGN_MIDDLE | HORZ_ALIGN_RIGHT,
//     ALIGN_BOTTOM_LEFT   = VERT_ALIGN_BOTTOM | HORZ_ALIGN_LEFT,
//     ALIGN_BOTTOM_CENTER = VERT_ALIGN_BOTTOM | HORZ_ALIGN_CENTER,
//     ALIGN_BOTTOM_RIGHT  = VERT_ALIGN_BOTTOM | HORZ_ALIGN_RIGHT
// } AlignmentFlags;

#define WINDOW_COUNT 8
#define POS_CENTRED -0x8000
#define DIALOGUE_NUM_NULL 0xFF

void fontSetWindow0(s32 width, s32 height) {
    Window->x2 = width - 1;
    Window->y2 = height - 1;
    Window->width = width;
    Window->height = height;
}

void fontSetButtonMode(s32 mode) {
    buttonMode = mode;
}

void fontSetWindowNoise(u8 arg0, u8 arg1, u8 arg2) {
    D_800A7868 = arg0;
    D_800A786C = arg1;
    D_800A7870 = arg2;
}

void fontUseFont(s32 font) {
    fontInUse = font;
    Window->font = font;
}

void fontColour(s32 red, s32 green, s32 blue, s32 alpha, s32 opacity) {
    Window->textColourR = red;
    Window->textColourG = green;
    Window->textColourB = blue;
    Window->textColourA = alpha;
    Window->opacity = opacity;
}

void fontBackground(s32 red, s32 green, s32 blue, s32 alpha) {
    Window->textBGColourR = red;
    Window->textBGColourG = green;
    Window->textBGColourB = blue;
    Window->textBGColourA = alpha;
}

void fontPrintXY(Gfx **displayList, s32 xpos, s32 ypos, char *text, AlignmentFlags alignmentFlags) {
    fontPrintWindowXY(displayList, 0, xpos, ypos, text, alignmentFlags);
}

/**
 * Text draw function that draws text in the current window while overriding position.
 */
void fontPrintWindowXY(Gfx **displayList, s32 windowId, s32 xpos, s32 ypos, char *text, AlignmentFlags alignmentFlags) {
    if (windowId >= 0 && windowId < WINDOW_COUNT) {
        DialogueBoxBackground *temp = &Window[windowId];
        temp->xpos = (xpos == POS_CENTRED) ? temp->width >> 1 : xpos;
        temp->ypos = (ypos == POS_CENTRED) ? temp->height >> 1 : ypos;
        func_80070518(displayList, temp, text, alignmentFlags);
    }
}

// render_text_string
#ifdef NON_EQUIVALENT
/**
 * Loops through a string, then draws each character onscreen.
 * Will also draw a fillrect if text backgrounds are enabled.
 */
extern u8 fontInUse;
void func_80070518(Gfx **dList, DialogueBoxBackground *box, char *text, AlignmentFlags alignmentFlags) {
    s32 fontInUse_saved;
    s32 scisOffset;
    s32 scisPos;
    s32 ypos;
    s32 xpos;
    TextureHeader *texture;
    s32 textureLrx;
    s32 textureLry;
    s32 textureS;
    s32 textureT;
    s32 textureUlx;
    s32 textureUly;
    s32 textureWidth;
    s32 textureHeight;
    s32 xAlignmentDiff;
    s32 yAlignmentDiff;
    s32 lastTextureIndex;
    s32 charIndex;
    s32 charSpace;
    s32 newData;
    s32 textureIndex;
    FontData *fontData;
    s32 newTempX;
    s32 newTempY;
    u8 curChar;

    xAlignmentDiff = -1;
    lastTextureIndex = -1;
    if (text == NULL) {
        return;
    }

    fontInUse_saved = fontInUse;
    fontInUse = box->font;
    xpos = box->xpos;
    ypos = box->ypos;
    fontData = &Font[fontInUse];
    gSPDisplayList((*dList)++, D_800A77F0);
    if (box != Window) {
        scisOffset = (((box->y2 - box->y1) + 1) / (f32) 2) * 4.0f;
        scisPos = (box->y1 + box->y2) >> 1;
        gDPSetScissor((*dList)++, 0, box->x1, scisPos - scisOffset, box->x2, scisPos + scisOffset);
    }
    if (alignmentFlags & (HORZ_ALIGN_RIGHT | HORZ_ALIGN_CENTER)) {
        xAlignmentDiff = fontStringWidth(text, xpos, box->font);
        if (alignmentFlags & HORZ_ALIGN_RIGHT) {
            xpos = (xpos - xAlignmentDiff) + 1;
        } else {
            xpos -= xAlignmentDiff >> 1;
        }
    }
    if (alignmentFlags & VERT_ALIGN_BOTTOM) {
        ypos = (ypos - fontData->y) + 1;
    }
    if (alignmentFlags & VERT_ALIGN_MIDDLE) {
        ypos -= fontData->y >> 1;
    }
    if (box->textBGColourA != 0) {
        gDPSetEnvColor((*dList)++, box->textBGColourR, box->textBGColourG, box->textBGColourB, box->textBGColourA);
        if (xAlignmentDiff == -1) {
            xAlignmentDiff = fontStringWidth(text, xpos, box->font);
        }
        gDPSetPrimColor((*dList)++, 0, 0, D_800A7868, D_800A786C, D_800A7870, 0);
        newTempX = xpos + xAlignmentDiff - 1;
        newTempY = ypos + fontData->y - 1;
        gDkrDmaDisplayList((*dList)++, &D_A7858, 2);
        gDPFillRectangle((*dList)++, xpos + box->x1, ypos + box->y1, newTempX + box->x1, newTempY + box->y1);
        gDPPipeSync((*dList)++);
    }
    gDPSetPrimColor((*dList)++, textureLry, 0, 255, 255, 255, box->opacity);
    gDPSetEnvColor((*dList)++, box->textColourR, box->textColourG, box->textColourB, box->textColourA);
    // gDkrDmaDisplayList((*dList)++, OS_K0_TO_PHYSICAL(dDialogueBoxDrawModes[0]), 2);
    // gDPPipeSync((*dList)++);
    xpos += box->textOffsetX;
    ypos += box->textOffsetY;
    for (charIndex = 0; (text[charIndex] != '\0') && (box->y2 >= ypos); xpos += charSpace, charIndex++) {
        curChar = text[charIndex];
        newData = FALSE;
        charSpace = 0;
        if (curChar <= 0x20 || curChar >= 0x80) {
            switch (curChar) {
                case ' ': // Space
                    xpos += fontData->charWidth;
                    break;
                case '\n': // Line Feed
                    xpos = box->textOffsetX;
                    ypos += fontData->y;
                    break;
                case '\t': // Tab
                    xpos += fontData->charHeight - ((xpos - box->textOffsetX) % fontData->charHeight);
                    break;
                case '\v': // VT - Vertical Tab
                    ypos += fontData->y;
                    break;
                case '\r': // Carriage Return
                    xpos = box->textOffsetX;
                    break;
                default:
                    xpos += fontData->charWidth;
                    break;
            }
        } else {
            curChar -= 0x20; // Convert lower case to upper case ASCII
            textureIndex = fontData->letter[curChar].textureID;
            if (textureIndex != 0xFF) {
                newData = TRUE;
                if (lastTextureIndex != textureIndex) {
                    lastTextureIndex = textureIndex;
                    texture = fontData->texturePointers[textureIndex];
                    gDkrDmaDisplayList((*dList)++, OS_PHYSICAL_TO_K0(texture->cmd), texture->numberOfCommands);
                }
                textureWidth = fontData->letter[curChar].width;
                textureHeight = fontData->letter[curChar].height;
                textureS = fontData->letter[curChar].s;
                textureT = fontData->letter[curChar].t;
                xAlignmentDiff = fontData->letter[curChar].lrx;
                yAlignmentDiff = fontData->letter[curChar].lry;
                charSpace = (fontData->x == 0) ? (fontData->letter[curChar].ulx) : (fontData->x);
                newData = TRUE;
            }
        }
        if (newData) {
            textureUlx = ((box->x1 + xpos) + textureWidth) * 4;
            textureUly = ((box->y1 + ypos) + textureHeight) * 4;
            textureLrx = (xAlignmentDiff * 4) + textureUlx;
            newTempY = (yAlignmentDiff * 4) + textureUly;
            textureS *= 32;
            textureT *= 32;
            if ((textureUlx < 0) && (textureLrx > 0)) {
                textureS += (-textureUlx) * 8;
                textureUlx = 0;
            }
            if ((textureUly <= (0 - 1)) && (newTempY > 0)) {
                textureT += -textureUly * 8;
                textureUly = 0;
            }
            gSPTextureRectangle((*dList)++, textureUlx, textureUly, textureLrx, newTempY, 0, textureS, textureT,
                                1 << 10, 1 << 10);
        }
        if (squash && charSpace) {
            charSpace--;
        }
    }

    box->xpos = xpos - box->textOffsetX;
    box->ypos = ypos - box->textOffsetY;
    fontInUse = fontInUse_saved;
    texDPInit(dList);
    if (box != Window) {
        camSetScissor(dList);
    }
}
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// cf. DKR render_text_string (alignment, BG fill and tab width follow the same logic; the JFG glyph path differs)
void func_80070518(Gfx **dList, DialogueBoxBackground *box, char *text, AlignmentFlags alignmentFlags) {
    Gfx *dlStart;
    Gfx *gfx;
    FontCharDataAlt *fontData;
    FontCacheLine *glyph;
    u8 *fontBytes;
    u8 *str;
    u8 *texData;
    u8 savedFont;
    u8 chr;
    u8 code;
    s32 xpos;
    s32 ypos;
    s32 strWidth;
    s32 colourFlag;
    s32 advance;
    s32 clipX1;
    s32 clipY1;
    s32 clipX2;
    s32 clipY2;
    s32 x;
    s32 y;
    s32 px;
    s32 py;
    s32 rx;
    s32 ry;
    s32 t0;
    s32 t1;
    s32 w;

    if (text == NULL) {
        return;
    }

    fontConvertString(text, printBuffer);
    savedFont = fontInUse;
    fontInUse = box->font;
    fontData = &Font[box->font];
    fontBytes = (u8 *) fontData;
    str = (u8 *) printBuffer;

    /* asm: gSPDisplayList is written to the current slot, but the write cursor is not advanced past it, so the
       following commands overwrite it. It only survives if the early clip return below is taken. */
    dlStart = *dList;
    dlStart->words.w0 = 0x06000000;
    dlStart->words.w1 = (u32) D_800A77F0;
    *dList = dlStart + 1;
    gfx = dlStart;

    if (box != Window) {
        /* asm: a failed clip test jumps straight to the epilogue (no fontInUse restore, no *dList update) */
        if (!(Window->x2 >= box->x1 && D_80104C82 >= box->y1 && box->x2 >= 0 && box->y2 >= 0)) {
            return;
        }
        clipX1 = box->x1;
        clipY1 = box->y1;
        clipX2 = box->x2;
        clipY2 = box->y2;
        if (clipX1 < 0) {
            clipX1 = 0;
        }
        if (clipY1 < 0) {
            clipY1 = 0;
        }
        if (Window->x2 < clipX2) {
            clipX2 = Window->x2;
        }
        if (D_80104C82 < clipY2) {
            clipY2 = D_80104C82;
        }
        /* gDPSetScissor (float -> int truncates, as the asm sets FCSR round-to-zero) */
        gfx->words.w0 = ((((s32) ((f32) clipX1 * 4.0f)) & 0xFFF) << 12) | 0xED000000 | (((s32) ((f32) clipY1 * 4.0f)) & 0xFFF);
        gfx->words.w1 = ((((s32) ((f32) clipX2 * 4.0f)) & 0xFFF) << 12) | (((s32) ((f32) clipY2 * 4.0f)) & 0xFFF);
        gfx++;
    }

    xpos = box->xpos;
    ypos = box->ypos;
    strWidth = -1;
    if (alignmentFlags & 5) {
        strWidth = fontStringWidth((char *) printBuffer, box->font, 0);
        if (alignmentFlags & 1) {
            xpos = (xpos - strWidth) + 1;
        } else {
            xpos -= strWidth >> 1;
        }
    }
    if (alignmentFlags & 2) {
        ypos = (ypos - fontBytes[1]) + 1;
    }
    if (alignmentFlags & 8) {
        ypos -= fontBytes[1] >> 1;
    }

    if (box->textBGColourA != 0) {
        gfx->words.w0 = 0xFB000000;
        gfx->words.w1 = (box->textBGColourR << 24) | (box->textBGColourG << 16) | (box->textBGColourB << 8) | box->textBGColourA;
        gfx++;
        if (strWidth == -1) {
            strWidth = fontStringWidth((char *) printBuffer, box->font, 0);
        }
        gfx->words.w0 = 0xFA000000;
        gfx->words.w1 = (D_800A7868 << 24) | ((D_800A786C & 0xFF) << 16) | ((D_800A7870 & 0xFF) << 8);
        gfx++;
        gfx->words.w0 = 0x07020010;
        gfx->words.w1 = (u32) D_A6E98;
        gfx++;
        /* fill rectangle: lrx = x1 + xpos + width, lry = font height + ypos + y1 */
        gfx->words.w0 = 0xF6000000 | ((((box->x1 + xpos + strWidth) & 0x3FF)) << 14) | (((fontBytes[1] + ypos + box->y1) & 0x3FF) << 2);
        gfx->words.w1 = ((((box->x1 + xpos) & 0x3FF)) << 14) | (((ypos + box->y1) & 0x3FF) << 2);
        gfx++;
        gfx->words.w0 = 0xE7000000;
        gfx->words.w1 = 0;
        gfx++;
    }

    gfx->words.w0 = 0xFA000000;
    gfx->words.w1 = box->opacity | 0xFFFFFF00;
    gfx++;
    gfx->words.w0 = 0xFB000000;
    gfx->words.w1 = (box->textColourR << 24) | (box->textColourG << 16) | (box->textColourB << 8) | box->textColourA;
    gfx++;

    colourFlag = 0;
    while (*str != 0 && box->y2 >= ypos) {
        chr = *str;
        str++;
        if (chr & 0x80) {
            code = *str;
            str++;
            if (code == 0 || code == 0xF) {
                advance = fontData->width;
            } else {
                if (buttonMode != 0) {
                    if (code == 2) {
                        gfx->words.w0 = 0xE7000000;
                        gfx->words.w1 = 0;
                        gfx++;
                        gfx->words.w0 = 0xFB000000;
                        gfx->words.w1 = 0xFFFF;
                        gfx++;
                        colourFlag = 1;
                    } else if (code == 0xE) {
                        gfx->words.w0 = 0xE7000000;
                        gfx->words.w1 = 0;
                        gfx++;
                        gfx->words.w0 = 0xFB000000;
                        gfx->words.w1 = 0x00FF00FF;
                        gfx++;
                        colourFlag = 1;
                    } else if (code >= 0x41 && code < 0x45) {
                        gfx->words.w0 = 0xE7000000;
                        gfx->words.w1 = 0;
                        gfx++;
                        gfx->words.w0 = 0xFB000000;
                        gfx->words.w1 = 0xFFFF00FF;
                        gfx++;
                        colourFlag = 1;
                    } else if (colourFlag != 0) {
                        gfx->words.w0 = 0xE7000000;
                        gfx->words.w1 = 0;
                        gfx++;
                        gfx->words.w0 = 0xFB000000;
                        gfx->words.w1 = (box->textColourR << 24) | (box->textColourG << 16) | (box->textColourB << 8) | box->textColourA;
                        gfx++;
                        colourFlag = 0;
                    }
                }

                x = box->x1 + xpos;
                y = box->y1 + ypos;
                advance = (&dxTable)[fontInUse][code];
                if (((fontBytes[0] + x) > 0) && ((fontBytes[1] + y) > 0) && (x < box->x2) && (y < box->y2)) {
                    glyph = (FontCacheLine *) func_80071B08(code);
                    if (glyph != NULL) {
                        y += glyph->fB;
                        px = x * 4;
                        py = y * 4;
                        advance = glyph->fE;
                        rx = ((glyph->fC - glyph->fA) * 4) + px;
                        ry = ((glyph->fD - glyph->fB) * 4) + py;
                        if (rx > 0 && ry > 0) {
                            t0 = glyph->fA << 5;
                            t1 = glyph->fB << 5;
                            if (px < 0) {
                                t0 -= px * 8;
                                px = 0;
                            }
                            if (py < 0) {
                                t1 -= py * 8;
                                py = 0;
                            }
                            texData = *(u8 **) (fontBytes + 0xC);
                            gfx->words.w0 = *(u32 *) texData;
                            gfx->words.w1 = (u32) ((u8 *) cache + (u16) glyph->f6);
                            gfx++;
                            texData += 8;
                            if (*(u16 *) (fontBytes + 0xA) == 4) {
                                gfx->words.w0 = 0x07060030;
                                gfx->words.w1 = (u32) texData + 0x80000000;
                                gfx++;
                                gfx->words.w0 = *(u32 *) (texData + 0x30);
                                gfx->words.w1 = (u32) ((u8 *) cache + (u16) glyph->f8);
                                gfx++;
                                texData += 0x38;
                            }
                            gfx->words.w0 = 0x07080040;
                            gfx->words.w1 = (u32) texData + 0x80000000;
                            gfx++;
                            /* texture rectangle */
                            gfx->words.w0 = 0xE4000000 | ((rx & 0xFFF) << 12) | (ry & 0xFFF);
                            gfx->words.w1 = ((px & 0xFFF) << 12) | (py & 0xFFF);
                            gfx++;
                            gfx->words.w0 = 0xB3000000;
                            gfx->words.w1 = (t0 << 16) | (t1 & 0xFFFF);
                            gfx++;
                            gfx->words.w0 = 0xB2000000;
                            gfx->words.w1 = 0x04000400;
                            gfx++;
                        }
                    }
                }
            }
            if (squash != 0 && advance != 0) {
                advance--;
            }
            xpos += advance;
        } else {
            switch (chr) {
                case 9: /* tab: advance to the next multiple of the tab width */
                    w = fontData->width * 4;
                    xpos = (xpos + w) - ((xpos - box->textOffsetX) % w);
                    break;
                case 10: /* line feed */
                    xpos = box->textOffsetX;
                    ypos += fontData->height;
                    break;
                case 11: /* vertical tab */
                    ypos += fontData->height;
                    break;
                case 13: /* carriage return */
                    xpos = box->textOffsetX;
                    break;
                default:
                    xpos += fontData->width;
                    break;
            }
        }
    }

    box->xpos = xpos - box->textOffsetX;
    box->ypos = ypos - box->textOffsetY;
    fontInUse = savedFont;
    *dList = gfx;
    texDPInit(dList);
    if (box != Window) {
        camSetScissor(dList);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/font/func_80070518.s")
#endif

#if 0 /* old NON_EQUIVALENT attempt */
typedef struct FontJpSpacing {
    u8 spacing[256]; // 256 characters in the japanese font
} FontJpSpacing;
// Japanese Font Header, 0x10 bytes
// Asset45 contains 4 font headers.
typedef struct FontData_JP {
    u8 unk0;
    u8 x;
    u8 y;
    u8 charWidth;
    u8 height;
    u8 pad[3];
    s32 offsetToData;
    s32 bytesPerCharacter;
} FontData_JP;

FontData_JP *dxTable;
s32 fontStringWidth(char *text, s32 font, s32 convertString) {
    FontCharDataAlt *currentFontSpacing;
    FontData_JP *currentFont;
    s32 glyphIndex;
    s32 length;
    s32 retLength;
    char currentChar;

    // do {
    //     currentChar = *input++;

    currentFont = (&dxTable)[font];
    currentFontSpacing = &Font[font];
    if (convertString) {
        fontConvertString(text, convertBuffer);
        text = convertBuffer;
    }
    retLength = 0;
    do {
        length += currentFont->charWidth;
        if (*text & 0x80) {
            glyphIndex = (text[1] & 0xFF) | ((text[0] & 0x7F) << 8);
            text += 2;
            if ((glyphIndex == 0) || (glyphIndex == 15)) {
                length += currentFont->charWidth;
            }
        }
        text++;
        retLength += length;
    } while (*text != '\0');
    return retLength;
}
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 fontStringWidth(char *text, s32 font, s32 convertString) {
    u8 *spacingTable;
    u8 *str;
    FontCharDataAlt *fontInfo;
    s32 width;
    u8 code;

    spacingTable = (&dxTable)[font];
    fontInfo = &Font[font];
    if (convertString != 0) {
        fontConvertString(text, convertBuffer);
        text = convertBuffer;
    }
    str = (u8 *) text;
    width = 0;
    while (*str != 0) {
        if (*str & 0x80) {
            code = str[1];
            str += 2;
            if ((code != 0) && (code != 0xF)) {
                width += spacingTable[code];
            } else {
                width += fontInfo->width;
            }
        } else {
            str++;
            width += fontInfo->width;
        }
    }
    return width;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/font/fontStringWidth.s")
#endif

/**
 * Sets the position and size of the current Window.
 */
void fontWindowSize(s32 windowId, s32 x1, s32 y1, s32 x2, s32 y2) {
    if (windowId > 0 && windowId < WINDOW_COUNT) {
        DialogueBoxBackground *temp = &Window[windowId];
        temp->xpos = 0;
        temp->ypos = 0;
        if (x1 < x2) {
            temp->x1 = (s16) x1;
            temp->x2 = (s16) x2;
        } else {
            temp->x2 = (s16) x1;
            temp->x1 = (s16) x2;
        }
        if (y1 < y2) {
            temp->y1 = (s16) y1;
            temp->y2 = (s16) y2;
        } else {
            temp->y2 = (s16) y1;
            temp->y1 = (s16) y2;
        }
        temp->width = (temp->x2 - temp->x1) + 1;
        temp->height = (temp->y2 - temp->y1) + 1;
    }
}

void fontWindowUseFont(s32 windowId, s32 font) {
    Window[windowId].font = font;
}

/**
 * Sets the background colour of the current dialogue box.
 */
void fontWindowColour(s32 windowId, s32 red, s32 green, s32 blue, s32 alpha) {
    if (windowId > 0 && windowId < WINDOW_COUNT) {
        DialogueBoxBackground *temp = &Window[windowId];
        temp->backgroundColourR = red;
        temp->backgroundColourG = green;
        temp->backgroundColourB = blue;
        temp->backgroundColourA = alpha;
    }
}

void fontWindowFontColour(s32 windowId, s32 red, s32 green, s32 blue, s32 alpha, s32 opacity) {
    if ((windowId > 0) && (windowId < WINDOW_COUNT)) {
        DialogueBoxBackground *temp;
        temp = &Window[windowId];
        temp->textColourR = red;
        temp->textColourG = green;
        temp->textColourB = blue;
        temp->textColourA = alpha;
        temp->opacity = opacity;
    }
}

void fontWindowFontBackground(s32 windowId, s32 red, s32 green, s32 blue, s32 alpha) {
    if ((windowId > 0) && (windowId < WINDOW_COUNT)) {
        DialogueBoxBackground *temp;
        temp = &Window[windowId];
        temp->textBGColourR = red;
        temp->textBGColourG = green;
        temp->textBGColourB = blue;
        temp->textBGColourA = alpha;
    }
}

void *fontWindowAddStringXY(s32 windowId, s32 posX, s32 posY, char *text, s32 number, s32 flags) {
    s32 i;
    s32 width;
    DialogueTextElement *ret;
    s32 pad;
    DialogueBox *textBox;
    DialogueBox **textBoxPtr;
    FontCharDataAlt *fontData;

    if (text == NULL) {
        return NULL;
    }

    for (i = 0, ret = NULL; i < 32 && ret == NULL; i++) {
        if (String[i].number == 255) {
            ret = &String[i];
        }
    }

    if (ret != NULL) {
        if (posX == POS_CENTRED) {
            posX = Window[windowId].width >> 1;
        }
        if (posY == POS_CENTRED) {
            posY = Window[windowId].height >> 1;
        }
        if (Window[windowId].font != FONT_UNK_FF) {
            fontData = &Font[Window[windowId].font];
            if (flags & (HORZ_ALIGN_CENTER | HORZ_ALIGN_RIGHT)) {
                func_80071A0C(text, combineBuffer, number);
                width = fontStringWidth(combineBuffer, Window[windowId].font, 1);
                if (flags & HORZ_ALIGN_RIGHT) {
                    posX = (posX - width) + 1;
                } else {
                    posX = posX - (width >> 1);
                }
            }
            if (flags & VERT_ALIGN_BOTTOM) {
                posY = (posY - fontData->ulx) + 1;
            }
            if (flags & VERT_ALIGN_MIDDLE) {
                posY -= fontData->ulx >> 1;
            }
        }
        if (Window[windowId].textBox == NULL) {
            Window[windowId].textBox = (DialogueBox *) ret;
            ret->nextBox = NULL;
        } else {
            textBoxPtr = &Window[windowId].textBox;
            textBox = *textBoxPtr;
            while (textBox != NULL && number < textBox->textNum) {
                textBoxPtr = &textBox->nextBox;
                textBox = textBox->nextBox;
            }
            *textBoxPtr = (DialogueBox *) ret;
            ret->nextBox = textBox;
        }
        ret->number = number;
        ret->text = text;
        ret->posX = posX;
        ret->posY = posY;
        ret->offsetX = 0;
        ret->offsetY = 0;
        ret->textColourR = Window[windowId].textColourR;
        ret->textColourG = Window[windowId].textColourG;
        ret->textColourB = Window[windowId].textColourB;
        ret->textColourA = Window[windowId].textColourA;
        ret->textBGColourR = Window[windowId].textBGColourR;
        ret->textBGColourG = Window[windowId].textBGColourG;
        ret->textBGColourB = Window[windowId].textBGColourB;
        ret->textBGColourA = Window[windowId].textBGColourA;
        ret->opacity = Window[windowId].opacity;
        ret->font = Window[windowId].font;
        ret->flags = Window[windowId].flags;
    }

    return ret;
}

void fontWindowFlushStrings(s32 windowId) {
    DialogueBoxBackground *dialogueBox;
    DialogueBox *dialogueTextBox, *dialogueTextBoxTemp;

    dialogueBox = &Window[windowId];
    dialogueTextBox = dialogueBox->textBox;
    if (dialogueTextBox != NULL) {
        dialogueTextBoxTemp = dialogueTextBox; // This seems redundant.
        while (dialogueTextBoxTemp != NULL) {
            dialogueTextBoxTemp->textNum = DIALOGUE_NUM_NULL;
            dialogueTextBoxTemp = dialogueTextBoxTemp->nextBox;
        }
        dialogueBox->textBox = NULL;
    }
}

void fontWindowEnable(s32 windowId) {
    Window[windowId].flags |= WINDOW_OPEN;
}

void fontWindowDisable(s32 windowId) {
    Window[windowId].flags &= WINDOW_CLOSED;
}

/**
 * Convert an integer to a string.
 */
void fontStringAddNumber(char **outString, s32 number) {
    u8 digit;
    s32 i;
    s32 hasDigit; // boolean
    s32 div;
    s32 *pow;
    char *ret = *outString;

    // Check for a negative number
    if (number < 0) {
        *ret = '-';
        ret++;
        number = -number;
    }

    // Loop through digit places.
    hasDigit = FALSE;
    for (i = 0; D_800A7874[i] != 0; i++) {
        digit = '0';
        pow = &D_800A7874[i];
        if (number >= *pow) {
            div = number / *pow;
            number -= div * *pow;
            digit += div;
            hasDigit = TRUE;
        }
        if (hasDigit) {
            *ret = digit;
            ret++;
        }
    }

    // One's digit place
    *ret++ = '0' + number;
    *outString = ret;
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fontWindowDraw(Gfx **dlist, void **mtxp, void **vtxp, s32 windowId);

void fontWindowsDraw(Gfx **dlist, void **mtxp, void **vtxp) {
    DialogueBoxBackground *window = &D_80104CA0;
    s32 windowId;

    for (windowId = 1; windowId < 8; windowId++) {
        if (window->flags & 0x8000) {
            fontWindowDraw(dlist, NULL, NULL, windowId);
        }
        window++;
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/font/fontWindowsDraw.s")
#endif

// render_fill_rectangle
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void func_80071564(Gfx **dlist, u32 ulx, u32 uly, s32 lrx, s32 lry) {
    s32 width;
    s32 height;
    u32 *cmd;

    viGetCurrentSize(&width, &height);
    if ((lrx >= 0) && (ulx < (u32) width) && (lry >= 0)) {
        if (uly < (u32) height) {
            if ((s32) ulx < 0) {
                ulx = 0;
            }
            if ((s32) uly < 0) {
                uly = 0;
            }
            cmd = (u32 *) *dlist;
            *dlist = (Gfx *) (cmd + 2);
            cmd[1] = ((ulx & 0x3FF) << 14) | ((uly & 0x3FF) * 4);
            cmd[0] = 0xF6000000 | ((lrx & 0x3FF) << 14) | ((lry & 0x3FF) * 4);
        }
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/font/func_80071564.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void fontWindowDraw(Gfx **dlist, void **mtxp, void **vtxp, s32 windowId) {
    DialogueBoxBackground *win = &Window[windowId];
    DialogueBox *box;
    Gfx *g;
    s8 *stripe;
    s32 stripeX;
    s32 top;
    s32 bot;
    s16 x1;
    s16 x2;
    s16 y1;
    s16 y2;

    if (win->backgroundColourA != 0) {
        gSPDisplayList((*dlist)++, D_800A77F0);
        gDPSetPrimColor((*dlist)++, 0, 0, D_800A7868, D_800A786C, D_800A7870, 0);
        g = *dlist;
        *dlist = g + 1;
        g->words.w0 = 0x07020010;
        g->words.w1 = (uintptr_t) D_A6E98;
        gDPSetEnvColor((*dlist)++, 0, 0, 0, 0);

        x1 = win->x1;
        x2 = win->x2;
        y1 = win->y1;
        y2 = win->y2;
        if (((x2 - x1) < 10) || ((y2 - y1) < 10)) {
            func_80071564(dlist, x1 - 2, y1 - 2, x2 + 2, y2 + 2);
        } else {
            func_80071564(dlist, x1 - 2, y1 + 2, x1 + 2, y2 - 2);
            func_80071564(dlist, x1 - 2, y1 - 2, x2 + 2, y1 + 2);
            func_80071564(dlist, x2 - 2, y1 + 2, x2 + 2, y2 - 2);
            func_80071564(dlist, x1 - 2, y2 - 2, x2 + 2, y2 + 2);
        }

        gDPPipeSync((*dlist)++);
        gDPSetEnvColor((*dlist)++, win->backgroundColourR, win->backgroundColourG, win->backgroundColourB,
                       win->backgroundColourA);

        stripe = D_800A78A0;
        if (stripe[0] >= 0) {
            stripeX = stripe[0];
            do {
                top = (stripe[1] != 0) ? (stripe[2] + win->y2) : (stripe[2] + win->y1);
                bot = (stripe[3] != 0) ? (stripe[4] + win->y2) : (stripe[4] + win->y1);
                func_80071564(dlist, stripeX + win->x1, top, win->x2 - stripeX, bot);
                stripeX = stripe[5];
                stripe += 5;
            } while (stripeX >= 0);
        }
        gDPPipeSync((*dlist)++);
    }

    box = win->textBox;
    if (box != NULL) {
        do {
            win->xpos = box->x1 + box->x2;
            win->ypos = box->y1 + box->y2;
            win->textColourR = box->textColourR;
            win->textColourG = box->textColourG;
            win->textColourB = box->textColourB;
            win->textColourA = box->textColourA;
            win->textBGColourR = box->textBGColourR;
            win->textBGColourG = box->textBGColourG;
            win->textBGColourB = box->textBGColourB;
            win->textBGColourA = box->textBGColourA;
            win->opacity = box->opacity;
            win->font = box->font;
            func_80071A0C(box->text, combineBuffer, (s32) box->textNum);
            func_80070518(dlist, win, combineBuffer, ALIGN_TOP_LEFT);
            box = box->nextBox;
        } while (box != NULL);
    }
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/font/fontWindowDraw.s")
#endif

void fontStringAddNumber(char **outString, s32 number);
// parse_string_with_number
void func_80071A0C(char *input, char *output, s32 number) {
    char currentChar;

    do {
        currentChar = *input++;
        if (currentChar & 0x80) {
            char nextChar = *input++;
            if (nextChar == 0xE) {
                fontStringAddNumber(&output, number);
            } else {
                *output++ = currentChar;
                *output++ = nextChar;
            }
        } else if (currentChar == '~') { // ~ is equivalent to a %d.
            fontStringAddNumber(&output, number);
        } else {
            *output++ = currentChar;
        }
    } while (currentChar);
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
void *func_80071B08(u8 arg0) {
    FontCacheLine *found = NULL;
    FontCacheLine *cur;
    FontCacheLine *run = NULL;
    u8 *fontEnt = (u8 *) Font + fontInUse * 0x10;
    u32 need;
    u32 lastOld;
    u32 hdr[4];
    u8 *blk;
    s32 idx;
    s32 runLen = 0;
    s32 k;
    s32 i;
    u8 tmp;

    cur = (FontCacheLine *) cacheLine;
    for (idx = 0; idx < 0x100 && found == NULL; idx++, cur++) {
        if (fontInUse == cur->font && arg0 == cur->charIdx) {
            found = cur;
        }
    }

    if (found != NULL) {
        cur = found;
        do {
            cur->state = 2;
            cur++;
        } while (cur->chain != 0);
        return found;
    }

    need = ((u32) (*(s16 *) (fontEnt + 8) + 0x6F)) >> 7;
    lastOld = need;
    if (need != 0) {
        cur = (FontCacheLine *) cacheLine;
        idx = 0;
        do {
            idx++;
            if (cur->state == 0) {
                if (runLen == 0) {
                    run = cur;
                }
                runLen++;
            } else {
                runLen = 0;
            }
            cur++;
        } while (idx < 0x100 && runLen != (s32) need);
    }

    if (runLen != (s32) need) {
        return NULL;
    }

    cur = run;
    k = (s32) need - 1;
    if (k >= 0) {
        do {
            lastOld = cur->chain;
            cur->chain = (u8) k;
            k--;
            cur->font = fontInUse;
            cur->charIdx = arg0;
            cur->state = 2;
            cur++;
        } while (k >= 0);
    }
    if (lastOld != 0) {
        do {
            tmp = cur->chain;
            cur->font = 0xFF;
            cur->chain = 0;
            cur++;
        } while (tmp != 0);
    }

    blk = (u8 *) cache + run->offset - 0x10;
    for (i = 0; i < 4; i++) {
        hdr[i] = *(u32 *) (blk + i * 4);
    }
    piRomLoadSection(0x3B, (u32) blk, *(s32 *) (fontEnt + 4) + arg0 * *(s16 *) (fontEnt + 8),
                     *(s16 *) (fontEnt + 8));
    run->f6 = (s16) ((run->offset + *(u16 *) blk) - 0x10);
    run->f8 = (s16) ((run->offset + *(u16 *) (blk + 2)) - 0x10);
    run->fA = blk[4];
    run->fB = blk[5];
    run->fC = blk[6];
    run->fD = blk[7];
    run->fE = blk[8];
    for (i = 0; i < 4; i++) {
        *(u32 *) (blk + i * 4) = hdr[i];
    }
    return run;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/font/func_80071B08.s")
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// cf. DKR font texture upload. JFG builds one 0x80-byte RDP block per glyph (16 Gfx slots):
// slot 0 SETTIMG(cache), 1 SETTILE, 2 RDPLOADSYNC, 3 LOADBLOCK, 4 LOADSYNC, 5 SETTILE (line/size),
// 6 SETTILESIZE (glyph w/h), then a 2-Gfx tail copied from a per-case table (D_800A78xx).
// Case 4 uploads a second texture into slots 7-13. Default (type >= 8) writes only the tail.
void fontCreateDisplayList(FontCharDataAlt *fontData) {
    u8 *fontBytes = (u8 *) fontData;
    Gfx *dl;
    u32 *tail;
    s32 tailIdx;
    s32 w;
    s32 h;
    s32 area;
    s32 count;
    u16 type;

    dl = (Gfx *) mmAlloc(0x80, 0xFF0000FF);
    *(Gfx **) (fontBytes + 0xC) = dl;
    if (dl == NULL) {
        return;
    }

    type = *(u16 *) (fontBytes + 0xA);
    w = fontBytes[0];
    h = fontBytes[1];
    area = w * h;

    switch (type) {
        case 0:
            dl[0].words.w0 = 0xFD700000;
            dl[0].words.w1 = (u32) cache;
            dl[1].words.w0 = 0xF5700000;
            dl[1].words.w1 = 0x07020080;
            dl[2].words.w0 = 0xE6000000;
            dl[2].words.w1 = 0;
            count = ((area + 3) >> 2) - 1;
            if (count >= 0x7FF) {
                count = 0x7FF;
            }
            dl[3].words.w0 = 0xF3000000;
            dl[3].words.w1 = ((count & 0xFFF) << 12) | 0x07000000;
            dl[4].words.w0 = 0xE7000000;
            dl[4].words.w1 = 0;
            dl[5].words.w0 = (((((w >> 1) + 7) >> 3) & 0x1FF) << 9) | 0xF5600000;
            dl[5].words.w1 = 0x00020080;
            dl[6].words.w0 = 0xF2000000;
            dl[6].words.w1 = (((((w - 1) * 4) & 0xFFF)) << 12) | (((h - 1) * 4) & 0xFFF);
            tailIdx = 7;
            tail = D_800A7828;
            break;
        case 1:
            dl[0].words.w0 = 0xFD700000;
            dl[0].words.w1 = (u32) cache;
            dl[1].words.w0 = 0xF5700000;
            dl[1].words.w1 = 0x07020080;
            dl[2].words.w0 = 0xE6000000;
            dl[2].words.w1 = 0;
            count = ((area + 1) >> 1) - 1;
            if (count >= 0x7FF) {
                count = 0x7FF;
            }
            dl[3].words.w0 = 0xF3000000;
            dl[3].words.w1 = ((count & 0xFFF) << 12) | 0x07000000;
            dl[4].words.w0 = 0xE7000000;
            dl[4].words.w1 = 0;
            dl[5].words.w0 = (((((w + 7) >> 3)) & 0x1FF) << 9) | 0xF5680000;
            dl[5].words.w1 = 0x00020080;
            dl[6].words.w0 = 0xF2000000;
            dl[6].words.w1 = (((((w - 1) * 4) & 0xFFF)) << 12) | (((h - 1) * 4) & 0xFFF);
            tailIdx = 7;
            tail = D_800A7828;
            break;
        case 2:
            dl[0].words.w0 = 0xFD180000;
            dl[0].words.w1 = (u32) cache;
            dl[1].words.w0 = 0xF5180000;
            dl[1].words.w1 = 0x07020080;
            dl[2].words.w0 = 0xE6000000;
            dl[2].words.w1 = 0;
            count = area - 1;
            if (count >= 0x7FF) {
                count = 0x7FF;
            }
            dl[3].words.w0 = 0xF3000000;
            dl[3].words.w1 = ((count & 0xFFF) << 12) | 0x07000000;
            dl[4].words.w0 = 0xE7000000;
            dl[4].words.w1 = 0;
            dl[5].words.w0 = (((((w * 2) + 7) >> 3) & 0x1FF) << 9) | 0xF5180000;
            dl[5].words.w1 = 0x00020080;
            dl[6].words.w0 = 0xF2000000;
            dl[6].words.w1 = (((((w - 1) * 4) & 0xFFF)) << 12) | (((h - 1) * 4) & 0xFFF);
            tailIdx = 7;
            tail = D_800A7828;
            break;
        case 3:
            dl[0].words.w0 = 0xFD100000;
            dl[0].words.w1 = (u32) cache;
            dl[1].words.w0 = 0xF5100000;
            dl[1].words.w1 = 0x07020080;
            dl[2].words.w0 = 0xE6000000;
            dl[2].words.w1 = 0;
            count = area - 1;
            if (count >= 0x7FF) {
                count = 0x7FF;
            }
            dl[3].words.w0 = 0xF3000000;
            dl[3].words.w1 = ((count & 0xFFF) << 12) | 0x07000000;
            dl[4].words.w0 = 0xE7000000;
            dl[4].words.w1 = 0;
            dl[5].words.w0 = (((((w * 2) + 7) >> 3) & 0x1FF) << 9) | 0xF5100000;
            dl[5].words.w1 = 0x00020080;
            dl[6].words.w0 = 0xF2000000;
            dl[6].words.w1 = (((((w - 1) * 4) & 0xFFF)) << 12) | (((h - 1) * 4) & 0xFFF);
            tailIdx = 7;
            tail = D_800A7828;
            break;
        case 4:
            dl[0].words.w0 = 0xFD100000;
            dl[0].words.w1 = (u32) cache;
            dl[1].words.w0 = 0xF5100000;
            dl[1].words.w1 = 0x07020080;
            dl[2].words.w0 = 0xE6000000;
            dl[2].words.w1 = 0;
            count = area - 1;
            if (count >= 0x7FF) {
                count = 0x7FF;
            }
            dl[3].words.w0 = 0xF3000000;
            dl[3].words.w1 = ((count & 0xFFF) << 12) | 0x07000000;
            dl[4].words.w0 = 0xE7000000;
            dl[4].words.w1 = 0;
            dl[5].words.w0 = (((((w * 2) + 7) >> 3) & 0x1FF) << 9) | 0xF5100000;
            dl[5].words.w1 = 0x00020080;
            dl[6].words.w0 = 0xF2000000;
            dl[6].words.w1 = (((((w - 1) * 4) & 0xFFF)) << 12) | (((h - 1) * 4) & 0xFFF);
            dl[7].words.w0 = 0xFD900000;
            dl[7].words.w1 = (u32) cache;
            dl[8].words.w0 = 0xF5900100;
            dl[8].words.w1 = 0x07020080;
            dl[9].words.w0 = 0xE6000000;
            dl[9].words.w1 = 0;
            count = ((area + 3) >> 2) - 1;
            if (count >= 0x7FF) {
                count = 0x7FF;
            }
            dl[10].words.w0 = 0xF3000000;
            dl[10].words.w1 = ((count & 0xFFF) << 12) | 0x07000000;
            dl[11].words.w0 = 0xE7000000;
            dl[11].words.w1 = 0;
            dl[12].words.w0 = (((((w >> 1) + 7) >> 3) & 0x1FF) << 9) | 0xF5800100;
            dl[12].words.w1 = 0x01020080;
            dl[13].words.w0 = 0xF2000000;
            dl[13].words.w1 = (((((w - 1) * 4) & 0xFFF)) << 12) | 0x01000000 | (((h - 1) * 4) & 0xFFF);
            tailIdx = 14;
            tail = D_800A7838;
            break;
        case 5:
            dl[0].words.w0 = 0xFD900000;
            dl[0].words.w1 = (u32) cache;
            dl[1].words.w0 = 0xF5900000;
            dl[1].words.w1 = 0x07020080;
            dl[2].words.w0 = 0xE6000000;
            dl[2].words.w1 = 0;
            count = ((area + 3) >> 2) - 1;
            if (count >= 0x7FF) {
                count = 0x7FF;
            }
            dl[3].words.w0 = 0xF3000000;
            dl[3].words.w1 = ((count & 0xFFF) << 12) | 0x07000000;
            dl[4].words.w0 = 0xE7000000;
            dl[4].words.w1 = 0;
            dl[5].words.w0 = (((((w >> 1) + 7) >> 3) & 0x1FF) << 9) | 0xF5800000;
            dl[5].words.w1 = 0x00020080;
            dl[6].words.w0 = 0xF2000000;
            dl[6].words.w1 = (((((w - 1) * 4) & 0xFFF)) << 12) | (((h - 1) * 4) & 0xFFF);
            tailIdx = 7;
            tail = D_800A7828;
            break;
        case 6:
            dl[0].words.w0 = 0xFD900000;
            dl[0].words.w1 = (u32) cache;
            dl[1].words.w0 = 0xF5900000;
            dl[1].words.w1 = 0x07020080;
            dl[2].words.w0 = 0xE6000000;
            dl[2].words.w1 = 0;
            count = ((area + 1) >> 1) - 1;
            if (count >= 0x7FF) {
                count = 0x7FF;
            }
            dl[3].words.w0 = 0xF3000000;
            dl[3].words.w1 = ((count & 0xFFF) << 12) | 0x07000000;
            dl[4].words.w0 = 0xE7000000;
            dl[4].words.w1 = 0;
            dl[5].words.w0 = (((((w + 7) >> 3)) & 0x1FF) << 9) | 0xF5880000;
            dl[5].words.w1 = 0x00020080;
            dl[6].words.w0 = 0xF2000000;
            dl[6].words.w1 = (((((w - 1) * 4) & 0xFFF)) << 12) | (((h - 1) * 4) & 0xFFF);
            tailIdx = 7;
            tail = D_800A7828;
            break;
        case 7:
            dl[0].words.w0 = 0xFD900000;
            dl[0].words.w1 = (u32) cache;
            dl[1].words.w0 = 0xF5900000;
            dl[1].words.w1 = 0x07020080;
            dl[2].words.w0 = 0xE6000000;
            dl[2].words.w1 = 0;
            count = ((area + 3) >> 2) - 1;
            if (count >= 0x7FF) {
                count = 0x7FF;
            }
            dl[3].words.w0 = 0xF3000000;
            dl[3].words.w1 = ((count & 0xFFF) << 12) | 0x07000000;
            dl[4].words.w0 = 0xE7000000;
            dl[4].words.w1 = 0;
            dl[5].words.w0 = (((((w >> 1) + 7) >> 3) & 0x1FF) << 9) | 0xF5800000;
            dl[5].words.w1 = 0x00020080;
            dl[6].words.w0 = 0xF2000000;
            dl[6].words.w1 = (((((w - 1) * 4) & 0xFFF)) << 12) | (((h - 1) * 4) & 0xFFF);
            tailIdx = 7;
            tail = D_800A7848;
            break;
        default:
            tailIdx = 0;
            tail = D_800A7828;
            break;
    }

    dl[tailIdx].words.w0 = tail[0];
    dl[tailIdx].words.w1 = tail[1];
    dl[tailIdx + 1].words.w0 = tail[2];
    dl[tailIdx + 1].words.w1 = tail[3];
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/font/fontCreateDisplayList.s")
#endif

// char D_800A78C4[] = {
//     0x0F, 0x34, 0x0A, 0x36, 0x02, 0x06, 0x0D, 0x37, 0x03, 0x04, 0x38, 0x39, 0x3A, 0x3B, 0x3C, 0x3D,
//     0x10, 0x11, 0x12, 0x13, 0x14, 0x15, 0x16, 0x17, 0x18, 0x19, 0x3E, 0x05, 0x0B, 0x3F, 0x0C, 0x40,
//     0x41, 0x1A, 0x1B, 0x1C, 0x1D, 0x1E, 0x1F, 0x20, 0x21, 0x22, 0x23, 0x24, 0x25, 0x26, 0x27, 0x28,
//     0x29, 0x2A, 0x2B, 0x2C, 0x2D, 0x2E, 0x2F, 0x30, 0x31, 0x32, 0x33, 0x07, 0x0F, 0x08, 0x0F, 0x0F,
//     0x09, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F, 0xA0, 0xA1, 0xA2, 0xA3,
//     0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0x03, 0x0F, 0x04, 0x0E, 0x0F,
// };
void fontConvertString(char *inString, char *outString) {
    char currentChar;
    char *conversionTable = D_800A78C4;

    do {
        currentChar = *inString++;
        if (currentChar & 0x80) {
            *outString++ = currentChar;
            *outString++ = *inString++;
        } else if (currentChar < 32) {
            *outString++ = currentChar;
        } else {
            *outString++ = 0x80;
            *outString++ = conversionTable[currentChar - 32];
        }
    } while (currentChar);
}

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
u8 *fontGetLine(s32 arg0, u8 *arg1, s32 arg2, u8 **arg3) {
    u8 *s = arg1;
    u8 *segStart;
    u8 *tbl;
    u8 *w;
    s32 total = 0;
    s32 first = 1;
    s32 wrapped = 0;
    s32 atEnd = 0;
    s32 inEscape;
    s32 segWidth;
    u8 ch;
    u8 code;

    for (;;) {
        inEscape = 0;
        segWidth = 0;
        segStart = s;
        for (;;) {
            ch = s[0];
            if (ch == 0x80 && s[1] == 0xF) {
                s += 2;
                if (first == 0) {
                    segWidth += Font[arg0].width;
                }
            } else if (ch == 0) {
                atEnd = 1;
            } else if (ch != 0x80) {
                s += 1;
            } else {
                inEscape = 1;
            }
            if (inEscape != 0 || atEnd != 0) {
                break;
            }
        }
        if (first != 0) {
            first = 0;
            if (atEnd != 0) {
                return NULL;
            }
            *arg3 = s;
        }
        ch = s[0];
        if (ch == 0x80 && s[1] != 0xF) {
            tbl = (&dxTable)[arg0];
            code = s[1];
            w = tbl + code;
            for (;;) {
                segWidth += *w;
                ch = s[2];
                s += 2;
                if (ch != 0x80) {
                    break;
                }
                code = s[1];
                if (code == 0xF) {
                    break;
                }
                w = tbl + code;
            }
        }
        total += segWidth;
        if (arg2 < total) {
            ch = *segStart;
            wrapped = 1;
            total -= segWidth;
            s = segStart;
        }
        if (ch == 0) {
            atEnd = 1;
        }
        if (wrapped != 0 || atEnd != 0) {
            break;
        }
    }
    if (s == *arg3) {
        return NULL;
    }
    return s;
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/font/fontGetLine.s")
#endif

u8 fontYSpacing(s32 arg0) {
    return Font[arg0].height;
}
