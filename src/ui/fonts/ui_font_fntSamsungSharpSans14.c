/*******************************************************************************
 * Size: 14 px
 * Bpp: 1
 * Opts: --bpp 1 --size 14 --font C:/Users/repy7/SquareLine/assets/samsungsharpsans.otf -o C:/Users/repy7/SquareLine/assets\ui_font_fntSamsungSharpSans14.c --format lvgl -r 0x20-0x7f --no-compress --no-prefilter
 ******************************************************************************/

#include "../ui.h"

#ifndef UI_FONT_FNTSAMSUNGSHARPSANS14
#define UI_FONT_FNTSAMSUNGSHARPSANS14 1
#endif

#if UI_FONT_FNTSAMSUNGSHARPSANS14

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xff, 0x40,

    /* U+0022 "\"" */
    0xfc,

    /* U+0023 "#" */
    0x11, 0x2, 0x20, 0x44, 0x7f, 0xf1, 0x10, 0x22,
    0x3f, 0xf8, 0x88, 0x11, 0x2, 0x20,

    /* U+0024 "$" */
    0x10, 0x21, 0xf4, 0x99, 0x1a, 0xc, 0xe, 0x12,
    0x26, 0x4b, 0xe1, 0x2, 0x0,

    /* U+0025 "%" */
    0x70, 0xa2, 0x68, 0xb2, 0x28, 0x74, 0x2, 0xe1,
    0x44, 0xd1, 0x64, 0x50, 0xe0,

    /* U+0026 "&" */
    0x38, 0x11, 0x4, 0x1, 0x0, 0x71, 0xa2, 0x28,
    0x4a, 0xc, 0x43, 0xf, 0x20,

    /* U+0027 "'" */
    0xe0,

    /* U+0028 "(" */
    0x11, 0x10, 0x88, 0x42, 0x10, 0x82, 0x10, 0x41,
    0x0,

    /* U+0029 ")" */
    0x41, 0x4, 0x20, 0x84, 0x21, 0x8, 0x84, 0x44,
    0x0,

    /* U+002A "*" */
    0x4d, 0x6f, 0x40,

    /* U+002B "+" */
    0x21, 0x3e, 0x42, 0x0,

    /* U+002C "," */
    0x60,

    /* U+002D "-" */
    0xf8,

    /* U+002E "." */
    0x80,

    /* U+002F "/" */
    0x4, 0x20, 0x84, 0x10, 0x82, 0x10, 0x41, 0x0,

    /* U+0030 "0" */
    0x7b, 0x38, 0x61, 0x86, 0x18, 0x61, 0xcd, 0xe0,

    /* U+0031 "1" */
    0xe4, 0x92, 0x49, 0x24,

    /* U+0032 "2" */
    0x7b, 0x30, 0x41, 0x8, 0x42, 0x10, 0x83, 0xf0,

    /* U+0033 "3" */
    0x3c, 0x8c, 0x8, 0x31, 0x80, 0xc0, 0x81, 0x46,
    0x78,

    /* U+0034 "4" */
    0x4, 0xc, 0x14, 0x24, 0x24, 0x44, 0x84, 0xff,
    0x4, 0x4,

    /* U+0035 "5" */
    0x7d, 0x2, 0x5, 0xcc, 0x50, 0x40, 0x81, 0xc4,
    0xf0,

    /* U+0036 "6" */
    0x10, 0x20, 0x83, 0xc4, 0x50, 0x60, 0xc1, 0x44,
    0x70,

    /* U+0037 "7" */
    0xfc, 0x10, 0x82, 0x10, 0x42, 0x8, 0x41, 0x0,

    /* U+0038 "8" */
    0x79, 0x9a, 0x14, 0x67, 0x98, 0xa0, 0xc1, 0xc6,
    0xf8,

    /* U+0039 "9" */
    0x38, 0x8a, 0xc, 0x18, 0x28, 0x8f, 0x4, 0x10,
    0x20,

    /* U+003A ":" */
    0x82,

    /* U+003B ";" */
    0x83,

    /* U+003C "<" */
    0x1b, 0x30, 0x70,

    /* U+003D "=" */
    0xf8, 0x3e,

    /* U+003E ">" */
    0xc1, 0x87, 0xc0,

    /* U+003F "?" */
    0x7a, 0x30, 0x41, 0x8, 0x42, 0x8, 0x0, 0x80,

    /* U+0040 "@" */
    0x1f, 0x4, 0x19, 0x3d, 0x49, 0x9a, 0x33, 0x26,
    0x63, 0x72, 0x0, 0x20, 0x83, 0xe0,

    /* U+0041 "A" */
    0x18, 0x18, 0x28, 0x24, 0x44, 0x44, 0x7e, 0x82,
    0x81, 0x81,

    /* U+0042 "B" */
    0xfd, 0xe, 0xc, 0x1f, 0xd0, 0xe0, 0xc1, 0x87,
    0xf8,

    /* U+0043 "C" */
    0x1f, 0x8, 0x24, 0x6, 0x0, 0x80, 0x20, 0x8,
    0x1, 0x1, 0x20, 0x87, 0xc0,

    /* U+0044 "D" */
    0xf8, 0x86, 0x82, 0x81, 0x81, 0x81, 0x81, 0x82,
    0x86, 0xf8,

    /* U+0045 "E" */
    0xfe, 0x8, 0x20, 0x83, 0xf8, 0x20, 0x83, 0xf0,

    /* U+0046 "F" */
    0xfe, 0x8, 0x20, 0x83, 0xf8, 0x20, 0x82, 0x0,

    /* U+0047 "G" */
    0x1f, 0xc, 0x11, 0x1, 0x40, 0x8, 0x1, 0xf,
    0xa0, 0x12, 0x2, 0x60, 0x83, 0xe0,

    /* U+0048 "H" */
    0x81, 0x81, 0x81, 0x81, 0x81, 0xff, 0x81, 0x81,
    0x81, 0x81,

    /* U+0049 "I" */
    0xff, 0xc0,

    /* U+004A "J" */
    0x8, 0x42, 0x10, 0x84, 0x21, 0x9b, 0x80,

    /* U+004B "K" */
    0x82, 0x84, 0x88, 0x90, 0xb0, 0xc8, 0x88, 0x84,
    0x82, 0x81,

    /* U+004C "L" */
    0x82, 0x8, 0x20, 0x82, 0x8, 0x20, 0x83, 0xf0,

    /* U+004D "M" */
    0x80, 0x70, 0x3a, 0x16, 0x89, 0x92, 0x63, 0x18,
    0x6, 0x1, 0x80, 0x60, 0x10,

    /* U+004E "N" */
    0x81, 0xc1, 0xa1, 0xa1, 0x91, 0x89, 0x89, 0x85,
    0x83, 0x81,

    /* U+004F "O" */
    0x1f, 0x4, 0x11, 0x1, 0x40, 0x18, 0x3, 0x0,
    0x60, 0xa, 0x2, 0x20, 0x83, 0xe0,

    /* U+0050 "P" */
    0xf9, 0xa, 0xc, 0x18, 0x30, 0xbe, 0x40, 0x81,
    0x0,

    /* U+0051 "Q" */
    0x1f, 0x4, 0x11, 0x1, 0x40, 0x18, 0x3, 0x0,
    0x60, 0xca, 0xe, 0x20, 0x83, 0xe8,

    /* U+0052 "R" */
    0xf9, 0xe, 0xc, 0x18, 0x5f, 0x22, 0x42, 0x85,
    0x4,

    /* U+0053 "S" */
    0x7b, 0x38, 0x20, 0x60, 0x60, 0x41, 0x8d, 0xe0,

    /* U+0054 "T" */
    0xfe, 0x20, 0x40, 0x81, 0x2, 0x4, 0x8, 0x10,
    0x20,

    /* U+0055 "U" */
    0x83, 0x6, 0xc, 0x18, 0x30, 0x60, 0xc1, 0x44,
    0x70,

    /* U+0056 "V" */
    0x81, 0x82, 0x82, 0x42, 0x44, 0x44, 0x24, 0x28,
    0x18, 0x10,

    /* U+0057 "W" */
    0x82, 0xc, 0x30, 0x61, 0x43, 0xa, 0x24, 0x91,
    0x24, 0x49, 0x22, 0x86, 0x14, 0x30, 0x61, 0x82,
    0x0,

    /* U+0058 "X" */
    0x41, 0x11, 0x8, 0x82, 0x80, 0x80, 0x60, 0x50,
    0x44, 0x41, 0x20, 0x80,

    /* U+0059 "Y" */
    0x83, 0x9, 0x11, 0x43, 0x2, 0x4, 0x8, 0x10,
    0x20,

    /* U+005A "Z" */
    0xfe, 0x4, 0x10, 0x41, 0x2, 0x8, 0x20, 0x81,
    0xfc,

    /* U+005B "[" */
    0xf8, 0x88, 0x88, 0x88, 0x88, 0x88, 0xf0,

    /* U+005C "\\" */
    0x41, 0x4, 0x8, 0x20, 0x41, 0x2, 0x8, 0x10,

    /* U+005D "]" */
    0xf1, 0x11, 0x11, 0x11, 0x11, 0x11, 0xf0,

    /* U+005E "^" */
    0x22, 0x94,

    /* U+005F "_" */
    0xfc,

    /* U+0060 "`" */
    0x48,

    /* U+0061 "a" */
    0x3c, 0xb1, 0xe0, 0x70, 0x18, 0xc, 0xd, 0x8e,
    0x79,

    /* U+0062 "b" */
    0x80, 0x40, 0x27, 0x9c, 0x68, 0x1c, 0x6, 0x3,
    0x3, 0xe3, 0x4f, 0x0,

    /* U+0063 "c" */
    0x3c, 0x63, 0x81, 0x80, 0x80, 0x81, 0x63, 0x3e,

    /* U+0064 "d" */
    0x0, 0x80, 0x4f, 0x2c, 0x78, 0x1c, 0x6, 0x3,
    0x3, 0x63, 0x9e, 0x40,

    /* U+0065 "e" */
    0x3c, 0x21, 0xa0, 0x5f, 0xe8, 0x4, 0x9, 0xc,
    0x7c,

    /* U+0066 "f" */
    0x34, 0x4f, 0x44, 0x44, 0x44, 0x40,

    /* U+0067 "g" */
    0x3c, 0xb1, 0xe0, 0x70, 0x18, 0xc, 0xd, 0x8e,
    0x79, 0x0, 0xa0, 0xd8, 0xc7, 0xc0,

    /* U+0068 "h" */
    0x80, 0x80, 0xbc, 0xc2, 0x81, 0x81, 0x81, 0x81,
    0x81, 0x81,

    /* U+0069 "i" */
    0xbf, 0xc0,

    /* U+006A "j" */
    0x20, 0x92, 0x49, 0x24, 0x93, 0x80,

    /* U+006B "k" */
    0x81, 0x2, 0x14, 0x49, 0x16, 0x34, 0x44, 0x85,
    0x4,

    /* U+006C "l" */
    0xff, 0xc0,

    /* U+006D "m" */
    0xb8, 0xf6, 0x28, 0xa0, 0x83, 0x4, 0x18, 0x20,
    0xc1, 0x6, 0x8, 0x30, 0x41,

    /* U+006E "n" */
    0xbc, 0xc2, 0x81, 0x81, 0x81, 0x81, 0x81, 0x81,

    /* U+006F "o" */
    0x3e, 0x31, 0xa0, 0x70, 0x18, 0xc, 0xd, 0x8c,
    0x7c,

    /* U+0070 "p" */
    0x9e, 0x71, 0xa0, 0x70, 0x18, 0xc, 0xf, 0x8d,
    0x3c, 0x80, 0x40, 0x20, 0x10, 0x0,

    /* U+0071 "q" */
    0x3c, 0xb1, 0xe0, 0x70, 0x18, 0xc, 0xd, 0x8e,
    0x79, 0x0, 0x80, 0x40, 0x20, 0x10,

    /* U+0072 "r" */
    0xbe, 0x21, 0x8, 0x42, 0x10,

    /* U+0073 "s" */
    0x7a, 0x18, 0x10, 0x38, 0x18, 0xde,

    /* U+0074 "t" */
    0x44, 0xf4, 0x44, 0x44, 0x43,

    /* U+0075 "u" */
    0x81, 0x81, 0x81, 0x81, 0x81, 0x81, 0x43, 0x3d,

    /* U+0076 "v" */
    0x83, 0xa, 0x12, 0x44, 0x85, 0xc, 0x8,

    /* U+0077 "w" */
    0x84, 0x18, 0x61, 0x8a, 0x24, 0x92, 0x51, 0x25,
    0x14, 0x30, 0xc2, 0xc,

    /* U+0078 "x" */
    0x41, 0x22, 0x14, 0x18, 0x18, 0x24, 0x22, 0x41,

    /* U+0079 "y" */
    0x82, 0x82, 0x44, 0x44, 0x24, 0x28, 0x18, 0x10,
    0x10, 0x20, 0x20, 0x40,

    /* U+007A "z" */
    0xfe, 0x4, 0x10, 0x43, 0xc, 0x30, 0x7f,

    /* U+007B "{" */
    0x34, 0x44, 0x44, 0x84, 0x44, 0x44, 0x30,

    /* U+007C "|" */
    0xff, 0xf8,

    /* U+007D "}" */
    0xc2, 0x22, 0x22, 0x12, 0x22, 0x22, 0xc0,

    /* U+007E "~" */
    0xed, 0xc0
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 57, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 54, .box_w = 1, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 3, .adv_w = 64, .box_w = 2, .box_h = 3, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 4, .adv_w = 187, .box_w = 11, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 18, .adv_w = 132, .box_w = 7, .box_h = 14, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 31, .adv_w = 192, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 44, .adv_w = 171, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 57, .adv_w = 40, .box_w = 1, .box_h = 3, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 58, .adv_w = 94, .box_w = 5, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 67, .adv_w = 94, .box_w = 5, .box_h = 13, .ofs_x = 0, .ofs_y = -3},
    {.bitmap_index = 76, .adv_w = 98, .box_w = 4, .box_h = 5, .ofs_x = 1, .ofs_y = 5},
    {.bitmap_index = 79, .adv_w = 106, .box_w = 5, .box_h = 5, .ofs_x = 1, .ofs_y = 2},
    {.bitmap_index = 83, .adv_w = 43, .box_w = 2, .box_h = 2, .ofs_x = 0, .ofs_y = -2},
    {.bitmap_index = 84, .adv_w = 106, .box_w = 5, .box_h = 1, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 85, .adv_w = 43, .box_w = 1, .box_h = 1, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 86, .adv_w = 104, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 94, .adv_w = 132, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 102, .adv_w = 72, .box_w = 3, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 106, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 114, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 123, .adv_w = 138, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 133, .adv_w = 137, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 142, .adv_w = 139, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 151, .adv_w = 120, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 159, .adv_w = 128, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 168, .adv_w = 136, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 177, .adv_w = 43, .box_w = 1, .box_h = 7, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 178, .adv_w = 43, .box_w = 1, .box_h = 8, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 179, .adv_w = 106, .box_w = 5, .box_h = 4, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 182, .adv_w = 106, .box_w = 5, .box_h = 3, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 184, .adv_w = 106, .box_w = 5, .box_h = 4, .ofs_x = 1, .ofs_y = 3},
    {.bitmap_index = 187, .adv_w = 121, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 195, .adv_w = 192, .box_w = 11, .box_h = 10, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 209, .adv_w = 156, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 219, .adv_w = 143, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 228, .adv_w = 178, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 241, .adv_w = 159, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 251, .adv_w = 131, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 259, .adv_w = 123, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 267, .adv_w = 190, .box_w = 11, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 281, .adv_w = 154, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 291, .adv_w = 51, .box_w = 1, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 293, .adv_w = 107, .box_w = 5, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 300, .adv_w = 145, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 310, .adv_w = 119, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 318, .adv_w = 194, .box_w = 10, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 331, .adv_w = 166, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 341, .adv_w = 192, .box_w = 11, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 355, .adv_w = 138, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 364, .adv_w = 192, .box_w = 11, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 378, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 387, .adv_w = 125, .box_w = 6, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 395, .adv_w = 137, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 404, .adv_w = 144, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 413, .adv_w = 153, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 423, .adv_w = 240, .box_w = 13, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 440, .adv_w = 146, .box_w = 9, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 452, .adv_w = 137, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 461, .adv_w = 134, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 470, .adv_w = 85, .box_w = 4, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 477, .adv_w = 104, .box_w = 6, .box_h = 10, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 485, .adv_w = 85, .box_w = 4, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 492, .adv_w = 112, .box_w = 5, .box_h = 3, .ofs_x = 1, .ofs_y = 7},
    {.bitmap_index = 494, .adv_w = 121, .box_w = 6, .box_h = 1, .ofs_x = 1, .ofs_y = -1},
    {.bitmap_index = 495, .adv_w = 112, .box_w = 3, .box_h = 2, .ofs_x = 2, .ofs_y = 8},
    {.bitmap_index = 496, .adv_w = 167, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 505, .adv_w = 167, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 517, .adv_w = 156, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 525, .adv_w = 167, .box_w = 9, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 537, .adv_w = 162, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 546, .adv_w = 89, .box_w = 4, .box_h = 11, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 552, .adv_w = 167, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 566, .adv_w = 158, .box_w = 8, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 576, .adv_w = 51, .box_w = 1, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 578, .adv_w = 51, .box_w = 3, .box_h = 14, .ofs_x = -1, .ofs_y = -4},
    {.bitmap_index = 584, .adv_w = 136, .box_w = 7, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 593, .adv_w = 52, .box_w = 1, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 595, .adv_w = 259, .box_w = 13, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 608, .adv_w = 158, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 616, .adv_w = 163, .box_w = 9, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 625, .adv_w = 167, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 639, .adv_w = 167, .box_w = 9, .box_h = 12, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 653, .adv_w = 103, .box_w = 5, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 658, .adv_w = 121, .box_w = 6, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 664, .adv_w = 90, .box_w = 4, .box_h = 10, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 669, .adv_w = 158, .box_w = 8, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 677, .adv_w = 134, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 684, .adv_w = 219, .box_w = 12, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 696, .adv_w = 138, .box_w = 8, .box_h = 8, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 704, .adv_w = 146, .box_w = 8, .box_h = 12, .ofs_x = 1, .ofs_y = -4},
    {.bitmap_index = 716, .adv_w = 141, .box_w = 7, .box_h = 8, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 723, .adv_w = 91, .box_w = 4, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 730, .adv_w = 43, .box_w = 1, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 732, .adv_w = 91, .box_w = 4, .box_h = 13, .ofs_x = 1, .ofs_y = -3},
    {.bitmap_index = 739, .adv_w = 102, .box_w = 5, .box_h = 2, .ofs_x = 1, .ofs_y = 7}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/



/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 95, .glyph_id_start = 1,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Map glyph_ids to kern left classes*/
static const uint8_t kern_left_class_mapping[] =
{
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 2, 3, 4, 0, 5,
    6, 7, 7, 8, 9, 10, 7, 7,
    4, 11, 12, 13, 14, 15, 16, 17,
    18, 19, 20, 21, 0, 0, 0, 0,
    0, 0, 22, 23, 24, 25, 26, 27,
    28, 29, 25, 0, 30, 25, 29, 29,
    23, 23, 31, 32, 33, 34, 22, 35,
    36, 37, 38, 39, 0, 0, 0, 0
};

/*Map glyph_ids to kern right classes*/
static const uint8_t kern_right_class_mapping[] =
{
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 2, 0, 0, 0,
    2, 0, 0, 3, 0, 0, 0, 0,
    2, 0, 2, 0, 4, 5, 6, 7,
    8, 9, 10, 11, 0, 0, 0, 0,
    0, 0, 12, 13, 12, 12, 12, 14,
    12, 13, 13, 15, 13, 13, 16, 16,
    12, 16, 12, 16, 17, 18, 19, 20,
    21, 22, 23, 24, 0, 0, 0, 0
};

/*Kern values between classes*/
static const int8_t kern_class_values[] =
{
    0, -10, 3, 3, -31, -6, -29, -25,
    0, -28, 0, -4, 0, -4, 0, -1,
    0, -8, -6, -17, -12, 0, -18, 0,
    0, 0, 0, 0, 0, 0, -3, 0,
    -3, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -2, 0, 0, 0, 0,
    -2, 0, -2, 0, -13, 0, -2, -2,
    -4, -7, -3, 3, 0, 2, 0, 0,
    1, 0, 0, 0, 0, -1, 0, 0,
    -10, 2, -6, -2, -17, 0, -10, -9,
    -9, -15, -11, 2, 2, 2, 2, 2,
    2, 2, 1, 1, 3, -1, 0, -1,
    -16, 1, -20, 0, 0, 0, 0, 0,
    -3, 0, -2, -1, 0, -1, 0, 0,
    0, 0, 0, 0, 0, -2, 0, -1,
    -8, 0, -4, 0, -13, 0, -7, -9,
    -8, -13, -9, 3, 1, 0, 1, 0,
    3, 1, 2, 0, 0, -1, -1, -2,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1,
    1, 0, 1, 0, 0, 0, 0, 0,
    -1, 0, -2, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -2, 0, 0,
    0, -11, 2, 1, -2, -4, 0, 0,
    0, 0, 0, -6, 0, -2, 0, 0,
    2, -9, -8, -11, -13, 2, -19, 0,
    2, -13, 0, 2, -27, -7, -27, -25,
    4, -31, 0, -7, 0, -2, 0, 0,
    1, -7, -8, -13, -13, 0, -21, 0,
    -20, 2, -27, 2, -9, 0, -4, -2,
    -10, -6, -11, -3, 0, 1, 1, 0,
    1, 0, 0, 2, 1, 1, 1, -1,
    -4, 2, -4, 0, -11, 0, -7, -4,
    -4, -10, -4, 2, 0, 0, 0, 0,
    0, 0, 1, 1, 2, 0, 1, 0,
    0, 1, -2, 3, -6, 0, -3, -2,
    0, -7, 0, -6, 1, 2, 2, 0,
    0, 1, -1, 1, 1, 0, 0, 0,
    -1, 0, 0, 1, -6, 0, -6, -7,
    -6, -7, -3, 3, 0, -2, 1, 0,
    1, -3, 0, -4, -4, -1, -8, -1,
    -31, -17, -29, -3, 1, 0, 2, 2,
    -3, 2, -2, -27, 0, -3, 0, -20,
    -22, -11, -20, -17, -16, -18, -20, -25,
    -7, 0, -2, 1, 0, 0, 0, 0,
    0, 0, -3, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -2, 0, -2,
    -29, -10, -34, 0, 0, 0, 0, 0,
    -2, 0, -2, -20, 0, -7, 0, -11,
    -16, -7, -13, -7, -7, -11, -9, -11,
    -27, -10, -22, 0, 0, 0, 0, 0,
    -4, 0, -2, -16, 0, -7, 0, -9,
    -11, -2, -10, -8, -9, -11, -9, -13,
    0, -7, 0, 0, -4, -3, -2, 0,
    0, -3, 0, -10, 0, -4, 0, 0,
    0, -7, -9, -18, -18, 0, -19, 0,
    -28, -15, -27, 0, 0, 0, 1, 0,
    -1, 2, 0, -29, 0, -9, 0, -16,
    -23, -11, -21, -16, -13, -18, -20, -22,
    0, -13, 0, 0, 0, 0, 1, 0,
    0, 1, -2, -9, 0, -4, 0, 0,
    2, -6, -7, -11, -9, 0, -15, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 2,
    0, 0, 0, 0, 0, 0, 0, 2,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, -3, 0, 0,
    0, -6, 0, -4, -3, -7, -7, -6,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, -1, 0, -2, 0, 0, -4, -2,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 2, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -4, 0, 0,
    0, -3, 0, -4, -3, -5, -6, -4,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -8, 0, 1, 0, 0,
    -3, 1, -1, 0, 0, 0, 0, -2,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 2, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -4, 0, 0,
    0, -4, 0, -4, -4, 0, -6, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -9, 0, 0, 0, 0,
    1, -1, -4, -1, -1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -9, 0, 0, 1, 0,
    -1, 0, 0, 2, 2, 2, 2, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, -1, 0, 0,
    0, -1, -1, -2, -1, -2, -3, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -6, 0, 0, 0, 0,
    2, 0, 0, 0, 0, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -4, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -4, 0, 2, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -7, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -7, 0, 3, 0, 0,
    0, 2, 0, 1, 1, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, -6, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0
};


/*Collect the kern class' data in one place*/
static const lv_font_fmt_txt_kern_classes_t kern_classes =
{
    .class_pair_values   = kern_class_values,
    .left_class_mapping  = kern_left_class_mapping,
    .right_class_mapping = kern_right_class_mapping,
    .left_class_cnt      = 39,
    .right_class_cnt     = 24,
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LVGL_VERSION_MAJOR == 8
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
#endif

#if LVGL_VERSION_MAJOR >= 8
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_classes,
    .kern_scale = 16,
    .cmap_num = 1,
    .bpp = 1,
    .kern_classes = 1,
    .bitmap_format = 0,
#if LVGL_VERSION_MAJOR == 8
    .cache = &cache
#endif
};



/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LVGL_VERSION_MAJOR >= 8
const lv_font_t ui_font_fntSamsungSharpSans14 = {
#else
lv_font_t ui_font_fntSamsungSharpSans14 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 16,          /*The maximum line height required by the font*/
    .base_line = 4,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -1,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc,          /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
#if LV_VERSION_CHECK(8, 2, 0) || LVGL_VERSION_MAJOR >= 9
    .fallback = NULL,
#endif
    .user_data = NULL,
};



#endif /*#if UI_FONT_FNTSAMSUNGSHARPSANS14*/

