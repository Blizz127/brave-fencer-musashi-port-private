/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012FCA4,8012FCC4).
 * Offset 0x7B4C at overlay base 80128158. SHA256(span)=57d6c47c0c7eca40fe3822e390541715abfd146e70609531e20692dd6f3f9bb7.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012fca4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012FCA4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80131CA8(int a0, int a1);

void func_8012FCA4(int a0) {
    func_80131CA8(a0, 0x1B);
}
