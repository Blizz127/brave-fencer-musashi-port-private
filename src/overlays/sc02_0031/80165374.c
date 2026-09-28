/* SC02.CD FILE_031 / ov_SC02_031 retail span [80165374,801653B8).
 * Offset 0x3D21C at overlay base 80128158. SHA256(span)=853107f21cc40343e38b221ed67b12190d33a23b5cb1c988d10a0c36ab39a7ff.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80165374.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80165374 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801653F4(s32 a0);
extern void func_80147078(s32 *a0, s16 a1);
extern void func_80165580(s32 a0);

void func_80165374(s32 a0) {
    func_801653F4(a0);
    func_80147078((s32 *)a0, 0x17);
    *(u8 *)(a0 + 0x197) = 1;
    func_80165580(a0);
}
