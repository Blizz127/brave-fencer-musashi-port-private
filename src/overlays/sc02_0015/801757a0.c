/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801757A0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80175DA8(s32 a0);
extern void func_80175AB8(s32 a0);
extern void func_80176144(s32 a0);

void func_801757A0(s32 a0) {
    s32 v = (s16)a0;
    func_80175DA8(v);
    func_80175AB8(v);
    func_80176144(v);
}
