/* Overlay range [8015640C,801564B0) from MAIN.CD member 0012.
 * SHA256(span)=0ccf92b7d46f0909909836120e61de2c556d4a8f6159382be99c1d15c3cc9ee4.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8015640C - 41 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 func_801564B0(s32 a0);
extern s32 func_80029178(s32 a0);

s32 func_8015640C(s32 a0, s32 a1) {
    if ((func_801564B0(a0) & 0xFFFF) != 0) {
        if ((func_80029178(0x1C) & 0xFF) != 0) {
            return (((175 * (a1 & 0xFFFF)) / 100) & 0xFFFF) | 0x8000;
        } else {
            return (((150 * (a1 & 0xFFFF)) / 100) & 0xFFFF) | 0x8000;
        }
    }
    return a1 & 0xFFFF;
}
