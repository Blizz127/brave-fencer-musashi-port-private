/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172EFC,80172F24).
 * Offset 0x4ADA4 at overlay base 80128158. SHA256(span)=0ef39a6ca74b531b6b64240984c3192852d64fdc2fd4c7cf7262400b2a693066.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172efc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172EFC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8017303C(void *);
extern u8 D_800D599C[];

void func_80172EFC(void) {
    func_8017303C(D_800D599C);
}
