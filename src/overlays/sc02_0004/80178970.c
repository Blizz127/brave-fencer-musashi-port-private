/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80178970 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_801789AC(s32 arg0);
extern s16 D_80196350;

int func_80178970(void)
{
    register int r __asm__("$2");
    int v;

    v = ((s32 (*)(void))func_801789AC)();
    r = 0;
    if (v != 0)
        r = D_80196350 == 0;
    return r;
}
