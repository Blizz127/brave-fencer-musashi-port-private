/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8013CB20 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80195024;
extern s32 D_80195028;
extern s32 D_80195050;
extern s32 D_80195054;

void func_8013CB20(void)
{
    D_80195050 = D_80195028;
    D_80195054 = D_80195024;
    D_80195028 = 1;
    D_80195024 = 0;
}
