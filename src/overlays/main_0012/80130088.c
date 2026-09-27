/* Overlay range [80130088,801300F4) from MAIN.CD member 0012.
 * SHA256(span)=a8c2d8590c6ff08df34ddae94130e50a5368c734aaa46f06406f7ed012930430.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80130088 - 27 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 func_8012BCCC(s32 a0);
extern s32 func_80131AC8(void *a0);

void func_80130088(void *a0) {
    s32 v0 = func_8012BCCC((s32)a0);
    if (v0 <= 0x8FFF) {
        if (((s32 (*)(void *, s32))func_80131AC8)(a0, 0x32)) {
            return;
        }
        ((s32 (*)(void *, s32))func_80131AC8)(a0, 0x33);
    } else {
        if (((s32 (*)(void *, s32))func_80131AC8)(a0, 0x33)) {
            return;
        }
        ((s32 (*)(void *, s32))func_80131AC8)(a0, 0x32);
    }
}
