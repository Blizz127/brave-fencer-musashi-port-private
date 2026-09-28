/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD848 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80012F74(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80012F74(s32, s32, s32, s32);

void func_800CD848(s32 param_1) {
    *(s16 *)(*(s32 *)(param_1 + 0x20) + 0x18) =
        *(s16 *)(*(s32 *)(param_1 + 0x20) + 0x1A) =
        func_80012F74(*(s16 *)(*(s32 *)(param_1 + 0x20) + 0x1A), 0x1000, 4, 1);
}
