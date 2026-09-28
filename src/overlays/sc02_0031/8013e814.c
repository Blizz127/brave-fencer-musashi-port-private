/* SC02.CD FILE_031 / ov_SC02_031 retail span [8013E814,8013E83C).
 * Offset 0x166BC at overlay base 80128158. SHA256(span)=bb012f763e07bf5281ee169375c2417a10b44a78c6374f4ac54c644cd6aa62c9.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8013e814.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8013E814 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_800D24A0(s32 arg);
extern void func_8013E6AC(void);

void func_8013E814(void) {
    func_800D24A0(0);
    func_8013E6AC();
}
