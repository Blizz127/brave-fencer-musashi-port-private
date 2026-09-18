/* Overlay range [80147F78,80148038) from MAIN.CD member 0012.
 * SHA256(span)=6006beb0943c37dab180cb63be57c1fb4f9416a4234623307aca4c9095bb553f.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80147F78 - 48 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_80147928(int a0, int a1);
extern void func_8014799C(int a0, int a1);
extern void func_80147A10(int a0, int a1);
extern volatile s32 D_80127090;
extern volatile s32 D_80127094;
extern volatile s32 D_80127098;

void func_80147F78(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 reserved[16];
    s32 t;
    func_80147928(a0, a1);
    func_8014799C(a0, a2);
    func_80147A10(a0, a3);
    D_80127090 = *(s32 *)(a0 + 0x24);
    t = D_80127090;
    D_80127094 = *(s32 *)(a0 + 0x28);
    D_80127098 = *(s32 *)(a0 + 0x2C);
    *(s32 *)(a0 + 0x10) = t;
    *(s32 *)(a0 + 0x14) = D_80127094;
    *(s32 *)(a0 + 0x18) = D_80127098;
    D_80127090 = 0;
    D_80127094 = 0;
    D_80127098 = 0;
    (void)reserved;
}
