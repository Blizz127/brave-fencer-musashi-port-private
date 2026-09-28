/* Overlay range [80175218,80175268) from MAIN.CD member 0012.
 * SHA256(span)=a9310ea5c1d153ab964b5b52099eb475cdd8a03a5cc9a4a59a75676ec0663fb6.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80175218 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80078EC0;
extern void func_80146CA0(void *a0);
extern s32 (*D_801819EC[])(void *);

s32 func_80175218(void * param_1)
{

    extern u8 D_80078EC0;
    extern void (*D_80181A10[])(s32);
    s32 i = D_80078EC0 - 1;

    D_80181A10[i](param_1);
    ((void (*)(s32))func_80146CA0)(param_1);
}
