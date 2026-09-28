/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013E448 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_800132BC(s32 a0, s32 a1);
extern s16 D_80126CAC;
extern s32 (*D_801274D0)(s32);
extern s32 D_801274D8;
extern s32 D_801274DC;

s32 func_8013E448(s32 param_1)
{
    s32 iVar1;
    register s32 uVar2 __asm__("$2");
    if (D_801274D0 == 0) {
        iVar1 = func_800132BC((s32)&D_80126CAC, param_1);
        uVar2 = 0;
        if (D_801274D8 < iVar1) {
            uVar2 = (iVar1 < D_801274DC);
        }
        return uVar2;
    }
    return (*D_801274D0)(param_1);
}
