/* SC02.CD FILE_031 / ov_SC02_031 retail span [80138948,8013895C).
 * Offset 0x107F0 at overlay base 80128158. SHA256(span)=fa42957481fd4c31f2408a423dfb62fbe5f8cbfb3fea7626028d6bf67c0f91ef.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80138948.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80138948 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_80138948(void *a0) {
    *(s16 *)((s32)a0 + 0x4)  = 7;
    *(s8  *)((s32)a0 + 0x1F) = 0;
    *(s8  *)((s32)a0 + 0xD)  = 0;
}
