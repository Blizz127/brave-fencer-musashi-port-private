/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB848 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CBBF8();
extern u8 D_80078EC1;
extern void (*D_800CBF2C[])();

void func_800CB848(int param_1)
{
    if (D_80078EC1 != 15) {
        func_800CBBF8();
    } else {
        D_800CBF2C[*(u16 *)(param_1 + 2)]();
    }
}
