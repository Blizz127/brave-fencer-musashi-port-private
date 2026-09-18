/* Overlay range [8013F1BC,8013F244) from MAIN.CD member 0012.
 * SHA256(span)=e83706c5b7ed6054f55030692fbcfb72277de70db4baf2ca36a4736451b04d7c.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_8013F1BC - 34 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern void func_800D2624(void);
extern short D_800B9A02;
extern unsigned short D_80115114;
extern unsigned short D_80115112;
extern unsigned short D_80115118;

void func_8013F1BC(void) {
    unsigned short *p = &D_80115118;
    if (*p != 0) {
        *p -= 0x10;
        __asm__ __volatile__("" ::: "memory");
        if (*p != 0) {
            return;
        }
    }
    if (D_80115114 == ((unsigned short)D_800B9A02 ^ 1)) {
        func_800D2624();
    } else {
        D_80115112 += 1;
    }
}
