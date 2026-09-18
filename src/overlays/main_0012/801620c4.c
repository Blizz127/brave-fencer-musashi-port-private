/* Overlay range [801620C4,80162120) from MAIN.CD member 0012.
 * SHA256(span)=69acdf05dc67f84037a78114909c2bc6155b2247857f9b3d2dc3cf5d27b2f1e2.
 * Word export for the native seam; the C body below is kept
 * byte-identical (wrap only, no rewrite): the cleaned Druthulu/BFM-decomp
 * form (vendor/bfm-decomp, same SLUS-00726 build), re-verified against
 * retail at the recorded optimization by tools/match_function.py. */
#include "psx_types.h"
#include "m2c_macros.h"

/* func_801620C4 - 23 words. Promoted from vendor/bfm-decomp
 * (Druthulu, same SLUS-00726 build), split to an address-named file.
 * Values and locals are the loosest that reproduce the bytes; they
 * are not evidence of the original declaration. */
extern int func_800291DC(int);
extern int func_800D0E30(void *a0);

int func_801620C4(void) {
    short local;
    int lo;
    local = func_800291DC(8) & 0x7FFF;
    local = func_800D0E30(&local);
    lo = *(unsigned char *)&local;
    return (short)(*((unsigned char *)&local + 1) * 100 + lo);
}
