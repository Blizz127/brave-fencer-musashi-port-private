/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_8014C43C - byte-exact against retail at -O2 (tools/register_match.py). */
extern u16 func_80156370(u16 a0);
extern void func_8014C4AC(s32 a0, s32 a1, s32 a2, s16 *a3, s32 a4);

s32 func_8014C43C(void * a0, s32 a1, s32 a2, s32 a3, s16 a4)
{
    u16 v0;
    v0 = func_80156370((u16)a2);
    func_8014C4AC(a1, a2, v0 & 0xFFFF, a3, (s16)a4);
}
