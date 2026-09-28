/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012CC40,8012CC64).
 * Offset 0x4AE8 at overlay base 80128158. SHA256(span)=3756baa404c7b9cc5d9468549b5be35738ef4215b42ad637059cba883fed03a8.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012cc40.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012CC40 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8012CC88();

void func_8012CC40(s32 arg0, s32 arg1) {
    func_8012CC88(arg0, 1, arg1);
}
