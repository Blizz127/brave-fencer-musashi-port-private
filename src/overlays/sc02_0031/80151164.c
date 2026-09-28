/* SC02.CD FILE_031 / ov_SC02_031 retail span [80151164,80151184).
 * Offset 0x2900C at overlay base 80128158. SHA256(span)=ec7c149ed193f4da71e062c616ccae27b24959be1c969818131b1dcd5409db7a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80151164.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80151164 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80151184(s32 a0, s32 a1, s32 a2);

s32 func_80151164(s32 a0, s32 a1) {
    return func_80151184(a0, a1, 0xA);
}
