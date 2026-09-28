/* SC02.CD FILE_031 / ov_SC02_031 retail span [80174604,80174630).
 * Offset 0x4C4AC at overlay base 80128158. SHA256(span)=c0c5adde0535f2bc84be47f5c5bd437dbff07e51bba3ad2ec04bbd081848886f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80174604.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80174604 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 D_801150F8;
extern void func_80174630(void);

void func_80174604(void) {
    D_801150F8 = 1;
    func_80174630();
}
