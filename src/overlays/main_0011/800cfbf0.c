/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800CFBF0 - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_800CFBF0(void) {
    extern s32 D_800D4C94;
    extern s32 D_800D3314[];
    func_8001534C(0x1A, D_800D3314[D_800D4C94], 0x90, 0x9A, 0, 0);
}
