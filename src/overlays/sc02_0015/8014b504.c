/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014B504 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8016F1AC(void);
extern s32 D_80078E98;
extern s16 D_80078E9A;

void func_8014B504(u16 *a0) {
    s32 v1;
    if (func_8016F1AC() != 0) {
        return;
    }
    if (*a0 == 0x1E || *a0 == 0x1A) {
        return;
    }
    if ((D_80078E9A & 0x8000) == 0) {
        return;
    }
    v1 = D_80078E98 + 0x1555;
    D_80078E98 = v1;
    if (0x257F6A < (v1 & 0x7FFF0000)) {
        D_80078E98 = 0;
    }
}
