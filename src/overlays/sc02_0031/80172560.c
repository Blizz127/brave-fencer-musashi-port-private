/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172560,80172588).
 * Offset 0x4A408 at overlay base 80128158. SHA256(span)=137089fa4af940f85e0d92cb4dc29b9c4cb0ef35d864548877fb3614087a5813.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172560.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172560 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_80013450(s32);

s32 func_80172560(u8 *a0, u8 *a1) {
    *(s16 *)(a1 + 2) = *(u16 *)(a0 + 0xA);
    return func_80013450((s32)(a0 + 4)) < 0x10;
}
