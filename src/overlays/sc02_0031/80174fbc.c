/* SC02.CD FILE_031 / ov_SC02_031 retail span [80174FBC,80175014).
 * Offset 0x4CE64 at overlay base 80128158. SHA256(span)=0dc4c99278e3ad177e191a1814c81a81a669a3836a1f8cd200cccc12439b8e48.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80174fbc.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80174FBC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_80175014(u8 *a0, u8 *a1, s32 a2);

void func_80174FBC(u8 *a0) {
    u16 *p = (u16 *)(a0 + 0x38);
    if ((*p & 0x7FFF) != 0) {
        func_80175014(a0, *(u8 **)(a0 + 0x34), *p & 0x7FFF);
        *p = *p - 1;
    } else {
        *p = *p | 0x8000;
    }
}
