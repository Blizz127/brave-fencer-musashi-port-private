/* SC02.CD FILE_031 / ov_SC02_031 retail span [80165840,80165874).
 * Offset 0x3D6E8 at overlay base 80128158. SHA256(span)=adc475373e005e248fee63021ecbcaf7a0baf3020d0f9a4cbdc3b74d517f88bd.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80165840.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165840 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80078EC3;
extern void func_80165874(void);

void func_80165840(void) {
    if (D_80078EC3 != 0) {
        D_80078EC3 = 0;
        func_80165874();
    }
}
