/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801299C8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_8019062A;
extern u8 D_80190552;
extern u8 D_80190530;
extern u8 D_8018EFF8[];
extern u8 D_8018EFF9[];
extern u8 D_8018EFFA[];

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
            r = D_8019062A;
            g = D_80190552;
            b = D_80190530;
            D_8018EFF8[0] = r * 5 >> 3;
            D_8018EFF9[0] = g << 3;
            D_8018EFFA[0] = (s32)(b * 255) >> 4;
            D_8018EFF8[4] = (s32)(r * 143) >> 4;
            D_8018EFF9[4] = g * 25 >> 1;
            D_8018EFFA[4] = (s32)(b * 255) >> 4;
            D_8018EFF8[8] = (s32)(r * 255) >> 4;
            D_8018EFF9[8] = (s32)(g * 255) >> 4;
            D_8018EFFA[8] = (s32)(b * 255) >> 4;
            D_8018EFF8[12] = (s32)(r * 143) >> 4;
            D_8018EFF9[12] = (s32)(g * 255) >> 4;
            D_8018EFFA[12] = (s32)(b * 45) >> 2;
            break;
        case 0:
        case 2:
            i = arg1 * 4;
            D_8018EFF8[i] = arg2[0x44] * D_8019062A >> 4;
            D_8018EFF9[i] = arg2[0x45] * D_80190552 >> 4;
            D_8018EFFA[i] = arg2[0x46] * D_80190530 >> 4;
            i = (arg1 + 1) * 4;
            D_8018EFF8[i] = arg2[0x47] * D_8019062A >> 4;
            D_8018EFF9[i] = arg2[0x48] * D_80190552 >> 4;
            D_8018EFFA[i] = arg2[0x49] * D_80190530 >> 4;
            break;
        case 3:
        case 4:
            arg2[0x20] = D_8019062A << 3;
            arg2[0x21] = D_80190552 << 3;
            arg2[0x22] = D_80190530 << 3;
            break;
        }
    }
}
