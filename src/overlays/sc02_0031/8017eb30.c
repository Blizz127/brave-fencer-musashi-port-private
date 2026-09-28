/* Complete SC02 retail span [8017EB30,8017ECB0).
 * Live STOP 7E39C; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017EB30 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern void func_8002D4C8(s32 a0, s32 a1);
extern void func_8012A828(s32 a0, void * a1);
extern void func_8012AD80(s32 a0);
extern s32 func_8012E778(int param_1, int param_2);
extern s32 func_801439C0(s32 a0);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern int func_80178970(void);
extern void func_8012CBA4(s32 a0);
extern void func_8012CBF4(s32 a0);
extern void func_8012B200(u8 *a0);

void func_8017EB30(s32 a0) {

    extern u8 D_80188950[];
    s32 v1;
    s32 v0;
    s32 p;

    func_80178970();

    if (*(s16 *)(a0 + 0x108) < 0x10) {
        if (*(s16 *)(a0 + 0xFE) != 0) {
            v1 = ((s32 (*)(s32))func_8012CBA4)(a0);
        } else {
            v1 = ((s32 (*)(s32))func_8012CBF4)(a0);
        }
        if ((v1 & 0x8000) != 0) {
            *(u16 *)(a0 + 0x108) = *(u16 *)(a0 + 0x108) + 1;
        }
        if ((v1 & 0x2000) != 0) {
            *(s16 *)(a0 + 0xFE) = 1;
        } else {
            *(s16 *)(a0 + 0xFE) = 0;
        }
    } else {
        func_8012AD80(a0);
    }

    if ((*(s32 *)(a0 + 0x1C) & 7) == 0) {
        func_80146A6C(2, (void *)a0, 0, 0, 0, 2, 0);
    }
    if ((*(s32 *)(a0 + 0x1C) & 0xF) == 0) {
        func_8002D4C8(0x828, 0);
    }

    v0 = *(s32 *)(a0 + 0x1C) - 1;
    *(s32 *)(a0 + 0x1C) = v0;
    if (v0 != -1) {
        if (func_8012E778(a0, 0x8000A8) != 0) {
            return;
        }
    }

    *(s16 *)(a0 + 0x10A) = 1;
    func_8012B200((u8 *)a0);
    func_8012A828(a0, D_80188950);

    *(s16 *)(a0 + 0x104) = 0;
    *(s16 *)(a0 + 0x102) = 0xA;
    p = *(s32 *)(a0 + 0x20);
    *(s32 *)(p + 4) |= 0x80000000;

    func_801439C0(*(s32 *)(a0 + 0xCC));

    *(s32 *)(a0 + 0x1C) = 0x14;
    *(s16 *)(a0 + 0x2) = 6;
}
