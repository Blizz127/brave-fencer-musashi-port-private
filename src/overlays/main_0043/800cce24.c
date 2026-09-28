/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCE24 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_8014B5C4(s32 *a0, s32 a1, s32 a2);
extern void func_8013C9C4(void *a0);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3,
                          s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void func_8014C010(s32 *a0, s32 a1);
extern void func_80147324(s32 a0);
extern s32 D_800D3414;

void func_800CCE24(void *a0) {
    s32 s0;

    s0 = (s32)a0;
    func_8014B5C4((s32 *)s0, 2, 0);
    func_8013C9C4(&D_800D3414);
    func_801466F0(5, s0, 0, 0, 0, 0, 0, 1);
    func_8014C010((s32 *)s0, 1);
    func_80147324(0x47D);
}
