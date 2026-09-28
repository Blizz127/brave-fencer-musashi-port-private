/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015F048,8015F080).
 * Offset 0x36EF0 at overlay base 80128158. SHA256(span)=3bd1f17f5d10efafb6a26bc945bd85c51410fe17ad4a9af8928f3dc79558cf02.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015f048.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015F048 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80161104(void);
extern void func_8015F080(s32);

void func_8015F048(s32 a0) {
    if (func_80161104() != 0) {
        func_8015F080(a0);
    }
}
