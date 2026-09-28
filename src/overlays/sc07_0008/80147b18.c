/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80147B18 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147D38(s32 a0, s32 a1, s32 a2, s32 a3, void *a4);
extern void func_80147B5C(s32 a0, void *a1);

void func_80147B18(s32 a0)
{
    s32 buf[4];
    s32 b0, b1, b2;
    func_80147D38(a0, b0, b1, b2, &buf[0]);
    func_80147B5C(a0, &buf[0]);
}
