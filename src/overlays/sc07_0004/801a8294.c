/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A8294 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801A8494(void *a0);
extern void func_801292C8(u8 *a0);
extern u8 D_801F89F8[4];

void func_801A8294(void *a0) {
    register u8 *base __asm__("$17");
    s32 sub;
    s16 val;

    func_801A8494(a0);
    base = D_801F89F8;

    sub = *(s32 *)((s32)a0 + 0x20);
    val = *(s16 *)(sub + 0x18);

    if (val < 0x3000) {
        if (*(s32 *)((s32)a0 + 0x1C) != 0) {
            *(s32 *)((s32)a0 + 0x1C) -= 1;
        } else {
            *(s16 *)(sub + 0x1A) = 0x6000;
            *(s16 *)(sub + 0x18) = 0x6000;
            *(s32 *)((s32)a0 + 0x1C) = 0x30;
        }
        return;
    }

    if (val > 0x3000) {
        *(s16 *)(*(s32 *)((s32)a0 + 0x20) + 0x18) = val - 0x100;
        *(s16 *)(*(s32 *)((s32)a0 + 0x20) + 0x1A) = *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x18);
        return;
    }

    if (*(s32 *)((s32)a0 + 0x1C) != 0) {
        u8 b0 = *base;

        if (b0 == 0xC0) {
            *base = b0 - 0x10;
            D_801F89F8[1] -= 0x10;
            D_801F89F8[2] -= 0x10;
        } else {
            *base = b0 + 0x10;
            D_801F89F8[1] += 0x10;
            D_801F89F8[2] += 0x10;
        }
        *(s32 *)((s32)a0 + 0x1C) -= 1;
        return;
    }

    *base -= 0x10;
    D_801F89F8[1] -= 0x10;
    D_801F89F8[2] -= 0x10;
    if (*base == 0) {
        func_801292C8((u8 *)a0);
    }
}
