/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AC8B8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { char c[4]; } Blk4_801A7358;
extern void func_8001CD9C(s32, s32);
extern int func_8005C49C(void);
extern Blk4_801A7358 D_801F88B8;

void func_801AC8B8(s32 param_1)
{
    s32 t;
    s32 ptr;

    *(u16 *)(param_1 + 0x2C) = 0;
    func_8001CD9C(*(s32 *)(param_1 + 0x20), (s32)&D_801F88B8);
    *(u32 *)(*(s32 *)(param_1 + 0x20) + 4) |= 0x50000000;
    *(u16 *)(*(s32 *)(param_1 + 0x20) + 0x2C) = 0xC020;
    t = (func_8005C49C() & 0x1F0) + 0x500;
    ptr = *(s32 *)(param_1 + 0x20);
    *(u16 *)(ptr + 0x1A) = t;
    *(u16 *)(ptr + 0x18) = t;
    *(s32 *)(param_1 + 0x1C) = 0x14;
    *(u16 *)(param_1 + 2) = *(u16 *)(param_1 + 2) + 1;
}
