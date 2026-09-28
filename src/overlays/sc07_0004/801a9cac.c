/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A9CAC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern u8 D_801B0770[];
extern u8 D_801EFC18[];
extern s32 func_8001D074(s32 a0, s32 a1);
extern void func_8001CB6C(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8001C214(s32 a0, s32 a1);
extern s32 func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_801A9EB0(void *a0);
extern void func_801A9F5C(void *a0);
extern void func_801A9FA8(void *a0);
extern void func_801AA2F8();
extern void func_801AA60C();

void func_801A9CAC(void *a0) {
    s32 pad[2];
    s32 p;
    s32 r;
    s32 q;

    switch (*(s16 *)((s32)a0 + 0x70)) {
    case 0:
    case 1:
        p = func_8001D074(0x7E, 0x100);
        if (p == 0) {
            func_8012CAE4(a0);
            break;
        }
        *(s32 *)((s32)a0 + 0x20) = p;
        func_8001CB6C(p, (s32)&D_801B0770, 0x280, 0x180);
        *(u8 *)(p + 0x27) = 0xFF;
        *(s16 *)(p + 0x10) = 0x400;
        *(s32 *)(p + 0x4) |= 0x51000000;
        *(s16 *)(p + 0x14) =
            -*(u16 *)(*(s32 *)(*(s32 *)((s32)a0 + 0x64) + 0x20) + 0x12);
        if (*(s16 *)((s32)a0 + 0x70) == 0) {
            *(s16 *)((s32)a0 + 0xFE) = -0x20;
            *(s16 *)(p + 0x14) = *(u16 *)(p + 0x14) + 0x180;
        } else {
            *(s16 *)((s32)a0 + 0xFE) = 0x20;
            *(s16 *)(p + 0x14) = *(u16 *)(p + 0x14) - 0x180;
        }
        *(s16 *)((s32)a0 + 0xA) = *(u16 *)((s32)a0 + 0xA) - 0x40;
        func_801A9EB0(a0);
        func_801AA60C(a0, 0xAB6);
        break;
    case 2:
        func_801AA2F8();
        /* fallthrough */
    case 3:
        q = func_8012C1B8();
        *(s32 *)((s32)a0 + 0x20) = q;
        if (q == 0) {
            func_8012CAE4(a0);
            break;
        }
        func_8001C214(q, (s32)&D_801EFC18);
        r = *(s32 *)((s32)a0 + 0x20);
        *(s16 *)(r + 0x2C) = *(u16 *)(r + 0x2C) | 0x10;
        *(s16 *)((s32)a0 + 0xA) = -0x200;
        *(s16 *)(*(s32 *)((s32)a0 + 0x20) + 0x12) =
            *(u16 *)(*(s32 *)(*(s32 *)((s32)a0 + 0x64) + 0x20) + 0x12);
        if (*(s16 *)((s32)a0 + 0x70) == 2) {
            r = *(s32 *)((s32)a0 + 0x20);
            *(s16 *)(r + 0x1C) = 0x400;
            *(s16 *)(r + 0x18) = 0x400;
            r = *(s32 *)((s32)a0 + 0x20);
            *(s16 *)(r + 0x1A) = 0x600;
            func_801A9F5C(a0);
            func_801AA60C(a0, 0xAB5);
        } else {
            q = *(u16 *)(*(s32 *)(*(s32 *)((s32)a0 + 0x64) + 0x20) + 0x18);
            r = *(s32 *)((s32)a0 + 0x20);
            *(s16 *)(r + 0x1C) = q;
            *(s16 *)(r + 0x1A) = q;
            *(s16 *)(r + 0x18) = q;
            func_801A9FA8(a0);
        }
        break;
    }
}
