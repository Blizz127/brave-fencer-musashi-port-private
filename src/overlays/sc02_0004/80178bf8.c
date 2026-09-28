/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80178BF8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *, s32);
extern short D_801963C4;
extern s32 D_801961B8;
extern s32 D_8019626C;

s32 func_80178BF8()
{
    extern void func_8017B1D8(void);
    extern short D_801963C4;
    extern int D_801961B8;
    extern short D_801961C8;
    extern short D_801961C4;
    extern short D_801961C0;
    extern short D_801961BC;
    extern int D_8019626C;
    extern int D_801961D0;
    extern s16 D_801961B0;
    extern short D_801961A8;
    extern short D_801961AC;
    extern int D_80196320;
    extern unsigned int D_80196220;
    extern unsigned short D_801961A6;

    unsigned short *puVar1;
    int iVar2;
    unsigned int *puVar3;

    iVar2 = 9;
    puVar3 = &D_80196220;
    D_801963C4 = 0;
    D_801961B8 = 0;
    D_801961C8 = 0;
    D_801961C4 = 0;
    D_801961C0 = 0;
    D_801961BC = 0;
    D_8019626C = 1;
    D_801961D0 = 0;
    (*(short *)&D_801961B0) = 0;
    do {
        *puVar3 = 0;
        iVar2 = iVar2 + -1;
        puVar3 = puVar3 + -1;
    } while (-1 < iVar2);
    iVar2 = 0x1ff;
    puVar1 = &D_801961A6;
    do {
        *puVar1 = 0;
        iVar2 = iVar2 + -1;
        puVar1 = puVar1 + -1;
    } while (-1 < iVar2);
    D_801961A8 = 0;
    D_801961AC = 0;
    ((void (*)(int *, int))func_80016714)(&D_80196320, 0x14);
    func_8017B1D8();
}
