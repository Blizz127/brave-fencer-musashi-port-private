/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80129398 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s16 D_800B9AAC[];
extern s16 D_800B9AAE[];
extern s16 D_800B9AB0[];
extern s16 D_800B9AB2[];
extern s16 D_800B9AB4[];
extern s16 D_800B9AB6[];
extern s16 D_800B9AB8[];
extern s16 D_800B9ABA[];

void func_80129398(void)
{
    s32 i;
    s32 off;
    for (i = 0; i < 2; i++) {
        off = i * 0x54;
        *(s16 *)((char *)D_800B9AAC + off) = 0x7FFF;
        *(s16 *)((char *)D_800B9AAE + off) = 0;
        *(u16 *)((char *)D_800B9AB0 + off) = 0xFFFF;
        *(s16 *)((char *)D_800B9AB2 + off) = 0;
        *(s16 *)((char *)D_800B9AB4 + off) = 0x140;
        *(s16 *)((char *)D_800B9AB6 + off) = 0xEE;
        *(s16 *)((char *)D_800B9AB8 + off) = 0;
        *(s16 *)((char *)D_800B9ABA + off) = 0;
        off += 0x54;
    }
}
