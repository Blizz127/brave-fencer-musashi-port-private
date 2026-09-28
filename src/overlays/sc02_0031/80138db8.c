/* SC02.CD FILE_031 / ov_SC02_031 retail span [80138DB8,80138DE0).
 * Offset 0x10C60 at overlay base 80128158. SHA256(span)=4cd337d7032d0927c5d0ce6c0ed1a37c8e728ccaef24f387958a322077751e7d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80138db8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80138DB8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_80014E80(s32 a0, s32 a1);

s16 func_80138DB8(s32 a0, u8 a1, s32 a2) {
    return (s16)func_80014E80(a1, a2);
}
