/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017DB14 - byte-exact against retail at -O2 (tools/register_match.py). */


s16 func_8017DB14(u32 a0)
{

    extern u16 D_8019AD38[];
    if (a0 < 0x400) {
        return D_8019AD38[a0];
    }
    if (a0 - 0x400 < 0x400) {
        return D_8019AD38[0x7FF - a0];
    }
    if (a0 - 0x800 < 0x400) {
        return -D_8019AD38[a0 - 0x800];
    }
    if (a0 - 0xC00 < 0x400) {
        return -D_8019AD38[0xFFF - a0];
    }
}
