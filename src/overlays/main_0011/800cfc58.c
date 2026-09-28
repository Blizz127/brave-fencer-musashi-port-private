/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800CFC58 - byte-exact against retail at -O0 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_800167F0(s32 a0);

void func_800CFC58(void) {
    if ((func_800167F0(4) & 0xffff) != 0) {
        func_800118AC();
        func_80011B7C(0);
        func_8001C044();
        func_80015310();
    }
}
