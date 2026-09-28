/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A1984 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801A36F0(void *a0);
extern void func_8012AD44(s32 *a0, s16 a1);

void func_801A1984(s32 a0)
{
    s32 *s0 = a0;

    func_801A36F0(s0);
    s0[7] = 0x14;
    func_8012AD44(s0, 10);
}
