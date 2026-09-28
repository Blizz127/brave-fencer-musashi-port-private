/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012ADE4,8012AE00).
 * Offset 0x2C8C at overlay base 80128158. SHA256(span)=df224b17f9960a88e4b46563f61a6a0d9288da4a2de3b9376d587239cf4d89a8.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012ade4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012ADE4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_8012ADE4(u8 *a0) {
    *(s32 *)(a0 + 0x4) = *(s32 *)(a0 + 0x38);
    *(s32 *)(a0 + 0x8) = *(s32 *)(a0 + 0x3C);
    *(s32 *)(a0 + 0xC) = *(s32 *)(a0 + 0x40);
}
