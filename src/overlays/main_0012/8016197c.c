/* Overlay range [8016197C,801619A4) from MAIN.CD member 0012.
 * SHA256(span)=e8ab3e29e739f4a995e7f0380f1426c3051402893ae374e0dabec40df253a493.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8016197C - 10 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */


s32 func_8016197C(s32 a0, s32 a1) {
    s32 v0;
    if (a1 & 1) {
        v0 = 1;
    } else if (a1 & 0x4000) {
        v0 = 2;
    } else {
        v0 = ((u32)a1 >> 11) & 4;
    }
    return v0;
}
