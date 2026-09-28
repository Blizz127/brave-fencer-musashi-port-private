/* SC02.CD FILE_031 / ov_SC02_031 retail span [8016E6E4,8016E728).
 * Offset 0x4658C at overlay base 80128158. SHA256(span)=2c5846ee073578744a808840174955dcf1a9edcc6a1cc9e34940b2748f6bf39a.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8016e6e4.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8016E6E4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8016E778();
extern void func_8012A568(void (*a0)(void));

void func_8016E6E4(s32 a0) {
    s32 v0 = *(s32 *)(a0 + 0x1C) - 1;
    *(s32 *)(a0 + 0x1C) = v0;
    if (v0 == -1) {
        *(u16 *)(a0 + 2) = *(u16 *)(a0 + 2) + 1;
    }
    func_8016E778();
}
