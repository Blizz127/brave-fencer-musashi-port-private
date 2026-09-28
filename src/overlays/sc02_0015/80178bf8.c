/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80178BF8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *, s32);
extern short D_8019069C;
extern s32 D_80190290;
extern s32 D_80190544;

s32 func_80178BF8()
{
    extern void func_8017B1D8(void);
    extern short D_8019069C;
    extern int D_80190290;
    extern short D_801902A0;
    extern short D_8019029C;
    extern short D_80190298;
    extern short D_80190294;
    extern int D_80190544;
    extern int D_801902A8;
    extern s16 D_80190288;
    extern short D_80190280;
    extern short D_80190284;
    extern int D_801905F8;
    extern unsigned int D_801902F8;
    extern unsigned short D_8019027E;

    unsigned short *puVar1;
    int iVar2;
    unsigned int *puVar3;

    iVar2 = 9;
    puVar3 = &D_801902F8;
    D_8019069C = 0;
    D_80190290 = 0;
    D_801902A0 = 0;
    D_8019029C = 0;
    D_80190298 = 0;
    D_80190294 = 0;
    D_80190544 = 1;
    D_801902A8 = 0;
    (*(short *)&D_80190288) = 0;
    do {
        *puVar3 = 0;
        iVar2 = iVar2 + -1;
        puVar3 = puVar3 + -1;
    } while (-1 < iVar2);
    iVar2 = 0x1ff;
    puVar1 = &D_8019027E;
    do {
        *puVar1 = 0;
        iVar2 = iVar2 + -1;
        puVar1 = puVar1 + -1;
    } while (-1 < iVar2);
    D_80190280 = 0;
    D_80190284 = 0;
    ((void (*)(int *, int))func_80016714)(&D_801905F8, 0x14);
    func_8017B1D8();
}
