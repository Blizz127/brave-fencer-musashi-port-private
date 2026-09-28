/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015DA5C,8015DA90).
 * Offset 0x35904 at overlay base 80128158. SHA256(span)=1f76bc0c158cb9c9e2811ceba319c8ff8620efebe6ae58a4bd7abbf77dab85fe.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015da5c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015DA5C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80154A74(s32 a0, s32 a1);
extern int func_8015E0D4(int);

void func_8015DA5C(s32 a0) {
    func_80154A74(a0, 0x11);
    func_8015E0D4(a0);
}
