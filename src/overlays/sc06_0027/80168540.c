/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80168540 - byte-exact against retail at -O2 (tools/register_match.py). */
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

void func_80168540(s32 a0) {
    s32 v0;
    if (((*(u32 *)(*(s32 *)(a0 + 0x34) + 0x44) & 2) == 0) ||
        (v0 = *(s32 *)(a0 + 0x1c) - 1, *(s32 *)(a0 + 0x1c) = v0, v0 == 0)) {
        *(s16 *)(a0 + 2) = *(s16 *)(a0 + 2) + 1;
        func_80166994(a0, 2, 2, 0);
    } else {
        func_80166994(a0, 1, 2, (s32)*(s16 *)(a0 + 0x30));
    }
    if ((short)func_80166690(2, 1) == 0) {
        ((void (*)(s32))func_80146C3C)(a0);
    }
}
