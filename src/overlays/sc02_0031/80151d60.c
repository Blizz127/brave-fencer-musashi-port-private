/* SC02.CD FILE_031 / ov_SC02_031 retail span [80151D60,80151DB0).
 * Offset 0x29C08 at overlay base 80128158. SHA256(span)=d06665e2a0dc0ed8f78271a5b46ac30f2b18c6e6594308145088a80dd3840090.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80151d60.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80151D60 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern void func_80151DB0(s32 a0);
extern void func_80146CA0(void *a0);

void func_80151D60(void *a0) {
    func_8014E934((s32)a0);
    func_8014CC28((s32)a0);
    func_8014F3E8((s32)a0);
    func_80151DB0((s32)a0);
    *(s8 *)((u8 *)a0 + 0xDE) = 0x20;
    func_80146CA0(a0);
}
