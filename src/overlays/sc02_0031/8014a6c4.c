/* SC02.CD FILE_031 / ov_SC02_031 retail span [8014A6C4,8014A71C).
 * Offset 0x2256C at overlay base 80128158. SHA256(span)=5066b7b0714659c6d24e7121347959f1cc0474131e077727bea2b741122af9de.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8014a6c4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8014A6C4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80029178(s32 a0);

s32 func_8014A6C4(s32 a0) {
    s32 r;
    if ((func_80029178(0x1F) & 0xFF) == 0) {
        r = 0;
    } else if (*(s32 *)(a0 + 0x44) & 0x4) {
        r = 0;
    } else {
        r = *(u8 *)(a0 + 0x1BE) == 0;
    }
    return r;
}
