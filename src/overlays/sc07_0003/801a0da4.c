/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A0DA4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801A28AC(s32 a0);
extern void func_8012A828(s32 a0, void *a1);
extern void func_80184C70(void);
extern void func_80184DB0(s32 a0, void *a1, s32 a2);
extern void func_8002D4C8(s32 a0, s32 a1);
extern u8 D_801A6544[];
extern s32 D_801A6B90;

void func_801A0DA4(void *a0) {
    func_801A28AC((s32)a0);
    *(s16 *)((s32)a0 + 2) = 0xC;
    *(u16 *)((s32)a0 + 0x34) = 0;
    *(s32 *)((s32)a0 + 0xE4) = 0x50;
    func_8012A828((s32)a0, D_801A6544);
    func_80184C70();
    func_80184DB0(0, &D_801A6B90, -8);
    *(s32 *)((s32)a0 + 0xE0) &= ~0x4;
    func_8002D4C8(0xC35, 0);
}
