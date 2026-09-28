/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801655E4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern u8 D_80078EC1;
extern void func_8014BD60(s32 param_1, s32 param_2);
extern void func_8014BD60(s32 a0, s32 a1);
extern u8 func_80165658(s32 a0, s32 a1);

void func_801655E4(s32 a0) {
    func_8014BD60(a0, func_80165658(a0, D_80078EC1 & 0x7F) & 0x7F);
}
