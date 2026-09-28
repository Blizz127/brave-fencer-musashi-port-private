/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A10B0 - byte-exact against retail at -O2 (tools/register_match.py). */
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
extern void func_8012B23C(s32 a0);
extern void func_8017F184(void);
extern s32 func_8012C658(s32 a0, s32 a1, s32 a2);
extern u8 D_801F0478[];

void func_801A10B0(void *a0) {
    func_801A28AC((s32)a0);
    *(s16 *)((s32)a0 + 0x2) = 0xE;
    *(u16 *)((s32)a0 + 0x34) = 0;
    *(s32 *)((s32)a0 + 0xE4) = 0x50;
    func_8012A828((s32)a0, D_801F0478);
    func_8012B23C((s32)a0);
    *(s32 *)((s32)a0 + 0x14) = 0xFFE00000;
    func_8017F184();
    func_8012C658(0x34C, 4, (s32)a0);
}
