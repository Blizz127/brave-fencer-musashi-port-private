/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017A180,8017A1A8).
 * Offset 0x52028 at overlay base 80128158. SHA256(span)=5e7238bfd311a2bd3b9af545f9971e2e87e2d2c0504b1ffde95ab8408f396dc4.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017a180.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017A180 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80179B74(u16 *p);

void func_8017A180(void) {
    short sp10;
    sp10 = 0x9;
    func_80179B74(&sp10);
}
