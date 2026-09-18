/* Overlay range [8013A8FC,8013A9B4) from MAIN.CD member 0012.
 * SHA256(span)=6c7e34d58f42f98e0d613b261ef29c6f62085e5bdf597696de09f8dfcb005842.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8013A8FC - 46 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern u8 D_8011DA80[];
extern void func_8013A9B4(s32 a0, s32 a1);

s32 func_8013A8FC(s32 arg0) {
    s32 p;
    s32 i;
    s32 v1;
    if (*(u16*)(arg0 + 0x18) == 0) {
        return 1;
    }
    if (*(s32*)(arg0 + 0x40) == 0) {
        i = 0;
        do {
            if (*(s16*)(i + (s32)D_8011DA80) == 0) {
                p = i + (s32)D_8011DA80;
                goto post;
            }
            i += 0x10;
        } while (i < 0x20);
        i = 0;
        p = i;
    post:
        if (p != 0) {
            v1 = *(u16*)(arg0 + 0x18);
            if (v1 < 7) {
                if (v1 != 0) {
                    func_8013A9B4(arg0, p);
                    return 1;
                }
            }
        }
    }
    return 0;
}
