/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A1E30 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012ADE4(u8 *a0);
extern void func_8012CBA4(s32 a0);
extern s32 func_8012E544(s32 a0);
extern s32 func_8017F2D8(void);
extern void func_801A24E8(s32 a0);

void func_801A1E30(s32 a0) {
    s32 v1;

    if (*(u32 *)(a0 + 0xE0) & 0x10) {
        if (func_8012E544(0x352) == 0) {
            func_8017F2D8();
            *(u32 *)(a0 + 0xE0) &= ~0x10;
        }
    }

    if (*(u16 *)(a0 + 0x34) != 0) {
        v1 = *(s32 *)(a0 + 0x94);
        if ((u32)v1 < 0x33) {
            if (v1 == 0x18) {
                func_8002D4C8(0xC34, 0);
            }
            if ((((s32 (*)(s32))func_8012CBA4)(a0) & 0x2000) == 0) {
                func_8012ADE4((u8 *)a0);
            }
            func_801A24E8(a0);
        }
    }

    if (*(s16 *)(a0 + 0x98) == 0) {
        if (*(u32 *)(a0 + 0xE0) & 0x20) {
            *(u32 *)(a0 + 0xE8) = 0;
            *(u32 *)(a0 + 0xEC) = 0x10000;
            *(u32 *)(a0 + 0xE0) |= 0x100;
        }
        *(s16 *)(a0 + 2) = 5;
        *(u32 *)(a0 + 0xE0) &= ~0x21;
    }
}
