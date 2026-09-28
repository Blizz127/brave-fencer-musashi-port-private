/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AF1EC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801AF2EC(void *a0);
extern void func_801AF368(void *a0);
extern void func_8012931C(struct vec *a0);
extern void func_801292C8(u8 *a0);

void func_801AF1EC(void *a0) {
    if (*(u16 *)((s32)a0 + 0x2) == 0) {
        func_801AF2EC(a0);
        return;
    }

    if (*(s32 *)((s32)a0 + 0x1C) != 0) {
        *(s32 *)((s32)a0 + 0x1C) -= 1;
        func_8012931C((struct vec *)a0);

        if (*(s16 *)((s32)a0 + 0x32) == 0) {
            u16 t = *(u16 *)((s32)a0 + 0xA) + 0x1000;
            if (t >= 0x1001) {
                func_801292C8((u8 *)a0);
                return;
            }
        }
    } else {
        func_801292C8((u8 *)a0);
        return;
    }

    *(s32 *)((s32)a0 + 0x14) += *(s32 *)((s32)a0 + 0x34);
    *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x14) += *(u16 *)((s32)a0 + 0x30);
    *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x8) = *(u16 *)((s32)a0 + 0x6);
    *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0xA) = *(u16 *)((s32)a0 + 0xA);
    *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0xC) = *(u16 *)((s32)a0 + 0xE);
    func_801AF368((void *)*(s32 *)((s32)a0 + 0x20));
}
