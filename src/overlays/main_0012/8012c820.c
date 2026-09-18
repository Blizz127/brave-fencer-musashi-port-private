/* Overlay range [8012C820,8012C890) from MAIN.CD member 0012.
 * SHA256(span)=9afdf98da44754df35af4b84593410e22aa0ec9c759195af15cfbc626f517241.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8012C820 - 28 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern u8 D_80120194[];
extern s32 func_8012C890(s32 a0, s32 a1, s32 a2);

s32 func_8012C820(u8 *a0) {
    u8 *base = D_80120194;
    u8 *p = base + 0x6480;
    if (p != base) {
        do {
            if (*(u16 *)p == 0) goto found;
            p -= 0x10C;
        } while (p != base);
    }
    p = 0;
found:
    if (p != 0) {
        *(u16 *)(a0 + 0xA) = *(u16 *)(a0 + 0xA) | 0x8000;
        func_8012C890((s32)a0, (s32)p, 0);
    } else {
        return 0;
    }
}
