/* SC02.CD FILE_031 / ov_SC02_031 retail span [80143C74,80143C98).
 * Offset 0x1BB1C at overlay base 80128158. SHA256(span)=d2af54763a1a1a97bfb6c210927ca9b5cec309a1069102d9c14da906a054a8a6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80143c74.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80143C74 - byte-exact against retail at -O2 (tools/register_match.py). */
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

void func_80143C74(s32 a0, s32 a1) {
    func_8012C658(0x205, a1, a0);
}
