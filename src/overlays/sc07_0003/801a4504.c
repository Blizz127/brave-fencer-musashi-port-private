/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A4504 - byte-exact against retail at -O2 (tools/register_match.py). */
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

void func_801A4504(void *arg0) {
    s32 v0 = func_8012C1B8();
    *(s32 *)((u8 *)arg0 + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4(arg0);
        return;
    }
    func_8001C214(v0, 0);
    *(u16 *)(*(s32 *)((u8 *)arg0 + 0x20) + 0x2C) |= 0x10;
    {
        s32 t = *(s32 *)((u8 *)arg0 + 0x20);
        *(s16 *)(t + 0x1A) = 1;
        *(s16 *)(t + 0x18) = 1;
    }
    {
        u16 x = *(u16 *)(*(s32 *)((u8 *)arg0 + 0x64) + 0x36);
        *(s16 *)((u8 *)arg0 + 0x2) = *(u16 *)((u8 *)arg0 + 0x2) + 1;
        *(s16 *)((u8 *)arg0 + 0x10A) = x;
    }
}
