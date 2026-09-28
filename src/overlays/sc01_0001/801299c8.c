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

extern u8 D_801F3152;
extern u8 D_801F307A;
extern u8 D_801F3058;
extern u8 D_801EC670[];
extern u8 D_801EC671[];
extern u8 D_801EC672[];

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
            r = D_801F3152;
            g = D_801F307A;
            b = D_801F3058;
            D_801EC670[0] = r * 5 >> 3;
            D_801EC671[0] = g << 3;
            D_801EC672[0] = (s32)(b * 255) >> 4;
            D_801EC670[4] = (s32)(r * 143) >> 4;
            D_801EC671[4] = g * 25 >> 1;
            D_801EC672[4] = (s32)(b * 255) >> 4;
            D_801EC670[8] = (s32)(r * 255) >> 4;
            D_801EC671[8] = (s32)(g * 255) >> 4;
            D_801EC672[8] = (s32)(b * 255) >> 4;
            D_801EC670[12] = (s32)(r * 143) >> 4;
            D_801EC671[12] = (s32)(g * 255) >> 4;
            D_801EC672[12] = (s32)(b * 45) >> 2;
            break;
        case 0:
        case 2:
            i = arg1 * 4;
            D_801EC670[i] = arg2[0x44] * D_801F3152 >> 4;
            D_801EC671[i] = arg2[0x45] * D_801F307A >> 4;
            D_801EC672[i] = arg2[0x46] * D_801F3058 >> 4;
            i = (arg1 + 1) * 4;
            D_801EC670[i] = arg2[0x47] * D_801F3152 >> 4;
            D_801EC671[i] = arg2[0x48] * D_801F307A >> 4;
            D_801EC672[i] = arg2[0x49] * D_801F3058 >> 4;
            break;
        case 3:
        case 4:
            arg2[0x20] = D_801F3152 << 3;
            arg2[0x21] = D_801F307A << 3;
            arg2[0x22] = D_801F3058 << 3;
            break;
        }
    }
}
