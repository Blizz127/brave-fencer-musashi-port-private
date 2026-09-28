/* SC02.CD FILE_031 / ov_SC02_031 retail span [80162F60,80162F80).
 * Offset 0x3AE08 at overlay base 80128158. SHA256(span)=0533d3bb29c05a2b3bef68e76ca75401af6745f4488ad935f26bc206194b52cd.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80162f60.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80162F60 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147948(s32 a0, s32 a1, s32 a2);

void func_80162F60(s32 arg0, s32 arg1) {
    func_80147948(arg0, arg1, 0x7F0000);
}
