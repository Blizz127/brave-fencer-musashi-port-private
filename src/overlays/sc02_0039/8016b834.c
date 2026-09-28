/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016B834 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801465C0(void);
extern void func_800233CC(void *, unsigned short);
extern void func_8001CD9C(int, void *);
extern int *D_8018231C[];
extern unsigned short D_80182324[];
extern unsigned short D_8018232C[];
extern unsigned char D_8019FF58[];

int func_8016B834(int param_1, int param_2) {
    int *puVar3;
    int *puVar2;
    int iVar1;

    puVar2 = (int *)(D_8019FF58 + param_2 * 0x40);
    puVar3 = D_8018231C[*(int *)(param_1 + 0x2c)];
    iVar1 = ((int (*)(void))func_801465C0)();
    if (iVar1 != 0) {
        func_8001CD9C(iVar1, puVar2);
        func_800233CC(puVar2, D_80182324[param_2]);
        puVar2[0] = *(int *)((int)puVar3 + param_2 * 8);
        puVar2[1] = *(int *)((int)puVar3 + param_2 * 8 + 4);
        *(unsigned int *)(iVar1 + 4) = *(unsigned int *)(iVar1 + 4) | 0x50040000;
        *(short *)(iVar1 + 0x1e) = D_8018232C[param_2];
    }
    return iVar1;
}
