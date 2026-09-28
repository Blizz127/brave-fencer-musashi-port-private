/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80175218 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80078EC0;
extern void func_80146CA0(void *a0);
extern void (*D_801818D4[])(s32);

s32 func_80175218(void * param_1)
{
    s32 i = D_80078EC0 - 1;

    D_801818D4[i](param_1);
    ((void (*)(s32))func_80146CA0)(param_1);
}
