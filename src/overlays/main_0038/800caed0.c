/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAED0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern u8 D_800CBB44[];

void func_800CAED0(u8 *a0)
{
    func_80154274((s32 *)a0, (s32)D_800CBB44);
    func_80154A74((s32)a0, 0x15);
    a0[0x197] += 1;
}
