/* SC02.CD FILE_031 / ov_SC02_031 retail span [80161554,8016158C).
 * Offset 0x393FC at overlay base 80128158. SHA256(span)=14134342fb6a85533e052db1c9bbcb84eb6ad22d7df95ad8e6fdc6d2bf777c1f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80161554.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80161554 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_801615C4(void *a0, s32 a1);
extern s32 func_8016163C(s32 a0, u32 a1);

void func_80161554(void *a0) {
    func_8016163C(a0, func_801615C4(a0, 1));
}
