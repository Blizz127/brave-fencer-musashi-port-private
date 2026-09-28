/* SC02.CD FILE_031 / ov_SC02_031 retail span [80132EF4,80132F40).
 * Offset 0xAD9C at overlay base 80128158. SHA256(span)=fb36d751c936b2f15f652610cce54ab0d3280c8f823cabc98705f888381a80d1.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80132ef4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80132EF4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern u8 *func_8012913C(s32 a0);
extern void func_80129350(s32 a0, s32 a1);

s32 func_80132EF4(s32 a0, s32 a1) {
    s32 s0 = func_8012913C(a1 & 0xFFFF);
    if (s0 != 0) {
        func_80129350(s0, a0);
    }
    return s0;
}
