/* Overlay range [8012CE2C,8012CEB0) from MAIN.CD member 0012.
 * SHA256(span)=fb3347e953cba5365a4c9257b661d7b8c0f70d83222652c0281290d54384f15a.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8012CE2C - 33 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern s32 func_80133784(s32 a0, void *a1, s32 a2);

s32 func_8012CE2C(s32 a0) {
    short a[4];
    short b[4];
    s32 pa, pb;
    a[0] = *(u16 *)(a0 + 0x6);
    a[1] = *(u16 *)(a0 + 0xA);
    a[2] = *(u16 *)(a0 + 0xE);
    pa = (s32)a;
    pb = (s32)b;
    __builtin_memcpy((void *)pb, (void *)pa, 8);
    b[1] += 8;
    func_80133784(1, a, pb);
    return a[1] == b[1];
}
