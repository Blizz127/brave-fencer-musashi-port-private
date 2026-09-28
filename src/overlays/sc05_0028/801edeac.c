/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801EDEAC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801EDEAC(s32 a0) {
    extern s16 D_801274E8;
    extern void func_801EDED4(s32 a0, s16 *a1);
    func_801EDED4(a0, &D_801274E8);
}
