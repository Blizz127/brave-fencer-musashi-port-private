/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801299C8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_801A0D8A;
extern u8 D_801A0CB2;
extern u8 D_801A0C90;
extern u8 D_8019F950[];
extern u8 D_8019F951[];
extern u8 D_8019F952[];

void func_801299C8(arg0, arg1, arg2)
s16 arg0;
s16 arg1;
u8 *arg2;
{
    u32 r;
    u32 g;
    u32 b;
    s32 i;

    if (arg0 != 0) {
        switch (arg1) {
        case 1:
            r = D_801A0D8A;
            g = D_801A0CB2;
            b = D_801A0C90;
            D_8019F950[0] = r * 5 >> 3;
            D_8019F951[0] = g << 3;
            D_8019F952[0] = (s32)(b * 255) >> 4;
            D_8019F950[4] = (s32)(r * 143) >> 4;
            D_8019F951[4] = g * 25 >> 1;
            D_8019F952[4] = (s32)(b * 255) >> 4;
            D_8019F950[8] = (s32)(r * 255) >> 4;
            D_8019F951[8] = (s32)(g * 255) >> 4;
            D_8019F952[8] = (s32)(b * 255) >> 4;
            D_8019F950[12] = (s32)(r * 143) >> 4;
            D_8019F951[12] = (s32)(g * 255) >> 4;
            D_8019F952[12] = (s32)(b * 45) >> 2;
            break;
        case 0:
        case 2:
            i = arg1 * 4;
            D_8019F950[i] = arg2[0x44] * D_801A0D8A >> 4;
            D_8019F951[i] = arg2[0x45] * D_801A0CB2 >> 4;
            D_8019F952[i] = arg2[0x46] * D_801A0C90 >> 4;
            i = (arg1 + 1) * 4;
            D_8019F950[i] = arg2[0x47] * D_801A0D8A >> 4;
            D_8019F951[i] = arg2[0x48] * D_801A0CB2 >> 4;
            D_8019F952[i] = arg2[0x49] * D_801A0C90 >> 4;
            break;
        case 3:
        case 4:
            arg2[0x20] = D_801A0D8A << 3;
            arg2[0x21] = D_801A0CB2 << 3;
            arg2[0x22] = D_801A0C90 << 3;
            break;
        }
    }
}
