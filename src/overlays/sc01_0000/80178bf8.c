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
    extern short D_801A58E4;
    extern int D_801A5678;
    extern short D_801A5688;
    extern short D_801A5684;
    extern short D_801A5680;
    extern short D_801A567C;
    extern int D_801A578C;
    extern int D_801A5690;
    extern s16 D_801A5670;
    extern short D_801A5668;
    extern short D_801A566C;
    extern int D_801A5840;
    extern unsigned int D_801A56E0;
    extern unsigned short D_801A5666;

    unsigned short *puVar1;
    int iVar2;
    unsigned int *puVar3;

    iVar2 = 9;
    puVar3 = &D_801A56E0;
    D_801A58E4 = 0;
    D_801A5678 = 0;
    D_801A5688 = 0;
    D_801A5684 = 0;
    D_801A5680 = 0;
    D_801A567C = 0;
    D_801A578C = 1;
    D_801A5690 = 0;
    (*(short *)&D_801A5670) = 0;
    do {
        *puVar3 = 0;
        iVar2 = iVar2 + -1;
        puVar3 = puVar3 + -1;
    } while (-1 < iVar2);
    iVar2 = 0x1ff;
    puVar1 = &D_801A5666;
    do {
        *puVar1 = 0;
        iVar2 = iVar2 + -1;
        puVar1 = puVar1 + -1;
    } while (-1 < iVar2);
    D_801A5668 = 0;
    D_801A566C = 0;
    ((void (*)(int *, int))func_80016714)(&D_801A5840, 0x14);
    func_8017B1D8();
}
