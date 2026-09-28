/* SC02.CD FILE_031 / ov_SC02_031 retail span [8017427C,801742A4).
 * Offset 0x4C124 at overlay base 80128158. SHA256(span)=e831bd081fd0cb48b08642a7a8d839c3f5d0195666f24edf74ad6b02f44dec13.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8017427c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017427C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80174684(void *);
extern s32 func_801742A4();

void func_8017427C(void) {
    func_80174684((void *)func_801742A4);
}
