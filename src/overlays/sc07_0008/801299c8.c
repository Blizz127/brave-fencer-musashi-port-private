/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801299C8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_801966D2;
extern u8 D_801965FA;
extern u8 D_801965D8;
extern u8 D_801952A0[];
extern u8 D_801952A1[];
extern u8 D_801952A2[];

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
            r = D_801966D2;
            g = D_801965FA;
            b = D_801965D8;
            D_801952A0[0] = r * 5 >> 3;
            D_801952A1[0] = g << 3;
            D_801952A2[0] = (s32)(b * 255) >> 4;
            D_801952A0[4] = (s32)(r * 143) >> 4;
            D_801952A1[4] = g * 25 >> 1;
            D_801952A2[4] = (s32)(b * 255) >> 4;
            D_801952A0[8] = (s32)(r * 255) >> 4;
            D_801952A1[8] = (s32)(g * 255) >> 4;
            D_801952A2[8] = (s32)(b * 255) >> 4;
            D_801952A0[12] = (s32)(r * 143) >> 4;
            D_801952A1[12] = (s32)(g * 255) >> 4;
            D_801952A2[12] = (s32)(b * 45) >> 2;
            break;
        case 0:
        case 2:
            i = arg1 * 4;
            D_801952A0[i] = arg2[0x44] * D_801966D2 >> 4;
            D_801952A1[i] = arg2[0x45] * D_801965FA >> 4;
            D_801952A2[i] = arg2[0x46] * D_801965D8 >> 4;
            i = (arg1 + 1) * 4;
            D_801952A0[i] = arg2[0x47] * D_801966D2 >> 4;
            D_801952A1[i] = arg2[0x48] * D_801965FA >> 4;
            D_801952A2[i] = arg2[0x49] * D_801965D8 >> 4;
            break;
        case 3:
        case 4:
            arg2[0x20] = D_801966D2 << 3;
            arg2[0x21] = D_801965FA << 3;
            arg2[0x22] = D_801965D8 << 3;
            break;
        }
    }
}
