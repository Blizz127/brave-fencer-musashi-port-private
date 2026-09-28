/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015CFFC,8015D01C).
 * Offset 0x34EA4 at overlay base 80128158. SHA256(span)=76a665b7626930261dcc3b6b0e69a2ce845c2f92fc0da9c1f53b73eded297324.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015cffc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015CFFC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8015D01C();

void func_8015CFFC(void) {
    func_8015D01C();
}
