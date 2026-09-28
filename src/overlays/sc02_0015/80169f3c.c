/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80169F3C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_800D21C4(s32 a0, void *a1, s32 a2);
extern void func_800D1FC8(s32 a0, s32 a1);
extern void func_80128EA8(s32 a0, s32 a1, s32 a2);
extern void func_80146C3C();
extern void func_80146C3C(void);
extern char D_801812D4[];
extern char D_80181294[];

void func_80169F3C(int param_1)
{
    int iVar1;

    ((int (*)(int, int))func_800D1FC8)(param_1, 6);
    iVar1 = func_800D21C4(param_1, D_801812D4, 0x16);
    if (iVar1 != 0) {
        *(int *)(param_1 + 0x20) = iVar1;
        *(short *)(iVar1 + 0x1a) = 0x2000;
        *(short *)(iVar1 + 0x18) = 0x2000;
        *(char *)(iVar1 + 0x26) = 0x60;
        *(char *)(iVar1 + 0x25) = 0x60;
        *(char *)(iVar1 + 0x24) = 0x60;
        *(unsigned int *)(iVar1 + 4) = *(unsigned int *)(iVar1 + 4) | 0x50000000;
        ((void (*)(int, int, void *))func_80128EA8)(iVar1, param_1 + 0x24, D_80181294);
        *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + 1;
    } else {
        ((void (*)(int))func_80146C3C)(param_1);
    }
}
