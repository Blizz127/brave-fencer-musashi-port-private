/* Overlay range [80158CD8,80158D60) from MAIN.CD member 0012.
 * SHA256(span)=2e106d30de8537312d94e60a17d1b3845e7cd6aa27e50f72d14f20e9b4a7d250.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_80158CD8 - 34 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern u16 func_801487F4(s32 *a0);
extern s32 func_80146E98(s32 a0);
extern void func_80147324(s32 a0);
extern void func_80146CA0(void *a0);

void func_80158CD8(s32 *a0) {
    s32 i = 1;
    if (func_801487F4(a0) & 0xF0) {
        i = 4;
    }
    while (i > 0) {
        if (func_80146E98((s32)a0)) {
            func_80147324(0x453);
            *(s32 *)((s32)a0 + 0x238) = 0x5B0000;
            func_80146CA0((void *)a0);
            i = 0;
        }
        i--;
    }
}
