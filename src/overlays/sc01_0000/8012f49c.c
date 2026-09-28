/* Source: derived verbatim from Druthulu/BFM-decomp (vendor/bfm-decomp, same SLUS-00726 build). */
/* func_8012F49C - byte-exact against retail at -O2 (tools/register_match.py). */
#include "psx_types.h"
typedef float f32;
typedef unsigned long long u64;
typedef long long s64;
typedef double f64;
#ifndef NULL
#define NULL ((void *)0)
#endif

extern void func_8012A5F8(void (*a0)(void), s32 a1);
extern void func_8004914C();
extern void func_800491AC();
extern void func_8004945C(s32 a0, s32 a1, void *a2);
extern s32 func_8004955C(s32, s32, s32 *, s32 *);

s32 *func_8012F49C(s32 *param_1, s32 param_2, s32 param_3) {
    extern u8 D_800AF648;
    s16 sv[4];
    s32 out[2];
    s32 sxy, p, flag;
    s32 m;
    void *pv;
    m = *(s32 *)(param_2 + 0x20) + 0x34;
    ((void (*)(s32))func_8004914C)(m);
    ((void (*)(s32))func_800491AC)(m);
    pv = (void *)sv;
    ((void (*)(s32, void *, s32 *))func_8004945C)(param_3, pv, &out[0]);
    sxy = 0;
    /* $a0-pinned scopes force the &D_800AF648 constant to be rematerialized
       (lui/addiu) before each call instead of CSE-hoisting it. */
    { register void *r4 __asm__("$4"); r4 = &D_800AF648; func_8004914C(r4); }
    { register void *r4 __asm__("$4"); r4 = &D_800AF648; func_800491AC(r4); }
    ((s32 (*)(void *, s32 *, s32 *, s32 *))func_8004955C)(pv, &sxy, &p, &flag);
    if (flag < 0) {
        out[0] = sxy = 0;
    } else {
        out[0] = sxy;
    }
    *param_1 = out[0];
    return param_1;
}
