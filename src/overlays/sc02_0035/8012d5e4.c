/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012D5E4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s16 D_80126B98;
extern s32 func_8012DEB8(s32 a0, s32 a1, s32 a2);

s32 func_8012D5E4(s32 a0, s32 a1, s32 a2, s32 a3) {
    if (func_8012DEB8(a0, a1, a2) != 0) {
        D_80126B98 = a3;
        return 1;
    }
    return 0;
}
