/* SC02.CD FILE_031 / ov_SC02_031 retail span [8013767C,801376C8).
 * Offset 0xF524 at overlay base 80128158. SHA256(span)=9596955eae32d7e2fcb33ac6455e89ca0c32d51becb5e238cb18a488f52622db.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8013767c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013767C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_801399A8(void);
extern void func_801377B4(s32 a0, s32 a1, s32 a2);

s32 func_8013767C(s32 a0) {
    s32 s0 = func_801399A8();
    if (s0 != 0) {
        func_801377B4(a0, 0, s0);
    }
    return s0;
}
