/* Overlay range [80147C30,80147CC8) from MAIN.CD member 0012.
 * SHA256(span)=7b0bd2810d787769e7707f6b55c3b29403a2b52c398e3474a91dbcb9d83933fd.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80147C30 - 38 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_80147CC8(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
extern s32 D_80127090;
extern s32 D_80127094;
extern s32 D_80127098;

void func_80147C30(s32 a0, s32 a1, s32 a2, s32 a3) {
    s32 out[3];
    s32 *p0 = &D_80127090;
    s32 *p1 = &D_80127094;
    s32 *p2 = &D_80127098;
    func_80147CC8(a0, a1, a2, a3, (s32)out);
    D_80127090 = out[0];
    D_80127094 = out[1];
    D_80127098 = out[2];
    *(s32 *)(a0 + 0x10) = *p0;
    *(s32 *)(a0 + 0x14) = *p1;
    *(s32 *)(a0 + 0x18) = *p2;
    D_80127090 = 0;
    D_80127094 = 0;
    D_80127098 = 0;
}
