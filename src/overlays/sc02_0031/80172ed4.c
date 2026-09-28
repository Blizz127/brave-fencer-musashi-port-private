/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172ED4,80172EFC).
 * Offset 0x4AD7C at overlay base 80128158. SHA256(span)=e3d11cc90b74ad01f2d52989185141931d81b7a3ee5d1bdd242c10d7e4da1eeb.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172ed4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172ED4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8017303C(void *);
extern u8 D_800D59EC[];

void func_80172ED4(void) {
    func_8017303C(D_800D59EC);
}
