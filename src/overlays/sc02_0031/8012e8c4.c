/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012E8C4,8012E8E0).
 * Offset 0x676C at overlay base 80128158. SHA256(span)=b886eac4cde9ddfcc4f1c843a4108d3e283ccffc117115e1d7e744717cd08271.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012e8c4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012E8C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_8012E8C4(u8 *a0) {
    s32 *p = *(s32 **)(a0 + 0x20);
    p[1] = p[1] ^ 0x80000000;
}
