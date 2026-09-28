/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012A8E8,8012A908).
 * Offset 0x2790 at overlay base 80128158. SHA256(span)=12611acd33f6dc175dc070161a1a6ac0766b749b3bde67e1c97104453e03f3d3.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012a8e8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012A8E8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012AAAC();

void func_8012A8E8(void) {
    func_8012AAAC();
}
