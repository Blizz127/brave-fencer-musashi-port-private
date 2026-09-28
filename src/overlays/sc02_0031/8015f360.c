/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015F360,8015F380).
 * Offset 0x37208 at overlay base 80128158. SHA256(span)=9927974d10a0f01c762e22024d8047e59d734b86a15e545a7d18104bf823dc54.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015f360.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015F360 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8015F380();

void func_8015F360(void) {
    func_8015F380();
}
