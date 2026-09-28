/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80155EA4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80147AD4(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_801473EC(s32 *a0);
extern void func_8014C010(s32 a0, s32 a1);
extern int func_80155FF8(int arg, int a1);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern s32 func_80161208();
extern u16 D_800B99DA;

void func_80155EA4(void *arg0) {
    volatile s32 spill[4];  /* forces the 0x28 frame the target reserves */
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
