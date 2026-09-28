/* SC02.CD FILE_031 / ov_SC02_031 retail span [80169E44,80169F00).
 * Offset 0x41CEC at overlay base 80128158. SHA256(span)=64e9cf7bd2ea5cc59f3bc13dd21fd43d0d2023da28b6cdfa2c995c9361f8aebb.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80169e44.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80169E44 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern void func_80146C3C();
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);

void func_80169E44(s32 a0) {
    s32 r;
    s32 p;
    if (func_80128ED8((void *)*(s32 *)(a0 + 0x20), (void *)(a0 + 0x24)) != 0) {
        ((void (*)(s32))func_80146C3C)(a0);
        return;
    }
    r = *(s32 *)(a0 + 0x1C);
    *(s32 *)(a0 + 0x1C) = r + 1;
    if (r < 3) {
        p = func_80146A6C(9, (void *)a0, *(s16 *)(a0 + 0x6),
                          *(s16 *)(a0 + 0xA),
                          *(s16 *)(a0 + 0xE),
                          *(s32 *)(a0 + 0x1C) & 1, 0);
        if (p != 0) {
            *(s16 *)(p + 0x12) = *(u16 *)(a0 + 0x12);
            *(s16 *)(p + 0x16) = *(u16 *)(a0 + 0x16);
            *(s16 *)(p + 0x1A) = *(u16 *)(a0 + 0x1A);
        }
    }
}
