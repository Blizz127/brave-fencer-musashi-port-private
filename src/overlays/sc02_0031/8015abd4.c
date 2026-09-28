/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015ABD4,8015AC48).
 * Offset 0x32A7C at overlay base 80128158. SHA256(span)=9a5099949e1e047a27b52471b14df38caeb0675a4852e1ff59573188a48abb21.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015abd4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015ABD4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8016F1AC(void);
extern s32 func_80029178(s32 a0);
extern s32 D_8011F9C4;

s32 func_8015ABD4(s32 a0, s32 a1, s32 a2) {
    if (func_8016F1AC() != 0) {
        return 0;
    }
    if (a2 < a1) {
        if (D_8011F9C4 == 0) {
            return 0;
        }
        if ((func_80029178(0x21) & 0xFF) != 0) {
            return 0;
        }
    }
    return 1;
}
