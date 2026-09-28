/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_801A9270 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern int func_8005C49C(void);
extern void func_801439C0(u8 *a0);
extern void func_8012AD44(s32 *a0, s16 a1);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern void func_8002D4C8(s32 a0, s32 a1);
extern s16 D_801F8E98;

void func_801A9270(void *a0) {
    s32 p;
    s32 t;
    s32 g;

    t = (func_8005C49C() & 7) + 0x50;
    p = *(s32 *)((s32)a0 + 0xD0);
    *(s32 *)((s32)a0 + 0x1C) = t;
    if (p != 0) {
        func_801439C0((u8 *)p);
    }
    func_8012AD44((s32 *)a0, 2);
    func_8012C658(0x44, 1, (s32)a0);
    g = D_801F8E98;
    *(u16 *)((s32)a0 + 6) = *(u16 *)((s32)a0 + 6) - 0x20;
    if (g == 0) {
        func_8002D4C8(0xABD, 0);
    }
    D_801F8E98 = D_801F8E98 + 1;
}
