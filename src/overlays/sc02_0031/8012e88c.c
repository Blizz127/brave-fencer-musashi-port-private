/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012E88C,8012E8A8).
 * Offset 0x6734 at overlay base 80128158. SHA256(span)=0163b589b16a2ca6a6f8cb0a5c60b94d92ae9be305d0e24a67ecbbd71492fd1e.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012e88c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012E88C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_8012E88C(u8 *a0) {
    s32 *p = *(s32 **)(a0 + 0x20);
    p[1] = p[1] & 0x7FFFFFFF;
}
