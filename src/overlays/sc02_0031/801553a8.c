/* SC02.CD FILE_031 / ov_SC02_031 retail span [801553A8,801553C0).
 * Offset 0x2D250 at overlay base 80128158. SHA256(span)=3d2cab15a2c361f1e329a01ed12bcb9fea650730daf46667490be0521cf411f1.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801553a8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801553A8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801553A8(s32 *a0) {
    *(s32 *)((s32)a0 + 0x44) &= 0xDFFFFFFF;
}
