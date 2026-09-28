/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016DA30 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8016DBD8(u8 *a0);
extern void (*D_80180FD8[])(int);

void func_8016DA30(int param_1)
{
    ((void (*)(void))func_8016DBD8)();
    D_80180FD8[*(unsigned short *)(param_1 + 2)](param_1);
}
