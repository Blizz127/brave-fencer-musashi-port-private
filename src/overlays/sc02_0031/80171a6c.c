/* SC02.CD FILE_031 / ov_SC02_031 retail span [80171A6C,80171A80).
 * Offset 0x49914 at overlay base 80128158. SHA256(span)=eba2ff8fb2bdf643c6f4b305df1cfe260fb2283700df877927842b9146fcd964.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80171a6c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80171A6C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

s32 func_80171A6C(u8 *a0) {
    s32 v0 = a0[0x216] - 1;
    a0[0x216] = v0;
    return v0;
}
