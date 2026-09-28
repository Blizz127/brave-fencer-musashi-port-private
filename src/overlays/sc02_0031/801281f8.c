/* SC02.CD FILE_031 / ov_SC02_031 retail span [801281F8,80128218).
 * Offset 0xA0 at overlay base 80128158. SHA256(span)=e910716af94dccfaf86514ae21067cad3094aef376a5fa4efceaaa2852d60725.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801281f8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801281F8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8013E558(void);

void func_801281F8(void) {
    func_8013E558();
}
