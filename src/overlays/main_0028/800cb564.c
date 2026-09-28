/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB564 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_800CB600();
extern s32 func_800CB6D4(s32 a0);

void func_800CB564(int param_1)
{
    if (((int (*)(void))func_800CB6D4)() != 0) {
        ((void (*)(int))func_800CB600)(param_1);
    }
}
