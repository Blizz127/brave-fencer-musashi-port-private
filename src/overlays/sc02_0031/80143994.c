/* SC02.CD FILE_031 / ov_SC02_031 retail span [80143994,801439C0).
 * Offset 0x1B83C at overlay base 80128158. SHA256(span)=3c84805bede05c1f06db917f90ccd1980dcb0462c9683e7b1aa4a61edfcb13d1.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80143994.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80143994 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8012C658(s32 a0, s32 a1, s32 a2);

void func_80143994(s32 a0, s32 a1) {
    func_8012C658(0x1B, (s16)a1, a0);
}
