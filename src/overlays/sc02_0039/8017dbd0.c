/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017DBD0 - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_8017DBD0(u32 a0v)
{

    extern u16 D_8019AD38[];
    if (a0v < 0x400) {
        return ((s16 *)D_8019AD38)[0x3FF - a0v];
    }
    if (a0v - 0x400 < 0x400) {
        return (s16)-((s16 *)D_8019AD38)[a0v - 0x400];
    }
    if (a0v - 0x800 < 0x400) {
        return (s16)-((s16 *)D_8019AD38)[0xBFF - a0v];
    }
    if (a0v - 0xC00 < 0x400) {
        return ((s16 *)D_8019AD38)[a0v - 0xC00];
    }
     


}
