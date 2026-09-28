/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F398,8016F410).
 * Offset 0x47240 at overlay base 80128158. SHA256(span)=6e583d0de5ad39c23afba3cd344cd58757c04d243a6b9d8949d1bb4470e58bdf.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f398.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F398 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80029124(s32, s32);

void func_8016F398(void) {
    func_80029124(0x125, 0);
    func_80029124(0x126, 0);
    func_80029124(0x127, 0);
    func_80029124(0x128, 0);
    func_80029124(0x129, 0);
    func_80029124(0x12A, 0);
    func_80029124(0x12B, 0);
    func_80029124(0x12C, 0);
}
