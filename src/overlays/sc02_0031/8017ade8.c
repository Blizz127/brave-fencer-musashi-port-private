/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017ADE8,8017AE08).
 * Offset 0x52C90 at overlay base 80128158. SHA256(span)=266411a03184626c44d33dd7dc089beec5fd2d5f25a16ec35e4f8948145f0953.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017ade8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017ADE8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_8017AD0C(s32);

s32 func_8017ADE8(s32 a0) {
    return func_8017AD0C(a0);
}
