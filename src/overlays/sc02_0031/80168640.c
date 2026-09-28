/* SC02.CD FILE_031 / ov_SC02_031 retail span [80168640,80168664).
 * Offset 0x404E8 at overlay base 80128158. SHA256(span)=7fc72c9f69cadad20c86c0b43fca539e0f0acf80746908ba9300f5f4f7c25a46.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80168640.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80168640 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_80168640(s32 a0) {
    *(s32 *)(a0 + 0x1C) = 0x20;
    *(u16 *)(a0 + 0x12) = 0;
    *(u16 *)(a0 + 0x10) = 0x80;
    *(u16 *)(a0 + 0x2) = *(u16 *)(a0 + 0x2) + 1;
}
