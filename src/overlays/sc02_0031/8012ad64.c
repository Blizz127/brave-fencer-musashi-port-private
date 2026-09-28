/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012AD64,8012AD6C).
 * Offset 0x2C0C at overlay base 80128158. SHA256(span)=8a02e31281d9f26d2aba6661e7ee809cf475aea3e1dc2f9414d0f3223fd7bcc8.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012ad64.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012AD64 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_8012AD64(void *p, s16 v) {
    *(s16 *)((s32)p + (0x34)) = v;
}
