/* SC02.CD FILE_031 / ov_SC02_031 retail span [80151094,801510B8).
 * Offset 0x28F3C at overlay base 80128158. SHA256(span)=5720fe9a1143bbe6ed0341c478ddc6d25e129a652dad81ad5ee1262305ed0206.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80151094.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80151094 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern int func_80151184(int arg, int a1, int a2);

int func_80151094(int arg) {
    return func_80151184(arg, 0xC00D, 0x18);
}
