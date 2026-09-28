/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016345C,801634D8).
 * Offset 0x3B304 at overlay base 80128158. SHA256(span)=ae10026f27ca6558da71ae1bbf1694280de1ad727a863cb2a13c4590f86e40df.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016345c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016345C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u16 func_80156370(u16 a0);
extern void func_80163534(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, u16 * a5);

void func_8016345C(s32 a0, u16 a1, s32 a2, u16 a3, s32 a4) {
    s32 r;
    r = func_80156370(a1);
    func_80163534(a0, a1, (u16)r, a2, a3, a4);
}
