/* SC02.CD FILE_031 / ov_SC02_031 retail span [80160F00,80160F70).
 * Offset 0x38DA8 at overlay base 80128158. SHA256(span)=032510f8282057f1af7c90823267c75fed5b319442df41b7cfa92925feb6a5b4.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80160f00.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80160F00 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80149020(s32 *a0);
extern void func_80154150(s32 a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80129248(s16 a0);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern u16 D_801270C0;
extern u8 D_800B9A17;

void func_80160F00(void* arg0) {
    ((void (*)(void*))func_80149020)(arg0);
    ((void (*)(void*, s32))func_80154150)(arg0, 4);
    ((void (*)(void*, s32))func_80154A74)(arg0, 0x11);
    D_801270C0 = 2;
    ((void (*)(s32))func_80129248)(0);
    D_800B9A17 = 0;
    ((void (*)(void*, s32))func_80146E90)(arg0, 0x10);
    func_80146CA0(arg0);
}
