/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80168430 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern unsigned char D_80181BA8[];
extern unsigned char D_80181B80[];
extern unsigned char D_80181B81[];
extern int func_80166F58(int param_1, int param_2, int param_3, int param_4);

void func_80168430(int param_1)
{
    int iVar1;

    *(unsigned int *)(param_1 + 0x30) = (unsigned int)(unsigned char)D_80181BA8[*(int *)(param_1 + 0x2c)];
    iVar1 = (*(int *)(param_1 + 0x2c) << 0x11) >> 0x10;
    *(unsigned short *)(param_1 + 0x2a) = (unsigned short)(unsigned char)D_80181B80[iVar1];
    *(unsigned int *)(param_1 + 0x1c) = (unsigned int)(unsigned char)D_80181B81[iVar1];
    func_80166F58(param_1, 5, 0x3b, 2);
    *(short *)(param_1 + 2) = *(short *)(param_1 + 2) + 1;
}
