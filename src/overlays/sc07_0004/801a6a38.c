/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A6A38 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern void func_8001C2C4(s32 a0);
extern void func_8012AD50(void *a0);
extern u8 D_801AFF14[];
extern u8 D_801AFF24[];

void func_801A6A38(void *a0) {
    s32 v0;

    v0 = func_8012C1B8();
    *(s32 *)((s32)a0 + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4(a0);
        return;
    }
    func_8001C2C4(v0);

    *(s32 *)((s32)a0 + 0x58) = (s32)D_801AFF14 | 0x40000000;
    *(u16 *)((s32)a0 + 0x5C) = 0x8800;
    *(u8 *)((s32)a0 + 0xC0) = 1;
    *(s32 *)((s32)a0 + 0xB4) = 0;
    *(u16 *)((s32)a0 + 0xAE) = 0;
    *(s32 *)((s32)a0 + 0xBC) = (s32)D_801AFF24;
    *(u8 *)((s32)a0 + 0xC1) = 0;
    *(s32 *)((s32)a0 + 0xC4) |= 2;
    func_8012AD50(a0);
}
