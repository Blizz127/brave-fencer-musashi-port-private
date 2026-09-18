/* Overlay range [80139DF4,80139E84) from MAIN.CD member 0012.
 * SHA256(span)=3cd86249b31cc1bc154668f88f43a162746248d03a6715942bd7e07023a89a6f.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80139DF4 - 36 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_80139A8C(s32 a0);

void func_80139DF4(s32 a0) {
    s32 c;
    s32 v;
    c = *(u8 *)(a0 + 0xC);
    if (c != 0) {
        c = c - 1;
        *(s8 *)(a0 + 0xC) = (s8)c;
        if ((c & 0xFF) != 0) {
            goto calls;
        }
    }
    *(s16 *)(a0 + 0x4) = 2;
    return;
calls:
    func_80139A8C(a0);
    if (*(s32 *)(a0 + 0x8) & 0x20) {
        *(s16 *)(a0 + 0x4) = 2;
        v = *(s32 *)(a0 + 0x8);
        *(s8 *)(a0 + 0xC) = 0;
        if ((v & 0x20000) == 0) {
            *(s32 *)(a0 + 0x8) = v & -0x21;
        }
    }
}
