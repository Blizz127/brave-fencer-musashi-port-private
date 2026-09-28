/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBD2C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CBD54(s32 param_1, s32 *param_2);

void func_800CBD2C(s32 param_1) {
    extern s32 D_800CBFE0;
    func_800CBD54(param_1, &D_800CBFE0);
}
