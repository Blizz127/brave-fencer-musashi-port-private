/* SC02.CD FILE_031 / ov_SC02_031 retail span [80158000,80158038).
 * Offset 0x2FEA8 at overlay base 80128158. SHA256(span)=12075c69894b4a002d5262801018f48d7b2f4f10aa9752a37d8f8c9bb1ce59ea.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80158000.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80158000 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80161104();
extern void func_80158038(void *);

void func_80158000(void *a0) {
    if (func_80161104(a0)) {
        func_80158038(a0);
    }
}
