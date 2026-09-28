/* SC02.CD FILE_031 / ov_SC02_031 retail span [80152BA8,80152BF0).
 * Offset 0x2AA50 at overlay base 80128158. SHA256(span)=c74d64726d0cfb89c385a8565566e9e6a962484b3714c76ce0b286cdc78a18c4.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80152ba8.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80152BA8 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern void func_80152BF0(s32 a0);
extern void func_80146CA0(void *a0);

void func_80152BA8(s32 a0) {
    func_8014E934(a0);
    func_8014CC28(a0);
    func_8014F3E8(a0);
    func_80152BF0(a0);
    func_80146CA0((void *)a0);
}
