/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80154BE4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_80154BE4(s32 a0) {
    s32 sp10;
    s32 sp14;
    sp10 = 0;
    sp14 = 0;
    func_80154C24(a0, &sp10, &sp14);
    func_80154F9C(a0);
}
