/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EF70C - byte-exact against retail at -O2 (tools/register_match.py). */


s32 func_801EF70C(void)
{
    extern s16 D_801F96B8;
    extern s16 D_801F96BA;
    extern void (*D_801F2A14[])(void);
    D_801F2A14[D_801F96B8]();
    return ((u32)D_801F96BA) >> 31;
}
