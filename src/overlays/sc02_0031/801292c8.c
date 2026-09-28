/* SC02.CD FILE_031 / ov_SC02_031 retail span [801292C8,8012931C).
 * Offset 0x1170 at overlay base 80128158. SHA256(span)=8244aa9f00ed4ff38a936a8a96b7340b155d38b5603c2f7bdafe1f4467b3ed57.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801292c8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801292C8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80016714(void *a0, s32 a1);

void func_801292C8(u8 *a0) {
    u16 *p = *(u16 **)(a0 + 0x20);
    if (p != 0) {
        func_80016714(p, (p[0] == 1) ? 0x84 : 0x38);
    }
    *(s16 *)a0 = 0;
}
