/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBC14 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146E98(s32);
extern void func_80146E90(s32 *, s32);
extern s32 func_80146E98(s32 a0);
extern void func_80146E90(s32 *a0, s32 a1);

void func_800CBC14(s32 arg0) {
    extern void func_800CBD2C(s32 param_1);
    extern void func_800CBEB0(s32 a0);
    extern s32 func_80146E98(s32 a0);
    extern void func_80146E90(s32 *a0, s32 a1);

    func_800CBD2C(arg0);
    func_800CBEB0(arg0);
    if (func_80146E98(arg0) != 0) {
        *(s32 *)(arg0 + 0x10) >>= 2;
        *(s32 *)(arg0 + 0x14) >>= 2;
        *(s32 *)(arg0 + 0x18) >>= 2;
        func_80146E90((s32 *)arg0, 0x40);
        *(u16 *)(arg0 + 0x2) += 1;
    }
}
