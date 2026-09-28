/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015D524,8015D544).
 * Offset 0x353CC at overlay base 80128158. SHA256(span)=78e537d36c6e3d91977aefed0edd0c1263dd2825b489dd141a7842064c1bd6fd.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015d524.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015D524 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80154A74(s32 a0, s32 a1);

void func_8015D524(s32 arg0) {
    func_80154A74(arg0, 0x11);
}
