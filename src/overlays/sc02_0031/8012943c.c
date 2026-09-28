/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012943C,8012944C).
 * Offset 0x12E4 at overlay base 80128158. SHA256(span)=6f5ae75d843634b01e87cc6ba089c244941f5535bf7a3bed8f77eeca499492fd.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012943c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012943C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_80114EE0;

void func_8012943C(void) {
    D_80114EE0 = 0;
}
