/* SC02.CD member31 [80150EA4,80150EC4); exact word export. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80150EA4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80150EC4(s32 a0, s32 a1);

void func_80150EA4(s32 a0) {
    func_80150EC4(a0, 0xF);
}
