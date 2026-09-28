/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016E728,8016E778).
 * Offset 0x465D0 at overlay base 80128158. SHA256(span)=6c78f27465f36b6ba62da57935256230dad239de3854736ed04a7b3e7ca2433d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016e728.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016E728 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80146C3C();
extern void func_8016E778();
extern void func_8012A568(void (*a0)(void));

void func_8016E728(u8 *a0) {
    s32 v0;
    s32 v1;
    v0 = (u16)*(u16 *)(a0 + 0x12) + 0x400;
    v1 = (u16)*(u16 *)(a0 + 0x16) - 8;
    *(u16 *)(a0 + 0x12) = v0;
    *(u16 *)(a0 + 0x16) = v1;
    if ((s16)v1 <= 0) {
        func_80146C3C();
    } else {
        func_8016E778();
    }
}
