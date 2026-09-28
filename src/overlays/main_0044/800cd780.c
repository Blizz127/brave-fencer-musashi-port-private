/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD780 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80015954(s32 a0, s32 a1);

void func_800CD780(s32 param_1) {
    func_80015954(param_1 + 0x58, param_1 + 4);
}
