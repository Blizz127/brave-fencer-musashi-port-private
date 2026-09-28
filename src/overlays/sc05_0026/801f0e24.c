/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801F0E24 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801F8330[][4];
extern s32 D_801F8334[][4];
extern s32 D_801F8338[][4];
extern s32 D_801F84AC;

void func_801F0E24(s32 arg0, s32 arg1, s32 arg2) {
    D_801F8334[D_801F84AC][0] = arg0;
    D_801F8330[D_801F84AC][0] = arg1;
    D_801F8338[D_801F84AC][0] = arg2;
    D_801F84AC++;
}
