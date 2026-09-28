/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CDA80 - byte-exact against retail at -O2 (tools/register_match.py). */
#define rand func_8005C49C
extern void func_80146E90(s32*, s32);
extern void func_80146E90(s32 *a0, s32 a1);
extern s32 func_80146C3C(void *a0);
extern void *func_800D2294(s32 a0, s32 a1);
extern void func_800233CC(void *a0, u16 a1);
extern s32 rand(void);

void func_800CDA80(int param_1)
{
    extern unsigned char D_800CEBF4[];
    void *ptr;
    s32 base;
    s32 r;

    base = (int)D_800CEBF4 + *(s32 *)(param_1 + 0x2c) * 0x40;
    ptr = func_800D2294(param_1, base);
    *(s32 *)(param_1 + 0x20) = ptr;
    if (ptr != 0) {
        r = rand();
        func_800233CC(base, (r & 0x1F) | 0x20);
        *(u32 *)((int)ptr + 4) |= 0x50000000;
        *(s32 *)base = ((r & 0x3F) + 0x40) << 16;
        *(s32 *)(base + 4) = 0;
        func_80146E90((s32 *)param_1, 4);
        *(u16 *)(param_1 + 2) += 1;
    } else {
        func_80146C3C(param_1);
    }
}
