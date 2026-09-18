/* Overlay range [8014D4C0,8014D610) from MAIN.CD member 0012.
 * SHA256(span)=cdfe634510760069bafb2f72a4f17f580728a1c5a8063c9fa4394e36ef1fd169.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8014D4C0 - 84 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 func_80135A4C(s32 a0, s32 a1, s32 *a2, s32 a3);
extern s32 func_8014C918(s32 a0, s32 a1);

s32 func_8014D4C0(s32 a0, void *a1, void *a2) {
    s32 psVar3;
    ((u16 *)a1)[1] = ((u16 *)a1)[1] - 3;
    ((u16 *)a2)[1] = ((u16 *)a2)[1] + 8;
    psVar3 = *(s32 *)(a0 + 0x174);
    if (*(u16 *)psVar3 != 0) {
        if ((*(u16 *)(psVar3 + 0x5c) & 0x400) &&
            *(s32 *)(psVar3 + 0x58) != 0 &&
            *(s16 *)(psVar3 + 0xa) >= *(s16 *)(a0 + 0xa)) {
            goto do_body;
        }
        if (*(u16 *)psVar3 != 0) {
            *(s8 *)(psVar3 + 0x74) = 0;
        }
    }
    *(s32 *)(a0 + 0x174) = 0;
    return 0;
do_body:
    *(u16 *)a1 = *(u16 *)(a0 + 0x98);
    ((u16 *)a1)[1] = *(u16 *)(a0 + 0x9a) - 3;
    ((u16 *)a1)[2] = *(u16 *)(a0 + 0x9c);
    if (func_80135A4C(*(s32 *)(psVar3 + 0x20), *(s32 *)(psVar3 + 0x58),
                      (s32 *)a1, (s32)a2) != 0) {
        *(u16 *)(a0 + 6) = ((u16 *)a2)[0];
        *(u16 *)(a0 + 0xa) = ((u16 *)a2)[1];
        *(u16 *)(a0 + 0xe) = ((u16 *)a2)[2];
        *(u16 *)(a0 + 0x16e) = func_8014C918(a0, *(u8 *)(psVar3 + 0x75)) & 0xff;
        return 1;
    }
    *(s8 *)(psVar3 + 0x74) = 0;
    *(s32 *)(a0 + 0x174) = 0;
    return 0;
}
