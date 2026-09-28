/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80168AE4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80168BDC(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);

void func_80168AE4(s32 a0) {
    s32 s0 = a0;
    func_80168BDC(s0, 9, 3, 2);
    func_80168BDC(s0, 9, 2, 1);
    func_80146A6C(3, (void *)s0, *(s16 *)(s0 + 0x6), *(s16 *)(s0 + 0xA),
                  *(s16 *)(s0 + 0xE), -5, 0xC0009C00);
    *(s32 *)(s0 + 0x1C) = 1;
    *(s16 *)(s0 + 0x2) = *(u16 *)(s0 + 0x2) + 1;
}
