/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012BF4C,8012BF54).
 * Offset 0x3DF4 at overlay base 80128158. SHA256(span)=ab96ea14c4cd28075ba493ec7f9c5835812a77b78c5b86afd972b2b5adb04d37.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012bf4c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012BF4C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_8012BF4C(s32 *a0, s32 a1) {
        *(s32 *)((s32)a0 + 0x1C) = a1;
    }
