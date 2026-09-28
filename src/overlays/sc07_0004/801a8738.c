/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A8738 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801A8738(s32 a0) {
    s32 v;
    s16 c;

    c = *(u8 *)a0;
    if (c == 0xFF) {
        return;
    }
    c += 2;
    if (c > 0xFF) {
        c = 0xFF;
    }
    *(u8 *)a0 = c;
}
