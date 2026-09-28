/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80173A28 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 D_8012750C;
extern void func_80173A60(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);

void func_80173A28(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5) {
    func_80173A60(a0, a1, a2, a3, a4);
    D_8012750C = a5;
}
