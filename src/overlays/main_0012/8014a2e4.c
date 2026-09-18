/* Overlay range [8014A2E4,8014A380) from MAIN.CD member 0012.
 * SHA256(span)=576180d49ff85e52b39e9aace097fdfcd222b1f18d1ee05b3b1cf44e0b394078.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8014A2E4 - 39 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern u8 D_801202A0[];
extern s32 func_8014C278(s32 a0, s32 a1, s32 a2);

s32 func_8014A2E4(s32 a0) {
    register s32 a0v __asm__("$18");
    register u32 i __asm__("$17");
    register u8 *p __asm__("$16");
    a0v = a0;
    i = 0;
    p = D_801202A0;
    do {
        if (*(u16 *)(p + 0x0) != 0
            && (*(u16 *)(p + 0x5C) & 0x8000)
            && *(s16 *)(p + 0xAA) != 0
            && func_8014C278(a0v, (s32)p, 0x30) != 0) {
            return (s32)p;
        }
        i++;
        p += 0x10C;
    } while (i < 0x60);
    return 0;
}
