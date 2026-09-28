/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A9AAC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801A9AAC(void) {
    extern void func_80128D60(s32, s32 *, s32 *);
    extern s32 D_801F8A50;
    extern s32 D_801B0748;

    func_80128D60(0, &D_801F8A50, &D_801B0748);
}
