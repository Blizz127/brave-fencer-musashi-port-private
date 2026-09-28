/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80158344 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern s32 func_80161208();
extern s32 func_801585AC(s32 *a0);
extern void func_80156648(s32 *a0);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80147324(s32 a0);
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80146CA0(void *a0);
extern void func_801599A4(void *a0);
extern void func_80159B3C(void *a0);
extern int func_80155FF8(int arg, int a1);
extern u8 D_800D52E8[];

void func_80158344(s32 *a0) {
    volatile s32 spill[4];
    *(s32 *)((s32)a0 + 0x44) |= 2;
    if (func_80161208() == 0) {
        if (func_801585AC(a0) != 0) {
            func_80156648(a0);
            *(s8 *)((s32)a0 + 0x1AA) = 0x11;
            func_80154274(a0, (s32)D_800D52E8);
            *(s32 *)((s32)a0 + 0x234) = 0;
            func_80147324(0x455);
            func_80146994(4, (s32)a0, 9, 0);
            func_80146994(5, (s32)a0, 0xD, 0);
            func_80146E90(a0, 0x12C);
            func_80146CA0(a0);
        }
        if (*(u16 *)((s32)a0 + 0xB8) & 0x8000) {
            func_801599A4(a0);
            func_80159B3C(a0);
        } else {
            func_80155FF8((int)a0, *(u8 *)((s32)a0 + 0x1AA));
        }
    }
}
