/* SC02.CD FILE_031 / ov_SC02_031 retail span [80162F80,80162FA0).
 * Offset 0x3AE28 at overlay base 80128158. SHA256(span)=5bd3ece3abe0a688db93d6fb1a92cd7a7ec5ad9c7af82237ef3f6fd1f895fda8.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80162f80.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80162F80 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801479BC(s32 a0, s32 a1, s32 a2);

void func_80162F80(s32 arg0, s32 arg1) {
    func_801479BC(arg0, arg1, 0x7F0000);
}
