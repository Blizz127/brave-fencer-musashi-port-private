/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015C6E0,8015C714).
 * Offset 0x34588 at overlay base 80128158. SHA256(span)=e34c0dd3a14660a0e0e2aa77a153ea06cc44b3bfd33447663a70564bda1f3695.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015c6e0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015C6E0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_8015C714(void *a0);

void func_8015C6E0(s32 *a0) {
    func_80147078(a0, 0x9);
    func_8015C714(a0);
}
