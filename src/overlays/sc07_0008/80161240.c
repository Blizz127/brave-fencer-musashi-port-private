/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80161240 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_801612B8(void *a0, s32 a1);
extern void func_8016130C(void *a0, s32 a1);

void func_80161240(void *a0) {
    func_8016130C(a0, func_801612B8(a0, 1));
}
