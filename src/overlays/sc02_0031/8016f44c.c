/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F44C,8016F470).
 * Offset 0x472F4 at overlay base 80128158. SHA256(span)=a10ca67441093430f90dfe12e866c43b93b492a89595ad292f87e18b6f6d45de.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f44c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F44C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80029178(s32 a0);
extern void func_8012A568(void (*a0)(void));

s32 func_8016F44C(s32 a0) {
    return (func_80029178(a0 + 0x125) & 0xff) != 0;
}
