/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016345C - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 func_80156370(u16 a0);
extern u16 func_80156370(u16 param_1);
extern void func_80163534(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, u16 * a5);

void func_8016345C(s32 a0, u16 a1, s32 a2, u16 a3, s32 a4) {
    s32 r;
    r = func_80156370(a1);
    func_80163534(a0, a1, (u16)r, a2, a3, a4);
}
