/* Overlay range [8014A454,8014A4B4) from MAIN.CD member 0012.
 * SHA256(span)=19a35159056383a59b3ba346195d5428eb2c648001423ec9486505d767b1c6ba.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8014A454 - 24 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 func_80012A60(s32 a0, s32 a1);

s32 func_8014A454(s32 a0) {
    s32 v0;
    if (*(u16 *)(a0 + 0x3C) & 0x4000) {
        v0 = (s16)func_80012A60(*(s16 *)(a0 + 0x42),
                                (*(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) + 0x800) & 0xFFF);
        if (v0 < 0x2AA) {
            return 1;
        }
    }
    return 0;
}
