/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80149544 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012F14C(s32 a0, s32 a1, s32 a2);
extern void func_8012EF70(s32 a0, s32 a1);

void func_80149544(s32 arg0, s32 arg1, s32 arg2) {
    s32 sp10[2];
    ((void(*)(s32,s32,s32))func_8012F14C)(*(s32 *)(arg0 + 0x20) + 0x34, arg1, (s32)sp10);
    func_8012EF70((s32)sp10, arg2);
}
