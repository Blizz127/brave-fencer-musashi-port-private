/* SC02.CD FILE_031 / ov_SC02_031 retail span [8012FF98,8013001C).
 * Offset 0x7E40 at overlay base 80128158. SHA256(span)=ee17c8110be49a1e0b26a7b3be5db54271f27642ca72b28cd78766c1fb71b361.
 * Re-carve of the registry-verified MAIN member 0012 source
 * src/overlays/main_0012/8012ff98.c (recovery=c, -O2); the span is
 * byte-identical between member 0012 and SC02_031.
 * Not MAIN10.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012FF98 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern s32 func_8012BEE8(s32 a0);
extern void func_80130D48(s32 a0);
extern void func_801319E0(s32 a0);
extern void func_80131CA8(int a0, int a1);

void func_8012FF98(u8 *a0) {
    if (*(s32 *)(a0 + 0xB4) & 0x20) {
        s32 p = *(s32 *)(a0 + 0x20);
        if (p != 0) {
            *(u32 *)(p + 4) ^= 0x80000000;
        }
        if (func_8012BEE8((s32)a0)) {
            func_80130D48((s32)a0);
            func_801319E0((s32)a0);
        }
    }
    func_80131CA8((int)a0, 0x10);
}
