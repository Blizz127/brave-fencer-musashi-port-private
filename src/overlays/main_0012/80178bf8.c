/* Overlay range [80178BF8,80178CBC) from MAIN.CD member 0012.
 * SHA256(span)=433b3cd99c3d18fb5819b8a31ab8cb82be850624b0bed81241fe36f47aeffbd4.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80178BF8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80016714(void *a0, s32 a1);
extern void func_80016714(void *, s32);
extern short D_80185C7C;
extern s32 D_80185350;
extern s32 D_80185B24;

void func_80178BF8(s32 _unused0, s32 _unused1)
{
    extern void func_8017B1D8(void);
    extern short D_80185C7C;
    extern int D_80185350;
    extern short D_80185360;
    extern short D_8018535C;
    extern short D_80185358;
    extern short D_80185354;
    extern int D_80185B24;
    extern int D_80185368;
    extern s16 D_80185348;
    extern short D_80185340;
    extern short D_80185344;
    extern int D_80185BD8;
    extern unsigned int D_801853B8;
    extern unsigned short D_8018533E;

    unsigned short *puVar1;
    int iVar2;
    unsigned int *puVar3;

    iVar2 = 9;
    puVar3 = &D_801853B8;
    D_80185C7C = 0;
    D_80185350 = 0;
    D_80185360 = 0;
    D_8018535C = 0;
    D_80185358 = 0;
    D_80185354 = 0;
    D_80185B24 = 1;
    D_80185368 = 0;
    (*(short *)&D_80185348) = 0;
    do {
        *puVar3 = 0;
        iVar2 = iVar2 + -1;
        puVar3 = puVar3 + -1;
    } while (-1 < iVar2);
    iVar2 = 0x1ff;
    puVar1 = &D_8018533E;
    do {
        *puVar1 = 0;
        iVar2 = iVar2 + -1;
        puVar1 = puVar1 + -1;
    } while (-1 < iVar2);
    D_80185340 = 0;
    D_80185344 = 0;
    ((void (*)(int *, int))func_80016714)(&D_80185BD8, 0x14);
    func_8017B1D8();
}
