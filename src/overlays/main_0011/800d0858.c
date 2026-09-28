/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D0858 - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_800D0858(void) {
    extern s32 func_800149E0(s32 a0);
    extern s32 func_80014B10(s32 a0);
    extern u16 D_800D4C9C;
    extern u16 D_800D4C98;
    extern u16 D_800D4CA0;
    extern u16 D_800D4CA4;

    D_800D4C9C = func_800149E0(0);
    D_800D4C98 = func_80014B10(0);
    if (D_800D4C98 != 0) {
        if (D_800D4C98 == D_800D4CA0) {
            if (--D_800D4CA4 == 0) {
                D_800D4C9C = D_800D4C98 & 0xF000;
                D_800D4CA4 = 3;
            }
        } else {
            D_800D4CA0 = D_800D4C98;
            D_800D4CA4 = 6;
        }
    } else {
        D_800D4CA0 = 0;
        D_800D4CA4 = 12;
    }
}
