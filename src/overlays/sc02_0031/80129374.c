/* SC02.CD FILE_031 / ov_SC02_031 retail span [80129374,80129398).
 * Offset 0x121C at overlay base 80128158. SHA256(span)=d3104ed8f18e83f68b7c95b1e5296cb4b3384ba8c53e9dd2b1e72c962513cea3.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80129374.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80129374 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_80129374(s32 a0, s32 a1) {
    *(s32 *)(a0 + 0x10) = *(s32 *)(a1 + 0x10);
    *(s32 *)(a0 + 0x14) = *(s32 *)(a1 + 0x14);
    *(s32 *)(a0 + 0x18) = *(s32 *)(a1 + 0x18);
}
