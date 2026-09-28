/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801EFB40 - byte-exact against retail at -O2 (tools/register_match.py). */
extern unsigned short D_80115112;
extern u16 D_80115112;

void func_801EFB40(void)
{

    extern unsigned short D_80115112;
    unsigned short *p = &D_80115112;
    *p = *p + 1;
}
