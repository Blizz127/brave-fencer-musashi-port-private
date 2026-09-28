/* SC02.CD FILE_031 / ov_SC02_031 retail span [80154150,80154190).
 * Offset 0x2BFF8 at overlay base 80128158. SHA256(span)=6922ce0c04de99e15d6cda3d691254a52d58798cf062d02f2504cb990885af0f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80154150.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80154150 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80154190(u8 *a0, s32 a1);

void func_80154150(s32 a0, s32 a1)
{
    if (*(s32 *)(a0 + 0xB4) != ((s32 *)*(s32 *)(a0 + 0xB0))[a1]) {
        func_80154190(a0, a1);
    }
}
