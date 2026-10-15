#include "common.h"
#include "stdarg.h"

#define RENDER_PRINTF_CMD_ARG_BYTE(val) \
    *D_800A6D44 = val;                  \
    D_800A6D44++;
#define RENDER_PRINTF_CMD_ARG_SHORT(val) RENDER_PRINTF_CMD_ARG_BYTE(val) RENDER_PRINTF_CMD_ARG_BYTE(val >> 8)

#define RENDER_PRINTF_CMD_END RENDER_PRINTF_CMD_ARG_BYTE(0)

#define RENDER_PRINTF_CMD_SET_COLOR(red, green, blue, alpha) \
    RENDER_PRINTF_CMD_ARG_BYTE(0x81)                         \
    RENDER_PRINTF_CMD_ARG_BYTE(red)                          \
    RENDER_PRINTF_CMD_ARG_BYTE(green)                        \
    RENDER_PRINTF_CMD_ARG_BYTE(blue)                         \
    RENDER_PRINTF_CMD_ARG_BYTE(alpha)                        \
    RENDER_PRINTF_CMD_END

// This is a bit hacky, but it matches.
#define RENDER_PRINTF_CMD_SET_POSITION(x, y) \
    u16 tempX, tempY;                        \
    RENDER_PRINTF_CMD_ARG_BYTE(0x82)         \
    RENDER_PRINTF_CMD_ARG_BYTE(x & 0xFF)     \
    tempX = x >> 8;                          \
    RENDER_PRINTF_CMD_ARG_BYTE(tempX)        \
    RENDER_PRINTF_CMD_ARG_BYTE(y & 0xFF)     \
    tempY = y >> 8;                          \
    RENDER_PRINTF_CMD_ARG_BYTE(tempY)        \
    RENDER_PRINTF_CMD_END

#define RENDER_PRINTF_CMD_SET_BACKGROUND_COLOR(red, green, blue, alpha) \
    RENDER_PRINTF_CMD_ARG_BYTE(0x85)                                    \
    RENDER_PRINTF_CMD_ARG_BYTE(red)                                     \
    RENDER_PRINTF_CMD_ARG_BYTE(green)                                   \
    RENDER_PRINTF_CMD_ARG_BYTE(blue)                                    \
    RENDER_PRINTF_CMD_ARG_BYTE(alpha)                                   \
    RENDER_PRINTF_CMD_END

/**
 * memset(void *s, int c, size_t n)
 *
 * s: start of area to clear
 * c: char to fill with
 * n: size of area to clear
 */
void *memset(void *s, int c, size_t n) {
    u8 *var_v0 = s;

    while (n-- > 0) {
        *var_v0++ = c;
    }
    return s;
}

const char _itoa_lower_digits[] = "0123456789abcdefghijklmnopqrstuvwxyz";
const char _itoa_upper_digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

/**
 * Standard C Library function that converts integers to strings.
 * Exact match to glibc 1.09 version.
 */
char *_itoa(unsigned long long int n, char *buflim, unsigned int base, int upper_case) {
    /* Base-36 digits for numbers. */
    const char *alphabet = upper_case ? _itoa_upper_digits : _itoa_lower_digits;
    register char *bp = buflim;

    while (n > 0) {
        *(--bp) = alphabet[n % base];
        n /= base;
    }

    return bp;
}

void sprintfSetSpacingCodes(s32 arg0) {
    D_800A6D40 = arg0;
}

UNUSED int sprintf(char *s, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    vsprintf(s, fmt, args);
    va_end(args);
}

const char D_800AE450[] = "";
#ifdef NON_MATCHING
const char D_800AE454[] = "(null)";
const char D_800AE45C[] = "(nil)";
#endif

#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
// Rare's debug printf formatter. Structure cf. DKR printf.c vsprintf (glibc 1.09 style).
// The asm walks the varargs by hand: align the cursor, read the word, advance past it.
// Float args are read as a pointer to f32 (lw + lwc1 0(ptr)); float math is single precision.
#define VS_NEXT4(ap, slot) ((slot) = (char *)(((u32)(ap) + 3) & ~3), (ap) = (slot) + 4)
#define VS_NEXT8(ap, slot) ((slot) = (char *)(((u32)(ap) + 7) & ~7), (ap) = (slot) + 8)
#define VS_OUT(c) (done++, *out++ = (c))
#define VS_PAD(c)     \
    while (width-- > 0) { \
        VS_OUT(c);    \
    }

/* sig: asm takes the va cursor as its 3rd argument; the header declares this variadic. */
s32 vsprintf(char *s, const char *fmt, ...) {
    va_list vargs;
    char *args;
    char *out = s;
    const char *f = fmt;
    const char *p;
    s32 done = 0;

    va_start(vargs, fmt);
    args = *(char **)vargs;

    while (*f != '\0') {
        s32 is_short;
        s32 is_long;
        s32 is_longlong;
        s32 space;
        s32 showsign;
        s32 left;
        s32 alt;
        char pad;
        s32 width;
        s32 prec;
        s32 is_neg;
        char fc;
        s32 base;
        u64 num;
        s64 signed_num;
        char work[0x100];
        char *slot;
        s32 digit;
        s32 len;
        const char *str;
        void *ptr;

        if (*f != '%') {
            while (*f != '%' && *f != '\0') {
                VS_OUT(*f++);
            }
            continue;
        }

        ++f;

        /* "%%" prints a single percent sign. */
        if (*f == '%') {
            ++f;
            VS_OUT('%');
            continue;
        }

        /* Flags. */
        space = showsign = left = alt = 0;
        pad = ' ';
        while (*f == ' ' || *f == '+' || *f == '-' || *f == '#' || *f == '0') {
            switch (*f++) {
                case ' ':
                    space = 1;
                    break;
                case '+':
                    showsign = 1;
                    break;
                case '-':
                    left = 1;
                    break;
                case '#':
                    alt = 1;
                    break;
                case '0':
                    pad = '0';
                    break;
            }
        }
        if (left) {
            pad = ' ';
        }

        /* Field width, possibly from an argument (negative means left-justify). */
        width = 0;
        if (*f == '*') {
            VS_NEXT4(args, slot);
            width = *(s32 *)slot;
            if (width < 0) {
                width = -width;
                left = 1;
            }
            ++f;
        } else {
            while (*f >= '0' && *f <= '9') {
                width *= 10;
                width += *f++ - '0';
            }
        }

        /* Precision, -1 means none given. */
        prec = -1;
        if (*f == '.') {
            ++f;
            if (*f == '*') {
                VS_NEXT4(args, slot);
                prec = *(s32 *)slot;
                if (prec < 0) {
                    prec = -1;
                }
                ++f;
            } else if (*f >= '0' && *f <= '9') {
                prec = 0;
                while (*f >= '0' && *f <= '9') {
                    prec *= 10;
                    prec += *f++ - '0';
                }
            }
        }

        /* Length modifiers. is_longlong is the asm's a0, is_long a1, is_short a2. */
        is_short = is_long = is_longlong = 0;
        while (*f == 'h' || *f == 'l' || *f == 'L' || *f == 'Z' || *f == 'q') {
            switch (*f++) {
                case 'h':
                    is_short = 1;
                    break;
                case 'l':
                    if (is_long) {
                        is_longlong = 1;
                    } else {
                        is_long = 1;
                    }
                    break;
                case 'L':
                    is_longlong = 1;
                    break;
                case 'Z':
                    is_long = 1;
                    break;
                case 'q':
                    is_longlong = 1;
                    break;
            }
        }

        fc = *f++;
        switch (fc) {
            case 'i':
            case 'd':
                base = 10;
                if (is_longlong) {
                    VS_NEXT8(args, slot);
                    signed_num = *(s64 *)slot;
                } else if (is_long || !is_short) {
                    VS_NEXT4(args, slot);
                    signed_num = *(s32 *)slot;
                } else {
                    VS_NEXT4(args, slot);
                    signed_num = *(s16 *)(slot + 2); /* big-endian low halfword */
                }
                is_neg = signed_num < 0;
                num = is_neg ? -signed_num : signed_num;
                goto number;
            case 'u':
                base = 10;
                goto unsigned_number;
            case 'o':
                base = 8;
                goto unsigned_number;
            case 'X':
                base = 16;
                goto unsigned_number;
            case 'x':
                base = 16;
            unsigned_number:
                if (is_longlong) {
                    VS_NEXT8(args, slot);
                    num = *(u64 *)slot;
                } else if (is_long || !is_short) {
                    VS_NEXT4(args, slot);
                    num = *(u32 *)slot;
                } else {
                    VS_NEXT4(args, slot);
                    num = *(u16 *)(slot + 2); /* big-endian low halfword */
                }
                /* ANSI only specifies the '+' and ' ' flags for signed conversions. */
                is_neg = showsign = space = 0;
            number: {
                char *w;
                char *workend = &work[sizeof(work) - 1];

                if (D_800A6D40) {
                    VS_OUT(0x84);
                }
                if (prec >= 0) {
                    pad = ' ';
                }
                /* Supply a default precision if none was given. */
                if (prec == -1) {
                    prec = 1;
                }

                w = _itoa(num, workend + 1, base, fc == 'X') - 1;
                width -= workend - w;
                prec -= workend - w;

                if (alt && base == 8 && prec <= 0) {
                    *w-- = '0';
                    width--;
                }
                if (prec > 0) {
                    width -= prec;
                    while (prec-- > 0) {
                        *w-- = '0';
                    }
                }
                if (alt && base == 16) {
                    width -= 2;
                }
                if (is_neg || showsign || space) {
                    width--;
                }

                if (!left && pad == ' ') {
                    VS_PAD(' ');
                }
                if (is_neg) {
                    VS_OUT('-');
                } else if (showsign) {
                    VS_OUT('+');
                } else if (space) {
                    VS_OUT(' ');
                }
                if (alt && base == 16) {
                    VS_OUT('0');
                    VS_OUT(fc);
                }
                if (!left && pad == '0') {
                    VS_PAD('0');
                }

                /* Write the number. */
                while (++w <= workend) {
                    VS_OUT(*w);
                }

                if (left) {
                    VS_PAD(' ');
                }
            } break;

            case 'e':
            case 'E': {
                s32 showDash;
                s32 length;
                s32 exponent;
                f32 spD0;
                f32 f02;
                f32 f16;
                f32 f0;

                showDash = FALSE;
                if (D_800A6D40) {
                    VS_OUT(0x84);
                }
                if (prec < 0) {
                    prec = 6;
                }

                VS_NEXT4(args, slot);
                spD0 = **(f32 **)slot;

                if (*((s8 *)&spD0) < 0) {
                    showDash = TRUE;
                    spD0 = -spD0;
                }

                /* Scale spD0 into [1, 10) and track the decimal exponent. */
                exponent = 0;
                if (spD0 == 0.0f) {
                    f16 = 1.0f;
                } else if (spD0 < 1.0f) {
                    f16 = 1.0f;
                    do {
                        f16 /= 10.0f;
                        exponent--;
                    } while (spD0 < f16);
                }
                if (spD0 >= 1.0f) {
                    exponent = 0;
                    f16 = 1.0f;
                    f0 = 10.0f;
                    while (f0 <= spD0) {
                        f16 = f0;
                        f0 *= 10.0f;
                        exponent++;
                    }
                }

                f02 = f16 * 0.5f;
                for (digit = prec; digit > 0; digit--) {
                    f02 /= 10.0f;
                }

                spD0 += f02;
                if (spD0 >= f16 * 10.0f) {
                    f16 = f16 * 10.0f;
                    exponent++;
                }

                length = (showDash || showsign || space) + prec + (prec > 0 || alt) + (exponent >= 100) + 5;

                if (!left && pad == ' ') {
                    while (width-- > length) {
                        VS_OUT(pad);
                    }
                }

                if (showDash) {
                    VS_OUT('-');
                } else if (showsign) {
                    VS_OUT('+');
                } else if (space) {
                    VS_OUT(' ');
                }

                if (!left && pad == '0') {
                    while (width-- > length) {
                        VS_OUT(pad);
                    }
                }

                digit = '0';
                while (spD0 >= f16) {
                    spD0 -= f16;
                    digit++;
                }
                VS_OUT(digit);
                f16 /= 10.0f;

                if (prec > 0 || alt) {
                    VS_OUT('.');
                }

                while (prec > 0) {
                    digit = '0';
                    while (spD0 >= f16) {
                        spD0 -= f16;
                        digit++;
                    }
                    VS_OUT(digit);
                    f16 /= 10.0f;
                    prec--;
                }

                VS_OUT(fc);

                if (exponent < 0) {
                    exponent = -exponent;
                    VS_OUT('-');
                } else {
                    VS_OUT('+');
                }

                if (exponent >= 100) {
                    VS_OUT('0' + (exponent / 100));
                }
                VS_OUT('0' + ((exponent / 10) % 10));
                VS_OUT('0' + (exponent % 10));

                if (left) {
                    while (width-- > length) {
                        VS_OUT(' ');
                    }
                }
                break;
            }

            case 'G':
            case 'g':
                break;

            case 'f': {
                f32 f12 = 1.0f;
                f32 f14;
                f32 f2;
                s32 length;
                s32 showDash;
                f32 spD0;

                showDash = FALSE;
                if (D_800A6D40) {
                    VS_OUT(0x84);
                }
                if (prec < 0) {
                    prec = 6;
                }

                for (digit = 0; digit < prec; digit++) {
                    f12 /= 10.0f;
                }

                VS_NEXT4(args, slot);
                spD0 = **(f32 **)slot;

                if (spD0 < 0.0f) {
                    showDash = TRUE;
                    spD0 = -spD0;
                }

                spD0 += f12 * 0.5f;

                digit = 1;
                f2 = 1.0f;
                f14 = 10.0f;
                while (spD0 >= f14) {
                    f2 = f14;
                    f14 *= 10.0f;
                    digit++;
                }

                length = (showDash || showsign || space) + (prec > 0 || alt) + digit + prec;
                if (!left && pad == ' ') {
                    while (width-- > length) {
                        VS_OUT(pad);
                    }
                }

                if (showDash) {
                    VS_OUT('-');
                } else if (showsign) {
                    VS_OUT('+');
                } else if (space) {
                    VS_OUT(' ');
                }

                if (!left && pad == '0') {
                    while (width-- > length) {
                        VS_OUT(pad);
                    }
                }

                do {
                    digit = '0';
                    while (spD0 >= f2) {
                        spD0 -= f2;
                        digit++;
                    }
                    f2 /= 10.0f;
                    VS_OUT(digit);
                } while (f2 >= 1.0f);

                if (prec > 0 || alt) {
                    VS_OUT('.');
                }

                while (prec > 0) {
                    digit = '0';
                    while (spD0 >= f2) {
                        spD0 -= f2;
                        digit++;
                    }
                    VS_OUT(digit);
                    f2 /= 10.0f;
                    prec--;
                }

                if (left) {
                    while (width-- > length) {
                        VS_OUT(' ');
                    }
                }
                break;
            }

            case 'c':
                VS_NEXT4(args, slot);
                num = *(s32 *)slot;
                if (!left) {
                    while (--width > 0) {
                        VS_OUT(pad);
                    }
                }
                VS_OUT((unsigned char)num);
                if (left) {
                    while (--width > 0) {
                        VS_OUT(' ');
                    }
                }
                break;

            case 's':
                VS_NEXT4(args, slot);
                str = *(const char **)slot;
                if (str == NULL) {
                    /* Write "(null)" if there's space. */
                    if (prec == -1 || prec >= 6) {
                        str = D_800AE454;
                        len = 6;
                    } else {
                        str = D_800AE450;
                        len = 0;
                    }
                } else {
                    len = strlen(str);
                }

                if (prec != -1 && prec < len) {
                    len = prec;
                }
                width -= len;

                if (!left) {
                    VS_PAD(' ');
                }
                while (len-- > 0) {
                    VS_OUT(*str++);
                }
                if (left) {
                    VS_PAD(' ');
                }
                break;

            case 'p':
                VS_NEXT4(args, slot);
                ptr = *(void **)slot;
                if (ptr != NULL) {
                    /* Non-nil pointers are written as %#x. */
                    base = 16;
                    fc = 'x';
                    alt = 1;
                    num = (u32)ptr;
                    is_neg = 0;
                    goto number;
                } else {
                    /* Write "(nil)" for a nil pointer. */
                    width -= 5;
                    if (!left) {
                        VS_PAD(' ');
                    }
                    p = D_800AE45C;
                    while (*p != '\0') {
                        VS_OUT(*p++);
                    }
                    if (left) {
                        VS_PAD(' ');
                    }
                }
                break;

            case 'n':
                /* Store the count of characters written so far. */
                VS_NEXT4(args, slot);
                ptr = *(void **)slot;
                if (is_longlong) {
                    *(s64 *)ptr = done;
                } else if (is_long) {
                    *(s32 *)ptr = done;
                } else if (!is_short) {
                    *(s32 *)ptr = done;
                } else {
                    *(s16 *)ptr = done;
                }
                break;

            default:
                /* Unrecognized format specifier. */
                break;
        }

        if (D_800A6D40) {
            VS_OUT(0x83);
        }
    }

    *out = '\0';
    return done;
}
#undef VS_NEXT4
#undef VS_NEXT8
#undef VS_OUT
#undef VS_PAD
#else
#pragma GLOBAL_ASM("asm/nonmatchings/diprint/vsprintf.s")
/* asm build: D_800AE454 comes from vsprintf.s .rodata, D_800AE45C follows it */
const char D_800AE45C[] = "(nil)";
#endif

void diPrintfInit(void) {
    D_80101F40 = texLoadTexture(0);
    D_80101F44 = texLoadTexture(1);
    D_80101F48 = texLoadTexture(2);
    D_800A6D44 = D_80101640;
}

s32 diPrintf(const char *format, ...) {
    va_list args;
    s32 written;
    va_start(args, format);
    if ((D_800A6D44 - D_80101640) > 0x800) {
        stubbed_printf("*** diPrintf Error *** ---> Out of string space. (Print less text!)\n");
        return -1;
    }
    sprintfSetSpacingCodes(1);
    written = vsprintf(D_800A6D44, format, args);
    sprintfSetSpacingCodes(0);
    if (written > 0) {
        D_800A6D44 = &D_800A6D44[written] + 1;
    }
    return 0;
}

/**
 * At the end of a frame, iterate through the debug text buffer and print it on screen.
 * Soft-clear the buffer afterwards by setting the endpoint to the start point.
 */
void diPrintfAll(Gfx **dList) {
    s32 height;
    s32 width;
    char *buffer;

    rcpInitDp(dList);
    viGetCurrentSize(&height, &width);
    D_80101F70 = height;
    D_80101F72 = width;
    gDPSetScissor((*dList)++, 0, 0, 0, D_80101F70, D_80101F72);
    func_800665C8();
    gSPDisplayList((*dList)++, D_800A6E08);
    buffer = (char *) D_80101640;
    func_80066658();
    D_80101F6C = -1;
    D_80101F54 = 0;
    D_80101F50 = D_80101F4C;
    D_80101F52 = D_80101F4E;
    while ((s32) buffer != (s32) D_800A6D44) {
        D_80101F58 = FALSE;
        buffer += func_80065CB4(dList, buffer);
    }
    func_800660D4(dList, D_80101F50, D_80101F52, D_80101F4C, D_80101F4E + 10);
    buffer = (char *) D_80101640;
    func_80066658();
    D_80101F6C = -1;
    D_80101F54 = 0;
    while ((s32) buffer != (s32) D_800A6D44) {
        D_80101F58 = TRUE;
        buffer += func_80065CB4(dList, buffer);
    }
    D_800A6D44 = D_80101640;
}

/**
 * Set the colour of the current debug text.
 */
UNUSED void diPrintfSetCol(u8 red, u8 green, u8 blue, u8 alpha) {
    RENDER_PRINTF_CMD_SET_COLOR(red, green, blue, alpha)
}

/**
 * Set the background colour of the current debug text.
 */
void diPrintfSetBG(u8 red, u8 green, u8 blue, u8 alpha) {
    RENDER_PRINTF_CMD_SET_BACKGROUND_COLOR(red, green, blue, alpha)
}

/**
 * Sets the character position of further prints to the given coordinates.
 */
void diPrintfSetXY(u16 x, u16 y) {
    RENDER_PRINTF_CMD_SET_POSITION(x, y)
}

// Same as debug_text_parse in DKR
#ifdef NON_MATCHING
// decomp: m2c + cleanup, non-matching
s32 func_80065CB4(Gfx **dlist, char *buffer) {
    char *start = buffer;
    char *p = buffer + 1;
    u8 c = (u8)buffer[0];

    if (c != 0) {
        do {
            s32 advance = 0;
            s32 x;
            s32 flag;
            s32 limit;
            s32 newX;

            if (c >= 0xB) {
                if (c >= 0x21) {
                    switch (c) {
                    case 0x83:
                        D_80101F54 = 0;
                        break;
                    case 0x84:
                        D_80101F54 = 1;
                        break;
                    case 0x81:
                        if (D_80101F58 != 0) {
                            Gfx *g = (*dlist)++;
                            g->words.w0 = 0xFB000000;
                            g->words.w1 = ((u8)p[0] << 0x18) | (((u8)p[1] & 0xFF) << 0x10) | (((u8)p[2] & 0xFF) << 8) | ((u8)p[3] & 0xFF);
                        }
                        p += 4;
                        break;
                    case 0x85:
                        if (D_80101F58 == 0) {
                            Gfx *g = (*dlist)++;
                            g->words.w0 = 0xFA000000;
                            g->words.w1 = ((u8)p[0] << 0x18) | (((u8)p[1] & 0xFF) << 0x10) | (((u8)p[2] & 0xFF) << 8) | ((u8)p[3] & 0xFF);
                        }
                        p += 4;
                        break;
                    case 0x82:
                        if (D_80101F58 == 0) {
                            func_800660D4(dlist, (u32)D_80101F50, (u32)D_80101F52, (u32)D_80101F4C, D_80101F4E + 0xA);
                        }
                        D_80101F4C = (u16)((u8)p[0] | (p[1] << 8));
                        D_80101F50 = D_80101F4C;
                        D_80101F4E = (u16)((u8)p[2] | (p[3] << 8));
                        D_80101F52 = D_80101F4E;
                        p += 4;
                        break;
                    }
                } else {
                    advance = 6;
                    if (c != 0x20) {
                        advance = func_80066174(dlist, c);
                    }
                }
                /* block_30 */
            } else {
                switch (c) {
                case 10:
                    if (D_80101F58 == 0) {
                        func_800660D4(dlist, (u32)D_80101F50, (u32)D_80101F52, (u32)D_80101F4C, D_80101F4E + 0xA);
                    }
                    func_8006667C();
                    D_80101F50 = D_80101F4C;
                    D_80101F52 = D_80101F4E;
                    break;
                case 9:
                    if ((D_80101F4C % 32) == 0) {
                        advance = 0x20;
                    } else {
                        advance = 0x20 - (D_80101F4C % 32);
                    }
                    break;
                default:
                    /* asm: no case for 1-8, uses current globals */
                    break;
                }
            }

            x = D_80101F4C;
            flag = D_80101F54;
            limit = D_80101F70 - 0x10;
            if ((flag != 0) && (c >= 0x20)) {
                if (c < 0x80) {
                    advance = 7;
                }
            }
            newX = (u16)(x + advance);
            D_80101F4C = newX;
            if (limit < newX) {
                if (D_80101F58 == 0) {
                    func_800660D4(dlist, (u32)D_80101F50, (u32)D_80101F52, (u32)newX, D_80101F4E + 0xA);
                }
                func_8006667C();
                D_80101F50 = D_80101F4C;
                D_80101F52 = D_80101F4E;
            }
            c = (u8)*p;
            p++;
        } while (c != 0);
    }
    return (s32)(p - start);
}
#else
#pragma GLOBAL_ASM("asm/nonmatchings/diprint/func_80065CB4.s")
#endif

void func_800660D4(Gfx **dList, u32 ulx, u32 uly, u32 lrx, u32 lry) {
    if (!((ulx == lrx) | (uly == lry))) {
        if (ulx >= 2) {
            ulx -= 2;
        }
        lrx += 2;
        gDPSetCombineMode((*dList)++, G_CC_PRIMITIVE, G_CC_PRIMITIVE);
        gDPFillRectangle((*dList)++, ulx, uly, lrx, lry);
    }
}

// Same as debug_text_character in DKR
// Loads a font texture and returns the width of the character given.
s32 func_80066174(Gfx **dList, s32 asciiVal) {
    s32 fontCharWidth;
    s32 fontCharU;

    if (asciiVal < 0x40) {
        // Character is a symbol or number and not a letter
        if (D_80101F6C != 0) {
            if (D_80101F58) {
                gDPLoadTextureBlockS((*dList)++, OS_PHYSICAL_TO_K0(D_80101F40 + 1), G_IM_FMT_IA, G_IM_SIZ_8b, 192, 11,
                                     0, 2, 2, 0, 0, 0, 0);
            }
            D_80101F6C = 0;
        }
        asciiVal -= 0x21;
    } else if (asciiVal < 0x60) {
        // Character is a upper case letter
        if (D_80101F6C != 1) {
            if (D_80101F58) {
                gDPLoadTextureBlockS((*dList)++, OS_PHYSICAL_TO_K0(D_80101F44 + 1), G_IM_FMT_IA, G_IM_SIZ_8b, 248, 11,
                                     0, 2, 2, 0, 0, 0, 0);
            }
            D_80101F6C = 1;
        }
        asciiVal -= 0x40;
    } else if (asciiVal < 0x80) {
        // Character is a lower case letter
        if (D_80101F6C != 2) {
            if (D_80101F58) {
                gDPLoadTextureBlockS((*dList)++, OS_PHYSICAL_TO_K0(D_80101F48 + 1), G_IM_FMT_IA, G_IM_SIZ_8b, 192, 11,
                                     0, 2, 2, 0, 0, 0, 0);
            }
            D_80101F6C = 2;
        }
        asciiVal -= 0x60;
    }
    fontCharU = D_800A6D48[D_80101F6C][asciiVal].u;
    fontCharWidth = (D_800A6D48[D_80101F6C][asciiVal].v - fontCharU) + 1;
    if (D_80101F58) {
        gDPSetCombineMode((*dList)++, DKR_CC_UNK14, DKR_CC_UNK14);
        gSPTextureRectangle((*dList)++, (D_80101F4C << 2), (D_80101F4E << 2), ((D_80101F4C + fontCharWidth) << 2),
                            ((D_80101F4E + 10) << 2), 0, (fontCharU << 5), 0, 1024, 1024);
    }
    return fontCharWidth;
}

// debug_text_bounds in DKR
void func_800665C8(void) {
    if (D_80101F70 <= 320) {
        D_80101F5C = 16;
        D_80101F60 = D_80101F70 - 16;
    } else {
        D_80101F5C = 32;
        D_80101F60 = D_80101F70 - 32;
    }
    if (D_80101F72 <= 240) {
        D_80101F64 = 16;
        D_80101F68 = D_80101F72 - 16;
    } else {
        D_80101F64 = 32;
        D_80101F68 = D_80101F72 - 32;
    }
}

// debug_text_origin in DKR
void func_80066658(void) {
    D_80101F4C = D_80101F5C;
    D_80101F4E = D_80101F64;
}

// debug_text_newline in DKR
void func_8006667C(void) {
    D_80101F4C = D_80101F5C;
    D_80101F4E += 11;
}
