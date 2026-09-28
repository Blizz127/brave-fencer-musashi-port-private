/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A8228 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { char c[4]; } Blk4_801A7358;

void func_801A8228(s32 a0)
{
    typedef struct { char c[4]; } Blk4;

    extern s32 D_801A0210;
    extern s32 D_801F89FC;
    extern u8 D_801F89F8[];
    extern Blk4_801A7358 D_801A01E8;

    s32 v0;

    *(Blk4 *)&D_801F89F8 = *(Blk4 *)&D_801A0210;
    *(Blk4 *)&D_801F89FC = *(Blk4 *)&(*(struct {char c [ 4 ] ;} *)&D_801A01E8);

    v0 = *(s32 *)(a0 + 0x20);
    *(s16 *)(v0 + 0x1A) = 0;
    *(s16 *)(v0 + 0x18) = 0;
    *(s32 *)(a0 + 0x1C) = 1;
    *(s16 *)(a0 + 2) = 0xA;
}
