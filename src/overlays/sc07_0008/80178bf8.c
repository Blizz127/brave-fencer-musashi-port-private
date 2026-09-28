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
    extern short D_80196744;
    extern int D_80196538;
    extern short D_80196548;
    extern short D_80196544;
    extern short D_80196540;
    extern short D_8019653C;
    extern int D_801965EC;
    extern int D_80196550;
    extern s16 D_80196530;
    extern short D_80196528;
    extern short D_8019652C;
    extern int D_801966A0;
    extern unsigned int D_801965A0;
    extern unsigned short D_80196526;

    unsigned short *puVar1;
    int iVar2;
    unsigned int *puVar3;

    iVar2 = 9;
    puVar3 = &D_801965A0;
    D_80196744 = 0;
    D_80196538 = 0;
    D_80196548 = 0;
    D_80196544 = 0;
    D_80196540 = 0;
    D_8019653C = 0;
    D_801965EC = 1;
    D_80196550 = 0;
    (*(short *)&D_80196530) = 0;
    do {
        *puVar3 = 0;
        iVar2 = iVar2 + -1;
        puVar3 = puVar3 + -1;
    } while (-1 < iVar2);
    iVar2 = 0x1ff;
    puVar1 = &D_80196526;
    do {
        *puVar1 = 0;
        iVar2 = iVar2 + -1;
        puVar1 = puVar1 + -1;
    } while (-1 < iVar2);
    D_80196528 = 0;
    D_8019652C = 0;
    ((void (*)(int *, int))func_80016714)(&D_801966A0, 0x14);
    func_8017B1D8();
}
