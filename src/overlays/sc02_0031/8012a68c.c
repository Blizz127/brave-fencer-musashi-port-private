/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012A68C,8012A6D0).
 * Offset 0x2534 at overlay base 80128158. SHA256(span)=1697cb458c26ab02e95321543405ed23afd4962be0b96e3cc2724edc70ad35c3.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012a68c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012A68C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A7D4(void *a0, void *a1);
extern s32 func_8012A6D0(void *a0, void *a1);

s16 func_8012A68C(void) {
    s16 a[4];
    s16 b[4];
    func_8012A7D4(a, b);
    return (s16)func_8012A6D0(a, b);
}
