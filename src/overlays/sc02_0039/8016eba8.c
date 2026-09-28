/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8016EBA8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8016EC0C(s32 a0, s32 a1);
extern u16 D_801824BC[];

void func_8016EBA8(u8 *param_1)
{
    u8 c;

    *(u16 *)(param_1 + 4) =
        *(u16 *)(param_1 + 4) - D_801824BC[param_1[2]];
    ((void (*)(u8 *, int))func_8016EC0C)(param_1, 0x80);
    c = param_1[2];
    param_1[2] = c + 0xFF;
    if (c == 0) {
        param_1[0] = 0;
    }
}
