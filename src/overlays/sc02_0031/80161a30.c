/* SC02.CD FILE_031 / ov_SC02_031 retail span [80161A30,80161A60).
 * Offset 0x398D8 at overlay base 80128158. SHA256(span)=71244adfa869568f1a198f240eb6093df994d2adbcde559847f123c30ca406a6.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80161a30.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80161A30 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_80078EC0;

s32 func_80161A30(s32 a0) {
    if (*(s16*)(a0 + 0x1C8) != 0) {
        return ((D_80078EC0 & 0x7F) ^ 0x5) == 0;
    }
    return 0;
}
