/* Overlay range [8013E448,8013E4B4) from MAIN.CD member 0012.
 * SHA256(span)=1193c59ba8ee87e59021411805b9a964f6877c60e2fa21ba9409d1e7cb27052f.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8013E448 - 27 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 (*D_801274D0)(s32);
extern s32 D_801274D8;
extern s32 D_801274DC;
extern s16 D_80126CAC;
extern s32 func_800132BC(s32 a0, s32 a1);

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
