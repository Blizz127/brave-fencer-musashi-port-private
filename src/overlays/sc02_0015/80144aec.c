/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80144AEC - byte-exact against retail at -O2 (tools/register_match.py). */
extern int func_80144B14(int param_1);

void func_80144AEC(s32 *a0) {
    s32 old;
    old = *(s32 *)((s32)a0 + 0xDC);
    *(s32 *)((s32)a0 + 0xDC) = (s32)&func_80144B14;
    *(s16 *)((s32)a0 + 0x0) = 0x83;
    *(s16 *)((s32)a0 + 0x2) = 1;
    *(s32 *)((s32)a0 + 0xCC) = old;
}
