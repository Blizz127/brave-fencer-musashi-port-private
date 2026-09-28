/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCFC8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_801619D0(s32 a0);
extern void (*D_800CE204[])(void);
extern void func_800CD178(void);

void func_800CCFC8(s32 param_1)
{
    s32 iVar1;
    iVar1 = *(s32 *)(param_1 + 0x4C);
    D_800CE204[*(u16 *)(param_1 + 2)]();
    if (func_801619D0(iVar1) == 0) {
        ((void (*)(s32))func_800CD178)(param_1);
    }
}
