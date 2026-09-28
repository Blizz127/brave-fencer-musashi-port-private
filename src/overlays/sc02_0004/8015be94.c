/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8015BE94 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern void func_80161124(void *a0);

s32 func_8015BE94(s32 *a0)
{
        ((void (*)(s32 *))func_80161124)(a0);
        ((s32 (*)(s32))func_80146CA0)((s32)a0);
    }
