/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015CF24,8015CF58).
 * Offset 0x34DCC at overlay base 80128158. SHA256(span)=6cbaad2ee00a00cc5b6ae6192257cdaf26a1d7a18a14acdc58d6a9a1cc87331b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015cf24.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015CF24 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801553C0(s32 a0);
extern void func_80154A74(s32 a0, s32 a1);

void func_8015CF24(s32 a0) {
    func_801553C0(a0);
    func_80154A74(a0, 0x11);
}
