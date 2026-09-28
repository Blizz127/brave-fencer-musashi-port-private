/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AC940 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { char c[4]; } Blk4_801A7358;
extern Blk4_801A7358 D_801F88B8;

void func_801AC940(s32 arg0)
{
    extern void func_801292C8(u8 *a0);
    extern void func_8012931C(struct vec *a0);

    s32 a1 = arg0;
    s32 v0;
    s16 v1;

    v0 = *(s32 *)(a1 + 0x1C);
    if (v0 == 0) {
        func_801292C8((u8 *)a1);
        return;
    }
    v0 = v0 - 1;
    *(s32 *)(a1 + 0x1C) = v0;
    if ((v0 & 3) == 0 && *(s16 *)(a1 + 0x2C) < 3) {
        v1 = *(s16 *)(a1 + 0x2C);
        v1 = v1 + 1;
        *(s16 *)(a1 + 0x2C) = v1;
        *(s32 *)(*(s32 *)(a1 + 0x20) + 0x20) = (s32)&D_801F88B8 + (v1 << 6);
    }
    func_8012931C((struct vec *)a1);
}
