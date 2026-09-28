/* SC02 resident image [80178BF8,80178CBC) at overlay base 0x80128158.
 * SHA256(span)=0b8febd67579cdfc52755fb27bfcc1b0d7ade5db356836a317d186e49609d63c.
 * Word export only: the native seam executes the guest's own loaded
 * instruction stream. No C match claim yet. */
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
    extern short D_801B7B0C;
    extern int D_801B7508;
    extern short D_801B7518;
    extern short D_801B7514;
    extern short D_801B7510;
    extern short D_801B750C;
    extern int D_801B79B4;
    extern int D_801B7520;
    extern s16 D_801B7500;
    extern short D_801B74F8;
    extern short D_801B74FC;
    extern int D_801B7A68;
    extern unsigned int D_801B7570;
    extern unsigned short D_801B74F6;

    unsigned short *puVar1;
    int iVar2;
    unsigned int *puVar3;

    iVar2 = 9;
    puVar3 = &D_801B7570;
    D_801B7B0C = 0;
    D_801B7508 = 0;
    D_801B7518 = 0;
    D_801B7514 = 0;
    D_801B7510 = 0;
    D_801B750C = 0;
    D_801B79B4 = 1;
    D_801B7520 = 0;
    (*(short *)&D_801B7500) = 0;
    do {
        *puVar3 = 0;
        iVar2 = iVar2 + -1;
        puVar3 = puVar3 + -1;
    } while (-1 < iVar2);
    iVar2 = 0x1ff;
    puVar1 = &D_801B74F6;
    do {
        *puVar1 = 0;
        iVar2 = iVar2 + -1;
        puVar1 = puVar1 + -1;
    } while (-1 < iVar2);
    D_801B74F8 = 0;
    D_801B74FC = 0;
    ((void (*)(int *, int))func_80016714)(&D_801B7A68, 0x14);
    func_8017B1D8();
}
