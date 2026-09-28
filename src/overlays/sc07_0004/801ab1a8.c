/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AB1A8 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern void func_8012AD50(void *a0);
extern u8 D_801F7490[];

void func_801AB1A8(void *a0) {
    s32 v0;

    v0 = func_8012C1B8();
    *(s32 *)((s32)a0 + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4(a0);
        return;
    }
    func_8001C214(v0, (s32)&D_801F7490);
    *(u16 *)((s32)a0 + 0xE) = 0;
    *(u16 *)((s32)a0 + 0xA) = 0;
    *(u16 *)((s32)a0 + 6) = 0;
    *(s32 *)(*(s32 *)((s32)a0 + 0x20) + 0x28) = 0x1000100;
    func_8012AD50(a0);
}
