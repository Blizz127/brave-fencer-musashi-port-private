/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015C750,8015C788).
 * Offset 0x345F8 at overlay base 80128158. SHA256(span)=76ad9b0235139c6845381e719d49d1e3c24be2cee29efba1eaff576fb1784a4c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015c750.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015C750 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80161104();
extern void func_8015C788(s32);

void func_8015C750(s32 a0) {
    if (func_80161104(a0) != 0) {
        func_8015C788(a0);
    }
}
