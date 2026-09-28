/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CB17C - byte-exact against retail at -O2 (tools/register_match.py). */
struct S;

s32 func_800CB17C(struct S *a0) {
    extern void func_8012A304(s32 a0, s32 a1);
    extern void func_801477E8(s32 a0, s32 a1);
    extern void func_80154274(s32 *a0, s32 a1);
    extern void func_80147324(s32 a0);
    extern void func_8014C010(s32 a0, s32 a1);
    extern void func_801483E8(s32 a0);
    extern void func_80019064(void *a0);
    extern s32 D_800CB1F4[];
    extern u8 D_80062BD0[];
    s32 s0 = (s32)a0;

    func_8012A304(*(s16 *)(s0 + 0xA), 0x80);
    func_801477E8(s0, 0xFFE80000);
    func_80154274((s32 *)s0, (s32)D_800CB1F4);
    func_80147324(0x47A);
    func_8014C010(s0, 2);
    func_801483E8(s0);
    func_80019064(D_80062BD0);
}
