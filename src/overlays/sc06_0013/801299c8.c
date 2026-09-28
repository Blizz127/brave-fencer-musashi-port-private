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

extern u8 D_8019AB92;
extern u8 D_8019AABA;
extern u8 D_8019AA98;
extern u8 D_80199758[];
extern u8 D_80199759[];
extern u8 D_8019975A[];

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
            r = D_8019AB92;
            g = D_8019AABA;
            b = D_8019AA98;
            D_80199758[0] = r * 5 >> 3;
            D_80199759[0] = g << 3;
            D_8019975A[0] = (s32)(b * 255) >> 4;
            D_80199758[4] = (s32)(r * 143) >> 4;
            D_80199759[4] = g * 25 >> 1;
            D_8019975A[4] = (s32)(b * 255) >> 4;
            D_80199758[8] = (s32)(r * 255) >> 4;
            D_80199759[8] = (s32)(g * 255) >> 4;
            D_8019975A[8] = (s32)(b * 255) >> 4;
            D_80199758[12] = (s32)(r * 143) >> 4;
            D_80199759[12] = (s32)(g * 255) >> 4;
            D_8019975A[12] = (s32)(b * 45) >> 2;
            break;
        case 0:
        case 2:
            i = arg1 * 4;
            D_80199758[i] = arg2[0x44] * D_8019AB92 >> 4;
            D_80199759[i] = arg2[0x45] * D_8019AABA >> 4;
            D_8019975A[i] = arg2[0x46] * D_8019AA98 >> 4;
            i = (arg1 + 1) * 4;
            D_80199758[i] = arg2[0x47] * D_8019AB92 >> 4;
            D_80199759[i] = arg2[0x48] * D_8019AABA >> 4;
            D_8019975A[i] = arg2[0x49] * D_8019AA98 >> 4;
            break;
        case 3:
        case 4:
            arg2[0x20] = D_8019AB92 << 3;
            arg2[0x21] = D_8019AABA << 3;
            arg2[0x22] = D_8019AA98 << 3;
            break;
        }
    }
}
