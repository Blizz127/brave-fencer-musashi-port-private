/* Main-exec range [80030538,80030604) from the SLUS executable.
 * SHA256(span)=15cd8f41b9cac7da6597356ccd0dc4834e9f98e231602b36e7ec5b62d9c3e37c.
 * Word export for the native seam. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_80030538 - byte-exact against retail at -O2 (tools/register_match.py). */

extern s16 D_800A46CC;
extern u8  D_800A4650[];
extern s16 D_800A4642[];
extern s16 D_800A46CE[];
extern s32 D_800A46C0;
extern s32 D_800A46C4;
extern s16 func_80042154();

s32 func_80030538(void) {
    s32 idx;
    s16 ret;

    idx = D_800A46CE[0];
    ret = func_80042154(D_800A46C0 + D_800A46C4, 0x8000, *(s16 *)((u8 *)D_800A4642 + idx * 24));
    switch (ret) {
    case -2: {
        s16 t2 = D_800A46CC + 1;
        s32 t1 = D_800A46C4 + 0x8000;
        D_800A46C4 = t1;
        D_800A46CC = t2;
        goto L_zero;
    }
    case -1:
        D_800A4650[idx * 24] = 1;
        D_800A46CC = D_800A46CC + 2;
        return 1;
    default: {
        s16 *p = &D_800A46CC;
        *p = *p + 2;
        goto L_zero;
    }
    }
L_zero:
    return 0;
}
