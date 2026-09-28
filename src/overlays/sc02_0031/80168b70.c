/* SC02.CD FILE_031 / ov_SC02_031 retail span [80168B70,80168BDC).
 * Offset 0x40A18 at overlay base 80128158. SHA256(span)=3853f87d5db961f4b971d01b213ad4a24a7222964da67a0056fd245cf304dac5.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80168b70.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80168B70 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80168BDC(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80146C3C(void);

void func_80168B70(s32 a0) {
    s32 *p = (s32 *)a0;
    if (--p[0x1C / 4] != -1) {
        func_80168BDC(a0, 9, 3, 1);
    } else {
        func_80168BDC(a0, 9, 2, 1);
        ((void (*)(s32))func_80146C3C)(a0);
    }
}
