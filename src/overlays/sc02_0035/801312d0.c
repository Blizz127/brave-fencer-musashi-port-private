/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801312D0 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef struct { char _b[8]; } M8_801312D0;

s32 func_801312D0(s32 param_1, void *param_2)
{
    extern int func_80131CF4(int, int);
    extern M8_801312D0 D_80184988;

    int iVar5;

    iVar5 = func_80131CF4(*(int *)(((int)param_1) + 0xBC), 0x2E);
    if (iVar5 != 0) {
        ((short *)param_2)[2] = 0;
        ((short *)param_2)[0] = 0;
        ((short *)param_2)[1] = (short)iVar5;
    } else {
        *(M8_801312D0 *)((short *)param_2) = D_80184988;
    }
}
