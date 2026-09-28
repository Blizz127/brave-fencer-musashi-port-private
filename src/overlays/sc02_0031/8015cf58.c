/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015CF58,8015CF8C).
 * Offset 0x34E00 at overlay base 80128158. SHA256(span)=1e980744bf1706b8127b51428cfb1c9a02d8335890eeb9462e7576ca9411ff00.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015cf58.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015CF58 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015D01C();

void func_8015CF58(s32 *param_1)
{
    func_80147078(param_1, 0xC);
    ((void (*)(s32 *))func_8015D01C)(param_1);
}
