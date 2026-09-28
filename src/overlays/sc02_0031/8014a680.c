/* SC02.CD FILE_031 / ov_SC02_031 retail span [8014A680,8014A69C).
 * Offset 0x22528 at overlay base 80128158. SHA256(span)=132d056f3e7b8a198df2da2b34557521df4510f81902478e8d864f073a7feb23.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8014a680.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014A680 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_8014A680(s32 a0) {
    u8 v = *(u8 *)(a0 + 0x1BC);
    if (v != 0) {
        *(u8 *)(a0 + 0x1BC) = v - 1;
    }
}
