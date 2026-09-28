/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801665B4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146C3C();
extern s32 func_80128ED8(s32 param_1, s32 *param_2);
extern void func_800D22E4(s32 a0);

void func_801665B4(s32 *a0)
{
    if (func_80128ED8((void *)a0[8], (void *)(a0 + 9))) {
        func_80146C3C((s32)a0);
    } else {
        func_800D22E4((s32)a0);
        a0[5] -= a0[5] >> 3;
    }
}
