/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015F738,8015F76C).
 * Offset 0x375E0 at overlay base 80128158. SHA256(span)=65b498f3be17fc14abf422e48a60160463452668b7c2be092e38cd21022a6d45.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015f738.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015F738 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801553A8(s32 *a0);
extern void func_80154A74(s32 a0, s32 a1);

void func_8015F738(s32 *a0) {
    func_801553A8(a0);
    func_80154A74((s32)a0, 0x11);
}
