/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AC47C - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern void func_8001C1E4(void *a0, s32 a1);
extern void func_801A9B40(void*, u16, u16);
extern void func_8012AD50(void *a0);
extern u8 D_801F0688;
extern u8 D_801F8A58;

void func_801AC47C(void *a0) {
    s32 v0;

    v0 = func_8012C1B8();
    *(s32 *)((s32)a0 + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4(a0);
        return;
    }
    func_8001C214(v0, (s32)&D_801F0688);
    *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x2C) |= 0x10;
    *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x18) = *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x1C) = 0x3000;
    *(u16 *)(*(s32 *)((s32)a0 + 0x20) + 0x1A) = 0x4000;
    *(s16 *)((s32)a0 + 0xA) = -0x40;
    *(s16 *)((s32)a0 + 0x6) = 0;
    *(s16 *)((s32)a0 + 0xE) = 0x28;
    func_8001C1E4(*(void **)((s32)a0 + 0x20),
                  *(s32 *)(*(s32 *)((s32)a0 + 0x64) + 0x20));
    ((void (*)(void *, s32, s32))func_801A9B40)(&D_801F8A58, 0x160, 0x157);
    *(s32 *)((s32)a0 + 0x1C) = 8;
    func_8012AD50(a0);
}
