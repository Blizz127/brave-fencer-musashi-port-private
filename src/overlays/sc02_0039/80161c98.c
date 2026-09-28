/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80161C98 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 a0);
extern void func_80147324();
extern u16 D_80181BD4[];

void func_80161C98(int param_1, u32 param_2)
{
    if (param_2 < 8) {
        func_80147324(D_80181BD4[param_2]);
    }
    return;
}
