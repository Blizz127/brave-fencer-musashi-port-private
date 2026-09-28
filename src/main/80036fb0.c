/* Main-exec range [80036FB0,80037004) from the SLUS executable.
 * SHA256(span)=9f0ac1fa75fe1f713fb010f1ea046a09060bec5ba909c9e75ae9867d4732329e.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80036FB0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"

void func_80036FB0(s32 arg0, s32 arg1) {
    extern s32 D_8006AEE8;
    extern s32 D_80078F10;
    double hole;
    s32 count;
    s32 i;
    s32 *p;

    __asm__ volatile("" ::
                     "m"(hole));
    if (D_8006AEE8 > 0) {
        i = 0;
        count = D_8006AEE8;
        p = &D_80078F10;
        do {
            if (*p == arg0) {
                *p = arg1;
            }
            p++;
            i++;
        } while (i < count);
    }
}
