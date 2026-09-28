/* Main-exec range [80038A00,80038A58) from the SLUS executable.
 * SHA256(span)=94315ba671b19e37c5ac31e76a55cd302556d6dd80f30f66c106693f1a272e5c.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80038A00 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

extern u8 *D_800762B0;
extern u8 D_800762B4[];

s32 func_80038A00(void) {
    u8 *ptr1 = D_800762B0;
    u8 *ptr2 = D_800762B4;
    s32 i = 0;

    while (i < 0x10) {
        if (*ptr1 == 0x2 && *ptr2 == 0) {
            return i;
        }
        i++;
        ptr1++;
        ptr2++;
    }
    return -1;
}
