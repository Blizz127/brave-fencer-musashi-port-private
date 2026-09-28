/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80164744 - byte-exact against retail at -O2 (tools/register_match.py). */
void func_80162D28(s32 *a0);
extern void (*D_801808E0[])(void);
extern void func_80162D28(s32 *a0);

void func_80164744(s32 param_1)
{
    s32 iVar1;

    iVar1 = *(s32 *)(param_1 + 0x20);
    D_801808E0[*(u16 *)(param_1 + 2)]();
    if (iVar1 != 0) {
        ((void (*)(s32))func_80162D28)(param_1);
    }
}
