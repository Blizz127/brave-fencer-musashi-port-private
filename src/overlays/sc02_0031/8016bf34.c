/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016BF34,8016BF50).
 * Offset 0x43DDC at overlay base 80128158. SHA256(span)=8e3cfeb5f6d2a8d5494bdcce39a680ce6247d390983ba368b88e7e04bd7b613f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016bf34.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016BF34 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

void func_8016BF34(void *a0) {
    *(s16 *)((s32)a0 + 0x12) = *(u16 *)((s32)a0 + 0x6);
    *(s16 *)((s32)a0 + 0x16) = *(u16 *)((s32)a0 + 0xA);
    *(s16 *)((s32)a0 + 0x1A) = *(u16 *)((s32)a0 + 0xE);
}
