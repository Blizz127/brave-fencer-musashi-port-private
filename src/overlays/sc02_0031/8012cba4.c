/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012CBA4,8012CBCC).
 * Offset 0x4A4C at overlay base 80128158. SHA256(span)=54fd6f9e994e58ff207947e31107ee265e2221b9d8d00c50dc99bd33cf1e2987.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012cba4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012CBA4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8012CC88();
extern u8 D_800D3918[];

void func_8012CBA4(s32 a0) {
    func_8012CC88(a0, 0, (s32)D_800D3918);
}
