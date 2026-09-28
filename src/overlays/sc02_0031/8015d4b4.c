/* SC02.CD FILE_031 / ov_SC02_031 retail span [8015D4B4,8015D4E8).
 * Offset 0x3535C at overlay base 80128158. SHA256(span)=25efd2f7970b449de6776af1028f8ae421160569c005300686358fefea938ef7.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8015d4b4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8015D4B4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147078(s32 *a0, s16 a1);
extern s32 func_8015D4E8();

void func_8015D4B4(s16 *a0) {
    func_80147078((s32 *)a0, 0xD);
    func_8015D4E8(a0);
}
