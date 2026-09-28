/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBC10 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CBC10(void *arg0) {
    u8 *a0 = (u8 *)arg0;
    a0 = *(u8 **)(a0 + 0x20);
    a0[0x24] -= 4;
    a0[0x25] -= 4;
    a0[0x26] -= 4;
}
