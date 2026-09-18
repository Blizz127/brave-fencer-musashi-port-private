/* Overlay range [8012E4C8,8012E504) from MAIN.CD member 0012.
 * SHA256(span)=bb69e77dac1699df5707fbda1a1808fee7122a0db6ca9b5b0d6ad9433ca2b897.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8012E4C8 - 15 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */


void func_8012E4C8(s32 a0) {
    s32 v1;
    s32 t;
    v1 = *(s32 *)(a0 + 0x20);
    *(s16 *)(v1 + 0x1C) = 0x1000;
    *(s16 *)(v1 + 0x18) = 0x1000;
    *(s16 *)(a0 + 0x60) = 0;
    *(u16 *)(a0 + 0x5C) = *(u16 *)(a0 + 0x5C) | 1;
    t = *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12);
    *(s16 *)(a0 + 0x5E) = 1;
    *(s16 *)(a0 + 0x62) = t + 0x800;
}
