/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017A2C0,8017A2E8).
 * Offset 0x52168 at overlay base 80128158. SHA256(span)=0ea2e5fed5b190874ba16803ddda20c4d7e7aeea8d5615024aa4dad8b4407b8b.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017a2c0.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017A2C0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80179B74(u16 *p);

void func_8017A2C0(void) {
    short sp10;
    sp10 = 0xF;
    func_80179B74(&sp10);
}
