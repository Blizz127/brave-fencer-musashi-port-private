/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80146360 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_80126B58;
extern void (*D_80185FC0[])(void *);
extern u8 D_80126BA4;

void func_80146360(void)
{
     


    extern s32 D_80126B58;
    D_80185FC0[D_80126BA4](&D_80126B58);
}
