/* Overlay range [801312D0,80131340) from MAIN.CD member 0012.
 * SHA256(span)=caaf5be818fe92bf35e2de6a45178003f1c34861e867895a2c0195baeab96268.
 * Word export for the native seam; the body below is an
 * UNVERIFIED draft, not an oracle match claim. */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801312D0 - byte-exact against retail at -O2 (tools/register_match.py). */
struct M8;
struct M8 { u8 b[8]; };
typedef struct { char _b[8]; } M8;
void *param_2;

s32 func_801312D0(s32 param_1, void *param_2)
{
    extern s32 func_80131CF4(s32);
    extern M8 D_8017E838;

    int iVar5;

    iVar5 = ((int (*)(int, int))func_80131CF4)(*(int *)(((int)param_1) + 0xBC), 0x2E);
    if (iVar5 != 0) {
        ((short *)param_2)[2] = 0;
        ((short *)param_2)[0] = 0;
        ((short *)param_2)[1] = (short)iVar5;
    } else {
        *(M8 *)((short *)param_2) = D_8017E838;
    }
}
