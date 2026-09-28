/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016D688 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801465C0(void);
extern void func_800233CC(void *, unsigned short);
extern void func_8001CD9C(int, void *);
extern void func_800233CC(void*, unsigned short);
extern void func_8001CD9C(int, void*);

void func_8016D688(int param_1)
{

    extern unsigned char D_8018F790[];
    int iVar2;
    int iVar3;

    D_8018F790[1] = 0xe0;
    D_8018F790[2] = 0xe0;
    D_8018F790[0] = 0xe0;
    D_8018F790[6] = 0;
    D_8018F790[5] = 0;
    D_8018F790[4] = 0;
    iVar2 = ((int (*)(void))func_801465C0)();
    if (iVar2 != 0) {
        *(int *)(param_1 + 0x20) = iVar2;
        ((void (*)(void *, int))func_800233CC)(D_8018F790, 0x28);
        func_8001CD9C(iVar2, D_8018F790);
        *(unsigned short *)(iVar2 + 0x1a) = 0x1400;
        *(unsigned int *)(iVar2 + 4) = *(unsigned int *)(iVar2 + 4) | 0x50000000;
        iVar3 = *(int *)(param_1 + 0x30);
        *(unsigned short *)(param_1 + 0x28) = *(unsigned short *)(iVar3 + 0x36);
        *(unsigned short *)(param_1 + 0x12) = *(unsigned short *)(iVar3 + 6);
        *(short *)(param_1 + 0x16) = *(unsigned short *)(iVar3 + 0xa) - 0x28;
        *(unsigned short *)(param_1 + 0x1a) = *(unsigned short *)(iVar3 + 0xe);
        *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + 1;
    }
    return;
}
