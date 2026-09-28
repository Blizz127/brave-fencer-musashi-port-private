/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80155E30 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern int func_80161208();
extern int func_80155FF8(int arg, int a1);

void func_80155E30(void *a0) {
    extern int func_80155FF8(int arg, int a1);
    extern void func_801599A4(void *a0);
    extern void func_80159B3C(void *a0);
    extern s32 func_80161208(void);
    volatile s32 spill[4];
    *(s32 *)((u8 *)a0 + 0x44) = *(s32 *)((u8 *)a0 + 0x44) | 2;
    if (*(u16 *)((u8 *)a0 + 0xB8) == 0x8000) {
        func_801599A4(a0);
        func_80159B3C(a0);
        return;
    }
    if (((s32 (*)(s32 *))func_80161208)(a0) != 0) {
        return;
    }
    func_80155FF8((int)a0, *(u8 *)((u8 *)a0 + 0x1AA));
}
