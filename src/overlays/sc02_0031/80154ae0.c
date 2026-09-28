/* SC02.CD FILE_031 / ov_SC02_031 retail span [80154AE0,80154B20).
 * Offset 0x2C988 at overlay base 80128158. SHA256(span)=63e67bacee3bda188a5b68a8fb7fb69e496a5be01f0d159f66105936bfc3641e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80154ae0.c (m2c-derived, oracle MATCH); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80154AE0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80154B20(s32 a0, s32 a1, s32 a2);

void func_80154AE0(s32 a0, s32 a1, s32 a2) {
    if (*(s32 *)(a0 + 0xD0) != ((s32 *)*(s32 **)(a0 + 0xCC))[a1]) {
        func_80154B20(a0, a1, a2);
    }
}
