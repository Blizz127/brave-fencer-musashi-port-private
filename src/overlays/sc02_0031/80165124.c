/* SC02.CD FILE_031 / ov_SC02_031 retail span [80165124,80165140).
 * Offset 0x3CFCC at overlay base 80128158. SHA256(span)=d915d84ad6be018187ddd859660cec4f179fc8a12560265e8c5c07c04b5facc6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80165124.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165124 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_80165124(void *a0) {
    *(s8 *)((s32)a0 + 0x50) = *(u16 *)((s32)a0 + 0x62);
    *(s8 *)((s32)a0 + 0x51) = *(u16 *)((s32)a0 + 0x62);
    *(s8 *)((s32)a0 + 0x52) = *(u16 *)((s32)a0 + 0x62);
}
