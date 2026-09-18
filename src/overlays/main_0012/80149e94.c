/* Overlay range [80149E94,80149F2C) from MAIN.CD member 0012.
 * SHA256(span)=d330357cc69b701bc3176ce7308884c80b10aaaedeae83f6a8d450c55aeaf2eb.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80149E94 - 38 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern u8 D_801202A0[];
extern s32 func_8016F1AC(void);
extern s32 func_80149F2C(s32 a0, s32 a1);

s32 func_80149E94(s32 arg0) {
    u8 *p;
    if ((func_8016F1AC() == 0) && (*(u8 *)(arg0 + 0x1C5) != 0)) {
        *(u8 *)(arg0 + 0x1C5) = 0;
        for (p = D_801202A0; p < D_801202A0 + 0x6480; p += 0x10C) {
            if (func_80149F2C(arg0, (s32)p) != 0) {
                return 1;
            }
        }
    }
    return 0;
}
