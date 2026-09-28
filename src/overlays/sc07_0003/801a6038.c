/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A6038 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C214(s32 a0, s32 a1);
extern u8 D_801F3208[];
extern u8 D_801A7404[];
extern u16 D_80126B62;
extern u16 D_80126BE2;
extern u16 D_80126B5E;
extern u16 D_80126BE0;
extern u16 D_80126B66;
extern u16 D_80126BE4;

void func_801A6038(void *a0) {
    register s32 s0 __asm__("$16") = (s32)a0;
    register s32 v0 __asm__("$2");

    v0 = func_8012C1B8();
    *(s32 *)(s0 + 0x20) = v0;

    if (v0 == 0) {
        func_8012CAE4((void *)s0);
        return;
    }

    func_8001C214(v0, (s32)D_801F3208);

    *(s32 *)(s0 + 0x58) = (s32)D_801A7404 | 0x40000000;
    *(u16 *)(s0 + 0x5C) = 0xC00;
    *(u16 *)(s0 + 0x6) = 0;

    *(s16 *)&D_80126B62 = -0x120;
    *(s16 *)&D_80126BE2 = -0x120;
    *(s16 *)&D_80126B5E = 0;
    *(s16 *)&D_80126BE0 = 0;
    *(s16 *)(s0 + 0xE) = -0x462;
    *(s16 *)&D_80126B66 = -0x462;
    *(s16 *)&D_80126BE4 = -0x462;
    *(s16 *)(s0 + 0xA) = -0x100;
    *(s32 *)(s0 + 0x14) = 0xFFFA0000;
    *(u8 *)(s0 + 0x75) = 2;
    *(u16 *)(s0 + 0x2) = *(u16 *)(s0 + 0x2) + 1;
}
