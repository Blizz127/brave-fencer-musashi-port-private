/* SC02.CD FILE_031 / ov_SC02_031 retail span [80138C30,80138C60).
 * Offset 0x10AD8 at overlay base 80128158. SHA256(span)=8c18d5bb21e4f558c7922a2bb661ba9867a55159267f0832384faf19f9254a78.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80138c30.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80138C30 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_80138C30(void *a0) {
    if (*(s16 *)((s32)a0 + 4) == 4) {
        *(s16 *)((s32)a0 + 4) = 2;
    } else {
        *(u32 *)((s32)a0 + 8) |= 0x800;
    }
}
