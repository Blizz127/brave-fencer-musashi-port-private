/* SC02.CD FILE_031 / ov_SC02_031 retail span [8014A71C,8014A738).
 * Offset 0x225C4 at overlay base 80128158. SHA256(span)=d5b42a4625dd7dd40034e2c90ef522a214734eb1e427633920bf1affe27d89b3.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8014a71c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014A71C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_8014A71C(s32 a0) {
    u8 v = *(u8 *)(a0 + 0x1BE);
    if (v != 0) {
        *(u8 *)(a0 + 0x1BE) = v - 1;
    }
}
