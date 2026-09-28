/* SC02.CD FILE_031 / ov_SC02_031 retail span [801375EC,80137614).
 * Offset 0xF494 at overlay base 80128158. SHA256(span)=54c7412411d2c4dd1e04b71d8f4179008fdb9a2225e75eec7507c75d859e88bf.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801375ec.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801375EC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80137614(s32 a0, s32 a1, s32 a2);

void func_801375EC(s32 a0, s16 a1) {
    func_80137614(a0, a1, 0);
}
