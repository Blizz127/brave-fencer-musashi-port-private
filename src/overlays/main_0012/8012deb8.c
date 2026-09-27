/* Overlay range [8012DEB8,8012DF34) from MAIN.CD member 0012.
 * SHA256(span)=262e5302194c2a49152810cbce934c4ecbced2ea3c692747aaa3dda34307950f.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8012DEB8 - 31 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_8012F214(s32 a0, s32 a1, s32 a2);
extern s32 func_8012DF34(s32 a0, s32 a1, s32 a2);
extern s16 D_80126B9A;

s32 func_8012DEB8(s32 a0, s32 a1, s32 a2) {
    s32 sp10[2];
    s32 sp18[2];
    func_8012F214(a0, a1, (s32)sp10);
    func_8012F214(a0, a2, (s32)sp18);
    if (func_8012DF34(a0, (s32)sp10, (s32)sp18) != 0) {
        D_80126B9A = *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12);
        return 1;
    }
    return 0;
}
