/* SC02.CD FILE_031 / ov_SC02_031 retail span [801733A4,801733CC).
 * Offset 0x4B24C at overlay base 80128158. SHA256(span)=b7a72efe056d4af29e1cca80aebf1960b6c61a11de3718ebff83fb9246ad44f3.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/801733a4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801733A4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80174684(void *);
extern void func_8017331C();

void func_801733A4(void) {
    func_80174684(func_8017331C);
}
