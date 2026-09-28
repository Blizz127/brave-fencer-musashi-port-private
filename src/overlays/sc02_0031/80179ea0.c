/* SC02.CD FILE_031 / ov_SC02_031 retail span [80179EA0,80179EE8).
 * Offset 0x51D48 at overlay base 80128158. SHA256(span)=6fa2132412e5a1e7fd2ae8100475b0f98cccced9049ba0a421ad0ee573afd7c1.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80179ea0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80179EA0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80179B74(u16 *p);

void func_80179EA0(u16 *a0) {
    s16 buf[4];
    buf[0] = 5;
    buf[1] = a0[0];
    buf[2] = a0[1];
    buf[3] = a0[2];
    func_80179B74(buf);
}
