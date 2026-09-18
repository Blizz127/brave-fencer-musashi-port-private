/* Overlay range [801488A8,8014891C) from MAIN.CD member 0012.
 * SHA256(span)=f1d643f29936a018ecea6acbf834702bb644fd3db10e6415460d452cfcaf0a2d.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_801488A8 - 29 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */


s32 func_801488A8(u8 *a0) {
    u8 c;
    s32 v0;
    u32 h;
    s32 lo;
    c = a0[0xA9];
    switch (c) {
    case 0x41:
        v0 = *(u16 *)(a0 + 0xAA) & 0xF000;
        break;
    case 0x53:
    case 0x73:
        h = *(u16 *)(a0 + 0xAE);
        lo = h & 0xFF;
        if (lo != 0x80) {
            return 1;
        }
        if ((s32)(h >> 8) != lo) {
            return 1;
        }
        v0 = 0;
        break;
    default:
        v0 = 0;
        break;
    }
    return v0;
}
