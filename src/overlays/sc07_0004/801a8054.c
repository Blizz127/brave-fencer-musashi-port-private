/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A8054 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { char c[4]; } Blk4_801A7358;
extern Blk4_801A7358 D_801A01E8;
extern s32 D_801F89B8[];
extern u8 D_801B0388;
extern u8 D_801F89BC;

void func_801A8054(s32 a0)
{
    s32 v0;

    *(Blk4_801A7358 *)&D_801F89B8 = *(Blk4_801A7358 *)&D_801A01E8;
    *(Blk4_801A7358 *)&D_801F89BC = *(Blk4_801A7358 *)&D_801B0388;

    v0 = *(s32 *)(a0 + 0x20);
    *(s16 *)(v0 + 0x1A) = 0;
    *(s16 *)(v0 + 0x18) = 0;

    *(s32 *)(a0 + 0x1C) = 1;
    *(s16 *)(a0 + 2) = 9;
}
