/* SC02.CD FILE_031 / ov_SC02_031 retail span [801663A4,801663FC).
 * Offset 0x3E24C at overlay base 80128158. SHA256(span)=7c7fe941e18e4936399c8b8cfdfba780c02766aa5e5b6b2aed8afd15864e9576.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801663a4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801663A4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);

void func_801663A4(void *a0) {
    func_80146A6C(3, a0, *(s16 *)((s32)a0 + 6),
                  (s16)(*(u16 *)((s32)a0 + 0xA) - 0x10),
                  *(s16 *)((s32)a0 + 0xE), 0xCCCFFF8, 0xE000C000);
}
