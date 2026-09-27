/* Overlay range [801628F4,80162968) from MAIN.CD member 0012.
 * SHA256(span)=40639445fe72781923afa85337553da894fa3c270fc17be929216ea6cb2abd3c.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_801628F4 - 29 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_80162968(s32 a0);

void func_801628F4(s32 *a0) {
    s16 *a2 = (s16 *)a0[0x4 / 4];
    s32 *a1 = (s32 *)a0[0x8 / 4];
    if (*(s16 *)((u8 *)a2 + 0x7E) != 0) {
        a1[0x4 / 4] |= 0x80000000;
    } else {
        a1[0x4 / 4] &= 0x7FFFFFFF;
    }
    a0[0x20 / 4] = *(s16 *)((u8 *)a2 + 0x78);
    a0[0x24 / 4] = *(s16 *)((u8 *)a2 + 0x7A);
    a0[0x28 / 4] = *(s16 *)((u8 *)a2 + 0x7C);
    func_80162968((s32)a0);
}
