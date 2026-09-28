/* SC02.CD FILE_031 / ov_SC02_031 retail span [8014A830,8014A850).
 * Offset 0x226D8 at overlay base 80128158. SHA256(span)=fb5497b19d4ca8de36837e61c6250397b704278cb294cf47ed4532bcb46cf513.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8014a830.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014A830 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8015E184();

void func_8014A830(void) {
    func_8015E184();
}
