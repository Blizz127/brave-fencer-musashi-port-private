/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAF84 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CAFBC();
extern s32 func_80161104(s32 a0);

void func_800CAF84(int param_1)
{
    if (((int (*)(void))func_80161104)() != 0) {
        ((void (*)(int))func_800CAFBC)(param_1);
    }
}
