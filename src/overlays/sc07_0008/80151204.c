/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80151204 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8014ACE8(void *a0, s32 a1, s32 a2);

int func_80151204(int a0, int a1)
{
    if (a1 != 0 && a1 != 1000) {
        func_8014ACE8(a0, 1, a1 & 0x7FFF);
    }
}
