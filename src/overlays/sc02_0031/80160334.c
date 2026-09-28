/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160334,80160368).
 * Offset 0x381DC at overlay base 80128158. SHA256(span)=aa9ffe24c4b24870e4f4e03626a68de8b9630016a7403c60b1c29e7ec035ccc6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160334.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80160334 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_80160410(s32 *a0);

void func_80160334(s32 *a0) {
    func_80147078(a0, 0x1B);
    func_80160410(a0);
}
