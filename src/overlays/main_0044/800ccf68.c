/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCF68 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CCF68(s32 param_1)
{
    extern s32 func_8014C088(s32 a0, s32 a1);
    extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
    s32 ptr;

    ptr = func_8014C088(param_1, 7);
    if (ptr != 0) {
        *(u16 *)(ptr + 0x60) = 1;
    }
    *(u16 *)(param_1 + 0x1C8) = 0;
    func_80146A6C(0x39, (void *)param_1, 0, 0, 0, 0, 0);
}
