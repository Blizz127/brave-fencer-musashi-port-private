/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015FD74 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 a0);
extern s32 func_8013767C(s32 a0);
extern unsigned int D_80181AF4[];

void func_8015FD74(int param_1)
{
    ((int (*)(int))func_80147324)(0x18);
    *(int *)(param_1 + 0x198) = func_8013767C(D_80181AF4[*(unsigned char *)(param_1 + 0x1a0)]);
    ((int (*)(int))func_80146CA0)(param_1);
}
