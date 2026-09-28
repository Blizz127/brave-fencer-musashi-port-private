/* SC02.CD FILE_031 / ov_SC02_031 retail span [80157880,801578C0).
 * Offset 0x2F728 at overlay base 80128158. SHA256(span)=2bf1cd8e90bc64dc4b71a77bad32c33a843786cab07b279ebfad4d3ca881fdf4.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80157880.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80157880 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8014ED28();
extern void func_8014D3E0();
extern void func_8014FA04(s32 a0);
extern void func_801578C0(s32 a0);

void func_80157880(s32 a0) {
    func_8014ED28(a0);
    func_8014D3E0(a0);
    func_8014FA04(a0);
    func_801578C0(a0);
}
