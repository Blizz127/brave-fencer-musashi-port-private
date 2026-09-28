/* SC02.CD FILE_031 / ov_SC02_031 retail span [80152D60,80152DA8).
 * Offset 0x2AC08 at overlay base 80128158. SHA256(span)=37edf317af46d54d020757d1d1228000da68f223059cc9914b8228bbd0e6938f.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80152d60.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80152D60 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8014E934(s32 a0);
extern void func_8014CC28(s32 a0);
extern s32 func_8014F3E8(s32 a0);
extern void func_80152DA8(s32 a0);
extern void func_80146CA0(void *a0);

void func_80152D60(s32 a0) {
    func_8014E934(a0);
    func_8014CC28(a0);
    func_8014F3E8(a0);
    func_80152DA8(a0);
    func_80146CA0((void *)a0);
}
