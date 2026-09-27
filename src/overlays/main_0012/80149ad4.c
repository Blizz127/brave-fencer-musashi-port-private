/* Overlay range [80149AD4,80149B14) from MAIN.CD member 0012.
 * SHA256(span)=51a616ec0da4f828b3506a2053bd464f2270231ca986b00d2ed255f8c78849e4.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80149AD4 - 16 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_8015DAC4(s32 *a0);
extern void func_8015554C(s32 *a0);

void func_80149AD4(s32 *a0) {
    s32 pad[6];
    (void)pad;
    if (*(s32 *)((s32)a0 + 0x178) != 0) {
        func_8015DAC4(a0);
    } else {
        *(s8 *)((s32)a0 + 0x1AA) = 1;
        func_8015554C(a0);
    }
}
