/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CC110 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CC110(s32 ot, s32 otz, s32 shift, void *prim, u32 code)
{
    s32 *entry;

    entry = (s32 *)ot + (otz >> shift);
    *(u32 *)prim = (*entry & 0xFFFFFF) | code;
    *entry = (s32)prim & 0xFFFFFF;
}
