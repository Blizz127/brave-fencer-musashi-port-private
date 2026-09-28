/* Main-exec range [80030470,800304C8) from the SLUS executable.
 * SHA256(span)=cf74af99fc0dc1c651c267e014d5ea880013087db30eecc0cba1b049913bcaf0.
 * Word export for the native seam. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_80030470 - byte-exact against retail at -O2 (tools/register_match.py). */

extern void func_800301A4(void);
extern s32 func_80037CD8(void *arg);
extern s16 D_800A46CC;
extern u8 D_8006AEF4;

s32 func_80030470(void) {
    s16 *p;

    if (func_80037CD8((void *) func_800301A4) != 0) {
        p = &D_800A46CC;
        *p += 1;
        D_8006AEF4 |= 2;
    }
    return 0;
}
