/* SC02.CD FILE_031 / ov_SC02_031 retail span [80171D1C,80171D78).
 * Offset 0x49BC4 at overlay base 80128158. SHA256(span)=20faa829d969c9dc249ff3a01197e047f9f1e49bc752143da9f4fbe66c119ac3.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80171d1c.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80171D1C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_80171FFC(short *a0, short *a1, s32 a2);
extern int func_8017250C(short *a0, short *a1);
extern void func_80146D90(s32 a0);

s32 func_80171D1C(void * a0, void * a1, s32 a2)
{
    s32 ret;
    ret = func_80171FFC(a0, a1, a2 & 0xFF);
    if (func_8017250C(a0, a1) != 0) {
        func_80146D90((s32)a0);
    }
    return ret;
}
