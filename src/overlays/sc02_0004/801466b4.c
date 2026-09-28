/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801466B4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);

void func_801466B4(u16 a0, s32 a1, s32 a2, s32 a3, s32 arg5) {
    func_801466F0(a0, a1, 0, 0, 0, a2, a3, arg5);
}
