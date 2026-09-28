/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801375EC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80137614(s32 a0, s32 a1, s32 a2);

void func_801375EC(s32 a0, s16 a1) {
    func_80137614(a0, a1, 0);
}
