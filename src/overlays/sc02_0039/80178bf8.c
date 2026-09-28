/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80178BF8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *, s32);
extern short D_801A0DFC;
extern s32 D_801A0BE8;
extern s32 D_801A0CA4;

s32 func_80178BF8()
{
    extern void func_8017B1D8(void);
    extern short D_801A0DFC;
    extern int D_801A0BE8;
    extern short D_801A0BF8;
    extern short D_801A0BF4;
    extern short D_801A0BF0;
    extern short D_801A0BEC;
    extern int D_801A0CA4;
    extern int D_801A0C00;
    extern s16 D_801A0BE0;
    extern short D_801A0BD8;
    extern short D_801A0BDC;
    extern int D_801A0D58;
    extern unsigned int D_801A0C50;
    extern unsigned short D_801A0BD6;

    unsigned short *puVar1;
    int iVar2;
    unsigned int *puVar3;

    iVar2 = 9;
    puVar3 = &D_801A0C50;
    D_801A0DFC = 0;
    D_801A0BE8 = 0;
    D_801A0BF8 = 0;
    D_801A0BF4 = 0;
    D_801A0BF0 = 0;
    D_801A0BEC = 0;
    D_801A0CA4 = 1;
    D_801A0C00 = 0;
    (*(short *)&D_801A0BE0) = 0;
    do {
        *puVar3 = 0;
        iVar2 = iVar2 + -1;
        puVar3 = puVar3 + -1;
    } while (-1 < iVar2);
    iVar2 = 0x1ff;
    puVar1 = &D_801A0BD6;
    do {
        *puVar1 = 0;
        iVar2 = iVar2 + -1;
        puVar1 = puVar1 + -1;
    } while (-1 < iVar2);
    D_801A0BD8 = 0;
    D_801A0BDC = 0;
    ((void (*)(int *, int))func_80016714)(&D_801A0D58, 0x14);
    func_8017B1D8();
}
