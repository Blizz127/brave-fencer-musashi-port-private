/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801442F8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8012C218(void *a0);
extern void (*D_8017FBE0[])();

void func_801442F8(int param_1)
{
    int iVar1;

    D_8017FBE0[*(u16 *)(param_1 + 2)]();
    iVar1 = *(int *)(param_1 + 0x1c) + 1;
    *(int *)(param_1 + 0x1c) = iVar1;
    if (0x1d < iVar1) {
        func_8012C218(param_1);
    }
}
