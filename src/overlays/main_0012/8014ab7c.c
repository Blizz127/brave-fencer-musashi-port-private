/* Overlay range [8014AB7C,8014ABF0) from MAIN.CD member 0012.
 * SHA256(span)=352b5db80e4f8c3f1b6501b301b19c4c0ba4ae659f8052a1aabc576bdd01abe6.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8014AB7C - 29 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_80162CCC();
extern s32 D_8011F9D0;

void func_8014AB7C(s32 arg0) {
    u8 *p;
    for (p = (u8 *)&D_8011F9D0; p < (u8 *)&D_8011F9D0 + 0x820; p += 0x68) {
        if (*(u16 *)p == arg0) {
            ((void (*)(u8 *))func_80162CCC)(p);
        }
    }
}
