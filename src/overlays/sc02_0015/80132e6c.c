/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80132E6C - byte-exact against retail at -O2 (tools/register_match.py). */
#define Square0 func_80049324
extern void Square0(s32 *a0, s32 *a1);
extern s16 D_80126CB0;
extern s16 D_80126CAC;

s32 func_80132E6C(s16 *a0) {
    s32 in[3];
    s32 out[3];
    in[0] = a0[3] - D_80126CAC;
    in[1] = 0;
    in[2] = a0[7] - D_80126CB0;
    Square0(in, out);
    return out[0] + out[2];
}
