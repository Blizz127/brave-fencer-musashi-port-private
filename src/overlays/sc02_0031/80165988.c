/* SC02.CD FILE_031 / ov_SC02_031 retail span [80165988,801659A8).
 * Offset 0x3D830 at overlay base 80128158. SHA256(span)=dd9df9a98c801ee527b84af6c546fc885c59002e7fe29456743cd790a6de09af.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80165988.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165988 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_8012811C;

void func_80165988(void) {
    D_8012811C = D_8012811C + 1;
}
