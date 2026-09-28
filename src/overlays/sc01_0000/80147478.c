/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80147478 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147514();
extern void func_80147628(s32 a0);

void func_80147478(s32 a0) {
    if ((*(s32 *)(a0 + 0x44) & 0x40000000) == 0) {
        func_80147514();
        func_80147628(a0);
        *(s32 *)(a0 + 0x44) |= 0x40000000;
    }
}
