/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015EFA4,8015EFD8).
 * Offset 0x36E4C at overlay base 80128158. SHA256(span)=e9f11199dae209624d3f369936a2e5f175a09f7e9d41e63efb331e459908bcf3.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015efa4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015EFA4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015F080(s32);

void func_8015EFA4(s32 *a0) {
    func_80147078(a0, 0x13);
    func_8015F080(a0);
}
