/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8012C284 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80126720[];

u16 *func_8012C284(u16 *a0)
{
    u16 *end;
    end = (u16 *)D_80126720;
    if (a0 == 0) {
        a0 = (u16 *)(D_80126720 - 0x6480);
    } else {
        a0 = (u16 *)((u8 *)a0 + 0x10C);
    }
    while (a0 != end) {
        if (*a0 == 0) {
            return a0;
        }
        a0 = (u16 *)((u8 *)a0 + 0x10C);
    }
    return 0;
}
