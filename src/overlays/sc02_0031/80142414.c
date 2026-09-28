/* SC02.CD FILE_031 / ov_SC02_031 retail span [80142414,80142454).
 * Offset 0x1A2BC at overlay base 80128158. SHA256(span)=9dab4606ac508291ee887be5155a0948d70723ab614547a19c942f3cb4e2bc31.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80142414.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80142414 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8012C588(s32 a0, s32 a1);

void func_80142414(s32 a0, s16 a1) {
    s32 v0;
    v0 = func_8012C588(0x13, a0);
    if (v0 != 0) {
        *(s16*)(v0 + 0x52) = a1;
    }
}
