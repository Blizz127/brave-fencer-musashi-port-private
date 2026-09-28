/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80178BF8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80016714(void *, s32);

s32 func_80178BF8()
{
    extern void func_8017B1D8(void);
    extern short D_8019D42C;
    extern int D_8019D218;
    extern short D_8019D228;
    extern short D_8019D224;
    extern short D_8019D220;
    extern short D_8019D21C;
    extern int D_8019D2D4;
    extern int D_8019D230;
    extern s16 D_8019D210;
    extern short D_8019D208;
    extern short D_8019D20C;
    extern int D_8019D388;
    extern unsigned int D_8019D280;
    extern unsigned short D_8019D206;

    unsigned short *puVar1;
    int iVar2;
    unsigned int *puVar3;

    iVar2 = 9;
    puVar3 = &D_8019D280;
    D_8019D42C = 0;
    D_8019D218 = 0;
    D_8019D228 = 0;
    D_8019D224 = 0;
    D_8019D220 = 0;
    D_8019D21C = 0;
    D_8019D2D4 = 1;
    D_8019D230 = 0;
    (*(short *)&D_8019D210) = 0;
    do {
        *puVar3 = 0;
        iVar2 = iVar2 + -1;
        puVar3 = puVar3 + -1;
    } while (-1 < iVar2);
    iVar2 = 0x1ff;
    puVar1 = &D_8019D206;
    do {
        *puVar1 = 0;
        iVar2 = iVar2 + -1;
        puVar1 = puVar1 + -1;
    } while (-1 < iVar2);
    D_8019D208 = 0;
    D_8019D20C = 0;
    ((void (*)(int *, int))func_80016714)(&D_8019D388, 0x14);
    func_8017B1D8();
}
