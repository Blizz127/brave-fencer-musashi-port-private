/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012F0BC,8012F14C).
 * Offset 0x6F64 at overlay base 80128158. SHA256(span)=f04ad4b7ead982297473d32c419c109c6fe5a8dcaf7b369655ad711ad5914955.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012f0bc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012F0BC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8004D504(void *a0, void *a1, void *a2);

void func_8012F0BC(s32 *a0, s32 *a1, s32 *a2) {
    s32 in[3];
    s32 out[3];
    in[0] = a1[0] - (a0[5] << 16);
    in[1] = a1[1] - (a0[6] << 16);
    in[2] = a1[2] - (a0[7] << 16);
    func_8004D504(a0, in, out);
    a2[0] = out[0];
    a2[1] = out[1];
    a2[2] = out[2];
}
