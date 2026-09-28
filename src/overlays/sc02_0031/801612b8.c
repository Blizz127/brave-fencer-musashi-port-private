/* SC02 resident retail span [801612B8,8016130C). Offset 0x39160 at base 80128158.
 * SHA256(span)=7ba46055884c2bcca8d1a5e12724bddaca8530085ccf59dda897a015fd5ae973.
 * Words are the guest's loaded image (artifacts/sc02-resident-20260910); the
 * C is the Druthulu shared/ov func_801612B8 shape (h_exact 5fffbf1e) with its
 * keepalive exactly as published. Oracle MATCH 21/21. Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801612B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8014E934(s32 a0);
extern void func_8014CC28(s32 a0);
extern s32 func_8014F3E8(s32 a0);

s32 func_801612B8(void * a0, s32 a1)
{
    register s32 p __asm__("$17");
    register s32 v0 __asm__("$16");
    s32 v1;
    p = a0;
    if ((a1 & 1) == 0) {
        func_8014E934(p);
    }
    v0 = ((s32 (*)(s32))func_8014CC28)(p);
    __asm__ __volatile__("" : : "r"(v0));
    v1 = ((s32 (*)(s32))func_8014F3E8)(p);
    return v0 | v1;
}
