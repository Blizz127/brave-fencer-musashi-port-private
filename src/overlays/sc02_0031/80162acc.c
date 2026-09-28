/* SC02.CD FILE_031 / ov_SC02_031 retail span [80162ACC,80162AE0).
 * Offset 0x3A974 at overlay base 80128158. SHA256(span)=7f8d0c89fdfba35e91bfa5dd9a24914f5248f6eae2b023b189a7cdc54ad10e0b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80162acc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80162ACC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


s32 func_80162ACC(u8 *a0)
{
    s32 v = a0[1] + 1;
    a0[1] = v;
    return v;
}
