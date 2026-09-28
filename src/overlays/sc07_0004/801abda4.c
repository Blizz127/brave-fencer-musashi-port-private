/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801ABDA4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_8001D074(s32 a0, s32 a1);
extern s32 func_8012C1B8(void);
extern void func_8012CAE4(void *a0);
extern void func_8001C2C4(s32 a0);
extern s32 func_8001CC3C(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
extern s32 func_80143994(s32 a0, s32 a1);
extern void func_801A90D8();
extern void func_801A930C();
extern u8 D_801B0408[];
extern u8 D_801B0414[];

void func_801ABDA4(void *a0) {
    s32 s0;
    s32 q;
    s32 v1;
    u16 v2;

    s0 = func_8001D074(0x7E, 0x100);
    *(s32 *)((s32)a0 + 0xCC) = s0;
    q = func_8012C1B8();
    *(s32 *)((s32)a0 + 0x20) = q;
    if (q == 0 || s0 == 0) {
        func_8012CAE4(a0);
        return;
    }
    func_8001C2C4(q);

    func_8001CC3C(s0, (s32)D_801B0408, 0x340, 0x100);
    *(s8 *)(s0 + 0x27) = 0x59;
    *(s16 *)(s0 + 0x18) = 0x3000;
    *(s16 *)(s0 + 0x1A) = 0x3000;
    v2 = 0xC018;
    *(s16 *)(s0 + 0x2C) = v2;
    *(s32 *)(s0 + 0x4) |= 0x50000000;

    func_80128EA8(*(s32 *)((s32)a0 + 0xCC), (s32)a0 + 0xF0, (s32)D_801B0414);

    if (*(s16 *)((s32)a0 + 0x70) == 0) {
        v1 = func_80143994(a0, 1);
        *(s32 *)((s32)a0 + 0xD0) = v1;
        if (v1 != 0) {
            s0 = *(s32 *)(v1 + 0xCC);
            if (s0 != 0) {
                *(s16 *)(s0 + 0x2C) = v2;
            }
        }
        func_801A90D8((s32)a0);
    } else {
        s32 t1;
        t1 = *(u16 *)((s32)a0 + 0x6) + 0x20;
        *(u16 *)((s32)a0 + 0x6) = t1;
        *(u16 *)(s0 + 0x8) = t1;
        t1 = *(u16 *)((s32)a0 + 0xA);
        *(u16 *)(s0 + 0xA) = t1;
        t1 = *(u16 *)((s32)a0 + 0xE);
        *(u16 *)(s0 + 0xC) = t1;
        func_801A930C(a0);
    }
}
