/* SC02.CD FILE_031 / ov_SC02_031 retail span [80163234,8016325C).
 * Offset 0x3B0DC at overlay base 80128158. SHA256(span)=4bef96788170048828e6e2e02676637d70ee7c1ece189f54eea24b7ab8b798df.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80163234.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80163234 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8016325C(s32 a0, s32 a1, s32 a2, s32 a3);

void func_80163234(s32 a0) {
    func_8016325C(a0, 0, 0, 0);
}
