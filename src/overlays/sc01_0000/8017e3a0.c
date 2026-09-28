/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017E3A0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));

void func_8017E3A0(s32 a0, s32 a1, s32 a2, s32 a3, s32 arg4, s32 arg5)
{
    extern u8 *D_800A5E60;
    extern u8 D_800AF630[];
    extern u8 D_800AA608[];

    u8 *prim;
    u8 *fl;
    u32 *q;
    u32 *addrw;
    u32 v1;
    u32 val;
    u32 mlo, mhi;
    volatile s32 pad;

    prim = D_800A5E60;
    fl = D_800AF630;
    prim[3] = 4;
    prim[7] = 0x50;
    if (arg5 == 0) {
        prim[0xC] = 0xFF;
        prim[0xE] = 0;
        prim[0xD] = 0;
        prim[4] = arg4;
        prim[6] = 0;
    } else {
        prim[0xE] = 0xFF;
        prim[0xD] = 0;
        prim[0xC] = 0;
        prim[6] = arg4;
        prim[4] = 0;
    }
    prim[5] = 0;
    __asm__ __volatile__("");
    mlo = 0xFFFFFF;
    ((u16 *)prim)[5] = a1;
    mhi = 0xFF000000;
    ((u16 *)prim)[4] = a0;
    ((u16 *)prim)[8] = a2;
    ((u16 *)prim)[9] = a3;
    *(u32 *)prim = (*(u32 *)prim & mhi) | (*(u32 *)&D_800AA608[*(u16 *)(fl + 0xA3D2) << 14] & mlo);
    q = (u32 *)D_800AA608;
    addrw = (u32 *)((s32)q + (*(u16 *)(fl + 0xA3D2) << 14));
    v1 = (u32)prim & mlo;
    val = *addrw;
    D_800A5E60 = (prim += 20);
    *addrw = (val & mhi) | v1;
}
