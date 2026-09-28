/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013CB20 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_8019FA54;
extern s32 D_8019FA58;
extern s32 D_8019FA80;
extern s32 D_8019FA84;

void func_8013CB20(void)
{
    D_8019FA80 = D_8019FA58;
    D_8019FA84 = D_8019FA54;
    D_8019FA58 = 1;
    D_8019FA54 = 0;
}
