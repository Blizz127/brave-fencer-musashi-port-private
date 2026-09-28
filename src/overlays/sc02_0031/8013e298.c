/* SC02.CD FILE_031 / ov_SC02_031 retail span [8013E298,8013E2C4).
 * Offset 0x16140 at overlay base 80128158. SHA256(span)=8598f36edc074d30016ddb6ff6f220c96a99441016cb3ae9d007f20d3afd4fc0.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8013e298.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013E298 - byte-exact against retail at -O2 (tools/register_match.py). */
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

s32 func_8013E298(s16 *a0) {
    s32 diff;
    diff = a0[2] - D_80126CB0;
    if (diff < 0) {
        diff = -diff;
    }
    return (u32)(diff - 0x2C1) < 0x3F;
}
