/* Overlay range [801638A0,80163950) from MAIN.CD member 0012.
 * SHA256(span)=00a79b42f520329092091eadaea5582ae07fa17fb00e21beff15f63625f18d1b.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_801638A0 - 44 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_80015978(s32 a0, s32 *a1);
extern s32 func_80135004(s32 a0, void *a1, s32 a2);
extern void func_80015954(s32 a0, s32 a1);
extern s16 D_801152AA;
extern void *memcpy(void *, const void *, u32);

s32 func_801638A0(u8 *a0, s32 a1) {
    u8 buf[8];
    s16 d;
    s32 p;
    __builtin_memcpy(buf, a0 + 0x44, 8);
    p = (s32)(a0 + 4);
    func_80015978(p, (s32 *)a1);
    if (func_80135004(1, buf, a1) != 0) {
        func_80015954(a1, p);
        d = D_801152AA;
        if (d >= -0x578) {
            return 0x8000;
        }
        if (d >= -0xBCB) {
            return 0x4000;
        }
        return 0x2000;
    }
    return 0;
}
