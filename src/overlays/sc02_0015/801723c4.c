/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801723C4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147078(s32 *a0, s16 a1);
extern void func_8014A1B0(s32 a0, s32 a1);
extern void func_801599A4(void *a0);
extern void func_80147078(s32 *, s16);

void func_801723C4(s32 param_1, s32 param_2)
{
    ((void (*)(void))func_801599A4)();
    ((void (*)(int, int))func_80147078)(param_1, 0xd);
    *(int *)(param_1 + 0x178) = param_2;
    func_8014A1B0(param_1, param_2);
}
