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

extern s32 D_8019CE00;
extern short D_8019D42C;

void func_80178CBC(s32 arg0, s32 arg1) {
    D_8019CE00 = arg1;
    do {
        func_80178D40(arg0, D_8019CE00);
    } while (D_8019D42C == 3);
}
