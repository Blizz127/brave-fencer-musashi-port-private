/* SC02.CD FILE_031 / ov_SC02_031 retail span [80151980,801519C8).
 * Offset 0x29828 at overlay base 80128158. SHA256(span)=ecd838b3c52c248e1c9047a93b45488d9919fd70866b5b82f336d8cebf616432.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80151980.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80151980 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern void func_801519C8(s32 a0);
extern void func_80146CA0(void *a0);

void func_80151980(s32 a0) {
    func_8014E934(a0);
    func_8014CC28(a0);
    func_8014F3E8(a0);
    func_801519C8(a0);
    func_80146CA0((void *)a0);
}
