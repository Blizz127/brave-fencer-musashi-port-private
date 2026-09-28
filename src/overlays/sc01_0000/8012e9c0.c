/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012E9C0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8016AA50(int, int);
extern void func_8016B428(int);
extern void func_80019064(void *);
extern int D_8017EF5C;

void func_8012E9C0(int param_1)
{
    int iVar1;

    if (*(short *)(param_1 + 0x60) != 0) {
        if (*(unsigned char *)(param_1 + 0x5e) == 0x1d) {
            *(short *)(param_1 + 0x82) = 0;
            *(short *)(param_1 + 0x7c) = *(unsigned short *)(param_1 + 6);
            *(short *)(param_1 + 0x7e) = *(unsigned short *)(param_1 + 0xa);
            *(short *)(param_1 + 0x80) = *(unsigned short *)(param_1 + 0xe);
        }
        if (*(int *)(param_1 + 0x78) != 0) {
            iVar1 = *(short *)(param_1 + 0x60) *
                        *(short *)(*(int *)(param_1 + 0x78) + 0x30) >> 0xc;
            if (iVar1 < 1) {
                iVar1 = 1;
            }
        } else {
            iVar1 = *(short *)(param_1 + 0x60);
        }
        func_8016AA50(param_1, iVar1);
        if ((*(unsigned short *)(param_1 + 0x82) & 1) != 0) {
            func_8016B428(param_1);
            func_80019064(&D_8017EF5C);
        }
    }
    return;
}
