/* Complete SC02 member31 [8012A018,8012A048). */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012A018 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A048(void *a0, s32 a1, u8 a2);

void func_8012A018(s32 a0, s32 a1)
{
    extern u8 D_80126948[];
    func_8012A048(D_80126948, a0, a1);
}
