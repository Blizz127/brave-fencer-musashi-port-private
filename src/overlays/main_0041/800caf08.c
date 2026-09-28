/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAF08 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern s32 func_80161208();

void func_800CAF08(void *a0) {
    u16 flags;

    flags = *(u16 *)((s32)a0 + 0xB8);
    if (flags == 0x8000) {
        func_801599A4(a0);
        func_80159B3C(a0);
    } else {
        if (flags & 0x4000) {
            func_801466F0(0x26, (s32)a0, 0, -0x40, 0, 0, 0, 0);
        }
        func_80161208(a0);
    }
}
