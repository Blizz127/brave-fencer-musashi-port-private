/* SC02.CD FILE_031 / ov_SC02_031 retail span [80173174,8017319C).
 * Offset 0x4B01C at overlay base 80128158. SHA256(span)=317cc1d3eaa4d44339e08df521d17f2dbb99172e468d4a8be2f0783b40d4672a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80173174.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80173174 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80174684(void *);
extern s32 func_8017319C();

void func_80173174(void) {
    func_80174684((void *)func_8017319C);
}
