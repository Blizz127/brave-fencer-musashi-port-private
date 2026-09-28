/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012A758,8012A79C).
 * Offset 0x2600 at overlay base 80128158. SHA256(span)=71dbee9872f3c01e195a53041714c9d9bff86b59037b0f98f1bf6c6d8431195d.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012a758.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012A758 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A7D4(void *a0, void *a1);
extern s16 func_8012A79C(s16 *a0, s16 *a1);

s16 func_8012A758(void) {
    s16 a[4];
    s16 b[4];
    func_8012A7D4(a, b);
    return func_8012A79C(a, b);
}
