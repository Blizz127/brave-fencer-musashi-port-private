/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017AE08,8017AE2C).
 * Offset 0x52CB0 at overlay base 80128158. SHA256(span)=34abac137961b061862613cb08ab76471c5dad673bdd3b30c3e07a16ae9dd7be.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017ae08.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017AE08 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 func_80174764(void);

s32 func_8017AE08(void) {
    return ((s32 (*)(void))func_80174764)() == 1;
}
