/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160888,801608C0).
 * Offset 0x38730 at overlay base 80128158. SHA256(span)=e20428464f46c22bb67cf65fa42b7fadb3f0db1fbd0f8a82c362579a36fc8f06.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160888.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80160888 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80161104();
extern void func_801608C0(s32 *a0);

void func_80160888(s32 *a0) {
    if (func_80161104(a0)) {
        func_801608C0(a0);
    }
}
