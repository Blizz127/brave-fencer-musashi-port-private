/* Overlay range [80146608,801466B4) from MAIN.CD member 0012.
 * SHA256(span)=d2d0ffd32e6251c88c592f54927eba47e8d7777990fdb5231b6a4bab7f61e122.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80146608 - 43 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern s32 D_8011F9D0;

s32 func_80146608(s32 a0, s32 a1, s32 a2, s32 a3, s16 arg9, s32 arg10, s32 arg11, s32 arg12, s32 arg13) {
    u8 *p;
    u8 *end;
    s32 cnt;
    cnt = 0;
    p = (u8 *)&D_8011F9D0;
    end = p + 0x820;
    while (p < end) {
        if (*(u16 *)p == (a0 & 0xFFFF)) {
            cnt++;
        }
        p += 0x68;
    }
    if ((u32)cnt >= (u32)arg12) {
        return 0;
    }
    func_801466F0(a0 & 0xFFFF, a1, (s16)a2, (s16)a3, arg9, arg10, arg11, arg13);
}
