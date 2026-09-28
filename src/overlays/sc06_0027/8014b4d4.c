/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014B4D4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80166244();
extern s32 D_80078E98;

void func_8014B4D4(void *a0) {
    *(u16 *)((s32)a0 + 0x1C8) = 0;
    D_80078E98 = 0x80000000;
    func_80166244();
}
