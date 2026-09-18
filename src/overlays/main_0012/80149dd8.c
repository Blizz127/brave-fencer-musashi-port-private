/* Overlay range [80149DD8,80149E94) from MAIN.CD member 0012.
 * SHA256(span)=e13625fbcb45d73e7bb2e8985d196b4ec144a3b241395b3ae731e7344ed0f04f.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80149DD8 - 47 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern u8 D_801202A0[];
extern s32 func_80149F2C(s32 a0, s32 a1);

s32 func_80149DD8(s32 a0) {
    u8 *p;
    if (*(s32 *)(a0 + 0x178) != 0) {
        return 0;
    }
    if (*(s32 *)(a0 + 0x44) & 0x404) {
        return 0;
    }
    if ((*(u16 *)(a0 + 0xAC) & 0x80) == 0) {
        return 0;
    }
    *(s32 *)(a0 + 0x190) = 0;
    for (p = D_801202A0; p < D_801202A0 + 0x6480; p += 0x10C) {
        if (func_80149F2C(a0, (s32)p) != 0) {
            return 1;
        }
    }
    return 0;
}
