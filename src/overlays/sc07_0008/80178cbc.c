/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80178CBC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_80196120;
extern short D_80196744;

void func_80178CBC(s32 arg0, s32 arg1) {
    D_80196120 = arg1;
    do {
        func_80178D40(arg0, D_80196120);
    } while (D_80196744 == 3);
}
