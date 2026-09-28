/* SC02.CD FILE_031 / ov_SC02_031 retail span [80171A10,80171A1C).
 * Offset 0x498B8 at overlay base 80128158. SHA256(span)=e35729a2e7f0619a4c27fdbe4a11cab12c28cbe245871b78485f2cd43669882c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80171a10.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80171A10 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

void func_80171A10(s32 *a0) {
    *(s8*)((s32)a0 + 0x217) = 2;
}
