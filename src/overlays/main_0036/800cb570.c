/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB570 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146CA0(void *a0);
extern s32 func_80146E98(s32);
extern s32 func_80146CA0(void *);
extern s32 func_80146E98(s32 a0);

void func_800CB570(int param_1)
{
    if (((int (*)(void))func_80146E98)() != 0) {
        ((void (*)(int))func_80146CA0)(param_1);
    }
}
