/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172710,80172738).
 * Offset 0x4A5B8 at overlay base 80128158. SHA256(span)=c2de4fa3fc3fbdde62e280613b12b6edb620783dd2d744d0a2d91f1dddeb1ae4.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172710.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172710 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void (*D_80127088)(void);

void func_80172710(void) {
    D_80127088();
}
