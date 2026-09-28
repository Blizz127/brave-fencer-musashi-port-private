/* SC02.CD FILE_031 / ov_SC02_031 retail span [80171CC4,80171D1C).
 * Offset 0x49B6C at overlay base 80128158. SHA256(span)=77406bf035774a6a3aac772b047585e40e0c431fed121ceb65adf236d596a73c.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80171cc4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80171CC4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32 func_80171D78(s32 a0, s32 a1);
extern int func_8017250C(short *a0, short *a1);
extern void func_80146D90(s32 a0);

s32 func_80171CC4(void * a0, void * a1)
{
    s32 ret;
    ret = func_80171D78(a0, a1);
    if (func_8017250C(a0, a1) != 0) {
        func_80146D90((s32)a0);
    }
    return ret;
}
