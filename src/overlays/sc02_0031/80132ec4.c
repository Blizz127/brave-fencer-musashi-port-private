/* SC02.CD FILE_031 / ov_SC02_031 retail span [80132EC4,80132EF4).
 * Offset 0xAD6C at overlay base 80128158. SHA256(span)=1f9f0f3b09308b2a6ed44ce2ee642ce1aaa1b3ad237f0b2e325c99df7cab7edc.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80132ec4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80132EC4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_80132EC4(void *a0, s16 a1) {
    while (*(s32 *)a0 != 0) {
        *(s16 *)((s32)a0 + 4) = a1;
        a0 = (void *)((s32)a0 + 8);
    }
}
