/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAEE0 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80154274(void *a0, void *a1);
extern void func_80154A74(s32 a0, s32 a1);
extern void func_80147324(s32 a0);
extern void func_801655E4(void *a0);
extern void func_80156648(s32 *a0);
extern void func_800CB054(void *a0);
extern void func_80019064(void *a0);

void func_800CAEE0(u8 *a0) {
    extern u8 D_800CB830[];
    extern u8 D_80062BD0;

    func_80154274(a0, D_800CB830);
    func_80154A74((s32)a0, 0x15);
    func_80147324(0x477);
    func_801655E4(a0);
    *(u8 *)(a0 + 0xBE) = 0;
    *(u8 *)(a0 + 0xBF) = 0;
    func_80156648((s32 *)a0);
    *(u8 *)(a0 + 0x1AA) = 0;
    func_800CB054(a0);
    func_80019064(&D_80062BD0);
    *(u8 *)(a0 + 0x197) = *(u8 *)(a0 + 0x197) + 1;
}
