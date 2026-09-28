/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801757E0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80176734(s32 a0);
extern void func_80176218(s32 a0);
extern void func_80176D00(s32 a0);

void func_801757E0(s32 a0) {
    s32 v = (s16)a0;
    func_80176734(v);
    func_80176218(v);
    func_80176D00(v);
}
