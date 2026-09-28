/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801299C8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80196352;
extern u8 D_8019627A;
extern u8 D_80196258;
extern u8 D_80194F20[];
extern u8 D_80194F21[];
extern u8 D_80194F22[];

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
            r = D_80196352;
            g = D_8019627A;
            b = D_80196258;
            D_80194F20[0] = r * 5 >> 3;
            D_80194F21[0] = g << 3;
            D_80194F22[0] = (s32)(b * 255) >> 4;
            D_80194F20[4] = (s32)(r * 143) >> 4;
            D_80194F21[4] = g * 25 >> 1;
            D_80194F22[4] = (s32)(b * 255) >> 4;
            D_80194F20[8] = (s32)(r * 255) >> 4;
            D_80194F21[8] = (s32)(g * 255) >> 4;
            D_80194F22[8] = (s32)(b * 255) >> 4;
            D_80194F20[12] = (s32)(r * 143) >> 4;
            D_80194F21[12] = (s32)(g * 255) >> 4;
            D_80194F22[12] = (s32)(b * 45) >> 2;
            break;
        case 0:
        case 2:
            i = arg1 * 4;
            D_80194F20[i] = arg2[0x44] * D_80196352 >> 4;
            D_80194F21[i] = arg2[0x45] * D_8019627A >> 4;
            D_80194F22[i] = arg2[0x46] * D_80196258 >> 4;
            i = (arg1 + 1) * 4;
            D_80194F20[i] = arg2[0x47] * D_80196352 >> 4;
            D_80194F21[i] = arg2[0x48] * D_8019627A >> 4;
            D_80194F22[i] = arg2[0x49] * D_80196258 >> 4;
            break;
        case 3:
        case 4:
            arg2[0x20] = D_80196352 << 3;
            arg2[0x21] = D_8019627A << 3;
            arg2[0x22] = D_80196258 << 3;
            break;
        }
    }
}
