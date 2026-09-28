/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8017D6C4 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_8017D6C4(arg0)
s32 arg0;
{
    s32 t = *(s32 *)(arg0 + 0x204) - 1;
    *(s32 *)(arg0 + 0x204) = t;
    if (t == -1)
        (*(u8 *)(arg0 + 0x214))++;
}
