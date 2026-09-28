/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAED0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80154274(s32 *a0, s32 a1);
extern void func_801655E4(s32 a0);
extern void func_80156648(s32 *a0);
extern u8 D_800CB858;

void func_800CAED0(u8 *a0) {
    func_80154274((s32 *)a0, (s32)&D_800CB858);
    func_801655E4((s32)a0);
    func_80156648((s32 *)a0);
    *(u8 *)(a0 + 0x1AA) = 1;
    *(u8 *)(a0 + 0x197) = *(u8 *)(a0 + 0x197) + 1;
}
