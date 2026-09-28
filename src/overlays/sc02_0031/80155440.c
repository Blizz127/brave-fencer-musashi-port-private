/* SC02.CD FILE_031 / ov_SC02_031 retail span [80155440,80155458).
 * Offset 0x2D2E8 at overlay base 80128158. SHA256(span)=8d6b7a899b76ea2a0aa22e2ab4c80cfab40ef7c95722ec5a7170b301fc8849b2.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80155440.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80155440 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_80155440(s32 *a0) {
    *(s32 *)((s32)a0 + 0x44) &= 0xEFFFFFFF;
}
