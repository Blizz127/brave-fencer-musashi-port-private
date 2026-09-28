/* Main-exec range [80030634,80030730) from the SLUS executable.
 * SHA256(span)=98c4b54bee0d0e860e85eb3d1bbf8773f25c1e4dcb920d00c5a7135ecf95fa21.
 * Word export for the native seam. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"

/* func_80030634 - byte-exact against retail at -O2 (tools/register_match.py). */

extern s32 D_800A46C0;
extern s32 D_800A46C4;
extern s16 D_800A46CC;
extern s16 D_800A46CE[];
extern s16 D_800A4642[];
extern u8  D_800A4650[];
extern s16 func_80042374(s32);
extern s16 func_80042154();

s32 func_80030634(void) {
    s32 t;
    s32 k;
    s16 r;
    s16 *pcc;

    if (func_80042374(0) != 0) {
        t = D_800A46CE[0] * 3;
        k = t << 3;
        r = func_80042154((u8 *)(D_800A46C0 + D_800A46C4), 0x8000,
                           *(s16 *)((u8 *)D_800A4642 + k));
        switch (r) {
        case -2:
            D_800A46C4 = D_800A46C4 + 0x8000;
            break;
        case -1:
            D_800A4650[k] = 1;
            D_800A46CC++;
            break;
        default:
            pcc = &D_800A46CC;
            (*pcc)++;
            break;
        }
    }
    return 0;
}
