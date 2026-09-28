/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801299C8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_801BE9D2;
extern u8 D_801BE8FA;
extern u8 D_801BE8D8;
extern u8 D_801BD5A0[];
extern u8 D_801BD5A1[];
extern u8 D_801BD5A2[];

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
            r = D_801BE9D2;
            g = D_801BE8FA;
            b = D_801BE8D8;
            D_801BD5A0[0] = r * 5 >> 3;
            D_801BD5A1[0] = g << 3;
            D_801BD5A2[0] = (s32)(b * 255) >> 4;
            D_801BD5A0[4] = (s32)(r * 143) >> 4;
            D_801BD5A1[4] = g * 25 >> 1;
            D_801BD5A2[4] = (s32)(b * 255) >> 4;
            D_801BD5A0[8] = (s32)(r * 255) >> 4;
            D_801BD5A1[8] = (s32)(g * 255) >> 4;
            D_801BD5A2[8] = (s32)(b * 255) >> 4;
            D_801BD5A0[12] = (s32)(r * 143) >> 4;
            D_801BD5A1[12] = (s32)(g * 255) >> 4;
            D_801BD5A2[12] = (s32)(b * 45) >> 2;
            break;
        case 0:
        case 2:
            i = arg1 * 4;
            D_801BD5A0[i] = arg2[0x44] * D_801BE9D2 >> 4;
            D_801BD5A1[i] = arg2[0x45] * D_801BE8FA >> 4;
            D_801BD5A2[i] = arg2[0x46] * D_801BE8D8 >> 4;
            i = (arg1 + 1) * 4;
            D_801BD5A0[i] = arg2[0x47] * D_801BE9D2 >> 4;
            D_801BD5A1[i] = arg2[0x48] * D_801BE8FA >> 4;
            D_801BD5A2[i] = arg2[0x49] * D_801BE8D8 >> 4;
            break;
        case 3:
        case 4:
            arg2[0x20] = D_801BE9D2 << 3;
            arg2[0x21] = D_801BE8FA << 3;
            arg2[0x22] = D_801BE8D8 << 3;
            break;
        }
    }
}
