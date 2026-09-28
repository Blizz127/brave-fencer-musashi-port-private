/* SC02.CD FILE_031 / ov_SC02_031 retail span [80151924,80151944).
 * Offset 0x297CC at overlay base 80128158. SHA256(span)=164661efd047780662814915f3209c8b4ebe74528662878035bbcfd2dc3c4663.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80151924.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80151924 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80151944(void *a0);

s32 func_80151924(void) {
    return ((s32 (*)(void))func_80151944)();
}
