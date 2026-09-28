/* SC02.CD FILE_031 / ov_SC02_031 retail span [801742E0,80174318).
 * Offset 0x4C188 at overlay base 80128158. SHA256(span)=c590851bf15d37f1a120c42903013880a068b2d3d341f4715ab2f0f685f9e91a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801742e0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801742E0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80147060(u8 *a0);
extern void func_80171A1C(u8 *a0);
extern void func_80174318(u8 *a0);

void func_801742E0(u8 *a0) {
    func_80147060(a0);
    func_80171A1C(a0);
    func_80174318(a0);
}
