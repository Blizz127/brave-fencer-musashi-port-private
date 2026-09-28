/* SC02.CD FILE_031 / ov_SC02_031 retail span [801683D8,80168430).
 * Offset 0x40280 at overlay base 80128158. SHA256(span)=4f29d729baabea89036f9ed6eddce7565e7457df57b5c6e4b7243e0903a814ca.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801683d8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801683D8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80166994(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80166690();
extern void func_80146C3C();

void func_801683D8(s32 a0) {
    func_80166994(a0, 2, *(short *)(a0 + 0x2c), 0);
    if ((short)func_80166690(*(short *)(a0 + 0x2c), *(short *)(a0 + 0x28)) == 0) {
        ((void (*)(s32))func_80146C3C)(a0);
    }
}
