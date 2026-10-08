/* Overlay range [8016AA50,8016AB30) from MAIN.CD member 0012.
 * SHA256(span)=f892d13d0dda0a76cffb2a4071d04ed703c73a617b834307c185dff5ab190257.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8016AA50 - 56 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_80146C3C();
extern s32 D_8011D030;
extern u16 D_80126B5E;
extern u16 D_80126B62;
extern u16 D_80126B66;

void func_8016AA50(s32 param_1, s32 param_2) {
    register short *psVar3 __asm__("$4");
    register s32 iVar4 __asm__("$5");
    register s32 sVar2 __asm__("$3");
    register s32 t __asm__("$2");
    if (param_2 >= 0) {
        ((s32 (*)(s32, void *, s32, s32, s32, s32, s32))func_80146A6C)(
            0x1d, (void *)param_1,
            *(s16 *)(param_1 + 0x7c), *(s16 *)(param_1 + 0x7e),
            *(s16 *)(param_1 + 0x80), 0, param_2);
        return;
    }
    iVar4 = 0;
    psVar3 = (short *)&D_8011D030;
    do {
        sVar2 = (u16)*psVar3;
        if (sVar2 == 0 || sVar2 == 3 || sVar2 == 9) {
            ((void (*)(short *))func_80146C3C)(psVar3);
            ((s32 (*)(s32, void *, s32, s32, s32, s32, s32))func_80146A6C)(
                0x1d, (void *)param_1,
                (s16)D_80126B5E, (s16)((u16)D_80126B62 - 0x20),
                (s16)D_80126B66, 7, 0);
            return;
        }
        t = iVar4 + 1;
        iVar4 = t;
        __asm__ __volatile__("" : "=r"(t) : "0"(t));
        psVar3 = psVar3 + 0x2c;
    } while ((s16)t < 0x1e);
}
