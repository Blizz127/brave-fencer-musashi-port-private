/* SC02.CD FILE_031 / ov_SC02_031 retail span [80171990,801719A4).
 * Offset 0x49838 at overlay base 80128158. SHA256(span)=7865ab33e7d49d35d1f66b5d110722a55d021491932ec531ad19fb50bb364f95.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80171990.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80171990 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_80171990(u8 *a0)
{
    s32 v = a0[0x216] + 1;
    a0[0x216] = v;
    return v;
}
