/* SC02.CD FILE_031 / ov_SC02_031 retail span [80141C50,80141CA4).
 * Offset 0x19AF8 at overlay base 80128158. SHA256(span)=ef5f83027c704e294b206644d70917fdb7be149b2b603616e5e76d4bd60f0c49.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80141c50.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80141C50 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80015144(void);
extern u16 D_8011511C;
extern u16 D_8011511E;

s32 func_80141C50(void) {
    if (D_8011511C != 0x90F) {
        return 0;
    }
    if ((D_8011511E & 0x800) == 0) {
        return 0;
    }
    return func_80015144() != 0;
}
