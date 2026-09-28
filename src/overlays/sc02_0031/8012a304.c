/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012A304,8012A328).
 * Offset 0x21AC at overlay base 80128158. SHA256(span)=4a855646b8c534c7beebd28f836c1c296b5ef365614b443f82a85edb5b233892.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012a304.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012A304 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s8 D_801152C0;
extern s16 D_80127080;
extern s16 D_801152C2;

void func_8012A304(s32 a0, s32 a1) {
    D_801152C0 = 1;
    D_80127080 = a0;
    D_801152C2 = a1;
}
