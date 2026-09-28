/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012CFA8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);

void func_8012CFA8(s32 arg0)
{
    extern s32 func_80058C6C(s32, void *);
    extern s32 func_8004955C(s32, s32 *, s32 *, s32 *);
    extern void func_80058D70(void *);
    extern void *func_80010A08(s32);
    extern void func_8004914C(void *a0);
    extern void func_800491AC(void *a0);
    extern s32 D_800A651C;
    extern u8 D_800AF648;
    extern short D_800B9A02;
    s32 sp10;
    s32 sp14;
    s32 sp18;
    s32 temp_a2;
    void *temp_v0;
    temp_v0 = func_80010A08(0x14);
    (*(s32 *)((s8 *)(temp_v0) + (4))) = 0xFF;
    func_80058D70(temp_v0);
    func_8004914C(&D_800AF648);
    func_800491AC(&D_800AF648);
    temp_a2 = (func_8004955C(arg0, &sp10, &sp14, &sp18) >> 2) - 0x20;
    if (temp_a2 > 0) {
        *(s32 *)((s8 *)temp_v0 + 8) = sp10;
        *(s16 *)((s8 *)temp_v0 + 0xC) = *(u16 *)((s8 *)temp_v0 + 8) + 8;
        *(s16 *)((s8 *)temp_v0 + 0xE) = *(u16 *)((s8 *)temp_v0 + 0xA);
        *(s16 *)((s8 *)temp_v0 + 0x10) = *(u16 *)((s8 *)temp_v0 + 8);
        *(s16 *)((s8 *)temp_v0 + 0x12) = *(u16 *)((s8 *)temp_v0 + 0xA) + 8;
        func_80058C6C(*(s32 *)((s8 *)&D_800A651C + ((u16)D_800B9A02 * 0x14)) + (temp_a2 * 4), temp_v0);
    }
}
