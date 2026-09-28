/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801E34B4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_801E9E38;
extern s32 D_801E9E3C;

void func_801E34B4(s32 param_1) {
    extern s32 D_801E9E38;
    extern s32 D_801E9E3C;
    s32 ptr1 = D_801E9E38;
    s32 ptr2 = D_801E9E3C;

    *(s16 *)(param_1 + 0xFC) = 0;
    *(s16 *)(ptr1 + 0xFC) = 0;
    *(s16 *)(ptr2 + 0xFC) = 0;
}
