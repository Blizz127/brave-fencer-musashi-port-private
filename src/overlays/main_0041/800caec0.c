/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAEC0 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef s32 M2C_UNK;
extern void func_80154274(s32 *a0, s32 a1);
extern void func_801655E4(s32 a0);

void func_800CAEC0(u8 *a0) {
    extern M2C_UNK D_800D57F4;

    func_80154274((s32 *)a0, &D_800D57F4);
    func_801655E4((s32)a0);
    *(u8 *)(a0 + 0x197) = *(u8 *)(a0 + 0x197) + 1;
}
