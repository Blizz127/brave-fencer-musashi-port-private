/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012B23C,8012B260).
 * Offset 0x30E4 at overlay base 80128158. SHA256(span)=5f0f873c2f6d20e722c043f617fdf1d2769f5efd372cbdcfe6cbf09134e8b933.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012b23c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012B23C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_8012B23C(s32 a0) {
    *(s32 *)(a0 + 0x18) = 0;
    *(s32 *)(a0 + 0x14) = 0;
    *(s32 *)(a0 + 0x10) = 0;
    *(s32 *)(a0 + 0x4C) = 0;
    *(s32 *)(a0 + 0x44) = 0;
    *(s32 *)(a0 + 0x48) = 0x18000;
}
