/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801576A8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif


void func_801576A8(void *arg0) {
    extern int func_80155FF8(int arg, int a1);
    extern void func_801599A4(void *a0);
    extern void func_80159B3C(void *a0);
    extern s32 func_80161208(void);
    volatile s32 spill[4];  /* forces the 0x28 frame the target reserves */
    *(s32 *)((u8 *)arg0 + 0x44) |= 2;
    if (*(u16 *)((u8 *)arg0 + 0xB8) == 0x8000) {
        func_801599A4(arg0);
        func_80159B3C(arg0);
    } else if (((s32 (*)(void *))func_80161208)(arg0) == 0) {
        func_80155FF8((int)arg0, *(u8 *)((u8 *)arg0 + 0x1AA));
    }
}
