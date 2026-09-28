/* Complete SC02 retail span [80182174,801821F4).
 * SC02 820xx state cluster.
 * Words from pinned SC02.CD member31 PAC0 decode (live-guest identity).
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_80182174 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8013C98C(void);
extern void func_801746DC(void);
extern void func_8013C9C4(void *a0);
extern void func_8012A568(void (*a0)(void));
extern s32 func_80178BF8();
extern void func_80178CBC(s32 arg0, s32 arg1);
extern void func_8002D4C8(s32 a0, s32 a1);

void func_80182174(s32 param_1) {
    extern void (*D_80188F98[])(void);
    extern void (*D_80188EEC[])(void);

    if (*(s16 *)(param_1 + 0xFC) != 0) {
        *(s16 *)(param_1 + 2) = 2;
        *(s32 *)(param_1 + 0x1C) = 0x1E;
        func_80178BF8();
        func_801746DC();
        func_80178CBC(param_1, (s32)&D_80188F98);
        func_8013C98C();
        func_8013C9C4(&D_80188EEC);
        func_8002D4C8(0xAC7, 0);
    }
}
