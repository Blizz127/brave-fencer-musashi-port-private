/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017DF44 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801292C8(u8 *a0);

void func_8017DF44(void *a0) {

    extern u8 D_80190330[];
    s32 v0;
    s32 v1;
    s32 a1;
    s32 a2;
    u8 *v1ptr;

    v0 = *(s32 *)((s32)a0 + 0x1C);
    v1 = *(s32 *)((s32)a0 + 0x2C);
    a1 = v0 - 1;
     





    __asm__ __volatile__("" : "=r"(v1) : "0"(v1));
    v1 = v1 << 6;
    a2 = (s32)D_80190330 + v1;
    v1ptr = *(u8 **)((s32)a0 + 0x20);

    *(s32 *)((s32)a0 + 0x1C) = a1;

    if (!(a1 == -1)) {
        v0 = 0x10 - a1;
        *(u16 *)((s32)v1ptr + 0x1A) = v0 << 8;
        *(u16 *)((s32)v1ptr + 0x18) = v0 << 8;

        v1 = *(s32 *)((s32)a0 + 0x1C);
        v0 = (v1 << 8) - v1;
        if (v0 < 0) {
            v0 = v0 + 0xF;
        }
        v0 = (u32)v0 >> 4;

        *(u8 *)(a2 + 0x2) = v0;
        *(u8 *)(a2 + 0x1) = v0;
        *(u8 *)(a2 + 0x0) = v0;

        v0 = *(s32 *)((s32)a0 + 0x1C) << 2;
        *(u8 *)(a2 + 0x5) = v0;
        *(u8 *)(a2 + 0x4) = v0;

        *(u8 *)(a2 + 0x6) = *(s32 *)((s32)a0 + 0x1C) << 3;
    } else {
        func_801292C8((u8 *)a0);
    }
}
