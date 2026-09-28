/* SC02.CD member31 [80150DE4,80150E04); exact word export. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80150DE4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80150EC4(s32 a, s32 b);

void func_80150DE4(s32 a) {
    func_80150EC4(a, 9);
}
