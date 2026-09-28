/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801575E4 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80154A74(s32 a0, s32 a1);
extern void func_80154274(s32 *a0, s32 a1);
extern void func_80147324(s32 a0);
extern void func_80146E90(s32 *a0, s32 a1);
extern void func_80156648(s32 *a0);
extern s32 func_80146994(s32 a0, s32 a1, s32 a2, s32 a3);
extern void func_8014B768(s32 a0, s32 a1);
extern void func_80147300(u16 arg0);
extern void func_80146CA0(void *a0);
extern u8 D_800D4F14[];
extern s32 D_8011F730;

void func_801575E4(void *a0) {
    s32 v;
    func_80154A74((s32)a0, 0x15);
    v = *(u8 *)((u8 *)a0 + 0x1AB) ^ 1;
    *(u8 *)((u8 *)a0 + 0x1AB) = v;
    if (v != 0) {
        *(u8 *)((u8 *)a0 + 0x1AA) = 0xA;
    } else {
        *(u8 *)((u8 *)a0 + 0x1AA) = 0xB;
    }
    func_80154274((s32 *)a0, (s32)D_800D4F14);
    func_80147324(0x455);
    func_80146E90((s32 *)a0, 0);
    func_80156648((s32 *)a0);
    func_80146994(0x5, (s32)a0, 0, 0);
    func_8014B768((s32)a0, 0x333);
    func_80147300(0x5F3);
    D_8011F730 |= 4;
    func_80146CA0(a0);
}
