/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_800CAF24 - byte-exact against retail at -O2 (tools/register_match.py). */


void func_800CAF24(void *a0) {
    extern void func_801599A4(void *a0);
    extern void func_80159B3C(void *a0);
    extern s32 func_80161208();
    extern s32 func_80155FF8(s32 a0, s32 a1);
    extern s32 func_80146608(s32 a0, s32 a1, s32 a2, s32 a3, s16 a4, s32 a5, s32 a6, s32 a7, s32 a8);
    u16 flag;
    *(s32 *)((u8 *)a0 + 0x44) |= 2;
    flag = *(u16 *)((u8 *)a0 + 0xB8);
    if (!(flag & 0x4000)) {
        if (flag == 0x8000) {
            func_801599A4(a0);
            func_80159B3C(a0);
            return;
        }
    } else {
        func_80146608(0x21, (s32)a0, 0, -0x18, 0, 0, 0, 8, 1);
    }
    if (func_80161208(a0) == 0) {
        func_80155FF8((s32)a0, *(u8 *)((u8 *)a0 + 0x1AA));
    }
}
