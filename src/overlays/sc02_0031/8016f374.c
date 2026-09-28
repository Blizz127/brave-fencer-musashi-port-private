/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F374,8016F388).
 * Offset 0x4721C at overlay base 80128158. SHA256(span)=72e04a8d1d49aa938e897dd333ea35228816d2f854127616711edc4621252595.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f374.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F374 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_800B9A17;

void func_8016F374(void)
{
    D_800B9A17 = 1;
}
