/* SC02.CD FILE_031 / ov_SC02_031 retail span [80159B08,80159B3C).
 * Offset 0x319B0 at overlay base 80128158. SHA256(span)=350ed196530bdfc7e79b1a1c31434ae5532df058b6fb23008ad4705797577ef9.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80159b08.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80159B08 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern void func_80159BE4(s32);

void func_80159B08(s32 *a0) {
    func_80147078(a0, 0);
    func_80159BE4(a0);
}
