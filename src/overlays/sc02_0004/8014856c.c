/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014856C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80126B58;
extern void func_801485B8(s32 a0, s32 a1, s32 a2);
extern s32 func_80154358(void *a0);

void func_8014856C(s32 a0, s32 a1) {
    s32 v0 = func_80154358(&D_80126B58);
    func_801485B8(v0 - 0x8, a0, a1);
}
