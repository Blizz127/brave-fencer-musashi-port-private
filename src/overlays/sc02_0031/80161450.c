/* SC02.CD FILE_031 / ov_SC02_031 retail span [80161450,80161488).
 * Offset 0x392F8 at overlay base 80128158. SHA256(span)=9605002a79cf0d1a7df5b51465c7cbb77cb8c069c0e9dcb012c34985326cc452.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80161450.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80161450 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_801615C4(void *a0, s32 a1);
extern s32 func_80161774(int param_1, u32 param_2);

void func_80161450(void *a0) {
    func_80161774(a0, func_801615C4(a0, 0));
}
