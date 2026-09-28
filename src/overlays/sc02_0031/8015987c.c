/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015987C,801598BC).
 * Offset 0x31724 at overlay base 80128158. SHA256(span)=e28af0229af976e392a4a98a748f8294ad837062104ce20728783ba632e2f8d8.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015987c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015987C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_800167B8(s32 a0);

s32 func_8015987C(s32 a0) {
    func_800167B8(4);
    *(u8 *)(a0 + 0x15) = *(u8 *)(a0 + 0x15) + 1;
    return 0;
}
