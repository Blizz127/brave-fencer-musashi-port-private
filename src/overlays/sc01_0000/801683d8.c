/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801683D8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80166994(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80166690();
extern void func_80146C3C();

void func_801683D8(s32 a0) {
    func_80166994(a0, 2, *(short *)(a0 + 0x2c), 0);
    if ((short)func_80166690(*(short *)(a0 + 0x2c), *(short *)(a0 + 0x28)) == 0) {
        ((void (*)(s32))func_80146C3C)(a0);
    }
}
