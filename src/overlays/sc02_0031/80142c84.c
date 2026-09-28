/* SC02.CD FILE_031 / ov_SC02_031 retail span [80142C84,80142C9C).
 * Offset 0x1AB2C at overlay base 80128158. SHA256(span)=d5aa617a084a45633699e7fd853b8e1c121ea3d0470e39451f07832e49732ce1.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80142c84.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80142C84 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_80142C84(s32 a0) {
    *(s32 *)(a0 + 0x14) = 0xFFF40000;
    *(s32 *)(a0 + 0x48) = 0x20000;
    *(s16 *)(a0 + 0x102) = 0;
}
