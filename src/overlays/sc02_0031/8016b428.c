/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016B428,8016B448).
 * Offset 0x432D0 at overlay base 80128158. SHA256(span)=ac5e410cbe7d3209dd40afae8cfeab8178fb8545dfad91d4bfb834d4dfd91278.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016b428.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016B428 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8016B448(s32, s32);
extern void func_8012A568(void (*a0)(void));

s32 func_8016B428(s32 a0) {
    return func_8016B448(a0, 0);
}
