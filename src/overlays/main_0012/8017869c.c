/* Overlay range [8017869C,80178744) from MAIN.CD member 0012.
 * SHA256(span)=5650da561189fc5de5225bef5034db39acf7666eb8a246a853f118ac78d1362d.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8017869C - 42 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_80178744(s32 a0, s32 a1);

void func_8017869C(s32 a0) {
    s32 v1;
    s32 a1;
    if (*(s16 *)(a0 + 0xAA) == 0) {
        return;
    }
    *(s16 *)(a0 + 0xAA) = *(s16 *)(a0 + 0xAA) - 1;
    v1 = *(s16 *)(a0 + 0xAA);
    if (v1 == 0) {
        a1 = 0x1000;
        if (*(u16 *)(a0 + 0x5E) == 0x1E) {
            *(s16 *)(a0 + 0x5E) = 0;
        }
    } else if (v1 >= 0xF1) {
        a1 = 0x1000 - (0x100 - v1) * 0x90;
    } else {
        if (v1 < 0x10) {
            a1 = 0x1000 - v1 * 0x90;
        } else {
            a1 = 0x700;
        }
    }
    func_80178744(a0, a1);
}
