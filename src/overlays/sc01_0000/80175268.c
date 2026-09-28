/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80175268 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef void (*VoidFn)(void);
extern u8 D_80078EC0;

s32 func_80175268(s32 param_1)
{

    extern VoidFn D_801822B0[];
    *(u32 *)(param_1 + 0x44) |= 2;
    (*(VoidFn *)((s32)D_801822B0 + ((D_80078EC0 - 1) << 2)))();
}
