/* SC02.CD FILE_031 / ov_SC02_031 retail span [80162F08,80162F60).
 * Offset 0x3ADB0 at overlay base 80128158. SHA256(span)=ad96031ff1fb59723f83044bc1ac58a42e89cc148d3a72a8a34f0921385ef6c0.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80162f08.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80162F08 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80162F60(s32 arg0, s32 arg1);
extern void func_80162F80(s32 arg0, s32 arg1);
extern void func_80162FA0(s32 arg0, s32 arg1);

void func_80162F08(s32 a0, s32 a1, s32 a2, s32 a3) {
    func_80162F60(a0, a1);
    func_80162F80(a0, a2);
    func_80162FA0(a0, a3);
}
