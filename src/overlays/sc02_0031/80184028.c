/* Complete SC02 retail span [80184028,8018418C).
 * Live STOP 84238 cluster; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80184028 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern s32  func_8005C49C(void);
extern u8 D_801893FC[];
extern void func_8001CB6C(u8 *a0, s32 a1, s32 a2, s32 a3);

void func_80184028(arg0)
s32 arg0;
{
    s32 q;

    func_8001CB6C(*(u8 **)(arg0 + 0x20), D_801893FC, 0x254, 0x1C0);
    *(u8 *)(*(u32 *)(arg0 + 0x20) + 0x27) = 0x25;
    *(u16 *)(*(u32 *)(arg0 + 0x20) + 0x10) = 0xC00;
    q = func_8005C49C();
    *(u16 *)(*(u32 *)(arg0 + 0x20) + 0x14) = q % 0x1000;
    *(u32 *)(*(u32 *)(arg0 + 0x20) + 4) |= 0x50000000;
    *(u16 *)(arg0 + 2) = *(u16 *)(arg0 + 2) + 1;
    *(s32 *)(arg0 + 0x1C) = *(s16 *)(arg0 + 0x36);
}
