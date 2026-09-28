/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80152194 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_80149020(s32 *a0);
extern void func_80147A84(s32 arg0);
extern void func_801473EC(s32 *a0);
extern void func_80148038(s32 a0, s32 a1);
extern void func_80147460(s32 a0);
extern void func_801470B4(s32 a0);
extern void func_8015369C(s32 a0);
extern void func_80146CA0(void *a0);

void func_80152194(s32 *a0) {
    u8 v1;
    func_80149020(a0);
    func_80147A84((s32)a0);
    func_801473EC(a0);
    func_80148038((s32)a0, 0x4000);
    func_80147460((s32)a0);
    v1 = *((u8 *)a0 + 0xDE);
    *((u8 *)a0 + 0xDE) = v1 + 0xFF;
    if (v1 == 0) {
        func_801470B4((s32)a0);
        func_8015369C((s32)a0);
        func_80146CA0(a0);
    }
}
