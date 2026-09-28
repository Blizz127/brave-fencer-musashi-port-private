/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CD4BC - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80146CA0(void *a0);
extern s32 func_80163408(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80163328();
extern s32 func_801632F0();
extern u16 D_800CD690[];
extern u16 D_800CD692[];
extern s32 func_80146E98(s32 a0);
extern void func_800CD5DC();
extern void func_80163194(s32 a0, s32 a1, s32 a2, s32 a3, s32 a4);
extern void func_80162FC0(s32 *a0);

void func_800CD4BC(s32 arg0) {
    s32 sp18[8];
    s32 temp_s2 = *(s32 *)(arg0 + 0x4C);
    s32 temp_s1 = *(s32 *)(arg0 + 0x20);

    if (func_80146E98(arg0) != 0) {
        func_80146CA0((void *)arg0);
        return;
    }
    *(u16 *)(temp_s1 + 0x28) = D_800CD690[(*(u16 *)(temp_s2 + 0x1C8) & 7) * 2];
    *(u16 *)(temp_s1 + 0x2A) = D_800CD692[(*(u16 *)(temp_s2 + 0x1C8) & 7) * 2];
    func_800CD5DC(arg0, sp18);
    func_80163194(arg0, 0, -0x10000, 0, (s32)sp18);
    func_80162FC0((s32 *)arg0);
    *(u16 *)(temp_s1 + 0x18) = *(u16 *)(temp_s1 + 0x1A) =
        *(u16 *)(temp_s1 + 0x1A) + 0x200;
    func_80163408(arg0, 0x24, 0x80, 4);
    func_80163328(arg0);
    func_801632F0(arg0);
}
