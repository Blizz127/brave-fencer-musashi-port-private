/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80162F80 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801479BC(s32 a0, s32 a1, s32 a2);

void func_80162F80(s32 arg0, s32 arg1) {
    func_801479BC(arg0, arg1, 0x7F0000);
}
