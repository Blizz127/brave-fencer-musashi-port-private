/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016B3F4,8016B428).
 * Offset 0x4329C at overlay base 80128158. SHA256(span)=4f8e195d1be99591a00aba6cc3d7c85d73f1930fd097bf1b59eaa75338eb3b74.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016b3f4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016B3F4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8016B448(s32, s32);
extern s32 func_8016BA48(s32 a0);
extern void func_8012A568(void (*a0)(void));

void func_8016B3F4(s32 a0) {
    func_8016B448(a0, 1);
    func_8016BA48(a0);
}
