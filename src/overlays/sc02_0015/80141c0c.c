/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80141C0C - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8002D4C8(s32 a0, s32 a1);
extern u16 D_80115110;
extern u8 D_8017F598;

void func_80141C0C(s32 param_1)
{
    func_8002D4C8(*(u16 *)(&D_8017F598 + (((param_1 << 16) >> 15) + (u32)D_80115110) * 2), 0);
}
