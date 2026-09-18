/* Overlay range [8014F2E0,8014F3E8) from MAIN.CD member 0012.
 * SHA256(span)=2715f0361ffae8cf26ee32c39ea38abcd4f788fad022e1263302aa70d8cb03ca.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8014F2E0 - 66 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 D_801150D8;
extern s32 func_80135A4C(s32 a0, s32 a1, s32 *a2, s32 a3);
extern u8 D_801202A0[];

s32 func_8014F2E0(s32 arg0, s16 * arg1, s16 * arg2)
{
    s32 ret = 0;
    u8 *s;
    for (s = D_801202A0; s < D_801202A0 + 0x6480; s += 0x10C) {
        if (*(u16 *)s != 0 &&
            *(s32 *)(s + 0x58) != 0 &&
            (s16 *)s != *(s16 **)(arg0 + 0x178) &&
            (s16 *)s != *(s16 **)(arg0 + 0x174) &&
            (*(s32 *)(s + 0x5C) & 0x1800) != 0) {
            D_801150D8 = 0;
            if (((s32 (*)(s32, s32, s32, s32))func_80135A4C)(((struct { s32 field; } *)(s + 0x20))->field,
                              ((struct { s32 field; } *)(s + 0x58))->field,
                              (s32)arg1, (s32)arg2) != 0) {
                ret = 1;
            }
        }
    }
    return ret;
}
