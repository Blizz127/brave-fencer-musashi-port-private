/* Overlay range [80139E84,80139F0C) from MAIN.CD member 0012.
 * SHA256(span)=755e076bd7dfd030084960c123a8c8a60d6dc324ae5870392f0723621c25e0b9.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80139E84 - 34 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_80139A8C(s32 a0);
extern void func_80139B18(s32 a0);

void func_80139E84(s32 a0) {
    s32 s0 = a0;
    if (*(u16 *)(s0 + 0xE) == 0) {
        *(s16 *)(s0 + 0x4) = 2;
    } else {
        func_80139A8C(s0);
        if ((*(s32 *)(s0 + 0x8) & 0x80020) != 0) {
            *(s16 *)(s0 + 0x4) = 2;
            *(s16 *)(s0 + 0xE) = 0;
            if ((*(s32 *)(s0 + 0x8) & 0x20000) == 0) {
                *(s32 *)(s0 + 0x8) = *(s32 *)(s0 + 0x8) & -0x21;
            }
        }
    }
    func_80139B18(s0);
}
