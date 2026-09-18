/* Overlay range [80178744,801787D4) from MAIN.CD member 0012.
 * SHA256(span)=b3a12e4bd639082008c908b1d91e5619f8bf79d6f47baf9b8b813f85676a8d25.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80178744 - 36 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_80178744(s32 a0, s32 a1);

void func_80178744(s32 a0, s32 a1) {
    s32 v0;
    s16 sv;
    if (*(s32 *)(a0 + 0x6C) != 0) {
        func_80178744(*(s32 *)(a0 + 0x6C), a1);
    }
    v0 = *(s32 *)(a0 + 0x20);
    sv = a1;
    *(s16 *)(v0 + 0x1C) = sv;
    *(s16 *)(v0 + 0x1A) = sv;
    *(s16 *)(v0 + 0x18) = sv;
    if (a1 == 0x1000) {
        s32 v1 = *(s32 *)(a0 + 0x20);
        *(u16 *)(v1 + 0x2C) = *(u16 *)(v1 + 0x2C) & 0xFFEF;
    } else {
        s32 v1 = *(s32 *)(a0 + 0x20);
        *(u16 *)(v1 + 0x2C) = *(u16 *)(v1 + 0x2C) | 0x10;
    }
}
