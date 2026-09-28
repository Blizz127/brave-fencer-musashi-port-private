/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A6D90 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8013240C(s32 a0);
extern void func_80132784(s32 a0, s32 a1, u32 a2);
extern s32 D_801F8888;

void func_801A6D90(void *arg0) {
    if (*(u16 *)((u8 *)arg0 + 0x34) == 0) {
        func_8013240C((s32)&D_801F8888);
        *(u16 *)((u8 *)arg0 + 0x34) += 1;
    }

    func_80132784((s32)arg0, *(s32 *)((u8 *)arg0 + 0x64), 0);
}
