/* SC02.CD FILE_031 / ov_SC02_031 retail span [801603D8,80160410).
 * Offset 0x38280 at overlay base 80128158. SHA256(span)=a2eecd0aa21202e91facd390a8ced71921301c4a69b328836efbeb4759522d06.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801603d8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801603D8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80161104(void);
extern void func_80160410(s32 *a0);

void func_801603D8(s32 *a0) {
    if (func_80161104()) {
        func_80160410(a0);
    }
}
