/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015BF7C,8015BFB0).
 * Offset 0x33E24 at overlay base 80128158. SHA256(span)=943600a6c6433bd03b21174ba710128a2c7455312d60fb0d7660f9b44668662b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015bf7c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015BF7C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015BFF4(void *a0);

void func_8015BF7C(s32 *a0) {
    func_80147078(a0, 0x4);
    func_8015BFF4(a0);
}
