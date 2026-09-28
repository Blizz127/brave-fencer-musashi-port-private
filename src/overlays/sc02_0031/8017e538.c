/* Complete SC02 retail span [8017E538,8017E73C).
 * Live STOP 7E39C; PAC0 member31.
 */
/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8017E538 - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A568(void (*a0)(void));
extern int func_8005C49C(void);
extern void func_8012A828(s32 a0, void * a1);
extern s32 func_80146A6C(s32 a0, void *a1, s32 a2, s32 a3, s32 a4, s32 a5, s32 a6);
extern void func_8017ECEC(s32 a0, s16 a1, s16 a2);
extern void func_8017ED60(s16 *a0);
extern s32 func_8012BB3C(s32 arg0, s32 arg1, u32 arg2, s32 arg3);
extern s32 func_8012B8E4(s32 arg0, s32 arg1);

void func_8017E538(s32 a0) {

    extern void (*D_801889D8[])(void);
    extern s16 D_801B7828;
    extern s32 D_801B7834;
    extern s32 D_801B783C;
    s32 v0;
    s32 v1;

    v0 = *(s32 *)(a0 + 0x1C);
    v1 = -1;
    v0 = v0 - 1;
    *(s32 *)(a0 + 0x1C) = v0;

    if (v0 == v1) {
        s32 t;
        s16 i;
        s32 ret;
        s32 ang;

        func_8012A828(a0, (void *)&D_801889D8);

        t = *(u16 *)(a0 + 0x10A) + 1;
        *(u16 *)(a0 + 0x10A) = t;

        if ((t & 3) != 0) {
            if (*(s16 *)(a0 + 0x104) == 0) {
                s32 r = func_8005C49C();
                s32 x;
                s32 y;

                x = *(s16 *)(a0 + 0x88) - 0x200;
                x += (r & 0x7F) << 3;
                D_801B7834 = x << 16;

                y = *(s16 *)(a0 + 0x8C) - 0x200;
                y += (u32)(r & 0x7F00) >> 5;
                D_801B783C = y << 16;
            } else {
                func_8017ED60((s16 *)a0);
                *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) =
                    *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) + 0xC00;
            }
        } else {
            for (i = 0; i < 2; i++) {
                ((s32 *)&D_801B7834)[i] = ((s32 *)&D_801B7828)[i];
            }
        }

        i = 8;
        if (*(s16 *)(a0 + 0x108) >= 0xD) {
            i = 2;
        }

        ret = func_8012BB3C(a0 + 4, (s32)&D_801B7834,
                            *(s16 *)(*(s32 *)(a0 + 0x20) + 0x12), i);
        *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) =
            *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) + ret;

        ang = -3 - *(u16 *)(a0 + 0x104);
        func_8017ECEC(a0, ang, 0x50);

        if (*(s16 *)(a0 + 0x104) != 0) {
            func_80146A6C(2, (void *)a0, 0, 0, 0, 2, 0);
        }

        *(s16 *)(a0 + 0x108) = 0;
        *(u16 *)(a0 + 2) = *(u16 *)(a0 + 2) + 1;
    } else {
        s16 d = *(s16 *)(a0 + 0x102);

        if (d != 0) {
            s32 r2 = func_8012B8E4(a0, d);

            *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) =
                *(u16 *)(*(s32 *)(a0 + 0x20) + 0x12) + r2;
        }
    }
}
