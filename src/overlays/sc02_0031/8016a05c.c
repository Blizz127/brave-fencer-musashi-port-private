/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016A05C,8016A08C).
 * Offset 0x41F04 at overlay base 80128158. SHA256(span)=de0e1e434ffc1d84c12da038cf5f0848c8f64d6bd0ea363ebd1e7adb2251eb7b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016a05c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016A05C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80078EC0;

void func_8016A05C(void *a0) {
    s32 v0;
    if (D_80078EC0 & 0x7F) {
        v0 = *(u16 *)((s32)a0 + 2) + 1;
    } else {
        v0 = 2;
    }
    *(s16 *)((s32)a0 + 2) = v0;
}
