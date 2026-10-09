/* Overlay range [80149290,80149350) from MAIN.CD member 0012.
 * SHA256(span)=c562ab0f22769c290b08dfa7d85d1293ece3f76b7406bd7b047d03cef1e299ad.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80149290 - 48 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_80149350(s32 arg0, s32 a1, s32 a2);

void func_80149290(s32 a0, s32 a1, s32 a2) {
    volatile s32 a;
    volatile s32 b;
    volatile s32 c;
    a = *(s32 *)(*(s32 *)(a0 + 0x20) + 0x48);
    b = *(s32 *)(*(s32 *)(a0 + 0x20) + 0x4C);
    c = *(s32 *)(*(s32 *)(a0 + 0x20) + 0x4C);
    *(s32 *)(*(s32 *)(a0 + 0x20) + 0x48) = *(s16 *)(a0 + 6);
    *(s32 *)(*(s32 *)(a0 + 0x20) + 0x4C) = *(s16 *)(a0 + 0xA);
    *(s32 *)(*(s32 *)(a0 + 0x20) + 0x50) = *(s16 *)(a0 + 0xE);
    func_80149350(a0, a1, a2); /* a1/a2 pass through untouched in retail */
    *(s32 *)(*(s32 *)(a0 + 0x20) + 0x48) = a;
    *(s32 *)(*(s32 *)(a0 + 0x20) + 0x4C) = b;
    *(s32 *)(*(s32 *)(a0 + 0x20) + 0x50) = c;
}
