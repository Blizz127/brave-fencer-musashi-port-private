/* SC02.CD FILE_031 / ov_SC02_031 retail span [80165770,801657A0).
 * Offset 0x3D618 at overlay base 80128158. SHA256(span)=a88433fd860e03b5410d60db70361080d04dc7cf877fb00435ceb13187108e64.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80165770.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165770 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80078EC1;
extern void func_800CAF6C(void);

void func_80165770(void) {
    if (D_80078EC1 == 0xC) {
        func_800CAF6C();
    }
}
