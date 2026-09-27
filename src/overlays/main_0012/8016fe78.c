/* Overlay range [8016FE78,8016FED0) from MAIN.CD member 0012.
 * SHA256(span)=c98d4e47766f20257bcf262ba41ebd9dce2ae9dc140926d704a79e5b2c80dac3.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8016FE78 - 22 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_801477E8(s32 *a0, s32 a1);
extern s32 func_80171990(u8 *a0);
extern u16 D_8011F73E;

s32 func_8016FE78(s32 *a0) {
    *(u16 *)((s32)a0 + 0xAA) |= 0x40;
    if (D_8011F73E != 0) {
        func_801477E8(a0, D_8011F73E << 16);
    }
    return func_80171990((u8 *)a0);
}
