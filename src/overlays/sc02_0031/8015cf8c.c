/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015CF8C,8015CFC0).
 * Offset 0x34E34 at overlay base 80128158. SHA256(span)=01783322ae0a52324a0921b0c22f84b1736980cba747cb36799374a10b85bb42.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015cf8c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015CF8C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015CFC0();

void func_8015CF8C(s32 *a0) {
    func_80147078(a0, 0xC);
    func_8015CFC0(a0);
}
