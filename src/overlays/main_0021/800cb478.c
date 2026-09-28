/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB478 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);

void func_800CB478(s32 param_1)
{
    extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
    extern void func_80146C3C();
    extern u8 D_80078EC1;
    s32 a1;
    s32 counter;

    a1 = *(s32 *)(param_1 + 0x34);
    if (D_80078EC1 == 2) {
        counter = *(s32 *)(param_1 + 0x1c) - 1;
        *(s32 *)(param_1 + 0x1c) = counter;
        if (counter == -1) {
            func_80146A6C(0x21, (void *)a1, 0, 0, 0, 0x8000, 0);
            *(s32 *)(param_1 + 0x1c) = 0x20;
        }
    } else {
        func_80146C3C(param_1);
    }
}
