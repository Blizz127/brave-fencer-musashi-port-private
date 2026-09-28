/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A7B08 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8004787C(s32 a0);
extern void func_801A8440(s32 a0);
extern u8 D_801F88BA;

void func_801A7B08(s32 arg0) {
    register s32 s0 __asm__("$16");
    u8 *p;
    s0 = arg0;
    func_801A8440(s0);

    switch (*(s16 *)((s32)s0 + 0x2C)) {
    case 0: {
        s16 t = *(s16 *)(*(s32 *)((s32)s0 + 0x20) + 0x18);
        if (t >= 0x401) {
            *(s16 *)(*(s32 *)((s32)s0 + 0x20) + 0x18) = t - 0xA0;
            *(u16 *)(*(s32 *)((s32)s0 + 0x20) + 0x1A) = *(u16 *)(*(s32 *)((s32)s0 + 0x20) + 0x18);
        }
        p = &D_801F88BA;
        if (*p < 0xF0) {
            *p += 0xC;
        }
        if ((*(s16 *)(*(s32 *)((s32)s0 + 0x20) + 0x18) < 0x401) &&
            (*p >= 0xF0)) {
            *(u16 *)((s32)s0 + 0x2A) = 0;
            *(u16 *)((s32)s0 + 0x2C) += 1;
        }
        break;
    }

    case 1:
        *(u16 *)((s32)s0 + 0x2A) += 0x40;
        *(s16 *)(*(s32 *)((s32)s0 + 0x20) + 0x18) =
            (func_8004787C(*(s16 *)((s32)s0 + 0x2A)) >> 5) + 0x400;
        *(s16 *)(*(s32 *)((s32)s0 + 0x20) + 0x1A) =
            (func_8004787C(*(s16 *)((s32)s0 + 0x2A) + 0x800) >> 5) + 0x400;
        break;
    }
}
