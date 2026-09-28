/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAEC0 - byte-exact against retail at -O2 (tools/register_match.py). */
typedef s32 M2C_UNK;
extern M2C_UNK D_800CB26C;
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80146DE8(s32 *a0, s32 a1, s32 a2, s32 a3);
extern void func_801477E8(s32 *a0, s32 a1);
extern void func_801655E4(s32 a0);
extern void func_80156648(s32 *a0);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);

void func_800CAEC0(u8 *a0) {
    func_80154274((s32 *)a0, (s32)&D_800CB26C);
    func_80146DE8((s32 *)a0, 0, 0, 0xFFEE0000);
    func_801477E8((s32 *)a0, 0xFFF40000);
    func_801655E4((s32)a0);
    func_80156648((s32 *)a0);
    a0[0x1AA] = 1;
    func_801466F0(0x18, (s32)a0, 0, 0, 0, 0, 0, 1);
    a0[0x197] = a0[0x197] + 1;
}
