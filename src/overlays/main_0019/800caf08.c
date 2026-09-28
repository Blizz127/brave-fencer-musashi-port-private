/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAF08 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80154274(void *a0, void *a1);
extern s32 func_80161208();
extern s32 func_800CB170(s32 a0);
extern void func_80147324(s32 a0);
extern void func_80162CCC();
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern u8 D_800CC0D8[];
extern s32 D_8011F9D0;

void func_800CAF08(u8 *arg0) {
    u16 *p;

    if (func_80161208() != 0) {
        func_800CB170((s32)arg0);
        return;
    }
    if (*(u16 *)(arg0 + 0xB8) != 0x8000) {
        return;
    }
    func_80147324(0x479);
    func_80154274(arg0, D_800CC0D8);
    *(u8 *)(arg0 + 0xBE) = 0x10;
    *(u8 *)(arg0 + 0x197) = *(u8 *)(arg0 + 0x197) + 1;
    p = (u16 *)&D_8011F9D0;
    if (p < (u16 *)((s32)&D_8011F9D0 + 0x820)) {
        do {
            if (*p == 4) {
                func_80162CCC(p);
            }
            if (*p == 0xF) {
                func_80162CCC(p);
            }
            p += 0x34;
        } while (p < (u16 *)((s32)&D_8011F9D0 + 0x820));
    }
    func_801466F0(4, (s32)arg0, 0, -0x18, -0xF, 0, 0, 1);
    func_801466F0(4, (s32)arg0, 0, -0x18, -0xF, 1, 0, 1);
    func_801466F0(4, (s32)arg0, 0, -0x18, -0xF, 2, 0, 1);
    func_801466F0(4, (s32)arg0, 0, -0x18, -0xF, 3, 0, 1);
    func_801466F0(0xF, (s32)arg0, 0, -0x18, -0xF, 0, 0, 0);
}
