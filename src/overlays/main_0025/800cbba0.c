/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CBBA0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_800CBBF8();
extern s32 func_8014C088(s32 a0, s32 a1);
extern void func_80146C98(s32 *a0, s16 a1);

void func_800CBBA0(s32 param_1) {
    s32 ret;
    ret = func_8014C088(param_1, 0x27);
    if (ret == 0) {
        return;
    }
    if (*(u16 *)(ret + 2) >= 2) {
        func_80146C98((s32 *)ret, 3);
    } else {
        func_800CBBF8();
    }
}
