/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBA74 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80078EC1;
extern void (*D_800CBEE0[])();
extern void func_80146C3C();

void func_800CBA74(int param_1)
{
    if (D_80078EC1 != 21) {
        func_80146C3C();
    } else {
        D_800CBEE0[*(u16 *)(param_1 + 2)]();
    }
}
