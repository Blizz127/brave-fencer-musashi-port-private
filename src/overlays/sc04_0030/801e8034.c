/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801E8034 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801E805C(s32 a0, s16 *a1);

void func_801E8034(s32 param_1) {
    extern s16 D_801274E8;
    func_801E805C(param_1, &D_801274E8);
}
