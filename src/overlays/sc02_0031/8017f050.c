/* Complete SC02 retail span [8017F050,8017F124).
 * Live STOP 7ECB0 cluster; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017F050 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern int func_80178970(void);
extern s32 func_8012C658(s32 arg0, s32 arg1, s32 arg2);
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void * a1);
extern void func_8012B14C(s32 a0, s32 a1);

void func_8017F050(s32 a0) {

    extern u8 D_80188A40[];
    s32 p;
    u16 v;
    s32 sp10[3];

    func_80178970();

    v = *(u16 *)(a0 + 0x5E);
    if ((v == 0x9) | (v == 0x11)) {
        p = func_8012C658(0x30, 2, a0);
        if (p == 0) {
            return;
        }
        *(u16 *)(p + 0xA) -= 0x20;
        *(u16 *)(p + 0x16) -= 0x10;
        func_8002D4C8(0x829, 0);

        *(s16 *)(a0 + 0x5E) = 0;
        func_8012A828(a0, D_80188A40);

        sp10[0] = 0;
        sp10[1] = 0xFFF20000;
        sp10[2] = 0x70000;
        func_8012B14C(a0, (s32)sp10);

        *(s32 *)(a0 + 0x48) = 0x10000;
        *(s32 *)(a0 + 0x1C) = 0x40;
        *(s16 *)(a0 + 0x108) = 0;
        *(s16 *)(a0 + 0x2) = 4;
    }
}
