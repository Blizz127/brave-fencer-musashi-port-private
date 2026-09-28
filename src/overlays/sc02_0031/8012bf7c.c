/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012BF7C,8012BFA8).
 * Offset 0x3E24 at overlay base 80128158. SHA256(span)=240fdfe81a01d2abe1cd0414bfbccf72090bbbc8c39dc7d592c97bc89106f45d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012bf7c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012BF7C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s16 D_80126CB0;

s32 func_8012BF7C(s16 *a0) {
    s32 diff;
    diff = a0[7] - D_80126CB0;
    if (diff < 0) {
        diff = -diff;
    }
    return diff >= 0x360;
}
