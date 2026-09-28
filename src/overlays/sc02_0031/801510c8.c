/* SC02.CD FILE_031 / ov_SC02_031 retail span [801510C8,801510EC).
 * Offset 0x28F70 at overlay base 80128158. SHA256(span)=efc506eb54f0c93ddd0b9f521937a0ffd099444274a51d1b94c30238a7c4cb99.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801510c8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801510C8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern int func_80151184(int arg, int a1, int a2);

int func_801510C8(int arg) {
    return func_80151184(arg, 0x4018, 0x20);
}
