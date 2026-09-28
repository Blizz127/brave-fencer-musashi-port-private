/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A88AC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80047E6C();
extern void func_8012AD44(s32 *a0, s16 a1);

void func_801A88AC(void *arg0)
{
    s32 sp10[3];

    sp10[0] = *(s16 *)(*(s32 *)((u8 *)arg0 + 0x64) + 0x6) - *(s16 *)((u8 *)arg0 + 0x6);
    sp10[1] = *(s16 *)(*(s32 *)((u8 *)arg0 + 0x64) + 0xA) - *(s16 *)((u8 *)arg0 + 0xA);
    sp10[2] = *(s16 *)(*(s32 *)((u8 *)arg0 + 0x64) + 0xE) - *(s16 *)((u8 *)arg0 + 0xE);
    func_80047E6C(sp10, sp10);

    *(s32 *)((u8 *)arg0 + 0x10) = sp10[0] << 9;
    *(s32 *)((u8 *)arg0 + 0x14) = sp10[1] << 9;
    *(s32 *)((u8 *)arg0 + 0x18) = sp10[2] << 9;
    *(s32 *)((u8 *)arg0 + 0x1C) = 0x20;

    func_8012AD44((s32 *)arg0, 3);
}
