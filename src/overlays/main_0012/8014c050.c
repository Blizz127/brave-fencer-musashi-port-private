/* Overlay range [8014C050,8014C088) from MAIN.CD member 0012.
 * SHA256(span)=f3180e970685ce696574c458e434e126009d7a83daa52e4629f1d2e604da38d5.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8014C050 - 14 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 D_8011D030;

s32 func_8014C050(s32 a0, s32 a1) {
    u32 i = 0;
    s32 p = (s32)&D_8011D030;
    for (; i < 0x1E; i++) {
        if (*(u16 *)p == a1) {
            return p;
        }
        p += 0x58;
    }
    return 0;
}
