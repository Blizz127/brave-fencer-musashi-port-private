/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A5194 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80133060(u8 *a0, s32 *a1, s32 a2);
typedef struct {
    s32 w[8];
} Blk32_801A5194;

void func_801A5194(s32 arg0) {
    s32 sp10[3];

    sp10[0] = *(s32 *)(*(s32 *)(*(s32 *)(arg0 + 0x64) + 0x20) + 0x48) << 16;
    sp10[1] = *(s32 *)(*(s32 *)(*(s32 *)(arg0 + 0x64) + 0x20) + 0x4C) << 16;
    sp10[2] = *(s32 *)(*(s32 *)(*(s32 *)(arg0 + 0x64) + 0x20) + 0x50) << 16;
    func_80133060((u8 *)sp10, (s32 *)(arg0 + 4), -0x60);

    *(Blk32_801A5194 *)(*(s32 *)(arg0 + 0x20) + 0x34) =
        *(Blk32_801A5194 *)(*(s32 *)(*(s32 *)(arg0 + 0x64) + 0x20) + 0x34);
    *(Blk32_801A5194 *)(*(s32 *)(arg0 + 0x20) + 0x54) =
        *(Blk32_801A5194 *)(*(s32 *)(*(s32 *)(arg0 + 0x64) + 0x20) + 0x54);

    *(s32 *)(*(s32 *)(arg0 + 0x20) + 0x48) = *(s16 *)(arg0 + 0x6);
    *(s32 *)(*(s32 *)(arg0 + 0x20) + 0x4C) = *(s16 *)(arg0 + 0xA);
    *(s32 *)(*(s32 *)(arg0 + 0x20) + 0x50) = *(s16 *)(arg0 + 0xE);
    *(s32 *)(*(s32 *)(arg0 + 0x20) + 0x68) = *(s16 *)(arg0 + 0x6);
    *(s32 *)(*(s32 *)(arg0 + 0x20) + 0x6C) = *(s16 *)(arg0 + 0xA);
    *(s32 *)(*(s32 *)(arg0 + 0x20) + 0x70) = *(s16 *)(arg0 + 0xE);

    *(s16 *)(*(s32 *)(arg0 + 0x20) + 0x18) =
        (*(s16 *)(*(s32 *)(*(s32 *)(arg0 + 0x64) + 0x20) + 0x18) * 7) >> 3;
    *(s16 *)(*(s32 *)(arg0 + 0x20) + 0x1A) =
        (*(s16 *)(*(s32 *)(*(s32 *)(arg0 + 0x64) + 0x20) + 0x1A) * 7) >> 3;
    *(s16 *)(*(s32 *)(arg0 + 0x20) + 0x1C) =
        (*(s16 *)(*(s32 *)(*(s32 *)(arg0 + 0x64) + 0x20) + 0x1C) * 7) >> 3;

    *(s16 *)(*(s32 *)(arg0 + 0x20) + 0x2C) =
        *(u16 *)(*(s32 *)(arg0 + 0x20) + 0x2C) | 1;
}
