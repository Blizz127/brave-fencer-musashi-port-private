/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80146CC8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_80127090;
extern s32 D_80127094;
extern s32 D_80127098;

void func_80146CC8(s32 a0) {
    s32 *p = &D_80127090;
    *(s32*)(a0 + 0x10) += *p;
    *(s32*)(a0 + 0x14) += D_80127094;
    *(s32*)(a0 + 0x18) += D_80127098;
    *p = 0;
    D_80127094 = 0;
    D_80127098 = 0;
}
