/* SC02.CD FILE_031 / ov_SC02_031 retail span [80179D78,80179DCC).
 * Offset 0x51C20 at overlay base 80128158. SHA256(span)=a77054f95e407c6d4f6490206b9d5f8779528be6e0f5d59aaa46f5cf13abc2a6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80179d78.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80179D78 - byte-exact against retail at -O2 (tools/register_match.py). */
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

void func_80179D78(u16 *a0) {
    s16 sp[5];
    sp[0] = 0x1C;
    sp[1] = a0[0];
    sp[2] = a0[1];
    sp[3] = a0[2];
    sp[4] = a0[3];
    func_80179B74(sp);
}
