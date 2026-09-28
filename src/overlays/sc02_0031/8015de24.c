/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015DE24,8015DE58).
 * Offset 0x35CCC at overlay base 80128158. SHA256(span)=65a7bd22f0c2238f6b7921a77f728629f028edd837daa0b0168b6a9c8885f0d0.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015de24.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015DE24 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015DE58();

void func_8015DE24(s32 *a0) {
    func_80147078(a0, 0xF);
    func_8015DE58(a0);
}
