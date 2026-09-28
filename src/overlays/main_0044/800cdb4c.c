/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CDB4C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146E98(s32 a0);
extern s32 func_80146C3C(void *a0);

void func_800CDB4C(int param_1)
{
    extern unsigned char D_800CEBF4[];
    unsigned char *base;

    base = (unsigned char *)D_800CEBF4 + *(s32 *)(param_1 + 0x2C) * 0x40;
    base[2] = base[2] - 8;
    if (func_80146E98(param_1) != 0) {
        func_80146C3C((void *)param_1);
    }
}
