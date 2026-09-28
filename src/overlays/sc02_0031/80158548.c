/* SC02.CD FILE_031 / ov_SC02_031 retail span [80158548,801585A4).
 * Offset 0x303F0 at overlay base 80128158. SHA256(span)=9d133c7ee5234df3ca29f56be1643562d818dc5bff8ad85ffc1906c7ab54f4bc.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80158548.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80158548 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern s32 func_80161208();

void func_80158548(s32 param_1) {
    *(u32 *)(param_1 + 0x44) = *(u32 *)(param_1 + 0x44) | 2;
    if (*(u16 *)(param_1 + 0xb8) & 0x8000) {
        ((void (*)(void))func_801599A4)();
        ((void (*)(s32))func_80159B3C)(param_1);
    } else {
        ((void (*)(s32))func_80161208)(param_1);
    }
}
