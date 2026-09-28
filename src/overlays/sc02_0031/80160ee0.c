/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160EE0,80160F00).
 * Offset 0x38D88 at overlay base 80128158. SHA256(span)=a152539c0da8afdad90fb4a58421c8475fb47ea32b70dcde559d57fe4ef41c68.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160ee0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80160EE0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80160F00();

void func_80160EE0(void) {
    func_80160F00();
}
