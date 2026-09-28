/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801681FC - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern int func_80029178(int arg);
extern int func_80166F58(int arg0, int arg1, int arg2, int arg3);
extern unsigned char D_80181B9C[];
extern unsigned char D_80181B6C[];
extern unsigned char D_80181B6D[];

void func_801681FC(int param_1) {
    unsigned char bVar1;
    int iVar3;
    unsigned int uVar4;

    *(unsigned short *)(param_1 + 0x28) = func_80029178(0x81) & 0xff;
    *(unsigned int *)(param_1 + 0x30) = (unsigned int)D_80181B9C[*(int *)(param_1 + 0x2c)];
    iVar3 = (*(int *)(param_1 + 0x2c) << 0x11) >> 0x10;
    *(unsigned short *)(param_1 + 0x2a) = (unsigned short)D_80181B6C[iVar3];
    bVar1 = D_80181B6D[iVar3];
    uVar4 = *(unsigned int *)(param_1 + 0x2c) & 1;
    *(unsigned int *)(param_1 + 0x2c) = uVar4;
    *(unsigned int *)(param_1 + 0x1c) = (unsigned int)bVar1;
    func_80166F58(param_1, 4, 4, uVar4);
    *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + 1;
}
