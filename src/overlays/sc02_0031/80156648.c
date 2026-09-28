/* SC02.CD FILE_031 / ov_SC02_031 retail span [80156648,80156670).
 * Offset 0x2E4F0 at overlay base 80128158. SHA256(span)=3f54c39eb256c3bde5eea91bf813e0d39c0b35fa89b3dd39996b3660c74f055c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80156648.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80156648 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80156A14(s32 *a0);

void func_80156648(s32 *a0) {
    *((u8 *)a0 + 0x1A8) = 0;
    *((u8 *)a0 + 0x1A9) = 0;
    *((u8 *)a0 + 0x1C0) = 0;
    func_80156A14(a0);
}
