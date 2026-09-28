/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80161D20 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147324(s32 arg0);
extern void func_80147324(s32 a0);
extern void func_80147324();
extern void func_80147324(int arg0);

void func_80161D20(int param_1, u32 param_2)
{

    extern u16 D_80181BF4[];
    if (param_2 < 8) {
        func_80147324(D_80181BF4[param_2]);
    }
    return;
}
