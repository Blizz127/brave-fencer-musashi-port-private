/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015BEE4,8015BF04).
 * Offset 0x33D8C at overlay base 80128158. SHA256(span)=7fe428d51066dfdf13fc5565d79e23157f1e760a16515f57ba0a565ca5c899a9.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015bee4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015BEE4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8015B950(s32 arg0);

s32 func_8015BEE4(void) {
    return ((s32 (*)(void))func_8015B950)();
}
