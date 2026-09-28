/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A5B5C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80132784(s32 a0, s32 a1, u32 a2);
extern u16 D_8019FF8A;
extern s32 D_801B6E94[0x11];

void func_801A5B5C(void *arg0)
{
    s32 *s1;
    s32 w;

    s1 = *(s32 **)((u8 *)arg0 + 0xCC);

    if (D_801B6E94[*(s16 *)((u8 *)arg0 + 0xFE)] == 0x1000000
        || *(s32 *)((u8 *)*(s32 *)(*(s32 *)((u8 *)arg0 + 0x64) + 0x20) + 4) < 0
        || (D_8019FF8A & 8) != 0)
    {
        *(s32 *)((u8 *)s1 + 4) |= 0x80000000;
        return;
    }

    func_80132784((s32)arg0, *(s32 *)((u8 *)arg0 + 0x64), (u16)*(s16 *)((u8 *)arg0 + 0xFE));
    *(s16 *)((u8 *)s1 + 8) = *(s32 *)((u8 *)*(s32 **)((u8 *)arg0 + 0x20) + 0x48);
    *(s16 *)((u8 *)s1 + 0xA) = *(s32 *)((u8 *)*(s32 **)((u8 *)arg0 + 0x20) + 0x4C);
    w = *(s32 *)((u8 *)s1 + 4);
    *(s16 *)((u8 *)s1 + 0xC) = *(s32 *)((u8 *)*(s32 **)((u8 *)arg0 + 0x20) + 0x50);
    *(s32 *)((u8 *)s1 + 4) = w & 0x7FFFFFFF;
}
