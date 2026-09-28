/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016F0AC,8016F0E4).
 * Offset 0x46F54 at overlay base 80128158. SHA256(span)=2c12f843297429801b2ec555a310c0ce20e77981db25bd11e2e6813665a04180.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016f0ac.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016F0AC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8016F0E4(void);
extern void func_80165770(void);

void func_8016F0AC(void) {
    extern u8 aD80126B58 __asm__("D_80126B58");
    ((void (*)(void *))func_8016F0E4)(&aD80126B58);
    ((void (*)(void *))func_80165770)(&aD80126B58);
}
