/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAF18 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3,
                          s32 a4, s32 a5, s32 a6, s32 a7);
extern s32 func_80161208();

void func_800CAF18(void *a0) {
    u16 flag;

    flag = *(u16 *)((u8 *)a0 + 0xB8);
    if (flag == 0x8000) {
        func_801599A4(a0);
        func_80159B3C(a0);
    } else {
        if (flag & 0x4000) {
            func_801466F0(0x20, (s32)a0, 0, -0x40, 0, 0, 0, 0);
        }
        if (func_80161208(a0) == 0) {
            *(u32 *)((u8 *)a0 + 0x44) |= 2;
        }
    }
}
