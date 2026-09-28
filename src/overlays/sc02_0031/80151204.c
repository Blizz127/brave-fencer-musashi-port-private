/* SC02.CD FILE_031 / ov_SC02_031 retail span [80151204,80151238).
 * Offset 0x290AC at overlay base 80128158. SHA256(span)=71c8d0a813a659d45f5772cc159d9af1c40818425484a65d3fddae0a269e2877.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80151204.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80151204 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8014ACE8(void *a0, s32 a1, s32 a2);

int func_80151204(int a0, int a1)
{
    if (a1 != 0 && a1 != 1000) {
        func_8014ACE8(a0, 1, a1 & 0x7FFF);
    }
}
