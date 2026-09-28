/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A7CDC - byte-exact against retail at -O2 (tools/register_match.py). */
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

s32 func_801A7CDC(void *a0)
{
    void *v1;
    s32 r;

    *(s32 *)((char *)a0 + 0x30) = *(s32 *)&D_801F88B8;
    v1 = *(void **)((char *)a0 + 0x20);
    *(s16 *)((char *)v1 + 0x1A) = 0x2000;
    *(s16 *)((char *)v1 + 0x18) = 0x2000;
    v1 = *(void **)((char *)a0 + 0x20);
    *(u16 *)((char *)v1 + 0x2C) = 0xC040;
    *(s32 *)((char *)a0 + 0x1C) = 1;
    __asm__("" : "=r"(r) : "0"(5));
    *(s16 *)((char *)a0 + 2) = (s16)r;
    return r;
}
