/* SC02.CD FILE_031 / ov_SC02_031 retail span [80172414,8017248C).
 * Offset 0x4A2BC at overlay base 80128158. SHA256(span)=7a63f14ef2f038606fde49dfe25c962bf94cf77c527f2b8860d56a36687eae30.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/80172414.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80172414 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_80161C24(s32, s32);
extern void func_8014C010(s32 a0, s32 a1);
extern u16 D_800B99DA;

void func_80172414(s32 a0) {
    if (*(u16 *)(a0 + 0xB8) & 0x2000) {
        func_80161C24(a0, *(u16 *)(a0 + 0x16E));
    }
    if (*(s32 *)(a0 + 0x2C) < (s32)0xFFF90000) {
        if ((D_800B99DA & 7) == 0) {
            func_8014C010(a0, 2);
        }
    }
}
