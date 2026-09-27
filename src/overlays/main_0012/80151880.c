/* Overlay range [80151880,801518D8) from MAIN.CD member 0012.
 * SHA256(span)=409e7861711e23597305bc9195bf13eed0910e05bd8abd11cc4ca2a4d7ba7b47.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80151880 - 22 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */


s32 func_80151880(s32 a0) {
    u16 h;
    s32 v1;
    h = *(u16*)(a0 + 0x3E);
    v1 = h & 0xFF;
    if (v1 == 0x1B) return 1;
    if (v1 == 0x1C) return 1;
    if (v1 == 0xF) return 1;
    if (v1 == 0x10) return 1;
    if (v1 == 0xB) return 2;
    if (v1 != 0x1F) return (h >> 8) & 2;
    return 1;
}
