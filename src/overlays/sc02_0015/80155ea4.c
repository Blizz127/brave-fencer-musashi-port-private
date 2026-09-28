/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
#include "psx_types.h"
/* func_80155EA4 - byte-exact against retail at -O2 (tools/register_match.py). */
extern void func_801473EC(s32 *a0);
extern void func_80147AD4(s32 arg0, s32 arg1, s32 arg2, s32 arg3);
extern void func_80147AD4(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern u16 D_800B99DA;
extern int func_80161208();
extern int func_80155FF8(int arg, int a1);
extern s32 func_80161208();

void func_80155EA4(void *arg0) {
    volatile s32 spill[4];   
    *(s32 *)((u8 *)arg0 + 0x44) |= 2;
    func_80147AD4((s32)arg0, 0, 0, 0x8000);
    func_801473EC((s32 *)arg0);
    if ((D_800B99DA & 3) == 0) {
        func_8014C010((s32)arg0, 2);
    }
    func_80155FF8((int)arg0, *(u8 *)((u8 *)arg0 + 0x1AA));
    if ((*(s32 *)((u8 *)arg0 + 0x2C) >= 0) || (*(u8 *)((u8 *)arg0 + 0x1C0) != 0)) {
        func_801599A4(arg0);
        func_80159B3C(arg0);
    } else {
        ((void (*)(void *))func_80161208)(arg0);
    }
}
