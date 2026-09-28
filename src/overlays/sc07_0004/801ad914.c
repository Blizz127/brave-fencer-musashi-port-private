/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AD914 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012B2CC(s32 a0);
extern s32 func_8012C658(s32 a0, s32 a1, s32 a2);
extern void func_800484EC(s32, s32, s32);
typedef struct { u16 a, b, c, d; } Blk8_801AD914;
typedef struct { s32 f10, f14, f18; } S12_801AD914;

void func_801AD914(s32 arg0, void *arg1, s32 arg2) {
    void *sp0;
    S12_801AD914 sp10;
    s32 inner;

    sp0 = (void *)func_8012C658(0x3A1, 1, arg0);
    if (sp0 != NULL) {
        *(Blk8_801AD914 *)(*(s32 *)((s32)sp0 + 0x20) + 0x10) = *(Blk8_801AD914 *)arg1;
        func_8012B2CC((s32)sp0);
        sp10.f18 = 0;
        sp10.f10 = 0;
        sp10.f14 = arg2;
        ((s32 (*)(s32, s32, s32))func_800484EC)(*(s32 *)((s32)sp0 + 0x20) + 0x34, (s32)&sp10, (s32)sp0 + 0x10);
        inner = *(s32 *)((s32)sp0 + 0x20);
        *(u16 *)(inner + 0x1C) = 0x500;
        *(u16 *)(inner + 0x1A) = 0x500;
        *(u16 *)(inner + 0x18) = 0x500;
        *(s32 *)((s32)sp0 + 0x1C) = 0x20;
    }
}
