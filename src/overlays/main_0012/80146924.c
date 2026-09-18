/* Overlay range [80146924,80146994) from MAIN.CD member 0012.
 * SHA256(span)=630377113f611dff15c5a153e78e8932795531eaf951a27197fe9b678ffa718f.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80146924 - 28 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 D_8011D030;
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);

s32 func_80146924(s32 a0, s32 a1, s32 a2, s32 a3, s32 arg5) {
    s32 count = 0;
    u8 *v1 = (u8 *)&D_8011D030;
    u8 *end = v1 + 0xA50;
    while (v1 < end) {
        if (*(u16 *)v1 == (a0 & 0xFFFF)) count++;
        v1 += 0x58;
    }
    if ((u32)count < (u32)arg5) {
        return func_80146994(a0 & 0xFFFF, a1, a2, a3);
    }
    return 0;
}
