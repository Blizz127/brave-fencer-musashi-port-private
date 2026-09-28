/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D2C0C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_800D2E64();

void func_800D2C0C(s32 *a0, s32 a1) {
    if (a1 & 1) {
        *a0 &= 0xF7FFFFFF;
    } else {
        *a0 |= 0x8000000;
    }
    if (a1 & 2) {
        *a0 |= 0x2000000;
    } else {
        *a0 &= 0xFDFFFFFF;
    }
    func_800D2E64(a0, *(u16 *)a0);
}
