/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80150FD8 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
s32 func_80146994(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern u16 D_800B99DA;

void func_80150FD8(s32 a0) {
    if (D_800B99DA & 7) {
        func_80146994(0x34, a0, 0, 0);
    }
}
