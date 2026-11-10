/* Overlay range [80131AC8,80131B14) from MAIN.CD member 0012.
 * SHA256(span)=9a02b0139d62b758bcb5954beadfe0b355a740e07ce4ee012330f26116be131f.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80131AC8 - 19 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 func_80131CF4(s32 a0, s32 a1);
extern void func_8002D4C8(s32 a0, s32 a1);

s32 func_80131AC8(void *a0, s32 a1) {
    s32 s0 = func_80131CF4(*(s32 *)((u8 *)a0 + 0xBC), a1) & 0xFFFF;
    if (s0 != 0) {
        func_8002D4C8(s0, 0);
        return s0;
    }
    return 0;
}
