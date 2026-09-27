/* Overlay range [8013914C,801391F0) from MAIN.CD member 0012.
 * SHA256(span)=8868c2714bb1d5a336d07d383494d1db1f8f7d9402233a8f4bcc4d04f17b2fac.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8013914C - 41 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 func_80139220(s32 a0);

s32 func_8013914C(s32 a0, s32 a1) {
    s32 t;
    if ((s32)*(u16 *)(a0 + 0x14) >= *(s16 *)(a0 + 0x2C)) {
        if (func_80139220(a0) != 0) {
            return 1;
        }
    }
    t = *(u16 *)(a0 + 0x14);
    *(s16 *)(a1 + 0x0) = *(u16 *)(a0 + 0x38) + (((u32)(t * 3)) >> 1);
    t = *(u16 *)(a0 + 0x12);
    *(s16 *)(a1 + 0x2) = *(u16 *)(a0 + 0x3A) + ((t * 3) << 2);
    *(s16 *)(a0 + 0x14) = *(u16 *)(a0 + 0x14) + 1;
    return 0;
}
