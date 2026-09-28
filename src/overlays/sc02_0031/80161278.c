/* SC02.CD FILE_031 / ov_SC02_031 retail span [80161278,801612B8).
 * Offset 0x39120 at overlay base 80128158. SHA256(span)=96c8f045866426223cd93b06e1345479f82a730b5d587f49d58d3f4299f4695e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80161278.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80161278 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801152BC;
extern s32 func_801612B8(void *a0, s32 a1);
extern int func_80161374(int param_1, unsigned int param_2);

void func_80161278(void *a0) {
    s32 r;
    D_801152BC = 0;
    r = func_801612B8(a0, 1);
    func_80161374(a0, r);
}
