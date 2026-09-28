/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAE8C - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80165910(void);
extern void func_801655E4(s32 a0);
extern s32 func_80146A6C(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);

s32 func_800CAE8C(s32 arg0)
{
    s32 v;
    if (func_80165910() == 0) {
        func_801655E4(arg0);
    }
    func_80146A6C(0x4B, arg0, 0, 0, 0, 0, 0);
    v = *(u8 *)((s32)arg0 + 0x197) + 1;
    *(u8 *)((s32)arg0 + 0x197) = v;
    return v;
}
