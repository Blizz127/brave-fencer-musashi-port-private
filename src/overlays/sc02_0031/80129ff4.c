/* SC02.CD FILE_031 / ov_SC02_031 retail span [80129FF4,8012A018).
 * Offset 0x1E9C at overlay base 80128158. SHA256(span)=f94000bb124fea8f9d2db4b36e106a71b0016ffb4f311478f42fb5b66aee57a2.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80129ff4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80129FF4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A018(s32 a, s32 b);

void func_80129FF4(void) {
    func_8012A018(0, 0);
}
