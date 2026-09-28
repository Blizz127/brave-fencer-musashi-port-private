/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80142D38 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8012BEE8(s32 a0);
extern s32 func_8012BEE8(s32);
extern int func_8012BEE8(int);

s32 func_80142D38(s32 *a0) {
    if (func_8012BEE8((s32)a0) == 1) {
        return 1;
    }
    if (a0[0x1C / 4] & 1) {
        ((s32 *)a0[0x20 / 4])[1] |= 0x80000000;
    } else {
        ((s32 *)a0[0x20 / 4])[1] &= 0x7FFFFFFF;
    }
    return 0;
}
