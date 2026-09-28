/* SC02.CD FILE_031 / ov_SC02_031 retail span [80151E78,80151ECC).
 * Offset 0x29D20 at overlay base 80128158. SHA256(span)=8e25c49b8c2379243f96df8cb326e5b5d14f5b390b6aed6d99d2560f7a9ecab0.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80151e78.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80151E78 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80149020(s32 *a0);
extern void func_80146CA0(void *a0);
extern s32 func_80172630(u8 *a0);

void func_80151E78(s32 *a0) {
    u8 *p = (u8 *)a0 + 0xDE;
    u8 v;
    func_80149020(a0);
    v = *p;
    *p = v + 0xFF;
    if (v == 0) {
        *p = 0x10;
        func_80146CA0(a0);
    }
    func_80172630((u8 *)a0);
}
