/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012CBF4,8012CC1C).
 * Offset 0x4A9C at overlay base 80128158. SHA256(span)=e0f23a418d387ab3d7d14650f6844ed48bf88acbec321d035f7e2590a13402d4.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012cbf4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012CBF4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u8 D_800D3918[];
extern s32 func_8012CC88();

void func_8012CBF4(s32 a0) {
    func_8012CC88(a0, 0x11, (s32)D_800D3918);
}
