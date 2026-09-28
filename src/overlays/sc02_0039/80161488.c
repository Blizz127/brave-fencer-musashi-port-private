/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80161488 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_801615C4(void *a0, s32 a1);
extern s32 func_80161774(int param_1, u32 param_2);
extern s32 func_8016197C(s32 a0, s32 a1);

s32 func_80161488(void *a0) {
    s32 v0 = func_801615C4(a0, 0);
    if (*(u8 *)((u8 *)a0 + 0x1C6) == 0) {
        func_80161774(a0, v0);
    } else {
        return func_8016197C((s32)a0, v0) & -0x8;
    }
     
}
