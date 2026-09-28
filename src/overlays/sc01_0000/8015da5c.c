/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015DA5C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80154A74(s32 a0, s32 a1);
extern int func_8015E0D4(int);

void func_8015DA5C(s32 a0) {
    func_80154A74(a0, 0x11);
    func_8015E0D4(a0);
}
