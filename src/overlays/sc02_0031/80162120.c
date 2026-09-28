/* SC02.CD FILE_031 / ov_SC02_031 retail span [80162120,8016216C).
 * Offset 0x39FC8 at overlay base 80128158. SHA256(span)=2e284355ae1a0457a5e833ad012982392931fe8f98081ea91d3a25e3f491dda2.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80162120.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80162120 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_800291DC(s32);
extern s32 func_800D0D7C(s32, s32);
extern void func_800291C8(s32, s32);

void func_80162120(void) {
    s32 v0;
    if ((s16)func_800291DC(8) == 0) {
        v0 = func_800D0D7C(0, 1);
        func_800291C8(8, (s16)(v0 | 0x8000));
    }
}
