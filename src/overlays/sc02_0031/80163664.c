/* SC02.CD FILE_031 / ov_SC02_031 retail span [80163664,801636D0).
 * Offset 0x3B50C at overlay base 80128158. SHA256(span)=b32fd59e8bdfd3be020cd46bb97ce3bb8c10678c3d3f94fe859a30baae018244.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80163664.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80163664 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80157158();

void func_80163664(s32 a0, u16 a1, u16 a2, s32 a3, s32 a4, s32 a5, s32 a6, s32 a7, s32 a8, s32 a9, u16 a10, s32 a11, s32 a12) {
    func_80157158(a0, a1 & 0xFFFF, a2 & 0xFFFF, a3, a4, a5, a6, a7, a8, a9, a10, a11, a12);
}
