/* Overlay range [801776EC,80177784) from MAIN.CD member 0012.
 * SHA256(span)=2c4bb06c7a9e724b179e915ba02f846911d70dc1dcc2e0539ea84ba48b4fbbd5.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_801776EC - 38 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern u8 D_8011F7AB;

void func_801776EC(u8 *a0)
{
    u8 *p;
    switch (D_8011F7AB) {
    default:
        D_8011F7AB = 0;
    case 0:
        a0[4] = 0xFF;
        a0[6] = 0x30;
        a0[5] = 0x30;
        break;
    case 1:
        a0[5] = 0xFF;
        a0[6] = 0x30;
        a0[4] = 0x30;
        break;
    case 2:
        a0[6] = 0xFF;
        a0[5] = 0x30;
        a0[4] = 0x30;
        break;
    }
    p = &D_8011F7AB;
    *p = *p + 1;
}
