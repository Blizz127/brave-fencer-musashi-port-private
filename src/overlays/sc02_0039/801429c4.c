/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801429C4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 D_801270C0;
extern void (*D_801807E8[])();

void func_801429C4(int param_1)
{
    if (*(s16 *)&D_801270C0 != 3) {
        D_801807E8[*(u16 *)(param_1 + 2)]();
    }
}
