/* Overlay range [801496D4,80149704) from MAIN.CD member 0012.
 * SHA256(span)=f348aa0b3a05a3e24c0ee52e4112903613d116fc07b772d70336b84cb27f5d5a.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_801496D4 - 12 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */


s32 func_801496D4(void *a0) {
    s32 v0 = 0;
    if (*(s32 *)((s32)a0 + 0x178)) {
        return v0;
    }
    v0 = *(u16 *)((s32)a0 + 0xAC) & 0x40;
    if (v0) {
        v0 = 1;
    }
    return v0;
}
