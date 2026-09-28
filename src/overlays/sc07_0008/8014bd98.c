/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014BD98 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 D_80078EB6;
extern s16 D_80078EB8;

void func_8014BD98(s32 a0, u16 a1) {
    D_80078EB8 = a1;
    if (D_80078EB6 < a1) {
        D_80078EB8 = D_80078EB6;
    }
}
