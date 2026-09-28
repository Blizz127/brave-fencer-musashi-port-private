/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB840 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CB840(s32 param_1) {
    *(s32 *)(param_1 + 0x4) += *(s32 *)(param_1 + 0x10);
    *(s32 *)(param_1 + 0x8) += *(s32 *)(param_1 + 0x14);
    *(s32 *)(param_1 + 0xC) += *(s32 *)(param_1 + 0x18);
}
