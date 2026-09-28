/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80154418 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8015444C(void *a0, s32 *a1, s32 *a2, s32 *a3);

void func_80154418(void *a0) {
    s32 sp10 = 0;
    s32 sp14 = 0;
    s32 sp18 = 0;
    func_8015444C(a0, &sp10, &sp14, &sp18);
}
