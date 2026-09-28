/* SC02.CD FILE_031 / ov_SC02_031 retail span [801599E0,80159A18).
 * Offset 0x31888 at overlay base 80128158. SHA256(span)=179c8f31a716f557e876339b8ae09069a5a32d5324a0669272d271853f47453e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801599e0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801599E0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80159A20();

void func_801599E0(void *a0) {
    func_80159A20(a0);
    *(u8 *)((s32)a0 + 0x4D) += 1;
}
