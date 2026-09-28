/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015E84C,8015E880).
 * Offset 0x366F4 at overlay base 80128158. SHA256(span)=b268d9b7edff04f5880a17c736975bd92c9aa740e5601bba9cea05c702aa414c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015e84c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015E84C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015E95C(s32);

void func_8015E84C(s32 *a0) {
    func_80147078(a0, 0x11);
    func_8015E95C(a0);
}
