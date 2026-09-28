/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012B21C,8012B23C).
 * Offset 0x30C4 at overlay base 80128158. SHA256(span)=2d141243bfdca1485d4387e60305141f5dcc6e8b50a7465580e985bc6b3c9bca.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012b21c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012B21C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_8012B21C(void *a0) {
    *(s32 *)((s32)a0 + 0x18) = 0;
    *(s32 *)((s32)a0 + 0x14) = 0;
    *(s32 *)((s32)a0 + 0x10) = 0;
    *(s32 *)((s32)a0 + 0x4C) = 0;
    *(s32 *)((s32)a0 + 0x44) = 0;
    *(s32 *)((s32)a0 + 0x48) = 0xC000;
}
