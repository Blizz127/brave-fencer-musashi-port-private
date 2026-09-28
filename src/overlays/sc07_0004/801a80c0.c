/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A80C0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801A8494(void *a0);
extern void func_800234E4(void *a0, s32 a1, s32 a2);
extern void func_801292C8(u8 *a0);
extern s32 D_801F89B8[];
extern u8 D_801F89BC;
extern u8 D_801B0388;
extern u8 D_801B0389;
extern u8 D_801B038A;

void func_801A80C0(void *a0) {
    u16 v0;

    func_801A8494(a0);

    v0 = *(u16 *)((s32)a0 + 0x2A) + 8;
    *(u16 *)((s32)a0 + 0x2A) = v0;
    func_800234E4((void *)D_801F89B8, 0x80, v0);

    if (*(s16 *)(*(s32 *)((s32)a0 + 0x20) + 0x18) < 0x1E00) {
        if (*(s32 *)((s32)a0 + 0x1C) != 0) {
            *(s32 *)((s32)a0 + 0x1C) -= 1;
            if (*(s32 *)((s32)a0 + 0x1C) == 0) {
                s32 p = *(s32 *)((s32)a0 + 0x20);
                *(u16 *)(p + 0x1A) = 0x800;
                *(u16 *)(p + 0x18) = 0x800;
            }
        }

        *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x18) =
            *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x18) + 0x2C0;
        *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x1A) =
            *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x18);

        if (*(s16 *)(*(s32 *)((s32)a0 + 0x20) + 0x18) >= 0x1E00) {
            *(s32 *)((s32)a0 + 0x1C) = 0x30;
        }
    } else {
        if (*(s32 *)((s32)a0 + 0x1C) != 0) {
            *(s32 *)((s32)a0 + 0x1C) -= 1;
        } else {
            u8 *p = &D_801F89BC;
            D_801F89BC -= (D_801B0388 >> 4);
            p[1] -= (D_801B0389 >> 4);
            p[2] -= (D_801B038A >> 4);
            if (D_801F89BC == 0) {
                func_801292C8((u8 *)a0);
            }
        }
    }
}
