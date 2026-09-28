/* SC02.CD FILE_031 / ov_SC02_031 retail span [80165024,80165064).
 * Offset 0x3CECC at overlay base 80128158. SHA256(span)=8b0d4e0600f155603674295f32f90d47c655f1147c1d311edaae6038456da94f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80165024.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165024 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80146E98(s32 a0);
extern void func_80146CA0(void *a0);
extern void func_801651B8(void *a0);

void func_80165024(void *a0) {
    if (func_80146E98((s32)a0)) {
        func_80146CA0(a0);
    }
    func_801651B8(a0);
}
