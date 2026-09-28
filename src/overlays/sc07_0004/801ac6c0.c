/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801AC6C0 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_801A3624(s32 target, u16 *cur, s32 step);
extern s32 func_8012BEE8(s32 a0);
extern void func_8012C218(void *a0);
extern s32 func_8012B8A4(s16 *a0);
extern void func_801AA0B4(void *a0);
extern void func_801AA160(s32 arg0, s32 arg1);
extern void func_801AA3CC(s32 arg0);
extern void func_8012AD80(s32 a0);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern u16 D_800B99DA;

void func_801AC6C0(s32 arg0) {
    s32 s0;
    s32 s1;

    s0 = arg0;
    s1 = (*(s16 *)((s8 *)s0 + 6)) * (*(s16 *)((s8 *)s0 + 6))
       + (*(s16 *)((s8 *)s0 + 0xE)) * (*(s16 *)((s8 *)s0 + 0xE));
    if (func_8012BEE8(s0) != 0 || s1 > 0x100000) {
        func_8012C218((void *)s0);
    } else {
        func_801A3624((s32)(s16)func_8012B8A4((s16 *)s0),
                      (u16 *)(*(s32 *)((s8 *)s0 + 0x20) + 0x12), 0x10);
        func_801AA0B4(s0);
        func_801AA160(s0, D_800B99DA & 1);
        func_801AA3CC(s0);
        func_8012AD80(s0);
        func_8012C658(0xD, 3, s0);
    }
}
