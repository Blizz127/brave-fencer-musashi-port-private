/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80141788 - byte-exact against retail at -O2 (tools/register_match.py). */
extern unsigned short D_80115112;
extern u16 D_80115112;
extern void (*D_801804F0[])(void);

void func_80141788(void)
{
    D_801804F0[D_80115112]();
}
