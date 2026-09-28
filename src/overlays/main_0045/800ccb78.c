/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CCB78 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_80147324(s32 a0);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);

void func_800CCB78(void *a0) {
    func_80147324(0x8DF);
    func_801466F0(0x10, (s32)a0, 0, 0, 0, 0, 0, 0);
    func_801466F0(0x11, (s32)a0, 0, 0, 0, 0, 0, 0);
    func_801466F0(0x11, (s32)a0, 0, 0, 0, 1, 0, 0);
    func_801466F0(0x11, (s32)a0, 0, 0, 0, 2, 0, 0);
    *(s16 *)((s32)a0 + 0x1C8) = 0xFF;
    func_801599A4(a0);
    func_80159B3C(a0);
}
