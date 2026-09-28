/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_801582C0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern s32 func_80146994(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_80146CA0(void *a0);
extern void func_80147324(s32 arg0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80147324(s32 a0);
extern void func_80154A74(int, int);
extern void func_8016706C(s32 a0);
extern u8 D_800D52A8[];
extern void func_801585A4(s32 *a0);

void func_801582C0(void *a0) {
    s32 s0 = (s32)a0;
    *(s32 *)(s0 + 0x44) = *(s32 *)(s0 + 0x44) | 2;
    *(s8 *)(s0 + 0x1AA) = 0x10;
    func_80154274((s32 *)s0, (s32)D_800D52A8);
    func_80154A74(s0, 0x15);
    func_801585A4((s32 *)s0);
    func_8016706C(5);
    func_80146994(4, s0, 8, 0);
    func_80147324(0x446);
    func_80146CA0((void *)s0);
}
