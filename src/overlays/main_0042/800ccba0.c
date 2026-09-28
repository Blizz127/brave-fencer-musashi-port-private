/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCBA0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80149020(s32 *a0);
extern void (*D_800CCD94[])(s32);

void func_800CCBA0(param_1)
s32 param_1;
{
    s32 s0 = param_1;
    s32 idx;
    func_80149020(s0);
    idx = *(u16 *)(s0 + 2) - 2;
    D_800CCD94[idx](s0);
}
