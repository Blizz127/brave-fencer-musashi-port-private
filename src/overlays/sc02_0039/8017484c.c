/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017484C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_8016F0AC();
extern s32 D_80126B9C;

void func_8017484C(s32 a0) {
    func_8016F0AC(a0);
    D_80126B9C &= 0xFBFFFFFF;
}
