/* SC02.CD FILE_031 / ov_SC02_031 retail span [80154B98,80154BC8).
 * Offset 0x2CA40 at overlay base 80128158. SHA256(span)=04661d0bca0f01017a381e98080aaa60984b298e71b13c7a8a2dbe5598fd89f5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80154b98.c (m2c-derived, oracle MATCH); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80154B98 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80154BC8(void *a0, s32 a1, s32 a2);

void func_80154B98(void *a0, s32 a1, s32 a2) {
    if (*(s32 *)((s32)a0 + 0xD0) != a1) {
        func_80154BC8(a0, a1, a2);
    }
}
