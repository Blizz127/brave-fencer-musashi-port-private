/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCDC8 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CCDC8(s32 *param_1)
{
    s32 v1;
    s32 v0;

    if (func_800CD240() != 0) return;
    func_800CD288(param_1);
    if (func_800CD494(param_1) != 0) return;
    v0 = func_800CD5CC(param_1);
    if (v0 != 0)
        func_800CD6A4(param_1, v0);
    v1 = func_801612B8(param_1, 0);
    if ((v1 & 0x4000) != 0) {
        func_800CCFA8(param_1);
        return;
    }
    if (v1 == 0 || v1 == 0x8000) {
        func_801477E8(param_1, 0);
        func_80146CA0(param_1);
        return;
    }
    if (func_801496D4(param_1) != 0) {
        func_800CCEB8(param_1);
        return;
    }
    func_801483E8(param_1);
    *(s32 *)((u8 *)param_1 + 0x44) |= 0x1000;
}
