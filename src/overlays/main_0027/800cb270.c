/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB270 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80078EC1;
extern void (*D_800CC180[])();
extern void func_800CB7FC();

void func_800CB270(int param_1)
{
    if (D_80078EC1 != 24) {
        func_800CB7FC();
    } else {
        D_800CC180[*(u16 *)(param_1 + 2)]();
    }
}
