/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012A79C - byte-exact against retail at -O2 (tools/register_match.py). */
#define ratan2 func_8004CFEC
extern s32 ratan2(s32 a0, s32 a1);

s16 func_8012A79C(s16 *a0, s16 *a1) {
    s16 x0 = a0[0];
    s16 x1 = a1[0];
    s16 y0 = a0[2];
    s16 y1 = a1[2];
    return ratan2(x0 - x1, y0 - y1);
}
