/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017A0F4,8017A11C).
 * Offset 0x51F9C at overlay base 80128158. SHA256(span)=5f852d0653ed11dd6fb9edb54a7cf87acc1627c1c6c88d89012ff5cecdc8a014.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017a0f4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017A0F4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80179B74(u16 *p);

void func_8017A0F4(void) {
    short sp10;
    sp10 = 0x7;
    func_80179B74(&sp10);
}
