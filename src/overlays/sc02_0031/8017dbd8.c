/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017DBD8 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_801466F0(s32 a0, s32 a1, s32 a2, s32 a3, s32 sp5, s32 sp6, s32 sp7, s32 sp8);
extern void func_80147324(s32 arg0);
extern s32 func_80171990(u8 *a0);

void func_8017DBD8(void *arg0) {
    if (*(u16 *)((s32)arg0 + 0xB8) & 0x4000) {
        *(s32 *)((s32)arg0 + 0x44) |= 0x20000;
        func_801466F0(0x16, (s32)arg0, 0, -0x80, -0x10, 0, 0, 0);
        func_80147324(0x7BC);
        func_80171990((u8 *)arg0);
    }
}
