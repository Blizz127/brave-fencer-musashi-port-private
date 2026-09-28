/* SC02.CD FILE_031 / ov_SC02_031 retail span [80128EA8,80128ED8).
 * Offset 0xD50 at overlay base 80128158. SHA256(span)=430f480c56f9e800de1a7b97a5f6c5e421f84016a902f1276b0a9f15afca844f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80128ea8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80128EA8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_80128EA8(s32 a0, s32 a1, s32 a2) {
    *(s32 *)(a1 + 0x0) = a2;                       /* sw a2, 0x0(a1) */
    *(s16 *)(a1 + 0x4) = 0;                         /* sh zero, 0x4(a1) */
    *(s16 *)(a1 + 0x6) = (*(s32 *)(a2 + 0x4)) & 0x3F; /* lw; andi 0x3F; sh 0x6(a1) */
    *(s16 *)(a0 + 0x28) = *(u16 *)(a2 + 0x0);      /* lhu 0x0(a2); sh 0x28(a0) */
    *(s16 *)(a0 + 0x2A) = *(u16 *)(a2 + 0x2);      /* lhu 0x2(a2); sh 0x2A(a0) */
}
