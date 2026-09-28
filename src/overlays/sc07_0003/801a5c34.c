/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A5C34 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern void func_8001C810(s32 a0, s32 a1);
extern void func_801A5098(s32 a0);
extern s32 D_801F28F8;
extern s32 D_801F30A8;

void func_801A5C34(s32 param_1)
{
    s32 v0;

    v0 = func_8012C1B8();
    *(s32 *)(param_1 + 0x20) = v0;
    if (v0 == 0) {
        func_8012CAE4((void *)param_1);
        return;
    }

    func_8001C810(v0, (s32)&D_801F28F8);

    v0 = func_8012C1B8();
    *(s32 *)(param_1 + 0xCC) = v0;
    if (v0 == 0) {
        func_8012CAE4((void *)param_1);
        v0 = *(s32 *)(param_1 + 0x20);
        *(s16 *)v0 = 0;
        return;
    }

    func_8001C810(v0, (s32)&D_801F30A8);

    *(u8 *)(param_1 + 0xC0) = 0;
    *(u32 *)(*(s32 *)(param_1 + 0x20) + 4) |= 0x50000000;
    *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x2C) |= 0x90;
    *(s32 *)(*(s32 *)(param_1 + 0x20) + 0x80) = param_1 + 0xFC;

    *(u32 *)(*(s32 *)(param_1 + 0xCC) + 4) |= 0x50000000;
    *(u16 *)(*(s32 *)(param_1 + 0xCC) + 0x2C) |= 0x90;
    *(s32 *)(*(s32 *)(param_1 + 0xCC) + 0x80) = param_1 + 0xFC;

    *(s16 *)(param_1 + 0xFC) = 0x100;
    *(s16 *)(param_1 + 0xFE) = 0x100;
    *(s16 *)(param_1 + 0x100) = 0x100;
    *(s16 *)(param_1 + 0x102) = -2;

    func_801A5098(param_1);
}
