/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80175820 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct { u32 *f0; s32 pad[4]; } S_AE7BC_80175820_80175820;
typedef struct { s32 g0; s32 pad[2]; } S_AF634_80175820_80175820;

s32 func_80175820(void)
{
    extern s16 D_800B9A02;
    extern S_AE7BC_80175820_80175820 D_800AE7BC[];
    extern S_AF634_80175820_80175820 D_800AF634[];
    extern u8 D_8011F7A8;
    u8 *p = (u8 *)&D_8011F7A8;
    u16 *q;
    u32 *ptr;
    u32 old;
    u32 *p2;
    q = (u16 *)&(*(u16 *)&D_800B9A02);
    ptr = D_800AE7BC[*q].f0;
    old = ptr[2];
    ptr[2] = (old & 0xff000000) | (*(u32 *)(p + *q * 4 + 0x20) & 0xffffff);
    __asm__("" ::: "memory");
    p2 = *(u32 **)(p + *q * 4 + 0x18);
    *p2 = (*p2 & 0xff000000) | (old & 0xffffff);
    __asm__("" ::: "memory");
    {
        s32 acc = D_800AF634[*q].g0;
        s32 t = *(s32 *)(p + *q * 4 + 0x18) - 0x14;
        D_800AF634[*q].g0 = acc + ((*(s32 *)(p + *q * 4 + 0x20) - t) >> 2);
    }
}
