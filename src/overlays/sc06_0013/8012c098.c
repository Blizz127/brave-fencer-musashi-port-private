/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012C098 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8012C218(void *a0);

void func_8012C098(void *param_1)
{
    int iVar1;
    iVar1 = *(int *)((char *)param_1 + 0x68);
    if ((iVar1 != 0) && ((*(short *)((char *)param_1 + 0x72) & 0x8000) != 0)) {
        *(unsigned short *)(iVar1 + 10) = *(unsigned short *)(iVar1 + 10) & 0x7fff;
    }
    func_8012C218(param_1);
    return;
}
