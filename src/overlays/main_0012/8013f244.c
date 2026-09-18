/* Overlay range [8013F244,8013F350) from MAIN.CD member 0012.
 * SHA256(span)=ff1c0ee145ce4cd5cff34ed794dfc617092a99ea7f0c3b782622a0c20890ebdd.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8013F244 - 67 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern u16 D_8011511A;
extern u16 D_8011511E;
extern void func_80141C0C(s32);

void func_8013F244(void)
{
    u16 *p = &D_8011511A;
    u16 uVar1;
    s32 iVar2;
    iVar2 = 0;
    if (*p < 3) {
        if ((D_8011511E & 0x2000) != 0) {
            uVar1 = *p + 1;
            iVar2 = 1;
            *p = *p + 1;
            if (2 < uVar1) {
                *p = 0;
            }
        }
        if ((D_8011511E & 0x8000) != 0) {
            D_8011511A = D_8011511A - 1;
            if (2 < D_8011511A) {
                D_8011511A = 2;
            }
            iVar2 = iVar2 + 1;
        }
        if ((D_8011511E & 0x5000) != 0) {
            D_8011511A = 3;
            iVar2 = iVar2 + 1;
        }
    } else {
        iVar2 = 0;
        if ((D_8011511E & 0x5000) == 0)
            goto done;
        *p = 0;
        iVar2 = 1;
    }
done:
    if ((iVar2 << 0x10) != 0) {
        func_80141C0C(2);
    }
    return;
}
