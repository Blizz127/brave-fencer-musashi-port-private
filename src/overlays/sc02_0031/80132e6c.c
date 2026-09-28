/* SC02.CD FILE_031 / ov_SC02_031 retail span [80132E6C,80132EC4).
 * Offset 0xAD14 at overlay base 80128158. SHA256(span)=de4161c97551428100a8d63a3bfd6b608856cc2ad6634d558675644b4acb67b5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80132e6c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80132E6C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_80049324(s32 *a0, s32 *a1);
extern s16 D_80126CAC;
extern s16 D_80126CB0;

s32 func_80132E6C(s16 *a0) {
    s32 in[3];
    s32 out[3];
    in[0] = a0[3] - D_80126CAC;
    in[1] = 0;
    in[2] = a0[7] - D_80126CB0;
    func_80049324(in, out);
    return out[0] + out[2];
}
