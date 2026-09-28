/* SC02.CD FILE_031 / ov_SC02_031 retail span [80155FB0,80155FD4).
 * Offset 0x2DE58 at overlay base 80128158. SHA256(span)=e21d50f46b11cf3078e51cdc3fd64181ef2fb033db3b460831bd0c89c00f73ac.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80155fb0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80155FB0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern int func_80155FF8(int arg, int a1);

int func_80155FB0(int arg, int a1) {
    return func_80155FF8(arg, a1 | 0x10000);
}
