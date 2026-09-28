/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_800D298C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

typedef struct {
    s8 pad00[0x18];
    u16 u18[2];
    s8 pad1C[0xC];
    s32 f28;
    u16 u2C;
    u16 u2E;
    s32 pad30;
    s32 f34;
} St;

void func_800D298C(St *a0) {
    volatile s32 cnt;
    s32 flag;
    s32 cond;
    s32 t;

    cond = a0->f34;
    cnt = 0x8000;
    if (cond == 0) {
        flag = 1;
        do {
            cnt = cnt - 1;
            if (cnt == 0) {
                t = a0->f28;
                a0->f34 = flag;
                a0->f28 = (t == 0);
                a0->u2C = *(u16 *)((s8 *)a0 + (a0->f28 << 3) + 0x18);
                a0->u2E = *(u16 *)((s8 *)a0 + (a0->f28 << 3) + 0x1A);
            }
        } while (a0->f34 == 0);
    }
    a0->f34 = 0;
}
