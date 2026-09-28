/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCFA8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80161A00(s32 a0);
extern void (*D_800CD6B0[])(void);
extern void func_800CD1A8(void);

void func_800CCFA8(s32 param_1)
{
    s32 iVar1;
    iVar1 = *(s32 *)(param_1 + 0x4C);
    D_800CD6B0[*(u16 *)(param_1 + 2)]();
    if (func_80161A00(iVar1) == 0) {
        ((void (*)(s32))func_800CD1A8)(param_1);
    }
}
