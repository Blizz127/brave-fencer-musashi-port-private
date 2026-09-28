/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80136C54 - byte-exact against retail at -O2 (tools/register_match.py). */
extern unsigned short D_800B99F0;
extern void (*D_8017F6A8[])(void);

void func_80136C54(void)
{
    D_8017F6A8[D_800B99F0]();
}
